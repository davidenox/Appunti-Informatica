# Relazioni tra flussi e tagli

>[!definition] Lemma Valore del Flusso
>Sia $f$ un qualunque flusso e sia $(A,B)$ un qualunque taglio.
>Allora,  Il valore del flusso $f$ è uguale al flusso netto che attraversa il taglio $(A,B)$
>$$val(f)=\sum\limits_{\text{archi e uscenti da A}}f(e)-\sum\limits_{\text{archi e entranti in A}}f(e)$$

![[lemma1.gif|center|500]]

**Dimostrazione del lemma**

$$\begin{align}val(f)&=\sum\limits_{\text{archi e uscenti da s}}f(e)-\sum\limits_{\text{archi e entranti in s}}f(e)\\&=\underbrace{\sum\limits_{v\in A}(\sum\limits_{\text{archi e uscenti da v}}f(e)-\sum\limits_{\text{archi e entranti in v}}f(e))}_{\text{Per la conservazione del flusso, tutti i termini tranne v=s sono 0}}\\&=\sum\limits_{\text{archi e uscenti da A}}f(e)-\sum\limits_{\text{archi e entranti in A}}f(e)\end{align}$$

>[!definition] Dualità debole
>Sia $f$ un qualunque flusso e sia $(A,B)$ un qualunque taglio.
>Allora, $val(f)\leq cap(A,B)$

**Dimostrazione**

$$\begin{align}val(f)&=\underbrace{\sum\limits_{\text{archi e uscenti da A}}f(e)-\sum\limits_{\text{archi e entranti in A}}f(e)}_{\text{Per il lemma sul valore del flusso}}\\&\leq\sum\limits_{\text{archi e uscenti da A}}f(e)\\&\leq\sum\limits_{\text{archi e uscenti da A}}c(e)\\&=cap(A,B)\end{align}$$
![[Pasted image 20250424154220.png|center|500]]
### Certificato di Ottimalità

>[!warning] Corollario
>Sia $f$ un flusso e $(A,B)$ un taglio
>Se $val(f)=cap(A,B)$, allora $f$ è un flusso massimo e $(A,B)$ è un taglio minimo

**Dimostrazione**
- Per ogni flusso $f':val(f')\overbrace{\leq}^{\text{Dualità debole}} cap(A,B)=val(f)$
- Per ogni taglio $(A',B'):cap(A',B')\underbrace{\geq}_{\text{Dualità debole}} val(f)=cap(A,B)$

![[Pasted image 20250424154241.png|center|500]]

## Teorema Max-Flow Min-Cut

Diamo ora la definizione del teorema che lega il max flow al min cut, senza dimostrazione

>[!definition] Teorema Max-Flow Min-Cut
>Il valore del max-flow $\underbrace{=}_{\text{Dualità forte}}$ capacità del taglio minimo

Diamo la definizione di un'altro teorema

>[!definition] Teorema dei percorsi aumentanti
>Un flusso $f$ è un max-flow $\iff$ non ci sono percorsi aumentanti

**Dimostrazione**

Le seguenti 3 condizioni sono equivalenti per ogni flusso $f$:
1) Esiste un taglio $(A,B)$ tale che $cap(A,B)=val(f)$
2) $f$ è un max-flow
3) Non esiste un percorso aumentante rispetto a $\overbrace{f}^{\text{Se Ford-Fulkerson termina, allora f è un max-flow}}$

- $1\implies2$
	- Corollario di dualità debole

- $2\implies3$ (**Dimostriamo il contropositivo** $\lnot3\implies\lnot2$)
	- Supponiamo che esiste un percorso aumentante rispetto a $f$
	- Possiamo migliorare $f$ inviando il flusso lungo questo percorso
	- Quindi, $f$ non è un flusso massimo

- $1\implies3$
	- Sia $f$ un flusso senza percorsi aumentanti
	- Sia $A=$ insieme di nodi raggiungibili da $s$ nel residual network $G_f$
	- Per definizione di $A:s\in A$
	- Per definizione del flusso $f:t\not\in A$ ![[Pasted image 20250424154327.png|center|300]]


### Calcolare un taglio minimo partendo da un flusso massimo

>[!definition] Teorema
>Dato un qualunque flusso massimo $f$, possiamo calcolare il taglio minimo $(A,B)$ in tempo $O(m)$

**Dimostrazione**

