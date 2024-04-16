# Capitolo 1 
## Introduzione
### Differenza tra traduzione e interpretazione
Un metodo per eseguire un programma scritto in L1 consiste nel sostituire, in una fase iniziale, ogni sua istruzione con un'equivalente sequenza di istruzioni in L0. Il programma che ne risulta è costituito interamente da istruzioni di L0 e può essere eseguito dal computer al posto del programma L1 originale. Questa tecnica è chiamata **traduzione**. 
L'altra tecnica consiste invece nello scrivere un programma in L0 che accetta come dati d'ingresso programmi in L1; tale programma li esegue esaminando un'istruzione alla volta e sostituendola direttamente con l'equivalente sequenza di istruzioni L0. Questa tecnica, che non richiede la generazione preventiva di un nuovo programma L0, è chiamata **interpretazione** e il programma che la esegue è detto **interprete**
- La traduzione: tradurre tutto il programma al linguaggio inferiore e poi viene eseguito. 
- L'interpretazione: traduce ed esegue ogni singola istruzione del programma. Legge ed esegue il codice sorgente del programma senza creare un file oggetto eseguibile. E' più lenta rispetto alla compilazione.

### Differenza tra compilazione ed interpretazione
La compilazione e l'interpretazione sono due metodi per eseguire un programma informatico. La compilazione, eseguita dal compilatore, traduce tutte le istruzioni di un programma in linguaggio macchina, creando un file eseguibile dal computer.
L'interpretazione traduce ed esegue ogni singola istruzione del programma. Legge ed esegue il codice sorgente del programma senza creare un file oggetto eseguibile. E' più lenta rispetto alla compilazione.

L'esecuzione di un programma compilato è molto più veloce rispetto a un programma interpretato. Il motivo è molto semplice, la compilazione crea un file eseguibile ( oggetto ) in linguaggio macchina ed è immediatamente eseguibile dal processore.
Viceversa, l'interpretazione legge un'istruzione alla volta dal codice sorgente del programma ( sorgente ) e la traduce in linguaggio macchina per farla eseguire dal processore.
Dopo aver eseguito un'istruzione, il software interprete passa ad elaborare la successiva e non resta traccia della precedente. Tutti questi passaggi si ripetono ogni volta che eseguo il programma. Per questa ragione l'esecuzione di un programma interpretato è più lenta.

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img0.png|center|400]]


### Livelli di un computer

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img1.png|center|400]]

# Capitolo 2 
## Organizzazione dei sistemi di calcolo
---
### CPU
Una tipica CPU di Von Neumann è formata da registri (da 1 a 32), dalla ALU e da alcuni bus che connettono tra loro diverse parti. I registri alimentano due registri di input della ALU che mantengono i dati d’ingresso della ALU. La ALU esegue operazioni di somma e sottrazione, e il risultato viene memorizzato in un apposito registro di input, successivamente può essere immagazzinato in uno dei registri della CPU e volendo copiato in memoria.
Le operazioni sono divise in: 
- istruzioni registro-memoria: prelevano parole in memoria e vengono portate all'interno dei registri, dove vengono utilizzate dalla ALU per operazioni successive
- istruzioni registro-registro: preleva due operandi dai registri e li porta dentro dei registri di input della ALU e ne memorizza il risultato in uno dei registri. Il processo che porta i due operandi attraverso la ALU e memorizza il risultato è chiamato **ciclo del percorso dati** ed è il cuore della CPU.

#### Esecuzione dell'istruzione
La CPU esegue ogni istruzione compiendo una serie di passi:
1.  preleva la successiva istruzione dalla memoria per portarla nell’IR;
2.  modifica il PC per farlo puntare all’istruzione seguente;
3.  determina il tipo di istruzione;
4.  se l’istruzione usa una parola in memoria, determina dove si trova;
5.  se necessario, preleva la parola per portarla in un registro della CPU;
6.  esegue l’istruzione;
7.  torna al punto 1 per l’istruzione successiva.
Questa sequenza di passi è detta ciclo di prelievo-decodifica-esecuzione (fetch-decode-execute). 

### CISC e RISC
La **CISC** (Complex istruction set computer) è formata da un set di istruzioni in grado di eseguire operazioni molto più complesse rispetto all’architettura **RISC**. È infatti possibile utilizzare una sola istruzione per leggere un dato in memoria, modificarlo e salvarlo nuovamente, cosa impensabile con un set di istruzioni ridotto. 
Sebbene questo tipo di architettura non abbia la velocità di quella **RISC**, ha il vantaggio di poter realizzare programmi più compatti che occupano un minor spazio in memoria. I programmi in questione sono però più “pesanti“, e richiedono molto tempo per l’esecuzione. Un singolo set di istruzioni è eseguito in più passaggi; ogni set di istruzioni ha oltre 300 istruzioni separate. Le istruzioni vengono completate in 2-10 cicli macchina.
La **RISC** è semplice e lineare, permettendo al microprocessore di eseguire il set di istruzioni in tempi molto rapidi e inferiori ai tempi dell'architettura CISC. Esiste un insieme di principi di progettazione, chiamati **principi di progettazione RISC**, che i progettisti delle CPU cercano di seguire il più possibile:
-   Tutte le istruzioni sono eseguite direttamente dall’hardware;
-   Massimizzare la frequenza di emissione delle istruzioni;
-   Le istruzioni devono essere facili da decodificare;
-   Solo le istruzioni Load e Store fanno riferimento alla memoria;
-   Molti registri disponibili.

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img2.png|center|500]]  

### Dischi magnetici
Ogni traccia è divisa in settori di lunghezza fissata. Tra due settori è presente un piccolo spazio detto **intersector gap**.
Le tracce interne hanno maggiore densità di memorizzazione rispetto alle esterne. Ogni drive ha una scheda dedicata (può contenere una CPU) chiamato controllore del disco, oltre a pilotare accetta i comandi software, corregge i dati.

### Hard disk
Sono dispositivi di memorizzazione dati che possono essere collegati internamente o esternamente al calcolatore. 

#### Hard disk magnetici 
Costituito da una pila di dischi che ruotano intorno all’asse, l’insieme di tracce è detto cilindro.
Le performance dell’HD dipendono da:
-   tempo medio di seek;
-   latenza rotazionale;
-   tempo di trasferimento.

Il posizionamento della testina nel raggio della traccia ricercata è detto tempo medio di seek.
La latenza rotazionale è il tempo necessario al disco per posizionare il corretto settore sotto la testina e dipende dalla velocità angolare del disco.
Il tempo di trasferimento dipende dalla densità lineare e dalla velocità di rotazione.

#### Dischi IDE
Il controller dell’Hard disk è su una scheda separata, fu utilizzato lo standard IDE in grado di gestire dischi con una capacità fino a 504 MB, 4 MB/s.
Il SO leggeva e scriveva dati sul disco inserendo parametri nei registri della CPU e poi invocando il BIOS. 
Da IDE si passò all’EIDE dove ha uno schema di indirizzamento aggiuntivo denominato LBA. Ai controllori EIDE potevano avere due canali su ciascuno dei quali poteva essere collegato un driver primario e secondario.
Dopo EIDE ci fu ATA-3, poi ATAPI-4 incrementarono la dimensione del connettore e la velocità di trasferimento , ATAPI-5 e ATAPI-6, mentre ATAPI-7 incrementa la dimensione del connettore per aumentare la banda, utilizza un serial ATA per trasferire i bit su un connettore.

#### SCSI disk
I controller possono collegare fino a 7 dispositivi, hanno organizzazione simile ai dischi IDE ma nescessitano di diverse interfacce ed hanno velocità più alte

#### Dischi a stato solido (SSD)
Dischi basati su memoria flash non volatile, velocità fino a tre volte superiore rispetto HDD.

### CD-ROM
Realizzato in policarbonato poi una striscia sottile di alluminio riflettente. Nel substrato di policarbonato è possibile creare delle depressioni tra aree non incise.
La transizione da un pit a land può rappresentare un valore logico alto o  basso.
I pit sono scritti in modo continuo su una spirale che parte dal buco centrale del disco, per leggere si usa un laser a bassa potenza.
Per memorizzare informazioni esistono due modalità: con correzione errori o senza ECC.
Un settore contiene:
-   un preambolo 
-   la sezione dei dati 
-   il codice ECC
il modo senza ECC è utilizzato per applicazioni audio/video.

### RAID
Per migliorare le prestazioni dei dischi (anche l’affidabilità) si pensò di adottare la strategia del calcolo parallelo.
L’idea è di far vedere al calcolatore il sistema RAID (insieme di dischi) come un unico enorme disco virtuale con elevata performance e affidabilità.
Esistono 5 schemi RAID:
- **RAID Livello 0**: i dati sono suddivisi in strisce di k settori e memorizzati in dischi con modalità round-robin. In questo modo un blocco di dati può essere letto con 4 letture parallele. Lavora meglio con richieste di grandi dimensioni, lavora male se il SO richiede i dati solo ad un settore alla volta; in caso di rottura di un disco tutti i dati sono persi.
 
![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img3.png|center|500]]

- **RAID Livello 1**: Stesso funzionamento RAID 0 ma dischi duplicati, così ci sono tanti dischi primari quanti di backup. In scrittura ogni striscia è scritta due volte, in lettura possono essere utilizzate tutte le copie, distribuendo il carico su più dischi. Se un disco si rompe, si può utilizzare una replica, il ripristino di un disco rotto è semplice poiché c’è una copia del disco.

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img4.png|center|500]]

- **RAID Livello 2**: Utilizza parole binarie, o byte, per decomporre le informazioni sui dischi. Con 7 dischi è possibile dividere un bit per disco: i byte si dividono in 4 bit e si aggiungono 3 bit ottenendo così un codice a correzione di errore di hamming. Se si rompe un disco si può ricostruire facilmente. Il throughput è alto poiché le operazioni sono in parallelo. La rotazione dei dischi sia sincronizzata e che si utilizzino un numero elevato di dischi. Carico di lavoro del controller per calcolare hamming è elevato;

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img5.png|center|500]]

