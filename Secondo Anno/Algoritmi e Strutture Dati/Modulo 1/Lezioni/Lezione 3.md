# Modelli di calcolo e notazione asintotica
È sensato misurare la complessità di un algoritmo contando il numero di linee di codice eseguite?
## Modelli di calcolo
### Un modello storico, la macchina di Turing
![[Pasted image 20231010140309.png|center]]

Troppo di *basso livello*: somiglia troppo poco ai calcolatori reali su cui girano i programmi.
Utile per parlare di *calcolabilità* ma meno utile per parlare di *efficienza*.
### Un modello più realistico
Macchina a registri (*RAM*: random access machine)
- Un programma finito;
- Un nastro di ingresso e uno di uscita;
- Una memoria strutturata come un array.
Ogni cella può contenere un qualunque valore intero/reale;
- Due registri speciali: PC e ACC;
La *RAM* è un’astrazione dell’architettura di von Neumann.
![[Pasted image 20231010140644.png|center]]
### Modello di calcolo : cosa posso fare?
L’analisi della complessità di un algoritmo è basata sul concetto di *passo elementare*.
*Passi elementari* su una **RAM**:
- Istruzione ingresso/uscita (accesso nastri I/O);
- Operazione aritmetico/logica;
- Accesso/modifica del contenuto della memoria;
### Criterio di costo 
**Criterio di costo uniforme**:
- Tutte le operazioni hanno lo stesso costo;
- Complessità temporale misurata come *numero di passi elementari eseguiti*;
**Criterio di costo logaritmico**:
- Il costo di una operazione dipende dalla dimensione degli operandi dell’istruzione;
- Un’operazione su un operando di valore *x* ha costo *log x*;
- È un criterio di costo che modella meglio la complessità di *algoritmi “numerici”*;
Il criterio di costo generalmente usato è quello **uniforme**.
#### Caso peggiore e caso medio
Misureremo il tempo di esecuzione di un algoritmo in funzione della dimensione *n* delle
istanze. Istanze *diverse*, a *parità di dimensione*, potrebbero però richiedere *tempo diverso*. Distinguiamo quindi ulteriormente tra analisi nel caso *peggiore* e *medio*.
##### Caso peggiore
Sia *tempo(I)* il tempo di esecuzione di un algoritmo sull’istanza *I*.
$T_{worst}(n) = max_{istanze\space I\space di\space dimensione\space n} \{tempo(I)\}$
Intuitivamente, $T_{worst}(n)$ è il tempo di esecuzione sulle istanze di ingresso che comportano più lavoro per l’algoritmo.
Rappresenta una *garanzia* sul tempo di esecuzione di ogni istanza. 
##### Caso medio
Sia *P(I)* la probabilità di occorrenza dell’istanza *I*.
$T_{avg}(n) =\sum_{istanze\space I\space di\space dimensione\space n} \{P(I) tempo(I) \}$
Intuitivamente, $T_{avg}(n)$ è il tempo di esecuzione nel caso medio, ovvero sulle istanze di ingresso “tipiche” per il problema. Come faccio a conoscere la distribuzione di probabilità sulle istanze?
*Semplice*: (di solito) non posso conoscerla. -> faccio un’assunzione.
Spesso è difficile fare assunzioni realistiche.

>[!danger]- Esercizio
>Analizzare la complessità nel caso medio del primo algoritmo di pesatura (*Alg1*) presentato nella prima lezione. Rispetto alla distribuzione di probabilità sulle istanze, si assuma che la moneta falsa possa trovarsi in modo equiprobabile in una qualsiasi delle n posizioni.

## Notazione asintotica
Complessità computazionale di un algoritmo espressa con una funzione $T(n)$.
$T(n)$: # passi elementari eseguiti su una *RAM* nel caso peggiore su un’istanza di dimensione *n*.
**Idea**: descrivere $T(n)$ in modo *qualitativo*. Ovvero: perdere un po’ in *precisione* (senza perdere l’essenziale) e guadagnare in *semplicità*.

>[!info]- Esempio

$$T(n)=\begin{cases} 71n^2 + 100\lfloor n / 4\rfloor+7 se\space n\space è\space pari \\ 70n^2 + 150\lfloor (n+1) / 4\rfloor+5 se\space n\space è\space dispari \end{cases} $$
Scriveremo $T(n)=\Theta(n^2)$.
Intuitivamente vuol dire che $T(n)$ è *proporzionale* a $n^2$.
Cioè ignoro:
- Costanti moltiplicative;
- Termini di ordine inferiore (che crescono più lentamente).
*Nota*: l’assunzione implicita è che guardo come si comporta l’algoritmo su *istanze grandi*.
![[Pasted image 20231010143935.png|center]]

### Un'altra tabella, dalla bilancia al computer
Tempi di esecuzione di differenti algorimi per istanze di dimensione crescente su un processore che sa eseguire *un milione di istruzioni* di alto livello al *secondo*. L’indicazione *very long* indica che il tempo di calcolo supera $10^{25}$ anni.
![[Pasted image 20231010144122.png|center]]

### Notazione asintotica $O$
$f(n) = O(g(n))$ se $\exists$ due costanti $c>0$ e $n_0\geq 0$ tali che $0\leq f(n) \leq c\cdot g(n)$ per ogni $n\geq n_0$.

![[Pasted image 20231010144443.png|center]]

>[!info]- Esempi
>Sia $f(n)=2n^2+3n$
>$f(n) = O(n^3) (c = 1, n_0 = 3)$
>$f(n) = O(n^2) (c = 3, n_0 = 3)$
>$f(n)\not= O(n)$

>[!note]- Refreshing
>![[Pasted image 20231010145001.png|center]]

### Notazione asintotica $\ohm$ 
Vedere tutte le notazioni asintotiche


