  # Introduzione alla probabilità e statistica

## Il fenomeno aleatorio

_Def :_
Un fenomeno è detto aleatorio se il suo esito è incerto.
L'insieme dei possibili esiti (in genere "numerico", eventualmente multidimensionale) viene indicato con $\Omega$ (Omega)

Si divide in due gruppi:
- Discreto : se $\Omega$ è finito o numerabile
- Continuo : se $\Omega$ è più che numerabile

Esempi discreti:
1) $\Omega$ finito (Possibili risultati del lancio di un dato) $\Omega$ = {1,2,3,4,5,6}
2) $\Omega$ numerabile (Numero di telefonate ricevute da un centralino) $\Omega$ = {0,1,2,...}

Esempio continuo:
1) Tempo di funzionamento di una lampadina rispetto ad una certa unità di misura $\Omega$ = (0,$\infty$)

In generale si introduce una "Famiglia di eventi" A che viene individuata da una famiglia di sottoinsiemi di $\Omega$

Tornando agli esempi : 
- "esce un numero pari" $\iff$ $\{ 2,4,6 \}  \subset \{1,2,...,6\}$
- "Il centralino si spegne dopo il tempo t=5" $\iff (5,\infty) \subset (0,\infty)$

Allora viene naturale considerare la corrispondenza tra "<u>Operazioni logiche tra eventi</u>" e "<u>Operazioni insiemistiche</u>":

- Somma logica : $A \lor B \implies$ Unione: $A\cup B$ 
- Prodotto logico : $A \land B \implies$ Intersezione: $A \cap B$
- Negazione: $\overline{A} \implies$ Complementare: $A^c = \Omega * A$  

## Sigma-algebra($\sigma$-algebra)

Si vuole fare riferimento a "Famiglia di eventi con buone proprietà". Si intende che, facendo operazioni insiemistiche su elementi di A, si ottiene ancora un elemento di A

_Def :_

Sia $\Omega$ un insieme non vuoto e sia A $\subset \mathcal{P}(\Omega)$
Allora A è una $\sigma-algebra$ (di eventi) se:
1) $\Omega \ni A$
2) $\forall a \ni A \implies a^c \ni A$
3) $\forall\{A_n\}_{n\geq1} \subset A \implies \bigcup_{n\geq1} A_n \ni A$

OSS: si vede facilmente che anche $\emptyset \ni A$ e che $\bigcap_{n\geq1} A_n \ni A$ nella 3)

## Misure di probabilità

_Def :_

Sia $\Omega$ un insieme non vuoto e A una $\sigma-algebra$ di eventi
Allora la funzione ${P: A\implies [0,\infty)}$ è una <u>misura di probabilità</u> se:
1) $P{(\Omega)} = 1$
2) $\forall \{A_n\}_{n\geq1} \subset A$ t.c. $A_m \cap A_n = \emptyset$ per m $\neq$ n si ha:

P($\bigcup_{n\geq1} A_n$) = $\sum_{n\geq1}P{(A_n)}$

**Terminologia**: la terna ($\Omega$,A,P) è detta <u>spazio di probabilità</u>


**Commenti** :

1) La misura di probabilità $P:A\implies[0,\infty)$ in realtà assume valori in $[0,1]$
2) La richiesta $A_m\cap A_n = \emptyset$ per m $\neq$ n è più forte della condizione $\bigcap_{n\geq1} A_n = \emptyset$. 

### Conseguenze della definizione di misura di probabilità
1) P($\emptyset$) = 0
infatti se consideriamo $A_n = \emptyset$ $\forall n\geq1$, sia ha $A_m\cap A_n = \emptyset$ per m $\neq$ n  da cui segue:

>$$\begin{cases}
P(\bigcup_{n\geq1} A_n) = P(\bigcup_{n\geq1}\emptyset)=P(\emptyset) \\
\sum_{n\geq1}P{(A_n)}=\sum_{n\geq1}P{(\emptyset)}
\end{cases}\implies P(\emptyset) = \sum_{n\geq1}P{(\emptyset)}$$

Questa condizione non può essere vera per P($\emptyset$) > 0; infatti il secondo membro sarebbe infinito.
Quindi si deve avere P($\emptyset$) = 0 e l'uguaglianza vale come 0=0

