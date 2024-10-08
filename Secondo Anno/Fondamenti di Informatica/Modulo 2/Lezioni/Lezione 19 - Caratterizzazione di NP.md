# Caratterizzazione di NP
## Da una condizione sufficiente...
Abbiamo visto che tutti i problemi decisionali tali che:
1. Il predicato ha la forma $\pi(x,S(x))=\text{esiste }y\in S(x)\text{ tale che }\eta(x,y)$ 
2. La scelta di un elemento $y$ di $S(x)$ richiede tempo non deterministico polinomiale in $|x|$ 
3. La verifica che $y$ soddisfi il predicato $\eta$, richiede tempo polinomiale in $|x|$
Appartengono ad NP.
Ossia, *1,2 e 3 sono condizioni sufficienti per poter affermare che un problema appartiene ad NP*.
## ..ad una nuova caratterizzazione..
>[!important]- Teorema 9.1 
>Un linguaggio $L\subseteq\Sigma*$ appartiene ad NP **se e soltanto se** esistono una macchina di Turing deterministica $T$ e due costanti $h,k\in \mathbb{N}$ tali che, per ogni $x\in\Sigma^*$,
>$$\begin{align}x\in L\iff & \exists y_x\in\{0,1\}^*:|y_x|\leq|x|^k \\& \land T(x,y_x)\text{ accetta } \\& \land dtime(T,x,y_x)\in O(|x|^h).    \end{align}$$
## ...di cui capire il significato
Intanto, osserviamo che il Th. è una *condizione necessaria e sufficiente* per poter dire "L appartiene ad NP", e, siccome è una condizione necessaria e sufficiente, dobbiamo scomporlo in due parti.
<u>Se partiamo dall'ipotesi che L appartiene a NP</u>, il teorema ci indica una c**ondizione necessaria e sufficiente** per poter affermare che $x\in L$:
- Per ogni $x\in\Sigma^*, x\in L\iff...$
Cerchiamo ora di capire qual è questa *condizione*:
***a)*** $\exists y_x\in\{0,1\}^*$: - Ci dice che, per poter affermare che $x\in L$ , dobbiamo trovare una parola da associare ad x...
***b)*** $|y_x|\leq|x|^k$  ...che non sia troppo lunga...
***c)*** $\land T(x, y_x)\text{ accetta}$    ...e che induca *una certa macchina deterministica T*
  ad accettare...
  ***d)*** $\land dtime(T,x,y_x)\in O(|x|^h)$ ... e accetta in tempi brevi.
  Quindi chi è questa macchina deterministica T?
