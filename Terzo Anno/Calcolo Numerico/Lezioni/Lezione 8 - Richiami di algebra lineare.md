# Calcolo dei determinanti

Il metodo di Laplace è un metodo classico per il calcolo dei determinanti. Utilizziamolo per calcolare il determinante della matrice $$A=\begin{bmatrix}1 &3 &2 \\ 0 &1 &4  \\ 2 &5 &10 \end{bmatrix}$$
Laplace funziona nel seguente modo:
- si sceglie una riga o una colonna della matrice
- si sviluppa il determinante lungo quella riga o colonna, tenendo conto della regola della scacchiera per la determinazione dei segni $$A=\begin{bmatrix}+ &- &+ \\ - &+ &-  \\ + &- &+ \end{bmatrix}$$
Scegliendo la prima riga si ha $$\begin{align*}
\det(A)&=\begin{vmatrix}1 &3 &2 \\ 0 &1 &4 \\ 2 &5 &10\end{vmatrix}=+1
\begin{vmatrix}1 &4 \\ 5 &10 \end{vmatrix}-3\begin{vmatrix}0 &4 \\ 2 &10\end{vmatrix}+2\begin{vmatrix}0 &1 \\ 2 &5 \end{vmatrix} \\
&= +1(1\cdot10-5\cdot4)-3(0\cdot10-2\cdot4)+2(0\cdot5-2\cdot1)=24+6-20=10\end{align*}$$ 
Scegliendo la seconda colonna e qualsiasi altra riga o colonna, ovviamente, il risultato non cambia.

Oltre al metodo di Laplace, un teorema da tener presente per il calcolo dei determinanti è il teorema di Binet. Date due matrici $A, B\in \mathbb C^{n\times n}$, il teorema di Binet stabilisce che $$\det(AB)=\det(A)\det(B)$$ Ricordiamo infine che il determinante di una matrice $A$ è uguale a quello della sua trasposta $A^T$.

## Esempio 
Sia $\alpha$ un parametro reale e sia $$U= \begin{bmatrix}2 &\alpha \\ 1 &3\end{bmatrix}$$ Stabilire per quali valori di $\alpha$ la matrice $A=LU$ ha determinante nullo nei seguenti casi:
- $L\begin{bmatrix}1 &-3  \\ -4 &12\end{bmatrix}$

- $L=\begin{bmatrix}1 &0  \\ 5 &2\end{bmatrix}$

**Soluzione**
In base al teorema di Binet $$\det(A)=\det(L)\det(U)=\det(L)(6- \alpha)$$
- Nel primo caso si ha $\det(L)=1\cdot 12 - (-4\cdot(-3))=12 -12=0$, per cui $\det(A)=0$ e dunque la matrice $A$ ha sempre determinante nullo per qualunque valore di $\alpha$
- Nel secondo caso si ha $\det(L)=1\cdot 2 - (5\cdot0)=2-0=2$ per cui $\det(A)=2(6-\alpha)$ e dunque la matrice $A$ ha determinante nullo $\iff \alpha=6$
 
# Traccia, determinante, raggio spettrale e autovalori
Data una matrice $A \in \mathbb C^{n\times n}$ con autovalori $\lambda_{1},\lambda_{2},\dots,\lambda_{n}$ (ciascuno dei quali compare nella sequenza un numero di volte pari alla sua molteplicità algebrica come radice del polinomio caratteristico di A), si ha $$\begin{align*}
\text{traccia}(A)&=a_{11}+a_{22}+\dots+a_{nn}=\lambda_{1}+\lambda_{2}+\dots+\lambda_{n}, \\
\det(A)&= \lambda_{1}\lambda_{2}\dots \lambda_{n}\\
\rho(A)&= \text{raggio spettrale di A}=\max(|\lambda_{1}|, |\lambda_{2}|,\dots, |\lambda_{n}|)       
\end{align*}$$
## Esempio
Sia $$A=\begin{bmatrix}2 &4 &-1  & 0  \\ 0  & 1+i & 0 & 7  \\ 1 & -1 & 1 & -2i \\ 3 & -1 & 0 & -12\end{bmatrix}$$
# Matrici invertibili
Una matrice $A\in \mathbb C^{n\times n}$ si dice invertibile se esiste una matrice $B\in \mathbb C^{n\times n}$ tale che $AB=BA=I$. In tal caso la matrice $B$ è univocamente determinata, prende il nome di **matrice inversa di A** e viene denotata con $A^{-1}$. Ricordiamo che una matrice $A\in \mathbb C^{n\times n}$ è invertibile $\iff$ $\det(A)\ne0$ $\iff$ $0$ non è un autovalore di $A$. Ricordiamo inoltre che il prodotto $AB$ di due matrici $A, B\in \mathbb C^{n\times n}$ è invertibile se e solo se $A$ e $B$ sono invertibili; l'inversa in tal caso è $(AB)^{-1}=B^{-1}A^{-1}$ come si può verificare direttamente: $$ABB^{-1}A^{-1}=B^{-1}A^{-1}AB=I$$ 
## Esempio 
Verificare che la matrice $$A=\begin{bmatrix}1 & 2 & -1  \\ -2 & 1 & 1 \\ 1 & 0 & 4\end{bmatrix}$$
è invertibile e calcolare la sua inversa.

