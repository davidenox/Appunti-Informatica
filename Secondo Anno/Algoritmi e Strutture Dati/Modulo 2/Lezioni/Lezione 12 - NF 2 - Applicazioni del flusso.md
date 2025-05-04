# Matching Bipartito
>[!important] Matching
>Dato un grafo non diretto $G=(V,E)$, un sottoinsieme degli archi $M\subseteq E$ è un **matching** se ogni nodo compate in al massimo un arco in $M$.

**Max Matching**
Dato un grafo $G$, trovare un matching di massima cardinalità
![[Pasted image 20250504170950.png|center|500]]

Un grafo $G$ è *bipartito* se i nodi possono essere partizioniati in due sottoinsiemi $L$ e $R$ tale che ogni arco connette un nodo in $L$ con un nodo in $R$.

>[!important] Matching Bipartito
>Dato un grafo bipartito $G=(L\cup R,E)$, trovare un matching di massima cardinalità.

![[Pasted image 20250504171306.png|center|300]]

Dato un grafo $G=(V,E)$, un sottoinsieme di archi $M\subseteq E$ è un **perfect matching** se ogni nodo appare in esattamente un arco in $M$.

>[!warning] Problema del Perfect Matching
>Dato un grafo bipartito $G=(L\cup R,E)$, trovare un perfect matching o dimostrare che non esiste.

![[Pasted image 20250504172232.png|center|500]]

## Formulazione del MaxFlow
1. Creare un digrafo $G'=(L\cup R\cup\{s,t\},E')$;
2. A tutti gli archi che vanno da $L$ a $R$ assegniamo capacità *infinito*;
3. A tutti gli archi da $s$ a $L$ assegniamo capacità $1$;
4. Stessa cosa per gli archi da $R$ a $t$.

![[Pasted image 20250504173714.png|center|500]]

#### Dimostrazione di correttezza

>[!definition] Teorema
>Esiste una corrispondenza $1-1$ tra i matching di cardinalità $k$ in $G$ e i flussi interi ($\forall e:f(e)\in\{0,1\}$) di valore $k$ in $G'$

**Dim** $\implies$
- Sia $M$ un matching in $G$ di cardinalità $k$
- Considera un flusso $f$ che manda $1$ unità ad ognuno dei $k$ percorsi corrispondenti
- $f$ è un flusso di valore $k$

![[Pasted image 20250504173753.png|center|500]]

**Dim** $\impliedby$
- Sia $f$ un flusso integrale in $G'$ di valore $k$
- Considera $M=$ insieme di archi da $L$ a $R$ con $f(e)=1$
	- Ogni nodo in $L$ e $R$ partecipa in appare in al più un arco in $M$
	- $|M|=k$ : Applichiamo il lemma sul valore del flusso, al taglio $(L\cup\{s\},R\cup\{t\})$

![[Pasted image 20250504173808.png|center|500]]

**Corollario** : Si può risolvere il problema del matching bipartito tramite la formulazione max-flow

**Dim**
- Dal teorema di integralità $\implies$ Esiste un max flow $f^\star$ in $G'$ che è intero
- Corrispondenza $1-1\implies f^\star$ corrispoinde al matching di cardinalità massima

#### Tempo di esecuzione

Se usiamo Ford-Fulkerson, abbiamo $\leq n$ aumenti $\implies$Tempo $O(mn)$
## Percorsi Disgiunti

>[!definition] Definizione
>Due percorsi sono **disgiunti** se non hanno archi in comune

>[!definition] Problema dei percorsi disgiunti
>Dato un grafo diretto $G=(V,E)$ e due nodi $s,t$, trova il massimo numero di percorsi disgiunti $s\to t$


**Esempio** : Le reti di comunicazione

![[Pasted image 20250504175509.png|center|500]]
![[Pasted image 20250504175541.png|center|500]]

### Formulazione max-flow

**Formulazione max-flow** : Assegnare una capacità di $1$ ad ogni arco

>[!definition] Teorema
>C'è una corrispondenza $1-1$ tra i $k$ percorsi disgiunti $s\to t$ in $G$ e il valore $k$ del flusso in $G'$


**Dimostrazione** $\implies$
- Siano $P_1,\dots,P_k$ i $k$ percorsi disgiunti $s\to t$ in $G$
- Sia $$f(e)=\begin{cases}1&\text{arco e "partecipa" in qualche percorso }P_j\\0&\text{altrimenti}\end{cases}$$
- Dato che i percorsi sono disgiunti, $f$ è un flusso di valore $k$

