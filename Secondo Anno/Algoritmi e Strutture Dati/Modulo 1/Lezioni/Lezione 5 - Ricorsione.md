# Metodo della sostituzione
*Idea* : 
1. Indovinare la forma della soluzione;
2. Usare induzione matematica per provare che la soluzione è quella intuita;
3. Risolvere rispetto alle costanti.
>[!alert]- Esempio

$$T(n) = n +T(n/2), T(1)=1$$
Proviamo a dimostrare che la soluzione sia $T(n)\leq c\cdot n$ per una costante $c$ opportuna.
*Passo base* : $T(1)=1\leq c\cdot 1$ per ogni $c\geq 1$
*Passo induttivo*: Assumiamo $T(k)\leq c\cdot k$ per ogni $k\lt n$.
$T(n)=n+T(n/2)\leq n+c(n/2)=(c/2+1)n$ . Quindi, quando $T(n)\leq c\cdot n$?
Devo avere $c/2+1\leq c$ , da cui segue $c\geq 2$. $$T(n)\leq 2n\implies T(n)=O(n)$$
## Esercizi
	Risolvere usando il metodo della sostituzione:
*Esercizio*: $$\begin{align}& T(n)=4T(n/2)+n \\& T(1)=1 \end{align}$$
Ipotizzo $T(n)=O(n^3)$
Proviamo a dimostrare che $T(n)\leq c\cdot n^3$.
*Assumiamo* $T(k)\leq k^3$ per ogni $k\lt n$.
	$$\begin{align} T(n) &=4T(n/2)+n \\&\le 4c(n/2)^3+n\\& = \frac{1}{2}c\cdot n^3+n \\& =\underbrace{c\cdot n^3}_{Goal} - \underbrace{(\frac{1}{2}c\cdot n^3-n)}_{Residuo} \\& \le c\cdot n^3\end{align}$$
*Caso base* : $T(1)=1\le c$. Per esempio : $c\ge 1$
Se $\frac{1}{2}c\cdot n^3-n\ge 0$. Per esempio : $$c\ge 2\implies\begin{align}&T{n}\le 2n^3 \\&T{n}=O(n^3)\end{align}$$ **Altro esempio**: $$\begin{align}& T(n)=4T(n/2)+n \\& T(1)=1 \end{align}$$
Ipotizzo $T(n)=O(n^2)$. Proviamo a dimostrare che $T(n)\le c\cdot n^2$. 
*Assumiamo* $T(k)\leq k^2$ per ogni $k\lt n$.
	$$\begin{align} T(n) &=4T(n/2)+n \\&\le 4c(n/2)^2+n\\& = c\cdot n^2+n \\& \not\le c\cdot n^2\end{align}$$
Come è possibile? Riproviamo.
*Assumiamo*: $T(k)\le c_1k^2-c_2k$ per ogni $k\lt n$.
$$\begin{align}T(n)& =4T(n/2)+n\\&\le4(c_1(n/2)^2-c_2(n/2))+n\\&=c_1n^2-2c_2n+n\\&=\underbrace{c_1n^2-c_2n}_{Goal}-\underbrace{(c_2n-n)}_{Residuo}\\&\le c_1n^2-c_2n\end{align}$$
*Caso base*:$$\begin{align}&T(1)=1\le c_1-c_2\\&\text{Per esempio }c_1=2,c_2=1\end{align}$$
Se $c_2n-n\ge 0$
Per esempio:$$c_2\ge 1\implies\begin{align}&T(n)\le 2n^2-n\\&T(n)=O(n^2) \end{align}$$
# Tecnica del divide et impera
Algoritmi basati sulla tecnica del *divide et impera*:
- - Dividi il problema ( di dimensione *n* )in *a* sottoproblemi di dimensione *n*/*b*;
- - Risolvi i sottoproblemi ricorsivamente;
- - Ricombina le soluzioni.
Sia $f(n)$ il tempo per dividere e ricombinare istanze di dimensione *n*. La relazione di ricorrenza è data da : $$T(n)=\begin{cases}aT(n/b)+f(n)& se\: n\geq1\\\Theta(1)& se\:n=1\end{cases}$$
## Algoritmo Fibonacci6
![[Pasted image 20231017144445.png|center]]
$$a=1,b=2,f(n)=O(1)$$
## Teorema Master

Rimando al seguente link per una spegazione più dettagliata e la dimostrazione:
link: [Teorema Master](https://it.wikipedia.org/wiki/Teorema_principale)

### Enunciato informale
$$n^{log_ba}\:vs\:f(n)$$
Quale va più velocemente a infinito?
Stesso ordine asintotico $T(n)=\Theta(f(n)log(n))$
Se una delle due è "polinomialmente" più veloce, allora T(n) ha l'ordine asintotico della più veloce
### Enunciato formale
$$T(n)=\begin{cases}aT(n/b)+f(n)& se\: n\gt1\\\Theta(1)& se\:n=1\end{cases}$$
Ha soluzione se:
- $T(n)=\Theta(n^{log_ba})$ se $f(n)=O(n^{log_ba-\epsilon})$ per $\epsilon\gt0$
- $T(n)=\Theta(n^{log_ba}\cdot log(n))$ se $f(n)=\Theta(n^{log_ba})$
- $T(n)=\Theta(f(n))$ se $f(n)=\Omega(n^{log_ba+\epsilon})$ per $\epsilon\gt0\:e\:af(n/b)\leq cf(n)\:per\: c\lt 1$ e n sufficientemente grande

**Esempi**
1. $T(n)=n+2T(n/2),a=2,b=2,f(n)=n=\Theta(n^{log_22})$ caso 2 del teorema master e quindi $T(n)=\Theta(nlog(n))$ 
2. $T(n)=c+3T(n/9),a=3,b=9,f(n)=c=O(n^{log_93-\epsilon})$ caso 1 del teorema master e quindi $T(n)=\Theta(\sqrt(n))$
3. $T(n)=n+3T(n/9),a=3,b=9,f(n)=n=\Omega(n^{log_93+\epsilon}),3T(n/9)\leq cn\:per\:c=1/3$ caso 3 del teorema master, es: $\epsilon=0.1$ e quindi $T(n)=\Theta(n)$
4. $T(n)=nlog(n)+2T(n/2), a=2,b=2,f(n)=\omega(n^{log_22})$ ma $f(n)\neq\Omega(n^{log_22+\epsilon}),\forall\epsilon\gt0$
Per l'esempio 4 non si può applicare il teorema master perchè non ci troviamo in nessuno dei 3 casi del teorema, per verificale dovremmo verificare che $nlog(n)=\Omega(n^{1+\epsilon})$
Vediamo: $lim_{n\to\infty}{\frac{nlog(n)}{n^2}}=\frac{log(n)}{n}=0$ e quindi $nlog(n)=\omega(n^{1+\epsilon})$ 
## Cambiamento di variabile
**Esempio**
$T(n)=T(\sqrt(n))+O(1)$

$T(n)=T(n^{1/2})+O(1)$
$n=2^x\implies x=\log_2n$
$T(2^x)=T(2^{x/2})+O(1)\:\:R(x):=T(2^x)$
$R(x)=R(x/2)+O(1)\implies R(x)=O(\log(x))$ e quindi $T(n)=O(\log\:\log(n))$
# Esercizi
## Problema della celebrità
## La torre di Hanoi
