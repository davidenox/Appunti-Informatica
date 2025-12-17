# Agenti e ricerca

Un **agente risolutore di problemi** è un agente che simula una sequenza di azioni prima di eseguirle, al fine di arrivare allo stato obiettivo. Quindi l'agente simula una **ricerca**.
Questi agenti sono detti **agenti pianificatori**, poiché adottano una **rappresentazione atomica della realtà**, in cui lo stato del mondo è indivisibile e non ha struttura interna.
La scelta delle azioni di tali agenti dipende dall'ambiente in cui si trovano:

- Ambiente **ignoto**: 
	L'agente non può fare altro che scegliere azioni in maniera randomica:
- Ambiente **noto**: 
	L'agente raggiunge l'obiettivo eseguendo quattro fasi:
	1. **Formulazione dell'obiettivo**: Aiuta ad organizzare il comportamento limitando le azioni da considerare;
	2. **Formulazione del problema**: Definisce gli stati e le azioni utili per l'obiettivo;
	3. **Ricerca**: Simula sequenze di azioni finché non trova la soluzione ( può anche non esserci );
	4. **Esecuzione**: Esegue le azioni indicate dalla soluzione.

Si può notare che se l'ambiente è *deterministico, noto ed osservabile* allora l'agente può ignorare le percezioni, poiché l'agente ha tutte le informazioni affinché possa ricavare una sequenza di azioni. Quindi, si va a rompere la relazione percezione-azione, avendo così un **sistema ad anello aperto**. In caso contrario (ambiente non deterministico o modello errato) si ha un **sistema ad anello chiuso**.

## Problema di ricerca

Un problema di ricerca è composto da:

- *Un insieme di stati*;
- *Uno stato iniziale*;
- *Uno o più stati obiettivo*;
- *Azioni che può compiere l'agente in base allo stato dell'ambiente*;
- *Un modello di transazione*;
- *Una funzione di costo dell'azione*.

L'insieme degli stati e le azioni dell'agente possono essere rappresentati tramite un **grafo orientato e pesato** in cui i nodi rappresentano gli stati e gli archi le azioni che possono essere applicati allo stato. Perciò, l'obiettivo dell'agente è **il cammino di costo minimo che raggiunge lo stato obiettivo**.

È possibile rappresentare i cammini per raggiungere lo stato obiettivo tramite un **albero di ricerca** in cui:
- Root = Stato iniziale;
- Nodo = Qualunque stato;
- Ramo = Azione qualunque.
A sua volta, il nodo può essere definito come una *struttura dati* composta da informazioni come:
- Stato del nodo;
- Padre del nodo;
- Azione eseguita dal nodo padre per generare il nodo corrente;
- Costo del cammino dalla radice al nodo corrente.

## Strategie di ricerca non informata
### BFS

>**Quando usarla**:
>	È utile utilizzare la BFS quando tutte le azioni hanno lo stesso costo.
>**Come funziona**:
>	Dalla radice, si visitano tutti i nodi per gradi di profondità dell'albero. Prima di visitare un qualunque nodo, si verifica se è lo stato obiettivo: in tal caso, si riporta la *soluzione*, altrimenti si visita il nodo e si generano i nodi figli, che verranno inseriti in una coda FIFO.
>**Vantaggi**:
>	La ricerca trova la soluzione con un numero minimo di azioni, poiché, quando genera i nodi di profondità $d$, ha già generato tutti i nodi di profondità $d-1$.
>**Funzione di valutazione** $f(n)$:
>	Numero di azioni per raggiungere $n$.
>**Costo**: 
>	$O(b^d)$ sia dal punto di vista spaziale che temporale, con $b=foglie$ e $d=profondità$.

### Dijkstra

>**Quando usarlo**:
>	Si utilizza l'algoritmo di Dijkstra quando le azioni hanno costi differenti.
>**Come funziona**: 
>	Ad ogni azione, aggiunge ad un insieme $X$ di nodi il nodo la cui stima della distanza radice-nodo è minima. Se durante la ricerca trova un arco che raggiunge lo stesso nodo già bisitato con distanza minore rispetto al cammino precedente allora lo sostituisce.
>**Funzione di valutazione** $f(n)$: 
>	Costo del cammino.
>**Costo**:
>	$O(b^{(1+\frac{C^*}{\varepsilon})})$ dove $C^*$ è il costo della soluzione ottima e $\varepsilon$ il limite inferiore al costo.

### DFS

