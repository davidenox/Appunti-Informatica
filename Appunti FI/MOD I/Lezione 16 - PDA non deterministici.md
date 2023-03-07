# Automi a pila non deterministici

Un **automa a pila non deterministico** è definito come una settupla $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$ dove $\Sigma$ è l'**alfabeto in input**, $\Gamma$ è l'**alfabeto dei simboli della pila**, $Z_0\in\Gamma$ è il **simbolo iniziale di pila**, Q è un insieme finito e non vuoto di **stati**, $q_0\in Q$ è lo **stato iniziale**, $F\subseteq Q$ è l'**insieme degli stati finali**, $\delta:Q\times(\Sigma\cup\{\varepsilon\})\times\Gamma\to\mathcal P(Q\times\Gamma^\star)$ è la **funzione (parziale) di transizione**

**Oss**
$\mathcal P(Q\times\Gamma^\star)$ è l'insieme potenza di $Q\times\Gamma^\star$

Nel caso degli automi a pila la presenza del non determinismo comporta un aumento del potere computazionale

Mentre gli automi a pila non deterministici riconoscono la classe dei linguaggi non contestuali, gli automi a pila deterministici riconoscono un sottoinsieme proprio di tali linguaggi, la classe dei linguaggi non contestuali deterministici

**Esempio**: accettazione del linguaggio non contestuale $\{w\hat w|w\in\{s,b\}^+\}$, dove $\hat w$ indica la stringa riflessa di $w$  

**Esempio di accettazione per pila vuota**

Tabella di transizione dell’automa a pila che accetta per pila vuota il linguaggio $\{w\hat w|w\in\{s,b\}^+\}$

![[appunti fi/mod i/immagini/Pasted image 20221217162459.png|center|550]]

**Esempio di accettazione per stato finale**

Tabella di transizione dell’automa a pila che accetta per stato finale il linguaggio $\{w\hat w|w\in\{s,b\}^+\}$ con $q_f=q_2$

![[appunti fi/mod i/immagini/Pasted image 20221217162904.png|center|550]]

## Equivalenza tra condizioni di accettazione

>[!important]- Teorema
>Dato un automa a pila non deterministico $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$ che accetta un linguaggio per stato finale,esiste un automa a pila non deterministico $\mathcal M'=\langle\Sigma',\Gamma',Z_0',Q',q_0',\emptyset,\delta'\rangle$ che accetta lo stesso linguaggio per pila vuota, vale a dire tale che $L(\mathcal M)=N(\mathcal M')$

$\mathcal M'$ opera in modo simile a $\mathcal M$ , secondo lo schema seguente:

1. All’inizio $\mathcal M'$ ha nella pila un simbolo speciale $X$ non appartenente a $\Gamma$ ed inserisce al di sopra di $X$ il simbolo $Z_0$
2. Quindi,$\mathcal M'$ esegue gli stessi passi di $\mathcal M$. Si noti che nel corso di tale fase la pila di $\mathcal M'$ non sarà mai vuota
3. Se, alla fine della stringa di input,$\mathcal M$ raggiunge un suo stato finale (che quindi è raggiuntoanche da $\mathcal M'$),$\mathcal M'$ provvede ad eliminare tutti i simboli presenti in pila, incluso $X$


$\mathcal M'$ è allora definito come $\Sigma'=\Sigma,\Gamma'=\Gamma\cup\{X\}(X\not\in\Gamma),Z_0'=X,Q'=Q\cup\{q_0',q_f\}(q_0',q_f\not\in\Gamma)$ e, per quanto riguarda la funzione di transizione $\delta'$:

1. $\delta'(q,a,Z)=\delta(q,a,Z)$ per ogni $q\in Q,a\in\Sigma,Z\in\Gamma$
2. $\delta'(q,\varepsilon,Z)=\delta(q,\varepsilon,Z)$ per ogni $q\in Q-F,Z\in\Gamma$
3. $\delta'(q,\varepsilon,Z)=\delta(q,\varepsilon,Z)\cup\{(q_f,\varepsilon)\}$ per ogni $q\in F,Z\in\Gamma$
4. $\delta'(q_0',\varepsilon,X)=\{(q_0,Z_0X)\}$
5. $\delta'(q_f,\varepsilon,Z)=\{(q_f,\varepsilon)\}$ per ogni $Z\in\Gamma'$

