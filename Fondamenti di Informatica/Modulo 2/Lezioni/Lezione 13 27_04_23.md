# Specifiche classi di complessità
>[!info]- Siamo al paragrafo 6.6, pronti a definire alcune fra le più rilevanti classi di complessità

P =  $U_{k\in\mathbb N}DTIME[n^k]$ :
- La classe dei linguaggi *decidibili in tempo deterministico polinomiale*; 
NP =$U_{k\in\mathbb N}NTIME[n^k]$ : 
- La classe dei linguaggi *accettabili in tempo non deterministico polinomiale*; - ma anche *decidibili in tempo non deterministico polinomiale*!
PSPACE =  $U_{k\in\mathbb N}DSPACE[n^k]$ :
- La classe dei linguaggi *decidibili in spazio deterministico polinomiale*; 
NPSPACE =  $U_{k\in\mathbb N}NSPACE[n^k]$ :
- La classe dei linguaggi *accettabili in spazio non deterministico polinomiale*; - ma anche *decidibili in spazio non deterministico polinomiale*!
EXPTIME = $U_{k\in\mathbb N}DTIME[2^{p(n,k)}]$ :
- La classe dei linguaggi *decidibili in tempo deterministico esponenziale* ove l’esponente che descrive la funzione limite è un polinomio in $n$ di grado $k$ – indicato come $p(n,k)$;
NEXPTIME= $U_{k\in\mathbb N}NTIME[2^{p(n,k)}]$ :
- La classe dei linguaggi *accettabili in tempo non deterministico esponenziale* (ove l’esponente che descrive la funzione limite è un polinomio in $n$ di grado $k$); 
- - ma anche *decidibili in tempo non deterministico esponenziale*!
Infine, una classe di complessità di funzioni: la classe delle **funzioni (totali) calcolabili in tempo deterministico polinomiale**: 
$FP=U_{k\in\mathbb N}\{f:\Sigma_1^*\rightarrow\Sigma_2^*:$ *esiste una macchina di Turing deterministica $T$ 			(di tipo trasduttore) che calcola f e, per ogni* $x\in\Sigma_1^*, dtime(T,x)\in O(|x|^k)\}$. 
## Proprietà - Corollario 6.2
$P\subseteq NP ,PSPACE\subseteq NPSPACE$ e $EXPTIME\subseteq NEXPTIME$
- Conseguenza diretta del Teorema 6.8: una macchina deterministica è una macchina non deterministica con grado di non determinismo 1.
$P\subseteq PSPACE$ e $NP\subseteq NPSPACE$
- Sono conseguenza diretta del Teorema 6.9: per ogni funzione totale e calcolabile f,	$DTIME[f(n)]\subseteq DSPACE[f(n)]$ e $NTIME[f(n)]\subseteq NSPACE[f(n)]$ 
- $PSPACE\subseteq EXPTIME$ e $NPSPACE\subseteq NEXPTIME$
- Sono conseguenza diretta del Teorema 6.10: per ogni funzione totale e calcolabile f, $DSPACE[f(n)]\subseteq DTIME[2^{O(f(n))}]$ e $NSPACE[f(n)]\subseteq NTIME[2^{O(f(n))}]$
$NP\subseteq EXPTIME$
- Conseguenza diretta del Teorema 6.17: per ogni funzione time-constructible f, $NTIME[f(n)]\subseteq DTIME[2^{O(f(n))}]$ , e i polinomi sono funzioni time-constructible.
## Relazioni interessanti, ma...
Tutte le relazioni fra classi complessità che abbiamo, fino ad ora, dimostrato sono  **inclusioni improprie**. Ossia, per ciascuna di quelle relazioni _non_ siamo in grado di dimostrare né l’inclusione propria né la coincidenza delle due classi che la costituiscono. 
Ad esempio, sappiamo che : 
1. Tutti i linguaggi che sono in $PSPACE$ sono anche in $EXPTIME$;
2. Tutti i linguaggi che sono in $P$ sono anche in $NP$.
Ma non sappiamo rispondere alle seguenti domande :
1. È possibile che tutti i linguaggi in $EXPTIME$ sono anche in $PSPACE$? Ossia, che $PSPACE = EXPTIME$?
2. Esiste almeno un linguaggio in $EXPTIME$ che non può essere deciso in spazio polinomiale? Ossia, che $PSPACE\subset EXPTIME$
Si tratta, se volete, di relazioni deboli, e sarebbe tremendo se si dimostrasse che tutte quelle inclusioni improprie fossero, in effetti, delle uguaglianze!
**Non saremmo affatto in grado di classificare i problemi in “facili” e “difficili”**.
## L'unica relazione di contenimento stretto
In effetti, uno strumento che dimostra l’inclusione stretta fra classi di complessità ce l’abbiamo: il Teorema di gerarchia temporale:
>[!important]- Teorema 6.15 (Teorema di gerarchia temporale) 
>Siano $f,g:\mathbb N\rightarrow\mathbb N$ due funzioni tali che f è time-constructible e	$\lim_{n\rightarrow\infty}\frac{g(n)log\space g(n)}{f(n)}= 0$ 
Allora, $DTIME[g(n)]\subset DTIME[f(n)]$ ossia, esiste un linguaggio L tale che $L\in DTIME[f(n)]$ e $L\not\in DTIME[g(n)]$. 

