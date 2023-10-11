# Introduzione ai concetti base del SO
## Lo zoo dei sistemi operativi
1. SO per mainframe;
2. SO per server;
3. SO per personal computer;
4. SO per smartphone e computer palmari;
5. SO per IOT e sistemi operativi embedded;
6. SO real-time;
7. SO per smart card.
### Cosa hanno in comune?
1. Extended Machine
	- Estensione della funzionalità hardware
	- Astrazione dell'hardware
	- Nascondere i dettagli al programmatore
2. Resource Manager
	- Protegge l'uso simultaneo/non sicuro delle risorse
	- Condivisione equa delle risorse
	- Resource accounting/limiting
## Concetti 'base' di un sistema operativo
Il sistema operativo offre funzionalità attraverso le chiamate di sistema. Gruppi di chiamate di sistema implementano servizi, ad esempio:
- File System Service
- Process Management Service
I processori sono astrazioni a livello utente per eseguire un programma per conto dell'utente. Ogni processo ha il proprio spazio di indirizzamento. i dati coinvolti nell'elaborazione vengono recuperati e memorizzati in file. I file persistono rispetto ai processi.
## Che cos'è un processo?
Concetto chiave in tutti i SO.
*Def*: **Programma in esecuzione**
Il processo è associato:
1. A uno spazio di indirizzi;
2. Un insieme di risorse:
	- Registri;
	- File aperti;
	- Allarmi;
	- ...
Il processo può essete pensato come un contenitore. Contiene tutte le informazioni necessarie per l'esecuzione del programma.
## Il layout di un processo
Il layout dipende da:
1. Architettura della macchina;
2. Il Sistema Operativo;
3. Il programma.
Very basic Layout:
1. Stack: Active call data;
2. Data: Program variables;
3. Text: Program code.
![[Pasted image 20231010163035.png|center|400]]

## Il ciclo di vita di un processo
Le informazioni sui processi sono conservate nella tabella dei processi del sistema operativo. Un processo sospeso consiste in una voce della tabella dei processi ( registri salvati e altre informazioni necessarie per riavviare il processo ) e nel suo spazio degli indirizzi.
Gestione dei processi:
- Operazioni come la *creazione*, la *terminazione*, la *pausa* e la *ripresa* di un processo.
Un processo può creare un altro processo, conosciuto come processo "figlio", il che crea una gerarchia ( *albero* ) di processi.
### Albero dei processi

![[Pasted image 20231010163910.png|center]]

Un albero di processi. Il processo A ha creato due processi figli, B e C. Il processo B ha creato tre processi figli, D, E ed F.
## Chi "possiede" un processo?
I processi sono "di proprietà" di un utente, identificato da un UID.
1. Ogni processo ha tipicamente l'UID dell'utente che lo ha avviato.
2. Su UNIX, un processo figlio ha lo stesso UID del suo processo padre.
3. Gli utenti possono essere membri di gruppi, identificati da un GUID.<
Un processo (superuser/root/administrator) è speciale: ha più privilegi.
## File
*File*: astrazione di un dispositivo di memorizzazione ( eventualmente ) reale (ad esempio, un disco).
È possibile leggere e scrivere dati da/su file fornendo una posizione e una quantità di dati da trasferire. 
I file vengono collezionati in *directory* ( o cartelle):
- Una directory conserva un identificatore per ogni file che contiene.
- Una directory è un file a sé stante.
Le directory e i file formano una gerarchia:
- La gerarchia inizia dalla "directory principale" (*root*):
	- /
- È possibile accedere ai file tramite percorsi assoluti ( *absolute path* ):
	- /home/ast/todo-list
- O percorsi relativi a partire dalla directory di lavoro corrente:
	- ../courses/slides1.pdf
- Altri filesystem possono essere montati ( da *mount* ) nella root:
	- /mnt/windows
