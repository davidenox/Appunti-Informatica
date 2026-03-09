# SO

Un **moderno calcolatore** è tipicamente formato da:
- Uno o più processori;
- Memoria centrale;
- Dischi;
- Periferiche I/O.
I dettagli di basso livello sono *complessi*, perciò è richiesto il **Sistema Operativo**, un software che funge da strato intermedio.

## Componenti di un computer moderno

- Uno o più processori;
- Memoria principale;
- Dischi o unità flash;
- Stampanti;
- Mouse e tastiera;
- Display;
- Interfacce di rete;
- Dispositivi I/O.
L'hardware supporta *due modalità*:
- **Modalità kernel** (o supervisor);
- **Modalità utente**.
![[Pasted image 20260309152931.png|center|500]]

È utile vedere un SO come una macchina estesa, in cui vigono diverse idee e visioni:
- Idea di **Astrazione**: Il SO si pone tra hardware e software;
- Visione **Top-Down**: Il SO fornisce astrazioni ai programmi applicativi;
- Visione **Bottom-Up**: Il SO gestisce parti di un sistema complesso, e fornisce un'allocazione ordinata e controllata delle risorse.

## SO come gestore delle risorse

Da un moderno sistema operativo ci si aspetta che gestisca sia *più programmi* in esecuzione che *più utenti*. Esso necessita un'allocazione ordinata e controllata di risorse, quali processori, memoria, unità di I/O ecc..

# Hardware

Architettura (semplificata) di un calcolatore:
![[Pasted image 20260309154418.png|center|500]]

## Processore

**CPU**, cervello del computer, esegue istruzioni dalla memoria. 
- Ciclo base: **fetch-decode-execute** (preleva-decodifica-esegue), ogni programma viene eseguito in questo ciclo.
Le CPU eseguono un set specifico di istruzioni:
- Registri interni memorizzano dati importanti e risultati;
- I set di istruzioni includono funzioni per il caricamento/salvataggio dati dalla memoria.

Il SO gestisce il *multiplexing* temporale della CPU. Durante il multiplexing, il SO salva e ripristina i registri. Una progettazione avanzata avviene tramite l'utilizzo di *pipeline*, che non sono del tutto trasparenti al SO.

![[Pasted image 20260309154825.png|center|500]]

### Più di un processore

**Multithreading**: Tiene all'interno della CPU lo stato di due thread (non c'è un'esecuzione parallela vera), ed il SO deve tenerne conto. L'utilizzo di multiprocessori massimizza il throughput e risulta più affidabile, è composto da un sistema multicore e viene caratterizzato da un impatto fondamentale della *cache*.
![[Pasted image 20260309155150.png|center|500]]

## Memoria
![[Pasted image 20260309155221.png|center|500]]

**Problemi** del sistema di cache:
- *Quando* inserire un nuovo elemento nella cache?
- *Dove* inserire il nuovo elemento?
- *Quale* elemento è necessario rimuovere dalla cache quando è necessario uno slot?
- *Dove* mettere un elemento appena rimosso nella memoria più grande?

### Nonvolatile Storage

![[Pasted image 20260309155445.png|center|500]]

Spesso indicato come *disco* (erroneamente, non ci sono parti in movimento: i dati sono in memoria elettronica (flash)). Molto più veloce dei dischi magnetici.

## Dispositivi I/O

Due componenti:
- **Controller**: più semplice da usare per il SO;
- **Dispositivo** in sé: interfaccia elementare ma complicata da pilotare.
Ogni Controller ha bisogno di un *driver* per il SO, che **interagisce con il controller** attraverso le porte di I/O (istruzioni IN/OUT, mappatura in memoria).

Per eseguire l'I/O:
- Il processo esegue la chiamata di sistema;
- Il kernel effettua una chiamata al driver;
- Il driver avvia l'I/O, 
	- ed interroga il dispositivo per sapere se è in attesa o occupato, oppure chiede al dispositivo di generare un interrupt quando ha finito. 
	- Più avanzato: fa uso di hw speciali (es. DMA).

![[Pasted image 20260309160004.png|center|500]]

### DMA

**Direct Memory Access**, dispositivo hw che consente ai componenti di accedere direttamente in memoria senza coinvolgere la CPU. Migliora l'efficienza ed aumenta le prestazioni nelle operazioni I/O ad alta velocità.
Viene utilizzato per il trasferimento veloce di dati tra la memoria ed i dispositivi periferici, riduce il carico sulla CPU dirante le operazioni I/O consentendole di concentrarsi su altri compiti critici.

### Bus

Aggiunta di bus supplementari per gestire l'aumento del traffico dati. *La CPU comunica con la memoria attraverso un bus veloce DDR4, con una periferica grafica esterna sul bus PCIe*, con tutti gli altri dispositivi attraverso un hub su bus DMI (Direct Media Interface).
![[Pasted image 20260309160420.png|center|500]]

Dispositivi legacy possono essere collegati ad un processore hub separato. 
*USB* (Universal Serial Bus) è stato sviluppato per connettere dispositivi lenti al pc. Utilizza un connettore a 4-11 conduttori per alimentazione e comunicazione, e consente il collegamento immediato dei dispositivi senza necessità di riavvio del sistema

### Boot

La memoria flash della scheda madre contiene il firmware (il *BIOS* (Basic-Input-Output-System)). All'accensione, la CPU esegue il BIOS che:
- Inizializza RAM ed altre risorse;
- Esegue la scansione dei bus PCI/PCIe ed inizializza i dispositivi;
- Imposta il Firmware Runtime per i servizi critici che il sistema deve utilizzare dopo l'avvio.
Il BIOS cerca la posizione della tabella delle partizioni, inoltre è in grado di leggere semplici file system (es. FAT-32 delle USB) ed avvia il primo programma di **bootloader** (dalla posizione indicata da boot manager). Infine viene caricato il SO.