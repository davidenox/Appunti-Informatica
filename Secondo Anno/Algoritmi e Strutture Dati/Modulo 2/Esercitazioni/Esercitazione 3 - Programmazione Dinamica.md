# Problema 1 - Massima sottostringa palindroma

**Input**: Una stringa $S$ di $n$ caratteri.
**Goal**: Eliminare da $S$ dei caratteri (anche nessuno) in modo tale che la sottostringa risultante $S^*$ sia *palindroma* e *di lunghezza massima*.

**OPT**: Massima lunghezza della sottostringa palindroma.
![[Pasted image 20250410121340.png|center|500]]

**Sottoproblema**: $$OPT[i,j]=\text{ massima lunghezza sottostringa palindroma di }S[i\dots j]$$
*Caso base*: $$\begin{align}\text{If }\space i>j\rightarrow OPT[i,j]=0\\OPT[i,i]=1\end{align}$$
**Soluzione**: $OPT[1,n]$.
**Formula ricorsiva**:$$OPT[i,j]=\begin{cases}
2+OPT[i+1,j-1]&\text{se }S[i]=S[j]\\
\max\{OPT[i+1,j],OPT[i,j-1]\}&\text{altrimenti}
\end{cases}$$
- Nel primo caso aggiungo $S[i]$ e $S[j]$ ad $S^*$ e ricorsivamente osservo $S[i+1...j-1]$
- Nel secondo caso, rimuovo $S[i]$ o $S[j]$ a seconda del caso.
## Demo
![[max_sott_pall.gif|center|500]]
## Implementazione bottom-up
![[Pasted image 20250410122731.png|center|500]]

**Ottimizzazione**: Non c'è bisogno di riempire tutta la tabella, ma solo ciò che ci serve.
## Implementazione top-down
![[Pasted image 20250410122959.png|center|500]]
![[Pasted image 20250410123015.png|center|500]]
# Problema 2 - I due scaffali
**Input**: Una collezione di $n$ libri di spessore $t_1,...,t_n\in N$.
**Goal**: Vuoi comprare due scaffali $S_1$ ed $S_2$, *entrambi di lunghezza* $W\in N$, per disporre tutti i libri.

**OPT**: Lunghezza *minima* necessaria per gli scaffali $S_1$ ed $S_2$.
![[Pasted image 20250410140543.png|center|500]]

**Sottoproblema**: $OPT[i,w] =$ minimo spazio usato dallo scaffale $S_1$ se sullo scaffale $S_2$ ho a disposizione spazio $w$ e voglio piazzare $i$ libri di spessore $t_1,...,t_i$.
**Caso base**: $OPT[0,w]=0$.
**Soluzione**: $\min W$ tale che $OPT[n,W]\le W$. ($W\le T=\sum t_i$)

## Complessità

**Spazio**: $O(n\cdot T)$ dove $T=\sum t_i$
**Tempo**: $O(n\cdot T)$, ogni volta devo combinare un numero costante di sottoproblemi.
*Pseudo polinomiale*

**Formula ricorsiva**: $$OPT[i,w]=\begin{cases}
t_i+OPT[i-1,w]&\text{se }t_i>w\\
\min\{t_i+OPT[i-1,w],OPT[i-1,w-t_i]\}&\text{altrimenti}
\end{cases}$$
- Nel primo caso, $t_i$ non entra in $S_2$, quindi lo devo mettere per forza in $S_1$.
- Nel secondo caso, inserisco $t_i$ in $S_1$ o $S_2$.
# Esercizi
1. Implementare l'algoritmo con approccio bottom-up (tabulation) e top-down (memoization);
2. Adattare l'algoritmo nel caso in cui si hanno tre scaffali $S_1,S_2$ ed $S_3$.