## Diritti di accesso
I file sono "protetti" da tuple a tre bit per il *proprietario*(**owner**), il *gruppo*(**group**) e gli *altri utenti*      (**other users**).
Le tuple contengono un bit (*r*)ead, (*w*)rite e un bit e(*x*)ecute ( ma sono disponibili più bit).
Esempio:
	-*rwx*r-x--x myuser my group 14492 Dec 4 18:04 my file
1. *Owner* ha il permesso di eseguire, modificare e leggere il file;
2. *Group* ha il permesso di leggere ed eseguire file;
3. *Other users* hanno il solo permesso di eseguire il file.
## Un esempio di organizzazione di un File System
![[Pasted image 20231010165824.png|center|600]]

Un file system per un dipartimento universitario.
## File e risorse
![[Pasted image 20231010170017.png]]
(a) Prima del *mount*, i file dell'unità USB non sono accessibili.
(b) Dopo aver eseguito l'operazione di *mount*, fanno parte della gerarchia dei file.
## Accesso ai file : un esempio
![[Pasted image 20231010170256.png|center|600]]
## File e pipe
Pipes : pseudo file che consentono ai processi di comunicare su un canale FIFO.
Deve essere impostato in anticipo.
Sembra un file "normale" per leggere e scrivere da/sui processi in esecuzione.
![[Pasted image 20231010170442.png|center|600]]

## Termini importanti
- - Path;
- - Folder / map / directory;
- - Root directory;
- - Working directory;
- - File descriptor;
- - Mounting;
- - Block/character special files;
- - Pipe.
# Le chiamate di sistema (System call)
## Chiamate di sistema
Le chiamate di sistema sono l'*interfaccia che il sisema operativo offre alle alle applicazioni per richiedere servizi*.
**Problema**:
- Il meccanismo delle chiamate di sistema è *altamente specifico* del sistema operativo e dell'hardware.
- La *necessità di efficienza esaspera* questo problema.
**Soluzione**:
- Incapsulare le chiamate di sistema nella libreria C ( *libc* ).
- Tipicamente esporta *una chiamata di libreria per ogni chiamata di sistema*.
- UNIX *libc* si basa sulla libreria C POSIX.
- Si noti che esistono molte librerie C UNIX...
![[Pasted image 20231011105002.png|center]]
## I 10 passi per effettuare la chiamata di sistema
	read( fd, buffer, nbytes )
- *Preparazione dei parametri*: Il programma chiamante prepara i parametri
	- Solitamente memorizzandoli nei registri o nello stack ( RDI, RSI, RDX)
- *Chiamata alla procedura di libreria*: Il programma effettua la chiamata alla procedura di libreria   ( passaggio 4 ).
- *Collocazione del numero di chiamata di sistema*: Colloca il numero della chiamata di sistema in un registro, come RAX ( passaggio 5 ).
- *Passaggio a modalità kernel*: Si esegue un'istruzione "*trap*" ( ad esempio, SYSCALL in x86-64 ).
	- Passare dalla modalità utente a quella kernel ( passaggio 6 );
	- L'istruzione "trap" è simile a una chiamata di procedura ma cambia la modalità in modalità kernel;
	- Può saltare solo a indirizzi specifici o indici di una tabella di memoria, a differenza della chiamata di procedura.
![[Pasted image 20231011111150.png|center|600]]
- *Esecuzione del gestore di chiamate di sistema*: Il gestore di chiamate di sistema specifico viene eseguito ( passaggio 8 ).
- *Ritorno alla procedura di libreria utente*: Dopo, il controllo può essere restituito alla procedura di libreria utente, all'istruzione successiva all'istruzione "trap" ( passaggio 9 ).
- *Possibilità di blocco*: La chiamata di sistema può bloccare il chiamante, ad esempio, se l'input desiderato non è disponibile.
	- Il sistema operativo può quindi eseguire altri processi.
- *Ripresa dopo il blocco*: Quando l'input o le condizioni desiderate sono disponibili, il processo bloccato viene ripreso.
	- Tornando alla procedura di libreria utente e procedendo all'istruzione successiva (passo 10).
## Chiamate di sistema per la gestione dei processi
	Alcune delle principali chiamate di sistema POSIX
	
