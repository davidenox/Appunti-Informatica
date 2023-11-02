# Progettare algoritmi veloci usando strutture dati efficienti

## HeapSort
Stesso approccio incrementale del SelectionSort
- selezione gli elementi dal più grande al più piccolo
- usa una **struttura dati efficente**
	- estrazione in tempo $O(log(n))$ del massimo

>**Tipo di dato** Specifica una collezione di oggetti e delle operazioni di interesse su tale colelzione (es. Dizionario: mantiene un insieme di elementi con chiavi soggetto a operazioni di inserimento, cancellazione,ricerca)

>**Struttura dati** Organizzazione dei dati che permette di memorizzare la collezione e supportare le operazioni di un tipo di dato usando meno risorse di calcolo possibile

**Cruciale**: progettare una struttura dati H su cui eseguire efficientemente le operazioni:
- dato un array A, generare velocemente H
- trovare il più grande oggetto in H
- cancellare il più grande oggetto da H

**Tipo di dato associato**: coda con priorità

### Alberi: qualche altra definizione

![[Pasted image 20221028093543.png|center|700]]

**albero d-ario**: albero in cui tutti i nodi interni hanno (al più) d figli
$d=2\implies$**albero binario**
Un albero d-ario è **completo**: se tutti nodi interni hanno esattamente d figli e le foglie sono tutte allo steso livello

![[Pasted image 20221028093928.png|center|600]]


## Struttura dati Heap
Associati ad un insieme S=albero binario radicato con le seguenti proprietà:
1. completo fino al penultimo livello (struttura rafforzata: foglie sull'ultimo livello tutte compattate a sinistra)
2. gli elementi di S sono memorizzati nei nodi dell'albero (ogni nodo v memorizza uno e un solo elemento, denotato con chiave(v))
3. $chiave(padre(v))\geq chiave(v)$ per ogni nodo v diverso dalla radice


![[Pasted image 20221028094332.png|center|600]]

### Proprietà salienti degli Heap
1. Il **massimo** è contenuto **nella radice**
2. L'albero con n nodi ha **altezza O(log(n))**
3. Gli heap con struttura rafforzara possono essere rappresentati in un **array di dimensione pari a n**
#### Altezza di un heap : prop2
Sia H un heap di n nodi e altezza h
![[Pasted image 20221028094753.png|center|600]]

$$n\geq 1+\sum_{i=0}^{h-1}2^i=1+2^h-1=2^h\implies h\leq log_2n$$
#### Rappresentazione tramite vettore posizionale : prop3

![[Pasted image 20221028095850.png|center|600]]

...ancora un esempio
![[Pasted image 20221028095939.png|center|700]]

## La procedura fixHeap

Sia v la radice di H. Assume che i sottoalberi radicati nel figlio sinistro e destro di v sono heap,ma la proprietà di ordinamento delle chiavi non vale per v. Posso ripristinarla così:

> **fixHeap**(nodo v,heap H)
> if (v non è una foglia) then
> 	sia u il figlio di v con chiave massima
> 	if (chiave(v)$\lt$chiave(u)) then
> 		scambia chiave(v) e chiave(u)
> 		**fixHeap**(u,H)

Tempo di esecuzione: $O(log(n))$

**Esempio**
![[Pasted image 20221028101608.png|center|500]]
Scambio 4 con 16 (quindi chiave(i=1)<chiave(i=2))
![[Pasted image 20221028103052.png|center|500]]
scambio 4 con 14 (quindi chiave(i=2)<chiave(i=4))
![[Pasted image 20221028103151.png|center|500]]
scambio 4 con 8 (quindi chiave(i=4)<chiave(i=9))
![[Pasted image 20221028103253.png|center|500]]

Complessità $O(log(n))$
### Pseudocodice più dettagliato
(l'heap è mantenuto attraverso un vettore posizionale)
![[Pasted image 20221028103423.png|center]]

## Estrazione del massimo

![[Pasted image 20221028112747.png|center|500]]
![[Pasted image 20221028112821.png|center|500]]
![[Pasted image 20221028112857.png|center|500]]

## Costruzione dell'heap

Algoritmo ricorsivo basato sulla tecnica del divide et impera
>**heapify**(heap H)
>if (H non è vuoto) then
>	heapify (sottoalbero sinistro di H)
>	heapify (sottoalbero destro di H)
>	fixHeap (radice di H,H)

![[Pasted image 20221028113058.png|center|500]]
![[Pasted image 20221028113117.png|center|500]]
![[Pasted image 20221028113132.png|center|500]]
![[Pasted image 20221028113150.png|center|500]]

#### Complessità heapify

Sia h l'altezza di un heap con n elementi
Sia $n'\geq n$ l'intero talche he un heap con $n'$ elementi ha
1. altezza h
2. è completo fino all'ultimo livello
Vale $T(n)\leq T(n')$ e $n'\geq 2n$

Tempo di esecuzione: $T(n')=2T((n'-1)/2)+O(log(n'))\leq 2T(n'/2)+O(log(n'))\implies T(n')=O(n')$ dal Teorema Master
Quindi: $T(n)\leq T(n')=O(n')=O(2n)=O(n)$

**Esercizio**
Scrivere lo pseudocodice dettagliato di heapify assumendo che l'heap è mantenuto con un vettore posizionale

## Max-Heap e Min-Heap

e se volessi una struttura dati che mi permette di estrarre il **minimo** velocemente invece del **massimo**?

**Semplice**: costruisco un **min-heap** invertendo la proprietà di ordinamento delle chiavi. Cioè richiedo che $chiave(padre(v))\leq chiave(v)$ per ogni v (diverso dalla radice)

E come mai noi abbiamo progettato un max-heap e non un min-heap?
Risposta qua $\to$ [[Lezione 6 - HeapSort#Ritornado a max-heap e min-heap|Ritornado a max-heap e min-heap]]

## Algoritmo HeapSort

Costruisce un heap tramite heapify
Estrare ripetutamente il massimo per n-1 volte
- asd ogni estrazione memorizza il massimo nella posizione dell'array che si è appena liberata

### Pseudocodice
![[Pasted image 20221028114925.png|center|500]]

- linea 1 ha costo $O(n)$
- linee 3-6 eseguono n-1 estrazioni di costo $O(log(n))$
$\implies$ ordina in loco in tempo $O(nlog(n))$

#### Esempio concreto

![[Pasted image 20221028115135.png|center|500]]
![[Pasted image 20221028121520.png|center|500]]
![[Pasted image 20221028121604.png|center|500]]
![[Pasted image 20221028121647.png|center|500]]
![[Pasted image 20221028121727.png|center|500]]
![[Pasted image 20221028121801.png|center|500]]

e così via, fin quando non ottengo il seguente risultato:
![[Pasted image 20221028121859.png|center|600]]

## Ritornado a max-heap e min-heap

Quindi: come mai abbiamo usato un max-heap e non un min-heap? Potevamo usare anche un min-heap?

...l'uso del max.heap (implementato con un vettore posizionale) ci permette di usare solo memoria ausiliare costante!

>**Teorema**
>L'algoritmo HeapSort ordina in loco un array di lunghezza n in tempo $O(n log(n))$ nel caso peggiore

