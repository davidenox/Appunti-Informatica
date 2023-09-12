# Riducibilità polinomiale
## Relazioni interessanti, ma..
La maggior parte delle relazioni fra classi complessità che abbiamo visto, fino ad ora, sono **inclusioni improprie** (a parte $P\subset EXPTIME$  e $PSPACE = NPSPACE$).
Ossia, a parte queste due ultime relazioni, per ciascuna delle rimanenti relazioni non siamo in grado di dimostrare né l’inclusione propria né la coincidenza delle due classi che la costituiscono. 
Ad esempio, sappiamo che: 
1. Tutti i linguaggi che sono in $PSPACE$ sono anche in $EXPTIME$  ($PSPACE\subseteq EXPTIME$);
2. Tutti i linguaggi che sono in $P$ sono anche in $NP$  ($P\subseteq NP$)
Ma non sappiamo rispondere alle seguenti domande:
1. non sarà forse che tutti i linguaggi in $EXPTIME$ sono anche in $PSPACE$? Ossia, che $PSPACE = EXPTIME$?
2. Oppure, esiste almeno un linguaggio in $NP$ che non può essere deciso in tempo deterministico polinomiale? Ossia: è $P\subset NP$ oppure $P = NP$ ?
Le relazioni che conosciamo sono, in massima parte, relazioni *deboli*.
E, inoltre, pur riuscendo a dimostrare che una certa classe di complessità  è contenuta propriamente in un’altra classe di complessità $\mathcal C_2$ (ossia, $\mathcal C_1\subset\mathcal C_2$  ).
Anche in questo caso, seppure dimostriamo che un certo linguaggio $L$ appartiene a $\mathcal C_2$, come facciamo a sapere se quel linguaggio è anche in $\mathcal C_1$ oppure se, invece, è un *linguaggio separatore* fra $\mathcal C_1$ e $\mathcal C_2$ , ossia è contenuto in $\mathcal C_2-\mathcal C_1$ ?
Certo sarebbe utile se disponessimo di uno strumento che permettesse di individuare i linguaggi separatori fra due classi di complessità...
## $=$ oppure $\not =$ ?
Date due classi di complessità $C_1$ e $C_2$ tali che $C_1\subseteq C_2$, come fare per poter capire se $C1  = C2$  oppure $C1\not = C2$ ?
*Idea*: **se per caso trovassimo un linguaggio  $L_0\in C_2$ tale che**:  
1. **Supponendo di avere un algoritmo $\mathcal A$ che decide $L_0$ utilizzando una quantità di risorse pari a quella che definisce la classe $C_1$**;
2. **Per ogni altro linguaggio $L$ in $C_2$ riusciamo a costruire, simulando $\mathcal A$ , un algoritmo $\mathcal B_L$ che decide $L$ e che utilizza una quantità di risorse pari a quella che definisce la classe $C_1$**.
Allora, *se riuscissimo davvero a progettare $\mathcal A$ (dimostrando così che $L_0\in C_1$ ), sapremmo automaticamente che tutti i linguaggi in $C_2$ sono anche in $C_1$*. 
E, d’altra parte, questo implicherebbe anche che **se qualcuno riuscisse a dimostrare che $C1\not = C2$** allora **sapremmo automaticamente che  $L_0\not\in C_1$  sarebbe il padre di tutti i linguaggi in $C_2$** (il linguaggio più difficile fra tutti i linguaggi che stanno in $C_2$).
Bel ragionamento! Ma come facciamo a trovare il padre di tutti i linguaggi di una classe? 
## Una vecchia conoscenza
>[!info]- Ve le ricordate le care, vecchie, riduzioni? (paragrafo 5.5)