Sia $A=$ insieme di nodi raggiungibili da $s$ nel residual network $G_f$ (?)
![[Pasted image 20250424154404.png|center|500]]
## Analisi dell'algoritmo di Ford-Fulkerson (per capacità intere)

**Assunzione** : Ogni capacità $c(e)$ è un intero compreso tra $1$ e $C$

**Invariante di integralità** :
Per tutta l'esecuzione di Ford-Fulkerson, i valori $f(e)(\text{valore del flusso dell'arco})$ e $c_f(e)(\text{capacità residua})$, sono interi

**Dimostrazione** :
- Per induzione sul numero di percorsi aumentanti

>[!definition] Teorema
>L'algoritmo di Ford-Fulkerson termina al più dopo $val(f^\star)\leq nC$ percorsi aumentanti, con $f^\star=$ flusso massimo

**Dimostrazione** : Ogni aumento incrementa il valore del flusso di almeno 1

>[!warning] Corollario
>Il tempo di esecuzione dell'algoritmo Ford-Fulkerson è $O(m*val(f^\star))=O(mnC)$

**Dimostrazione** : Possiamo usare la BFS o la DFS per trovare il percorso aumentante in tempo $O(m)$

>[!definition] Teorema di Intergralità
>Esiste un flusso massimo integrale $f^\star$
>$f(e)$ è un intero per ogni arco $e$

**Dimostrazione** :

Dato che Ford-Fulkerson termina, il teorema segue dall'invariante di integralità (e dal teorema sui percrosi aumentanti)

### Ford-Fulkerson : Esempio esponenziale

**D** : L'algoritmo di Ford-Fulkerson è polinomiale nella dimensione dell'input?

**R** :
- No, l'algoritmo è pseudo-polinomiale
- Se la capacità massima è $C$, l'algoritmo impiega $\geq C$ iterazioni

![[Pasted image 20250424154441.png|center|500]]


**Cattive notizie** : Il numero di percorsi aumentanti può essere esponenziale nella dimensione dell'input

Vedi esempio qui -> [Esempio](https://www.mat.uniroma2.it/~guala/07_Network_Flow_I_2023.pdf#page=45)

----

# Scegliere dei buoni percorsi aumentanti

**Prestare attenzione quando si scelgono i percorsi aumentanti**
- Alcune scelte portano ad algoritmi esponenziali
- Scelte intelligenti portano ad algoritmi polinomiali

**Patologia** : Quando le capacità degli archi sono irrazionali, non c'è alcuna garanzia che Ford-Fulkerson termini (o che converga al flusso massimo)

**Goal** : Scegliere i percorsi aumentanti in modo tale che
- Possiamo trovare i percorsi aumentanti in modo efficiente
- Ci sono poche iterazioni

**Scegliere i percorsi aumentanti con** :
- Capacità del bottleneck sufficientemente grande
- Pochi archi

## Algoritmo Capacity-scaling

**Overview** : Scegliere i percorsi aumentanti con capacità di bottleneck "grande" (non necessariamente la più grande)
- Mantenere un parametro di scalign $\Delta$
- Sia $G_f(\Delta)$ una parte del residual network che contiene solo gli archi con capacità $\geq\Delta$
- Ogni percorso aumentante in $G_f(\Delta)$ ha una capacità di bottleneck $\geq\Delta$

![[Pasted image 20240429120019.png|center|500]]

L'algoritmo è il seguente

![[Pasted image 20240429120044.png|center|500]]

### Analisi dell'algoritmo (sketch)

Si possono dimostrare le seguenti condizioni

**Lemma 1** : Ci sono $1+\lfloor\log_2C\rfloor$ fasi di scaling
**Lemma 2** : Ci sono $\leq2m$ aumenti per ogni fase di scaling

Quindi, il numero totale di aumenti è : $O(m\log C)$

>[!definition]- Teorema
>L'algoritmo capacity-scaling impiega tempo $O(m^2\log C)$


## Percorso aumentante più corto

**D** : Come si sceglie il prossimo percorso aumentante in Ford-Fulkerson?

**R** : Prendiamo quello che usa meno archi (si può trovare tramite la BFS)

L'algoritmo è il seguente :

![[Pasted image 20240429120449.png|center|500]]

### Analisi dell'algoritmo

Si può dimostrare la seguente condizione

**Lemma 1** : Il numero totale di aumenti è al più $mn$

>[!definition]- Teorema
>L'algoritmo per lo shortest-augmenting-path impiega tempo $O(m^2n)$