2) sia $h \geq1$ e ${(B_1,...,B_h)} \ni A$ con $B_m \cap B_n$ per $m\neq n$ allora P($\bigcup_{n=1}^{h} B_n$) = $\sum_{n=1}^{h} P(B_n)$
Infatti basta fare riferimento alla condizione 2 nella definizione con:
$A_1=B_1, A_2=B_2,...,A_h=B_h,A_{h+1}=A_{h+2}=...=\emptyset$
Infatti, con questa scelta, si ha $A_m\cap A_n=\emptyset$ per $m\neq n$ e si ha:
P($\bigcup_{n\geq1}A_n) = \sum_{n\geq1}P(A_n)$ da cui segue:

>$$\begin{cases}
\bigcup_{n\geq1}A_n = B_1\cup B_2\cup...\cup B_h\cup \emptyset \cup \emptyset \cup \emptyset...=\bigcup_{n=1}^{h}\implies P(\bigcup_{n\geq1}A_n)=P(\bigcup_{n=1}^{h} B_n)
\\
\sum_{n\geq1}P(A_n) = P(B_1)+...+P(B_h)+P(\emptyset)+..+P(\emptyset)+..=\sum_{n=1}^{h}B_n
\end{cases}$$

**OSS:** P($\emptyset$) = 0

e quindi si ottiene P($\bigcup_{n=1}^{h}B_n$) = $\sum_{n=1}^{h}B_n$

3) Specializziamo l'uguaglianza appena verificata prendendo $E,F\ni A$, h=2, $B_1=E\cap F, B_2=E\cap F^c$ 
	Allora $P((E\cap F)\cup (E\cap F^c))=P(E\cap F)+P(E\cap F^c)$ 
	**OSS:** $P((E\cap F)\cup (E\cap F^c))$ = P(E)
	$\implies P(E)=P(E\cap F)+P(E\cap F^c)$ 

3.1) (con E=$\Omega$) 
		1=$P(F)+P(F^c)$  $\forall F\ni A$
		e quindi $$\begin{cases}
		P(F) = 1-P(F^c)\\
		P(F^c) = 1-P(F)
		\end{cases}$$
3.2) (con $F\subset E$) 
		$P(E) = P(F) + P(E\cap F^c) \geq P(F) \implies P(E)\geq P(F)$ 
	 Da questo segue che $P(\Omega)\geq P(A) = 1$ $\forall A\ni A$ 

3.3) Specializziamo la formula al punto 2) con $E,F\ni A, h=3,B_1=E\cap F^c, B_2=E\cap F, B_3=F\cap E^c$
Ovviamente $B_1\cup B_2\cup B_3 = E\cup F$, e quindi $P(E\cup F) = P(B_1)+P(B_2)+P(B_3) = P(E\cap F^c)+P(E\cap F)+P(F\cap E^c)$ = 

$P(E\cap F^c)+P(E\cap F)+P(F\cap E^c)+P(E\cap F)-P(E\cap F)$

$\implies$ >$P(E\cup F)= P(E)+P(F)-P(E\cap F)$

**Oss** $P(E\cap F^c)+P(E\cap F)=P(E)$ e $P(F\cap E^c)+P(E\cap F) = P(F)$


La formula ottenuta nella 3.3) si estende al caso più di due eventi(**IDENTITà DI BONFERRONI**)

(SOSTANZIALMENTE è IL PRINCIPIO DI INCLUSIONE-ESCLUSIONE)

**COMMENTO GENERALE**

Le proprietà della misura di probabilità sono svincolate dalla costruzione del modello, e quindi da come si definisce la misura di probabilità in questione per descrivere il fenomeno aleatorio

## Spazio di probabilità uniforme discreto
Questa terminologia si usa nel caso in cui si ha la seguente situazione:
- $\Omega$ insieme finito
- $A=\mathcal{P}(\Omega)$ 
- $\forall a\ni A$ vale che $P(A)=|A|/|\Omega| = |A|/n$           (|A| è la cardinalità di A)

Questa situazione viene fuori imponendo la seguente condizione: $\forall \omega \ni \Omega$   P($\omega$) assume sempre lo stesso valore.

