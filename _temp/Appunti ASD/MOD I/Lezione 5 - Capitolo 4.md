
# Ordinamento

## Il problema dell'ordinamento
- Input : una sequenza di n numeri $\langle a_1,a_2,....,a_n\rangle$
- Output: una permutazione(riarrangiamento) $\langle a_1',a_2',...,a_n'\rangle$ della sequenza data in input tale che $a_1'\leq a_2'\leq...\leq a_n'$ 

# Ordinare in tempo quadratico
## Selection Sort
**Approccio incrementale**: estende l'ordinamento da ka a k+1 elementi, scegliendo il minimo degli n-k elementi non ancora ordinati e mettendolo in posizione k+1

![[Pasted image 20221020092539.png|center|500]]

**Pseudo-codice**:
>SelectionSort(A)
>1. for k=0 to n-2 do
>2. m=k+1
>3. for j=k+2 to n do
>4. if($A[j]\lt A[m]$) then m=j
>5. scambia $A[m]\:con\:A[k+1]$

- Al generico passo k,$A[1],...,A[k]$ sono già ordinati
- linee 2-4: ricerca del minimo fra gli elementi $A[k+1],..,A[n]$
- m è l'indice dell'array in vui si trova il minimo
- il minimo è messo in posizione k+1

**Corretto?**
è facile convincersi che l'algoritmo mantiene le seguenti **invarianti**: dopo il generico passo k (k=0,...,n-2) abbiamo che:
- i primi k+1 elementi sono ordinati e
- sono i k+1 elementi più piccoli dell'array

>**Oss**: ragionare per invarianti è uno strumento utile per dimostrare la correttezza di un algoritmo, perchè permette di isolare proprietà dell'algoritmo, spiegarne il funzionamento, capire a fondo l'idea su cui si basa

### Complessità temporale (analisi)
T(n)=#operazioni elementari sul modello RAM a costi uniformi eseguiita dall'algoritmo nel caso peggiore su istanze di dimensione n
#### Upper Bound

>SelectionSort(A)
>1. for k=0 to n-2 do
>2. m=k+1
>3. for j=k+2 to n do
>4. if($A[j]\lt A[m]$) then m=j
>5. scambia $A[m]\:con\:A[k+1]$

- linee da 3 a 5: eseguite al più n volte per ogni ciclo esterno
- linee da 1 a 5: ciclo esterno eseguito al più n volte
Ogni linea di codice costa O(1)
$T(n)\leq 5n^2O(1)=\Theta(n^2)\implies T(n)=O(n^2)$

#### Lower Bound

>SelectionSort(A)
>1. for k=0 to n-2 do
>2. m=k+1
>3. for j=k+2 to n do
>4. if($A[j]\lt A[m]$) then m=j
>5. scambia $A[m]\:con\:A[k+1]$

Idea: conto solo i confronti fra elementi
- linea 3-4: esegue n-k-1 confronti

$T(n)\geq\sum_{k=0}^{n-2}(n-k-1)=\sum_{k=1}^{n-1}(k)=n(n-1)/2=\Theta(n^2)\implies T(n)=\Omega(n^2)$

Upper Bound $O(n^2)$ e Lower Bound $\Omega(n^2)$ allora $T(n)=\Theta(n^2)$

## Altri algoritmi di ordinamento con tempo $O(n^2)$
### Insertion Sort
**Approccio incrementale**: estende l'ordinamento da k a k+1 elementi, posizionando l'elemento (k+1)-esimo nella posizione corretta rispetto ai primi k elementi
![[Pasted image 20221020093938.png|center|500]]

### Bubble Sort
**Approccio incrementale**: esegue n-1 scansioni. Ad ogni scansione guarda coppie di elementi adiacenti e li scambia se non sono nell'ordine corretto

![[Pasted image 20221020094051.png|center|500]]

**Esercizio**
Scrivere per i due algoritmi lo pseudo-codice ed effettuare l'analisi nel caso peggiore

# Ordinare in tempo meno che quadratico
## MergeSort
Usa la tecnica del divide et impera.
1. **Divide**: dividi l'array a metà
2. Risolvi i due sottoproblemi ricorsivamente
3. **Impera**: fondi le due sottosequenze ordinate

**Pseudo-codice**
> MergeSort(A,i,f)
> 1. if(i<f) then
> 	1. m=(i+f)/2
> 	2. MergeSort(A,i,m)
> 	3. MergeSort(A,m+1,f)
> 	4. Merge(A,i,m,f) $\implies\:fonde\:A[i;m]\:e\:A[m+1;f]\:output\:A[i;f]$

**Notazione**: dato un array A e due indici $x\leq y$,denotiamo con $A[x;y]$ la porzione di A costituita da $A[x],A[x+1],...,A[y]$

### Esempio di esecuzione
![[Pasted image 20221020094724.png|center|600]]


### Procedura Merge
Due array ordinati A e B possono essere fusi rapidamente:
- estrai ripetutamente il minimo di A e B e copialo nell'array di output, finchè A oppure B non diventa vuoto
- copia gli elementi dell'array non vuoto alla fine dell'array di output

