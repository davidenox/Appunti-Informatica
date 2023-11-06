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
# Matrici definite positive
Una matrice $A \in \mathbb C^{n\times n}$ si dice definita positiva se $Re(\underline{x}^{\star}A\underline{x}) > 0$ per ogni vettore $x \in \mathbb C^{n} - \{0\}$. Notiamo che $$\begin{align*}
Re(\underline{x}^{\star}A\underline{x})&=\frac{\underline{x}^{\star}A\underline{x}+\overline{\underline{x}^{\star}A\underline{x}}}{2}=\frac{\underline{x}^{\star}A\underline{x}+(\underline{x}^{\star}A\underline{x})^{\star}}{2}\\
&= \frac{\underline{x}^{\star}A\underline{x}+\underline{x}^{\star}A^{\star}\underline{x}}{2}=\underline{x}^{\star}\left(\frac{A+A^{\star}}{2}\right)\underline{x}\\
&= \underline{x}^{\star}Re(A)\underline{x}
\end{align*}$$ dove $$Re(A)=(A+A^{\star}),\:\:\:Im(A)=\frac{A-A^{\star}}{2i},\:\:\:A=Re(A)+Im(A)$$
Sia la parte reale $Re(A)$ che la parte immaginaria $Im(A)$ di una qualsiasi matrice $A \in \mathbb C^{n\times n}$ sono matrici hermitiane
Di conseguenza $\underline{x}^{\star}Re(A)\underline{x}\in \mathbb R\:\:\:\forall \underline{x}\in \mathbb C^{n}$. Dunque $$\begin{align*}
A \text{ è definita positiva }&\iff Re(\underline{x}^{\star}A\underline{x})>0\:\:\: \forall \underline{x}\in \mathbb C^{n}-\{0\}\\
&\iff \underline{x}^{\star}Re(A)\underline{x}>0\:\:\: \forall \underline{x}\in \mathbb C^{n}-\{0\}\\
&\iff Re(\underline{x}^{\star}Re(A)\underline{x})>0 \:\:\: \forall \underline{x}\in \mathbb C^{n}-\{0\}\\
&\iff Re(A) \text{ è definita positiva}  
\end{align*}$$ Ogni matrice definita positiva $A$ è sicuramente invertibile perché i suoi autovalori hanno parte reale positiva (e quindi sono diversi da 0). Prendiamo $\underline{x}\ne\underline{0}$ autovettore corrispondente a $A$: $$\begin{align*}
A\underline{x}=\lambda\underline{x}&\implies \underline{x}^{\star}A\underline{x}=\underline{x}^{\star}(\lambda\underline{x})=\lambda\underline{x}^{\star}\underline{x}=\lambda\sum\limits_{i=1}^{n}\overline{x_{i}}x_{i}=\lambda\sum\limits_{i=1}^{n}|x_{i}|^{2}\\
&\implies \frac{\underline{x}^{\star}A\underline{x}}{\sum\limits_{i=1}^{n}|x_{i}|^{2}}\implies Re(\lambda)=\frac{Re(\underline{x}^{\star}A\underline{x})}{\sum\limits_{i=1}^{n}|x_{i}|^{2}} >0
\end{align*}$$

## Teorema
Sia $A \in \mathbb C^{n\times n}$ una matrice hermitiana e siano $A_{1},A_{2},\dots,A_{n}$ le sue sottomatrici principali di testa: $$A_{1}=[a_{11}],\:\:\:A_{2}=\begin{bmatrix}a_{11} & a_{12} \\ a_{21} & a_{22}\end{bmatrix},\:\:\:A_{3}=\begin{bmatrix}a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33}\end{bmatrix},\:\:\:\dots\:\:\:,\:\:\:A_{n}=A$$
Le seguenti condizioni sono equivalenti: 
- $A$ è definita positiva 
- gli autovalori di $A$ sono reali e positivi
- $\det(A_{k})>0$ per ogni $k=1,\dots,n$ 

## Esempio 1
Dire se la matrice $$A=\begin{bmatrix}2 & -1 & 1  \\ -1 & 2 & 0 \\ 1 & 0 & 1 & \end{bmatrix}$$
è definita positiva.

