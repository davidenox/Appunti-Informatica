# Virtual memory
## Gestione della memoria : Outline
- Memory Abstractation;
- *Virtual Memory*;
- Algoritmi di sostituzione delle pagine;
- Problemi di progettazione per sistemi di paging.
## Il problema del bloatware e la crescita della memoria
Necessità di *gestire programmi che superano la capacità della memoria* disponibile.
Negli anni '60, introduzione di *tecniche per dividere programmi in parti gestibili*.
- *Overlay*: Sono piccole parti o segmenti di un programma.
- *Solo l'overlay necessario viene caricato in memoria*.
- Overlay successivi sovrascrivono o coesistono con quelli precedenti.
- Gli overlay vengono scambiati tra memoria e disco.
Originariamente, i programmatori dovevano suddividere manualmente i programmi in overlay ( soluzione tediosa e soggetta ad errori ).
## Memoria virtuale
La *memoria virtuale estende l'idea dei registri base e limite*.
- Ogni programma ha un proprio spazio degli indirizzi suddiviso in *pagine*, che sono intervalli di indirizzi contigui.
- Non tutte le pagine devono essere contemporaneamente nella memoria fisica:
	- L'hardware crea una mappa di quelle direttamente in memoria;
	- Se una pagina manca, il SO interviene.
- La maggior parte dei sistemi moderni usa il **Paging** ( paginazione ) :
	- Divisione dello spazio degli indirizzi in unità di dimensione fissa, es. 4Kb.
- *Alternativa*: **Segmentazione** con unità di dimensione variabile ( ora meno comune ).

