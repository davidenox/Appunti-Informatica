# Modello dei Dati

Insieme di costrutti utilizzati per organizzare i dati di interesse e descriverne la dinamica

Componente fondamentale: **meccanismi di strutturazione** (o **costrutti di tipo**)

Come nei linguaggi di programmazione esistono meccanismi che permettono di definire tipi di dati, così ogni modello dei dati prevede alcuni costruttori
Ad esempio, il **modello relazionale** prevede il costruttore **relazione**, che permette di definire insiemi di record omogenei

- **Modelli logici**: utilizzati nei DBMS esistenti per l'organizzazione dei dati:
	- utilizzati dai programmi
	- indipendenti dalle strutture fisiche
	- esempi: **relazionale**,reticolare,gerarchico, a oggetti
- **Modelli concettuali**: permettono di rappresentare i dati in modo indipendente da ogni sistema e dal modello logico su cui è basato
	- cercano di descrivere i concetti del mondo reale
	- sibi utilizzati nelle fasi preliminari di progettazione
	- Il più noto è il modello **_Entità-Relazione_**
- Sono stati sviluppati modelli più moderni:
	- **Modello Entità-Relazione Esteso - EER** (consente l'utilizzo di costrutti più potenti e.g ereditarietà)
	- **UML**: linguaggio unificato per la progettazione dei dati e delle funzioni

## Progettazione di Basi di Dati

Progettare una base di dati significa definirne **struttura,caratteristiche e contenuto**
Prevede l'uso di opportune **metodologie**. In base al grado di **astrazione**, nella progettazione abbiamo:
- _Modello concettuale_: rappresenta la realtà dei dati e le relazioni tra essi attraverso uno schema
- _Modello logico_: descrive il modo attraverso il quale i dati sono organizzati negli archivi del calcolatore
- _Modello fisico_: descrive come i dati sono registrati nelle memorie di massa

**Rappresentazione**
![[appunti bsd/mod i/immagini/Pasted image 20221122141408.png|center|500]]

### Modello Concettuale

Rappresentazione **astratta** della realtà:
- Definire un insieme di dati presenti in natura e che rappresentano la natura stessa delle informazioni che si vogliono archiviare
- **Non esistono regole** prefissate per l'individuazione dei dati e per la loro selezione

Progettazione della base di dati:

1. Cosa c'è? (Oggetti)
2. Come si collegano o si parlano?
3. Quanti tra loro?
4. Cosa identifica gli "oggetti"?
5. Quali informazioni utili non principali?

### Modello Entità Relazioni ER

Il **modello entità relazione** è uno strumento per analizzare le caratteristiche di una realtà in modo indipendente dagli eventi che in essa accadono, cioè per costruire un modello concettuale dei dati indipendente dalle applicazioni

In particolare:
![[appunti bsd/mod i/immagini/Pasted image 20221122142017.png|center|600]]
![[appunti bsd/mod i/immagini/Pasted image 20221122142117.png|center|600]]

#### Modello ER - Entità

_Def_

Un'**entità** è un oggetto, concreto o astratto, che ha un significato anche quando viene considerato in modo isolato ed è di interesse per la realtà che si vuole modellare

**Esempio**
- le persone, un modello di automobile,i movimenti contabili, le prove sostenute da uno studente
- gli studenti sono classificabili nel tipo entità Studente (il singolo studente rappresenta unìistanza del tipo entità Studente)
- i diversi modelli di automobile sono classificabili nel tipo entità Automobile

Infatti:
![[appunti bsd/mod i/immagini/Pasted image 20221122142403.png|center|600]]

#### Modello ER - Relazione

_Def_
La **relazione(relationship)** è un legame che stabilisce unìinterazione tra le entità

**Esempio**
Tra l'entità Persona e Automobile esiste l'associazione **Possedere** (tra Automobile e Persona esiste l'associazione **Essere Posseduta** che è l'inverso) che può essere descritta nel linguaggio naturale secondo due versi:
- una persona può possedere una o più automobili
- un'automobile deve essere posseduta da una persona

Si rappresenta solo un verso della relazione
![[appunti bsd/mod i/immagini/Pasted image 20221122143122.png|center|600]]

##### Relazioni ricorsive o isA
_Def_
Le relazioni tra un'entità e se stessa si dicono **ricorsive o isA**

**Esempio**
Esempio di relazione ricorsiva sull'entità Persona è l'associazione Essere genitore nella quale Persona partecipa con il ruolo di **Genitore** e di **Figlio**
![[appunti bsd/mod i/immagini/Pasted image 20221122143627.png|center|600]]

##### Relazioni ternarie
_Def_
Le relazioni tra tre entità si dicono **ternarie**

**Esempio**
Una relazione ternaria si compone di diverse relazioni binarie
![[appunti bsd/mod i/immagini/Pasted image 20221122144046.png|center|600]]

#### Modello ER - Attributi e Chiavi

_Def (Attributi)_
Le proprietà delle entità e delle relazioni sono descritte tramite gli **attributi**. Alcune caratteristiche che descrivono il **Dominio**:
- **Formato:** Tipi di valore che assume (carattere,numerico,data/ora,etc...)
- **Dimensione:** Quantità max di caratteri o cifre inseribili
- **Opzionalità:** Possibilità di non essere sempre valorizzato

**Esempio**
Automobile ($\underline{NumeroTelaio}$,modello,produttore,cilindrata,prezzo)
![[appunti bsd/mod i/immagini/Pasted image 20221122144837.png|center|300]]

_Def_
La **chiave primaria** è un attributo o un insieme di attributi che identificano univocamente un'istanza dell'entità

**Esempio**
(chiave primaria identificata con la sottolineatura)
- Automobile ($\underline{NumeroTelaio}$,modello,produttore,cilindrata,prezzo)
- Studente ($\underline {cognome,nome}$,data nascita)

![[appunti bsd/mod i/immagini/Pasted image 20221122145253.png|center|300]]

Anche le relazioni possono avere attributi, infatti:

![[appunti bsd/mod i/immagini/Pasted image 20221122145416.png|center|600]]

Spesso, anche in presenza di chiavi palesi, si utilizza un numero progressivo come chiave primaria ovvero una chiave artificiale
Infatti:
![[appunti bsd/mod i/immagini/Pasted image 20221122145517.png|center|600]]
_Def_
Una **chiave artificiale** è formata da un attributo privo di significato proprio. Di solito consiste in un contatore che si autoincrementa ad ogni istanza che si aggiunge

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221122145652.png|center|600]]

