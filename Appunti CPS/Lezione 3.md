# Indipendenza tra più eventi

_Def_
Sia {$A_i$}$_{i\ni I}$ una famiglia di eventi.
Allora si ha una famiglia di eventi indipendenti se:
- la famiglia è finita quindi $\forall$ sottoinsieme di alemeno due insiemi ($A_{i_1},...,A_{i_k}$)  con $k\geq2$ si ha$$P(A_{i_1}\cap...\cap A_{i_k}) = P(A_{i_1})\cdot...\cdot P(A_{i_k})$$
- se la famiglia è infinita, ogni sottoinsieme finito lo è in accordo con quanto detto sopra

**Esempio**
Consideriamo tre eventi {$A_1,A_2,A_3$}. Allora c'è indipendenza se:
$$\begin{cases}P(A_1\cap A_2)=P(A_1)P(A_2)\\
P(A_1\cap A_3)=P(A_1)P(A_3)\\
P(A_2\cap A_3)=P(A_2)P(A_3)\end{cases}\:\: e\: P(A_1\cap A_2\cap A_3) = P(A_1)P(A_2)P(A_3)$$

Consideriamo la seguente situazione : Un'urna ha 4 carte numerate come segue (1,2,3,123) e si estrae una carta a caso
Consideriamo l'evento $A_i$={la carta estratta ha il numero i} i=1,2,3

Allora
$P(A_1) = P(A_2) = P(A_3) = \frac {2}{4}=\frac {1}{2}$
$P(A_1\cap A_2) = P(A_1\cap A_3) = P(A_2\cap A_3) = \frac {1}{4}$
$P(A_1\cap A_2\cap A_3)=\frac {1}{4}$

Quindi $P(A_1\cap A_2)=P(A_1)P(A_2),P(A_1\cap A_3)=P(A_1)P(A_3),P(A_2\cap A_3)=P(A_2)P(A_3)$
e $P(A_1\cap A_2\cap A_3)\neq P(A_1)P(A_2)P(A_3)$

Conclusione: Eventi <u>non</u> indipendenti  ma indipendenti a due a due

_Proposizione_
Se $(A_i)_{i\ni I}$ è una famiglia di eventi indipendenti. allora lo à anche qualsiasi altra famiglia ottenuta considerando il complementare di alcuni(o tutti) gli eventi

**Commento** l'ipotesi di indipendenza spesso segue dal modello in esame. Ad esempio si hanno eventi indipendenti nel caso di un evento legato a diversi lanci di moneta, diversi lanci di un dado, diverse estrazioni da un insieme di elementi <u>con</u> reinserimento
In altri casi gli eventi indipendenti escono fuori in maniera soprendente perchè i valori si combinano in maniera opportuna

Consideriamo il seguente esempio:
Si lanciano 3 monete eque e consideriamo i seguenti eventi :
$A=(\text{esce testa al primo lancio})$
$B=(\text{esceono esattamente 2 teste consecutive})$
L'insieme di riferimento è :
$\Omega = ((T,T,T,),(T,T,C),(T,C,T),(T,C,C,),(C,T,T,),(C,T,C),(C,C,T),(C,C,C))$
Ognuno di questi 8 el. ha prob. $\frac {1}{2}\frac {1}{2}\frac {1}{2}=\frac {1}{8}$ perchè i lanci di moneta sono indipendenti (Quindi spazio di prob. uniforme definito)

Si ha $P(A) = P((T,T,T),(T,T,C),(T,C,T),(T,C,C)) = \frac {4}{8}=\frac {1}{2}$ e $P(B)=P((T,T,C),(C,T,T,)) = \frac {2}{8}=\frac {1}{4}$
Inoltre $P(A\cap B) = P((T,T,C))=\frac {1}{8}\:e\:P(A)P(B)=\frac{1}{2}\frac{1}{4}=\frac{1}{8}$
Quindi A e B sono indipendenti, ma la cosa non era prevedibile a priori

# Cenni di calcolo combinatorio
Consideriamo un insieme di $n\geq1$  elementi; senza perdere di qualità supponiamo che sia l'insieme (1,...,n) 

Siamo interessati al seguente insieme:

>$D_{n,k}=(i_1,...,i_k)$ sequenze ordinate di elementi in {1,...,n}, senza ripetizioni, di lunghezza k con $k\ni (1,...,n)$ (DISPOSIZIONI SEMPLICI)

Ci si chiede quanto vale #$D_{n,k}$
Risposta : Si hanno n scelte per $i_1$, n-1 scelte per $i_2$,...,fino ad avere n-(k-1) scelte per $i_k$
Quindi:
#$D_{n,k} = n(n-1)...(n-(n-k))=n(n-1)...(n-k+1)$

Se si vuole far riferimento al fattoriale si ha #$D_{n,k} = \frac {n!}{(n-k)!}$
Nel caso k=n si ha #$D_{n,k} = \frac {n!}{(n-n)!} = \frac {n!}{0!}=n!$

Ora consideriamo il seguente insieme:
$C_{n,k} = (i_1,..,i_k)$ sottoinsiemi di (1,...,n) di k elementi (ovviamente tutti distinti) (COMBINAZIONI SEMPLICI) 
Ci si chiede quanto vale #$C_{n,k}$

Si ha $C_{n,0} = (\emptyset)\implies |C_{n,0}| = 1$ e $C_{n,n} = (1,..,n) \implies |C_{n,n}| = 1$

Allora:
preso un sottoinsieme $(i_1,...,i_k)$, considerando tutte le permutazioni di $(i_1,...,i_k)$ danno origine a particolari sequenze ordinate in $D_{n,k}$; tutti gli elementi di $D_n,k$ possono essere visti come una particolare permutazioni di elementi di un certo insieme

