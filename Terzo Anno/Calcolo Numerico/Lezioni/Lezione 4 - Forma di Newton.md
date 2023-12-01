- La forma canonica: 
	- forma associata alla base canonica di $\mathbb R_{n}[x]$ $\to$ $1,\: x,\:x^{2},\dots,\:x^{n}$
- La forma di Lagrange: 
	- forma associata alla base dei polinomi di Lagrange  $\mathbb R_{n}[x]$ $\to$ $L_{0}(x),\dots,\: L_{n}(x)$
# Forma di Newton
**Def.** (differenze divise)
Sia $f:[a,b]\to \mathbb R$.
- Se $y \in [a,b]$ si definisce differenza divisa fi $f(x)$ relativa a $y$ il numero $f[y]=f(y)$
- Se $y_{1},\dots,y_{k}\in [a,b]$ sono $k \ge 2$ punti distinti, si definisce defferenza divisa di $f(x)$ relativa a $y_{1},\dots,y_{k}$ il numero $$f[y_{1},\dots,y_{k}]=\frac{f[y_{1},\dots,y_{k-2},y_{k}]-f[y_{1},\dots,y_{k-1}]}{y_{k}-y_{k-1}}$$
**Oss.** ($k=2$)
$$f[y_{1},y_{2}]=\frac{f[y_{2}]-f[y_{1}]}{y_{2}-y_{1}}=\frac{f(y_{2})-f(y_{1})}{y_{2}-y_{1}}=\text{rapporto incrementale di }f\text{ relativo a }y_1,y_2$$

**Teo.**
Sia $f:[a,b]\to \mathbb R$ una funzione e siano $x_{0},\dots,x_{n}\in[a,b]$ punti distinti. Allora il polinomio di interpolazione di $f(x)$ sui nodi $x_{0},\dots,x_{n}$ è data da $$p(x)=f[x_{0}]+f[x_{0},x_{1}](x-x_{0})+\dots+f[x_{0},x_{1},\dots,x_{n}](x-x_{0})\dots(x-x_{n-1})\:\:\:(\star)$$
*Corollario*
Sia $f:[a,b]\to \mathbb R$ una funzione e siano $x_{0},\dots,x_{n}\in[a,b]$ punti distinti. Allora $f[x_{0},x_{1},\dots,x_{n}]$ non cambia se vengono permutati i suoi $n+1$ argomenti, ovvero $$f[x_{0},x_{1},\dots,x_{n}]=f[x_{\sigma(0)},x_{\sigma(1)},\dots,x_{\sigma(n)}]\:\:\: \forall \: \sigma \text{ permutazione di } \{0,1,\dots,n\}$$
*Dim.*
Sia $\sigma$ una permutazione qualsiasi di $\{0,1,\dots,n\}$. Dalla $(\star)$ applicata prima con i nodi $x_{0},\dots,x_{n}$ e poi con i nodi $x_{\sigma(0)},x_{\sigma(1)},\dots,x_{\sigma(n)}$, vediamo che $f[x_{0},x_{1},\dots,x_{n}]$ e $f[x_{\sigma(0)},x_{\sigma(1)},\dots,x_{\sigma(n)}]$ sono entrambi uguali al coefficiente direttore (ovvero il coefficiente del termine di grado massimo $x^{n}$) di $p(x) =$ polinomio di interpolazione di $f(x)$ sui nodi $x_0,\dots,x_n$ 

## Esempio
Scrivere in forma canonica e in forma di Newton il polinomio di interpolazione $p(x)$ di $f(x)=\sqrt x$ sui nodi $x_{0}=0,\:x_{1}=0.16,\:x_{2}=0.64,\:x_{3}=1$

**Soluzione**
Iniziamo dalla forma di Newton

$$p(x)=\underline{f[x_{0}]}+\underline{f[x_{0},x_{1}]}(x-x_{0})+\underline{f[x_{0},x_{1},x_{2}]}(x-x_{0})(x-x_{1})+\underline{f[x_{0},x_{1},x_{2},x_{3}]}(x-x_{0})(x-x_{1})(x-x_{2})$$  ^aea032

L'unica cosa da fare è calcolare le differenze divise sottolineate. Si usa la tabella delle differenze divise, procedendo colonna per colonna

$$\underline{f[x_0]=f(x_0)=\sqrt{0}=0}$$ 
$f[x_1]=f(x_1)=\sqrt{0.16}=0.4$
$f[x_2]=f(x_2)=\sqrt{0.64}=0.8$
$f[x_3]=f(x_3)=\sqrt{1}=1$