**Soluzione**
Per verificare che $A$ è invertibile, calcoliamo il suo determinante (con il metodo di Laplace) e verifichiamo che è diverso da $0$. Scegliendo l'ultima riga di $A$ (che ha uno zero e quindi semplifica i calcoli), si ha $$\det(A)=\begin{vmatrix}1 & 2 & -1 \\ -2 & 1 & 1 \\ 1 & 0 & 4\end{vmatrix}=+1\begin{vmatrix}2 & -1 \\ 1 & 1\end{vmatrix}-0\begin{vmatrix}1 & -1 \\ -2 & 1\end{vmatrix}+4\begin{vmatrix}1 & 2 \\ -2 & 1\end{vmatrix}=3+20=23\ne 0$$ dunque $A$ è invertibile. Ricordiamo che l'inversa $A^{-1}$ si calcola usando la seguente formula $$A^{-1}=\frac{1}{\det(A)}\begin{bmatrix}\begin{vmatrix}1 & 2 & -1 \\ 0 & 1 & 1 \\ 0 & 0 & 4\end{vmatrix} &\begin{vmatrix} 0 & 2 & -1 \\ 1 & 1 & 1 \\ 0 & 0 & 4\end{vmatrix} &\begin{vmatrix}0 & 2 & -1  \\ 0 & 1 & 1 \\ 1 & 0 & 4\end{vmatrix} \\ \begin{vmatrix}1 & 1 & -1 \\ -2 & 0 & 1 \\ 1 & 0 & 4\end{vmatrix} & \begin{vmatrix}1 & 0 & -1  \\ -2 & 1 & 1 \\ 1 & 0 & 4\end{vmatrix} & \begin{vmatrix}1  & 0 & -1  \\ -2 & 0 & 1 \\ 1 & 1 & 4\end{vmatrix} \\ \begin{vmatrix}1 & 2 & 1 \\ -2 & 1 & 0 \\ 1 & 0 & 0\end{vmatrix} & \begin{vmatrix}1 & 2 & 0 \\ -2 & 1 & 1  \\ 1 & 0 & 0\end{vmatrix} & \begin{vmatrix}1 & 2 & 0 \\ -2 & 1 & 0 \\ 1 & 0 & 1\end{vmatrix}\end{bmatrix}=\frac{1}{23}\begin{bmatrix}4 & -8 & 3 \\ 9 & 5 & 1 \\ -1 & 2 & 5\end{bmatrix}$$ 
*Oss.* Il metodo di calcolo dell'inversa appena visto coincide con il metodo dei cofattori.

# Matrici diagonalizzabili
Una matrice $A \in \mathbb C^{n\times n}$ si dice diagonalizzabile se esistono una matrice invertibile $X \in \mathbb C^{n\times n}$ e una matrice diagonale $D = \text{diag}(\lambda_{1},\lambda_2,\dots,\lambda_{n})\in \mathbb C^{n\times n}$ tali che $$A=XDX^{-1}$$
Questo significa che per ogni $i=1,\dots,n$, l'elemento diagonale $\lambda_{i}$ è un autovalore di $A$ con corrispondente autovettore $x_{i}=\text{i-esima colonna di X}$. Questo si vede moltiplicando a destra per $X$ entrambi i membri della formula sopra ottenendo $AX=XD$; da qui si nota che la colonna $\text{i-esima}$ di $AX$ è $Ax_{i}$ e la colonna $\text{i-esima}$ di $XD$ è $\lambda_{i}x_{i}$, per cui $Ax_{i}=\lambda_{i}x_{i}$. Ricordiamo che ogni matrice $A \in \mathbb C^{n\times n}$ che possiede $n$ autovalori *distinti* è diagonalizzabile

# Matrici hermitiane e matrici simmetriche
Una matrice $A \in \mathbb C^{n\times n}$ si dice hermitiana se $A^{\star}=A$ dove $A^{\star}$ è la trasposta coniugata di $A$. Nel caso in cui le componenti di $A$ sono reali (cioè $A\in \mathbb R^{n\times n}$), dire che $A$ è hermitiana equivale a dire che $A$ è simmetrica, cioé $A^{T}=A$. Gli elementi diagonali di una matrice hermitiana $A$ sono uguali ai loro coniugati e dunque sono reali. Anche gli autovalori di una matrice hermitiana $A$ sono reali. Infatti, se $\lambda$ è un autovalore di $A$ e indichiamo con $x\ne0$ un corrispondente autovettore, allora $$\begin{align*}
Ax=\lambda x&\implies (x^{\star}Ax)^{\star}=x^{\star}(\lambda x)=\lambda x^{\star}x=\lambda\sum\limits_{i=1}^{n}\overline{x_{i}}x_{i}=\lambda\sum\limits_{i=1}^{n}|x_{i}|^{2} \\
&\implies \lambda=\frac{x^{\star}Ax}{\sum\limits_{i=1}^{n}|x_{i}|^{2}}\in \mathbb R 
\end{align*}$$ perché $x^{\star}Ax$ è un numero reale essendo uguale al suo complesso coniugato: $$\overline{x^{\star}Ax}=(x^{\star}Ax)^{\star}=x^{\star}A^{\star}(x^{\star})^{\star}=x^{\star}Ax$$
