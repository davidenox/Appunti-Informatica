Nasce la necessità di trattare algoritmi che operano in *ambienti non deterministici con osservabilità parziale*.

# Algoritmi di ricerca locale

Partendo dallo stato $s$, si esplorano gli stati adiacenti senza tenere traccia né del cammino seguito né degli stati già visitati, concentrandosi esclusivamente sul raggiungimento dello stato obiettivo. Si tratta di algoritmi non sistematici, che richiedono poca memoria e sono in grado di trovare soluzioni anche in spazi di ricerca ampi e complessi. 
È possibile considerare gli stati disposti in un **panorama dello spazio degli stati**:
![[Pasted image 20251217152322.png|center|500]]

## Algoritmo Hill Climbing

Dato uno stato attuale $s$, la funzione obiettivo $f$ e l'insieme degli stati vicini ad $s$, denotato come $N(s)$, lo stato successivo viene scelto:

1. Se migliora $f$ (**a scelta rapida**);
2. Randomicamente (**stocastico**);
3. Il primo (**prima scelta**).

Nel caso in cui l'algoritmo si trova in un punto di **massimo locale** qualsiasi scelta effettuata comporterebbe un peggioramento. Altre difficoltà emergono in caso di **creste** (serie di massimi locali difficili da esplorare) o **plateaux** (aree piatte della funzione). 
Nell'ultimo caso, è possibile risolvere il problema eseguendo una serie di "mosse laterali", ottenendo un aumento della risoluzione delle istanze del 94%.

Una variante per risolvere il problema dei massimi locali consiste nell'utilizzare il *riavvio casuale*, ossia una ripartenza da stati generati casualmente. Indicando con $p$ la probabilità di successo, il numero medio di ripartenze necessarie è $\frac{1}{p}$.

![[Pasted image 20251217153051.png|center|500]]

## Simulated annealing

Seleziona passo per passo un successore randomicamente:

- Se il nuovo stato migliora la situazione, viene accettato ed espanso.
- Altrimenti, può essere scelto con una probabilità definita come $\mathcal p=e^{\frac{\Delta E}{T}}$, in cui $\Delta E$ è la differenza tra il valore del nodo successivo e quello corrente. Maggiore è questa differenza, minore sarà la probabilità che lo stato venga scelto. $T$, chiamato **tempo di elaborazione**, è un parametro che diminuisce progressivamente nel tempo. Maggiore è il valore di $T$ è più aumenta la probabilità di scegliere uno stato peggiore.

Con il passare del tempo la probabilità di fare scelte peggiorative diminuisce, e l'algoritmo tetnte a comportarsi sempre di più come un algoritmo **hill climbing**.

## Local Beam

Tiene traccia di $k$ stati, inizialmente scelti randomicamente. Durante l'esecuzione vengono generati i successori di quegli stati, e se uno di essi corrisponde alla soluzione, l'algoritmo termina. In caso contrario, vengono selezionati i $k$ migliori successori ed il processo continua.

# Ricerca con azioni non deterministiche
p14