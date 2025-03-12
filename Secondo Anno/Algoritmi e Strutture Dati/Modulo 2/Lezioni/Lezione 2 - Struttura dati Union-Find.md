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
classe QuickFindBilanciato implementa UnionFind:
dati: S(n)=O(n)
	Una collezione di insiemi disgiunti di elementi *elem*;ogni insieme 
	ha un nome *name*.
operazioni:
	makeSet(elem e) T(n)=O(1)
		Crea un nuovo albero, composto da due nodi: una radice ed un
		unico figlio(foglia). Memorizza *e* sia nella radice che nella
		foglia dell'albero. Inizializza la cardinalità del nuovo insieme
		ad 1, assegnando il valore size(x)=1 alla radice x.
	find(elem e)->name T(n)=O(1)
		Accede alla foglia x corrispondente all'elemento *e*. Da tale 
		nodo segue il puntatore al padre, che è la radice dell'albero, 
		e restituisce il nome memorizzato in tale radice.
	union(name a, name b) T_am=O(log n)
		Considera l'albero A corrispondente all'insieme di nome *a*, e 
		l'albero B corrispondente all'insieme di nome *b*. 
		Se size(A) >= size(B), muovi tutti i puntatori dalle foglie di 
		B alla radice di A, e cancella la vecchia radice di B. 
		Altrimenti (size(B)>size(A)) memorizza nella radice di B il nome
		A, muovi tutti i puntatori dalle foglie di A alla radice di B, e
		cancella la vecchia radice di A. In entrambi i casi si assegna
		al nuovo insieme la somma delle cardinalità dei due insiemi 
		originali(size(A)+size(B)).
