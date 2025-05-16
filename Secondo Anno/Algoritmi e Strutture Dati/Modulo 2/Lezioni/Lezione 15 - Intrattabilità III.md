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

Comportamento previsto:

--- 

