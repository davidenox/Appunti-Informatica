
# Pumping Lemma

>[!important]- Teorema
>Sia $L\subseteq V_T^\star$ un linguaggio non contestuale. Esiste allora una costante n tale che se $z\in L$ e $|z|\geq n$ allora esistono 5 stringhe $u,v,w,x,y\in V_T^\star$ tali che $$\begin{align}i)&uvwxy=z\\ii)&|vx|\geq1\\iii)&|vwx|\leq n\\iv)&\forall i\geq0\:uv^iwx^iy\in L\end{align}$$

## Interpretazione come gioco a due

Se $L$ è contex free, Alice vince sempre questo gioco con Bob:
(Alice = $\exists$ e Bob = $\forall$)

1. Alice fissa un intero $n\gt0$ opportuno
2. Bob sceglie una stringa $z\in L$ con $|z|\gt n$
3. Alice divide z in cinque parti uvwxy con $|vwx|\leq n$ e $|vx|\geq1$
4. Bob sceglie un intero $i\geq0$
5. Alice mostra a Bob che $uv^iwx^iy\in L$

**Dimostrazione**

Grammatica $\mathcal G=\langle V_T,V_N,P,S\rangle$ in CNF che genera $L=L(\mathcal G)$ e sia $k=|V_N|$ il numero di simboli non terminali in $\mathcal G$ 

Qualunque albero sintattico $A(\sigma)$ relativo ad una stringa $\sigma\in V_T^\star$ derivata in $\mathcal G$ sarà tale da avere tutti i nodi interni (corrispondenti ai simboli non terminali) di grado 2,eccetto quelli aventi foglie dell'albero come figli, che hanno grado 1

- Se h è l'altezza di $A$ (numero massimo di archi, e anche numero massimo di nodi interni, in un cammino dalla radice ad una foglia), il massimo numero di foglie $l(h)$ è dato dal caso in cui l'albero è completo (i nodi interni hanno due figli, eccetto i padri di foglie, che ne hanno uno). SI può facilmente verificare che in tal caso abbiamo $l(h)=2^{h-1}$, in quanto $l(1)=1=2^0$ e $l(h+1)=2\cdot l(h)=2\cdot 2^{h-1}=2^h$ 
- Se l'albero sintattico $A(\sigma)$ relativo alla stringa $\sigma\in L$ ha altezza $h(\sigma)$, la lunghezza di $\sigma$ è allora $|\sigma|\leq 2^{h(\sigma)-1}$, e quindi $h(\sigma)\geq 1+log_2|\sigma|$
- Se $\sigma$ è una stringa sufficientemente lunga (in questo caso,$|\sigma|\gt 2^{|V_N|-1}$), ne risulta che $h(\sigma)\geq 1+log_2|\sigma|\gt|V_N|$
- Quindi, se $|\sigma|\gt 2^{|V_N|-1}$ esiste almeno un cammino c dalla radice ad una foglia di $A(\sigma)$ che attraversa almeno $|V_N|+1$ nodi interni

- I nodi interni di $A(\sigma)$ sono etichettati da simboli non terminali (le aprti sinistre delle produzioni nella derivazione di $\sigma$)
- Dato che i simboli non temrinli sono $|V_N|$ mentre i nodi interni in c sono più di $|V_N|$, deve esistere (per il pigeonhole principle) un simbolo non terminale A che compare in due diversi nodi di c
- Di questi due nodi, indichiamo con _r_ il nodo più vicino alla radice e _s_ il nodo associato ad A più vicino alla foglia
- Indichiamo con $r(\sigma),s(\sigma)$ le sottostringhe di $\sigma$ corrispondenti alle foglie dei due sottoalberi $R(\sigma),S(\sigma)$ di $A(\sigma)$ aventi radice _r_ e _s_
- Dato che _s_ è un discendente di _r_, necessariamente $s(\sigma)$ è una sottostringa di $r(\sigma)$, per cui esistono due sottostringhe di v,x di $\sigma$ tali che $r(\sigma)=v\cdot s(\sigma)\cdot x$

- La grammatica considerata è in CNF, per cui non sono presenti produzioni unitarie (a parte quelle relatice alle foglie): di conseguenza, non può essere $s(\sigma)=r(\sigma)$, e quindi $|vx|\gt1$
- Senza perdere generalità, possiamo assumere che $r(\sigma)$ sia il nodo in c più vicino alle foglie per il quale c'è un nodo sottostante $s(\sigma)$ associato allo stesso non terminale: quindi, il cammino più lungo da $r(\sigma)$ ad una foglia attraversa al più $|V_N|+1$ nodi interni (esso stesso incluso)
- Dalle osservazioni precedenti, ne deriva che $r(\sigma)$ ha lunghezza al più $2^{|V_N|+1-1}=2^{|V_N|}$

Poniamo $s(\sigma)=w$ e $r(\sigma)=vwx$

