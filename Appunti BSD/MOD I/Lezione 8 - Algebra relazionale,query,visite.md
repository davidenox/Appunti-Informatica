# Argomenti

- Linguaggi di interrogazione
- Algebra Relazionale
- Operatori insiemistici
- Ridenominazione
- Selezione
- Join
- Theta Join
- Query

# Linguaggi per base di dati

- Operazioni sullo schema
	- **DDL: Data Definition Language**
- Operazione sui dati:
	- **DML: Data Manipulation Language**
		- Interrogazione ("query")
		- Aggiornamento

## Linguaggi di interrogazione per basi di dati relazionali

- **Dichiarativi**: specificano le proprietà del risultato ("**che cosa**")
- **Procedurali**: specificano le modalità di generazione del risultato ("**come**")

## Linguaggi Relazionali

- **Algebra relazionale**: procedurale
	- Insieme di operatori
		- Su relazioni
		- Che producono relazioni
		- E possono essere composti
- **Calcolo Relazionale**: dichiarativo (teorico)
	- Basato sul calcolo dei predicati del primo ordine
	- Connettivi e clausole che consentono di descrivere la relazione del risultato
- **SQL (Structured Query Language)**: intermedio (reale)
- **QBE (Query by Example)**: dichiarativo (reale)

# Algebra Relazionale

Linguaggio procedurale, in cui le operazioni vengono descritte descrivendo la procedura per ottenere la soluzione.

**Operatori di base**: 
- **Unione,Differenza,Intersezione**: derivati dalla teoria degli insiemi
- **Ridenominazione,Selezione,Proiezione**: specifici dell'algebra relazionale
- **Join**: che può assumere diverse forme (naturale, theta-join,prodotto cartesiano)

# Operatori insiemistici

Le relazioni sono **insiemi** e quindi è naturale estendere ad esse le operazioni relative.

Tuttavia le relazioni sono insiemi di tuple **omogenee** e quindi ha senso definire ed applicare tali operatori solo a tuple **definite sugli stessi attributi**

Es. l'unione fra due relazioni su tuple non omogenee _non è_ una relazione

## Operatori derivati dagli insiemi

- **Unione**: L'unione fra due relazioni $r_1,r_2$ definite sullo stesso insieme di attributi X è indicata con $r_1\cup r_2$ ed è una relazione su X contenente le tuple che appartengono a $r_1$ o $r_2$ oppure entrambe
- **Intersezione**: L'intersezione fra due relazioni $r_1,r_2$ definite sullo stesso insieme di attributi X è indicata con $r_1\cap r_2$ ed è una relazione su X contenente le tuple che appartengono sia a $r_1$ che a $r_2$
- **Differenza**: La differenza fra due relazioni $r_1,r_2$ definite sullo stesso inisme edi attributi X è indicata con $r_1-r_2$ ed è una relazione su X contenente le tuple che appartengono a $r_1$ e non a $r_2$

Per esempio:

![[appunti bsd/mod i/immagini/Pasted image 20230113121721.png|center|600]]

# Ridenominazione

L'operazione di **ridenominazione** cambia il nome degli attributi allo scopo di facilitare operazioni insiemistiche

é un operatore che consente di modificare il nome di un attributo per poterlo associare ad un altro attributo in una operazione algebrica:
- operatore **monadico** (con argomento)
- "**modifica lo schema**" lasciando inalterata l'istanza dell'operando

SI indica con "$\rho$ nuovonome $\leftarrow$ vecchionome (Relazione)"

La ridenominazione $\rho_{B1,B2,...,Bk\leftarrow A1,A2,...,Ak}(R)$ contiene tuple $t'$ tali che $t'$ è una tupla e $t'[B_i]=t[A_i]$, cioè cambiano i nomi degli attributi ma i valori non cambiano

