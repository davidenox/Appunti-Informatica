# Verifica delle identità polinomiali

**Problema**: Verificare che $P(x)\equiv Q(x)$.
**Es.** Verificare se $$(x+1)(x-2)(x+3)(x+5)(x-6)\equiv x^6 - 7x^3 +25$$
Utilizziamo "$\equiv$" per le identità polinomiali, "$=$" per le uguaglianze numeriche.
$P(x)\equiv Q(x)\iff\forall r\in R,P(r)=Q(r)$ 

La soluzione deterministica sarebbe quella di sviluppare $P(x)$ e verificare che sia identico a $Q(x)$.

## Soluzione Randomizzata
1. Scegliere un intero randomico $r$ nel range $[1,...,600]$.
2. Computare $H(r)$ e $G(r)$.
3. Se $H(r)=G(r)$ allora rispondi **CORRECT** altrimenti *FALSE*

# Algoritmo randomizzato

*Scegliere un numero randomico uniformemente dal set* $\{a_1,a_2,...,a_k\}$. Assumiamo che questa operazione costi $1$ step.

L'output potrebbe dipendere dalla scelta di $r$, quindi è una **variabile casuale**.

*Qual è la "possiblità" che l'algoritmo dia effettivamente la risposta corretta?*
$$\begin{align}\\& H(x)\equiv (x+1)(x-2)(x+3)(x+5)(x-6) \\& G(x)\equiv x^6 - 7x^3 +25  \end{align}$$
Assumendo che $r=2$, $H(2)=0$, mentre $G(2)=33$. Quindi dato che $H(2)\neq G(2)$ allora $H(x)\not\equiv G(x)$ .

**Cosa succede se avessimo un'uguaglianza?**
Es. $(x+1)(x-1)\equiv x^2 -1$ 
Potrebbero esserci scelte di  $r$ che danno esito corretto ($r=1$) ed altre che danno esito errato ($r=2$), quindi*una scelta sbagliata di $r$ potrebbe dare una risposta errata*.
Quante delle possibili scelte di $r$ sono sbagliate?

Assumiamo che $G(x)\not\equiv H(x)$, e la somma dei gradi di $x$ in $H$ e $G$ è limitata da $d$.
$F(x)\equiv G(x)-H(x)$ è un polinomio in una variabile di grado delimitata da $d$.

>[!important]- Teorema
>Se $$F(x)\equiv G(x)-H(x)\not\equiv 0$$ allora l'equazione $$F(x)=G(x)-H(x)=0$$ non ha più di $d$ radici (soluzioni).

## Analisi dell'algoritmo

Se l'identità è corretta l'algoritmo risponde sempre con una risposta corretta. Se invece l'identità *non* è corretta, l'algoritmo risponde con una risposta *errata* solo se prendiamo un $r$ che è una delle radici del polinomio $F(x)=G(x)-H(x)=0$. Se scegliamo $r$ in un range di $[1,...,100d]$ allora la possibilità di una risposta errata è non più dell'1%.

### Ottenere una probabilità di errore arbitrariamente piccola

È possibile ridurre la "probabilità di errore" incrementando il tempo di esecuzione dell'algoritmo:
1. Eseguire l'algoritmo 10 volte;
2. L'output è *CORRETTO* se si ottiene *CORRETTO* in tutte e 10 le esecuzioni
Se il nuovo algoritmo risponde *corretto*, la "possibilità" che $H(x)\not\equiv G(x)$ è meno di $10^{-20}<2^{-64}$.

>[!danger]- Il caso sfavorevole avviene quando per 10 tentativi l'algoritmo risponde *CORRETTO* semplicemente perché è stato preso un $r$ radice.
>

## Spazio di probabilità

>[!important]- Definizione
>Uno **Spazio di probabilità** ha tre componenti:
>1. Uno *Spazio di esempio* $\Omega$, ovvero l'insieme di tutti i possibili risultati del processo randomico modellato dallo spazio delle probabilità;
>2. Una famiglia di insiemi $\mathcal{F}$ che rappresenta gli *eventi possibili*, dove ogni insieme in $\mathcal{F}$ è un sottoinsieme dello spazio di esempio $\Omega$;
>3. Una *Funzione di probabilità* $Pr:\mathcal{F}\rightarrow R$, che soddisfa la definizione seguente.

