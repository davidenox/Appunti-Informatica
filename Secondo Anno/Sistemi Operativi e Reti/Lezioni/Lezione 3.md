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

(slide19)