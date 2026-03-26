# Tipi di SO

1. **SO per Mainframe**: pc di grandi dimensioni usati in grandi aziende o istituzioni.
	- Funzioni principali:
		- *Batch Processing*: Esecuzione di job senza interazione dell'utente;
		- *Elaborazione di transazioni*: Gestione di numerose richieste simultanee;
		- *Timesharing*: Molti utenti eseguono lavori contemporaneamente.
	- Es: Z/OS, usato per applicazioni mission-critical (banche, e-commerce). 
2. **SO per Server**: Utilizzati sui server che servono più utenti attraverso la rete.
	- Servizi forniti:
		- *File Sharing*;
		- *Database*;
		- *Stampa*;
		- *Web hosting*
	- Vengono usati da provider di servizi internet ed aziende per supportare infrastrutture critiche.
	- Es: Linux, FreeBSD, Windows Server, Solaris.
3. **SO per PC**: Supportano un singolo utente con multiprogrammazione e, spesso, architetture multiprocessore. Utilizzati per compiti quotidiani.
	- Es: Windows, macOS, Linux, FreeBSD.
	- Caratteristiche: Facilità d'uso, interfaccia grafica, supporto per applicazioni di produttività
4. **SO per Smartphone e Tablet**: usati su *dispositivi mobili*.
	- Mercato dominato da *Android* (Google) e *iOS* (Apple);
	- Supportano *CPU multicore, GPS, fotocamere, app di terze parti*.
5. **SO per IoT ed Embedded**: usati in *dispositivi connessi* (frigoriferi, lavatrici, telecamere).
	- Tipicamente leggeri, con funzioni specifiche e limitate;
	- Es: Embedded Linux, QNX, TinyOS.
	- Caratteristiche: footprint ridotto.
6. **SO Real-Time**: Progettati per rispettare *scadenze rigide* nei processi industriali e militari.
	- *Hard Real Time*: Risposte immediate e precise (es. robotica industriale);
	- *Soft Real-Time*: Occasionali ritardi tollerabili (es. Streaming multimediale);
	- Es: eCos, VxWorks.
7. **SO per Smart Card**: Utilizzati in Smart Card per pagamenti, autenticazioni ed altro. Alimentate tramite contatti o induzione, con capacità limitate.
	- *Java-oriented*: alcune eseguono applet Java per multiprogrammazione;
	- Es: Sistemi proprietari, JavaCard.

Il SO offre funzionalità attraverso le *chiamate di sistema*. Gruppi di chiamate di sistema implementano *servizi*, come *File System Service* o *Process Management Service*.
I processi sono astrazioni a livello utente per eseguire un programma per suo conto. Ogni processo ha il suo *spazio di indirizzamento*, i dati coinvolti nell'operazione vengono recuperati e memorizzati in file, che persistono rispetto ai processi.

# Processo

>[!important] Un processo è un **programma in esecuzione**, associato ad uno *spazio di indirizzi* e ad un *insieme di risorse* (registri, file,..)

Le informazioni sui processi sono conservate nella *tabella dei processi* del SO. Un processo può essere creato, terminato, messo in pausa e ripreso; può inoltre *creare* un altro processo ( detto processo figlio ) e creare una gerarchia ("albero") di processi. 

I processi sono 'di proprietà' di un utente, identificato da un UID. Gli utenti possono far parte di gruppi, identificati da un GUID.

## File

Per **file** si intende l'astrazione di un dispositivo di memorizzazione: è possibile leggere e scrivere dati su file fornendo una posizione ed una quantità di dati da trasferire.
I file vengono collezionati in **directory** (cartelle), che sono anch'esse file.

Directory e file formano una gerarchia, che inizia dalla directory principale (**root**) che si ramifica in altre directory/file.

I file sono 'protetti' da tuple a tre bit per il **proprietario**, il **gruppo** e gli **altri utenti**: 
Le tuple contengono i bit:
- r - read, consente di leggere il file;
- w - write, consente di modificare il file;
- x - execute, consente di eseguire il file.

### File e pipe

**pipes** - pseudo file che consentono ai processi di comunicare su un canale FIFO. Deve essere impostato in anticipo, e sembra un file 'normale' per leggere/scrivere da/su processi in esecuzione.

## System Call

>[!important] **System Call** - meccanismo con cui un'applicazione chiede servizi al SO (aprire/leggere/scrivere un file, allocare memoria, creare o terminare un processo ecc..).

*Problema*: ogni SO ha delle *system call* diverse, e sono **costose**.
*Soluzione*: Incapsulare le syscall in **librerie**: ogni syscall viene esportata come funzione di libreria.

![[Pasted image 20260326162622.png|center|400]]
![[Pasted image 20260326162727.png|center|500]]

#### Syscall per la gestione dei processi

![[Pasted image 20260326163132.png|center|500]]

#### Syscall per la gestione del file system

![[Pasted image 20260326163234.png|center|500]]
![[Pasted image 20260326163302.png|center|500]]

#### Altre syscall

![[Pasted image 20260326163351.png|center|500]]

## Struttura di un SO
### Kernel monolitico

Il programma principale invoca le chiamate di sistema richieste. Il kernel è un blocco monolitico con:
- *Procedure di servizio* che eseguono le syscall;
- *Procedure di utility* che aiutano ad imprementare le procedure di servizio.
Il kernel è un'unica unità grande ed interconnessa. Tutte le funzioni del SO sono strettamente integrate in un unico spazio di indirizzamento.

### Macchine virtuali

Le **VM** permettono l'esecuzione di più SO su un unico hw fisico, simulando un ambiente separato per ciascuno.
Vantaggi:
- *Isolamento*: Ogni VM opera indipendentemente dalle altre;
- *Flessibilità*: Possibilità di eseguire diversi SO simultaneamente;
- *Gestione semplificata*: Facilita la gestione e manutenzione, separando multiprogrammazione e risorse hw.

**Perché passare dalle VM ai Container?**

1. **Contesto** (VM):
	-  Ogni VM include un SO completo, quindi più memoria/cpu ed avvio lento
	- Ottime per *isolamento forte* e *SO eterogenei*, ma si hanno meno istanze per host
	- Operazioni lente per ambienti dinamici.
2. **Esigenze moderne**:
	- *Ridurre* overhead;
	- *Avvio rapidissimo* e rollback facili per rilasci frequenti;
	- *Portabilità dell'ambiente* dall'IDE al cloud.
I *Container* hanno la stessa idea di isolamento logico, ma senza un OS per istanza.

### Container

I **Container** consentono di eseguire più istanze isolate di applicazioni e servizi sopra lo *stesso kernel* del SO host. Ogni container condivide kernel e librerie di base con l'host, ma mantiene il filesystem, librerie e configurazioni proprie.
Vantaggi:
- *Leggeri e veloci* da avviare;
- Ideali per il deployment rapido e scalabile di applicazioni;
- Uso più *efficiente* delle risorse rispetto alle VM.
Svantaggi:
- Non è possibile eseguire OS diversi dall'host;
- Isolamento meno forte rispetto alle VM: se il kernel viene compromesso, tutti i container sono a rischio.

![[Pasted image 20260326171445.png|center|500]]

### Exokernel
****
