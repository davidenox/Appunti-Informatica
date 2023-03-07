# Capitolo 3 - Modeli discreti
## Modelli Discreti
In questo capitolo tratteremo essenzialmente **VARIABILI ALEATORIE DISCRETE**(spesso definite su spazi di prob. $(\Omega,\mathcal A,\mathcal P)$ con $\Omega$ discreto)

_Def_
In generale una variabile aleatoria è una funzione del tipo $$X:\Omega\rightarrow\mathcal X$$
Dove $\mathcal X$ è un qualunque insieme, con certe proprietà
In questo corso tratteremo il caso in cui $\mathcal X=\mathbb R$(o un suo sottinsieme)
Il concetto di v.a è utile perchè spesso gli eventi di interesse negli esercizi sono esprimibili tramite v.a
**Esempio**
Si lanciano due dadi e consideriamo l'evento "la somma dei due numeri ottenuti è uguale a 5"
Allora è utile fare riferimento alla seguente scelta dell'insieme $\Omega$:
>$\Omega=\lbrace 1,...,6\rbrace x\lbrace 1,...,6\rbrace=\lbrace w=(w_1,w_2):w_1,w_2\in\lbrace 1,...,6\rbrace\rbrace$

Essendo $\Omega$ un insieme finito, non ci sono problemi nello scegliere $\mathcal A=\mathcal P(\Omega)$ 
Inoltre è opportuno considerare la seguente funzione $X:\Omega\rightarrow\mathbb R$
definita come segue:
$$X(w)=X(w_1,w_2)=w_1+w_2 \:\forall w=(w_1,w_2)\in\Omega$$
Allora l'evento di interesse è:
>$w=(w_1,w_2)\in\Omega:X(w)=5$

_Def_
Sia ($\Omega,\mathcal A,\mathcal P$) uno spazio di prob. Inoltre sia $X:\Omega\rightarrow\mathbb R$ una funzione.
Allora la funzione X è una v.a (_reale_) se vale la seguente condizione
$$\forall t\in\mathbb R\:\:\lbrace w\in\Omega:X(w)\leq t\rbrace\in \mathcal A$$
In altri termini si richiede che le controimmagini delle semirette del tipo $(-\infty,t]$, che sono sottoinsiemi di $\Omega$, sono elementi della $\sigma-algebra\:\mathcal A$ 
Questo consente di dire che, per queste controimmagini, è possibile definire la prob.
Quindi possiamo dire che, per ogni $t\in\mathbb R$, $P(\lbrace w\in\Omega:X(w)\leq t\rbrace)$ è un numero ben definito
Quindi si richiede che, se $B=(-\infty,t]$ per qualsiasi scelta di $t\in\mathbb R$,
$\lbrace w\in\Omega:X(w)\in B\rbrace\in\mathcal A\:\:(\star)$

A partire da questa richiesta, la condizione $(\star)$ vale anche per le altre scelte di B "naturali" da considerare:
$$\begin{cases}B=[t,\infty)\\B=(t,\infty) & \forall t\in\mathbb R\\B=(-\infty,t)\end{cases}$$
B unione finita o numeraabile di insiemi dei tipi indicati sopra
(Es: $B=(0,1)\cup \lbrace 2\rbrace\cup [4,5)\cup [6,\infty)$)

## Notazioni che useremo
$\lbrace w\in\Omega:X(w)\in B\rbrace\text{useremo la notazione}\implies \lbrace X\in B\rbrace$ 
$P(\lbrace\omega\in\Omega:X(\omega)\in B\rbrace)$ useremo la notazione $P(\lbrace X\in B\rbrace)$, o anche $P(X\in B)$

## Distribuzione o Legge di una v.a reale
è la corrispondente tra "gli insiemi della retta B per cui $\lbrace X\in B\rbrace\in A$" e i valori $P(\lbrace X\in B\rbrace)$ relativi

## Funzione di distribuzione di una v.a reale
è la funzione $F_x:\mathbb R\to [0,1]$ così definita: $F_x(t)=P(X\leq t)$

### Commento
La conoscenza di $F_x$ consete di individuare la distribuzione di una v.a. X
Quindi, se uno conosce i valori di $P(X\in B)$ per $B=(-\infty,t]$ (al variare di tutti i valori $t\in\mathbb R$), è possibile conosceere tutti i valori di $P(X\in B)$ al variare di $B\subset\mathbb R$

## Proprietà della funzione di distribuzione $F_x$
1. $F_x$ non è decrescente, cioè $F_x(t_1)\leq F_x(t_2)$ $\forall t_1,t_2\in\mathbb R|t_1\leq t_2$. Questo si verifica facilemente osservando che $$t_1\leq t_2\implies (-\infty,t_1]\subset(-\infty,t_2]\implies P(X\leq t_1)\leq P(X\leq t_2)\implies F_x(t_1)\leq F_x(t_2)$$
2. $lim_{t\to-\infty} F_x(t)=0$ e $lim_{t\to\infty} F_x(t)=1$
3. $F_x$ è continua a destra, cioè $\forall t_0\in\mathbb R F_x(t)=F_x(t_0)$

