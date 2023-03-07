# State elimination

Procedura iterativa di eliminazione degli stati su un automa non deterministico **generalizzato** equivalente, in cui:
1. La funzione di transizione è definita su $Q\times E$, dove $E$ è l'insieme delle espressioni regolari su $\Sigma$, per cui gli archi sono etichettati con e.r
2. Lo stato inziale non ha archi entranti, per cui : $\not\exists q\in Q,e\in E : q_0\in\delta_N(q,e)$
3. Esiste un solo stato finale $q_F$ senza archi uscenti, per cui: $\not\exists e\in E:\delta_N(q_F,e)\neq\emptyset$

Dato un qualunque automa $\mathcal A$ non deterministico, un automa **generalizzato** $\mathcal A'$ equivalente può essere immediatamente ottenuto:
1. mantenendo gli stati di $\mathcal A$
2. introducendo, per ogni arco del grafo di transizione di $\mathcal A$ etichettato con l'insieme $a_1,...,a_k$, un arco nel grafo di transizione di $\mathcal A'$ etichettato $a_1+...+a_k$
3. Se lo stato iniziale $q_0$ di $\mathcal A$ ha archi entranti, introducendo in $\mathcal A'$ un nuovo stato iniziale $\overline q_0$ senza archi entranti, e la $\varepsilon$-transizione $\delta_N'(\overline q_0,\varepsilon)=\lbrace q_0\rbrace$
4. se esistono più stati finali in $F$, o se il solo stato finale ha archi uscenti, introducendo un ulteriore stato $q_F$, ponendo $F'=q_F$ e introducendo la $\varepsilon$-transizione $\delta_N'(\overline q_0,\varepsilon)=\lbrace q_F\rbrace$ per ogni $q\in F$

- Dato un automa non deterministico (con $\varepsilon$-transizioni) $\mathcal A$ con insieme di stati $Q$, e dato uno stato $q$ non iniziale né finale, è possibile ottenere un automa **generalizzato** equivalente $\mathcal A'$ con stati $Q−\{q\}$ effettuando una opportuna operazione di **eliminazione dello stato**
- L'eliminazione dello stato viene effettuata considerando tutti i possibili cammini di lunghezza 3 passanti per $q$ (sequenze $q_i,q,q_j$ per le quali esistono archi da $q_i$ a $q$ e da $q$ a $q_j$)
- Per ogni cammino, le etichette degli archi interessati vengono modificate come mostrato di seguito
- Al termine, rimangono lo stato iniziale e quello finale, collegati da un arco, la cui etichetta fornisce l'espressione regolare cercata

Infatti, avremo una situazione del genere
![[Pasted image 20221114124724.png|center|500]]

Le espressioni regolari possono essere comunque complesse
![[Pasted image 20221114125012.png|center|600]]

In effetti, se esistono n cammini $q_iq_jq_h(h=k_1,...,k_n)$, allora si ha che:
$$\overline r_{ik}=r_{ik_1}+r_{ij}r_{jj}^\star r_{jk_1}+r_{ik_2}+r_{ij}r_{jj}^\star r_{jk_2}+...+r_{ik_n}+r_{ij}r_{jj}^\star r_{jk_n}$$
lo stesso vale per $\overline r_{ki}$

# Chiusura dei linguaggi regolari

## Proprietà
Dato l’insieme dei linguaggi regolari, ci chiediamo quali siano le sue proprietà di chiusura rispetto avarie operazioni.
Ci chiediamo quindi se, data una qualunque operazione $\odot$:

- se $\odot$ è unaria, $\odot L$ è un linguaggio regolare per ogni $L$ regolare
- se $\odot$ è binaria, $L_1\odot L_2$ è un linguaggio regolare per ogni coppia $L_1,L_2$ di linguaggi regolari
- non consideriamo operatori di "arietà" maggiori

Le dimostrazioni di tali proprietà presentano tutte uno stesso schema, in cui, a partire dagli ASFD che riconoscono i linguaggi regolari dati, viene derivato un automa (deterministico o non deterministico) che riconosce il linguaggio risultante.

## Unione

Dati $L_1,L_2$, la loro unione $L_1\cup L_2$ è un linguaggio regolare
Infatti, siano $A_1=\langle\Sigma_1,Q_1,\delta_{N_1},q_0,F_1\rangle$ e $A_1=\langle\Sigma_2,Q_2,\delta_{N_2},q_0,F_2\rangle$ , due ASFD che accettano $L_1,L_2$
Costruiamo da $A_1,A_2$ un automa $A=\langle\Sigma,Q,\delta_N,q_0,F\rangle$ che riconosce il linguaggio $L_1\cup L_2$