![[Pasted image 20231011120203.png|center]]
Il codice di ritorn *s* è $-1$ se si è verificato un errore. I codici di ritorno sono i seguenti: *pid* è l'id di un processo.
![[Pasted image 20231011121338.png|center]]

Il codice di ritorn *s* è $-1$ se si è verificato un errore. I codici di ritorno sono i seguenti: *fd* è un descrittore di file, *n* è un conteggio di byte, *position* è un offset all'interno del file.
### Chiamate di sistema per la gestione del file system
![[Pasted image 20231011121525.png|center]]

### Altre chiamate di sistema
![[Pasted image 20231011130841.png|center]]
#### Un esempio
![[Pasted image 20231011130926.png|center]]
### API di Windows
	Le chiamate API Win32 che corrispondono grosso modo alle chiamate UNIX

![[Pasted image 20231011131119.png|center]]
![[Pasted image 20231011131153.png|center]]
# Struttura di un sistema operativo
## Struttura di un sistema operativo monolitico
Il programma principale invoca le chiamate di sistema richieste.
Il kernel è un blocco monolitico con:
- - Procedure di servizio che eseguono le chiamate di Sistema;
- - Procedure di utilità che aiutano a implementare le procedure di servizio.
![[Pasted image 20231011131558.png|center]]
### Alcune considerazioni
*Sistemi Operativi Monolitici*: Un approccio al design "tutto in uno".
- Il kernel è un'unica unità grande e interconnessa;
- Tutte le funzioni del sistema operativo, come la gestione dei processi, la gestione della memoria e la gestione dei dispositivi di I/O, sono strettamente integrate in un unico spazio di indirizzamento.
*Flessibilità $vs$ Complessità*:
- Offre una certa flessibilità in termini di prestazione e design;
- Tuttavia, dato che è tutto strettamente interconnesso, un bug o un errore in una parte del sistema può causare problemi in altre parti, potenzialmente portando a crash sistemici.
*Compilazione e Collegamento*:
- Tutte le funzioni e procedure del sistema operativo devono essere compilate e collegate in un unico eseguibile del kernel.
*Mancanza di occultamento*: 
- Tutte le procedure possono, in teoria, accedere a qualsiasi altra procedura o variabile all'interno del kernel.
- Non c'è un vero e proprio "occultamento" o isolamento tra le diverse parti del sistema.
*Utilizzo di "trap"*:
- Meccanismo attraverso il quale un programma può richiedere i servizi del sistema operativo.
	- Avviene attraverso interruzioni software che trasferiscono il controllo al sistema operativo.
*Una "struttura a tre strati"*:
- Una suddivisione del sistema in livelli, spesso user mode, kernel mode e hardware, con il "trap" che agisce come meccanismo di comunicazione tra questi livelli.
*Estensioni caricabili*:
- Molti sistemi operativi permettono di caricare dinamicamente componenti aggiuntivi, come driver di dispositivi o file system, senza dover riavviare o ricompilare l'intero sistema operativo.
- Questi componenti possono essere caticati e scaticati a seconda della necessità, offrendo una certa modularità anche in un sistema monolitico.
*Librerie condivise e DLL*:
- Sia UNIX che Windows supportano l'idea di librerie di codice che possono essere condivise tra più programmi.
	- In UNIX, queste sono chiamate *librerie condivise*;
	- In Windows sonpo chiamate *Dynamic Link Libraries* ( **DLL** ).
- Contengono codice che può essere eseguito da più programmi contemporaneamente, riducendo la necessità di avere copie multiple del medesimo codice in memoria.
L'organizzazione stratificata dei sistemi operativi è una generalizzazione dell'approccio monolitico.
Il sistema THE fu uno dei primi ad implementare questa idea, con sei livelli gerarchici ( questi livello gestivano l'allocazione del processore, la memoria, la comunicazione, l'I/O, i dispositivi e gli utenti ).
Il sistema MULTICS usava anelli concentrici per definire i privilegi, con livelli interni più privilegiati di quelli esterni. Vantaggi:
- - Protezione delle risorse e dati critici;
- - Separazione chiara dei compiti ( es. valutazione degli studenti ).
![[Pasted image 20231011133256.png|center]]