![[appunti fi/mod i/immagini/Pasted image 20221206094941.png|center|400]]

![[appunti fi/mod i/immagini/Pasted image 20221206095016.png|center|400]]

- Gli alberi $R(\sigma),S(\sigma)$ possono essere sostituiti (avendo radice corrispondente allo stesso non terminale) l'uno all'altro all'interno di qualunque albero sintattico
- Quindi, anche la stringa $uvy$ è generata dalla grammatica (sostituendo in $A(\sigma),R(\sigma)\:e\:S(\sigma)$)
- Mediante la sostituzione opposta, anche la stringa $uvwxy$ risulta generabile

$\square$

## Interpretazione come gioco a due

La proprietà mostrata fornisce soltanto una condizione necessaria perchè un linguaggio sia context free: non può essere utilizzata per mostrare la non contestualità di un linguaggio, ma solo per dimostrarne la contestualità

$$\begin{align}&\text{L contestuale}\implies\text{pumping lemma verificato}\\&\text{pumping lemma non verificato}\implies\text{L non contestuale}\end{align}$$

Se Alice vince sempre questo gioco con Bob, allora $L$ non è CF
(Alice = $\exists$ e Bob = $\forall$)

1. Bob sceglie un interno $n\gt0$
2. Alice sceglie una stringa $z\in L$ con $|z|\gt n$
3. Bob divide $z$ in cinque parti $uvwxy$ con $|vwx|\leq n$ e $|vx|\geq1$
4. Alice sceglie un intero $i\geq0$
5. Alice mostra a Bob che $uv^iwx^iy\not\in L$

**Esempio**

$L=\{a^kb^kc^k|k\gt0\}$ non è CF

Infatti:
1. Bob sceglie un intero $n\gt0$
2. Alice prende la stringa $a^nb^nc^n\in L$
3. Bob divide $z$ in cinque parti $uvwxy$ con $|vwx|\leq n$ e $|vx|\geq1$. $vwx$ o è una sequenza di occorrenze dello stesso simbolo (ad esempio $a^h,h\gt0$) o è composta di due sottosequenze di stessi simboli (ad esempio $a^rb^s,r,s\gt0$). Quindi, almeno uno dei simboli a,b,c non compare in vwx e quindi né in v né in x
4. Alice sceglie i=2
5. Alice mostra a Bob che $uv^2wx^2y\not\in L$ in quanto almeno un simbolo ha aumentato il numero di occorrenze ed almeno un altro simbolo ha un numoer di occorrenze invariato

# Proprietà dei linguaggi CF

## Chiusura dei linguaggi CF: intersezione

Il linguaggio $L=\{a^nb^nc^n|n\geq1\}$ non è context free

Del resto, $L_1=\{a^nb^nc^m|n,m\geq1\}$ e $L_2=\{a^mb^nc^n|n,m\geq1\}$ sono non contestuali

Ma $L=L_1\cap L_2$ ,da cui deriva che la classe dei linguaggi CF non è chiusa rispetto all'intersezione

## Chiusura dei linguaggi CF: unione

Dati due linguaggi CF $L_1\subseteq\Sigma_1^\star$ e $L_2\subseteq\Sigma_2^\star$, siano $\mathcal G_1=\langle\Sigma_1,V_{N_1},P_1,S_1\rangle$ e $\mathcal G_2=\langle\Sigma_2^\star,V_{N_2},P_2,S_2\rangle$ due grammatiche di tipo 2 tali che $L_1=L(\mathcal G_1),L_2=L(\mathcal G_2)$

Il linguaggio $L=L_1\cup L_2$ potrà allora essere generato dalla grammatica di tipo 2 $\mathcal G=\langle\Sigma_1\cup\Sigma_2,V_{N_1}\cup V_{N_2}\cup\{S\},P,S\rangle$, dove $P=P_1\cup P_2\cup\{S\to S_1|S_2\}$

## Chiusura dei linguaggi CF: concatenazione

Dati due linguaggi CF $L_1\subseteq\Sigma_1^\star$ e $L_2\subseteq\Sigma_2^\star$, siano $\mathcal G_1=\langle\Sigma_1,V_{N_1},P_1,S_1\rangle$ e $\mathcal G_2=\langle\Sigma_2^\star,V_{N_2},P_2,S_2\rangle$ due grammatiche di tipo 2 tali che $L_1=L(\mathcal G_1),L_2=L(\mathcal G_2)$

Mostriamo che il linguaggio $L=L_1\circ L_2$ è generato dalla grammatica di tipo 2 definita come $\mathcal G=\langle\Sigma_1\cup\Sigma_2,V_{N_1}\cup V_{N_2}\cup\{S\},P,S\rangle$, dove $P=P_1\cup P_2\cup\{S\to S_1S_2\}$ 

## Chiusura dei linguaggi CF: iterazione