**Esempio**: Date le relazioni
- **Paternità** (Padre,Figlio)
- **Maternità** (Madre,Figlio)
è possibile ottenere : **$\rho$ Genitore $\leftarrow$ Padre (Paternità) $\cup$ $\rho$ Genitore $\leftarrow$ Madre (Maternità)**

**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20230113122711.png|center|500]]
![[appunti bsd/mod i/immagini/Pasted image 20230113122810.png|center|500]]

# Selezione e Proiezione

Le operazioni di **selezione** e di **proiezione** si applicano ad una relazione e ne restituiscono una porzione

Possono essere considerate ortogonali o complementari, in quanto una opera sulle **righe** el'altra sulle **colonne**

La **selezione** produce un insieme di tuple, su tutti gli attributi

La **produzione** produce un risultato definito su un inseme di attributi, cui contribuiscono tutte le tuple

![[appunti bsd/mod i/immagini/Pasted image 20230113123542.png|center|500]]

- Operatore **monadico**
- Produce un risultato che:
	- ha lo stesso schema dell'operando
	- contiene un sottoinsieme delle ennuple dell'operando che soddisfano una **specifica _condizione di selezione_**
- Si indica con $\sigma_F(r)$ o $SEL_F(r)$, dove:
	- F è una condizione da verificare
	- r è la relazione a cui la selezione è applicata definita su un insieme di attributi X

Quindi, $\sigma_F(r)$ produce una relazione sugli stessi attributi di r contenente le ennupla su cui F è vera (**semantica**)

## Selezione: Condizione di selezione

- F è una formula proposizionale su X, cioè una formula ottenuta combinando con i simboli $\land(and),\lor(or),\lnot(not)$ espressioni del tipo $A\theta B$ o $A\theta c$, dove:
	- $\theta$ è un operatore di confronto ($\leq,\lt,=,\gt,\geq$)
	- A e B sono attributi di X su cui il confronto abbia senso
	- c è una costante tale che il confronto con A sia definito
- è definito un valore di verità di F su una ennupla $t\in r$:
	- $A\theta B$ è vera se e solo se $t[A]\theta t[B]$ è vero
	- $A\theta c$ è vera se $t[A]\theta c$ è vera
	- $F_1\land F_2,F_1\lor F_2,\lnot F$ hanno l'usuale significato

**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20230113155508.png|center|500]]

![[appunti bsd/mod i/immagini/Pasted image 20230113155614.png|center|500]]

## Selezione con valori nulli

![[appunti bsd/mod i/immagini/Pasted image 20230113155721.png|center|500]]

- Perchè? Perchè le selezioni vengono valutate separatamente!
- Ma anche $$\sigma_{Età\gt30\lor Età\leq30}(Persone)\neq Persone$$
- Perchè? Perchè anche le condizioni atomiche vengono valutate separatamente!

Per riferisi ai valori nulli esistono forme apposite di condizioni:$$\begin{align}&\text{Is Null}\\&\text{Is Not Null}\end{align}$$
![[appunti bsd/mod i/immagini/Pasted image 20230113160103.png|center|500]]

# Proiezione

Dati una relazione $r(X)$ e un sottoinsieme Y di X, la proiezione di r su Y si indica con 
$$\Pi_Y(r),PROJ_Y(r)$$
l'insieme delle ennuple su Y ottenute dalle ennuple di r considerando solo i valori su Y

La proiezione $\Pi_Y(r)$ è l'insieme di tuple su un sottoinsieme Y di attributi X di R, ottenuta dalle tuple  di R considerando solo i valori su Y cioè:
$$\Pi_Y(r)=\{t[Y]:t\in r\}$$
Una proiezione ha un numero di tuple _minore o uguale_ rispetto alla relazione r cui è applicata. Il numero di tuple è uguale se e solo se **Y è superchiave per r**

**Esempio**:

Visualizzare matricola e cognome di tutti i cittadini

![[appunti bsd/mod i/immagini/Pasted image 20230113160642.png|center|500]]
 
