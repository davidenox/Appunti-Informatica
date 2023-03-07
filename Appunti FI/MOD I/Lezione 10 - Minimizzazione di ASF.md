# Minimizzazione di ASF

L'ASFD con minimo numero di stati che riconosce un dato linguaggio $L$ può essere derivato partizionando l'insieme $Q$ degli stati in un automa che riconosce $L$ in classi di equivalenza rispetto alla relazione
$$q_i\equiv q_j\iff(\forall x\in\Sigma^\star,\overline\delta(q_i,x)\in F\iff\overline\delta(q_j,x)\in F)$$
Quindi, $q_i\equiv q_j$ se e solo se ogni stringa che porta da $q_i$ ad uno stato finale porta anche da $q_j$ ad uno stato finale (e vice versa)


>[!Info]
>$\equiv$ è una relazione di equivalenza

Se $q_i\equiv q_j$ i due stati sono detti **indistinguibili**

Se esiste una stringa $x\in\Sigma^\star$ per cui $\overline\delta(q_i,x)\in F\:e\:\overline\delta(q_j,x)\in Q-F$ (o viceversa) diremo che $q_i,q_j$ sono **distinguibili** tramite x

La costruzione è basata sul teorema di Myhill-Nerode

>[!important]- Teorema Myhill-Nerode
>Dato un linguaggio $L$ definiamo la relazione di equivalenza $R_L$ su $\Sigma^\star$ come:$$xR_Ly\iff(\forall z\in\Sigma^\star,xz\in L\iff yz\in L)$$
>Un linguaggio $L\subseteq\Sigma^\star$ è regolare se e solo se $R_L$ partiziona $\Sigma^\star$ in un numero finito di classi di equivalenza

Dato un linguaggio regolare $L$ definiamo un ASF $\mathcal A'=\langle\Sigma,Q',\delta',q_0',F'\rangle$, dove:

1. $Q'$ associa a ogni classe di equivalenza $[x]$ di $\Sigma^\star$ uno stato $q_{[x]}$
2. $q_0'=q_{[\varepsilon]}$
3. $F'=\lbrace q_{[x]}|x\in L\rbrace$
4. $\delta'(q_{[x]},a)=q_{[xa]}\:\forall a \in\Sigma$

Si può notare che $\forall z\in[x]:\overline\delta'(q_0',z)=q_{[x]}$. Quindi:

- l'insieme delle stringhe che portano l'automa dallo stato iniziale allo stato finale $q_{[x]}$ corrisponde all'insieme delle stringhe (equivalenti secondo $R_L$) in $[x]$. Dalla definizione di $F'$ ne consegue immediatamente che $\mathcal A'$ riconosce $L$
- $Q'$, pari al numero di classi di equivalenza di $R_L$ è il minimo numero di classi in cui è possibile partizionare $\Sigma^\star$ in modo tale che valga la proprietà $\forall z\in\Sigma^\star,xz\in L\iff yz\in L$ se $xR_Ly$

>$Q'$ è minimo

_Dim_
Se così non fosse, esisterebbero due stringhe x,y non equivalenti rispetto a $R_L$, per cui $\overline\delta'(q_0',x)=\overline\delta'(q_0',y)=q$. Ma allora ne seguirebbe che $\forall z\in\Sigma:\overline\delta'(q_0',xz)=\overline\delta'(q_0',yz)$, il che comporterebbe allora che $xR_Ly$, contrariamente all'ipotesi
$\square$

Minimizzazione di un ASFD

- Individuazione di tutte le coppie di stati indistinguibili (mediante un algoritmo di marcatura delle coppie distinguibili)
- Unificazione degli stati equivalenti, eliminando quelli non raggiungibili e modificando opportunamente la funzione di transizione

Ipotesi:

Tutti gli stati di $\mathcal A$ sono raggiungibili dallo stato iniziale, altrimenti è necessario un passo preliminare di eliminazione degli stati irraggiungibili

