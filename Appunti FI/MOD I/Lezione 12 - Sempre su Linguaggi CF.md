Ritornando a [[Lezione 11 - Pumping Lemma per ling. reg.,Linguaggi CF#Forme ridotte e forme normali|Forme ridotte e forme normali]]

# Forme ridotte e normali 

Trasformazione di una grammatica $\mathcal G=\langle V_T,V_N,P,S\rangle$ di tipo 2 in una grammatica equivalente in forma ridotta mediante una sequenza di passi

1. A partire da $\mathcal G$, derivazione di $\mathcal G_1$ di tipo 2 senza $\varepsilon$-produzioni tale che $L(\mathcal G_1)=L(\mathcal G)-\lbrace\varepsilon\rbrace$
2. A partire da $\mathcal G_1$, derivazione di $\mathcal G_2$ di tipo 2 senza $\varepsilon$-produzioni e senza produzioni unitarie tale che $L(\mathcal G_2)=L(\mathcal G_1)$
3. A partire da $\mathcal G_2$, derivazione di $\mathcal G_3$ di tipo 2 senza $\varepsilon$-produzioni, senza produzioni unitarie e senza simboli inutili tale che $L(\mathcal G_3)=L(\mathcal G_2)$
4. La grammatica $\mathcal G_4$ di tipo 2, equivalente a $\mathcal G$ coincide con $\mathcal G_3$ se $\varepsilon\not\in L(\mathcal G)$; altrimenti, $\mathcal G_4$ è ottenuta da $\mathcal G_3$ introducendo un nuovo assioma ed un opportuno insieme di produzioni su tale simbolo


## Passo 1

>[!important]- Teorema
>Data una grammatica $\mathcal G=\langle V_T,V_N,P,S\rangle$ il cui insieme di produzioni P comprende soltanto produzioni di tipo non contestuale e produzioni vuote, esiste una grammatica non contestuale $\mathcal G'$ tale che $L(\mathcal G')=L(\mathcal G)-\lbrace\varepsilon\rbrace$

Determinazione dell'insieme $N\subseteq V_N$ dei simboli che si annullano, cioè i non terminali da cui è possibile derivare $\varepsilon$ in $\mathcal G$

Costruzione di una sequenza $N_0,N_1,...,N_k=N$ di sottoinsiemi di $V_N$, con $N_0=\lbrace A\in V_N|A\to\varepsilon\in P\rbrace$ e $N_{i+1}$ derivato da $N_i$ :$$N_{i+1}=N_i\cup\lbrace B\in V_N|(B\to\beta\in P)\land(\beta\in N_i^+)\rbrace$$
La costruzione termina quando $N_{k+1}=N_k, k\geq0$

$\varepsilon\in L(\mathcal G)\iff S\in N$

![[appunti fi/mod i/immagini/Pasted image 20221122112802.png|center|500]]

**Esempio**
Consideriamo la grammatica $\mathcal G=\langle\{a,b\},\{S,A,B\},P,S\rangle$, le cui produzioni sono:
$$\begin{align}S&\to A|SSa\\A&\to B|Ab|\varepsilon\\B&\to S|ab|aA\end{align}$$
Quindi:
$$\begin{align}N_0 &= \{A\}\\N_1 &= \{A,S\}\\N_2&=\{A,S,B\}\\N_3&=\{A,S,B\}=N_2=N\end{align}$$
Costruzione delle produzioni $P'$ di $\mathcal G'$:
- Si esamina ciascuna produzione $A\to\alpha$ di $P$, con l'esclusione delle $\varepsilon$-produzioni:
	- Se nessun simbolo di $\alpha$ è annullabile: $A\to\alpha$ è inserita in $P'$
	- Altrimenti $\alpha$ contiene $k\gt0$ simboli che si annullano: sono inserite in $P'$ tutte le possibili produzioni ottenute da $A\to\alpha$ eliminando da $\alpha$ uno dei sottoinsiemi di simboli che si annullano

Ritornando all'esempio:

Le produzioni $P'$ sono quindi:
$$\begin{align}S&\to A|SSa|Sa|a|\varepsilon\\A&\to B|Ab|b\\B&\to S|ab|aA|a\end{align}$$

## Passo 2

>[!important]- Teorema
>Per ogni grammatica $\mathcal G$ di tipo 2 senza $\varepsilon$-produzioni, esiste sempre una grammatica $\mathcal G'$ di tipo 2 senza $\varepsilon$-produzioni,priva di produzioni unitarie ed equivalente a $\mathcal G$

Sia, per ogni $A\in V_N,U(A)$ il sottoinsieme di $V_N-\lbrace A\rbrace$ comprendente tutti i non terminali derivabili da $A$ applicando una sequenza di produzioni unitarie:
$$U(A)=\lbrace B\in V_N-\lbrace A\rbrace|A\xRightarrow[]{\star}B\rbrace$$
Data la grammatica $\mathcal G=\langle V_T,V_N,P,S\rangle$, $P'$ è costruito:

- Inserendo dapprima in $P'$ tutte le produzioni non unitarie di $P$
- Inserendo in $P'$, per ogni non terminale $A$ e per ogni $B\in U(A)$, la produzione $A\to\beta$ se e solo se in $P$ esiste una produzione non unitaria $B\to\beta$

**Esercizio/Esempio**
Costruire un algoritmo che, data una grammatica $\mathcal G$ di tipo 2 senza $\varepsilon$-produzioni e dato un non terminale $A$ della grammatica, determini l’insieme $U(A)$

Soluzione:
- Passo iniziale: Inserisci in $U(A)$ tutti i simboli $B$ tali che $A\to B$
- Passo iterativo: per ogni simbolo $B\in U(A)$, inserisci in $U(A)$ tutti i simboli $C$ tali che $B\to C$; termina se nessun nuovo simbolo è stato inserito in $U(A)$


## Passo 3

>[!important]- Teorema
>Per ogni grammatica $\mathcal G=\langle V_T,V_N,P,S\rangle$ di tipo 2 senza ε-produzioni e priva di produzioni unitarie, esiste sempre una grammatica $\mathcal G'$ senza ε-produzioni,priva di produzioni unitarie e senza simboli inutili equivalente a $\mathcal G$

Affinchè un simbolo $A\in V_N$ non sia inutile, è necessario che nella grammatica $\mathcal G$ si abbia che:

- A sia un simbolo **fecondo**, vale a dire che da esso siano generabili stringhe di terminali, cioè $\exists w\in V_T^+:A\xRightarrow[]{\star}w$
- A sia generabile dall'assioma in produzioni che non contengano simboli fecondi, cioè $S\xRightarrow[]{\star}\alpha A\beta$ con $\alpha,\beta\in(V_T\cup V_N)^\star$ e, per ogni $B\in V_N$ in $\alpha$ o $\beta$, valga la proprietà precedente

Equivalentemente, un simbolo $A\in V_N$ non è inutile se esiste una derivazione $S\xRightarrow[]{\star}\alpha A\beta\xRightarrow[]{\star}w\in V_T^+$

Un non terminale $A$ è fecondo se e solo se vale una delle seguenti condizioni:

- esiste $w\in V_T^+|A\to w\in P$
- esiste $\alpha\in(V_N\cup V_T)^\star|A\to\alpha\in P$ e tutti i simboli non terminali in $\alpha$ sono fecondi

![[appunti fi/mod i/immagini/Pasted image 20221122131622.png|center|600]]

è necessario verificare che i simboli rimasti siano generabili a partire dall'assioma.

Ciò può essere effettuato in modo iterativo osservando che $A$ è generabile a partire da $S$ se vale una delle due condizioni seguenti:

1. esistono $\alpha,\beta\in(F\cup V_T)^\star:S\to\alpha A\beta\in \hat P$
2. esistono $\alpha,\beta\in(F\cup V_T)^\star$ e $B\in F$,generabile a partire da $S$, tali che $B\to\alpha A\beta\in\hat P$ 

Al fine di eliminare i simboli inutili (non fecondi e non generabili da $S$) è necessario eseguire i due algoritmi nell'ordine dato: eliminare prima i simboli non generabili e poi quelli non fecondi può far si che non tutti i simboli inutili vengano rimossi dalla grammatica

Infatti, si consideri la grammatica:
$$\begin{align}S&\to AB|a\\A&\to a\end{align}$$
Procedendo prima all'eliminazione dei simboli non derivabili dall'assioma e poi all'eliminazione di quelli non fecondi, otterremmo le seguenti grammatiche:
$$\begin{align}S&\to AB|a\\ A&\to a\end{align}$$
e successivamente : $$\begin{align}S&\to a\\A&\to a\end{align}$$
che non è in forma ridotta

Se invece si procede come indicato sopra si ottengono le due grammatiche
$$\begin{align}S&\to a\\A&\to a\end{align}$$
e successivamente:
$$\begin{align}S&\to a\end{align}$$

## Passo 4

Una grammatica $\mathcal G=\langle V_T,V_N,P,S\rangle$ può essere estesa in una grammatica $\mathcal G'=\langle V_T,V_N',P',S'\rangle$ che generi anche la stringa vuota nel modo seguente:

1. $V_N'=V_N\cup\lbrace T\rbrace$, dove $T\not\in V_N$
2. $P'=P\cup\lbrace T\to\varepsilon\rbrace\cup\lbrace T\to\alpha|S\to\alpha\in P\rbrace$
3. $S'=T$

**Esempio**
$$\begin{align}S&\to aUVb|TZ\\Z&\to aZ\\U&\to bU|b\\V&\to W\\V&\to aY\\Y&\to bY|b\\W&\to cWd|cd\\T&\to tT|tz\end{align}$$
- L’eliminazione delle produzioni unitarie porta ad escludere la produzione 4 e ad aggiungere una terza produzione alla 1.
- L’eliminazione di simboli non fecondi porta ad escludere la produzione 2 e la seconda produzione della 1.
- L’eliminazione dei simboli non raggiungibili porta infine ad escludere la produzione 8.

Si ottiene quindi la grammatica:
$$\begin{align}S&\to aUVb|aUWb\\U&\to bU|b\\V&\to aY\\Y&\to bY|b\\W&\to cWd|cd\end{align}$$
