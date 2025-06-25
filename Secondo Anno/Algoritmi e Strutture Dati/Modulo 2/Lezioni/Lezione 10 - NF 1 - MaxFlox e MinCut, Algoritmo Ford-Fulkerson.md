# Rete di flusso
Una **rete di flusso** è un grafo orientato e pesato $G=(V,E,s,t,c)$, con:
- *Sorgente* $s\in V$ e *pozzo* $t\in V$;
- *Capacità* $c(e)\ge 0$ per ogni $e\in E$.
![[Pasted image 20250417120901.png|center|500]]
## Min Cut

>[!important] Un **st-Cut** (*Taglio*) è una partizione $(A,B)$ dei nodi con $s\in A$ e $t\in B$.

>[!important] La sua **Capacità** è la somma delle capacità degli archi da $A$ a $B$.$$cap(A,B)=\sum_{e\text{ fuori da A}} c(e).$$

![[Pasted image 20250417121555.png|center|500]]
![[Pasted image 20250417121655.png|center|500]]
*Esempio*:
![[Pasted image 20250417121754.png|center|500]]
Capacità del taglio dato: $20+25=45$.

>[!important] Problema del MinCut
**Trovare un taglio con la capacità minima.**

## Max Flow

>[!important] Un **st-Flow** (*flusso*) $f$ è una funzione che:
>- Per ogni $e\in E: 0\le f(e)\le c(e)$`[Capacità]`
>- Per ogni $v\in V-\{s,t\}: \sum_{e\text{ dentro }v} f(e)=\sum_{e\text{ fuori }v}f(e)$`[Conservazione del flusso]`

![[Pasted image 20250417123531.png|center|500]]

> Il **valore** di un flusso $f$ è:$$val(f)=\sum_{e\text{ fuori }s}f(e) - \sum_{e\text{ dentro }s}f(e)$$

![[Pasted image 20250417123816.png|center|500]]

>[!important] Problema del MaxFlow
>**Trovare un flusso di valore massimo.**
 
# Algoritmo di Ford-Fulkerson
	 Algoritmo per risolvere il problema del Max Flow

**Algoritmo Greedy**:
- Inizia con $f(e)=0$ per ogni arco $e\in E$;
- Trova un percorso da $s$ a $t$ denominato $P$ dove ogni arco $e$ ha $f(e)\le c(e)$;
- Aumenta il flusso lungo il percorso $P$;
- Ripeti finché puoi.
## Demo

![[ford_fulkerson_prev.gif|center|500]]

>[!danger] Perché fallisce?


**D** : Perchè l'algoritmo greedy fallisce?
**R** : Una volta che il greedy incrementa il valore del flusso su un'arco, non lo decrementa mai

**Esempio** : Consideriamo il network flow $G$
- L'unico max flow $f^\star$ ha $f^\star(v,w)=0$
- L'algoritmo greedy sceglie il percorso $s\to v\to w\to t$ come primo percorso

![[Pasted image 20250417150500.png|center|300]]

**Linea di fondo** : Abbiamo bisogno di un meccanismo per "disfare" le decisioni sbagliate

### Residual network

**Arco originale** : $e=(u,v)\in E$

![[Pasted image 20250417150608.png|center|300]]


**Arco invertito** : $e^\text{reverse}=(v,u)$
- "Annullare" l'invio del flusso

**Capacità residua**
$$c_f(e)=\begin{cases}c(e)-f(e)&\iff e\in E\\f(e^\text{reverse})&\iff e^\text{reverse}\in E\end{cases}$$

![[Pasted image 20250417150626.png|center|500]]

**Residual Network** : $G_f=(V,E_f,s,t,c_f)$
- $E_f=\{e|f(e)\lt c(e)\}\cup\{e|f(e^\text{reverse})\gt0\}$ (archi con capacità residua positiva)
- Proprietà chiave : $f'$ è un flusso in $G_f\iff f+f'$ è un flusso in $G$ (dove il flusso su un arco inverso nega il flusso sul corrispondente arco anteriore)

**Esempio**

![[Pasted image 20250417150837.png|center|500]]

#### Percorso aumentante

>[!definition] Percorso aumentante
>Un **percorso aumentante** è un percorso semplice $s\to t$ nel residual network $G_f$

>[!definition] Bottleneck capacity
>La **bottleneck capacity** di un percorso aumentante $P$ è la capacità residua minima di ogni arco in $P$

**Proprietà chiave**
- Sia $f$ un flusso e sia $P$ un percorso aumentate in $G_f$
- Allora, dopo aver chiamato la funzione $f'\gets Augment(f,c,P)$, il risultato $f'$ sarà un flusso e $val(f')=val(f)+bottleneck(G_f,P)$

![[Pasted image 20250417151039.png|center|400]]


Ora, dopo tutte le definizioni di [Residual Network](#^89e245) e [Percorso Aumentate](#^ca9035), possiamo definire l'algoritmo di Ford-Fulkerson, per il calcolo del max-flow in un network $G$
### Algoritmo

**Algoritmo dei cammini aumentanti di Ford-Fulkerson** :
- Inizia con $f(e)=0,\forall e\in E$
- Trova un percorso $s\to t$, chiamato $P$, nel residual network $G_f$
- Aumenta il valore del flusso lungo il percorso $P$
- Continua finchè non ti blocchi

L'algoritmo è il seguente:
![[Pasted image 20250417151342.png|center|400]]

#### Demo

![[ford_fulkerson.gif|center|500]]