![[Appunti CPS/Immagini/Pasted image 20221011164449.png]]

A partire da questo esempio possiamo dire che $|C_{n,k}|\cdot k!=D_{n,k}$
da cui segue
>$$|C_{n,k}|=\frac {|D_{n,k}|}{k!}=\frac {n!}{k!(n-k)!}$$

L'espressione ottenuta è il _coefficente binomiale_ e si usa la notazione $n\choose k$=$\frac{n!}{k!(n-k)!}$ 
**Alcuni esempi**

In generale si ha $n\choose k$=$n\choose{n-k}$ (ad ogni sottoinsieme di K elementi corrisponde il suo complemento di n-k elementi; quindi #$C_{n,k}$=$C_{n,n-k}$)
In particolare per k=0 e k=1 si ha:
- $n\choose0$=$n\choose n$=1
- $n\choose1$=$n\choose{n-1}$=n

## Spiegazione del termine "coefficente binomiale"
Possiamo dire che il nome coefficente binomiale segue dalla formula del binomio di Newton:
$$(a+b)^n=\sum_{k=0}^{n}{n\choose k}a^kb^{n-k}$$
Infatti:
$$(a+b)^n=\underbrace{(a+b)...(a+b)}_{n\:volte}$$
e $\forall k\ni(0,1,...,n)$ abbiamo termini del tipo $a^kb^{n-k}$; se vogliamo contare quanti ce ne sono si vede che appare il coefficente binomiale

# Applicazioni di formule di calcolo combinatorio
## Estrazioni casuali in blocco
Abbiamo oggetti di due tipi: $n_1$ di tipo 1 e $n_2$ di tipo 2
Si estraggono a caso contemporaneamente n oggetti, dove $n<n_1+n_2$
Quanto vale la prob. di estrarre k oggetti di tipo 1? (quindi contemporaneamente si estraggono n-k oggetti di tipo 2)
Indichiamo questa probabilità con $p_k$ e si ha:
>$$p_k=\begin{cases}
0 & se\:k>n_1\: oppure\: se\: n-k>n_2\\
"da\: calcolare" & se\begin{cases}0\leq k\leq n_1\\
0\leq n-k\leq n_2\end{cases}
\end{cases}$$

Bisogna osservare che in generale abbiamo ${n_1+n_2}\choose n$ casi possibili e tutti equiparabili dati da tutti i sottoinsiemi di n elementi a partire da $n_1+n_2$ elementi.
I casi favorevoli all'evento "estrarre k oggetti 1 e n-k oggetti 2" devono essere pensati come sottoinsiemi del tipo {$i_1,...,i_k,j_1,...,j_{n-k}$}
Abbiamo $n_1\choose k$ scelte per $(i_1,...,i_k)$ e $n_2\choose {n-k}$ scelte per $(j_1,...,j_{n-k})$
In conclusione il numero di casi favorevoli è dato dal prodotto dei due binomiali e quindi :
>$$p_k=\frac{{n_1\choose k}{n_2\choose {n-k}}}{{n_1+n_2}\choose n}$$

**Esempio**
$n_1=3,n_2=2,n=3$

${n_1+n_2}\choose n$ = ${3+2}\choose 3$=10

Convenzione $\begin{cases}1 & 1,2,3\\2 & 4,5\end{cases}$
In quel che segue scrivo i 10 sottoinsiemi e indico accanto il numero di elementi di tipo 1
Quindi $p_0=0,p_1=\frac{3}{10},p_2=\frac{6}{10},p_3=\frac{1}{10}$
Questi valori sono in accordo con la formula:
$$p_k=\frac{{3\choose k}{2\choose{3-k}}}{5\choose3}=\frac{{3\choose k}{2\choose{3-k}}}{10}=\begin{cases}k=0 & 0\\k=1 & \frac{3}{10}\\k=2 & \frac{6}{10}\\k=3 & \frac{1}{10}\end{cases}$$

**Esercizi di riepilogo**

Un'urna ha 3 palline bianche e 4 nere. Si estraggono 2 palline a caso, una alla votla a con reinserimento
1) calcolare la prob. di estrarre due colori uguali
2) calcolare la prob. di estrarre almeno una pallina nera

Svolgimento
segniamo questi due insiemi
$B_k=(\text{k-esima estratta bianca})$  
$N_k=(\text{k-esima estratta nera})$ 
-  la rob. richiesta è $P((B_1\cap B_2)\cup(N_1\cap N_2))$ = $P(B_1\cap B_2)+P(N_1\cap N_2)= P(B_1)P(B_2)+P(N_1)P(N_2)=\frac{3}{7}\frac{3}{7}+\frac{4}{7}\frac{4}{7}=\frac{25}{49}$
-  La prob. richiesta è $P(N_1\cup N_2)$: 
	- 1 modo: $P(N_1\cup N_2)=P(N_1)+P(N_2)-\underbrace{P(N_1\cap N_2)}_{=P(N_1)P(N_2)}=\frac{4}{7}+\frac{4}{7}-\frac{3}{6}\frac{4}{7}=\frac{6}{7}$
	- 2 modo $P(N_1\cup N_2)=1-P((N_1\cup N_2)^c)=1-P(N_1^c\cap N_2^c)=1-P(B_1\cap B_2)=1-P(B_1|B_2)P(B_1)=$$1-\frac{\cancel{2}}{\cancel{6}}\frac{\cancel{3}}{7}=1-\frac{1}{7}=\frac{6}{7}$  

