# Funzioni più che calcolabili (e complessità)
## Qualcosa di strano
Nella definizione di una teoria della complessità in grado di classificare significativamente i linguaggi in classi di complessità crescente, *sarebbe auspicabile che $DTIME[f(n)]$ non fosse contenuto in $DTIME[g(n)]$ quando  $f(n)$ è **molto** più grande di $g(n)$* – ad esempio, quando $f (n) = 2^{g(n)}$, perché, in definitiva, quel che ci interessa è poter dire; “questo problema è più difficile di quest’altro”.
>[!important]- Teorema 6.13 (Gap Theorem) 
>Esiste una funzione totale calcolabile $f:\mathbb N\rightarrow\mathbb N$  tale che $DTIME[2^{f(n)}]\subseteq DTIME[f(n)]$. 

E, allora, questi comportamenti “strani” si verificano quando le funzioni limite sono anch’esse “strane”, e se date un’occhiata alla dimostrazione del Gap Theorem, vedete quanto è “strana” $f$. E, allora, definiamo un insieme (anzi, due) di funzioni che non sono strane.
## Funzioni time- e space-constructible
>[!important]- Definizione 6.1 
>Una funzione totale e calcolabile $f:\mathbb N\rightarrow\mathbb N$  è **time-constructible** se esiste una macchina di Turing $T$ di tipo trasduttore che, preso in input un intero $n$ espresso in notazione unaria (ossia, come sequenza di n ‘1’), scrive sul nastro output il valore $f(n)$ in unario e $dtime(T,n)\in O(f(n))$ . 

>[!important]- Definizione 6.2 
>Una funzione totale calcolabile $f:\mathbb N\rightarrow\mathbb N$ è **space-constructible** se esiste una macchina di Turing $T$ di tipo trasduttore che, preso in input il valore $n$ espresso in notazione unaria, scrive sul nastro output il valore $f(n)$ in unario e $dspace(T,n)\in O(f(n))$. 

D’ora in poi scriveremo $1^n$ per intendere una sequenza di n ’1’ – ossia, “n espresso in notazione unaria”.

>[!info] 
>Per esser chiari: “5 in notazione unaria” $= 1^5 = 11111$

*Attenzione*: l’input $n$ di una macchina che testimonia la time-contructibility (o la space-constructibility) di una funzione $f$ deve essere in notazione unaria (ad esempio, 5 è espresso come $1^5 = 11111$). Questo significa che la lunghezza dell’input è uguale al valore dell’input: $|n| = n$ , e quella macchina **scrive sul nastro di output il valore $f(n)$ in notazione unaria**.
Ad esempio, se $f(n)=n^2+3$, la macchina che testimonia la time-contructibility di $f$ scrive $1^{12} = 111111111111$ quando calcola $f(3)$.
Una funzione time-constructible è molto più che una funzione totale e calcolabile: **è una funzione che può essere calcolata in tempo proporzionale al suo valore**. In soldoni, scrivere un ‘1’ sul nastro di output richiede alla macchina che la calcola di eseguire un numero costante di istruzioni (in media), e analogamente per le funzioni space-constructible.
Tutte le funzioni “regolari” con le quali abbiamo normalmente a che fare sono sia time-constructible che space-constructible, ad esempio:
1. Tutti i polinomi – ossia, $f(n) = n^k$, con k costante;
2. Le funzioni esponenziali – ossia, $f(n) = 2^n$, o anche $f(n) = n^n$; 
3. Tantissime altre;
4. Grosso modo, le funzioni “regolari” sono time- e space-constructible.
In Appendice alla dispensa 6 trovate dimostrazioni di time-constructibility. 
Sono da considerarsi utili esercizi :
1. esercizi sul progetto di macchine di Turing;
2. esercizi sull’analisi di complessità di macchine di Turing.
## Superare il gap theorem
La funzione totale calcolabile $f:\mathbb N\rightarrow\mathbb N$ tale che $DTIME[ 2^{f(n)} ]\subseteq DTIME[f(n)]$ definita nel gap theorem non è time-constructible.
E, infatti valgono i seguenti teoremi (la cui dimostrazione non dovete studiare (non è neanche riportata sulla dispensa – se vi interessa, la trovate sul libro di testo che avete utilizzato per il primo modulo)).
>[!important]- Teorema 6.14 (Teorema di gerarchia spaziale) 
>Siano $f:\mathbb N\rightarrow\mathbb N$  e $g:\mathbb N\rightarrow\mathbb N$ due funzioni tali che $f$ è space-constructible  e $\lim_{n\rightarrow\infty}{\frac {g(n)}{f(n)}}=0$ . 
>Allora, $DSPACE[g(n)]\subset DSPACE[ f (n)]$, ossia, esiste un linguaggio $L$ tale che	$L\in DSPACE[ f(n)]$ e $L\not\in DSPACE[ g(n)]$. 

