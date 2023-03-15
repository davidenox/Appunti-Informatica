# Dimostrazione per induzione

> $n^2+3n+5$ è dispari $\forall n\geq 0$

Si tratta in realtà di un'infinità di affermazioni, una per ogni valore di n Si può verificare a mano che, per esempio, per n = 0,1,2,3 il valore della formula è rispettivamente 5, 9, 15, 23 Ma se si volesse dimostrare che il valore della formula è sempre un numero dispari? Ovviamente non si possono fare infinite verifiche →

## Dimostrazione per induzione (V.1)
> -   Sia b un numero intero
> -   Sia P(n) un enunciato definito $\forall n \geq b$ Per dimostrare "per induzione" che P(n) è vero $\forall n \geq b$ si procede in due passi:
> 1.  Si verifica che P(b) è vero;
> 2.  Si dimostra che, dato un qualunque $k\geq b$, se P(k) è vero $\Rightarrow$ P(k+1) è vero. Il punto 1 è definito come base dell'induzione, Il punto 2 è definito come passo induttivo. All'interno del punto 2, l'ipotesi che P(k) sia vero si chiama ipotesi induttiva, P(k+1) è la tesi induttiva.

## Ex Dimostrativo

Sia $\alpha\in\mathbb{R}$ un qualunque numero reale. Dimostriamo per induzione che $\forall n\geq 0$ $$(1-\alpha) \sum\limits_{i=0 }^{n} \alpha^{i}= 1-\alpha^{n+1}$$ Questo enunciato è definito $\forall n\geq 0$

### Base dell'induzione

Verifichiamo P(0) : $$ (1-\alpha) \sum\limits_{i=0 }^{0} \alpha^{i}= 1-\alpha^{0+1} $$ Questo è vero perchè l'espressione a sinistra dell'uguale e a destra valgono $1-\alpha$.

### Passo induttivo

Dato un qualunque $k\geq 0$ dimostriamo che se P(k) è vero $\Rightarrow$P(k+1) è vero: $$P(k): \ (1-\alpha) \sum\limits_{i=0 }^{k} \alpha^{i}= 1-\alpha^{k+1}$$ $$P(k+1): \ (1-\alpha) \sum\limits_{i=0 }^{k+1} \alpha^{i}= 1-\alpha^{k+2}$$ Quindi si deve dimostrare che, dato un qualunque $k\geq 0$ , se è vera la nostra ipotesi induttiva allora è vera anche la nostra tesi induttiva. Ovviamente ci sono diversi modi per procedere. Un modo è il seguente: 
Nella nostra tesi induttiva scriviamo l'espressione a sinistra dell'uguale: $$ (1-\alpha) \sum\limits_{i=0 }^{0} \alpha^{i} $$ Si osservi che la sommatoria si può spezzare a metà nei primi k termini + l'ultimo $$ (1-\alpha) \sum\limits_{i=0 }^{0} \alpha^{i}= \ (1-\alpha) \left[ \left(\sum\limits_{i=0 }^{k} \alpha^{i}\right)+\alpha^{k+1}\right]$$ $$ (1-\alpha) \sum\limits_{i=0 }^{0} \alpha^{i}= \ (1-\alpha) \left(\sum\limits_{i=0 }^{k} \alpha^{i}\right)+(1-\alpha)\alpha^{k+1}$$ Per l'ipotesi induttiva: $$\ (1-\alpha) \sum\limits_{i=0 }^{k} \alpha^{i}= 1-\alpha^{k+1}$$ Possiamo riscrivere l'ultimo termine in questo modo: $$ \ (1-\alpha) \left(\sum\limits_{i=0 }^{k} \alpha^{i}\right)+(1-\alpha)\alpha^{k+1}= 1-\alpha^{k+1} + (1-\alpha)\alpha^{k+1}=1-\alpha^{k+1} + \alpha^{k+1}-\alpha^{k+2}= 1-\alpha^{k+2}$$ Unendole abbiamo che: $$ (1-\alpha) \sum\limits_{i=0 }^{k+1} \alpha^{i}= 1-\alpha^{k+2}$$Quindi abbiamo dimostrato che se P(k) è vero allora anche P(k+1) deve essere vero.