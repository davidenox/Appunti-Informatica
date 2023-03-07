
# Ambiguità

>[!important]- Definizione (Ambiguità)
>Una grammatica CF $\mathcal G$ si dice **ambigua** se esiste una stringa $x\in L(\mathcal G)$ derivabile con due diversi alberi sintattici

L'albero sintattico di una stringa corrisponde in qualche modo al significato della stringa stessa, quindi l'univocità di questo albero è importante per comprendere senza ambiguità tale significato

**esempio**

Si consideri la grammatica 
$$E\to E+E|E-E|E*E|E/E|(E)|a$$
Essa genera tutte le espressioni aritmetiche sulla variabile a, ma come si vede facilmente la stessa espressione può essere derivata con alberi di derivazione differenti

Ad esempio la stringa $a+a*a$ può venire derivata mediante due diversi alberi 

![[appunti fi/mod i/immagini/Pasted image 20221209100138.png|center|600]]

Se si pone $a=3$, nel primo albero avremo che la stringa genererà il numero 12, mentre il secondo genererà il numero 18

## Eliminazione dell'ambiguità

- Introduzione di parentesi
- Precedenza tra operatori

### Parentesi
$$E\to (E+E)|(E-E)|(E*E)|(E/E)|(E)|a$$
I due diversi alberi di derivazione che davano origine alla stessa stringa, danno ora origine alle due stringhe
$$\begin{align}&(a+(a*a))\\&((a+a)*a)\end{align}$$


### Precedenza

