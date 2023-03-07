# Complessità computazionale e notazioni asintotiche

## Un modello di calcolo storico: la macchina di Turing

![[Pasted image 20221014151459.png]]

- Troppo di basso livello: somiglia troppo poco ai calcolatori reali su cui girano i programmi
- Utile per parlare di calcolabilità ma meno utile per parlare di efficenza

Un modello più realistico...
- Macchina a registri (**RAM**: random access machine)
	- un programma finito
	- un nastro in ingresso e uno di uscita
	- una memoria strutturata come un array
		- ogni cella può contenere un qualunque valore reale/intero
	- due registri speciali: PC e ACC
- la RAM è unìastrazione dell'architettura di von Neumann

![[Pasted image 20221014152028.png]]

## Modello di calcolo: cosa posso fare
- L'analisi della complessità di un algoritmo è basata sul concetto di **passo elementare**
- passi elementari su una RAM:
	- istruzioni ingresso/uscita
	- operazione aritmetico/logica
	- accesso/modifica del contenuto della memoria
## Criterio di costo: quanto mi costa
### Criterio di costo uniforme:
- tutte le operazioni hanno lo stesso costo 
- complessità temporale misurata come **numero di passi elementari eseguiti**
### Criterio di costo logaritmico
- Il costo di una operazione dipende dalla dimensione degli operandi dell'istruzione
- Un'operazione su un operando di valore x ha costo log(x)
- è un criterio di costo che modella meglio la complessità di **algoritmi "numerici"**

**Oss** il criterio di costo generalmente usato è quello UNIFORME

## Caso peggiore e caso medio

Misureremo il tempo di esecuzione di un algoritmo in funzione della dimensione n delle istanze
Istanze diverse, a **parità di dimensione**, potrebbero però richiedere **tempo diverso**
Distinguiamo quindi ulteriormente tra analisi nel caso **peggiore** e **medio**

### Caso peggiore
Sia **tempo(I)** il tempo di esecuzione di un algoritmo sull'istanza I
$$T_{worst}(n)=max_{\text{istanze I di dimensione n}}(tempo(I))$$
Intuitivamente, $T_{worst}(n)$ è il tempo di esecuzione sulle istanze di ingresso che comportano più lavoro sull'algoritmo
Rappresenta una garanzia sul tempo di esecuzione di ogni istanza
### Caso medio
Sia P(I) la probabilità di occorrenza dell'istanza I
$$T_{avg}(n)=\sum_{\text{istanze I di dimensione n}}(P(I)\cdot tempo(I))$$
Intuitivamente, $T_{avg}(n)$ è il tempo di esecuzione nel caso medio, ovvero sulle istanze di ingresso "tipiche" per il problema
Come faccio a conoscere la distribuizione di probabilità sulle istanze?
- Semplice:(di solito) non posso conoscerla
	- faccio un'assunzione
	- spesso è difficile fare assunzioni realistiche

## Notazione asintotica: intuizioni

La complessità computazionale di un algoritmo viene espressa con una funzione T(n)

_Def_
T(n):# passi elementari eseguiti su una RAM nel caso peggiore di un'istanza di dimensione n

**Idea**: descrivere T(n) in modo **qualitativo**. Ovvero: perdere un pò in **precisione** (senza perdere l'essenziale) e guadagnare in **semplicità**

**Esempio**
$$T(n)=\begin{cases}71n^2+100(n/4)+7 & n\:è\:pari\\
70n^2+150(n+1)/4+5 & n\:è\:dispari\end{cases}$$
Scriveremo $T(n)=\Theta(n^2)$
intuitivamente vuol dire: T(n) è proporzionale a $n^2$
cioè ignoro:
- costanti moltiplicative
- termini di ordine inferiore

### Notazione asintotica O
$f(n)=\mathcal{O}g(n)$se$\exists$ c>0, $n_0\geq0$ tali che $0\leq f(n)\leq c\cdot g(n)\:\:\forall\: n\geq n_0$    

![[Pasted image 20221014155959.png|center]]
**Esempi**

Sia $f(n)=2n^2+3n$, allora:
- $f(n)=O(n^3)$
- $f(n)=O(n^2)$
- $f(n)\neq O(n)$

In generale
$$f(n)=O(g(n))\implies lim_{n\to\infty}{\frac{f(n)}{g(n)}}\lt\infty$$
### Notazione asintotica $\Omega$

$f(n)=\Omega(g(n))$ se $\exists\:c\gt0, n_0\geq0|f(n)\geq c\cdot g(n)\geq0$ 

![[Pasted image 20221014160550.png]]

**Esempi**

Sia $f(n)=2n^2-3n$ allora:
- $f(n)=\Omega(n)$
- $f(n)=\Omega(n^2)$
- $f(n)\neq\Omega(n^3)$

In generale
$$f(n)=\Omega(g(n))\implies lim_{n\to\infty}\frac{f(n)}{g(n)}\gt0$$

### Notazione asintotica $\Theta$

$f(n)=\Theta(g(n))$ se $\exists c_1,c_2\gt0,n_0\geq0|c_1\cdot g(n)\leq f(n)\leq c_2\cdot g(n)$

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

simile a O(g(n)) ma con $f(n)\lt c\cdot g(n)$
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

- **misura indipendente** dall'implementazione dell'algoritmo e dalla macchina reale su cui è eseguito
- i "dettagli" nascosti sono **poco rilevanti** quando n è grande per funzioni asintoticamente diverse
- **analisi dettagliata** del numero di passi realmente eseguiti sarebbe difficile, noiosa e **non direbbe molto di più**
- si è visto come descrive bene **in pratica** la velocità degli algoritmi