Dimostriamo ora il seguente caso particolare del Teorema di gerarchia temporale: 
>[!important]- Teorema 6.18( $P\subset EXPTIME$ )
>È un caso particolare del Teorema di gerarchia temporale: 
>1) le funzioni limite per la classe $P$ sono i polinomi, ossia, **$DTIME[g(n)]$ è una delle classi contenute in $P$ se e solo se $g(n)=n^k$** per qualche costante $k$; 
>2) se $f(n) =2^{hn}$ per qualche *costante* $h$ allora $DTIME[f(n)]$ è contenuta in $EXPTIME$ 
>3) $lim_{n\rightarrow\infty}\frac{g(n)log\space g(n)}{f(n)}\leq lim_{n\rightarrow\infty}\frac{g(n)\cdot g(n)}{f(n)}\leq lim_{n\rightarrow\infty}\frac{n^{2k}}{2^{hn}}= 0$

La dimostrazione consiste nel costruire un particolare linguaggio $L\subset\{0,1\}^*$ tale che: 
1. L è deciso in tempo deterministico $t(n)=n2^{2n}$ – cioè $L\in DTIME[n2^{2n}]$;
2. Contemporaneamente, $L\not\in DTIME[2^n]$. 
Questo dimostrerà che $DTIME[2n]\subset DTIME[n2^{2n}]$
Quindi, poiché: 
1. $P\subseteq DTIME[2^n]$ e $DTIME[n2^{2n}]\subseteq DTIME[2^n2^{2n}]\subseteq EXPTIME$
avremo: $P\subset DTIME[2^n]\subset DTIME[n2^{2n}]\subseteq EXPTIME$, ossia,  avremo dimostrato che $P\subset EXPTIME$.
Definiamo, allora, il seguente linguaggio:$$L=\{z\in\{0,1\}^*:z=1^i0x\}$$ 
1. **$x$ è la codifica binaria di una parola $k\in\mathbb N$  che è la codifica di una macchina di Turing deterministica ad un nastro di tipo riconoscitore $T_k$ definita sull’alfabeto $\{0, 1\}$** ;
2. **$T_k(z)$ termina in $2^{2|z|}$ passi** ; 
3. $T_k(z)$ **rigetta**. 
Chiariamo:
“$z=1^i0x$“ significa che $z$ inizia con una sequenza di ‘1’ (lunga quanto gli pare);
(1) significa che la parola (binaria) che inizia a destra del primo ‘0’ di $z$ è un intero $k$ che è la codifica di una macchina di Turing $T_k$;
(2)(3) significa che, se alla macchina $T_k$  si dà in input $z$ (al cui interno è codificato, in binario, $k$), la computazione $T_k(z)$ termina in $2^{2|z|}$ passi , e termina nello stato di rigetto. 
Non vi ricorda un po’ l’halting problem questa storia della macchina che prende sé stessa come input?

**Primo passo**: dimostriamo che $L\not\in DTIME[2^n]$. 
Supponiamo per assurdo che $L\in DTIME[2^n]$, cioè che esistono :
1. Una macchina di Turing deterministica ad un nastro *$T_h$ – l’intero h descrive la macchina $T_h$*;
2. Una costante $c\in\mathbb N$.   
Tali che $T_h$ decide $L$ in tempo $c\space 2^n$, dunque: **qualunque sia $z$ , la computazione $T_h(z)$ termina entro $c\space 2^{|z|}$ passi, termina nello stato di accettazione se $z\in L$ e termina nello stato di rigetto se $z\not\in L$**
Ora: indichiamo con $x_h$ la codifica binaria di $h$, dove $T_h$ è la macchina che decide $L$, e scegliamo $z=1^i0x_h$ con i scelto in modo tale che sia $c\space 2^{|z|}\leq 2^{2|z|}$ : 
e questa scelta di i è un punto importante.
1) abbiamo una macchina $T_h$ che decide $L$ e, qualunque sia $z$, $Th(z)$ termina entro $c\space 2^{|z|}$ passi; 
2) abbiamo $x_h$ che è la codifica binaria di $h$; 
3) abbiamo $z=1^i 0 x_h$ con **i** scelto in modo tale che sia $c\space 2^{|z|}\leq 2^{2|z|}$. 
Osserviamo: da 1) e da 3) segue che **la computazione $T_h(z)$ termina in $c\space 2^{|z|} \leq 2^{2|z|}$ passi**. 
Ora, chiediamoci: **$z$ appartiene a $L$ oppure no?**
$z\in L$ *se e soltanto se $T_h(z)$ rigetta*. Quindi, $z\in L$ solo se $z\not\in L$. Da qui l'**assurdo**.