In uno spazio di probabilità *discreto* poniamo $\mathcal{F}=2^{\Omega}$.

### Funzione di probabilità

>[!important]- Definizione
>Una *Funzione di probabilità* è una qualsiasi funzione $Pr:\mathcal{F}\rightarrow R$ che soddisfa le condizioni seguenti:
>1. Per ogni evento $E$, $0\le Pr(E)\le 1;$;
>2. $Pr(\Omega)=1$;
>3. Per ogni seguenza finita o infinita ma contabile di eventi a coppie reciprocamente disgiunti $E_1,E_2,...$ $$Pr(\cup_{i\gt 1} E_i) = \sum_{i\gt 1} Pr(E_i)$$

La probabilità di un evento è la somma delle probabilità di questi semplici eventi.

## Torniamo agli algoritmi di controllo dell'identità polinomiale

- Un semplice evento = una scelta di $r$;
- Spazio di esempio = tutti gli interi in $[1,...,100d]$.
- Assumiamo che tutti gli interi nello spazio di esempio hanno la stessa probabilità, quindi la probabilità di un semplice evento $r$ è $Pr(r)=\frac{1}{100d}$.
- Gli eventi *sfavorevoli*: Scegliere come $r$ una radice del polinomio. Non ci sono più di $d$ eventi semplici nel caso sfavorevole:
	- $Pr(\text{"sfavore"})\le\frac{d}{100d}.$

Assumiamo di ripetere l'algoritmo $k$ volte;
- Se ogni iterazione ritorna *FALSE* rispondi *FALSE*, altrimenti *CORRECT*.
- Un evento semplice: $A$ sequenze di numeri $r$ nel range $[1,...,100d]$.
- La probabilità di un semplice evento = $(\frac{1}{100d})^k$.
- L'evento *sfavorevole* = Tutte le scelte di $k$ sono radici del polinomio, non ci sono più di $d^k$ eventi semplici.
- Probabilità dell'evento sfavorevole $\le d^k(\frac{1}{100d})^k.$

## Eventi indipendenti

Due eventi $E$ e $F$ sono **indipendenti** se e solo se $$Pr(E\cap F) = Pr(E)\cdot Pr(F).$$
In generale gli eventi $E_1,E_2,...,E_k$ sono mutualmente indipendenti se e solo se per *qualsiasi* sottoinsieme $I\subseteq [1,k]$, $$Pr(\cap_{i\in I} E_i) = \prod_{i\in I} Pr(E_i).$$
- La probabilità di pescare una radice al primo tentativo è $\le\frac{d}{100d}$;
- Gli eventi in tentativi differenti sono *indipendenti*.
- La probabilità di pescare radici in $k$ passi successivi indipendenti è $\le(\frac{d}{100d})^k$.

### Probabilità condizionale

Qual è la probabilità che uno studente di Torino è nato ad Empoli?
- $E_1 =$ L'evento "Nato ad Empoli";
- $E_2 =$ L'evento "Uno studente di Torino".
La probabilità condizionale che uno studente di Torino è nato ad Empoli è denotata come:
$$Pr(E_1|E_2).$$

>[!important]- Definizione
>La **probabilità condizionale** che un evento $E$ accada dato l'accadere di un evento F è:
>$$Pr(E|F)=\frac{Pr(E\cap F)}{Pr(F)}$$
>La probabilità condizionale è ben definita solo se $Pr(F)>0$.

Condizionando $F$ restringiamo lo spazio di esempio all'insieme $F$. QUindi siamo interessati a $Pr(E\cap F)$  "normalizzato" da $Pr(F)$.

# Indipendenza

Due eventi $A$ e $B$ sono **indipendenti** se $$Pr(A\cap B) = Pr(A)\times Pr(B)$$ oppure $$Pr(A|B)=\frac{Pr(A\cap B)}{Pr(B)}=Pr(A).$$
# Verifica di moltiplicazioni tra matrici

Date tre matrici $n\times n\space\space A, B$ e $C$  nel campo Booleano, si vuole verificare se $AB=C$
Il metodo standard sarebbe la moltiplicazione tra matrici, che richiede $\Theta(n^3)$ ($\Theta(n^{2.37})$).

**Algoritmo randomizzato**

