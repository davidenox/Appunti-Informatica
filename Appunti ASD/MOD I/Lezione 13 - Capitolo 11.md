# Grafi e visite di grafi

## Teoria dei grafi, problemi su grafi

### Origini storiche

Nel 1736, il matematico Eulero, affrontò l'annoso problema dei 7 ponti di Königsberg (Prussia)
![[appunti asd/mod i/immagini/Pasted image 20221214122043.png|center|400]]

è possibile o meno fare una passeggiata che parta da un **qualsiasi** punto della città e percorra **una ed una** sola volta ciascuno dei 7 ponti?

Eulero affrontò il problema schematizzando **topologicamente** la pianta della città, epurando così l'istanza da insignificanti dettagli **topografici**:
![[appunti asd/mod i/immagini/Pasted image 20221214122334.png|center]]

... e così Königsberg venne rappresentata con un insieme di **4 punti** (uno per ciascuna zona della città), opportunamente uniti da **7 linee** (una per ciascun ponte)

### Definizione di grafo (non orientato)

Un **grafo G=(V,E)** consiste in:
- Un insieme **V** di **vertici** (o nodi)
- Un insieme **E** di coppie (non ordinate) di vertici, detti **archi**

**Esempio**

Grafo di Eulero associato alla città di Königsberg:
- $V=\{A,B,C,D\}$
- $E=\{(A,B),(A,B),(A,D),(B,C),(B,C),(B,D),(B,D),(C,D)\}$

![[appunti asd/mod i/immagini/Pasted image 20221214123110.png|center]]

**Nota**: è più propriamente detto **multigrafo**, in quanto contiene **archi paralleli**

![[appunti asd/mod i/immagini/Pasted image 20221214123400.png|center|600]]

![[appunti asd/mod i/immagini/Pasted image 20221214123443.png|center|600]]

### Definizione di grafo diretto

Un **grafo diretto D=(V,A)** consiste in:
- Un insieme **V** di **vertici** (o **nodi**)
- Un insieme **A** di coppie **ordinate** di vertici, detti **archi diretti**

![[appunti asd/mod i/immagini/Pasted image 20221214123706.png|center|600]]

![[appunti asd/mod i/immagini/Pasted image 20221214123758.png|center|600]]

### Terminologia

- **G=(V,E)** grafo non diretto
- **n** = |V| numero di vertici
- **m** = |E| numero di archi
- **u** ed **v** sono **adiacenti**
- **(u,v)** è **incidente** a **u** e a **v** (detti **estremi**)
- $\delta(u)$: **grado** di **u**: numero archi incidenti a **u**
- **grado** di **G** = $max_{v\in V}\{\delta(v)\}$

![[appunti asd/mod i/immagini/Pasted image 20221214124123.png|center]]

### Che relazione c'è fra grado dei nodi e numero di archi?

#### Una semplice proprietà (grafi non diretti)

Cosa ottengo se sommo i gradi di ogni nodo?

![[appunti asd/mod i/immagini/Pasted image 20221214124257.png|center|400]]

>[!important]- Formula
>$$\sum_{v\in V}\delta(v)=2m$$

In ogni grafo il numero di nodi di grado dispari è pari

#### Una semplice proprietà (grafi diretti)

**Domanda (sui grafi diretti)**
Cosa ottengo se sommo il grado **uscente/entrante** di tutti i nodi?

![[appunti asd/mod i/immagini/Pasted image 20221214124551.png|center|400]]

>[!important]- Formula
>$$\sum_{v\in V}\delta_{out}(v)=\sum_{v\in V}\delta_{in}(v)=m$$


### Altra Terminologia

- **_cammino_**: sequenza di nodi connessi da archi
- **_lunghezza_** di un cammino: numero di archi del cammino
- **_distanza_**: la lunghezza del più corto cammino tra due vertici si dice **_distanza_** tra due vertici

![[appunti asd/mod i/immagini/Pasted image 20221214124943.png|center]]

