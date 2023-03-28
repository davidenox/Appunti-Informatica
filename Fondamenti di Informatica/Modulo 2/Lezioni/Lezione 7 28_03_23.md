# Modelli di calcolo
Esiste un modello di calcolo più potente della Macchina di di Turing? Che “sa risolvere più problemi”?
Ebbene: per tutti i modelli di calcolo definiti fino ad ora, è stato dimostrato che sanno “risolvere” tutti e soli i problemi che possono essere “risolti” mediante la Macchina di Turing
Ossia, tutti i modelli di calcolo introdotti sino ad ora sono **Turing-equivalenti**.
Viene quasi da pensare che un modello di calcolo più potente della Macchina di Turing non esista, posto che esso consideri “*operazione elementare*” una operazione che possa essere eseguita “*a mente*” da un umano medio.
## La tesi di Church-Turing
Questa tesi assume che non esista un modello di calcolo più potente della Macchina di Turing: dato un qualunque altro modello di calcolo **M**: 
1. Se un linguaggio L è decidibile/accettabile nel modello **M** allora L è decidibile/accettabile nel modello Macchina di Turing;
2. Se una funzione f è calcolabile nel modello **M** allora f è calcolabile nel modello Macchina di Turing, e viceversa.
Purché **M** sia un modello”*ragionevole*”, ossia, sia basato sul concetto di *operazione elementare* del quale abbiamo parlato diffusamente.
Se definiamo un modello di calcolo che disponga dell’unica operazione elementare “qualunque sia il problema, qualunque sia l’istanza del problema, trova la soluzione di quell’istanza”.
È ovvio che questo modello è più potente della macchina di Turing, ma non è mica tanto realistico (nel senso che dalla Macchina di Turing sono nati i calcolatori, ma è difficile che nascano macchine reali che corrispondano a questo modello).
Dunque, **è calcolabile tutto e solo ciò che può essere calcolato dalla Macchina di Turing**.
*Attenzione*: è una tesi, non è un teorema, non è mai stata dimostrata.
E sembra difficile riuscire a dimostrarla: sembra difficile riuscire a prevedere i modelli di calcolo che potrebbero essere definiti nel futuro.
Tuttavia, sembra poco probabile riuscire a progettare un modello di calcolo che non la soddisfi, e, non dimentichiamolo, tutti i modelli di calcolo esistenti la soddisfano, infatti, è generalmente accettata.
## Il modello di calcolo PascalMinimo
È un linguaggio di programmazione () perché ogni linguaggio di programmazione è un modello di calcolo).
Dispone di tutte le istruzioni “tipiche” dei linguaggi di programmazione:
1. Istruzione di assegnazione: **a  b** ; 
2. Istruzione condizionale **if … then ... else**;
3. Istruzioni di loop **while** ( … ) **do** e **for** (...);
4. Funzioni;
5. Istruzioni per l’input e l’output;
6. ecc. ecc.
E dispone di variabili semplici (intere, caratteri, ...) ma anche di variabili che corrispondono a collezioni di oggetti – insiemi e, soprattutto, **array**.
>[!info]
>Nella dispensa 3, a partire da pag. 7, si accenna alla dimostrazione che il modello di calcolo PascalMinimo è equivalente alla Macchina di Turing.
>Nel Teorema 3.5 si dà un’idea (grossolana) di come “trasformare” un programma in PascalMinimo in una macchina di Turing che “faccia le stesse cose”.
>Nel Teorema 3.6 si dà un’idea (abbastanza precisa) di come “trasformare” una macchina di Turing in un programma in PascalMinimo che “faccia le stesse cose”.

>[!important]- Teorema 3.5 
>Per ogni programma scritto in accordo con il linguaggio di 						programmazione PascalMinimo, esiste una macchina di Turing T di 				tipo trasduttore che scrive sul nastro di output lo stesso valore 						fornito in output dal programma. 