Dati due linguaggi, $L_1\subseteq\Sigma_1^*$  e $L_2\subseteq\Sigma_2^*$,  diciamo che $L_1$ **è riducibile a $L_2$  				e scriviamo $L1\succeq L2$** se:
Esiste una funzione $f:\Sigma_1^*\rightarrow\Sigma_2^*$ tale che:
1) $f$ è totale e calcolabile – ossia, è definita per ogni parola $x\in\Sigma_1^*$ e, inoltre, 
esiste una macchina di Turing di tipo trasduttore $T_f$ tale che, per ogni parola $x\in\Sigma_1^*$, la computazione $T_f(x)$ termina con la parola $f(x)\in\Sigma_2^*$ scritta sul nastro di output;
2) per ogni $x\in\Sigma_1^*$ vale che: $x\in L_1$  se e solo se $f(x)\in L_2$
$$\forall x\in\Sigma_1^*[x\in L_1\iff f(x)\in L2]$$
Ora, aggiungiamo una piccola richiesta alla funzione di riduzione $f$: richiediamo che, oltre ad essere totale e calcolabile
3) per ogni $x\in\Sigma_1^*$, $f(x)$ è calcolabile in tempo polinomiale in $|x|$ – ossia, $f\in FP$.
## Un nuovo strumento
Dati due linguaggi, $L_1\in\Sigma_1^*$  e $L_2\in\Sigma_2^*$,  diciamo che **$L_1$  è polinomialmente *riducibile* a $L_2$**  e scriviamo $L1\succeq_p L_2$  se:
Esiste una funzione $f:\Sigma_1^*\rightarrow\Sigma_2^*$ tale che
1) f è totale e calcolabile in tempo polinomiale (in breve, $f\in FP$) – ossia, è definita per ogni parola $x\in\Sigma_1^*$ e, inoltre, esiste una macchina di Turing di tipo trasduttore $T_f$ tale che, per ogni parola $x\in\Sigma_1^*$, la computazione $T_f(x)$ termina con la parola $f(x)\in\Sigma_2^*$ scritta sul nastro di output, ed esiste una costante $c$ tale che: per ogni $x\in\Sigma_1^*$ , $dtime(T_f,x)\in O(|x|^c )$;
2) per ogni $x\in\Sigma_1^*$ vale che: $x\in L_1$  se e solo se $f(x)\in L_2$
$$\forall x\in\Sigma_1^*[x\in L_1\iff f(x)\in L2]$$
La riducibilità polinomiale ci aiuterà a trovare il padre di tutti i problemi di una classe
>[!info]- E siamo al paragrafo 6.8: come sulla dispensa, d’ora in poi scriveremo sempre invece di p

Abbiamo due linguaggi, $L_1\in\Sigma_1^*$  e $L_2\in\Sigma_2^*$, e riusciamo a dimostrare che $L_1\succeq_p L_2$  (anzi, come abbiamo detto, leviamo la p: $L1\succeq L2$ ), cioè, dimostriamo che esistono un trasduttore $T_r$ e una costante $c$ tali che, per ogni $x\in\Sigma_1^*$, e, inoltre, per ogni $x\in\Sigma_1^*$, $dtime(T_r , x)\in O(|x|^c )$.

Supponiamo di sapere che $L2\in DTIME[f(n)]$, cioè, esiste un riconoscitore $T_2$ tale che, per ogni $y\in\Sigma_2^*$, $T_2(y)$ accetta se e soltanto se $y\in L_2$  e, inoltre, per ogni $y\in\Sigma_2^*$, $dtime(T_2, y)\in O( f (|y|) )$.  
Allora, possiamo costruire la seguente macchina $T_1$ : con input $x\in\Sigma_1^*$, $T_1$ opera in due fasi (ed utilizza due nastri):
**FASE 1**: $T_1$ simula $T_r(x)$ scrivendo l’output $y$ sul secondo nastro;
**FASE 2**: $T_1$ simula $T_2(y)$ sul secondo nastro: se $T_2(y)$ accetta allora anche $T_1$ accetta, se $T_2(y)$ rigetta allora anche $T_1$ rigetta. 
*$T_1$ decide $L_1$*: perché $T_2(y)$ accetta se e solo se $y\in L_2$ , e $y\in L_2$ se e solo se $x\in L_1$. 
Ma quanto impiega $T_1$ a decidere $L_1$?
Con input x:
1. La FASE 1 termina in $O(|x|^c )$ passi;
2. La FASE 2 termina in $O( f(|y|) )$ passi.
*Ma quanto è grande $|y|$ in funzione di $|x|$?*
Poiché $T_r(x)$ impiega $O(|x|^c )$ passi per calcolare $y$, e in questo numero di passi sono conteggiati anche i passi che occorrono a scrivere $y$ sul nastro di output, allora, $|y|\in O(|x|^c )$.
E, quindi, per ogni $x\in\Sigma_1^*$, $T_1(x)$ termina in $O(|x|^c + f(|x|^c ))$ passi.
Ossia, $L_1\in DTIME[ n^c + f( n^c ) ]$.

