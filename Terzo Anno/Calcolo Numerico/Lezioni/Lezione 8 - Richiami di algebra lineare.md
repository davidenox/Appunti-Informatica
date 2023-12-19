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
- Gli autovalori di $A$ sono reali e positivi
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
Se $p(\lambda)$ è un polinomio e $A\in \mathbb C^{n\times n}$ è una matrice con autovalori $\lambda_{1},\lambda_{2},\dots,\lambda_{n}$, allora gli autovalori della matrice $p(A)$ sono $p(\lambda_{1}),\dots,p(\lambda_{n})$.

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
Pertanto fissato un polinomio $p(\lambda)=a_{0}+a_{1}\lambda+a_{2}\lambda^{2}+\dots+a_{m}\lambda^{m}$, si ha $$p(A)=a_{0}I+a_{1}A+a_{2}A^{2}+\dots+a_{m}A^{m}=X(a_{0}I+a_{1}D+...+a_{m}D^{m})X^{-1}=Xp(D)X^{-1},$$ dove $$p(D)=a_{0}I+a_{1}D+a_{2}D^{2}+\dots+a_{m}D^{m}=\begin{bmatrix}p(\lambda_{1}) &   &   &  \\  & p(\lambda_{2}) &   &  \\  &   & \ddots &  \\   &   &   & p(\lambda_{n})\end{bmatrix}$$
In conclusione la formula $p(A)=Xp(D)X^{-1}$ ci sta dicendo che $p(A)$ è diagonalizzabile con autovalori $p(\lambda_{1}),p(\lambda_{2}),\dots,p(\lambda_{n})$ (e con corrispondenti autovettori dati dalle colonne di $X$).
# Matrici irriducibili
Un grafo è un diagramma formato da un certo numero di nodi e di archi. Un arco è semplicemente una freccia che parte da un nodo e arriva in un altro. Se il grafico possiede $n$ nodi, questi vengono tipicamente indicati con i numeri $1,\dots,n$ mentre l'arco che va dal nodo $i$ al nodo $j$ viene indicato con una freccia $i \to j$. Un *cammino* all'interno di un grafo è un percorso che parte da un nodo $i$ e, seguendo gli archi del grafo, si arriva a un altro nodo $j$. Se il nodo di arrivo $j$ coincide con il nodo di partenza $i$ allora si parla di *ciclo*.
Un grafo si dice **fortemente connesso** se per ogni coppia di nodi $i$ e $j$ esiste un cammino all'interno del grafo che va da $i$ a $j$. Equivalentemente, un grafo è fortemente connesso se esiste un ciclo nel grafo che tocca tutti i nodi. In figura sotto sono mostrati due grafi, uno fortemente connesso e l'altro no.

![[Pasted image 20231110104305.png|center|700]]

Data una matrice $A\in\mathbb C^{n\times n}$, il grafo associato ad $A$ è così definito:
- i nodi sono $1,\dots,n$ 
- gli archi sono le frecce $i\to j$ tali che $a_{ij}\neq0$ 
In pratica nel grafo di $A$ ho un arco da $i$ a $j$ se e solo se l'elemento di $A$ in posizione $(i,j)$ è diverso da 0. Una matrice $A\in\mathbb C^{n\times n}$ si dice **irriducibile** se il suo grafo è fortemente connesso.

## Esempio 
Stabilire se le matrici $$A=\begin{bmatrix}0 & i & 0 \\ 1 & 1 & 4 \\ 0 & i & 0\end{bmatrix}\:\:\:B=\begin{bmatrix}0 & -1 & 0 \\ i & 2 & -3   \\ 0 & 0 & 0 \end{bmatrix}$$
sono irriducibili oppure no.

**Soluzione**
Il grafo della matrice $A$ è così definito:
- i nodi sono $1,2,3$ 
- gli archi sono $1\to2,2\to1,2\to2,2\to3,3\to2$ 
Il grafo di $A$ è quello mostrato in [[CN/img/img2.png|figura]] a sinistra ed è fortemente connesso, per cui $A$ è irriducibile. 
Il grafo della matrice B è così definito:
- i nodi sono $1,2,3$
- gli archi sono $1\to2,2\to1,2\to2,2\to3$ 
Il grafo di $B$ è quello mostrato in [[CN/img/img2.png|figura]] a destra e non è fortemente connesso, per cui $B$ non è irriducibile. 

