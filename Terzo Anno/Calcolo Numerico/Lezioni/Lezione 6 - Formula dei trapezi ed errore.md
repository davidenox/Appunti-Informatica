# Formula dei trapezi
È data una funzione (integrabile) $f:[a,b]\to \mathbb R$ e si vuole calcolare un'approssimazione di $\int_{a}^{b}f(x)dx$. A tal fine si suddivide l'intervallo $[a,b]$ in $n\ge1$ sottointervalli tutti della stessa ampiezza $h= \frac{b-a}{n}$ e si pone $x_j=a+jh$ per ogni $j=0,1,\dots,n$. Il valore che si prende come approssimazione di $\int_{a}^{b}f(x)dx$ è $\int_{a}^{b}s(x)dx$  dove $$s:[a,b]\to \mathbb R
\begin{cases} s(x)=f(x_{j})+\frac{f(x_{j+1})-f(x_j)}{x_{j+1}-x_{j}}(x-x_{j}), \\ \\

\text{per } x\in[x_{j},x_{j+1}],\:\:\:j=0,\dots,n-1
\end{cases}$$ è la funzione lineare a tratti mostrata in figura sotto 
![[Pasted image 20231025154750.png|center|500]]

Quindi il valore che si prende come approssimazione di $\int_{a}^{b}f(x)dx$ è $$I_n=\int_{a}^{b}s(x)dx=\sum_{j=0}^{n-1}\int_{x_{j}}^{x_{j+1}}s(x)dx=\sum_{j=0}^{n-1}\int_{x_{j}}^{x_{j+1}}\left[f(x_{j})+\frac{f(x_{j+1})-f(x_j)}{x_{j+1}-x_{j}}(x-x_{j})\right]dx$$ $$=\sum_{j=0}^{n-1}\left[f(x_{j})(x-x_{j})+\frac{f(x_{j+1})-f(x_j)}{x_{j+1}-x_{j}}\frac{(x-x_{j})^2}{2}\right]_{x_{j}}^{x_{j+1}}$$ $$=\sum_{j=0}^{n-1}\left[f(x_{j})(x_{j+1}-x_{j})+\frac{f(x_{j+1})-f(x_j)}{2}(x_{j+1}-x_{j})\right]$$ $$=\sum_{j=0}^{n-1}\frac{f(x_{j})+f(x_{j+1})}{2}h=\frac{h}{2}\sum_{j=0}^{n-1}\bigg[f(x_{j})+f(x_{j+1})\bigg]$$ $$=\frac{h}{2}\bigg[f(x_{0})+f(x_{1})+f(x_{1})+f(x_{2})+f(x_{2})+f(x_{3})\dots+f(x_{n-1})+f(x_{n})\bigg]$$ $$=h\left[\frac{f(a)+f(b)}{2}+\sum\limits_{j=1}^{n-1}f(x_{j})\right]$$
cioè $$I_n=h\left[\frac{f(a)+f(b)}{2}+\sum\limits_{j=1}^{n-1}f(x_{j})\right]\:\:\: (\star)$$
La $(\star)$ prende il nome di **formula dei trapezi di ordine n**. L'ampiezza $h= \frac{b-a}{n}$ si chiama anche *passo (di discretizzazione) della formula $I_{n}$*.

# Errore o resto della formula dei trapezi
Qual è l'errore che si commette approssimando $\int_{a}^{b}f(x)dx$ con $I_n$? Per rispondere utilizzeremo il seguente lemma.

**Lemma**
Siano $\omega,\alpha,\beta:[a,b]\to \mathbb R$ funzioni tali che: 
- $\omega(x)$ è continua e $\ge 0$ su $[a,b]$
- $\alpha(x)$ e $\beta(x)\omega(x)$ sono continue su $[a,b]$.
- $m\le \beta(x)\le M$ per ogni $x \in [a,b]$, dove $m$ e $M$ sono rispettivamente il minimo e il massimo di $\alpha(x)$ su $[a,b]$.
Allora esiste un punto $\eta \in [a,b]$ tale che $$\int_{a}^{b}\beta(x)\omega(x)dx=\alpha(\eta)\int_{a}^{b}\omega(x)dx$$ Questo lemma è una generalizzazione del teorema della media integrale. Per $\omega(x)=1$ e $\beta(x)=\alpha(x)$ si ottiene infatti il teorema della media integrale.