- **RAID Livello 3**: Versione semplificata del RAID 2, un singolo bit di parità è scritto in un disco di parità separato per ogni parola. Tutti i dischi devono essere sincronizzati. Non offre garanzie di affidabilità su errori casuali perché un solo bit non è sufficiente, se si rompe un disco è possibile ricostruire il suo contenuto.

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img6.png|center|500]]

- **RAID Livello 4/5**: I RAID 4 e 5 lavorano su strisce e non richiedono dischi sincronizzati. è come il RAID 0, con una parità per striscia scritta su un disco separato di parità. Si esegue l’EXOR bit a bit di tutte le strisce ottenendo così una striscia di parità.

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img7.png|center|500]]

# Capitolo 3
## Livello logico digitale
---
La base hardware di tutti i calcolatori è costituita da piccoli dispositivi elettronici dette porte logiche, ciascune delle quali calcola una diversa funzione di questi segnali.

### Negazione NOT
![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img8.png|center|150]]

Restituisce il valore inverso del valore in entrata (1 restituisce 0 e 0 restituisce 1)
### Congiunzione logica AND
![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img9.png|center|150]]

Il risultato è 1 se tutti gli operatori sono 1, altrimenti 0
Proprietà: 
- idempotenza: $A \land A = A$  
- commutativa: $A \land B = B \land A$
- associativa: $A \land (B\land C) = (A\land B)\land C$ 
- elemento neutro: $1 \land A = A$
- elemento assorbente: $0 \land A = 0$ 
- complementi: $\bar A \land A = 0$ 
### Disgiunzione logica OR
![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img10.png|center|150]]  

Il risultato è 1 se e solo se almeno uno degli operandi è 1
Proprietà:
- idempotenza: $A \lor A = A$  
- commutativa: $A \lor B = B \lor A$
- associativa: $A \lor (B\lor C) = (A\lor B)\lor C$ 
- elemento neutro: $0 \lor A = A$
- elemento assorbente: $1 \lor A = 0$ 
- complementi: $\bar A \lor A = 1$ 
### Disgiunzione logica esclusiva XOR e EXOR

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img11.png|center|150]]  

Il risultato è 1 se e solo se un numero dispari di operandi vale 1
>$$A \oplus B = (\bar A\land B) \: \lor (A\land\bar B)  $$

### Proprietà logiche
#### Distributiva di AND rispetto OR
$$A\land(B\lor C)= (A\land B)\lor(A\land C)$$
#### Distributiva OR rispetto AND
$$A\lor(B\land C)= (A\lor B)\land(A\lor C)$$
#### Primo teorema dell'assorbimento
$$A\land(A\lor B)= A$$
#### Secondo teorema dell'assorbimento
$$A\land(\bar A\lor B)= A \land B$$
#### Prima legge di de Morgan
$$\overline{(A\land B)}= \bar A\lor\bar B$$
#### Seconda legge di de Morgan
$$\overline{(A\lor B)}= \bar A\land\bar B$$
### Multiplexer
Un multiplexer è un circuito con $2^n$ dati di input, un valore di output ed n input di controllo. Gli input selezionano la linea di ingresso che verrà trasferita in uscita. 

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img12.png|center|300]]

Le linee di controllo $S_0,\: S_1,\: S_2$ codificano un numero a 3 bit che specifica quale delle $I_0,\: I_1,...,\:I_7$ linee di input deve essere instradata verso la porta OR e quindi verso l'output. Indipendentemente dal valore definito dalle linee di controllo, le 7 rimanenti porte AND genereranno il valore 0, mentre quella rimanente produrrà in output 0 oppure 1.

>**Oss.**
>A partire dalla forma normale disgiuntiva, è possibile costruire un qualsiasi circuito utilizzando solamente porte AND, OR e NOT. Di conseguenza il MUX può essere utilizzata per realizzare qualsiasi funzione logica.

### Decoder
Un decodificatore accetta come input un numero ad n bit e lo utilizza per impostare ad 1 una sola delle $2^n$ linee di output.

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img13.png|center|350]]

Quando si fornisce alla memoria un indirizzo, si utilizzano i suoi 3 bit più significativi per selezionare uno degli otto chip di memoria ($U_0,\: U_1,...,\: U_7$). I 3 bit corrispondono ai tre input A, B, C; a seconda del loro valore 1 solo degli 8 chip assumerà il valore 1, mentre tutti gli altri rimangono a 0.

### PLA (Array logico programmabile)
Chip generale che permette di calcolare somme di prodotti. Nella figura la porta OR $F_1$ genera come risultato $\bar WYZ+WX\bar Z$ 

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img14.png|center|350]]

>**Oss.**
>A partire dalla forma normale disgiuntiva, come per il multiplexer, la PLA può essere realizzata utilizzando porte AND, OR, NOT e può essere utilizzata per implementare qualsiasi funzione.

### Circuiti aritmetici
#### Shifter

![[Primo Anno/Architettura dei Sistemi di Elaborazione/img/img15.png|center|500]]

Lo shifter in figura è un circuito con 8 input ($D_0,\: D_1,...,\:D_7$) e 8 output ($S_0,\: S_1,...,\:S_7$). I bit in output sono la copia di quelli in input traslati tutti di una posizione a destra o a sinistra. La direzione (destra/sinistra) è impostata da un bit di controllo C (0 = sx, 1 = dx).

