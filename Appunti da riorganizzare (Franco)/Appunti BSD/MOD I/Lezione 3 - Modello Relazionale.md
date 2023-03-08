
- [[Lezione 3 - Modello Relazionale#Modello Relazionale|Modello Relazionale]]
- [[Lezione 3 - Modello Relazionale#Strutture Nidificate|Strutture Nidificate]]
- [[Lezione 3 - Modello Relazionale#Informazione incompleta|Informazione incompleta]]

# Modello Relazionale

Modello proposto da E. F. Codd nel 1970 per favorire **l'indipendenza dei dati**
Disponibile in **DBMS reali nel 1981**
Si basa sul concetto matematico di **relazione(con una variante)**. Le relazioni hanno naturale rappresentazione per mezzo di **tabelle**

## Relazione Matematica
- $D_1,..,D_n$: insieme anche non distinti detti **domini**
- il **prodotto cartesiano** $D_1\times...\times D_n$ è definito come: l'insieme di tutte le **n-uple($d_1,..,d_n$)** tali che $d_1\in D_1,...,d_n\in D_n$
- Una **relazione matematica** su $D_1,...,D_n$ è un sottoinsieme di $D_1\times...\times D_n$
- $D_1,...,D_n$ sono i **domini della relazione**

**Esempio**
![[Pasted image 20221102200220.png|center|500]]

### Relazione Matematica: Proprietà

Una relazione matematica è un insieme di n-uple ordinate: $(d_1,...,d_n)|d_1\in D_1,...,d_n\in D_n$
Una relazione è un **insieme**, quindi:
- _non c'è ordinamento_ fra le n-uple;
- le n-uple sono _distinte_
- _ciascuna n-upla è ordinata_: l'i-esimo valore proveien dall'i-esimo dominio

**esempio**
![[Pasted image 20221105103445.png|center|700]]

Ciascuno dei domini ha due **ruoli** diversi, distinguibili attraverso la posizione
La struttura è **posizionale**

## Struttura Non Posizionale
Se a ciascun dominio si associa un nome (**attributo**), che ne descrive il "ruolo", la struttura diviene non posizionale
![[Pasted image 20221105103918.png|center|500]]

## Collezione di funzioni
Per meglio catturare il concetto di relazione del modello relazionale definiamo:
- $X=\lbrace A_1,...,A_n\rbrace$ un insieme (**non ordinato**) di attributi
- $DOM=X\to D$: funzione che associa ad un attibuto il corrispondente dominio
Una _ennupla_ o _tupla_ è una funzione $t$ che associa ad ogni $A\in X$ un valore del dominio
$t[A]$ denota il valore della ennupla $t$ sull'attributo A

>Una _relazione_ è una collezione di _ennuple_

## Modello Relazionale: esempio
**Esempio di relazione**: Relazione rappresentata tramite tabella (solo una delle possibili forme)

![[Pasted image 20221105104410.png|center]]

## Modello Relazione: notazione
**Notazione**
Se $t$ è una tupla su $X$ e $A$ è un attributo, con $A\in X$ allora $t[A]$ indica il valore di t su A
**Esempio**: se t è la prima tupla allora...
$$t[Cognome]\to\:'Rossi'$$
![[Pasted image 20221105104628.png|center]]

### Tabelle e Relazioni

Una tabella rappresenta una relazione se:
- i valori di ogni _colonna_ sono fra loro omogenei
- le _righe_ sono _diverse_ fra loro
- le _intestazioni_ delle _colonne_ sono diverse tra loro
In una _tabella_ che rappresenta una _relazione_:
- l'ordinamento tra le righe è irrilevante
- l'ordinamento tra le colonne è irrilevante

**Esempi**
- Ordine non rilevante
- NO due righe uguali
- NO dati non omogenei
![[Pasted image 20221105104923.png|center|600]]
![[Pasted image 20221105105009.png|center|600]]

### Modello basato su valori
I riferimenti fra dati in relazioni diverse sono rappresentanti per mezzo di valori dei domini che compaiono nelle ennuple
![[Pasted image 20221105105126.png|center|600]]
![[Pasted image 20221105105211.png|center|600]]

#### Vantaggi della struttura basata sui valori

- Indipendenza dalle strutture fisiche (si potrebbe avere anche con puntatori di alto livello)  che possono cambiare dinamicamente
- Si rappresenta solo ciò che è rilevante dal punto di vista dell'applicazione
- l'utente finale vede gli stessi dati dei programmatori
- I dati sono portabili più facilmente da un sistema ad un altro
- I puntatori sono direzionali

## Modello Relazionale: definizioni

- **Schema di relazione**: un nome R con un insieme di attibuti $A_1,...,A_n$: $$R(A_1,..,A_n)$$
- **Schema basi di dati**: insieme di schemi di relazione $$R=\lbrace R_1(X_1),...,R_k(X_k)\rbrace$$
**Esempio schema di relazioni e di basi di dati**

![[Pasted image 20221105105801.png|center|600]]

- (Istanza di) **relazione** su uno schema $R(X)$: insieme $r$ di ennuple su X
- (Istanza di) **base di dati** su uno schema $R=\lbrace R_1(X_1),..,R_k(X_k)\rbrace$: insieme di relazioni $r=\lbrace r_1,...,r_n\rbrace$ (con $r_i$ relazione su $R_i$)

### Relazioni su singoli attributi
![[Pasted image 20221105110113.png|center|600]]


# Strutture Nidificate
![[Pasted image 20221105110203.png|center|600]]
## Rappresentazione relazionale delle strutture nidificate
![[Pasted image 20221105110238.png|center|600]]

- Abbiamo rappresentato veramente tutti gli aspetti delle ricevute?
- Dipende da che cosa ci interessa!
	- l'ordine delle righe è rilevante?
	- possono esistere linee ripetute in una ricevuta?
- Sono possibili rappresentazioni diverse

### Rappresentazione alternativa
![[Pasted image 20221105110459.png|center|600]]


# Informazione incompleta

Il modello relazionale impone ai dati una struttura rigida_
- le informazioni sono rappresentate per mezzo di ennuple
- solo alcuni formati di ennuple sono ammessi: quelli che corrispondono agli schemi di relazione
I dati disponibili possono non corrispondere al formato previsto

**Esempio**
![[Pasted image 20221105110719.png|center|500]]

## Soluzioni?

No conviene (anche se spesso si fa) usare valori del dominio (0,stringa vuota,"99",...):
- potrebbero non esistere valori "non utilizzati"
- valori "non utilizzati" potrebbero diventare significativi
- in fase di utilizzo (nei programmi) sarebbe necessario ogni volta tener conto del "significato" di questi valori

## Informazione incompleta nel modello relazionale
Si adotta una tecnica rudimentale ma efficace:
- **valore nullo**: denota l'assenza di un valore del dominio (e non è un valore del dominio)
- $t[A]$, per ogni attributo A, è un valore del dominio dom(A) oppure valore nullo NULL
- Si possono (e debbono) imporre restrizioni sulla presenza di valori nulli

**Esempio con troppi valori nulli**
![[Pasted image 20221105111347.png|center|500]]

## Tipi di valore nullo

Almeno tre casi differenti:
- valore **sconosciuto**
- valore **inesistente**
- valore **senza informazione**

**Oss** I DBMS non distinguono i tipi di valore nullo