## Piccolo aiuto
Meglio: Il Th ci dice che **se $L\in NP$ allora esiste una macchina deterministica T** tale che, se le do in input due parole $x$ e $y$, *con y scelta da me e non troppo lunga*, $T(x,y)$, in tempo polinomiale in $|x|$, **accetta se e soltanto se $x\in L$ e io ho scelto la $y$ giusta**, perché, mi dice il teorema, *una parola $y_x$ che possa convincere T ad accettare riesco a trovarla se $x\in L$, ma **non** riesco a trovarla se $x\notin L$*.
Allora, *se trovo qualcuno in grado di suggerirmi, per ogni $x\in L$, la parola $y_x$ giusta*, io le parole di L riesco ad accettarle in tempo deterministico polinomiale.
## Il ritorno del Genio
Se al genio viene chiesta la sequenza di tuple di NT che costituiscono una computazione accettante di $NT(x)$, egli comunicherà una certa parola, denominata come $y_x$, *che descrive la sequenza di quintuple che egli afferma costituire una computazione accettante di $NT(x)$*. Sequenza che però bisogna verificare:
- Verificare innanzitutto che $y_x$ sia una sequenza di quintuple di NT.
- Poi che $y_x$ sia una sequenza di quintuple che NT può eseguire su input x - ossia, che corrisponda ad una computazione deterministica di $NT(x)$.
- Infine devo verificare che $y_x$ corrisponda ad una computazione accettante.
Se tutte e tre le prove hanno esito positivo, allora posso concludere che $x\in L$.
Data la lunghezza di queste prove, è opportuno costruire una macchina deterministica T che esegue la verifica autonomamente, e poiché  T serve a fare le verifiche, verrà denominata **verificatore**.
Quanto impiega $T(x, y_x)$ ad eseguire la verifica?
- Innanzi tutto, poiché $L\in NP$, se $x\in L$ allora esiste una computazione deterministica accettante di NT lunga $|x|^k$ passi - dove $ntime(NT,z)\leq |z|^k$ per ogni $z\in L$.  Perciò $|y_x|\leq|x|^k$.
- Per verificare che $y_x$ sia una sequenza di quintuple di NT, T impiega $O(|y_x|)$ passi.
- Per verificare che $y_x$ corrisponda ad una computazione accettante di $NT(x)$, T deve simulare l'esecuzione delle quintuple descritte in $y_x$, e dunque simula $|x|^k$ passi di NT e impiega $O(|x|^k\times |y_x|)\subseteq O(|x|^{2k})$ passi.
Ossia, T impiega tempo polinomiale in $|x|$ per verificare che il genio non abbia sbagliato. L'unico problema è che T è in grado di verificare che il genio non abbia sbagliato *solo se $x\in L$*. Quindi **se $x\notin L$ non esiste alcuna parola $y$ tale che $T(x,y)$ accetta**.
Infine, siccome per ogni $x\in L$, $ntime(NT,x)\leq|x|^k$. Allora posso fare in modo che, per ogni $x\in L$ e per ogni $y$ tale che $|y|\leq |x|^k$, $dtime(T,x,y)\leq |x|^{hk}$.
Quindi, per la prima parte della dimostrazione:
- Se $L\in NP$ allora esistono una macchina di Turing deterministica T e due costanti $h,k\in\mathbb {N}$ tali che, per ogni $x\in\Sigma^*$,$$x\in L\iff\exists y_x\in\{0,1\}^*:|y_x|\leq|x|^k\land T(x,y_x)\text{accetta}\land dtime(T,x,y_x)\in O(|x|^k)$$
### Un paio di precisazioni
1. Nell'enunciato del [[Lezione 19 - Caratterizzazione di NP#..ad una nuova caratterizzazione..|teorema]] si parla dell'esistenza di una "$y_x\in\{0,1\}^*$", ma la $y_x$ che risulta dalla dimostrazione non è una parola in $\{0,1\}^*$.
	**1.1** È tuttavia gestibile con le codifiche binarie, e si sa trasformare una macchina di Turing definita su un alfabeto generico in una macchina di Turing definita sull'alfabeto $\{0,1\}$ e in modo tale che le due macchine siano polinomialmente correlate.
2. Poi, quel che si chiede al Genio è "x appartiene ad L?"
	**2.1**  E se $x\in L$ il genio dice Sì, ma poi bisogna verificare la parola $y_x$ che viene comunicata. Per questo, se $x\in L$, $y_x$ prende il nome di *dimostrazione* o **certificato** per x.
## Una nuova caratterizzazione 
Non resta che dimostrare la seconda parte del [[Lezione 19 - Caratterizzazione di NP#..ad una nuova caratterizzazione..|teorema]]: dobbiamo dimostrare che $L\in NP$, ossia che esistono una macchina di Turing non deterministica NT e un intero $a$ tale che:
- Per ogni $x\in L$, $NT(x)$ accetta e $ntime(NT,x)\in O(|x|^a)$;
- Per ogni $x\notin L$, $NT(x)$ non accetta.
Si dimostra che esistono $NT$ e $a$:
1)  Si costruisce $NT$:
	- Sfruttando ciò che si sa sulle parole in L e usando T
2) Si dimostra che $NT$ accetta L
3) Si dimostra che, sulle parole di L, $NT$ opera in tempo polinomiale
### 1) Si costruisce NT
	Sfruttando quello che si sa sulle parole in L e usando T
Di L, si sa che:
- $x\in L\iff\exists y_x\in\{0,1\}^*:|y_x|\leq|x|^k\land T(x,y_x)\text{accetta}\land dtime(T,x,y_x)\in O(|x|^k)$ dove T, h e k si conoscono. 
	- Infatti, le ipotesi sono "dato L, esistono una macchina di Turing deterministica T e due costanti $h,k\in\mathbb N$ tali che..."
