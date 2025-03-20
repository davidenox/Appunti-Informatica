# Insieme indipendente di peso massimo
	Su grafi a cammino
>**Input**: Un cammino $G$ di $n$ nodi. Ogni nodo $v_i$ ha un *peso* $w_i$.

>**Goal**: Trovare un insieme indipendente di *peso massimo*, ovvero un insieme $S$ di nodi tale che:
>1. $S$ è un II
>2. $w(s)=\sum_{v_i\in S} w_i$ è più grande possibile.

![[Pasted image 20250320114429.png|center|500]]
Un *Insieme Indipendente* di $G$ è un sottoinsieme di nodi che non contiene due nodi adiacenti, ovvero per ogni coppia di nodi dell'insieme i due nodi non sono collegati da un arco.
![[ins_indip.gif|center|500]]
## Progettazione algoritmica
### Forza bruta: Enumerazione

>**Idea**: Enumeriamo tutti i sottoinsiemi degli $n$ nodi, per ciascuno verifichiamoche è in un insieme indipendente, ne calcoliamo il peso e teniamo quello di peso massimo.
>**Domanda**: Quanti sottoinsiemi guardiamo?
>**Risposta**: Tanti, Troppi! $2^n$

### Approccio greedy

>**Idea**: Costruisco la soluzione in modo incrementale scegliendo ogni volta il nodo indipendente di valore massimo.
>**Domanda**: Funziona?
![[greedy_ins_ind.gif|center|500]]
>**Risposta**: In questa istanza l'algoritmo funziona, ma è corretto davvero?
![[Pasted image 20250320142121.png|center|500]]
>Spoiler: NO

### Divide et Impera
>**Idea**: Divido il cammino a metà, calcolo ricorsivamente l'II di peso massimo sulle due metà e poi ricombino le soluzioni
>**Domanda**: È corretto?
>**Domanda**: Posso risolvere efficientemente i conflitti che ho quando ricombino?
![[Pasted image 20250320143303.png|center|500]]

Spoiler: è difficile ricombinare le soluzioni.

Non stiamo capendo la *struttura del problema*. La comprensione della struttura del problema porterà a sviluppare un *nuovo approccio*.

**Passaggio critico**: Ragionare sulla struttura/proprietà della soluzione ottima del problema.
*In termini di soluzioni ottime di sottoproblemi "più piccoli"* non è così diverso da come si ragiona implicitamente quando si usa la tecnica del divide-et-impera.
**Obiettivo**: Esprimere la *soluzione del problema* come combinazione di *soluzioni di (opportuni) sottoproblemi*. Se le combinazioni sono "poche", possiamo cercare la combinazione giusta per forza bruta.

Sia $S^*$ la soluzione ottima, ovvero l'II di peso massimo di $G$. Considera l'ultimo nodo $v_n$ di $G$.

>[!info]- Osservazione: $v_n\not\in S^*$ o $v_n\in S^*$

**Caso 1**: $v_n\not\in S^*$
- Considera $G'=G-\{v_n\}$.
- Allora $S^*$ è una soluzione ottima per $G'$.
- Se esistesse una soluzione $S$ migliore per $G'$, $S$ sarebbe migliore anche per $G$: ***Assurdo!*** 
![[Pasted image 20250320145041.png|center|500]]
**Caso 2**: $v_n\in S^*$
- Considera $G''=G-\{v_{n-1},v_n\}$.
- Allora $S^*-\{v_n\}$ è una soluzione ottima per $G''$.
- Se esistesse una soluzione $S$ migliore per $G''$, $S\cup\{v_n\}$ sarebbe migliore di $S^*$ per G: ***Assurdo***.
![[Pasted image 20250320145401.png|center|500]]

**Proprietà**: L' II di peso massimo per G deve essere o:
- L'II di peso massimo per $G'$
- $v_n$ unito all'II di peso massimo per $G''$
L'idea(*folle*) è di calcolare tutte e due le soluzioni e ritornare la migliore delle due. Il problema è il tempo di esecuzione, che diventa come Fibonacci2 ($\Theta(\phi^n)$) nel caso in cui quest'algoritmo calcola le due soluzioni ricorsivamente.

Però

Quanti problemi distinti sono risolti dall'algoritmo ricorsivo? $\Theta(n)$
**Idea**: Procediamo iterativamente considerando prefissi di $G$ dai più piccoli verso i più grandi.

$G_j$ :Sottocammino composto dai primi $j$ vertici di $G$.
*Sottoproblema* $j$: Calcolare il peso del miglior II per $G_j$.
`OPT[j]`: Valore soluzione *sottoproblema* $j$, ovvero peso dell'II di peso massimo di $G_j$.

$OPT[1]=w_1;OPT[2]=\max\{w_1,w_2\}$ 
$OPT[j]=\max\{OPT[j-1],w_j+OPT[j-2]\}$
![[Pasted image 20250320154609.png|center|500]]
