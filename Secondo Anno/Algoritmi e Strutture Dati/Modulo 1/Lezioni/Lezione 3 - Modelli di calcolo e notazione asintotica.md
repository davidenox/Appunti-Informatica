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
$f(n)=\ohm(g(n))$ se $\exists$ due costanti $c\gt 0$ e $n_0\geq 0$ tali che $f(n)\geq c\cdot g(n)\geq 0$ per ogni $n\geq n_0$

![[Pasted image 20231010160742.png|center]]

>[!info]- Esempi
>$f(n)=\ohm(n)\space (c=1,n_0=2)$
>$f(n)=\ohm(n^2)\space (c=1,n_0=3$
>$f(n)\not=\ohm(n^3)$

>[!note]- Refreshing
>![[Pasted image 20231010161012.png|center]]

### Notazione asintotica $\Theta$

$f(n)=\Theta(g(n))$ se $\exists c_1,c_2\gt0,n_0\geq0$ tale che $c_1\cdot g(n)\leq f(n)\leq c_2\cdot g(n)$

![[Pasted image 20221014161512.png|center]]

**Esempi**

Sia $f(n)=2n^2-3n$ allora
- $f(n)=\Theta(n^2)$
- $f(n)\neq\Theta(n)$
- $f(n)\neq\Theta(n^3)$

In generale
$$\begin{cases}f(n)=\Theta(g(n))& \implies f(n)=O(g(n))\\
f(n)=O(g(n))& \centernot\implies f(n)=\Theta(g(n))\\
f(n)=\Theta(g(n))& \implies f(n)=\Omega(g(n))\\
f(n)=\Omega(g(n))& \centernot\implies f(n)=\Theta(g(n))\end{cases}$$

>$f(n)=\Theta(g(n))\iff f(n)=\Omega(g(n))\wedge f(n)=O(g(n))$

#### Notazione asintotica o

Simile a O(g(n)) ma con $f(n)\lt c\cdot g(n)$
defizione alternativa:
$$f(n)=o(g(n))\iff lim_{n\to\infty}\frac{f(n)}{g(n)}=0$$
#### Notazione asintotica $\omega$

Simile a $\Omega(g(n))$ ma con $f(n)\gt c\cdot g(n)$
definizione alternativa:
$$f(n)=\omega(g(n))\iff lim_{n\to\infty}\frac{f(n)}{g(n)}=\infty$$
### Analogie

$$\begin{cases}O & \leq\\
\Omega & \geq\\
\Theta & =\\
o & \lt\\
\omega & \gt\end{cases}$$

#### Graficamente

![[Pasted image 20231010162056.png|center]]

#### Proprietà deòòa notazione asintotica

![[Pasted image 20231010162142.png|center]]

****

## Usare la notazione asintotica nelle analisi
### Upped Bound
>algoritmo fibonacci3(intero n)$\rightarrow$ intero
>1. sia Fib un array di n interi
>2. $Fib[1]=Fib[2]=1$
>3. for i = 3 to n do
>	4. $Fib[i]=Fib[i-1]+Fib[i-2]$
>5. return $Fib[n]$

T(n): complessità computazionale nel caso peggiore con input n
$c_j$:#passi elementari eseguiti su una RAM quando è eseguita la linea di codice j
- linea 1,2,5 eseguite una volta
- linee 3 e 4 eseguite aò più n volte
$T(n)\leq c_1+c_2+c_5+(c_3+c_4)n=\Theta(n)\implies T(n)=O(n)$

### Lower Bound

>algoritmo fibonacci3(intero n)$\rightarrow$ intero
>1. sia Fib un array di n interi
>2. $Fib[1]=Fib[2]=1$
>3. for i = 3 to n do
>	4. $Fib[i]=Fib[i-1]+Fib[i-2]$
>5. return $Fib[n]$

T(n): complessità computazionale nel caso peggiore con input n
$c_j$:#passi elementari eseguiti su una RAM quando è eseguita la linea di codice j
- linea 4 eseguita almeno n-3 volte
$T(n)\geq c_4(n-3)=c_4n-3c_4=\Theta(n)\implies T(n)=\Omega(n)$

Quindi tra upper bound e lower bound possimao dedurre che $$T(n)=\Theta(n)$$
## Notazione asintotica: perchè è una grande idea
**Misura indipendente** dall'implementazione dell'algoritmo e dalla macchina reale su cui è eseguito.
I "dettagli" nascosti sono **poco rilevanti** quando n è grande per funzioni asintoticamente diverse.
**Analisi dettagliata** del numero di passi realmente eseguiti sarebbe difficile, noiosa e **non direbbe molto di più**.
Si è visto come descrive bene **in pratica** la velocità degli algoritmi.