# L'Halting Problem
## Si fa presto a dire "infinito"
La dispensa 4 descrive il lavoro di Cantor (una piccola parte del lavoro di Cantor) sui numeri transfiniti, che dimostra che esistono insiemi infiniti “piccoli” e insiemi infiniti “grandi” (dove “piccolo” e “grande” sono basati sul concetto di corrispondenza biunivoca e un **numero transfinito** è la “grandezza” di un insieme infinito).
Cantor ha dimostrato che non esiste una corrispondenza biunivoca fra l’insieme dei numeri naturali e l’insieme dei numeri reali , ossia che comunque si scelga una funzione (totale) $f:\mathbb N\rightarrow\mathbb R$ esiste tale $y_f\in\mathbb R$  che, per ogni $x\in\mathbb N, f(x)\neq y_f$ , e questo prova che *l’insieme dei numeri reali è strettamente “più grande” dell’insieme dei naturali*. In effetti, Cantor ha dimostrato anche che l’insieme infinito “più piccolo” di tutti è quello dei numeri naturali
In realtà, quel che Cantor ha dimostrato è che non esiste una corrispondenza biunivoca fra l’insieme dei numeri naturali e l’intervallo reale  $[ 0 , 1 ]$, ossia, che nel segmento	<u>0_____1 </u> ci sono infinitissimamente più punti di quanti sono i numeri naturali, e mai noi riusciremmo a disegnarli tutti, i numeri naturali.
E che lo stesso vale per ogni intervallo reale $[0,\varepsilon]$ 
per quanto vicino allo 0 scegliamo.
## Problemi irrisolvibili
La dispensa 5 è dedicata allo studio dell’esistenza di problemi “impossibili” da risolvere (Turing-irrisolvibili, con tutto quel che segue). 
Nei paragrafi 5.1 e 5.2 si utilizza quanto studiato nella dispensa 4 per dimostrare che **esiste un problema irrisolvibile**:
Poiché le macchine di Turing sono tante quanti i numeri naturali, e poiché i problemi sono tanti quanti i numeri reali (che Cantor ha dimostrato essere più dei numeri naturali), allora, esiste almeno un problema al quale non corrisponde alcuna macchina di Turing.
Ossia, ***esiste* almeno un problema che non può essere risolto con una macchina di Turing** (e, quindi, per la tesi di Church-Turing non può proprio essere risolto).
Per il momento, quel che ci interessa dei paragrafi 5.1 e 5.2 è soltanto che esiste almeno un problema che non può essere risolto con una macchina di Turing (e, quindi, per la tesi di Church-Turing non può essere risolto) e che questo fatto viene dimostrato, semplicemente, *contando*: il numero dei problemi è maggiore del numero di macchine.
Purtroppo, la tecnica del conteggio non ci dà alcuna idea di come possa essere fatto un problema irrisolvibile. Magari, i problemi irrisolvibili sono strani, astrusi, sono problemi astratti costruiti apposta per essere irrisolvibili… Problemi, insomma, che non incontreremmo mai nella vita reale e la cui risoluzione non è rilevante. Invece, non è così.
Turing ha costruito un problema irrisolvibile, anzi, la sua macchina l’ha inventata proprio per arrivare a dimostrare che questo problema è irrisolvibile, ed è un problema con il quale ogni informatico fa i conti tutti i giorni.
## Macchina = Parola = Numero
>[!info]
>Siamo a pag. 11 della dispensa 2
>

Avevamo descritto una macchina di Turing T con alfabeto {0,1}, insieme degli stati $Q_T = \{ω_0,...,ω_{k-1}\}$ , con stato iniziale $ω_0$, stato di accettazione $ω_1$, e stato di rigetto $ω_2$ – $|Q_T|=k$ , e insieme delle quintuple $P = \{p_1,..., p_h\}$ , dove la sua i-esima quintupla è $p_i = ⟨ ω_{i1} ,b_{i1} , b_{i2} , ω_{i2} , m_i ⟩$ mediante la parola: 
$\begin{align}\\&\rho_T = ω_0 − ω_1 \otimes ω_{11} − b_{11} − b_{12} − ω_{12} − m_1 \oplus ω_{21} − b_{21} − b_{22} − ω_{22} − m_2 \oplus ... \oplus \\& ω_{h1} − b_{h1} − b_{h2} − ω_{h2} − m_h \oplus\end{align}$