**Pseudo-codice Merge**
>$Merge(A,i_1,f_1,f_2)$
>1. Sia X un array ausilirario di lunghezza $f_2-i_1+1$
>2. $i=1;k_1=i_1$
>3. $k_2=f_1+1$
>4. while($k_1\leq f_1\:e\:k_2\leq f_2$) do
>	1. if($A[k_1\leq A[k_2]$)
>	2. then $X[i]=A[k_1]$
>		1. incrementa i e $k_1$
>	3. else $X[i]=A[k_2]$
>		1. incrementa i e $k_2$
>2. if($k_1\leq f_1$) then copia $A[k_1;f_1]$ alla fine di X
>3. else copia $A[k_2;f_2]$ alla fine di X
>4. copia X in $A[i_1;f_2]$

**Lemma** La procedure Merge fonde due sequenze ordinate di lunghezza $n_1\:e\:n_2$ in tempo $\Theta(n_1+n_2)$
**dim**
Ogni confronto "consuma" un elemento di una delle due sequenze. Ogni posizione di X è riempita in tempo costante. Il numero totale di elementi è $n_1+n_2$.Anche l'ultima linea (copia del vettore ausiliario) costa $\Theta(n_1+n_2)$

### Tempo di esecuzione
La complessità termporale del MergeSort è descritto dalla seguente relazione di ricorrenza:
$$T(n)=2T(n/2)+O(n)$$
Usando i teorema Master abbiamo che:
$$T(n)=O(nlog(n))$$
**Quanta memoria ausiliaria usiamo?**
La complessità spaziale del MergeSort è $\Theta(n)$:
- la procedura Merge usa memoria asuiliaria pari alla dimensione di porzione da fondere;
- non sono mai attive due procedure di Merge contemporaneamente
- ogni chiamata di MergeSort usa memoria costante(esclusa quella usata dalla procedura Merge)
- numero di chiamate di MergeSOrt attive contemporaneamente sono $O(log(n))$

Il MergeSort non ordina in loco:
- occupazione di memoria ausiliaria pari a $\Theta(n)$

# Ancora un algoritmo di ordinamento che usa la tecnica del divide et impera: il Quick Sort

## QuickSort
Usa la tecnica del divide et impera:
1. **Divide**: scegli un elemento x della sequenza(perno) e partiziona la sequenza in elementi $\leq x$ ed elementi $\gt x$
2. Risolvi i due sottoproblemi ricorsivamente
3. **Impera**: restituisci la concatenazione delle due sottosequenze ordinate

Rispetto al MergeSort, divide complesso ed impera semplice

### Partizione in loco
- Scegli il perno
- Scorri l'array in "parallelo" da sinistra verso destra e da destra verso sinistra
	- da sinistra verso destro, ci si ferma su un elemento maggiore del perno
	- da destra verso sinistra, ci si ferma su un elemento minore del perno
- Scambia gli elementi e riprendi la scansione

**Esempio**

![[Pasted image 20221020101754.png|center|600]]

**Pseudo-codice Partition**

>Partition(A,i,f)
>1. $x=A[i]$
>2. inf=i
>3. sup=f+1
>4. while(true) do
>	1. do (inf=inf+1) while ($inf\leq f\:e\:A[inf]\leq x$)
>	2. do (sup=sup-1) while ($A[sup\gt x]$)
>	3. if ($inf\lt sup$) then scambia $A[inf]\:e\:A[sup]$
>	4. else **break**
>5. scambia $A[i]\:e\:A[sup]$
>6. return sup

Partiziona $A[i;f]\:rispetto\:a\:A[i]$
- penultima linea: mette il perno "al centro"
- ultima linea: restituisce l'indice del "centro"

**Proprietà(invariante)**: 
In ogni istante, gli elementi $A[i],...,A[inf-1]$ sono $\leq$ del perno, mentre gli elementi $A[sup+1],...,A[f]$ sono $\gt$ del perno

**Pseudo-codice QuickSort**

>QuickSort(A,i,f)
>1. if($i\lt f$) then
>	1. m=Partition(A,i,f)
>	2. QuickSort(A,i,m-1)
>	3. QuickSort(A,m+1,f)

**Esempio di esecuzione**

![[Pasted image 20221020102641.png|center|500]]

L'albero delle chiamate corsive può essere sbilanciato

**Corretto?** si

### Complessità: 
#### Analisi nel caso peggiore
Ogni invocazione di Partition posiziona almeno un elemento in modo corretto (il perno)
Quindi dopo n invocazioni di Partition, ognuna di costo $O(n)$ ho il vettore ordinato. Il costo complessivo è quindi $O(n^2)$

Il caso peggiore si verifica quando il perno scelto ad ogni passo è il minimo o il massimo degli elementi nell'array
La complessità in questo caso è:
$$T(n)=T(n-1)+T(0)+O(n)=T(n-1)+O(1)+O(n)=T(n-1)+O(n)\implies T(n)=O(n^2)$$
#### Analisi caso migliore
$O(nlog(n))$, partizionamento sempre bilanciato = albero della ricorsione bilanciato

![[Pasted image 20221020103857.png|center|600]]

#### Analisi caso medio

- **Problema**: la partizione può essere sbilanciata
	- La probabilità che ad ogni passo si presenti la partizione peggiore è molto bassa
	- Per partizione che non sono "troppo sbilanciate" l'algoritmo è veloce
- **Domanda**: quale è la complessità dell'algoritmo suppondendo che l'algoritmo di partizionamento produca sempre una partizione proporzionale 9-a-1?
	- E se la partizione fosse sempre proporzionale a 99-a-1?
- **Nota**: sembrano partizioni piuttosto sbilanciate

La complessità è ancora $O(nlog(n))$

![[Pasted image 20221020104253.png|center|620]]


... e se le istanze non sono equiprobabili?
### Versione Randomizzata
Si sceglie il perno x a caso fra gli elementi da ordinare

**Teorema** L'algoritmo quickSort randomizzato ordina in loco un array di lunghezza n in tempo $O(n^2)$ nel caso peggiore $O(nlog(n))$ con alta probabilità, overo con probabilità almeno 1-1/n

#### Randomizzazione $\neq$ caso medio
- nessuna assunzione sulla distribuzione di prbabilità delle istanze
- nessun input specifico per il quale si verifica il caso peggiore
- il caso peggiore determinato solo dal generatore di numeri casuali



