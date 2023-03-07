
# Strutture dati per rappresentare grafi

## Grafi non diretti

Quanto spazio?
![[appunti asd/mod i/immagini/Pasted image 20221215111018.png|center]]

**Matrice di adiacenza**: $O(n^2)$
![[appunti asd/mod i/immagini/Pasted image 20221215111110.png|center|300]]

**Liste di adiacenza**: $O(m+n)$
![[appunti asd/mod i/immagini/Pasted image 20221215111147.png|center|300]]

| **Operazione**              | Matrice di a. | Liste di a.                     |
| --------------------------- | ------------- | ------------------------------- |
| elenco archi incidenti in v | $O(n)$        | $O(\delta(v))$                  |
| c'è un arco (u,v)?          | $O(1)$        | $O(min\{\delta(u),\delta(v)\})$ |


## Grafi diretti

Quanto spazio?

![[appunti asd/mod i/immagini/Pasted image 20221215111613.png|center]]

**Matrice di adiacenza**: $O(n^2)$
![[appunti asd/mod i/immagini/Pasted image 20221215111658.png|center|300]]

**Liste di adiacenza**: $O(m+n)$
![[appunti asd/mod i/immagini/Pasted image 20221215111753.png|center|300]]


| **Operazione**            | Matrice di a. | Liste di a.    |
| ------------------------- | ------------- | -------------- |
| elenco archi uscenti da v | $O(n)$        | $O(\delta(v))$ |
| c'è arco (u,v)?           | $O(1)$        | $O(\delta(u))$ |

## Quali parti del grafo sono raggiungibili da un certo nodo?

... eseguo una **visita** del grafo

### Scopo e tipi di visita

Una visita di un grafo G permette di esaminare i nodi e gli archi di G **in modo sistematico** (se G è connesso)
Genera un **albero** di visita
Problema di base di molte applicazioni
Esistono vari tipi di visite con diverse proprietà:

- **visita in ampiezza (BFS=breadth first search)**
- **visita in profondità (DFS=depth first search)**

#### Visita in ampiezza

Dato un grafo G (non pesato) e un nodo s, trova tutte le **distanze/cammini minimi** da s verso ogni altro nodo v

**Applicazioni**:
- **web crawling**
	- come google trova nuove pagine da indicizzare
- **social networking**
	- trovare gli amici che potresti conoscere
- **network broadcast**
	- un nodo manda un messaggio a tutti gli altri nodi della rete
- **garbage collection**
	- come scoprire memoria non puù raggiungibile che si può liberare
- **model checking**
	- verificare una proprietà di un sistema
- **risolvere puzzle**
	- risolvere il Cubo di Rubick con un numero minimo di mosse

**Esempio**

Cubo di Rubick 2x2x2

- grafo delle configurazioni:
	- un vertice per ogni possibile stato del cubo
	- un arco fra due configurazioni se l'una è ottenibile dall'altra tramite una mossa

![[appunti asd/mod i/immagini/Pasted image 20221215112709.png|center|400]]

numero di vertici $\leq 8!\times 3^8=264.539.520$

![[appunti asd/mod i/immagini/Pasted image 20221215112839.png|center]]


![[appunti asd/mod i/immagini/Pasted image 20221215113149.png|center|500]]

**God's number**:

- 2x2x2 = 11
- 3x3x3 = 20
- 4x4x4 = ???
- ...
- $n\times n\times n=\Theta(n^2/log(n))$

##### Pseudo-codice

![[appunti asd/mod i/immagini/Pasted image 20221215113850.png|center|600]]

**Esempio**

