# Progettazione di una base di dati

Progettare una base di dati significa definirne struttura, caratteristiche e contenuto. E quindi prevede l'uso di opportune metodologie. In base al grado di astrazione, la progettazione prevede:

- **Modello concettuale**: rappresenta la realtà dei dati e le relazioni tra essi attraverso uno schema
- **Modello logico**: descrive il modo attraverso il quale i dati sono oragnizzati negli archivi del calcolatore
- **Modello fisico**: descrive come i dati sono registrati nelle memorie di massa

## Modello logico

Obiettivo della fase di progettazione logica è pervenire, **a partire dallo schema concettuale**, a uno schema logico che lo rappresenti in modo fedele, "efficiente" e indipendente dal particolare DBMS adottato. A tal fine questa fase di progettazione può essere suddivisa in 2 passi:
1. **Ristrutturazione dello schema Entità-Relazione**: è una fase indipendente dal modello logico e si basa su criteri di ottimizzazione dello schema
2. **Traduzione verso il modello logico**: fa riferimento ad uno specifico modello logico (**modello relazionale**)

## Ciclo di vita di un sistema informativo

1. **Studio di fattibilità**: definisce le varie alternative possibili,i relativi costi e le priorità di realizzazione
2. **Raccolta e analisi dei requisiti**: individua proprietà e funzionalità del sistema tramite interazione con gli utenti e definizione informale dei dati e delle operazioni
3. **Progettazione**: divisa in progettazione dei dati e progettazione delle applicazioni. Individua struttura e organizzazione dei dati e caratteristiche degli applicativi che vi dovranno accedere
4. **Implementazione**: realizza la base di dati e il codice dei programmi conformemente alle specifiche
5. **Validazione e collaudo**: verifica il corretto funzionamento del sistemas informativo
6. **Funzionamento**: il sistema informativo diviene operativo

![[appunti bsd/mod i/immagini/Pasted image 20221221145532.png|center|600]]


## Fasi della progettazione

- **Progettazione concettuale**: rappresenta le specifiche informali in modo formale e completo, ma indipendente dalla rappresentazione usata nei DBMS. Produce lo schma concettuale e fa riferimento ad un modello concettuale dei dati. Rappresenta il contenuto informativo e non la codifica
- **Progettazione logica**: traduce lo schema concettuale nello schema logico basato su un modello logico (es. relazionale) ancora indipendente dalla realizzazione fisica della base di dati
- **Progettazione fisica**: completa lo schema logico con la specifica dei parametri fisici di memorizzazione dei dati. Produce uno schema fisico e fa riferimento ad un modello fisico dei dati,dipendente dal DBMS

![[appunti bsd/mod i/immagini/Pasted image 20221221145847.png|center|600]]

## Specifiche

Si distinguono le **specifiche dei dati** e le **specifiche sulle operazioni**

- **Progettazione concettuale**: si usano le specifiche sui dati; quelle sulle operazioni servono a verificare che lo schema concettuale contenga tutte le informazioni necessarie alla loro esecuzione
- **Progettazione logica**: lo schema concettuale riassume le specifiche sui dati, le specifiche sulle operazioni si usano per ottenere uno schema logico che permetta di eseguirle in modo efficiente. Bisogna conoscere il modello ma non il DBMS adottato
- **Progettazione fisica**: si usano lo schema logico e le specifiche sulle operazioni per implementare il sistema in modo efficiente

## Progettazione concettuale

Il prodotto è uno schema E-R che descrive le specifiche sui dati relative ad una applicazione.

Si può suddividere in due fasi:

- **Raccolta e analisi dei requisiti**
	- Individuazione dei problemi da risolvere
	- Chiarimento ed organizzazione delle specifiche
- **Definizione dello schema E-R**

### Raccolta e analisi dei requisiti

I **requisiti** definiscono le caratteristiche dell'applicazione da realizzare (dati, operazioni)
I requisiti spesso sono espressi con frasi in linguaggio naturale spesso ambigue e disorganizzate
L'analisi consiste nel chiarimento e nell'organizzazione delle specifiche

- Il reperimento dei requisiti è un'attività difficile e non standardizzabile
- L'attività di analisi inizia con i primi requisiti raccolti spesso indirizza verso altre acquisizioni

Realizzazione di una descrizione del problema in linguaggio naturale che rispetti criteri di comletezza e non ambiguità