$$\underline{f[x_0,x_1]=\frac{f[x_1]-f[x_0]}{x_{1}-x_{0}}=\frac{0.4}{0.16}=\frac{5}{2}}$$ $$f[x_0,x_2]=\frac{f[x_2]-f[x_0]}{x_{2}-x_{0}}=\frac{0.8}{0.64}=\frac{5}{4}$$ $$f[x_0,x_3]=\frac{f[x_3]-f[x_0]}{x_{3}-x_{0}}=\frac{1}{1}=1$$
$$\underline{f[x_0,x_1,x_2]=\frac{f[x_0,x_2]-f[x_0,x_1]}{x_{2}-x_{1}}=\frac{\frac{5}{4}- \frac{5}{2}}{0.64-0.16}=-\frac{125}{48}}$$ $$f[x_0,x_1,x_3]=\frac{f[x_0,x_3]-f[x_0,x_1]}{x_{3}-x_{1}}=\frac{1- \frac{5}{2}}{1-0.16}=-\frac{25}{14}$$ $$\underline{f[x_0,x_1,x_2,x_3]=\frac{f[x_0,x_1,x_3]-f[x_0,x_1,x_2]}{x_{3}-x_{2}}=\frac{- \frac{25}{14}+\frac{125}{48}}{1-0.64}=\frac{6875}{3024}}$$ 
Sostituendo nella [[#^aea032|forma di Newton]] otteniamo $$p(x)=\frac{5}{2}x- \frac{125}{48}x(x-0.16)+ \frac{6875}{3024}x(x-0.16)(x-0.64)$$ 
Sviluppiamo i calcoli e portiamo il polinomio in forma canonica: $$p(x)=\frac{6875}{3024}x^{3}+(- \frac{125}{48}- 0.16\frac{6875}{3024}-0.64\frac{6875}{3024})x^{2}+(\frac{5}{2}+ \frac{124}{48}0.16+ \frac{6875}{3024}0.16\cdot0.64)x=$$ $$=\frac{6875}{3024}x^{3}- \frac{13375}{3024}x^{2}+ \frac{2381}{756}x$$ 
**Oss.**
Supponiamo che siano dati i punti $(x_{0},y_{0}),\dots,(x_{n},y_{n})\in \mathbb R^{2}$ con $x_{0},\dots,x_{n}$ distinti. I numeri $y_{0},\dots,y_{n}$ possono <u>sempre</u> essere interpretati come i valori nei nodi $x_{0},\dots,x_{n}$ di una qualche funzione $f:[a,b]\to \mathbb R$ definita su un qualche intervallo $[a,b]$ che contiene $x_{0},\dots,x_{n}$. Pertanto possiamo senza problemi parlare di forma di Newton del polinomio di interpolazione dei dati $(x_{0},y_{0}),\dots,(x_{n},y_{n})$ anche se non viene specificata alcuna funzione $f(x)$ t.c. $f(x_{i})=y_{i}\:\: \forall \:i=0,\dots,n$.

# Esercizi
- Scrivere in forma canonica e in forma di Newton il polinomio di interpolazione di $f(x)=\cos(\frac{\pi}{2}x)\cdot\log_{2}(x)$ sui nodi $x_{0}=1,x_{1}=2,x_{2}=4,x_{3}=8$.

- Scrivere in forma Lagrange e in forma di Newton il polinomio di interpolazione dei valori $y_{0}=0,y_{1}=3,y_{2}=-3$ sui nodi $x_{0}=0,x_{1}=1,x_{2}=2$

# Algoritmo di valutazione del polinomio di interpolazione in un punto
Si basa sulla forma di Newton che è conveniente per questo scopo.

Sia $f:[a,b]\to \mathbb R$, siano $x_{0},\dots,x_{n}\in[a,b]$ punti distinti e sia $t\in \mathbb R$. Si vuole costruire un algoritmo per calcolare $p(t)$, dove $p(x)$ è il polinomio di interpolazione di $f(x)$ sui nodi $x_{0},\dots,x_{n}$.

Per chiarezza, esprimiamo l'algoritmo nel caso $n=3$ $$p(x)=\underline{f[x_{0}]}+\underline{f[x_{0},x_{1}]}(x-x_{0})+\underline{f[x_{0},x_{1},x_{2}]}(x-x_{0})(x-x_{1})+\underline{f[x_{0},x_{1},x_{2},x_{3}]}(x-x_{0})(x-x_{1})(x-x_{2})$$
- Il primo passo dell'algoritmo è indipendente dal punto $t$ in cui $p(x)$ deve essere valutato e consiste nel calcolare le differenze divise sottolineate. Questo calcolo si fa con la tabella delle differenze divise.

- Dopo il primo passo, per calcolare $p(t)$ si usa il metodo di Ruffini-Hormer: $$p(t)=\underbrace{f[x_{0}]+(t-x_{0})\{\underbrace{f[x_{0},x_{1}](t-x_{1})\underbrace{[f[x_{0},x_{1},x_{2}]+(t-x_{2})\underbrace{f[x_{0},x_{1},x_{2},x_{3}]}_{h3}]}_{h2}}_{h1}}_{h0}  \}$$
Che possiamo riassumere come: 
- $h_{3}=f[x_{0},x_{1},x_{2},x_{3}]$
- $h_{2}=f[x_{0},x_{1},x_{2}]+(t-x_{2})h_{3}$
- $h_{1}=f[x_{0},x_{1}]+(t-x_{1})h_{2}$
- $h_{0}=f[x_{0}]+(t-x_{0})h_{1}$ 

In generale $$h_i=f[x_0,\dots,x_i]+(t-x_{i})h_{i+1}$$
## Calcolo costo computazionale 
- Costo primo passo: le differenze divise da calcolare sono tutte quelle della tabella meno la prima colonna. In totale quindi le differenze divise da calcolare  sono in numero pari agli elementi della parte triangolare inferiore (compresa la diagonale) di una matrice $n\times n$, cioè sono in numero di $\frac{n^2-n}{2}+n=\frac{n(n+1)}{2}$. Il calcolo di ogni differenza divisa richiede $2S + 1D$.
$\implies$ in totale il costo del primo passo è $$n(n+1)S+\frac{n(n+1)}{2}D$$
- Costo secondo passo: ci sono $n$ elementi $h_{i}\text{ per }i=0,\dots,n$ da calcolare, e il calcolo di ciascuno richiede $1A+1S+1M$ 
$\implies$ in totale $nA+nS+nM=2nA+nM$ 

Il costo totale quindi risulta $$C(n)=(n^{2}+3n)A+nM+\left(\frac{n^{2}}{2}+ \frac{n}{2}\right)\approx n^{2}A+nM+ \frac{n^{2}}{2}D=$$ $$=\frac{3n^{2}}{2}+ \frac{9n}{2}\approx \frac{3n^{2}}{2}$$