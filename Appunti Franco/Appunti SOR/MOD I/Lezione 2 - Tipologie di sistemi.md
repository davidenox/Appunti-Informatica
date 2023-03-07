# Lezione 2
## Sistemi a singolo processore. Sistemi multiprocessore. Struttura del sistema operativo. Tipologie di sistemi operativi. 
---
## Sistemi a singolo processore
Fino a qualche anno fa, la maggior parte dei computer era dotata di un singolo processore. Un sistema di questo tipo è composto da un processore principale, in grado di eseguire le istruzioni dei programmi e di altri processori per usi speciali, come ad esempio le schede grafiche, controller di dischi ecc. Questi processori specializzati eseguono un set d’istruzioni che riguardano i rispettivi dispositivi ma non eseguono istruzioni dei programmi utente.  
L’uso di microprocessori specializzati è diffuso, ma la presenza di tali processori non rende un sistema a singolo processore un sistema multiprocessore.  

## Sistemi multiprocessori
Questi sistemi, anche detti **multicore**, hanno due o più processori, condividono i bus del computer, la memoria e le periferiche. Un vantaggio di un sistema multiprocessore rispetto un sistema monoprocessore è l'**aumento della produttività**, perchè la presenza di più processori implica che possono essere eseguiti più programmi in parallelo. I sistemi multiprocessore sono più affidabili, poiché essendo le funzioni distribuite tra diversi processori, in caso di guasto di uno di essi il sistema continua a funzionare, anche se più lentamente. I sistemi che subiscono un guasto di uno o più componenti e continuano a funzionare sono detti **fault tolerant**.  
Gli attuali sistemi multiprocessore si distinguono in: **multiprocessori simmetrici (SMP) e asimmetrici (AMP)**.  

### Multiprocessori asimmetrici
Questi sistemi utilizzano il **asymmetric multiprocessing** (AMP), in cui ad ogni processore è assegnato un compito specifico, seguendo il modello **master-worker** in cui un processore **master** controlla il sistema e assegna i compiti ai processori worker.

### Multiprocessori simmetrici
I sistemi più diffusi utilizzano il **symmetric multiprocessing**, che prevede che ogni processore esegua tutte le funzioni del sistema operativo. SMP significa che tutti i processori sono pari; non esiste alcun rapporto gerarchico tra i processori.  

![[img2.png|center|500]]


Ogni processore ha il proprio insieme di registri e una cache privata. Tuttavia, tutti i processori condividono la memoria fisica. Il vantaggio di questo modello è che molti processi possono essere eseguiti in parallelo. 
I sistemi multiprocessore possono avere due modelli di accesso alla memoria: **accesso alla memoria uniforme (UMA) e accesso alla memoria non uniforme (NUMA)**. UMA è una tecnica in cui l’accesso a qualsiasi RAM da qualsiasi processore richiede la stessa quantità di tempo. Con NUMA, alcune parti della memoria possono richiedere più tempo di accesso rispetto ad altre parti, creando una riduzione delle prestazioni.  
Una recente tendenza nella progettazione dei processori è quella di includere più core di elaborazione su un unico chip. Tali sistemi sono detti multicore e sono più efficienti di multipli chip separati, perchè la comunicazione in uno stesso chip è più veloce della comunicazione tra chip separati. Inoltre un sistema multicore utilizza meno energia rispetto a più chip single-core.

### Cluster
Un altro tipo di sistema multiprocessore è il **cluster**. Questi sistemi differiscono dai sistemi multiprocessore in quanto sono costituiti da più computer (detti nodi) connessi tra loro. Questi computer condividono la memoria secondaria e sono connessi tramite LAN o un bus di interconnessione veloce. 

![[img3.png|center|500]]


