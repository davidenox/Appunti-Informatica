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

```