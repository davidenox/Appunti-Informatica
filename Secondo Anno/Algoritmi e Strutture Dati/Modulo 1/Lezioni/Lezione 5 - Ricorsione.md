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