Allora, se $L_2\in P$ allora $L_1\in  P$. 
In questo caso, esiste una costante $k$ tale che  $L_2\in DTIME[ n^k  ]$. Allora, $L_1\in DTIME[ n^c + ( n^c )^k ]\subseteq P$.
Se $L_2\in EXPTIME$ allora $L_1\in EXPTIME$, 
Ma si può dimostrare la stessa cosa con le classi non deterministiche:
1. Se $L_2\in NP$ allora $L_1\in NP$; 
2. Se $L_2\in NEXPTIME$ allora $L_1\in NEXPTIME$.
E anche per le classi spaziali, se $L_2\in PSPACE$ allora $L_1\in PSPACE$. 
>[!info]- Il **Teorema 6.21** della dispensa 6 dimostra il solo caso “Se $L1\succeq L2$ e $L_2\in P$ allora $L_1\in  P$”, che è quel che abbiamo appena dimostrato!

## Lezione 13 vs Dispensa 6
Bisogna ora “riallinearci” con la dispensa 6
>[!info]- Nel paragrafo 6.8 viene introdotto il concetto generale di $\pi$-riduzione

Sia un predicato definito sull’insieme delle funzioni totali e calcolabili – ossia, una proprietà, che deve essere posseduta da una funzione ad esempio: 
1. Per ogni $x\in\Sigma_1^*$ , $|f(x)| = |x|$;
2. Per ogni $x\in\Sigma_1^*$ , *f è calcolabile in tempo polinomiale in* $|x|$.
Dati due linguaggi, $L_1\subseteq\Sigma_1^*$  e $L_2\subseteq\Sigma_2^*$,  diciamo che **$L_1$  è $\pi$-riducibile a $L_2$**  				e scriviamo $L_1\preceq_{\pi} L_2$  se esiste una funzione $f:\Sigma_1^*\rightarrow\Sigma_2^*$ tale che:
1) f è totale e calcolabile;
2) per ogni $x\in\Sigma_1^*$ vale che: $x\in L_1$  se e solo se $f(x)\in L_2$;
3) f soddisfa $\pi$.
Quindi, le riduzioni polinomiali che abbiamo visto in questa lezione sono specifiche $\pi$-riduzioni - le trovate sulla dispensa, Definizione 6.5.
Prima di arrivare alla definizione 6.5, nella dispensa vengono introdotti altri concetti che si riferiscono alle $\pi$-riduzioni in generale:
1. **Chiusura** di una classe rispetto a una $\pi$-riduzione;
2. **Completezza** di un linguaggio per una classe rispetto a una $\pi$-riduzione.
### Chiusura di una classe rispetto a $\preceq_{\pi}$
>[!important]- Definizione 6.4 
>Una classe di complessità C è **chiusa** rispetto ad una generica $\pi$-riduzione se, per ogni coppia di linguaggi $L_1$ ed $L_2$ tali che $L_1\preceq_{\pi} L_2$ e $L_2\in C$, si ha che $L_1\in C$. 

