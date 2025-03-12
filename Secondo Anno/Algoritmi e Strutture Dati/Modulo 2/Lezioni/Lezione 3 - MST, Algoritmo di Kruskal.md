# Minimum Spanning Tree
	Minimo albero ricoprente

>[!important]- MST
>Dato un grafo pesato non orientato $G=(V,E)$ con pesi sugli archi $c_e$, un MST è un sottonisieme degli archi $T\subseteq E$ tale che $T$ è un albero ricoprente la cui somma dei pesi degli archi è minima:
>![[Pasted image 20250312102838.png|center|600]]

>[!info]- **Th. Cayley**: Esistono $n^{n-2}$ spanning tree di $K_n$.

> Input:
> - Un grafo connesso non orientato e pesato $G=(V,E)$ con archi con pesi $c_e$

>Soluzione ammissibile:
>- Uno spanning tree $T$ di $G$; Un albero con $T\subseteq E$ ricoprente ogni nodo di $G$

>Misura (da minimizzare):
>- Il peso (o costo) di $T$; $c(T)=\sum_{e\in T}c_e$ 

>**Unicità di MST**
>L'MST non è unico in generale:![[Pasted image 20250312103539.png|center|500]]
>*Proprietà*: Se $G$ ha pesi distinti allora l'MST è unico

# Algoritmi greedy

**Algoritmo di Kruskal**:
- Si parte con $T=\not0$. Si considerano gli archi in ordine di costo dal più piccolo al più grande. Si inserisce l'arco $e$ in $T$ a meno che non si crei un ciclo.
**Algoritmo Reverse-Delete**: 
- Si parte con $T=E$. Si considerano gli archi in ordine di costo dal più grande al più piccolo. Si elimina l'arco $e$ da $T$ a meno che non disconnetta $T$.
**Algoritmo di Prim**:
- Si inizia con un qualche nodo radice $s$. Si sviluppi *golosamente* un albero $T$ da $s$ verso l'esterno. Ad ogni step, si aggiunge l'arco di peso minore $e$ a $T$ che ha esattamente un endpoint in $T$

>[!note]- Tutti e tre gli algoritmi producono un MST

## Cicli e tagli

>**Ciclo**(*Cycle*): Insieme di archi di forma $a-b,b-c,...,y-z,z-a$ 
>![[Pasted image 20250312104355.png|center|500]]
>**Taglio**(*Cut*): Sottoinsieme di nodi $S$ (A volte definito come partizione di $V$ in $S$ e $V/S$)
>**Cutset**: Il corrispondente cutset $D$ di un taglio $S$ è il sottoinsieme di archi con esattamente un endpoint in $S$ 
>![[Pasted image 20250312112838.png|center|500]]

>[!info]- Un ciclo ed un cutset si intersecano in un numero pari di archi 
>![[Pasted image 20250312112930.png|center|500]]
>Dimostrazione da immagine:
>![[Pasted image 20250312112953.png|center|500]]

### Proprietà

>[!important]- **Proprietà del taglio**
>Sia $S$ un qualsiasi sottoinsieme di nodi, e sia $e$ un arco di costo minimo con esattamente un endpoint in $S$. Allora esiste un MST $T^*$ che contiene $e$.
>*Dim*:
>- Supponiamo che $e$ non appartenga a $T^*$
>- Aggiungendo $e$ a $T^*$ si creerebbe un ciclo $C$ in $T^*$
>- L'arco e si troverebbe sia nel ciclo $C$ che nel cutset $D$ corrispondente ad $S$
>- $\implies$ esiste un altro arco, chiamiamo $f$, che si trova sia in $C$ che in $D$
>- $T'=T^* \cup \{e\}-\{f\}$ è anch'esso uno spanning tree
>- Dato che $c_e\le c_f$, allora $costo(T')\le costo(T^*)$
>- Quindi $T'$ è un MST che contiene $e$
>![[Pasted image 20250312113654.png|center|500]]

>[!important]- **Proprietà del ciclo**

****
