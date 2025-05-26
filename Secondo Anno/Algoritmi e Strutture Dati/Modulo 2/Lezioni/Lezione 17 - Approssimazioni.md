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


### Analisi

>[!important] Th. `[Graham 1966]`
>L'algoritmo Greedy è una 2-Approssimazione.
>- Analisi del caso peggiore di un algoritmo di approssimazione
>- C'è bisogno di comparare i risultati delle soluzioni con un makespan ottimale $L^*$.

**Lemma 1**. Per ogni $k$: il makespan ottimale $L^*\ge t_k$.
*Pf.* Una delle macchine dovrà processare il job che consuma più tempo.

**Lemma 2**. Il makespan ottimale $L^*\ge\frac{1}{m}\sum_{k}t_k$.
*Pf*.
- Il tempo di processo totale è $\sum_k t_k$.
- Una delle $m$ macchine deve fare almeno una frazione di $\frac{1}{m}$ del lavoro.

>[!important] Th. `[Graham 1966]`
>L'algoritmo Greedy è una 2-Approssimazione.
>- Analisi del caso peggiore di un algoritmo di approssimazione
>- C'è bisogno di comparare i risultati delle soluzioni con un makespan ottimale $L^*$.
>
>*Pf*. Si consideri un carico $L[i]$ della macchina i (collo di bottiglia).
>- Sia $j$ l'ultimo job schedulato sulla macchina $i$.
>- Quando il job $j$ viene assegnato alla macchina $i$, $i$ ha il carico minore. Il suo carico prima dell'assegnazione è $L[i]-t_j$; quindi $L[i]-t_j\le L[k]$ per tutti i $1\le k\le m$.
>![[Pasted image 20250526110712.png|center|500]]
>- Somma di disuguaglianze su tutti i $k$ e divisione per $m$: $$\begin{align}
L[i]-t_j\le&\frac{1}{m}\sum_k L[k]\\
=\frac{1}{m}\sum_k t_k\\
\le L^*\\ \text{ (Lemma 2)}\uparrow
\end{align}$$
>- Ora, $L=L[i]=\underbrace{(L[i]-t_j)}_{\underbrace{\le L^*}_{\text{la disuguaglianza di sopra}}}+\underbrace{t_j}_{\underbrace{\le L^*}_{\text{Lemma 1}}}\le 2L^*$.

L'analisi è stretta? 
*Essenzialmente si*.
*Es.* $m$ macchine, i primi $m(m-1)$ job hanno lunghezza 1, l'ultimo job ha lunghezza $m$.![[Pasted image 20250526111806.png|center|500]]
![[Pasted image 20250526111822.png|center|500]]

### Regola LPT

>[!important] **Longest Processing Time** (*LPT*)
>Ordina $n$ job in ordine decrescente (dal più grande al più piccolo) di tempo di processo; Poi, esegui l'algoritmo di List Scheduling
>![[Pasted image 20250526112105.png|center|500]]

**Oss**. Se la macchina collo di bottiglia $i$ ha solo 1 job, allora è ottimale.
*Pf*. Ogni soluzione deve schedulare quel job.

**Lemma 3**. Se ci sono più di $m$ job, $L^*\le 2t_{m+1}$.
*Pf*.
- Si consideri il tempo di processo dei primi $m+1$ job $t_1\ge t_2\ge\dots\ge t_{m+1}$.
- Ognuno impiega almeno tempo $t_{m+1}$.
- Ci sono $m+1$ job ed $m$ macchine, quindi per il [[https://it.wikipedia.org/wiki/Principio_dei_cassetti|principio della piccionaia]], almeno una macchina ha 2 job.

>[!important] Th. La regola LPT è un algoritmo di $\frac{3}{2}$-approssimazione.
>*Pf*. `[simile a list-scheduling]`
>- Si consideri il carico $L[i]$ della macchina-collo di bottiglia $i$-
>- Sia $j$ l'ultimo job schedulato sulla macchina $i$ (Assumendo che la macchina i abbia almeno 2 job, abbiamo $j\ge m+1$). $$L=L[i]=\underbrace{(L[i]-t_j)}_{\underbrace{\le L^*}_{\text{come prima}}}+\underbrace{t_j}_{\underbrace{\le \frac{1}{2}L^*}_{\text{Lemma 3(dato che }t_{m+1}\ge t_j)}}\le\frac{3}{2}L^*$$

# k-Center
**Input**: Insieme di $n$ siti $s_1,...,s_n$ ed un intero $k\gt 0$.

**Center Selection Problem**: Seleziona $k$ centri $C$ in modo che la massima distanza da un sito al suo centro più vicino sia minimizzata.

![[k_center.gif|center|500]]

>[!info] Notazione:
>- $dist(x,y)=$ distanza tra $x$ ed $y$.
>- $dist(s_i,C)=\min_{c\in C} dist(s_i,c)$= distanza tra $s_i$ al centro più vicino.
>- $r(C)=\max_i dist(s_i,C)=$ raggio coprente più piccolo.

**Goal**: Trovare un insieme di centri $C$ che minimizza $r(C)$, soggetto a $|C|=k$.

