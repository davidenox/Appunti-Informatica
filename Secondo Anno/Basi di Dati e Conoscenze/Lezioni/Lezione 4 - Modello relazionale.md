# Modello relazionale
Proposto da E. F. Codd nel 1970 per favorire l'*indipendenza dei dati*. Disponibile in *DBMS reali nel 1981*. Si basa sul concetto matematico di *relazione* ( con una variante ). Le relazioni hanno naturale rappresentazione per mezzo di **tabelle**.
## Relazione matematica
1. $D_1, ..., D_n$ : Insiemi anche non distinti detti *domini*.
2. Il *prodotto cartesiano* $D_1\times ... \times D_n$ è definito come :
>[!important]- L'insieme di tutte le *n-uple* $(d_1,...,d_n)$ tali che $d_1\in D_1,...,d_n\in D_n$
3. Una *relazione matematica* su $D_1,...,D_n$ è un  sottoinsieme di $D_1\times ... \times D_n$.
4. $D_1,...,D_n$ sono i *domini della relazione*.

$D_1=\{A,B\} \implies \begin{matrix} A\\B \end{matrix}$            $D_2=\{X,Y,Z\} \implies \begin{matrix} X\\Y\\Z \end{matrix}$
*Prodotto cartesiano* $D_1\times D_2$      $\begin{matrix} A X \\ A Y \\ A Z \\ B X \\ B Y \\ B Z \end{matrix}$
*Relazione* $r ? D_1\times D_2$ $\begin{matrix} A X \\ B Y \\ B Z \end{matrix}$
### Relazione matematica : Proprietà
Una *relazione matematica* è un insieme di n-uple ordinate:
- - $(d_1,...,d_n)$ tali che $d_1\in D_1,...,d_n\in D_n$ .
Una relazione è un **insieme**, quindi:
1. *Non c'è ordinamento* fra le n-uple;
2. Le n-uple sono *distinte*;
3. *Ciascuna n-upla è ordinata* : l'i-esimo valore proviene dall'i-esimo dominio.
### Relazione matematica : Esempio
$$Partite\subseteq string\times string\times int\times int$$

| Juve  | Lazio | 3   | 1   |
| ----- | ----- | --- | --- |
| Lazio | Milan | 2   | 0   |
| Juve  | Roma  | 0   | 2   |
| Roma  | Milan | 0   | 2   |

Ciascuno dei domini ha due *ruoli* diversi, distinguibili attraverso la posizione: la struttura è *posizionale*.
#### Struttura non posizionale
Se a ciascun dominio si associa un nome ( *attributo* ), che ne descrive il "ruolo", la struttura diventa non posizionale :

| Casa  | Fuori | RetiCasa | RetiFuori |
| ----- | ----- | -------- | --------- |
| Juve  | Lazio | 3        | 1         |
| Lazio | Milan | 2        | 0         |
| Juve  | Roma  | 0        | 2         |
| Roma  | Milan | 0        | 2         |
## Collezione di funzioni
Per meglio catturare il concetto di relazione del modello relazionale definiamo :
1. $X=\{A_1,...,A_n\}$ : un insieme ( *non ordinato* ) di attributi;
2. $DOM=X\Rightarrow D$ :  funzione che associa ad un attributo il corrispondente dominio.
	- - Una *ennupla* o *tupla* è una funzione *t* che associa ad ogni $A\in X$ *un valore del dominio*.
	- - $t[A]$ denota il valore della ennupla *t* sull'attributo *A*.
	- 
>[!important]- Una *relazione* è una collezione di **ennuple**.

## Modello relazionale : Esempio
**Esempio di relazione** : Relazione rappresentata tramite tabella ( solo una delle possibili forme)

| Nome  | Cognome | Matricola | Voto medio |
| ----- | ------- | --------- | ---------- |
| Mario | Rossi   | 1         | 24         |
| Luigi | Bianchi | 2         | 28         |
| Rosa  | Rossa   | 3         | 26         |

*Notazione* : Se *t* è una tupla su *X* e *A* è un attributo, con $A\in X$, allora $t[A]$ indica il valore di $t$ su *A*.
**Esempio** : Se *t* è la prima tupla allora... $$t[cognome]\rightarrow'Rossi'$$

