# Least Squares
Dati $n$ punti nel piano: $(x_1,y_1),(x_2,y_2),...,(x_n,y_n)$, *trovare* una retta $y=ax+b$ che minimizza l'errore della somma dei quadrati:$$SSE=\sum_{i=1}^{n}{(y_i-ax_i-b)^2}$$
![[Pasted image 20250330181332.png|center|400]]

>**Soluzione**: Calcoli $\implies$ L'errore minimo viene raggiunto quando: $$a=\frac{n\sum_i x_iy_i-(\sum_i x_i)(\sum_i y_i)}{n\sum_i x_i^2 - (\sum_i x_i)^2},\space b=\frac{\sum_i y_i-a\sum_i x_i}{n}$$

## Segmented Least Squares
- I punti giacciono approssimativamente su una sequenza di segmenti.
- Dati $n$ punti nel piano: $(x_1,y_1),(x_2,y_2),...,(x_n,y_n)$ con $x_1\lt x_2\lt\dots\lt x_n$, *trovare* una sequenza di segmenti che minimizza $f(x)$.
*Q*: Qual è una scelta ragionevole per $f(x)$ per bilanciare accuratezza e parsimonia?
![[Pasted image 20250330182037.png|center|400]]

>**Goal**: Minimizzare $f(x)=E+c\cdot L$ per una costante $c\gt 0$, dove:
>- $E=$ somma delle somme degli errori al quadrato di ogni segmento.
>- $L=$ numero di segmenti.

### Programmazione dinamica: scelta multipla

>[!note] Notazione:
>- $OPT(j)$= costo minimo per i punti $p_1,...,p_j$
>- $e_{ij}$= SSE per i punti $p_i,p_{i+1},...,p_j$

Per **computare** $OPT(j)$:
- L'ultimo segmento usa i punti $p_i,p_{i+1},...,p_j$ per qualche $i\le j$;
- Costo $=e_{ij}+c+OPT(i-1)$ (*Prop. della sottostruttura ottimale*).
**Eq. Bellmann**:$$OPT(j)=\begin{cases}
0&\text{se }j=0\\
\min_{1\le i\le j}\{e_{ij}+c+OPT(i-1)\}&\text{se }j\gt 0
\end{cases}$$
![[Pasted image 20250330183246.png|center|400]]

>[!theorem] Th. Bellmann $[1961]$ 
>L'algoritmo di programmazione dinamica risolve il problema Segmented Least Squares in tempo $O(n^3)$ e spazio $O(n^2)$.
>**Dim**.
>- Collo di bottiglia: Computare SSE $e_{ij}$ per ogni $i$ e $j$: $$\begin{align}&a_{ij}=\frac{n\sum\limits_kx_ky_k-(\sum\limits_kx_k)(\sum\limits_ky_k)}{n\sum\limits_kx_k^2-(\sum\limits_kx_k)^2}\&b_{ij}=\frac{\sum\limits_ky_k-a\sum\limits_kx_k}{n}\end{align}$$
>- $O(n)$ per computare $e_{ij} ._{\square}$ 

>[!note] OSS. Può essere ottimizzato a tempo $O(n^2)$
>- $\forall i$ : pre-calcola le somme comulative $\sum\limits_{k=1}^ix_k,\sum\limits_{k=1}^iy_k,\sum\limits_{k=1}^ix_k^2,\sum\limits_{k=1}^ix_ky_k$
>- Usando le somme comulative, si può calcolare $e_{ij}$ in tempo $O(1)$

# Problema Knapsack
**Goal** : Preparare lo "zaino" in modo da massimizzare il valore totale degli oggetti presi
- Ci sono $n$ oggetti : l'oggetto $i$ ha un valore $v_i\gt0$ e peso $w_i\gt0$
- Valore di un sottoinsieme di oggetti = somma dei valori degli oggetti singoli
- Lo "zaino" (knapsack) ha un limite di peso pari a $W$