$$\begin{align}&E\to E+T|E-T|T\\&T\to T*F|T/F|F\\&F\to (E)|a\end{align}$$
La grammatica rappresenta nella sua struttura le relazioni di precedenza definite tra gli operatori (nell'ordine non decrescente $+,-,*,/$) e in tal caso consente di utilizzare le parentesi soltanto quando strettamente necessario

## Riconoscimento

Data una grammatica $\mathcal G$ non contestuale, $\mathcal G$ è ambigua?

Il problema è **indicidibile** nel caso delle CFG: non esiste quindi nessun algoritmo di decisione che, data una CFG, restituisca T se la grammatica è ambigua e F altrimenti

### Riduzione

Indecibilità dimostrata mediante **riduzione** da un'altro problema di decisione $\mathcal P$, che si sa essere indecidibile

Schema generale di dimostrazione:

- Si vuole mostrare che il problema $\mathcal P_1$ è indecidibile
- Si individua un'altro problema $\mathcal P_0$ che si sa essere indecidibile
- Se definisce un algoritmo $\mathcal A$ che trasforma ogni istanza $\mathcal I_0$ di $\mathcal P_0$ in una istanza $\mathcal I_1=\mathcal A(\mathcal I_0)$ di $\mathcal P_0$
- Si mostra che l'istanza $\mathcal I_1$ è positiva per $\mathcal P_1$ se e solo se $\mathcal I_0$ è positiva per $\mathcal P_0$
- Si conclude che $\mathcal P_1$ è indecidibile: se così non fosse avremmo un algoritmo che decide $\mathcal P_0$, in quanto potremmo trasformare, per mezzo di $\mathcal A$, ogni sua istanza in una istanza corrispondente di $\mathcal P_1$, che potremmo, per ipotesi, risolvere

Nel nostro caso:

- $\mathcal P_1$ è il problema di determinare, data una grammatica CF (istanza del problema), se essa è ambigua
- $\mathcal P_0$ è **PCP** (Problema delle Corrispondenze di Post):
	- data una istanza del problema, composta da:
		- un alfabeto $\Sigma$
		- due sequenze di k parole $X=x_1,...,x_k$ e $Y=y_1,...,y_k$ costruite su $\Sigma$
	- ci si chiede se esiste una sequenza di $m\geq1$ interi $i_1,i_2,...,i_m\in [1,..,k]$ tale che risulti $$x_{i_1},...,x_{i_m}=y_{i_1},...,y_{i_m}$$
**Esempio di PCP**

- Consideriamo le due sequenze 1,10111,10 e 111,10,0 costruite sull'alfabeto $\{0,1\}$
- Si può verificare che la sequenza di interi 2,1,1,3 costitusice una soluzione alla istanza di PCP considerata
- Infatti, si ottiene in un caso la sequenza $$10111*1*1*10 = 101111110$$ e nell'altro la stessa sequenza $$10*111*111*0 = 101111110$$
PCP è indecidibile (dimostrazione per riduzione dal **Problema della fermata**)

- Sia $A=x_1,..,x_k$ e $B=y_1,..,y_k$ una istanza (generica) di PCP su un alfabeto $\Sigma$
- Consideriamo:
	- l'alfabeto $\Sigma\cup\{a_1,a_2,...,a_k\}$, con $a_i\not\in\Sigma,i=1,...,k$
	- Il linguaggio $L'=L_A\cup L_B$ definito su $\Sigma$, in cui:
		- $L_A=\{x_{i_1}x_{i_2}...x_{i_m}a_{i_{m-1}}...a_{i_1}|m\geq1\}$
		- $L_B=\{y_{i_1}y_{i_2}...y_{i_m}a_{i_{m-1}}...a_{i_1}|m\geq1\}$
	- La relativa grammatica CF: $$\mathcal G'=\langle\{S,S_A,S_B\},\Sigma\cup\{a_1,a_2,...,a_k\},P,S\rangle$$, con produzioni P, per $i=1,...,k$:$$\begin{align}&S\to S_A|S_B\\&S_A\to x_1S_Aa_1|...|x_kS_Aa_k|x_1a_1|....|x_ka_k\\&S_B\to y_1S_Ba_1|...|y_kS_Ba_k|y_1a_1|...|y_ka_k\end{align}$$
**Esempio di riduzione**

Data l'istanza $([1,10111,10],[111,10,0])$, la corrispondente grammatica sarà data da:
$$\begin{align}&S\to A|B\\&A\to 1Aa|10111Ab|10Ac|1a|10111b|10c\\&B\to 111Ba|10Bb|0Bc|111a|10b|0c\end{align}$$
#### Equivalenza tra istanze

Se l'istanza $(A,B)$ di PCP ha soluzione,allora $\mathcal G'$ è ambigua

- Sia $i_1,...,i_m$ una soluzione di PCP, tale che quindi $x_{i_1}...x_{i_m}a_{i_m}...a_{i_1}=y_{i_1}...y_{i_m}a_{i_m}...a_{i_1}=\sigma$
- La stringa $\sigma$ appartiene a $L'$ e ammette due distinti alberi sintattici, corrispondenti (il primo) alla derivazione: $$S\implies S_A\implies x_{i_1}S_Aa_{i_1}\implies x_{i_1}x_{i_2}S_Aa_{i_2}a_{i_1}\xRightarrow[]{\star}x_{i_1}...x_{i_m}a_{i_m}...a_{i_1},$$ e il secondo alla derivazione : $$S\implies S_B\implies y_{i_1}S_Ba_{i_1}\xRightarrow[]{\star} y_{i_1}...y_{i_m}a_{i_m}...a_{i_1}=x_{i_1}...x_{i_m}a_{i_m}...a_{i_1}$$
- $\mathcal G'$ risulta dunque ambigua

Se $\mathcal G'$ è ambigua, allora l'istanza $(A,B)$ di PCP ha soluzione

- Sia z una stringa di $L'$ che ammette due distinti alberi sintattici
- Per definizione di $L'$, deve essere $z=wa_{i_m}...a_{i_1}$ per un qualche $m\geq1$
- Inoltre, per definzione di $L'$, z deve appartenenre ad almeno uno tra $L_A$ e $L_B$: assumiamo, senza perdere generalità, che $z\in L_A$
- Allora, deve essere $w=x_{i_1}...x_{i_m}$. e la produzione iniziale della derivazione deve essere $S\to S_A$
- Ma per definizione di $\mathcal G'$, l'altro modo di derivare z non può che prevedere come pirma produzione $S\to S_B$, per cui $w=y_{i_1}...y_{i_m}$
- Ne deriva che $i_1,...,i_m$ è la soluzione dell'istanza $(A,B)$ di PCP

**Esempio di riduzione**

Come osservato, la sequenza 2,1,1,3 costituisce una soluzione dell'istanza di PCP

Corrispondentemente, la stringa 101111110caab può essere ottenuta dalle due derivazioni
$$\begin{align}&S\to A\to 10111Ab\to 101111Aab\to 1011111Aaab\to 10111111ocaab\\&S\to B\to 10Bb\to 10111Babb\to 10111111Baab\to 101111110caab\end{align}$$

## Indecidibilità

- La trasformazione definita deriva quindi, da una istanza di PCP, una grammatica CF che è ambigua se e solo se l'istanza ha soluzione
- Se avessimo un algoritmo che determina se una grammatica CF è ambigua, allora potremmo determinare se una istanza di PCP ha soluzione
- Ma un algoritmo ceh determina se una istanza di PCP ha soluzione non esiste
- Quindi, non esiste un algoritmo che determina se una grammatica CF è ambigua

## Esistenza di grammatica equivalente non ambigua

>[!important]- Definizione
>Un linguaggio di tipo 2 si dice **inerentemente ambiguo** se tutte le grammatiche che lo generano sono ambigue

Anche il problema dell'inerente ambiguità di un linguaggio è indecidibile

# Automi a Pila

Un automa a pila (o automa push-down) è definito come una settupla $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$ dove $\Sigma$ è l'**alfabeto in input**, $\Gamma$ è l'**alfabeto dei simboli della pila**, $Z_0\in\Gamma$ è il **simbolo iniziale di pila**, Q è un insieme finito e non vuoto di **stati**, $q_0\in Q$ è lo **stato iniziale**, $F\subseteq Q$ è l'**insieme degli stati finali**, $\delta:Q\times(\Sigma\cup\{\varepsilon\})\times\Gamma\to Q\times\Gamma^\star$ è la **funzione (parziale) di transizione**

L'automa introdotto è non deterministico, in quanto la presenza di $\varepsilon$-transizioni può comportare che esistano continuazioni diverse di una stessa computazione anche in presenza di uno stesso carattere letto

Per ottenere un comportamento deterministico dobbiamo fare l'ulteriore ipotesi che se, per una coppia $q\in Q,Z\in\Gamma$, è definita $\delta(q,\varepsilon,Z)$ allora la funzione di transizione $\delta(q,a,Z)$ non deve essere definita per nessun $a\in\Sigma$ 

Ad ogni passo l'automa, a partire dallo stato attuale,dal carattere letto sul nastro di input e dal carattere affiorante sulla pila, sostituisce il simbolo affiorante nella pila con una stringa di caratteri e si porta in un nuovo stato.

La convenzione è che il primo carattere della stringa diventi il simbolo di pila affiorante. Si noti che se la stringa che viene inserita nella pila è la stringa vuota,ciò equivale a dire che il simbolo precedente affiorante nella pila è stato cancellato

![[appunti fi/mod i/immagini/Pasted image 20221217155019.png|center|600]]

**Esempio**

![[appunti fi/mod i/immagini/Pasted image 20221217155054.png|center|600]]

## Configurazioni

Dato un automa a pila $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$, una configurazione di $\mathcal M$ è data dalla tripla $\langle q,x,\gamma\rangle$, dove $q\in Q,x\in\Sigma^\star,\gamma\in\Gamma^\star$

Sia $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$ un automa a pila e siano $(q,x,\gamma)$ e $(q',x',\gamma')$ due configurazioni di $\mathcal M$: avremo allora che $(q,x,\gamma)\vdash_{\mathcal M}(q',x',\gamma')$ se e solo se valgono le tre condizioni:

1. esiste $a\in\Sigma$ tale che $x=ax'$
2. esistono $Z\in\Gamma$ e $\eta,\zeta\in\Gamma^\star$ tali che $\gamma=Z\eta$ e $\gamma'=\zeta\eta$
3. $\delta(q,a,Z)=(q',\zeta)$

oppure le tre condizioni: 

1. $x=x'$
2. esistono $Z\in\Gamma$ e $\eta,\zeta\in\Gamma^\star$ tali che $\gamma=Z\eta$ e $\gamma'=\zeta\eta$
3. $\delta(q,\varepsilon,Z)=(q',\zeta)$

Una computazione è definita come una sequenza $c_0,...,c_k$ di configurazioni di $\mathcal M$ tale che 
$$c_i\vdash_{\mathcal M}c_{i+1}$$
## Accettazione per pila vuota

Sia $\mathcal M$ un automa a pila. Una configurazione $(q,x,\gamma)$ di $\mathcal M$ è di accetazione se $x=\gamma=\varepsilon$. Secondo tale definizione, una stringa x è quindi **accettata** da $\mathcal M$ se e solo se al termine della scansione della stringa la pila è vuota

Indichiamo con $N(\mathcal M)$ il linguaggio accettato per pila vuota dall'automa $\mathcal M$

## Accettazione per stato finale

Sia $\mathcal M$ un automa a pila. Una configurazione $(q,x,\gamma)$ di $\mathcal M$ è di accetazione se $x=\varepsilon$ e $q\in F$. Secondo tale definzione, una stringa x è quindi **accettata** da $\mathcal M$ se e solo se al termine della scansione della stringa l'automa si trova in uno stato finale

Indichiamo con $L(\mathcal M)$ il linguaggio accettato per stato finale dall'automa

