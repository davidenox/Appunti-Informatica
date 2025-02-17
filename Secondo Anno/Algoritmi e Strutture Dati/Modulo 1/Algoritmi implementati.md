>[!important]- Algoritmo
>Procedimento che descrive una sequenza di passi ben definiti finalizzato a risolvere un dato problema (Computazionale).

# Fibonacci
## Fibonacci 1
```c
algoritmo fibonacci1(intero n) -> intero
	return 1/sqrt(5) (phi^n - phi(cappuccio)^n) 
```

## Fibonacci 2

```C
algoritmo fibonacci2(intero n) -> intero
	if(n<=2) then
		return 1
	else
		return fibonacci2(n-1) + fibonacci2(n-2)
```

## Fibonacci 3

```C
algoritmo fibonacci3(intero n) -> intero
	sia Fib un array di n interi
	Fib[1] <- 1; Fib[2] <- 1
	for i=3 to n do
		Fib[i] <- Fib[i-1] + Fib[i-2]
	return Fib[n]
```

## Fibonacci 4

```C
algoritmo fibonacci4(intero n) -> intero
	a <- 1; b <- 1;
	for i=3 to n do
		c <- a+b
		a <- b
		b <- c
	return c
```

## Fibonacci 5

```c
algoritmo fibonacci5(intero n) -> intero
	M <- [1,0;0,1]
	for i=1 to n-1 do
		M <- M*[1,1;1,0]
	return M[0][0]
```

## Fibonacci 6

```C
algoritmo fibonacci6(intero n) -> intero
	A <- [1,1;1,0]
	M <- potenzaDiMatrice(A, n-1)
	return M[0][0]

funzione potenzaDiMatrice(matrice A, intero k) -> matrice
	if k=0 then
		return [1,0;0,1]
	else
		M <- potenzaDiMatrice(A, [k/2]) //parte intera inferiore
		M <- M*M
	if (k dispari) then
		M <- M*A
	return M
```

- Tempo di esecuzione : $O(\log_{2}{n})$ .

### Riepilogo

![[Pasted image 20250217212435.png|center|500]]

# Ricerca
## Ricerca sequenziale
	array/lista non ordinata

```C
algoritmo RicercaSequenziale(Array L, elem x) -> intero
	n = lunghezza di L
	i = 1
	for i=1 to n do
		if(L[i] = x) then return i //trovato
	return -1 // non trovato
```

- $T_{worst}(n)=n$
- $T_{avg}(n) = \frac{n+1}{2}$
- $T(n)=\Theta(n)$

## Ricerca Binaria
	array/lista ordinata

```C
algoritmo RicercaBinariaRic(array L, elem x, int i, int j) -> intero
if(i>j) then return -1
m = [(i+j)/2] //parte intera inferiore
if(L[m]=x) then 
	return m
if(L[m]>x) then 
	return RicercaBinariaRic(L,x,i,m-1)
else 
	return RicercaBinariaRic(L,x,m+1,j)
```

- $T(n)=O(\log n)$ 

# Problemi
## Celebrità

>[!note]- Ad una festa ci sono **n** persone, una di queste è una **celebrità**. La celebrità non conosce nessuno ma è conosciuta da tutti. **Obiettivo**: individuare la celebrità facendo domande a persone del tipo "Conosci questa persona?".

```C
Celebrità(X)
if |X|=1 then
	return "l'unica persona in x" //la celebrità
//siano A e B due persone qualsiasi in X: chiedi ad A se conosce B
if(A "conosce" B) then //A non è la celebrità
	return Celebrità(X-{A}) 
else //B non è la celebrità
	return Celebrità(X-{B})
```

- $T(n) = n-1$

## Hanoi
>[!note]- $n$ dischi di diametro diverso, tre pali. 
>- **Obiettivo**: spostare i dischi dal palo A al palo C (facendo meno spostamenti possibile).
>- **Regole**: si può spostare un disco alla volta e non si può mettere un disco di diametro più grande sopra uno di diametro più piccolo.

```C
Hanoi ([1,2..,n], C, B)
if n=1 then "sposta il disco su C"
	Hanoi([1,2,…,n-1], B, C)
	"sposta il disco n su C"
	Hanoi([1,2,…,n-1], C, A)
```

- $T(n)= \Theta(2^n)$

# Ordinamento
## Tempo quadratico
### SelectionSort

```C
SelectionSort(A)
	for k=0 to n-2 do
		m = k+1
		for j=k+2 to n do
			if(A[j]<A[m]) then
				m=j
		"Scambia A[m] con A[k+1]"
```

### InsertionSort

