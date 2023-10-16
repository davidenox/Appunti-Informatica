# Esercizio
Analizzare la complessità nel casi medio del primo algoritmo di pesatura (*Alg1*) presentato nella prima lezione. Rispetto alla distribuzione di probabilità sulle istanze, si assuma che la moneta falsa possa trovarsi in modo equiprobabile in una qualsiasi delle $n$ posizioni
$Alg1(X=\{x_1, x_2, ..., x_n\})$ 
1. *for* i = 2 *to* n do
2.      *if* $peso(x_1)\gt peso(x_i)$ *then return* $x_1$
3.      *if* $peso(x_1)\lt peso(x_i)$ *then return* $x_i$
![[Pasted image 20231012141152.png|center]]
## Un problema simile: ricerca di un elemento in un array / lista non ordinata
L'algoritmo torna la posizione *x* in *L* se *x* è presente, $-1$ altrimenti
``` Pseudo-codice
algoritmo RicercaSequenziale( array L, elem x) -> intero
1. n = lunghezza di L
2. i = 1
3. for i=1 to n do
4.      if( L[i] = x )then return i \\trovato
5. return -1 \\non trovato
```
T(n) = # elementi acceduti ( Linea 4) su un array di dimensione *n*.
$T_{worst}(n) = n$                 $x\not\in L$ oppure è in ultima posizione
T(n) = # operazioni RAM su un array di dimensione *n*.
$T_{worst}(n) = \Theta (n)$            $x\not\in L$ oppure è in ultima posizione.
$T_{avg}(n)=\Theta (n)$    assumendo che $x\in L$ e che si trovi con la stessa probabilità in qualsiasi posizione.
## Una variante: ricerca di un elemento in un array ordinato
Algoritmo di *ricerca binaria*, uno strumento molto potente. Gli inidici $i$ e $j$ indicano la porzione di $L$ in cui cercare l'elemento $x$. L'algoritmo torna in posizione di $x$ in $L$, se $x$ c'è, $-1$ altrimenti.
```Pseudo-codice
algoritmo RicercaBinariaRic(array L, elem x, int i, int j) --> intero
1. if (i>j) then return -1
2. m= [(i+j)/2]
3. if (L[m]=x) then return m
4. if (L[m]>x) then return RicercaBinariaRic(L, x, i, m-1)
5.     else return RicercaBinariaRic(L, x, m+1,j)
```
$$T(n)=T(n/2)+O(1)\implies T(n) = O(\log(n))$$
>[!info]- Esempio

![[Pasted image 20231012142637.png|center|500]]
# Ricorsione, tecniche di progettazione e equazioni di ricorrenza
**Sommario**
- - *Algoritmi ricorsivi* : come analizzarli?
- - *Complessità* di algoritmi ricorsivi ed *equazioni di ricorrenza*.
- - Una tecnica di progettazione algoritmica : *divide et impera*.
- - Metodi per risolvere equazioni di ricorrenza:
- 1. Iterazione
- 2. Albero della ricorsione
- 3. Sostituzione
- 4. Teorema Master
- 5. Cambiamento di variabile
## Algoritmi ricorsivi : come analizzarli?
```Pseudo-codice
algoritmo fibonacci2(intero n) -> intero
	if(n <= 2) then return 1
	else return fibonacci2(n-1) + fibonacci2(n-2)
```
$$T(n)=T(n-1)+T(n-2)+O(1)$$
## Equazioni di ricorrenza
La *complessità computazionale* di un algoritmo ricorsivo può essere espressa in modo naturale attraverso una *equazione di ricorrenza*
>[!info]- Esempio
>![[Pasted image 20231012143832.png|center]]

## Metodo dell'iterazione
*Idea*: "srotolare" la ricorsione, ottenendo una sommatoria dipendente solo dalla dimensione $n$ del problema iniziale.
*Esempio*:
$$\begin{align} T(n) &= c + T(n/2)  \\&=2c + T(n/4) \\& = 2c + c + T(n/8) \\&=3c+T(n/8)\\&...\\&=ic+T(n/2^i) \end{align}$$
Per $i=\log_2(n): T(n)=c\log_2(n)+T(1)=\Theta(\log(n))$ 

*Esempio*: $T(n)=T(n-1)+1$
$$\begin{align} T(n) &= T(n-1)+1  \\&=T(n-2)+1+1 \\& = T(n-2)+2\\&=T(n-3)+1+2 \\&=T(n-3)+3\\&...\\&=T(n-i)+i \end{align}$$
Per $i = n-1:T(n) = T(1)+(n-1)=\Theta(n)$
*Altri esempi...*
## Analisi dell'albero della ricorsione
	Un modo grafico di pensare il metodo dell'iterazione
*Idea*: 
- - Disegnare l'albero delle chiamate ricorsive indicando la dimensione di ogni nodo;
- - Stimare il tempo speso da ogni nodo dell'albero;
- - Stimare il tempo complessivo "sommando" il tempo speso da ogni nodo.
*Sugg. 1*
	Se il tempo speso da ogni nodo è costante, T(n) è proporzionale al numero di nodi.
*Sugg. 2* 
	A volte conviene analizzare l'albero per livelli:
	- Analizzare il tempo speso su ogni livello ( fornendo upper bound );
	- Stimare il numero di livelli
**Esempio**
$T(n)=T(n-1)+1$

![[Pasted image 20221016160539.png|center]]
Quanto costa ogni nodo? ...uno!
Quanti nodi ha l'albero? **n**
Di conseguenza possiamo dire che $T(n)=\Theta(n)$

**Esempio**
$T(n)=T(n-1)+n$

![[Pasted image 20221016160737.png|center]]

Quanto costa ogni nodo? **...al più n**
Quanti nodi ha l'albero? **n**

Quindi possiamo dedurre che $T(n)=O(n^2)$
Ma vale $T(n)=\Theta(n^2)$?

![[Pasted image 20221016161024.png|center]]

Come possiamo vedere dalla foto, il lower bound è $T(n)\geq n/2n/2=n^2/4$ e quindi $T(n)=\Omega(n^2)$
Di conseguenza dato che T(n) è sia $O(n^2)(upper\:bound)\:che\:\Omega(n^2)(lower\:bound)\implies T(n)=\Theta(n^2)$ 
**Altro esempio**: 
![[Pasted image 20231012150921.png|center]]
**Generalizzazione ad n**
![[Pasted image 20231012151028.png|center]]

### Altri esempi
>[!danger]- Esempio 

$T(n)=T(n-1)+T(n-2)+1$
$T(1)=1$
*Un'idea* : Usare maggiorazioni per fornire un upper bound.
$T(n)\leq R(n), \space R(n)=2R(n-1)+1\implies T(n)=O(2^n)\implies R(n)=\Theta(2^n)$, vale $T(n)=\Theta(2^n)$? 
![[Pasted image 20231012151849.png|center]]

### Due esempi
Esempio 1: $$\begin{align} & T(n)=T(n/3)+T(2n/3)+n, \\& T(1)= 1 \end{align}$$Esempio 2: $$\begin{align} & T(n)=2T(n-2)+1, \\& T(1)= 1 \end{align}$$
#### Esempio 1
![[Pasted image 20231012152317.png|center]]
$$\Downarrow$$
![[Pasted image 20231012152330.png|center]]
