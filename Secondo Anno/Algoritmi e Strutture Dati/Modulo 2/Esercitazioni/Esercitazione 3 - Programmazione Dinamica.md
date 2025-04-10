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
