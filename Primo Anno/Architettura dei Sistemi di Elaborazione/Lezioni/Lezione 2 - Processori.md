# Processori
La **CPU** (*Central Processing Unit* ) è il "cervello" del computer e la sua funzione è quella di eseguire i programmi contenuti nella memoria principale prelevando le loro istruzioni. I componenti sono connessi tra di loro mediante un *bus*, cioè un insieme di cavi paralleli sui quali vengono trasmessi indirizzi, dati e segnali di controllo. I bus possono essere esterni alla CPU, per connetterla alla memoria e ai dispositivi I/O, oppure interni.
La CPU contiene anche una piccola memoria ad alta velocità, utilizzata per memorizzare i risultati temporanei e alcune informazioni di controllo. Questa memoria è costituita da un certo numero di registri, ciascuno dei quali ha una funzione e una dimensione predefinite.
Il registro più importante è il *contatore di istruzioni*, o **Program Counter** (PC), che punta alla successiva istruzione che dovrà essere prelevata per l'esecuzione. Un altro registro importante è il *registro istruzione corrente*, o **Instruction Register** (IR), contenente l'istruzione che si trova in fase di esecuzione.
![[Pasted image 20240314143429.png|center|400]]
## Organizzazione della CPU
La CPU è composta da registri ( generalmente da 1 a 32 ), dalla ALU e da alcuni bus che connettono fra loro le diverse parti. I registri alimentano due registri di input della ALU che mantengono i dati di ingresso mentre essa è occupata con l'esecuzione di alcune computazioni.
La ALU esegue alcune semplici esecuzioni sui suoi input, come addizioni e sottrazioni, e genera un risultato che viene memorizzato in un suo apposito registro di output.![[Pasted image 20240314143753.png|center|400]]
## Esecuzione dell'Istruzione
La CPU esegue ogni istruzione compiendo una serie di piccoli passi che, in linea generale, possono essere descritti nel seguente modo:
1. Prelevare la successiva istruzione dalla memoria per portarla nell'IR;
2. Modificare il PC per farlo puntare all'istruzione seguente;
3. Determinare il tipo dell'istruzione appena prelevata;
4. Se l'istruzione usa una parola in memoria, determinare dove si trova;
5. Se necessario, prelevare la parola per portarla in un registro della CPU;
6. Eseguire l'istruzione;
7. Tornare al punto 1 per iniziare l'esecuzione dell'istruzione successiva.
## Parallelismo a livello di istruzione
Il parallelismo può essere presente in due forme principali: a livello di istruzione e a livello di processore. Nella prima forma il parallelismo è sfruttato all'interno delle singole istruzioni per far sì che la macchina possa elaborarne un maggior numero al secondo, mentre nella seconda sono presenti più CPU che lavorano congiuntamente su uno stesso problema. Entrambi gli approcci hanno i propri pregi.
### Pipeling
Uno dei maggiori colli di bottiglia nella velocità di esecuzione delle istruzioni è rappresentato dal prelievo delle istruzioni dalla memoria. I calcolatori sono stati dotati delle capacità di poter prelevare in anticipo le istruzioni dalla memoria. in modo da averle già a disposizione nel momento in cui dovrebbero rendersi necessarie. Le istruzioni venivano memorizzate in un insieme di registri chiamati *buffer di prefetch*. Il concetto di **pipeline** spinge questa strategia molto più avanti; invece di dividere l'esecuzione di un'istruzione solamente in due fasi, la si divide in un numero maggiore di parti che possono essere eseguite in parallelo; ciascuna di queste parti è gestita da componenti hardware dedicati.![[Pasted image 20240314151226.png|center|500]]
### Multiprocessori
In un processore parallelo sui dati le unità di elaborazione non sono delle CPU indipendenti, dato che c'è un'unica unità di controllo condivisa fra tutte. Il primo sistema parallelo che analizziamo e che è composto da più CPU complete è il **multiprocessore**, cioè un sistema composto da più CPU con una memoria in comune. Dato che ogni CPU può leggere e scrivere una qualsiasi parte della memoria, esse devono coordinarsi per evitare di ostacolarsi a vicenda.