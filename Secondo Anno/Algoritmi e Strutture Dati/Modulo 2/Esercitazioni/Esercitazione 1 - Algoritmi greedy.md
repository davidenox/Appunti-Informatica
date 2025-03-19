# Problema 1
Sia $G=(V,E,w)$ un grafo con pesi positivi distinti $w$ sugli archi ed $e\in E$ un arco di $G$. 
**Progettare** un algoritmo lineare in grado di determinare se esiste un MST di $G$ che contiene l'arco $e$.

>**Input**:
>- $G=(V,E,w)$ con pesi distinti;
>- Arco $e=(u,v) \in E$
>**Domanda**:
>- $e$ appartiene all'unico MST di $G$?
>**Goal**:
>- Tempo lineare $O(m+n)$ dove $m$ è il numero di archi ed $n$ il numero di vertici.

*Hint*: Utilizzare *Cut-Property e Cycle-Property*.
![[Pasted image 20250319112540.png|center|500]]
## Soluzione
- Costruisco $G'$ da $G$ togliendo tutti gli archi di $G$ di peso $\ge w(e)$.
- Effettuo una visita BFS/DFS di $G'$ partendo dal nodo $u$ per raggiungere il nodo $v$
	- *Nota*: In $G'$ l'arco $e$ che collega $u$ e $v$ non esiste
- Se $v$ è raggiungibile, allora, per la proprietà del ciclo, l'arco $e$ sarebbe l'arco del "ciclo" creato di costo più elevato, e quindi non fa parte dell'MST (che è unico dato che i pesi degli archi sono distinti).
	- $\implies e\not\in MST(G)$
- Altrimenti, $e\in MST(G)$.
## Correttezza
Dividiamo la dimostrazione di correttezza in due casi:
- **Caso 1**: $v$ è raggiungibile da $u$ in $G'$.
	- $\implies\exists$ un cammino $P$ da $u$ a $v$ in $G'$
	- $\implies P\cup\{e\}$ è un ciclo $C$ in $G$ t.c. $e$ è l'arco di costo massimo di $C$
	- $\implies$ *Prop. del Ciclo* $\implies e\not\in MST(G).\square$
- **Caso 2**: $v$ non è raggiungibile da $u$ in $G'$.
	- $S=\{k\in V \text{ t.c. } k \text{ è raggiungibile da }u\text{ in }G'\}$ 
	- Dato $v\in \{V-S\}$, l'arco $e=(u,v)$ attraversa il taglio $\{S,V-S\}$
	- $\implies$ *Prop. del Taglio* $\implies e$ è l'arco più leggero che attraversa il taglio.$\square$
# Problema 2
	Sincronizzazione di circuiti

![[Pasted image 20250319114251.png|center|500]]

**Goal**: Sincronizzare le foglie: metterle tutte alla stessa distanza.
**Come**: Si possono incrementare i pesi degli archi.
**Misura (da minimizzare)**: Peso totale dell'albero risultante.

>**Input**:
>- Albero binario completo e pesato $T$
>**Soluzione ammissibile**:
>- Nuova pesatura $w'$ per $T$ con $w'(e)\ge w(e)$ tale che tutte le foglie rispetto a $w'$ hanno la stessa distanza dalla radice
>**Misura (da minimizzare)**:
>- $w'(T)=\sum_e w'(e)$

![[Pasted image 20250319114717.png|center|500]]
## SOlu