# Join

Combinando selezione e proiezione, si possono estrarre informazioni da **una** relazione

Non si possono però correlare informazioni presenti in relazioni diverse

Il **join** è l'operatore più interessante (potente) dell'algebra relazionale in quanto permette di correlare dati in relazioni diverse

Evidenzia la prorpietà del modello relazione di essere **basato su valori**

Due tipi di join:
- **Join naturale**
- **Theta Join**

## Join naturale

L'operatore di **join naturale** $r_1\Join r_2$ (o $r_1|X|r_2$) correla dati in relazioni diverse sulla base di valori uguali in attributi con lo stesso nome

Il **join naturale** $r_1\Join r_2$ di $r_1(X),r_2(x)$ è una relazione definita su $X_1\cup X_2$ (che si può scrivere $X_1X_2$):
$$r_1\Join r_2=\{t\in X_1X_2:t[X_1]\in r_1,t[X_2]\in r_2\}$$
- Il grado di una relazione ottenuta è minore o uguale al grado della somma dei gradi delle due relazioni in quanto gli attributi omonimi compaiono una sola volta
- se $X_1\cap X_2$ è vuoto, il join naturale equivale al **_prodotto cartesiano_** fra le relazioni
- se $X_1=X_2$, il join naturale equivale all'intersezione fra le relazioni


- Se ciascuna ennupla di ciascuno degli operandi contribuisce ad almeno una ennupla del risultato il join si dice **_completo_**
- Se per alcune ennuple non è verificata la corrispondenza e non contribuiscono al risultato, le ennuple si dicono **_dangling_**
- Ai due estremi si pongono il join vuoto, in cui nessuna ennupla delgi operandi è combinabile, e quello in cui ciascuna delle ennuple dell'operando è combinabile con tutte le ennuple dell'altro. In questo caso la cardinalità della relazione risultatne è pari al prodotto della cardinalità degli operandi

**Esempio join naturale completo**

Ogni ennupla contribuisce al risultato: join **completo**

![[appunti bsd/mod i/immagini/Pasted image 20230114102556.png|center|500]]

**Esempio join non completo**

![[appunti bsd/mod i/immagini/Pasted image 20230114102652.png|center|500]]


**Esempio join vuoto**

![[appunti bsd/mod i/immagini/Pasted image 20230114102750.png|center|500]]


### Join naturale: Proprietà

1. Il join di $r_1,r_2$ contiene un numero di ennuple compreso fra zero e il prodotto di $|r_1|,|r_2|$
2. Se il join di $r_1,r_2$ è **completo** allora contiene un numero di tuple pari almeno al massimo fra $|r_1|,|r_2|$
3. Se $X_1\cap X_2$ contiene un achiave per $r_2$, allora il join di $r_1(X),r_2(X)$ contiene almeno $|r_2|$ tuple
4. Se il join coinvolge una chaive di $r_2$ e un **vincolo di integrità referenziale**, allora il numero di tuple è pari a $|r_1|$
5. Il join è **_commutativo_**, infatti $r_1\Join r_2=r_2\Join r_1$
6. il join è **_associativo_**, infatti $(r_1\Join r_2)\Join r_3=r_1\Join(r_2\Join r_3)$. Quindi sequenze di join possono essere scritte senza parentesi

### Prodotto cartesiano

- Un join naturale senza attributi in comune
- Contiene sempre un numero di ennuple pari al prodotto delle cardinalità degli operandi (le ennuple sono tutte combinabili)
- il prodotto cartesiano $r_1\times r_2$ di $r_1(X_1),r_2(X_2)$ è una relazione definita su $X_1\cup X_2$ : $$r_1\times r_2=\{t\in X_1X_2:t[X_1]\in r_1,t[X_2]\in r_2\}$$
**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20230114103942.png|center|500]]

## Join esterni: Outer Join