A questo punto si avrà che:

- Per l'effetto di 1 e 2 $\mathcal M'$ simula perfettamente $\mathcal M$ se questo non si trova in uno stato finale
- Per l'effetto di 1 e 3 $\mathcal M'$ in uno stato finale può eseguire tutte le transizioni definite per $\mathcal M$ con l'ulteriore possibilità di effettuare una $\varepsilon$-transizione verso il suo stato $q_f$ lasciando la pila immutata
- La condizione 4 fa si che il simbolo $X$ rimanga in fondo alla pile mentre l'automa $\mathcal M'$ effettua la simulazione di $\mathcal M$
- La condizione 5 assicura lo svuotamento della pila di $\mathcal M'$ nel caso in cui $\mathcal M$ raggiunga uno stato finale

>[!important]- Teorema
>Dato un automa a pila non deterministico $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$ che accetta un linguaggio per pila vuota,esiste un automa a pila non deterministico $\mathcal M'=\langle\Sigma',\Gamma',Z_0',Q',q_0',\emptyset,\delta'\rangle$ che accetta lo stesso linguaggio per stato finale, vale a dire tale che $N(\mathcal M)=L(\mathcal M')$

$\mathcal M'$ opera in modo simile a $\mathcal M$ , secondo lo schema seguente:

1. All’inizio $\mathcal M'$ ha nella pila un simbolo speciale $X$ non appartenente a $\Gamma$ ed inserisce al di sopra di $X$ il simbolo $Z_0$
2. Quindi,$\mathcal M'$ esegue gli stessi passi di $\mathcal M$. Si noti che nel corso di tale fase la pila di $\mathcal M'$ non sarà mai vuota
3. Se, alla fine della stringa di input, $\mathcal M$ raggiunge la condizione di pila vuota, $\mathcal M'$ entra nello stato finale $q_f$

$\mathcal M'$ è allora definito come $\Sigma'=\Sigma,\Gamma'=\Gamma\cup\{X\}(X\not\in\Gamma),Z_0'=X,Q'=Q\cup\{q_0',q_f\}(q_0',q_f\not\in\Gamma)$ e, per quanto riguarda la funzione di transizione $\delta'$:

1. $\delta'(q,a,Z)=\delta(q,a,Z)$ per ogni $q\in Q,a\in\Sigma\cup\{\varepsilon\},Z\in\Gamma$
2. $\delta'(q,\varepsilon,Z)=\{(q_f,X)\}$ per ogni $q\in Q$
3. $\delta'(q_0',\varepsilon,X)=\{(q_0,Z_0X)\}$

A questo punto si avrà che: 

- Per effetto di 1, $\mathcal M'$ simula perfettamente $\mathcal M$ se la pila di questo non è vuota
- Per effetto di 2 $\mathcal M'$, se la pila di $\mathcal M$ è vuota (e quindi la propria contiene solo $X$), può effettuare una $\varepsilon$-transizione verso il suo stato finale $q_f$ lasciando la pila immutata
- La 3 fa si ch il simbolo $X$ rimanga in fondo alla pila mentre l'automa $\mathcal M'$ effettua la simulazione di $\mathcal M$

## Equivalenza CFG-NPDA

Se un linguaggio è generato da una grammatica $\mathcal G$ non contestuale, esiste un automa a pila non deterministico $\mathcal M$ tale che $L(\mathcal G)=N(\mathcal M)$

La dimostrazione è costruttiva: a partire da $\mathcal G$ deriviamo $\mathcal M$ e poi mostriamo l'equivalenza

### $\varepsilon\not\in L(\mathcal G)$  da $\mathcal G$ deriviamo $\mathcal M$ 