Il cluster è utilizzato per fornire alta affidabilità di un servizio, ovvero in caso di guasto di uno o più computer del cluster, il servizio continua a funzionare. Un cluster può essere strutturato in modo **asimmetrico** o **simmetrico**.  
Nel cluster asimmetrico una macchina è in modalità hot-standby, mentre le altre eseguono le applicazioni. La macchina host in hot-standby ha il compito di monitorare i nodi attivi e, in caso di guasto di uno dei nodi, diventa un server attivo.  
Nel cluster simmetrico, due o più nodi eseguono applicazioni e si controllano a vicenda. Questa architettura è più efficiente in quanto sfrutta tutti l'hardware a disposizione.  
Con cluster costituiti da molti computer collegati tramite una rete, è possibile ottenere ambienti di calcolo ad alte prestazioni.  

## Struttura del sistema operativo
I sistemi operativi variano molto nella loro struttura e composizione, in quanto sono realizzati seguendo obiettivi di progetto differenti. Una delle caratteristiche che condividono i sistemi operativi è la multiprogrammazione (multitasking).

### Sistemi operativi batch multiprogrammati
La multiprogrammazione, introdotta con i sistemi batch nei mainframe degli anni '60, si basa sull'evidenza che un solo programma in esecuzione non può tenere il processore e i dispositivi di I/O occupati allo stesso tempo, poichè esso alterna operazioni di computazioni a istruzioni di input-output.
La multiprogrammazione aumenta l'utilizzo del processore organizzando l'esecuzione dei programmi (job) in modo che la CPU abbia sempre istruzioni da eseguire. 

![[img4.png|center|500]]


Il sistema operativo selezione e inizia ad eseguire uno dei programmi in memoria. In un certo istante, il programma in esecuzione potrebbe eseguire un'operazione di I/O e trovarsi in attesa del completamento. In questa situazione, in un sistema non multiprogrammato, la CPU sarebbe inattiva. In un sistema multiprogrammato, invece, il sistema operativo passa semplicemente ad eseguire un altro programma. Quando i programmi terminano l'attesa, possono essere selezionati di nuovo per tornare in esecuzione. Grazie alla multiprogrammazione l'efficienza dell'uso della CPU aumenta notevolmente, rispetto ad un sistema monoprogrammato

![[img5.png|center|500]]


A prima vista, l’efficienza d’uso della CPU potrebbe essere migliorata aumentando il grado di multiprogrammazione cioè il numero di programmi caricati in memoria allo stesso tempo. Tuttavia bisogna considerare anche il tempo necessario per commutare la CPU da un programma ad un altro. Questo meccanismo, detto **cambio di contesto**, porta ad un aumento dell’**overhead** di sistema. Infatti, quando la CPU è assegnata ad un altro programma, il SO deve eseguire varie operazione tra cui il salvataggio dello stato della CPU (il valore di tutti i suoi registri).  
Per scegliere i programmi da caricare in memoria, una strategia spesso usata è preferire un insieme di programmi con caratteristiche diverse, ad esempio alcuni programmi che eseguono molte operazioni di computazione e poche operazione di I/O (**CPUbound**) e altri con poche istruzioni di calcolo e molte operazioni di I/O (**I/O-bound**) in modo bilanciato e quindi ottimizzare tutte le risorse di macchina.  
Quando avviene un cambio di contesto a causa di operazioni di I/O, è necessario scegliere quale sarà il prossimo programma a cui assegnare la CPU. Un criterio spesso utilizzato nei sistemi batch è di assegnarla in base al programma che da più tempo attende di essere eseguito (criterio FIFO). Un altro criterio, è SJF (Short Job First) che assegna la CPU al programma in coda che ha una durata d’esecuzione più breve.  
La multiprogrammazione migliora le prestazioni ma introduce problemi, perchè il sistema operativo si deve occupare della gestione delle risorse per evitare conflitti tra i programmi.  
I sistemi batch sono oggi ancora molto per attività che richiedono una grande potenza elaborativa su grandissime quantità di dati.  
I sistemi batch multiprogrammati forniscono un ambiente in cui le varie risorse di sistema (per esempio, CPU, memoria e periferiche) sono utilizzate in modo efficace, ma non prevedono l’interazione dell’utente con il computer.

