# Definizione di Macchina di Turing
La macchina di Turing della scorsa lezione utilizza tre nastri: sui primi due nastri, prima che la macchina inizi ad operare, vengono scritti dall'utente i due numeri da sommare, sul terzo, inizialmente vuoto, la macchina scrive il risultato nel corso della sua computazione. Dobbiamo, ora, formalizzare questi concetti e, allo scopo, cominciamo con il limitarci a considerare macchine di Turing che utilizzano un solo nastro.
E come funziona una macchina di Turing? Facile: quando l’unità di controllo si trova nello stato $q_0$, la testina legge il simbolo contenuto nella cella che sta scandendo, cerca una quintupla i cui primi due elementi sono $q_0$ e il simbolo letto dalla testina (che può anche essere il simbolo **blank** ◻) e, se trova una tale quintupla, la esegue; se non la trova ... non compie alcuna azione (ci torneremo più avanti) e la computazione termina.
Eseguire una quintupla significa eseguire le tre azioni in essa indicate:
1. Sovrascrivere il simbolo nella cella scandita dalla testina con il simbolo indicato nella quintupla;
2. Cambiare (eventualmente) stato interno: eventualmente, ossia, a meno che nella quintupla non sia indicato di rimanere nel medesimo stato in cui ci si trovava prima della sua esecuzione
3. Muovere (eventualmente) la testina (eventualmente, ossia a meno che nella quintupla sia indicato “ferma”)
Eseguita la prima quintupla, si cerca un’altra quintupla da eseguire (ossia, una quintupla i cui primi due elementi sono lo stato in cui si trova la machina e il simbolo letto dalla testina) e così via, fino a quando nessuna quintupla può essere eseguita
## Esempio di macchina di Turing
Consideriamo una macchina di Turing ad un nastro, $T_{parità}$ , definita sull’alfabeto    $Σ = \{ 0, 1, p, d\}$ e sull’insieme di stati 
$Q = \{q_0 , q_p , q_d , q_{(F )}\}$ con stato iniziale $q_0$ e stato finale $q_F$ il cui insieme delle quintuple è
$$\begin{align}&P  =  \{  〈 q_0 , 0, ◻, q_p , destra〉, 〈 q_0 , 1, ◻, q_d , destra〉, \\&  〈 q_p , 0, ◻, q_p , destra〉, 〈 q_d , 0, ◻, q_d , destra〉, \\&  〈 q_p , 1, ◻, q_d , destra〉, 〈 q_d , 1, ◻, q_p , destra〉, \\&  〈 q_p , ◻, p, q_F , fermo〉, 〈 q_d , ◻, d, q_F , fermo〉\}\end{align}
$$
La macchina $T_{parità}$ scandisce la sequenza di caratteri scritta sul suo nastro, cancellandoli via via che vengono scanditi, e verificando se tale sequenza contiene un numero pari o un numero dispari di ‘1’: al termine della scansione, nel primo caso scrive ‘p’ e termina, nel secondo caso scrive ‘d’ e termina.
Vediamo ora la macchina  $T_{parità}$  in azione:
1. Poniamo la macchina nello stato $q_0$;
2. Scriviamo una sequenza di caratteri sul nastro – che era precedentemente vuoto;
3. Posizioniamo la testina sul carattere più a sinistra fra quelli scritti sul nastro:
![[turing.png|center]]
Osserviamo che P contiene la quintupla $〈 q_0 , 1, ◻, q_d , destra〉$ e che essa può essere eseguita. 
Eseguiamo, dunque, la quintupla $〈 q_0 , 1, ◻, q_d , destra〉$:
![[turing_2.png|center]]
Ora possiamo eseguire la quintupla $〈 q_d , 0, ◻, q_d , destra〉∈ P$:![[turing_3.png|center]]
Ora possiamo eseguire la quintupla $〈 q_d , 1, ◻, q_p , destra〉∈ P$:
![[turing_4.png|center]]
Ora possiamo eseguire la quintupla $〈 q_p , ◻, p, q_F , ferma〉∈ P$:
![[turing_5.png|center]]
Computazione terminata!
Naturalmente, sul nastro di  $T_{parità}$  possiamo scrivere ciò che vogliamo: ad esempio, possiamo scrivere la sequenza di caratteri p010, e vedere cosa succede facendo partire questa nuova computazione:
![[turing_6.png|center]]P non contiene alcuna quintupla che inizia con la coppia $(q_0,p)$, quindi, nessuna quintupla può essere eseguita.
*Riassumiamo*: una macchina di Turing ad un nastro è completamente caratterizzata dai cinque elementi:
1. Σ, ossia, un insieme *finito* di caratteri che prende il nome di **alfabeto**;
2. Q, ossia, un insieme *finito* di **stati interni**;
3. Uno stato interno particolare (generalmente indicato come $q_0$) chiamato **stato iniziale**;
4. Un sottoinsieme $Q_F$ di Q di **stati finali**;
5. Un insieme $$P ⊆ Q × Σ × Σ × Q × \{sinistra, fermo, destra\}$$ di **quintuple** (che, sappiamo, deve essere non ambiguo, ossia,  non contiene coppie di quintuple che hanno uguali i primi due elementi, ossia, in effetti, **P è una funzione:   
P: Q × Σ → Σ × Q × {sinistra, fermo, destra}**
Ossia, possiamo dire che:   
>[!important]- Definizione
>Una macchina di Turing (ad un nastro) è una quintupla $〈 Σ, Q, q_0, Q_F, P〉$

e dare per assodata l’esistenza di unità di controllo e nastro.
## Definizione di **m**acchina di Turing
E che dire di una macchina di Turing a più nastri? È (quasi) la stessa cosa:
-Una macchina di Turing a k nastri è completamente caratterizzata da:
1. Un **alfabeto** $Σ$, ossia, un insieme *finito* di caratteri;
2. Un insieme *finito* Q di **stati interni**;
3. Uno stato interno **iniziale**;
4. Un sottoinsieme $Q_F$ di Q di **stati finali**;
5. Un insieme P di **quintuple**, ove in questo caso una quintupla ha la forma: $$ 〈 q_1 , (a_1, a_2, ... , a_k), (b_1, b_2, ... , b_k),  q_2 , (m_1, m_2, ... , m_k) 〉 $$
	1. $(a_1, a_2, ... , a_k)$ sono i caratteri che devono essere letti sui k nastri:
			$a_1$ è il carattere che deve essere letto sul nastro 1, $a_2$ è il carattere che deve essere letto sul nastro 2, ...
	2.  $(b_1, b_2, ... , b_k)$ sono i caratteri che devono essere scritti sui k nastri (sovrascrivendo $(a_1, a_2, ... , a_k)$ ):
			$b_1$ è il carattere che deve essere scritto sul nastro 1, ...
	3.  $(m_1, m_2, ... , m_k)$, sono i movimenti che devono essere eseguiti dalle k testine:
			$m_1$ è il movimento che deve essere compiuto dalla testina sul nastro 1, ...
Dunque, possiamo dire che, in generale:
>[!important] 
>Una macchina di Turing è una **quintupla** $〈 Σ, Q, q_0, Q_F, P〉$

>[!important]- Osservazione $\downarrow$

Per capire quale sia il numero di nastri di una macchina di Turing $〈 Σ, Q, q_0, Q_F, P〉$ è sufficiente osservare le quintuple contenute in P:
1. Il numero di componenti del secondo elemento di una quintupla in P (che specifica ciò che deve essere letto sul/sui nastro/nastri per poter eseguire una quintupla) corrisponde al numero di nastri!
Ad esempio, se le quintuple di una macchina di Turing hanno la forma $〈 q_1 , a_1, ... 〉$ allora si tratta di una macchina *ad un nastro*;
Se le quintuple di una macchina di Turing hanno la forma $〈 q_1 , (a_1, a_2), ... 〉$ allora si tratta di una macchina *a due nastri*, e così via.
## Definizione di **M**acchina di Turing
Dunque, possiamo dire che, in generale:
**una macchina di Turing è una quintupla $〈 Σ, Q, q_0, Q_F, P〉$**
e, come dovremmo aver compreso, una macchina di Turing è la descrizione di un procedimento di calcolo. Ossia, è un ***algoritmo descritto utilizzando le regole introdotte da Alan Turing***. In qualche modo, dunque, un programma scritto nel linguaggio progettato da Turing.
Le regole introdotte da Turing per descrivere procedimenti di calcolo costituiscono un modello di calcolo ( tanto quanto ciascun linguaggio di programmazione, ad esempio, è un modello di calcolo), un modello di calcolo che prende il nome di **Macchina di Turing**.
## Esercizi: progetto di macchine di Turing
**Esercizio**: 
Progettare una macchina di Turing a due nastri che, avendo sul primo nastro due numeri interi della stessa lunghezza, calcola il valore della loro somma scrivendo il risultato sul secondo nastro – ossia, si richiede di progettare una macchina di Turing che esegua la somma “in riga” di due numeri.
>[!important]- Osservazione 1 
Poiché i due numeri devono essere scritti entrambi sul primo nastro e ciascuno di essi è una sequenza di cifre ‘0’,‘1’, ... , ‘9’, è necessario utilizzare un ulteriore carattere (un carattere separatore) che permetta di separare i due numeri. Scegliamo, quindi, il ‘+’ come carattere separatore e, di conseguenza, assumiamo che sul primo nastro siano scritte due sequenze di cifre ‘0’,‘1’, ... , ‘9’ separate da un ‘+’.

>[!important]- Osservazione 2 
Nella macchina che stiamo per progettare, i due nastri hanno funzioni (e, dunque, significati) differenti.

Il secondo nastro serve soltanto a contenere il risultato – è il **nastro di output**. Il primo nastro serve a contenere i dati del problema e a svolgere le azioni richieste per ottenere il risultato – è il **nastro di input e di lavoro**.
**Esercizio**:
Progettare una macchina di Turing a due nastri che, avendo sul primo nastro due sequenze di cifre ‘0’,‘1’, ... , ‘9’ $\underline{della\space stessa\space lunghezza}$ separate da un ‘+’, calcola il valore della loro somma scrivendo il risultato sul secondo nastro.
*Idea della soluzione*:
1. A partire dallo stato iniziale e con la testina posizionata sul carattere più a sinistra sul primo nastro, ci posizioniamo sul carattere più a destra del primo numero ossia, sul carattere che si trova immediatamente a sinistra di ‘+’, senza mai muovere la testina sul secondo nastro;
2. (°) poi, ricordando la cifra letta e il valore del riporto, cancelliamo quella cifra sostituendola con un ‘+’ e ci posizioniamo sul carattere più a destra del secondo numero (che si trova a sinistra del ◻);
3. Poi, eseguiamo la somma fra la cifra del primo numero che ci stiamo ricordando e quello che stiamo leggendo: cancelliamo la cifra che stiamo leggendo sul primo nastro sostituendola con un ◻ e scriviamo sul secondo nastro la cifra appena calcolata muovendo, in seguito, la sua testina a sinistra e ricordando il nuovo riporto;
4. Poi, ricordando il valore del riporto della somma delle due cifre appena calcolata, spostiamo la testina sul primo nastro a sinistra dell’ultimo ‘+’;
5. E ripetiamo da (°).
A partire dallo stato iniziale e con la testina posizionata sul carattere più a sinistra sul primo nastro, ci posizioniamo sul carattere più a destra del primo numero ossia, sul carattere che si trova immediatamente a sinistra di ‘+’, senza mai muovere la testina sul secondo nastro:
1. Chiamiamo $q_i$ lo stato iniziale;
2. Indichiamo (in breve) con con s sinistra, con f fermo e con d destra;
3. Utilizziamo le quintuple $〈 q_i , (0,◻), (0,◻), q_i , (d,f)〉, ... , 〈 q_i , (9,◻), (9,◻), q_i , (d,f)〉$,
che abbreviamo con: per ogni $x ∈ \{0, ... , 9\} 〈 q_i , (x,◻), (x,◻), q_i , (d,f)〉$
e la quintupla $〈 q_i , (+,◻), (+,◻), q_{is} , (s,f)〉$
4. Osserviamo che lo stato q_i corrisponde all’azione “vai a destra finché incontri ‘+’ “;
5. Quando incontriamo ‘+’ dobbiamo smettere di muoverci a destra sul primo nastro e tornare indietro di una posizione: dobbiamo, cioè, eseguire un’azione diversa da quella regolata da $q_i$;
6. Per questo, quando sul primo nastro leggiamo ‘+’, entriamo nello stato $q_{is}$ al quale corrisponde l’azione “muoviti a sinistra sul primo nastro”.
(°) Poi, ricordando la cifra letta e il valore del riporto, cancelliamo quella cifra sostituendola con un ‘+’ e ci posizioniamo sul carattere più a destra del secondo numero (che si trova a sinistra del $◻$).
1. Memorizziamo la cifra letta e il valore del riporto nello stato: per ogni x ∈ {0, ... , 9} , entriamo nello stato $q_x^0$ se leggiamo x e il riporto è 0, entriamo nello stato $q_x^1$ se leggiamo x e il riporto è 1.
2. Utilizziamo le quintuple: per ogni x ∈ {0, ... , 9} $〈 q_{is} , (x,◻), (+,◻),q_x^0, (d,f)〉$
(in questo modo, si crea una sequenza di ‘+’ via via che le cifre del primo numero vengono cancellate)
3. Poi, per posizionarci sul carattere più a destra del secondo numero (che si trova a sinistra del $◻$) utilizziamo le quintuple:   per ogni x ∈ {0, ... , 9} $〈q_x^0, (x,◻), (x,◻),q_x^0, (d,f)〉$ e$〈q_x^1, (x,◻), (x,◻),q_x^1, (d,f)〉$.
4. Poi le quintuple $〈q_x^0, (◻,◻), (◻,◻),q_xs^0, (s,f)〉$  e $〈q_x^1, (◻,◻), (◻,◻),q_xs^1, (s,f)〉$
5. Di nuovo: l’azione corrispondente a $q_x^0$ e a $q_x^1$ è **““vai a destra finché incontri $◻$”**
6. Quando incontriamo $◻$ dobbiamo smettere di muoverci a destra sul primo nastro e tornare indietro di una posizione: dobbiamo, cioè, eseguire un’azione diversa da quella regolata da $q_x^0$ e a $q_x^1$ e per questo, quando sul primo nastro leggiamo $◻$, entriamo in uno degli stati $q_{xs}^0$ o $q_{xs}^1$ ai quale corrisponde l’azione __“muoviti a sinistra sul primo nastro”__.
Poi, ricordando il valore del riporto della somma delle due cifre appena calcolata, spostiamo la testina sul primo nastro a sinistra dell’ultimo ‘+’:
1. Utilizziamo le quintuple:   per ogni x ∈ {0, ... , 9} $〈q^0, (x,◻), (x,◻),q^0, (s,f)$ e $〈q^1, (x,◻), (x,◻),q^1, (s,f)〉$;
2. Non appena viene letto un ‘+’ sul primo nastro, è necessario cambiare stato e continuare a muoversi a sinistra: $〈 q^0, (+,◻), (+,◻), q_s^0, (s,f)〉$ e $〈q^1, (+,◻), (+,◻),q_s^1, (s,f)〉$;

3. Per fare in modo che la prima cifra incontrata al termine della sequenza di ‘1’ venga riconosciuta;
4. Quando, poi, viene letta una cifra sul primo nastro, si ricomincia dal passo (°):   per ogni x ∈ {0, ... , 9} $〈q_s^0, (x,◻), (+,◻),q_x^0, (d,f)〉$ e $〈q_s^1, (x,◻), (+,◻),q_x^1, (d,f)〉$  $(⊙)$
5. Se, invece, sul primo nastro viene letto un $◻$ allora la somma è terminata (perché i due numeri hanno lo stesso numero di cifre) e, dunque, viene scritto ’1’ sul nastro di output se il riporto è 1 e poi la macchina termina la computazione:   $〈q_s^0, (◻,◻), (◻,◻),q_F , (d,f)〉$ e $〈q_s^1, (◻,◻), (◻,1),q_F , (d,f)〉$.
Osserviamo che il punto  “e ripetiamo da (°)” si realizza tornando in uno degli stati $q_x^0$ o $q_x^1$ al passo $(⊙)$.
>[!important]- Osservazione
>La macchina che calcola la “somma in riga” di due numeri funziona soltanto se i due numeri hanno lo stesso numero di cifre.

>[!info]- ESERCIZIO(complesso)
>Progettare una macchina di Turing ad un solo nastro che, avendo sul nastro due sequenze di cifre ‘0’,‘1’, ... , ‘9’ separate da un ‘+’ , scrive (in una posizione opportuna) il valore della somma dei due numeri rappresentati dalle due sequenze – ossia, si richiede di progettare una macchina di Turing che esegua la somma “in riga” di due numeri.

>[!info]- ESERCIZIO(facile)
>Progettare una macchina di Turing ad un solo nastro che, avendo sul nastro una sequenza di ‘a’ e di ‘b’, scrive (in una posizione opportuna) il valore 1 se la sequenza è palindroma, 0 altrimenti

## **m**acchine di Turing
Il modello di calcolo *M*acchina di Turing richiede che in ogni macchina l’insieme degli stati e l’alfabeto abbiano cardinalità finita – e lo stesso vale per il numero di nastri. Cerchiamo di capire perché ripensando, ancora una volta, alla somma di due numeri.
Se fosse possibile avere un numero infinito di stati interni e un numero infinito di caratteri dell’alfabeto, il progetto di una macchina di Turing che esegue la “somma in riga” di due numeri (scrivendo il risultato sul secondo nastro) sarebbe banale: basterebbe porre $$ Σ = N ∪ \{+\} $$ e $$Q = \{q_x : x ∈  N\} ∪ \{q_i , q_F  \}$$ e utilizzare le quintuple:
1. Per ogni n ∈ $\mathbb{N}$ $〈q_i, (n,◻), (n,◻),q_n, (d,f)〉$, che legge il primo numero (scritto in una singola cella del primo nastro), entra nello stato interno corrispondente e muove la testina del primo nastro a destra per andare a cercare il secondo numero;
2. Per ogni n ∈ $\mathbb{N}$ $〈q_n , (+,◻), (+,◻),q_n , (d,f)〉$,  che “scavalca” il ‘+’;
3. Per ogni n, m ∈ $\mathbb{N}$ $〈q_n , (m,◻), (m,h),q_F , (d,f)〉$, dove *h = m+n*;
Se fosse possibile avere un numero infinito di stati interni e un numero infinito di caratteri dell’alfabeto, il progetto di una macchina di Turing che esegue la “somma in riga” di due numeri (scrivendo il risultato sul secondo nastro) sarebbe banale: basterebbe porre $\Sigma = \mathbb{N}$ e $Q = \mathbb{N} ∪ \{q_i , q_F \}$ e utilizzare le quintuple:
1. per ogni n ∈ $\mathbb{N}$ $〈q_i, (n,◻), (n,◻),q_n, (d,f)〉$,         
2. per ogni n ∈ $\mathbb{N}$ $〈q_n , (+,◻), (+,◻),q_n^, (d,f)〉$,         
3. per ogni n, m ∈ $\mathbb{N}$ $〈q_n, (m,◻), (m,h),q_F, (d,f)〉$, dove h = m+n.
Facile! Troppo facile... E, infatti, la cosa non funziona. Il punto è che questa “macchina” non potremmo *costruirla*.
1. Possiamo pensare che gli stati siano realizzati, ad esempio, mediante lampadine: a ciascuno stato corrisponde una lampadina (che è accesa o spenta a seconda che la macchina si trovi o meno in quello stato);
2. E che ciascuna quintupla sia una sorta di circuito che si occupa, fra l’altro, di controllare, accendere e spegnere le lampadine;
3. Dovremmo, dunque, predisporre tante lampadine e tanti circuiti quanti sono i numeri naturali... e mi sa che non ce la faremmo nel corso della nostra vita.
Fuor di metafora (di lampadine e bulloni), il punto è che la forma abbreviata “per ogni x ∈ A” dobbiamo poterla scrivere in forma esplicita (ossia, anche se la notazione implicita “per ogni x ∈ A”  è parecchio comoda; dobbiamo poter scrivere esplicitamente *tutti* gli stati e *tutte* le quintuple che occorrono a descrivere completamente una macchina di Turing, e lo stesso vale per il numero di nastri). Affinché questo sia possibile è necessario che il numero di stati, il numero di simboli dell’alfabeto, il numero di quintuple e il numero di nastri siano **finiti**. Ossia, che numero di stati, numero di simboli dell’alfabeto, numero di quintuple e numero di nastri siano scelti una volta per tutte:
1. E non di volta in volta a seconda del dato particolare sul quale vogliamo operare
2. Non possiamo, ribadiamo, scrivere per ogni n ∈ $\mathbb{N}$  $〈q_i, (n,◻), (n,◻),q_n, (d,f)〉$.
Ossia, è necessario che numero di stati, numero di simboli dell’alfabeto, numero di quintuple e numero di nastri siano **costanti**, ossia, ***indipendenti dall’input***.
## Tante definizioni per le macchine di Turing
Nel paragrafo 2.1 della dispensa 2 vengono presentate alcune definizioni formali relative alle macchine di Turing:
1. Parole
2. Stati globali
3. Transizioni
4. Computazioni
Queste definizioni devono essere tenute sempre presenti. Viene utilizzata la parola deterministica: questo significa che P è una funzione (avremo tempo e modo di affrontarla bene e a lungo, questa questione)
Innanzi tutto: dato un alfabeto finito $\Sigma$, una **parola** su $\Sigma$ è una sequenza **finita** di elementi di $\Sigma$ (ad esempio, aba è una parola sull’alfabeto $\Sigma$ = { a, b, c }).
L’**insieme della parole** su un alfabeto $\Sigma$ si indica con $\Sigma^*$. 
## Stati globali
Uno stato globale **SG** di una macchina di Turing è una “fotografia” della macchina ad un certo istante. Formalmente, uno *stato globale* di una macchina ad un nastro T ad un certo istante:
1. Contiene una descrizione della porzione non blank del nastro di T, della posizione della testina (e, dunque, del carattere da essa letto) e dello stato interno;  
2. Ed é rappresentato mediante la sequenza di caratteri (non blank) contenuti sul nastro in cui al carattere letto dalla testina è premesso lo stato interno.
Naturalmente, possiamo definire anche lo stato globale di una macchina a k nastri (con k costante).
### Esempi: Stati Globali
![[turing_7.png|center]]
(a): Lo stato globale iniziale $SG_0$ di una computazione della macchina che calcola la somma di due numeri vista a lezione:  $q_0= 812+53$;
(b): Uno stato globale successivo SG della stessa computazione: $= 812 + q_0^3 5$
## Transizioni
Una transizione dallo stato globale $SG_1$ allo stato globale $SG_2$ avviene quando viene eseguita una quintupla che trasforma $SG_1$ in $SG_2$. 
Formalmente, se $T =〈 Σ, Q, q_0, Q_F, P〉$ è una macchina di Turing ad un nastro, esiste una transizione da $SG_1$ a $SG_2$ se esiste una quintupla $〈q, x, x’, q’, m〉∈ P$ tale che:
1. In $SG_1$ T si trova nello stato interno q ∈ Q;
2. In $SG_1$ la testina di T sta scandendo una cella che contiene il carattere x ∈ $\Sigma$;
3. In $SG_2$ la cella che in $SG_1$conteneva il carattere x contiene il carattere x’ ∈ $\Sigma$;
4. In $SG_2$ T si trova nello stato interno q’ ∈ Q;
5. In $SG_2$ la testina di T sta scandendo la cella che si trova in posizione m rispetto a quella che stava scandendo in $SG_1$.
Il concetto può essere facilmente esteso a macchine a più nastri, con qualche tecnicismo in più, che non affrontiamo.
### Esempi: transizioni
![[turing_8.png|center]]
Un esempio di transizione dallo stato globale $=812+ q_0^3 5$ (in figura (a)) allo stato globale $=812 q_0^3 +5$  (in figura (b)) a seguito dell’esecuzione della quintupla $〈 q_0^3 , 5, 5, q_0^3 , sinistra 〉$.
## Computazione
Informalmente, una computazione di una macchina di Turing **deterministica** a un nastro   $T =〈 \Sigma, Q, q_0, Q_F, P〉$ è l’esecuzione delle quintuple di T su una sequenza di caratteri scritti sul suo nastro (e analogamente per le macchine a più nastri)
Formalmente: una **computazione** di una macchina di Turing T è una sequenza $SG_0, SG_1, SG_2, ... , SG_h, ...$di stati globali di T tali che:
1. $SG_0$ è uno stato globale iniziale, ossia, uno stato globale nel quale lo stato interno è $q_0$ e la testina è posizionata sul carattere più a sinistra scritto sul nastro;
2. Per ogni 0 ≤ i ≤ h-1, esiste una transizione da $SG_i$ a $SG_{i+1}$ oppure per ogni h ≥ i+1 $SG_h$ non è definito;
3. Per ogni i ≥ 0 esiste una transizione da $SG_i$ a $SG_{i+1}$ oppure $SG_{i+1}$ non è definito;
4. Se esiste un indice h tale che $SG_{h+1}$ non è definito allora $SG_j$ non è definito per ogni j ≥ h+1.
Se esiste un indice h tale che $SG_h$ è uno stato globale dal quale non può avvenire alcuna transizione allora la computazione **termina**, e questo accade quando lo stato interno nel quale T si trova in  $SG_h$ è uno stato finale oppure P non contiene una quintupla che possa essere eseguita in $SG_h$.
Oppure, se esiste un indice h tale che $SG_{h+1}$ non è definito allora $SG_h$ è uno stato globale dal quale non può avvenire alcuna transizione e la computazione termina, e questo accade quando lo stato interno nel quale T si trova in  $SG_h$ è uno stato finale oppure P non contiene una quintupla che possa essere eseguita in $SG_h$.
![[turing_9.png|center]]
Una computazione dallo stato globale $(5,2,◻)q_0(3,8,◻)$ (a)             
allo stato globale $q_1(5,2,◻)(3,8,1)$  (b)          
allo stato globale $q_0 (◻,◻,◻)(5,2,8) (3,8,1)$   (c)           
allo stato globale $q_F (◻,◻,◻) (5,2,8)(3,8,1)$   (d).
E così, abbiamo visto anche un modo di rappresentare uno stato globale in una macchina a più nastri.
## Trasduttori e Riconoscitori
Nel paragrafo 2.2 della dispensa 2 vengono definiti due tipi di macchine di Turing. 
1. Le macchine di tipo **trasduttore** sanno calcolare il valore di una funzione qualsiasi (ad esempio, un trasduttore sa calcolare la funzione f(a,b)=a+b).
Assumeremo sempre che le macchine di Turing di tipo trasduttore dispongano di un *nastro di output* sul quale scrivono il valore della funzione che hanno calcolato.
Un trasduttore ha _un solo stato finale_ con il quale terminare la computazione: lo stato $q_F$.
2. Le macchine di tipo **riconoscitore** sanno calcolare soltanto il  valore di funzioni booleane (ossia, funzioni il cui valore è 0 oppure 1) e non dispongono di un nastro di output.
**Il valore calcolato da un riconoscitore viene memorizzato nello stato interno con il quale la macchina termina la computazione**: $q_A$ se il valore della funzione è 1, $q_R$ se il valore della funzione è 0.
Quindi, ogni riconoscitore ha due stati finali: $q_A$  e $q_R$.
Diciamo che un riconoscitore T accetta x se la computazione T(x) termina in $q_A$ e che la macchina T rigetta x se la computazione T(x) termina in $q_R$.
### Esito di una computazione
Sempre nel paragrafo 2.2 della dispensa 2 viene introdotto il concetto di esito di una computazione.
Data una macchina di Turing T ed un suo input x, l’esito della computazione T(x) è indicato con $o_T(x)$ – informalmente è “il risultato” della computazione, la risposta che ci dà la macchina rispetto all’istanza x del problema che le abbiamo chiesto di risolvere.
Se T è una macchina di tipo **trasduttore, allora $o_T(x)$ è la parola scritta da T sul nastro di output al termine della computazione** T(x) (ossia, quando T ha raggiunto lo stato $q_F$): ad esempio, se T è il trasduttore che calcola la funzione f(a,b)=a+b. Allora $o_T(15,6)= 21$.
Se T è una macchina di tipo **riconoscitore, allora $o_T(x)$ è lo stato interno con il quale la macchina termina la computazione** T(x): ad esempio, se T è la macchina che decide se una parola è palindroma, allora $o_T(abba) =q_A$ e $o_T(baaba) =q_R$.
#### Delucidazioni
Quando si menzionerà “macchina di Turing” ci si riferirà sempre ad una macchina di tipo riconoscitore. Se invece si farà riferimento ad un trasduttore si dirà “macchina di Turing di tipo trasduttore”.


