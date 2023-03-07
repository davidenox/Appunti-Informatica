
# Esercitazione 1

## Esercizio 1
>Dimostrare o confutare la seguente affermazione:
>Date $f(n)$ e $g(n)$, allora vale che:
>$f(n)=O(g(n))\implies 2^{f(n)}=O(2^{n/2})$

Soluzione:

prendiamo $f(n)=n\:e\:g(n)=n/2$
Così vale che $n=O(n/2)$, ma $2^n\neq O(2^{n/2})$

Infatti:
$lim_{n\to\infty}\frac{n}{n/2}=1/2\lt\infty$ e quindi $n=O(n/2)$

Ma:
$lim_{n\to\infty}\frac{2^n}{2^{n/2}}=2^{n/2}=\infty$ e quindi $2^n=\omega(2^{n/2})$

### Altri esempi per cui non vale l'implicazione
- $f(n)=2n\:e\:g(n)=n$
- $f(n)=n\:e\:g(n)=n^2$
- etc

## Esercizio 2

>Progettare un algoritmo (efficiente) che, dato un array ordinato $A[1:n]$ di n interi e un intero x, trova (se esistono) due indici i e j, $i\lt j$, tale che $A[i]+A[j]=x$

Soluzione banale:
Fisso "i", e per ogni "i" lo confronto con n-1 "j",se li trovo li ritorno, altrimenti ritorno -1
```python
def funzione(A,x):
    n=len(A)
    for i in range(n-1):
        for j in range(i+1,n):
            if A[i]+A[j]==x:
                return i,j
    return (-1,-1)
a = [2,5,9,14,20,21,25,40]
print(funzione(a,25))
```

Corretto? Sì
Complessità? $O(n^2)$

Soluzione non banale

Utilizzo il binarysearch per cercare l'indice j, e per ogni i confronto i con il j trovato dal binarysearch, se j non viene trovato mi ritorna -1
```python
def bin_search( a, k ):
    n = len(a)
    lx, rx = 0, n-1
    while lx <= rx: # fintanto che lo spazio di ricerca non è vuoto
        cx = (lx + rx)//2
        if k == a[cx]:
            return cx
        if k < a[cx]:
            rx = cx-1
        else: # k > a[cx]
            lx = cx+1
    return -1

def algoritmo(A,x):
    n=len(A)
    for i in range(n-1):
        j=bin_search(a,x-A[i])
        if (A[i]+A[j]==x):
            return i,j
    return (-1,-1)

a = [2,5,9,14,20,21,25,40]
print(funzione(a,26))
```

Corretto? Si
Complessità? $O(nlog(n))$

Soluzione meglio di nlog(n)

**Idea**: scansionare l'array "parallelamente" da sinistra e da destra
```python
def Lineare(A,x):
    n=len(A)
    i,j=0,n-1
    while i<j:
        if (A[i]+A[j]==x):
            return i,j
        if (A[i]+A[j]<x):
            i+=1
        else:
            j-=1
    return (-1,-1)

a = [2,5,9,14,20,21,25,40]
print(funzione(a,54))
```

Complessità? $O(n)$
Correttezza? Da vedere

**Oss**: Se non esistono due elementi di A che sommano a x l'algoritmo _Lineare_ risponde sicuramente bene, ovvero restituisce (-1,-1)

# Esercitazione 2

## Esercizio 1

### Risposta alla domanda a
Utilizzo un algoritmo che in tempo $O(log(n))$ mi trova l'indice del massimo. L'algoritmo si basa sul fatto che $a[m]>a[m-1]\:e\:a[m+1]$ 
Il codice è questo:
```python
#a = [2,4,20,13,9,6,5,2]
a = [2,4,20,30,31,6,5,2]
def funzione(a):
    n = len(a)
    lx,rx = 0,n-1
    while lx<=rx:
        cx = (rx+lx)//2
        if (a[cx-1]<a[cx] and a[cx+1]<a[cx]):
            return cx
        if a[cx-1]>a[cx]:
            rx=cx-1
        else:
            lx=cx+1
print(funzione(a))
```
### Risposta alla domanda b
Dato m trovato prima, sappiamo che le due "metà" $a[1:m]$ e $a[m+1,n]$ sono già ordinate
A questo punto utilizzo il Merge per fonderle velocemente
Codice:
```python
import math
a = [2,4,20,30,31,6,5,2]
def trovaMax(a):
    n = len(a)
    lx,rx = 0,n-1
    while lx<=rx:
        cx = (rx+lx)//2
        if (a[cx-1]<a[cx] and a[cx+1]<a[cx]):
            return cx
        if a[cx-1]>a[cx]:
            rx=cx-1
        else:
            lx=cx+1
def ordina(a,m):
    n=len(a)
    if m != n:
        Inverti(a,m)
        if m!=1:
            a = merge(a[:m],a[m:])
    return a
def Inverti(a,m):
    n=len(a)-1
    while m<n:
        tmp = a[m]
        a[m]=a[n]
        a[n]=tmp
        m+=1
        n-=1
    return a
def merge( a, b ):
    n_a, n_b = len(a), len(b)
    i, j = 0, 0 # indice in a ed in b rispettivamente
    c = [] # lista di output
    while i < n_a and j < n_b:
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    c += a[i:] + b[j:]
    return c
max = trovaMax(a)
print(ordina(a,max))
```
Con la funzione trovaMax trovo l'indice dell'elemento maggiore nell'array A, come nella risposta a
Poi partendo da m inverto la lista, quindi inverto da m a fine lista (tutta la parte sinistra partendo da m)
a questo punto in tempo lineare eseguo il merge delle due sottoliste e ottengo l'array ordinato in tempo $o(nlog(n))$

