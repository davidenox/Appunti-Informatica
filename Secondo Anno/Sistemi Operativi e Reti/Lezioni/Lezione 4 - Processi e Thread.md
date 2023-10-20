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
1. L