```C
InsertionSort(A, n)
    // Scorriamo l'array partendo dal secondo elemento (indice 1)
    for i ← 1 to n-1 do
        chiave ← A[i]   // L'elemento corrente da inserire nell'ordine corretto
        j ← i - 1       // Indice dell'elemento precedente
        // Sposta gli elementi di A[0..i-1] che sono maggiori di 'chiave' a destra
        while(j >= 0) and A[j] > chiave do
            A[j + 1] ← A[j]  // Spostiamo l'elemento verso destra
            j ← j - 1        // Passiamo all'elemento precedente
        // Inseriamo la chiave nella posizione corretta
        A[j + 1] ← chiave
```

### BubbleSort

```C
BubbleSort(A, n)
    for i ← 0 to n - 2 do
        swapped ← false
        for j ← 0 to n - 2 - i do
            if A[j] > A[j + 1] then
                SWAP(A[j], A[j + 1])
                swapped ← true
        if swapped = false then
            break
```

## Tempo meno che quadratico
### MergeSort

```C
MergeSort (A, i, f)
	if (i < f) then
		m = [(i+f)/2] // parte intera inferiore
		MergeSort(A,i,m)
		MergeSort(A,m+1,f)
		Merge(A,i,m,f)
Merge (A, i1, f1, f2)
"Sia X un array ausiliario di lunghezza f_2-i_1+1"
	i=1; k1=i1
	k2=f1+1
	while (k1<= f1 "e" k2 <= f2) do
		if (A[k1] <= A[k2]) then 
			X[i]=A[k1]
			//incrementa i e k1
		else 
			X[i]=A[k2]
			//incrementa i e k2
	if (k1<=f1) then 
		"copia A[k1;f1] alla fine di X"
	else 
		"copia A[k2;f2] alla fine di X"
	"copia X in A[i1;f2]"
```

- Con array ausiliario $\Theta(n)$.
- $O(n\log{n})$

### QuickSort

```C
QuickSort (A, i, f )
	if (i < f) then
		m=Partition(A,i,f)
		QuickSort(A,i,m-1)
		QuickSort(A, m +1,f)

Partition (A, i, f )
	x=A[i]
	inf =i
	sup= f + 1
	while (true) do
		do (inf=inf + 1) while (inf ≤ f "e" A[inf] <= x)
		do (sup=sup-1) while (A[sup] > x)
		if (inf < sup) then 
			scambia A[inf] e A[sup]
		else 
			break
	scambia A[i] e A[sup]
	return sup
```

- $T(n)=O(n^2)$ Nel caso peggiore.
- $T(n)=O(n\log{n})$ Caso medio ( e versione randomizzata).

## HeapSort

>[!important]- Sia v la radice di H. Assume che i sottoalberi radicati nel figlio sinistro e destro di v sono heap, ma la proprietà di ordinamento delle chiavi non vale per v. Posso ripristinarla così:

```C
fixHeap(nodo v, heap H)
	if (v non è una foglia) then
		"sia u il figlio di v con chiave massima"
		if ( chiave(v) < chiave(u) ) then
			scambia chiave(v) e chiave(u)
			fixHeap(u,H)
```

- $O(\log{n})$

Più dettagliato:
```C
fixHeap (i,A)
	s=sin(i)
	d=des(i)
	if (s  heapsize[A] e A[s] >A[i])
		then massimo=s
	else massimo=i
	if (d <= heapsize[A] e A[d] >A[massimo])
		then massimo=d
	if (massimo!=i) then //scambia A[i] e A[massimo]
		fixHeap(massimo,A)
```

```C
heapify(heap H)
	if (H non è vuoto) then
		heapify(sottoalbero sinistro di H)
		heapify(sottoalbero destro di H)
		fixHeap(radice di H,H)
```

- Complessità: $O(\log{n})$

```C
heapSort (A)
	Heapify(A)
	Heapsize[A]=n
	for i=n down to 2 do
		scambia A[1] e A[i]
		Heapsize[A] = Heapsize[A] -1
		fixHeap(1,A)
```

- Ordina in loco in tempo $O(n\log{n})$

## IntegerSort

```C
IntegerSort (X, k)
	Sia Y un array di dimensione k
	for i=1 to k do Y[i]=0
	for i=1 to n do incrementa Y[X[i]]
	j=1
	for i=1 to k do
		while (Y[i] > 0) do
			X[j]=i
			incrementa j
			decrementa Y[i]
```

- $O(n+k)$
## BucketSort
	ordinare n record con chiavi intere in [1,k]

```C
BucketSort (X, k)
	Sia Y un array di dimensione k
	for i=1 to k do Y[i]=lista vuota
	for i=1 to n do
		appendi il record X[i] alla lista Y[chiave(X[i])]
	for i=1 to k do
		copia ordinatamente in X gli elemeti della lista Y[i]
```

