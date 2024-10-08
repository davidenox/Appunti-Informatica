# Data Mining: Modelli ed Algoritmi

>[!important]- Obiettivo strategico ( Goal )
>Trovare:
>- Il miglior Hardware,
>- I migliori **Modelli**,
>- I migliori **Algoritmi**,
>- I migliori Software
>Per risolvere problemi su *Input Data Set* ( Insieme di dati rozzi ) **complessi** e/o di **larghe dimensioni**.


## Modelli per Data Set Larghi/Complessi

**Fase 1**: Trasformare l'*input Data Set* reale in un **modello/struttura** $\texttt{I}$ in modo che il problema reale si *riduca* in una **Task computazionale ben definita** $\texttt{T}$ sull'input $\texttt{I}$.
**Fase 2**: Trovare il miglior algoritmo per risolvere $\texttt{Tp}$ su input $\texttt{I}$.

Scenario tipico nel Data Mining:
- La **Fase 1** è spesso la parte difficile;
- Una volta risolta la *Fase 1*, la **Fase 2** richiede metodi standard.

### Problema reale di Data-Mining: Email di Phishing

*Soluzione algoritmica*:
1. Classificare le mail ricevute in due sottogruppi: **Phishing**/*Non-Phishing*;
2. Estrarre queste *parole di phishing* ( o frasi ) che appaiono insolitamente spesso in **Phishing**, per creare una lista di parole chiave (es. "send money");
3. Assegnare *pesi positivi* alle **parole di phishing** e *pesi negativi* agli altri;
4. *Algoritmo*: Per ogni mail in arrivo, computare la somma dei pesi delle parole. Se questa somma è più grande di una soglia data, allora invia la mail in **Phishing**, altrimenti inviala in *Non-Phishing*.

#### KeyTask in Data Mining

2. Definire un *modello statistico adeguato* $\texttt{M}$ (es. una *Distribuzione Probabilistica*) sul vero (rozzo) input dei dati (email) in modo che le informazioni nascoste che si cercano emergono come eventi probabili in  $\texttt{M}$.
3. Assegnare i giusti pesi alle parole, in modo che la somma totale della mail in arrivo sia *proporzionale* alla probabilità di Phishing

## Modellazione Statistica: Informale

- Costruire una *distribuzione di probabilità* sottostante da cui vengono **campionati** i dati grezzi visibili.
Esempio: L'*insieme di dati grezzi* ( `raw data set` ) è un insieme $\texttt{D}$ di numeri. Un *modello statistico*/*ipotesi* per $\texttt{D}$ esiste per assumere che i numeri siano campionati secondo la *Distribuzione Gaussiana* su $\texttt{D}$. Quindi, la *media* e la *deviazione standard* caratterizzano completamente questa distribuzione e diventerebbero il **Modello** dei *Dati di Input* ( `input data` ).

### Modelli di dati contraddittori: Informale

Altri scenari tipici del *Data Mining* adottano l'ipotesi del **caso peggiore**:
- Il *Data Set di input*, da cui estrarre le informazioni target, è gestito da una *fonte avversaria* che genera i dati con l'obiettivo di minimizzare l'efficienza della soluzione algoritmica o, peggio ancora, la sua validità.
Esempio: calcolo (e aggiornamento) del **numero** di $1$ nell'ultima finestra di lunghezza $\texttt{N}$ su un flusso infinito di bit governato da un avversario che sceglie il bit successivo in funzione delle scelte dell'algoritmo precedente.

## Data Mining e Machine Learning
Il **Machine Learning** (***ML***) è un possibile, spesso potente, approccio per il Data Mining.

>[!info]- Approccio ML:
>Utilizzare parte dell'Insieme di Dati di input come un *Training Set*, per allenare il sistema di ML

Domanda generale: Quando l'approccio ML funziona bene?

*Risposta informale*: ML diventa un buon approccio in situazioni in cui non è possibile definire una *funzione obiettivo pulita* nel Data Set

### Approcci ML: situazioni favorevoli

Valutazioni dei film (il **problema Netflix**): *prevedere la valutazione dei film da parte degli utenti*.
- *Compiti difficili*: selezionare le caratteristiche di un film che lo fanno piacere o meno a un utente; Formalizzarli e fornire un efficiente sistema di controllo.
- L'approccio *ML* propone algoritmi efficienti che prendono campioni delle *valutazioni degli utenti* e fanno previsioni con un buon livello di approssimazione.
* Non è chiaro quali caratteristiche di un film giochino qui un ruolo cruciale e come formalizzarle.

### Approcci ML: Situazioni sfavorevoli

Il ML spesso non è competitivo quando la funzione obiettivo è chiara e ben definita nel set di dati.
- Esempio: Localizzare i *CV* delle persone sul *WEB*: le caratteristiche di una pagina CV possono essere ben definite rilevando la presenza di *parole tipiche*.
- Trovare **triangoli** nei social network: esistono algoritmi locali efficienti per questo compito che lavorano su grafici grandi e/o dinamici.
Un'altra questione del machine learning: la **trasparenza**.

## Limiti statistici del Data Mining

Il tipico obiettivo nei problemi di Data Mining è scoprire eventi *inusuali* nascosti in enormi Data Set.

>[!cite]- Utilizzo del Data Mining - Principio di Bonferroni
>“Se il set di dati (o il processo di dati) raccoglie un gran numero di elementi da diverse fonti in modo sufficientemente *casuale*, allora gli eventi *insoliti* potrebbero non avere significati particolari: sono solo artefatti statistici che potrebbero verificarsi”

### Principio di Bonferroni

Supponiamo di osservare uno specifico evento con input DataSet $\texttt{DS}$. Dunque...

>[!info]- Puoi aspettarti che si verifichi un **evento**, anche se $\texttt{S}$ è completamente casuale, e il numero di occorrenze di eventi **aumenterà all'aumentare della dimensione di** $\texttt{DS}$.

Questi eventi sono “**falsi**”: non hanno altra causa se non il fatto che i *dati* casuali avranno sempre un certo numero di caratteristiche insolite che sembrano significative ma non lo sono.
Un teorema fondamentale della *statistica*, noto come **correzione di Bonferroni**, fornisce un modo statisticamente valido per evitare la maggior parte di queste risposte false-positive a una ricerca tra i dati.

#### Esempi di "bogus": Gang nei Social Network

13/24 arrivare a 16