# Errore (resto) dell'interpolazione polinomiale

>[!important]-  Teorema
>Sia $f:[a,b]\to\mathbb R$ di classe $C^{n+1}[a,b]$ e sia $p(x)$ il polinomio di interpolazione di $f(x)$ sugli n+1 nodi distinti $x_0,x_1,\dots,x_n\in[a,b]$
>Allora 
>$$\begin{align}&\forall x\in[a,b]\exists\xi=\xi(x)\in[a,b] :\\(X)\space &f(x)-p(x) = \frac{f^{n+1}(\xi)}{(n+1)!}\cdot(x-x_0)(x-x_1)\dots(x-x_n)\end{align}$$

**Dimostrazione**

Sia $x\in[a,b]$ fissato

1) se x coincide con uno dei nodi $x_i$ allora $(X)$ è soddisfata con un qualsiase $\xi\in(a,b)$, perchè entrambi i memebri vengono uguali a 0
2) Supponiamo che x non coincida con nessuno dei nodi $x_i$

Siamo nel caso 2)

Definiamo $\pi(y) = (y-x_0)(y-x_1)\dots(y-x_n)$ e $r(y) = f(y)-p(y)$

Definiamo $z:[a,b]\to\mathbb R,z(y) = r(y)-\underbrace{\frac{r(x)}{\pi(x)}}_{\text{costante}}\pi(y)$
La funzione $z(y)$ è di classe $C^{n+1}[a,b]$ come somma/diff. di funzioni $f(y),p(y),\pi(y)$, tutte di classe $C^{n+1}[a,b]$ ($p(y),\pi(y)$ addirittura di classe $C^\infty[a,b]$)

Inoltre, la funzione z si annulla in almeno n+2 punti, perchè si annulla in tutti i nodi $x_0,\dots,x_n$ e anche nel punto x

>[!tip]- Osservazione
>$z(x_i)= r(x_i)-\frac{r(x)}{\pi(x)}\cdot\pi(x_i)= \underbrace{f(x_i)-p(x_i)}_{=0}-\frac{r(x)}{\pi(x)}\cdot\underbrace{\pi(x_i)}_{=0}\implies z(x) = \cancel{r(x)}-\cancel{\frac{r(x)}{\pi(x)}}\cdot\cancel{\pi(x)} = 0$

**Passaggio cruciale della dimostrazione**

Per il teorema di Rolle :

