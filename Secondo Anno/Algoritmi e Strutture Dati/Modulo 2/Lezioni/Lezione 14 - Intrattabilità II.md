# P $v_s$ NP

**Problema decisionale**:
- Il problema $X$ è un insieme di stringhe;
- L'istanza $s$ è una stringa;
- L'algoritmo $A$ risolve il problema $X$: $A(s)=\begin{cases}yes&if\ s\in X \\ no & if\ s\not\in X\end{cases}$

>[!important] L'algoritmo $A$ viene eseguito in *tempo polinomiale* se per ogni stringa $s$, $A(s)$ termina in $\le p(|s|)$ "passi", dove $p(\cdot)$ è una qualche funzione polinomiale.

## P

>[!def] **P** = insieme di problemi decizionali per i quali esiste un algoritmo polinomiale su una macchina di Turing deterministica.

![[Pasted image 20250514111240.png|center|500]]
![[Pasted image 20250514111331.png|center|550]]

## NP

>[!important] L'algoritmo $C(s,t)$ è un **certificatore** per il problema $X$ se per ogni stringa $s$: $s\in X\iff\exists string\ t:[C(s,t)=yes]$.

>[!important] **NP**= insieme di problemi di decisioni per i quali esiste un **certificatore polinomiale**.
>- $C(s,t)$ è un algoritmo polinomiale;
>- Il certificato $t$ è di grandezza polinomiale: $|t|\le p(|s|)$ per qualche $p(\cdot)$ polinomiale.

![[Pasted image 20250514111926.png|center|500]]
## Certificati e certificatori: soddisfacibilità

**SAT**: Data una formula $\Phi$ in CNF, essa ha un'assegnazione di verità soddisfacibile?
**3-SAT**: SAT in cui ogni clausola contiene esattamente 3 letterali.

**Certificato**: Un'assegnazione di valori di verità alle variabili booleane.
**Certificatore**: Certifica che ogni clausola in $\Phi$ ha almeno un letterale vero.

![[Pasted image 20250514112522.png|center|500]]

>Conclusione: $SAT\in NP, 3-SAT\in NP$

![[Pasted image 20250514115948.png|center|500]]

### Percorso Hamiltoniano

>[!important] Percorso Hamiltoniano
>Dato un grafo indiretto $G=(V,E)$, esiste un percorso semplice $P$ che visita ogni nodo?

**Certificato**: Una permutazione $\pi$ degli $n$ nodi.
**Certificatore**: Certifica se $\pi$ contiene ogni nodo in $V$ esattamente una volta, e che $G$ contenga un arco tra ogni coppia di nodi adiacenti.

![[Pasted image 20250514114310.png|center|500]]

>Conclusione: $HP\in NP$.

### Due problemi che probabilmente non appartengono ad NP

>**Scacchi**: Data una posizione specifica di una tavola $n\cdot n$ di scacchi, si può garantire la vittoria del nero?

>**Co-Longest-Path**: Dato un grafo indiretto $G=(V,E)$, la lunghezza del percorso semplice $P$ è $\le k$?

## P, NP ed EXP

- *P*: Problemi decisionali per cui esiste un algoritmo polinomiale che lo risolve;
- *NP*: Problemi decisionali per cui esiste un certificatore polinomiale;
- *EXP*: Problemi decisionali per cui esiste un algoritmo esponenziale che lo risolve. 

>[!important] Proposizione: $P\subseteq NP$.
>**Pf**. Si consideri un qualunque problema $X\in P$.
>- Per definizione, esiste un algoritmo polinomiale $A(s)$ che lo risolve;
>- Certificato $t=\varepsilon$, Certificatore $C(s,t)=A(s)$.

>[!important] Proposizione: $NP\subseteq EXP$
>**Pf**. Si consideri un qualunque problema $X\in NP$.
>- Per definizione, allora esiste un certificatore polinomiale $C(s,t)$ per $X$, che certifica che $t$ soddisfi $|t|\le p(|s|)$ per qualche polinomiale $p(\cdot)$;
>- Per risolvere l'istanza $s$, esegue $C(s,t)$ su tutte le stringhe $t$ con $|t|\le p(|s|)$.
>- Restituisce $yes$ se e solo se $C(s,t)$ restituisce $yes$ per ogni altro potenziale certificato.

