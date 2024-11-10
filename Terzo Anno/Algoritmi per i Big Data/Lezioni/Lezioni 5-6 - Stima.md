# L'aspettativa non è tutto

Quale gioco è più conveniente?
1. Con probabilità $\frac{1}{2}$ vinci $1, con probabilità $\frac{1}{2}$ paga $1. 
2. Con probabilità $\frac{1}{2}$ vinci $100.000, con probabilità $\frac{1}{2}$ paga $100.000.
3. Con probabilità $\frac{1}{1.000.000}$ vinci $1.000.000, con probabilità $\frac{1}{2}$ paga $5, altrimenti $0.

## Deviazione limite dalle aspettative

>[!important]- Teorema - Disuguaglianza di Markov
>Per ogni variabile randomica non negativa: $$Pr(X>a)\le\frac{E[X]}{a}.$$

Questo è buonissimo, perché risulterebbe $Pr(X\ge n\log^2n)\le\frac{1}{\log n}$.

### Varianza

>[!important]- Definizione
>La **varianza** di una variabile randomica $X$ è $$Var[X]=E[(X-E[X])^2]=E[X^2]-(E[X])^2.$$

>[!important]- Definizione
>La **deviazione standard** di una variabile randomica $X$ è $$\sigma(X)=\sqrt{Var[X]}.$$


# Disuguaglianza di Chebyshev

>[!important]- Teorema 1
>Per ogni variabile randomica $$Pr(|X-E[X]|\le a)\le\frac{Var[X]}{a^2}$$

>[!important]- Teorema 2
>Per ogni variabile randomica $$Pr(|X-E[X]|\ge a\sigma[X])\le\frac{1}{a^2}.$$

>[!important]- Teorema 3
>Per ogni variabile randomica $$Pr(|X-E[X]|\ge\epsilon E[X])\le\frac{Var[X]}{\epsilon^2(E[X])^2}.$$

>[!important]- Teorema 4
>Se $X$ e $Y$ sono variabili randomiche indipendenti $$E[XY]=E[X]\cdot E[Y].$$

>[!important]- Teorema 5
>Se $X$ e $Y$ sono variabili randomiche indipendenti $$Var[X+Y] = Var[X] + Var[Y]$$

### Tornando al lancio della moneta

Assumiamo di lanciare $N$ monete. Sia $X$ il numero di teste.
$X_i=1$ se l'$i$-esimo lancio è stata testa altrimenti $X_i=0$.
![[Pasted image 20241105152745.png|center|500]]

## Prova di Bernoulli

Sia $X$ una variabile randomica $0-1$ tale che $$\begin{align}\\&
Pr(X=1)=p,Pr(X=0)=1-p.\\&
E[X]=1\cdot p+0\cdot(1-p)=p.\\&
Var[X]=p(1-p)^2+(1-p)(0-p)^2=p(1-p)[1-p+p]=p(1-p).
\end{align}$$
# Una variabile randomica binomiale
Si consideri una sequenza di $n$ prove indipendenti di Bernoulli $X_1,...,X_n$. Sia $$X=\sum_{i = 1}^n X_i.$$
$X$ ha una **distribuzione binomiale** $X\sim B(n,p)$.$$\begin{align}\\&
Pr(X=k)=\binom{n}{k}p^k(1-p)^{n-k}.\\&
E[X]=np.\\&
Var[X]=np(1-p).
\end{align}$$
# Algoritmo per computare il Mediano

Il **mediano** di un insieme $X$ di $n$ elementi distinti è l'elemento $\lceil\frac{n}{2}\rceil$ nell'insieme.
Se $n=2k+1$, l'elemento mediano è il $k+1$-esimo nell'insieme ordinato. Viene facilmente calcolato attraverso un ordinamento in tempo $O(n\log n)$. Qui esiste un algoritmo deterministico complicato $O(n)$.

## Algoritmo Mediano Randomizzato

**Input**: Un insieme di $n=2k+1$ elementi da un universo totalmente ordinato.
**Output**: Il $k+1$-esimo elemento più grande nell'insieme.

1. Prendere un (multi)insieme $R$ di $s=n^{3/4}$ elementi in $S$, scelto indipendentemente ed uniformemente random con rimpiazzi. Ordinare l'insieme $R$.
2. Sia $d$ il ($\frac{1}{2}n^{3/4}-\sqrt n$)-esimo elemento più piccolo nell'insieme $R$ ordinato.
3. Sia $u$ il ($\frac{1}{2}n^{3/4}+\sqrt n$)-esimo elemento più piccolo nell'insieme $R$ ordinato.
4. Confrontando ogni elemento di $S$ a $d$ e $u$ genera l'insieme $C=\{x\in S:d\le x\le u\}$, ed i numeri $l_d=|\{x\in S:x<d\}|$ e $l_u=|\{x\in S:x>u\}|$.
5. Se $l_d>n/2$ o $l_u>n/2$ allora `FAIL`.
6. Se $|C|\le 4n^{3/4}$ allora ordinare l'insieme $C$, altrimenti `FAIL`.
7. Restituire il $(\lfloor\frac{n}{2}\rfloor-l_d+1)$-esimo elemento ordinato in $C$.