**Esempio**:
distanza fra L e A: 4 (il cammino in questione è L-I-E-B-A)

In un grafo **orientato**, il cammino deve rispettare il verso di orientamento degli archi

- G è **connesso** se esiste un cammino per ogni coppia di vertici
- **ciclo**: un cammino chiuso, ovvero un cammino da un vertice a se stesso
- **diametro**: massima distanza fra due nodi_
	- $max_{u.v\in V}dist(u,v)$
	- il diametro di un grafo non connesso è $\infty$

![[appunti asd/mod i/immagini/Pasted image 20221214125445.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221214125541.png|center|600]]

Altri due grafi di diametro 2

![[appunti asd/mod i/immagini/Pasted image 20221214140325.png|center]]

- **Grafo pesato**: è un grafo **G=(V,E,w)** in cui ad ogni arco viene associato un valore definito dalla funzione peso w (definita su un opportuno insieme, di solito i reali)

![[appunti asd/mod i/immagini/Pasted image 20221214140535.png|center]]
![[appunti asd/mod i/immagini/Pasted image 20221214140551.png|center]]

### Quanti archi può avere un grafo di n nodi?

Due grafi molto particolari

- **Grafo totalmente sconnesso**: è un grafo G=(V,E) tale che $V\neq\emptyset$ ed $E=\emptyset$ ![[appunti asd/mod i/immagini/Pasted image 20221214140800.png|center]]
- **Grafo completo**: per ogni coppia di nodi esiste un arco che li congiunge. ![[appunti asd/mod i/immagini/Pasted image 20221214140900.png|center]]
Il grafo completo con n vertici verrà indicato con $K_n$

Vale, infatti:
$$m=|E|=n(n-1)/2$$
Il grafo completo in esempio ha $K_n=K_5$

Per rispondere alla domanda quindi:
- un grafo (senza cappi o archi paralleli) può avere un numero di archi m compreso tra $0$ e $n(n-1)/2=\Theta(n^2)$

### Come è fatto un grafo connesso con il minimo numero di archi?

_Def_

Un albero è un grafo connesso e aciclico

![[appunti asd/mod i/immagini/Pasted image 20221214141251.png|center|600]]

>[!important]- Teorema
>Sia **T=(V,E)** un albero, allora $|E|=|V|-1$

**Dim (per induzione su |V|)**

**Caso base**: $|V|=1\implies T=\text{un solo nodo}\implies |E|=0=|V|-1$
**Caso induttivo**: $|V|\gt1$. 
Sia n il numero di nodi di T. 
Poichè T è connesso e aciclico ha almeno una foglia (nodo con grado 1)
	**Oss**: Se tutti i nodi avessero grado almeno 2 ci sarebbe un ciclo (si vede perchè?)
Rimuovendo tale foglia si ottiene un grafo connesso e aciclico con n-1 nodi che per **ipotesi induttiva** ha n-2 archi
Quindi, T ha n-1 archi
![[appunti asd/mod i/immagini/Pasted image 20221214141849.png|center]]

$\square$ 

**Esercizio**

![[appunti asd/mod i/immagini/Pasted image 20221214142026.png|center]]

Per un grafo connesso con n nodi e m archi vale :
$$n-1\leq m\leq n(n-1)/2$$

Se G è connesso: $$m=\Omega(n),m=O(n^2)$$
**Nota bene**: Se un grafo ha $m\geq n-1$ archi, non è detto che sia connesso. Quanti archi deve avere un grafo per essere **sicuramente connesso?**


### ... Tornando al problema dei 7 ponti

>[!important]- Definizione (Ciclo Euleriano)
Dato un grafo G, un **ciclo** (rispettivamente un **cammino**) **Euleriano** è un ciclo (rispettivamente un **cammino** non chiuso) di G che passa per tutti gli archi di G una e una sola volta