**Dim.**
Poiché $\omega(x)\ge 0$ su $[a,b]$ e $m\le \beta(x)\le M$ per ogni $x\in[a,b]$, si ha $m\omega(x)\le\beta(x)\omega(x)\le M\omega(x)$ per ogni $x\in[a,b]$ e $$m\int_{a}^{b}\omega(x)dx\le \int_{a}^{b}\beta(x)\omega(x)dx\le M\int_{a}^{b}\omega(x)dx$$
Consideriamo la funzione$z:[a,b]\to \mathbb R$, $$z(y)=\alpha(y)\int_{a}^{b}\omega(x)dx$$
Questa funzione è continua su $[a,b]$ perché $\alpha(y)$ è continua su $[a,b]$. Quindi per il teorema dei valori intermedi $z(y)$ assume su $[a,b]$ tutti i valori compresi tra il suo minimo $m \int_{a}^{b}\omega(x)dx$ e il suo massimo $M \int_{a}^{b}\omega(x)dx$. In particolare $z(y)$ assume il valore $\int_{a}^{b}\beta(x)\omega(x)dx$, ovvero esiste $\eta\in[a,b]$ tale che $$z(\eta)=\int_{a}^{b}\beta(x)\omega(x)dx\:\:\: \square.$$ 

**Teorema**
Sia $f:[a,b]\to \mathbb R$ di classe $C^{2}[a,b]$ e sia $I_{n}$ la formula dei trapezi di ordine $n$ e passo $h= \frac{b-a}{n}$ per approssimare $\int_{a}^{b}f(x)dx$. Allora esiste un punto $\eta\in[a,b]$ tale che $$\int_{a}^{b}f(x)dx-I_{n}=-\frac{(b-a)f^{''}(\eta)}{12}h^{2}$$ ^d9e450