>[!important]- Teorema 6.15 (Teorema di gerarchia temporale) 
>Siano $f:\mathbb N\rightarrow\mathbb N$  e $g:\mathbb N\rightarrow\mathbb N$ due funzioni tali che $f$ è time-constructible  e $\lim_{n\rightarrow\infty}{\frac {g(n)log\space g(n)}{f(n)}}=0$ . 
>Allora, $DTIME[g(n)]\subset DTIME[ f (n)]$, ossia, esiste un linguaggio $L$ tale che	$L\in DTIME[ f(n)]$ e $L\not\in DTIME[ g(n)]$. 

Ma qual è il significato dei teoremi di gerarchia spaziale e temporale?
Se $\lim_{n\rightarrow\infty}{\frac {g(n)}{f(n)}}=0$ , allora $f$(n) cresce “*asintoticamente più velocemente*” di $g(n)$ (ossia, man mano che $n$ cresce, la distanza fra $g(n)$ e $f(n)$ aumenta sempre di più, o, se preferite, $f(n)$ diventa enormemente grande per valori di $n$ molto più piccoli di quelli che occorrono a $g(n)$ per diventare altrettanto grande).
E un discorso analogo vale (a maggior ragione!) se $\lim_{n\rightarrow\infty}{\frac {g(n)log\space g(n)}{f(n)}}=0$.
Quindi, il teorema di gerarchia temporale ci dice che, *quando f è time-constructible*, **$DTIME[f(n)]$ *non* è contenuto in $DTIME[g(n)]$ quando  $f(n)$ è molto più grande di $g(n)$** – ad esempio, quando $f (n) = 2^{g(n)}$ .
E analogamente per quanto afferma il teorema di gerarchia spaziale relativamente alle classi DSPACE quando f è space-constructible.
## Questioni aperte
Innanzi tutto, c’era la questione della definizione delle classi di complessità non deterministiche – dove viene richiesta la **accettabilità** di un linguaggio, pur sapendo che, ogni volta che fissiamo la quantità massima di risorse (spazio o tempo) utilizzabile, un linguaggio accettabile è anche decidibile. Non conosciamo la quantità di risorse che occorrono per rigettare le parole che non vi appartengono.
Poi, sappiamo che tutto ciò che è deciso da una macchina non deterministica può essere deciso anche da una macchina deterministica.
Tuttavia, un linguaggio che sappiamo appartenere a $NTIME[f(n)]$ non sappiamo ancora in quale classe di complessità temporale deterministica collocarlo, né sappiamo se il fatto di sapere che appartiene a $NTIME[f(n)]$ ci fornisca strumenti in grado di affermare “ok, allora sta pure in $DTIME[qualche\space altra\space funzione]$”.
### La prima questione aperta
Innanzi tutto, non è proprio piacevole dover ammettere che se un certo linguaggio $L$ è in $NTIME[f(n)]$, ossia, sappiamo che esiste una macchina $NT$ che accetta le sue parole $x$ (ossia, le parole $x\in L$) eseguendo $O( f(|x|))$ istruzioni. Non sappiamo quanto tempo occorre per capire che una parola non appartiene a quel linguaggio, ossia, quando $x\not\in  L$ non sappiamo quante istruzioni sono eseguite da ciascuna computazione deterministica di $NT(x)$ – che, sappiamo, rigetta.
Ebbene, il prossimo teorema afferma che:
1. Se $f$ è *time-constructible* e $L$ è in $NTIME[f(n)]$, allora la macchina $NT$ che accetta le parole x di $L$ eseguendo $O(f(|x|))$ istruzioni è anche capace di rigettare le parole non in $L$ eseguendo $O(f(|x|))$ istruzioni;
2. Se $f$ è *space-constructible* e $L$ è in $NSPACE[f(n)]$, allora la macchina $NT$ che accetta le parole di $L$ utilizzando $O(f(|x|))$ celle del nastro è anche capace di rigettare le parole di $L$ utilizzando $O(f(|x|))$ celle del nastro.
>[!important]- Teorema 6.16 
>Sia $f:\mathbb N\rightarrow\mathbb N$  una funzione time-constructible. Allora, per ogni $L\in NTIME[ f (n)]$, si ha che $L$ è decidibile in tempo non deterministico in $O( f (n))$.  	
>Sia $f:\mathbb N\rightarrow\mathbb N$ una funzione space-constructible. Allora, per ogni $L\in NSPACE[ f (n)]$, si ha che L è decidibile in spazio non deterministico in $O( f (n))$. 

