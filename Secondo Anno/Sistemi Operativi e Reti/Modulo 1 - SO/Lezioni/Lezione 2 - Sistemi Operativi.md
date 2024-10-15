# Dalle architetture ai sistemi operativi
## Che cos'è un sistema operativo
Un *moderno calcolatore* è tipicamente formato da:
- Uno o più processori;
- Memoria centrale;
- Dischi;
- Stampanti e altre periferiche di I/O.
I dettagli di basso livello sono *molto complessi*. Gestire tutte queste componenti richiede uno strato intermedio software: il **Sistema Operativo**.

## Componenti di un computer moderno (1)
1. 1 o più processori;
2. Memoria principale;
3. Dischi o unità flash;
4. Stampanti;
5. Tastiera;
6. Mouse;
7. Display;
8. Interfacce di rete;
9. Dispositivi di I/O;
## Componenti di un computer moderno (2)
Doppia modalità supportate dall'hardware:
- Modalità **Kernel** ( o *supervisor*);
- Modalità **Utente**.
![[Pasted image 20231008165919.png||center]]

# Il SO come una Macchina estesa
- Idea di *astrazione* :
	- Il sistema operativo si pone tra l'Hardware e le applicazioni; 
- Visione *top-down* :
	- Il SO fornisce astrazioni ai programmi applicativi
- Vista *bottom-up* :
	- Il SO gestisce parti di un sistema complesso
	- E fornisce un'allocazione ordinata e controllata delle risorse
## Il sistema operativo come gestore di risorse
Da un moderno sistema operativo ci aspettiamo che *gestisca* :
1. *Più programmi in esecuzione*;
2. *Più utenti*.
Necessita un'allocazione ordinata e controllata di risorse, quali processore, memoria, unità di I/O ...
Non solo hardware: File, database, ...
*Multiplexing* :
- Nel *tempo* : CPU, stampante..
- Nello *spazio* : memoria centrale, disco, ...
### Storia dei sistemi operativi
Libro

## Uno sguardo all'Hardware
![[Pasted image 20231006164824.png|center]]

### Il processore
La CPU è il cervello del computer, esegue istruzioni della memoria.
- Il ciclo base della CPU: **preleva**(*fetch*), **decodifica**(*code*), **esegue**(*execute*) istruzioni.
- I programmi vengono eseguiti in questo ciclo.
![[Pasted image 20231006165017.png|center|700]]

Le CPU eseguono un set specifico di istruzioni.
- Registri interni memorizzano dati importanti e risultati.
- I set di istruzioni includono funzione per il caricamento/salvataggio dati dalla memoria.
Registri speciali come il *program counter* indicano l'istruzione successiva.
Lo *stack pointer* punta alla cima dello stack in memoria.
- Lo stack contiene frame di procedure con parametri e variabili locali.
Il *registro Program Status Word* (PSW) contiene informazioni sullo stato del programma.
- Il PSW è fondamentale per chiamate di sistema e I/O.
Il sistema operativo gestisce il *multiplexing* temporale della CPU.
- Durante il *multiplexing*, il sistema operativo salva e ripristina i registri.
- Ciò permette al sistema operativo di eseguire programmi in modo efficiente.
Programmazioni avanzate: **Pipeline** (non del tutto trasparenti al SO).
![[Pasted image 20231008170204.png|center]]

### Più di un processore
1. *Multithreading*( o *hyperthreading*):
	- Tiene all'interno della CPU lo stato di due thread ma non c'è una esecuzione parallela vera e propria;
	- Il SO deve tenerne conto.
2. Multiprocessori, vantaggi:
	- Throughput;
	- Economia di scala;
	- Affidabilità.
3. Multicore
4. GPU
5. Impatto fondamentale della **cache**.
![[Pasted image 20231008170550.png|center]]

#### La memoria di un processore
![[Pasted image 20231008170635.png|center]]

