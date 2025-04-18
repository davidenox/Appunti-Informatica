# Misure di complessità
>[!info]
>Siamo alla dispensa 6, paragrafo 6.1

Una **misura di complessità** è *una funzione **c*** che associa un valore numerico ad una macchina di Turing $T$ e ad un suo input x.
$c(T,x)$ intende rappresentare il “costo” della computazione $T(x)$.
Affinché c possa essere considerata una misura di complessità, essa deve soddisfare le due seguenti proprietà, note come **assiomi di Blum**: 
1) <u>c è definita per tutte e sole le computazioni che terminano.</u> Se una computazione T(x) non termina, non ha senso considerare che tale computazione abbia come costo un valore finito; 
2) <u>c deve essere una funzione calcolabile</u>, ossia, deve esistere una macchina di Turing $M$ che, ricevendo in input una macchina di Turing $T$ ed un suo input $x$, calcola $c(T,x)$ ogni volta $c(T,x)$ è definita (cioè, ogni volta $T(x)$ termina). 
Intuitivamente, questo significa che, il costo di una computazione $T(x)$ (che termina) dobbiamo poterlo calcolare effettivamente. ù
## Misure deterministiche
Iniziamo con le misure di complessità che si riferiscono a computazioni deterministiche.
- <u>Per ogni macchina di Turing deterministica T </u> (riconoscitore o trasduttore), definita su un alfabeto $\Sigma$; 
- <u>Per ogni</u> $x\in\Sigma^*$; 
Definiamo le due *funzioni* seguenti associate alla computazione $T(x)$: 																					
$$
dtime(T,x) =\begin{cases} 
numero\space di\space istruzioni \space eseguite\space da\space T(x)\space se\space T(x)\space termina &\\
non\space definita\space \space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space se\space T(x)\space non\space termina
\end{cases} $$
$$dspace(T,x)=\begin{cases}
numero\space di\space celle\space di\space memoria\space usate\space da\space T(x)\space se\space T(x)\space termina &\\non\space definita\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space se\space T(x)\space non\space termina
\end{cases}
$$
Osserviamo che $dtime$ e $dspace$ sono due funzioni parziali: non sono definite se $T(x)$ non termina.
Dimostriamo ora che le funzioni **dtime** e **dspace** soddisfano i due assiomi di Blum. 
1) Per ogni macchina di Turing deterministica $T$ e per ogni $x\in\Sigma^*$, $dtime(T,x)$ e $dspace(T,x)$ sono definite se e solo se $T(x)$ termina. 
2)  Dobbiamo mostrare che $dtime$ e $dspace$ sono calcolabili. 
Iniziamo da $dtime$:
Consideriamo una **modifica** $U_{dtime}$ della macchina di Turing universale $U$: 
aggiungiamo ad $U$ il nastro $N_5$ che fungerà da contatore del numero di istruzioni della computazione $T(x)$.
$U_{dtime}(T,x)$ si comporta come $U(T,x)$ con l’unica differenza che, dopo avere eseguito una quintupla della macchina $T$ su input $x$ ed essersi preparata ad eseguire la quintupla successiva, scrive un 1 sul nastro $N_5$ e muove a destra la testina su tale nastro. 
Al termine della computazione $U_{dtime}(T,x)$ (se essa termina) il nastro $N_5$ conterrà, codificato in unario ( serie di 1 ), il numero di passi eseguiti dalla computazione $T(x)$. Dunque, $dtime$ è una funzione calcolabile. 
La dimostrazione che $dspace$ è una funzione calcolabile è simile .
## Misure non deterministiche
Passiamo ora a definire  le misure di complessità che si riferiscono a computazioni non deterministiche. Per ogni macchina di Turing non deterministica $NT$ (riconoscitore, per forza!), definita su un alfabeto $\Sigma$, e per ogni $x\in\Sigma^*$ tali che $NT(x)$ **ACCETTA**, definiamo le due funzioni seguenti: 
1. $ntime(NT,x)$ = *minimo* numero di istruzioni eseguite da una computazione deterministica accettante di  $NT(x)$; 
2. $nspace(NT,x)$ = *minimo* numero di celle utilizzate da una computazione deterministica accettante di $NT(x)$.
Osservate che $ntime$ e $nspace$ sono due funzioni parziali – molto parziali, avendole definite solo per computazioni accettanti.
Potremmo aggiungere: **se $NT(x)$ non accetta**, anche quando $NT(x)$ termina, allora:
1. $ntime(NT,x)$ non è definita;
2. $nspace(NT,x)$ non è definita.
Ma perché, nella definizione di $ntime$ e $nspace$ si parla di  computazioni che “accettano” invece che di computazioni che “terminano”?
Ve la ricordate quell'asimmetria nelle definizioni di accettazione e di rigetto di una macchina non deterministica?
1. $NT(x)$ accetta se *esiste* una sua computazione deterministica che accetta;
2. $NT(x)$ rigetta se **tutte** le sue computazioni deterministiche rigettano.
Perciò, se vogliamo estendere le definizioni di $ntime$ e $nspace$ a tutte le computazioni che terminano, dobbiamo dire che: per ogni macchina di Turing non deterministica $NT$, definita su un alfabeto $\Sigma$, e per ogni $x\in\Sigma^*$ tali che $NT(x)$ **RIGETTA**, 
1. $ntime(NT,x)$ = *massimo* numero di istruzioni eseguite da una computazione deterministica rigettante di $NT(x)$; 
2. $nspace(NT,x)$ = *massimo* numero di celle utilizzate da una computazione deterministica rigettante di $NT(x)$.
Anche con questa estensione, le funzioni $ntime$ e $nspace$ restano funzioni parziali.
### Relazioni fra spazio e tempo
>[!important]- Teorema 6.1 (caso deterministico) 
>Sia $T$ una macchina di Turing **deterministica**, definita su un alfabeto  (non contenente il simbolo $\square$ ) e un insieme degli stati $Q$, e sia $x\in\Sigma^*$  tale che $T(x)$ termina. Allora,
>$dspace(T,x)\leq dtime(T,x)\leq dspace(T,x)|Q|\space\space (|\Sigma|+1)^{dspace(T,x)}$. 

