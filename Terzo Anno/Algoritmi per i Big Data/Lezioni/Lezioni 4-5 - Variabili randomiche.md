# Variabili randomiche

>[!important]- Definizione
>Una **variabile randomica** $X$ definita su uno spazio di esempio $\Omega$ è una funzione di probabilità a valore reale su $\Omega$, ovvero: $X:\Omega\rightarrow\mathcal R$. Una **variabile randomica discreta** è una variabile randomica che assume solo un numero finito o infinito numerabile di valori.

>[!warning]- Una variabile aleatoria **non** è randomica

## Indipendenza

>[!important]- Definizione
>Due variabili randomiche $X,Y$ sono **indipendenti** se e solo se $$Pr((X=x)\cap(Y=y))=Pr(X=x)\cdot Pr(Y=y).$$
>per tutti i valori $x,y$. Analogamente, variabili randomiche $X_1,X_2,...,X_k$ sono **mutualmente indipendenti** se e solo se per *qualunque* sottoinsieme $I\subseteq[1,k]$ e *qualunque* $x_i,i\in I$:$$Pr(\cup_{i\in I}X_i = x_i)=\prod_{i\in I} Pr(X_i = x_i).$$

## Stima

>[!important]- Definizione
>La **stima** di una variabile randomica discreta $X$, denotata come $E[X]$, è data da:$$E[X]=\sum_i i Pr(X=i),$$ dove la somma è su tutti i valori nel range di $X$. La stima è *finita* se $\sum_i |i|Pr(X=i)$ converge; altrimenti, la stima è illimitata.

Si può dire che la stima sia è una somma pesata su tutti i possibili valori della variabile randomica.

>Esempio

Il risultato stimato di un lancio di dati è:$$E[X]=\sum_{i=1}^6iPr(X=i)=\sum_{i=1}^6 \frac{i}{6}=3\frac{1}{2}.$$
La stima di una variabile $X$ rapprresentante la somma di due lanci è:$$E[X]=\frac{1}{36}\cdot2+\frac{2}{36}\cdot3+\frac{3}{36}\cdot4+...+\frac{1}{36}\cdot12=7.$$
Dato $X$ sul valore $2^i$ con probabilità $\frac{1}{2^i}$ per $i=1,2,...$ $$E[X]=\sum_{i=1}^{\infty} \frac{1}{2^i}2^i=\sum_{i=1}^{\infty}1=\infty.$$
### Linearità della stima

>[!important]- Teorema
>Per due variabili randomiche qualsiasi $X,Y$:$$E[X+Y]=E[X]+E[Y]$$

**Dimostrazione**:
![[Pasted image 20241030115648.png|center|500]]

> Esempi:
> - La stima della somma di due dadi è $7$, anche se non sono indipendenti
> - La stima della risultante della somma di due dadi è $10\frac{1}{2}$.
> - Assumiamo di lanciare $N$ monete, qual è il numero stimato di "testa"?
> 	- Utilizzando la linearità della stima otteniamo $N\cdot\frac{1}{2}.$
> 	- Con la somma diretta ottteniamo $\sum_{i=1}^N i\binom{N}{i}2^{-N}.$
> Quindi proviamo che $$\sum_{i=0}^N i\binom{N}{i}2^{-N}=\frac{N}{2}$$

## Variabile randomica di Bernoulli

