# BubbleSort
Algoritmo 1 (BubbleSort)

## Pseudo-codice
Pseudo-codice:

>BubbleSort(A):
>scambio = true
>while scambio do
>	scambio = false
>	for i =0 to n-2 do
>		if $A[i]\gt A[i+1]$ then
>		swap($A[i],A[i+1]$)
>		scambio=true

n è la lunghezza dell'array

## Complessità temporale

Il Upper bound dell'algoritmo è:

T(n)=#passi elementari eseguiti su una RAM
$c_j$= costo della j-esima riga
- linee 1,3,5,6,7 hanno costo costante
- linea 2 eseguita al più n volte
- linea 4 eseguita al più n-2 volte per ogni ciclo esterno

$$T(n)\leq c_1+nc_2+n(n-2)(c_3+c_4+c_5)\implies T(n)=O(n^2)\implies T(n)=\Theta(n^2)$$

# Insertion Sort

## Pseudo-codice

>InsertionSort(A)
>for j=2 to n
>	do key=$A[j]$
>		//inserisce $A[j]$ nella sequenza ordinata $A[1...j-1]$
>		i=j-1
>		while $i\gt0\:and\:A[i]\gt key$
>			do $A[i+1]=A[i]$
>				i=i-1
>		$A[i+1]=key$

## Complessità temporale

- linea 1 eseguita n-2 volte
- linea 2,3 costo costante,eseguite al più n volte
- linea 4 eseguita al più n-2 volte (In realtà sarebbe $\sum_{j=2}^n t_j$) per ciclo esterno
- linee 5,6 costo costante, eseguite al più n-2 volte (In realtà sarebbe $\sum_{j=2}^n t_j$)
- linea 7 costo costante
$t_j$ è il numero di volte che la linea 4 viene eseguita
$T(n)\leq n((c_2+c_3+c_7+c_6+c_5)+(n-2))=nc+n^2\implies$
$T(n)=O(n^2)\implies T(n)=\Theta(n^2)$