1) $dspace(T,x)\leq dtime(T,x)$
Se $T(x)$ utilizza $dspace(T,x)$ celle di memoria, quelle celle deve almeno leggerle, e, per leggere ciascuna cella impiega un’istruzione (ossia, esegue una quintupla). Fine.
Beh, in realtà, potrebbe utilizzare un input molto più lungo del necessario; pensate, ad esempio, se per sommare i due numeri 15 e 6, scrivessimo l’input nella forma: $00000000000000000000000000000000000000000000000000000000000000000=15+6$ e poi posizionassimo la testina sul carattere ’=‘ all’inizio della computazione: in questo caso non avremmo bisogno di leggere i tantissimi ‘0’ iniziali. Per questo la definizione di $dspace$ è un po’ diversa da quella che abbiamo visto, ma noi ci teniamo quella e non consideriamo questi casi “anomali”.
>[!important]- Teorema 6.1 (caso deterministico)
>Sia $T$ una macchina di Turing deterministica, definita su un alfabeto $\Sigma$ (non contenente il simbolo $\square$ ) e un insieme degli stati Q, e sia $x\in\Sigma^*$ tale che $T(x)$ termina. Allora,
>$dtime(T,x)\leq dspace(T,x) |Q|\space\space (|\Sigma|+1)^{dspace(T,x)}$
1)  $dtime(T,x)\leq dspace(T,x) |Q|\space\space(|Sigma|+1)^{dspace(T,x)}$
Osserviamo che $dtime(T,x)\leq dspace(T,x) |Q| \space\space(|\Sigma|+1)^{dspace(T,x)}$  è il numero di stati globali possibili di $T$ nel caso in cui non più di $dspace(T,x)$ celle del nastro vengano utilizzate dalla computazione $T(x)$.
Infatti: 
poiché ogni cella del nastro può contenere un simbolo di $\Sigma$ oppure il blank, il numero di possibili configurazioni di $dspace(T,x)$ celle del nastro è $(|Sigma|+1)^{dspace(T,x)}$.
Poi, per ognuna di queste configurazioni:
1. La testina può trovarsi su una qualsiasi delle $dspace(T,x)$ celle
2. La macchina può essere in uno qualsiasi dei $|Q|$ stati interni
Chiamiamo $k(T,x)$ questo valore: $k(T,x) = dspace(T,x)|Q|(|Sigma|+1)^{dspace(T,x)}$ 
>[!important]-  Teorema 6.1 (caso deterministico)
>Sia $T$ una macchina di Turing **deterministica**, definita su un *alfabeto* $\Sigma$ (non contenente il simbolo $\square$ ) e un insieme degli stati Q, e sia $x\in\Sigma^*$ tale che $T(x)$ termina. Allora,
> $dtime(T,x)\leq dspace(T,x)|Q| \space\space(|\Sigma|+1)^{dspace(T,x)}$ . 

