# Lezione 3
---
## Operazioni del sistema operativo
I sistemi multiprogrammati richiedono che diversi programmi siano contemporaneamente in memoria, per questo è necessaria la **gestione di essa**. Inoltre se alcuni programmi sono pronti per essere eseguiti nello stesso momento , il SO deve scegliere chi verrà eseguito prima. Queesta decisione è presa da una funzione del kernel, ovvero lo **scheduling della CPU**.
In un sistema [[Lezione 2 - Tipologie di sistemi#Sistemi operativi time-sharing|time-sharing]] il sistema operativo deve garantire un tempo di risposta breve. Il metodo più comune per garantire questo si ottiene con la **memoria vituale**, una tecnica che permette l'esecuzione di un processo anche se non è completamente caricato in memoria. Un vantaggio di questo metodo è che consente di eseguire programmi più grandi della memoria fisica disponibile. Un sistema [[Lezione 2 - Tipologie di sistemi#Sistemi operativi time-sharing|time-sharing]] deve fornire anche un file system che risiede su uno o più supporti di memorizzazione, per cui è necessaria la **gestione della memoria secondaria**.  
Per garantire un'esecuzione ordinata, il sistema deve fornire i meccanismi per la **sincronizzazione e la comunicazione dei processi** ed assicurarsi che questi non restino bloccati in situazioni di **stallo**.  

## Funzionamento dual-mode e multi-mode
Per garantire la corretta esecuzione del sistema operativo, bisogna distinguere tra l'esecuzione del codice di sistema operativo e codice dei programmi utente, per questo si utilizzano processori con un supporto hardware che differisce tra i vari modi di esecuzione. Le modalità di funzionamento sono due: **kernel mode** (detta anche modalità privilegiata) e **modalità utente**.  
Un bit, detto **bit di modalità**, è presente nella CPU per stabilire la modalità di funzionamento: kernel (0) o utente (1).  
Quando la CPU esegue un processo utente, il sistema è in modalità utente. Tuttavia, se un'applicazione richiede un servizio dal sistema operativo, tramite una chiamata di sistema, il sistema deve passare da utente a modalità kernel. Questa tecnica di protezione si ottiene suddividendo le istruzioni macchina in istruzioni privilegiate e non privilegiate.  
L'hardware della CPU consente di eseguire le istruzioni privilegiate solo in modalità kernel. Ogni CPU ha il suo set di istruzioni privilegiate, ad esempio le istruzioni di controllo dell'I/O, la gestione del timer e dell'interrupt.  
Un programma utente che esegue istruzioni errate può causare un crash del sistema operativo, ad esempio scrivendo in locazioni di memoria appartenenti al codice o ai dati del sistema operativo. ^86a8e2

## Timer
È necessario assicurarsi che il sistema operativo mantenga il controllo sulla CPU, cosicché un programma non resti in esecuzione in un ciclo infinito o non restituisca il controllo del processore al SO. Per questo si utilizza un timer, che viene impostato per generare un interruzione dopo un determinato periodo. Prima di passare il controllo al programma utente, il SO imposta il timer affinché generi un'interruzione allo scadere, restituiendo il controllo della CPU al SO. 
>**Oss.**
>Le istruzioni che modificano il valore del timer sono privilegiate.

## Ambienti di elaborazione
### Computing tradizionale
Pochi anni fa, un ambiente di elaborazione consisteva in un certo numero di PC collegati in rete, con un server che forniva servizi di condivisione di file e di stampa. L'accesso remoto era lento. I terminali erano collegati a minicomputer con SO [[Lezione 2 - Tipologie di sistemi#Sistemi operativi time-sharing|time-sharing]] ed erano spesso utilizzati in molte società e università.  
Con l'avvento di Internet e grazie all'evoluzione delle tecnologie web, le aziende forniscono portali per accedere ai propri server interni. I terminali sono stati sostituiti dai computer e dispositivi mobili.

![[img9.png|center|500]]


### Computing mobile
Il mobile computing si riferisce all'elaborazione su dispositivi mobili (tablet, smartphone...). Negli ultimi anni la potenza di calcolo dei dispositivi mobili è aumentata notevolmente. I sistemi mobili oggi sono utilizzati per diverse funzioni e possono essere comparati ai computer portatili. Per accedere ai servizi online, i dispositivi mobili utilizzano reti wireless wi-fi ([IEEE 802.11](https://it.wikipedia.org/wiki/IEEE_802.11)) che le reti dati dei cellulari.  

### Sistemi paralleli e distribuiti
I **sistemi paralleli** sono dotati di più processori ed in questi sistemi più processi potrebbero essere realmente eseguiti contemporaneamente. Il SO deve risolvere vari problemi legati all'esecuzione in parallelo dei programmi, nel caso in cui accedano contemporaneamente agli stessi dati, prevenendo possibili condizioni di inconsistenza sulle strutture dati del sistema, che si potrebbero verificare se queste fossero modificate contemporaneamente da funzioni di SO eseguite su diverse CPU.  
Lo sviluppo delle reti ha portato alla realizzazione di moduli di SO per la gestione delle schede di rete e servizi che hanno permesso ai sistemi collegati in rete di condividere dati e informazioni in vario modo come ad esempio tramite il web.  
I SO per calcolatori collegati in rete sono classificati in:
- **Sistemi operativi di rete**: ogni nodo della rete dispone di un proprio sistema operativo ed i sistemi cooperano tra di loro, come ad esempio in applicazioni web ad n-strati.
- **Sistemi operativi distribuiti**: in ogni nodo è installato lo stesso SO e l'utente vede l'intero sistema come un unico calcolatore. Il SO provvede a bilanciare il carico di lavoro distribuendolo opportunatamente sui vari nodi del sistema. (Es. [[Lezione 2 - Tipologie di sistemi#Cluster|Cluster]]).

#### Client-server

Con l'evoluzione dei PC, i progettisti hanno abbandonato l'architettura di sistema centralizzato. I terminali collegati a sistemi centralizzati ora sono sostituiti da PC e dispositivi mobili ad interfaccia grafica che si connettono ai server tramite un'applicazione web. Molti sistemi attuali funzionano come sistemi server per soddisfare le richieste generate da sistemi client.  

![[img9.png|center|500]]


#### Peer-to-peer
In questo sistema, tutti i nodi sono considerati alla pari, ovvero ciascuno funziona sia da client che da server. I sistemi peer-to-peer offrono un vantaggio rispetto ai sistemi [[#Client-server|client-server]] perchè in questi il server è l'unico nodo a fornire servizi, mentre nel sistema peer-to-peer i servizi sono forniti da tutti i nodi distribuiti nella rete.  

![[img11.png|center|500]]


#### Cloud computing
Il cloud computing è un'architettura d'elaborazione che offre servizi di rete come memorizzazione di dati ed applicazioni. Gli utenti pagano tariffe in base ai servizi e alle risorse che utilizzano. Ci sono diversi tipi di cloud computing: 
- **Cloud privato**: gestito da una società per uso proprio.  
- **Cloud pubblico**: cloud disponibile via Internet per gli utenti che sottoscrivono un abbonamento.  
- **Cloud ibrido**: include componenti di cloud pubblici e privati.  
- **Infrastructure as a Service (IaaS)**: server o dispositivi di memorizzazione utilizzabili per fare backup di dati di produzione.  
- **Platform as a Service (PaaS)**: ambiente software per sviluppare applicazioni e utilizzabile tramite Internet.  
- **Software as a Service (SaaS)**: una o più applicazioni disponibili via Internet.  

## Struttura e organizzazione software dei sistemi operativi
Un sistema operativo deve svolgere molti compiti complessi. Per questo deve essere progettato in modo tale che, oltre a funzionare correttamente, il suo codice sia agevolmente modificabile. Per la definizione e la progettazione di un sistema operativo si ricorre ai principi generali che sono stati sviluppati nel campo dell'ingegneria del software. Ad alto livello, la progettazione del sistema sarà influenzata dalla scelta dell'hardware e dal [[Lezione 2 - Tipologie di sistemi|tipo di sistema]].  
Nella fase di progettazione è molto importante suddividere le operazioni che il sistema operativi deve svolgere in meccanismi (**tecniche**) e criteri (**politiche o strategie**):
- i **meccanismi** stabiliscono in che modo deve essere eseguito qualche compito.  
- i **criteri** determinano in che modo utilizzare i meccanismi. 

Nei sistemi multiprogrammati, il SO, per commutare la CPU da un processo all'altro, esegue le istruzioni di *cambio di contesto*, che comprende il salvataggio dei registri della CPU del processo che la lascia e il caricamento dei registri del nuovo processo che andrà in esecuzione.  
Le operazioni di schedulazione della CPU, stabiliscono i criteri con cui assegnare la CPU ad un nuovo processo. La schedulazione potrebbe basarsi su politica FIFO, sulla priorità che possiede ogni processo ecc.  
I meccanismi devono essere progettati in modo tale che siano separati dai criteri. Questo consente, nel caso si cambino i criteri, di mantenere ancora validi i meccanismi. 
>**Es.**
>Se ad esempio si decidesse di modificare la politica di scheduling FIFO, sarebbe ancora possibile utilizzare i meccanismi già esistenti, senza modificarli.

La scrittura di un sistema operativo dipende dall'architettura hardware, in particolare dal processore utilizzato.  
Dato che molti processori sono dotati di istruzioni da eseguire in [[#^86a8e2|modalità privilegiata o utente]], bisogna realizzare ed organizzare il software in modo tale che solo il codice del SO possa eseguire le istruzioni privilegiate, proteggendo le componenti del SO da uso improprio o errato. Generalmente, i sistemi operativi si scrivono con linguaggi di alto livello, come C o C++ con poche e limitate parti in linguaggio assembly, per poter accedere ai dispositivi hardware e realizzare funzioni compatte e veloci.  

### Struttura monolitica
Consiste nel realizzare un insieme di funzioni, ciascuna delle quali implementa un determinato servizio, attivabile tramite una o più chiamate di sistema. Spesso queste funzioni si scrivono in linguaggio assembly, per poter avere la massima velocità di esecuzione e una minore dimensione in termini di occupazione di memoria RAM.

![[img12.png|center|600]]


Questa struttura, piuttosto semplice è stata usata nel sistema operativo Microsoft MS-DOS e nelle prime versioni dei kernel UNIX e Linux. MS-DOS era un sistema operativo monoutente e mono tasking scritto per microprocessori Intel 8088, 8086, 80286, privi di modalità kernel.  
In assenza di modalità privilegiata, il programmatore può accedere a qualsiasi interruzione del microprocessore e quindi eseguire qualsiasi operazione, come scrivere dati in qualsiasi locazione di memoria, anche se riservata al sistema operativo. In questi sistemi, un semplice errore di programmazione in un'applicazione può causare un crash del sistema.  

### Struttura stratificata
Per la progettazione e lo sviluppo di sistemi più complessi si può ricorrere ai modelli e alle tecniche della programmazione strutturata o alla programmazione ad oggetti. I progettisti organizzano il sistema in un insieme di moduli, strutturandoli in vari livelli. Ciascun modulo di un livello utilizza le funzionalità offerte dai moduli di livello sottostante e fornisce i servizi al livello superiore.  

![[img13.png|center|500]]


In questi sistemi, con il termine *kernel* si intende il livello a stretto contratto con l'hardware. Questa tecnica semplifica la fase di progettazione e rende più agevole apportare modifiche e correzioni al codice. Ogni strato può essere modificato, senza apportare cambiamenti agli altri strati. Tuttavia, è richiesta un attenta e complessa analisi per stabilire quanti strati realizzare e scegliere quale funzionalità implementare in ciascuno di essi. La stratificazione porta, però, ad un funzionamento meno efficiente in termini di velocità di esecuzione e di occupazione di memoria, perchè per eseguire un’operazione, un programma applicativo, potrebbe effettuare una chiamata di sistema al livello sottostante, la quale, a sua volta, ne richiama un'altra, e così via. In altre parole, il programma applicativo per ottenere un servizio potrebbe attendere l’esecuzione di N funzioni di sistema. Bisogna tenere anche presente che nel passaggio da uno strato all’altro sono spesso allocate strutture dati e parametri, con conseguente maggiore impegno di memoria. Per tale motivo, attualmente, si progettano sistemi stratificati con un limitato numero di strati.  

### Struttura a microkernel
Per proteggere le componenti del SO è necessario che il processore sia dotato di istruzioni in stato privilegiato, ma questo rende il sistema più difficile da modificare. Per rendere più semplice il cambiamento delle politiche di gestione delle risorse, è stata pensata la struttura a microkernel.  
Per gestire una risorsa sono definite due tipi di componenti del SO: le **tecniche** (meccanismi) per consentire l'uso della risorsa e le **strategie di gestione** (politiche), realizzate utilizzando i meccanismi.  
In questa struttura l'insieme dei meccanismi costituisce il microkernel, che è l'unico componente che gira in stato privilegiato. Tutte le strategie sono implementate in programmi applicativi che girano in modalità utente. In questo modo, i programmi sono più facili da modificare ed espandere. Quando un processo applicativo richiede una risorsa, interagisce con il relativo processo server mediante un insieme di chiamate di sistema detto **IPC (Inter Process Comunication)**, fornite dal microkernel, che consentono la comunicazione tra processi.

![[img14.png|center|600]]


La struttura a microkernel comporta una perdita di efficienza, poiché ogni operazione di comunicazione tra processi utilizza chiamate di sistema. 

### Struttura modulare
Attualmente la miglior tecnica per progettare sistemi e realizzare i sistemi operativi complessi, si basa sulla programmazione orientata agli oggetti. 
Con questa tecnica si sviluppa il sistema in moduli, ciascuno dei quali svolge un compito. Ogni modulo è implementato da un insieme di funzioni descritte da un'interfaccia che descrive le funzionalità svolte dal modulo e da un corpo che consiste nel codice che implementa le funzioni descritte nell'interfaccia.  

![[img15.png|center|600]]


Il codice del corpo di un modulo è nascosto al resto del sistema e si comunica con esso solo tramite le funzioni della propria interfaccia. Il kernel si realizza in base ad un numero di componenti fondamentali, ai quali, se richiesto, se ne aggiungono altri dinamicamente durante la procedura di avvio o durante l'esecuzione.  

### Struttura ibrida 
In realtà pochi sistemi utilizzano una struttura unica. Generalmente l'architettura di un sistema è ibrida, costituita da una combinazione di diverse strutture in modo da risolvere i problemi di prestazioni, sicurezza ed usabilità. Ad esempio, Linux e altri sistemi Unix sono monolitici, perché avere il kernel in un unico spazio di indirizzamento offre prestazioni molto efficienti. Tuttavia, sono anche modulari, poiché nuove funzionalità possono essere aggiunte dinamicamente al kernel. Windows è in gran parte monolitico, soprattutto per motivi di prestazioni, ma conserva alcuni comportamenti tipici dei sistemi a microkernel, compreso il supporto per sottosistemi come win32 e POSIX, che sono eseguiti come processi in modalità utente. I sistemi Windows hanno anche il supporto per i moduli del kernel caricabili dinamicamente.