
# Il corso
Il corso si distingue in due parti principali:
1. La parte di calcolabilità (ovvero quali problemi possono essere risolti automaticamente);
2. La parte di complessità (ovvero quali problemi so risolvere per davvero).
Un **problema** è la descrizione di un insieme di parametri, che chiameremo *dati*, collegati da un certo insieme di relazioni, associata alla richiesta di derivare da essi un altro insieme di parametri, che costituiscono la **soluzione**. Un’**istanza** di un problema è un particolare insieme di valori associati ai dati.

## Trovare la soluzione di un’istanza
Per trovare la soluzione di talune istanze di taluni problemi posso sfruttare le caratteristiche di quelle istanze. D’altra parte, a volte non è così semplice, altre volte è impossibile.
Quando l’istanza di un problema non ha soluzione diciamo che essa è una **istanza negativa**.
## Risolvere un problema 
Risolvere un problema significa individuare un metodo che sappia trovare la soluzione di qualunque istanza positiva del problema e, in più, che sappia riconoscere se un’istanza è negativa Ossia, significa trovare un procedimento che, data una qualunque istanza del problema, indichi la sequenza di azioni che devono essere eseguite per trovare la soluzione di quell’istanza, o per poter concludere che, quell’istanza, una soluzione non ce l’ha.
### Cos’è un procedimento? 
Un procedimento è la descrizione di un insieme di azioni unita alla specifica dell’ordine con il quale le azioni devono essere eseguite.
#### E che cos’è una azione? 
Qualcosa che deve esser fatto, ovvio! Tuttavia, anche “data un’istanza del problema, trova la soluzione di quell’istanza” è una azione. Allora, dobbiamo dire che le azioni indicate in un procedimento, devono essere azioni semplici, azioni, cioè, che possono essere eseguite con facilità.
#### Esempio
Data una funzione $f:\mathbb R \to\mathbb R^+$ e dati due numeri reali a e b, calcolare la misura dell'area della regione di piano compresa fra la funzione, l'asse x e le rette y=a e y=b.
###### Procedimento
1. Calcola la funzione primitiva F(x) di f(x);
2. Calcola F(b)-F(a).
Un **procedimento** è la descrizione di un insieme di azioni unita alla specifica dell’ordine con il quale le azioni devono essere eseguite e, a ciascuna di quelle azioni, viene dato il nome di *istruzione*. Le istruzioni indicate in un procedimento devono essere ***elementari***, devono, cioè, essere azioni che possono essere eseguite con facilità.
## L'istruzione elementare
Se vogliamo svincolare la definizione di procedimento risolutivo di un problema da quello di esecutore delle azioni in esso indicate, è necessario, prima di tutto, chiarire formalmente cosa si intende con istruzione elementare. Vediamo, a tal proposito, la soluzione individuata da Alan Turing a questa questione:
Turing, osservò che, indipendentemente dall’esecutore, qualunque istruzione, per potere essere definita elementare, deve avere le seguenti caratteristiche: 
1. Deve essere scelta in un insieme di “poche” istruzioni disponibili; 
2. Deve scegliere l’azione da eseguire all’interno di un insieme di “poche” azioni possibili; 
3. Deve poter essere eseguita ricordando una quantità limitata di dati, ossia, in termini più tecnici, utilizzando una quantità limitata di memoria. 
Osserviamo che le caratteristiche individuate da Turing indicano come istruzione elementare una operazione che possa essere eseguita... a mente!
#### Esempio
Consideriamo il PROBLEMA SOMMA: dati due interi n e k, ci viene richiesto di calcolare s=n+k. Vogliamo progettare un procedimento che risolva questo problema. Ebbene: calcolare la somma di due interi è certamente facile; allora, potremmo pensare che l’istruzione “calcola n + k” sia un’istruzione elementare.
**ATTENZIONE**: stiamo cercando un procedimento che risolva un problema (il PROBLEMA SOMMA), quindi “calcola n + k” deve essere un’istruzione elementare qualunque valore venga assegnato a n e k. Però, se n = 37895 e k = 441238 ... a nessuno di noi, soltanto guardando i due addendi, salta in mente il risultato, anche se le addizioni le sappiamo fare benissimo!
Ma se disponessimo di una tabella sufficientemente grande che indica le somme di tutti i numeri naturali compresi fra 0 e 1000000 (ad esempio), ci basterebbe guardare nella cella opportuna e avremmo la somma cercata:

![[tabellina 1.png|center]]
Il problema è che, per risolvere il PROBLEMA SOMMA, occorre indicare un procedimento che sappia addizionare qualunque coppia di numeri naturali, per quanto grandi essi siano, e, quindi, se volessimo considerare istruzione elementare la somma di qualunque coppia di numeri, dovremmo costruire una tabella infinita!
Per questa ragione, per eseguire la somma di qualunque coppia di numeri naturali, utilizziamo un procedimento che:
1. utilizza un numero limitato di operazioni elementari (le somme di coppie di numeri di una sola cifra); 
2. in cui ogni operazione elementare utilizza una quantità limitata di dati (due cifre e l’eventuale riporto).
In accordo alle caratteristiche enunciate da Turing
Per calcolare il valore della somma 37895 + 441238, innanzi tutto scriviamo l’operazione in colonna: 3 7 8 9 5 + 4 4 1 2 3 8 
poi, osserviamo le due cifre più a destra, e calcoliamo la loro somma e l’eventuale riporto 3 7 8 9 **5** + 4 4 1 2 3 **8** = ---- *3* con riporto di *1* 
poi, osserviamo le due cifre più a destra non ancora considerate, e calcoliamo la loro somma più l’eventuale riporto, e il nuovo eventuale riporto 3 7 8 **9** 5 + 4 4 1 2 **3** 8 = --------*3 3* con riporto di *1*
e così via ...
Pensandoci bene, potremmo descrivere il procedimento per calcolare la “somma in colonna” di due numeri naturali nel modo seguente: 
1) Posizionati sulla coppia di cifre più a destra, e poni r = 0; 
2) Fino a quando leggi una coppia di cifre, esegui la somma della coppia di cifre sulle quali sei posizionato, aggiungi r a tale valore e scrivi una cifra del risultato calcolando anche il nuovo valore di r, e poi spostati a sinistra;
3) Fino a quando leggi una sola cifra (ossia, le cifre di uno dei due numeri sono terminate) aggiungi r ad essa e scrivi una cifra del risultato calcolando anche il nuovo valore di r, e poi spostati a sinistra;
4) Se le cifre di entrambi i numeri sono terminate, allora calcola l’eventuale ultima cifra del risultato e termina.
Il procedimento per calcolare la “somma in colonna” di due numeri naturali è una sequenza di **“se sono vere certe condizioni** *allora* **esegui queste azioni”**. Ma, pur essendo istruzioni elementari da un punto di vista intuitivo, sono quelle appena individuate istruzioni elementari nel senso indicato da Turing?
Nell’accezione di Turing, un’istruzione, per potere essere definita elementare, deve avere le seguenti caratteristiche: 
1. Deve essere scelta in un insieme di “poche” istruzioni disponibili;
2. Deve scegliere l’azione da eseguire all’interno di un insieme di “poche” azioni possibili;
3. Deve poter essere eseguita ricordando una quantità limitata di dati, ossia, in termini più tecnici, utilizzando una quantità limitata di memoria.
Ma è vero che Il procedimento che esegue la somma ha un insieme di “poche” istruzioni disponibili ciascuna delle quali utilizza una quantità limitata di memoria?
Riflettiamo: 
1. Il numero di istruzioni disponibili è pari al numero di coppie di cifre moltiplicato per il numero di possibili valori per il riporto, ossia, 10 x 10 x 2 = 200; 
2. Per sapere quale istruzione dobbiamo eseguire abbiamo bisogno di conoscere le due cifre da sommare e il valore del riporto, ossia, 3 numeri di una cifra.
Ricapitolando: per sommare qualunque coppia di interi (grandi quanto ci pare) abbiamo a disposizione **222 istruzioni** (che eseguono 2 azioni) fra le quali scegliere quella da eseguire utilizzando una memoria di *3* cifre. Indipendentemente da quanto sono grandi i due numeri che vogliamo sommare, sempre 222 istruzioni (che eseguono 2 azioni) disponibili che utilizzano una memoria di 3 cifre sono!
*Il numero di istruzioni, azioni e la quantità di memoria necessaria sono -**costanti**-: non dipendono da quello che chiameremo input*.
Pensandoci bene, per eseguire questo procedimento non è necessario nemmeno sapere cosa significa “sommare due numeri naturali”: esegui le istruzioni del procedimento e, come per magia, alla fine ti ritrovi con il risultato in mano! 
**Attenzione**, però: per ottenere il risultato devi eseguire le istruzioni; ossia, ogni volta che si verificano quelle condizioni tu quelle azioni devi eseguirle, senza se e senza ma, le esegui e basta! Le istruzioni sono una sorta di ordini. Questa idea di istruzione, nata dall’analisi di Turing, è alla base di molti linguaggi di programmazione che, proprio per questo, vengono detti imperativi. Questo procedimento potrebbe anche essere eseguito da un automa.
## Risolvere automaticamente un problema
Informalmente, risolvere automaticamente un problema significa progettare un procedimento che risolve tutte le istanze di quel problema e che può essere eseguito da un automa, ossia da un esecutore che può non avere alcuna idea del problema né del significato delle istruzioni contenute nel procedimento.
#### Un nuovo linguaggio...
Ripensiamo alla somma di due numeri naturali:
1) Il procedimento che abbiamo visto è costituito di sole istruzioni “se sono vere certe condizioni allora esegui queste azioni”, ripetute fino a quando non si incontra il comando “termina”;
2) In ciascuna istruzione le azioni da eseguire sono le 3 azioni seguenti: la scrittura di una cifra, la (eventuale) modifica del riporto, il movimento a sinistra per considerare le successive due cifre da sommare;
3) infine, le condizioni di ognuna delle istruzioni dipendono da due tipi di parametri:
1. Il valore del riporto;
2. Le due cifre da sommare.
In virtù delle osservazioni 1), 2) e 3), possiamo scrivere il nostro procedimento in forma più compatta, come ad esempio l'istruzione:
"se r = 0 e le due cifre sono 4 e 6, allora scrivi 0, poni r = 1, e spostati di una posizione a sinistra"
diventa: $$〈q_0 , (4, 6), 0,q_1 , sinistra 〉$$
e l’istruzione:
"se r = 1 e l’unica cifra è 5, allora scrivi 6, poni r = 0, e spostati di una posizione a sinistra"
nella quale le cifre di uno degli operandi sono terminate, diventa la coppia di istruzioni
$$〈q_1 , (5, ◻), 6,q_0 , sinistra 〉$$

