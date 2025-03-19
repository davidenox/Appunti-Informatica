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
## Soluzione 
![[Pasted image 20250319120816.png|center|500]]
- $x^*$: Foglia più lontana a distanza $L=15$
- *Idea*: Mettere tutte le foglie a distanza $L=15$
- *Intuizione*: Conviene aumentare gli archi "alti"
- *Definizione*: Arco $e$ copre una foglia $x$ se il cammino dalla radice verso $x$ passa per $e$
$F$= Insieme delle foglie;
$F_e$ = Insieme delle foglie coperte da $e$.
Per ogni sottoinsieme di archi $X$ $\{F_e\}_{e\in X}$ famiglia **laminare** di insiemi:
Per ogni $e$, $e'$ in $X-F_e \subseteq F_{e'}$ oppure $F_e\cap F_{e'}=\not0$ 

>Algoritmo Greedy
>- Marca tutti gli archi del cammino $r-x^*$
>- Considera gli archi di T top-down (ordine ascendente di profondità)
>	- Se l'arco $e$ non è marcato
>		- Alza il peso di $e$ finché una foglia $x\in F_e$ non diventa a distanza $L$
>		- Marca tutti gli archi lungo il cammino verso $x$
>- Restituisci la nuova pesatura.
### Demo
![[sync_circuit.gif|center|500]]
## Ottimalità
**Claim:** una soluzione ottima mette tutte le foglie a distanza $L$
Supponi che **Opt** metta tutte le foglie a distanza $L'\gt L$.
![[Pasted image 20250319125021.png|center|300]]
**Concetti chiave:**
- $X$: archi incrementati da **Opt**
- Poiché tutte le foglie hanno aumentato la loro distanza:$\bigcup_{e \in X} F_e = F$
- $X' \subseteq X$: tale che ogni foglia è coperta da un solo $e \in X'$.

Definiamo 
$$
\delta = \min \{ w'(e) - w(e) \mid e \in X' \}
$$
Se decrementiamo di $\delta$, otteniamo una soluzione ammissibile **strettamente migliore**.
Allora **Opt** non era ottima: **assurdo!**

**Idea:** *faccio vedere che il greedy non sbaglia mai*

**Definizioni**
- $e^*$ : primo arco incrementato dal greedy  
- $W$ : incremento del greedy che porta $x$ a distanza $L$  
**Ipotesi**
Assumiamo che **Opt** incrementi $e^*$ di $W' < W$.
- $X$: archi incrementati da **Opt** in $T'$
- Poiché tutte le foglie di $T'$ devono aumentare la loro distanza:$$
  \bigcup_{e \in X} F_e = \text{foglie di } T'
  $$
- $X' \subseteq X$: tale che ogni foglia di $T'$ è coperta da un solo $e \in X'$
**Nota**
$$
|X'| \geq 2
$$
**Contraddizione**
Definiamo:
$$
\delta = \min \{ W - W', \min \{ w'(e) - w(e) \mid e \in X' \} \}
$$
Decrementando di $\delta$ e incrementando $e^*$ di $\delta$, otteniamo una soluzione ammissibile **strettamente migliore**.
Allora **Opt** non era ottima: **assurdo!**

**Conclusione**
Quindi l'ottimo deve incrementare $e^*$ come il **greedy**: stesse argomentazioni per i prossimi archi.
