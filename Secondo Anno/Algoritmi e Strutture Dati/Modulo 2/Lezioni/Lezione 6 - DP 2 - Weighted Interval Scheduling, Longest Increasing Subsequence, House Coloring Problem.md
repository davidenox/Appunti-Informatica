# Weighted Interval Scheduling
- Il job $j$ inizia a $s_j$, finisce a $f_j$ ed ha peso $w_j\gt 0$;
- Due job sono *compatibili* se non si sovrappongono;
- **Goal**: Trovare il sottoinsieme di maggior peso di job mutualmente compatibili.
![[Pasted image 20250327112827.png|center|500]]
## Algoritmo Earliest-finish-time-first
- Ordina i job in ordine ascendente di tempo di fine.
- Aggiungi un job al sottoinsieme solo se è compatibile con il job scelto precedentemente

>Questo algoritmo greedy funziona se tutti i pesi sono $1$
>L'algoritmo greedy fallisce sulla versione pesata:

![[Pasted image 20250327113057.png|center|500]]
## Programmazione dinamica: scelta binaria
**Convenzione**: i job sono ordinate per ordine di fine in modo che $f_1\le f_2\le\dots\le f_n$.
>**Def**. $p(j)=$il più alto indice $i<j$ tale che il job $i$ è compatibile con $j$.

![[Pasted image 20250327114607.png|center|500]]
**Es.** $p(8)=1,p(7)=3,p(2)=0$.

>**Def**. $OPT(j)=$ il peso massimo di ogni sottoinsieme dei lavori mutualmente compatibili per sottoproblemi che prendono in considerazione solo i job $1,..,j$.
>**Goal**:$OPT(n)=$ il peso massimo di tutti i sottoinsiemi di job mutualmente compatibili.

**Caso 1**: $OPT(j)$ *non seleziona* il job $j$:
- Deve esserci una soluzione ottimale tra i job rimanenti $1,...,j-1$.
**Caso 2**: $OPT(j)$ *seleziona* il job $j$:
- Colleziona il profitto $w_j$:
- Non si possono usare job incompatibili $\{p(j)+1,p(j)+2,...,j-1\}$.
- Deve includere la soluzione ottimale per problemi con i job compatibili restanti $1,2,\dots,p(j)$.
>[!important]- Equazione di Bellman 
>$$OPT(j)=\begin{cases}
0&\text{se }j=0\\
\max\{OPT(j-1),w_j+OPT(p_j))\}&\text{se }j>0
\end{cases}$$

### Programmazione dinamica Bottom-Up
```pseudo
BottomUp(n,s_1,...,s_n,f_1,...,f_n,w_1,...,w_n)
	Ordina i job per ordine di tempo di fine
	Computa p[1], p[2],...,p[n] via ricerca binaria
	M[0]=0
	for j=1 to n do
		M[j]=max{M[j-1],w_j+M[p[j]]}
	return M[n]
```

**Tempo di esecuzione**: La versione Bottom-Up impiega tempo $O(n\log n)$:
- Ordinamento per tempo di fine: $O(n\log n)$ via MergeSort;
- Computazione di $p[j]$ per ogni $j$: $O(n\log n)$ via BinarySearch;
- Cicli `FOR` impiegano tempo $O(n)$. 
### Ricorsione aka Brute Force

```pseudo
BruteForce(n,s_1,...,s_n,f_1,...,f_n,w_1,...,w_n)
	ordina i job per tempo di fine
	computa p[1],..,p[n] via binary search
	return Compute-OPT(n)

Compute-OPT(j)
	if j=0 then
		return 0
	else
		return max{Compute-OPT(j-1),w_j+Compute-OPT(p[j])}.
```

Il tempo di esecuzione dell'algoritmo è descritto dalla seguente equazione di ricorrenza

$$T(n)=\begin{cases}\Theta(1)&n=1\\2T(n-1)+\Theta(1)&n\gt1\end{cases}\implies T(n)=\Theta(2^n)$$
**Osservazione** : L'algoritmo ricorsivo è spettacolarmente lento a causa dei sottoproblemi che si sovrappongono $\implies$ algoritmo esponenziale

**Esempio** : Numero di chiamate ricorsive per una famiglia di istanze "stratificate" cresce come la sequenza di Fibonacci

![[Pasted image 20250327122220.png|center|500]]
### Top-down Dynamic Programming (Memoization)

**Memoization** :
- Salva il risultato del sottoproblema $j$ in $M[j]$
- Usa $M[j]$ per evitare di risolvere il sottoproblema $j$ più di una volta