Dimostriamo soltanto il caso in cui f è time-constructible.
La dimostrazione del caso in cui f è space-constructible è analoga. 
Riutilizziamo, aggiustandola opportunamente, la dimostrazione del Teorema 6.2:
>[!important]- Teorema 6.2 (tempo): 
>Sia $f:\mathbb N\rightarrow\mathbb N$ una funzione totale calcolabile.
>Se $L\subseteq\Sigma^*$ è accettato da una macchina di  Turing non deterministica $NT$ tale che, per ogni $x\in L$, $ntime(NT,x)\leq f (|x|)$ allora $L$ è decidibile.

Lo vedete quanto si assomigliano i due teoremi?
Sia $f:\mathbb N\rightarrow\mathbb N→$  una funzione time-constructible. Allora, per ogni  $L\in NTIME[ f (n)]$, si ha che L è decidibile in tempo non deterministico in $O( f(n))$.	
$L\in NTIME[f(n)]$: sia $NT$ la macchina che accetta $L$, e assumiamo che, per $x\in L$, $ntime(NT,x)\leq c\space f(|x|)$, per qualche costante $c > 0$.
Poiché *$f$ è time-constructible*, **anche $c\space f$  è time-constructible**: allora, esiste una macchina $T_f$ di tipo trasduttore tale che, per ogni $n\in\mathbb N$ , $T_f(1^n)$ termina con il valore $c\space f(n)$ scritto sul nastro di output in unario dopo aver eseguito $O(c\space f(n))$ istruzioni.
Costruiamo una nuova macchina non deterministica $NT’$, a tre nastri, che decide $L$: per ogni $x\in\Sigma^*$:
1. $NT’(x)$ scrive $|x|$ in unario sul secondo nastro e invoca $T_f(|x|)$: al termine della computazione sul terzo nastro si troverà scritto $c\space f(|x|)$ in unario;
2. $NT’(x)$ invoca $NT(x)$ e, per ogni quintupla eseguita non deterministicamente da NT(x):
	*2.1* $NT’$ “cancella” un ‘1’ dal terzo nastro e, inoltre,
	*2.2* Se $NT(x)$ accetta allora anche $NT’(x)$ accetta, se $NT(x)$ rigetta allora anche $NT’(x)$ rigetta;
