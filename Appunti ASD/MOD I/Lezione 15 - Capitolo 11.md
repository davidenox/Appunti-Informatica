# Usi meno scontati della visita DFS

## Informazioni utili: tenere il tempo

![[appunti asd/mod i/immagini/Pasted image 20221219160725.png|center|600]]

pre(v) = tempo in cui viene "scoperto" v
post(v) = tempo in cui si "abbandona" v

## Quando non tutti i nodi sono raggiungibili dal punto di partenza

![[appunti asd/mod i/immagini/Pasted image 20221219160919.png|center|600]]

### Esempio

![[appunti asd/mod i/immagini/Pasted image 20221219161301.png|center]]


### Proprietà

Per ogni coppia di nodi u e v, gli intervalli $[pre(u),post(u)]$ e $[pre(v),post(v)]$ o sono disgiunyi o l'uno è contenuto nell'altro

u è antenato di v nell'albero DFS, se $pre(u)\lt pre(v)\lt post(v)\lt post(u)$ condizione che rappresentiamo così:

![[appunti asd/mod i/immagini/Pasted image 20221219161714.png|center]]

![[appunti asd/mod i/immagini/Pasted image 20221219161757.png|center|300]]

Possiamo usare i tempi di visiita per riconoscere il tipo di un generico arco (u,v) nel grafo?

### ...riconoscere i tipi di arco

![[appunti asd/mod i/immagini/Pasted image 20221219161932.png|center|600]]


# Cicli,DAG e ordinamenti topologici

## Riconoscere la presenza di un ciclo in un grafo diretto

**Algoritmo**: fai una visita DFS e controlla se c'è un arco all'indietro

>[!important]- Proprietà
>Un grafo diretto G ha un ciclo se e solo se la visita DFS rivela un arco all'indietro

$(\leftarrow):$ se c'è arco all'indietro, chairamente G ha un ciclo
$(\to):$ se c'è ciclo $\lt v_0,v_1,..,v_k=v_0\gt$ 

sia $v_i$ il primo nodo scoperto nella visita:
- $v_i$ termina la visita dopo che $v_{i+1}$ ha terminato la sua
- $v_{i+1}$ termina la visita dopo che $v_{i+2}$ ha terminato la sua
- ...
- quindi, per transitività, $v_i$ termina la visita dopo che $v_{i-1}$ ha temrinato la sua
- allora $(v_{i-1},v_i)$ è un arco all'indietro

![[appunti asd/mod i/immagini/Pasted image 20221219163048.png|center|150]]

>[!important]- Definizione
>Un **grafo diretto aciclico (DAG)** è un grafo diretto G che non contiene cicli (diretti)

>[!important]- Definizione
>Un ordinamento topologico di un grafo diretto G=(V,E) è una funzione biettiva $\sigma:V\to\{1,2,...,n\}$ tale che per ogni arco $(u,v)\in E,\sigma(u)\lt\sigma(v)$

![[appunti asd/mod i/immagini/Pasted image 20221219163503.png|center|600]]


### Reti delle "dipendenze"

**nodi**: compiti da svolgere
**arco (u,v)**: u deve essere eseguito prima di v

![[appunti asd/mod i/immagini/Pasted image 20221219163623.png|center|300]]

**problema**: trovare un ordine in cui eseguire i compiti in modo da rispettare le dipendenze

![[appunti asd/mod i/immagini/Pasted image 20221219163735.png|center|500]]

### Quali grafi (diretti) ammettono un ordinamento topologico?

>[!important]- Teorema
>Un grafo diretto G ammette un ordinamento topologico se e solo se G è un DAG

**dim (per $\leftarrow$)**

per assurdo: sia $\sigma$ un ordinamento topologico di G, e sia $\lt v_0,v_1,..,v_k=v_0\gt$ un ciclo, allora $\sigma(v_0)\lt\sigma(v_1)\lt...\lt\sigma(v_{k-1})\lt\sigma(v_k)=\sigma(v_0)$
$\square$

**dim (per $\to$)**: ... adesso diamo un algoritmo costruttivo

#### Calcolare ordinamento topologico

![[appunti asd/mod i/immagini/Pasted image 20221219164658.png|center|650]]

**Esempio**

![[appunti asd/mod i/immagini/Pasted image 20221219164841.png|center|400]]
![[appunti asd/mod i/immagini/Pasted image 20221219164912.png|center|500]]
![[appunti asd/mod i/immagini/Pasted image 20221219164942.png|center|200]]


##### Correttezza

Per ogni coppia di nodi u e v, gli intervalli $[pre(u),post(u)]$ e $[pre(v),post(v)]$ o sono disgiunyi o l'uno è contenuto nell'altro

![[appunti asd/mod i/immagini/Pasted image 20221219165156.png|center|500]]

##### Algoritmo alternativo

![[appunti asd/mod i/immagini/Pasted image 20221219165306.png|center|600]]

$(*)$ perchè altrimenti in $\hat G$ ogni vertice deve avere almeno un arco entrante, e quindi posso trovare un ciclo percorrendo archi entranti a ritroso, e quindi G non può essere aciclico

**Tempo di esecuzione (con liste di adiacenza)**: $\Theta(n+m)$

[Esempio](http://www.mat.uniroma2.it/~guala/usi_dfs_2021.pdf#page=17)

## Componenti fortemente connesse

Una **componente fortemente connessa** di un grafo G=(V,E) è un insieme **_massimale_** di vertici $C\subseteq V$ tale che per ogni coppia di nodi **u** e **v** in C, **u** è raggiungibile da **v** e **v** è raggiungibile da **u**

**massimale**: se si aggiunge un qualsiasi vertice a C la proprietà non è più vera

Grafo delle componenti fortemente connesse di G

![[appunti asd/mod i/immagini/Pasted image 20221219165907.png|300]]

è sempre un **DAG**
![[appunti asd/mod i/immagini/Pasted image 20221219170011.png|center|300]]


### Come si possono calcolare le componenti fortemente connesse di un grafo diretto?


**Proprietà 1**: se si esegue la procedura visitaDFSricorsiva a partire da un nodo u la procedura termina dopo che tutti i nodi raggiungibili da u sono stati visitati

![[appunti asd/mod i/immagini/Pasted image 20221219165907.png|300]]

**Idea**: eseguire una visita a partire da un nodo di una componente pozzo, "eliminare" la componente e ripetere

#### Come trovo una componente pozzo?

**Proprietà 2**: se C e C' sono due componenti e c'è un arco da un nodo in C verso uno in C', allora il più grande valore post() in C è maggiore del più alto valore di post() di C'

**dim**: 
- se la DFS visita prima C' di C: banale
- se visita prima C, allora si ferma dopo che ha raggiunto tutti i nodi di C e C' e termina su un nodo di C

**Proprietà 3**: il nodo che riceve da una visita DFS il valore più grande di post() appartiene a una componente sorgente

![[appunti asd/mod i/immagini/Pasted image 20221219170808.png|center|300]]

##### Ma avevamo bisogno di una componente pozzo?

**Idea**: invertiamo gli archi!

![[appunti asd/mod i/immagini/Pasted image 20221219171514.png|300]]

**Nota bene:** le componenti fortemente connesse sono le stesse! **(perchè?)**

![[appunti asd/mod i/immagini/Pasted image 20221219171613.png|300]]


![[appunti asd/mod i/immagini/Pasted image 20221219171716.png|center|600]]

![[appunti asd/mod i/immagini/Pasted image 20221219171819.png|center|600]]

![[appunti asd/mod i/immagini/Pasted image 20221219171854.png|center|600]]





