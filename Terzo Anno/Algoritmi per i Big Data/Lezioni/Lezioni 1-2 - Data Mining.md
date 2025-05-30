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

**Estrazione di informazioni da un social network**

Il *modello grafico* (versione semplificata) $G(V,E)$: un (ampio) insieme $\texttt{V}$ di $n$ agenti (potenzialmente criminali) che visitano un (ampio) insieme $\texttt{H}$ di $h$ luoghi pubblici (hotel, bar, ristoranti, aeroporti, ecc.) in una grande città/regione:
- Esiste un arco $(u,v)$ se $u$ e $v$ visitano la stessa posizione in $\texttt{H}$ nello stesso giorno in una sequenza di $T >> 0$ giorni;
- **Ipotesi del modello** (versione semplificata): il processo di visita degli agenti nei luoghi pubblici (hotel, bar, aeroporto, banche, ecc.) è sufficientemente *casuale* e *uniforme*.

- *Problema* (informale): individuare possibili «**Gang**», ovvero *Clique* in $G$.

**Impostazione formale**

*Domanda*: Quale dimensione massima della clique ci aspettiamo in $G(V,E)$?

*Risposta*: Per ogni coppia di agenti $(u,v)$, otteniamo $Pr[(u,v)\in E]\simeq T/h ≜ p$
Per un sottoinsieme S ⊆ V di dimensione s, otteniamo:
$Pr[\text{S è una cricca}]\simeq p^{(s^2/2)}$,
Quindi:
$H =$ size of location set;
$T =$ number of days;
Hyp: $H >> T$

![[Pasted image 20241009142250.png|center]]

Ora, osservando un grande sistema spazio-temporale, ad es. $n\simeq 10^7, h \simeq 10^4; T \simeq 10^3 \implies p \simeq 1/10$, 
Da $(*)$, possiamo aspettarci un gran numero di cliques di dimensioni $s\simeq 10$
Quindi, una Gang di 10 ragazzi che si sono incontrati almeno una volta non è un evento sorprendente!

## Uno sguardo computazionale per il Data Mining

L'*approccio informatico* al Data Mining è di tipo **algoritmico**:
- Dato un DataSet $\texttt{DS}$, trovare un *algoritmo efficiente* ( e relativa struttura dati ) per risolvere query complesse su $\texttt{DS}$.
**Esempio**: 
Dato un flusso infinito $\texttt{DS}$ di interi, mantieni il *valore medio* di $\texttt{DS}$ (visto finora) e la sua *deviazione standard* (o il suo numero sorprendente)
**Osservazione**: 
L'algoritmo *non dovrebbe basarsi* su alcuna ipotesi statistica $\texttt{I}$ su $\texttt{DS}$ ma se $\texttt{I}$ è valida, i valori calcolati saranno coerenti con $\texttt{I}$.

### Task tipiche

1. **Modellazione computazionale** dei *processi di dati* (input) (ad esempio streaming)
2. **Riepilogo** di un *DataSet*
3. **Estrazione** delle *caratteristiche più importanti* del set di dati e scarto del resto.

### Flussi di dati

In molte situazioni di *Data Mining*, non conosciamo nello specifico l'intero DataSet.
La **gestione del flusso** è importante quando il tasso di input è controllato *esternamente*:
- Query dei motori di ricerca;
- Aggiornamenti di stato di Twitter o Facebook;
- Indirizzi IP gestiti dai server;
- ecc.
Possiamo pensare al *DataSet* come **infinito** e **non stazionario**(la *distribuzione* cambia nel tempo).

## Il modello del DataStream

Gli *elementi* di input entrano a una *velocità elevata*, in una o più porte di input (ad esempio, Stream):
	- ad esempio *elementi* degli $Stream\equiv tuple$
Il sistema non può memorizzare l'intero Stream $S$ in modo accessibile, solo brevi *schizzi* di $S$ possono essere mantenuti e aggiornati.

**Domanda**: Come si risponde a *query critiche* su $S$ utilizzando una *quantità di memoria limitata*?

![[Pasted image 20241015120106.png|center|500]]

### Problemi del DataStream

Tipi di *query* su un flusso di dati (**DS**):
-  **Campionamento** dei dati da un *DS*: creazione di un campione casuale;
-  **Filtraggio** di un DS: selezione di elementi con proprietà x;
-  **Conteggio** di elementi *distinti* in DS: numero di elementi distinti negli ultimi k elementi del DS;
-  **Stima dei momenti**: stima della media e della deviazione standard degli ultimi k elementi in DS
-  **Individuazione** dei k elementi più frequenti finora visti in DS

#### Riepilogo

**Query algoritmica**: dato un ampio set di dati *DS*, fornire un breve schizzo $H(S)$ che riassuma efficacemente le caratteristiche principali di *DS*
**Sfide di ottimizzazione**:
-  Ridurre al minimo la dimensione $|H(S)|$ (dovrebbe essere asintoticamente molto più piccola di $|DS|$);
-  $H(S)$ deve approssimare efficacemente le caratteristiche principali di DS
-  $H(S)$ deve consentire un aggiornamento dinamico efficiente (struttura dati dinamica)
Esempio pratico: Page Rank

#### Estrazione

L'**estrazione** di caratteristiche da enormi *DataSet* spesso si basa sulla selezione delle *dipendenze statistiche (correlazioni) più forti* tra gli ***elementi*** e sull'utilizzo solo di queste *dipendenze* per rappresentare l'intero DataSet.