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
p9