**Dim.**
Poniamo $x_j=a+jh$ per $j=0,\dots,n$ e indichiamo con $s(x)$ la funzione lineare a tratti in [[#^04a94e|figura]]. Osserviamo che $s(x)$ coincide sull'intervallo $[x_j,x_{j+1}]$ con il polinomio (retta) di interpolazione $f(x)$ sui nodi $x_j$ e $x_j+1$. Risulta $$\int_{a}^{b}f(x)dx - I_n=\int_{a}^{b}f(x)dx-\int_{a}^{b}s(x)dx=\int_{a}^{b}\big[f(x)-s(x)\big]dx$$ $$=\sum\limits_{j=0}^{n-1}\int_{x_{j}}^{x_{j+1}}\big[f(x)-s(x)\big]dx$$ $$=\sum\limits_{j=0}^{n-1}\int_{x_{j}}^{x_{j+1}}\frac{f^{''}(\xi_{j}(x))}{2}(x-x_{j})(x-x_{j+1})dx$$
(per il [[Lezione 2 - Errore o resto dell'interpolazione polinomiale#^e77fd4|teorema]] applicato sull'intervallo $[x_{j},x_{j+1}]$; $\xi_{j}(x)$ è un punto in $(x_{j},x_{j+1})$ ) $$=-\sum\limits_{j=0}^{n-1}\int_{x_{j}}^{x_{j+1}}f^{''}(\xi_{j}(x))\frac{(x-x_{j})(x_{j+1}-x)}{2}dx$$ $$=-\sum\limits_{j=0}^{n-1}f^{''}(\eta_{j})\int_{x_{j}}^{x_{j+1}}\frac{(x-x_{j})(x_{j+1}-x)}{2}dx$$
(per il lemma applicato sull'intervallo $[x_j,x_{j+1}]$ con $\alpha(x)=f^{''}(x)$, $\beta(x)=f^{''}(\xi_j(x))$, $\omega(x)=\frac{1}{2}(x-x_{j})(x_{j+1}-x)$; $\eta_j$ è un punto in $[x_j,x_{j+1}]$ )
$$=-\sum\limits_{j=0}^{n-1}f^{''}(\eta_{j})\int_{0}^{h}\frac{t(h-t)}{2}dt$$ (cambio di variabile $t=x-x_{j}\iff x=t+x_{j}$ e si ha $dt=dx$ )
$$=-\sum\limits_{j=0}^{n-1}f^{''}(\eta_{j}) \frac{1}{2}\bigg[\frac{h}{2}t^{2}- \frac{1}{3}t^{3}\bigg]=-\sum\limits_{j=0}^{n-1}f^{''}(\eta_{j}) \frac{h^{3}}{12}=-\frac{h^3n}{12}\cdot\frac{1}{n}\sum\limits_{j=0}^{n-1}f^{''}(\eta_j)=-\frac{h^2(b-a)}{12}f^{''}(\eta)$$
dove l'ultima uguaglianza vale perché, essendo $f^{''}(x)$ continua su $[a,b]$ per ipotesi ed essendo la media aritmetica $\frac{1}{n}\sum\limits_{j=0}^{n-1}f^{''}(\eta_{j})$ un valore compreso tra il minimo e il massimo di $f^{''}(x)$ su $[a,b]$, per il teorema dei valori inermedi esiste sicuramente un $\eta\in [a,b]$ tale che $f^{''}(\eta)= \frac{1}{n}\sum\limits_{j=0}^{n-1}f^{''}(\eta_{j})\:\:\:\square.$ 


# Esericzi

## Esempio 1
- Calcolare l'approssimazione di $\int_{0}^{1}\sqrt{\cos x}\:dx$ con $I_{10}$
- Stimare l'errore $\bigg|\int_{0}^{1}\sqrt{\cos x}\:dx-I_{10}\bigg|$ 

**Soluzione**
Applichiamo la formula di $I_{n}$ con $n=10$, $h= \frac{1-0}{10}= \frac{1}{10}$, $f(x)=\sqrt{\cos x}$, $x_{j}= \frac{j}{10}$, $j=0,\dots,10$, per cui $$I_{10}= \frac{1}{10}\left[\frac{\sqrt{\cos 0}+\sqrt{\cos 1}}{2}+\sum\limits_{j=1}^{9}\sqrt{\cos \frac{j}{10}}\right]$$ $$=\frac{1}{10}\left[\frac{1+\sqrt{\cos 1}}{2}+\sqrt{\cos \frac{1}{10}}+\sqrt{\cos \frac{2}{10}}+\dots+\sqrt{\cos \frac{9}{10}}\right]$$ $$=0.9135078\dots$$
Per il secondo punto abbiamo che $f(x)=\sqrt{\cos x}$ è $C^{\infty}[0,1]$ perché è la composizione di $\cos x:[0,1]\to[\cos 1,1]$ e $\sqrt{y}:[\cos1,1]\to \mathbb R$ ed entrambe le funzioni sono $C^{\infty}$ sui rispettivi domini. Di conseguenza per il [[#^d9e450|teorema]] abbiamo che $$(\star)\:\:\int_{0}^{1}\sqrt{\cos x}\:dx-I_{10}=\frac{-f^{''}(\eta)}{12}\left(\frac{1}{10}\right)^{2}=\frac{-f^{''}(\eta)}{1200}\:\:\:(\eta\in[0,1])$$
Calcoliamo $f^{''}(x)$:
 $$f^{'}(x)=\frac{-\sin x}{2\sqrt{\cos x}}$$ $$\begin{align}f^{''}(x)&=\frac{-\cos x2\sqrt{\cos x}-(-\sin x)\cancel2\frac{-\sin x}{\cancel2\sqrt{\cos x}}}{4\cos x}= \\
 &=- \frac{1}{2}\sqrt{\cos x}-\frac{\sin^{2}x}{4(\cos x)^{\frac{3}{2}}}
 \end{align}$$
 Per ogni $x\in[0,1]$ si ha $$|f^{''}(x)|\le \frac{1}{2}\sqrt{\cos x}+\frac{sin^{2}x}{4(\cos x)^{\frac{3}{2}}}\le \frac{1}{2}+\frac{\sin^{2}1}{4(\cos 1)^{\frac{3}{2}}}\le0.9458$$ 
 Tornando a $(\star)$ si ha $$\left|\int_{0}^{1}\sqrt{\cos x}\:dx-I_{10}\right|=\frac{\big|f^{''}(\eta)\big|}{1200}\le\frac{0.9458}{1200}=0.000788$$ 
## Esempio 2
Fissato $\epsilon=10^{-8}$, determinare un $n$ tale che la formula $I_{n}$fornisca un'approssimazione di $\int_{0}^{1}\sqrt{\cos x}\:dx$ con errore $\bigg|\int_{0}^{1}\sqrt{\cos x}\:dx-I_{n}\bigg|\le \epsilon$ .

**Soluzione**
Per il teorema sull'errore della formula dei trapezi si ha $$\bigg|\int_{0}^{1}\sqrt{\cos x}\:dx-I_{n}\bigg|=\left|-\frac{f^{''}(\eta)}{12}\left(\frac{1}{n}\right)^{2}\right|=\frac{\big|f^{''}(\eta)\big|}{12n^{2}}\:\:\:(\eta\in[0,1])$$ 
Nell'[[#Esempio 1|esempio precedente]] abbiamo che $|f^{''}(x)|\le0.9458$ per ogni $x\in[0,1]$ e quindi risulta $$\left|\int_{0}^{1}\sqrt{\cos x}\: dx-I_{n}\right|\le \frac{1}{12n^{2}}$$
Poiché $$\frac{1}{12n^{2}}\le\epsilon\iff n\ge \sqrt{\frac{1}{12\epsilon}}=n(\epsilon)$$ si ha $$\left|\int_{0}^{1}\sqrt{\cos x}\: dx-I_{n}\right|\le\epsilon\:\:\:\: \forall n\ge n(\epsilon)$$ Nel nostro caso abbiamo $\epsilon=10^{-8}$ e quindi per garantire che $\left|\int_{0}^{1}\sqrt{\cos x}\: dx-I_{n}\right|\le10^{-8}$, basta prendere un qualsiasi $n \le n(10^{-8})=2886.75\dots$

## Esempio 3
Fissato $\epsilon > 0$, determinare un $n$ tale $I_n$ fornisca un'approssimazione di $\left|\int_{0}^{1}\frac{x+2}{\log(x+2)}\:dx-I_{n}\right|\le \epsilon$. Quanto vale $n$ se $\epsilon=10^{-8}$?

**Soluzione**
Posto $f(x)=\frac{x+2}{\log(x+2)}$, si ha $$\left|\int_{0}^{1}\frac{x+2}{\log(x+2)}\:\: dx-I_{n}\right|=\left|- \frac{1}{12n^{2}}f^{''}(\eta)\right|=\frac{f^{''}(\eta)}{12n^{2}}\:\:\:(\eta\in[0,1])$$ Calcoliamo $f^{''}(x)$:$$\begin{align}f^{'}(x)&=\frac{\log(x+2)-(x+2)\frac{1}{x+2}}{\log^{2}(x+2)}=\frac{\log(x+2)-1}{\log^2(x+2)}\\
f^{''}(x)&=\frac{\frac{1}{x+2}\log^{2}(x+2)-(\log(x+2)-1)2\log(x+2)\frac{1}{x+2}}{\log^{4}(x+2)}=\frac{2-\log(x+2)}{(x+2)\log^{3}(x+2)}\end{align}$$
Per ogni $x\in[0,1]$ si ha $$\big|f^{''}(x)\big|=\left|\frac{2-\log(x+2)}{(x+2)\log^{3}(x+2)}\right|=\frac{2-\log(x+2)}{(x+2)\log^{3}(x+2)}\le \frac{2-\log2}{2\log^{3}2}\le1.97$$
Dunque $$\left|\int_{0}^{1}\frac{x+2}{\log(x+2)}\:dx-I_{n}\right|\le \frac{1.97}{12n^{2}}$$
Poiché $$\frac{1.97}{12n^{2}}\le\epsilon\iff n\ge\sqrt{\frac{1.97}{12\epsilon}}=n(\epsilon)$$
Nel caso $\epsilon=10^{-8}$, per garantire che $\left|\int_{0}^{1}\frac{x+2}{\log(x+2)}\:dx-I_{n}\right|\le 10^{-8}$ basta prendere un qualsiasi $n\ge n(10^{-8})=4051.74$.