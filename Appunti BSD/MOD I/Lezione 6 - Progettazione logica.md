# Da ER a Modello Relazionale

- Ogni **entità** diventa una relazione (o tabella)
- Ogni **attributo di entità** diventa un attributo di relazione,ossia una **colonna di tabella** ereditando le caratteristiche dell'attributo da cui deriva
- L'**identificatore univoco di una entità** diventa la **chiave primaria (PK)** della relazione

La rappresentazione di una tabella avviene tramite il suo schema: 
_nomerelazione(nome_attributo,nome_attributo,...)_
![[appunti bsd/mod i/immagini/Pasted image 20221123150119.png|center|600]]

## ER->Modello Relazionale (1:1)

La relazione 1:1 diventa un'unica relazione che contiene gli attributi della prima e della seconda entità

**Esempio con partecipazione obbligatoria**.
![[appunti bsd/mod i/immagini/Pasted image 20221123150316.png|center|600]]


![[appunti bsd/mod i/immagini/Pasted image 20221123150444.png|center|700]]
![[appunti bsd/mod i/immagini/Pasted image 20221123150728.png|center|700]]

La relazione 1:1 con una entità con _partecipazione opzionale_ viene trattata come una _associazione uno a molti_ scegliendo l'entità con _partecipazione opzionale come se fosse a molti_

Se _entrambe_ le entità partecipano in modo opzionale si tratta come una _associazione molti a molti_

**Esempio con partecipazione opzionale da un lato**
![[appunti bsd/mod i/immagini/Pasted image 20221123151117.png|center|700]]

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221123151207.png|center|700]]

**Esempio con partecipazione opzionale da entrambi i lati**
![[appunti bsd/mod i/immagini/Pasted image 20221123151553.png|center|700]]

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221123151731.png|center|700]]
![[appunti bsd/mod i/immagini/Pasted image 20221123151909.png|center|700]]

## ER->Modello Relazionale 1:N

La relazione 1:N viene rappresentatat aggiungendo,agli attributi dell'entità che svolge il ruolo a molti, l'identificatore univoco dell'entità col ruolo a uno. Questo identificatore prende il nome di **chiave esterna (foreign key = FK)** dell'entità associata. Eventuali atrtibuti dell'associazione vengono inseriti anch'essi nell'entità con ruolo a molti,insieme alla chiave esterna

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221123152226.png|center|700]]
![[appunti bsd/mod i/immagini/Pasted image 20221123152258.png|center|700]]

**Esempio con partecipazione opzionale**
![[appunti bsd/mod i/immagini/Pasted image 20221123152355.png|center|700]]
![[appunti bsd/mod i/immagini/Pasted image 20221123152427.png|center|700]]
![[appunti bsd/mod i/immagini/Pasted image 20221123152510.png|center|700]]

La **relazione ricordiva 1:N** è oltre che con due relazioni è traducibile con una sola relazione che contiene due volte l'attributo identificatore, una volta come chiave priamaria e una volta come chiave esterna con un nome che riflette il ruolo dell'entità

## ER->Modello Relazionale N:N

La relazione N:N diventa una nuova relazione (tabella) composta dagli identificatori univoci delle due entità e dagli eventuali attributi dell'associazione. La chaive della nuova relazione è formata dall'insieme di attributi che compongono le chiavi delle due entità oltre agli attributi necessari a garantire l'unicità delle entità

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221123153139.png|center|700]]
![[appunti bsd/mod i/immagini/Pasted image 20221123153217.png|center|700]]

La **relazione ricorsiva N:N** è tradotta con 2 relazioni, una per l'entità e una per la relazione, la chiave della relazione che modella l'associazione è composta da 2 attributi, i cui nomi riflettono il diverso ruolo dell'entità. Ognuno di questi 2 attributi è anche chiave esterna

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221123153458.png|center|600]]
![[appunti bsd/mod i/immagini/Pasted image 20221123153617.png|center|600]]


# ER->Modello Relazionale - Generalizzazioni

Il modello relazionale non può rappresentare direttamente le **generalizzazioni**. Si eliminano quindi le gerarchie sostituendole con entità e relazioni/associazioni

**Esempio**
![[appunti bsd/mod i/immagini/Pasted image 20221123153929.png|center|700]]

Soluzione 1: accorpamento dell'entità padre nelle entità figlie
- Le soluzioni d'accesso distinguono tra occorrenze delle diverse entità figlie (accesso pèiù efficiente)
- le entità figlie introducono differenziazioni non sostanziali (pochi valori nulli)

![[appunti bsd/mod i/immagini/Pasted image 20221123162022.png|center|700]]

Soluzione 2: accorpamento dell’entità padre nelle entità figlie
- le operazioni d’accesso distinguono tra occorrenze delle diverse entità figlie (accesso più efficiente)
![[appunti bsd/mod i/immagini/Pasted image 20221123162107.png|center|700]]

Soluzione 3: sostituzione delle generalizzazioni con le associazioni
![[appunti bsd/mod i/immagini/Pasted image 20221123162148.png|center|700]]

















