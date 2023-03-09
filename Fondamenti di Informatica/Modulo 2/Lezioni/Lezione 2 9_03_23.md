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
(slide 17)