### Intuizioni

- Possiamo ordinare insiemi di grandezza $<n/\log n$ in tempo lineare.
- Il campione di $R$ elementi sono distanziati "più o meno" equamente tra gli elementi di $C$.
- Con alta probabilità più di $\frac{1}{2}n^{3/4} -\sqrt n$ campioni sono più piccoli del mediano.
- Con alta probabilità più di $\frac{1}{2}n^{3/4} -\sqrt n$ campioni sono più grandi del mediano.
- Con alta probabilità il mediano è l'insieme $C$, e $|C|<n/\log n$

Siano $Y_1,Y_2$ rispettivamente i numeri di campioni sotto e sopra il mediano.
L'algoritmo fallisce nel calcolare il mediano in tempo $O(n)$ se e solo se almeno uno dei 3 seguenti eventi accadono:
1. $E_1: Y_1<\frac{1}{2}n^{3/4}-\sqrt n.$
2. $E_2: Y_2<\frac{1}{2}n^{3/4}-\sqrt n.$
3. $E_3:|C|> n/\log n.$ 
Qual è la probabilità che le tre variabili randomiche $Y_1,Y_2,|C|$ sono tutte entro gli intervalli richiesti?

Lo spazio di esempio in esecuzione di questo algoritmo è un insieme di tutte le possibili scelte di $n^{3/4}$ elementi da $n$, con ripetizioni (lo spazio di esempio ha $n^{n^{3/4}}$).
Ogni punto nello spazio di esempio definisce i valori per $Y_1,Y_2,|C|$. Calcolare le probabilità direttamente è troppo complicato, useremo invece limiti su deviazioni dalla stima.

Qual è la probabilità che $Y_1<\frac{1}{2}n^{3/4}-\sqrt n$?
Vedendo $Y_1$ come la somma di $n^{3/4}$ variabili indipendenti randomiche $0-1$, ognuna con stima $1/2$ e varianza $1/4$, abbiamo che $$E[Y_1]=\frac{1}{2}n^{3/4}.$$$$Var[Y_1]=\frac{1}{4}n^{3/4}.$$
Applicando la disuguaglianza di Chebyshev otteniamo:$$\begin{align}\\&
Pr(E_1:Y_1<\frac{1}{2}n^{3/4}-\sqrt n)\le Pr(|Y_1-E[Y_1]|>\sqrt n)\le\\&
\frac{Var[Y_1]}{n}=\frac{n^{3/4}/4}{n}=\frac{1}{4}n^{-1/4}.
\end{align}$$
Analogamente $$\begin{align}\\&
Pr(E_1:Y_1<\frac{1}{2}n^{3/4}-\sqrt n)\le\frac{1}{4}n^{-1/4}.\\&
Pr(E_1\cup E_2)\le\frac{2}{4}n^{-1/4}.
\end{align}$$
>Richiamo

>[!important]- Lemma
>$$Pr(E_3)\le\frac{1}{2}n^{-1/4}.$$

Definire questi due eventi:
1. $\varepsilon_{3,1}$: Almeno $2n^{3/4}$ elementi di $C$ sono più grandi del mediano;
2. $\varepsilon_{3,2}$: Almeno $2n^{3/4}$ elementi di $C$ sono più piccoli del mediano;
Se $|C|>4n^{3/4}$, allora almeno uno dei due eventi avviene.

Almeno $2n^{3/4}$ elementi di C sono più grandi del mediano;
Almeno $2n^{3/4}$ elementi di C dopo mediano$\implies$ 
$u$ è almeno il $\frac{1}{2}n+2n^{3/4}$ più grande in $S\implies$
$R$ ha avuto almeno $\frac{1}{2}n^{3/4}-\sqrt n$ campionamenti tra i $\frac{1}{2}n-2n^{3/4}$ elementi più larghi in $S$.

Sia $X$ il numero di campionamenti tra i $\frac{1}{2}n-2n^{3/4}$ elementi più grandi in $S$. Sia $X=\sum_{i=1}^{n^{3/4}}X_i$ dove $$X_i=\begin{cases}
1 \rightarrow\text{l'esempio i-esimo nei} \frac{1}{2}n-2n^{3/4}\text{elementi maggiori in }S \\
0\rightarrow\text{altrimenti.}
\end{cases}$$
****
L6Mitz3S23