- Per marcare le coppire di stati distinguibili si utilizza una tabella contenente una casella per ciascuna coppia (non ordinata) di stati di $Q$
- Le caselle vengono usate per marcare le coppie di stati distinguibili e per elencare, in una lista associata, tutte le coppie che dovranno essere marcate qualora la coppia a cui è associata la casella venga marcata

La procedura inizia con la marcatura delle coppie distinguibili tramite la stringa $\varepsilon$ (tutte e sole le coppie costituite da uno stato finale e da uno non finale)
Per ogni coppia $(p,q)$ non ancora marcata, si considerano, per ogni $q\in\Sigma$, tutte le coppie $(r,s)$, con $r=\delta(p,)\:e\:s=\delta(q,a)$
- Se nessuna delle coppie $(r,s)$ è marcata come distinguibile allora si inserisce $(p,q)$ nella lista associata ad ognuna di esse
- Altrimenti p e q veongono riconosciuti distinguibili e la corrispondente casella viene marcata; qualora questa contenga una lista di coppie si procede (ricorsivamente) con la marcatura delle relative caselle

![[appunti fi/mod i/immagini/Pasted image 20221117125800.png|center|600]]

Una volta identificate le coppie di stati indistinguibili, ricordando che la relazione di indistinguibilità è una relazione di equivalenza, l'automa equivalente con il minimo numero di stati è dato evidentemente da $\mathcal A'=\langle\Sigma,Q',\delta',q_0',F'\rangle$, in cui:

1. $Q'$ è costruito selezionando, per ogni insieme di stati indistinguibili, uno ed un solo stato $Q$ (rappresentante)
2. $F'$ è costruito da tutti i rappresentanti appartenenti a $F$
3. $\delta'$ è ottenuta da $\delta$ mediante restrizione al dominio $Q'\times\Sigma$ ed inoltre, per ogni $\delta(q_i,a)=q_j$, con $q_i\in Q'\:e\:q_j\in Q$, poniamo $\delta'(q_i,a)=q_k$, dove $q_k\in Q'$ è il rappresentante dell'insieme di stati indistinguibili che include $q_j$ (chiaramente, se $q_j\in Q'$ allora è esso stesso un rappresentante e dunque $q_k=q_j$)

**Esempio**

![[appunti fi/mod i/immagini/Pasted image 20221117131616.png|center|600]]

**Passo inziale**: $q_0,q_1$, finali, distinguibili da tutti gli altri

Tutte le coppie in cui uno dei stati è $q_o\:o\:q_1$ e l'altro non è $q_o\:o\:q_1$ sono marcate 

![[appunti fi/mod i/immagini/Pasted image 20221117131847.png|center|600]]

Consideriamo le coppie di stati scandendo le celle da sinistra verso destra e dall'alto verso il basso
$(q_0,q_1)$ è distinguibile se lo è la coppia $(q_2,q_5)$, in quanto $\delta(q_0,b)=q_2$ e $\delta(q_1,b)=q_5$: quindi $(0,1)$ inserito nella lista associata

![[appunti fi/mod i/immagini/Pasted image 20221117132358.png|center|600]]

$(q_2,q_3)$ sono distinguibili in quanto $\delta(q_2,a)=q_4$ e $\delta(q_3,a)=q_0$, e la coppia $(q_0,q_4)$ è distinguibile (perchè la cella $(0,4)$ è marcata): quindi viene marcata anche la cella $(2,3)$

![[appunti fi/mod i/immagini/Pasted image 20221117132550.png|center|600]]

Proseguendo, l'algoritmo determina che:

-  la coppia $(q_2,q_4)$ è distinguibile se lo è la coppia $(q_3,q_6)$: $(2,4)$ è inserito nella lista della cella $(3,6)$
- la coppia $(q_3,q_4)$ è distinguibile: la cella viene marcata
- la coppia $(q_2,q_5)$ è distinguibile se lo sono le coppie $(q_2,q_4)$ e $(q_3,q_6)$: $(2,5)$ è inserito nelle liste delle celle $(2,4)$ e $(3,6)$
- la coppia $(q_3,q_5)$ è distinguibile: la cella viene marcata
- la coppia $(q_4,q_5)$ non è distinguibile (perchè se leggo b,partendo da $q_4,q_5$ arrivo sempre in $q_6$, se leggo a partendo da $q_4,q_5$ vado sempre in $q_2$)
- la coppia $(q_2,q_6)$ è distinguibile: la cella viene marcata
- la coppia $(q_3,q_6)$ è distinguibile se lo è la coppia $(q_0,q_1)$: $(3,6)$ è inserito nella lista della cella $(0,1)$
- la coppia $(q_4,q_6)$ è distinguibile: la cella viene marcata
- la coppia $(q_5,q_6)$ è distinguibile: la cella viene marcata

Si ottiene quindi:
![[appunti fi/mod i/immagini/Pasted image 20221117133405.png|center|600]]

Mantenendo le sole indicazioni delle coppie distinguibili e non si ottiene:

![[appunti fi/mod i/immagini/Pasted image 20221117133513.png|center|600]]

Quindi avremo le coppie di stati indistinguibili, che saranno.
- $q_0,q_1$
- $q_2,q_4$ - $q_2,q_5$ - $q_4,q_5$ (oss. la regola di equivalenza rispettata è la transitività)
- $q_3,q_6$
E sono anche 3 classi di equivalenza

A questo punto l'automa equivalente con il minimo numero di stati risultante dal procedimento è mostrato sotto:
lo stato $q_0$ corrisponde alla classe d'equivalenza $\lbrace q_0,q_1\rbrace$, lo stato $q_1$ corrisponde alla classe $\lbrace q_3,q_6\rbrace$ e lo stato $q_3$ corrisponde alla classe $\lbrace q_2,q_4,q_5\rbrace$

e quindi:
![[appunti fi/mod i/immagini/Pasted image 20221117134319.png|center|400]]


# Decidibilità di predicati

>[!important]- Teorema
>è possibile decidere se il linguagio accettato da un dato automa a stati finiti è vuoto

**Osservazione**: se un automa con n stati accetta qualche stringa, allora accetta una stringa di lunghezza inferiore ad n

Sia z la stringa più breve accettata dall'automa, se fosse $|z|\geq n$ allora, in base al pumping lemma, z potrebbe essere scritta come $uvw$ e anche la stringa $uw$, più breve di z, sarebbe accettata dall'automa

Dato un automa $\mathcal A$ con $n=|Q|$ stati e $s=|\Sigma|$ simboli di input, per decidere se $L(\mathcal A)=\Lambda$ basta verificare se $\mathcal A$ accetta almeno una delle
$$\sum_{i=0}^{n-1}s^i=\frac{s^n-1}{s-1}=\Theta(s^{n-1})$$
stringhe di lunghezza inferiore ad n

Il tempo necessario per tale operazione sarà evidentemente proporzionale a :
$$\sum_{i=0}^{n-1}is^i=s\sum_{i=1}^{n}\frac{ds^i}{ds}=s\frac{d}{ds}\sum_{i?1}^{n}s^i=s\frac{d}{ds}\frac{s^n-1}{s-1}=\frac{ns^{n+1}-s^{n+1}+s}{(s-1)^2}=\Theta(s^n)$$
L'algoritmo ha quindi complessità esponenziale

**Osservazione**: dato il grafo di transizione di $\mathcal A,L(\mathcal A)$ è non vuoto se e solo se esiste almeno uno stato finale raggiungibile da $q_0$

Algoritmo polinomiale: visita del grafo di transizione, avente n nodi e $m\leq ns$ archi

La visitia richiede tempo $\Theta(n+m)=\Theta(n)$ lineare nel numero di stati

>[!important]- Teorema
>è possibile decidere se il linguaggio accettato da un dato automa a stati finiti è finito

**Proprietà 1**
Se $\mathcal A$ accetta una z lungha almeno n allora, per il pumping lemma, accetta infinite stringhe

**Proprietà 2**
Se $L(\mathcal A)$ è infinito, allora esiste $z\in L(\mathcal A)$ tale che $n\leq|z|\lt 2n$
- se $L(\mathcal A)$ è infinito esiste chiaramente $z\in L(\mathcal A)$ con $|z|\geq n$, altrimenti $L(\mathcal A)$ sarebbe finito (e composto di stringhe di lunghezza al più n-1)

Assumiamo, senza perdere generalità, che z sia una stringha di lunghezza minima tra tutte le stringhe in $L(\mathcal A)$ lunghe almeno n

Due casi sono possibili:
- $|z|\lt 2n$, e quindi la proprietà è vera
- $|z|\geq 2n$: in questo caso, per il pumping lemma (visto che $|z|\gt n$) possiamo scrivere $z = uvw$, con $1\leq|v|\leq n$. Per il pumping lemma, $uw\in L(\mathcal A)$ e $|uw|\lt|uvw|$: data l'ipotesi che z abbia lunghezza minima tra tutte le stringhe di $L(\mathcal A)$ lunghe almeno n, ne consegue che deve essere $|uw|\lt n$. Ma questo è impossibile, in quanto $|uw|=|z|-|v|\geq 2n-n=n$ in quanto per ipotesi $|z|\geq 2n$ e $|v|\leq n$. Ne deriva che la stringa in $L(\mathcal A)$ di lunghezza minima tra tutte quelle linghe almeno n non può essere lunga di 2n o più, e quindi la proprietà è vera

In conclusione: $L(\mathcal A)$ è infinito se e solo se esiste una stringa $z\in L(\mathcal A)$ tale che $n\leq|z|\lt 2n$

Dato un automa $\mathcal A$ con $n=|Q|$ stati e $s=|\Sigma|$ simboli di input, per decidere se $L(\mathcal A)$ è infinito basta verificare se $\mathcal A$ accetta almeno una delle
$$\sum_{i=n}^{2n-1}s^i=\sum_{i=0}^{2n-1}s^i-\sum_{i=0}^{n-1}s^i=\frac{(s^{2n}-1)-(s^n-1)}{s-1}=\Theta(s^{2n-1})$$
stringhe di lunghezza compresa tra n e 2n

Applicando le stesse considerazioni viste sopra il tempo necessario per tale operazione sarà evidentemente proporzionale a :
$$\sum_{i=n}^{2n-1}is^i=\sum_{i=0}^{2n-1}is^i-\sum_{i=0}^{n-1}is^i=...=\Theta(s^{2n})$$
L'algoritmo ha quindi complessità esponenziale

**Osservazione**: dato il grafo di transizione di $\mathcal A,L(\mathcal A)$ è infinito se e solo se esiste almeno un ciclo a partire da uno stato su un cammino da $q_0$ a uno stato finale

Algoritmo polinomiale: visita del grafo di transizione, avente n nodi e $m\leq ns$ archi

La visita richiede tempo $\Theta(m+n)=\Theta(n)$ lineare nel numero di stati


Dalla possibilità di deidere se un linguaggio regolare è vuoto, ne deriva immediatamente la decidibilità di altri predicati sui linguaggi regolari

>[!important]- Teorema
>Il problema dell'equivalenza di due linguaggi regolari è decidibile

Per dimostrare l'equivalenza tra due linguaggi, basta dimostrare che la loro intersezione coincide con la loro unione, cioè che la loro differenza simmetrica (l'unione dell'intersezione del primo con il complemento del secondo e l'unione dell'intersezione del secondo con il complemento del primo) è il linguaggio vuoto
