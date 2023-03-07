
# Equivalenza tra ASFD e ASFND

Dato un ASFD che riconosce un linguaggio $L$, esiste corrispondentemente un ASFND che rinconosce lo stesso linguaggio $L$; viceversa, dato un ASFND che riconosce un linguaggio $L'$, esiste un ASFD che riconosce lo stesso linguaggio $L'$ 

Dato un ASFND $\mathcal A_n=\langle\Sigma,Q,\delta,q_0,F\rangle$, un ASFD equivalente $\mathcal A'=\langle\Sigma,Q',\delta',q_0',F'\rangle$ è derivabile nel modo seguente:

L'insieme $Q'$ è in corrispondenza biunivoca con $\mathcal P(Q)$ (quindi $|Q'|=2^{|Q|}$).

Indichiamo come $[q_{i_1},...,q_{i_k}]\in Q'$ lo stato corrispondente all'insieme $\lbrace q_{i_1},...,q_{i_k}\rbrace\subseteq Q$: i nomi degli stati di $Q$ sono ordinati lessicograficamente.

Quindi $Q'$ risulta definito come:
$$Q'=\lbrace[q_{i_1},...,q_{i_k}]:\lbrace q_{i_1},...,q_{i_k}\rbrace\in\mathcal P(Q)\rbrace$$

Lo stato iniziale è $q_0'=[q_0]$

Gli stati finali di $F'$ corrispondono ai sottoinsiemi di Q che contengono almeno un elemento di $F$:
$$F'=\lbrace[q_{i_1},...,q_{i_k}]:\lbrace q_{i_1},...,q_{i_k}\rbrace\in\mathcal P(Q)\land\lbrace q_{i_1},...,q_{i_k}\rbrace\cap F\neq\emptyset\rbrace$$

$\delta^{'}$ è definita nel seguente modo:
$$\forall q_{i_1},...,q_{i_k}\in Q,\forall a\in\Sigma,\delta'([q_{i_1},...,q_{i_k}],a)=[q_{j_1},...,q_{j_h}]$$
se e solo se
$$\delta_N(q_{i_1},a)\cup...\cup\delta_N(q_{i_k},a)=\lbrace q_{j_1},...,q_{j_h}\rbrace$$
con $k\gt0,h\geq0$

Inoltre, si assume che per ogni $a\in\Sigma$ sia $\delta'([],a)=[]$

**Esempio di transizione da ASFND a ASFD**

![[Pasted image 20221107150359.png|center|600]]

Come mostrare che $\mathcal A_N$ e $\mathcal A$ sono equivalenti?

è necessario mostrare che, per ogni $x\in\Sigma^\star$, se $x$ è accettata da $\mathcal A_N$ allora viene accettata anche da $\mathcal A$. Vale anche il viceversa

Dimostrazione "più forte", che ad ogni computazione effettuata dall'automa $\mathcal A$ ne corrisponde una equivalente dell'automa $\mathcal A_N$ e viceversa. Cioè
$$\overline\delta'([q_0],x)=[q_{j_1},...,q_{j_h}]\iff\overline\delta_N(q_0,x)=\lbrace q_{j_1},...,q_{j_h}\rbrace$$

Se è vero questo, significa che o ogni stringa $x$ è accettata sia da $\mathcal A$ e da $\mathcal A_N$, o non è accettata da nessuno dei due

_Dim_

Dimostrazione per induzione su $|x|$

Passo base: $(|x|=0)$ In questo caso vale necessariamente che $x=\varepsilon$, per cui abbiamo che $\overline\delta_N(q_0,\varepsilon)=\lbrace q_0\rbrace$ e $\overline\delta'([q_0],\varepsilon)=[q_0]$

Passo induttivo $(|x|\gt0)$ Supponiamo che la proprietà sia vera per $|x|=m$ e dimostriamo che essa continua a valere per $|x|=m+1$

Poniamo $x=x'a$, con $|x'|=m$. Per $\overline\delta_N$ abbiamo:
$$\overline\delta(q_0,x'a)=\bigcup_{p\in\overline\delta_N(q_0,x')}\delta_n(p,a)$$
Supponendo che $\overline\delta_N(q_0,x')=\lbrace q_{i_1},...,q_{i_k}\rbrace$ e che $\delta_N(q_{i_1},a)\cup...\cup\delta_N(q_{i_k},a)=\lbrace q_{j_1},...,q_{j_h}\rbrace$ otteniamo:
$$\overline\delta_N(q_0,x'a)=\lbrace q_{j_1},...,q_{j_h}\rbrace$$

Per $\overline\delta$ vale:
$$\overline\delta'(q_0,x'a)=\delta'(\overline\delta'([q_0],x'),a)$$
Essendo $|x'|=m$ possiamo sfruttare l'ipotesi induttiva, e quindi:
$$\delta'(\overline\delta'([q_0],x'),a)=\delta'([q_{i_1},...,q_{i_k}],a)$$
che per costruzione vale proprio $[ q_{j_1},...,q_{j_h}]$ 

La dimostrazione è completa osservando che $\overline\delta'([q_0],x)\in F'$ esattamente quando $\delta_N(q_0,x)$ contiene uno stato di $Q$ che è in $F$ $\square$ 

# Equivalenza tra ASF,RG e RE

## ASF e Grammatiche di tipo 3

Per ogni grammatica regolare $\mathcal G=\langle V_T,V_N,P,S\rangle$, esiste un ASFND $\mathcal A_N=\langle\Sigma,Q,\delta_N,q_0,F\rangle$ che riconosce il linguaggio che esso genera

Viceversa, per ogni ASFND $\mathcal A_N$ esiste una grammatica regolare che genera il linguaggio che esso riconosce

Sia $\mathcal G=\langle V_T,V_N,P,S\rangle$ una grammatica di tipo 3 con al più la sola $\varepsilon$-produzione $S\to\varepsilon$

Definiamo una procedura che a partire da $\mathcal G$ produca un ASFND $\mathcal A_N=\langle\Sigma,Q,\delta_N,q_0,F\rangle$ equivalente (che accetta tutte e sole le stringhe prodotte da $\mathcal G$)

### Da $\mathcal G$ a $\mathcal A_N$

- $\Sigma=V_T$
- $Q=\lbrace q_I|I\in V_N\rbrace\cup\lbrace q_F\rbrace$
- $q_0=q_S$
- $$F=\begin{cases}\lbrace q_0,q_F\rbrace & se\:S\to\varepsilon\in P\\\lbrace q_F\rbrace & altrimenti\end{cases}$$
Per ogni coppia $a\in V_T$, $B\in V_N$, si ha che
$$\delta_N(q_B,a)=\begin{cases}\lbrace q_C|B\to aC\in P\rbrace\cup\lbrace q_F\rbrace & se\:B\to a\in P\\\lbrace q_C|B\to aC\in P\rbrace & altrimenti\end{cases}$$
L'automa, in generale, è non deterministico

#### Equivalenza di $\mathcal G$ e $\mathcal A_N$
Per dimostrare l'equivalenza tra $\mathcal G\:e\:\mathcal A_N$, dobbiamo mostrare che per ogni $x\in\Sigma^\star$ si ha che:
$$S\xRightarrow[\mathcal G]{\star}x\:\text{se e solo se}\:\overline\delta_N(q_S,x)\cap F\neq\emptyset$$
Questo è chiaramente vero se $x=\varepsilon$, in quanto $\overline\delta_N(q_S,\varepsilon)=q_S\in F$, se e solo se $S\to\varepsilon\in P$, per costruzione

Nel caso $x\in\Sigma^+$ mostriamo, per induzione sulla lunghezza di x, la proprietà più generale
$$S\xRightarrow{\star}xZ\:\text{se e solo se}\:q_Z\in\overline\delta_N(q_S,x)$$

Iniziamo da 
$$S\xRightarrow{\star}xZ\implies q_Z\in\overline\delta_N(q_S,x)$$
**Passo base**: $|x|=1$, per cui $x=a$, con $a\in\Sigma$. Allora abbiamo che $S\xRightarrow{}aZ$ se e solo se $S\to aZ\in P$ e quindi se e solo se, per costruzione dell'automa, $q_Z\in\delta_N(q_S,a)$
**Passo induttivo**: $|x|\gt1$, per cui $x=ya$, con $|y|=n\geq1\;e\;a\in\Sigma$. Per l'ipotesi induttiva il risultato si assume valido per y, quindi $$S\xRightarrow{\star}yZ\iff q_Z\in\overline\delta_N(q_S,y)$$ Osserviamo che $S\xRightarrow{\star}xZ'$ se e solo se esiste $Z\in V_N$ tale che $S\xRightarrow{\star}yZ\xRightarrow{}yaZ'=xZ'$. Ne deriva che
-  $q_Z\in\overline\delta_N(q_S,y)$ per induzione
- $Z\to aZ'\in P$, e quindi $q_{Z'}\in\delta_N(a,Z)$ per costruzione

Quindi, $q_{Z'}\in\overline\delta_N(q_S,ya)=\overline\delta_N(q_S,x)$ 

Abbiamo verificato che $S\xRightarrow{\star}xZ$ se e solo se $q_Z\in\overline\delta_N(q_S,x)$
Osserviamo ora che $S\xRightarrow{}x$ se e solo se esistono $Z\in V_N,y\in\Sigma^\star$ e $Z\to a\in P:x=ya\:e\:S\xRightarrow{\star}yZ\xRightarrow{\star}ya=x$ 

Da quanto visto sopra, cio è vero se e solo se $q_Z\in\overline\delta_N(q_S,y)$ e $q_F\in\delta_N(q_Z,a)$, e quindi se e solo se $q_F\in\overline\delta_N(q_S,ya)=\overline\delta_N(q_S,x)$

In conclusione, per ogni linguaggio regolare (generato da una gframmatica di tipo 3), esiste un ASFND che lo accetta (e quindi anche un ASFD che lo decide)

$\square$

### Da $\mathcal A$ a $\mathcal G$

Sia $\mathcal A=\langle\Sigma,Q,\delta_N,q_0,F\rangle$ un ASFD

Definiamo una procedura che a partire da $\mathcal A$ produca una grammatica di tipo 3 $\mathcal G=\langle V_T,V_N,P,S\rangle$ equivalente (che genera tutte e sole le stringhe accettate da $\mathcal A$)

Se $q_0\not\in F$:
- $V_T=\Sigma$
- $V_N=\lbrace A_i|\forall q_i\in Q\rbrace$
- $S=A_0$

Per ogni regola di transizione $\delta(q_i,a)=q_j$ esiste $A_i\to aA_j\in P$, e se $q_j\in F$ esiste anche $A_i\to a\in P$

Se $q_0\in F$:
- $V_T=\Sigma$
- $V_N=\lbrace A_i|\forall q_i\in Q\rbrace$
- $S=A_0'$

Per ogni regola di transizione $\delta(q_i,a)=q_j$ esiste $A_i\to aA_j\in P$, e se $q_j\in F$ esiste anche $A_i\to a\in P$ (tutte le precedenti). Inoltre, per ogni $\delta(q_0,a)=q_j$ esiste $A_0'\to aA_j\in P$, e se $q_j\in F$ esiste anche $A_0'\to a\in P$ ($A'$ ha tutte le produzioni di $A_0$), infine, esiste $A_0'\to\varepsilon\in P$ 

#### Equivalenza di $\mathcal G$ e $\mathcal A$

Come prima, per dimostrare l'equivalenza tra $\mathcal G$ e $\mathcal A$, dobbiamo mostrare che per ogni $x\in\Sigma^\star$ si ha che :
$$\overline\delta(q_0,x)\in F\iff S\xRightarrow[\mathcal G]{\star}x$$
Questo è chiaramente vero se $x=\varepsilon$,in quanto in tal caso necessariamente $q_0\in F$ e, per costruzione, l'assioma di $\mathcal G$ è $A_0'$ e $A_o'\to\varepsilon\in P$

Nel caso $x\in\Sigma^+$ mostriamo, per induzione sulla lunghezza di x. entrambe le proprietà
$$\begin{cases}A_i\xRightarrow{\star}xA_j&\iff\overline\delta(q_i,x)=q_j\\A_i\xRightarrow{\star}x&\iff\overline\delta(q_i,x)\in F\end{cases}$$
**Passo base**: $|x|=1$, ad esempio $x=a$. Abbiamo allora che, per costruzione $A_i\to aA_j\in P$ se e solo se $\delta(q_i,a)=q_j$
E inoltre, per costruzione, $A_i\to a\in P$ se e solo se $q_j\in F$

**Passo induttivo** $|x|=n\gt1$
Sia $x=ya$, con $|y|=n-1$: per l'ipotesi induttiva, la proprietà è valida per y e quindi
$$A_i\xRightarrow{\star}yA_k\iff\overline\delta(q_i,y)=q_k$$
Supponiamo $A_i\xRightarrow{\star}xA_j=yaA_j$: ciò è possibile se e solo se esiste $A_k$ tale che $A_i\xRightarrow{\star}yA_k$ e $A_k\to aA_j\in P$

Per l'ipotesi induttiva, $A_i\xRightarrow{\star}yA_k$ se e solo se $\overline\delta(q_i,y)=q_k$
Per costruzione, $A_k\to aA_j\in P$ se e solo se $\delta(q_k,a)=q_j$
Ne consegue che 
$$A_i\xRightarrow{\star}yA_k\xRightarrow{}yaA_j=xA_j$$
se e solo se
$$q_j=\delta(q_k,a)=\delta(\overline\delta(q_i,ya),a)=\overline\delta(q_i,ya)=\overline\delta(q_i,x)$$
$\square$

**Esempio**
Il linguaggio rappresentato da $a(a+ba)^\star a$ è generato dalla grammatica
- $S\to aB$
- $B\to aB|bS|a$

ed è riconosciuto dall'ASFND
![[Pasted image 20221110143259.png|center|500]]

A partire dall' ASFND è possibile derivare un ASFD equivalente
![[Pasted image 20221110143449.png|center|500]]

E da questo una grammatica di tipo 3 equivalente a quella iniziale, dove $S=A_0$
- $A_0\to aA_1$
- $A_1\to bA_0|aA_2|a$
- $A_2\to aA_2|bA_0|a$
Per costruzione, questa grammatica ha, per ogni coppia $X\in V_N$ e $c\in V_T$, al più un $Y\in V_N$ tale che $X\to xY\in P$
