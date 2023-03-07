# CNF (Chomsky Normal Form)

Una grammatica di tipo 2 si dice in **Forma Normale di Chomsky** se tutte le sue produzioni sono del tipo $A\to BC$ o del tipo $A\to a$, con $A,B,C\in V_N,a\in V_T$

>[!important]- Teorema
>Data un grammatica $\mathcal G$ non contestuale tale che $\varepsilon\not\in L(\mathcal G)$, esiste una grammatica equivalente in CNF

Come mostrato, è possibilederivare una grammatica $\mathcal G'$ in forma ridotta equivalente a $\mathcal G$: in particolare, $\mathcal G'$ non ha produzioni unitarie

Da $\mathcal G'$, è possibile derivare una grammatica $\mathcal G''$ in CNF, equivalente a essa

Sia $A\to\zeta_{i_1}...\zeta_{i_n}$  una produzione di $\mathcal G'$ non in CNF. Si possono verificare due casi:

- $n\geq3$ e $\zeta_{i_j}\in V_N,j=1,...,n$. In tal caso, introduciamo $n-2$ nuovi simboli non terminali $Z_1,...,Z_{n-2}$ e sostituiamo la produzione $A\to\zeta_{i_1}...\zeta_{i_n}$ con le produzioni $$\begin{align}A&\to\zeta_{i_1}Z_1\\Z_1&\to\zeta_{i_2}Z_2\\&...\\Z_{n-2}&\to\zeta_{i_{n-1}}\zeta_{i_n}\end{align}$$
	- **Esempio** $A\to BCBD$ diventa $A\to BZ_1,Z_1\to CZ_2,Z_2\to BD$ 
- $n\geq2$ e $\zeta_{i_j}\in V_N$ per qualche $j\in\lbrace 1,...,n\rbrace$. In tal caso per ciascun $\zeta_{i_j}\in V_T$ introduciamo un nuovo non terminale $\overline Z_{i_j}$, sostituiamo $\overline Z_{i_j}$ a $\zeta_{i_j}$ nella produzione considerata e aggiungiamo la produzione $\overline Z_{i_j}\to\zeta_{i_j}$. Così facendo o abbiamo messo in CNF la produzione considerata (se $n=2$) o ci siamo ricondotti al caso precedente (se $n\geq3$). 
	- **Esempio**: La grammatica $A\to ab$ diventa $A\to X_aX_b,X_a\to a,X_b\to b$

**Esempio**

Si consideri la grammatica di tipo 2 che genera il linguaggio $\lbrace a^nb^n|n\geq1\rbrace$ con le produzioni:
$$\begin{align}S&\to aSb\\S&\to ab\end{align}$$
La gramamtica è in forma ridotta

La grammatica equivalente in CNF avrà le seguenti produzioni: 
$$\begin{align}&S\to X_aSX_b\\&X_a\to a\\&X_b\to b\\&\text{oppure}\\&S\to X_aZ_1\\&Z_1\to SX_b\\&X_a\to a\\&X_b\to b\end{align}$$
>[!info]- Osservazione
>La produzione $S\to X_aSX_b$ può essere sostituita con le produzioni $S\to X_aZ_1,Z_1\to SX_b$

# GNF (Greibach Normal Form)

Una grammatica di tipo 2 si dice in **Forma Normale di Greibach** (GNF) se tutte le sue produzioni sono del tipo $A\to a\beta$, con $A\in V_N,a\in V_T,\beta\in V_N^\star$

Si osservi come una grammatica di tipo 3 corrisponda al caso in cui $|\beta|\leq1$

## Trasformazione in forma normale di Greibach

>[!important]- Lemma (Sostituzione)
>Sia $\mathcal G$ una grammatica di tipo 2 le cui produzioni includono $$\begin{align}A&\to\alpha_1B\alpha_2\\B&\to\beta_1|...|\beta_n\end{align}$$
>$(\alpha_1,\alpha_2\in V^\star)$ e in cui non compaiono altra B-produzioni oltre a quelle indicate. La grammatica $\mathcal G'$ in cui la produzione $A\to\alpha_1B\alpha_2$ è stata sostituita dalla produzione $$\begin{align}A&\to\alpha_1\beta_1\alpha_2|...|\alpha_1\beta_n\alpha_2\end{align}$$

>[!important]- Lemma (Eliminazione ricursione sinistra)
>Sia data la grammatica $\mathcal G$ con ricursione sinistra sul non terminale A e sia $$\begin{align}A&\to A\alpha_1|...|A\alpha_m|\beta_1|...|\beta_n\end{align}$$
>L'insieme delle A-produzioni in $\mathcal G$, dove nessuna delle stringhe $\beta_i$ inizia per A. La grammatica $\mathcal G'$ in cui le A-produzioni in $\mathcal G$ sono state sostituite dalle produzioni: $$\begin{align}A&\to\beta_1A'|...|\beta_nA'|\beta_1...|\beta_n\\A'&\to\alpha_1A'|...|\alpha_mA'|\alpha_1...|\alpha_m\end{align}$$
>è equivalente a $\mathcal G$ e non presenta ricursione sinistra rispetto al non terminale A

**Esempio**
La grammatica con produzioni:
$$\begin{align}A&\to Ab|ABC|bb|BA\end{align}$$
diventa:
$$\begin{align}A&\to bb|BA|bbA'|BAA'\\A'&\to b|BC|bA|BCA'\end{align}$$

>[!important]- Teorema
>Ogni linguaggio non contestuale $L$ tale che $\varepsilon\not\in L$ può essere generato da una grammatica di tipo 2 in GNF

Si assuma che $\mathcal G$ sia una grammatica CF in CNF che genera $L$

La derivazione di $\mathcal G'$ da $\mathcal G$ avviene applicando iterativamente i due lemmi precedenti, a partire da un ordinamento arbitrario $A_1,...,A_n$ tra i non terminali di $\mathcal G$.

### Fase 1

![[appunti fi/mod i/immagini/Pasted image 20221130153509.png|center|700]]

Siano $B_1,...,B_j$ i non terminali aggiunti. A questo punto le produzioni sono tutte di uno tra i tipi:

- (a) $A_k\to A_jy$ con $j\gt k,y\in(V_N\cup\lbrace B_1,...,B_j\rbrace)^\star$
- (b) $A_k\to ay$ con $a\in V_T,y\in(V_N\cup\lbrace B_1,...,B_j\rbrace)^\star$
- (c) $B_k\to y$ con $y\in V_N(V_N\cup\lbrace B_1,...,B_j\rbrace)^\star$

Inoltre, le $A_k$-produzioni sono:
- se $k=n$ tutte del tipo (b)
- se $k\lt n$ del tipo (b) o del tipo (a), con $j\leq n$

### Fase 2

![[appunti fi/mod i/immagini/Pasted image 20221130155448.png|center|700]]

A questo punto le produzioni sono del tipo (b) o (c)

### Fase 3

![[appunti fi/mod i/immagini/Pasted image 20221130155547.png|center|700]]

A questo punto le produzioni sono del tipo (b)

**Esempio**

Vedi file 7-lincf-slides.pdf da pagina 54 a pagina 59





