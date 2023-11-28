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
#### Classificazione delle pagine e scelta di rimozione
**Classi di pagine**:
- *Classe 0*: Non referenziata, non modificata.
- *Classe 1*: Non referenziata, modificata.
- *Classe 2*: Referenziata, non modificata.
- *Classe 3*: Referenziata, modificata.
Le pagine di *classe 1* sembrano a prima vista *impossibili*, *ma* appaiono quando *un interrupt del clock azzera il bit R* di una pagina di classe 3.
- Gli interrupt del clock non azzerano il bit M perché questa informazione è necessaria per sapere se la pagina deve essere riscritta su disco o meno.
>**Selezione per Rimozione**:
- NRU rimuove una pagina casuale dalla classe più bassa non vuota.
- Azzerare R ma non M produce una pagina di classe 1: Una pagina di classe 1 è stata modificata molto tempo fa e da allora non è stata più toccata.
**Vantaggi di NRU**: Semplicità, efficienza implementativa e prestazioni accettabili.
### Algoritmo FIFO (First-In, First-Out)
*Descrizione*: FIFO è un algoritmo di paginazione che elimina la pagina più vecchia in memoria.
*Implementazione*: Il SO rimuove la pagina in testa alla lista ( la più vecchia ) durante un page fault, aggiungendo la nuova pagina in coda.
*Problema di FIFO*: Nel contesto informatico, la pagina più vecchia potrebbe ancora essere frequentemente utilizzata, rendendo FIFO poco efficace.
*Conclusione*: A causa di queste limitazioni, FIFO è raramente utilizzato nella sua forma più semplice.
### Seconda Chance : Miglioramento di FIFO
*Principio*: Controllo del bit R (di lettura) della pagina più vecchia per decidere la rimozione.
*Funzionamento*:
- Se R=0 la pagina è vecchia e non usata di recente, quindi viene sostituita.
- Se R=1 il bit viene azzerato, la pagina è reinserita in fondo alla lista e considerata come appena caricata.
![[Pasted image 20231124101847.png|center|500]]
![[Pasted image 20231124101908.png|center|500]]
a) Pagine ordinate in ordine FIFO
b) Elenco delle pagine se si verifica un errore di pagina al tempo 20 e A ha il bit R impostato.
I numeri sopra le pagine sono i loro tempi di caricamento.
#### Operatività e caso peggiore del miglioramento
*Azioni*:
- Se A ha R=0, viene rimossa ( scritta su memoria non volatile se modificata, altrimenti scartata ).
- Se A ha R=1, viene messa in fondo alla lista e il suo timestamp di caricamento aggiornato.
**Scenari possibili**:
- Se trova una pagina non referenziata, la rimuove.
- Se tutte le pagine sono state referenziate, il miglioramento opera come un FIFO puro, con un ciclo completo di reset dei bit R prima di rimuovere la pagina iniziale.
### Algoritmo di clock per la sostituzione delle pagine
*Funzionamento*: Lista circolare dei frame di pagina con un puntatore simile a una lancetta di orologio per identificare la pagina più vecchia.
*Page fault*:
- Se il bit R della pagina puntata è 0, la pagina viene rimossa e sostituita con la nuova, poi il puntatore avanza.
- Se R=1, il bit viene azzerato e il puntatore si sposta alla pagina successiva.
*Concetto*: Ripete il processo finché non trova una pagina con R=0.
*Vantaggio*: Elimina l'inefficienza della continua riallocazione delle pagine lungo la lista.
> Efficiente e più performante rispetto a Seconda Chance e FIFO.
![[Pasted image 20231124104402.png|center|400]]
### Least Recently Used ( LRU ) - Tra teoria e "pratica"
**Teoria**:
- *Fondamento LRU*: Pagine non usate di recente sono candidate alla sostituzione
- *Possibile implementazione*: Lista delle pagine  con quelle più usate in testa e quelle meno usate in coda.
- *Aggiornamenti*: Ogni riferimento richiede l'aggiornamento della lista (uno stack) e copia di pagine intere, operazione costosa anche con hardware dedicato.
Sebbene tendente all'ottimo, praticamente non efficiente e non utilizzato.
Esistono però altri metodi per implementare l'LRU con hardware speciale:
- Uso di un contatore a 64 bit per ogni riferimento a memoria.
- *Selezione LRU*: alla generazione di un page fault, si rimuove la pagina con il contatore più basso, indicando l'uso meno recente.
#### Simulazione Software di LRU : Algoritmo NFU
**NFU ( Not Frequently Used )**: Associa un contatore ad ogni pagina, incrementato con ogni interrupt del clock in base al bit R.
- Tanti accessi ad una pagina $\implies$ Alto valore di "frequenza" assegnato alla pagina $\implies$ minore possibilità di rimozione.
**Limite di NFU**: Non dimentica l'uso passato, può portare a scelte subottimali in ambienti multi-pass o in fase di boot.
- Es: Una pagina utilizzata con altissima frequenza in un determinato periodo e poi "abbandonata" potrebbe non venire sostituita.
**Miglioramento di NFU $\implies$ Aging**:
- Numero di bit fisso, ad esempio 8 bit.
- Ad ogni interrupt del clock i bit vengono spostati a destra.
- Prima dello shift dei contatori, il bit R viene aggiunto al lato sinistro.
*Effetto dell'Aging*: Emula LRU, dando meno peso agli usi passati e preferendo le pagine meno referenziate di recente.
##### NFU e Aging in azione
![[Pasted image 20231124114013.png|center|600]]
Simula l'LRU via software, es: *Pagina 1*:
a) NON è modificata ed ha valore `00000000`
b) Viene modificata e diventa `10000000`
c) Viene modificata e diventa `11000000`
d) NON viene modificata e diventa `01100000`
Consideriamo le *pagine 3 e 5*:
*(c)* - Entrambe hanno avuto accesso.
*(d) ed (e)* - Nessuna delle due ha avuto riferimenti.
- Registrando un solo bit per intervallo di tempo non potremmo distinguere fra riferimenti in tempi recenti o meno.
- Con NFU e Aging, la *pagina 3 viene rimossa* poiché la pagina 5 ha avuto riferimenti in (a) prima e la pagina 3 no.
##### Limiti e praticità dell'Aging
*Differenza da LRU*: Aging non distingue l'ordine esatto dei riferimenti recenti ed ha un orizzonte temporale limitato ( non è necessariamente un male, anzi ).
*Fattibilità*: 8 bit sono generalmente sufficienti per un buon compromesso tra accuratezza e uso di memoria.
### Il concetto di Working Set
*Definizione di Working Set*: 
- Insieme delle pagine attualmente usate da un processo.
- Rappresenta la località di riferimento, ovvero le pagine a cui un processo fa riferimento durante una fase dell'esecuzione.
*Demand Paging*:
- Le pagine sono caricate in memoria "On demand", solo quando necessario.
- Inizialmente molti page fault si verificano finché non vengono caricate tutte le pagine necessarie.
#### Concetto e dinamica del WS
*Definizione*: Working Set `w(k,t)` è l'insieme di pagine usate negli ultimi k riferimenti.
*Monotonia*: `w(k,t)` è monotona non decrescente al crescere di `k`.
*Asintoto*: Il limite di `w(k,t)` è finito, correlato allo spazio degli indirizzi del programma.
*Implicazione*: C'è un ampio intervallo di `k` dove il WS resta invariato.
![[Pasted image 20231124120900.png|center|600]]
#### Working Set e Performance
**Gestione della memoria e Page Fault**:
- *Se* il WS di un processo è completamente *in memoria*, si verificano *pochi page fault*.
- *Se* il WS è *più grande della memoria* disponibile, si verificano *frequenti page fault*, rallentando significativamente il processo ( fenomeno noto come ***thrashing***).
**Working Set Model**:
- Molti *SO cercano di tracciare il WS* di ogni processo e di mantenerlo in memoria per ridurre i page fault.
- La *pre-paginazione carica in anticipo le pagine basandosi* sul WS del processo.
#### Implementazione e algoritmi di sostituzione
**Tracciamento del WS**:
- Il WS è definito come l'insieme delle pagine usate negli ultimi `k` riferimenti alla memoria.
- *In pratica*: è spesso definito *in termini di tempo*, ad esempio, le pagine usate negli ultimi $\tau$ secondi di tempo di esecuzione.
**Algoritmo di Sostituzione basato sul WS**:
- Alla verifica di un page fault, si ricerca una pagina fuori dal WS per rimuoverla.
- Utilizza informazioni come il bit di riferimento e il tempo dell'ultimo utilizzo per determinare quali pagine rimuovere.
#### Un esempio
**Impostazione dei bit R e M**:
- Un *interrupt periodico azzera il bit R* a ogni ciclo di clock.
**Durante un Page Fault**:
- Scansione delle pagine alla ricerca di una pagina da rimuovere.
- *Controllo del bit R* per ogni pagina:
	- *R=1*: Aggiornamento del tempo dell'ultimo utilizzo, la pagina è nel WS.
	- *R=0 e Età $\gt\tau$*: La pagina non è nel WS e viene rimossa.
	- *R=0 e Età $\le\tau$*: La pagina rimane, ma si contrassegna la più vechia per possibile rimozione.
