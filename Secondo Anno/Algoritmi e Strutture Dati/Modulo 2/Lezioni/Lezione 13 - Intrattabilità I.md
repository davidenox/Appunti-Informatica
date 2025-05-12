# Riduzioni polinomiali
## Design pattern algoritmici ed antipattern

**Design pattern algoritmici**:
- Greedy
- Divide et Impera
-  Programmazione dinamica
- Dualità
- *Riduzioni*

**Design antipattern algoritmici**:
- *NP-Completezza* - Algoritmi in $O(n^k)$ 
- PSPACE-Completezza - Certificati degli algoritmi in $O(n^k)$
- Indecidibilità - Non esiste un algoritmo

## Classificazione dei problemi dati i requisiti computazionali

**Q**: Quali problemi possiamo effettivamente risolvere in pratica?
> Quelli con algoritmi polinomiali.

![[Pasted image 20250512101853.png|center|400]]


## Classificazione dei problemi

**Ottimo**: Classificare i problemi in base a quali possono essere risolti in tempo polinomiale e quali no.

*Dimostrarlo richiede tempo esponenziale*.
- Dato un programma di grandezza costante, si ferma in al più $k$ passi?
- Dato un posizionamento in una scacchiera $n\cdot n$, può vincere il nero?

>Un numero enorme di problemi fondamentali ha sfidato ogni classificazione per decenni.

## Riduzioni polinomiali

Supponiamo di poter risolvere il problema Y in tempo polinomiale. Cos'èaltro possiamo risolvere in tempo polinomiale?

**Riduzione**: Il problema X in tempo polinomale si riduce al problema Y se istanze arbitrarie del problema X possono essere risolte usando:
- Numero polinomiale di passi computazionali standard, e
- Numero polinomiale di chiamate all'oracolo che risolve il problema Y

![[Pasted image 20250512102720.png|center|500]]

>[!note] Notazione $X\le_p Y$ 

Paghiamo per il tempo impiegato per scrivere le istanze di Y inviate all'oracolo $\implies$
le istanze di Y devono essere di dimensione polinomiale.


**Design di algoritmi**: Se $X\le_p Y$ ed Y può essere risolto in tempo polinomiale, allora *anche X può essere risolto in tempo polinomiale*.

**Intrattabilità**: Se $X\le_p Y$ ed X non può essere risolto in tempo polinomiale, allora *neanche Y può essere risolto in tempo polinomiale*.

**Equivalenza**: Se $X\le_p Y$ e $Y\le_p X$ usiamo la notazione $X\equiv_p Y$. In questo caso, *X può essere risolto in tempo polinomiale se e solo se lo è anche Y*.

**Linea di fondo**: Le riduzioni classificano i problemi in base ad una difficoltà *relativa*.

# Problemi di raggruppamento e copertura
## Indipendent Set

>[!important] Indipendent Set
>Dato un grafo $G=(V,E)$ ed un intero $k$, c'è un sottoinsieme di $k$ (o più) nodi tali che non siano adiacenti?

![[Pasted image 20250512103606.png|center|500]]
## Vertex Cover

>[!important] Vertex Cover
>Dato un grafo $G=(V,E)$ ed un intero $k$, esiste un sottoinsieme di $k$ nodi (o meno) tali che ogni arco è incidente ad almeno un nodo in quel sottoinsieme?

![[Pasted image 20250512103737.png|center|500]]
### VC e IS si riducono ad altro

>[!important] $IS\equiv_p VC$
>**Pf.**
>Rappresentiamo $S$ come un Indipendent-Set di grandezza $k$ se e solo se $V-S$ è un Vertex-Cover di grandezza $n-k$.
>$\Rightarrow$
>- Sia $S$ un IS di grandezza $k$.
>- $V-S$ è di grandezza $n-k$.
>- Consideriamo un arco arbitrario $(u,v)\in E$.
>- $S$ indipendente $\implies$ 
>	- o $u\not\in S$ o $v\not\in S$, o entrambi.
>	- o $u\in V-S$ o $v\in V-S$, o entrambi.
>- Quindi, $V-S$ copre $(u,v)._\square$
>
>$\Leftarrow$
>- Sia $V-S$ un VC di grandezza $n-k$.
>- $S$ è di grandezza $k$.
>- Cosideriamo un arco arbitrario $(u,v)\in E$.
>- $V-S$ è un VC $\implies$
>	- o $u\in V-S$ o $v\in V-S$, o entrambi.
>	- o $u\not\in S$ o $v\not\in S$, o entrambi.
>- Quindi, $S$ è un Indipendent Set.$_\square$

## Set Cover
>[!important] Set Cover
>Dato un insieme $U$ di elementi, una collezione $S$ di sottoinsiemi di $U$, ed un intero $k$, esistono $\le k$ di questi sottoinsiemi la cui unione è $U$?

