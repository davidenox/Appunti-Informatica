# String Similarity
**Q**: Quanto sono simili due stringhe?
Es. "ocurrance" vs. "occurrence"
![[Pasted image 20250403114856.png|center|500]]
## Edit Distance
**Edit distance**:
- Gap penalty = $\delta$, Mismatch penalty $\alpha_{pq}$.
- Costo = somma degli errori di gap e mismatch
![[Pasted image 20250403121123.png|center|500]]

Es. 
Qual è la distanza tra queste due stringhe?$$\texttt{ PALETTE }\texttt{ PALATE }$$
Assumiamo che il gap penalty sia 2 ed il mismatch penalty sia 1
![[Pasted image 20250403121321.png|center|500]]

# Sequence Alignment

**Goal**: Date due stringhe $x_1,...,x_m$ e $y_1,...,y_n$, trovare un *allineamento* di costo minimo.

>**Def**. Un **allineamento** $M$ è un insieme di coppie ordinate $x_i-y_j$ in modo che ogni carattere appare in al più una coppia e non ci sia un incrocio.

>[!important] Il **costo** di un allineamento $M$ è:$$cost(M)=\sum_{(x_i,y_j)\in M}\alpha_{x_iy_i}+\sum_{i:x_i\text{ unmatched}}\delta +\sum_{j:y_j\text{ unmatched}}\delta$$
>- La prima sommatoria rappresenta il mismatch, la somma delle altre due il gap

![[Pasted image 20250403122025.png|center|400]]

## Struttura del problema
**Def**. $OPT(i,j)$= il costo minimo per allineare delle stringhe prefissate $x_1,...,x_i$ e $y_1,...,y_j$.
**Goal**: $OPT(m,n)$.

> **Caso 1**. $OPT(i,j)$ combacia con $x_i-y_j$.
> - Costo di mismatch per $x_i-y_j+$ il minimo costo di allineamento $x_1,...,x_{i-1}$ e $y_1,...y_{j-1}$

>**Caso 2a**. $OPT(i,j)$ lascia $x_i$ non combaciato.
>- Costo di gap per $x_i+$ il minimo costo di allinamento $x_1,...,x_{i-1}$ e $y_1,...,y_j$.

>**Caso 2b**. $OPT(i,j)$ lascia $y_i$ non combaciato.
>- Costo di gap per $y_i+$ il minimo costo di allineamento $x_1,...,x_i$ e $y_1,...y_{j-1}$.

**Equazione di Bellman** $$OPT(i,j)=\begin{cases}
j\omega &se\space i=0\\
i\omega &se\space j=0\\
\min\begin{cases}
\alpha_{x_iy_j}+OPT(i-1,j-1)\\
\omega + OPT(i-1,j)& altrimenti\\
\omega + OPT(i,j-1)
\end{cases}
\end{cases}$$
## Algoritmo Bottom-Up

```pseudo
SEQUENCE-ALIGNMENT(m,n,x1,...,xm,y1,...,yn,δ,α)
	FOR i=0 TO m  
		M[i,0]←iδ.

	FOR j=0 TO n  
		M[0,j]←jδ.
		
	FOR i=1 TO m  
		FOR j=1 TO n  
			M[i, j] \leftarrow \min \{ \alpha_{x_i y_j} + M[i-1, j-1],
			\delta + M[i-1, j],
			\delta + M[i, j-1] \}.
			(già computate tutte e tre)
RETURN M[m,n].
```

## Traceback
![[Pasted image 20250403151940.png|center|500]]
### Analisi
>[!important] **Th**. L'algoritmo computa l'edit distance (ed un allineamento ottimale) di due stringhe di lunghezza $m$ ed $n$ in tempo e spazio$\Theta(m\cdot n)$.
>**Dim**.
>- L'algoritmo computa l'edit distance;
>- Può risalire all'estrazione dell'allineamento ottimale stesso.$_\square$

**Possiamo migliorare lo spazio usato dall'algoritmo?**
# Algoritmo di Hirschberg
## Sequence Alignment in spazio lineare
>[!important] **Th**. Hirschberg
>Esiste un algoritmo per trovare un allineamento ottimale in tempo $O(m\cdot n)$ e spazio $O(m+n)$.
>- Combinazione intelligente di programmazione dinamica e tecnica di divide et impera.

![[Pasted image 20250403152928.png|center|500]]
- Per computare la prossima colonna/riga della matrice abbiamo bisogno solo della colonna/riga precedente
- $\implies$ basta mantenere due colonne/righe alla volta
- $\implies$ Spazio $O(m+n)$
*Da notare*: Ciò permette di computare l'edit distance ma non l'alignment

