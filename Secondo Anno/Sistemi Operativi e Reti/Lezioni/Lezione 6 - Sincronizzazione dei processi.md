# Outline
Programmazione concerrente e thread:
- Analisi del problema.
La mutua esclusione:
- I "semafori";
- Mutex e Pthreads;
- I monitor;
- Scambi di messaggi.
# Programmazione concerrente e thread: Il problema
## Sincronizzazione e comunicazione tra processi (IPC)
I processi hanno bisogno di un modo per *comunicare*: Condividere i dati durante l'esecuzione.
Nessuna condivisione esplicita tra processi: I dati devono essere scambiati normalmente tra i processi.
I processi hanno un modo per *sincronizzarsi*:
- Per tenere conto delle dipendenze;
- Per evitare che si intralcino a vicenda;
- Si applica anche all'esecuzione multithread.
## Race conditions
- Il processo *A* legge `in=7` e decide di aggiungere il suo file in quella posizione.
- *A* viene sospeso dal SO ( perché il suo slot è scaduto ).
- Anche il processo *B* legge `in=7` e inserisce il suo file in quella posizione.
- *B* imposta `in=8` e alla fine viene sospeso.
- *A* scrive il suo file nella posizione `7`.
**Problema**: La lettura/aggiornamento di un file dovrebbe essere un'azione atomica. Se non lo è, i processi possono "gareggiare" tra loro e giungere a conclusioni errate.
![[Pasted image 20231102101528.png|center|400]]
## Critical region 
Requisiti per evitare "race conditions":
1. Due processi non possono trovarsi contemporaneamente all'interno delle rispettive regioni critiche.
2. Non si possono fare ipotesi sulla velocità o sul numero di CPU.
3. Nessun processo in esecuzione al di fuori della propria regione critica può bloccare altri processi.
4. Nessun processo deve aspettare all'infinito per entrare nella propria regione critica.
*(NON)* soluzioni:
- *Disabilitare gli interrupt*: Impedisce semplicemente che la CPU possa essere riallocata. Funziona solo per sistemi a CPU singola. 
- *Bloccare le variabili*: Proteggere le regioni critiche con variabii 0/1. Le "corse" si verificano ora sulle variabili di blocco.
# La mutua esclusione
## Critical region
![[Pasted image 20231102103623.png|center|500]]
## Esclusione reciproca con *busy waiting*: Alternanza rigorosa
```C
while(TRUE){
	while(turn!=0);
	critical_region();
	turn=1;
	noncritical_region();
}
```
```C
while(TRUE){
	while(turn!=1);
	critical_region();
	turn = 0;
	noncritical_region();
}
```
Purtroppo, questa è un'altra (non) soluzione:
- Non permette ai processi di entrare nelle loro regioni critiche due volte di seguito.
- *Un processo fuori dalla regione critica può effettivamente bloccarne un altro*.
## Esclusione reciproca con busy waiting: Peterson's Algorithm
Alice e Bob vogliono usare un'*unica postazione* computer in un ufficio. Ma ci sono delle regole:
- Solo una persona può usare il computer alla volta.
- Se entrambi vogliono usarlo contemporaneamente, devono decidere chi va per primo.
>*Idea* dell'algoritmo:
- Alice o Bob devono segnalare il loro interesse a usare il computer.
- Se l'altro non è interessato, la persona interessata può usarlo subito.
- Se entrambi mostrano interesse, registrano il loro  nome su un foglio. Ma se scrivono quasi allo stesso tempo, l'ultimo nome sul foglio ha la precedenza.
- La persona che non ha la precedenza aspetta finché l'altra ha finito.
- Una volta finito, la persona che ha usato il computer segnala che ha finito, e l'altra può iniziare.

```C
#define N 2  // Numero di processi

int turn;    // A chi tocca?
int interested[N];   // Tutti i valori inizialmente 0

void enter_region(int process){ // process è 0 o 1
	int other; // Numero dell'altro processo
	other = 1 - process; // L'opposto del processo
	interested[process] = TRUE; //mostra chi è interessato
	turn = process; // Imposta il flag
	while(turn == process && interested[other] == TRUE)
}// istruzione NULL
void leave_region(int process){ //process: chi esce
	interested[process] = FALSE; //indica l'uscita della
	// regione critica
}
```