**La chiusura di una classe C rispetto ad una -riduzione può essere utilizzata per dimostrare l’appartenenza di un linguaggio L a C**: 
Segue direttamente dalla definizione che, se sappiamo che una classe di complessità $C$ è chiusa rispetto ad una $\pi$-riduzione e che un certo linguaggio $L_0$ appartiene a $C$, allora, se dimostriamo che $L\preceq_{\pi} L_0$, possiamo dedurre che anche $L$ appartiene a $C$. 
### Completezza di un linguaggio per una classe rispetto a $\preceq_{\pi}$
>[!important]- Definizione 6.3 
>Sia $C$ una classe di complessità di linguaggi e sia $\preceq_{\pi}$ una generica $\pi$-riduzione. 
>Un linguaggio $L\subseteq\Sigma^*$ è **C-completo** rispetto alla $\pi$-riducibilità se: 
>a) $L\in C$;
>b) Per ogni altro $L_0\in  C$, vale che $L_0\preceq_{\pi} L$. 

Le nozioni di:
1. Completezza di un linguaggio per una classe rispetto ad una $\pi$-riduzione; 
2. Chiusura di una classe rispetto alla $\pi$-riduzione; 
sono gli strumenti che ci permettono di arrivare al concetto di “*padre di tutti i linguaggi*” per una classe.
## Il padre di tutti i linguaggi di una classe
Abbiamo due classi di complessità $C_1$ e $C_2$ tali che $C_1\subseteq C_2$, e sappiamo che $C_1$ è **chiusa** rispetto ad una qualche $\pi$-riduzione:
- Allora, per ogni coppia di linguaggi $L_1$ ed $L_2$ tali che $L_1\preceq_{\pi}L_2$ e $L_2\in C_1$,  si ha che $L_1\in C_1$. 
Se per caso troviamo un linguaggio $L$ $C_2$–**completo** rispetto a $\preceq_{\pi}$
- ossia, $L\in C_2$ e per ogni altro $L_0\in C_2$, vale che $L_0\preceq_{\pi} L$
e **se dimostriamo che $L\in C_1$**, abbiamo che: 
- Per ogni altro $L_0\in C_2$, vale che $L_0\preceq_{\pi} L$ e inoltre $L\in C_1$. 
Allora, in virtù della chiusura di $C_1$ rispetto alla $\pi$-riduzione, 
- **Per ogni altro $L_0\in C_2$, vale che $L_0\in C_1$**.
- 
>[!important]- Riassumendo 
>Abbiamo due classi di complessità $C_1$ e $C_2$ tali che $C_1\subseteq C_2$, e sappiamo che $C_1$ è chiusa rispetto ad una qualche $\pi$-riduzione.

Se per caso trovassimo un linguaggio **L $C_2$–completo** rispetto a $\preceq_{\pi}$ allora
da un ipotetico algoritmo che decide $L$ utilizzando una quantità di risorse pari a quella che definisce la classe $C_1$ – cioè, se dimostrassimo che $L\in C_1$ potremmo dedurre un algoritmo che decide qualunque problema in $C_2$ utilizzando una quantità di risorse pari a quella che definisce la classe $C_1$.
Allora, se riuscissimo a dimostrare che $L\in C_1$  sapremmo automaticamente che tutti i linguaggi in $C_2$ sono anche in $C_1$ - ossia sapremmo che $C_1 = C_2$.
Ma possiamo vederla anche in un altro modo: se $C_1\subseteq C_2$ e L è $C_2$–**completo** e **se qualcuno riuscisse a dimostrare che $C_1\not= C_2$ allora sapremmo automaticamente che $L\not\in C1$**. 
L sarebbe il padre di tutti i linguaggi in $C_2$, il linguaggio più difficile fra tutti i linguaggi che stanno in $C_2$.
Infatti:
>[!important]- Teorema 6.20 
>Siano $C$ e $C_0$ due classi di complessità tali che $C_0\subseteq C$. Se $C_0$ è chiusa rispetto ad una $\pi$-riduzione allora, per ogni linguaggio $L$ che sia C-completo rispetto a $\preceq_\pi$ , $L\in C_0$ se e solo se $C = C_0$. 

