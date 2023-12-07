# Estrapolazione
Sia $f:[a,b]\to \mathbb R$ (integrabile) e siano $I_{n_{0}},I_{n_{1}} ,\dots,I_{n_{m}}$ le formule dei trapezi di ordini (distinti) $n_{0}, n_{1},\dots,n_{m}$ e passi $h_{0}= \frac{b-a}{n_{0}}, h_{1}= \frac{b-a}{n_{1}},\dots,h_{m}= \frac{b-a}{n_{m}}$ per approssimare $\int_{a}^{b}f(x)\:dx$. Sia $p(x)\in \mathbb R_{m}[x]$ il polinomio di interpolazione dei dati $(h_{0}^{2},I_{n_{0}}),\dots,(h_{m}^{2},I_{n_{m}})$; osserviamo che tale polinomio esiste ed è unico per il [[Lezione 1 - Interpolazione polinomiale#^0c2fd0|teorema]] in quanto i nodi $h_{0}^{2},h_{1}^{2},\dots,h_{m}^{2}$ sono distinti in quanto $n_{0}, n_{1},\dots,n_{m}$ sono distinti.

Il risultato è che $p(0)$ è un approssimazione di $\int_{a}^{b}f(x)\:dx$ **molto** più accurata delle singole formule dei trapezi $I_{n_{0}},I_{n_{1}} ,\dots,I_{n_{m}}$. In figura l'illustrazione del procedimento di estrapolazione nel caso $m=2$.

![[Pasted image 20231102150824.png|center|500]]


Il procedimento di valutare in $0$ il polinomio di interpolazione $p(x)$ si chiama **estrapolazione**, perché $p(x)$ viene valutato in un punto ($x=0$) che si trova all'esterno del più piccolo intervallo che contiene i nodi $h_{0}^{2},h_{1}^{2},\dots,h_{m}^{2}$; $p(0)$ è detto **valore estrapolato**. 

# Esempio
Si consideri la funzione $f(x)=xe^x$. Per ogni $n \ge 1$ indichiamo con $I_{n}$ la formula dei trapezi di ordine $n$ per approssimare $I=\int_{0}^{2}f(x)\:dx$.
- Calcolare $I$
- Calcolare $I_{12},I_{24},I_{30}$ e confrontarli con $I$.
- Calcolare $p(0)$ dove $p(x)$ è il polinomio di interpolazione dei dati $(h_{0}^{2},I_{12}),(h_{1}^{2},I_{24}),(h_{2}^{2},I_{30})$ e $h_0,h_1,h_2$ sono i passi di discretizzazione delle formule dei trapezi $I_{12},I_{24},I_{30}$. Confrontare $p(0)$ con il valore esatto $I$.
- Posto $\epsilon=\big|p(0)-I\big|$, determinare un $n$ in modo tale che la formula dei trapezi $I_{n}$ fornisca un'approssimazione di $I$ con errore $\big|I_{n}-I\big|\le \epsilon$.

## Soluzione punto 1
Integrando per parti $$I=\int xe^{x}\:dx=xe^{x}\int e^x\:dx=xe^{x}-e^{x}$$per cui $$I=\int_{0}^{2} xe^{x}\:dx=\bigg[xe^{x}-e^{x}\bigg]_{0}^{2}=1+e^2=8.3890560989\dots$$
## Soluzione punto 2
Siano $$h_{0}= \frac{2-0}{12}=\frac{1}{6},\:\:\:h_{1}= \frac{2-0}{24}=\frac{1}{12},\:\:\:h_{2}= \frac{2-0}{30}=\frac{1}{15}$$ i passi di discretizzazione delle formule $I_{12},I_{24},I_{30}$. Usando la formula nota otteniamo $$\begin{align*}
I_{12}&=\frac{1}{6}\left[\frac{0+2e^{2}}{2}+\sum\limits_{j=1}^{11} \frac{j}{6}e^{\frac{j}{6}}\right]=\frac{1}{6}\left[e^{2}+ \frac{1}{6}e^{\frac{1}{6}}+\frac{2}{6}e^{\frac{2}{6}}+\dots+\frac{11}{6}e^{\frac{11}{6}} \right]=\\
&=8.4380178285\dots \\\\

I_{24}&=\frac{1}{12}\left[\frac{0+2e^{2}}{2}+\sum\limits_{j=1}^{23} \frac{j}{12}e^{\frac{j}{12}}\right]=\frac{1}{12}\left[e^{2}+ \frac{1}{12}e^{\frac{1}{12}}+\frac{2}{12}e^{\frac{2}{12}}+\dots+\frac{23}{12}e^{\frac{23}{12}} \right]=\\
&=8.4013033444\dots\\\\

I_{30}&=\frac{1}{15}\left[\frac{0+2e^{2}}{2}+\sum\limits_{j=1}^{29} \frac{j}{15}e^{\frac{j}{15}}\right]=\frac{1}{15}\left[e^{2}+ \frac{1}{15}e^{\frac{1}{15}}+\frac{2}{15}e^{\frac{2}{15}}+\dots+\frac{29}{15}e^{\frac{29}{15}} \right]=\\
&=8.3968948597\dots
\end{align*}$$ Confrontando con il valore esatto $I$, vediamo che $I_{12}$ e $I_{24}$ non hanno nessuna cifra decimale esatta, mentre $I_{30}$ ha una sola cifra decimale. Si ha: $$\begin{align*}
\big|I-I_{12}\big|\approx4.9\cdot10^{-2} \\
\big|I-I_{24}\big|\approx1.2\cdot10^{-2} \\
\big|I-I_{30}\big|\approx7.8\cdot10^{-3} 
\end{align*}$$
## Soluzione punto 3
Usando la forma di Lagrange, si ha $$\begin{align*}
p(0) &= I_{12} \frac{(0-h_{1}^{2})(0-h_{2}^{2})}{(h_{0}^{2}-h_{1}^{2})(h_{0}^{2}-h_{2}^{2})}+ I_{24} \frac{(0-h_{0}^{2})(0-h_{2}^{2})}{(h_{1}^{2}-h_{0}^{2})(h_{1}^{2}-h_{2}^{2})}+ I_{30} \frac{(0-h_{0}^{2})(0-h_{1}^{2})}{(h_{2}^{2}-h_{0}^{2})(h_{2}^{2}-h_{1}^{2})} = \\
&= \frac{h_{1}^{2}h_{2}^{2}}{(h_{0}^{2}-h_{1}^{2})(h_{0}^{2}-h_{2}^{2})}I_{12}+ \frac{h_{0}^{2}h_{2}^{2}}{(h_{1}^{2}-h_{0}^{2})(h_{1}^{2}-h_{2}^{2})}I_{24}+ \frac{h_{0}^{2}h_{1}^{2}}{(h_{2}^{2}-h_{0}^{2})(h_{2}^{2}-h_{1}^{2})}I_{30}=\\
&= \frac{4}{63}I_{12}- \frac{64}{27}I_{24}+ \frac{625}{189}I_{30}=\\
&= 8.3890561002\dots
\end{align*}$$ Confrontando con il valore esatto $I$, si nota che $p(0)$ ha 6 cifre decimali esatte e fornisce quindi un'approssimazione molto migliore rispetto alle singole formule dei trapezi $I_{12},I_{24},I_{30}$. Si ha $$\big|I-p(0)\big|\approx1.3\cdot10^{-9}$$
## Soluzione punto 4
Si ha $\epsilon=\big|I-p(0)\big|\approx1.3\cdot10^{-9}$. Per il teorema, si ha $$\bigg|\int_{0}^{2}xe^{x}\:dx-I_{n}\bigg|= \bigg|- \frac{2^{3}}{12n^{2}}f^{''}(\eta)\bigg|= \frac{2|f^{''}(\eta)|}{3n^{2}} \:\:\: (\eta \in [0,2])$$ Calcoliamo $f^{''}(\eta)$: $$\begin{align*}
f^{'}(x)&= e^{x}+xe^{x}=(1+x)e^{x}\\
f^{''}(x)&= e^{x}+(1+x)e^{x}=(2+x)e^{x}
\end{align*}$$ Per ogni $x\in [0,2]$ si ha $$|f^{''}(x)|=|(2+x)e^{x}|=(2+x)e^{x}\le4e^{x}$$
Dunque $$\bigg|\int_{0}^{2}xe^{x}\:dx-I_{n}\bigg|\le \frac{8e^{2}}{3n^{2}}$$
Poiché $$\frac{8e^{2}}{3n^{2}}\le \epsilon\iff n\ge \sqrt{\frac{8e^{2}}{3n^{2}}}= n(\epsilon)$$ Nel caso $\epsilon=1.3\cdot10^{-9}$, per garantire che $\bigg|\int_{0}^{2}xe^{x}\:dx-I_{n}\bigg|\le \epsilon$ basta prendere un qualsiasi $n\ge n(1.3\cdot 10^{-9})=123113.92\dots$