### PascalMinimo e macchine di Turing
>[!important]- Teorema 3.6
>Per ogni macchina di Turing deterministica T di tipo riconoscitore 					ad un nastro esiste un programma $A_T$ scritto in accordo alle regole 				del linguaggio PascalMinimo tale che, per ogni parola $x$, se $T(x)$ 					termina nello stato finale $q_F  \{q_A,q_R\}$ allora $A_T$ con input x 							restituisce $q_F$ in output. 

Dimostriamo questo teorema progettando un programma U  che si comporta come la macchina Universale:
1. Utilizzando opportune strutture dati per rappresentare  le quintuple di una generica macchina di Turing , e il suo stato iniziale, e i suoi stati finali;
2. E altre opportune strutture dati per rappresentare un input di quella generica macchina;
3. Fornendo in input ad U le descrizioni di una data macchina T e di un suo dato input x (in accordo alle strutture dati utilizzate);
4. L’esecuzione di U sul suo input restituisce un output che corrisponde allo stato in cui terminerebbe la computazione T(x) (o che non termina qualora T(x) non terminasse).
Progettiamo un programma U  che si comporta come la macchina Universale:
1. Per memorizzare le quintuple della macchina T che si vuole simulare, utilizziamo i 5 array Q1, S1, S2, Q2, M:
		Usiamo i valori -1, 0, 1 per rappresentare i movimenti della testina ‘sinistra’, ‘ferma’, ‘destra’;
2. Se la **i**-esima quintupla di T è $〈 q , a, b, q’ , sinistra〉$,  allora avremo 							$Q1[ i ] =q, S1[ i ] = a, S2[ i ] = b, Q2[ i ] = q’, M[ i ] = -1$ e analogamente per i movimenti della testina ‘ferma’ e ‘destra’;
3. $Q1[i]$ memorizza lo stato in cui si deve trovare la macchina per eseguire la quintupla i, $Q2[i]$ memorizza lo stato in cui deve entrare la macchina dopo aver eseguito la quintupla i, e analogamente per $S1[i], S2[i]$ e $M[i]$;
4. Rappresentiamo il nastro di T mediante l’array N, che, per semplicità, ammettiamo possa avere anche indici negativi (ad esempio, $N[-4]$: tanto il PascalMinimo ce lo stiamo inventando)
A questo punto, vediamo il programma:
![[Pasted image 20230328113042.png|center]]
![[Pasted image 20230328113110.png|center]]
![[Pasted image 20230328113155.png|center]]
![[Pasted image 20230328113333.png|center]]
Guardiamo insieme ora l’algoritmo in PascalMinimo che simula una macchina di Turing non deterministica (che trovate al paragrafo 3.4) , meno facile rispetto alla simulazione della macchina Universale.
L’algoritmo implementa in  PascalMinimo la coda di rondine con ripetizioni che abbiamo descritto informalmente nel corso della Lezione 4, e che dimostra il Teorema 2.1 (Dispensa 2):
1. Inizializza un contatore i a 1;
2. Simula **tutte** le computazioni deterministiche di i istruzioni:
	- Se una di esse accetta, allora accetta;
	- Altrimenti; se tutte rigettano, allora rigetta;
3. Se al passo precedente non hai terminato (ossia, nessuna computazione di i passi ha accettato e almeno una di esse non ha rigettato), allora incrementa il valore di i e ripeti il passo precedente.
E tutto ciò si traduce in PascalMinimo nel programma seguente:
![[Pasted image 20230328114017.png|center]]

Ove la simulazione di tutte le computazioni deterministiche è eseguita dall’invocazione della funzione ricorsiva *simulaRicorsivo$(q_0 , 1, N , i)$* , i cui parametri sono: lo stato interno ($q_0$), la posizione della testina (1) e il contenuto del nastro (N) della macchina non deterministica quando ha inizio la simulazione, e la lunghezza (i) delle computazioni da simulare.
Ecco lo schema della funzione ricorsiva:
![[Pasted image 20230328114155.png|center]]

![[Pasted image 20230328114236.png|center]]