## Esercizio 2

## Esercizio 3 (opzionale)

Sia $V[1:n]$ un vettore di n caratteri, dove ogni posizione può contenere un carattere nell'insieme $\lbrace Y,E,S\rbrace$. il vettore è organizzato in modo che, se letto da sinistra verso destra, si ottiene pirma un seq. non nulla di Y, poi di E e poi si S
Progettare un algoritmo che in tempo $o(n)$ calcoli il numero di Y,E,S nel vettore.

Codice:
```python
a = ["Y","Y","E","E","E","E","S","S"]
def algoritmo(a):
    num_y = applicazionebinsearch(a,"Y",0)
    num_e = applicazionebinsearch(a,"E",1)-num_y
    num_s = applicazionebinsearch(a,"S",2)-(num_e+num_y)
    return(num_y,num_e,num_s)
def applicazionebinsearch(a,k,flag):
    """flag = 0 per Y, flag = 1 per E, flag = 2 per S"""
    n = len(a)
    lx, rx = 0, n-1
    while lx <= rx:
            cx = (lx + rx)//2
            if k == a[cx] and ( cx == n-1 or a[cx+1] != k ):
                return cx+1
            if flag == 0 or flag == 1:
                if k != a[cx+1]:
                    rx = cx-1
                else:
                    lx = cx+1
            else:
                if k != a[cx-1]:
                    lx = cx+1
                else:
                    rx = cx-1
    return -1
print(algoritmo(a))
```

Pseudocodice

Algoritmo
![[appunti asd/mod i/esercizi/imges/Pasted image 20221117115715.png|center|700]]

Applicazione BinSearch
![[appunti asd/mod i/esercizi/imges/Pasted image 20221117115744.png|center|700]]


# Esercitazione 3

L'albero per es 1 e es2 è fatto così

```python
class TreeNode:
    def __init__(self, val, left=None, right=None,col = None):
        self.val = val
        self.left = left
        self.right = right
        self.col = col
root = TreeNode(1)
l1 = TreeNode(10)
r1 = TreeNode(4)
l1_l = TreeNode(1)
l1_r = TreeNode(2)
l1_l_l = TreeNode(1)
l1_l_r = TreeNode(2)
l1_r_l = TreeNode(30)
l1_r_l_l = TreeNode(50)
l1_r_r = TreeNode(2)
r1_l = TreeNode(15)
r1_l_l = TreeNode(2)
r1_r = TreeNode(20)
r1_r_l = TreeNode(20)
  
root.col = "R"
l1.col = "R"
r1.col = "R"
l1_l.col = "R"
l1_l_l.col = "R"
l1_r.col = "R"
l1_l_r.col = "R"
l1_r_l.col = "N"
l1_r_l_l.col = "R"
l1_r_r.col = "R"
r1_l.col = "R"
r1_l_l.col = "N"
r1_r.col = "N"
r1_r_l.col = "R"
  
root.left = l1
root.right = r1
l1.left = l1_l
l1.right = l1_r
l1_l.left = l1_l_l
l1_l.right = l1_l_r
l1_r.left = l1_r_l
l1_r.right = l1_r_r
l1_r_l.left = l1_r_l_l
r1.left = r1_l
r1.right = r1_r
r1_l.left = r1_l_l
r1_r.left = r1_r_l

```

## Esercizio 1