*Problemi del sistema di cache*:
1. Quando inserire un nuovo elemento nella cache?
2. In quale riga della cache inserire il nuovo elemento?
3. Quale elemento rimuovere dalla cache quando è necessario uno slot.
4. Dove mettere un elemento appena eliminato nella memoria più grande.
![[Pasted image 20231008171013.png|center]]

#### Nonvolatile Storage
![[Pasted image 20231008171105.png|center]]

Spesso ( erroneamente ) indicato come disco. Nessuna parte in movimento, dati in memoria elettronica ( flash ). Molto più veloce dei dischi magnetici.

### Dispositivi di I/O
Si individuano due componenti:
- Il **Controller** : più semplice da usare per il SO.
- Il **Dispositivo** in sé : interfaccia elementare ma difficile da pilotare.
	- Esempio: dischi SATA.
Ogni controller ha bisogno di un *driver* per il SO.
Il ***Driver** interagisce con il **controller*** attraverso le porte di I/O:
	Istruzioni tipo IN / OUT ;
	Mappatura in memoria.
Per eseguire l'I/O:
1. Il processo esegue la chiamata di sistema;
2. Il Kernel effettua una chiamata al driver;
3. Il driver avvia l'I/O.
E interroga il dispositivo per vedere se ha finito (è occupato in attesa), o chiede al dispositivo di generare un interrupt quando ha finito ( e restituisce qualche informazione ).
Più avanzato: fa uso di hardware speciale (DMA).
![[Pasted image 20231008172841.png|center]]

#### Il DMA
**DMA** è l'acronimo di "*Direct Memory Access*" ed è un dispositivo hardware speciale. Consente ai componenti di accedere direttamente alla memoria del computer senza coinvolgere la CPU. Migliora l'efficienza ed aumenta le prestazioni nelle operazioni di input/output (I/O) ad alta velocità. Utilizzato per il trasferimento veloce di dati tra memoria e dispositivi periferici, riduce il carico sulla CPU durante le operazioni di I/O, consentendole di concentrarsi su altri compiti critici.

### Buses
L'evoluzione dei computer ha portato all'aggiunta di bus supplementari per gestire l'aumento del traffico dati.
	Un sistema x86 moderno ha diversi bus con funzioni e velocità di trasferimento diverse.
	*La CPU comunica con la memoria attraverso un bus veloce DDR4, con una periferica grafica esterna sul bus PCIe* ( Peripheral Component Interconnect Express).
	Con tutti gli altri dispositivi attraverso un hub su un bus *DMI* (Direct Media Interface).
Il bus **PCIe** è il principale e più veloce bus di comunicazioni dei computer attuali.
	*PCIe utilizza un'architettura a connessioni punto a punto dedicate*, migliorando l'efficienza rispetto ai bus condivisi.
![[Pasted image 20231008173528.png|center]]

Dispositivi *legacy* possono essere collegati ad un processore hub separato.
**USB** ( Universal Series Bus ) è stato sviluppato per connettere dispositivi lenti al computer, ma le versioni moderne possono raggiungere velocità fino a 40Gbps. USB utilizza un connettore a 4-11 conduttori per alimentazione e comunicazione. USB consente il collegamento immediato dei dispositivi senza necessità di riavvio del sistema.
## Avvio del sistema (Boot)
La memoria flash della scheda madre contiene il firmware ( il BIOS ). Dopo aver premuto il pulsante di accensione, la CPU esegue il BIOS che:
1. Inizializza la RAM e altre risorse;
2. Esegue la scansione dei bus PCI/PCIe e inizializza i dispositivi;
3. Imposta il *firmware runtime* per i servizi critici ( ad esempio, I/O a basso livello) che il sistema deve utilizzare dopo l'avvio.
Il BIOS cerca la posizione della tabella delle partizioni sul secondo settore del dispositivo di avvio ( contiene le posizioni di altre partizioni ). Il BIOS è in grado di leggere semplici file system ( ad esempio, FAT-32) e avvia il primo programma di *bootloader* ( dalla partizione indicata dal boot manager ).
	Il *bootloader* può caricare altri programmi di *bootloading*.
Alla fine viene caricato l'OS.