**Secondo passo**: dimostriamo che $L\in DTIME[n2^{2n}]$ 
>[!warning]- OSSERVAZIONE 
>$f(n)=2^{2n}$ è una funzione time-constructible. Allora, esiste una macchina di Turing $T_C$ di tipo trasduttore che, con input $n$ in notazione unaria, scrive sul nastro di output il valore $2^{2n}$, in unario, in tempo proporzionale a $2^{2n}$.

Per decidere $L$ usiamo una variante $U’$ a **6 nastri** della macchina di Turing universale $U$ perché, per decidere $L$, abbiamo bisogno di simulare qualunque macchina di Turing descritta nelle sue parole.
1. I primi 4 nastri hanno funzioni analoghe a quelle dei nastri della macchina $U$: su $N_1$, viene memorizzato l’input $z$, su $N_2$, se $z$ è nella forma $1^i0x$, viene scritta la parola $x$, ossia, la parola che dovrebbe essere la descrizione binaria delle quintuple di una macchina $T_h$, su $N_3$ viene memorizzato, ad ogni passo, lo stato attuale della macchina $T_h$, *su $N_4$ viene memorizzato lo stato di **rigetto*** della macchina $T_h$; 
2. $N_5$ è il *nastro su cui verrà scritto in unario il valore* $|z|$; 
3. $N_6$ è il *nastro su cui verrà scritto in unario il valore* $2^{2|z|}$ .
$U’$, con input $z$ sul primo nastro, lavora nelle seguenti sei fasi: 
**FASE 1**- $U’$ verifica che $z$ sia della forma $1^i 0x$: se è così allora inizia la fase 2, altrimenti *rigetta*; 
**FASE 2** - $U’$ verifica che $x$ sia la codifica binaria di un intero $h$ che sia la codifica di una macchina di Turing $T_h$: se è così allora $U’$ copia $x$ su $N_2$ ed ha inizio la fase 3, altrimenti *rigetta*; 
**FASE 3** - $U’$ copia lo stato iniziale di $T_h$ su $N_3$ e lo stato di rigetto di $T_h$ su $N_4$ ;
**FASE 4** - $U’$ scrive su $N_5$ $|z|$ in unario, ossia, $1^{|z|}$;
**FASE 5** - $U’$ simula, su $N_5$, il comportamento di $T_C(1^{|z|})$ scrivendo su $N_6$  il valore $2^{2|z|}$ in unario;
**FASE 6** - $U’$ si comporta come si comporterebbe $U$ sui nastri $N_1$ e $N_2$ (invertiti) contando, però, le istruzioni eseguite: 
- Ogni volta che viene eseguita una quintupla di $T_h(z)$, $U’$ sposta di una posizione la testina su $N_6$: 
	- *1*. Se $T_h(z)$ raggiunge lo stato di *rigetto* mentre su $N_6$ viene letto un ‘1’ allora $U’$ **accetta**;
	- *2*. Se $T_h(z)$ raggiunge lo stato di *accettazione* mentre su $N_6$ viene letto un ‘1’ allora $U’$ **rigetta**;
	- *3*. Se $T_h(z)$ *non* ha ancora raggiunto lo stato di rigetto quando su $N_6$ viene letto un ‘$\square$’ allora $U’$ **rigetta**. 

>[!important]- Osservazione 
>La **FASE 6*** non simula computazioni di $T_h$ che durano più di $2^{2|z|}$ passi.
>

Mostriamo che **se $z\in L$  allora $U’(z)$ accetta**:
1. $z = 1^i 0x_h$ - perciò $U’$ non rigetta durante la FASE 1; 
2. $x_h$ è la codifica binaria di una parola $h$ che codifica una macchina di Turing $T_h$ – perciò, $U’$ non rigetta durante la FASE 2; 
3. Poiché $z\in L$  allora $T_h(z)$ rigetta in $2^{2|z|}$  passi  - perciò, $U’$ accetta durante la FASE 6.
Mostriamo che **se $z\not\in L$  allora $U’(z)$ rigetta**:
e questo è lasciato come esercizio!

Ma quanto tempo impiega $U’$ a decidere $L$?
**In definitiva, $U’$ decide se $z\in L$ in $O(|z| 2^{2|z|} )$ passi: quindi $L\in DTIME[ n 2^{2n} ]$**.
## L'unica relazione di uguaglianza
La maggior parte delle relazioni fra classi complessità che abbiamo visto fino ad ora, sono **inclusioni improprie**. A parte le inclusioni proprie che derivano dal Teorema di gerarchia temporale, del quale abbiamo dimostrato un caso particolare: **Teorema 6.18: $P\subset EXPTIME$** .
In effetti, esiste anche un teorema che va nella direzione opposta – che dimostra, cioè, l’uguaglianza di due classi, una classe deterministica e una classe non deterministica:
>[!important]- Teorema 6.19 
>$PSPACE = NPSPACE$

Non studiamo, quest’anno, la dimostrazione di questo teorema.