Dunque: $k(T,x) = dspace(T,x)|Q|(|Sigma|+1)^{dspace(T,x)}$ è il numero di stati globali possibili di T nel caso in cui non più di $dspace(T,x)$ celle del nastro vengano utilizzate dalla computazione $T(x)$.
Ora, ricordiamo che una computazione (deterministica) è una successione di stati globali tali che si passa da uno stato globale al successivo eseguendo una quintupla.
Se $T(x)$ durasse più di $k(T,x)$ passi **(senza uscire mai dalle dspace(T,x) celle)**, allora sarebbe una successioni di stati globali contenente almeno due volte uno stesso stato globale – chiamiamolo $SG_h$: $$SG_1\rightarrow SG_2\rightarrow...\rightarrow SG_h\rightarrow SG_{h+1}\rightarrow SG_{h+2}\rightarrow ...\rightarrow SG_{k(T,x)}$$
Ma $T$ è deterministica; allora, a partire da  è possibile eseguire un’unica quintupla (quella che porta nello stato globale $SG_{h+1}$ ) ed essa viene eseguita tutte le volte in cui $T(x)$ si trova in $SG_h$. Quindi, entrambe le volte, avviene una transizione verso lo stesso stato globale $SG_{h+1}$ , e così via: $T(x)$ sarebbe in loop (contro l’ipotesi che termina).
>[!important]- Teorema 6.1 (caso non deterministico) 
>Sia $NT$ una macchina di Turing **non deterministica**, definita su un alfabeto $\Sigma$ (non contenente il simbolo $\square$ ) e un insieme degli stati Q, e sia $x\in\Sigma^*$ tale che $NT(x)$ accetta/termina. Allora,
>$nspace(NT,x)\leq ntime(NT,x)\leq nspace(NT,x)|Q|(|\Sigma|+1)^{nspace(NT,x)}$ .

## Verso le classi di complessità
Sia $f:\mathbb N\rightarrow\mathbb N$  una funzione **totale calcolabile**. Sia $\Sigma$ un alfabeto finito e sia $x\in\Sigma^*$ : indichiamo con $|x|$ il numero di caratteri di $x$.
Un *linguaggio* $L\subseteq\Sigma^*$  è **deciso in tempo (spazio) deterministico $f(n)$** se:
1. Esiste una macchina di Turing deterministica $T$ che decide $L$; 
2. Per ogni $x\in\Sigma^*$, $dtime(T,x) \leq f(|x|)\space\space(dspace(T,x) = f(|x|) )$.
Un *linguaggio* $L\subseteq\Sigma^*$  è <u>accettato in tempo (spazio) non deterministico</u> $f(n)$ se:
1. Esiste una macchina di Turing non deterministica $NT$ che accetta $L$;
2. Per ogni $x\in L$, $ntime(NT,x)\leq f(|x|)\space\space(nspace(NT,x)\leq f(|x|))$
Un *linguaggio* $L\subseteq\Sigma^*$  è **deciso in tempo (spazio) non deterministico f(n)** se:
1. Esiste una macchina di Turing non deterministica $NT$ che decide $L$;
2. Per ogni $x\in\Sigma^*$, $ntime(NT,x) \leq f(|x|)\space\space(nspace(NT,x)\leq f(|x|))$. 
### Dall'accettazione alla decisione
Si osserva che nel caso deterministico definiamo soltanto i linguaggi decisi in un certo tempo o spazio, mentre nel caso non deterministico distinguiamo in linguaggi accettati in un certo tempo o spazio da quelli decisi nello stesso tempo o spazio.
Ma *perché*?
Si potrebbe pensare che esistono linguaggi che sono accettabili in un certo tempo o spazio, ma che non sono decidibili – ossia, il loro complemento non è accettabile. Ma, allora, verrebbe da chiedersi, perché questa cosa esce fuori solamente quando si utilizza una macchina non deterministica?
In effetti, non è così: 
>[!important]- Teorema 6.2 (tempo) 
>Sia $f:\mathbb N\rightarrow\mathbb N$ una funzione totale calcolabile.
>Se $L\subseteq\Sigma^*$  è accettato da una macchina di Turing non deterministica $NT$ tale che, per ogni $x\in L$, $ntime(NT,x) \leq f (|x|)]$ allora **L è decidibile**.