Infatti, se questo valore lo indichiamo con p, allroa abbiamo le seguenti uguaglianze:

>$1=P(\Omega)=P(\bigcup_{\omega \ni \Omega}{\omega})=\sum_{\omega \ni \Omega} P({\omega}) = \sum_{\omega \ni \Omega} p = np \implies p=1/n$

Allora, per ogni $A\ni A$, si ha $P(A) = P(\bigcup_{\omega \ni A}\omega) = \sum_{\omega \ni A} p = p\cdot |A| = |A|/n$ 

**Commenti** 

1) In questo caso P(A) = 0 $\iff$ A=$\emptyset$ 
2) Questa situazione esce fuori quando si compiono "estrazioni a caso da un insieme di n oggetti"
3) Questa costruzione non può essere fatta nel caso di cui $\Omega$ è definito numerabile perchè si avrebbe infinito a denominatore e quindi si avrebbe sempre P(A) = 0. In altri termini non si riesce a modellare il caso di estrazioni a caso da un insieme infinito numerabile di oggetti
4) Questo modello si può usare nel caso del lancio di un dado equo con n =6 e $\Omega={1,2,3,4,5,6}$

_Def :_
Sia ($\Omega,A,P$) uno spazio di probabilità. Siano A,B$\ni A$ con P(B)$\neq0$
Allora si definisce "Probabilità condizionata di A in B"(oppure sapendo che si è verificato l'evento B) la seguente quantità:
>$P(A|B)=P(A\cap B)/P(B)$

**Motivazione**

Nel voler definire P(A|B) è naturale considerare una quantità che dipende da P(A$\cap B$) proporzionalmente, con una costante di proporzionalità che non dipende da A(e che dipende da B):
$P(A|B)=c_b\cdot P(A\cap B)$
Inoltre si vule fare in modo che $(\Omega,A,P(.|B))$ sia uno spazio di probabilità. Quindi per $A=\Omega$ si ha:
$P(\Omega|B) = c_b\cdot P(\Omega\cap B) \implies c_b = 1/P(B) \implies P(A|B)=P(A\cap B)/P(B)$

- $P(\Omega|B) = 1$
- $P(\Omega\cap B) = P(B)$

**Commento**

Supponiamo che P(B) = 1. Allora $P(A|B)=P(A\cap B)/P(B) = P(A\cap B)/1 = P(A\cap B)$
Inoltre P(A) = $P(A\cap B)+P(A\cap B^c)$ dove $0\leq P(A\cap B^c)\leq P(B^c) = 0$
quindi P(A) = P($A\cap B$), e sostituendo nell'eguaglianza precedente si ha 
>$P(A|B)=P(A)$

Questa conclusione si può spiegare come segue. Il verificarsi di un evento di probabilità 1 è una informazione "banale" e quindi la probabilità condizionata conclude con quella che si ha senza il condizionamento.

**Commento (PROB. CONDIZIONATA IN UNO SPAZIO DI PROBABILITà UNIFORME DISCRETO)**

Sia $B\ni A$ t.c $P(B)\neq0; B\neq0$. Allora:
$P(A|B)=P(A\cap B)/P(B)=|((A\cap B)|/n)/(|B|/n) = |(A\cap B)|/|B|$ $\forall A\ni A$

**Esempio**

Un'urna ha 10 paline numerate da 1 a 10
si estrae una pallina a caso
1) calcolare la probabilità di estrarre in numero maggiore di 5 sapendo che è stato estratto un numero pari
2) Calcolare la stessa probabilità nel caso in cui vengano aggiunte due palline, una con il numero 1 e l'altra con il numero 10

Risposta:
Abbiamo $A={(6,7,8,9,10)}$ $B={(2,4,6,8,10)}$
quindi $A\cap B = (6,8,10)$
nel primo caso abbiamo uno spazio di prob. uniforme discreto e quindi $P(A|B)=|(A\cap B)|/|B| = 3/5$

Nel secondo caso abbiamo:
$P(A|B)=P(A\cap B)/P(B) = P(6,8,10)/P(2,4,6,8,10) = (1+1+2/12)/(1+1+1+1+2/12) = 4/6=2/3$

