# Il problema della Coda con priorità

## Tipo di dato

![[appunti asd/mod i/immagini/Pasted image 20221205161959.png|center]]

**Operazioni aggiuntive**
![[appunti asd/mod i/immagini/Pasted image 20221205162056.png|center]]

**Applicazioni**: gestione code in risorse condivise, gestione priorità in processi concorrenti, progettazione di algoritmi efficienti per diversi problemi fondamentali (es: calcolo cammini minimi in un grafo, minimo albero ricoprente,ordinamento,ecc...)

## Quattro implementazioni elementari

1. Array non ordinato
2. Array ordinato
3. Lista non ordinata
4. Lista ordinata

Ci focalizzeremo soltato sulle **operazioni di base**

### Array non ordinato

Lo dimensiono sufficientemente grande e tengo traccia del numero n di elementi nella coda in una variabile di appoggio

- **FindMin**: $\Theta(n)$ (devo guardare tutti gli elementi)
- **Insert**: $O(1)$ (inserisco in coda)
- **Delete**: $O(1)$ (poichè mi viene fornito il riferimento diretto all'elemento da cancellare, lo posso cancellare in $O(1)$ sovracopiando l'ultimo elemento)
- **DeleteMin**: $\Theta(n)$ (devo prima cercare il minimo in $\Theta(n)$, poi lo posso cancellare in $O(1)$)

### Array ordinato

Lo dimensiono sufficientemente grande, lo tengo **ordinato** in ordine **decrescente** e tengo traccia del numero n di elementi nella coda in una variabile di appoggio

- **FindMin**: $O(1)$
- **Insert**: $O(n)$ (trovo in $\Theta(log(n))$ la giusta posizione, ma poi devo fare $O(n)$ spostamenti)
- **Delete**: $O(n)$ (devo fare $O(n)$ spostamenti)
- **DeleteMin**: $O(1)$ (l'elemento minimo è in fondo all'array, non devo fare spostamenti)

### Lista non ordinata

La considero **bidirezionale**

![[appunti asd/mod i/immagini/Pasted image 20221205163205.png|center|400]]

