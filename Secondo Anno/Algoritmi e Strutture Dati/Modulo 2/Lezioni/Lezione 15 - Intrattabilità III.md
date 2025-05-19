# Riduzioni polinomiali di NP-Completezza
## Super Mario
Alcuni videogiochi sono computazionalmente difficili. Vengono presi sotto esame alcuni livelli del videogioco "Super Mario" della Nintendo. Nello specifico, è possibile ridurre degli scenari di Super Mario al problema NP-Completo 3SAT:

>3-SAT
>**Input**: Una formula booleana formata da 3 clausole letterali su $n$ variabili.
>**Goal**: Esiste un'assegnazione soddisfacibile (ovvero che rende vere tutte le clausole)?

$$\Phi=(\lnot x_1\lor x_2\lor x_3)\land(x_1 \lor\lnot x_2\lor x_3)\land(\lnot x_1\lor x_2\lor x_4)$$
*Istanza si*: $x_1=TRUE,x_2=FALSE,x_3=FALSE,x_4=FALSE$

**Idea**: Data un'istanza di 3SAT costruiamo un livello/istanza di Super Mario risolvibile se e solo se la formula è soddisfacibile.

Visivamente:
![[Pasted image 20250516154829.png|center|600]]


**Gadget di variabile**: ![[Pasted image 20250516154742.png|center|500]]
**Gadget di clausola**:
![[Pasted image 20250516154913.png|center|500]]

**Gadget di Crossover**
![[Pasted image 20250516154956.png|center|500]]

## Peg Solitaire
![[fun_peg.gif|center|500]]

>[!note] Goal
>Trovare una sequenza di mosse da una configurazione iniziale per arrivare alla desiderata

È **NP-Completo** decidere **se** la tavola può essere pulita. Questo problema *può essere ridotto dal problema* Hamiltonian Cycle.

>Hamiltonian Cycle
>	Applicato ad un grafo diretto planare (può essere disegnato in un piano in modo che nessun arco si sovrapponga ad un altro) di grado 3
>**Input**: Un grafo diretto planare $G$ dove ogni vertice ha grado 3
>**Goal**: $G$ ha un ciclo hamiltoniano?

Spoiler: **È NP-Completo**.
- Due tipi di nodi: ![[Pasted image 20250516160905.png|center|500]]
	- ![[Pasted image 20250516160945.png|center|500]]
	- ![[Pasted image 20250516160959.png|center|500]]
- Cavi/archi: ![[Pasted image 20250516161028.png|center|500]]
- Connessione dei gadget:![[connection_peg.gif|center|500]]
**Claim**: Si può pulire la tavola solo se $G$ ha un ciclo hamiltoniano.
*Pf.*$\Leftarrow$
Se esiste un ciclo hamiltoniano $C$:
- Prima elimina/pulisci gli archi che non appartengono a $C$;
- Pulisci i nodi rimanenti passando per $C$.
*Pf.*$\Rightarrow$
Intuitivamente: Se si vuole pulire la tavola si devono utilizzare i gadget nel loro modo previsto (altrimenti de base perdi).

Comportamento previsto:
**2-in-1-out**

![[2in1out.gif|center|500]]

**1-in-2-out**

![[1in2out.gif|center|500]]

# Tetris

>3-Partition
>**Input**: Una collezione $A$ di $n$ interi positivi $a_1,...,a_n$.
>**Goal**: È possibile *partizionare* $A$ in $n/3$ collezioni $A_1,A_2,A_3$ di somme uguali? es. $$\sum_{a\in A_1}a=...=\sum_{a\in A_\frac{n}{3}}a=\frac{\sum_{a\in A}a}{\frac{n}{3}}=t.$$
>- Fatto 1: 3-Partition è NP-Completo, anche se $t/4\lt a_i \lt t/2$.
>- **Oss**. Se assumiamo che $t/4\lt a_i \lt t/2$ abbiamo $|A_i|=3$ per ogni $A_i$
> - Fatto 2: 3-Partition è **NP-Hard**, ovvero è NPC anche se ogni $a_i$ è limitato polinomialmente in $n$ ($n$=numero di numeri).

![[Pasted image 20250519114531.png|center|500]]
**Input**: Una configurazione iniziale della tavola, e l'intera sequenza dei pezzi.
**Goal**: Si riesce a pulire la tavola?

![[Pasted image 20250519114703.png|center|500]]
![[Pasted image 20250519114739.png|center|500]]

![[3par-tetris.gif|center|500]]

![[Pasted image 20250519115609.png|center|500]]

E si continua finché la tavola non è pulita.