| Nome  | Cognome | Matricola | Voto medio |
| ----- | ------- | --------- | ---------- |
| Mario | -***Rossi***-   | 1         | 24         |
| Luigi | Bianchi | 2         | 28         |
| Rosa  | Rossa   | 3         | 26         |

## Tabelle e relazioni
Una tabella rappresenta una relazione se : 
1. I valori di ogni *colonna* sono fra loro *omogenei*;
2. Le *righe* sono *diverse* fra loro;
3. Le *intestazioni* delle *colonne* sono diverse tra loro.
In una *tabella* che rappresenta una *relazione* :
1. L'ordinamento tra le righe è irrilevante ; 
2. L'ordinamento tra le colonne è irrilevante.
### Modello basato sui valori
I riferimenti fra dati in relazioni diverse sono rappresentati per mezzo di valori dei domini che compaiono nelle ennuple.
![[Pasted image 20231016103041.png|center]]

### Vantaggi della struttura basata sui valori
- - Indipendenza dalle strutture fisiche ( si potrebbe avere anche con puntatori di alto livello ) che possono cambiare dinamicamente;
- - Si rappresenta solo ciò che è rilevante dal punto di vista dell'applicazione;
- - L'utente finale vede gli stessi dati dei programmatori;
- - I dati sono portabili più facilmente da un sistema ad un altro;
- - I puntatori sono direzionali.
## Modello relazionale : Definizioni
1. *Schema di relazione* : 
	- Un nome $R$ con un insieme di attributi $A_1,...,A_n$ : $$R(A_1,...,A_n)$$
2. *Schema di base di dati* :
	- Insieme di schemi di relazione :$$R=\{R_1(\chi_1),...,R_n(\chi_n)\}$$

### Schema di relazione e basi di dati
	Esempio
- - *Schema di relazione*
```SQL
STUDENTI(Matricola, Cognome, Nome, Data di Nascita)
```
- - *Schema di basi di dati*
```SQL
STUDENTI(Matricola, Cognome, Nome, Data di Nascita)
ESAMI(Matricola, Voto, Corso)
CORSO(Codice, Titolo, Docente)
```
## Tornando alle definizioni
- - (Istanza di) *relazione* su uno schema $R(\chi)$:
	- Insieme $r$ di ennuple su $\chi$
- - (Istanza di) *base di dati* su uno schema $R=\{R_1(\chi_1),...,R_n(\chi_n)\}$:
	- Insieme di relazioni $r=\{r_1,...,r_n\}$ ( con $r_i$ relazione su $R_i$)
### Relazioni sui singoli attributi

![[Pasted image 20231016104501.png|center|500]]
# Strutture nidificate
![[Pasted image 20231016104604.png|center|400]]
![[Pasted image 20231016104626.png|center|400]]
## Rappresentazione relazionale delle strutture nidificate
![[Pasted image 20231016104730.png|center]]
![[Pasted image 20231016104754.png|center]]

Abbiamo rappresentato veramente tutti gli aspetti delle ricevute? Dipende da cosa ci interessa. L'ordine delle righe è rilevante? Possono esistere linee ripetute in una ricevuta?
Sono possibili rappresentazioni diverse.
### Rappresentazione alternativa
![[Pasted image 20231016104959.png|center]]
![[Pasted image 20231016105019.png|center]]

# Informazione incompleta
Il modello relazionale impone ai dati una struttura rigida :
- - Le informazioni sono rappresentate per mezzo di ennuple;
- - Solo alcuni formati di ennuple sono ammessi: quelli che corrispondono agli schemi della relazione.
I dati disponibili possono non corrispondere al formato previsto.
## Informazione incompleta : Motivazioni

| Nome     | SecondoNome | Cognome   |
| -------- | ----------- | --------- |
| Franklin | Delano      | Roosevelt |
| Winston  |             | Churchill |
| Charles  |             | De Gaulle |
| Josip    |             | Stalin    |

## Informazione incompleta : Soluzioni?
Non conviene ( anche se spesso si fa ) usare i valori del dominio ( 0, stringa nulla, "99",...):
- - Potrebbero non esistere valori "non utilizzati";
- - Valori "non utilizzati" potrebbero diventare significativi;
- - In fase di utilizzo ( nei programmi ) sarebbe necessario ogni volta tener conto del "significato" di questi valori.

