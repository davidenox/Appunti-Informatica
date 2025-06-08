# Interval Scheduling
- Un job $j$ inizia al tempo $s_j$ e termina al tempo $f_j$;
- Due job sono *compatibili* se non si sovrappongono;
- **Goal**: Trovare il sottoinsieme massimo di job mutualmente compatibili.
![[Pasted image 20250305103323.png|center|500]]

>Input:
>- Un insieme di $n$ intervalli $I_1,...,I_n$
>- L'intervallo $I_i$ ha tempo di inizio $s_i$ e tempo di fine $f_i$

>Soluzione ammissibile:
>- Un sottonsieme $S$ degli intervalli che sono mutualmente compatibili, ovvero $\forall I_i,I_j\in S, I_i\text{ non si sovrappone con }I_j$.

>Misura (da massimizzare):
>- Numero di intervalli schedulati, ovvero la cardinalità di $S$.

## Algoritmi greedy

>[!important]- Template Greedy: Considerare i job in qualche ordine naturale; accettare ogni lavoro purché compatibile con quelli già svolti.

> **Earliest start time**
> - Valutare i job in ordine di tempo di inizio $s_j$

>**Earliest finish time**
>- Valutare i job in ordine di tempo di fine $f_j$

>**Shortest interval**
>- Valutare i job in ordine di tempo $f_j-s_j$

>**Fewest conflicts**
>- Per ogni job $j$, conta il numero di job sovrapposti $c_j$. Ordina per $c_j$

![[Pasted image 20250305114241.png|center|300]]

### Earliest finish time first

```pseudo
Earliest-Finish-Time-First(n, s1,s2,...,sn, f1,f2,...,fn)
Ordina i job per tempo di fine e rinomina in modo che f1<=f2<=...<=fn
S <- insieme vuoto
for j=1 to n do
	if(job j compatibile con S) then
		S <- S \union {j}
return S
```

#### Demo

![[interval_scheduling.gif|center|500]]

>[!important] Affermazione
>È possibile implementare l'EarliestFinishTime in tempo $O(n\log n)$.
>- Tenere traccia dell'ultimo job $j^*$ aggiunto in $S$
>- Il job $j$ è compatibile con $S$ solo se $s_j\ge f_{j^*}$
>- Ordinare per tempo di fine richiede tempo $O(n\log n)$.

#### Analisi dell'algoritmo
Sia $i_1,...,i_k$ l'insieme dei job selezionati dal greedy (ordinate per tempo di fine).
Sia $j_1,...,j_m$ l'insieme dei job in una soluzione ottimale ( ordinate per tempo di fine).
Si denota $f(i_r)$ il tempo di fine del job $i_r$.
>**Lemma**. Per ogni $r=1,2,..,k$ abbiamo che $f(i_r)\le f(j_r)$

>**Dim.**(induzione)
>- $r=1$ è banale.
>- $r\gt 1$:
>- ![[Pasted image 20250305115722.png|center|500]] Il job $i_r$ deve finire per forza non più tardi di $j_r$.

>[!important]- Th. L'algoritmo Earliest-finish-time è ottimale.
>**Dim**. (Contraddizione):
>- Sia $i_1, i_2, ... i_k$ l'insieme dei job selezionati da greedy (ordinati in base ai tempi di fine).
>- Sia $j_1, j_2, ... j_m$ un insieme di job in una soluzione ottima (ordinati per tempo di fine).
>- **Supponiamo** che greedy non sia ottimale:
>	- Allora $m>k$
>![[Pasted image 20250305120311.png|center|500]]

# Interval Partitioning
- La lezione $j$ inizia a tempo $s_j$ e finisce al tempo $f_j$.
- **Goal**: Trovare il numero minimo di classi per schedulare tutte le lezioni in modo che due lezioni non siano nello stesso momento nella stessa classe.

*Es*. Questa schedule utilizza 4 classi per 10 lezioni:
![[Pasted image 20250305121250.png|center|500]]
*Es*. Questa ne utilizza 3 per 10 lezioni:
![[Pasted image 20250305121342.png|center|500]]

>Input:
>- Un insieme di $n$ intervalli $I_1,...,I_n$
>- L'intervallo $I_i$ ha tempo di inizio $s_i$ e tempo di fine $f_i$.

>Soluzione ammissibile:
>- Una partizione degli intervalli come sotto insiemi (classi) $C_1,...,C_d$ in modo che ogni $C_i$ contiene intervalli mutualmenti compatibili.

>Misura (da minimizzare):
>- Numero di classi $d$.

![[Pasted image 20250305121904.png|center|300]]

### Earliest start time first

```pseudo
Earliest-Start-Time-First(n, s1,s2,...,sn, f1,f2,...,fn)
Ordina le lezioni per tempo di inizio e rinomina in modo che s1<=s2<=...<=sn
d <- 0 //numero di classi allocate
for j=1 to n do
	if(lezione j compatibile con qualche classe) then
		schedula lezione j in una qualsiasi classe k
	else
		alloca una nuova classe d+1
		schedula la lezione j nella classe d+1
		d <- d+1
return schedulazione
```

#### Demo
![[interval_partitioning.gif|center|500]]

>[!important] Affermazione
>L'algoritmo Earliest-start-time-first può essere implementato in tempo $O(n\log n)$.
>- L'ordinamento in base agli orari di inizio richiede tempo $O(n\log n)$.
>- Memorizza le aule in una **coda prioritaria** (chiave = ora di fine dell'ultima lezione).
>	- per assegnare una nuova aula, `insert` l'aula nella coda prioritaria.
>	- per programmare la lezione $j$ nell'aula $k$, `increase-key` dall'aula $k$ a $f_j$. 
>	- determinare se la lezione $j$ è compatibile con qualsiasi classe, confrontare $s_j$ con `Find-Min`
>- Il numero totale di operazioni in coda con priorità è $O(n)$; ciascuno richiede tempo $O(\log n)$.

>[!info]- Questa implementazione sceglie una classe $k$ la cui ora di fine dell'ultima lezione è la *prima*.

>[!important]- Def. La **profondità** di una serie di intervalli aperti è il numero massimo di intervalli che contengono un dato punto.

>*Oss. chiave*: Numero di classi necessarie $\ge$ profondità

![[Pasted image 20250305143416.png|center|500]]
#### Analisi dell'algoritmo
>*Oss*. L'algoritmo earliest-start-time non schedula mai due lezioni incompatibili nella stessa classe.

>[!important] Th. L'algoritmo Earliest-start-time-first è ottimale
>- Sia $d$ = numero di aule assegnate dall'algoritmo. 
>- L'aula $d$ è aperta perché dovevamo programmare una lezione, diciamo $j$, che è incompatibile con una lezione in ciascuna delle altre aule $d – 1$. 
>- Pertanto, queste lezioni terminano ciascuna dopo $s_j$. 
>- Poiché abbiamo ordinato in base all'orario di inizio, ciascuna di queste lezioni incompatibili inizia non più tardi di $s_j$. 
>- Quindi, abbiamo d lezioni che si sovrappongono al tempo $s_j + \varepsilon$.
>- Osservazione chiave $\implies$ tutti gli orari utilizzano $\ge d$ aule.