**Costruzione**:
1. $\Sigma=\Sigma_1\cup\Sigma_2$
2. $Q=Q_1\cup Q_2\cup\lbrace q_0\rbrace$
3. $F=F_1\cup F_2$, oppure $F=F_1\cup F_2\cup\lbrace q_0\rbrace$ se uno dei due automi riconosce anche la stringa vuota
4. La funzione di transizione $\delta_N$ è definita come: $$\begin{cases}\delta_N(q,a)&=\delta_{N_1}(q,a)&se\:q\in Q_1,a\in\Sigma_1\\\delta_N(q,a)&=\delta_{N_2}(q,a)&se\:q\in Q_2,a\in\Sigma_2\\\delta_N(q_0,a)&=\delta_{N_1}(q_{0_1},a)\cup\delta_{N_1}(q_{0_2},a)&a\in\Sigma\end{cases}$$
**Esempio**

![[Pasted image 20221115093902.png|center|500]]
![[Pasted image 20221115093936.png|center|500]]


## Complemento

Dato un linguaggio regolare $L$, il suo complemento $\overline L$ è un linguaggio regolare
Infatti sia $A=\langle\Sigma,Q,\delta_N,q_0,F\rangle$ un automa che riconosce $L$, con funzione $\delta$ totale: l'automa
$$\overline{\mathcal A}=\langle\Sigma,Q,\delta,q_0,\lbrace Q-F\rbrace\rangle$$
riconosce allora il linguaggio $\overline L$

Infatti, ogni stringa che porta $\mathcal A$ in uno stato finale porta l'automa $\overline{\mathcal A}$ in uno stato non finale, e viceversa, ogni string che porta $\overline{\mathcal A}$ in uno stato finale, porta $\mathcal A$ in uno stato non finale

## Intersezione

Dati $L_1,L_2$, la loro intersezione $L=L_1\cap L_2$ è un linguaggio regolare

è sufficente osservare che, per la legge di De Morgan:
$$L=L_1\cap L_2=\overline{\overline L_1\cup\overline{L_2}}$$
## Concatenazione

Dati $L_1,L_2$, la loro intersezione $L=L_1\circ L_2$ è un linguaggio regolare

Infatti, siano $A_1=\langle\Sigma_1,Q_1,\delta_{N_1},q_0,F_1\rangle$ e $A_1=\langle\Sigma_2,Q_2,\delta_{N_2},q_0,F_2\rangle$ , due ASFD che accettano $L_1,L_2$
Costruiamo da $A_1,A_2$ un automa $A=\langle\Sigma,Q,\delta_N,q_0,F\rangle$ che riconosce il linguaggio $L_1\circ L_2$

**Costruzione**
1. $\Sigma=\Sigma_1\cup\Sigma_2$
2. $Q=Q_1\cup Q_2$
3. $$F=\begin{cases}F_2&se\:\varepsilon\not\in L(A_2)\\F_1\cup F_2&altrimenti\end{cases}$$
4. $q_0=q_{01}$
5. $\delta_N$ è definita in questo modo:$$\begin{cases}\delta_N(q,a)&=\delta_1(q,a)&\forall q\in Q_1-F_1,a\in\Sigma_1\\\delta_N(q,a)&=\delta_1(q,a)\cup\delta_2(q,a)&\forall q\in F_1,a\in\Sigma\\\delta_N(q,a)&=\delta_2(q,a)&\forall q\in Q_2,a\in\Sigma_2\end{cases}$$

**Esempio**

![[Pasted image 20221115095638.png|center|500]]
![[Pasted image 20221115095705.png|center|500]]

## Iterazione

Dato un linguaggio regolare $L$, la sua iterazione $L^\star$ è un linguaggio regolare

Infatti, sia $A=\langle\Sigma,Q,\delta_{N},q,F\rangle$ un ASFD che accetta $L$
Costruiamo da $A$ un automa $A'=\langle\Sigma,Q\cup\lbrace q_0'\rbrace,\delta',q_0',F\cup\lbrace q_0'\rbrace\rangle$ che riconosce il linguaggio $L^\star$ ponendo:
$$\begin{cases}\delta'(q,a)&=\delta(q,a)&\forall q\in Q-F\\\delta'(q,a)&=\delta(q,a)\cup\delta(q_0,a)&\forall q\in F\\\delta'(q_0',a)&=\delta(q_0,a)\end{cases}$$
**Esempio**
![[Pasted image 20221115111514.png|center|500]]

![[Pasted image 20221115111531.png|center|500]]



