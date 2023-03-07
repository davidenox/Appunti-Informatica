# Macchine di Turing a nastro singolo

Dispositivo che accede ad un **nastro** potenzialmente illimitato diviso in celle contenenti ciascuna un simbolo appartenente a un alfabeto $\Gamma$, ampliato con il carattere speciale $\square$ (blank)  che rappresenta la situazione di cella non contenente caratteri.

All'inizio del calcolo solo una porzione finita del nastro contiene simboli di $\Gamma$. La macchina di Turing opera su tale nastro tramite una testina, la quale può scorrere su di esso in entrambe le direzioni.
Su ogni cella la testina può leggere o scrivere caratteri appartenenti all'alfabeto $\Gamma$ oppure il simbolo $\square$

![[appunti fi/mod i/immagini/Pasted image 20230109112412.png|center|500]]

## Macchina di Turing deterministica

Sestupla $\mathcal M=\langle\Gamma,\square,Q,q_0,F,\delta\rangle$ dove:
- $\Gamma$: alfabeto dei simboli di nastro
- $\square\not\in\Gamma$: carattere speciale denominato **blank**
- $Q$: insieme finito e non vuoto di **stati**
- $q_0\in Q$: **stato iniziale**
- $F\subseteq Q$: insieme degli **stati finali**
- $\delta$: funzione di transizione definita come $$\delta:(Q-F)\times(\Gamma\cup\{\square\})\to Q\times(\Gamma\cup\{\square\})\times(\to,\leftarrow,\circ)$$ in cui $\to,\leftarrow,\circ$ indicano rispettivamente, lo spostamento a destra, a sinistra o l'immobilità della testina

**Esempio**

![[appunti fi/mod i/immagini/Pasted image 20230109121029.png|center|500]]

### DTM (Deterministic Turing Machine)

- DTM utilizzabili per il calcolo di funzioni, o per riconoscere o accettare stringhe su un alfabeto di input $\Sigma\subseteq\Gamma$
- DTM usate per accettare stringhe vengono dette di tipo _riconoscitore_
- DTM usare per calcolare funzioni vengono dette di tipo _trasduttore_
- In entrambi i casi, all'inizio del calcolo, solo una porzione finita del nastro contiene simboli diversi da blank che costituiscono l'input del calcolo stesso

#### Configurazione di una DTM

SI definisce configurazione istantaneta o configurazione di una macchina di Turing con alfabeto di nastro $\Gamma$ ed insieme degli stati $Q$, una stringa $c=xqy$, con (assumendo $\overline\Gamma=\Gamma\cup\{\square\}$):

1. $x\in\Gamma\overline\Gamma^\star\cup\{\varepsilon\}$
2. $q\in Q$
3. $y\in\overline\Gamma^\star\Gamma\cup\{\square\}$

L'interpretazione data ad una stringa $xqy$ è che $xy$ rappresenti il contenuto della sezione non vuota del nastro, che lo stato attuale sia $q$ e che la testina sia posizionata sul primo carattere di $y$. Nel caso in cui $x=\varepsilon$ abbiamo che a sinistra della testina compaiono solo simboli $\square$, mentre se $y=\square$ sulla cella attuale e a destra della testina compaiono soltanto simboli $\square$

##### Configurazione iniziale

La configurazione iniziale di MT rispetto a una stringa di input $\sigma$ prevede che:

- il nastro contenga la stringa $\sigma$ in una sequenza di celle
- tutte le altre celle del nastro siano vuote (contengano $\square$)
- lo stato attuale sia lo stato iniziale $q_0$
- la testina si trovi sulla cella contenente il primo carattere di $\sigma$

Una configurazione $xqy$ è quindi iniziale se $x=\varepsilon,q=q_0,y=\sigma$

##### Configurazione finale

Una configurazione $c=xqy$ si dice **finale** se $q\in F$

Quindi, una macchina di Turing si trova in una configurazione finale se il suo stato attuale è lo stato finale, indipendentemente dal contenuto del nastro e dalla posizione della testina

#### Matrice di transizione

La funzione di transizione può essere rappresentata mediante **matrici di transizione** e **grafi di transizione**

**Esempio**

![[appunti fi/mod i/immagini/Pasted image 20230110110553.png|center|500]]

In generale, assumiamo che uno stato finale non abbia transizioni uscenti definite.

#### Grafo di transizione

![[appunti fi/mod i/immagini/Pasted image 20230110110701.png|center|600]]

**Esercizio**

Considerata la macchina di Turing deterministica definita sopra e assumendo la configurazione iniziale $q_010$:

1. determinare la computazione effettuata dalla macchina, indicando la configurazione finale che viene raggiunta
2. descrivere informalmente il comportamento della macchina su un input generico

#### Accettazione e rifiuto di stringhe

