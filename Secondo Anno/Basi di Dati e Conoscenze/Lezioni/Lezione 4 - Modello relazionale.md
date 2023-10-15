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








# Strutture nidificate



# Informazione incompleta