Dato un albero binario T di n nodi, dove ogni nodo ha: **valore** $val(v)\gt0$, **colore** $col(v)\in\lbrace R,N\rbrace$,ottenere il valore del cammino rosso di tipo radice-nodo di valore massimo

![[appunti asd/mod i/esercizi/imges/Pasted image 20221121160455.png|center]]

Def: il **valore di un cammino** è la somma di valori dei nodi del cammino
Def: un cammino è **rosso** se tutti i suoi nodi sono di colore rosso

![[appunti asd/mod i/esercizi/imges/Pasted image 20221121160433.png|center|500]]

Soluzione in python:
```python

def problema_1(root):
    if root == None:
        return 0
    if root.col == "N":
        return 0
    return root.val+max(problema_1(root.left),problema_1(root.right))
  
n = problema_1(root)
print(n)
```

Pseudocodice:
Arriverà!!

Complessità $O(n)$

## Esercizio 2

Input:
- albero binario T di n nodi
- un intero $h\geq0$

Output: numero di nodi di T con profondità almeno h

Def: **profondità di un nodo** distanza (#di archi) dalla radice

Es: $h=3\implies output=7$

Soluzione in python

```python
def problema_2(root,h,i):
    #Uso la visita in ampiezza, algoritmo BFS
    #i = livello
    if root == None:
        return 0
    if i>=h:
        return 1+problema_2(root.left,h,i+1)+problema_2(root.right,h,i+1)
    else:
        return problema_2(root.left,h,i+1)+problema_2(root.right,h,i+1)
```

## Esercizio 3

Input:
- albero binario T di n nodi
- ogni nodo v ha un valore $val(v)\gt0$

Output: numero di nodi che soddisfano $\overbrace{\text{somma dei valori degli antenati del nodo}=\text{somma dei valori dei discendenti del nodo}}^{=\Delta}$

Esempio

![[appunti asd/mod i/esercizi/imges/Pasted image 20221121171612.png|center|500]]

Soluzione python

```python
def problema_3(root,SA):
    if root == None:
        return (0,0)
    SA = SA+root.val
    (SD_s,k_s) = problema_3(root.left,SA)
    (SD_d,k_d) = problema_3(root.right,SA)
  
    SD = SD_s+SD_d+root.val
    if SD == SA:
        return (SD,1+k_s+k_d)
    else:
        return (SD,k_s+k_d)
```

# Esercitazione 4

## Esercizio 1

**Input**: vettore ordinato $A[1:n]$ di n bit, ovvero $A[i]\in\lbrace 0,1\rbrace$
**Output**: l'indice k dell'ultimo 0

![[appunti asd/mod i/esercizi/imges/Pasted image 20221201092633.png|center|600]]

**Goal1**: $O(log(n))$
**Idea1** (di base): uso l'approccio della ricerca binaria

![[appunti asd/mod i/esercizi/imges/Pasted image 20221201092412.png|center|600]]

Complessità? $O(log(n))$

Goal2: $O(log(k))$

![[appunti asd/mod i/esercizi/imges/Pasted image 20221201092633.png|center|600]]

Soluzione? 
Scorro l'array in base alle potenze di 2, mi trovo in un caso in cui avrò che l'elemento in posizione $2^i=0$ e $2^{i+1}=1$
A quel punto mi trovo l'indice k in tempo $O(log(k))$ utilizzando la ricerca binaria classica

Infatti,
**Idea:** trovare in $O(log(k))$ due indici $i^\star,j^\star$ tali che:
- $A[i^\star]=0,A[j^\star]=1$
- $|j^\star-i^\star|=O(k)$ su cui fare la ricerca binaria in tempo log(k)

**Analisi**:
Ho guardato $i+2=O(i)$ elementi:
- $2^i\leq k\implies i\leq log_2k$
- $j^\star-i^\star=2^{i+1}-2^i=2^i\leq k\implies A[i^\star:j^\star]$ ha $j^\star-i^\star+1$ elementi e quindi $O(k)$ elementi

## Esercizio 2

**Input**: vettore $A[1:n]$ di n bit, ovvero $A[i]\in\lbrace 0,1\rbrace$
**Output**: l'indice k tale che num di zeri in $A[1:k]$ = num di uno in $A[k+1:n]$

![[appunti asd/mod i/esercizi/imges/Pasted image 20221201095802.png]]

Goal: $O(n)$

Soluzione nostra:
Tempo $O(nlog(n))$

```python
def prob2(a,i,j):
    n=len(a)
    k = (i+j)//2
    k_i,k_j=k,k+1
    count_0,count_1=0,0
    while k_i>0 and k_j<n-1:
        if a[k_i] == 0:
            count_0+=1
            k_i-=1
        else:
            k_i-=1
        if a[k_j]==1:
            count_1+=1
            k_j+=1
        else:
            k_j-=1
    if count_1 == count_1:
        return k
    if count_1 > count_0:
        k=binsearch(a,(3j/2))
        return prob2(a,i,k)
    else:
        k=binsearch(a,(j/2))
        return prob2(a,i,k)
```

Soluzione prof:

[Soluzione prof](http://www.mat.uniroma2.it/~guala/esercitazione_4_2021.pdf) da pagina 9 a 10

Soluzione perfetta (anche se non sembra):
```python
def prob2(a):
    n=len(a)
    count=0
    for i in range(n):
        count+=a[i]
    return count
```

Complessità? $O(n)$

# Esercitazione 5

## Esercizio 1

Grafo diretto e pesato $G=(V,E,w)$, ad ogni arco è associato un peso $w(e)\geq0$ che rappresenta il costo della benzina 
Due nodi $s_1,s_2$ e un nodo di arrivo $t$ 
Per ogni nodo $v$ si conosce il costo del parcheggio, ovvero $c(v)$ (per semplicità si assume che $c(s_1)=c(s_2)=c(t)=0$)
Progettare un algoritmo con complessità $O(m+nlog(n))$ che faccia spendere il meno possibile in termini di costo della benzina e del parcheggio

**Grafo**

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112091415.png|center|500]]