![[appunti cps/immagini/Pasted image 20221027135649.png|center|600]]

## Variabili aleatorie discrete

Sia $X:\Omega\to\mathbb R$ una v.a reale definita su uno spazio di probabilità ($\Omega\mathcal A,P$).
Indichiamo con $S_x$ l'insieme dei valori assunti da X, cioè l'immagine di X vista come funzione
La definizione di questo insieme in termini matematici è la seguente:
$$S_x=\lbrace x\in\mathbb R:\exists \omega\in\Omega |X(\omega)=x\rbrace$$
_Def_
Una v.a reale X è una v.a discreta se l'insieme $S_x$ è discreto (cioè $S_x$ è finito o numerabile)

**Oss**
Se $\Omega$ è discreto (cioè finito o numerabile), allora X è una v.a discreta.
In generale non vali il viceversa: ad esempio si pensi al caso in cui, per qualche $c\in\mathbb R$, si ha
$$X(\omega)=c\:\:\:\forall\omega\in\Omega$$
(quindi $S_x=\lbrace c\rbrace$) e X non è un insieme discreto

----
Quando X è una v.a discreta, allora possiamo pensare di avere
$$S_x=\lbrace x_i\rbrace_{i\in I}$$
dove I è un insieme discreto
In corrispondenza, per ogni $B\in\mathbb R$, si ha
$$P(X\in B)=P(X\in B\cap S_X)=P(X\in B\cap (\bigcup_{i\in I}\lbrace x \rbrace))=\sum_{i\in I}P(X\in B\cap\lbrace x_i\rbrace)=\sum_{x_i\in S_x\cap B}P(X=x_i)$$
Quindi la distribuzione di una v.a discreta X, cioè la conoscenza dei valori di $P(X\in B)$ al variare di $B\subset\mathbb R$, è individuata dalla conoscenza di $S_x=\lbrace x_i\rbrace_{i\in I}$ e delle probabilità $\lbrace P(X=x_i)\rbrace_{i\in I}$

Si osservi anche che, per $B=\mathbb R$, si ha
$$\underbrace{P(X\in\mathbb R)}_{=1}=\sum_{x_i\cap\underbrace{S_x\cap\mathbb R}_{= S_x}}P(X=x_i)$$
da cui segue $$\sum_{x_i\cap S_x}P(X=x_i)=1$$
Più in generale si può considerare la funzione $P_x:\mathbb R\to[0,1]$ così definita:
$$P_x(x)=P(X=x)\:\:\:\forall x\in\mathbb R$$
tale funzione è detta **densità discreta** della v.a X

**Proposizione**
$x\not\in S_x\implies P_x(x)=0$

**Dim**
Si ha che:
$$P_x(x)=P(\underbrace{\lbrace\omega\in\Omega:X(\omega)=x\rbrace}_{=\emptyset\:perchè\:x\not\in S_X})=P(\emptyset)=0.$$

Come vedremo successivamente la funzione di distribuzione ha maggiore interesse quando la v.a X è continua
In ogni caso vedremo come è fatta $F_x$ nel caso di v.a discrete. Iniziamo con il caso in cui $S_x$ è un insieme finito; ad esempio $S_x=\lbrace x_1,x_2,...x_n\rbrace$ con $x_1\lt....\lt x_n$
In questo grafico si ha n=3

![[appunti cps/immagini/Pasted image 20221027150631.png|center|700]]

**Oss** dal grafico (relativo al caso n=3) si vede che $\sum_{i=1}^n P_x(x_i)=1\implies P_x(x_1)+P_x(x_2)+P_x(x_3)$
Nel caso in cui $S_x$ è infinito numerabile la casisitca è più varai e ci possono essere casi molto complicati. Qui faccio riferimento a due casi (sopratutto il primo ci interessa in vista di quel che vedremo con le distribuzioni di Poisson e geometriche)

1. $S_x=\lbrace x_0,x_0+1,x_0+2,...\rbrace$

![[appunti cps/immagini/Pasted image 20221027151413.png|center|500]]

2. $S_x=\lbrace 1,1/2,1/3,...,1/n,..\rbrace_{n\in\mathbb N}$

![[appunti cps/immagini/Pasted image 20221027151612.png|center|500]]


### Introduzione alle distribuzioni notevoli

Si palra di "distribuzioni notevoli" quando queste hanno una certa espressione, un pò come accade per i prodotto notevoli nel calcolo attuale
Per le v.a discrete tipicamente ci si riferisce alla espressione della densità discreta. Talvolta si fa riferimento ad alcune situazioni pratiche
Per la v.a continua tipicamente ci si riferisce alla espressione delle funzioni di distribuzioni o, equivalente (più o meno) alla densità continua

### Distribuzione Bernoulliana
Si ha questo termine quando $S_x=\lbrace 0,1\rbrace$
talvolta è utile pensare ad un evento $B\in\mathcal A$ tale che:
1. X=1 $\iff$ l'evento B si verifica
2. X=0 $\iff$ l'evento B non si verifica