![[Pasted image 20250504175611.png|center|500]]

**Dimostrazione** $\impliedby$
- Sia $f$ un flusso in $G'$ di valore $k$
- Consideriamo l'arco $(s,u)$ con $f(s,u)=1$
	- Per la conservazione del flusso, esiste un arco $(u,v)$ con $f(u,v)=1$
	- Continua finchè non raggiungi $t$, scegliendo sempre un nuovo arco
- Produce $k$ percorsi disgiunti (non necessariamente semplice) (si possono eliminare i cicli per ottenere percorsi semplici in tempo $O(mn)$ se si desidera)

**Corollario** : Si può risolvere il problema dei percorsi disgiunti usando la formulazione max-flow

**Dim** :
- Teorema di integralità $\implies$ Esiste un max-flow $f^\star$ in $G'$ che è intero
- Corrispondenza $1-1\implies f^\star$ corrisponde al massimo numero di percorsi disgiunti $s\to t$ in $G$
#### Tempo di esecuzione

Il tempo di esecuzione dell'algoritmo è il seguente
- Usando Ford-Fulkerson si hanno $\leq n$ aumenti $\implies$ tempo $O(mn)$
### Percorsi disgiunti su grafi non diretti

Il problema è identico al problema precedente, solo che il grafo in questione non è diretto

![[Pasted image 20250504175648.png|center|500]]

![[Pasted image 20250504175705.png|center|500]]

![[Pasted image 20250504175724.png|center|500]]
## Segmentazione dell'immagine

**Segmentazione dell'immagine** :
- Dividere l'immagine in regioni coerenti
- Problema centrale nel processing dell'immagine

**Esempio** : Separare l'umano e il robot dalla scena in background

![[Pasted image 20250504175753.png|center|500]]

**Segmentazione foreground/background**
- Un Label che dice se l'immagine appartiene al background o no
- $V=$ insieme di pixel, $E=$ coppie di pixel vicine
- $a_i\geq0$ è la probabilità che il pixel $i$ sia in foreground
- $b_i\geq0$ è la probabilità che il pixel $i$ sia in background
- $p_{ij}\geq0$ è la penalità di separazione per aver etichettato uno tra $i$ e $j$ come freground, e l'altro come backround

![[Pasted image 20250504175817.png|center|200]]

**Goal** :
- **Accuratezza** : se $a_i\gt b_i$, preferiamo etichettare $i$ come foreground
- **Smoothness** : se molti vicini di $i$ sono etichettati in primo piano, dovremmo essere propensi a etichettare $i$ come foreground
- Trovare una partizione $(\underbracket{A}_{\text{foreground}},\underbracket{B}_{\text{background}})$ che massimizza : $$\sum_{i\in A}a_i+\sum_{j\in B}b_j-\sum\limits_{(i,j)\in E\atop\vert A\cap\{i,j\}\vert=1}p_{ij}$$
SI può formulare come un problema di min-cut

Facciamolo diventare un **problema di minimizzazione**  :
- Massimizzare $\sum\limits_{i\in A}a_i+\sum\limits_{j\in B}b_j-\sum\limits_{(i,j)\in E\atop\vert A\cap\{i,j\}\vert=1}p_{ij}$
- È equivalente a minimizzare $$\underbracket{(\sum\limits_{i\in V}a_i+\sum\limits_{j\in V}b_j)}_{\text{una costante}}-\sum_{i\in A}a_i-\sum_{j\in B}b_j+\sum\limits_{(i,j)\in E\atop\vert A\cap\{i,j\}\vert=1}p_{ij}$$
Quindi, formulato come un problema di min-cut abbiamo :
- $G'=(V',E')$
- Per ogni pixel si crea un nodo
- Usiamo due archi antiparalleli al posto di un arco non diretto
- Aggiungiamo la sorgete $s$ che corrisponde al foreground
- Aggiungiamo il pozzo $t$ che corrisponde al background

Il grafo $G'$ sarà cosi fatto

![[Pasted image 20250504175905.png|center|500]]

![[Pasted image 20250504175921.png|center|200]]


Per essere precisi

**Consideriamo il min-cut** $(A,B)\in G'$
- $A=$ foreground
	- $$cap(A,B)=\sum\limits_{j\in B}a_j+\sum\limits_{i\in A}b_i-\sum\limits_{(i,j)\in E\atop i\in A, j\in B}p_{ij}$$
- Precisamente la quantità che vogliamo minimizzare

![[Pasted image 20250504175938.png|center|500]]

## Baseball Elimination

da finire