- **Computazione massimale**: computazione che non può prolungarsi (non esistono transizioni applicabili alla configurazione raggiunta)
- **Computazione di accettazione**: computazione massimale che termina in una configurazione finale
- **Computazione di rifiuto**: computazione massimale che si conclude in una configurazione non finale

Dato un alfabeto di input $\Sigma\subseteq\Gamma$, una stringa $x\in\Sigma^\star$ è _accettata (rifiutata)_ da una MT $\mathcal M$ se esiste una computazione di accettazione (di rifiuto) di $\mathcal M$ con $c_0=q_0x$

- Terza possibilità: non esiste alcuna computazione massimale con $c_0=q_0x$; in altre parole, la computazione di $\mathcal M$ su input x non termina

Data una MT $\mathcal M$ con alfabeto di input $\Sigma$, l'insieme $\Sigma^\star$ è partizionato in tre linguaggi:

- L'insieme $L(\mathcal M)$ delle stringhe **accettate** da $\mathcal M$
- L'insieme $\overline L(\mathcal M)$ delle stringhe **rifiutate** da $\mathcal M$
- L'insieme $\Sigma^\star-(L(\mathcal M)\cup\overline L(\mathcal M))$ delle stringhe sulle quali la computazione effettuata da $\mathcal M$ non termina

**Definizioni equivalenti**

1. esistono due soli stati finali, $q_1,q_2$, tutte le computazioni massimmali terminano in uno stato finale ed una stringa x è accettata se $q_0x\vdash_{\mathcal M}^\star wq_1z$, mentre è rifiutata se $q_0x\vdash_{\mathcal M}^\star wq_2z$
2. esiste un solo stato finale $q_F$, l'alfabeto di nastro contiene due simboli speciali $Y,N\not\in\Sigma$ (Y=yes, N=no), tutte le computazioni massimali terminano nello stato finale ed una stringa x è accettata se $q_0x\vdash_{\mathcal M}^\star q_FY$, mentre è rifiutata se $q_0x\vdash_{\mathcal M}^\star q_FN$

#### Riconoscimento di linguaggi

- Data una MT deterministica $\mathcal M=\langle\Gamma,\square,Q,q_0,F,\delta\rangle$ 
- Dato un alfabeto di input $\Sigma\subseteq\Gamma$
- $\mathcal M$ **riconosce (decide)** un linguaggio $L\in\Sigma^\star$ se e solo se per ogni $x\in\Sigma^\star$:
	- esiste una computazione massimale $q_0x\vdash_{\mathcal M}^\star wqz$
	- $q\in F$ se e solo se $x\in L$
	- $w\in\Gamma\overline\Gamma^\star\cup\{\varepsilon\}$ e $z\in\overline\Gamma^\star\Gamma\cup\{\square\}$ rappresentano il contenuto delle porzioni di nastro significative prima e dopo la posizione della testina
- Afficnhè un linguaggiosia riconosciuto, $\mathcal M$ deve fermarsi per ogni $x\in\Sigma^\star$

#### Accettazione di linguaggi

- Data una MT deterministica $\mathcal M=\langle\Gamma,\square,Q,q_0,F,\delta\rangle$ 
- Dato un alfabeto di input $\Sigma\subseteq\Gamma$
- $\mathcal M$ **accetta** un linguaggio $L\in\Sigma^\star$ se e solo se: $L=\{x\in\Sigma^\star|q_0x\vdash_{\mathcal M}^\star wqz;q\in F\}$
- Quindi, L è l'insieme delle stringhe per le quali la computazione effettuata da $\mathcal M$ temrina in uno stato finale
- Che succede per $x\not\in L?$ La computazione effettuata da $\mathcal M$ può:
	- terminare in uno stato $q\in Q-F$
	- non terminare

### Turing-decidibilità

- Un linguaggio $L$ è detto **Turing-decidibile** se esiste una DTM che lo riconosce
- Un linguaggio $L$ è detto **Turing-semidecidibile** se esiste una DTM che lo accetta

# Macchine di Turing a più nastri

Una MTM (**Multi-tape Turing Machine**) a k nastri ($k\geq2$) è una sestupla $\mathcal M^{(k)}=\langle\Gamma,\square,Q,q_0,F,\delta^{(k)}\rangle$ 
dove:

- $\Gamma=\bigcup_{i=1}^{(k)}\Gamma_i$ è l'unione dei k **alfabeti di nastro** $\Gamma_1,...,\Gamma_k$ non necessariamente distinti
- $Q,q_0,F$ hanno lo stesso significato che nel caso della macchina di Turing ad 1 nastro 
- la funzione di transizione $\delta^{(k)}$ è definita come: $$\delta^{(k)}:(Q-F)\times\overline\Gamma[1]\times...\times\overline\Gamma[k]\times\{\to,\leftarrow,\circ\}^k$$
Una $\mathcal M$ esegue una transizione a partire da uno stato interno $q_i$ e con le k testine - una per nastro - posizionate sui caratteri $a_{i_1},...,a_{i_k}$