1. Scegliere un vettore randomico $\bar{r}=(r_1,r_2,...,r_n)\in\{0,1\}^n$.
2. Computare $B\bar{r}$.
3. Computare $A(B\bar{r})$
4. Computare $C\bar{r}$.
5. Se $A(B\bar{r})\neq C\bar{r}$ ritorna $AB\neq C$, altrimenti $AB=C$.
Questo algoritmo richiede tempo $\Theta(n^2)$.

>[!important]- Teorema
>Se $AB\neq C$, ed $\bar{r}$ viene scelto randomicamente in modo uniforme su $\{0,1\}^n$ allora $$Pr(AB\bar{r}=C\bar{r})\le\frac{1}{2}.$$

>[!note]- Dimostrazione
>Dato $D=AB-C\neq 0$. $A(B\bar{r})=C\bar{r}$ implica che $D\bar{r}=0$.
>Se $D\neq 0$ allora ha qualche elemento non nullo; assumiamo $d_{1,1}$.
>Per $D\bar{r}=0$, deve essere il caso di $$\sum_{j=1}^n d_{1j}r_j = 0$$ oppure, equivalentemente $$r_1 =- \frac{\sum_{j=2}^n d_{1j}r_j}{d_{11}}$$  Qui diciamo $d_{11}\neq 0$.

## Principio della decisione differita
	Principle of Deferred Decision

Assumiamo di aver corretto $r_2,...,r_n$.
L'unica variabile è $r_1$:$$r_1 = - \frac{\sum_{j=2}^n d_{1j}r_j}{d_{11}}$$  La probabilità che questa operazione sia vera non vale più di $\frac{1}{2}$.

>[!important]- Teorema ( Legge della Probabilità Totale ) 
>Dati $E_1,E_2,...,E_n$ eventi mutualmente esclusivi nello spazio di esempio $\Omega$, e $\cup_{i=1}^n E_i=\Omega$, quindi $$Pr(B) = \sum_{i = 1}^n Pr(B\cap E_i) = \sum_{i=1}^n Pr(B|E_i)Pr(E_i).$$


# Legge di Bayes


>[!important]- Legge di **Bayes**
>Assumendo che $E_1,E_2,...,E_n$ siano insiemi mutualmente esclusivi dati da $\cup_{i=1}^n E_i=E$, allora $$Pr(E_j|B)=\frac{Pr(E_j\cap B)}{Pr(B)} = \frac{Pr(B|E_j)Pr(E_j)}{\sum_{i=1}^n Pr(B|E_i)Pr(E_i)}$$


## Approccio Bayesiano

Inizia con un *modello precedente*, dando dei valori inziali ai parametri del modello. Questo modello viene poi modificato, incorporando nuove osservazioni per avere *un modello a posteriori* che catturi nuove informazioni.

> Esempio: Test di moltiplicazioni delle matrici randomizzato

La volontà è quella di incrementare la sicurezza attraverso test ripetuti.
Se non abbiamo informazioni sul processo che ha generato l'identità, una plausibile assunzione a posteriori è che l'identità è corretta con probabilità $\frac{1}{2}$. Se eseguiamo il test randomizzato una volta ed esso restituisce l'identità matriciale corretta, come cambia la nostra sicurezza nell'identità?
$$\begin{align} \\&  E-\text{L'identità è corretta} \\& B -\text{Il test ritorna che l'identità è corretta} \\& \text{Iniziamo con }Pr(E)=Pr(\overline{E})=\frac{1}{2}\text{, e dato che il test non ha errori nascosti con limite }\frac{1}{2},\\&\text{abbiamo che }Pr(B|E)=1\text{ e che } Pr(B|\overline{E})\le\frac{1}{2}).\\&\text{Applicando la legge di Bayes si ha:}\\& Pr(E'|B)=\frac{Pr(B|E)Pr(E)}{Pr(B|E)Pr(E)+Pr(B|\overline E)Pr(\overline E)}\le\frac{1/2}{1/2 + 1/2\space\cdot 1/2}=\frac{2}{3}\\&\text{Supponiamo ora di riprovare il test e ancora una volta abbiamo una risposta corretta.}\\&\text{Dopo il primo test, il modello a priori è cambiato, quindi:}\\&Pr(E)\ge 2/3, Pr(\overline E)\le 1/3.\\&Pr(B|E)=1, Pr(B|\overline E)\le 1/2.\\&\text{Applicando la legge di Bayes abbiamo}\\&Pr(E'|B)\ge\frac{2/3}{2/3 +1/3\space\cdot 1/2}=\frac{4}{5}.   \end{align}$$