#### Sommatori
Per un calcolatore, la somma tra bit è un operazione fondamentale. Per realizzare un sommatore ad n bit, vengono utilizzati n [[#Full-adder|sommatori]] (full-adder a 1 bit), realizzati a loro volta partendo da [[#Half-adder|semi-sommatori]] (half-adder a 1 bit).    
##### Half-adder

![[img16.png|center|500]]

L'half-adder funziona solo per i bit meno significativi, perché non gestisce un riporto in ingresso.
##### Full-adder

![[img17.png|center|500]] 

A partire da due half-adder, si può costruire un sommatore che prende in ingresso tre bit (A, B e riporto in ingresso). 

##### Clock
Nei circuiti digitali complessi è necessario stabilire l'ordine con cui si verificano gli eventi. Un clock è un circuito che emette degli impulsi di larghezza definita ad intervalli di tempo costanti. L'intervallo di tempo compreso tra le estremità di due impulsi è detto **tempo di ciclo di clock**.

![[img18.png|center|450]]

La frequenza di clock specifica il numero di cicli di clock per unità di tempo (secondo). L'unità di misura è dell'ordine degli Hertz (Hz).

#### Memorie
La memoria è un componente fondamentale in un computer perché memorizza dati ed istruzioni. Per costruire un circuito che memorizza dati è necessario utilizzare circuiti sequenziali in cui l'output non dipende solamente dall'input, ma anche dallo stato del circuito.

##### Latch
Per creare una memoria a 1 bit è necessario un circuito che ricordi i precedenti valori in input. Un circuito semplice può essere realizzato con due NOR che hanno le uscite retroazionate in ingresso (dipendono dai valori dei precedenti ingressi). Il set-reset latch (**SR Latch**) ha due ingressi: S (set) è utilizzato per impostare ad 1 il valore dell'uscita e R (reset) è usato per azzerarlo. 

![[img19.png|center|450]]

Il cambio di stato è provocato da un segnale/impulso; a seguito dell'impulso il circuito si mantiene nello stato raggiunto a meno che non vengano inviati ulteriori segnali/impulsi.
Quando S è impostato temporaneamente ad 1, lo stato del latch diventa Q = 1, indipendentemente dallo stato precedente. Quando si imposta R temporaneamente ad 1, si forza il latch a passare nello stato Q = 0.

##### SR Latch temporizzato

![[img20.png|center|450]]

È un SR latch in cui i segnali agiscono solo quando il segnale di clock è attivo. Quando il clock vale 0, le porte AND generano in output il valore 0, indipendentemente dai valori di S ed R, impedendo al latch di cambiare stato. Quando il clock vale 1, le porte AND non bloccano i segnali di S ed R che tornano a pilotare lo stato del latch.
Ma cosa succede nel caso in cui S = R = 1? Come cambiano gli stati? In questa circostanza il circuito è in uno stato instabile. Vediamo come risolvere questo problema.

##### D latch temporizzato
Per risolvere l'ambiguità del latch SR, viene utilizzato un solo ingresso dati D. 
- Quando D = 1 e il clock = 1, il latch va nello stato Q = 1
- Quando D = 0 e il clock = 1, il latch va nello stato Q = 0

![[img21.png|center|450]]

##### Flip-Flop
Il flip-flop è un circuito simile ad un latch, l'unica differenza è relativa all'istante in cui il segnale di clock determina il cambiamento di stato:
- Nel latch il cambiamento di stato è determinato dal livello alto/basso del clock
- Nel flip-flop è determinato dal fronte salita/discesa del clock

![[img22.png|center|450]]

Molti latch hanno due ingressi aggiuntivi PRESET (per forzare lo stato Q = 1) e CLEAR (per forzare lo stato Q = 0).
Un flip-flop D è dotato di un generatore di impulsi che funge da clock nei fronti di salita e discesa dovuti ai ritardi fisici del processamento del segnale passante per l'AND.

![[img23.png|center|450]]

Per realizzare un registro ad 1 byte possono essere utilizzati 8 flip-flop come mostrato nella figura sottostante

![[img24.png|center|450]]

- Gli 8 flip-flop hanno l'input di clock collegati tra loro e sono pilotati da una porta NOT (pin 11).
- Input (D) e Output (Q) sono separati tra loro.
- Per la scrittura è sufficiente prendere i dati sui PIN D e inviare un impulso di clock.
- Il byte memorizzato è sempre disponibile sui PIN Q.

### Bus
Un bus è un collegamento che unisce i vari dispositivi di un computer. Possono essere interni alla CPU (connette i registri della ALU) o esterni (memoria o periferiche di I/O). 
Alcuni dispositivi sono **attivi** (master) perché possono iniziare un trasferimento dati sul bus, altri **passivi** (slave) perché restano in attesa di una richiesta di un master.
Spesso i segnali digitali generati dalle periferiche sono troppo deboli per alimentare un bus, soprattutto se questo è lungo o collegato a molti dispositivi. Per risolvere questo problema molti master sono connessi al bus mediante un chip detto **bus-driver**, mentre gli slave utilizzano un chip detto **bus-receiver**. Per le periferiche che svolgono sia il ruolo di master che di slave si utilizzano chip detti **trasmettitore-ricevitore del bus**. Questi chip sono dispositivi a tre stati per permettere loro di essere sconnessi quando non necessari. Un'alternativa consiste nell'agganciare la periferica al bus tramite un collettore aperto; quando due o più dispositivi accedono la linea nello stesso istante, il risultato è un OR di tutti i segnali (wired-OR).

Se un bus ha n linee di indirizzi, la CPU può indirizzare almeno $2^n$ locazioni di memoria diverse. L'incremento della dimensione del bus indirizzi permette di indirizzare maggiori spazi di memoria, ma questo comporta un incremento di costi, larghezza del bus, fili e occupazione di spazio.
Per incrementare la larghezza di banda di un bus si può:
- ridurre il periodo di clock del bus, con il rischio, però, di:
	- avere dispositivi che operano a velocità differenti
	- perdere retrocompatibilità
- aggiungere nuove linee di dati; per non avere bus troppo ampi si utilizza la tecnica del bus multiplexato, ma questo porta un rallentamento del sistema.

#### Bus sincroni
Utilizzano un clock che determina la temporizzazione delle attività sul bus. Ogni operazione richiede un numero di periodi di clock per essere eseguita.
1. La CPU master pone l'indirizzo di memoria sull'address bus in modo che le linee si stabilizzino;
2. la CPU comunica al sistema l'operazione che intende fare con la memoria;
3. la CPU comunica che si tratta di un'operazione in lettura, così la memoria slave deve fornire il contenuto della cella indirizzata dall'address bus;
4. poiche la memoria è meno veloce della CPU, c'è maggiore stato di attesa

#### Bus asincroni
Il bus si adatta alla velocità del dispositivo collegato ed un dispositivo lento non rallenterà il sistema. La maggior parte dei bus sono sincroni perché più semplici da realizzare.

#### Arbitraggio del bus
Ciascun dispositivo intelligente del computer (CPU, coprocessori, ecc.) possono diventare a turno master del bus. L'arbitraggio del bus è utilizzato per prevenire situazioni di conflitto in cui due o più dispositivi tentano di diventare master. Questo meccanismo può essere **centralizzato** o **decentralizzato**.

Il meccansimo centralizzato necessita di un arbitro, che quando riceve una richiesta di utilizzo del bus, la concede garantendo una linea di connessione del bus. Quando il dispositivo più vicino vede la connessione: ^5c5be8
- se lo ha richiesto lui, blocca la linea negandola a tutti
- altrimenti mantiene libera la linea

Quando due o più dispositivi fanno richiesta, la ottiene il più vicino all'arbitro.
Molti bus per aggirare il fatto che le priorità sono legate alla distanza dall'arbitro, definiscono diversi livelli di priorità, utilizzando diverse linee di richiesta-concessione ed il bus viene concesso al dispositivo con priorità maggiore; a parità di priorità vince chi è più vicino all'arbitro.

![[img25.png|center]]

Nel meccanismo decentralizzato, ogni dispositivo ha una propria linea di richiesta ed una priorità, prima di inviare una richiesta ciascuno deve verificare che non ci sia già una richiesta con priorità più alta. Al termine dell'utilizzo del bus, la linea deve essere negata. Lo svantaggio è che ci sono troppi collegamenti e il numero di collegamenti non può superare il numero di linee.
Lo schema utilizza tre linee:
- La linea di richiesta del bus;
- La linea BUSY asserita dal dispositivo bus master corrente;
- La linea di arbitraggio propagata tra i dispositivi in cascata.
Per ottenere un bus un dispositivo deve:
- controllare che BUSY sia negata e che l'ingresso IN sia asserito;
- cosi nega OUT, asserisce la linea BUSY e diventa il master del bus.
al termine sblocca OUT e libera BUSY negandolo.

![[img26.png|center]]

### Dispositivi di I/O
I dispositivi esterni dovrebbero rappresentare/raccogliere informazioni in una forma comprensibile agli esseri umani.
Le periferiche esterne possono essere divise in tre categorie: input, output o entrambi.
Le periferiche di input permettono di inserire dati all'interno del computer (tastiera, mouse);
quelli di output permettono di fornire dati dal computer (monitor, stampante);
quelli di I/O permettono di inserire ed estrarre dati dal computer (modem, hard disk).

# Capitolo 4
## Livello di microarchitettura
---
Il livello della microarchitettura **descrive il funzionamento interno di una CPU**, e in particolare come le istruzioni ISA (Instruction Set Architecture) vengono interpretate ed eseguite dall'hardware (livello della logica digitale) che costituisce la CPU.

### Percorso dati
Il percorso dati è quella parti della CPU che contiene la ALU, i suoi input ed output. Il data path contiene registri a 32 bit che controllano l'accesso in memoria. Inoltre il percorso dati si compone di due bus: B e C (l'operando A è quello contenuto nel registro H).
La maggior parte dei registri può inviare il proprio contenuto sul bus B, collegato in input alla ALU. Alla base dell'ALU troviamo lo shifter, il quale invia il proprio risultato al bus C. 

I registri del data path sono i seguenti (in **grassetto** i più importanti):
- **Memory address register (MAR)**
- **Memory data register (MDR)**
- **Program counter (PC)**
- Memory byte register (MBR), è un byte nello stream di istruzioni che provengono dalla memoria.
- **Stack pointer (SP)**
- Local variable (LV), è il riferimento nello stack alla base delle variabili locali
Gli altri registri presenti sono:
- Constant pool (CPP)
- Top word on the stack (TOS)
- Op code register (OPC), è il registro temporaneo, può contenere l'ultima istruzione eseguita prima di un salto e identifica il tipo di istruzione indicando anche se è di tipo ADD o BRANCH
- Holding (H)

![[img27.png|center|450]]

### ALU 
![[img28.png|center|500]]

Il settore in basso a sinistra contiene un decodificatore a 2 bit che, in base ai segnali $F_0$ e $F_1$, permette di attivare una delle quattro linee per le 4 operazioni: $AB$ (AND), $A+B$ (OR), $\bar B$ (NOT), $A + B$ (somma aritmetica). 
Il settore in alto contiene le porte logiche per calcolare A AND B, A OR B e $\bar B$; in base alle linea attivata dal decodificatore solo uno di questi risultati viene passato attraverso la porta OR. 
Gli input ENA e ENB possono essere utilizzati per forzare a 0 gli input A e B, mentre è possibile avere come input $\bar A$ al posto di $A$ impostando ad 1 l'input INVA (inverti A). 
Il settore in basso a destra è un [[#Full-adder|full-adder]].

Le ALU ad 1 bit possono essere assemblate insieme per costruire un ALU di lunghezza variabile. Questa tecnica è detta bit-slice e può essere applicata ad altri circuiti digitali che lavorano bit a bit.

![[img29.png|center|500]]

Il segnale INC è utilizzato per incrementare il risultato, ovvero per calcolare somme come A+1, A+B+1.

### Temporizzazione del percorso dati

![[img30.png|center|550]]

Ogni nuovo ciclo ha inizio sul fronte di discesca del clock, momento in cui vengono memorizzati i bit che controllano il funzionamento delle porte. Questa operazione richiede un intervallo di tempo finito (w in figura). Il registro richiesto viene selezionato e il suo contenuto portato sul bus B, dopo un intervallo di tempo x. A questo punto, la ALU e lo shifter possono iniziare ad operare sui suoi dati e i loro output diventano stabili dopo un intervallo di tempo y. Dopo un ulteriore intervallo di tempo z, i risultati vengono propagati lungo il bus C e caricati nei registri in corrispondenza del fronte di salita del successivo impulso di clock.

### Operazioni della memoria
La CPU ha due modi per comunicare con la memoria:
- Una porta da 32 bit per la lettura/scrittura dei dati del livello ISA. La porta viene controllata da due registri:
	- MAR (Memory Address Register): specifica l'indirizzo di memoria in cui si desidera leggere o scrivere una parola
	- MDR (Memory Data Register): ospita la parola (32 bit) che sarà letta o scritta all'indirizzo di memoria specificato da MAR
- Una porta a 8 bit per leggere (solo lettura!) il programma eseguibile (fetch delle istruzioni ISA). Anche questa porta è controllata da due registri:
	- PC (Program Counter): registro a 32 bit che indica l'indirizzo di memoria della prossima istruzione ISA da caricare (fetch)
	- MBR (Memory Byte Register): contiene il byte letto dalla memoria durante il fetch. È un registro a 32 bit, pertanto il byte letto viene memorizzato negli 8 bit meno significativi
In generale tutti i registri della CPU vengono controllati da uno o due segnali di controllo. In [[img27.png|figura]] la freccia vuota indica l'output del registro sul bus B, mentre la freccia piena indica il caricamento dal bus C. 
MBR può essere scritto sul bus B in due modi diversi: 
- unsigned: i 24 bit non utilizzati vengono impostati a 0 (valore MBR tra 0 e 255)
- signed: il bit di segno (il settimo), viene copiato su tutti i 24 bit non utilizzati (valori tra -128 e +127)

Le due porte MAR/MDR e PC/MBR indirizzano la memoria a parole (32 bit) e a byte (8 bit) rispettivamente.

### Microistruzioni
Per controllare il data path abbiamo bisogno di 29 segnali suddivisibili in 5 gruppi funzionali:
- 9 segnali (frecce piene) per controllare la scrittura dei dati dal bus C all'interno dei registri 
- 9 segnali (frecce vuote) per controllare l'abilitazione dei registri del bus B per l'input della ALU
- 8 segnali per controllare le funzioni della ALU e dello shifter
- 2 segnali (non mostrati in [[img27.png|figura]]) per indicare lettura/scrittura della memoria tramite PC/MBR
- 1 segnale (non mostrato in [[img27.png|figura]]) per il fetch (lettura) delle istruzioni dalla memoria tramite PC/MBR
I valori di questi 29 segnali specificano il comportamento della CPU da eseguire durante un ciclo del percorso dati.
La sequenza di cicli di data path necessari all'esecuzione di un istruzione ISA prende il nome di **microprogramma** di quell'istruzione ISA. Un microprogramma è costituito di **microistruzioni**. 

I 29 segnali di controllo non sono sufficienti a specificare una microistruzione; infatti, è necessario specificare anche cosa fare nel ciclo seguente. Una microistruzione è una sequenza di bit, composta da 3 parti:
- Control: stato dei segnali di controllo
	- ALU: seleziona le funzioni dell'ALU e dello shifter 
	- C: seleziona quali registri sono scritti dal bus C
	- Mem: seleziona la funzione in memoria
	- B: seleziona quale registro è scritto sul bus B
- Address: indirizzo della prossima microistruzione da eseguire
- JAM: bit per la gestione dei salti incondizionati a seconda dei bit di stato (N, Z) dell'ALU

![[img31.png|center|500]]

### [[img32.png|Microarchitettura MIC-1]]
La decisione dei segnali di controllo da abilitare durante ciascun ciclo è determinato da un **sequenzializzatore** che si occupa di far avanzare passo dopo passo la sequenza di operazioni necessarie per eseguire una singola istruzione ISA. Durante ogni ciclo, il sequenzializzatore deve produrre due tipi di informazioni:
- stato di ogni segnale di controllo del sistema
- indirizzo della microistruzione successiva
Il cuore dell'architettura (in [[img32.png|figura]]) di controllo è una memoria detta **control store** che contiene le microistruzioni.  
Il "decoder" decodifica il tipo di istruzione in base all'opcode (codice del tipo di operazione da svolgere).

#### Funzionamento di MIC-1
All'inizio di ogni ciclo di clock (fronte di discesa) MIR viene caricato con il contenuto della parola indirizzata da MPC. Il caricamento deve terminare entro il tempo w (in riferimento alla [[img30.png|figura]]). 
Subito dopo i segnali vengono propagati all'interno del data path ed uno dei registri vengono inviati attraverso il bus B alla ALU che calcola la funzione richiesta e produce sul bus C il risultato; sul fronte di salita i registri selezionati vengono caricati. 

# Capitolo 5
## Il livello ISA e un esempio: IJVM
---
Il **livello ISA** (Istruction Set Architecture) descrive l'architettura delle istruzioni che la CPU è in grado di eseguire in Hardware (firmware). Ogni CPU ha un proprio ISA e quindi istruzioni diverse spesso non sono compatibili tra loro. 
Il livello ISA è l'interfaccia tra i compilatori e l'hardware, quindi il linguaggio che entrambi possono comprendere. Questo livello deve essere retrocompatibile. 
Normalmente ha due modalità operative:
- Modalità kernel: per eseguire il SO e tutte le istruzioni
- Modalità utente: per eseguire i programmi utente e non operazioni "sensibili" (come quelle che accedono alla cache). 

Ogni istruzione di livello ISA è una funzione che deve essere richiamata dal programma principale. 
Il PC (Program Counter) è una delle variabili di stato e indica la locazione di memoria che contiene la successiva istruzione ISA da eseguire.

### Ortogonalità
È il principio secondo cui ogni istruzione dovrebbe essere in grado di utilizzare qualsiasi modalità di indirizzamento supportata. Fornendo una varietà di modalità di indirizzamento, l'ISA consente al programmatore di scegliere quella che soddisfa esattamente la necessità del proprio programma a quel punto, e quindi riduce la necessità di utilizzare più istruzioni per raggiungere lo stesso scopo. Ciò significa che il numero totale di istruzioni viene ridotto, risparmiando memoria e migliorando le prestazioni.

### Lo stack 
È una struttura dati utilizzata per memorizzare lo stato di una procedura che segue la filosofia LIFO (Last In First Out). Questa organizzazione dei dati permette di gestire anche situazioni di chiamate ricorsive.
In IJVM lo stack è utilizzato per memorizzare variabili locali ed eseguire calcoli aritmetici. Vengono manetenuti due puntatori a indirizzi di memoria nello stack:
- Un puntatore alla base attuale dello stack - LV (Local Variable)
- Un puntatore alla cima dello stack - SP (Stack Pointer)

![[img33.png|center|450]]

### Il modello della memoria IJVM
La memoria può essere vista come un vettore di:
- 4.294.967.296 byte (4 GB) 
- 1.073.741.824 parole da 4 byte 
L'unico modo che le istruzioni IJVM hanno per accedere alla memoria è quello di indicizzarla utilizzando dei puntatori. In ogni momento sono definite le seguenti aree di memoria:
- **Porzione costante di memoria (Constant Pool)**: I programmi IJVM non possono scrivere in quest’area che contiene costanti, stringhe e puntatori ad altre aree di memoria cui è possibile far riferimento. È caricata quando il programma è portato in memoria e in seguito non viene modificata. 
- **Blocco delle variabili locali**: Per ogni invocazione di un metodo viene allocata un'area in cui memorizzare le variabili locali durante l'intero ciclo di vita dell'invocazione. Nella parte iniziale di questo blocco sono memorizzati i parametri (argomenti) con cui è stato invocato il metodo. Il blocco delle variabili locali non comprende lo stack degli operandi, che è separato.
- **Stack degli operandi**: Il blocco dello stack non può superare una certa dimensione, stabilita in anticipo dal compilatore Java. Lo spazio per lo stack degli operandi è allocato direttamente sopra il blocco delle variabili locali.
- **Area dei metodi**: Infine c’è una regione di memoria in cui risiede il programma. Quì è presente un registro implicito che contiene l’indirizzo della successiva istruzione da prelevare. Questo puntatore è chiamato contatore di programma (Program Counter), oppure PC.

![[img34.png|center|500]]

Tutti i computer suddividono la memoria in celle adiacenti di un byte che sono a loro volta raggruppati in gruppi di 4 (32 bit) o 8 (64 bit).
I processori a livello ISA normalmente dispongono di uno spazio di memoria lineare (232 o 264), talvolta alcuni hanno una suddivisione tra dati e istruzioni (questo rende più difficili gli attacchi malware).

### Istruction set IJVM

Il set di istruzioni IJVM è molto semplice e si compone di 20 istruzioni: 
- 3 istruzioni per la scrittura sulla cima allo stack di dati provenienti da sorgenti diverse (BIPUSH, ILOAD, LDCW) 
- 1 istruzione per la lettura della parola sulla cima dello stack il salvataggio nell'area delle variabili locali (ISTORE) 
- 3 istruzioni per la manipolazione dello stack: scambio parole, duplicazione parola, rimozione cima (SWAP, DUP, POP) 
- 2 operazioni aritmetiche (IADD, ISUB) + 2 operazioni logiche (IAND, IOR) 
- 1 istruzione di incremento del valore di una variabile locale (IINC) 
- 4 istruzioni di salto: 1 incondizionata (GOTO), 3 condizionali (IFEQ, IFLT, IFICMPEQ) 
- 1 istruzione per specificare ha un indice di 16 bit e non di 8 come di solito (WIDE) 
- 2 istruzioni per la chiamata di metodi (INVOKEVIRTUAL, IRETURN) 
- 1 istruzione nulla (NOP)
La tabella seguente elenca le istruzioni IJVM; la prima colonna contiene il codice (opcode) dell'istruzione, la seconda il codice mnemonico e gli eventuali operandi dell'istruzione; la terza colonna riporta una descrizione
![[img35.png|center|500]]

### I registri
Tutti i computer hanno dei registri visibili a livello ISA. Il loro compito è il controllo dell'esecuzione del programma, il contenimento dei risultati temporanei o altro.
I registri ISA si suddividono in due categorie:
- Specializzati: Program Counter, Stack Pointer e quelli visibili solo in modalità kernel
- Di uso generale: utilizzati per memorizzare risultati temporanei delle variabili. 
Il registro dei flag (Program Status Word - PSW) è un registro ibrido, poiché è tra le modalità kernel ed utente. Questo registro di controllo contiene vari bit che sono necessari alla CPU e che vengono impostati a ogni ciclo dell'ALU e riflettono lo stato del risultato dell'operazione più recente.
Questi sono:
- N: posto a 1 dopo risultato è negativo.   
- Z: posto a 1 dopo risultato uguale a 0.
- V: posto a 1 se il risultato ha causato un overflow.
- C: posto a 1 se il risultato ha causato un riporto oltre l’ultimo bit più significativo.
- A: posto a 1 se si è verificato un riporto oltre il terzo bit (riporto ausiliario).
- P: posto a 1 se il risultato è pari.

### Core i7
#### Panoramica del livello ISA Intel Core i7
Mantiene completo supporto per l'esecuzione di programmi scritti per 8086 e 8088 (che avevano lo stesso ISA). Fino all'80286 il bus indirizzi era a 16 bit e si potevano indirizzare 16.384 segmenti di 64 KB. 
A partire dal x386 nasce una nuova architettura nota come IA-32 su cui si basano tutti gli attuali processori Intel. I cambiamenti introdotti dall'x386 sono le istruzioni MMX, SSE ed SSE2 nate per applicazioni multimediali.
Un'altra evoluzione importante è l'ampliamento del bus a 64 bit (x86-64).

#### Modalità operative di Intel Core i7
Il core i7 ha 3 diverse modalità operative:
1. Modalità reale: si comporta come un 8088, ma nel caso in cui vengono eseguite istruzioni errate, la macchina va in blocco. 
2. Modalità virtuale: permette di eseguire programmi 8088 in modo protetto e controllato da un vero SO.
3. Modalità protetta: si comporta come un Pentium 4 e non un 8088 molto costoso con 4 privilegi controllati da bit di PSW:
	- Livello 0 (modalità kernel): Usato dal SO
	- Livello 1 e 2: usati raramente
	- Livello 3: usato dai programmi utente in modo protetto

#### Registri di Intel Core i7
Il Core i7 ha 4 registri di uso generale (tutti a 32 bit):
- EAX: usato per le operazioni aritmetiche 
- EBX: usato per contenere puntatori ad indirizzi di memoria
- ECX: usato nei cicli
- EDX: è necessario per le moltiplicazioni e le divisioni durante le quali contiene con EAX prodotti e dividendi di 64 bit.
Tutti questi registri possono essere utilizzati a 16 o 8 bit

![[img36.png|center|500]]


Ulteriori 4 registri a 32 bit con caratteristiche specifiche sono:
- ESI: puntatore in memoria alla stringa sorgente.
- EDI: puntatore in memoria alla stringa destinazione.
- EBP: referenzia l’indirizzo base del record di attivazione corrente (analogo al registro LV della IJVM).
- ESP: Puntatore allo stack (come SP di IJVM).

![[img37.png|center|500]]

Poi sono presenti:
- I registri segmento (tutti a 16 bit) che derivano dalla compatibilità dell’indirizzamento a 16 bit dell’8088:  CS, SS, DS, ES, FS e GS.
- Il Program Counter che è EIP (Extender Instruction Pointer).
- L’insieme dei bit dei flag della program status word EFLAGS.

![[img38.png|center|500]]

# Capitolo 8 (Da vedere con sistemi operativi)
## Architetture per il calcolo parallelo
---
L'obiettivo principale dell'industria dei computer è sempre stato quello di incrementare la performance.
In passato questo è stato possibile incrementando la frequenza del clock. Poi, con l'aiuto della teoria della relatività, si capì che nessun segnale elettrico può propagarsi più velocemente della velocità della luce. 
Un computer con un clock di 1 THz dovrebbe essere piccolissimo (100 µm). Rendere un computer di queste dimensioni è possibile ma si presenterebbe un ulteriore problema, cioè la dissipazione del calore.
Quindi per ottenere una maggiore potenza di calcolo ci si affidò alle architetture parallele: **molte CPU (con velocità normale) che collaborano per per raggiungere lo stesso obiettivo**.

La classificazione si basa su due concetti: il flusso di istruzioni ed il flusso di dati.

![[img39.png|center|500]]

### Parallelismo
Il parallelismo nel chip aiuta a migliorare le performance della CPU: con il pipelining e le architetture superscalari si può arrivare ad un fattore di miglioramento da 5 a 10.
Per incrementare drasticamente le performance di un calcolatore occorre progettare sistemi con molte CPU, con cui si arriva ad un fattore di miglioramento di 50, 100 o anche più.
Esistono 3 diversi approcci:
- Data Parallel Computer (SIMD)
- Multiprocessori e Multicomputer (MIMD)

![[img40.png|center|500]]

- **[[#Parallelismo a|Parallelismo a livello di istruzione]]**: l'idea è di emettere più istruzioni per ciclo di clock utilizzando processori superscalari e processori con più parole di istruzione molto lunghe
- **[[#Multithreading|Multithreading nel chip]]**: la CPU esegue contemporaneamente due thread (parti di programma) come se esistessero due CPU virtuali. Se uno dei due deve attendere ad esempio per un cache-miss (sia di primo che di secondo livello) l’altro può continuare l’esecuzione evitando di lasciare la CPU in attesa. Serve per superare lo stallo che si verifica nelle pipeline quando si accede ad un indirizzo assente nella cache
- **[[#Multiprocessori in un solo chip|Multiprocessori in un solo chip]]**: più core sullo stesso chip che condividono cache e memoria principale. Consente un vero multi-threading e permette in molti casi di aumentare notevolmente le prestazioni.

#### Parallelismo a livello di istruzione 
A livello delle istruzioni, un modo per ottenere il parallelismo è emettere più istruzioni per ciclo di clock. Ci sono due tipi di CPU a emissione multipla: i processori superscalari e i processori VLIW.

![[img41.png|center|500]]

##### Pipelining
Da anni è ovvio che uno dei maggiori [colli di bottiglia](https://it.wikipedia.org/wiki/Collo_di_bottiglia_(ingegneria)) è rappresentato dal fetch delle istruzioni in memoria. Fin dal modello IBM Stretch (1959), per alleviare questo problema, i calcolatori sono stati dotati della capacità di poter prelevare in anticipo le istruzioni dalla memoria, in modo da averle già a disposizione nel momento in cui dovessero rendersi necessari. Le istruzioni venivano memorizzate in un insieme di registri chiamati **buffer di prefetch**, dai quali potevano essere prese nel momento in cui venivano richieste, senza dover attendere che si completasse una lettura della memoria. La tecnica di prefetching suddivide l'esecuzione dell'istruzione in due parti: il prelievo e la sua esecuzione. 

Il concetto di pipeline spinge questa strategia molto più avanti; invece di dividere l'esecuzione di un'istruzione in due fasi, la si divide in un numero maggiore di parti (12 o più) che possono essere eseguite in parallelo; ciascuna di queste parti è gestita da componenti hardware dedicati. 

![[img42.png|center|500]]

Durante il primo ciclo di clock lo stadio S1 sta lavorando sull'istruzione 1, prelevandola dalla memoria. Durante il ciclo di clock 2 lo stadio S2 decodifica l'istruzione 1, mentre lo stadio S1 preleva l'istruzione 2. Durante il ciclo 3 lo stadio S3 preleva gli operandi per l'istruzione 1, lo stadio S2 decodifica l'istruzione 2 e lo stadio S1 preleva la terza istruzione. Durante il quarto ciclo lo stadio S4 esegue l'istruzione 1, S3 preleva gli operandi per l'istruzione 2, S2 decodifica l'istruzione 3 e S1 preleva l'istruzione 4. Infine, durante l'ultimo ciclo S5 scrive il risultato dell'istruzione 1, mentre gli altri componenti lavorano sulle istruzioni successive. 

###### Il problema dello stallo della pipeline
Questo problema si verifica quando una CPU tenta di accedere ad un riferimento in memoria non presente nella cache e quindi attende il caricamento prima di riprendere l'esecuzione. 
Il multithreading nel chip permette di mascherare queste situazioni attraverso lo switch tra thread. Esistono approcci differenti:
- [[#Multithreading a grana fine|Multithreading a grana fine]]
- [[#Multithreading a grana grossa|Multithreading a grana grossa]] 
- [[#Multithreading simultaneo|Multithreading simultaneo]] 

Supponiamo di avere una CPU che emette una istruzione per ciclo di clock con tre thread A, B e C. Durante il primo ciclo A, B e C eseguono le istruzioni A1, B1 e C1. Purtroppo al secondo ciclo di clock A2 fa un riferimento non presente nella cache di primo livello e deve attendere 2 cicli per recuperarlo dalla cache di secondo livello.

![[img43.png|center|500]]

###### Pipe
Il pipe è uno pseudo-file che permette a due processi di comunicare tra loro, ma affinché questi due processi possano comunicare attraverso una pipe, essa deve essere inizializzata in anticipo. Il processo A, che vuole inviare dati al processo B, deve scrivere sulla pipe come fosse un file in uscita. Il processo B, per leggere i dati inviati da A, legge la pipe come se fosse un file in entrata.

#### Multithreading
Indica il supporto hardware da parte di un processore di eseguire più thread. Questa tecnica si distingue da quella alla base dei sistemi multiprocessore per il fatto che i singoli thread condividono lo stesso spazio di indirizzamento e la stessa cache. Il multithreading migliora le prestazioni dei programmi solamente quando questi sono stati sviluppati suddividendo il carico di lavoro su più thread che possono essere eseguiti in parallelo.

##### Multithreading a grana fine
Sono eseguite ogni ciclo di clock, a turno, le singole istruzioni dei thread. Nei due cicli di stallo la CPU svolge le istruzioni degli altri due thread. Poiché non c'è alcuna relazione tra i thread, ciascuno ha il proprio insieme dei registri. Il numero massimo di thread concorrenti è definito a priori in fase di progettazione del chip.
Le operazioni in memoria non sono l'unica ragione di stallo: alcune istruzioni condizionano l'esecuzione di altre.
Nella pipeline non ci sarà mai più di una istruzione per thread e quindi il numero massimo di thread è pari al numero di stadi della pipeline.

##### Multithreading a grana grossa
Un thread va avanti finchè non raggiunge uno stallo, perde un ciclo e commuta su un altro thread. Perde un ciclo ogni stallo ed è inefficiente rispetto al multithreading a grana fine. Richiede meno thread per mantenere occupata la CPU.
Esiste una variante che permette di “guardare avanti” le istruzioni anticipando lo stallo e approssimando il multithreading a grana fine.

###### Multithreading a CPU superscalari 
Le CPU possono avere più unità in parallelo ed emettere più istruzioni per ciclo.

![[img44.png|center|500]]

In ogni thread sono eseguiti due istruzioni per ciclo finché non si raggiunge uno stallo

![[img45.png|center|500]]

##### Multithreading simultaneo
Ciascun thread emette due istruzioni per ciclo finché non si raggiunge uno stallo. A questo punto si passa all'istruzione del thread che segue affinché la CPU rimanga impiegata

#### Multiprocessori in un solo chip
Con l'avanzare della tecnologia, i transistor sono diventati più piccoli ed è stato possibile incrementare il loro numero in un singolo chip.
A causa del raggiungimento dei limiti fisici dei materiali non è stato possibile incrementare la frequenza di clock per ottenere CPU veloci. Per tale ragione le industrie produttrici di chip hanno incominciato ad inserire più CPU (core) all’interno dello stesso chip.
I multiprocessori possono essere realizzati con core identici (multiprocessori omogenei) oppure con core con specifiche funzionalità (multiprocessori eterogenei).

##### Multiprocessori omogenei in un solo chip
Le CPU che contengono più processori che condividono cache e memoria principale, sono dette multiprocessori. Esistono 2 tecnologie di multiprocessore in un solo chip:
- Quelle con una sola CPU e più pipeline che possono moltiplicare il throughput in base al numero di pipeline. Le unità funzionali sono intimamente correlate
- Quelle che hanno più CPU ciascuna con la propria pipeline. L'interazione tra CPU non è semplice poiché risultano maggiormente disaccoppiate.
Mentre le CPU possono o meno condividere la cache, esse condividono sempre la memoria principale.
Il processo di snooping (eseguito dall’hardware) garantisce che se una parola è presente  in più cache e una CPU modifica il suo valore in memoria, essa è automaticamente rimossa in tutte le cache in modo da garantire consistenza.

##### Multiprocessori eterogenei in un solo chip
Oltre ai multicore simmetrici esiste un altro tipo di chip multicore in cui ogni core ha un compito specifico.
-   poiché queste architetture realizzano un vero e proprio calcolatore completo in un singolo chip sono spesso dette system on a chip.
Come accaduto spesso nel passato, l’hardware è molto più avanti del software: non abbiamo applicazioni in grado di sfruttare queste nuove caratteristiche.
Pochi programmatori sono in grado di scrivere algoritmi paralleli che gestiscono correttamente la competizione delle risorse condivise.

##### Chip-level multiprocessors
I chip multicore sono come dei piccoli multiprocessori e per questa ragione vengono chiamati CMP (Chip-level Multiprocessors ovvero multiprocessori a livello di chip).
Dal punto di vista software essi non sono così differenti dai multiprocessori a bus o a reti di switch. Rispetto a multiprocessori a bus che hanno una cache per ogni CPU, potrebbero avere delle prestazioni degradate sulla cache condivisa nelle situazioni in cui un core “ingordo” saturi la cache L2. Altra differenza rispetto ai multiprocessori è la minore tolleranza ai malfunzionamenti causati dalla stretta connessione dei core.

#### Coprocessori
È possibile velocizzare il calcolatore mediante l'aggiunta di un secondo processore detto "coprocessore" che permette di migliorare le performance del calcolatore.
Esistono vari tipi di coprocessori:
- Processori di rete
- Processori grafici
- Crittoprocessori

#### MIMD
Tutte le comunicazioni tra componenti elettronici avvengono attraverso lo scambio di messaggi.
Le principali differenze tra MIMD risiedono nella base dei tempi, nella scala delle distanze e nell'organizzazione logica utilizzata.

#### Caching
Il caching è il processo di memorizzazione dei dati in un luogo separato (chiamato cache) in modo tale che sia possibile accedervi più rapidamente se gli stessi dati vengono richiesti in futuro. Quando vengono richiesti alcuni dati, la cache viene prima controllata per vedere se contiene quei dati. Se i dati sono già nella cache, la richiesta può essere soddisfatta più velocemente.

#### Multiprocessori e multicomputer (MIMD)
Si possono aumentare ulteriormente le prestazioni delle macchine con la combinazione di più CPU per formare sistemi più grandi. Questi sistemi si dividono in:
- Multiprocessori: calcolatore in cui tutte le CPU condividono una memoria comune. Tutti i processi che cooperano in un multiprocessore possono condividere un solo spazio degli indirizzi virtuali mappato nella memoria comune
- Multicomputer: architettura parallela che prevede per ogni CPU una memoria virtuale privata, accessibile solo da essa e non dalle altre. Questo aspetto distingue un multiprocessore da un multicomputer.

Ci sono vari tipi di multiprocessori e multicomputer:
- **Multiprocessori a memoria condivisa**: meno di 1000 CPU comunicano attraverso una memoria condivisa; il tempo di accesso ad una parola è 2-10 ns.
- **Multicomputer a scambio di messaggi**: un certo numero di coppie memoria-CPU sono collegati attraverso una rete di interconnessione ad alta velocità; le comunicazioni avvengono attraverso brevi messaggi che possono essere spediti in 10-50 µs; ogni memoria è locale a ciascuna CPU 
- **Sistemi distribuiti**: computer distribuiti su un'area geografica estesa come Internet, i messaggi impiegano da 10 a 100 ms.

##### Hardware dei multiprocessori
Esistono due differenti tipologie di multiprcoessori:
- Multiprocessori UMA (Uniform Memory Access): ogni parola di memoria può essere letta alla stessa velocità
- Multiprocessori NUMA (Non-uniform Memory Access): non tutte le parole di memoria possono essere lette alla stessa velocità.

##### UMA con architettura basata su bus
I più semplici multiprocessori sono basati su un singolo bus che interconnette tutte le CPU alla memoria condivisa.

![[img46.png|center|350]]

Una CPU che vuole leggere/scrivere una parola in memoria, se il bus è occupato, deve attendere che si liberi. Questa architettura funziona bene con due o tre CPU. Per aumentare il numero di CPU occorre aumentare il numero di memorie.

##### UMA con singlo bus e cache nelle CPU
L'aggiunta di una memoria cache all'interno delle singole CPU può ridurre il traffico sul bus e il sistema può sopportare anche più di 3 CPU

![[img47.png|center|350]]

Il [[#Caching|caching]] non viene eseguito sulle singole parole di memoria ma su blocchi di 32 o 64 byte. Quando una parola è referenziata, l’intero blocco che la contiene, chiamato linea di cache, è caricato nella CPU che l’ha richiesta.
Ogni blocco di cache è contrassegnato come READ-ONLY oppure READ/WRITE.
Se una CPU scrive una parola che è contenuta anche in altri blocchi di cache remote, l’hardware del bus percepisce la scrittura e lo segnala alle altre cache che possono avere:
-   una copia “pulita” del blocco di memoria, allora la cache la sovrascrive con il valore aggiunto
-   una copia modificata del blocco di memoria (detta “copia sporca”), allora la cache lo deve prima trascrivere in memoria e poi applicare la modifica
L’insieme di tali regole, utilizzate per la gestione della cache è chiamato **protocollo di coerenza della cache**.

##### UMA con singolo bus e CPU dotate di RAM
Un'altra soluzione è con l'aggiunta di memorie RAM in un bus dedicato per ogni CPU 

![[img48.png|center|250]]

A questo punto la memoria condivisa è utilizzata esclusivamente per scrivere variabili condivise (globali). Questa soluzione riduce il traffico sul bus ma richiede una collaborazione attiva del compilatore che deve separare gli oggetti locali da quelli globali.

##### UMA con crossbar switch
Anche con le migliori tecniche di caching, l’uso di un singolo bus di interconnessione limita la dimensione del multiprocessore UMA a 16 o 32 CPU.
Per andare oltre, occorre utilizzare una differente rete di interconnessione. Il circuito più semplice che permette di collegare $n$ CPU a $k$ memorie è il **crossbar switch**.

![[img49.png|center|400]]

Ad ogni intersezione tra una linea orizzontale (CPU) e una verticale c'è un **crosspoint**, un commutatore che può essere aperto o chiuso, a seconda che si voglia collegare o meno le linee corrispondenti. 
Un vantaggio di questo sistema è che si crea una rete non bloccante, ovvero non succede mai che venga negata a una CPU la connessione di cui ha bisogno perché la linea è già occupata. 
Non è necessaria alcuna azione di pianificazione anticipata, perché è sempre possibile connettere una CPU ad una nuova memoria. 
Rimane il problema della competizione per la memoria, qualora due, o più, CPU vogliono accedere allo stesso modulo nel medesimo istante.
Una delle peggiori caratteristiche di questo schema è che il numero di crosspoint cresce come $n^2$
- Con 1000 CPUs e 1000 moduli di memoria occorrono un milione di crosspoints. Costruire una crossbar di queste dimensioni non è fattibile.

##### UMA con reti a commutazione multilivello
Una progettazione differente è basata su commutatori 2x2 (2 input, 2 output); i messaggi che arrivano nelle due linee di ingresso possono scambiarsi in una delle due linee di uscita. 
Ogni messaggio contiene:
- quale memoria utilizzare 
- l'indirizzo del modulo
- il codice dell'operazione
- il valore di un operando
Lo switch utilizza il campo module per scegliere dove spedire il messaggio.
Una rete economica e semplice è la rete **Omega**

![[img50.png|center|500]] 

Sono state connesse 8 CPU ad 8 memorie con 12 switch. Per $n$ CPU e $n$ memorie sono necessarie $\log_2 n$ stadi per un totale di $(\frac{n}{2})\log_2 n$ switch. 
Lo schema di connessione è detto shuffle perfetto. A differenza del crossbar la Omega è una rete 
bloccante, non tutti gli insiemi di richieste possono essere processati contemporaneamente.

##### Multiprocessori NUMA
Forniscono un singolo spazio degli indirizzi a tutte le CPU.
In un processore NUMA il tempo di accesso ai moduli di memoria locale è minore rispetto a quello dei moduli remoti, tutti i programmi UMA girano in quelli NUMA, ma avranno performance degradate.
Le macchine NUMA hanno 3 caratteristiche chiave: 
1. c’è un singolo spazio degli indirizzi visibile a tutte le CPU
2. l’accesso in memoria remota avviene tramite istruzioni LOAD e STORE   
3. l’accesso alla memoria remota è più lento rispetto all’accesso in memoria locale
Quando il tempo di accesso in memoria è nascosto, si parla di NC-NUMA(Non-Cache NUMA); mentre quando sono presenti cache coerenti, si parla di CC-NUMA(Cache-Coherent NUMA)
L’approccio migliore per la creazione di grandi sistemi multiprocessore CC-NUMA è il multiprocessore basato su directory.
L’idea che sta alla base è quella di mantenere un DB che indica dove sia ciascuna linea di cache e quale sia il suo stato; quando si ha un riferimento ad una linea di cache, si interroga il DB perchè trovi dov'è e se è pulita o sporca (modificata). Occorre mantenere il DB in un hardware veloce.

##### Tipi di SO multiprocessore 
Esistono diverse organizzazioni. Le più usate sono:
- ogni CPU ha il proprio SO
- multiprocessori master-slave
- multiprocessori simmetrici

###### Ogni CPU ha il proprio SO
In questa organizzazione la memoria è divisa in partizioni, tante quante sono al CPU, fornendo ad ogni CPU la propria memoria virtuale e il proprio SO. 
Bisogna ricordare 4 aspetti fondamentali di questa organizzazione:
1. Quando un processo fa una system call, essa viene intercettata dalla propria CPU, utilizzando le proprie strutture dati.
2. Ogni CPU ha il proprio insieme di processi, che schedula per conto proprio. Non c'è condivisione dei processi, e può capitare che se la CPU 1 è inattiva, la CPU 2 è carica di lavoro (non c'è bilanciamento del carico)
3. Non c'è condivisione delle pagine e non c'è alcun modo di ottenere pagine da una CPU all'altra
4. Se il sistema operativo mantiene una cache dei blocchi del disco recentementi usati, ciascun SO lo farà in modo indipendente; è possibile che un certo blocco sia presente e "sporco" in più CPU contemporaneamente. Per eliminare questo problema, basterebbe eliminare la cache, ma ciò provocherebbe un abbassamento delle prestazioni.

###### Multiprocessori master-slave
In questa organizzazione, una sola CPU contiene il SO e le tabelle delle pagine, mentre le altre eseguono processi utente. Questa organizzazione viene chiamata **master-slave** dato che la CPU 1 è il padrone (master) e le altre gli schiavi (slave). Questo modello risolve la maggior parte dei problemi del modello precedente; infatti non accade mai che una CPU sia inattiva e un'altra carica di lavoro. C'è però uno svantaggio: con tanti slave, il master potrebbe diventare il collo di bottiglia del sistema, perché deve gestire tutte le system call degli slave

###### Multiprocessori simmetrici
Gli SMP (Symmetric MultiProcessor) eliminano questa asimmetria: in memoria è presente una copia del SO, ma ogni CPU può eseguirlo. La CPU che ha eseguito la system call, effettua una trap al kernel ed elabora la richiesta.
Ogni CPU può diventare il master della struttura. Questo modello bilancia i processi e la memoria dinamicamente, elimina il collo di bottiglia della CPU master, ma ha qualche svantaggio: se due o più CPU eseguono il codice del SO in contemporanea, avverrà un disastro.
Per evitare questi problemi, il modo più semplice è associare un mutex al SO, rendendo questo una grande regione critica. Quando una CPU vuole eseguire un codice del SO, deve prima acquisire il mutex: se è occupata, la CPU resta in attesa.

#### Sincronizzazione dei multiprocessori
Le CPU dei multiprocessori vanno sincronizzate di frequente.
Per essere sincronizzate occorrono primitive di sincronizzazione appropriate. Tutte le CPU devono usare e rispettare un protocollo mutex appropriato. Per garantire la mutua esclusione, il cuore di ogni mutex e l'istruzione TSL. Per implementare le regioni critiche in un multiprocessore, l'istruzione TSL deve bloccare il bus, poi effettuare entrambi gli accessi in memoria e infine sbloccare il bus. Il lock del bus avviene richiedendolo al bus stesso, per mezzo del protocollo ordinario di richiesta, quindi ponendo a livello logico alto (cioè 1) una linea speciale del bus.

Se TSL è implementata in maniera corretta, la mutua esclusione viene sempre garantita. Questo modello è detto **spin lock**.

#### Scheduling dei multiprocessori
In un multiprocessore lo scheduling è bidirezionale, cioè lo scheduler deve scegliere quale processo schedulare e su quale CPU.
Ci sono 3 tipi di scheduling: 
- Timesharing
- Condivisione dello spazio
- Schedulazione gang

##### Timesharing
L'algoritmo di scheduling a timesharing viene usato **solo quando i processi sono indipendenti**.
Utilizza un vettore di liste e thread (tutti nello stato ready) a diverse priorità di esecuzione. Questa schedulazione con una sola struttura dati, utilizzata da tutte le CPU, ripartisce il tempo tra le CPU come se ci trovassimo in un multiprocessore, fornendo anche un bilanciamento del carico automatico.
I due svantaggi sono:
- potenziale contesa per la struttura di schedulazione
- overhead nell'effettuare il context-switch tra i processi che si bloccano su I/O
Se un processo tiene un lock gestito da ciclo di attesa, le altre CPU sprecano tempo per ciclare in attesa che il processo rilasci il lock. Per ovviare a questo problema si utilizza lo smart scheduling, in cui un processo con un lock, utilizza un flag a livello di processo per evidenziare che detiene correntemente il lock; quando rilascia il lock, azzera il flag. Lo scheduler non ferma un processo che detiene il lock, ma gli concede un po' di tempo in più.

Alcuni multiprocessori utilizzano lo scheduling per affinità: l'idea di base è quella di eseguire un processo sulla stessa CPU dove è stato eseguito l'ultima volta.
Un modo per implementare ciò è la schedulazione a due livelli: quando un processo viene creato, viene assegnato ad una CPU e tale assegnazione costituisce il livello superiore dell'algoritmo.
Come risultato otteniamo che ogni CPU acquisisce il proprio insieme di processi. Ci sono 3 vantaggi:
1. il carico tra le CPU è distribuito in modo paritario
2. sfrutta l'affinità della cache
3. viene minimizzata la contesa tra le liste

##### Condivisione dello spazio (space sharing)
Questo modello si può utilizzare quando i processi sono correlati tra di loro. 
Funziona così: supponiamo di creare un insieme di thread contemporaneamente; in quel momento lo scheduler controlla se ci sono tante CPU libere quanti sono i thread. Se esistono, assegnano ogni thread alla CPU dedicata e partono tutti insieme; se non ci sono abbastanza CPU, non va in esecuzione nessun thread, finché non è disponibile un numero di CPU adeguato. In ogni istante, l'insieme delle CPU è suddiviso in un certo numero di partizioni, ciascuna delle quali esegue i thread di un processo.

Un vantaggio dello space sharing è che elimina l'overhead dovuto al context-switch. Uno svantaggio è il tempo perso per il blocco di una CPU.

##### Schedulazione gang
Una soluzione ai problemi dello space sharing è la schedulazione gang, uno sviluppo della co-schedulazione . È costituita di 3 parti:
1. gruppi di thread correlati sono schedulati come un'unità;
2. tutti i membri di una gang sono in esecuzione contemporaneamente, in differenti CPU in time sharing
3. tutti i membri di una gang iniziano e finiscono nello stesso istante
Questo modello funziona perché tutte le CPU sono schedulate in sincronia; questo significa che il tempo è suddiviso in quanti discreti.
All'inizio di un nuovo quanto, tutte le CPU sono di nuovo schedulate e un nuovo thread inizia su ciascuna di esse.
L'idea di questo modello è quella di avere tutti i thread di un processo in esecuzione in contemporanea, cosicché se uno di essi manda una richiesta all'altro, quest'ultimo riceverà il messaggio e sarà in grado di rispondere quasi immediatamente.

#### Multicomputer
I multiprocessori offrono un modello semplice di comunicazione: tutte le CPU condividono una memoria comune. I thread possono scrivere messaggi in memoria che possono essere letti da altri thread. La sincronizzazione può essere fatta utilizzando una mutex, semafori o monitor. I multiprocessori di grandi dimensioni, però sono difficili da costruire e perciò risultano costosi.

Per ovviare a questi problemi sono nati i multicomputer che sono fortemente accoppiati ma non condividono memoria (ogni computer ha la sua). Questi sistemi sono chiamati anche Cluster di Computers o Cluster di workstations. I multicomputer sono facili da costruire perché il componente base è un PC con una scheda di rete con alte performance. Il segreto per ottenere alte performance in un multicomputer è nel progetto della rete di interconnesione e delle schede di rete. I messaggi sono spediti in un tempo dei $\mu$s, mille volte in meno rispetto ad un accesso in memoria (ordine dei ns). Il progetto è quindi più semplice da realizzare ed allo stesso tempo economico. 

##### Hardware dei multicomputer (Topologia)
Il nodo base di un multicomputer consiste di una CPU, una memoria ed un'interfaccia di rete. Ogni nodo ha un'interfaccia di rete con uno o due cavi (o fibra) che lo connette agli altri nodi oppure agli switch

In un sistema piccolo potrebbe essere presente uno switch attraverso il quale sono connessi tutti i nodi

![[img51.png|center|150]]

Un'altra rete di interconnessione è la topologia ad anello: ogni nodo è connesso ad altri due nodo in ordine per formare un anello circolare (non sono necessari switch).

![[img52.png|center|150]]

La topologia a griglia (grid) o maglia (mesh) è una struttura bidimensionale utilizzata in molti sistemi complessi. La sua forma regolare la rende altamente scalabile. Il percorso più lungo tra due nodi, aumenta come $\sqrt n$ sul numero $n$ di nodi. 

![[img53.png|center|150]]

Il doppio toro è una variante della griglia, ma con i nodi estremi che si congiungono, è più tollerante ai guasti ma ha un diametro più piccolo. 

![[img54.png|center|150]]

Il cubo è una topologia tridimensionale regolare

![[img55.png|center|150]]

Un cubo di dimensione 4 si può ottenere da uno di dimensione 3 ed è detto ipercubo. Molti computer paralleli utilizzano questa topografia perché il diametro cresce in modo logaritmico con la dimensione.
Diametro = $\log_2 n$ con n nodi.
Un cubo di dimensione n + 1 si può ottenere da uno di dimensione n in modo ricorsivo.

![[img56.png|center|250]]

Nei multicomputer sono utilizzati due tipi di schemi di switching:
1. store and forward packet switching 
2. circuit switching

##### Store and forward packet switching
Ogni messaggio è suddiviso in pacchetti che sono poi inseriti nella rete. Il pacchetto raggiunge il nodo destinatario attraverso delle politiche di instradamento che dipendono da vari fattori (traffico dati, priorità).
È flessibile ed efficiente ma ha il problema dell'incremento dei tempi di latenza lungo la rete di interconnessione.

##### Circuit swtiching
Nel secondo schema il primo switch stabilisce un collegamento fisico, attraverso tutti gli switch coinvolti, fino allo switch del nodo di destinazione. Una volta che la connessione è creata i bit sono spediti alla massima velocità possibile (gli switch intermedi non hanno la necessità di memorizzare i dati in transito).
-   Richiede una fase di inizializzazione che prende tempo, ma una volta terminata il processo è velocissimo.
Una variante del circuit switching è il **wormhole routing** (instradamento verso la tana del verme), spezza il pacchetto in sottopacchetti e permette a quest’ultimi di iniziare il tragitto prima che sia stato inizializzato il collegamento.

##### Interfacce di rete 
Tutti i nodi di un multicomputer hanno una scheda di rete per consentire la connessione del nodo alla rete di interconnessione.
La scheda di interfaccia contiene della RAM per conservare i pacchetti in ingresso/uscita, che vanno copiati nella RAM della scheda di interfaccia, prima di poter essere trasmessi al primo switch.
La scheda di interfaccia può avere uno o più canali DMA, o anche una CPU completa (Processore di rete). I canali DMA possono copiare i pacchetti fra la scheda di interfaccia e la RAM principale ad alta velocità, trasferendo quindi diverse parole senza dover richiedere il bus per ogni parola. 

#### Software di comunicazione a basso livello
Il nemico peggiore della comunicazione ad alte prestazioni è l’eccesso di copia dei pacchetti: nel migliore dei casi avremo una copia dalla RAM alla scheda di interfaccia, una copia dall’interfaccia del sorgente a quella di destinazione, e una copia da li alla RAM di destinazione, per un totale di 3 copie.
Per evitare questo numero di copie in eccesso, e l’abbassamento delle prestazioni, alcuni multicomputer mappano la scheda di interfaccia direttamente nello spazio utente, permettendo al processo utente di mettere i pacchetti direttamente sulla scheda, senza interpellare il kernel.
Sorgono però 2 problemi:
- Il primo problema sta nella competizione di due o più processi, concorrenti sullo stesso nodo, che vogliono spedire un pacchetto. Una possibile soluzione è quella di mappare la scheda di interfaccia in tutti i processi che se ne servono, però occorre un meccanismo per evitare le corse critiche.
- Il secondo problema sta nella condivisione della scheda di rete tra il kernel, che magari vuole accedere ad un file system remoto, ed il processo utente. La soluzione ottimale è quella di utilizzare 2 schede di rete diverse per ciascuna funzione: una nello spazio utente per il traffico di applicazioni, l’altra nello spazio kernel per il SO

#### Software di comunicazione a livello utente
I processi sulle diverse CPU di un multicomputer comunicano attraverso lo scambio di messaggi; nella forma più semplice lo scambio di messaggi è visibile al processo utente.

##### Send e Receive
I servizi di comunicazioni possono essere ridotti a 2 chiamate di sistema, una per inviare (send) messaggi e l’altra per leggerli (receive)

```C
send(dest, &mptr)
receive(addr, &mptr)
```

Poiché in un multicomputer il numero di CPU è noto a priori, il campo addr si compone di due parti:
1.  Identificativo della CPU
2.  Identificativo del processo o della porta sulla CPU selezionata

###### Primitive bloccanti e non bloccanti
Le primitive viste prima sono dette bloccanti (a volte anche sincrone): quando un processo utente chiama la send, specifica la destinazione e il buffer da spedire a quella destinazione. Mentre il messaggio viene inviato, il processo si blocca; l’istruzione dopo la send non viene eseguite finché il messaggio non viene spedito.

Un’alternativa a questo è rappresentato dalle primitive non bloccanti (dette anche asincrone). La send non bloccante restituisce immediatamente il controllo al processo utente, prima che il messaggio venga spedito; il vantaggio è che il mittente può continuare ad eseguire calcoli in parallelo alla trasmissione del messaggio, anziché lasciare inattiva la CPU. La scelta tra primitive bloccanti o non bloccanti viene fatta dai progettisti del sistema.
Oltre al grosso vantaggio delle primitive non bloccanti, esse presentano un grosso svantaggio: il mittente non ha idea di quando il destinatario ha ricevuto il messaggio, e quindi non sa quando può operare sul buffer contenente il messaggio senza fare danni.

Ci sono 3 possibili soluzioni.
- il kernel si crea una copia del messaggio in un buffer interno. svantaggio : eccesso di copie
- generare un’interrupt verso il mittente quando il messaggio viene effettivamente spedito,per informarlo che il buffer è di nuovo utilizzabile. svantaggio: la gestione degli interrupt a livello utente rende la programmazione complessa, e potrebbe portare a molte race condition
- marcare il buffer come copia in scrittura (copy-on-write), cioè marcare il buffer in sola lettura finché il messaggio non viene spedito. svantaggio: eccesso di copie.

Quindi, dal punto di vista del mittente, abbiamo queste scelte:
1.  send bloccante (CPU inattiva)
2.  send non bloccante con copia (spreco di tempo di CPU per la copia)   
3.  send non bloccante con interrupt (difficile la programmazione)
4.  copy-on-write (probabilità elevata di eccesso in scrittura)
In condizioni normali, la prima scelta è la migliore, sopratutto se sono disponibili thread multipli, così quando un thread si blocca con la send, gli altri svolgono altri lavori.

Anche la receive può essere bloccante o non.
Una receive bloccante sospende il mittente finchè il messaggio non è arrivato; una receive non bloccante invece dice al kernel dove si trova il buffer e ritorna quasi immediatamente.
Si possono usare gli interrupt per segnalare che il messaggio è arrivato, ma sono difficili da programmare e anche piuttosto lente, quindi è preferibile che il ricevente effettui il polling per i messaggi in ingresso,vutilizzando una procedura detta poll, che rileva se ci sono dei messaggi in attesa.

Un ulteriore schema è quello di creare e utilizzare, nello spazio degli indirizzi del processo ricevente, un thread pop-up ,appena arriva il messaggio. Dopo aver svolto il proprio lavoro, questo thread viene automaticamente distrutto.

Una variante consiste nell’eseguire il codice di ricezione direttamente nel gestore delle interruzioni. Per velocizzare il tutto, il messaggio stesso contiene l’indirizzo del gestore delle interruzioni, così da poter richiamare il gestore con poche istruzioni.
Il vantaggio è che non viene effettuata nessuna copia: il gestore preleva il messaggio dalla scheda di interfaccia e lo elabora al volo.
Questo metodo è detto **schema a messaggi attivi**

##### Remote Procedure Call (Chiamate di procedura remote)
L’unico problema del modello a scambio di messaggi è che il paradigma base, su cui è costruito tutto il processo, è l’I/O.
Per ovviare a questo problema Birrel e Nelson, hanno proposto di permettere ai programmi di chiamare procedure su altre CPU.
Quando il processo sulla macchina 1 chiama una procedura sulla macchina 2, il processo chiamante viene sospeso, e l’esecuzione della procedura avviene sulla macchina. L’informazione può essere trasportata attraverso i parametri, e tornare indietro attraverso i risultati della procedura.
Questa tecnica è nota come RPC(Remote Procedure Call) 
La procedura chiamante è nota come client, e quella chiamata come server. 
L’idea alla base è quella di far sembrare la chiamata di procedura remota il più possibile come una chiamata locale

I passi effettivi della RPC sono:
1.  chiamata da parte del client al client stub(piccola procedura di libreria,locale)
2.  impacchettamento dei parametri in un messaggio e system call per spedire il messaggio(l’impacchettamento dei messaggi è detto marshaling)
3.  il kernel spedisce il messaggio dalla macchina client a quella server
4.  il kernel passa il pacchetto in arrivo al server stub
5.  il server stub chiama la procedura al server
La risposta fa lo stesso percorso in direzione opposta.

###### Problemi implementativi
Esistono diversi problemi nascosti:
1. Con RPC il passaggio dei puntatori è impossibile, perchè il client ed il server hanno diversi spazi per gli indirizzi
2. Questo capita con i linguaggi debolmente tipati come il C, in cui è perfettamente legale scrivere una procedura che calcola il prodotto scalare di due vettori senza che se ne conosca la dimensione. Con RPC è impossibile che il client riesca a fare il marshaling dei pacchetti, se non ne conosce la dimensione
3. Non è sempre possibile dedurre i tipi di parametri
4. Questo è relativo all'uso delle variabili globali. Di norma le procedure chiamante e chiamata possono comunicare con le variabili globali. Se la procedura chiamata viene spostata su una macchina remota, il codice fallirà, perchè non sono più condivise le variabili globali

##### DSM (Distributed Shared Memory)
Molti programmatori preferiscono ancora un modello a memoria condivisa.
Si utilizza una tecnica chiamata DSM (Memoria Condivisa Distribuita).
Questa tecnica consiste nel fare avere ad ogni macchina la propria memoria e le proprie tabelle delle pagine. Quando una CPU effettua una LOAD o STORE su una pagina che non ha, avviene una trap, che localizza la pagina e chiede alla CPU che la possiede di inviarla e spedirla sulla rete di interconnessione.
Quando arriva, viene mappata e viene fatta ripartire l’istruzione che aveva provocato il fault.

### Virtualizzazione
Un sistema virtualizzato mantiene l’affidabilità di un sistema multicomputer ad un costo ridotto ed una maggiore semplificazione della manutenibilità. Un guasto sul server che gestisce le macchine virtuali produce un danno catastrofico rispetto a quello di un sistema virtualizzato (la probabilità di un guasto naturale hardware è più bassa rispetto ad un guasto naturale software)

#### Vantaggi della virtualizzazione
- un malfunzionamento su una macchina virtuale non inficia il comportamento delle altre
- la riduzione delle macchine fisiche riduce lo spazio, il consumo di energia, la produzione di calore quindi l’energia per il raffreddamento
- la creazione di checkpoint e la migrazione di macchine virtuali è più semplice rispetto ad un ambiente tradizionale   
- si possono far girare applicazioni legacy su ambienti obsoleti che non funzionerebbero con gli attuali hardware   
- i programmatori possono effettuare il test delle applicazioni su differenti SO senza disporre di hardware fisici e SO

#### Tipi di virtualizzazione
continuare quando necessario


