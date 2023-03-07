
# Strutture dati elementari

## Gestione di collezioni di oggetti

**Tipo di dato**:
- Specifica una collezione di oggetti e delle operazioni di interesse su tale collezione (es. inserisci,cancella,cerca)

**Struttura dati**:
- Organizzazione dei dati che permette di memorizzare la collezione e supportare le operazioni di un tipo di dato usando meno risorse di calcolo possibile

### Il tipo di dato Dizionario

![[appunti asd/mod i/immagini/Pasted image 20221117092001.png|center|600]]

### Il tipo di dato Pila

![[appunti asd/mod i/immagini/Pasted image 20221117092056.png|center|600]]

### Il tipo di dato Coda

![[appunti asd/mod i/immagini/Pasted image 20221117092140.png|center|600]]

## Tecniche di rappresentazione dei dati

**Rappresentazione indicizzate**:
- I dati sono contenuti (principalmente) in array

**Rappresentazioni collegate**:
- I dati sono contenuti in record collegati fra loro mediante puntatori

### Proprietà

**Rappresentazioni indicizzate**:
- Array: collezione di celle numerate che contengono elementi di un tipo prestabilito

>[!important]- Proprietà
>**(forte)**: gli indici delle celle di un array sono numeri consecutivi
>**(debole)**: non è possibile aggiungere nuove celle ad un array

**Rappresentazioni collegate**:
- i constituenti di base sono i _record_
- i record sono numerati tipicamente con il loro _indirizzo di memoria_
- record creati e distrutti individualmente e dinamicamente
- il collegamento tra un record A e un record B è realizzato tramite un puntatore

>[!important]- Proprietà
>**(forte)**: è possibile aggiungere o togliere record a una struttura collegata
>**(debole)**: gli indirizzi dei record di una struttura collegata non sono necessariamente consecutivi

**Esempi di strutture collegate**
![[appunti asd/mod i/immagini/Pasted image 20221117093120.png|center|600]]

### Pro e contro

**Rappresentazioni indicizzate**:
- **Pro**: accesso diretto ai dati mediante indici
- **Contro**: dimensione fissa (riallocazione array richiede tempo lineare)

**Rappresentazioni collegate**:
- **Pro**: dimensione variabile (aggiunta e rimozione record in tempo costante)
- **Contro**: accesso sequenziale ai dati

**Realizzazione di un dizionario**

Metodo più semplice: **array non ordinato** (sovradimensionamento)

- **Insert**: costa $O(1)$ - inserisco dopo l'ultimo elemento
- **Search**: costa $O(n)$ - devo scorrere l'array
- **Delete**: costa $O(n)$ - delete = search+cancellazione

**Array ordinato**:

- **Search**: $O(log(n))$ - ricerca binaria
- **Insert**: $O(n)$ - Ho bisogno di $O(log(n))$ confronti per trovare la giusta posizione in cui inserire, $O(n)$ trasferimento per mantenere l'array ordinato
- **Delete**: $O(n)$

...e con le liste?

**Lista non ordinata**:

- **Insert**: costa $O(1)$
- **Search**: costa $O(n)$
- **Delete**: costa $O(n)$

**Lista ordinata**:

- **Insert**: costa $O(n)$ - devo manterene ordinata la lista
- **Search**: costa $O(n)$ - non posso usare la ricerca binaria
- **Delete**: costa $O(n)$

## Alberi

### Organizzazione gerarchica dei dati

![[appunti asd/mod i/immagini/Pasted image 20221117095717.png|center|600]]

Dati contenuti nei **nodi**, relazioni gerarchiche definite dagli **archi** che li collegano

![[appunti asd/mod i/immagini/Pasted image 20221117095848.png|center|700]]

- **grado di un nodo**: numero dei suoi figli
- **albero d-ario,albero d-ario completo**

_Def_
u si dice **antenato** di v se u è raggiungibile da v risalendo di padre in padre
v si dice **discendente** di u se u è un antenato di v

### Rappresentazioni indicizzate di alberi

**Idea**: ogni cella dell'array contiene:
- le informazioni di un nodo
- eventualmente altri indici per raggiungere altri nodi