Poi, a pag. 13 (dispensa 2) avevamo introdotto una codifica binaria  $b_Q$ dell’insieme $Q_T$ degli stati di T, che, nella lezione 4 di questa serie, avevamo semplificato come segue:
1. $b_Q : Q_T  \rightarrow \{ 0,1 \}^k$, ossia, la codifica $b_Q$ rappresenta uno stato di T mediante una parola di k bit.
2. $b_Q(ω_i)$ è la parola che ha un 1 in posizione i+1 e 0 altrove – esempio: se k=4, $b_Q(ω_0)=1000, b_Q(ω_1)=0100, b_Q(ω_2)=0010, b_Q(ω_3)=0001$ .
A questo punto, avevamo rappresentato T mediante la seguente parolona nell’alfabeto$\Sigma=\{0,1,\oplus,\otimes,_,f,s,d\}$ :
	$\begin{align} \\&= b_Q(ω_0) - b_Q( ω_1) \otimes b_Q(ω_{11}) − b_{11} − b_{12} − b_Q(ω_{12}) − m_1 \oplus b_Q(ω{21}) − b_{21} − b_{22} \\& − b_Q(ω_{22}) − m_2 \oplus ... \oplus b_Q(ω_{h1}) − b_{h1} − b_{h2} − b_Q(ω_{h2}) − m_h \oplus\end{align}$ 

Quello che viene fatto nel paragrafo 5.1 (dispensa 5) è trasformare la parola  in un numero sostituiamo in:  
1. ogni carattere ‘s’  con il carattere ‘5’, ogni carattere ‘f’ con il carattere ‘6’, e ogni carattere ‘d’ con il carattere ‘7’; 
2. ogni carattere ‘-’ con il carattere ‘4’, ogni carattere ‘$\oplus$’ con il carattere ‘3’ e ogni carattere ‘$\otimes$’ con il carattere ‘2’; 
3. ogni carattere ‘$\square$’ con il carattere ‘9’;
Infine, premettiamo il carattere ‘8’ alla parola ottenuta. 
Alla “parola” ottenuta… *In realtà, quello che abbiamo ottenuto è un numero intero*.
Abbiamo associato ad ogni macchina di Turing un numero intero
e l’associazione è univoca: a macchine di Turing diverse sono associati interi diversi, o, equivalentemente, un intero non può corrispondere a due macchine di Turing. 
**Cioè, abbiamo imparato a rappresentare le macchine di Turing mediante numeri naturali. Mediante parole nell’alfabeto {0,… ,9} che possono essere lette come numeri naturali**.
## Problemi irrisolvibili
Abbiamo imparato a rappresentare una macchina di Turing mediante un numero naturale – abbiamo **codificato** macchine di Turing mediante numeri naturali. Se vogliamo dirlo bene, abbiamo trovato una corrispondenza biunivoca fra le macchine di Turing e un sottoinsieme dei numeri naturali. I numeri naturali che rappresentano macchine di Turing hanno certe proprietà: iniziano tutti per 8, …

>[!danger]- ESERCIZIO 
>Scrivete tutte le proprietà che un numero deve soddisfare perché sia la codifica di una macchina di Turing. E fatene un algoritmo.

Intanto, osserviamo, se ci limitiamo a considerare macchine di Turing che lavorano sull’alfabeto binario, anche l’input di una $T_M$ è un numero intero.
>[!danger]- ESERCIZIO 
>E come distinguere 101 da 0101 da 0000101?
>(sugg. : possiamo premettere un 1: 101  1101 ,  0101  10101 ,  0000101  10000101 ).