- Se nessuna pagina è rimovibile, viene selezionata la più vecchia con R=0 ( in caso contrario, una pagina a caso).
![[Pasted image 20231124123957.png|center|600]]
### Introduzione all'algoritmo WSClock
**Miglioramento dell'Algoritmo Working Set**:
- WSClock è un'evoluzione dell'algoritmo Clock che integra informazioni del WS.
- Popolare per la sua semplicità e buone prestazioni.
**Struttura dati**:
- Usa una lista circolare di frame, simile all'algoritmo Clock.
- Ogni frame nella lista contiene:
	- Il tempo dell'ultimo utilizzo;
	- Il bit R ( Riferimento );
	- Il bit M (Modificato ).
#### WSClock : Un esempio
![[Pasted image 20231128111902.png|center|500]]
Ad ogni page fault è esaminata per prima la pagina indicata dalla lancetta dell'orologio.
- Se oò *bit R=1*, la pagina ***NON** è la candidata ideale* alla rimozione ( è stata usata nel ciclo di clock).
- Il bit R viene quindi impostato a 0
- La lancetta avanza alla pagina successiva e l'algoritmo viene ripetuto per la nuova pagina.
La situazione dopo questa sequenza è mostrata nella figura (b).
![[Pasted image 20231128112203.png|center|500]]
Se la pagina indicata ha R=0 (c) e se l'età è maggiore di $\tau$:
- Se *M=0 ( pagina pulita )*:
	- Non è nel set di lavoro e ne esiste una copia valida su memoria non volatile.
	- Il frame viene semplicemente riciclato e vi viene posta la nuova pagina (d)