- $O(n+k)$

## Radix Sort
- Ordina n interi con valori in $[1,k]$ 
- Rappresentiamo gli elementi in base b, ed eseguiamo una serie di BucketSort
- Partiamo dalla cifra meno significativa verso quella più significativa:
	- Ordiniamo per l’i-esima cifra con una passata di buckerSort (stabile) 
	- i-esima cifra è la chiave, il numero info satellite 
	- i-esima cifra è un intero in $[0,b-1]$

Se $b=\Theta(n)$ si ha $O(n\log_n{k})=O(n\frac{\log{k}}{\log{n}})$ 

# Tipi di dato
# Dizionario

```
**tipo** Dizionario:  
**dati:**  
un insieme S di coppie (elem, chiave).

**operazioni:**

**insert(elem e, chiave k)**  
aggiunge a S una nuova coppia (e, k).

**delete(chiave k)**  
cancella da S la coppia con chiave k.

**search(chiave k) → elem**  
se la chiave k è presente in S restituisce l’elemento e ad essa associato,  
e null altrimenti.
```

## Pila

```
**tipo** Pila:  
**dati:**  
una sequenza S di n elementi.

**operazioni:**

**isEmpty() → result**  
restituisce true se S è vuota, e false altrimenti.

**push(elem e)**  
aggiunge e come ultimo elemento di S.

**pop() → elem**  
toglie da S l’ultimo elemento e lo restituisce.

**top() → elem**  
restituisce l’ultimo elemento di S (senza toglierlo da S).
```

## Coda

```
**tipo** Coda:  
**dati:**  
una sequenza S di n elementi.

**operazioni:**

**isEmpty() → result**  
restituisce true se S è vuota, e false altrimenti.

**enqueue(elem e)**  
aggiunge e come ultimo elemento di S.

**dequeue() → elem**  
toglie da S il primo elemento e lo restituisce.

**first() → elem**  
restituisce il primo elemento di S (senza toglierlo da S).
```

**Realizzazione di un dizionario**

 **1. Array non ordinato (sovradimensionato)**
- **Insert:** O(1) → aggiunta in coda
- **Search:** O(n) → scansione completa
- **Delete:** O(n) → ricerca + cancellazione
**2. Array ordinato**
- **Search:** O(log(n)) → ricerca binaria
- **Insert:** O(n)
    - O(log(n)) confronti → trovare posizione
    - O(n) trasferimenti → mantenere ordine
- **Delete:** O(n) → simile a Insert
 **Nota:** O(n) + O(log(n)) = O(n)

**con liste**
**1. Lista non ordinata**
- **Search:** O(n)
- **Insert:** O(1)
- **Delete:** O(n)
**2. Lista ordinata**
- **Search:** O(n) →  _niente ricerca binaria_
- **Insert:** O(n) → *mantenere ordine*
- **Delete:** O(n)

# Visita alberi
## DFS
>[!note]- L’algoritmo di visita in profondità (DFS) parte da r e procede visitando nodi di
figlio in figlio fino a raggiungere una foglia. Retrocede poi al primo antenato che ha ancora figli non visitati (se esiste) e ripete il procedimento a partire da uno di quei figli.

(Alberi binari)
```C
algoritmo visitaDFS(nodo r)
	Pila S
	S.push(r)
	while(not S.isEmpty()) do
		u <- S.pop()
	if(u != NULL ) then
		visita il nodo u
		S.push(figlio destro di u)
		S.push(figlio sinistro di u)
```

- $T(n) = O(n)$

Versione ricorsiva:
```C
algoritmo visitaDFSRicorsiva(nodo r)
	if(r!= NULL) then
		visita il nodo r
		visitaDFSRicorsiva(figlio sinistro di r)
		visitaDFSRicorsiva(figlio destro di r)
```

- Visita in **preordine**: radice, sottoalbero sin, sottoalbero destro
- Visita **simmetrica**: sottoalbero sin, radice, sottoalbero destro (scambia riga 2 con 3)
- Visita in **postordine**: sottoalbero sin, sottoalbero destro, radice (sposta riga 2 dopo 4)

## BFS
>[!note]- L’algoritmo di visita in ampiezza (BFS) parte da r e procede visitando nodi per livelli successivi. Un nodo sul livello i può essere visitato solo se tutti i nodi sul livello i-1 sono stati visitati.

```C
algoritmo visitaBFS(nodo r)
	Coda C
	C.enqueue(r)
	while(not C.usEmpty()) do
		u <- C.dequeue()
		if(u!= NULL) then
			visita il nodo u
			C.enqueue(figlio sinistro di u)
			C.enqueue(figlio destro di u)
```
