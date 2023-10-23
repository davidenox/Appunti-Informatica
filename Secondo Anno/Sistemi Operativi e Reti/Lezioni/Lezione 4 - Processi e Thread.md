# Processi
## Il  modello di un processo
>[!important]- Processo = Programma in esecuzione

Quanti processi per ogni programma? Si tratta di un'*astrazione* fondamentale del sistema operativo. Un processo consente al sistema operativo di semplificare:
- *Allocazione* delle risorse;
- Accounting ( o "contabilizzazione" ) delle risorse;
- Limitazione delle risorse.
Il SO *mantiene informazioni*  sulle risorse e sullo stato interno di ogni singolo processo del sistema.
![[Pasted image 20231020160923.png|center]]
>Schema di Multiprogrammazione di quattro programmi

Ogni processo ha un *proprio flusso di controllo*.
- Proprio contatore logico di programma.
Ogni volta che si passa da un processo all'altro, si salva il contatore di programma del primo processo e si ripristina il contatore di programma del secondo.
![[Pasted image 20231020161124.png|center]]

Tutti i processi progrediscono, ma solo uno è attivo in un dato momento.
![[Pasted image 20231020161224.png|center|400]]
### Processi concorrenti
In *linea di principio*, i processi multipli sono *reciprocamente indipendenti*. Essi hanno bisogno di mezzi espliciti per interagire tra loro. La CPU può essere assegnata a turno a diversi processi, ma il SO, normalmente, *non offre garanzie di tempistica o di ordine*.
![[Pasted image 20231020161434.png|center|500]]
## Gerarchie di processi
Il SO in genere crea solo un processo `init`.
- Nei moderni sistemi operativi `init` avvia `kthreadd`, un processo per la gestione dei thread.
I sottoprocessi sono *creati in modo indipendente*:
- Un processo padre può creare un processo figlio;
- Ne consegue una struttura ad albero e gruppi di processi.
![[Pasted image 20231020161723.png|center|300]]
## Creazione di processi
Ci sono quattro eventi principali che causano la creazione di processi:
1. *Inizializzazione* del sistema;
2. Esecuzione di una *chiamata di sistema per la creazione* di un processo da parte di un altro processo in esecuzione (`fork()`);
3. *Richiesta dell'utente* di creare un nuovo processo ( ad esempio tramite Bash );
4. *Avvio di un lavoro* in modalità batch ( o da Bash ). 
## Termine di un processo
Le condizioni tipiche che terminano un processo sono:
1. Uscita normale ( Volontaria );
2. Uscita a causa di un errore ( Volontaria );
3. Errore "fatale" ( Ad esempio $\texttt{Segmentation Fault}$, Involontario);
4. Ucciso da un altro processo ( Involontario ).
## Process management
`fork`: Crea un nuovo processo.
- Il figlio è un clone "privato" del genitore;
- Condivide alcune risorse col genitore.
`exec`: Esegue di nuovo un processo.
- Utilizzato in combinazione con `fork`.
`exit`: Causa la terminazione volontaria del processo.
- Lo "stato di uscita" viene restituito al processo "genitore".
`kill`: Invia un segnale a un processo ( o a un gruppo).
- Può causare la terminazione involontaria di un processo.
## Gli stati di un processo
Esistono tre stati in cui si può trovare un processo:
1. *Running*/In esecuzione. Sta effettivamente utilizzando la CPU in quel momento;
2. *Ready*/Pronto. Eseguibile, temporaneamente fermato per consentire l'esecuzione di un altro processo;
3. *Blocked*/Bloccato. Non può essere eseguito fino a quando non si verifica un evento esterno.
Il SO alloca le risorse ( ad esempio la CPU ) ai processi. Per allocare la CPU, il sistema operativo deve tenere traccia degli stati dei processi:
- *Running*/*Blocked*/*Ready*;
Lo scheduler (de)assegna la CPU:
![[Pasted image 20231020163253.png|center]]
## Informazioni associate ad un processo
- ID (PID), Utente (UID), Gruppo (GID)
- Spazio degli indirizzi di memoria
- Registri Hardware ( Ad esempio il Program Counter)
- File aperti
- *Segnali* ( Signal )
- *Interrupt*
Queste informazioni sono memorizzate nella tabella dei processi del sistema operativo.
### Signal vs Interrupt
"Signals" e "Interrupts" sono meccanismi utilizzati nei SO e nelle applicazioni per gestire eventi asincroni.
>*Interrupts*:
- *Origine*: Dispositivi *Hardware* ( es. tastiera, disco rigido );
- *Gestione*: Tramite routine di servizio di interrupt ( ISR );
- *Uso*: Comunicazione tra hardware e software; risposta pronta agli eventi hardware;
- *Asincronia*: Si verificano in modo asincrono; gestiti immediatamente.
>*Signals*:
- *Origine*: Eventi *Software*; generati da un processo o dal SO;
- *Gestione*: Gestori di segnali personalizzati o comportamento predefinito;
- *Uso*: Gestione condizioni eccezionali nelle applicazioni;
- *Asincronia*: Inviati asincronamente; possono essere gestiti in modo sincrono.
### Interrupts
*Idea*: Per deallocare la CPU a favore dello scheduler, ci si affida al supporto per la gestione degli interrupt fornito dall'hardware.
- *Permette allo scheduler di ottenere periodicamente il controllo*, cioè ogni volta che l'hardware genera un interrupt.
>*Interrupt vector*:
- Associato a ciascun *dispositivo I/O* e linea di interrupt;
- Oarte della tabella dei descrittori di interrupt ( IDT );
- Contiene l'indirizzo iniziale di una procedura interna fornita dal SO ( Gestore di Interrupt o interrupt handler che continua l'esecuzione).
*Tipi di interruzione* : sw, *dispositivo hw(async)*, eccezioni.
## Implementazione dei processi
>Schema di ciò che fa il livello più basso del SO quando si verifica un'interruzione
1. L'hardware impila il Program Counter e le altre informazioni del processo.
2. L'hardware carica il nuovo contatore di programma dal vettore di interrupt.
3. La procedura in linguaggio `assembly` salva i registri.
4. La procedura in linguaggio `assembly` imposta un nuovo stack.
5. Il servizio di interrupt `C` viene eseguito ( tipicamente legge ed esegue il buffer dell'input).
6. Lo scheduler decide quale processo deve essere eseguito successivamente.
7. La procedura `C` ritorna al codice `assembly`.
8. La procedura in linguaggio `assembly` avvia un nuovo processo ( corrente ).

>[!important]- Ogni volta che si verifica un'interruzione, lo scheduler ottiene il controllo e agisce come mediatore.

*Un processo non può cedere la CPU ad un altro processo* ( Context Switch ) senza passare attraverso lo scheduler.
## Gestione dei segnali (1)
*Tipi di segnali*:
- Hardware-induced ( es. `SIGILL` )
- Software-induced ( es. `SIGQUIT` oppure `SIGPIPE` )
*Azioni possibili*:
- `Term`, `Ign`, `Core`, `Stop`, `Cont`.
- Azione predefinita per ogni segnale, tipicamente sovrascrivibile.
- I segnali possono essere tipicamente bloccati e le azioni ritardate.
*Gestione ( catching ) dei segnali*:
- Il processo registra il gestore del segnale.
- Il SO invia il segnale e consente al processo di eseguire l'handler.
- Il contesto di esecuzione di corrente deve essere salvato/ripristinato.
### Gestire il segnale indotto da Ctrl+C

```C
void signalHandler ( int signum ){
	printf("interrupt signal &d received\n", signum );
	// ripulisce e termina il progra,,a
	exit(signum);
}
int main(){
	// registra il signal SIGINT e signal handler
	signal(SIGINT, signalHandler);
	while(1){
		printf("Going to sleep...\n");;
		sleep(1);
	}
	return 0;
}
```

## Gestione dei segnali (2)
- Il kernel invia un segnale
- Interrompe il codice in esecuzione
- Salva il contesto
- Esegue il codice di gestione del segnale
- Ripristina il contesto originale
# Thread
Un'assunzione implicita fatta fin'ora è stata:
- $1\text{ processo}\implies 1\text{ thread in esecuzione}$ 
*Multithreaded* Execution:
- $1\text{ processo}\implies N\text{ thread in esecuzione}$ 
Perché consentire più thread per processo?
- *Lightweight processes* ( processi leggeri).
- Consentire un parallelismo efficiente in termini di tempo e spazio.
- *Una comunicazione e una sicronizzazione semplici*.
## Utilizzo dei Thread
![[Pasted image 20231022115218.png|center]]
![[Pasted image 20231022115305.png|center]]
![[Pasted image 20231022115411.png|center]]
## Thread, processo, macchina a stati finiti
| Modello                   | Caratteristiche                                            |
| ------------------------- | ---------------------------------------------------------- |
| Thread                    | Parallelismo, chiamate di sistema bloccanti                |
| Processo a Thread singolo | Nessun parallelismo, chiamate di sistema bloccanti         |
| Macchina a stati finiti   | Parallelismo, chiamate di sistema non bloccanti, interrupt |

## Thread e processi
I thread *risiedono nello stesso spazio degli indirizzi in un singolo processo*. Tutti gli *scambi* di informazioni avvengono *tramite dati condivisi* tra i thread. I thread si sincronizzano tramite semplici primitive.
Ogni thread ha:
- Il *proprio stack*;
- I *propri registri hardware*;
- Il *proprio stato*.
Tabella/interrupt dei thread:
- Una tabella/interrupt di processo più leggera.
Ciascun *thread puù chiamare qualsiasi chiamata* di sistema supportata dal sistema operativo *per conto de processo a cui appartiene*.
![[Pasted image 20231022120150.png|center|400]]
### Il modello di thread classico
![[Pasted image 20231022120326.png|center]]

| Per processo                   | Per thread        |
| ------------------------------ | ----------------- |
| - Spazi di indirizzi           | - Program counter |
| - Variabili globali            | - Registri        |
| - File aperti                  | - Stack           |
| - Processi figli               | - Stati           |
| - Allarmi in attesa            |                   |
| - Segnali e gestore di segnali |                   |
| - Informazioni contabili       |                   |
$\underbrace{------------}_\text{Elementi condivisi dai thread di un processo }$$\underbrace{-------}_{Elementi privati di ogni thread}$  
### I thread in POSIX
>Alcune chiamate di funzione di `pthreads`

| Chiamata thread        | Descrizione                                               |
| ---------------------- | --------------------------------------------------------- |
| `pthread_create`       | Crea un nuovo thread                                      |
| `pthread_exit`         | Termina il thread chiamante                               |
| `pthread_join`         | Attende l'uscita di uno specifico thread                  |
| `pthread_yield`        | Rilascia la CPU per consentire l'exec di un altro thread  |
| `pthread_attr_init`    | Crea e inizializza la struttura di attributi di un thread |
| `pthread_attr_destroy` | Rimuove la struttura di attributi di un thread                                                          |

### Pthreads
```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10
void *print_hello_world(void *tid){
	printf("Hello World. Greetings from thread %d\n", tid);
	pthread_exit(NULL);
}
int main( int argc, char *argv[]){
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;
	for(i=0;i<NUMBER_OF_THREADS;i++){
		status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
		if(status != 0){
		exit(-1);
		}
	}
	return 0;
}
```

## Implementazione dei thread nello spazio utente
Esisono tre luoghi di implementazione dei *thread*:
1. Nello *spazio utente*;
2. Nel *kernel*;
3. *Implementazione ibrida*.
![[Pasted image 20231022122904.png|center]]

### Pro
I **thread nello spazio utente** *sono gestiti dal kernel* come processi ordinari a singolo thread.
- *Possono essere eseguiti sui sistemi operativi che non supportano* direttamente i thread.
- Sono *gestiti tramite una libreria*.
Ogni processo che usa thread a livello utente *necessita di una propria tabella* dei thread per tracciare lo stato e altre proprietà dei suoi thread.
L'interruzione e il cambio tra thread a livello utente *non richiedono un cambiamento di contesto* completo, sono *molto più veloci* rispetto alle operazioni nel kernel. Offrono l'abilità di *personalizzare l'algoritmo di scheduling* per ogni processo e una maggiore scalabilità.
### Contro
Tuttavia, ci sono *problemi*  con le chiamate di *sistema bloccanti*:
- Se *un thread fa una chiamata che lo blocca, tutti gli altri thread nel processo vengono fermati*.
- Gli *errori di pagina*, dove un prohtramma accede a memoria non presente, *possono bloccare l'intero processo* quando sono causati da un thread a livello utente.
I thread nello spazio utente non hanno *interrupt del clock*, rendendo impossibile uno scheduling di tipo **round-robin** ( prossimamente ).
Sebbene i thread a livello utente siano più veloci e flessibili, *sono meno adatti per applicazioni in cui i thread si bloccano frequentemente*, come i web server multithread. I thread a livello utente possono fermarsi completamente se un singolo thread effettua una chiamata di sistema bloccante, influenzando tutti gli altri nel processo.
## Implementazione dei thread nello spazio Kernel
Il *kernel* che gestisce i thread *elimina la necessità di un sistema run-time* per processo. La tabella dei thread del kernel conserva informazioni simili a quelle dei thread a livello utente.
Le *chiamate che potrebbero bloccare un thread* vengono implementate come chiamate di sistema:
- *Hanno costi più elevati* rispetto alle chiamate di procedura dei sistemi run-time.
- Se un thread si blocca, il kernel può eseguire un altro thread, sia dello stesso processo sia di un altro.
Alcuni sistemi "riciclano" i thread per ridurre i costi, invece che terminarli. Se un thread *causa un errore di pagina*, il *kernel verifica la disponibilità di altri thread eseguibili* nel processo e può eseguire uno di essi.
La programmazione con *thread richiede cautela per evitare errori*.
## Implementazioni ibride
Alcuni sistemi effetttuano il **multiplexing** *dei thread utente sui thread del kernel* ( combinano i vantaggi dei due approcci ). I programmatori *decidono quanti thread del kernel utilizzare* e quanti thread utente multiplexare per maggiore flessibilità. Il kernel è consapevole solo dei thread del kernel, ma ogni thread del kernel può gestire più thread a livello utente.
![[Pasted image 20231023102143.png|center|500]]
## Threads : problemi aperti
Molte *procedure di libreria possono causare conflitti* se un thread sovrascrive dati cruciali per un altro, ad esempio:
- L'invio di un messaggio sulla rete potrebbe essere programmato assemblando il messaggio in un buffer fisso nella libreria e poi eseguendo una trap nel kernel per spedirlo.
- Che cosa accade se un thread ha preparato il suo messaggio nel buffer e poi un interrupt del clock forza uno scambio con un secondo thread, che sovrascrive immediatamente il buffer con un suo messaggio?
L'implementazione di wrappers ( impostare un bit per segnalare che la libreria è in uso ) può evitare conflitti, ma limita il parallelismo.
La gestione dei segnali è complicata:
- Alcuni sono specifici per un thread, altri no.
- Decidere chi deve gestire questi segnali e come gestire conflitti tra thread può essere sfidante.