```pseudo
Top-Down(n,s_1,...,s_n,f_1,...,f_n,w_1,...,w_n)
	ordina i job per ordine di tempo di fine
	computa p[1],..,p[n]
	M[0]=0
	return M-Compute-OPT(n)

M-Compute-OPT(j)
	if(M[j] non inizializzato) then
		M[j]=max{M-Compute-OPT(j-1),w_j+M-Compute-OPT(p[j])}
	return M[j]
```

**Claim** : La versione "Memoizzata" dell'algoritmo richiede tempo $O(n\log(n))$

**Pf.**
- Ordinare tramite finish time : $O(n\log(n))$ usando il MergeSort
- Calcolare $p[j]$ per ogni $j$ : $O(n\log(n))$ usando il binary search
- `M-ComputeOPT(j)` : Ogni invocazione richiede tempo $O(1)$ e inoltre :
	1) Ritorna un valore inizializzato $M[j]$
	2) Inizializza $M[j]$ ed esegue due chiamate ricorsive
- Misura di progresso $\phi$ = # voci inizializzate in $M[1\dots n]$
	- Inizialmente $\phi=0$; Totale $\phi\leq n$
	- Incrementa $\phi$ di 1 $\implies\leq 2n$ chiamate ricorsive
- Tempo totale di esecuzione di `M-Compute-OPT(n)` è $O(n)$

**Q** : L'algoritmo di DP calcola il valore della soluzione ottima. Come troviamo la soluzione ottima?
**A** : Eseguiamo una seconda passata chiamando l'algoritmo `Find-Solution(n)`

```pseudo
Find-Solution(j)
	if(j=0) then
		return 0
	else if (w_j + M[p[j]] > M[j-1]) then
		return {j} \union Find-Solution(p[j])
	else
		return Find-Soluion(j-1)
```


Numero di chiamate ricorsive $\leq n\implies O(n)$

## Memoization (top-down) vs Table-base (bottom-up)

| Memoization                                                           | Table-base                                                                 |
| --------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Approccio Top-Down                                                    | **Più difficile da "afferrare"**                                           |
| Più facile indicizzare i sottoproblemi da altri oggetti (es. insieme) | **Bisogna indicizzare i sottoproblemi con gli interi**                     |
| Calcola solo i sottoproblemi necessari                                | **Calcola sempre tutti i sottoproblemi**                                   |
| **Chiamate delle funzioni sopraelevate**                              | Nessuna ricorsione. Più efficiente                                         |
| **La complessità temporale è più difficile da analizzare**            | La complessità temporale è più facile da analizzare, codice corto e pulito |

----
# Longest Increasing Subsequence

Una piccola analogia

Robert vuole bere il più possibile

- Robert cammina lungo una via e incontra $n$ taverne $t_1,t_2,\dots t_n$ in ordine
- Quando Robert incontra una taverna $t_i$, lui si può fermare a bere o no
- Il vino servito nella taverna $t_i$ ha gradazione $s_i$
- La gradazione dei drinks di Robert deve incrementarsi ogni volta
- **Goal** : Calcola il massimo numero di fermate di Robert

**Esempio**

![[Pasted image 20250327143600.png|center|500]]
Diventa
![[Pasted image 20250327143613.png|center|500]]

Questo problema è conosciuto col nome di **Longest Increasing Subsequence**

## Algoritmo DP : Prima prova

- **Definizioni dei sottoproblemi** : $OPT[i]$ : Lunghezza del LIS di $S[1],\dots S[i]$
- **Caso base** $$OPT[1]=1$$
- **Soluzione** $$OPT[n]$$
- Formula ricorsiva ???

## Algoritmo DP : Seconda prova

**Tip** : Molte volte aggiungere costanti al problema può aiutare!

$OPT[i]$ : Lunghezza del LIS di $S[1],\dots S[i]$ che finisce con $S[i]$

![[long_incr_seq.gif|center|500]]

- **Definizione di sottoproblemi** : $OPT[i]$ : Lunghezza del LIS di $S[1],\dots S[i]$ che finisce con $S[i]$
- **Caso base** : $$OPT[1]=1$$
- **Soluzione** : $$\max_{i=1,2,\dots,n}OPT[i]$$
- **Ordine dei sottoproblemi** $$OPT[1],OPT[2],\dots OPT[n]$$
- **Formula ricorsiva** $$OPT[i]=1+\max\{0,\max_{j=1,2,\dots,i-1}OPT[j]\}$$
Ora vediamo lo pseudocodice dell'algoritmo

```pseudo
LIS(S[1:n])
	OPT[1]=1
	for i=2 to n do
		OPT[i]=1+max{0, max_{j=1,...,n t.c. S[j]<S[i]} OPT[j]}
	return max_i OPT[i]
```

**Tempo di esecuzione**
- Ogni $OPT[i]$ viene calcolare in tempo $O(i)=O(n)$
- tempo totale $O(n^2)$
