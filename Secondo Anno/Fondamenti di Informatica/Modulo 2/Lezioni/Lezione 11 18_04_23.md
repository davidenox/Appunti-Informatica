# Classi di complessità
## Alla ricerca della macchina più veloce
Ci siamo lasciati con la storia della correlazione polinomiale:**Tutti i modelli (deterministici) sono correlati polinomialmente** 				
Tuttavia, se ho una macchina di Turing $T$ che decide linguaggio $L\subseteq\Sigma^*$ tale che, per ogni $x\in\Sigma^*$, $dtime(T, x)\leq|x|^3$  e un’altra macchina $T_4$ che decide lo stesso linguaggio L e tale che , per ogni $x\in\Sigma^*$, $dtime(T_4, x)\leq\frac{|x|^3}{4}$ .
Conviene scegliere $T_4$, per decidere $L$.
Ma se poi qualcuno progetta ancora un’altra macchina $T_8$ che decide lo stesso linguaggio L e tale che $dtime(T_8, x)\leq\frac{|x|^3}{8}$Allora sceglierò quest’ultima!
Ma nella Teoria della Complessità Computazionale le cose non sono proprio così…
>[!important]- Teorema 6.7 (Accelerazione lineare)
> Sia $L\subseteq\Sigma^*$ un linguaggio deciso da una macchina di Turing deterministica ad un nastro $T$ tale che, per ogni $x\in\Sigma^*$, $dtime(T,x) = t(|x|)$ e sia $k > 0$ una costante. Allora:
>1. esiste una macchina di Turing ad un nastro $T_1$ tale che $T_1$ decide $L$ e, per ogni $x\in\Sigma^*$, $dtime(T1, x)\leq\frac {t(|x|)}{k}+O(|x|^2)$;
>2. esiste una macchina di Turing a due nastri $T_2$ tale che $T_2$ decide $L$ e, per ogni $x\in\Sigma^*$, $dtime(T2, x)\leq\frac {t(|x|)}{k} +O(|x|)$.

Questo teorema ci dice che, dato un qualunque algoritmo, esiste sempre un algoritmo più veloce del primo di un fattore costante! 
Resta da capire: perché i due addendi $O(|x|^2)$ e $O(|x|)$?
Essi derivano dal fatto che, per poter essere più veloci, le macchine $T_1$ e $T_2$ devono innanzi tutto codificare in forma compressa il proprio input (vedi prossimo teorema): se la codifica compressa viene scritta su un nastro apposito (come fa $T_2$ sul suo secondo nastro) sono sufficienti $O(|x|)$ passi; se si dispone di un solo nastro (il caso di $T_1$) occorrono $O(|x|^2)$ passi.
## Risparmiare memoria
Si può dimostrare qualcosa di analogo nel caso della funzione dspace
>[!important]- Teorema 6.6 (Compressione lineare)
>Sia $L\subseteq\Sigma^*$ un linguaggio deciso da una macchina di Turing deterministica ad un nastro $T$ tale che, per ogni $x\in\Sigma^*$, $dspace(T, x) = s(|x|)$ e sia $k > 0$ una costante. Allora:
>1. esiste una macchina di Turing ad un nastro $T_1$ tale che $T_1$ decide $L$ e, per ogni $x\in\Sigma^*$, $dspace(T_1, x)\leq\frac {s(|x|)}{k} +O(|x|)$