#### Modello ER - Proprietà

- Ogni entità deve avere una **chiave primaria**
- L'attributo chiave primaria **non può essere opzionale**
- La chiave primaria **non può avere valori ripetuti**

Proprietà per il Dominio:
- **Tipo di dato**: intero,decimale,carattere,data,...
- **Lunghezza**: numero di cifre o caratteri per rappresentare il valore del'attributi
- **Intervallo**: Limite superiore e inferiore dei valori
- **Vincoli**: Restrizioni sui valori ammessi
- **Supporto del valore NULL**: quando non è assegnato nessun valore
- Valore di **default**
Per le chiavi primarie:
- Il valore deve essere unico e i NULL non sono ammessi
Per le chiavi esterne:
- Il tipo di dato, la lunghezza e il formato della chiave esterna devono essere uguali a quelli della corrispondente chiave primaria

##### Ritornando a [[Lezione 5 - Modello Concettuale, Modello ER#Modello ER - Entità|Modello ER - Entità]]

Esistono vari tipi di entità, alcune **forti** e altre **deboli**
_Def_
Le entità **deboli** sono le entità che non hanno una chiave primaria e devono essere associate ad un'altra entità per essere completamente significative
![[appunti bsd/mod i/immagini/Pasted image 20221122150709.png|center|600]]

- Movimento ha senso solo in relazione a Conto
- Movimento è un entità debole
- Cliente e Conto sono entità forti
- Per evitare entità deboli, si aggiunge un numero progressivo come attributo

![[appunti bsd/mod i/immagini/Pasted image 20221122150955.png|center|600]]

#### Modello ER - Molteplicità

La **molteplicità** di una relazione è il numero di possibili istanze di un'entità che sono messe in corrispondenza con un'istanza dell'altra entità:

- I valori **min** e **max** assunti dalla molteplicità sono rappresentati con : **(1,1),(1,N),(0,1),(0,N)**
- Al valore min è associato il concetto di partecipazione facoltativa **(0)** o obbligatoria **(1)**
- Il valore massimo definisce la cardinalità della partecipazione all'associazione e assume due valori  1 e N
- In relazione alla cardinalità si parla di **associazioni**:
	- **Uno a uno 1:1**
	- **Uno a molti 1:N**
	- **Molti a molti N:N**

#### Modello ER - Associazione 1:1
Un'associazione tra E1 e E2 si dice _uno a uno (1:1)_ quando a ogni istanza di E1 corrisponde una sola istanza di E2 e a ogni istanza di E2 corrisponde una sola istanza di E1
![[appunti bsd/mod i/immagini/Pasted image 20221122152709.png|center|600]]

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221122152854.png|center|600]]