Se $C = C_0$ , poiché L è C-completo e, dunque $L\in C$, allora $L\in C_0$.
**Viceversa**, supponiamo che $L\in C_0$. Poiché L è C completo rispetto a $\preceq_\pi$ , allora, per ogni  $L’\in C$, $L’\preceq_\pi L$. 															         Poiché $C_0$ è chiusa rispetto a $\preceq_\pi$ , questo implica che, per ogni $L’\in C$, $L’\in C_0$, quindi, $C = C_0$.  
![[Pasted image 20230508122948.png|center|500]]

## I linguaggi NP-completi
A questo punto, abbandoniamo le generiche $\pi$-riduzioni e torniamo definitivamente alle nostre riduzioni polinomiali. Da questo momento in poi, quando parleremo di riduzioni ci riferiremo sempre alle riduzioni polinomiali e utilizzeremo il simbolo per riferirci ad esse $\preceq$. 
Un linguaggio $L\subseteq \Sigma^*$  è **NP-completo (rispetto alla riducibilità polinomiale)** se:
a) $L\in NP$;												
b) Per ogni altro $L_0\in NP$, vale che $L_0\preceq L$. 
I linguaggi NP-completi sono particolarmente importanti per il loro ruolo di possibili linguaggi separatori fra le classi P e NP:
>[!important]- Corollario 6.4 
>Se $P\not= NP$ allora, per ogni linguaggio NP-completo L, $L\not\in P$. 

Supponiamo che L sia un linguaggio NP-completo e che $L\in P$. 
Poiché L è NP-completo allora, per ogni linguaggio $L_0\in NP$, $L_0\preceq L$; 
Ma, se $L\in P$, poiché P è **chiusa** rispetto a $\preceq$, questo implica che, per ogni $L_0\in NP$, $L_0\in P$. 
Ossia, $P = NP$, contraddicendo l’ipotesi.
Ma quale è il senso del Corollario 6.4?
Intanto che è molto improbabile che un linguaggio NP-completo appartenga a P. Perché ci interessa? 
Ebbene, si sospetta che sia $P\not= NP$ – ma nessuno è mai riuscito a dimostrarlo, per questo è una congettura..
E siccome è una questione importante, sulla dimostrazione della congettura (o della sua negazione) hanno messo una taglia da 1.000.000 di dollari!
Ma, dell’importanza della congettura, parleremo in seguito…
Quindi: se vogliamo dimostrare che, probabilmente, non esiste un algoritmo deterministico che decide in tempo polinomiale un linguaggio che è in NP quel che dobbiamo fare è dimostrare che quel linguaggio è NP-completo.
E se, invece, abbiamo un linguaggio NP-completo e progettiamo un algoritmo deterministico che decide quel linguaggio in tempo polinomiale?
In tal caso, abbiamo vinto un milione di dollari, oppure abbiamo sbagliato qualcosa…
## Uso delle riduzioni
Ricordiamo che le riduzioni nel campo della calcolabilità si rivelano utili tanto per dimostrare  che un linguaggio è decidibile/accettabile quanto per dimostrare  che un linguaggio non è decidibile/accettabile: dato un linguaggio $L_1$:
1. se dimostro che $L_1\preceq L_2$ , per un qualche altro linguaggio $L_2$ *decidibile*, allora, posso concludere che anche $L_1$ è **decidibile**; 
2. se dimostro che $L_0 \preceq L_1$ , per un qualche altro linguaggio $L_0$ *non decidibile*, allora, posso concludere che anche $L_1$ è **non decidibile**.
Allo stesso modo, le riduzioni polinomiali sono uno strumento utile tanto per dimostrare che un linguaggio è in P quanto per dimostrare che un linguaggio probabilmente non è in P
Dato un linguaggio $L_1$:
1. se dimostro che $L_1\preceq  L_2$ , per un qualche altro linguaggio $L_2\in  P$, allora, posso concludere che anche $L_1\in  P$;
2. se dimostro che $L_0\preceq L_1$ , per un qualche altro linguaggio $L_0$ , allora, posso concludere che… $L_1$ non può essere “più facile” di $L_0$, ossia se $L_0$ *probabilmente* non appartiene a P allora anche $L_1$ probabilmente non appartiene a P.
