# Classi di complemento
## Classi di complessità complemento
>[!info]- Torniamo un attimo al paragrafo 6.6

Accanto alle classi introdotte all’inizio di questo paragrafo, possiamo considerare i corrispondenti complementi:
$coP = \{L\subseteq\{0,1\}^*:L^c\in P \}$, 
$coNP = \{L\subseteq\{0,1\}^*:L^c\in NP \}$, 
E, allo stesso modo, le classi
$coEXPTIME$, $coNEXPTIME$, $coPSPACE$.
E, in generale: $$\begin{align}\\& coDTIME[f(n)]=\{L\subseteq\{0,1\}^* : L^c\in DTIME[f(n) \},\\& 		  							   	coDSPACE[f(n)]=\{L\subseteq\{0,1\}^*:L^c\in DSPACE[f(n)\},\\& coNTIME[f(n)]=\{L\subseteq\{0,1\}^*:L^c\in NTIME[f(n)\},\\& coNSPACE[f(n)]=\{L\subseteq\{0,1\}^*:L^c\in NSPACE[f(n)\}\end{align}$$
Osserviamo che *nella definizione delle classi di complessità complemento* non viene specificato come vengono decisi (o accettati) i linguaggi che vi appartengono ma, invece, *viene specificato come vengono decisi (o accettati) i **complementi** dei linguaggi che vi appartengono*.
Tuttavia, questa differenza è irrilevante quando si parla di classi deterministiche.
>[!important]- Teorema 6.11 
>Per ogni funzione totale calcolabile $f:\mathcal N\rightarrow\mathcal N$ ,
>$DTIME[ f (n)] = coDTIME[f (n)]$ e  $DSPACE[ f (n)] = coDSPACE[f (n)]$.

E come viene dimostrato, in breve, questo teorema?
1. Si prende una macchina $T$ che decide $L$ tale che, per ogni $x$, $dtime(T,x)\in O(f(|x|))\space\space[ o dspace(T,x)\in O(f(|x|)) ]$;
2. Si costruisce una nuova macchina $T’$ complementando gli stati di accettazione e di rigetto di $T$ – ossia, si aggiungono le quintuple $\langle q_A, s, s, q’_R , F\rangle$ e $\langle q_R, s, s, q’_A , F\rangle$  per ogni $s\in\{0,1,\square\}$, dove $q’_A$ e $q’_R$ sono gli stati di accettazione e di rigetto di $T’$;
3. $T’$ **decide** $L^c$ e $dtime(T’,x)\in O(f(|x|))\space\space[ o\space dspace(T’,x)\in O(f(|x|)) ]$.
>[!important]- Corollario 6.3
>$P=coP$
>Ma anche $coPSPACE=PSPACE$

Possiamo arrivare alla stessa conclusione per le classi non deterministiche?
Cioè: possiamo utilizzare la stessa tecnica utilizzata nella dimostrazione del Teorema 6.11 nel caso non deterministico?

Possiamo complementare gli stati di **accettazione** e di rigetto di una macchina $NT$ che *accetta* un linguaggio $L$ al fine di *accettare* il complemento di $L$?

Perché la questione è proprio questa: le classi non deterministiche sono definite come classi di linguaggi *accettati* da macchine non deterministiche entro quantità limitate di istruzioni o celle di nastro
“Ma, come?!” state sicuramente pensando, dopo aver dimostrato che, sì, sono definite sulla base dell’accettazione ma, in effetti, siccome le funzioni limite sono time- e space-constructible, allora quei linguaggi sono anche **decisi** entro le stesse quantità di risorse?!

Allora: è vero, anche se $NP$ è definita come la classe dei linguaggi *accettati* in tempo non deterministico polinomiale, i linguaggi in $NP$ sono, in effetti, linguaggi decisi da macchine non deterministiche in tempo polinomiale.
Tuttavia, ricordiamo che una macchina di Turing non deterministica $NT$:
1. **Accetta** un input $x$ se ***esiste** una computazione deterministica in $NT(x)$ che termina in $q_A$*;
2. **Rigetta** un input $x$ se ***ogni** computazione deterministica in $NT(x)$ termina in $q_R$*.
Ecco: il problema è proprio in questa asimmetria nelle definizioni di accettazione e di rigetto.
## Facciamo un gioco
Proviamo ad applicare la stessa tecnica usata nel teorema 6.11 ad un macchina non deterministica $NT$
1. Costruiamo una nuova macchina $NT’$ invertendo gli stati di accettazione e di rigetto di $NT$;
2. Vediamo se $NT’$ accetta (oppure no) il complemento del linguaggio accettato da $NT$.
Cominciamo scegliendo un linguaggio $L\subseteq\{0,1\}^*$ accettato da una macchina di Turing non deterministica $NT$.
E ricordiamo che il linguaggio complemento di $L$ è $L^c = \{0,1\}^*- L$, ossia, per ogni $x\in\{0,1\}^*$:
1. se $x\in L$ allora $x\not\in L^c$;
2. se $x\not\in L$ allora $x\in L^c$.
Allora, una macchina non deterministica $NT^C$ accetta $L^c$ se, per ogni $x\in\{0,1\}^*$,
1. se $x\in L$ allora $NT^C(x)$ non accetta;
2. se $x\not\in L$ allora $NT^C(x)$ accetta.
e, quindi:
1. se $x\in L$ allora ***ogni** computazione deterministica in $NT^C(x)$ **non** termina in $q_A$*.
2. se $x\not\in L$ allora ***esiste** una computazione deterministica in $NT^C(x)$ che termina in $q_A$*.
Un attimo, però: prima di invertire gli stati di accettazione e di rigetto di $NT$, costruiamo una nuova macchina $NT_1$ che, ancora, accetta $L$.
Prendiamo $NT$ ed aggiungiamo all’insieme delle sue quintuple le quintuple $\langle q_0, s, s, q_R , F\rangle$ per ogni $s\in\{0,1,\square\}$.
**ATTENZIONE**: *per ogni $x\in\{0,1\}^*$ esiste sempre una computazione deterministica di $NT_1(x)$ che termina in $q_R$*.
![[Pasted image 20230504100237.png|center]]

$NT_1$ **accetta** $L$ 
Infatti: per ogni $x\in L$: 
1. poiché $NT$ accetta $L$, allora $NT(x)$ accetta; 
2. allora, esiste una computazione deterministica di $NT(x)$ che termina in $q_A$;
3. ma quella stessa computazione deterministica compare anche in $NT_1(x)$. 
e, quindi, $NT_1(x)$ accetta.
![[Pasted image 20230504100707.png|center]]

E d’altra parte: per ogni $x\not\in L$ :
1. poiché $NT$ accetta $L$, allora $NT(x)$ non accetta (ossia, rigetta oppure non termina);
2. allora, non esiste alcuna computazione deterministica di $NT(x)$ che termina in $q_A$;
3. e allo stesso modo non esiste in $NT_1(x)$ una computazione deterministica che accetta.
e, quindi, $NT_1(x)$ non accetta.
![[Pasted image 20230504100956.png|center]]

Ci aspetteremmo che $NT_1^c$ accetti $L^c$, sarà davvero così?
Vediamo: scegliamo $x\in\{0,1\}^*$ e poniamo $x=x_1x_2... x_n$, ossia, $x_1\in\{0,1\}$ è il primo carattere di $x$, $x_2\in\{0,1\}$ il secondo e così via.
Se $x\in L^c$ :
1. In $NT_1(x)$ esiste la computazione deterministica $\langle q_0, x_1, x_1, q_R , F\rangle$ che termina in $q_R$;
2. Quella stessa computazione deterministica compare anche in $NT_1^C(x)$  che, però, in  termina in $q_A$.
allora $NT_1^C(x)$ **accetta** – Bene!
Se $x\not\in L^c$ :
1. Se fosse vero che $NT_1^C$ decide $L^c$ allora $NT_1^C(x)$ non dovrebbe accettare; 
2. Ma in $NT_1(x)$ esiste la computazione deterministica $\langle q_0, x_1, x_1, q_R , F\rangle$ che termina in $q_R$
3. E quella stessa computazione deterministica compare anche in $NT_1^C(x)$ che, però, in $NT_1^C$ termina in $q_A$
4. Allora $NT_1^C(x)$ **accetta** – MALE! $NT_1^C(x)$ *non* dovrebbe accettare se $x\not\in L^c$.
Invece $NT_1^C(x)$ accetta qualunque sia $x$. $NT_1^C$ ***non** accetta assolutamente $L^c$*.
Allora: anche se i linguaggi in NP sono, in effetti, linguaggi decisi da macchine di Turing non deterministiche in tempo polinomiale, il fatto che una macchina di Turing non deterministica $NT$:
1. *accetta* un input x se ***esiste** una computazione deterministica in $NT(x)$ che termina in $q_A$*;
2. *rigetta* un input x se ***ogni** computazione deterministica in $NT(x)$ termina in $q_R$*;
proprio questa asimmetria nelle definizioni di accettazione e di rigetto non permette di derivare una macchina che decide $L^c$ invertendo gli stati di accettazione e di rigetto di una macchina non deterministica che decide $L$.
E questo significa che non possiamo affermare che $coNP = NP$.
Ma, tutto questo ragionamento, ci permette forse di affermare che $coNP \not=NP$? La dimostrazione che $coNP = NP$ potrebbe seguire una strada completamente diversa da quella dell’inversione degli stati finali di una macchina non deterministica…
E allora?
## Questioni di congetture
Abbiamo detto più volte che la maggior parte delle inclusioni fra classi di complessità sono inclusioni deboli, nelle quali non si riesce a dimostrare che le due classi sono diverse ma non si riesce nemmeno a dimostrare che le due classi sono uguali!
Il caso più famoso è quello che riguarda le classi P e NP:
1. sappiamo che $P\subseteq NP$ – e, quindi, che ogni problema in P è contenuto anche in NP;
2. ma non sappiamo se $P = NP$ – ossia, se ogni problema in NP è contenuto, in effetti, in P;
3. né sappiamo se $P\not= NP$ – ossia, se esiste un problema in NP  che non è contenuto in P.
La *congettura fondamentale della teoria della complessità computazionale* ipotizza che $P\not= NP$, e sulla dimostrazione (o confutazione) di questa congettura pende una taglia da un milione di dollari!
Ed ora abbiamo appena scoperto una nuova congettura:
La *seconda congettura della teoria della complessità computazionale* ipotizza che $coNP\not= NP$.
## Relazione tra le due congetture
>[!important]- Teorema 6.23
>Se P = NP allora NP = coNP.
>

>[!important]- Dimostrazione 
>per il Corollario 6.3, P = coP
>per ipotesi: P = NP e quindi coP = coNP
>allora: NP = P = coP = coNP

Il teorema afferma che: *se è **falsa** la Congettura Fondamentale della Teoria della Complessità Computazionale **allora** è falsa anche la Seconda Congettura della Teoria della Complessità Computazionale*. 
Questo teorema può anche essere letto come: se $NP\not= coNP$ allora $P\not= NP$, 
ossia: *se è vera la Seconda Congettura della Teoria della Complessità Computazionale **allora** è vera anche la Congettura Fondamentale della Teoria della Complessità Computazionale*. 
L’affermazione inversa “se $NP = coNP$ allora $P = NP$” non è invece stata dimostrata, per questo l*e due congetture sono*, fino ad ora, *due congetture distinte*.
## Struttura della classe $coNP$
>[!important]- Teorema 6.24 
>La classe coNP è chiusa rispetto alla riducibilità polinomiale. 

Come detto sulla dispensa, “La dimostrazione è analoga a quella del Teorema 6.21 ed è lasciata per esercizio“.
Come per tutte le classi di complessità, anche per la classe coNP possiamo definire linguaggi completi rispetto alla riducibilità polinomiale

>[!important]- DEFINIZIONE 
>un linguaggio L è coNP-completo se
>1) $L\in coNP$
>2) per ogni linguaggio $L’\in coNP$, si ha che $L’\preceq L$

Come abbiamo visto la scorsa lezione, i linguaggi NP-completi sono i possibili linguaggi separatori fra P e NP, ossia, nell’ipotesi $P\not= NP$
un linguaggio NP-completo *non* può essere contenuto in P (sono i linguaggi “più difficili” all’interno di NP)
La stessa cosa ci proponiamo di fare nella classe coNP. Vogliamo mostrare che i linguaggi coNP-completi sono i candidati ad essere i linguaggi separatori fra NP e coNP, ossia che, nell’ipotesi $coNP\not= NP$ , un linguaggio coNP-completo non può essere contenuto in NP, e che i linguaggi coNP-completi sono i linguaggi “più difficili” all’interno di coNP.

>[!important]- Teorema 6.25 
>Un linguaggio L è NP-completo se e soltanto se il suo complemento $L^c$ è coNP-completo.
 
Sia L un linguaggio NP-completo – mostriamo che $L^c$ è coNP-completo:
1) $L\in NP$ e, quindi, $L^c\in coNP$. 
2) Dobbiamo mostrare che, per ogni $L_1\in coNP$, vale che $L_1\preceq L^c$.
Sia allora $L_1$ un *qualsiasi* linguaggio in coNP (ossia,  $\forall L_1\in coNP$ ): allora, $L_1^c\in NP$. Poiché L è completo per la classe NP, allora per ogni $L_0\in NP$, $L_0 \preceq L$: allora, in particolare, poiché $L_1^c\in NP$, vale che $L_1^c\preceq L$.
Questo significa che esiste una funzione $f_1:\{0,1\}^*\rightarrow\{0,1\}^*$	(ricordiamo che consideriamo linguaggi nell’alfabeto $\{0,1\}$) tale che $f_1\in FP$ e, per ogni $x\in\{0,1\}^*$, $x\in L_1^c$ se e soltanto se $f_1(x)\in L$. 
Ma questo è equivalente a dire che, per ogni $x\in\{0,1\}^*$, $x\not\in L_1^c$ se e soltanto se $f_1(x)\in L$, ossia, per ogni $x\in\{0,1\}^*$, $x\in L_1$ se e soltanto se $f_1(x)\in L^c$ , ossia, $L_1\preceq L^c$.
**Poiché $L_1$ è un qualsiasi linguaggio in coNP**, questo dimostra che $L^c$ è completo per coNP. 
Sia $L^c$ un linguaggio coNP-completo – mostriamo che L è NP-completo
1) $L^c\in coNP$ e, quindi, $L\in  NP$. 
2) Dobbiamo mostrare che, per ogni $L_1\in NP$, vale che $L_1\preceq L$.
Sia allora $L_1$ un qualsiasi linguaggio in NP (ossia,  $\forall L_1\in NP$ ): allora, $L_1^c\in coNP$, poiché $L^c$ è completo per la classe coNP, allora per ogni $L_0\in coNP$, $L_0\preceq L^c$: allora, in particolare, poiché $L_1^c\in coNP$, vale che $L_1^c\preceq L^c$. 
Questo significa che esiste una funzione $f_1:\{0,1\}^*\rightarrow\{0,1\}^*$(ricordiamo che consideriamo linguaggi nell’alfabeto $\{0,1\}$) tale che $f_1\in FP$ e, per ogni $x\in \{0,1\}^*$, $x\in L_1^c$ se e soltanto se $f_1(x)\in L^c$. 
Ma questo è equivalente a dire che, per ogni $x\in\{0,1\}^*$, $x\not\in L_1^c$ se e soltanto se $f_1(x)\not\in L^c$, ossia, per ogni $x\in\{0,1\}$,$x\in L_1$ se e soltanto se $f_1(x)\in L$ .
Poiché $L_1$ è un qualsiasi linguaggio in NP, questo dimostra che L è completo per NP. 
>[!important]- Teorema 6.26 
>Se esiste un linguaggio L NP-completo tale che $L\in coNP$, allora $NP = coNP$. 