Consideriamo dapprima il caso in cui $\varepsilon\not\in L(\mathcal G)$. A partire da $\mathcal G$, costruiamo una grammatica $\mathcal G'=\langle\Sigma,V_N',P',S'\rangle$ equivalente a $\mathcal G$, ma in Forma Normale di Greibach

Per l'automa, poniamo $\Gamma=V_N',Q=\{q_0\},Z_0=S'$

Funzione di transizione: per ogni produzione $A\to a\gamma,\gamma\in(V_N')^\star$ introduciamo la regola $\delta(q_0,a,A)=(q_0,\gamma)$ (più precisamente si ha che $(q_0,\gamma)\in\delta(q_0,a,A)$)

L'equivalenza deriva dalla dimostrazione che 
$$(q,x,S')\vdash^\star(q,\varepsilon,\alpha)$$
se e solo se $S'\xRightarrow[]{\star}x\alpha$, dove $q\in Q,x\in\Sigma^\star,\alpha\in(V_N')$

**Dimostrazione**

In due passi:

1. Dimostrazione, per induzione su i (numero di passi della computazione), che se $$(q,x,S')\vdash^i(q,\varepsilon,\alpha)\implies S'\xRightarrow[]{\star}x\alpha$$
2. Dimostrazione, per induzione su i (numero di passi della derivazione), che se $$S'\xRightarrow[]{\star}x\alpha\implies (q,x,S')\vdash^\star(q,\varepsilon,\alpha)$$
$\square$

## Equivalenza NPDA-CFG

### $\varepsilon\in L(\mathcal G)$ da $\mathcal M$ deriviamo $\mathcal G$

Se $\varepsilon\in L(\mathcal G)$ possiamo costruire una grammatica $\mathcal G'$ in GNF che genera il linguaggio $L(\mathcal G')=L(\mathcal G)-\{\varepsilon\}$ e quindi applicare la procedura descritta per ottenere un automa a pila $\langle\Sigma,\Gamma,Z_0,\delta,\{q_0\},\emptyset\rangle$ che riconosce $L(\mathcal G')$

Un automa che riconosce $L(\mathcal G)$ può essere ottenuto aggiungendo un nuovo stato iniziale $q_0'$ e la transizione $\delta(q_0',\varepsilon,Z_0)=\{(q_0',\varepsilon),(q_0,Z_0)\}$

Sia $L$ un linguaggio accettato mediante pila vuota da un automa a pila $\mathcal M=\langle\Sigma,\Gamma,Q,\delta,Z_0,q_0,\emptyset\rangle$, allora esiste una grammatica non contestuale $\mathcal G$ che lo genera, cioè $L=N(\mathcal M)=L(\mathcal G)$

La dimostrazione è costruttiva: a partire da $\mathcal M$ deriviamo $\mathcal G$ e mostriamo poi l'equivalenza

Definiamo 
$$V_N=\{[q_i,A,q_j]:\forall q_i,q_j\in Q,A\in\Gamma\}\cup\{S\}$$
dove S è l'assioma:

- **Idea di base**: $[q_i,A,q_j]\xRightarrow[\mathcal G]{\star}\sigma\iff (q_i,\sigma,A)\vdash_{\mathcal M}^\star(q_j\varepsilon,\varepsilon)$
- quindi $[q_i,A,q_j]\xRightarrow[\mathcal G]{\star}\sigma$ se e solo se $\mathcal M$, a partire dalla configurazione $(q_i,\sigma,A)$, può raggiungere (per una sequenza opportuna di scelte) la configurazione $(q_j,\varepsilon,\varepsilon)$

Definiamo le produzioni $P$ nel modo seguente:

1. per ogni $q\in Q$: $S\to[q_0,Z_0,q]\in P$
	1. **per ipotesi**, $[q_0,Z_0,q]\xRightarrow[\mathcal G]{\star}\sigma$ se e solo se $\mathcal M$, a partire dalla configurazione $(q_0,\sigma,Z_0)$, può raggiungere (per una sequenza opportuna di scelte) la configurazione $(q,\varepsilon,\varepsilon)$ e quindi se $\mathcal M$ accetta $\sigma$ per **pila vuota** (q è lo stato in cui $\mathcal M$ si viene a trovare)
	2. quindi $S\xRightarrow[]{}[q_0,Z_0,q]\xRightarrow[]{\star}\sigma$ se e solo se $\mathcal M$ accetta $\sigma$ e quindi $\sigma\in L(\mathcal G)\iff\sigma\in N(\mathcal M)$

2. per ogni $q\in Q,A\in\Gamma,a\in\Sigma\cup\{\varepsilon\}$: se $(q',\varepsilon)\in\delta(q,a,A)$ allora $[q,A,q']\to a\in P$
	1. **mantiene l'ipotesi**, in quanto $[q,A,q']\xRightarrow[]{\star}a$ e $\mathcal M$, a partire da $(q,A,a)$, può raggiungere la configurazione $(q',\varepsilon,\varepsilon)$

3. per ogni $q\in Q,A\in\Gamma,a\in\Sigma\cup\{\varepsilon\}$: se $(q',B_1...B_m)\in\delta(q,a,A)$ allora $[q,A,q_{i_m}]\to a[q'B1q_{i_1}][q_{i_1}B_2q_{i_2}]...[q_{i_m-1}B_mq_{i_m}]\in P$. Per ogni possibile sequenza $q_{i_1},...,q_{i_m}$ di m stati (non distinti) in Q:
	1. **Ipotesi**: $[q,A,q_{i_m}]\xRightarrow[\mathcal G]{\star}\sigma$ se e solo se $\mathcal M$, a partire da $(q,\sigma,A)$, può giungere a $(q_{i_m},\varepsilon,\varepsilon)$
	2. Consideriamo il caso in cui il primo passo di $\mathcal M$ è $\delta(q,a,A)=(q',B_1...B_m)$: allora $\mathcal M$ potrà raggiungere $(q_{i_m},\varepsilon,\varepsilon)$ soltanto attraverso una sequenza di passi di cui la prima parte (leggendo una stringa $\sigma_1$ e giungendo a uno stato $q_{i_1}$) porterà all'eliminazione di $B_1$ dallo stack, la seconda (leggeno una stringa $\sigma_2$ e giugnendo a uno stato $q_{i_2}$) all'eliminazione di $B_2$ e così via

Quindi, si ha che:

- $\mathcal M$ può passare da $(q_{i_{k-1}},\sigma_kB_k)$ a $(q_{i_k},\varepsilon,\varepsilon)$ per $k=1,..,m$
- $\sigma=a\sigma_1\sigma_2\sigma_m$

Corrispondentemente, la grammatica $\mathcal G$ può generare $\sigma$ a partire da $[q,A,q_{i_m}]$ producendo in un passo la frase $a[q'B_1q_{i_1}][q_{i_1}B_2q_{i_2}]...[q_{i_{m-1}}B_mq_{i_m}]$ e utilizzando le derivazioni $[q_{i_{k-1}}B_kq_{i_k}]\xRightarrow[]{\star}\sigma_k$

**Esempio totale**

Consideriamo l'automa a pila avente la funzione di transizione:
$$\begin{align}&\delta(q_0,0,Z_0)=\{(q_0,XZ_0)\}\\&\delta(q_0,0,X)=\{(q_0,XX)\}\\&\delta(q_0,1,X)=\{(q_1,\varepsilon)\}\\&\delta(q_1,1,X)=\{(q_1,\varepsilon)\}\\&\delta(q_1,\varepsilon,X)=\{(q_1,\varepsilon)\}\\&\delta(q_1,\varepsilon,Z_0)=\{(q_1,\varepsilon)\}\end{align}$$
Le produzioni iniziali della grammatica saranno:
$$\begin{align}&S\to[q_0Z_0q_0]\\&S\to[q_0Z_0q_1]\end{align}$$
Da $\delta(q_0,0,Z_0)=\{(q_0,XZ_0)\}$:
$$\begin{align}&[q_0Z_0q_0]\to 0[q_0Xq_0][q_0Z_0q_0]\\&[q_0Z_0q_0]\to 0[q_0Xq_1][q_1Z_0q_0]\\&[q_0Z_0q_1]\to 0[q_0Xq_0][q_0Z_0q_1]\\&[q_0Z_0q_1]\to 0[q_0Xq_1][q_1Z_0q_1]\end{align}$$
Da $\delta(q_0,0,X)=\{(q_0,XX)\}$:
$$\begin{align}&[q_0Xq_0]\to 0[q_0Xq_0][q_0Xq_0]\\&[q_0Xq_0]\to 0[q_0Xq_1][q_1Xq_0]\\&[q_0Xq_1]\to 0[q_0Xq_0][q_0Xq_1]\\&[q_0Xq_1]\to 0[q_0Xq_1][q_1Xq_1]\end{align}$$
Poi, tutte le altre saranno:
$$\begin{align}&[q_0Xq_1]\to1\\&[q_1Xq_1]\to1\\&[q_1Xq_1]\to\varepsilon\\&[q_1Z_0q_1]\to\varepsilon\end{align}$$
Portata poi in forma ridotta, la grammatica risultate sarà:
$$\begin{align}&S\to 0[q_0Xq_1][q_1Z_0q_1]\\&[q_0Xq_1]\to 0[q_0Xq_1][q_1Xq_1]\:|\:1\\&[q_1Xq_1]\to1|\varepsilon\\&[q_1Z_0q_1]\to\varepsilon\end{align}$$
L'equivalenza deriva dalla dimostrazione che 
$$[q,A,q']\xRightarrow[]{\star}x\iff(q,x,A)\vdash^\star(q',\varepsilon,\varepsilon)$$
da cui otteniamo come caso particolare, che $[q_0Z_,q']\xRightarrow[]{\star}x\iff(q_0,x,Z_0)\vdash^\star(q',\varepsilon,\varepsilon)$ per qualche $q'$, cioè se e solo se l'automa accetta la stringa x per pila vuota

**Esempio**

Accettazione/produzione della stringa 00011

![[appunti fi/mod i/immagini/Pasted image 20221228125503.png|center|650]]

# Automi a pila deterministici

Un automa a pila **deterministico** è un automa a pila $\mathcal M=\langle\Sigma,\Gamma,Z_0,Q,q_0,F,\delta\rangle$ tale che, $\forall a\in\Sigma,\forall Z\in\Gamma,\forall q\in Q$, si ha che 
$$|\delta(q,a,Z)|+|\delta(q,\varepsilon,Z)|\leq1$$
Una stringa è accettata da un automa a pila deterministico se e solo se essa da luogo ad una computazione che termina in una configurazione $\langle q,\varepsilon,\omega\rangle$, con $q\in F,\omega\in\Gamma^\star$ 

1. La definizione di automa a pila deterministico è una **specializzazione** della definizione di automa a pila non deterministico, quindi la classe dei linguaggi accettati da automi a pila non deterministici include quella dei linguaggi accettati da automi a pila deterministici.
2. La classe dei linguaggi di tipo 2, vale a dire dei linguaggi accettati da automi a pila non deterministici, non è chiusa rispetto alla complementazione.
3. Per ogni automa a pila deterministico $\mathcal M$, è possibile costruirne uno che accetta il linguaggio $\Sigma^\star-L(\mathcal M)$: quindi classe dei linguaggi accettati da automi a pila deterministici è chiusa rispetto alla complementazione
4. Quindi, la classe dei linguaggi accettati da automi a pila deterministici dunque non coincide con quella dei linguaggi di tipo 2

Intuitivamente, un linguaggio separatore è dato da $L = \{w\hat w | w\in\{a,b\}^+ \}$

Il linguaggio, di tipo 2, non può essere accettato da alcun automa a pila deterministico. Infatti,intuitivamente, durante la scansione dell’input non è possibile individuare a priori, in maniera deterministica, dove termina la stringa $w$ ed inizia $\hat w$.