### Come è realizzata la mutua esclusione nella CPU?
È possibile avvalersi di due istruzioni assembly.
*Istruzione TSL ( Test and Set Lock )*:
- Presente in computer con più processori.
- Legge il contenuto della memoria "`lock`", salva un valore non zero, e blocca altre CPU
	- Purtroppo anche disabilitando gli interrupt su un processore non c'è garanzia che un processo << faccia danni >> da un'altra CPU e quindi, blocchiamo tutti fino al termine dell'esecuzione di TSL.
*Istruzione XCHG*:
- Scambia i contenuti di due posizioni atomicamente.
- Usata in tutte le CPU x86 Intel per sincronizzazione di basso livello.
#### Funzionamento e uso del TSL
Quando `lock` è 0:
- Un processo può impostare `lock` a 1 con TSL e accedere alla memoria condivisa.
- Al termine, il processo resetta `lock` a 0.
*Metodo per gestire Regioni Critiche*:
- Processi chiamano `enter_region` prima di entrare nella regione critica e `leave_region` dopo.
- Se chiamati correttamente, garantisce la mutua esclusione.
- Se usati in modo errato, la mutua esclusione fallisce.
##### Utilizzo dell'istruzione $\texttt{TLS}$ 
```Assembly
enter_region:
	TSL REGISTER,LOCK |copia il lock nel registro e lo imposta a 1
	CMP REGISTER,#0 |il lock era 0?
	JNE enter_region |se non era 0, il lock era stato impostato, per cui ri-esegui il ciclo
	
	RET |torna al chiamante; si è entrati nella regione critica

leave_region:
	MOVE LOCK,#0 |memorizza 0 in lock
	RET | torna al chiamante
```
##### Utilizzo dell'istruzione $\texttt{XCHG}$
```Assembly
enter_region:
	MOVE REGISTER,#1
	XCHG REGISTER, LOCK
	lock
	CMP REGISTER,#0
	JNE enter_region

	RET

leave_region:
	MOVE LOCK,#0
	RET
```
Entrambe le istruzioni sono essenziali per garantire la sicurezza nelle operazioni condivise da più processori.
### Istruzione $\texttt{TSL}$ e $\texttt{XCHG}$
*Istruzione TSL*:
- Legge il contenuto della parola di memoria lock in un registro e salva un valore non zero in lock.
- Operazione indivisibile : nessun altro processore può accedere finché TSL non è completata.
- Bloccare il bus della memoria impedisce altri accessi alla memoria da altre CPU.
*Istruzione XCHG*:
- Scambia i contenuti di due posizioni ( es. Un registro e una parola di memoria ) atomicamente.
- Usata in tutte le CPU x86 Intel per sincronizzazione di basso livello.
## Come evitare i busy waiting?
Le soluzioni finora adottate consentono a un processo di tenere occupata la CPU in attesa di poter entrare nella sua regione critica ( *spin lock* )$$\texttt{SPRECO DI RISORSE :(}$$
*Soluzione*: Lasciare che un processo in attesa di entrare nella sua regione critica restituisca volontariamente la CPU allo scheduler.
```
void sleep(){
	set own state to BLOCKED;
	give CPU to scheduler;
}

void wakeup(process){
	set state of process to READY;
	give CPU to scheduler;
}
```
## Programmazione concorrente nel problema produttore-consumatore
Nel problema del *produttore-consumatore*, due processi condividono un buffer di dimensioni fisse. Il produttore inserisce informazioni nel buffer, mentre il consumatore le preleva. Il produttore si addormenta ( entra in modalità `sleep` ) se il buffer è pieno e viene risvegliato ( viene riattivato ) quando il consumatore preleva dati. Analogamente, il consumatore dorme se il buffer è vuoto e viene risvegliato quando il produttore inserisce dati.
### Produttore-consumatore (1)
```C
#define N 100
int count = 0;

void producer(void){
	int item;
	while(TRUE){
		item = produce_item();
		if(count==N) sleep();
		insert_item(item);
		count++;
		if(count==1) wakeup(cons);
	}
}

void consumer(void){
	int item;
	while(TRUE){
		if(count==0) sleep();
		item = remove_item();
		count--;
		if(count==N-1) wakeup(prod);
		consume_item(item);
	}
}
```
Il consumatore potrebbe essere risvegliato un attimo prima di andare a dormire, e nessuno lo sveglierebbe più.
###  Bit di attesa del wakeup
**Problema**:
- Il consumatore potrebbe essere risvegliato un attimo prima di andare a dormire.
- Bit di Attesa puà essere aggiunto come rimedio per segnali di risveglio persi.
**Possibile soluzione**:
- Si attiva quando un processo non dormiente riceve un 'wakeup'.
- Se acceso, previene l'entrata in 'sleep' del processo e viene poi spento.
- Funziona come accumulatore per segnali di risveglio.
- Viene resettato dal consumatore a ogni ciclo.
È un *workaround*, non funziona sempre.
# La mutua esclusione: i Semafori
*Valori*: Può essere:
- 0 ( nessun wakeup );
- Positivo ( wakeup in attesa );
**Operazioni**:
`down`:
- Se il valore del semaforo è maggiore di zero, questo valore viene decrementato, e il processo continua la sua esecuzione.
- Se il valore del semaforo è 0, il processo che ha invocato `down` viene bloccato e messo in una coda di attesa associata al semaforo.
	- In altre parole, il processo " va a dormire ".
`up`:
- Se il valore è 0, ci sono processi nella coda di attesa, vengono << svegliati >> ( eventualmente per entrare in competizione ed eseguire di nuovo `down` ).
- In ogni caso, il valore viene incrementato e il processo continua la sua esecuzione.
## I semafori
*Atomicità*: Le operazioni sui semafori sono << indivisibili >>, evitando conflitti.
*Problema Produttore-Consumatore*: Uso dei semafori per gestire accesso e capacità di un buffer.
Tipi di semafori:
- `mutex` ( mutual exclusion, accesso esclusivo )
- `full` ( tutti i posti occupati )
- `empty` ( tutti i posti liberi )
Uso:
- `mutex` previene accessi simultanei;
- `full` e `empty` coordinano attività.
### Semafori: Produttore-Consumatore
```C
#define N 100

typedef int sema;
sema mutex=1;
sema empty=N, full=0;

void producer(void){
	int item;
	while(TRUE){
		item = produce_item();
		down(&empty);
		down(&mutex);
		insert_item(item);
		up(&mutex);
		up(&full);
	}
}

void consumer(void){
	int item;
	while(TRUE){
		down(&full);
		down(&mutex);
		item=remove_item();
		up(&mutex);
		up(&empty);
		consume_item(item);
	}
}
```
## Lettori e Scrittori: Regole e Problemi
*Regola base*: In ogni momento, possono essere ammessi:
- R lettori;
- Solo 1 Scrittore.
*Esempio*: Si possono avere mollteplici letture in un database, ma solo un singolo scrittore.
*Funzionamento sintetico*:
- Il primo lettore blocca l'accesso al database.
- Lettori successivi incrementano un contatore.
- L'ultimo lettore libera l'accesso al database così gli scrittori possono fare il loro lavoro.
### Readers/Writers
N processi accedono ( cioè leggono o scrivono ) ad alcuni dati condivisi. In qualsiasi momento: *R lettori o 1 scrittore ammessi*. Soluzione di base:
```C
typedef int sema;
sema mutex = 1;
sema db = 1;
int rc = 0;

void reader(){
	while(TRUE){
		down(&mutex);
		rc++;
		if(rc==1) down(&db);
		up(&mutex);
		read_db();
		down(&mutex):
		rc--;
		if(rc==0) up(&db);
		up(&mutex):
		use_data_read();
	}
}

void writer(){
	while(TRUE){
		think_up_data();
		down(&db);
		write_db();
		up(&db);
	}
}
```

*Problema*: Se nuovi lettori arrivano mentre uno scrittore è in attesa, lo scrittore potrebbe mai ottenere l'accesso, portando a un blocco perpetuo.
*Soluzione proposta*: 
- Nuovi lettori vengono posti in coda dietro gli scrittori in attesa.
- Gli scrittori ottengono accesso dopo i lettori già attivi.
*Implicazioni*:
- Questo metodo riduce la concorrenza.
- Potenziale impatto sulle prestazioni.
*Alternative*:
- Esistono soluzioni che danno priorità agli scrittori.
- Ogni strategia ha i suoi vantaggi e svantaggi
## La mutua esclusione: Mutex e Pthreads
### Introduzione ai Mutex
Un "mutex" è *una versione esplicita e semplificata dei semafori*, usata per gestire la mutua esclusione di risorse o codice condiviso, quando *non bisogna contare* accessi o altri fenomeni.
Può essere in due stati:
- *Locked* ( Bloccato );
- *Unlocked* ( Sbloccato);
Un bit basta per rappresentarlo, ma spesso viene usato un intero ( 0 = unlocked, altri valori = locked ). Due procedure principali: `mutex_lock` e `mutex_unlock`.
### Funzionamento dei mutex
Quando un thread vuole accedere a una regione critica, chiama `mutex_lock`. Se il mutex è unlocked, il thread può entrare; se è locked, il thread attende. Al termine dell'accesso, il thread chiama `mutex_unlock` per liberare la risorsa. *Importante*: **Non si utilizza il "busy waiting"**. Se un thread non può acquisire un lock, chiama `thread_yield` per cedere la CPU ad un altro thread.
#### Considerazioni aggiuntive
I mutex possono essere implementati nello spazio utente con istruzioni come $\texttt{TLS}$ o $\texttt{XCHG}$. Alcuni pacchetti di thread offrono `mutex_trylock` ( tenta di acquisire il lock o restituisce un errore, senza bloccare). I mutex sono efficaci quando i thread operano in uno spazio degli indirizzi comune.
La condivisione di memoria tra processi può essere gestita tramite il kernel o con l'aiuto di sistemi operativi che permettono la condivisione di parti dello spazio degli indirizzi.
### Parallelismo e prestazioni
L'efficienza nella sincronizzazione diventa cruciale con l'aumento del parallelismo. Spin lock e mutex con busy waiting: efficaci per attese brevi, ma sprecano CPU per attese lunghe. Passaggio al kernel per bloccare processi è oneroso se le contese sono poche. 
Soluzione: *Futex* (Fast User Space Mutex) - combina il meglio di entrambi gli approcci.
### Cos'è un Futex?
Caratteristica di Linux per *implementare lock elementari evitando il kernel finché non è necessario*.
- Migliora le prestazioni riducendo il passaggio al kernel.
- Non standard ( serve `#include <inux/futex.h>`)
*Due parti*:
- Servizio kernel.
- Libreria utente.
*Operazione*:
- Variabile condivisa nello spazio utente usata come lock.
- Il passaggio al kernel avviene solo quando un *thread* è bloccato da un altro.
Quando il lock è rilasciato, il kernel può essere chiamato per svegliare altri processi in attesa.
### Pthread e Mutex
*Pthread*: Fornisce funzioni per sincronizzare i thread.
*Mutex*:
- Variabile che può essere *locked* o *unlocked*.
- Protegge le regioni critiche.
*Funzionamento*:
- Thread tenta di bloccare ( lock ) un mutex per accedere alla regione critica.
- Se mutex è unlocked, l'accesso è immediato e atomico.
- Se locked, il thread attende.
#### Mutex in Pthreads

| Thread Call             | Descrizione                  |
| ----------------------- | ---------------------------- |
| `pthread_mutex_init`    | Crea un Mutex                |
| `pthread_mutex_destroy` | Distrugge un Mutex esistente |
| `pthread_mutex_lock`    | Acquisisce un lock o blocca  |
| `pthread_mutex_trylock` | Acquisice un lock o fallisce |
| `pthread_mutex_unlock`  | Rilascia un lock             |