```
$T_{am}$= Tempo per operazione *ammortizzato* sull'intera sequenza di unioni. Vedremo che una singola `union` può costare $\Theta(n)$, ma l'intera sequenza di $n-1$ `union` costa $O(n\log n)$.
![[Pasted image 20250306141458.png|center|500]]


#### Demo
![[union_by_size.gif|center|500]]
#### Complessità Union
![[Pasted image 20250306141539.png|center|500]]
**Domanda**: Quanto costa cambiare padre ad un nodo?
- Tempo costante
**Domanda CRUCIALE**: Quante volte può cambiare padre un nodo?
- Al più $\log n$.
#### Complessità ammortizzata

Vogliamo dimostrare che se eseguiamo $m$ `find`, $n$ `makeSet`, ed al più $n-1$ `union`, il tempo richiesto dall'intera sequenza di operazioni è $O(m+n\log n)$.

Idea:
- È facile vedere che `find` e `makeSet` richiedono tempo $\Theta(m+n)$.
- Per analizzare le operazioni di `union`, ci concentriamo su un singolo nodo/elemento e dimostriamo che il tempo speso per tale nodo è $O(\log n)\implies$ in totale, il tempo speso è $O(n\log n)$.

Quando eseguiamo una `union`, per ogni nodo che cambia padre pagheremo tempo costante.
- Osserviamo ora che ogni nodo *può cambiare al più $O(\log n)$ padri*, poiché ogni volta che un nodo cambia padre la cardinalità dell’insieme al quale apparterrà è almeno doppia rispetto a quella dell’insieme cui apparteneva!
	- all’inizio un nodo è in un insieme di dimensione $1$, 
	- poi se cambia padre in un insieme di dimensione almeno $2$, 
	- all’i-esimo cambio è in un insieme di dimensione almeno $2^i$
 - $\implies$ Il tempo speso per un singolo nodo sull’intera sequenza di $n$ `union` è $O(\log n)$. 
 - $\implies$ L’intera sequenza di operazioni costa $O(m+n+n \log n)=O(m+n \log n)$.
## QuickUnion
Utilizziamo una foresta di alberi di altezza anche maggiore di $1$ per rappresentare gli insiemi disgiunti. In ogni albero:
- Radice = elemento rappresentativo dell'insieme
- Rimanenti nodi = altri elementi (*escluso* l'elemento nella radice)
![[Pasted image 20250306150037.png|center|500]]
### Demo
![[quick_union.gif|center|500]]
### Find di costo lineare
Particolari sequenze di `union` possono generare un albero di altezza lineare, e quindi la `find` è molto inefficiente (costa $n-1$ nel caso peggiore).
![[Pasted image 20250306153403.png|center|500]]
Se eseguiamo $n$ `makeSet`, $n-1$ `union` come sopra, seguite da $m$ `find`, il *tempo* richiesto *dall'intera sequenza* di operazioni è $O(n+n-1+mn)=O(mn)$.
### Euristica Union-by-size
**Idea**: Fare in modo che per ogni insieme l'albero corrispondente abbia altezza piccola.

*UnionBySize*: Nell'unione degli insiemi A e B, rendiamo la radice dell'albero *con meno nodi* figlia della radice dell'albero *con più nodi*.
![[Pasted image 20250306153844.png|center|500]]
#### Demo
![[union_by_size2.gif|center|500]]

>[!definition]- Lemma
>Con la *Union-By-Size*, dato un albero QuickUnion con size (numero di nodi) $s$ ed altezza $h$ vale che $s\ge 2^h$.
>**Dim.** per induzione sul numero di union fatte.

Quindi, *L'operazione `find` richiede tempo $O(\log n)\implies$* L'intera sequenza di operazioni costa $O(n+m\log n)$.

### Euristica Path-Compression
**Idea**: Quando eseguo `find(x)` ed attraverso il cammino da x alla radice, comprimo il cammino, ovvero rendo tutti i nodi del cammino figli della radice.
*Intuizione*: `find(x)` ha un costo ancora lineare nella lunghezza del cammino attraversato, ma prossime `find` costeranno di meno.

![[Pasted image 20250307161943.png|center|500]]

>[!important]- Th. Tarjan&van Leeuwen
>Usando in **QuickUnion** le euristiche di union-by-rank o *union-by-size* e *path compression*, una qualsiasi sequenza di $n$ `makeSet`, $n-1$ `union` ed $m$ `find` hanno un costo di $O(n+m\space\alpha(n+m,n))$.
>- $\alpha(x,y)$: Funzione inversa della funzione di Ackermann

##### Funzione di Ackermann ed inversa

*Notazione*: Con $a^{b^c}$  intendiamo $a^{(b^c)}$ e non $(a^b)^c=a^{b\cdot c}$. 

Per interi $i,j\ge 1$, definiamo $A(i,j)$ come:
![[Pasted image 20250307162518.png|center|400]]
![[Pasted image 20250307162547.png|center|500]]
##### La funzione $\alpha(m,n)$ 
Per interi $m\ge n\ge 0$, definiamo $\alpha(m,n)$ come:$$\alpha(m,n)=\min\{i\ge1|A(i,\lfloor m/n\rfloor)\gt\log_2 n\}.$$
>Proprietà
1. Per $n$ fissato, $\alpha(m,n)$ è monotonicamente decrescente al crescere di $m$:$$\alpha(m,n)=\min\{i\gt0:A(i,\lfloor m/n\rfloor)\gt\log_2{n}\}$$
2. $\alpha(n,n)\rightarrow\infty$ per $n\rightarrow\infty$ $$\begin{align}
 \alpha(n,n)&=\min\{i\gt0:A(i,\lfloor n/n\rfloor)\gt\log_2 n \}\\&
 =\min\{i\gt0:A(i,1)\gt\log_2 n \}\text{ dove }\log_2 n\rightarrow\infty
 \end{align}$$ 
>[!info]- Osservazione
 >$\alpha(m,n)\le4$ per ogni scopo pratico (ovvero per valori ragionevoli di $n$).
 
 >Ultime proprietà: densità di $m/n$ 

- $\alpha(m,n)\le1$ quando $\lfloor m/n\rfloor\gt\log_2\log_2 n$ 
- $\alpha(m,n)\le2$ quando $\lfloor m/n\rfloor\gt\log^*\log_2 n$ dove:
	- $\log^{(1)}n=\log n$
	- $\log^{(i)}n=\log\log^{(i-1)}n$
	- $\log^* n=\min{i\gt0:\log^{(i)}n\le1}$
		*Riuscite a dimostrarle?*