[Esempio visitaBFS](http://www.mat.uniroma2.it/~guala/visite_2021.pdf) da pagin a15 a pagina 33

**Esempio Grafo orientato**

![[appunti asd/mod i/immagini/Pasted image 20221215114402.png|center|600]]


##### Costo della visita in ampiezza (grafo rappresentato con matrice di a.)

![[appunti asd/mod i/immagini/Pasted image 20221215114527.png|center|600]]


##### Costo della visita in ampiezza (grafo rappresentato con liste di a.)

![[appunti asd/mod i/immagini/Pasted image 20221215114640.png|center|600]]

##### Costo della visita in ampiezza

Il tempo di esecuzione dipende dalla sruttura dati usata per rappresentare il grafo (e dalla connettività o meno del grafo rispetto ad s):
- Liste di adiacenza: $O(m+n)$
- Matrice di adiacenza: $O(n^2)$

**Osservazioni**

1. Si noti che se il grafo è connesso allora $m\geq n-1$ e quindi $O(m+n)=O(m)$
2. Ricordando che $m\leq n(n-1)/2$, si ha $O(m+n)=O(n^2)\implies$ per $m=o(n^2)$ la rappresentazione mediante **liste di adiacenza** è **temporalmente più efficiente!**

##### Proprietà dell'albero BFS radicato in s

1. Se il grafo è **non orientato**, per ogni arco (u,v) del grafo gli estremi u e v appartengono allo stesso livello o a livelli consecutivi dell'albero BFS ![[appunti asd/mod i/immagini/Pasted image 20221215115146.png|center]]
2. Se il grafo è **orientato**, allora gli archi orientati **verso il basso** uniscono nodi sullo stesso livello o su livelli adiacenti, mentre gli archi orientati **verso l'alto** possono unire nodi su livelli non adiacenti ![[appunti asd/mod i/immagini/Pasted image 20221215115354.png|center]]

>[!important]- Teorema
>Per ogni nodo v, il livello di v nell'albero BFS è pari alla distanza di v dalla sorgente s (sia per grafi orientati che non orientati)

**Dimostrazione informale**

- all'inizio inserisco **s** in **F** (che è a distanza 0 da se stesso) e gli assegno livello 0; chiaramente **s** è l'unico nodo a distanza 0
- estraggo **s** e guardo tutti i suoi vicini (archi uscenti); questi sono tutti i nodi a distanza 1 da **s**; li inserisco in **F** e assegno loro livello 1. Ora in **F** ho **tutti** i nodi a distanza 1
- estraggo uno a uno tutti i nodi di livello/distanza 1 e per ognuno guardo tutti i suoi vicini (archi uscenti); i vicini non marcati sono a distanza 2 da **s**; li inserisco in **F** e assegno loro livello 2; quando ho estratto e visitato tutti i nodi di livello 1, in **F** ho **tutti** i nodi a distanza 2 da **s**
- estraggo uno a uno tutti i nodi di livello/distanza 2 e per ognino guardo tutti i suoi vicini (archi uscenti); i vicini non marcati sono a distanza 3 da **s**...

#### Visita in profondità

Un'analogia: esplorare un labirinto

![[appunti asd/mod i/immagini/Pasted image 20221215120225.png|center|700]]

**Cosa mi serve?**

- gesso: per disegnare le strade prese
- corda: per tornare indietro se necessario

**Variabile booleana**: dice se un nodo è stato già visitato 
**Pila**: push vuol dire srotolare, pop vuol dire arrotolare

##### Pseudo-codice

![[appunti asd/mod i/immagini/Pasted image 20221215120502.png|center|600]]


Esempio --> [Esempio visitaDFS](http://www.mat.uniroma2.it/~guala/visite_2021.pdf) da pagina 43 a pagina 60

**Esempio: Grafo diretto**

![[appunti asd/mod i/immagini/Pasted image 20221215120651.png|center|600]]


... ritornando al labirinto

L'albero DFS associato al labirinto sarà

![[appunti asd/mod i/immagini/Pasted image 20221215120841.png|center|400]]


##### Costo della visita in profondità

Il tempo di esecuzione dipende dalla struttura dati usata per rappresentare il grafo (e dalla connettività o meno del grafo rispetto ad s):
- Liste di adiacenza: $O(m+n)$
- Matrice di adiacenza: $O(n^2)$

##### Proprietà dell'albero DFS radicato in s

- Se il grafo è **non orientato**, per ogni arco **(u,v)** si ha:
	- **(u,v)** è un arco dell'albero DFS
	- i nodi **u** e **v** sono l'uno discendente/antenato dell'altro
- Se il grafo è **orientato**,per ogni arco **(u,v)** si ha:
	- **(u,v)** è un arco dell'albero DFS
	- i nodi **u** e **v** sono l'uno discendente/antenato dell'altro
	- **(u,v)** è un arco **trasversale a sinistra**, ovvero il vertice v è in un sottoalbero visitato precedentemente ad u


