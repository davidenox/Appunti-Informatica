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
****
L5 MitzCh2S17