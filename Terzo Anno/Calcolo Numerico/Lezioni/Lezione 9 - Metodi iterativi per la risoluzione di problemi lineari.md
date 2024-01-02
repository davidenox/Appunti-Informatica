È dato un sistema lineare $$A\underline x=\underline b$$ con $\underline b\in\mathbb C^{n}$ e $A\in\mathbb C^{n\times n}$ invertibile. Il sistema ha un'unica soluzione $\underline x=A^{-1}\underline b$. Ci proponiamo di risolvere il sistema lineare con un metodo iterativo, ovvero un metodo che a partire da un vettore iniziale $\underline x^{(0)}$ scelto dall'utente, costruisce una successione di vettori $\underline x^{(0)},\underline x^{(1)},\underline x^{(2)},\dots$ Vogliamo che tale successione sia "facile da costruire" e converga a $\underline x$ [[Capitolo 3 - Richiami di algebra lineare#Successioni di vettori|(componente per componente)]] qualunque sia il vettore iniziale $\underline x^{(0)}$ scelto.

# Forma generale di un metodo iterativo stazionario e proprietà di convergenza
Per risolvere il sistema lineare consideriamo solo *metodi iterativi stazionari* cioè metodi della forma $$\begin{align*}
&\underline x^{(0)}\in \mathbb C^{n} \text{ dato}\\
&\underline x^{(k+1)}=P\underline x^{(k)}+\underline q, \:\:k=0,1,2,\dots
\end{align*}\:\:\:\:(\star)$$ dove $P\in \mathbb C^{n\times n}$ è una matrice fissata detta *matrice d'iterazione* e $\underline{q}\in\mathbb{C}^{n}$ è un vettore fissato.
**Oss.**
Se una successione $\{\underline{x}^{(k)}\}_{k=0,1,2,\dots}$, generata dal metodo $(\star)$,  converge a un vettore $\underline{x}^{(\infty)}$ allora $\underline{x}^{(\infty)}$ soddisfa l'equazione $$\underline{x}^{(\infty)}=\lim_{k\to\infty}\underline{x}^{(k+1)}=\lim_{k\to \infty}(P\underline{x}^{(k)}+\underline{q})=P \underline{x}^{(\infty)}+\underline{q}\implies \underline{x}^{(\infty)}=P \underline{x}^{(\infty)}+\underline{q}$$Di conseguenza, se la soluzione $\underline{x}$ del sistema lineare non soddisfa l'equazione $\underline{x}=P\underline{x}+\underline{q}$ allora non c'è speranza che una successione $\{\underline{x}^{(k)}\}_{k=0,1,2,\dots}$ generata dal metodo $(\star)$ converga a $\underline{x}$. Si noti che "soddisfare l'equazione $\underline{x}=P\underline{x}+\underline{q}$" vuol dire "essere punto fisso della funzione $\underline{g}(\underline{y})=P\underline{y}+\underline{q}$".

>[!important]- **Def.** Consistenza di un metodo iterativo
>Il metodo iterativo $(\star)$ si dice consistente col sistema lineare, se la soluzione $\underline{x}$ del sistema soddisfa l'equazione $\underline{x}=P\underline{x}+\underline{q}$. 

>[!important]- **Def.** Convergenza di un metodo iterativo
>Il metodo iterativo $(\star)$ per risolvere il sistema lineare, si dice convergente se per ogni scelta del vettore iniziale $\underline{x}^{(0)}$, la successione $\{\underline{x}^{(k)}\}_{k=0,1,2,\dots}$ generata dal metodo converge (componente per componente) alla soluzione $\underline{x}$ del sistema lineare.

## Teorema (condizione necessaria e sufficiente di convergenza)
Supponiamo che il metodo $(\star)$ sia consistente col sistema lineare. Allora esso *è convergente* se e solo se $\rho(P)<1$.

**Dim.**
Dimostriamo soltanto che se $\rho(P)<1$ allora il metodo è convergente.
Dobbiamo dimostrare che la successione $(\star)$ converge alla soluzione $\underline{x}$ del sistema lineare indipendentemente dalla scelta del vettore iniziale $\underline{x}^{(0)}$. Poiché il metodo è consistente per ipotesi, vale l'equazione $$\underline{x}=P \underline{x}+\underline{q}$$ Inoltre, ovviamente, vale anche l'equazione del metodo, cioè $$\underline{x}^{(k+1)}=P \underline{x}^{(k)}+\underline{q} \:\:\text{ per ogni }k=0,1,2,\dots$$ Sottraendo membro a membro le due equazioni sopra, si ottiene l'equazione dell'errore $$\underline{e}^{(k+1)}=P\underline{e}^{(k)}\:\:\text{ per ogni }k=0,1,2,\dots$$ dove $\underline{e}^{(k)}=\underline{x}^{(k)}-\underline{x}$ è l'errore al passo $k$. Sviluppando per ricorrenza l'equazione dell'errore, si ottiene $$\underline{e}^{(k+1)}=P\underline{e}^{(k)}=P^{2}\underline{e}^{(k-1)}=P^{3}\underline{e}^{(k-2)}=\dots=P^{k+1}\underline{e}^{(0)}\:\:\text{ per ogni }k=0,1,2,\dots$$ da cui $$\underline{e}^{(k)}=P^{k}\underline{e}^{(0)}\:\:\text{ per ogni }k=0,1,2,\dots$$ Siccome stiamo assumendo che $\rho(P)<1$, il [[Capitolo 3 - Richiami di algebra lineare#Successioni di matrici#Teorema|teorema]] ci dice che $P^{k}\to O$. Dall'ultima equazione si deduce quindi che $\underline{e}^{(k)}\to \underline{0}$ cioè $\underline{x}^{(k)}\to\underline{x}$.

### Corollario 1
**Condizione sufficiente di convergenza**
Supponiamo che il metodo $(\star)$ sia consistente col sistema lineare. Se esiste una norma matriciale indotta $||\cdot||$ tale che $||P||<1$, allora il metodo è convergente.

**Dim.**
Poiché $\rho(P)\le||P||$ per il [[Capitolo 3 - Richiami di algebra lineare#Norme matriciali indotte#Teorema|teorema]], la condizione $||P||<1$ implica che $\rho(P)<1$ e dunque il metodo è convergente per il teorema precedente. $\square$

### Corollario 2
**Condizioni necessarie di convergenza**
Suppinamo che il metodo $(\star)$ sia consistente col sistema lineare.
- Se $|\text{traccia}(P)|\ge n$ allora il metodo *non è convergente*.
- Se $|\det(P)|\ge1$ allora il metodo *non è convergente*.
Quindi le condizioni $|\text{traccia}(P)|<n$ e $|\det(P)<1|$ sono **necessarie** per la convergenza del metodo $(\star)$.

**Dim.**
- Se $|\text{traccia}(P)|\ge n$ allora esiste almeno un autovalore di $P$ di modulo $\ge1$. Infatti, se tutti gli autovalori $\lambda_{1},\dots,\lambda_{n}$ di $P$ fossero di modulo $<1$ allora avremmo $$|\text{traccia}(P)|=|\lambda_{1}+\dots+\lambda_{n}|\le|\lambda_{1}|+\dots+|\lambda_{n}|<n$$ Poiché esiste almeno un autovalore di $P$ di modulo $\ge1$ si deduce che $\rho(P)=\max(|\lambda_{1}|,\dots,|\lambda_{n}|)\ge1$ e dunque il metodo non è convergente per il [[#Teorema (condizione necessaria e sufficiente di convergenza)|teorema]].
- Se $|\det(P)|\ge1$ allora esiste almeno un autovalore di $P$ di modulo $\ge1$. Infatti, se tutti gli autovalori $\lambda_{1},\dots,\lambda_{n}$ di $P$ fossero di modulo $<1$ allora avremmo $$|\det(P)|=|\lambda_{1}\dots\lambda_{n}|=|\lambda_{1}|\dots|\lambda_{n}|<1$$ Poiché esiste almeno un autovalore di $P$ di modulo $\ge1$, si deduce che $\rho(P)=\max(|\lambda_{1}|,\dots,|\lambda_{n}|)\ge1$ e dunque il metodo non è convergente per il [[#Teorema (condizione necessaria e sufficiente di convergenza)|teorema]].

**Oss.** Si può dimostrare che se il metodo iterativo $(\star)$ non è convergente, allora praticamente ogni scelta del vettore $\underline{x}^{(0)}$ produce una successione che non converge alla soluzione $\underline{x}$ del sistema lineare. In sostanza, se il metodo iterativo $(\star)$ non è convergente, allora è da buttare.

## Esempio 1
Consideriamo il sistema lineare $$A\underline{x}=\underline{b},\qquad A=\begin{bmatrix}2 & 1 \\ 1 & 2\end{bmatrix}, \qquad \underline{b}=\begin{bmatrix}1 \\ 1\end{bmatrix}$$ e il metodo iterativo $$\begin{align*}
&\underline{x}^{(0)}\in\mathbb{C}^2\:\:\text{dato}\\
&\underline{x}^{(k+1)}=(I-A)\underline{x}^{(k)}+\underline{b} \quad k=0,1,2,\dots
\end{align*}$$
1. Stabilire se il metodo è consistente con il sistema dato.
2. Stabilire se il metodo è convergente oppure no.
3. Calcolare le prime 5 iterazioni del metodo partendo dal vettore iniziale $\underline{x}^{(0)}=[0,0]^{T}$ e confrontarle con la soluzione estesa.

**Soluzione**
1. Il metodo assegnato è della forma $(\star)$ con $P=I-A$ e $\underline{q}=\underline{b}$. Sostituendo la soluzione $\underline{x}$ del sistema dato, nell'equazione del metodo (al posto di $\underline{x}^{(k+1)}$ e $\underline{x}^{k}$) otteniamo $$\underline{x}=(I-A)\underline{x}+\underline{b}\quad\iff\underline{x}=\underline{x}-A\underline{x}+\underline{b}\quad\iff A\underline{x}=\underline{b}$$ che è un'identità verificata. Dunque il metodo è consistente con il sistema dato.
2. La matrice d'iterazione del metodo è $$P=I-A=\begin{bmatrix}-1 & -1 \\ -1 & -1\end{bmatrix}$$ Poiché $|\text{traccia}(P)|=|-1 \:-1|=2$, non è verificata la condizione necessaria di convergenza $|\text{traccia}(P)|<2$ espressa nel [[#Corollario 2|corollario 2]], dunque il metodo non è convergente. 
3. La soluzione esatta del sistema dato possiamo calcolarla ad esempio col metodo di Gauss: $$A\underline{x}=\underline{b}\iff \begin{cases}
2x_{1}+x_{2}=1 \\
x_{1}+2x_{2}=1
\end{cases} \iff \begin{cases}
\begin{align*}
2x_{1}+&x_{2}=1 \\
\frac{3}{2}&x_{2}=\frac{1}{2}
\end{align*}
\end{cases}\iff\begin{cases}
x_{1}=\frac{1}{3} \\
  \\

x_{2}=\frac{1}{3}
\end{cases}$$ dunque $\underline{x}=[\frac{1}{3},\frac{1}{3}]^{T}$. Calcoliamo le prime 5 iterazioni del metodo partendo da $\underline{x}^{(0)}=[0,0]^{T}$: $$\begin{align*}
&\underline{x}^{(1)}=\begin{bmatrix}-1 & -1\\
-1 & -1\end{bmatrix}\begin{bmatrix}0\\
0\end{bmatrix}+\begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix}1\\
1\end{bmatrix}\\
&\underline{x}^{(2)}=\begin{bmatrix}-1 & -1\\
-1 & -1\end{bmatrix}\begin{bmatrix}1\\
1\end{bmatrix}+\begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix}-1\\
-1\end{bmatrix}\\
&\underline{x}^{(3)}=\begin{bmatrix}-1 & -1\\
-1 & -1\end{bmatrix}\begin{bmatrix}-1\\
-1\end{bmatrix}+\begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix}3\\
3\end{bmatrix}\\
&\underline{x}^{(4)}=\begin{bmatrix}-1 & -1\\
-1 & -1\end{bmatrix}\begin{bmatrix}3\\
3\end{bmatrix}+\begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix}-5\\
-5\end{bmatrix}\\
&\underline{x}^{(5)}=\begin{bmatrix}-1 & -1\\
-1 & -1\end{bmatrix}\begin{bmatrix}-5\\
-5\end{bmatrix}+\begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix}-11\\
-11\end{bmatrix}
\end{align*}$$ Si nota che le iterazioni non stanno convergendo alla soluzione $\underline{x}$.

## Esempio 2
Consideriamo il sistema lineare $$A\underline{x}=\underline{b},\qquad A=\begin{bmatrix}2 & 1 \\ 1 & 2\end{bmatrix}, \qquad \underline{b}=\begin{bmatrix}1 \\ 1\end{bmatrix}$$ e il metodo iterativo $$\begin{align*}
&\underline{x}^{(0)}\in\mathbb{C}^2\:\:\text{dato}\\
&\underline{x}^{(k+1)}=(I-\frac{1}{2}A)\underline{x}^{(k)}+ \frac{1}{2}\underline{b} \quad k=0,1,2,\dots
\end{align*}$$
1. Stabilire se il metodo è consistente con il sistema dato.
2. Stabilire se il metodo è convergente oppure no.
3. Calcolare le prime 5 iterazioni del metodo partendo dal vettore iniziale $\underline{x}^{(0)}=[0,0]^{T}$ e confrontarle con la soluzione estesa.

**Soluzione**
1. Il metodo assegnato è della forma $(\star)$ con $P=I- \frac{1}{2}A$ e $\underline{q}=\frac{1}{2}\underline{b}$. Sostituendo la soluzione $\underline{x}$ del sistema dato, nell'equazione del metodo (al posto di $\underline{x}^{(k+1)}$ e $\underline{x}^{k}$) otteniamo $$\underline{x}=(I- \frac{1}{2}A)\underline{x}+ \frac{1}{2}\underline{b}\quad\iff\underline{x}=\underline{x}- \frac{1}{2}A\underline{x}+ \frac{1}{2}\underline{b}\quad\iff A\underline{x}=\underline{b}$$ che è un'identità verificata. Dunque il metodo è consistente con il sistema dato.
2. La matrice d'iterazione del metodo è $$P=I-A=\begin{bmatrix}0 & - \frac{1}{2}  \\ - \frac{1}{2} & 0\end{bmatrix}$$ Poiché $||P||_{\infty}= \frac{1}{2}<1$  è verificata la condizione sufficiente espressa nel [[#Corollario 1|corollario 1]], dunque il metodo è convergente.corollario 1
3. La soluzione esatta del sistema è stata calcolata nell'esempio precedente ed è $\underline{x}=[\frac{1}{3}, \frac{1}{3}]^{T}$. Calcoliamo le prime 5 iterazioni del metodo partendo da $\underline{x}^{(0)}=[0,0]^{T}$ $$\begin{align*}
&\underline{x}^{(1)}=\begin{bmatrix}0 & - \frac{1}{2}\\
- \frac{1}{2} & 0\end{bmatrix}\begin{bmatrix}0\\
0\end{bmatrix}+ \frac{1}{2} \begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix} \frac{1}{2}\\
\frac{1}{2}\end{bmatrix}=\begin{bmatrix}0.5\\
0.5\end{bmatrix}\\
&\underline{x}^{(2)}=\begin{bmatrix}0 & - \frac{1}{2}\\
- \frac{1}{2} & 0\end{bmatrix}\begin{bmatrix} \frac{1}{2}\\
\frac{1}{2}\end{bmatrix}+ \frac{1}{2} \begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix} \frac{1}{4}\\
\frac{1}{4}\end{bmatrix}=\begin{bmatrix}0.25\\
0.25\end{bmatrix}\\
&\underline{x}^{(3)}=\begin{bmatrix}0 & - \frac{1}{2}\\
- \frac{1}{2} & 0\end{bmatrix}\begin{bmatrix} \frac{1}{4}\\
\frac{1}{4}\end{bmatrix}+ \frac{1}{2} \begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix} \frac{3}{8}\\
\frac{3}{8}\end{bmatrix}=\begin{bmatrix}0.375\\
0.375\end{bmatrix}\\
&\underline{x}^{(4)}=\begin{bmatrix}0 & - \frac{1}{2}\\
- \frac{1}{2} & 0\end{bmatrix}\begin{bmatrix} \frac{3}{8}\\
\frac{3}{8}\end{bmatrix}+ \frac{1}{2} \begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix} \frac{5}{16}\\
\frac{5}{16}\end{bmatrix}=\begin{bmatrix}0.3125\\
0.3125\end{bmatrix}\\
&\underline{x}^{(5)}=\begin{bmatrix}0 & - \frac{1}{2}\\
- \frac{1}{2} & 0\end{bmatrix}\begin{bmatrix} \frac{5}{16}\\
\frac{5}{16}\end{bmatrix}+ \frac{1}{2} \begin{bmatrix}1\\
1\end{bmatrix}=\begin{bmatrix} \frac{11}{32}\\
\frac{11}{32}\end{bmatrix}=\begin{bmatrix}0.34375\\
0.34375\end{bmatrix}
\end{align*}$$ Si nota che le iterazioni stanno convergendo alla soluzione $\underline{x}$.