*Problema*: 
- Finora la memoria può essere assegnata ai processi solo in blocchi contigui.
**Soluzione** ( *e vantaggio dell'uso della Memoria Virtuale* ):
- Creare per il processo l'illusione di uno spazio di indirizzi ampio ( ad esempio indicizzabile con 48 bit).
- Questo spazio è noto come spazio di indirizzi virtuale.
- La *RAM* (molto più limitata ) è nota come *memoria fisica*.
- **Memory Management Unit** ( MMU ): Traduce gli indirizzi virtuali ( come usati dal processo ) in indirizzi fisici.
![[Pasted image 20231122104849.png|center|400]]
### Memoria Virtuale e Paginazione
I sistemi moderni utilizzano la *Paginazione* ( o **Paging** ):
- Dividendo la memoria fisica e virtuale in pagine di dimensioni fisse;
- Traducendo le pagine virtuali in *pagine fisiche* ( *frame* ).
![[Pasted image 20231122105024.png|center|200]]
#### Spazio di indirizzamento virtuale vs Spazio degli indirizzi fisici, e page table
*Mappatura Memoria*:
- 16 pagine virtuali possono essere mappate in 8 frame fisici usando la MMU.
- Tuttavia, non tutte le pagine virtuali sono mappate fisicamente.
	- Quelle NON mappate sono contrassegnate con una X.
Se un programma fa riferimento a una pagina non mappata, si verifica un *Page fault*. Il SO allora:
- Sposta un frame raramente usato su disco, se serve;
- Carica la pagina richiesta nel frame libero o liberato;
- Aggiorna la mappa della MMU per riflettere i cambiamenti.
![[Pasted image 20231122112823.png|center|300]]
La *relazione* tra gli indirizzi di memoria virtuale e fisica è data dalla **Page Table**.
*Esempio*: Gestire istruzione:
- `MOV REG,32780`
Fa riferimento alla pagina virtuale 8.
- Indirizzo `12` della pagina:
- `32780-2^15 (32769) = 12`
Se non è mappata, il SO potrebbe decidere di sostituire il frame 1:
- Spostando il precedente su disco;
- Popolando il nuovo frame e puntando poi a:
	- `4108 = 4096 + 12`
Il page fault avviene nello spazio kernel durante il **trap** eseguito dal SO.
![[Pasted image 20231122113548.png|center|300]]

### Funzionamento interno della MMU
**Indirizzo virtuale**: 8196
	*Rappresentazione Binaria*: `0010 000000000100`
**Suddivisione dell'Indirizzo virtuale**:
- *Numero di pagina*: 4 bit ( permette di gestire 16 pagine ).
- *Offset*: 12 bit ( indirizza 4096 byte per pagina che compongono ogni frame ).
**Mappature tramite la Tabella delle Pagine**:
- Numero di pagina $\rightarrow$
	- Indice nella tabella delle pagine $\rightarrow$
		- Numero di frame.
![[Pasted image 20231122114045.png|center|400]]
#### Evoluzione degli indirizzi e tabella delle pagine
![[Pasted image 20231122114135.png|center|400]]
*Indirizzi nei nostri esempi*: 16 bit ( per chiarezza nelle illustrazioni ).
*Moderni PC*:
- Usano indirizzi a 32 o 64 bit.
- Con 32 bit e pagine da 4Kb:
	- 12 bit per indirizzare 4096 byte per pagina;
	- Tabella delle pagine di $2^{(32-12)}=2^{20}=1.048.576$ voci. Una taglia di 4Gb è "fattibile" anche per PC con pochi Gb di RAM.
*Indirizzi a 64 bit e pagine da 4Kb*:
- Richiede $2^{64}$ voci ($\sim 4,5\times 10^{15}$) nella tabella.
- In realtà nei sistemi a 64 bit si usano 48 bit.
	- 256 Tb bastano e avanzano, gli altri bit sono riservati per il futuro.
#### Come è composta una voce della Page Table?
Ogni voce ha informazioni cruciali come il numero del frame, come:
- *Bit Presente/Assente*: indica *se* la pagina virtuale *è in memoria*.
- *Bit Protezione*: Specifica i *tipi di accesso consentiti* (lettura, scrittura, esecuzione).
- *Bit Supervisor*: Stabilisce *se la pagina è accessibile* solo al SO o anche ai programmi utente.
- *Bit Modificato (M) e Riferimento (R)*: Registrano l'uso della pagina :
	- Il bit M si attiva quando la pagina viene scritta;
	- Il bit R viene impostato ogni volta che si accede alla pagina,
![[Pasted image 20231122120621.png|center|500]]
*Nota*: Per un processo l'indirizzo in memoria della "sua" tabella delle pagine è scritto nel registro Page Table Base Register ($\texttt{PTBR}$).
### Velocizzare la paginazione - Problemi chiave
*Mappatura Veloce*: Necessaria a ogni riferimento alla memoria. Ogni istruzione può richiedere più riferimenti alla tabella delle pagine.
- *Sfida*: Se un'istruzione impiega 1 ns, la ricerca nella tabella delle pagine deve essere inferiore a 0,2 ns per evitare colli di bottiglia.
**Dimensione della Tabella delle Pagine**:
- *Contesto*: Con 48 bit di indirizzamento e pagine di 4Kb, ci sono 64 miliardi di pagine. Una tabella delle pagine per questo spazio di indirizzi richiederebbe voci enormi.
- *Problema*: Usare centinaia di Gb solo per la tabella delle pagine è impraticabile. Ogni processo richiede una propria tabella delle pagine.
#### Approcci alla soluzione
**Tabella delle Pagine in Registri Hardware**:
- *Funzionamento*: Un registro hardware per ogni pagina virtuale, caricato all'avvio del processo.
- *Vantaggi*: Semplice, non richiede accessi alla memoria durante la mappatura.
- *Svantaggi*: Costoso con tabelle delle pagine grandi, ricaricare l'intera tabella ad ogni cambio di contesto è inefficiente.
**Tabella delle Pagine in Memoria Principale**:
- *Funzionamento*: La tabella delle pagine è interamente in RAM, con un registro che punta al suo inizio.
- *Vantaggi*: Facile da cambiare a ogni cambio di contesto, richiede solo il ricaricamento di un registro.
- *Svantaggi*: Richiede accessi frequenti alla memoria, rendendo la mappatura più lenta.
### Problema della paginazione e TLB
**Problema di Prestazioni nella Paginazione**:
- *Ogni istruzione richiede l'accesso alla memoria* per prelevare l'istruzione stessa e un ulteriore accesso per la tabella delle pagine.
- Raddoppio degli accessi alla memoria *riduce le prestazioni* di metà.
**Ma**:
- I programmi tendono a fare *molti riferimenti a un piccolo numero di pagine*.
- *Solo una parte limitata* delle boci della tabella delle pagine viene *utilizzata frequentemente*.
**Introduzione del ***Translator Lookaside Buffer (TLB)***:
- Dispositivo hardware che mappa indirizzi virtuali in fisici senza passare dalla tabella delle pagine.
- Riduce gli accessi alla memoria durante la paginazione.
### Funzionamento e gestione del TLB
**Struttura**:
- *Piccolo numero* di voci ( es. $8-256$), ciascuna con numero di pagina virtuale, *bit modificato*, *codice di protezione* e frame fisico.
**Funzionamento**:
- Alla richiesta di un indirizzo virtuale, la MMU controlla prima nel TLB.
- Se trovato e valido, il frame è prelevato direttamente dal TLB.
- Se non trovato (`TLB miss`), avviene una ricerca normale nella tabella delle pagine e la voce trovata rimpiazza una voce nel TLB.
**Gestione delle Modifiche**:
- Le modifiche ai permessi di una pagina nella tabella delle pagine richiedono l'aggiornamento del TLB.
- Per garantire la coerenza, la voce corrispondente nel TLB viene eliminata o aggiornata.
![[Pasted image 20231122153836.png|center|500]]
### Gestione software del TLB
*TLB in Architetture RISC*:
- Alcune macchine RISC come SPARC, MIPS e HP PA gestiscono le voci del TLB tramite software.
*Processo in Caso di TLB Miss*:
- Un TLB miss non porta a una ricerca automatica nella tabella delle pagine da una parte della MMU.
- Invece, si genera un errore di TLB e il SO deve intervenire.
- Il SO cerca la pagina, aggiorna il TLB e riavvia l'istruzione.
#### Tipologie di Miss e Implicazioni
**Frequenza dei TLB Miss**:
- I TLB Miss *sono comuni a causa del numero limitato di voci* nel TLB (es. 64 voci).
- *Aumentare la dimensione del TLB è costoso* e richiede compromessi nella progettazione dei chip.
**Soft Miss vs Hard Miss**:
- *Soft Miss*: La pagina è in memoria ma non nel TLB. Richiede solo l'aggiornamento del TLB.
- *Hard Miss*: La pagina non è in memoria e richiede un accesso alla memoria non volatile   ( disco o SSD ).
	- Un hard miss è significativamente più lento di un soft miss.
**Page Table Walk e diverse tipologie di Miss**:
- La ricerca nella gerarchia delle tabelle delle pagine è chiamata "*page table walk*".
- I miss possono *variare in "gravità"* da minori a maggiori.
- Un *accesso a un indirizzo non valido* può portare a un ***Segmentation Fault*** e alla ***Terminazione del programma***.
#### Page Table Size
Pochi paragrafi fa: "Con 32 bit e pagine da 4Kb":
- 12 bit per indirizzare 4096 byte per pagina;
- Tabella delle pagine di 1.048.576 voci.
Uno spazio di indirizzi virtuali molto grande porterebbe a una tabella di pagine molto grande- *Spreco di memoria* ( senza contare cosa succederebbe per 64 bit).
*Possibili soluzioni*: Multi-level Page Table.
#### Page table a due livelli (x86)
Le Page Tables sono "attraversate" ( "walked" ) dal Memory Management Unit.
*CR3* register: Registro speciale per puntare al vertice della gerarchia delle tabelle di pagina.

>Esempio:
>a) Un indirizzo a 32 bit con due campi (10+10 bit).
>b) Una page table a due livelli.