$z'(y)$ si annulla in almeno n+1 punti di $(a,b)$
$z''(y)$ si annulla in almeno n punti di $(a,b)$
$z'''(y)$ si annulla in almeno n-1 punti di $(a,b)$
...
$z^{n+1}(y)$ si annulla in almeno 1 punti di $(a,b)\to$ chiamo questo punto $\xi$

Mostriamo che il punto $\xi$ è quello che fa valere la formula $(X)$

$$\begin{align}&z(y)=r(y)-\frac{r(x)}{\pi(x)}\cdot\pi(y)\\&r(y)=f(y)-\underbrace{p(y)}_{\in\mathbb R_n[y]}\\&\underbrace{\pi(y)=(y-x_0)(y-x_1)\dots(y-x_n)}_{=y^{n+1}\cdot \underbrace{q(y)}_{\in\mathbb R_n[y]}}\end{align}$$

Quindi

$$\begin{align}z^{n+1}(y)&=r^{n+1}(y)-\frac{r(x)}{\pi(x)}\pi^{n+1}(y)\\&=f^{n+1}(y)-\cancel{p^{n+1}(y)}_{=0}-\frac{r(x)}{\pi(x)}\cdot(n+1)!\\&=f^{n+1}(y)-\frac{r(x)}{\pi(x)}\cdot(n+1)!\end{align}$$

$z^{n+1}(y)$ si annulla in $\xi$, quindi posso scrivere 
$$\begin{align}0=&z^{n+1}(\xi)=f^{n+1}(\xi)-\frac{r(x)}{\pi(x)}\cdot(n+1)!\\&\implies\frac{r(x)}{\pi(x)}\cdot(n+1)!=f^{n+1}(\xi)\\&\implies r(x)=\frac{f^{n+1}(\xi)}{(n+1)!}\cdot\pi(x)\end{align}$$
Che è proprio $(X)$ quindi $\square$

## Esempio 1

Fissiamo un punto $t\in [0,1]$. Stimare l'errore che si commette approssimando $\sin(t)$ con $p(t)$, dove $p(x)$ è il polinomio di interpolazione di $\sin(x)$ sui nodi $x_{0}=0, x_{1}=\frac{\pi}{6}, x_{2}=\frac{\pi}{4}$

**Soluzione**
Applichiamo il teorema con $f(x)=\sin(x)\in C^{\infty}(\mathbb R)$ e $n=2$ e $[a,b]=[0,1]=$ il più piccolo intervallo che contiene i nodi $x_0,x_1,x_2$ e il punto $t$. Per il teorema: $$\left|\sin(t)-p(t)\right|=\left|\frac{f^{'''}}{3!}(t-x_{0})(t-x_{1})(t-x_{2})\right|\:\:\: (\xi \in (0,1))$$ $$=\left|-\frac{\cos(\xi)}{6}t(t- \frac{\pi}{6})(t- \frac{\pi}{4})\right|$$ $$=\frac{\left|\cos(\xi)\right|}{6}|t|\left|t- \frac{\pi}{6}\right|\left|t- \frac{\pi}{4}\right|$$ $$\leq \frac{1}{6}\cdot1\cdot \frac{\pi}{6}\cdot \frac{\pi}{4} \approx0.0685$$
Volendo ottenere una stima più precisa si può procedere come segue $$\left|\sin(t)-p(t)\right|=\left|\frac{f^{'''}(\xi)}{3!}(t-x_{0})(t-x_{1})(t-x_{2})\right|\:\:\: (\xi \in (0,1))$$ $$=\left|-\frac{\cos(\xi)}{6}t(t- \frac{\pi}{6})(t- \frac{\pi}{4})\right|$$ $$=\frac{\left|\cos(\xi)\right|}{6}\left|t\left(t- \frac{\pi}{6}\right)\left(t- \frac{\pi}{4}\right)\right|$$ $$\leq \frac{1}{6} \max_{y\in[0,1]}\left|\underbrace{y\left(y- \frac{\pi}{6}\right)\left(\frac{y- \pi}{4}\right)}_{\omega(x)}\right|\:\:\: (\$)$$
Andiamo a calcolare il massimo di $|\omega(x)|$ su $[0,1]$.
Per farlo dobbiamo cercare tutti **i massimi e i minimi relativi** di $\omega(y)$ su $[0,1]$ e prendere il più grande di essi in modulo.
Per un teorema dell'analisi matematica, i massimi e i minimi relativi di $\omega(y)$ su $[0,1]$ si trovano o nei punti di bordo di $[0,1]$ o nei punti stazionari di $\omega(y)$ in $[0,1]$, cioè i punti di $[0,1]$ in cui si annulla $\omega^{'}(y)$.
$$\omega(y)=y^{3}-\left(\frac{5\pi}{12}\right)y^{2}+\left(\frac{\pi^{2}}{24}\right)y\:\:\:\: \text{(ho svolto i prodotti)}$$
da cui $$\omega^{'}(y)=3y^{2}- \frac{5\pi}{6}y+ \frac{\pi^{2}}{24}$$ ora calcoliamo $$w^{'}(y)=0 \iff 3y^{2}- \frac{5\pi}{6}y+ \frac{\pi^{2}}{24}=0\iff y=\frac{\frac{5\pi}{6}\pm\sqrt{\frac{25\pi^{2}}{36}- \frac{\pi^{2}}{2}}}{6}$$
svolgendo i calcoli risulta $$y_{1}=\frac{\pi(5+\sqrt7)}{36}$$$$y_2=\frac{\pi(5-\sqrt7)}{36}$$
$y_{1},y_{2}\in [0,1]\implies$ $y_{1},y_{2}$ sono punti stazionari du $\omega(y)$ in $[0,1]$. 
Risulta quindi che $$\max_{y\in[0,1]}|\omega(y)|=\max(|\omega(0)|,\:|\omega(1)|,\:|\omega(y_{1})|,\:|\omega(y_{2})|)$$$$=\max(0,\:\underline{0.10223},\:0.01132,\:0.03790)\leq 0.103$$
In base a $(\$)$ $$|\sin(t)-p(t)|\leq \frac{1}{6}\cdot0.103\approx0.0172$$
**Oss.**
1. Per ottenere le stime dell'errore di interpolazione non serve conoscere il polinomio di interpolazione $p(x)$.
2. La stima più precisa diventa più difficile se ci sono più di 3 nodi, perché in tal caso $\omega(y)$ è un polinomio di grado $>3$ dunque $\omega^{'}(y)$ è un polinomio di grado $>2$  e dunque risolvere l'equazione $\omega^{'}(y)=0$ risulta complicato.
## Esempio 2

Sia $f(x)=e^{x^{2}}$ e sia $p(x)$ il polinomio di interpolazione sui nodi $x_{0}=0, x_{1}=\frac{1}{2}, x_{2}=1$.
1. Fornire una stima dell'errore d'interpolazione $|f(x)-p(x)|\:\: \forall\:x\in[0,1]$, cioè trovare C costante t.c. $|f(x)-p(x)|\le C\:\: \forall\:x\in[0,1]$
2. Stimare l'errore che si commette approssimando $\sqrt[9]{e}$ con $p(\frac{1}{3})$ senza calcolare ne' $\sqrt[9]{e}$ ne' $p(\frac{1}{3})$.

**Soluzione**
1. Applichiamo il teorema sul resto dell'interpolazione con 
- $f(x)=e^{x^{2}}$
- $[a,b]=[0,1]$
- $n=2$
$\forall \: x \in[0,1]$
$$\left|f(x)-p(x)\right|=\left|\frac{f^{'''}(\xi)}{3!}x(x- \frac{1}{2})(x-1)\right|\:\:\: (\xi \in (0,1))\:\:\: (\texteuro) $$ Calcoliamo 
- $f^{'}(x)=2xe^{x^{2}}$ 
- $f^{''}(x)=2xe^{x^{2}}+4x^{2}e^{x^{2}}=(2+4x^{2})e^{x^{2}}$ 
- $f^{'''}(x)=8xe^{x^{2}}+(2+4x^{2})2xe^{x^{2}}=e^{x^{2}}(12x+8x^{3})$

$\forall\: x \in [0,1]$ $$|f^{'''}(x)|=|e^{x^{2}}(12x+8x^{3})|=\underbrace{e^{x^{2}}}_{\le1}\underbrace{(12x+8x^{3})}_{\le20}\le20e$$
Tornando a $(\texteuro)$ ho
$$\left|f(x)-p(x)\right|=\left|\frac{f^{'''}(\xi)}{3!}x(x- \frac{1}{2})(x-1)\right|\:\:\: (\xi \in (0,1))$$$$=\frac{|f^{'''}(\xi)|}{3!}|x|\left|x- \frac{1}{2}\right||x-1|\le \frac{20e}{6} \max_{y\in[0,1]}\left|y\left(y- \frac{1}{2}\right)(y-1)\right| \:\:\: (£)$$
Dobbiamo trovare i massimi  i minimi relativi di $\omega(y)$ su $[0,1]$.
$$\omega(y)=y^{3}- \frac{3}{2}y^{2}+ \frac{1}{2}y$$ 
$$\omega^{'}(y)=3y^{2}-3y+ \frac{1}{2}=0 \iff y=\frac{3\pm\sqrt{9-6}}{6}=\frac{3\pm\sqrt{3}}{6}$$

da cui 
- $y_{1}=\frac{3+\sqrt3}{6}$
- $y_{2}=\frac{3-\sqrt3}{6}$

Risulta quindi che $$\max_{y\in[0,1]} |\omega(y)|=\max\left(|\omega(0)|,\: |\omega(1)|,\:\left|\omega\left(\frac{3+\sqrt3}{6}\right)\right|,\:\left|\omega\left(\frac{3-\sqrt3}{6}\right)\right|\right)$$ $$=\max(0,\:0,\: \frac{\sqrt3}{36},\frac{\:\sqrt3}{36})=\frac{\sqrt3}{36} $$
Tornando a $(£)$, $\forall x \in [0,1]$ si ha: 

$$|f(x)-p(x)|\le \frac{20e}{6}\cdot \frac{\sqrt3}{6}\approx 0.436$$ 
2. Dal risultato sopra scegliendo $x=\frac{4}{3}\in [0,1]$ si ha $$\left|\underbrace{f\left(\frac{1}{3}\right)-p\left(\frac{1}{3}\right)}_{\sqrt[9]e-p(\frac{1}{3})}\right|\le\frac{20e}{6}\cdot \frac{\sqrt3}{6}\approx 0.436$$ Volendo ottenere una stima più precisa applico il teorema del resto dell'interpolazione con $x=\frac{1}{3}$ $$\left|f\left(\frac{1}{3}\right)-p\left(\frac{1}{3}\right)\right|=\left|\frac{f^{'''}(\xi)}{6}\left(\frac{1}{3}-0\right)\left(\frac{\frac{1}{3}-1}{2}\right)\left(\frac{1}{3}-1\right)\right|\le \frac{20e}{6}\frac{1}{3}\frac{1}{6}\frac{2}{3}\approx 0.336$$