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