## Algoritmo Min-Cut

**Input**: Un grafo $G=(V,E)$ con $|V|=n$ nodi e $|E|=m$ archi.
**Output**: Un insieme minimo di archi che disconnettono il grafo.
1. Ripetere $n-2$ volte:
	1. Scegliere un nodo a caso ( uniformemente ).
	2. Contrarre i due vertici connessi a quel nodo, eliminando tutti i nodi connessi al nodo scelto.
2. Restituisce l'insieme di nodi che connettono i due archi rimanenti

![[Pasted image 20241030102905.png|center|600]]

>[!important]- Teorema
>L'algoritmo restituisce un set con tagli minimi di nodi con probabilità di successo $\le\frac{1}{n(n-1)}.$
>La probabilità diminuisce all'aumentare di $n$.

>[!note]- Lemma
>La contrazione dei nodi non riduce la dimensione dell'insieme di taglio minimo. Un taglio in $G'$ è un taglio in $G$, quindi o migliora la situazione o la rende invariata, non può peggiorarla.


### Analisi dell'algoritmo

 Assumiamo che il grafo abbia un insieme `min-cut` di $k$ nodi. Computiamo la probabilità di trovarne uno come il set di prima C.

>[!note]- Lemma
>Se l'arco contratto non appartiene a C, nessun altro arco eliminato in quel passaggio appartiene a C

Dati:$$\begin{align}
\\& E_i=\text{"L'arco contratto nell'iterazione i non appartiene a C."}
\\& F_i = \cap_{j=1}^i E_j =\text{"Nessun arco di C è stato contratto nelle prime i iterazioni".}
\\& \text{Dobbiamo computare }Pr(F_{n-2})\\&
\\&\texttt{OSSERVAZIONE FONDAMENTALE}\\&
\\&\text{Dato che il cut-set minimo ha }k\text{ archi, tutti i nodi hanno grado}\le k\text{, ed il grafo ha un}\\&\text{numero di archi}\ge nk/2.
\\&\text{Ci sono almeno }nk/2\text{ archi nel grafo, }k\text{ archi sono in }C.
\\& Pr(E_1)=Pr(F_1)\ge1-\frac{2k}{nk}=1-\frac{2}{n}.
\end{align}$$
Assumiamo che la prima contrazione non ha eliminato un arco di C ( condizionamento sull'evento $E_1=F_1$). Alla prima contrazione degli archi ci resta un grafo con $n-1$ nodi, con un cut-set minimo, ed un grado minimo $\ge k$.
Il nuovo grafo ha almeno $k(n-1)/2$ archi.
$Pr(E_2|F_1)\ge 1-\frac{k}{k(n-1)/2}\ge 1-\frac{2}{n-1}$.
Analogamente:
$Pr(E_i|F_{i-1})\ge 1-\frac{k}{k(n-i+1)/2}=1-\frac{2}{n-i+1}$.

Dobbiamo eseguire $Pr(F_{n-2})$. Usiamo:
![[Pasted image 20241030104937.png|center|500]]

![[Pasted image 20241030105011.png|center|500]]

Data $A_1,..,A_n$ una sequenza di eventi, e dato $E_i=\cap_{j=1}^i A_i$.
$$Pr(E_n)=Pr(A_n|E_{n-1})Pr(E_{n-1})=Pr(A_n|E_{n-1})Pr(A_{n-1}|E_{n-2})...Pr(A_2|E_1)Pr(A_1).$$
>[!important]- Teorema
>Assumiamo di eseguire l'algoritmo Min-Cut randomizzato $n(n-1)\log(n)$ volte, e che esso restituisca la dimensione minima di cut-set trovati in tutte le iterazioni. La probabilità che l'output **non** sia un insieme di min-cut è limitata a:$$(1-\frac{2}{n(n-1)})^{n(n-1)\log n}\le e^{-2\log n}=\frac{1}{n^2}.$$
>Si tratta di un buon risultato, poiché la probabilità di errore decresce all'aumentare di $n$.
>


