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
****