Turing considerò il seguente linguaggio, sottoinsieme di  :                              																		      			$L_H = \{ (i,x)\in\mathbb N :$ i è la codifica di una macchina di Turing $T_i$ e $T_i(x)$ termina },
che si chiama **Halting Problem**.
Turing dimostrò che $L_H$ è accettabile, e dimostrò anche che $L_H$ non è decidibile. Questo significa che $L_H^C$  non è accettabile, e noi, adesso, studiamo queste dimostrazioni (paragrafo 5.3 della dispensa 5)
Ma prima cerchiamo di capire che senso ha domandarsi, data $(i,x)\in\mathbb N\times\mathbb N$ , se $(i,x)\in L_H$ , quale può essere la rilevanza di questa domanda?
## A chi importa dell'Halting Problem?
Sei informatico, ti capiterà, qualche volta nella vita, di scrivere un programma
complicatissimo. Bene, dopo tutta questa fatica, lanci il tuo programma su un certo input x (x è un’istanza del problema risolto dal tuo programma della quale è fondamentale calcolare la soluzione) e attendi la risposta…
... e attendi ... e attendi ...
Ti viene un dubbio: e se fosse andato in loop?!
Certo sarebbe bello se esistesse un **programma** che, se gli do in input un altro programma P e un suo input x, quello mi dice se  l’esecuzione di P su x termina oppure no. Sarebbe bello se esistesse un **programma** che decide l’*Halting Problem*!
## $L_H$ è accettabile - Teorema 5.4
Questo è facile: prendete la macchina Universale U e le fate un paio di modifiche – trasformandola nella macchina U’. La prima modifica serve a fare in modo che U’ verifichi se l’input i scritto sul suo primo nastro è davvero la codifica di una macchina di Turing $T_i$ , se non è così, $U’(i,x)$ rigetta.
La seconda modifica serve a fare in modo che, se i è la codifica di una macchina di Turing $T_i$ , U’ accetti la coppia (i,x) ogni qualvolta $T_i(x)$  termina, ossia, sia nel caso in cui accetta sia nel caso in cui rigetta:
Accertato che i è la codifica di una macchina di Turing $T_i$,$U’(i,x)$ simula $U(i,x)$ e: 
1. Se $U(i,x)$ accetta allora $U’(i,x)$ accetta;
2. Se $U(i,x)$ rigetta allora $U’(i,x)$ accetta.
Quindi $U’(i,x)$ accetta tutte e sole le coppie $(i,x)$ che appartengono a $L_H$ – ossia, **$L_H$ è accettabile**.
Ma se $(i,x)\not\in L_H$? Ossia, se $(i,x)\in L_H^C$? Nulla possiamo concludere circa l’esito della computazione U’(i,x).
## $L_H$ non è decidibile - Teorema 5.5
La dimostrazione è per assurdo: supponiamo che $L_H$ sia decidibile.
Se $L_H$ è decidibile, allora esiste una macchina T tale che, per ogni $(i,x)\in\mathbb N\times\mathbb N$:
1. T(i,x) accetta se $(i,x)\in L_H$
2. T(i,x) rigetta se $(i,x)\not\in L_H$ 
**NOTA BENE**: T termina su ogni input!
Ebbene, se abbiamo T, possiamo utilizzare T per **costruire** una nuova macchina T’ tale che:
1. T’(i,x) accetta se $(i,x)\not\in L_H$;
2. T’(i,x) rigetta se $(i,x)\in L_H$. 
Come è fatta T’? Beh, prendiamo T, la smontiamo e invertiamo gli stati di accettazione e di rigetto. Oppure, se non abbiamo pinze e cacciaviti, usiamo T come se fosse una funzione: con la coppia (i,x) sul nastro, T’ “invoca” T passandogli (i,x) come parametri, e quando T(i,x) termina T’ risponde complementando $q_A$ con $q_R$.
Osservate: più che simulare T, T’ usa T – proprio come nei linguaggi di programmazione si invoca una funzione.
questo significa che, per costruire T’, non abbiamo bisogno di sapere come è fatta T, la usiamo “chiusa”, a **scatola nera**. Tutto quello che abbiamo bisogno di sapere, per costruire T’, è come risponde T sui vari input (i,x).
Ora, di nuovo con la “tecnica della scatola nera”, a partire da T’, **costruiamo** una macchina T’’, che accetta (i,x) se $(i,x)\not\in L_H$ , mentre *non termina* se $(i,x)\in L_H$, con la coppia (i,x) sul nastro, T’’ invoca T’ passandogli (i,x) come parametri: quando  T’(i,x) termina, se termina in $q_A$ allora anche T’’ termina in qA, se, invece, T’(i,x)  termina in $q_R$ allora T’’(i,x) *entra in loop*.
È sufficiente aggiungere le due quintuple $〈 q_R , 0, 0, q_R , F〉$ e  $〈 q_R , 1, 1, q_R , F〉$ e rimuovere $q_R$ dall’insieme degli stati finali di T’’.
**NOTA BENE**: T’’ <u>non</u> termina su ogni input!
**NOTA BENE**: poiché $(i,x)\in\mathbb N\times\mathbb N$, ossia, l’input di T, di T’ e di T’’ è costituito da una coppia di interi, **allora (i,i) – che è una coppia di interi – può ben essere dato in input a queste tre macchine**: se i è la codifica di una macchina di Turing, allora:
1. T( i, i ) accetta se $( i, i )\in L_H$  , ossia se $T_i ( i )$ termina, e T( i, i ) rigetta se $( i, i )\not\in L_H$ , ossia se  $T_i ( i )$ non termina;
2. T’( i, i ) accetta se $( i, i )\not\in L_H$ , ossia se $T_i ( i )$ non termina, e  T’( i, i ) rigetta se $( i, i )\in L_H$, ossia se $T_i ( i )$ termina;
3. T’’( i, i ) accetta se $( i, i )\not\in L_H$ , ossia se $T_i ( i )$ non termina, e T’’( i, i ) non termina se $( i, i )\in L_H$ , ossia se $T_i ( i )$ termina.
Compreso che come input di T, T’ e T’’possiamo usare una coppia $(i,x)\in\mathbb N\times\mathbb N$ tale che x=i, di nuovo con la “tecnica della scatola nera”, a partire da T’’, **costruiamo** un’ultima macchina *$T^*$che lavora con un solo input e tale che **l’esito della computazione $T^*( i )$ coincide con l’esito della computazione T’’( i, i )***.
Ossia, se i è la codifica di una macchina di Turing, allora:
1. $T^*( i )$ accetta se $( i, i )\not\in L_H$  , ossia se $T_i ( i )$ non termina, 
2. $T^*( i )$ non termina se $( i, i )\in L_H$ , ossia se $T_i ( i )$ termina.
PS: se i non è la codifica di una macchina di Turing, allora $( i, i )\not\in L_H$ , e quindi $T^*( i )$ accetta, ma di questo ci interessa poco.
**ALTRA NOTA BENE:** poiché abbiamo supposto che T esiste, allora anche $T^*$ esiste, ossia è una macchina reale – l’abbiamo costruita fisicamente a partire da T.
E, se $T^*$ esiste, allora la posso codificare come intero – lo abbiamo visto all’inizio di questa lezione.
Chiamiamo k il codice di $T^*$ ottenuto applicando il procedimento illustrato in questa lezione cioè, $$T^* = T_k$$
Ma k è un intero. Allora, k può essere input di $T^*$ - ossia, input di $T_k$
Ossia, possiamo considerare la computazione $T_k ( k )$.
Ebbene, siamo al nocciolo della questione: quale è l’esito della computazione $T^*( k ) = T_k ( k )$? 
Osservate bene: $T_k ( k )$ è la computazione di *una macchina che si interroga su sé stessa* – che cerca di verificare se essa stessa soddisfa una certa proprietà.
Ricapitoliamo:
1. $L_H = \{ (i,x) :$ i è la codifica di una macchina di Turing $T_i$ e $T_i (x)$ termina };
2. $T^*( k ) = T_k ( k )$ accetta se $( k, k )\not\in L_H$ , mentre *non termina* se $( k, k )\in L_H$. 
Dunque, $T^*( k ) = T_k ( k )$ o accetta oppure non termina. Potrebbe forse accettare?
$T^*( k ) = T_k ( k )$ accetta solo se $( k, k )\not\in L_H$ , poiché k è il codice di una macchina di Turing, $( k, k )\not\in L_H$  solo se $T_k ( k )$ non termina: dunque, $T^*( k ) = T_k ( k )$ accetta solo se $T^*( k ) = T_k ( k )$ non termina
**Allora, no**: non è possibile che accetti 
Allora, non c’è altra possibilità: $T^*( k ) = T_k ( k )$ non termina! Siamo sicuri?
 $T^*( k ) = T_k ( k )$ non termina solo se $( k, k )\in L_H$ , ossia (dalla definizione di $L_H$ ), solo se $T_k (k)$ termina: dunque, $T^*( k ) = T_k ( k )$ non termina solo se $T^**( k ) = T_k ( k )$ termina.