**Esempio di applicazione**:
- $m$ software disponibili.
- Impostare $U$ di $n$ capacità che vorremmo che il nostro sistema avesse.
- L'$i-$esimo software fornisce l'insieme $S_i\subseteq U$ di capacità.
- *Obiettivo*: ottenere tutte le $n$ capacità utilizzando il minor numero di software.
![[Pasted image 20250512111336.png|center|300]]

**Altro esempio**: Dato l'universo $U=\{1,2,3,4,5,6,7\}$ ed i seguenti insiemi, qual è il Set-Cover di grandezza minima?
![[Pasted image 20250512111700.png|center|500]]

### Vertex-Cover si riduce a Set-Cover

>[!definition] Th. Vertex Cover $\leq_p$ Set Cover

**Dimostrazione** : Data un'istanza di Vertex Cover $G=(V,E)$ e $k$, costruiamo un'istanza di Set Cover $(U,S,k)$ che ha un set cover di dimensione $k\iff G$ ha un vertex cover di dimensione $k$

**Costruzione**
- Universo $U=E$
- Includiamo un sottoinsieme per ogni nodo $$v\in V:S_v=\{e\in E:\text{e incidente a v}\}$$
![[Pasted image 20250512113309.png|center|500]]

>[!definition] Lemma
>$G=(V,E)$ contiene un vertex cover di dimensione $k\iff(U,S,k)$ contiene un set cover di dimensione $k$


**Dimostrazione** $\implies$
- Sia $X\subseteq V$ un vertex cover di dimensione $k$ in $G$
	- Allora $Y=\{S_v:v\in X\}$ è un vertex cover di dimensione $k$

![[Pasted image 20250512113339.png|center|500]]

*L'istanza "si" di Vertex Cover è stata risolta correttamente*

$\impliedby$
- Sia $Y\subseteq S$ un set cover di dimensione $k$ in $(U,S,k)$
	- Allora $X=\{v:S_v\in Y\}$ è un vertex cover di dimensione $k$

*L'istanza "no" di Vertex Cover è stata risolta correttamente*

# Problemi di soddisfazione dei vincoli

## Soddisfacibilità

Prima di parlare del problema **SAT**, diamo la definizione di **Letterale, Clausola e Forma Normale Congiuntiva**

>[!definition] Letterale
>Una variabile booleana o la sua negazione $$x_i\lor\lnot x_i$$

>[!definition] Clausola
>Una disgiunzione di clausole $$C_j=x_1\lor\lnot x_2\lor x_3$$

>[!definition] Forma Normale Congiuntiva (CNF)
>Una formula proposizionale $\Phi$ che è una congiunzione di clausole $$\Phi=C_1\land C_2\land C_3\land\dots$$

Possiamo ora parlare del problema **SAT**

>[!definition] SAT
>Data una formula $\Phi$ in CNF, essa ha un assegnazione di verità?
>Ovvero, esiste un modo di assegnare le variabili in modo tale da avere che la formula $\Phi$ risulti vera?

>[!definition] 3-SAT
>Generalizzazione del problema SAT, dove ogni clausola ha esattamente 3 letterali
>Per esempio $$\Phi=(\lnot x_1\lor x_2\lor x_3)\land(x_1\lor\lnot x_2\lor x_3)\land(\lnot x_1\lor x_2\lor x_4)$$

L'istanza "si" per l'esempio sopra è
- $x_1=x_2=true$
- $x_3=x_4=false$

#### Il problema SAT è NP-Hard

**Ipotesi scientifica** : Non esiste un algoritmo polinomiale per 3-SAT

>[!error] $P$ vs $NP$
>Questa ipotesi è equivalente alla congettura $P\neq NP$

### 3-SAT si riduce a Indipendent Set

>[!definition] Teorema
>3-SAT $\leq_p$ Indipendent Set

**Dim**
Data un'istanza $\Phi$ di 3-SAT, costruiamo un istanza $(G,k)$ di Indipendet Set che ha un indipendent set di dimensione $k=\vert\Phi\vert\iff\Phi$ è ***soddisfacibile***

**Costruzione**
- $G$ contiene 3 nodi per ogni clausola, uno per ogni letterale
- Connetti i 3 letterali nella clausola in un triangolo
- Connetti ogni letterale con la sua negazione

![[Pasted image 20250512113947.png|center|500]]

**Lemma** : $\Phi$ è soddisfacibile $\iff G$ contiene un insieme indipendente di dimensione $k=\vert\Phi\vert$

**Dimostrazione** $\implies$
- Consideriamo ogni assegnamento soddisfacente per $\Phi$
- Selezionamo un letterale vero da ogni clausola/triangolo
- Questo è un indipendent set di dimensione $k=\vert\Phi\vert$

*L'istanza "si" di 3-SAT è stata risolta correttamente*

$\impliedby$
- Sia $S$ un indipendent set di dimensione $k$
- $S$ deve contenere esattamente un nodo da ogni triangolo
- Impostiamo questi letterali a `true`
- Tutte le clausole in $\Phi$ sono soddisfatte

*L'istanza "no" di 3-SAT è stata risolta correttamente*

# Riduzioni Polinomiali

![[Pasted image 20250512114036.png|center|500]]