Una variabile randomica **Bernoulliana**:$$Y =\begin{cases}
   x + y = 2 & \text{se l'esperimento ha successo }(p)\\
   x - y = 0 & \text{altrimenti }(1-p)
\end{cases}
$$ $$E[Y]=p\cdot1+(1-p)\cdot0=Pr(Y=1).$$

## Variabile randomica Binomiale

>[!important]- Definizione
>Una **variabile randomica Binomiale** $X$ con parametri $n,p$, denotati come $B(n,p)$ è definita dalla seguente distribuzione di probabilità su $j=0,1,..,n$:
>$$Pr(X=j)=\binom{n}{j}p^j(1-p)^{n-j}.$$

### Stima della Variabile Randomica Binomiale
	per completezza ma non applicare.

![[Pasted image 20241030122129.png|center|600]]

Utilizzando la linearità delle stime:$$E[X]=E[\sum_{i=1}^{n}X_i]=\sum_{i=1}^{n}E[X_i]=np.$$

# QuickSort Randomizzato
	Procedura: Q_S(S);
**Input**: Un insieme $S$;
**Output**: L'insieme $S$ ordinato.
$y\in_\cup S\implies\forall x\in S[Pr(y=x)=\frac{1}{|S|=n}]$ 
1. Scegliere un elemento randomico $y$ da $S$ denominato come *elemento pivot*;
2. Confrontare tutti gli elementi di $S$ a $y$. Sia: $$S_1=\{x\in S - \{y\}|x\le y\},S_2=\{x\in S - \{y\}|x\gt y\}$$
3. Restituire la lista:$$Q_S(S_1),y,Q_S(S_2).$$
Dove $y$ è fisso ed il resto avviene tramite ricorsioni.

Sia $T$ il numero di confronti in una run di QS:
>[!important]- $E[T] = O(n\log n).$

Dati $s_1,...,s_n$ gli elementi di $S$ ordinati. Per $i=1,...,n,\space j>i$, definire variabili $0-1$ $X_{i,j}$.
$X_{i,j}=1\iff s_i$ viene confrontato con $s_j$ nella run dell'algoritmo, altrimenti $X,{i,j}=0$.
Il numero di confronti nell'esecuzione dell'algoritmo è $$T=\sum_{i=1}^n\sum_{j>i} X_{i,j}.$$
Noi siamo interessati in $E[T]$.$$\begin{align} \\&
E[T]=E[\sum_{i=1}^n\sum_{j>i} X_{i,j}]= \\&
\sum_{i=1}^n\sum_{j>i} E[X_{i,j}] = \sum_{i=1}^n\sum_{j>i}\frac{2}{j-i+1}\le \\&
n\sum_{k=1}^n \frac{2}{k}\text{(serie armonica)}\le 2nH_n=n\log n+ O(n).
\end{align}$$

# Classificazione degli algoritmi

Un **algoritmo di Monte Carlo** è un algoritmo randomizzato che potrebbe produrre un risultato errato. Per i problemi decisionali:
- Un algoritmo di MonteCarlo `one-side error` sbaglia solo su un possibile output;
- Un algoritmo di Montecarlo `two-side error` altrimenti.
In entrambi i casi il tempo di esecuzione è una variabile randomica.

# La distribuzione geometrica

>[!important]- Definizione
>Una variabile randomica geometrica $X$ con parametro $p$ è dato dalla seguente distribuzione geometrica su $n=1,2,...$ $$Pr(X=n)=(1-p)^{n-1}p.$$

## Proprietà senza memoria

>[!info]- Lemma
>Per una variabile randomica geometrica con parametro $p$ e $n>0$, $$Pr(X=n+k|X>k)=Pr(X=n)$$

>[!info]- Lemma
>Data $X$ una variabile randomica discreta che opera solo su valori interi non negativi. Allora:$$E[X]=\sum_{i=1}^{\infty}Pr(X\ge i).$$

$$\begin{align}
E(X) = & \sum_{i=1}^\infty Pr(X\ge i)\\&
=\sum_{i=1}^\infty (1-p)^{i-1} \\&
=\frac{1}{1-(1-p)} \\&
=\frac{1}{p}.
\end{align}$$

### Esempio: Problema del collezionista di coupon

Supponiamo che ogni scatola di cereali contenga un coupon randomico da un insieme di $n$ coupon differenti. Quante scatole di cereali bisogna comprare per avere almeno uno di ogni tipo di coupon?

Sia $X$ il numero di scatole comprate prima che almeno uno di ogni tipo di coupon sia stato ottenuto, e sia $X_i$ il numero di scatole comprate mentre si hanno esattamente $i-1$ coupon differenti. $$X=\sum_{i=1}^n X_i$$
$X_i$ è una variabile randomica geometrica con parametro $p_i=1-\frac{i-1}{n}.$
$$\begin{align}\\&
E[X_i]=\frac{1}{p_i}=\frac{n}{n-i+1}\\&\\&
E[X]=E[\sum_{i=1}^n X_i]\\&
=\sum_{i=1}^n E[X_i] \\&
=\sum_{i=1}^n \frac{n}{n-i+1}\\&
=n\sum_{i=1}^n\frac{1}{i}=n \ln n +\Theta(n).
\end{align}$$