- Il **join naturale** tralascia le ennuple in cui non ci è corrispondenza fra gli attributi legati dal join
- L'operatore di _join esterno_ (**outer join**) prevede che tutte le tuple diano sempre un contributo al risultato, eventualmente estese con valori nulli ove non vi siano controparti opportune

Tre tipi di outer join:
- **Left join**: Contribuiscono tutte le ennuple del primo operando eventualmente estese con valori nulli
- **Right join**: Contribuiscono tutte le ennuple del secondo operando eventualmente estese con valori nulli
- **Full join**: Contribuiscono tutte le ennuple del primo e del secondo operando eventualmente estese con valori nulli

### Left Join

Ritorna tutte le tuple dalla relazione di sinistra a prescindere dal fatto che siano combinabili con quelle della relazione di destra

Assegna valori nulli per i record che non matchano

**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20230114104538.png|center|500]]

### Right Join

Ritorna tutte le tuple dalla relazione di destra a prescindere dal fatto che siano combinabili con quelle della relazione di sinistra

Assegna valori nulli per i record che non matchano

**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20230114104805.png|center|500]]

### Full Join

Combina i risultati di due relazioni tenendo conto di tutte le tuple delle relazioni, anche di quelle che non hanno corrispondenza tra di loro
Il risultato contiene sempre tutte le tuple della relazione di sinistra ("left"), estraendo dalla relazione di destra ("right") solamente le tuple che trovano corrispondenza nella regola di confronto; inoltre verranno estratte tutte le tuple della relazione di sinistra ("left") che non trovano corrispondenza nella relazione di destra ("right") impostando a nulli i valori di tutti gli attributi della relazione di destra, e viceversa

**Esempio**

![[appunti bsd/mod i/immagini/Pasted image 20230114105214.png|center|500]]

## Theta Join

Si devono correlare attributi con nome diverso è possibile fare il **theta-join** ($\Join_\theta$), definito come un prodotto cartesiano seguito da una selezione 
$$r_1\Join_{\theta F} r_2=\sigma_F(r_1\times r_2)$$
Dove F è una formula e $r_1,r_2$ non hanno attributi di nome comune
Se F è una relazione di uguaglianza, con un attributo della prima relazione e uno della seconda, allora siamo in presenza di un **equi-join**

Sono importati formalmente:
- il join naturale è basato sui **_nomi_** degli attributi
- equi-join e theta-join sono basati sui _**valori**_

![[appunti bsd/mod i/immagini/Pasted image 20230114110111.png|center|500]]

**Esempio join naturale ed equi-join**

![[appunti bsd/mod i/immagini/Pasted image 20230114110446.png|center|700]]

## Join e proiezioni: perdita di informazioni

- $R_1(X_1),R_2(X_2)$ $$\Pi_{X_1}(R_1\Join R_2)\subseteq R_1$$
- $R(X),X=X_1\cup X_2$ $$(\Pi_{X_1}(R))\Join(\Pi_{X_2}(R))\supseteq R$$
## Join e proiezioni: problemi

![[appunti bsd/mod i/immagini/Pasted image 20230114111128.png|center|600]]

![[appunti bsd/mod i/immagini/Pasted image 20230114111350.png|center|600]]

# Query

Un’interrogazione è una funzione $E(R)$ che applicata ad istanze di una base di dati $R$ produce una relazione su un dato insieme di attributi $X$.
Le interrogazioni su uno schema di base di dati $R$ in algebra relazionale sono espressioni i cui atomi (le variabili) sono relazioni in $R$ o costanti.

Le interrogazioni sono in pratica espressioni di relazioni che producono relazioni

![[appunti bsd/mod i/immagini/Pasted image 20230114111846.png|center|600]]

**Esempio**

Trovare matricola, nome, età e stipendio degli impiegati che guadagnano più di 40 milioni

![[appunti bsd/mod i/immagini/Pasted image 20230114111950.png|center|600]]