#### Modello ER - Associazione 1:N
Un'associazione tra E1 e E2 si dice uno a molti (1:N) quando a ogni istanza di E1 corrispondono una o più istanze di E2 e a ogni istanza di E2 corrisponde una sola istanza di E1
![[appunti bsd/mod i/immagini/Pasted image 20221122153254.png|center|600]]

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221122153325.png|center|600]]


#### Modello ER - Associazione N:N
Un'associazione tra E1 e E2 si dice uno a molti (1:N) quando a ogni istanza di E1 corrispondono una o più istanze di E2 e a ogni istanza di E2 corrispondono una o più istanze di E1
![[appunti bsd/mod i/immagini/Pasted image 20221122153612.png|center|600]]

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221122153728.png|center|600]]


#### Modello ER - IsA

Può accadere che sussista l'**associazione IsA** (o associazione di sottoinsieme) tra due entità, e cioè che ogni istanza di una sia anche istanza dell'altra

L'associazione IS-A nel modello ER si può definire tra due entità, che si dicono "entità padre" ed "entità figlia" (o sottentità,cioè quella che rappresenta un sottoinsieme dell'entità padre)

L'associazione IS-A si rappresenta nel diagramma dello schema concettuale mediante una freccia dalla sottoentità alla entità padre
Vige la regola che un'entità può avere al massimo una entità padre. In altre parole,il modello ER non ammette ereditarietà multipla

![[appunti bsd/mod i/immagini/Pasted image 20221125090657.png|center|600]]

#### Modello ER- Ereditarietà
**Principio di ereditarietà:** ogni proprietà dell'entità è anche una proprietà della sottoentità, e non si riporta esplicitamente nel diagramma
**L'entità figlia** può avere ovviamente ulteriori proprietà.

**Esempio**
Cognome e Nome ereditati da Persona:
![[appunti bsd/mod i/immagini/Pasted image 20221125090738.png|center|400]]

**Principio di ereditarietà:** l'associazione IS-A si eredita, pertanto IS-A è transitiva
**Esempio**
Ogni istanza di Studente è un'istanza di Persona, ogni istanza di Fuori corso è un'istanza di Studente -> ogni istanza di Fuori corso è un'istanza di Persona

![[appunti bsd/mod i/immagini/Pasted image 20221125090905.png|center|500]]

#### Modello ER - Generalizzazione

L'entità padre può generalizzare diverse sottoentità rispetto ad un unico criterio. In questo caso si parla di **generalizzazione**
Nella generalizzazione, le sottoentità hanno insiemi di istanza disgiunti a coppie (anche se in alcune varianti del modello ER si può speficifare se due sottoentità della stessa entità padre sono disgiunte o no).

![[appunti bsd/mod i/immagini/Pasted image 20221125091033.png|center|500]]
![[appunti bsd/mod i/immagini/Pasted image 20221125091118.png|center|600]]

Il principio di ereditarietà vale anche per le generalizzazioni:
- ogni proprietà dell'entità padre è anche una proprietà della sottoentità, e non si riporta esplicitamente nel diagramma
- L'entità figlia può avere ovviamente ulteriori proprietà

### UML - Diagramma delle Classi

_Def_
Il _diagramma delle classi_ è un grafo che descrive i tipi degli oggetti in un sistema, le relazioni statistiche tra essi, gli attributi e le operazioni di una classe,ed i vincoli sulle relazioni

Una classe è rappresentata da un rettangolo scomposto in tre parti:
- il nome della classe
- gli attributi della classe
- le operazioni della classe

![[appunti bsd/mod i/immagini/Pasted image 20221125091208.png|center]]

#### Proprietà di una classe: Attributi in UML
- Un **attributo** modella una proprietà locale della classe ed è caratterizzato da un nome e dal tipo dei valori associati
- Ogni attributo di una classe stabilisce una proprietà locale **valida per tutte le istanze** della classe. Il fatto che la proprietà sia locale significa che è una prorpeità indipendente da altri oggetti
- Formalmente, un attributo A della classe C si può considerare una funzione che associa un valore di tipo T ad **ogni** oggetto che è istanza di C