**Allora, no**: non è possibile che $T^*( k ) = T_k ( k )$ non termini.
In conclusione, $T^*( k ) = T_k ( k )$ o accetta oppure non termina – non vi sono altre possibilità!
E, però, non è possibile che $T^*( k ) = T_k ( k )$ accetti e non è possibile nemmeno che $T^*( k ) = T_k ( k )$ non termini.
Ricapitoliamo:
Partendo dall’ipotesi “$L_H$ è decidibile” – ossia che esista la macchina T che decide $L_H$ , siamo arrivati a costruire una computazione, $T^*( k ) = T_k ( k )$, che non può esistere!
E quindi abbiamo sbagliato a supporre che $L_H$  è decidibile.Abbiamo, così, dimostrato che $L_H$  è indecidibile.
## $L_H$ è accettabile ma non decidibile
Ma cosa significa che $L_H$  è accettabile ma non è decidibile?
>[!important]
>“un linguaggio L è decidibile se e solo se L è accettabile e LC è accettabile”

Allora, poiché $L_H$  è accettabile e $L_H$ non è decidibile :$L_H^C$ non è accettabile.
E questo significa che, quando state lì ad aspettare se l’esecuzione del vostro programma termini sull’importante istanza che gli avete dato in input,
la domanda alla quale è difficile rispondere è proprio:
**Ma non è che, per caso, è andato in loop?**

