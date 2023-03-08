# Ricorsione, tecniche di progettazione e equazioni di ricorrenza

## Metodo della sostituzione
_Idea_
1. Indovinare la (forma della) soluzione
2. usare induzione matematica per provare che la soluzione è quella intuita
3. risolvi rispetto alle costanti

**Esempio**
$T(n)=n+T(n/2),T(1)=1$

Proviamo a dimostrare che la soluzione sia $T(n)\leq c\cdot n$ per una costante c opportuna
Passo base: $T(1)=1\leq c\cdot 1\:\forall\:c\geq1$
Passo induttivo: assumiamo che $T(k)\leq c\cdot k\:\forall\:k\lt n$
$T(n)=n+T(n/2)\leq n+c(n/2)=(c/2+1)n$

Quindi: quando $T(n)\leq c\cdot n?$
devo avere $c/2+1\leq c\implies c\geq2$
quindi $T(n)\leq 2n\implies T(n)=O(n)$

**Esercizio**
$T(n)=4T(n/2)+n$

**Esempio**
$T(n)=4T(n/2)+n$
ipotizzo: $T(n)=O(n^3)$
proviamo a dimostrare che $T(n)\leq c\cdot n^3$
assumiamo che: $T(k)\leq c\cdot k^3$ Caso base $T(1)=1\leq c$ per esempio $c\geq1$ 

$$T(n)=4T(n/2)+n\leq 4c(n/2)^3+n=\frac{1}{2}cn^3+n=\underbrace{cn^3}_{goal}-\underbrace{(\frac{1}{2}cn^3-n)}_{residuo}\leq cn^3$$
se $\frac{1}{2}cn^3-n\geq0$ 
per esempio $c\geq2\implies T(n)\leq2n^3\implies T(n)=O(n^3)$  

Ipotizzo $T(n)=O(n^2)$
proviamo a dimostrare che $T(n)\leq c\cdot n^2$
assumiamo che: $T(k)\leq c\cdot k^2$ 
$$T(n)=4T(n/2)+n\leq 4c(n/2)^2+n=cn^2+n\not\leq cn^2....$$

Assunzione sbagliata perchè $c\cdot n^2+n\leq n^2$ non è mai verificata, proviamo ad assumere diversamente:
Assumiamo che $T(n)\leq c_1n^2-c_2n$ Caso base $T(1)=1\leq c_1-c_2$ per esempio $c_2=2,c_1=1$
$$T(n)\leq 4(c_1(n/2)^2-c_2(n/2))+n=c_1n^2-2c_2n+n=\underbrace{c_1n^2-c_2n}_{goal}-\underbrace{(c_2n-n)}_{residuo}\leq c_1n^2-c_2n$$
se $c_2n-n\geq 0$
per esempio $c_2\geq 1\implies T(n)\leq 2n^2-n\implies T(n)=O(n^2)$

## Tecnica del divide et impera
Algoritmi basati sulla tecnica del **divide et impera**:
- Dividi il problema (di dimensione n) in a sottoproblemi di dimensione n/b
- risolvi i sottoproblemi ricorsivamente
- ricombina le soluzioni

Sia f(n) il tempo per dividere e ricombinare istanze di dimensione n. La relazione di ricorrenza è data da:
$$T(n)=\begin{cases}aT(n/b)+f(n)& se\: n\geq1\\\Theta(1)& se\:n=1\end{cases}$$
**Esempio** L'algoritmo di fibonacci6, ha come relazione di ricorrenza $T(n)=T(n/2)+c$ e rientra nel teorema master perchè basta prendere $a=1,b=2,f(n)=c$

## Teorema Master

Rimando al seguente link per una spegazione più dettagliata e la dimostrazione:
link: [Teorema Master](https://it.wikipedia.org/wiki/Teorema_principale)

### Enunciato informale

>$n^{log_ba}\:vs\:f(n)$

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
 per l'esempio 4 non si può applicare il teorema master perchè non ci troviamo in nessuno dei 3 casi del teorema, per verificale dovremmo verificare che $nlog(n)=\Omega(n^{1+\epsilon})$
 Vediamo: $lim_{n\to\infty}{\frac{nlog(n)}{n^2}}=\frac{log(n)}{n}=0$ e quindi $nlog(n)=\omega(n^{1+\epsilon})$
 
## Cambiamento di variabile

**Esempio**
$T(n)=T(\sqrt(n))+O(1)$

$T(n)=T(n^{1/2})+O(1)$
$n=2^x\implies x=log_2n$
$T(2^x)=T(2^{x/2})+O(1)\:\:R(x):=T(2^x)$
$R(x)=R(x/2)+O(1)\implies R(x)=O(log(x))$ e quindi $T(n)=O(log\:log(n))$