#### Istanze di una classe
Tra un oggetto che è istanza di una classe C e la classe C si traccia un arco **Instance-of** (l'arco in realtà non è strettamente necessario, perchè la classe di cui l'oggetto è istanza è già indicata nell'oggetto)
Ricordiamo che gli oggetti formano il livello **estensionale**, mentre le classi a livello **intensionale**

![[appunti bsd/mod i/immagini/Pasted image 20221125091257.png|center|600]]

#### Attributi di oggetti

Gli attributi di una classe determinano gli attributi delle sue istanze
- **Regola importante**: se una classe C ha un attributo A di tipo T, ogni oggetto che è istanza di C ha l'attributo A, con un valore associato di tipo T
- **Regola importante**: un oggetto X non può avere un valore per un attributo che non è definito nella classe di cui X è istanza
![[appunti bsd/mod i/immagini/Pasted image 20221125091418.png|center|500]]

#### Identificatori degli oggetti
Due oggetti con identificatori distinti sono comunque distinti, anche se hanno i valori di tutti gli attributi uguali
Due oggetti diversi devono avere identificatori diversi, anche se possono avere gli stessi valori per tutti gli attributi

![[appunti bsd/mod i/immagini/Pasted image 20221125091453.png|center|500]]

#### Diagrammi delle classi
Secondo la metodologia UML vengono definiti come _Diagrammi a struttura statica_. Vengono utilizzati per:
- Documentate le classi che compongono un sistema o un sottosistema
- Descrivere **associazioni,generalizzazioni aggregazioni**, fra le varie classi.
- Evidenziare le caratteristiche di una classe - **attributi** e **operazioni**

- I diagrammi delle classi possono essere utilizzati in vaire fasi dello sviluppo di un sistema:
	- In fase di **analisi**: per la specifica delle classi all'interno del dominio del problema
	- In fase di **progettazione**: per la rappresentazione delle classi e relazioni che riflettono il modello della soluzione
- Possono documentare come interagiscono le classi di un particolare sistema con le librerie di classi già esistenti
- Possono essere utilizzati a rappresentare istanze di oggetti all'interno delle classi
- Possono mostrare le interfacce di una classe

#### Tipi di attributi e di operazioni

- **Sintassi** $$<nomeCaratteristica>:<tipo>$$
- **Semantica**
	- **nomeCaratteristica**: identifica o un attributo oppure un'operazione 
	- **Tipo**: identifica il tipo di dato dell'attributo oppure il tipo di dato restituito dall'operazione
- **Oss**: Gli attributi e le operazioni possono essere tipizzati come classi provenienti:
	- Dalle librerire dell'ambientazione d'implementazione
	- Dal modello delle classi in uso

![[appunti bsd/mod i/immagini/Pasted image 20221125091546.png|center|500]]

##### Attributi e operazioni: Visibilità
- **"-" private**: disponibile solo all'interno della classe che la definisce
- **"+" public**: disponibile solo per le classi associate alla classe che la definisce
- **"#" protected**: disponibile solo all'interno della classe che la possiede e di ogni sua sottoclasse

###### Attributi: ulteriori specifiche

![[appunti bsd/mod i/immagini/Pasted image 20221125091639.png|center|700]]

#### Associazioni
Per il momento, ci limitiamo a discutere associazioni tra **due** classi (ma le associazioni possono coinvolgere N classi)
Una **associazione** (o relazione) tra una classe $C1$ ed una classe $C2$ modella una relazione matematica tra l'insieme delle istanze di $C1$ e l'insieme delle istanze di $C2$
Gli attributi modellano proprietà locali di una classe, le associazioni modellano proprietà che coinvolgono altre classi
Una associazione tra due classi modella una proprietà di entrambe le classi

**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20221125091718.png|center]]

- Alcune volte è interessante specificare un verso per il nome della associazione
- **Atttenzione**: La notazione riportata sopra **non** significa che l'associazione ha un verso. In altre parole, il verso non è una caratteristica del significato della associazione, ma dice semplicemente che il nome scelto per l'associazione evoca un verso

##### Associazione: Ruoli 
è possibile aggiungere alla associazione una informazione che specifica il **ruolo** che una classe gioca nella associazione
Il ruolo si indica con un nome posizionato lungo la linea che rappresenta l'assocaizione, vicino alla claase alla quale si riferisce

![[appunti bsd/mod i/immagini/Pasted image 20221125095952.png|center]]

Analogalmente al verso, il ruolo è generalmente opzionale, e non aggiunge nulla al significato dell'associazione
L'unico caso in cui **il ruolo è obbligatorio è quello in cui l'associazione insiste più volte sulla stessa classe**, e rappresenta una relazione non simmetrica

![[appunti bsd/mod i/immagini/Pasted image 20221125100135.png|center]]


##### Associazione: Molteplicità

Per specificare con maggiore precisione il significato delle associazioni binarie si possono definire i vincoli di **molteplicitià** (o semplicemente molteplicità) delle associazioni

![[appunti bsd/mod i/immagini/Pasted image 20221125100303.png|center|600]]

![[appunti bsd/mod i/immagini/Pasted image 20221125100334.png|center|600]]

##### Associazioni N-arie