>**Quando usarla**:
>	È utile utilizzare la DFS per gli spazi degli stati finiti.
>**Come funziona**:
>	Dalla radice si scende di nodo in nodo fino ad una foglia, risalendo poi o al nodo padre o al figlio non visitato.
>**Vantaggi**:
>	Poca memoria necessaria, inesistenza di una tabella di nodi raggiunti e riduzione dei nodi nella frontiera.
>**Costo**:
>	$O(b\cdot m)$ dove $b$ è il fattore di ramificazione ed $m$ la massima profondità dell'albero.
>
>**Variante**: Backtracking
>**Come funziona**: 
>	Dopo aver visitato un nodo, viene generato un solo suo successore, e vengono ricordati i successori ancora da generare. I successori sono generati modificando la descrizione dello stato corrente.
>**Vantaggio**: 
>	Viene allocata meno memoria - $O(m)$.
>
>**Variante**: Profondità limitata
>**Quando usarla**:
>	Anche per spazi degli stati infiniti, poiché viene posto un limite di profondità $l$ per evitare che l'algoritmo si perda in un cammino infinito. Scelta di $l$ importante.
>**Costo**:
>	$O(b^l)$ Temporale e $O(b\cdot l)$ Spaziale.
>	
>**Variante**: Approfondimento iterativo
>**Come funziona**:
>	Pone una ricerca all'incrementare del valore $l$. Quindi, parte per $l=1$  e se fallisce parte con $l=2$  e così via.
>	
>**Variante**: Ricerca bidirezionale
>**Come funziona**: 
>	L'algoritmo si muove verso due direzioni: dallo stato iniziale allo stato obiettivo e viceversa, espandendo il nodo con il valore minimo della funzione di valutazione. Si ha una soluzione quando le due frontiere si incontrano.

## Algoritmi di ricerca informata

L'agente deve essere in grado di *stimare* quanto lontano si trovi dall'obiettivo, in modo da scegliere la direzione più promettente da seguire. Per raggiungere questo scopo, l'agente utilizza una **funzione euristica** che rappresenta una valutazione del costo stimanto per arrivare all'obiettivo a partire dallo stato attuale.
Questa funzione $h$ associa a ciascun nodo $n$ una stima numerica $h(n)$ del costo del cammino più economico che porta dallo stato attuale allo stato obiettivo.

### Best-First Greedy

>**Funzione di valutazione**: 
>	$f(n)=h(n)$.
>**Funzionamento**: 
>	Espande i nodi con $h(n)$ minimo.
>**Vantaggio**:
>	Non espande nodi superflui che non portano alla soluzione.
>**Svantaggio**: 
>	La soluzione non ha il costo ottimale.
>**Costo**:
>	$O(|V|)$ Temporale e Spaziale; $O(b\cdot m)$ con una buona euristica.

### A*

L'algoritmo A* utilizza la funzione di valutazione $f(n)=g(n)+h(n)$, dove:

- $g(n)$ è il costo effettivo del cammino dalla radice al nodo $n$;
- $h(n)$ è il costo stimato del cammino dal nodo $n$ allo stato obiettivo.

Per verificare l'ottimalità dell'algoritmo è importante introdurre i concetti di:

- **Ammissibilità**: La funzione euristica non sovrastima mai il costo per raggiungere un obiettivo;
- **Consistenza**: Per ogni nodo $n$ e suo successore $n'$ generato da un'azione $a$, deve valere $h(n)\le c(n,a,n')+h(n)$.

>[!important] Prima proprietà
>Se l'euristica è consistente, allora è ammissibile, e quindi ottima rispetto al costo.

>[!important] Seconda proprietà
>Con un'euristica consistente, il primo percorso per raggiungere uno stato è ottimo.

Se l'euristica *non* è ammissibile, esistono due casi di ottimalità rispetto al costo:

- Se esiste un solo cammino ottimo rispetto al costo lungo cui $h(n)$ è ammissibile per ogni $n$ sul suo cammino, allora tale cammino verrà trovato;
- Se $h(n)$ sovrastima alcuni costi ma non è mai $\lt C_2-C^*$, allora A* restituisce sempre soluzioni ottime rispetto al costo.

Una problematica di A* è lo spazio in memoria: $O(b^d)$. È possibile migliorare tale risultato con l'algoritmo **Beam Search**, che mantiene solamente i $k$ nodi più 'promettenti' della frontiera.

### ID A*
	A* con approfondimento iterativo

ID A* applica i vantaggi di A* e determina il valore di taglio dal *limite di costo*, non di profondità. Nella ricerca ID A* la soglia è $f(g+h)$, ovvero la somma tra stima e percorso complessivo. 
L'algoritmo ha costo $O(d\cdot b)$.
![[Pasted image 20251217122948.png|center|500]]

### Best-First Ricorsivo

Replica del comportamento del [[Ch.2 - Risolvere i problemi con la ricerca#Best-First Greedy|Best-First Greedy]], ma in spazio lineare. Aggiunge una variabile `f-limite` per tenere traccia del miglior cammino alternativo che si origina da un antenato del nodo corrente.
Quando il valore $f$ del nodo corrente supera il limite stabilito, l'algoritmo riparte dal cammino alternativo individuato. In questa fase il valore del nodo abbandonato viene aggiurnato con il miglior valore $f$ tra i figli, il che permette all'algoritmo di riesaminare quel nodo in un momento successivo in cui potrebbe essere conveniente espanderlo nuovamente.

### SM A*

Stessa funzione di valutazione di A*, ma gestisce diversamente la memoria.
Espande la foglia migliore fino ad esaurimento della memoria, per poi eliminare la foglia con il valore $f$ più alto e memorizzare quel valore nel nodo padre come '$f$ dimenticato'.
L'algoritmo può rigenerare quella foglia solo se tutti gli altri cammini hanno un valore $f$ maggiore rispetto al cammino abbandonato.
Questo algoritmo differenzia dagli altri per l'utilizzo intensivo della memoria, che permette di espandere il maggior numero possibile di nodi.

## Valutazioni delle funzioni euristiche

**Per essere ammissibile un'euristica non deve superare il costo effettivo delle operazioni necessarie per raggiungere la soluzione.** 

Negli algoritmi non informati la funzione euristica $h(n)$ assume il valore $0$ per ogni nodo $n$, mentre negli algoritmi di ricerca informata l'euristica $h^*(n)$ fornisce una stima esatta del costo per raggiungere la soluzione. In generale,$$0\le h(n)\le h^*(n)$$Se si considerano due euristiche $h_1$ ed $h_2$, con $h_1\le h_2$, allora $h_2$ possiede un **livello di informazione maggiore** rispetto ad $h_1$. Tuttavia, utilizzare $h_2$ in un algoritmo comporta tempi di ricerca ridotti per trovare il cammino ottimale, ma a fronte di un costo di calcolo più elevato rispetto ad $h_1$.

### Misura del potere euristico 

>**Fattore di diramazione effettivo** $b^*$:
>	Data una ricerca informata, si ha:
>	- $N$ = numero di nodi espansi;
>	- $d$ = profondità.
>	Sapendo che $N+1=1+(b^*)^1+(b^*)^2+\dots+(b^*)^d$ possiamo determinare $b^*$:
>Es. 
>$d=5,N=52\implies b^5+b^4+...+b-52=0\implies b=1,92$. 
>Una buona euristica ha $b^*\lt 1,5$.

### Invenzione di un'euristica
	Strategie

1. **Rilassamento del problema**:
	- Un *problema rilassato* è una versione semplificata del problema, ottenuta riducendo il numero di vincoli sulle azioni possibili. Questa semplificazione permette di definire euristiche specifiche per il problema rilassato, che forniscono una stima esatta del costo per risolverlo.
2. **Massimo di euristiche**:
	- Se un problema dispone di $m$ euristiche ammissibili, e nessuna di queste domina le altre, utilizziamo la combinazione: $$h(n)=\max\{h_1(n),...,h_m(n)\}.$$
	- In questo modo selezioniamo l'euristica che fornisce la stima più alta tra quelle disponibili, garantendo di risolvere il problema anche nel caso peggiore.
3. **Generarla dai sottoproblemi**:
	- Derivando euristiche ammissibili dal costo di una soluzione di un sottoproblema: Memorizzare in un pattern di DB i costi esatti di ogni istanza del sottoproblema. Per ogni sottoproblema, è possibile calcolare $h_{DB}$ per ogni stato incontrato nella ricerca. Il risultato è caratterizzato da euristiche molto più accurate ma anche da un costo rilevante di memoria e tempo.
4. **Apprendere dall'esperienza**:
	- Ogni soluzione ottima è rappresentata da una tupla (obiettivo, cammino). A partire da queste soluzioni, è possibile utilizzare un algoritmo di apprendimento per costruire un'euristica in grado di approssimare il costo del cammino reale, applicabile ad altri stati che potrebbero emergere durante la ricerca.