![[appunti bsd/mod i/immagini/Pasted image 20230114114519.png|center|600]]

Per esercizi vedi pagina 59 del pdf 9-AlgebraRelazionale.pdf

## Equivalenza di espressioni

Due espressioni sono **equivalenti** se:

- $E_1\equiv_R E_2$ se $E_1(r)=E_2(r)$ per ogni istanza r di R (**equivalenza dipendente dallo schema**)
- $E_1\equiv E_2$ se $E_1\equiv_R E_2$ per ogni schema R (**equivalenza assoluta**)

L'equivalenza è importante in quanto consente di scegliere, a parità di risultato,l'operazione meno  costosa

- **Atomizzazione delle selezioni** $$\sigma_{F_1\land F_2}(E)\equiv\sigma_{F_1}(\sigma_{F_2}(E))$$
- **Indempotenza delle proiezioni**$$\Pi_X(E)\equiv\Pi_X(\Pi_{XY}(E))$$
- **Anticipazione della selezione rispetto al join** $$\sigma_F(E_1\Join E_2)\equiv(\sigma_F(E_1))\Join(\sigma_F(E_2))$$

- Anticipazione della proiezione rispetto al join: $$\Pi_{X_1Y_2}(E_1\Join E_2)\equiv E_1\Join\Pi_{Y_2}(E_2)$$ (Se gli attributi in $X_2-Y_2$ non sono coinvolti nel join). Allora (combinando con inmepotenza delle proiezioni) : $$\Pi_Y(E_1\Join_F E_2)\equiv\Pi_Y(\Pi_{Y_1}(E_1\Join_F\Pi_{Y_2}(E_2)))$$ dove $Y_1,Y_2$ sono gli attributi di $X_1,X_2$ compresi in $Y$ o coinvolti nel join. In pratica è possibile ignorare in ciascuna relazione gli attributi non compresi in Y e non coinvolti nel join
- **Inglobamento di una selezione in un prodotto cartesiano a formare un join**: $$S_F(E_1\Join E_2)\equiv E_1\Join_F E_2$$

- **Distributività** della selezione rispetto all'unione: $$S_F(E_1\cup E_2)\equiv S_F(E_1)\cup S_F(E_2)$$
- **Distributività della selezione rispetto alla differenza**: $$S_F(E_1-E_2)\equiv S_F(E_1)- S_F(E_2)$$
- Distributività della proiezione rispetto **all'unione**: $$P_X(E_1\cup E_2)\equiv P_X(E_1)\cup P_X(E_2)$$ NB: **La proiezione NON è distributiva rispetto alla differenza**
- Tutti gli operatori binari eccetto la differenza godono delle proprietà associativa e commutativa

- Corrispondenze fra operatori insiemistici e selezioni complesse $$\begin{align}&\sigma_{F_1\lor F_2}(R)\equiv\sigma_{F_1}(R)\cup\sigma_{F_2}(R)\\&\sigma_{F_1\land F_2}(R)\equiv\sigma_{F_1}(R)\cap\sigma_{F_2}(R)\\&\sigma_{F_1\land\lnot F_2}(R)\equiv\sigma_{F_1}(R)-\sigma_{F_2}(R)\end{align}$$
- Proprietà distributiva del join rispetto all'unione: $$E\Join(E_1\cup E_2)\equiv(E\cup E_1)\Join(E\cup E_2)$$
## Algebra con valori nulli

Estensione degli operatori logici ad una logica a 3 valori (VERO,FASLO,SCONOSCIUTO(U))

![[appunti bsd/mod i/immagini/Pasted image 20230114121814.png|center|500]]

- A IS NULL è vero su una ennupla t se il valore di t su A è nullo; falso se è specificato.
- A IS NOT NULL è vero su una tupla t se il valore di t su A è specificato; falso se è nullo.

![[appunti bsd/mod i/immagini/Pasted image 20230114122108.png|center|500]]