**Soluzione**
Osserviamo che $A$ è hermitiana (reale e simmetrica). Pertanto grazie al [[#Teorema|teorema]], $A$ è definita positiva se e solo se $\det(A_{k})>0$ per ogni $k=1,2,3$. Si ha $$\begin{align*}
\det(A_{1})&=2>0\\
\det(A_{2}) &= \begin{vmatrix}2 & -1\\ -1  & 2\end{vmatrix}=3>0\\
\det(A_{3}) &= \begin{vmatrix}2 & -1 & 1 \\-1 & 2 & 0\\1 & 0 & 1\end{vmatrix}=\begin{vmatrix}-1 & 1 \\2 & 0\end{vmatrix}+\begin{vmatrix}2 & -1 \\-1 & 2\end{vmatrix}=-2+3=1>0
\end{align*}$$ Dunque $A$ è definita positiva.

# Polinomi di matrici
Se $p(\lambda)=a_{0}+a_{1}\lambda+\dots+a_{m}\lambda^{m}$ è un polinomio e $A \in \mathbb C^{n\times n}$ è una matrice, definiamo la matrice $$p(A)=a_{0}I+a_{1}A+a_{2}A^{2}+\dots+a_{m}A^{m}$$

**Esempio** 
Se $p(\lambda)=1-2\lambda^{2}+\lambda^{3}$, allora $$p(A)=I-2A^{2}+A^{3}$$ 
**Teorema**
Se $p(\lambda)$ è un polinomio e $A\in \mathbb C^{n\times n}$ è una matrice con autovalori $\lambda_{1},\lambda_{2},\dots,\lambda_{n}$, allora gli autovalori della matrie $p(A)$ sono $p(\lambda_{1}),\dots,p(\lambda_{n})$.

**Dim.**
Dimostriamo il teorema soltanto in tre casi.

*Caso 1.* Il polinomio $p(\lambda)=a_{0}$ è costante. In tal caso, $p(A)=a_{0}I$ e i suoi autovalori sono $\underbrace{a_{0},\dots,a_{0}}_{\text{n volte}}$. Dunque gli autovalori di $p(A)$ sono $p(a_{0}),\dots,p(a_{0})$ e la tesi del teorema vale.
*Caso 2.* Il polinomio $p(\lambda)=a_{0}+a_{1}\lambda$ ha grado 1. In tal caso il polinomio caratteristico di $p(A)$ e quello di $A$ sono legati dalla seguente relazione: per ogni $\lambda\in\mathbb C$, $$\begin{align*}
C_{p(A)}(\lambda)&=\det(\lambda I-p(A))=\det(\lambda I-(a_{0}I+a_{1}A))=\det((\lambda-a_{0})I-a_{1}A)=\\
&= \det\left(a_{1}\left(\frac{\lambda-a_{0}}{a_{1}}I-A\right)\right)=a_{1}^{n}\det\left(\frac{\lambda-a_{0}}{a_{1}}I-A\right)=\\
&= a_{1}^{n}C_{A}\left(\frac{\lambda-a_{0}}{a_{1}}\right)
\end{align*}$$
Dunque gli autovalori di $p(A)$ sono $$\begin{align*}
\{\lambda\in\mathbb C:C_{p(A)}=0\}&=\left\{\lambda\in\mathbb C:C_{A}\left(\frac{\lambda-a_{0}}{a_{1}}\right)=0\right\} =\left\{\lambda\in \mathbb C:\frac{\lambda-a_{0}}{a_{1}}=\lambda_{1},\dots,\lambda_{n}\right\} \\
&= \left\{\lambda\in \mathbb C:\lambda=a_{0}+a_{1}\lambda_{1},\dots,a_{0}+a_{1}\lambda_{n}\right\}=\{a_{0}+a_{1}\lambda_{1},\dots,a_{0}+a_{1}\lambda_{n}\}\\
&= \{p(\lambda_{1}),p(\lambda_{2}),\dots,p(\lambda_n)\}
\end{align*} $$ 
*Caso 3.* La matrice $A$ è diagonalizzabile. In tal caso esistono una matrice invertibile $X$ e una matrice diagonale $D=\text{diag}(\lambda_{1},\dots,\lambda_{n})$ (avente sulla diagonale gli autovalori di A) tali che $$\begin{align*}
A&=XDX^{-1}\\
A^{2}&=XDX^{-1}XDX^{-1}=XD^{2}X^{-1}\\
A^{3}&=XDX^{-1}XDX^{-1}XDX^{-1}=XD^{3}X^{-1},\\
&\vdots
\end{align*}$$
Pertanto fissato un polinomio $p(\lambda)=a_{0}+a_{1}\lambda+a_{2}\lambda^{2}+\dots+a_{m}\lambda^{m}$, si ha $$p(A)=a_{0}I+a_{1}A+a_{2}A^{2}+\dots+a_{m}A^{m}=X(a_{0}I+a_{1}D+a_{m}D^{m})X^{-1}=Xp(D)X^{-1},$$ dove $$p(D)=a_{0}I+a_{1}D+a_{2}D^{2}+\dots+a_{m}D^{m}=\begin{bmatrix}p(\lambda_{1}) &   &   &  \\  & p(\lambda_{2}) &   &  \\  &   & \ddots &  \\   &   &   & p(\lambda_{n})\end{bmatrix}$$
In conclusione la forumal $p(A)=Xp(D)X^{-1}$ ci sta dicendo che $p(A)$ è diagonalizzabile con autovalori $p(\lambda_{1}),p(\lambda_{2}),\dots,p(\lambda_{n})$ (e con corrispondenti autovettori dati dalle colonne di $X$).
