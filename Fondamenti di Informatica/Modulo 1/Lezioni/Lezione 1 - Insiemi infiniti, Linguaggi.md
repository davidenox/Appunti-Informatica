# Introduzione

- [[#Induzione matematica semplice]]
- [[#Induzione completa]]
- [[#Insiemi Infiniti]]
- [[#Linguaggi]]


## Induzione matematica semplice

Data una proposizione $P(n)$ definita per un generico numero naturale n, si a che essa è vera per tutti i num naturali se:
- P(0) è vera (**passo base** dell'induzione)
- $\forall$ naturale k, $P(k)$ vera (ipotesi induttiva) implica $P(k+1)$ vera (**passo induttivo**) 

$$(P(0)\wedge\forall k' (P(k')\implies P(k'+1)))\implies \forall\: nP(n)$$
**Esempio**
dimostrare che $\sum_{i=0}^n i=\frac{n(n+1)}{2}$ (questa è $P(n)$)
- Passo base : $\sum_{i=0}^0 i = \frac{0(0+1)}{2} = 0$ 
- Passo induttivo:$$\sum_{i=0}^{k+1}i=\sum_{i=0}^k i+(k+1)=\frac{k(k+1)}{2}+(k+1)=\frac{k^2+3k+2}{2}=\frac{(k+1)(k+2)}{2}$$
> Sostanzialmente dobbiamo verificare che se vale $\sum_{i=0}^k i= \frac{k(k+1)}{2} \implies$ vale $\sum_{i=0}^{k+1} i = \frac{(k+1)(k+2)}{2}$ 

Chiaramente questo è verificato e vale $\forall k$ 

**Esempio**

Dimostrare che $\sum_{i=0}^{n-1}2^i=2^n-1\: per\: n\geq1$
- Passo base(n=1): $\sum_{i=0}^02^i=2^0-1=0$
- Passo Induttivo:$$\sum_{i=0}^{k-1}2^i=2^k-1\implies \sum_{i=0}^{k}2^i=2^{k+1}-1$$
$$\sum_{i=0}^k 2^i=\sum_{i=0}^{k-1}2^i+2^k=2^k-1+2^k=2\cdot2^k-1=2^{k+1}-1$$


## Induzione completa
data una proposizione $P(n)$ definita per un generico numero naturale $n\geq n_0$ si ha che essa è vera per tutti gli $n\geq n_0$ se:
- $P(n_0)$ è vera (passo base dell'induzione)
- per ogni naturale $k\geq n_0,P(i)$ è vera per ogni $i,n_0\leq i\leq k$ (ipotesi induttiva) implica $P(k+1)$ vera (passo induttivo)
$$(P(0)\wedge \forall k'(P(0)\wedge...\wedge P(k')\implies P(k'+1)))\implies \forall\:nP(n)$$
## Insiemi Infiniti

Due insiemi A e B si dicono **equinumerosi** se esiste una biezione tra di essi
Dato un insieme finito A, la sua cardinalità |A| è definita come :
$$|A|=\begin{cases}0 & se\: A=\emptyset\\
n & se\: è\: equinumeroso\:a\: (0,1,...,n-1),con\: n\geq1\end{cases}$$
- Un insieme di dice numerabile se esso è **equinumeroso** a $\mathbb N$ 
- Un insieme si dice **contabile** se esso è finito o numerabile
- Per indicare la cardinalità degli insiemi infiniti equinumerosi ad $\mathbb N$ si utilizza il simbolo $\aleph_0$ (ALEPH) 
- Se un insieme A è equinumeroso a un insieme B, con $B \subseteq C$, dove C è un insieme contabile, allora anche A è contabile

L'insieme $\mathbb Z$ degli interi relativi risulta essere numerabile (cioè $|\mathbb Z|=\aleph_0$) poichè i suoi elementi possono essere posti in corrispondenza biunivoca con $\mathbb N$ tramite biezione $f:\mathbb Z \rightarrow \mathbb N$ definita nel seguente modo:$$f(i)=\begin{cases}-2i & se\: i\leq0\\
2i-1 & se\: i>0\end{cases}$$ **Esempio**
$\mathbb Z$={-5,-4,-3,-2,-1,0,1,2,3,4,5}
L'insieme $\mathbb N$ associato a $\mathbb Z$ è ={10,8,6,4,2,0,1,3,5,7,9}
(-5=10 {-2i},-4=8 {-2i}, 3=5 {2i-1}, etc...)

L'insieme $\mathbb N^2$ delle coppie di numeri naturali risulta essere numerabile. La corrispondenza biunivoca può essere stabilita con la seguente biezione, frequentemente chiamata **funzione coppia di Cantor**
>$$p(i,j)=\frac{(i+j)(i+j+1)}{2}+i$$

ES : $p(3,4)=\frac{(3+4)(3+4+1)}{2}+3 = \frac{7\cdot 8}{2}+3 = \frac{56}{2}+3 =28+3=31$
$p(0,0)=0, p(0,1)=1, p(1,0)=2, etc..$ 

![[Pasted image 20221013163248.png|center]]

I numeri razionali corrispondono alle classi d'equivalenza della relazione bianria $R$ definita sull'insieme $\mathbb Zx\mathbb Z^+$ :
$$R((\langle a,b\rangle),(\langle c,d\rangle)) \iff ad=bc$$
L'insieme $\mathbb Q$ è dunque equinumeroso all'insieme $\mathbb Z\cdot(\mathbb Z^+)/R$ 
D'altronde poichè $\mathbb Z$ è contabile, anche $\mathbb Z^2$ lo è così come anche l'insieme $\mathbb Z\cdot(\mathbb Z^+)/R$ che è equinumeroso ad un sottoinsieme proprio di $\mathbb Z^2$.
Quindi $\mathbb Q$ è contabile.

L'unione di una quantità contabile di insiemi contabili è ancora un insieme contabile. L'enumerazione può essere effettuata applicando ancora il metodo di Cantor, dove si suppone che la riga i-esima contenga gli elementi dell'i-esimo insieme.

![[Pasted image 20221013163946.png|center]]

L'insieme $\mathbb R$ dei reali non è numerabile
L'insieme aperto (0,1) e l'insieme $\mathbb R$ sono equinumerosi(una possibile biezione è $\frac{1}{(2^x+1)}$, con dominio $\mathbb R$ e codominio (0,1)).

Basta dunque mostrare che l'insieme dei reali in (0,1) non è numerabile. A tal fine, consideriamo l'insieme delle sequenze infinite di cifre decimali che i reali in (0,1) e mostriamo che tale insieme non è numerabile

_Dim per assurdo_
Si supponga per assurdo di aver trovato una qualsiasi corrispondenza tra i naturali e le sequenze: questa corrispondenza definirebbe una enumerazione $\Phi =\: \langle\phi_0,\phi_1,...\rangle$ delle sequenze

Introduciamo ora la sequenza $\phi$ avente come i-esima cifra, per $i=0,1,2,,,$ il valore ottenuto sommando 1(mod 10) alla i-esima cifra di $\phi_i$ 
$$\phi[i]=(\phi_i[i]+1)mod\:10$$
**Esempio**
$\phi[0]=(\phi_0[0]+1)mod\:10$, se $\phi_0[0]=4\implies \phi[0]=5\:mod\:10$ 

![[Pasted image 20221013165610.png|center]]

Si considera la prima cifra della prima sequenza(0+1), la seconda cifra della seconda sequenza(1+1), la terza cifra della terza sequenza(3+1) e cosi via, e otteniamo, in questo caso, una sequenza del tipo 
$$\langle1,2,4,...,\rangle$$
Ci si muove lungo la diagonale della tabella, e la sequenza sarà diversa da ogni cifra della diagonale
Per ogni sequenza(nelle righe) ci sarà un numero nella diagonale, ma quel numero sarà diverso dalla sequenza che stiamo costruendo e quindi la sequenza sarà diversa da ogni altra sequenza

(**Dimostrazione per Diagonalizzazione**)

La sequenza $\phi$ viene a costituire elemento diagonale dell'enumerazione $\phi_0,\phi_1,...$ in quanto differisce da ogni altra sequenza $\phi_i$ nella posizione i

Quindi, dopo aver supposto per assurdo di poter enumerare tutte le rappresentazioni decimali di reali nell'intervallo (0,1), è stato possibile costruire per diagonalizzazione un'ulteriore rappresentazione che, seppure relativa ad un reale in (0,1), non appartiene all'enumerazione, il che contrasta con l'ipotesi che l'insieme delle rappresentazioni dei reali sia numerabile.
La non numerabilità dei reali in (0,1) deriva da quanto detto ed osservando inoltre che ogni numero reale ha al più due rappresentazioni distinte (ad esempio, 0.01000 ... e 0.00999....)

L'insieme delle aprti di $\mathbb N,\mathcal P(\mathbb N)$ non è numerabile

Supponiamo per assurdo che $\mathcal P(\mathbb N)$ sia numerabile e sia $P_o,P_1,...$ una sua enumerazione. A ciascun $P_i, con\: i=0,1,2,...$ associamo una sequenza $b_{i0},b_{i1},b_{i2},...$ dove 
$$b_{i,j}=\begin{cases}0 & se\: j\notin P_i \\
1 & se\: j\in P_i\end{cases}$$
**Oss** $b_{i,j}$ è la **funzione caratteristica dell'insieme**

L'insieme diagonale $P=p_o,p_1,...$ è definito come $p_i=1-b_{i,j}$ e differisce da ciascuno degli insiemi $P_i$ poichè, per costruzione, $i\in P\iff i\notin P_i$. Avendo dunque supposto che sia possibile enumerare gli elementi di $\mathcal P(\mathbb N)$, si è riusciti a costruire un insieme $P\in \mathcal P(\mathbb N)$ che non fa parte della enumerazione, il che falsifica tale ipotesi. 

L'insieme delle funzioni caratteristiche {$f | f:\mathbb N\rightarrow (0,1)$} non è numerabile

Dato un insieme numerabile A, e quindi di cardinalità $\aleph_0$, si dice che l'insieme $\mathcal P(A)$ ha cardinalità $2^{\aleph_0}$ 
Gli insiemi aventi cardinalità $2^{\aleph_0}$ vengono detti insiemi **continui**
L'insieme delle funzioni da interi a interi è continuo:
$|f|f:\mathbb N\rightarrow \mathbb N|=2^{\aleph_0}$ 
L'insieme delle funzioni da reali a reali ha cardinalità:
$|f|f:\mathbb R\rightarrow \mathbb R|=2^{2^{\aleph_0}}$ 

## Linguaggi

_Def_
Un insieme finito non vuoto $\Sigma$ di simboli (detti **caratteri**)  prende il nome di **alfabeto**

Dato un alfabeto $\Sigma$ denotiamo come $\langle\Sigma^\star,\circ ,\epsilon\rangle$ il **monoide libero definito su $\Sigma$**
Gli elementi di $\Sigma^\star$ vengono detti **parole** o **stringhe**
L'elemento $\epsilon$ viene detto **parola vuota**. L'operazione $o:\Sigma^\star x\Sigma^\star\rightarrow \Sigma^\star$ definita sul monoide è chiamata **concatenazione** e consiste nel giustapporre due parole di $\Sigma^\star$:
$$x_{i_1},...,x_{i_n}\:o\:y_{j_1},...,y_{j_m}=x_{i_1}...x_{i_n}y_{j_1}...y_{j_m},con\: x_{i_1},...,x_{i_n},y_{j_1},...,y_{j_m}\in \Sigma$$
**Esempio**

Un esempio di concatenazione dei caratteri $x_1,x_2,x_3,y_1,y_2,z_1$
$(x_1,x_2,x_3\:o\:y_1,y_2)o\:z_1$ 

Dato un alfabeto $\Sigma$ ed il monoide sintattico definito su di esso vale la proprietà:
$$\forall x,x\circ \epsilon = \epsilon\circ x=x$$
La concatenazione di due stringhe x e y è frequentemente indicata omettendo il simbolo $\circ$, cioè scrivendo xy anzichè x o y

Con la notazione |x| indichiamo la **lunghezza** di una parola x, ovvero il numero di caratteri che la costituiscono. Chiaramente $|\epsilon|=0$ Si osservi inoltre che la concatenazione non gode della proprietà commutativa e quindi in generale:
$$x\circ y\neq y\circ x$$

Un caso particolare di concatenazione è quello in cui la stringa viene concatenata con se stesa: con $x^h$ si denota la concatenazione di x con se stessa iterata h volte, Per convenzione con $x^0$ si intende la stringa vuota. 

_Def_
Dato un alfabeto $\Sigma$, si definisce **linguaggio** un qualsivoglia sottoinsieme di $\Sigma^\star$. Si noti che poichè $\Sigma\subseteq\Sigma^\star$, un alfabeto è a sua volta un linguaggio.

Si chiama **linguaggio vuoto**, e lo si indica con $\Lambda$, il linguaggio che non contiene stringa alcuna. Si noti che $\Lambda\neq (\epsilon)$ 

**Oss** $\Sigma$ è un linguaggio finito, $\Sigma^\star$ è un linguaggio infinito

**Esempio**
$L\subseteq (a,b)^\star$ $L=(x\in (a,b)^\star|x=ay,y\in (a,b)^\star)$ 
$(a,b)^\star=\Sigma^\star$ 

x è una sequenza di simboli tra a e b, lunghezza arbitraria, che ha la caratteristica di poter essere divisa in due parti: la prima parte è composta dal carattere a, la seconda è qualunque stringa in (a,b)
L è l'insieme di tutte le stringhe che iniziano in questo modo

L'**intersezione** di due linguaggi $L_1\:e\:L_2$ il linguaggio $L_1\cap L_2$ costituito dalle parole di $L_1$ e di $L_2$, cioè $L_1\cap L_2=(x\in\Sigma^\star|x\in L_1\wedge x\in L_2)$ 
L'**unione** di due linguaggi è il linguaggio $L_1\cap L_2$ costituito dalle parole appartententi ad almeno uno fra $L_1\:ed\:L_2$, cioè $L_1\cup L_2=(x\in\Sigma^\star|x\in L_1\vee x\in L_2)$.
Si noti che $L_1\cap\Lambda=\Lambda$ e $L_1\cup\Lambda=L_1$
Il **complemento** di un linguaggio L_1 è il linguaggio $\overline L_1=\Sigma^\star-L_1$ costituito dalle parole appartenenti a $\Sigma^\star$ ma non a $L_1$, cioè $\overline L_1=(x\in\Sigma^\star|x\notin L_1)$ 

La **concatenazione**(o prodotto) di due linguaggi è il linguaggio $L_1\circ L_2$ delle parole costituite dalla concatenazione di una stringa di $L_1$ e di una stringa di $L_2$, cioè:
$$L_1\circ L_2 = (x\in\Sigma^\star|\exists y_1 \in L_1\:\exists y_2\in L_2(x=y_1\circ y_2))$$

Si noti che $L\circ (\epsilon)=L$ e $L\circ \Lambda=\Lambda$ 

La **potenza** $L^h$ di un linguaggio è definita come:
$$L^h=L\circ L^{h-1},h\geq1$$
con la convenzione secondo cui $L^0=(\epsilon)$. Si noti che,in basde alla suddetta convenzione, $\Lambda^0=(\epsilon)$

_Def_
Il linguaggio $L^\star$ definito da:
$$L^\star=\bigcup_{h=0}^\infty L^h$$
prende il nome di **chiusura riflessiva del linguaggio** L rispetto all'operazione di concatenazione, mentre l'operatore '$\star$' prende il nome di **iterazione o stella di Kleene**. Si noti che, dato un qualunque linguaggio $L,\epsilon\in L^\star$, e che $\Lambda^\star=(\epsilon)$ 

_Def_
Si indica con $L^+$ la **chiusura(non riflessiva)** definita da $$L^+=\bigcup_{h=1}^\infty L^h$$
Risulta ovviamente $L^\star=L^+\cup (\epsilon)$ 