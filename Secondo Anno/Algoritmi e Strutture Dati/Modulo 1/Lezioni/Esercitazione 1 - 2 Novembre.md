# Problema
>[!important]- Dimostrare o confutare la seguente osservazione:
>Siano $f(n)$ e $g(n)$ due funzioni sempre non negative. Allora vale:
>$$f(n)=O(g(n))\implies 2^{f(n)}=O(2{g(n)})$$

**Soluzione**:
La relazione è *falsa* in generale. La seguente coppia di funzioni rappresenta un controesempio:
$f(n)=n$ e $g(n)=n/2$
Infatti vale:
$n=O(n/2)$, *ma* $2^n\neq O(2^{n/2})$  $[2^n=\omega(2^{n/2})]$ 
# Problema

>[!important]- Progettare un algoritmo ( efficiente ) che, dato un array ordinato $A[1:n]$ di $n$ inter e un intero $x$, trova ( se esistono ) due indici $i$ e $j$, $i\lt j$, tale che $A[i]+A[j]=x$.

![[Pasted image 20231102142325.png|center|]]
$$\begin{align}& x=26\implies i=2,j=6\\&x=23\implies i=3,j=4\\&x=20\implies i=-1,j=-1\implies \text{(Non esistono i<j con A[i]+A[j]=20)}\end{align}$$
*Idea*: Provo con tutte le coppie di indici $i$,$j$.
```PseudoCodice
Banale(A,x)
for i=1 to n-1 do
	for j=i+1 to n do
		if(A[i]+A[j]=x) then return(i,j)
return(-1,-1)
```

**Correttezza?** Ovvia. **Complessità?**$\Theta(n^2)$.**Si può fare di meglio?**

*Idea*: Per ogni valore dell'indice $i$, cerco l'opportuno $j$ usando la ricerca binaria.
```PseudoCodice
MenoBanale(A,x)
for i=1 to n-1 do
	j=RicercaBinaria(A,x-A[i],i+1,n)
	if(j!=-1) then return(i,j)
return(-1,-1)
```

**Correttezza?** Ovvia. **Complessità?**$\Theta(n\log n)$.**Si può fare di meglio?**

*Idea*: Scansionare l'array "parallelamente" da sinistra e da destra.
```PseudoCodice
Lineare(A,x)
i=1, j=n
while i<j do
	if A[i]+A[j]=x then return(i,j)
	if A[i]+A[j]<x then i++ else j--
return(-1,-1)
```

**Complessità?**$O(n)$. **Correttezza?**
## Correttezza
*Oss.* Se non esistono due elementi di $A$ che sommano a $x$ l'algoritmo `Lineare` risponde sicuramente bene, ovvero restituisce `(-1,-1)`
*E se esistono due elementi che sommano a x?*
Siano $i^*$ e $j^*$ tale che $A[i^*]+A[j^*]=x$
![[Pasted image 20231102144408.png|center]]

Per come si muovono gli indici, ad un certo punto succede una di queste cose:
1) $i=i^*$ e $j>j^*$
2) $i<i^*$ e $j=j^*$

*Caso 1*: $$A\text{ è ordinato, quindi }A[i]+A[j]\ge x\implies\text{ Algoritmo decrementa }j$$
*Caso 2*: Analogo