![[Pasted image 20231123151320.png|center|300]]![[Pasted image 20231123151338.png|center|200]]
##### 64 bit : Page Table a 4 livelli
- *PGD* : Page Global Directory;
- *PUD* : Page Upper Directory;
- *PMD* : Page Mid-Level Directory;
- *PTE* : Page Table Entry.
![[Pasted image 20231123151810.png|center|700]]

>[!note]- Nota: $2^9\times 2^9\times 2^9\times 2^9\times 2^{12}=2^{48}$ byte.
>Ricordate i 48 bit? Permettono di puntare, al momento, 256Tb di memoria.

# Algoritmi di sostituzione delle pagine
## Gestione della memoria : Outline
- Memory Abstraction
- Virtual Memory
- *Algoritmi di Progettazione per Sistemi di Paging*
- Problemi di Progettazione per Sistemi di Paging
## Page Replacement
Il computer potrebbe utilizzare più memoria virtuale di quanta ne abbia fisica. La paginazione crea l'illusione di una memoria praticamente illimitata a disposizione dei processi utente. Quando una pagina logica non è in memoria ( scambiata o "swapped" con un file/partizione ), il SO deve caricarla in memoria in caso di *page fault*. Un'altra pagina logica potrebbe essere scambiata, ma quale?
## Algoritmi di sostituzione delle pagine
- Algoritmo ottimale
- Not Recently Used ( NRU )
- First-In, First-Out ( FIFO ) algorithm
- Second-chance algorithm
- Clock algorithm
- Least recently used ( LRU ) algorithm
- Working set algorithm
- WS Clock algorithm
### Algoritmo di sostituzione delle pagine ottimale
*Concetto*: Scegliere la pagina con in riferimento più distante nel futuro da rimuovere.
*Idealmente*, si rimuove la pagina che non sarà usata per il maggior numero di istruzioni future.
*Esempio*: "Se una pagina non sarà usata per 8 milioni di istruzioni e un'altra per 6 milioni, si rimuove la prima".
*Problema*: È impossibile per il SO prevede il momento del prossimo riferimento per ciascuna pagina.
#### Limiti pratici e valutazione degli algoritmi
Il metodo ottimale *non è realizzabile* in pratica perché richiede la previsione del futuro utilizzo delle pagine. È possibile un'implementazione per valutare le prestazioni rispetto agli algoritmi reali.
*Valutazione*: Se un sistema ha prestazioni inferiori dell'1% rispetto all'ottimale, il miglioramento massimo tecnico è dell'1%.
Gli algoritmi reali devono essere valutati per la loro applicabilità pratica, non per l'ottimalità teorica.
#### Un breve recap
![[Pasted image 20231123160105.png|center|600]]
Bit della Page Table Entry utili per gli algoritmi di sostituzione delle pagine:
- *Modified (M)*: Impostato quando una pagina viene modificata ( conosciuto anche come "dirty bit" );
- *Referenced (R)*: Impostato quando la pagina viene acceduta ( conosciuto anche come "accessed" bit).
### Concetto e funzionamento di NRU 
*Obiettivo*: Trovare le pagine non modificate che non sono state accedute "recentemente".
Vengono usati i *Bit di Stato R e M*:
- R indica l'accesso della pagina,
- M segnala le modifiche.
*Aggiornamento Hardware*: I bit vengono impostati dall'hardware a ogni accesso.
*Reset periodico*: Il bit R viene periodicamente ripulito per identificare pagine non recentemente usate ( per esempio a ogni interrupt del clock ).
*Classificazione delle pagine* in base ai bit R e M ( Le pagine sono divise in 4 pagine da 0 a 3 in funzione dell'uso e delle modifiche ).