Talvolra si usa anche la notazione $X=1_B$
In questo caso si ha 
$$\begin{cases} P_x(1)=P(X=1)=P(B)\\ P_x(0)=P(X=0)=P(B^c)\end{cases}$$
Quindi 
- se $0\lt P(B)\lt 1$ (e quindi $0\lt P(B^c)\lt 1$)
![[appunti cps/immagini/Pasted image 20221027152335.png|center|600]]

- se $P(B)=1$ (e quindi $P(B^c)=0$)
![[appunti cps/immagini/Pasted image 20221027152438.png|center|600]]

- se $P(B)=0$ (e quindi $P(B^c)=1$)
![[appunti cps/immagini/Pasted image 20221027152531.png|center|600]]

### Schemi successo-fallimento su un numero finito di prove
Si tratta di una premessa comune per due casi che vedremo nella prossima lezione:
- [[Appunti CPS/Lezione 5#Il caso 1: Distribuzione Binomiale|Distribuzione Binomiale]] (caso di n prove indipendenti, tutte con la stessa probabilità di successo P)
- [[Appunti CPS/Lezione 5#Il caso 2: Distribuzione Ipergeometrica|Distribuzione Ipergeometrica]] (caso di n estrazioni casuali di un oggetto alla volta, senza reinserimento (un caso particolare senza avere prove indipendenti))

In entrambi i casi si vuole studiare la v.a X che conta il numero di successi
Nel caso 2 gli oggetti sono di due tipi, e si ha successo con l'estrazione di oggetti di un certo tipo. Ad esempio: oggetti colorati con un certo colore, oggetti numerati con un certo numero,ecc...

In entrambi i casi conviene fare riferimento all'insieme $\Omega$ così definito:
$$\Omega=\underbrace{\lbrace 0,1\rbrace....\lbrace 0,1\rbrace}_{n\:volte}=\lbrace\omega=(\omega_1,...,\omega_n):\omega_1,..,\omega_n\in\lbrace 0,1\rbrace\rbrace$$
Ogni $\omega\in\Omega$ descrive i possibili risultati (successi e fallimenti) nelle n prove.
Scegliamo $\mathcal A=\mathcal P(\Omega)$
Avremo due diverse misure di probabilità per i casi 1 e 2

**Oss**
- Per n=1 abbiamo ovviamente una distribuzione Bernoulliana
- In generale si dovrà avere $S_x=\lbrace 0,1,...,n\rbrace$ e questo è quel che accadrà

Noi siamo interessati a contare quanti successi ci sono nella stringa di risultati. allora è opportuno considerare la v.a così definita
$$X(\omega)=\omega_1+...+\omega_n$$ per ogni $\omega=(\omega_1,..,\omega_n)\in\Omega$

**Oss**
Ad esempio la v.a Y che conta il numero di fallimenti è Y così definita
$$Y(\omega)=n-X(\omega)$$
Del resto $$Y(\omega)=(1+..+1)-(\omega_1+...+\omega_n)=1-\omega_1+...+1-\omega_n$$
Nella prossima lezione vedremo come definire le misure di probabilità P su $(\Omega,\mathcal A)=(\Omega,\mathcal P(\Omega))$ a partire dagli insieme costituiti dai singoli punti, cioè a partire dalle seguenti quantità:
$$P(\lbrace\omega\rbrace)=P(\lbrace \omega_1,...,\omega_n\rbrace)$$
Due diverse situazioni per i casi 1 e 2

Dopo aver fatto questo troveremo la densità discreta di X:
per $k\in\lbrace 0,1,...,n\rbrace$
$P_x(k)=P(X=k)=P(\lbrace\omega\in\Omega:X(\omega)=k\rbrace)=\sum_{\omega:X(\omega)=k}P(\lbrace\omega\rbrace)$

**esempio**
Per fissare le idee consideriamo il caso n=3. Abbiamo 
$$\Omega=\lbrace 0,1\rbrace\times\lbrace 0,1\rbrace\times\lbrace 0,1\rbrace=\lbrace\omega=(\omega_1,\omega_2,\omega_3):\omega_1,\omega_2,\omega_3\in\lbrace 0,1\rbrace\rbrace$$
Allora "le sequenze $\omega$ per cui $X(\omega=k)$" sono:
- per k=0 (0,0,0)
- per k=1 (0,0,1),(0,1,0),(1,0,0)
- per k=2 (0,1,1),(1,0,1),(1,1,0)
- per k=3 (1,1,1)

Quindi 
- $P_x(0)=P(\lbrace (0,0,0)\rbrace)$
- $P_x(1)=P(\lbrace (0,0,1)\rbrace)+P(\lbrace (0,1,0)\rbrace)+P(\lbrace (1,0,0)\rbrace)$
- $P_x(2)=P(\lbrace (0,1,1)\rbrace)+P(\lbrace (1,0,1)\rbrace)+P(\lbrace (1,1,0)\rbrace)$
- $P_x(3)=P(\lbrace (1,1,1)\rbrace)$