### Sistemi operativi time-sharing
Questi sistemi, detti a condivisione di tempo, utilizzano un'estensione della multiprogrammazione e permettono a più utenti di condividere allo stesso tempo un computer. I primi nascono negli anni '70 con l'introduzione dei minicalcolatori. Unix e Linux sono a partizione di tempo e multiprogrammati.
In questi sistemi, la CPU esegue più programmi passando da uno all'altro con frequenza elevata in modo da consentire agli utenti di interagire con i propri programmi quando sono in esecuzione.  A causa della veloce commutazione della CPU, l'utente ha l'impressione di avere l'intero sistema di elaborazione a sua disposizione, anche se in realtà è condiviso con più utenti.
L'obiettivo principale dei sistemi time-sharing è quello di minimizzare il tempo di risposta dei programmi e di conseguenza ridurre al minimo il tempo di attesa da parte degli utenti per ottenere dal programma una risposta. 
Un utente si collega ad un sistema time-sharing utilizzando un terminale o un computer tramite un'utenza sul sistema. Nel computer deve essere installata un’applicazione di rete che utilizza un protocollo di comunicazione per la connessione remota, come ad esempio telnet, rsh, rlogin e ssh (security shell). Quest’ultimo è l’unico che garantisce sicurezza nella connessione. Una volta connesso comunica col SO mediante shell o GUI.  
La politica di scheduling della CPU usata nei sistemi a partizione di tempo è di eseguire i vari programmi assegnando ad essi un quanto di tempo (time slice) di CPU dell’ordine di alcune decine di millisecondi.

![[img6.png|center|500]]


### Sistemi real-time
Nei SO real-time il calcolatore è utilizzato per la gestione e il controllo di un sistema fisico, detto **ambiente operativo**, costituito da impianti industriali, robot , centrali elettrice ecc.  

![[img7.png|center|400]]


Una caratteristica di questi sistemi è che ogni task deve essere eseguito entro un intervallo di tempo definito (**deadline**) imposto dall'applicazione (ordine di micro-millisecondi).  In altri termini, la validità dei risultati ottenuti da un programma non dipende solo dalla correttezza del programma, ma anche dall’intervallo di tempo entro il quale i risultati sono prodotti.

>**Es.**
>Supponiamo che un’applicazione real time, quando avviata, esegua dapprima un CPU burst di 20 ms, quindi I/O burst per altri 20 ms e infine di nuovo CPU burst per 40 ms. Supponiamo, inoltre, che tale programma sia stato progettato affinché esegua il suo task entro 100 ms (deadline). Molto probabilmente il sistema operativo non assegnerà la CPU immediatamente all’applicazione, poiché in un sistema multitasking ci sono altri programmi che competono per l’uso della CPU.
>![[img8.png|center|500]]



In questi SO i task hanno diverse criticità e quindi diverse priorità che possono essere assegnate in modo statico (**priorità statiche**) o calcolate dinamicamente in base alle caratteristiche dei singoli task (**priorità dinamiche**).  
I SO real-time sono classificati in **hard real-time** e **soft real-time**. In questi ultimi, a differenza dei primi, una deadline non rispettata, non danneggia il funzionamento dell’ambiente operativo, ma ne abbassa le prestazioni e quindi la qualità del servizio.

#### Sistemi embedded real-time
I computer embedded sono la forma più diffusa di computer, e sono detti **micro-computer** o **micro-controller**. Questi sistemi sono utilizzati in ambienti come ad esempio i sistemi di controllo per la domotica. Di solito l'interfaccia utente è molto semplice o a riga di comando. In alcuni di essi sono installati sistemi operativi d’uso generale come Linux o Windows, in cui alcune parti del sistema, come ad esempio lo scheduler, sono modificate opportunamente per far girare applicazioni real-time. L’uso di sistemi embedded continua ad espandersi, sia come unità stand alone che come nodi connessi alla rete Internet e gestiti via web. L’accesso al Web può consentire a un utente di monitorare e controllare da remoto i dispositivi e lo stato dell’abitazione o di altri ambienti.

### Sistemi operativi per personal computer
I primi SO per personal computer erano semplici mono programmati e monoutente. Con l’aumento delle prestazione dei microprocessori e delle dimensioni della memoria, la tecnica della multiprogrammazione è stata implementata anche nei SO per PC. Tutti i sistemi operativi moderni per PC sono multitasking.