Allora si costruisce una macchina NT che opera in due fasi: con input x:
- Fase **1**: NT sceglie non deterministicamente una parola binaria $y$ di lunghezza $|y|\leq|x|^k$
- Fase **2**: NT invoca $T(x,y)$ e, se $T(x,y)$ accetta entro $O(|x|^k)$ passi allora NT accetta.

>[!note]- Oss.
>$f(n)=n^k$ è una funzione time-costructible ( sia $T_f$ il trasduttore che la calcola, in unario, con $dtime(T_f,n)\in O(n^k)$)

In dettaglio:
#### Fase 1

$$\begin{align}&B\leftarrow T_f(|x|);\\& i\leftarrow 1;\\& while(i\le B) do\space begin\\&\space\space\space\space\space\space\space\text{scegli y[i] nell'insieme \{0,1\}};\\&\space\space\space\space\space\space\space i\leftarrow i+1;\\&end\\&y\leftarrow y[1]y[2]...y[B];\end{align}$$
Assumiamo che, se $x\in L$, T accetti entro $c|x|^h\in O(|x|^h)$ passi.
- Anche $g(n)=c\cdot n^h$ è una funzione time-constructible
#### Fase 2
Con input x e y:
$$\begin{align}&A\leftarrow T_g\\&i\leftarrow1;\\&while(i\le A)do\space begin\\&\space\space\space\space\space\space\space\space\space \text{simula l'esecuzione della i-esima istruzione seguita da T(x,y)}\\&\space\space\space\space\space\space\space\space\space if(\text{T è entrato in }q_A)then\text{ accetta e termina};\\&\space\space\space\space\space\space\space\space\space else\space i\leftarrow i+1;\\& end\end{align}$$
Se $x\in L$ allora *esiste* $y_x\in\{0,1\}^*:|y_x|\le|x|^k\land T(x,y_x)$ accetta.
- Allora, **esiste una sequenza di scelte** nella fase 1 che genera $y_x$;
- Allora, nella fase 2, $T(x,y_x)$ accetta entro $c\cdot |x|^h$ passi;
- Allora, anche la computazione deterministica di $NT(x)$ corrispondente alla sequenza di scelte che ha generato $y_x$ accetta.
**Questo dimostra che, se $x\in L$, allora $NT(x)$ accetta**.
Se $x\notin L$ allora *non esiste alcuna* $y_x\in\{0,1\}^*:|y_x|\le|x|^k\land T(x,y_x)$ accetta.
- Allora, **qualunque sia la sequenza di scelte** nella fase 1 per generare $y$;
- Nella fase 2, $T(x,y_x)$ non accetta;
- Questo significa che nessuna computazione deterministica di $NT(x)$ (corrispondente ciascuna ad una diversa sequenza di scelte nella fase 1) accetta.
***Questo dimostra che, se $x\notin L$, allora $NT(x)$ non accetta***.
Ora dimostriamo che, sulle parole di $L$, $NT$ opera in tempo polinomiale.
La fase 1 termina in $O(|x|^k)$ operazioni. La fase 2 termina in $O(|x|^k)$ operazioni.
***Quindi, partendo dall'ipotesi, abbiamo dimostrato che $L\in NP$***
## Una caratterizzazione alternativa
Ogni problema
- Il cui predicato ha la forma $\pi(x, S(x))=$ esiste $y\in S(x)$ tale che $\eta(x,y)$.
- In cui la lunghezza di un elemento $y\in S(x)$ è polinomiale in $|x|$.
- *In cui la verifica che $y$ soddisfi il predicato $\eta$, richiede tempo deterministico polinomiale in $|x|$*
Appartiene ad $NP$.
Utilizzando la notazione mostrata in precedenza, **un elemento $y\in S(x)$ è un ***certificato* per l'istanza x del problema**.
E dire che *sceglierlo richiede tempo non deterministico polinomiale in $|x|$* è equivalente a dire **che ha lunghezza polinomiale in $|x|$**.