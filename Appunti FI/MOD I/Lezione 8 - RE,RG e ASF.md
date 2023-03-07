# Espressioni Regolari e Grammatiche

>**Teorema**
>Tutti i linguaggi definiti da espressioni regolari sono regolari

>**Teorema**
>Data una grammatica $\mathcal G$ di tipo 3, esiste una espressione regolare $r$ tale che $L(\mathcal G)=L(r)$, che descrive cioè il linguaggio generato da $\mathcal G$

Consideriamo una grammatica $\mathcal G$ di tipo 3 e il linguaggio $L$ da essa generato, che per semplicità assumiamo non contenga la stringa vuota $\varepsilon$

Se così non fosse, applichiamo le considerazioni seguenti al linguaggio $L-\lbrace\varepsilon\rbrace$, anch'esso regolare: una volta derivata un'espressione regolare $r$ che lo definisce, l'espressione regolare che definisce $L$ sarà chiaramente $r+\varepsilon$

Alla grammatica $\mathcal G$ possiamo far corrispondere un sistema di equazioni su espressioni regolari

Estensione del linguaggio delle espressioni regolari con variabili $A,...,Z$, associando una variabile ad ogni non terminale in $\mathcal G$

Tali variabili potranno assumere valori nell'insieme delle espressioni regolari

Raggruppamento di tutte le produzioni che presentano a sinistra lo stesso non terminale. Per ogni produzione del tipo $$A\to a_1B_1|a_2B_2|...|a_nB_n|b_1|b_2|...|b_m$$abbiamo un equazione del tipo:
$$A=a_1B_1+a_2B_2+...+a_nB_n+b_1+b_2+...+b_m$$

Da una grammatica regolare si ottiene un sistema di **equazioni lineari destre**, in cui ogni monomio contiene una variabile a destra di simboli terminali

Risoluzione del sistema di equazioni su espressioni regolari estese:
Individuazione dei valori (espressioni regolari normali, prive delle variabili che definiscono a loro volta espressioni regolari) che, una volta sostituiti alle variabili, soddisfano il sistema di equazioni

**Esempio**
- $A\to aA|bB$
- $B\to bB|c$
corrisponde al sistema di equazioni
$$\begin{cases}A=aA+bB\\B=bB+c\end{cases}$$
Per risolvere il sistema è possibile utilizzare, le trasformazioni algebriche applicabili sulle operazioni di unione e concatenazione, oltre alle seguenti due regole

**Regola 1**: _Sostituzione_ di una variabile con un'espressione regolare estesa

Con riferimento all'esempio precedente abbiamo 
$$\begin{cases}A=aA+b(bB+c)=aA+bbB+bc\\B=bB+c\end{cases}$$
**Regola 2**: _Eliminazione della ricursione_ (**Teorema di Arden**)

L'equazione $B=bB+c$ si risolve in $B=b^\star c$. Infatti, sostituendo a destra e sinistra abbiamo
$$b^\star c=b(b^\star c)+c=b^+c+c=(b^++\varepsilon)c=b^\star c$$
Più in generale abbiamo che un'equazione del tipo 
$$A=\alpha_1A+\alpha_2A+...+\alpha_nA+\beta_1+\beta_2+...+\beta_m$$
si risolve in 
$$A=(\alpha_1+\alpha_2+...+\alpha_n)^\star(\beta_1+\beta_2+...+\beta_m)$$
dove $\alpha_1,...,\alpha_n,\beta_1,...,\beta_m$ sono espressioni regolari estese

**Esempio concreto**

Grammatica regolare
- $A_0\to aA_1|a$
- $A_1\to bA_3|bA_2$
- $A_2\to aA_2|bA_0|b$
- $A_3\to bA_3|aA_2$
da cui si ottiene il seguente sistema lineare
$$\begin{cases}A_0&=aA_1+a\\A_1&=bA_3+bA_2\\A_2&=A_2+bA_0+b\\A_3&=bA_3+aA_2\end{cases}$$
Per eliminazione della ricursione su $A_3$:
$$\begin{cases}A_0&=aA_1+a\\A_1&=bA_3+bA_2\\A_2&=A_2+bA_0+b\\A_3&=b^\star aA_2\end{cases}$$
per eliminazione della ricursione su $A_2$:
$$\begin{cases}A_0&=aA_1+a\\A_1&=bA_3+bA_2\\A_2&=a^\star(bA_0+b)\\A_3&=b^\star aA_2\end{cases}$$
per sostituzione di $A_2$ nell'equazione relativa ad $A_3$
$$\begin{cases}A_0&=aA_1+a\\A_1&=bA_3+bA_2\\A_2&=a^\star(bA_0+b)\\A_3&=b^\star aa^\star(bA_0+b)\end{cases}$$
per sostituzione di $A_2$ e $A_3$, nell'equazione relativa ad $A_1$
$$\begin{cases}A_0&=aA_1+a\\A_1&=b(b^\star aa^\star(bA_0+b))+b(a^\star(bA_0+b))\\A_2&=a^\star(bA_0+b)\\A_3&=b^\star aa^\star(bA_0+b)\end{cases}$$
per sostituzione di $A_2$ e $A_3$, nell'equazione relativa ad $A_1$
$$\begin{cases}A_0&=aA_1+a\\A_1&=b(b^\star aa^\star+a^\star)(bA_0+b)\\A_2&=a^\star(bA_0+b)\\A_3&=b^\star aa^\star(bA_0+b)\end{cases}$$
per sostituzione di $A_1$ nell'equazione relativa a $A_0$
$$\begin{cases}A_0&=a(b(b^\star aa^\star+a^\star)(bA_0+b))+a\\A_1&=b(b^\star aa^\star+a^\star)(bA_0+b)\\A_2&=a^\star(bA_0+b)\\A_3&=b^\star aa^\star(bA_0+b)\end{cases}$$
per fattorizzazione nell'equazione relativa ad $A_0$
$$\begin{cases}A_0&=ab(b^\star aa^\star+a^\star)bA_0+ab(b^\star aa^\star+a^\star)b+a\\A_1&=b(b^\star aa^\star+a^\star)(bA_0+b)\\A_2&=a^\star(bA_0+b)\\A_3&=b^\star aa^\star(bA_0+b)\end{cases}$$