- **FindMin**: $\Theta(n)$ (devo guardare tutti gli elementi)
- **Insert**: $O(1)$ (inserisco in coda o in testa)
- **Delete**: $O(1)$ (poichè mi viene fornito il riferimento diretto all'elemento da cancellare, lo posso cancellare in $O(1)$ agendo sui puntatori)
- **DeleteMin**: $\Theta(n)$ (devo prima cercare il minimo in $\Theta(n)$, poi lo posso cancellare in $O(1)$)

### Lista ordinata

Tengo la lista bidirezionale **ordinata** in ordine **crescente**

- **FindMin**: $O(1)$ (il minimo è in testa alla lista)
- **Insert**: $O(n)$ (trovo in $O(n)$ la giusta posizione, e poi faccio in $O(1)$ l'inserimento)
- **Delete**: $O(1)$ (agisco sui puntatori)
- **DeleteMin**: $O(1)$ (basta far puntare la testa della lista al secondo elemento della lista stessa)

### Riepilogo

![[appunti asd/mod i/immagini/Pasted image 20221205163929.png|center|600]]


## Tre implementazioni evolute

1. d-heap: generalizzazione degli heap binari visti per l'ordinamento
2. Heap binomiali
3. Heap di Fibonacci (cenni)

### d-heap

_Def_

Un d-heap è un albero radicato d-ario con le seguenti proprietà:
1. **Struttura**: è completo almeno fino al penultimo livello, e tutte le foglie sull'ultimo livello sono compattate verso sinistra
2. **Contenuto Informativo**: ogni nodo v contiene un elemento **elem(v)** ed una chiave **chiave(v)** presa da un dominio totalmente ordinato
3. **Ordinamento Parziale (inverso) dell'heap (min-heap)**: chiave(v)$\geq$chiave(parent(v)) per ogni nodo v diverso dalla radice

**Esempio**

Heap d-ario con 18 nodi e d=3
![[appunti asd/mod i/immagini/Pasted image 20221205164418.png|center|600]]


#### Proprietà

1. Un d-heap con n nodi ha altezza $\Theta(log_dn)$
2. La **radice** contiene l'**elemento con chiave minima** (per via della proprietà di ordimento a heap)
3. Può essere **rappresentato implicitamente** tramite vettore posizionale grazie alla proprietà di struttura

##### Procedure ausiliarie

Utili per ripristinare la prorpietà di ordinamento a heap su un nodo v che non la soddisfi
![[appunti asd/mod i/immagini/Pasted image 20221205165117.png|center]]

#### FindMin

![[appunti asd/mod i/immagini/Pasted image 20221205165304.png|center|500]]

$T(n)=O(1)$

#### Insert(elem e, chiave k)

Vedi esempio qua [Esempio Insert](https://www.mat.uniroma2.it/~guala/cap8_2021.pdf) da pagina 17 a 21

![[appunti asd/mod i/immagini/Pasted image 20221205165446.png|center]]

$T(n)=O(log_dn)$ per l'esecuzione di muoviAlto

#### delete(elem e) e deleteMin

Vedi esempio qua [Esempio delete](https://www.mat.uniroma2.it/~guala/cap8_2021.pdf) da pagina 23 a 30

![[appunti asd/mod i/immagini/Pasted image 20221205170319.png|center]]

$T(n)=O(log_dn)$ o $O(dlog_dn)$ per l'esecuzione di muoviAlto o muoviBasso

#### decreaseKey (elem e, chiave d)

Vedi esempio qua [Esempio delete](https://www.mat.uniroma2.it/~guala/cap8_2021.pdf) da pagina 32 a 36

![[appunti asd/mod i/immagini/Pasted image 20221205170802.png|center]]

$T(n)=O(log_dn)$ per l'esecuzione di muoviAlto

#### increaseKey (elem e,chiave d)

Vedi esempio qua [Esempio delete](https://www.mat.uniroma2.it/~guala/cap8_2021.pdf) da pagina 38 a 42

![[appunti asd/mod i/immagini/Pasted image 20221205170924.png|center]]

$T(n)=O(dlog_dn)$ per l'esecuzione di muoviBasso

#### merge (CodaPriorità $c_1$, CodaPriorità $c_2$)

Due modi:
1. **Costruire da zero**: si distruggono le due cose e se ne crea una nuova contenente l'unione degli elementi
2. **Inserimenti ripetuti**: si inseriscono ripetutamente gli elementi della cosa più piccola in quella più grande

##### Costruire da zero

**Idea**: genero un nuovo heap d-ario contenente tutti gli elementi in $c_1,c_2$

**Come**: 
- generalizzazione della procedura **heapify**
- rendo i d sottoalberi della radice heap ricorsivamente e chiamo **muoviBasso** sulla radice

**Complessità** (d costante):
$$T(n)=dT(n/d)+O(dlog_dn)\underbrace{\implies}_{\text{Teorema Master (caso 1)}}T(n)=\Theta(n)$$
dove $n=|c_1|+|c_2|$

##### Inserimenti ripetuti

Inseriamo ad uno ad uno tutti gli elementi della coda più piccola nella coda più grande

Sia $k=min\{|c_1|,|c_2|\}$ e $n=|c_1|+|c_2|$
Eseguiamo quindi k inserimenti nella cosa più grande
Costo: $O(klog(n))$, dove $n=|c_1|+|c_2|$

L'approccio conviene quindi per $klog(n)=o(n)$, cioè per $$k=o(n/log(n))$$
**Osservazione**: nel caso peggiore entrambe le operazioni hanno un costo di $\Omega(n)$

### Heap Binomiali

#### Alberi Binomiali

Un albero binomiale $B_i$ è definito ricorsivamente come segue:

1. $B_0$ consiste di un **unico** nodo
2. per $i\gt0,B_{i+1}$ è ottenuto fondendo due alberi binomiali $B_i$, ponendo la radice dell'uno come figlia della radice dell'altro

![[appunti asd/mod i/immagini/Pasted image 20221205172006.png|center]]

##### Proprietà strutturali

![[appunti asd/mod i/immagini/Pasted image 20221205172251.png|center|600]]

#### Definizione di un heap binomiale

Un heap binomiale è una **foresta di alberi binomiali** che gode delle seguenti proprietà:

1. **Unicità**: per ogni intero $i\geq0$ esiste al più un $B_i$ nella foresta
2. **Contenuto informativo**: ogni nodo v contiene un elemento elem(v) ed una chaive chiave(v) presa da un dominio totalmente ordinato
3. **Ordinamento a heap**: chiave(v)$\geq$chiave(parent(v)) per ogni nodo v diverso sa una delle radici

**Esempio con n=13 nodi**

![[appunti asd/mod i/immagini/Pasted image 20221205172958.png|center]]


Domanda: quanti alberi binomiali può avere al massimo un heap binomiale con n nodi?

![[appunti asd/mod i/immagini/Pasted image 20221205173317.png|center|500]]

La risposta è $\lceil log_2n\rceil$ 

##### Proprietà topologiche

Dalla prorpietà di unicità degli alberi binomiali che lo costituiscono, ne deriva che un heap binomiale di n elementi è formato dagli alberi binomiali $B_{i_0},B_{i_1},...,B_{i_h}$, dove $i_0,i_1,..,i_h$ corrispondomo alle posizione degli 1 nella rappresentazione in base 2 di n
Ne consegue che in un heap binomiale con n nodi, vi sono al più $\lceil log_2n\rceil$ **alberi binomiali**, ciascuno con grado ed altezza $O(log(n))$

##### Procedura ausiliaria

Utile per ripristinare la prorpietà di unicità in un heap binomiale (ipotizziamo di scorrere la lista delle radici da sinistra verso destra, in ordine crescente rispetto all'indice degli alberi binomiali)

![[appunti asd/mod i/immagini/Pasted image 20221207134234.png|center]]

$T(n)$ = lineare nel numero di alberi binomiali in input
(Ogni fusione diminuisce di uno il numero di alberi binomiali)

Esempio -> [Esempio Ristruttura](http://www.mat.uniroma2.it/~guala/cap8_2022.pdf#page=59)


###### Realizzazione (1/3)

![[appunti asd/mod i/immagini/Pasted image 20221207134640.png|center|600]]

###### Realizzazione (2/3)

![[appunti asd/mod i/immagini/Pasted image 20221207134721.png|center|600]]

###### Realizzazione (3/3)

![[appunti asd/mod i/immagini/Pasted image 20221207134805.png|center|600]]

Tutte le operazioni richiedono tempo $T(n)=O(log(n))$
Durante l'esecuzione della procedura ristruttura esistono infatti al più tre $B_i$, per ogni $i\geq0$

Esempio completo -> [Esempio Completo](http://www.mat.uniroma2.it/~guala/cap8_2022.pdf) da pag 63 a 67

### Heap di Fibonacci (Fredman,Tarjan,1987)

>[!important]- Definizione (Heap Binomiale Rilassato)
>**Heap Binomiale Rilassato**: si ottiene da un heap binomiale rilassando la proprietà di **unicità** dei $B_i$ ed utilizzando un atteggiamento più "pigro" durante l'operazione insert (perchè ristrutturare subito la foresta quando potremmo farlo dopo?)

>[!important]- Defizione (Heap di Fibonacci)
>si ottiene da un heap binomiale rilassato indebolendo la proprietà di **struttura** dei $B_i$ che non sono più necessariamente alberi binomiali

Analisi sofisticata: i tempi di esecuzione sono **ammortizzati** su sequenze di operazioni, cioè dividendo il **costo complessivo** della sequenza di operazioni per il numero di operazioni della sequenza

### Conclusioni: tabella riassuntiva

| Heap        | **FindMin** | **Insert**      | **Delete**            | **DelMin**            | **IncKey**            | *DecKey*       | **Merge**        |
| ----------- | ----------- | ----------- | ----------------- | ----------------- | ----------------- | ------------ | ------------ |
| d-Heap      | $O(1)$      | $O(log(n))$ | $O(log(n))$       | $O(log(n))$       | $O(log(n))$       | $O(log(n))$  | $O(n)$       |
| Heap Binom. | $O(log(n))$ | $O(log(n))$ | $O(log(n))$       | $O(log(n))$       | $O(log(n))$       | $O(log(n))$  | $O(log(n))$  |
| Heap Fibon. | $O(1)$      | $O(1)$      | $O(log(n))^\star$ | $O(log(n))^\star$ | $O(log(n))^\star$ | $O(1)^\star$ | $O(1)^\star$ |

L'analisi per d-Heap e Heap Binomiali è nel caso peggiore, mentre quella per gli Heap di Fibonacci è ammortizzata (per le operazioni **asteriscate**)

----
# Analisi Ammortizzata

- Il **costo ammortizzato** di un'operazione è il costo "**medio**" rispetto a una sequenza _qualsiasi_ di operazioni
- Esempio: se un'operazione ha costo ammortizzato costante e eseguo una sequenza (qualsiasi) di k operazioni è possibile che il costo di una singola operazione può non essere costante, ma l'intera sequenza costerà $O(k)$
- Diverso dal **costo medio**: non c'è nessuna deistribuzione di probabilità (sulla sequenza da eseguire) e l'algoritmo è un algoritmo deterministico
- Molto utile quando si vogliono **buone prestazioni sull'intera sequenza** e non garanzie sulla singola operazione
	- esempio: progettare algoritmi veloci attraverso strutture dati efficienti

>[!important]- Teorema
>Usando un Heap di Fibonacci, una qualsiasi sequenza di _n_ insert, _d_ delete, _f_ findMin, _m_ deleteMin, $\Delta$ increaseKey, $\delta$ decreaseKey, $\micro$ merge prende tempo (nel caso peggiore): $$O(n+f+\delta+\micro+(d+m+\Delta)log(n))$$

**Esercizio (di manipolazione)**
Creare e unire 2 Heap Binomiali sui seguenti insiemi:
- $A_1=\{3,5,7,21,2,4\}$
- $A_2=\{1,11,6,22,13,12,23,31\}$