$$〈 q_1, (◻, 5), 6,q_0 , sinistra 〉$$

dove il simbolo ◻ indica che non viene letto alcunché o che non deve essere scritto alcunché, e abbiamo due diverse istruzioni perché l’operando le cui cifre sono terminate può essere il primo o il secondo.
Infine, le istruzioni "se r = 1 e le cifre di entrambi i numeri sono terminate, allora scrivi 1 e termina" e "se r = 0 e le cifre di entrambi i numeri sono terminate, allora termina" diventano, rispettivamente
$$〈 q_1, (◻, ◻), 1,q_F , fermo 〉$$

$$〈q_0 , (◻, ◻), ◻,q_F , fermo 〉$$

dove è lo “stato interiore” che permette all’esecutore di comprendere che non deve più eseguire alcuna azione (ossia, non si deve “tornare al punto 2)”), e qui l’utilizzo di “fermo” mostra anche perché è necessario specificare come ci si deve muovere.
#### ... e una macchina che lo comprende
Possiamo, a questo punto, rappresentare graficamente l’esecuzione del procedimento che calcola la somma di due numeri qualsiasi, ad esempio, i numeri 53 e 28. Per farlo, immaginiamo di disporre di una sorta di automa, che rappresentiamo come una specie di “testa robotizzata” e che può trovarsi in uno di tre possibili “stati interiori”: , e che utilizza, per leggere e scrivere , tre nastri suddivisi ciascuno in un numero infinito di celle tali che ciascuna cella, in ogni istante, può contenere o una cifra (un numero compreso fra 0 e 9) oppure può essere vuota (e indichiamo con ◻ il simbolo di cella vuota) e tre testine di lettura/scrittura.
Non appena viene scritto qualcosa sui nastri, dipendentemente dallo “stato interiore” dell’automa e da quello che viene letto, l’automa inizia a computare, ossia a eseguire le quintuple del procedimento.
![[touring.png|center]]
#### Quasi una macchina di Turing
Quella che abbiamo visto è quasi una descrizione informale di una macchina di Turing; *quasi*, perché abbiamo utilizzato tre nastri e in una macchina di Turing occorre descrivere cosa viene letto (nelle condizioni) e cosa viene scritto (nelle azioni) su ogni nastro, così che l’istruzione 
**se r = 0 e le due cifre sono 4 e 6, allora scrivi 0, poni r = 1, spostati di una posizione a sinistra e torna al punto 2)**
diventa $$〈 q_0, (4, 6, ◻), (4, 6, 0),q_1 , sinistra 〉$$

che specifica cosa deve essere scritto sui 3 nastri (4, 6, ◻) e con cosa questi tre elementi devono essere sovrascritti (4, 6, 0). Poiché specifica 2 condizioni e 3 azioni, essa prende il nome di **quintupla** e, quelli che abbiamo chiamato sino ad ora *“stati interiori”*, si chiamano propriamente **stati interni**, e l’esecuzione delle quintuple su un insieme fissato di dati (come nella figura) si chiama **computazione**.
#### Calcolabilità
Quella che abbiamo visto è, dunque, una descrizione informale di una macchina di Turing (con la ‘m’ minuscola), che è la descrizione di un procedimento di risoluzione di un problema espresso nel linguaggio definito da Alan Turing, linguaggio che costituisce un modello di calcolo: il modello **Macchina di Turing** (con la ’M’ maiuscola).