- Se *M=1* invece la pagina è "sporca" ( ovvero modificata );
	- Non ne esiste una copia valida in memoria non volatile.
	- Non può essere sfrattata immediatamente.
**Per evitare "rallentamenti"** ( come un cambio di processo ), **la scrittura su memoria non volatile viene schedulata** e rimandata:
- Lungo la lista potrebbe esserci una pagina pulita e vecchia che può essere usata immediatamente;
- La lancetta avanza e l'algoritmo procede con la pagina successiva.
#### Gestione scritture e selezione pagina in WSClock
**Limitazione scritture su Memoria Non Volatile**:
- Possibilità di schedulare tutte le pagine per I/O su memoria non volatile in un ciclo di clock.
- Per ridurre il traffico su disco/SSD, si imposta un limite massimo di scritture ( `n` pagine).
- Una volta raggiunto il limite `n`, ulteriori scritture non vengono schedulate.
***Comportamento al completamento del Giro di Orologio***:
- **Quando ci sono scritture Pendenti**:
	- La lancetta prosegue il suo giro *cercando pagine "pulite"* ( non modificate ).
	- *Non appena una* scrittura pendente *viene completata*, la pagina associata diventa "pulita".
	- La lancetta *seleziona la prima pagina pulita che incontra* e la rimuove dalla memoria.
- **Quando <u>NON</u> ci sono Scritture Pendenti**:
	- Significa che tutte le pagine sono attivamente utilizzate ( "nel set di lavoro" ).
	- La strategia diventa quella di *scegliere e rimuovere una pagina pulita a caso*.
	- Se non ci sono pagine pulite disponibili, la pagina corrente viene scelta per la rimozione e la sua copia viene scritta su disco.
# Riepilogo

| Algoritmo     | Commento                                                             |
| ------------- | -------------------------------------------------------------------- |
| Ottimale      | Non implementabile, ma utile come termine di confronto e valutazione |
| LRU           | Eccellente, ma difficile da implementare con precisione              |
| NRU           | Approssimazione molto rozza di LRU                                   |
| FIFO          | Potrebbe eliminare pagine importanti                                 |
| Second Chance | Deciso miglioramento rispetto al FIFO                                |
| Clock         | Realistico                                                           |
| NFU           | Approssimazione abbastanza rozza di LRU                              |
| Aging         | Efficente che approssima bene LRU                                    |
| Working Set   | Dispendioso da implementare                                          |
| WSClock       | Algoritmo efficiente e buono                                                                     |

**Algoritmi Preferiti**:
- *Aging e WSClock* sono i "migliori" tra gli algoritmi analizzati.
- Entrambi basati rispettivamente su LRU e WS, con buone prestazioni e implementazione efficiente.
- La nozione di "migliore" è risultato del trade-off tra la complessità del metodo e i vincoli hardware che il SO deve comunque rispettare.
**Implementazione nei SO**:
Sistemi some Windows e Linux adottano varianti di questi algoritmi, a volte combinando diversi elementi per ottimizzare le prestazioni in base a specifiche esigenze al tipo di hardware.