Questo teorema ci dice che, dato un qualunque algoritmo, esiste sempre un algoritmo che una una frazione costante della memoria del primo! 
Resta da capire: perché l’addendo $O(|x|)$?
Esso deriva dal fatto che l’input di $T_1$ è lo stesso di $T$. Pertanto $T_1$ deve innanzi tutto codificare in forma compressa il proprio input e poi lavorare sull’alfabeto compresso: osservate che l’alfabeto compresso è $\Sigma^k$ (ossia, un carattere dell’alfabeto compresso è una parola di k caratteri di $\Sigma$) e che l’alfabeto di $T_1$ è $\Sigma^k\cup\Sigma$.
## Classi di complessità (deterministiche)
Siamo pronti a raggruppare i linguaggi in base all’efficienza delle macchine che li decidono. *Per esempio, potremmo considerare l’insieme dei linguaggi  tali che la la migliore macchina che li decide ha una certa efficienza*. Un linguaggio L è un insieme di parole – contiene, tipicamente, infinite parole, e una macchina che decide L, tipicamente, esegue un numero diverso di operazioni quando opera su input diversi – *anche su input diversi che hanno la stessa lunghezza*.
Ve la ricordate, ad esempio, $T_{PPAL}$, che accettava parole palindrome di lunghezza pari sull’alfabeto $\{a,b\}$? Ebbene: $T_{PPAL}(abababab)$ rigetta dopo aver eseguito 10 quintuple, $T_{PPAL}(abbbbbba)$ accetta dopo aver eseguito all’incirca 45 quintuple (deve fare avanti e indietro un sacco di volte (considerazioni analoghe possono essere fatte per la misura dspace).
Cosa significa dire che una macchina che decide un linguaggio ha una certa efficienza? Significa che si comporta “bene” (con quella efficienza) almeno *su qualche input*? O che si comporta “bene” su *ogni input*?
Siamo pronti a raggruppare i linguaggi in base all’efficienza delle macchine che li decidono. *Per esempio, potremmo considerare l’insieme dei linguaggi  tali che **la migliore macchina che li decide** ha una certa efficienza*.
La risposta corretta è la seconda: vogliamo che la macchina che decide un linguaggio $L\subseteq\Sigma^*$ si comporti ”bene” su **ogni** parola $x\in\Sigma^*$.
Poi, non possiamo scegliere la “*migliore*” macchina che decide un linguaggio, perché se un linguaggio è deciso da una macchina che ha una certa efficienza, quel linguaggio è deciso anche da una macchina che è efficiente il doppio. O il triplo. O il quadruplo…
E per risolvere questa questione ricorriamo alla notazione O
>[!important]- Notazione 0
>Un linguaggio $L$ appartiene all’insieme caratterizzato dalla “efficienza temporale” individuata dalla funzione totale e calcolabile f se esiste una macchina $T$ che decide $L$ e che, per ogni parola x sull’alfabeto di $L$, termina in $O( f(|x| ) )$ istruzioni.

E analogamente a proposito di “efficienza spaziale” 
**OSSERVATE BENE**: è sparita la richiesta di “*migliore*” macchina che decide L.
Le classi che misurano “efficienza temporale” nel caso deterministico si chiamano $DTIME$: data una funzione totale e calcolabile f, $DTIME[f(n)]=\{L\subseteq\{0,1\}^*$ tali che esiste una macchina deterministica $T$ che decide $L$ e, per ogni $x\in\{0,1\}^*$, $dtime(T,x)\in O(f(|x|))\}$
In Teoria della Complessità Computazionale si parla di classi invece che di insiemi.
**ATTENZIONE**: dtime (*minuscolo*) è la <u>misura di complessità</u>, ossia, una funzione; DTIME (*maiuscolo*) è una <u>classe di complessità</u>, ossia, un insieme!
$DTIME[ f(n) ] = DTIME[ f(n)/2 ] = DTIME[2 f(n)+58 ] = …$ come è giusto che sia a seguito del Teorema di accelerazione lineare.
Le classi che misurano “efficienza spaziale” nel caso deterministico si chiamano $DSPACE$: data una funzione totale e calcolabile f, $DSPACE[f(n)] = \{L\subseteq\{0,1\}^*$ tali che esiste una macchina deterministica $T$ che decide $L$ e, per ogni $x\in\{0,1\}^*,dspace(T,x)\in O(f(|x|))\}$.
## Classi di complessità (non deterministiche)
Le stesse considerazioni che ci hanno condotto a definire le classi di complessità deterministiche, possono essere ripetute anche nel caso non deterministico.
Le classi che misurano “efficienza temporale” nel caso non deterministico si chiamano $NTIME$: data una funzione totale e calcolabile f, $NTIME[f(n)] = \{L\subseteq\{0,1\}^*$ tali che esiste una macchina non deterministica $NT$ che $ACCETTA$ $L$ e, per ogni $x\in L$, $ntime(NT,x)\in O(f(|x|))\}$.
Ma perché una classe non deterministica è definita in base al tempo di accettazione, invece che del tempo di decisione? Ricordate quello che abbiamo detto la scorsa lezione: *se sappiamo che un linguaggio è accettato entro un certo numero di istruzioni, sappiamo che quel linguaggio è decidibile, <u>ma non sappiamo quanto tempo occorre a rigettare le parole del suo complemento</u>*.
E a noi interessa accettare le parole del linguaggio – non di rifiutare quelle del complemento.
Le classi che misurano “efficienza spaziale” nel caso non deterministico si chiamano $NSPACE$: data una funzione totale e calcolabile f, $NSPACE[f(n)]=\{L\subseteq\{0,1\}^*$ tali che esiste una macchina non deterministica $NT$ che $ACCETTA$ $L$ e, per ogni $x\in L$ , $nspace(NT,x)\in O(f(|x|))\}$.
## Classi di complemento
Sia f una f*unzione totale e calcolabile*: 
1. La classe $coDTIME[f(n)]$ contiene i linguaggi il cui complemento è contenuto in $DTIME[(f(n)]$:
	$coDTIME[f(n)]=\{L\subseteq\{0,1\}^*$ tali che $L^C\in DTIME[f(n)]\}$; 
2. La classe $coDSPACE[f(n)]$ contiene i linguaggi il cui complemento è contenuto in $DSPACE[(f(n)]$:
	$coDSPACE[f(n)]=\{L\subseteq\{0,1\}^*$ tali che $L^C\in DSPACE[f(n)]\}$; 
3. La classe $coNTIME[f(n)]$ contiene i linguaggi il cui complemento è contenuto in $NTIME[(f(n)]$:
	$coNTIME[f(n)]=\{L\subseteq\{0,1\}^*$ tali che $LC\in NTIME[f(n)]\}$ ù
4. La classe $coNSPACE[f(n)]$ contiene i linguaggi il cui complemento è contenuto in $NSPACE[(f(n)]$:
		$coNSPACE[f(n)]=\{L\subseteq\{0,1\}^*$ tali che $L^C\in NSPACE [f(n)]\}$.
### Un paio di questioni
Innanzi tutto, perché ci limitiamo a considerare linguaggi definiti sull’alfabeto $\{0,1\}$?
In realtà, lo facciamo perché è più comodo, ma potremmo utilizzare un alfabeto qualsiasi (e, quando ci farà comodo, lo faremo).
Sappiamo che se un linguaggio è deciso da una macchina definita su un alfabeto qualsiasi, allora esiste anche una macchina definita su $\{0,1\}$ che lo decide. E le due macchine, sappiamo, sono pure polinomialmente correlate!
Poi, alla funzione f che che definisce una classe di complessità (ad esempio, $DTIME[f(n)]$ ) diamo il nome di **funzione limite**.
Ma perché viene sempre richiesto che una funzione limite sia totale e calcolabile? Ve li ricordate gli assiomi di Blum?
## Relazioni fra classi di complessità
>[!important]- Teorema 6.8 
>Per ogni funzione totale calcolabile $f :\mathbb N\rightarrow\mathbb N$  ,
>$DTIME[ f (n)]\subseteq NTIME[ f (n)]$ e $DSPACE[ f (n)]\subseteq NSPACE[ f (n)]$. 

Facile: una macchina di Turing deterministica è una particolare macchina di Turing non deterministica avente grado di non determinismo pari ad 1 e, inoltre, ogni parola decisa *in un certo numero* di passi è anche accettata in *quel certo numero di passi*, e una parola decisa utilizzando un *certo numero di celle* è anche accettata in *quel certo numero di celle*.
>[!important]- Teorema 6.9 
>Per ogni funzione totale calcolabile $f :\mathbb N\rightarrow\mathbb N$ ,
>$DTIME[ f (n)]\subseteq DSPACE[ f (n)]$ e $NTIME[ f (n)]\subseteq NSPACE[ f (n)]$. 

Segue direttamente dal Teorema 6.1. 
Sia $L\subseteq\{0,1\}^*$ tale che $L\in DTIME[f(n)]$: 
allora, esiste una macchina di Turing deterministica $T$ che decide $L$ e tale che, per ogni $x\in\{0,1\}^*$, $dtime(T,x)\in O(f(|x|))$, poiché $dspace(T,x)\leq dtime(T,x)$. Allora, $dspace(T,x)\leq dtime(T,x)\in O(f(|x|))$.
Questo implica che $dspace(T,x)\in O(f(|x|))$ e che, dunque, $L\in DSPACE[f(n)]$ (analogo il caso non deterministico).
>[!important]- Teorema 6.10
>Per ogni funzione totale calcolabile $f:\mathbb N\rightarrow\mathbb N$:
>$DSPACE[ f (n)]\subseteq DTIME[2^{O(1)f(n)}]$ e $NSPACE[ f (n)]\subseteq NTIME[2^{O(1) f (n)} ]$.

Sia $L\subseteq \{0,1\}^*$ tale che $L\in DSPACE[f(n)]$: allora, esiste una macchina di Turing deterministica $T$ che decide $L$ e tale che, per ogni $x ∈ \{0,1\}^*$, $dspace(T,x)\in O(f(|x|))$. 
Poiché $$\begin{align}\\&
dtime(T,x)\leq dspace(T,x)|Q|(|\Sigma|+1)^{dspace(T,x)}=dspace(T,x)|Q|3^{dspace(T,x)}=\\& =2^{log\space dspace(T,x)}|Q|[2^{log3}]^{dspace(T,x)}=\\& =|Q|2^{log\space dspace(T,x)+dspace(T,x)log 3}\leq|Q| 2^{[1+log 3]dspace(T,x)} 
\end{align}$$
Allora $dtime(T,x)\in O(2^{O(1)f(|x|)})$ e, dunque, $L\in DTIME[ 2^{O(1) f(n)} ]$ (la dimostrazione per il caso non deterministico è analoga).
>[!important]- Teorema 6.11 
>Per ogni funzione totale calcolabile $f:\mathbb N\rightarrow\mathbb N$,
>$DTIME[ f (n)] = coDTIME[f (n)]$ e $DSPACE[ f (n)] = coDSPACE[f (n)]$.

Sia $L\subseteq \{0,1\}^*$ tale che $L\in DTIME[f(n)]$: allora, esiste una macchina di Turing deterministica $T$ che decide $L$ e tale che, per ogni $x\in\{0,1\}^*$, $dtime(T,x)\in O(f(|x|))$. 
Poiché $T$ decide $L$, allora $T(x)=q_A$ se $x\in L$, e $T(x)=q_R$ se $x\in {0,1}^*-L = L^C$.
Costruiamo una macchina $T’$ identica a $T$ tranne per il fatto che, rispetto a $T$, gli stati di accettazione e di rigetto di $T’$ sono invertiti, allora, per ogni $x\in \{0,1\}^*$, $dtime(T’,x)\in O(f(|x|))$, e, inoltre, $T’(x)=q_R$ se $x\in L$, e $T’(x)=q_A$ se $x\in \{0,1\}^*-L = L^C$.
Dunque, $T’$ decide $L^C$ e, per ogni $x\in\{0,1\}^*$, $dtime(T’,x)\in O(f(|x|))$.
Quindi, $L^C\in DTIME[f(n)]$.
Poiché $L$ è un qualunque linguaggio in $DTIME[f(n)]$ e, quindi, $L^C$ è un qualunque linguaggio in $coDTIME[f(n)]$, questo significa che: 
1. per ogni linguaggio $L^C\in coDTIME[f(n)]$, $L^C\in DTIME[f(n)]$ – ossia, $coDTIME[ f (n)]\subseteq DTIME[f (n)]$; 
2. per ogni linguaggio $L\in DTIME[f(n)]$, poiché $L^C\in DTIME[f(n)]$, allora  $L\in coDTIME[f(n)]$, ossia $DTIME[ f (n)]\subseteq coDTIME[f (n)]$. 
La dimostrazione per $DSPACE$ e $coDSPACE$ è analoga. 
## Classi "poco precise"
Attenzione: l’utilizzo di O nella definizione delle classi di complessità ha come conseguenza che esse non caratterizzino con precisione i linguaggi; nel senso che, se dimostriamo che un certo linguaggio $L$ è contenuto, ad esempio, in $DTIME[f(n)]$ (per qualche funzione totale e calcolabile f), allora esiste una serie infinita di classi $DTIME$ nelle quali $L$ è contenuto!
Ricordiamo che, date $f:\mathbb N\rightarrow\mathbb N$ e $g:\mathbb N\rightarrow\mathbb N$ due funzioni, $f(n) \in O(g(n))$ se
1. esistono $n_0\in\mathbb N$ e $c\in\mathbb N$ tali che, per ogni $n\geq n_0$, $f(n)\leq c\space g(n)$;
2. $\exists n_0\in\mathbb N\exists c\in\mathbb N:\forall n\geq n_0[f(n)\leq c\space g(n)]$.
Ossia, $O(f(n))\subseteq O(g(n))$  e da questo segue il seguente teorema:
>[!important]- Teorema 6.12 
>Per ogni coppia di funzioni totali calcolabili $f:\mathbb N\rightarrow\mathbb N$ e $g:\mathbb N\rightarrow\mathbb N$  tali che $\exists n_0\in\mathbb N:\forall n\geq n_0 [ f(n)\leq g(n) ]$ – ossia $f(n)\leq g(n)$  **definitivamente**:
>$DTIME[ f (n)] \subseteq DTIME[g(n)]$ 	$NTIME[ f (n)]\subseteq NTIME[g(n)]$,
>$DSPACE[ f (n)]\subseteq DSPACE[g(n)]$ 	$NSPACE[ f (n)]\subseteq NSPACE[g(n)]$. 
>Infatti, $O(f(n))\subseteq O(g(n))$.

E questo significa che: **se collochiamo un linguaggio $L$, ad esempio, in $DTIME[f(n)]$, questo non implica che $L$ non possa appartenere anche a qualche classe $DTIME[r(n)]$ tali che, definitivamente, $r(n) \leq  f(n)$**.
Che, detto altrimenti, significa che qualcuno potrebbe progettare per decidere $L$ un algoritmo più efficiente del nostro!
Perciò, aver collocato un linguaggio $L$, ad esempio, in $DTIME[f(n)]$,  è aver fatto solo metà del lavoro. L’altra metà sarebbe dimostrare che $L$ non appartiene a $DTIME[r(n)]$ per alcuna funzione $r(n)$ tale che, definitivamente, $r(n)\leq f(n)$.