Poiché f è totale calcolabile, esiste una macchina $T_f$ di tipo trasduttore tale che, per ogni $n\in\mathbb N$ , $T_f(n)$ termina con il valore $f(n)$ scritto sul nastro di output.
Senza perdita di generalità, assumiamo che $T_f$  scriva $f(n)$ in unario sul nastro di output. Perché possiamo assumerlo?
Costruiamo una nuova macchina non deterministica $NT’$, a tre nastri, che decide L: 
Per ogni $x\in\Sigma^*$ :
- *FASE 1)* $NT’(x)$ scrive $|x|$ sul secondo nastro e invoca $T_f(|x|)$: al termine della computazione sul terzo nastro si troverà scritto $f(|x|)$ in unario;
- *FASE 2)* $NT’(x)$ **simula** $NT(x)$ e, per ogni quintupla eseguita da $NT(x)$:
1. $NT’$ “cancella” un ‘1’ dal terzo nastro ;
2. Se $NT(x)$ accetta allora anche $NT’(x)$ accetta, se $NT(x)$ rigetta allora anche $NT’(x)$ rigetta;
3. Se quando il terzo nastro di $NT’$ è vuoto $NT(x)$ non ha ancora terminato, allora $NT’(x)$ rigetta.
Osserviamo, intanto, che le computazioni di $NT’$ terminano sempre (se una computazione $NT’(x)$ dura più di $f(|x|)$ passi, la interrompiamo).
Poi, $NT’$ decide $L$, infatti:
1. Se $x\in L$, allora $NT(x)$ accetta in al più $f(|x|)$ passi: e, quindi, $NT’(x)$ *accetta*;
2. Se $x\not\in L$, allora o $NT(x)$ rigetta in al più $f(|x|)$ passi e, quindi, $NT’(x)$ rigetta, oppure $NT(x)$ non termina entro $f(|x|)$ passi e, quindi, $NT’(x)$, ugualmente, *rigetta*.
**Ma quanto impiega $NT’$ a rigettare $x\not\in L$?**
Non è possibile sapere quanto tempo impiega $T_f$ a calcolare $f(|x|)$. Sappiamo solo che $T_f(|x|)$ termina, ma non in quanto tempo!
**Per questo possiamo concludere che L è decidibile, ma non possiamo concludere che è deciso in tempo non deterministico $f(n)$**.
>[!important]- Teorema 6.2 (spazio)
>Sia $f:\mathbb N\rightarrow\mathbb N$ una funzione totale calcolabile.
>Se $L\subseteq\Sigma^*$  è accettato da una macchina di di Turing non deterministica $NT$ tale che, per ogni $x\in L$, $nspace(NT,x) \leq f (|x|)]$ allora $L$ è decidibile. 

La dimostrazione è analoga al caso di ntime.
## Complessità e modelli di calcolo
>[!info]
>Siamo al paragrafo 6.2 della dispensa 6.

Qui si dimostra che che tutti i modelli di calcolo deterministici sono fra loro **polinomialmente correlati**:
- -Macchine di Turing ad un nastro;
- -Macchine di Turing a quanti nastri si vogliono;
- -Macchine di Turing su alfabeto binario;
- -Macchine di Turing su alfabeti grandi quanto si vuole.
Ma che vuol dire che questi modelli sono fra loro polinomialmente correlati?
Per ogni macchina di Turing $T$ di uno di questi tipi esistono una macchina di Turing $T’$ di uno qualunque degli altri tipi ed un polinomio $p$ tali che $T’$ risolve lo stesso problema risolto da $T$ e, per ogni $x$, $dtime(T’,x) \leq p( dtime(T,x) )$ e $dspace(T’,x)\leq p( dspace(T,x) )$. 
E anche che il modello Macchina di Turing è polinomialmente correlato con il PascalMinimo.
Cosa significa tutto ciò?
Che possiamo risolvere un problema utilizzando il modello che più ci aggrada. Ad esempio, per risolvere un certo problema possiamo scrivere un algoritmo $A$ in PascalMinimo (invece che stare lì a progettare quintuple di una macchina di Turing), e se $A$ trova la soluzione di una istanza $x$ del problema eseguendo $f(|x|)$ istruzioni, allora esiste una macchina di Turing $T$ ad un nastro che risolve lo stesso problema, ed esiste un polinomio $p$ tale che $dtime(T,x)\leq  p( f(|x|)$.

Ma perché è così importante sapere che sono **polinomialmente** correlati?
Beh, perché se abbiamo un algoritmo in PascalMinimo che impiega un numero di istruzioni polinomiale nella lunghezza dell’input per risolvere il problema, sappiamo anche che esiste una macchina di Turing che risolve lo stesso problema eseguendo, anch’essa, un numero di istruzioni polinomiale nella lunghezza dell’input.
E un problema è trattabile se il tempo necessario a risolverlo è polinomiale (nella dimensione dell’input), perciò, se un problema è trattabile rispetto ad un modello, è trattabile anche rispetto a tutti gli altri.