3. Se quando il terzo nastro di $NT’$ è vuoto $NT(x)$ non ha ancora terminato, allora $NT’(x)$ rigetta.
Osserviamo, intanto, che le computazioni di $NT’$ terminano sempre. 
Se la simulazione di una computazione di $NT(x)$ dura più di $c\space f(|x|)$ passi, la interrompiamo.
Poi, $NT’$ decide $L$, infatti:
1. Se $x\in L$, allora $NT(x)$ accetta in al più $c\space f(|x|)$ passi: e, quindi, $NT’(x)$ accetta;
2. Se $x\not\in L$, allora o $NT(x)$ rigetta in al più $c\space f(|x|)$ passi e, quindi, $NT’(x)$ rigetta, oppure $NT(x)$ non termina entro $c\space f(|x|)$ passi e, quindi, $NT’(x)$, ugualmente, rigetta.
**Ma quanto impiega $NT’$ a decidere se $x\in L$ oppure no?**
1. $O(c\space f(|x|)$ per calcolare $c\space f(|x|)$ – perché $c\space f$  è time-constructible;
2. E altri $c\space f(|x|)$ passi per simulare $c\space f(|x|)$ passi di $NT(x)$;
3. Ossia, $O(f(|x|))$ passi.
*Per questo possiamo concludere che L è decidibile, in tempo non       deterministico $O(f(n))$*.
### La seconda questione aperta
Le uniche relazioni che conosciamo (fino ad ora) fra classi deterministiche e classi non deterministiche sono quelle banali: $$DTIME[f(n)]\subseteq NTIME[f(n)]\space e\space DSPACE[f(n)]\subseteq NSPACE[f(n)].$$ Basate sull’osservazione che una macchina deterministica è una particolare macchina non deterministica.
A parte ciò, sappiamo che tutto ciò che è deciso da una macchina non deterministica può essere deciso anche da una macchina deterministica
Tuttavia, un linguaggio che sappiamo appartenere a $NTIME[f(n)]$ non sappiamo in quale classe di complessità temporale deterministica collocarlo, 
non sappiamo se esiste un funzione $g(n)$ che magari cresce molto più velocemente di $f(n)$, tale che possiamo affermare “se $L$ appartiene a $NTIME[f(n)]$ allora $L$ appartiene a $DTIME[g(n)]$”, a meno che la funzione limite $f$ della classe non sia una funzione time-constructible…
>[!important]- Teorema 6.17
>Per ogni funzione time-constructible $f:\mathbb N\rightarrow\mathbb N$ , $NTIME[ f (n)]\subseteq DTIME[ 2^{O( f (n))} ]$. 

Sia $L\subseteq\{0,1\}^*$ tale che $L\in NTIME[f(n)]$; allora esistono: 
1. Una macchina di Turing non deterministica $NT$ che accetta $L$; 
2. Una costante $h$. 
Tali che, per ogni $x\in L$, $ntime(NT,x)\leq hf(|x|)$.
Poiché $h f$ è time-constructible, esiste $T_f$ che, con input $1^n$, calcola $1^{hf(n)}$ in tempo $O( f(n))$. 
Indichiamo con $k$ il grado di non determinismo di $NT$, e ricordiamo che $k$ è una costante, indipendente dall’input, e utilizziamo di nuovo la tecnica della simulazione per definire una macchina di Turing deterministica $T$, dotata di 3 nastri, che simuli il comportamento di $NT$: 
Su input $x$, $T$ simula in successione, una dopo l’altra, tutte le computazioni deterministiche di $NT(x)$ di lunghezza $h f (|x|)$. 
>[!important]- Teorema 6.17 
>Per ogni funzione time-constructible $f:\mathbb N\rightarrow\mathbb N$ , $NTIME[f(n)]\subseteq DTIME[2^{O(f(n))}]$. 

La macchina $T$ con input $x$ opera in due fasi, come di seguito descritto: 
**FASE 1)**  Simula la computazione $T_f(|x|)$: 
1. per ogni carattere di $x$, scrive sul secondo nastro un carattere ‘1’ - ossia, scrive $1^{|x|}$ sul secondo nastro; 
2. in seguito, calcola $1^{f(|x|)}$ scrivendolo sul terzo nastro; 
3. infine, concatena $h$ volte il contenuto del terzo nastro ottenendo il valore $1^{h f (|x|)}$.
	*3.1*(stiamo dimostrando che: se $f$ è time-constructible allora anche $h f$ è time constructible, cosa che nel teorema precedente avevamo solo enunciato). 