# Espressioni Regolari e ASF

>**Teorema**
>Dato un ASFD $\mathcal A$, esiste una espressione regolare $r$ tale che $L(\mathcal A)=L(r)$, che descrive cioè il linguaggio riconosciuto da $\mathcal A$

Sia $\mathcal A=\langle\Sigma,Q,\delta,q_0,F\rangle$ un ASFD e $L$ il linguaggio da esso riconosciuto. Assumiamo $F=\lbrace q_F\rbrace$

Sia $n=|Q|$ e sia $\langle q_0,...,q_{n-1}\rangle$ un qualunque ordinamento degli stati tale che $q_{n-1}=q_F$

Definiamo ora come $$R_{ij}^k\:0\leq i,j\leq n-1;k\geq max(i,j)$$
L'insieme delle stringhe tali da portare $\mathcal A$ da $q_i\:a\:q_j$ senza transitare nessuno stato $q_h$ con $h\geq k$

Abbiamo cioè che $x=a_1,..,a_m\in R_{ij}^k$ se e solo se:

1. $\overline\delta(q_i,x)=q_j$
2. se $\overline\delta(q_i,a_1...a_l)=q_{i_l}$ allora $i_l\lt k$, per $1\leq l\leq m-1$

Per $k=0$ si ha:
$$R_{ij}^0=\begin{cases}\bigcup\{a\} & tali\:che\:\delta(q_i,a)=q_j,\text{se ne esiste alemeno uno}\\\emptyset & altrimenti\end{cases}$$
Per $k\gt1$, se $x\in R_{ij}^{k+1}$ è una stringa che conduce da $q_i\:a\:q_j$ senza transitare per nessuno stato $q_h$ con $h\geq k+1$, possono verificarsi due casi

1. x conduce da $q_i\:a\:q_j$ senza transitare per $q_k$, dal che deriva che $x\in R_{ij}^k$
2. x conduce da $q_i\:a\:q_j$ transitando per $q_k$

Nel secondo caso la sequenza degli stati attraversati può essere divisa in varie sottosequenze:

1. Una prima sequenza, da $q_i$ a $q_{k-1}$ senza transitare per nessuno stato $q_h$ con $h\geq k-1$, la corrispondente sottostringa di $x$ appartiene quindi a $R_{i(k-1)}^{k-1}$
2. $r\geq0$ sequenze, ognuna dele quali inizia e termina in $q_{k-1}$ senza transitare per nesusno stato $q_h$ con $h\geq k-1$, le corrispondenti sottostringhe di x appartengono quindi ciascuna a $R_{(k-1)(k-1)}^{k-1}$
3. una sequenza finale, da $q_{k-1}$ a $q_j$ senza transitare per nessuno stato $q_h$ con $h\geq k-1$, la corrispondente sottostringa di x appartiene quindi a $R_{(k-1)j}^{k-1}$

In conseguenza, ne deriva la relazione:
$$R_{ij}^{k+1}=R_{ij}^k\cup R_{ik}^k\circ(R_{kk}^k)^\star\circ R_{kj}^k$$
Dalle osservazioni precedenti deriva che è possibile costrutire tutti gli insieme $R_{ij}^k$ a partire da $k=0$ e derivando poi man mano i successivi

Osserviamo anche che $L=R_{0(n-1)}^n$

Ogni insieme di stringhe $R_{ij}^k$ può essere descritto per mezzo di una opportuna espressione regolare $r_{ij}^k$, infatti abbiamo che, per $k=0$,
$$r_{ij}^0=\begin{cases}a_{i_1}+...+a_{i_l}&dove:\delta(q_i,a_{i_k})=q_j,k=1...,l;\\\varepsilon&se\:l=0\end{cases}$$
per $k\geq1$, abbiamo che, dalla relazione $R_{ij}^{k+1},R_{ik}^k,R_{kk}^k,R_{kj}^k$, deriva che $$r_{ij}^{k+1}=r_{ij}^k+r_{ik}^k(r_{kk}^k)^\star r_{kj}^k$$
Quindi, il linguaggio $L$ sarà descritto dall'espressione regolare
$$r_{0(n-1)}^n$$
**Esempio**

![[Pasted image 20221114105223.png|center|500]]
Assumiamo l'ordinamento $q_0=q_0,q_1=q_1,q_2=q_3,q_3=q_2$ tra gli stati. 
Allora:
![[Pasted image 20221114105420.png|center|400]]
E quindi:
![[Pasted image 20221114105736.png|center|500]]
![[Pasted image 20221114105826.png|center|500]]
![[Pasted image 20221114105854.png|center|600]]

E quindi il linguaggio accettato dall'automa sarà descritto dall'espressione regolare 
$$r_{03}^4$$