## Esempio 3
Consideriamo il sistema lineare $$A\underline{x}=\underline{b},\qquad A=\begin{bmatrix}2 & 1 \\ 1 & 2\end{bmatrix}, \qquad \underline{b}=\begin{bmatrix}1 \\ 1\end{bmatrix}$$ e il metodo iterativo $$\begin{align*}
&\underline{x}^{(0)}\in\mathbb{C}^2\:\:\text{dato}\\
&\underline{x}^{(k+1)}=(I-\omega A)\underline{x}^{(k)}+ \omega\underline{b} \quad k=0,1,2,\dots
\end{align*}$$ dove $\omega\in\mathbb{R}$ è un parametro fissato.
1. Stabilire per quali valori di $\omega$ il metodo è consistente con il sistema dato.
2. Stabilire per quali valori di $\omega$ il metodo è convergente.

**Soluzione**
1. Il metodo assegnato è della forma $(\star)$ con $P=I- \omega A$ e  $\underline{q}=\omega\underline{b}$. Sostituendo la soluzione $\underline{x}$ del sistema dato nell'equazione del metodo (al posto di $\underline{x}^{(k+1)}$ e $\underline{x}^{k}$) otteniamo $$\underline{x}=(I- \omega A)\underline{x}+ \omega\underline{b}\quad\iff\quad\underline{x}=\underline{x}-\omega A\underline{x}+\omega\underline{b}\quad\iff\quad\omega A\underline{x}=\omega\underline{b}$$ che è un identità verificata. Dunque il metodo è consistente con il sistema dato per qualunque valore di $\omega$.
2. La matrice d'iterazione del metodo è $$P=I-\omega A=\begin{bmatrix}1-2\omega & -\omega \\ -\omega & 1-2\omega\end{bmatrix}$$ Per capire quali sono i valori di $\omega$ per i quali il metodo è convergente dobbiamo capire quando è soddisfatta la condizione necessaria e sufficiente di convergenza $\rho(P)<1$ espressa nel [[#Teorema (condizione necessaria e sufficiente di convergenza)|teorema]]. In questo caso infatti non possiamo basarci sulle condizioni solo sufficienti o solo necessarie espresse in entrambi i corollari. Calcoliamo dunque $\rho(P)$. Il polinomio caratteristico di $P$ è $$\begin{align*}
C_{p}(\lambda)&=\det(\lambda I-P)=\begin{vmatrix}\lambda-1+2\omega & \omega \\ \omega & \lambda-1+2\omega\end{vmatrix}\\
&= (\lambda-1+2\omega)^{2}-\omega^{2}=\lambda^{2}+2(-1+2\omega)\lambda+(-1+2\omega)^{2}-\omega^2
\end{align*}$$ per cui gli autovalori di $P$ sono $$\lambda_{1,2}=1-2\omega\pm\sqrt{(-1+2\omega)^{2}-(-1+2\omega)^{2}+\omega^{2}}=1-2\omega\pm|\omega|=1-\omega, 1-3\omega$$ Dunque $$\rho(P)=\max(|1-\omega|,|1-3\omega|)$$ In conclusione, il metodo è convergente per i valori di $\omega$ tali che $$\begin{align*}
\rho(P)<1\quad&\iff\quad\begin{cases}
|1-\omega|<1\\
|1-3\omega|<1
\end{cases}\quad\iff\quad\begin{cases}
-1<1-\omega<1\\
-1<1-3\omega<1
\end{cases}\quad\iff\quad\begin{cases}
0<\omega<2\\
0<\omega<\frac{3}{2}
\end{cases}\\
&\iff 0<\omega<\frac{3}{2} 
\end{align*}$$Il metodo non è convergente per gli altri valori di $\omega$.

