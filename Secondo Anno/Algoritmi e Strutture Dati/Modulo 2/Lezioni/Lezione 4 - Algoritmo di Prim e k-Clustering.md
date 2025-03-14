Ricordiamo il problema dell'MST e le varie proprietà.

> Input:
> - Un grafo connesso non orientato e pesato $G=(V,E)$ con archi con pesi $c_e$

>Soluzione ammissibile:
>- Uno spanning tree $T$ di $G$; Un albero con $T\subseteq E$ ricoprente ogni nodo di $G$

>Misura (da minimizzare):
>- Il peso (o costo) di $T$; $c(T)=\sum_{e\in T}c_e$ 
>![[Pasted image 20250312102838.png|center|600]]

>[!important]- **Proprietà del taglio**
>Sia $S$ un qualsiasi sottoinsieme di nodi, e sia $e$ un arco di costo minimo con esattamente un endpoint in $S$. Allora esiste un MST $T^*$ che contiene $e$.
>![[Pasted image 20250312113654.png|center|500]]

>[!important]- **Proprietà del ciclo**
>Sia $S$ un qualsiasi sottoinsieme di nodi, e sia $e$ un arco di costo minimo con esattamente un endpoint in $S$. Allora esiste un MST $T^*$ che contiene $e$.
>![[Pasted image 20250312113654.png|center|500]]

# Algoritmo di Prim
	Jarnìk 1930, Dijkstra 1957, Prim 1959ù

>[!important]- Si inizia con un qualche nodo radice $s$ e si fa crescere un albero da $s$ con approccio "greedy". Ad ogni step, si aggiunge l'arco con il costo minore $e$ a $T$ che ha esattamente un endpoint in $T$.
>

**Correttezza**: Diretta conseguenza della proprietà del *taglio*, usata esattamente $n-1$ volte.
## Demo
![[prim.gif|center|500]]
## Tempo di esecuzione

Una semplice *ed inefficiente* implementazione:
- Per $n-1$ volte, trova un arco di costo minimo che attraversa il taglio introdotto dall'albero parziale corrente in tempo $O(m)$.
- Tempo totale: $O(mn)$.
Un'implementazione più **veloce**:
- Mantiene l'insieme di nodi esplorati $S$
- Usa una coda con priorità per manterene i nodi non esplorati
- Per ogni nodo non esplorato $v$, la priorità è il costo di attaccamento `a[v]`= costo dell'arco più 'economico' incidente in $v$ avendo un endpoint in $S$.
```pseudo
Prim(G,s){
	foreach (v in V) a[v] <- infty
	a[s] <- 0
	Inizializza una coda con priorità vuota Q
	foreach (v in V) inserisci v in Q con priorità a[v]
	Inizializza l'insieme di nodi visitati S <- /0
	Inizializza T come l'albero contenente solo s.

	while(Q non vuoto){
		u <- elimina l'elemento minimo da Q
		S <- S \union {u}
		foreach (arco e=(u,v) incidente ad u)
			if((v not in S) and (c_e < a[v]))
				fai u genitore di v in T
				decrementa la priorità a[v] a c_e
	}
	return T
}
```

**Tempo di esecuzione**
- $O ( m + n )$ più il costo delle operazioni sulla coda
    - n inserimenti, n cancellazioni del minimo, m decrease key
- $O ( n^2 )$ con array, $O ( m \log ⁡ ( n ) )$ con un heap binario
- $O ( m + n \log ⁡ ( n ) )$ con gli heap di Fibonacci

Quindi, il tempo di esecuzione dell'algoritmo di Prim è $O ( m + n \log ⁡ ( n ) )$
# Clustering
>[!important]- Dato un insieme $U$ di $n$ oggetti etichettati come $p_1,...,p_n$, classificare questi oggetti in gruppi coerenti
>

**Funzione distanza**: Valore numerico che specifica la *vicinanza* di due oggetti

**Problema fondamentale**: Dividere in cluster in modo che i punti in cluster diversi sono lontani tra loro.
- Routing in reti mobili ad hoc.
- Identificazione di modelli nell'espressione genica.
- Categorizzazione di documenti per la ricerca web.
- Ricerca di similarità nei database di immagini mediche
- Skycat: raggruppa $10^9$ oggetti celesti in stelle, quasar, galassie.
## k-Clustering
	Dividere oggetti in k gruppi non vuoti

**Funzione distanza**: Assumiamo che soddisfi numerose proprietà naturali:
- $d(p_i,p_j)=0 \iff p_i=p_j$ (identità)
- $d(p_i,p_j)\ge 0$ (non-negatività)
- $d(p_i,p_j)=d(p_j,p_i)$ (simmetria)

**Spacing**: Distanza minima tra qualsiasi paio di punti in cluster differenti

**Clustering dello spacing massimo**: Dato un intero $k$, trovare un $k$-clustering dello spacing massimo.
![[Pasted image 20250314141624.png|center|500]]
## Algoritmo greedy di Clustering
**Algoritmo Single-linkage k-clustering**
- Crea un grafo sull'insieme dei vertici $U$ , corrispondente a $n$ cluster
- Trova la coppia di oggetti più vicini tale che i due oggetti si trovano in cluster diversi, e poi aggiungi un'arco tra i due
- Ripeti il procedimento $n − k$ volte, fino a quando non ci sono esattamente $k$ cluster

**Osservazione chiave** : Questo procedimento è esattamente l'algoritmo di Kruskal (solo che qui ci fermiamo quando abbiamo k componenti connesse)

**Osservazione** : Questo è equivalente a trovare un MST e cancellare i k − 1 archi di costo massimo

>[!note]- **Clustering gerarchico**
>Eseguire l'algoritmo di Kruskal fino alla fine produce implicitamente un clustering gerarchico, ovvero un $k$-clustering per ogni valore di $k=n,n-1,...,1$.

### Demo
![[k_cluster.gif|center|500]]
### Analisi
> [!important]- **Th**. Sia $C^*$ un qualunque clustering, composoto dai cluster $C_1^* , … , C_k^*$ , formato cancellando i $k − 1$ archi più costosi del MST. Allora $C^*$ è un $k$-clustering di spacing massimo

**Dimostrazione**

Sia $C$ un'altro clustering, formato dai cluster $C_1,\dots,C_k$
- Lo spacing di $C^\star$ è la lunghezza $d^\star$ del $(k-1)$-esimo arco più pesante del MST
- Siano $p_i,p_j$ due punti che stanno in un cluster di $C^\star$, detto $C^\star_r$, ma in due cluster diversi di $C$, detti $C_s,C_t$
- Un qualche arco $(p,q)$ sul percorso $p_i-p_j$ in $C^\star_r$ spazia due diversi cluster di $C$
- Tutti gli archi sul percorso $p_i-p_j$ hanno lunghezza $\leq d^\star$, dato che Kruskal li ha scelti nella sua soluzione
- Lo spacing di $C$, di conseguenza, è $\leq d^\star$ dato che $p$ e $q$ sono in due cluster diversi
- Quindi, $C^\star$ è un k-clustering di spacing massimo $\square$.
![[Pasted image 20250314144504.png|center|500]]