Dato un linguaggio CF $L\subseteq\Sigma^\star$,sia $\mathcal G=\langle\Sigma,V_{N},P,S\rangle$ e una grammatica di tipo 2 tale che $L=L(\mathcal G)$

Il linguaggio $L'=L^\star$ è allora generato dalla grammatica di tipo 2 $\mathcal G'=\langle\Sigma,V_N\cup\{S'\},P',S'\rangle$, dove $P'=P'\cup\{S'\to SS'|\varepsilon\}$ 

## Chiusura dei linguaggi CF: complemento

La classe dei linguaggi CF non è chiusa rispetto al complemento

Infatti, se così fosse, avremmo che dati due qualunque linguaggi CF $L_1,L_2$, il linguaggio $L=\overline{\overline{L_1}\cup\overline{L_2}}$ sarebbe CF anch'esso. Ma $L=L_1\cap L_2$ e quindi ne risulterebbe la chiusura rispetto all'intersezione, che non sussiste 

>[!info]- Osservazione
>Ricorda, vale che:
$$L_1\cap L_2=\overline{\overline{L_1}\cup\overline{L_2}}$$
Quindi se non è chiuso rispetto all'intersezione, allora non è chiuso rispetto al complemento, e viceversa

# Decidibilità di predicati su linguaggi CF

>[!info]- Ricorda
>Qualunque linguaggio CF ha una grammatica in CNF che lo genera

## Predicato $L(\mathcal G)=\emptyset$

Data una grammatica $\mathcal G$ di tipo 2 è decidibile stabilire se $L(\mathcal G)=\emptyset$

Assumiamo che $\mathcal G=\langle V_T,V_{N},P,S\rangle$ sia in CNF

Per il pumping lemma, se esiste una stringa $z=uvwxy\in L(\mathcal G)$ con $|z|\geq2^{|V_N|}$, allora esiste una stringa $z'=uwy\in L(\mathcal G)$ con $|z'|\lt2^{|V_N|}$.
Quindi, se il linguaggio non è vuoto, esiste una stringa in esso di lunghezza minore di $2^{|V_N|}$

In una grammatica in CNF, ogni applicazione di una produzione o incrementa di uno la lunghezza della forma di frase (se la produzione è del tipo $A\to BC$) o sostituisce un terminale a un non temrinale (se è del tipo $A\to a$). Quindi, una stringa di lunghezza $2^k$ è generata da una derivazione di lunghezza $2^{k+1}-1$

Per verificare se esiste una stringa di lunghezza minore di $2^{|V_N|}$ generabile, è sufficiente considerare tutte le derivazioni di lunghezza minore di $2^{|V_N|+1}-1$ che sono, al più:
$$\sum_{k=1}^{2^{|V_N|+1}-2}|P|^k=\frac{|P|^{2^{|V_N|+1}-1}-1}{|P|-1}=O(2^{2^{|V_N|+1}})$$
Un metodo più efficiente consiste nel portare la grammatica in forma ridotta, verificando se esistono simboli fecondi. Condizione necessaria e sufficiente affinchè il linguaggio sia vuoto è che la grammatica non abbia simboli fecondi

## Predicato $L(\mathcal G)$ infinito

Data una grammatica $\mathcal G$ di tipo 2 è decidibile stabilire se $L(\mathcal G)$ è infinito

Assumiamo che $\mathcal G=\langle V_T,V_{N},P,S\rangle$ sia in CNF

Per il pumping lemma, se esiste una stringa $z=uvwxy\in L(\mathcal G)$ con $|z|\geq2^{|V_N|}$, allora esistono infinite stringhe $z_i=uv^iwx^iy\in L(\mathcal G)$, con $i\geq0$, e almeno una di queste ha lunghezza $|z'|\lt2^{|V_N|+1}$

Quindi, se il linguaggio è infinito, esiste una stringa in esso di lunghezza $z\in[2^{|V_N|},2^{|V_N|+1}-1]$, che sarà derivata (in una grammatica in CNF) da una derivazione di lunghezza compresa tra $2^{|V_N|+1}-1$ e $2^{|V_N|+2}-3$

è possibile allora considerare tutte le derivazioni di lunghezza compresa tra $2^{|V_N|+1}-1$ e $2^{|V_N|+2}-3$ che sono al più:
$$\sum_{k=2^{|V_N|+1}-1}^{2^{|V_N|+2}-3}|P|^k=\frac{|P|^{2^{|V_N|+2}-2}-|P|^{2^{|V_N|+1}-1}}{|P|-1}=O(2^{2^{2^{|V_N|+2}}})$$
e verifica re se qualcuna di esse da origine ad una stringa di terminali

Metodo più efficiente: verificare la ciclicità del grafo orientato $G=(N,A)$ derivato dalla grammatica in CNF che genera $L$, ponendo $N=V_N$ e introducendo, per ogni produzione $B\to CD$, gli archi $\langle B,C\rangle$ e $\langle B,D\rangle$