**Oss. 1**
Se prendiamo $\omega=\frac{3}{4}$ allora $$\begin{align*}
P&=\begin{bmatrix}- \frac{1}{2} & - \frac{3}{4} \\ - \frac{3}{4} & - \frac{1}{2}\end{bmatrix}\\
|\det(P)|&= \Bigg| \frac{1}{4}- \frac{9}{16}\Bigg|=\Bigg|- \frac{5}{16}\Bigg|= \frac{5}{16}<1\\
|\text{traccia}(P)|&= \Bigg| -\frac{1}{2}- \frac{1}{2}\Bigg|=1<2  
\end{align*}$$ per cui sono soddisfatte le condizioni necessarie di convergenza espresse nel [[#Corollario 2|corollario 2]] Tuttavia, il metodo non è convergente perché $\frac{3}{4}<\frac{2}{3}$ . Questo mostra che le condizioni espresse nel [[#Corollario 2|corollario 2]] sono necessarie *ma non sufficienti* a garantire la convergenza.

**Oss. 2**
Per ogni valore $\omega\in(0, \frac{2}{3})$ il metodo considerato è convergente. 
Ci si potrebbe chiedere: qual è il miglior valore di ω che possiamo scegliere? 
Risposta: il miglior valore di $\omega$ è quello che rende minimo il raggio spettrale della matrice d’iterazione $P$ perché questo valore di $\omega$ è quello che assicura la maggiore velocità di convergenza. Nel nostro caso, il miglior valore di $\omega$ è quello che rende minimo $$\rho(P)=\max(|1-\omega|, |1-3\omega|)$$ La figura sotto mostra i grafici delle funzioni $|1-\omega|$ (rosso) e $|1-3\omega|$ (blu), da cui si vede che il valore di $\omega$ che rende minimo $\rho(P)$ è $\omega_{opt}= \frac{1}{2}$. Il valore $\omega_{opt}$ è l'ascissa del punto d'intersezione delle rette di equazione $y=1-\omega$ e $y=-1+3\omega$, e si ottiene risolvendo l'equazione $1-\omega=-1+3\omega$. Per $\omega=\omega_{opt}= \frac{1}{2}$ risulta $\rho(P)= \frac{1}{2}$ e il metodo che si ottiene è quello visto nell'[[#Esempio 2|esempio 2]]. 
![[Pasted image 20231218100315.png|center|500]]

# Velocità di convergenza
Consideriamo il metodo $(\star)$ per risolvere il sistema lineare, e supponiamo che esso sia convergente (cioé $\underline{x}=P\underline{x}+\underline{q}$ e $\rho(P)<1$). Sulla base dell'equazione dell'errore $\underline{e}^{(k)}=P^{k}\underline{e}^{(0)}$ (ultima equazione della dimostrazione del [[#Teorema (condizione necessaria e sufficiente di convergenza)|teorema]]), si possono dimostrare alcuni risultati teorici relativi alla velocità di convergenza del metodo nei quali non ci addentriamo. Per noi è sufficiente sapere questo fatto. 

>Fissiamo una qualsiasi norma vettoriale $||\cdot||$. Per quasi tutti i vettori $\underline{x}^{(0)}\in\mathbb{C}^{n}$, l'errore $\underline{e}^{(k)}=\underline{x}^{(k)}-\underline{x}$ commesso dal metodo $(\star)$ soddisfa $$||\underline{e}^{(k)}||\approx Ck^{m}\rho(P)^{k}$$ per ogni $k$ abbastanza grande, dove $0\le m\le n-1$ è un intero, che dipende solo da $P$ e da $C$, è una costante indipendente da $k$.

Vediamo quindi che la convergenza delle successioni $\underline{x}^{(0)},\underline{x}^{(1)},\underline{x}^{(2)},\dots$ generate da un metodo della forma $(\star)$ risulta tanto più veloce quanto più $\rho(P)$ è piccolo. Sulla base di questo fatto, diamo la seguente definizione.

**Def.** Dati due metodi $\alpha$ e $\beta$ della forma $(\star)$ per risolvere il sistema lineare, entrambi convergenti, diremo che $a$ *converge più velocemente di* $\beta$ se $\rho(P_{\alpha})<\rho(P_{\beta})$ dove $P_{\alpha}$ e $P_{\beta}$ indicano rispettivamente la matrice d'iterazione di $\alpha$ e di $\beta$. 

# Criterio d'arresto del residuo
Consideriamo il metodo $(\star)$ per risolvere il sistema lineare. La successione di vettori $\underline{x}^{(0)},\underline{x}^{(1)},\underline{x}^{(2)},\dots$ generata dal metodo, anche quando risulta convergente alla soluzione $\underline{x}$ del sistema lineare, deve essere comunque arrestata prima o poi: non si può pretendere di raggiungere esattamente la soluzione $\underline{x}$. Il criterio di arresto più utilizzato è quello del residuo: si sceglie una norma vettoriale $||\cdot||$ (tipicamente $||\cdot||_{1}, ||\cdot||_{2}$ oppure $||\cdot||_{\infty}$) *e si arresta la successione al primo vettore $\underline{x}^{(K)}$ che soddisfa la condizione* $$\frac{||\underline{r}^{(K)}||}{||\underline{b}||}\le \epsilon\qquad (\star\star)$$ dove $\underline{r}^{(k)}=\underline{b}-A\underline{x}^{(K)}$ è il residuo del sistema lineare relativo a $\underline{x}^{(K)}$ e $\epsilon>0$ è una soglia di precisione (4.2)prefissata. La condizione $(\star\star)$ impone che l'errore relativo $\frac{||A\underline{x}^{(K)}-\underline{b}||}{||b||}$ commesso approssimando $\underline{b}$ con $A\underline{x}^{(K)}$ sia $\le \epsilon$. In questo modo, avremo che l'errore relativo sulla soluzione soddisfa $$\begin{align*}
\frac{||\underline{x}-\underline{x}^{(K)}||}{||\underline{x}||}&= \frac{||A^{-1}(\underline{b}-A\underline{x}^{(K)})||}{||A^{-1}\underline{b}||}=\frac{||A^{-1}\underline{r}^{(K)}||}{||A^{-1}\underline{b}||}\\
&\le \frac{||A^{-1}||\:||\underline{r}^{(K)}}{A^{-1}\underline{b}||}=\frac{||A||\:||A^{-1}||\:||\underline{r}^{(K)}||}{||A||\:||A^{-1}\underline{b}||}\\
&\le \frac{||A||\:||A^{-1}||\:||\underline{r}^{(K)}}{||AA^{-1}\underline{b}||}=\frac{||A||\:||A^{-1}||\:||\underline{r}^{(K)}}{||\underline{b}||}\\
&\le \mu(A)\epsilon 
\end{align*}$$ dove $\mu(A)=||A||\:||A^{-1}||$ si chiama numero di condizioamento della matrice $A$ in norma $||\cdot||$.

**Oss.**
La successione di vettori $\underline{x}^{(0)},\underline{x}^{(1)},\underline{x}^{(2)},\dots$ generata dal metodo $(\star)$, anche quando risulta convergente alla soluzione $\underline{x}$ del sistema lineare, potrebbe impiegare troppo tempo a convergere. In tal caso, potrebbero volerci troppe iterazioni prima che venga soddisfatta la condizione di arresto del residuo $(\star\star)$. Per questo motivo è indispensabile, quando si implementa un metodo iterativo come $(\star)$, fissare sempre un numero massimo di iterazioni consentite. Questo peraltro serve anche ad arrestare le iterazioni quando non c’è convergenza.