**Vettore dei padri**
Per un albero con n nodi uso un array P di dimensione (almeno) n
Una generica cella i contiene una coppia (**info,parent**) dove:
- **info**: contenuto informativo del nodo i
- **parent**: indice (nell'array) del nodo padre di i

**Vettore posizionale** (per alberi d-ari (quasi) completi)

**Esempio vettore dei padri**
![[appunti asd/mod i/immagini/Pasted image 20221117100527.png|center|700]]

>[!info]- Osservazioni
>- num. arbitrario di figli
>- tempo per individuare il padre di un nodo: $O(1)$
>- tempo per individuare uno o più figli di un nodo: $O(n)$

**Vettore posizionale**:
- i nodi arrangiati nell'array "per livelli"
- j-esimo figlio $(j\in\lbrace 1,...,d\rbrace)$ di i è in posizione $d(i-1)+j+1$
- il padre di i è in posizione $\lfloor{(i-2)/d}\rfloor+1$

![[appunti asd/mod i/immagini/Pasted image 20221117101155.png|center|600]]

>[!info]- Osservazioni
> - num. di figli esattamente $d$
> - solo per alberi completi o quasi
> - tempo per individuare il padre di un nodo: $O(1)$
> - tempo per individuare uno specifico figlio di un nodo: $O(1)$


### Rappresentazioni collegate di alberi

![[appunti asd/mod i/immagini/Pasted image 20221117102127.png|center|700]]

![[appunti asd/mod i/immagini/Pasted image 20221117102207.png|center|700]]

## Visite di alberi

Algoritmi che consentono l'**accesso sistematico ai nodi e agli archi** di un albero

Gli algoritmi di visita si distinguono in nodi base al particolare ordine di accesso ai nodi

### Algoritmo di visita in profondità (DFS)

_Def_
L'algoritmo di visita in profondità (DFS) parte da r (radice) e procede visitando nodi di figlio in figlio fino a raggiungere una foglia.
Retrocede poi al primo antenato che ha ancora figli non visitati (se esiste) e ripete il procedimento a partire da uno di quei figli
![[appunti asd/mod i/immagini/Pasted image 20221117102555.png|center|600]]

#### Versione iterativa

##### Pseudo-codice
![[appunti asd/mod i/immagini/Pasted image 20221117102755.png|center|500]]


Vedi esempio qua --> [Esempio algoritmo DFS](http://www.mat.uniroma2.it/~guala/cap3_2021.pdf) (da pag. 26 a pag. 45)

##### Complessità Temporale

![[appunti asd/mod i/immagini/Pasted image 20221117103228.png|center|700]]

Quindi $T(n)=O(n)$

#### Versione ricorsiva

![[appunti asd/mod i/immagini/Pasted image 20221117103812.png|center|600]]

- **Visita in preordine**: radice, sottoalbero sx, sottoalbero dx
- **Visita simmetrica**: sottoalbero sx,radice,sottoalbero dx (scambio riga 2 con 3)
- **Visita in postordine**: sottoalbero sx,sottoalbero dx,radice (sposta riga 2 dopo 4)

**Esempi**

![[appunti asd/mod i/immagini/Pasted image 20221117104111.png|center|600]]

##### Complessità temporale

Come la versione iterativa

### Algoritmo di visita in ampiezza (BFS)

_Def_
L'algoritmo di visita in ampiezza (BFS) parte da r (radice) e procede visitando nodi per livelli successivi.
Un nodo sul livello i può essere visitato solo se tutti i nodi sul livello i-1 sono stati visitati
![[appunti asd/mod i/immagini/Pasted image 20221117104456.png|center|600]]


#### Versione iterativa
##### Pseudo-codice
![[appunti asd/mod i/immagini/Pasted image 20221117104625.png|center|600]]

**Esempio**

![[appunti asd/mod i/immagini/Pasted image 20221117104803.png|center|600]]


##### Complessità temporale
![[appunti asd/mod i/immagini/Pasted image 20221117104916.png|center|700]]

Quindi $T(n)=O(n)$