**Idea/Soluzione**

"Indovinare" il nodo in cui Guala e Clementi parcheggiano l'auto, e poi da li calcolare il cammino minimo verso t

$cost(x):=d(s_1,x)+d(s_2,x)+c(x)+d(x,t)$

cost(x) costo totale se guala e clementi parcheggiano nel nodo x

**Corretto?** Si
**Complessità**?

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112091612.png|center|500]]

Costo $O(m+nlog(n))$

## Esercizio 2

- grafo orientato G=(V,E,w) con pesi non negativi
- $B\subseteq E$ sottoinsieme di archi blu 
- k intero, $s,t\in V$

Output: un cammino di costo minimo da s a t che usa al più k archi blu

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112111246.png|center|400]]

**Idea 1/Soluzione**

"Indovinare" i k archi blu della soluzione

$\overline G=(V,E-B)$  
Per ogni k-tupla F di archi in B:
- calcola il cammino minimo da s a t nel grafo $\overline G+F$ 
restituisci il miglior cammino trovato

Correttezza?
- Ogni cammino calcolato è un cammino ammisibbile
- Quando guardo la k-tupla usata dalla soluzione (o un sovrainsieme) il cammino calcolato è quello ottimo cercato

Complessità? $O(|B|^k(m+nlog(n)))$

**Idea 2/Soluzione**

Ridurre il problema al calcolo di un cammino minimo su un opportuno grafo ausiliario $G'$

- $G'$ fatto "a livelli"
- ogni volta che uso un arco blu sono costretto a cambiare livello
- num. livelli dipende da k

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112112027.png|center|600]]


**Definizione di $G'$**

nodi:

- per ogni nodo $v\in V$ ho $k+1$ nodi $v_0,v_1,...,v_k$
- un nodo $\overline t$

archi:
- per ogni arco (u,v) non blu in G ho gli archi ($u_i,v_i$), $i=0,1,..,k$ di peso $w(u,v)$
- per ogni arco (u,v) blu in G ho gli archi ($u_i,v_{i+1}$),$i=0,1,...,k-1$ di peso $w(u,v)$
- ho archi $(t_i,\overline t)$, $i=0,1,...,k$ di peso 0

soluzione cercara: cammino minimo in $G'$ da $s_0\to\overline t$

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112114304.png|center|400]]

**correttezza**:

>[!tips]- Proprietà
>Esiste un cammino in G da s a t che usa al più k archi blu di costo w se e solo se esiste un cammino in $G'$ da $s_0$ a $\overline t$ di costo w

**complessità**
- dimensione di $G'$:
	- $n'=n(k+1)+1=\Theta(nk)$
	- $m'\leq(k+1)m+k=\Theta(mk)$
- costruzione di $G'$: $O(m'+n')=O(k(m+n))$
- calcolo cammino minimo in $G'$: $O(m'+n'log(n'))=O(k(m+nlog(n)))$

Quindi l'algoritmo ha costo $O(k(m+nlog(n)))$ 

# Esercitazione 6

## Esercizio 1

