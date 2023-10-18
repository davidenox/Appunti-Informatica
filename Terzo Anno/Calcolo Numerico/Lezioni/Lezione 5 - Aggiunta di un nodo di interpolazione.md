# Aggiunta di un nodo di interpolazione

La forma di Newton è molto utile quando si deve aggiungere ai dati dell'interpolazione $(x_0,y_0),(x_1,y_1),\dots,(x_n,y_n)$ un nuovo dato $(x_{n+1},y_{n+1})$ con $x_{n+1}\neq x_0,\dots,x_n$. Infatti, detta $f(x)$ una funzione che soddisfa $f(x_{i})=y_{i}\:\:\forall \:i=0,\dots,n+1$, allora il polinomio di interpolazione dei dati $(x_0,y_0),(x_1,y_1),\dots,(x_n,y_n)$, si scrive in forma di Newton come$$p(x)=\underline{f[x_{0}]}+\underline{f[x_0,x_1]}(x-x_0)+\dots+\underline{f[x0,\dots,x_n]}(x-x_0)\dots(x-x_{n-1})$$ mentre il polinomio di interpolazione dei dati $(x_0,y_0),\dots,(x_{n+1},y_{n+1})$ si scrive in forma di Newton come $$q(x)=p(x)+f[x_0,\dots,x_{n+1}](x-x_0)\dots(x-x_n)$$
- Avendo a disposizione $p(x)$ in forma di Newton (cioè i coefficienti sottolineati), per ottenere $q(x)$ in forma di Newton, basta calcolare $f[x_0,\dots,x_{n+1}]$. Guardando la tabella delle differenze divise, pensando $n=2$ e quindi $n+1=3$, si vede che per calcolare $f[x_0,\dots,x_{n+1}]$, devo calcolare solo l'ultima riga della tabella (tranne il primo elemento $f[x_{n+1}]=y_{n+1}$ noto) e questo calcolo mi costa $2(n+1)A+(n+1)D$
- Avendo a disposzione $p(x)$ in forma di Newton e il suo valore $p(t)$, per calcolare $q(t)$ occorre calcolare $f[x_0,\dots,x_{n+1}](t-x_0)\dots(t-x_n)$ e sommarlo a $p(t)$. Questo richiede $2(n+1)A+(n+1)D$ per calcolare $f[x_0,\dots,x_{n+1}]$, più $(n+1)M+(n+1)A$ per ottenere $f[x_0,\dots,x_{n+1}](t-x_0)\dots(t-x_n)$ più $1A$ per sommare il risultato a $p(t)$. In totale quindi: $$(3n+4)A+(n+1)M+(n+1)D\approx3nA+nM+nD$$
## Esempio 
Consideriamo $f(x)=cos(\pi x)+x^{2}$.
1. Scrivere il polinomio di interpolazione $p(x)$ di $f(x)$ sui nodi $x_{0}=-1,x_1=0,x_2=2$ e calcolare il valore in $t=\frac{1}{2}$. 
2. Scrivere il polinomio di interpolazione $q(x)$ di $f(x)$ sui nodi $x_{0}=-1,x_1=0,x_2=2$ a cui aggiungiamo $x_{3}=1$ e calcolare il valore in $t=\frac{1}{2}$. 

**Soluzione**
Conviene scrivere $p(x)$ in forma di Newton in vista del secondo punto dell'esercizio: $$p(x)=f[x_{0}]+f[x_0,x_1](x-x_0)+f[x0,x_1,x_2](x-x_0)(x-x_{1})\:\:\:(\star)$$
- $f[x_0]=f(x_0)=0$
- $f[x_1]=f(x_1)=1$
- $f[x_2]=f(x_2)=5$

$$\underline{f[x_0,x_1]=\frac{f[x_1]-f[x_0]}{x_{1}-x_{0}}=1}$$ $$f[x_0,x_2]=\frac{f[x_2]-f[x_0]}{x_{2}-x_{0}}=\frac{5}{3}$$
$$\underline{f[x_0,x_1,x_2]=\frac{f[x_0,x_2]-f[x_0,x_1]}{x_{2}-x_{1}}=\frac{1}{3}}$$ Sostituendo in $(\star)$ si ottiene $$p(x)=(x+1)+ \frac{1}{3}(x+1)x$$ Calcoliamo $p(t)$ in $t= \frac{1}{2}$ con Ruffini-Horner:
$h_2=f[x_0,x_1,x_{2}]=\frac{1}{3}$
$h_{1}=f[x_0,x_{1}]+(t-x_{1})h_2=1+\left(\frac{1}{2}-0\right) \frac{1}{3}= \frac{7}{6}$
$h_{0}=f[x_{0}]+(t-x_{0})h_{1}=0+\left(\frac{1}{2}+1\right) \frac{7}{6}= \frac{7}{4}$
$\implies p(t)=p(\frac{1}{2})=h_{0}= \frac{7}{4}=1.75$ 

Per il secondo punto scriviamo $q(x)$ in forma di Newton sfruttando il calcolo di $p(x)$ precedente: $$q(x)=p(x)+f[x_0,x_1,x_2,x_3](x-x_0)(x-x_1)(x-x_2)$$ $f[x_3]=f(x_3)=0$
$$f[x_0,x_3]=\frac{f[x_3]-f[x_0]}{x_{3}-x_{0}}=0$$ $$f[x_0,x_1,x_3]=\frac{f[x_0,x_3]-f[x_0,x_1]}{x_{3}-x_{1}}=-1$$ $$\underline{f[x_0,x_1,x_2,x_3]=\frac{f[x_0,x_1,x_3]-f[x_0,x_1,x_2]}{x_{3}-x_{2}}=\frac{- 1+\frac{1}{3}}{1-2}=\frac{4}{3}}$$
Concludendo, la forma di Newton di $q(x)$ è $$q(x)=p(x)+ \frac{4}{3}(x+1)x(x-2)=0+1(x+1)+ \frac{1}{3}(x+1)x+ \frac{4}{3}(x+1)x(x-1)$$ Avendo già $p(t)=\frac{7}{4}$ $$q(t)=p(t)+ \frac{4}{3}(t+1)t(t-2)=\frac{7}{4}+ \frac{4}{3}(\frac{1}{2}+1)\frac{1}{2}(\frac{1}{2}+2)=\frac{7}{4}- \frac{3}{2}= \frac{1}{4}$$
*Oss.* 
$f(t)=f(\frac{1}{2})=\frac{1}{4}=q(\frac{1}{2})$, l'aggiunta del nodo $x_{3}=1$ ha migliorato l'approssimazione in $t=\frac{1}{2}$ rendendola esatta, cioé $p(\frac{1}{2})=\frac{7}{4}$ non è un'approssimazione esatta di $f(1/2)$, mentre $q(\frac{1}{2})=\frac{1}{4}$ **è** un'approssimazione esatta di $f(1/2)$.

# Esercizio
Considerate $f(x)=\sin(2\pi x)$
1. Determinare il polinomio di interpolazione $p(x)$ di $f(x)$ sui nodi $x_{0}=0,x_{1}= \frac{1}{2},x_{2}=2$ e calcolare $p(t)$, per $t= \frac{1}{4}$ e $t= \frac{1}{3}$
2. Determinare il polinomio di interpolazione $q(x)$ di $f(x)$ sui nodi $x_{0}=0,x_{1}= \frac{1}{2},x_{2}=2$ a cui si aggiunge $x_{3} = \frac{3}{4}$ e calcolare $q(t)$, per $t= \frac{1}{4}$ e $t= \frac{1}{3}$