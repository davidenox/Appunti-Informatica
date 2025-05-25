Supponiamo di dover risolvere un problema di ottimizzazione NP-Hard. *Cosa dovremmo fare?*

**Sacrificare** una di queste cose:
1. Esecuzione in tempo polinomiale;
2. Risoluzione di istanza arbitrarie del problema;
3. Trovare una soluzione ottima al problema. $\leftarrow$ Questa

>[!important] Algoritmo $\rho$-approssimato
>- Esecuzione in tempo polinomiale;
>- Risoluzione di istanze arbitrarie del problema;
>- Trova soluzioni che si trovano in raggio $\rho$ dell'ottimo.

La **sfida** è dimostrare che un valore soluzione sia vicino all'ottimo, senza neanche sapere quale sia il valore ottimo.

>[!info] Def.
>Un **algoritmo $\alpha$-approssimato** per un problema di ottimizzazione è un algoritmo polinomiale che per ogni istanza del problema produce una soluzione il cui valore è di un fattore $\alpha$ del valore della soluzione ottima.

- $\alpha$: *raggio di approssimazione* o **fattore di approssimazione**.

>**Problema di minimizzazione**:
>- $\alpha\ge1$
>- Per ogni soluzione $x$, $costo(x)\le\alpha\cdot OPT(x)$

>**Problema di massimizzazione**:
>- $\alpha\le1$
>- Per ogni soluzione $x$, $costo(x)\ge\alpha\cdot OPT(x)$ 

# Load balancing

>**Input**: $m$ macchine identiche; $n\ge m$ job, il job $j$ ha tempo di risoluzione $t_j$.
>- Il job $j$ deve essere eseguito continuamente su una macchina.
>- Una macchina può risolvere al massimo un job alla volta.

>[!info] Def.
>Sia $S[i]$ il sottoinsieme di job assegnati alla macchina $i$.
>Il **carico** della macchina $i$ è $$L[i]=\sum_{j\in S[i]}t_j.$$

>[!info] Def.
>Il **makespan** (tempo di produzione) è il carico massimo di ogni macchina. $$L=\max_i L[i].$$

**Load balancing**: Assegna ogni job ad una macchina per minimizzare il makespan.
![[Pasted image 20250525170808.png|center|500]]

>[!warning] **Claim**: Load Balancing è difficile anche se $m=2$.
>*Pf*. $\text{Partition}\le_p \text{Load-Balance}$.![[Pasted image 20250525171011.png|center|500]]

## Pianificazione degli elenchi

**Algoritmo List-Scheduling**:
- Si considerano $n$ job in un determinato ordine.
- Si assegna il job $j$ alla macchina $i$ il cui carico è il più basso al momento.

![[Pasted image 20250525171257.png|center|400]]

**Implementazione**: $O(n\log m)$ usando una coda con priorità per i carichi $L[k]$.
### Demo

![[list_scheduling.gif|center|500]]