>[!important]- Teorema (di Eulero)
>Un grafo G ammette un **ciclo Euleriano** se e solo se tutti i nodi hanno grado pari. Inoltre, ammette un **cammino Euleriano** se e solo se tutti i nodi hanno grado pari tranne due (i due nodi di grado dispari sono gli estremi del cammino)

![[appunti asd/mod i/immagini/Pasted image 20221214143312.png|center]]

## Perchè i grafi?

I grafi costituscono un linguaggio potente per descrivere oggetti e problemi algoritmici

### Vari esempi

#### Reti stradali e di trasporto

![[appunti asd/mod i/immagini/Pasted image 20221214143455.png|center|650]]

![[appunti asd/mod i/immagini/Pasted image 20221214143535.png|center|650]]

![[appunti asd/mod i/immagini/Pasted image 20221214143609.png|center|650]]

![[appunti asd/mod i/immagini/Pasted image 20221214143639.png|center|650]]

**Problema**: trovare il cammino minimo fra due nodi

![[appunti asd/mod i/immagini/Pasted image 20221214143741.png|center|650]]

Due soluzioni:
- Pesi archi: lunghezze $\implies$ Strada più breve
- Pesi archi: tempo percorrenza $\implies$ Strada più veloce

#### Reti sociali

![[appunti asd/mod i/immagini/Pasted image 20221214143923.png|center|650]]

![[appunti asd/mod i/immagini/Pasted image 20221214143951.png|center|650]]

![[appunti asd/mod i/immagini/Pasted image 20221214144048.png|center|650]]

![[appunti asd/mod i/immagini/Pasted image 20221214144118.png|center|650]]


**Kevin Bacon Number**: Distanza dal nodo Kevin Bacon

![[appunti asd/mod i/immagini/Pasted image 20221214144246.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221214144448.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221214144515.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221214144649.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221214144846.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221214144914.png|center]]

>[!quote]- Cit.
>Studia Algoritmi dicevano, è una materia seria dicevano...


#### Reti "delle dipendenze"

![[appunti asd/mod i/immagini/Pasted image 20221214145117.png|center]]

**Nodi**: compiti da svolgere
**Arco (u,v)**: u deve essere eseguito prima di v

**Esempi**:
- Esami e propedeucità
- Moduli software di un progetto e dipendenze
- ...

**Problema**: trovare un ordine in cuie seguire i compiti in modo da rispettare le dipendenze

![[appunti asd/mod i/immagini/Pasted image 20221214145402.png|center]]

Un altro esempio

![[appunti asd/mod i/immagini/Pasted image 20221214145602.png|center|300]]

**Nodi**: compiti da svolgere
**Arco (u,v)**: u e v _non_ possono essere svolti insieme

Esempi:
- Esami e vincoli
- certi esami non possono essere svolti lo stesso giorno (stesso anno, usano la stessa aula, ecc...)

**Problemi**:

1. Trovare max numero di compiti eseguibili
2. Trovare min numero di "gruppi" di compiti, t.c. compiti dello stesso gruppo possono essere eseguiti insieme

Nello specifico vale che:
- (1) = **Massimo insieme indipendente**: Trovare l'insieme X di nodi di cardinalità massima tale che per ogni u,v in X, u e v non sono **adiacenti**
- (2) = **Colorazione di un grafo**: Colorare i nodi del grafo risultante usando il minimo numero $\chi$ di colori in modo che due nodi **adiacenti** non abbiano lo stesso colore

$\chi$ : numero cromatico 

**Esempio**

![[appunti asd/mod i/immagini/Pasted image 20221214150439.png|center|600]]

Vale che : $\chi(G)=3$ 

Possiamo usare 2 colori? ..no: ogni ciclo da tre (triangolo) ha bisogno di almeno tre colori

"Per questa parte rimando agli appunti di Matematica Discreta, parte sui Grafi"

**Esercizio**

![[appunti asd/mod i/immagini/Pasted image 20221214150641.png|center]]