**Fase 2)** Simula, una alla volta, tutte le computazioni deterministiche di $NT(x)$ di lunghezza $h f(|x|)$ utilizzando, per ciascuna computazione, la posizione della testina sul terzo nastro come contatore:
1. simula al più $h f(|x|)$ passi della computazione più a sinistra di tutte nell’albero $NT(x)$: se tale computazione accetta entro $h f(|x|)$ passi allora $T$ termina in $q_A$, altrimenti;
2. simula al più $h f(|x|)$ passi della computazione immediatamente più a destra di quella appena simulata: se tale computazione accetta entro $h f(|x|)$ passi allora $T$ termina in $q_A$, altrimenti;
3. …
4. simula al più $h f(|x|)$ passi della computazione più a destra di tutte nell’albero $NT(x)$: se tale computazione accetta entro $h f(|x|)$ passi allora $T$ termina in $q_A$, altrimenti $T$ termina in $q_R$.
$T$ decide $L$: infatti, poiché in al più $h f(|x|)$ passi $NT$ accetta le parole $x\in L$, allora se $x\in L$, allora in $hf(|x|)$ passi una delle computazioni deterministiche di $NT(x)$ termina nello stato di accettazione. 
	Allora, durante la *FASE 2)*, poiché $T$ simula i primi $h f(|x|)$ passi di tutte le computazioni deterministiche di $NT(x)$ fino a quando una di esse accetta oppure non le ha esaminate tutte, prima o poi $T$ simulerà anche quella accettante: e questo porterà $T$ nello stato $q_A$.
Se $x\not\in L$, allora in $hf(|x|)$ passi nessuna delle computazioni deterministiche di $NT(x)$ termina nello stato di accettazione. 
	Allora, durante la *FASE 2)*, $T$ dovrà simulare i primi $h f(|x|)$ passi di **tutte** le computazioni deterministiche di $NT(x)$ (da quella più a sinistra nell’albero a quella più a destra, nessuna esclusa), perché nessuna di esse accetta: e questo porterà $T$ nello stato $q_R$.
Questo prova che $T$ decide $L$. 
Ma quanto tempo impiega T a decidere L? 
Intanto, la *FASE 1)* richiede $O( h f(|x|)$ passi – perché $f$ è time-constructible
Poi, riguardo la *FASE 2)*:
1. Sia $k$ il grado di non determinismo di $NT$ – k è costante!
2. Allora, il numero di computazioni deterministiche di $NT(x)$ di lunghezza $h f(|x|)$ è  $k h f(|x|)$; 
3. ciascuna di queste computazioni viene simulata da $T$ in $O( h f(|x|))$ passi. 
Allora, $dtime(T,x)\in O(hf(|x|)+hf(|x|)k^{hf(|x|)})=O(hf(|x|)k^{hf(|x|)})\subseteq O(2^{O(f(|x|)})$.
Infine, in virtù del Teorema 6.3, esiste una macchina $T_1$ ad un nastro tale che 
1. Per ogni input $x$, l’esito della computazione $T_1(x)$ coincide con l’esito della computazione $T(x)$; 
2. Esiste una costante $c$ tale che $dtime(T1,x)\leq dtime(T,x)^c\in O(2^{O(f(|x|))} )$.
Questo conclude la dimostrazione che $L\in DTIME[2^{O(f(|x|))}]$. 