>$P\not= EXP\implies P\not= NP, NP\not= EXP.$

## P vs. NP

Ma quindi, **P=NP?**
![[Pasted image 20250514122017.png|center|500]]

- Se si, esistono algoritmi efficienti per 3SAT, TSP, VC,...
- Se no, non esistono algoritmi efficienti per gli stessi

**Opinione condivisa da tutti**: probabilmente no.

# NP-Completezza
## Trasformazioni polinomiali

>[!info] Il problema $X$ si *riduce polinomialmente* (Cook) al problema $Y$ se istanze arbitrarie del problema $X$ possono essere risolte computando:
>- Un numero polinomiale di step computazionali standard, e;
>- Un numero polinomiale di chiamate alla struttura dati che risolve il problema $Y$.

>[!info] Il problema $X$ si *trasforma polinomialmente* (Karp) al problema $Y$ se data una qualsiasi istanza $x$ di $X$, possiamo costruire un'istanza $y$ di $Y$ tale che $x$ è un'istanza si di $X$ se e solo se $y$ è un'istanza si di $Y$.
>

**Nota**. Le trasformazioni polinomiali sono riduzioni polinomiali con una sola chiamata all'oracolo per $Y$, esattamente alla fine dell'algoritmo per $X$. Quasi tutte le precedenti riduzioni sono di questa forma.

## NPC

>[!important] NP-Completezza
>Un problema $Y\in NP$ con la proprietà che per ogni problema $X\in NP$, $X\le_p Y$.

**Prop.** Supponiamo che $Y\in NP-Completo$. Allora, $Y\in P\iff P=NP$.
*Pf.* $\Leftarrow$ Se P=NP, allora $Y\in P\iff P=NP$
*Pf.* $\Rightarrow$ Supponiamo che $Y\in P$.
- Si consideri un qualunque problema $X\in NP$. Dato che $X\le_p NP$, allora $X\in P$.
- Quindi $NP\subseteq P$.
- Sappiamo già che $P\subseteq NP$. Quindi... $P=NP$.

>Domanda fondamentale: **Esistono problemi NP-Completi "naturali"**?

>[!important] Th. Cook-Levin: SAT è NP-Completo

## Stabilire l'NP-Completezza

Una volta stabilito il primo problema NP-Completo "naturale", gli altri seguono facilmente.

>**Procedimento**: Per provbare che $Y\in NPC$
>1. Mostrare che $Y\in NP$
>2. Scegliere un problema NPC $X$
>3. Provare che $X\le_p Y$.

**Prop**. Se $X\in NPC$, $Y\in NP$ ed $X\le_p Y$, allora $Y\in NPC$.
*Pf*. Si consideri un qualsiasi problema $W\in NP$. Allora, vale che sia $W\le_p X$ sia che $X\le_p Y$.
- Per transitività, $W\le_p Y$.
- Quindi $Y\in NPC$.

# Co-NP

## Asimmetria di NP

**Asimmetria** : Noi abbiamo bisogno di certificati "corti" solo per le istanze *si*

**Esempio 1** SAT vs. Co-SAT
- Possiamo provare che una formula in CNF è soddisfacibile specificando un assegnamento
- Come possiamo provare che la formula non è soddisfacibile

**Esempio 2** Hamiltonian Cycle vs. Co-Hamiltonian Cycle
- Possiamo provare che un grafo sia Hamiltoniano specificando una permutazione
- Come possiamo provare che un grafo non è Hamiltoniano?

**Q** : Come classifichiamo Co-SAT e Co-Hamiltonian Cycle?
- SAT è NPC e SAT$\equiv_p$Co-SAT
- HamiltonianCycle è NPC e HamiltonianCycle$\equiv_p$Co-HamiltonianCycle
- Ma né Co-SAT né Co-HamiltonianCycle sono noti essere in **NP**

## NP e Co-NP

>[!definition] Complemento
>Dato un problema decisionale $X$, il suo **complemento** $\overline{X}$ è lo stesso problema con le istanze `si` e `no` invertite