# Localizzazione degli autovalori 
Denotiamo con $\textit{}$ $\mathscr{C}(z_{0},r)=\{z\in\mathbb C\: : \:|z-z_{0}|\leq r\}$ il cerchio nel piano complesso $\mathbb C$ di centro $z_{0}$ e raggio $r$. Data una matrice $A \in \mathbb C^{n\times n}$, i cerchi di Gershgorin di $A$ sono i cerchi $K_{1},\dots,K_{n}$ definiti nel modo seguente: 
per ogni $i=1,\dots,n,$ $$K_{i}=\mathscr{C}(a_{ii},|a_{i1}|+\dots+|a_{i,i-1}|+|a_{i,i+1}|+\dots+|a_{in}|)=\mathscr{C}\left(a_{ii},\sum\limits_{j\neq i}|a_{ij}|\right)$$
Poiché il raggio del cerchio $K_{i}$ è la somma dei moduli degli elementi sulla riga $i$-esima di $A$ (escluso l'elemento diagonale $a_{ii}$), i cerchi di Gershgorin per colonna di $A$ che sono i cerchi $H_{1},\dots,H_{n}$ definiti nel modo seguente: 
per ogni $j=1,\dots,n,$ $$H_{j}=\mathscr{C}(a_{jj},|a_{1j}|+\dots+|a_{j-1,j}|+|a_{j+1,j}|+\dots+|a_{nj}|)=\mathscr{C}\left(a_{jj},\sum\limits_{j\neq i}|a_{ij}|\right)$$
Ad ogni modo, *quando si parla di cerci di Gershgorin senza altre specificazioni, s'intendono i cerchi di Gershgorin per riga*. Quando si vuole parlare dei cerci di Gershgorin per colonna, questo va specificato ogni volta.

# Esempio 1 
Determinare i cerchi di Gershgorin della matrice A.
$$A=\begin{bmatrix}0 & -1 & 0 & 0\\ 1 & 0 & 1 & i \\ 1+i & 0 & 0 & -1 \\ -2 & 7 & 10 & 3i\end{bmatrix}$$
**Soluzione**
Non essendo specificato diversamente, si sta parlando dei cerchi di Gershgorin per riga di $A$. Tali cerchi sono $K_{1}=\mathscr{C}(0,1),K_{2}=\mathscr{C}(0,3),K_{3}=\mathscr{C}(0,1+\sqrt2),K_{4}=\mathscr{C}(3i,19)$ 

## Primo teorema di Gershgorin
Gli autovalori di una matrice $A\in\mathbb C^{n\times n}$ stanno tutti nell'unione dei cerchi di Gershgorin di $A$.

**Dim.**
Sia $\lambda$ un autovalore di $A$. Allora, detto $\underline{u}\neq \underline{0}$ un corrispondente autovettore, si ha $$A\underline{u}=\lambda\underline{u}\iff\sum\limits_{j=1}^{n}a_{ij}u_{j}=\lambda u_{j}\:\:\:\:\:\text{per ogni }i=1,\dots,n$$Selezionando un indice $i$ corrispondente ad una componente $u_{i}$ di modulo massimo di $\underline{u}$, la precedente equazione $i-$esima ci dice che $$\begin{align*}
\sum\limits_{j=1}^{n}a_{ij}u_{j}=\lambda u_{i}&\implies (\lambda-a_{ii})u_{i}\sum\limits_{j\ne i}a_{ij}u_{j}\\
&\implies |\lambda-a_{ii}||u_{i}|=|\sum\limits_{j\ne i}a_{ij}u_{j}|\le\sum\limits_{j\ne i}|a_{ij}||u_{j}|=|u_{i}|\sum\limits_{j\ne i}|a_{ij}|\\
&\implies |\lambda-a_{ii}|\le\sum\limits_{j\ne i}|a_{ij}|
\end{align*}$$ Quindi $\lambda$ sta dentro $K_{i}$ e dunque dentro l'unione dei cerchi di Gershgorin di $A$. $\square$ 

## Secondo teorema di Gershgorin 
Supponiamo che l'unione di $k$ cerchi di Gershgorin di $A\in\mathbb C^{n\times n}$ sia disgiunta dall'unione degli altri $n-k$ cerchi. Allora $k$ autovalori di $A$ stanno nella prima unione e $n-k$ nella seconda.

## Terzo teorema di Gershgorin
Supponiamo che $A\in\mathbb C^{n\times n}$ sia irriducibile. Allora i punti che stanno sul bordo dei cerchi di Gershgorin di A a cui appartengono ma non sul bordo di tutti i cerchi **non sono** autovalori di $A$

Questo teorema si usa per escludere alcuni punti dai possibili autovalori di $A$. Si tratta quindi di un teorema "esclusivo". Di questo teorema esiste una versione più debole ma più semplice. 

### Terzo teorema di Gershgorin debole
Supponiamo che $A\in\mathbb C^{n\times n}$ sia irriducibile e sia $\mathscr{B}$ il bordo dell'unione dei cerchi di Gershgorin di $A$. Allora i punti di $\mathscr{B}$ che non stanno sul bordo di tutti i cerchi non sono autovalori di $A$.

**Dim.**
Ogni punto di $\mathscr{B}$ sta per forza sul bordo di quei cerchi a cui appartiene (non può stare dentro a un cerchio altrimenti non sarebbe un punto di $\mathscr{B}$). Pertanto, ogni punto di $\mathscr{B}$ che non sta sul bordo di tutti i cerchi soddisfa l'ipotesi del [[#Terzo teorema di Gershgorin|terzo teorema di Gershgorin]] e quindi va escluso dall'insieme dei possibili autovalori di $A$. $\square$

## Esempio 2
Supponiamo di sapere che una matrice $A\in\mathbb C^{5\times 5}$ è irriducibile e che i suoi cerchi di Gershgorin siano i seguenti $$\begin{align*}
&K_{1}=\mathscr{C}(1,1)\\
&K_{2}=\mathscr{C}(-i,1)\\
&K_{3}=\mathscr{C}(4i,1)\\
&K_{4}=\mathscr{C}(1+i,1)\\
&K_{5}=\mathscr{C}(-1,1)
\end{align*}$$Avendo a disposizione solo queste informazioni, dire se le seguenti affermazioni sono vere o false: 
1.  $0$ non è autovalore $A$ 
2. $A$ è invertibile
3. $1$ potrebbe essere un autovalore di $A$
4. $-1+4i$ potrebbe essere un autovalore di $A$
5. $K_{3}$ privato del suo bordo contiene esattamente un autovalore di $A$
6. Per il raggio spettrale $\rho(A)$ vale la stima $3<\rho(A)<5$ 

**Soluzione**
![[Pasted image 20231110104344.png|center|300]]

1. VERO, infatti $A$ è irriducibile e $0$ sta sul bordo dell'unione dei cerchi di Gershgorin ma non sul bordo di tutti i cerchi, per cui non può essere autovalore di A in base al [[#Terzo teorema di Gershgorin#Terzo teorema di Gershgorin debole|terzo teorema di Gershgorin debole]] 
2. VERO, infatti $0$ non è un autovalore di $A$ e quindi $A$ è invertibile
3. VERO, infatti non si può escludere che $1$ sia un autovalore di $A$ usando il [[#Terzo teorema di Gershgorin|terzo teorema di Gershgorin]], perché $1$ non soddisfa le ipotesi di tale teorema: $1$ appartiene a $K_{1}$ ed è interno a $K_{1}$, dunque non sta sul bordo di quei cerchi di Gershgorin a cui appartiene  
4. FALSA, $A$ è irriducibile e $-1+4i$ sta sul bordo dell'unione dei cerchi di Gershgorin ma non sul bordo di tutti i cerchi, per cui non può essere autovalore di $A$ in base al [[#Terzo teorema di Gershgorin debole|terzo teorema di Gershgorin debole]].
5. VERA, infatti $K_3$ contiene esattamente un autovalore di A per il [[#Secondo teorema di Gershgorin|secondo teorema di Gershgorin]]. Inoltre, tale autovalore non può stare sul bordo di $K_3$ perché, per lo stesso motivo visto nel punto precedente, ogni punto del bordo di $K_3$ non può essere autovalore di A. Dunque $K_3$ privato del suo bordo contiene esattamente un autovalore di A.
6. VERA, infatti l’autovalore $\lambda$ di modulo massimo di $A$ è quello che sta in $K_3$ privato del suo bordo. Questo perché $|\lambda| = \text{ distanza}(\lambda, 0) > 3$ (tutti i punti di $K_3$ privato del bordo hanno modulo $> 3$), mentre gli altri autovalori hanno modulo $< 3$ (essendo contenuti nel cerchio di centro $0$ e raggio $3$). Inoltre, $|\lambda| < 5$ perché tutti i punti interni a $K_3$ hanno questa proprietà. Infatti, tutti i punti interni a $K_3$ cono contenuti nel cerchio di centro $0$ e raggio $5$ e dunque hanno distanza da $0$ (cioè modulo) minore di $5$.
# Matrici a diagonale dominante e a diag. dom. in senso stretto
Sia $A\in\mathbb C^{n\times n}$ una matrice: 
- Si dice che $A$ è a diagonale dominante (per righe) se: 
	- $a_{ii}\ge\sum\limits_{j\ne i}|a_{ij}|$ per ogni $i=1,\dots,n$
	- esiste almeno un indice $k\in\{1,\dots,n\}$ per il quale vale la disuguaglianza stretta $a_{kk}>\sum\limits_{j\ne k}|a_{kj}|$.
- Si dice che $A$ è diagonale dominante in senso stretto (per righe) se $a_{ii}>\sum\limits_{j\ne i}|a_{ij}|$ per ogni $i=1,\dots,n$
- Si dice che $A$ è a diagonale dominante per colonne se:
	- $a_{jj}\ge\sum\limits_{i\ne j}|a_{ij}|$ per ogni $j=1,\dots,n$
	- esiste almeno un indice $\ell\in\{1,\dots,n\}$ per il quale vale la disuguaglianza stretta $|a_{\ell\ell}>\sum\limits_{i\ne\ell}|a_{i\ell}|$ 
- Si dice che A è a diagonale dominante in senso stretto per colonne se $|a_{jj}|>\sum\limits_{i\ne j}|a_{ij}|$ per ogni $i=1,\dots,n$. 
Analogamente a quanto avviene per i cerchi di Gershgorin, quando si parla di dominanza diagonale senza altre specificazioni, si intende per righe. Quando si vuole parlare di dominanza diagonale per colonne, questo va specificato ogni volta.

## Esempio
Discutere le proprietà di dominanza diagonale per righe e per colonne della matrice $$A=\begin{bmatrix}3 & 1 & -2 \\ 0 & -3 & 1 \\ 1-2i & -1 & 5\end{bmatrix}$$
**Soluzione**
Poiché $$\begin{align*}
|3|&=|1|+|-2|&\iff\:\:\:\: &3=3\\
|-3|&>|0|+|1|&\iff \:\:\:\:&3>1\\
|5|&>|1-2i|+|-1| &\iff \:\:\:\:&5>\sqrt{5}+1
\end{align*}$$ si conclude che $A$ è a diagonale dominante (per righe) ma non a diagonale dominante in senso stretto (per righe). 
Poiché $$\begin{align*}
|3|&>|0|+|1-2i|&\iff\:\:\:\: &3>\sqrt{5}\\
|-3|&>|1|+|-1|&\iff \:\:\:\:&3>2\\
|5|&>|-2|+|1| &\iff \:\:\:\:&5>3
\end{align*}$$ si conclude che $A$ è a diagonale dominante in senso stretto per colonne.

## Teorema
Supponiamo che la matrice $A\in\mathbb C^{n\times n}$ soddisfi *almeno una* delle seguenti condizioni:
- $A$ è a diagonale dominante e irriducibile;
- $A$ è a diagonale dominante in senso stretto;
- $A$ è a diagonale dominante per colonne e irriducibile;
- $A$ è a diagonale dominante in senso stretto per colonne;
Allora $A$ è invertibile.
**Dim.**
La dimostrazione si basa sui teoremi di Gershgorin. Dimostriamo il teorema sotto l'ipotesi che $A$ sia diagonale dominante e irriducibile. Mostriamo che $0$ non è un autovalore di $A$ usando il [[#Terzo teorema di Gershgorin|terzo teorema di Gershgorin]]. Poiché $A$ è a diagonale dominante, se $0$ appartiene a un cerchio di Gershgorin $K_{i}$ allora deve stare per forza sul bordo di $K_{i}$. Infatti non può stare all'interno, perché per ipotesi di dominanza diagonale si ha $$\text{raggio di }K_{i} =\sum\limits_{j\ne i}|a_{ij}|\le|a_{ii}|=|a_{ii}|=\text{distanza}(a_{ii},0)=\text{distanza}(\text{centro di }K_{i},0)$$Dunque $0$ sta per forza sul bordo di quei cerchi di Gershgorin a cui esso appartiene. Inoltre, sempre per l'ipotesi di dominanza diagonale, esiste un indice $k$ tale che $$|a_{kk}|>\sum\limits_{j\ne k}|a_{kj}|$$ Questo significa che $0$ non sta sul bordo di $K_{k}$ e dunque $0$ non sta sul bordo di tutti i cerchi di Gershgorin di $A$. Poiché $A$ è irriducibile per ipotesi, il terzo teorema di Gershgorin ci dice che $0$ non può essere un autovalore di $A$ e quindi $A$ è invertibile. $\square$

**Oss.**
Nella dimostrazione del [[#Matrici a diagonale dominante e a diag. dom. in senso stretto#Teorema|teorema]] abbiamo dovuto usare la versione forte del terzo teorema di Gershgorin perché quella [[#Terzo teorema di Gershgorin debole|debole]] non basta. Infatti la matrice $$A=\begin{bmatrix}1 & 1 & 0 & 0 & 0 \\ 0 & i & 1 & 0 & 0 \\  0 & 0 & -1 & 1 & 0 \\ 0 & 0 & 0 & -i & 1 \\ 1/4 & 0 & 0 & 0 & 1\end{bmatrix}$$ è a diagonale dominante e irriducibile e ha i cerchi di Gershgorin sia per righe che per colonne mostrati sotto in figura, per cui non riusciremmo a dimostrare che é invertibile (cioé che $0$ non è un autovalore) usando la sola versione debole del terzo teorema di Gershgorin. 
![[Pasted image 20231219162845.png|center|350]]

# Norme vettoriali 
## Il concetto di norma vettoriale
Consideriamo il sistema lineare $$\begin{bmatrix}8 & 1 & 1 \\ 1 & 5 & -1 \\ 1 & -1 & 5\end{bmatrix}\begin{bmatrix}x_{1} \\ x_{2} \\ x_{3}\end{bmatrix}=\begin{bmatrix}26 \\ 7 \\ 7 \end{bmatrix}$$ la cui soluzione è $\underline{x}=[3,1,1]^{T}$. Si supponga di aver ottenuto le seguenti approssimazioni della soluzione: $$\begin{align*}
\underline{y}=[2.99972,1.00023,1.00030]^{T}\\
\underline{z}=[3.00027,0.99971,0.99955]^{T}
\end{align*}$$ Come possiamo stabilire quale delle due è più vicina alla soluzione $\underline{x}$? Occorre introdurre un concetto di distanza sullo spazio dei vettori e misurare la distanza di $\underline{y}$ e $\underline{z}$ da $\underline{x}$: la soluzione approssimata che dista di meno è quella più vicina. Un ottimo concetto di distanza in uno spazio di vettori è il concetto di norma vettoriale.

**Def.**
Una funzione $||\cdot||:\mathbb{C}^{n}\to\mathbb R$ si dice norma vettoriale se soddisfa le seguenti proprietà:
- $||\underline{x}||\ge0$ per ogni $\\underline{x}\in\mathbb{C}^{n}$ e $||\underline{x}||=0$ se e solo se $\underline{x}=\underline{0}\text{ [ positività ]}$ 
- $||\alpha\underline{x}||=|\alpha|\:||\underline{x}||$ per ogni $\alpha\in\mathbb{C}$ e ogni $\underline{x}\in\mathbb C^{n}\text{ [ omogeneità ]}$
- $||\underline{x}+\underline{y}||\le||\underline{x}||+||\underline{y}||$ per ogni $\underline{x},\underline{y}\in\mathbb C^{n}\text{ [ disuguaglianza triangolare ]}$  
Data una norma vettoriale $||\cdot||:\mathbb{C}^{n}\to\mathbb R$, definiamo la distanza fra due vettori $\underline{x},\underline{y}\in\mathbb C^{n}$ come $||\underline{x}-\underline{y}||$.

## Le norme 1, 2, $\infty$ 
Le norme più importanti in $\mathbb C^{\infty}$ sono tre: la norma 1, la norma 2 (o euclidea) e la norma $\infty$. Esse sono definite nel modo seguente: $$\begin{align*}
||\underline{x}||_{1}&=|x_{1}|+|x_{2}|+\dots+|x_{n}|\\
||\underline{x}||_{2}&=\sqrt{|x_{1}|^{2}+|x_{2}|^{2}+\dots+|x_{n}|^{2}}\\
||\underline{x}||_{\infty}&=\max(|x_{1}|,|x_{2}|,\dots,|x_{n}|)
\end{align*}$$ Le relative distanze sono definite nel modo seguente: $$\begin{align*}
||\underline{x}||_{1}&=|x_{1}-y_{1}|+|x_{2}-y_{2}|+\dots+|x_{n}-y_{n}|\\
||\underline{x}||_{2}&=\sqrt{|x_{1}-y_{1}|^{2}+|x_{2}-y_{2}|^{2}+\dots+|x_{n}-y_{n}|^{2}}\\
||\underline{x}||_{\infty}&=\max(|x_{1}-y_{1}|,|x_{2}-y_{1}|,\dots,|x_{n}-y_{1}|)
\end{align*}$$ Tornando all'[[#Il concetto di norma vettoriale|esempio introduttivo]], se calcoliamo la distanza dei vettori $\underline{y}$ e $\underline{z}$ dal vettore $\underline{x}=[3,1,1]^{T}$ usando la $||\cdot||_{\infty}$, otteniamo $$\begin{align*}
\underline{x}-\underline{y}=[0.00028,-0.00023,-0.00030]^{T} &\implies ||\underline{x}-\underline{y}||_{\infty}=0.00030\\
\underline{x}-\underline{z}=[-0.00027,0.00029,0.00045]^{T} &\implies ||\underline{x}-\underline{z}||_{\infty}=0.00045\\
\end{align*}$$ Quindi rispetto alla $||\cdot||_{\infty}$ il vettore $\underline{y}$ è più vicino a $\underline{x}$ rispetto a $\underline{z}$.

## Equivalenza delle norme vettoriali
### Teorema
Tutte le norme vettoriali in $\mathbb C^{n}$ sono equivalenti, nel senso che se prendiamo due norme vettoriali $||\cdot||',||\cdot||'':\mathbb C^{n}\to\mathbb R$ allora si ha $$\alpha||\underline{x}||''\le ||\underline{x}||'\le \beta||\underline{x}||''\:\:\: \text{per ogni }\underline{x}\in\mathbb C^{n}\:\:\:\: (\star)$$ dove $\alpha, \beta>0$ sono due costanti indipendenti da $\underline{x}$.

Verifichiamo ad esempio che $||\cdot||_{1}$ e $||\cdot||_{\infty}$ sono equivalenti. Per ogni $\underline{x} \in \mathbb C^{n}$ si ha $$\begin{align*}
&\max(|x_{1}|,\dots,|x_{n}|)\le|x_{1}|+\dots+|x_{n}|\le n\max(|x_{1}|,\dots,|x_{n}|)\\\\

&\implies||\underline{x}||_{\infty}\le ||\underline{x}||_{1}\le n||\underline{x}||_{\infty}\implies \frac{1}{n}||\underline{x}||_{1}\le ||\underline{x}||_{\infty}\le ||\underline{x}||_{1} 
\end{align*}$$
Dunque $||\cdot||_{1}$ e $||\cdot||_{\infty}$ sono equivalenti essendo $(\star)$ soddisfatta per $\alpha=1$ e $\beta=n$ (considerando $||\cdot||'=||\cdot||_{1}$ e $,||\cdot||''=||\cdot||_{\infty}$) oppure con $\alpha= \frac{1}{n}$ e $\beta=1$ (considerando $||\cdot||'=||\cdot||_{\infty}$ e $,||\cdot||''=||\cdot||_{1}$). In ogni caso, quello che conta è che $\alpha$ e $\beta$ sono costanti positive indipendenti da $\underline{x}$. 
Analogamente, possiamo verificare che  $||\cdot||_{2}$ e $||\cdot||_{\infty}$ sono equivalenti: Per ogni $\underline{x} \in \mathbb C^{n}$ si ha $$\begin{align*}
\max(|x_{1}|,\dots,&|x_{n}|)\le \sqrt{|x_{1}|^{2}+..+|x_{n}|^{2}} \le \sqrt{n\max(|x_{1}|,..,|x_{n}|)^{2}}=\sqrt{n}\max(|x_{1}|,..,|x_{n}|) \\\\
&\implies||\underline{x}||_{\infty}\le ||\underline{x}||_{2}\le \sqrt{n}||\underline{x}||_{\infty}\implies \frac{1}{n}||\underline{x}||_{2}\le ||\underline{x}||_{\infty}\le ||\underline{x}||_{2} 
\end{align*}$$
## Successioni di vettori
Una successione di vettori $\underline{x}^{(0)},\underline{x}^{(1)},\underline{x}^{(2)},\dots$ in $\mathbb C^{n}$ si dice convergente al vettore $\underline{x}\in \mathbb C^{n}$ rispetto alla norma vettoriale $||\cdot||$ se $||\underline{x}^{(k)}-\underline{x}||\to0$. Poiché tutte le norme vettoriali sono equivalenti, se una successione vettoriale converge a $\underline{x}$ rispetto una norma $||\cdot||$ allora converge a $\underline{x}$ rispetto a tutte le norme. Infatti, supponiamo che la successione $\{\underline{x}^{(k)}\}_{k=0,1,2,\dots}$ converga a $\underline{x}$ rispetto alla norma $||\cdot||$ e sia $||\cdot||'$ un'altra norma. Poiché $||\cdot||$ e $||\cdot||'$ sono equivalenti, esistono due costanti $\alpha,\beta>0$ tali che $$\alpha||\underline{y}||''\le ||\underline{y}||'\le \beta||\underline{y}||''\:\:\: \text{per ogni }\underline{y}\in\mathbb C^{n}$$ dunque $$\alpha||\underline{x}^{(k)}-\underline{x}||\le||\underline{x}^{(k)}-\underline{x}||'\le \beta||\underline{x}^{(k)}-\underline{x}||\:\:\: \text{per ogni }k=0,1,2,\dots$$ Siccome $||\underline{x}^{(k)}-\underline{x}||\to0$ (perché $\underline{x}^{(k)}\to\underline{x}$ in norma $||\cdot||$) concludiamo che $||\underline{x}^{(k)}-\underline{x}||'\to0$ (cioè $\underline{x}^{(k)}\to\underline{x}$ in norma $||\cdot||'$).

Una successione di vettori $\underline{x}^{(0)},\underline{x}^{(1)},\underline{x}^{(2)},\dots$ in $\mathbb C^{n}$ si dice convergente (componente per componente) al vettore $\underline{x}\in \mathbb C^{n}$ se $\underline{x}^{(k)}\to\underline{x}$ componente per componente, cioè se $$\begin{align*}
\\
\begin{cases}
x_{1}^{(k)}\to x_{1} \\
x_{2}^{(k)}\to x_{2} \\
\vdots \\
x_{n}^{(k)}\to x_{n}
\end{cases}&\iff\begin{cases}
|x_{1}^{(k)}- x_{1}|\to0\\
|x_{2}^{(k)}- x_{2}|\to0\\\\
\vdots\\
|x_{n}^{(k)}- x_{n}|\to0\\
\end{cases}\\\\

&\iff \max(|x_{1}^{(k)}- x_{1}|,|x_{2}^{(k)}- x_{2}|,\dots,|x_{n}^{(k)}- x_{n}|)\to 0\\\\
&\iff ||\underline x^{(k)}-\underline x||_{\infty}\to 0
\end{align*}$$ Vediamo quindi che la convergenza componente per componente altro non è che la convergenza in $||\cdot||_{\infty}$. Pertanto, ricordando l'equivalenza di tutte le norme, dire che $\underline{x}^{(k)}\to\underline{x}$ componente per componente è lo stesso che dire che $\underline{x}^{(k)}\to\underline{x}$ in una qualsiasi norma. 

# Norme matriciali
## Il concetto di norma matriciale
## Le norme 1, 2, $\infty$
## Equivalenza delle norme matriciali
## Successioni di matrici