- corretto livello di astrazione
- frasi standardizzate
- semplicità dele specifiche (evitare frasi contorte)
- eliminazione di sinonimi o omonimi
- esplicitazione dei riferimenti fra termini
- glossario dei termini

Per i **dati**, specificare in numero delle **occorrenze** previste
Per le **operazioni**, specificare il **numero di volte** che si prevede che debbano essere eseguite in un certo arco di tempo

#### Fonti dei requisiti

- **Utenti** (interviste,documentazione scritta)
- **Documentazione esistente** (normative, leggi e regolamenti del settore, regolamenti interni, procedure aziendali, moduli)
- **Realizzazioni preesistenti** (applicativi da rimpiazzare, applicazioni che dovranno interagire col sistema da realizzare)

#### Interazione con gli utenti

- Utenti diversi possono fornire informazioni diverse
- Utenti a livello più alto hanno spesso una visione più ampia ma meno dettagliata
- Le interviste portano spesso ad una acquisizione dei requisiti "per raffinamenti successivi"
	- effettuare spesso verifiche di comprensione e coerenza
	- verificare anche per mezzo di esempi (generali e relativi a casi limite)
	- richiedere definizioni e classificazioni
	- far evidenziare gli aspetti essenziali rispetto a quelli marginali

Vedi esempio1 -> [Esempio 1](http://www.informatica.uniroma2.it/upload/2022/BDC/08-Progettazione.pdf#page=15)

Vedi esempio2 -> [Esempio 2-Più articolato](http://www.informatica.uniroma2.it/upload/2022/BDC/08-Progettazione.pdf#page18)

### Criteri di rappresentazione

- Rappresentare mediante **entità** classi di oggetti con esistenza autonoma e caratterizzati da proprietà significative
- Rappresentare mediante **attributi** gli oggetti con struttura semplice e che non rappresentino proprietà rilevanti
- Rappresentazione mediante **relazioni** concetti che associano più entità precedentemente identificate
- Rappresentazione mediante **generalizzazioni** concetti che risultino essere casi particolari di altri

### Strategie di progetto

Si possono utilizzare le strategie tipiche dello sviluppo di un processo di ingegnerizzazione (es. ingegneria del software)

- Strategie top-down
- Strategie bottom-up
- Strategie inside-out
- Approcci misti

#### Strategia top-down

A partire da uno schema che descrive le specifiche mediante pochi concetti molto astratti, si produce uno schema concettuale mediante raffinamenti successivi che aggiungono via via più dettagli.

I raffinamenti successivi, come accade anche per altre strategie, vengono realizzati mediante trasformazioni elementari, denominate _primitive di trasformazione top-down_ che trasformano un concetto di uno schema in una struttura più complessa che descrive la realtà in maggiore dettaglio

![[appunti bsd/mod i/immagini/Pasted image 20221221152107.png|center|500]]

##### Primitive di trasformazione top-down

- **T1, _da entità a relazione fra entità_**: si applica quando si verifica che una entità descrive due concetti diversi legati logicamente fra loro
- **T2, _da entità a generalizzazione_**: si applica quando una entità è composta da sotto-entità distinte o,più in generale, che uno stesso concetto può in realtà comprendere più concetti
- **T3, _da relazione a insieme di relazioni_**: si applica quando una relazione descrive in realtà due o pià relazioni fra le medesime entità; tipicamente le due relazioni sono due specializzazioni di una relazione più generale
- **T4, _da relazione ad entità con relazioni_**: si applica quando una realzione descrive un concetto con esistenza autonoma ai fini dell'applicazione o concetti di cui si possono avere più occorrenze
- **T5, _introduzione di attributi in una entità_**: si applica per introdurre nuovi attributi ad una entità, che aiutino a descriverla in modo più completo
- **T6,_introduzione di attributi su relazioni_**: si applica per aggiungere proprietà a relazioni

![[appunti bsd/mod i/immagini/Pasted image 20221221152609.png|center|400]]

#### Strategia bottom-up

Nella strategia bottom-up le specifiche iniziali sono suddivise in componenti via via sempre più piccole, fino a descrivere frammenti elementari della realtà

Le componenti vengono poi fuse con trasformazioni successive (primitive di trasformazione bottom-up) per giungere allo schema concettuale finale

Ogni trasformazione introduce nuovi concetti non presenti al livello precedente

![[appunti bsd/mod i/immagini/Pasted image 20221221152927.png|center|500]]


##### Primitive di trasformazione bottom-up

- **T1, _generazione di entità_**: si applica quando si individua nelle specifiche una classe di oggetti caratterizzata da proprietà comuni
- **T2, _generazione di relazione_**: si applica quando nelle specifiche si individua un legame logico fra entità
- **T3, _generazione di generalizzazione_**: si applica quando si individua un legame fra diverse entità riconducibile ad una generalizzazione, quando cioè le diverse entità possono essere istanze di una stessa classe
- **T4, _aggregazione di attributi su entità_**: si applica quando si individua una entità che può essere rappresentata come aggragazione di attributi presenti nelle specifiche
- **T5, _aggregazione di attributi su relazione_**: analoga a T4, ma relativa ad una relazione

![[appunti bsd/mod i/immagini/Pasted image 20221221153416.png|center|400]]

#### Strategia inside-out

Può essere vista come un caso particolare della strategia bottom-up: individua solo alcuni concetti importanti, per poi procedere a macchia d'olio

Si rappresentano prima i concetti più vicini a quelli di partenza per poi sviluppare quelli più lontani attraverso una _navigazione_ nelle specifiche

- **Vantaggi**: non richiedere passi di integrazione
- **Svantaggi**: è necessario di volta in volta esaminare tutte le specifiche e descrivere i nuovi concetti nel dettaglio

**Non è possibile procedere per livelli di astrazione**

![[appunti bsd/mod i/immagini/Pasted image 20221221153733.png|center|600]]

![[appunti bsd/mod i/immagini/Pasted image 20221221153833.png|center|500]]

#### Strategia mista

- Cerca di unire i vantaggi delle strategie top-down e bottom-up. A un estremo, si individuano **componenti elementari**, all'altro si crea uno **schema scheletro** contenente concetti di base da espandere, con raffinamenti successivi, in modo top-down
- Contemporaneamente, dalle specifiche, si creano in modo bottom-up i concetti non presenti nello schema scheletro
- Si adatta alle esigenze opposte di suddivisione di un problema complesso in sottoproblemi, e di procedura per raffinamenti successivi
- Ingloba in pratica anche la strategia inside-out

**Spesso è l'unica strategia utilizzabile**

##### In pratica

Si procede di solito con una strategia ibrida (**mista**):
- si individuano i concetti principali e si realizza uno **schema scheletro**
- sulla base di questo si può decomporre
- poi si **raffina**, si espande, si integra

**Schema scheletro**: Si individuano i concetti più importanti, ad esempio perchè più citati o perchè indicati esplicitamente come cruciali e li si organizza in un semplice schema concettuale

### Qualità di uno schema concettuale

Nel definire uno schema concettuale ci sono alcune prorpietà che bisogna cercare di garantire:

- **Correttezza**: lo schema utilizza propriamente i costrutti del modello di riferimento
- **Completezza**: tutti i dati di interesse sono rappresentati e tutte le operazioni sono eseguibili a partire dai concetti descritti nello schema
- **Leggibilità**: i requisiti sono rappresentati in modo naturale e comprensibile. Estetica dello schema
- **Minimalità**: le specifiche sono rappresentate una sola volta. Non sempre, tuttavia, eventali ridondanze sono indesiderate

### Metodologia

- **Analisi dei requisiti**:
	- Analizzare i requisiti ed eliminare le ambiguità
	- Costruire un glossario dei termini
	- Raggruppare i requisiti in insiemi omogenei
- **Passo base**: Definire uno schema scheletro con i concetti più rilevanti
- **Passo decomposizione**: Effettuare una decomposizione dei requisiti con riferimento ai concetti presenti nello schema scheletro
- **Passo iterativo**: Da ripetere per tutti i sottoschemi finchè ogni specifica è stata rappresentata:
	- Raffinare i concetti presenti in base alle specifiche
	- Aggiungere nuovi concetti
- **Passo di integrazione**: Integrare i vari sottoschemi utilizzando lo schema scheletro
- **Analisi di qualità**:
	- Verifica correttezza
	- Verifica compeltezza
	- Verifica leggibilità
	- Verifica la minimalità e documentare eventuali ridondanze volute