1. *Kernel Unificato*: Tutte le funzionalità centralizzate in un unico kernel;
2. *Interconnessione*: Ogni componente ha la capacità di richiamare qualsiasi altro componente;
3. *Scalabilità*: Questa struttura può diventare complessa e meno gestibile con l'evoluzione del sistema.
![[Pasted image 20231011133359.png|center]]

## Struttura di un sistema operativo: Virtualizzazione
Inventato negli anni '70 per separare la multiprogrammazione della macchina estesa. Oggi di nuovo interesse in diversi ambiti. N interfacce di chiamata di sistema indipendenti dal sistema operativo.
![[Pasted image 20231011133923.png|center]]

Virtual Machine Monitor (*VMM*) o Hypervisor emula l'hardware.
- - *Type 1* : VMM viene eseguito sul "pezzo di ferro" ( direttamente su HW, come Xen);
- - *Type 2* : VMM ospitato nel sistema operativo ( esempio: QEMU);
- - *Hybrid* : VMM all'interno del sistema operativo ( esempio: KVM).
![[Pasted image 20231011134232.png|center]]
## Container
I container possono eseguire più istanze di un sistema operativo su una singola macchina. Ogni container divide il kernel del sistema operativo host e i file binari e le librerie ( il container non contiene il sistema operativo completo e può quindi essere leggero ). 
Gli svantaggi dei container:
1. Non è possibile eseguire un container con un sistema operativo completamente diverso da quello dell'host;
2. A differenza delle macchine virtuali, non esiste un rigido partizionamento delle risorse;
3. I container sono isolati a livello di processo ( se un container altera la stabilità del kernel sottostante, ciò può influire sugli altri container ).
## Struttura di un sistema operativo : EXOKERNEL
*Idea*: Separare il controllo delle risorse dalla macchina estesa.
Simile ad un VMM/Hypervisor, ma:
- Exokernel non emula l'hardware.
- Fornisce solo una condivisione sicura delle risorse a basso livello.
Ogni macchina virtuale a livello utente esegue il suo sistema operativo, ma è limitata a utilizzare solo le risorse assegnate.
Rispetto ad altri approcci, l'exokernel elimina la necessità di mappature complesse, concentrandosi solo su quale macchina virtuale ha accesso a quali risorse.
## Struttura di un sistema operativo : UNIKERNEL
Gli Unikernel sono sistemi minimi basati su LibOS, progettati per eseguire una singola applicazione su una macchina virtuale ( es. WebServer ). Questi sistemi contengono solo la funzionalità necessaria per supportare l'applicazione specifica, come un server web, su una macchina virtuale. Gli unikernel sono altamente efficienti poiché non richiedono protezione tra il sistema operativo (LibOS). Esiste solo un'applicazione per macchina virtuale.
Il concetto degli unikernel è stato recentemente riscoperto, offrendo una soluzione leggera ed efficiente per eseguire applicazioni isolate su macchine virtuali.
## Struttura di un sistema operativo: MicroKernel-based client/server
Organizza le *service procedure* che vengono eseguiti in modo separato.
	processes $\implies$ *System Servers/Drivers*
I processi di sistema comunicano attraverso il passaggio di messaggi. Le chiamate di sistema si basano sullo stesso meccanismo di messaggistica. Meccanismo di messaggistica implementato nel kernel minimale $\implies$ *Microkernel*.
![[Pasted image 20231011151534.png|center]]

*Pro*: è più facile aderire al Principle of Least Authority (POLA):
- - Trusted Computing Base ( TCB ) relativamente "piccolo";
- - Ogni processo del sistema operativo può fare solo ciò che è necessario per svolgere il proprio compito;
- - La compromissione, ad esempio, del driver di stampa non influisce sul resto del sistema operativo.
*Contro*: 
- - Il passaggio di messaggi è più lento di una chiamata di funzione (come in un kernel monolitico).