**Esempio** : Il sottoinsieme $\{1,2,5\}$ ha valore $35\$$ (e peso 10)
**Esempio** : Il sottoinsieme $\{3,4\}$ ha valore $40\$$ (e peso 11)

**Assunzione** : Tutti i valori e i pesi sono integrali
![[Pasted image 20250330184149.png|center|500]]
## Dynamic Programming : Falsa partenza

>[!definition]
>$OPT(i)$ = Valore ottimale per il problema del knapsack con gli elementi $1,\dots,i$

**Goal** : $OPT(n)$.
Abbiamo 2 casi
1) $OPT(i)$ *non seleziona* l'elemento $i$
2) $OPT(i)$ *seleziona* l'elemento $i$

**Caso 1** : $OPT(i)$ non seleziona l'elemento $i$
- $OPT$ seleziona i migliori tra $\{1,2,\dots,i-1\}$

**Caso 2** : $OPT(i)$ seleziona l'elemento $i$
- Selezionare l'elemento $i$ non implica immediatamente che dobbiamo rigettare gli altri elementi
- Senza sapere quale altro elemento è stato selezionato prima di $i$, non possiamo sapere se abbiamo abbastanza spazio per $i$

**Conclusione** : Servono più sottoproblemi

## Dynamic Programming : Due variabili

>[!definition]
>$OPT(i)$ = Valore ottimale per il problema del knapsack con gli elementi $1,\dots,i$, soggetti al limite di peso $w$

**Goal** : $OPT(n,W)$

Anche qui abbiamo due casistiche

**Caso 1** : $OPT(i)$ non seleziona l'elemento $i$ (possibile perchè $w_i\gt w$)
- $OPT$ seleziona i migliori tra $\{1,2,\dots,i-1\}$ soggetti al peso limite $w$

**Caso 2** : $OPT(i)$ seleziona l'elemento $i$
- Salviamo il valore $v_i$
- Il nuovo peso limite sarà = $w-w_i$
- $OPT(i,w)$ seleziona i migliori tra $\{1,2,\dots,i-1\}$ soggetti al nuovo peso limite

**Equazione di Bellman**

$$OPT(i,w)=\begin{cases}0&i=0\\OPT(i-1,w)&w_i\gt w\\\max\{OPT(i-1,w),v_i+OPT(i-1,w-w_i)\}&\text{altrimenti}\end{cases}$$

### Algoritmo di DP per Knapsack (bottom-up)

![[Pasted image 20250330184332.png|center|500]]

**Esempio**

![[Pasted image 20250330184357.png|center|500]]

#### Tempo di esecuzione

>[!definition] Teorema
>L'algoritmo di DP per il problema del Knapsack con $n$ elementi e peso massimo $W$, lo risolve in tempo $\Theta(nW)$ e spazio $\Theta(nW)$

**Dimostrazione** :
- Impiega tempo $O(1)$ per le entry della tabella
- Ci sono $\Theta(nW)$ entry della tabella
- Dopo aver calcolato il valore della soluzione ottima, possiamo tornare indietro per trovare la soluzione : $$OPT(i,w)\text{ prende l'elemento}\space i\iff M[i,w]\gt M[i-1,w]$$
Ma la domanda fondamentale è la seguente

**Q** : Il tempo di esecuzione dell'algoritmo appena mostrato è polinomiale?

**A** : NO!!, perchè $\Theta(nW)$ non è una funzione polinomiale nella dimensione dell'input, ma si dice `pseudo-polinomiale`

>[!definition] Algoritmo pseudo-polinomiale
>Un algoritmo il cui tempo di esecuzione risulta essere polinomiale nel valore dell'input (es: il più grande intero presente nell'input) :
>- Efficiente quando i numeri nell'input sono ragionevolmente piccoli
>- Non necessariamente polinomiale nella dimensione dell'input (numeor di bits richiesti per rappresentare l'input)