Dimostriamo il teorema mostrando prima che   
1. $coNP\subseteq NP$ 
2. $NP\subseteq coNP$
Sia L un qualunque linguaggio NP-completo tale che che $L\in coNP$.
1. Poiché $L\in NP\cap coNP$, allora $L\in coNP$, e, allora, $L^c\in NP$. 
Poiché L è NP-completo allora, per il Teorema 6.25, $L^c$ è coNP-completo, 
quindi, per ogni $L’\in coNP$, si ha che $L’\preceq L^c$. 
Ma NP è chiusa rispetto alla riducibilità polinomiale (Teorema 6.22)che significa che se accade che $L_1\preceq L_2$  e $L_2\in NP$, allora $L1\in NP$ e $L’\preceq L^c$ e $L^c\in  NP$. Allora, per ogni linguaggio $L’\in coNP$, si ha che $L’\in NP$. 
E questo dimostra che $coNP\subseteq NP$. 
2. Mostriamo ora l’inclusione opposta. 
Poiché L è NP-completo allora, per ogni $L’’\in NP$ si ha che $L’’\preceq L$. 
Poiché $L\in NP\cap coNP$, allora, in particolare, $L\in coNP$. 
Ma *coNP è chiusa rispetto alla riducibilità polinomiale* (Teorema 6.24) 									che significa che se accade che $L_1\preceq L_2$  e $L2\in coNP$, allora $L_1\in coNP$ e $L’’\preceq L$ e $L\in coNP$. Allora per ogni $L’’\in NP$ si ha che $L’’\in coNP$.
E questo dimostra che $NP\subseteq coNP$. 
Infine, le due inclusioni $coNP\subseteq NP$ e $NP\subseteq coNP$ **dimostrano il teorema**. 
