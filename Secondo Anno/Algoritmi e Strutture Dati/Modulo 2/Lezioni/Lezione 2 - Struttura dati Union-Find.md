# Union-Find
	Gestione di insiemi disgiunti
Consiste nel mantenere una *collezione di insiemi disgiunti* contenenti elementi distinti durante l'esecuzione di una sequenza di operazioni del seguente tipo:
- `makeSet(x)`: Crea il nuovo insieme $x=\{x\}$ di nome $x$;
- `union(A,B)`: Unisce gli insiemi $A$ e $B$ in un unico insieme, di *nome* $A$, e distrugge i vecchi insiemi (si suppone di accedere direttamente agli insiemi $A,B$);
- `find(x)`: Restituisce il nome dell'insieme contenente l'elemento $x$ (si suppone di accedere direttamente all'elemento $x$).

>Esempio
>![[Pasted image 20250306113611.png|center|500]]
>- $n=6$, L'elemento in grassetto dà il nome all'insieme

**Domanda**: Se ho $n$ elementi, quante `union` posso fare al più?
*Risposta*: $n-1$

L'**obiettivo** è di progettare una struttura dati che sia efficiente su una sequenza arbitratia di operazioni.

>**Idea generale**: Rappresentare gli insiemi disgiunti con una foresta, in cui:
>- Ogni insieme è un albero radicato
>- La *radice* contiene il *nome* dell'insieme (elemento rappresentativo).

## QuickFind
Utilizziamo una foresta di alberi di altezza $1$ per rappresentare gli insiemi disgiunti. In ogni albero:
- Radice = nome dell'insieme;
- Foglie = elementi (*incluso* l'elemento rappresentativo, il cui valore è nella radice e dà il nome all'insieme).

```Realizzazione
classe QuickFind implementa UnionFind:
dati: S(n)=O(n)
	Una collezione di insiemi disgiunti di elementi *elem*; ogni insieme ha un nome *name*.
operazioni:
	makeSet(elem e) T(n)=O(1)
		Crea un nuovo albero, composto da due nodi: una radice ed un
		unico figlio (foglia). Memorizza *e* sia nella foglia 
		dell'albero che come nome della radice.

	union(name a, name b) T(n)=O(n)
		Considera l'albero A corrispondente all'insieme di nome *a*, e
		l'albero B corrispondente all'insieme di nome *b*. Sostituisce 
		tutti i puntatori dalle foglie di B alla radice di B con 
		puntatori alla radice di A. Cancella la vecchia radice di B.

	find(elem e)->name T(n)=O(1)
		accede alla foglia x corrispondente all'elemento *e*. Da tale 
		nodo segue il puntatore al padre, che è la radice dell'albero, 
		e restituisce il nome memorizzato in tale radice.
```

![[Pasted image 20250306115444.png|center|500]]
### Demo
![[quick_find.gif|center|500]]

E se eseguo una sequenza arbitraria di operazioni?
### Union di costo lineare
`find` e `makeSet` richiedono solo tempo $O(1)$, ma particolari sequenze di `union` possono essere molto inefficienti:
![[Pasted image 20250306115619.png|center|500]]
### Euristica Union-by-size
**Idea**: Fare in modo che un nodo/elemento non cambi troppo spesso padre.

Nell'unione degli insiemi A e B, attacchiamo gli elementi dell'insieme *di cardinalità minore a quello di cardinalità maggiore*, e se necessario modifichiamo la radice dell'albero ottenuto per aggiornare il nome. Ogni insieme mantiene esplicitamente anche la propria size:
![[Pasted image 20250306115927.png|center|300]]

```Realizzazione

```

#### Demo
![[union_by_find.gif|center|500]]
