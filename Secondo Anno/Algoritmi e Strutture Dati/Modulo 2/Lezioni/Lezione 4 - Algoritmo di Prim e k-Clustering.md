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

>[!important]- **Proprietà del taglio**
>Sia $S$ un qualsiasi sottoinsieme di nodi, e sia $e$ un arco di costo minimo con esattamente un endpoint in $S$. Allora esiste un MST $T^*$ che contiene $e$.
>![[Pasted image 20250312113654.png|center|500]]

# Algoritmo di Prim
****