Grafo non orientato e non pesato $G=(V,E)$
Due nodi $s_1,s_2$ e due nodi di arrivo $t_1,t_2$ 
I due robot devono stare a distanza almeno k, con k elemento del problema

**Obiettivo**: Spostare $s_1\to t_1,s_2\to t_2$
**Mossa**: sposta un robot verso il nodo adiacente
**Vincolo**: i robot devono essere sempre a distanza almeno k

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112093134.png|center|300]]

Trovare la sequenza minima di mosse.

**Esempio** Da pagina 4 a pagina 14 [Esempio](http://www.mat.uniroma2.it/~guala/esercitazione_6_2021.pdf#page=4)

**Idea/Soluzione**

Ridurre il problema al calcolo di un cammino minimo in un opportuno **grafo delle configurazioni**

Grafo ausiliario $G'=(V',E')$ definito così:
- $V'=\{\langle u,v\rangle:u,v\in V,d_G(u,v)\geq k\}$
- $E'=\{(\langle u,v\rangle,\langle x,y\rangle):(u=x,(v,y)\in E)\lor(v=y,(u,x)\in E)\}$

Una possibile configurazione:
![[appunti asd/mod i/esercizi/imges/Pasted image 20230112094651.png|center|250]]

Robot blu su "u" e robot rosso su "v"

Il grafo è fatto in questo modo:

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112094846.png|center|500]]

Adesso quello che devo fare è cercare un cammino minimo da $\langle s_1,s_2\rangle\to\langle t_1,t_2\rangle$

**Correttezza**:

>[!tips]- Proprietà
>Esiste una sequenza di k mosse che porta i robot nella posizione finale **se e soltanto se** essite un cammino in $G'$ da $\langle s_1,s_2\rangle\to\langle t_1,t_2\rangle$ di lunghezza k

**Complessità**

Dimensione di $G'$: 

$|V'|=O(n^2)$ 
$$\begin{align}&|E'|\leq\sum_{\{u,v\}\in V'}\delta_{G'}(\{u,v\})\leq\sum_{\{u,v\}\in V'}(\delta_G(u)+\delta_G(v))=\sum_{\{u,v\}\in V'}\delta_G(u)+\sum_{\{u,v\}\in V'}\delta_G(u)\leq\\&\sum_{u,v\in V}\delta_G(u)+\sum_{u,v\in V}\delta_G(v)\leq n\sum_{u\in V}\delta_G(u)+n\sum_{v\in V}\delta_G(v)\leq 2nm+2nm=O(nm)\end{align}$$

Calcolo cammino minimo in $G'$:

$O(|V'|+|E'|)\implies O(n^2+nm)=O(nm)$

Costruzione di $G'$:

$O(|V'|+|E'|)=O(nm)$ Se trovo le distanze fra tutte le coppie in $O(nm)$ (eseguo n visite BFS, una da ogni vertice)

## Esercizio 2

Grafo non orientato $G=(V,E)$ di n nodi e m archi
Alice vuole spostarsi in tutti i rimenenti n-1 nodi
Ad ogni arco è associato un valore $w(e)$ che indica l'età minima necessaria per attraversare l'arco

Un posto v è raggiungibile da Alice all'età x se esiste un cammino da s a v composto di soli archi di peso minore o uguale a x

Progettare un algoritmo che calcoli l'età minima che consente ad Alice di vedere il mondo intero, ovvero la più piccola età x per cui tutti i posti sono raggiungibili da Alice all'età x

Esempio di grafo

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112101504.png|center|500]]

**Esempio** da pagina 20 a pagina 29 [Esempio](http://www.mat.uniroma2.it/~guala/esercitazione_6_2021.pdf#page=20)

**Idea/Soluzione**

Far crescere l'insieme degli archi utilizzabili con l'età

Considera gli archi di G ordinati in ordine crescente di peso:
$\underbrace{e_1,e_2,e_3,...,e_i}_{E_i},...,e_{m-1},e_m$
$G_i=(V,E_i)$

**Osservazione**: se $G_i$ è connesso allora Alice può vedere il mondo intero all'età di $w(e_i)$

**Goal**: trovare il minimo i per cui $G_i$ è connesso

**Corretto?** Si, per oss. precedente
**Complessità?**

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112104216.png|center|600]]


Posso fare di meglio? Si, cerco l'indice i utilizzando la ricerca binaria

![[appunti asd/mod i/esercizi/imges/Pasted image 20230112104548.png|center|600]]

SI poteva risolvere anche con il calcolo del Minimum Spanning Tree, ma è un piccolo spoiler per ASD Mod 2