**Grafo edit distance**
- Sia $f(i,j)$ la lunghezza dello shortest path da $(0,0)$ a $(i,j)$.
- *Lemma*: $f(i,j)=OPT(i,j)$ per tutti gli $i$ e $j$.
![[Pasted image 20250403154732.png|center|500]]
**Dimostrazione del Lemma** (tramite induzione forte su i + j )

- Caso base : $f ( 0 , 0 ) = O P T ( 0 , 0 ) = 0$
- Ipotesti induttiva : Assumi che è vera $∀ ( i ′ , j ′ )$ con $i ′ + j ′ < i + j$
- L'ultimo arco dello shortest path $→ ( i , j )$ viene da $( i − 1 , j − 1 ) , ( i − 1 , j )$ oppure $( i , j − 1 )$
- Quindi, abbiamo che $$\begin{align}f(i,j)&=\min{\alpha_{x_iy_j}+f(i-1,j-1),\delta+f(i-1,j),\delta+f(i,j-1)}\&=\underbrace{\min{\alpha_{x_iy_j}+OPT(i-1,j-1),\delta+OPT(i-1,j),\delta+OPT(i,j-1)}}_{\text{Ipotesi induttica}}\&=\underbrace{OPT(i,j)}_{\text{Equazione di Bellman}}\square\end{align}$$
![[Pasted image 20250403155039.png|center|300]]

Si può calcolare $f ( ⋆ , j )$ per ogni $j$ in tempo $O ( m n )$ e spazio $O ( m + n )$.
![[Pasted image 20250403155128.png|center|500]]
- Sia $g(i,j)$ la lunghezza dello shortest path da $(i,j)$ a $(m,n)$.
![[Pasted image 20250403160233.png|center|500]]
- Si può computare $g(i,j)$ invertendo gli orientamenti degli archi ed i ruoli di $(0,0)$ e $(m,n)$.
![[Pasted image 20250403160357.png|center|500]]
- Si può computare $g(\cdot,j)$ per ogni $j$ in tempo $O(mn)$ e spazio $O(m+n)$.
![[Pasted image 20250403162608.png|center|500]]
*Oss*: La lunghezza di un shortest path che usa $(i,j)$ è $f(i,j)+g(i,j)$.
![[Pasted image 20250403163442.png|center|500]]
*Oss*: Sia $q$ un indice che minimizza $f(q,n/2)+g(q,n/2)$. Allora, esiste uno shortest path da $(0,0)$ a $(m,n)$ che usa $(q,n/2)$.
![[Pasted image 20250403163621.png|center|500]]

>[!important] 
>**Divide**: Trova l'indice $q$ che minimizza $f(q,n/2)+g(q,n/2)$; salva il  nodo $i-j$ come parte della soluzione.
>**Impera**: Computa ricorsivamente l'allineamento ottimale in ogni pezzo

![[Pasted image 20250403165002.png|center|500]]

>[!important] **Th**. L'algoritmo di Hirschberg utilizza spazio $\Theta(m+n)$
>**Dim.**
>- Ogni chiamata ricorsva usa spazio $\Theta(m)$ per calcolare $f(\star,\frac{n}{2})$ e $g(\star,\frac{n}{2})$
>- Server solo $\Theta(1)$ di spazio per mantenere le chiamate ricorsive
>- Il numero di chiamare ricorsive è $\leq n$

### Analisi del tempo di esecuzione

>[!definition] **Th**. Sia $T(m,n)$ il massimo tempo di esecuzione dell'algoritmo di Hirschberg su una strigna di lunghezza al più $m$ e $n$. Allora $T(m,n)=O(mn)$
>**Dimostrazione** (induzione forte su $m+n$)
>- $O(mn)$ tempo per calcolare $f(\star,\frac{n}{2})$ e $g(\star,\frac{n}{2})$ e trovare l'indice $q$
>- $T(q,\frac{n}{2})+T(m-q,\frac{n}{2})$ tempo per le due chiamate ricorsive
>- Scegli una costante $c$ tale che : $$\begin{align}&T(m,2)\leq cm\\&T(2,n)\leq cn\\&T(m,n)\leq cmn+T(q,n/2)+T(m-q,n/2)\end{align}$$
>- Claim : $T(m,n)\leq2cmn$
>- Dimostriamolo :
>	- Caso base : $m=2\land n=2$
>	- Ipotesi induttiva : $T(m',n')\leq2cm'n'$ per ogni $(m',n')$ con $m'+n'\lt m+n$
>	- Quindi : $$\begin{align}T(m,n)&\leq T(q,n/2)+T(m-q,n/2)+cmn\\&\underbrace{\leq2cq*n/2+2c(m-q)n/2+cmn}_{\text{Ipotesi Induttiva}}\\&=cqn+cmn-cqn+cmn\\&=2cm\space\square\end{align}$$