Se $\delta^{(k)}(q_i,a_{i_1},...,a_{i_k})=(q_j,a_{j_1},...,a_{j_k},z_{j_1},...,z_{j_k})$:
- si porta nello stato $q_j$
- scrive i caratteri $a_{j_1},...,a_{j_k}$ sui rispettivi nastri
- fa compiere alle testine i rispettivi spostamenti - a destra, a sinistra o nessuno spostamento, come specificato dagli $z_{j_l}\in\{\to,\leftarrow,\circ\},l=1,...,k$

## Configurazioni di MTM

Una _**configurazione istantaneta**_ di una macchina di Turing multinastro può essere rappresentata da una stringa del tipo 
$$q\#\alpha_1\uparrow\beta_1\#\alpha_2\uparrow\beta_2\#...\#\alpha_k\uparrow\beta_k$$
- q è lo stato attuale
- il contenuto significativo del nastro $T_k$ è $\alpha_k\beta_k$
- la testina del nastro $T_k$ è posizionata sulla cella contenente il primo carattere di $\beta_k$

Una configurazione di una MTM è:
- **finale**, se $q\in F$, quindi se lo stato attuale è finale, indipendentemente dal contenuto dei nastri
- **iniziale** (con stringa di input x) se $q=q_0,\alpha_i=\varepsilon,i=1,...,k,\beta_1=x,\beta_i=\square,i=2,...,k$, quindi se il primo nastro contiene l'input con la testina sul primo carattere, e gli altri nastri sono vuoti

**Esempio**

Riconoscimento di $L=\{xc\hat x,x\in\{a,b\}^+\}$

![[appunti fi/mod i/immagini/Pasted image 20230116151522.png|center|500]]

Sul nastro di lavoro deve esserci $\square$

- Operazioni:
	1. input scandito da sx verso dx fino a quando si incontra il separatore c: simboli copiato sul nastro di lavoro da sx a dx
	2. resto dell'input scandito da sx verso dx, nastro di lvaoro scandito da dx verso sx, confrontando i caratteri in input con quelli presenti sul nastro di lavoro
- Alfabeto di input $\Sigma=\{a,b,c\}$
- Alfabeto del nastro di lavoro è $\Gamma=\{a,b\}$
- Configurazione iniziale: $q_0\#\uparrow xc\hat x\#\uparrow\square$
- Tre stati: $q_0$ (scansione di x), $q_1$ (scansione di $\hat x$), $q_2$ stato finale. Quindi $Q=\{q_0,q_1,q_2\}$ e $F=\{q_2\}$

Funzione di transizione:

- Lettura e copiatura di x: $\delta(q_0,a,\square)=(q_0,a,a,\to,\to),\delta(q_0,b,\square)=(q_0,b,b,\to,\to)$
- Lettura separatore: $\delta(q_0,c,\square)=(q_1,c,\square,\to,\leftarrow)$
- Lettura e verifica di $\hat x$:
	- Caratteri uguali sui due nastri $\delta(q_1,a,a)=(q_1,a,a,\to,\leftarrow),\delta(q_1,b,b)=(q_1,b,b,\to\leftarrow)$
	- Caratteri diversi sui due nastri: in questo caso la stringa non viene accettata. Nessuna transizione definita
- Terminazione della verifica: $\delta(q_1,\square,\square)=(q_2,\square,\square,\circ,\circ)$

Computazioni massimali corrispondenti ai due input $bacab$ e $acb$.

![[appunti fi/mod i/immagini/Pasted image 20230118144127.png|center|200]]

## Equivalenza tra MTM e MT

è possibile dimostrare l'equivalenza tra MTM e MT:
- per ogni MT $\mathcal M$ esiste una MTM $\mathcal M'$ equivalente, tale cioè che $L(\mathcal M)=L(\mathcal M')$ (si tratta della stessa $\mathcal M$)
- per ogni MTM $\mathcal M$ esiste una MT $\mathcal M'$ equivalente, tale cioè che $L(\mathcal M)=L(\mathcal M')$
	- dimostrazione mediante **simulazione** di $\mathcal M'$ su $\mathcal M$: mostrando come ad ogni computazione di $\mathcal M$ corrisponda una computazione di $\mathcal M'$ con stesso esito (accettazione, rifiuto, non termina)

## Macchina di Turing non deterministica

Una macchina di Turing non deterministica (NDTM) $\mathcal M$ a k nastri è una sestupla $\mathcal M=\langle\Gamma,\square,Q,q_0,F,\delta_N\rangle$, in cui:

- $\Gamma=\bigcup_{i=1}^k\Gamma_i$
- $\delta_N$ è una funzione parziale: $$\delta_N:(Q-F)\times\overline\Gamma_1\times...\times\overline\Gamma_k\to\mathcal P(Q\times\overline\Gamma_1\times...\times\overline\Gamma_k\times\{\to,\leftarrow,\circ\}^k)$$
**Esempio di NDTM**

Consideriamo una macchina di Turing non deterministica avente $\Gamma=\{a,b,c,d\},Q=\{q_0,...,q_{11}\},F=\{q_{11}\}$ e funzione di transizione definita in questo modo 

![[appunti fi/mod i/immagini/Pasted image 20230118145343.png|center|600]]

La macchina di Turing $\mathcal M$:

- ha grado di non determinismo 2
- data una stringa di input $x\in\{a,b\}^\star$, la accetta se e solo se esiste una stringa $y\in\{a,b\}^\star$ con $|y|\geq2$ tale che $x=uyyv$, con $u,v\in\{a,b\}^\star$


### Equivalenza tra MT e MTND

è possibile dimostrare l'equivalenza tra MTM e MT:
- per ogni MT $\mathcal M$ esiste una MTND $\mathcal M'$ equivalente, tale cioè che $L(\mathcal M)=L(\mathcal M')$ (si tratta della stessa $\mathcal M$)
- per ogni MTND $\mathcal M$ esiste una MT $\mathcal M'$ equivalente, tale cioè che $L(\mathcal M)=L(\mathcal M')$
	- dimostrazione mediante **simulazione** di $\mathcal M'$ su $\mathcal M$: mostrando come ad ogni computazione di $\mathcal M$ corrisponda una computazione di $\mathcal M'$ con stesso esito (accettazione, rifiuto, non termina).

# Linguaggi di tipo 0 e Macchine di Turing

>[!important]- Teorema
>Se $\mathcal G$ è una grammatica di tipo 0 e $L=L(\mathcal G)$ è il linguaggio da essa generato, esiste una macchina di Turing non deterministica a due nastri $\mathcal M_L$ che accetta $L$

Sia $\mathcal G=\langle V_N,V_T,P,S\rangle$, la macchina $\mathcal M_L$ opera nel seguente modo.

- Data una stringa $w\in V_T^\star$, la configurazione iniziale di $\mathcal M_L$ è $q_0\#\uparrow w\#\uparrow S$ 
- Ad ogni passo, in modo non deterministico $\mathcal M_L$ applica sulla forma di frase $\phi$ presente sul secondo nastro tutte le possibili produzioni in P, rimpiazzando $\phi$ con una nuova forma di frase $\phi'$ derivabile da $\phi$. Quindi verifica se $\phi'$ coincide con $w$: solo se la verifica da esito positivo la macchina entra in uno stato finale di accettazione

Corollario:
I linguaggi di tipo 0 sono **Turing-semidecidibili**

Lo stesso approccio mostrato sopra può essere applicato in una MT che **genera**, una dopo l'altra, tutte le stringhe generate da $\mathcal G$, di tipo 0

Dato un linguaggio di tipo 0 esiste una MT che produce una dopo l'altra (enumerata) tutte e sole le stringhe del linguaggio 

I linguaggi di tipo 0 sono **ricorsivamente enumerabili**

>[!important]- Teorema
>Se $\mathcal M$ è una macchina di Turing che accetta il linguaggio $L$ allora esiste una grammatica $\mathcal G_L$ di tipo tale che $L=L(\mathcal G)$

# Linguaggi di tipo 1 e Macchine di Turing

Cosa possiamo dire rispetto ai linguaggio di tipo 1?

Vale il seguente teorema

>[!important]- Teorema
>Se $\mathcal G$ è una grammatica di tipo 1 e $L=L(\mathcal G)$ è il linguaggio da essa generato, esiste una macchina di Turing deterministica $\mathcal M_L$ che accetta $L$ utilizzando un numero di celle di nastro al più pari a kn, dove n è la lunghezza della stringa e k una costante (**Lineare Bounded Automaton,**LBA)

**Osservazione**: 
- Il LBA utilizza al più $L=kn$ celle di nastro: ne deriva che il numero di possibili configurazioni dell'automa è finito e al più pari a $$N=|\overline\Gamma|^L|Q|L$$
- Una computazione dell'automa più lunga di N necessariamente attraversa la stessa configurazione per due volte, e quindi successivamente un numero infinito di volte
- è possibile verificare se l'automa non si ferma su un determinato input semplicemente osservando se la relativa computazione è più lunga di N passi
- L'appartenenza di una stringa a un linguaggio CS è un problema Turing-decidibile

Vale anche il contrario

>[!important]- Teorema
>Se $\mathcal M$ è un LBA che accetta il linguaggio $L$ allora esiste una grammatica $\mathcal G_L$ di tipo 1 tale che $L=L(\mathcal G_L)$