Una associazione può essere definita su tre o più classi. In tale caso **l'associazione si dice n-aria**, modella una relazione matematica tra n insiemi

![[appunti bsd/mod i/immagini/Pasted image 20221125100452.png|center|600]]

#### Aggregazioni in UML

Un'**aggregazione** viene utilizzata per indicare che, oltre ad avere attributi propri, l'istanza di una classe può consistere di, o comprendere, istanze di altre classi
Per riferisri alle aggregazione si utilizza il termine _**tutto-parte**_

![[appunti bsd/mod i/immagini/Pasted image 20221125100637.png|center]]

#### Composizioni in UML

A differenza delle aggregazioni, in cui le istenze componenti possono eisstere a prescindere dalla istanza di cui sono componenti, in una _composizione_ le parti non possono eisstere senza la parte "tutto"

![[appunti bsd/mod i/immagini/Pasted image 20221125100811.png|center]]

#### Generalizzazioni in UML

Fino ad ora abbiamo assunto che due classi siano sempre disgiunte. In realtà sappiamo che può accadere che tra due classi susista la relazione Is-A, e cioè che ogni istanza di una sia anche istanza dell'altra
In UML la relazione Is-A si modella mediante la nozione di _**generalizzazione**_
La generalizzazione coinvolge una superclasse ed una o più sottoclassi (dette anche **classi derivate**). Il significato della generalizzazione è il seguente: ogni istanza di ciascuna sottoclasse è anche istanza della superclasse
Quando la sottoclasse è una, la generalizzazione modella appunto la relazione Is-A tra la sottoclasse e la superclasse

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221125101156.png|center|500]]

_**Principio di ereditarietà**_: ogni proprietà della superclasse è anche una proprietà della sottoclasse, e non si riporta esplicitamente nel diagramma

![[appunti bsd/mod i/immagini/Pasted image 20221125101310.png|center|500]]

La _**generalizzazione**_ oltre a modellare la relazione "Is-A" fra due classi, vengono utilizzate anche per rappresentare la relazione gerarchica fra più classi rispetto ad un unico criterio (che si può indicare con un nome, che è il nome della generalizzazione)

![[appunti bsd/mod i/immagini/Pasted image 20221125101519.png|center|600]]

##### Diverse generalizzazioni di una stessa classe

La stessa superclasse può partecipare a diverse generalizzazioni

![[appunti bsd/mod i/immagini/Pasted image 20221125101634.png|center|600]]

Concettualmente, non c'è alcuna correlazione tra due generalizzazioni diverse, perchè rispondono a due criteri diversi di classificare le istanze della superclasse

###### Generalizzazioni "disjoint"

Una generalizzazione può essere disgiunta (le sottoclassi sono disgiunte a coppie) o no
![[appunti bsd/mod i/immagini/Pasted image 20221125101839.png|center|600]]

##### Generalizzazioni "complete"

Una generalizzazione può essere completa (l'unione dele istanze delle sottoclassi è uguale all'insieme delle istanze della superclasse) o no

![[appunti bsd/mod i/immagini/Pasted image 20221125102039.png|center|600]]

##### Generalizzazioni "incomplete"

Una generalizzazione incomplete è tale che l'unione delle istanze delle sottoclassi non è uguale all'insieme delle istanze della superclasse

![[appunti bsd/mod i/immagini/Pasted image 20221125102214.png|center|400]]

##### Generalizzazioni "overlapping"
Una generalizzazione **_overlapping_** è l'opposto di quella disjoint. Un'istanza può esserlo di più di una delle sottoclassi della superclasse

![[appunti bsd/mod i/immagini/Pasted image 20221125102341.png|center]]

#### Specializzazioni
In una generalizzazione la sottoclasse non solo può avere proprietà aggiuntive rispetto alla superclasse, ma può anche specializzare le proprietà ereditare dalla superclasse
- Specializzazione di un attributo: se una classe $C1$ ha un atrtibuto $A$ di tipo $T1$, e se $C2$ è una sottoclasse di $C1$, specializzare $A$ in $C2$ significa definire $A$ anche in $C2$ ed assegnargli un tipo $T2$ i cui valori sono un sottoinsieme dei valori di $T$

![[appunti bsd/mod i/immagini/Pasted image 20221125102606.png|center|400]]


#### Classi di associazioni

Le **Classi associazioni** permettono di esplicitare gli attributi e le associazioni di una associazione

![[appunti bsd/mod i/immagini/Pasted image 20221125102730.png|center]]

**UML Example for Displaying Specialization/Generalization**

![[appunti bsd/mod i/immagini/Pasted image 20221125102824.png|center]]







