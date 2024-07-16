# Transazioni

**Transazione**: complesso di operazioni (di *lettura* e *scrittura*) che portano il DB da uno stato corretto ad un altro stato corretto.
Un sistema transazionale è in grado di eseguire transazioni per un certo numero di applicazioni concorrenti.
(In SQL è possibile definire una transazione mediante uno specifico comando `start`, non è invece necessario definire l’`end`  $\Rightarrow$ nel blocco va poi utilizzato almeno un comando tra il `commit work` (permette terminazione corretta) e il `rollback work` (permette di abortire la tranisizione) ).
## ACID

La transazione gode di 4 proprietà:
- **Atomicità**: le operazioni che costituiscono la transazione compongono un blocco unico che deve essere eseguito nella sua interezza (Il DB non può essere lasciato in uno stato intermedio). In caso di guasti o errori prima del termine della transazione, le azioni sui dati già svolte devono essere annullate (operazione detta `UNDO`) e poi successivamente ripetute (`REDO`). $\Rightarrow$Tali operazioni sono realizzate dal sistema di recovery (Ha il compito di riportare il DB in uno stato corretto in caso di guasti).
Se la transazione ha successo, le modifiche vengono riporate in modo permanente dal DBMS nella memoria fisica (stato corretto: stato in cui il DB non presenta modifiche dovute a transazioni incomplete).

>[!warning]- NOTA: 
>Mediante rollback work è la transazione che richiede l’annullamento delle operazioni per qualche motivo. Talvolta però, questa richiesta può essere inoltrata direttamente dal sistema che non riesce ad eseguire le operazioni.

-  **Consistenza**: la transazione rispetta i vincoli di integrità del DB. In questo modo si garantisce che lo stato di arrivo sia corretto.
- **Isolamento**: la transazione è isolata rispetto alle altre transazioni concorrenti.
- **Durabilità**: le transazioni che terminano con una operazione di commit vengono mantenute in memoria fisica in modo permanente.
## Lock e Concorrenza
Per garantire tali proprietà occorre effettuare controlli su *affidabilità* (per atomicità e durabilità), *concorrenza* (per isolamento) e sull’*esecuzione* delle operazioni  (consistenza), che vengono realizzati dal gestore delle transazioni.
Il controllo sull’affidabilità è realizzato mediante un particolare file detto `log` che al suo interno mantiene l’insieme delle operazioni svolte sul DB mediante transazioni. (All’interno del file troviamo anche **checkpoint**, che indicano quali sono i dati già riportati in memoria dal DBMS dopo operazioni di commit)

>[!warning]- NOTA:
>Le modifiche spesso vengono riportate prima sul log e solo dopo nella memoria secondaria contenente il DB. (modalità differita)

Il log è memorizzato all’interno della memoria stabile (memoria che non si può danneggiare, astrazione).
Per facilitare il recupero delle informazioni il DBMS mantiene in memoria stabile anche il dump del DB, ovvero una copia completa di riserva dei dati e delle informazioni.

### Gestione dei guasti

Le operazioni di risoluzione vengono svolte dal **recovery manager**.
- *Guasti “soft”*: errori di programma, crash di sistema, perdita di tensione. In questo caso si perde il contenuto della memoria principale, ma rimane preservato il contenuto della memoria secondaria (gestite tramite ripresa a caldo);
- *Guasti “hard”*: si perde anche il contenuto della memoria secondaria. Rimane perciò preservato solo il contenuto della memoria stabile (`log` e `dump`).
**Ripresa a caldo**: 4 fasi
- Individuazione ultimo *checkpoint* nel log
- Costruire insiemi `UNDO` (operazioni da disfare) e `REDO` (operazioni da rifare)
- Scandire il log a ritroso, cancellando tutte le operazioni inserite nell’insieme UNDO
- Avanzare nuovamente nel log implementando le operazioni dell’insieme REDO
**Ripresa a freddo**: i dati vengono ripristinati mediante il dump. A questo punto vengono effettuate di nuovo tutte le operazioni registrate nel log fino al momento del guasto seguendo lo schema di una ripresa a caldo.

### Concorrenza

I sistemi odierni devono essere in grado di governare centinaia di transazioni al secondo che possono essere eseguite anche nello stesso arco temporale.
Se la concorrenza non venisse gestita correttamente, potrebbero verificarsi gravi problematiche legate alla consistenza dei dati.
Consideriamo la seguente situazione: una transizione $T_1$ prova a modificare il valore di una certa variabile $X$, però, prima che questo venga trascritto in memoria fisica, viene schedulata una seconda transizione $T_2$ che legge $X$ e la modifica. In questo caso il risultato della transizione $T_1$ viene perso, perché $T_2$ leggerà il valore iniziale di $X$ e sarà questo ad essere modificato. 
Un’altra situazione critica è quando la transizione $T_1$ prova a leggere due volte il valore di una certa $X$. Se tra queste due operazioni viene schedulata una $T_2$ che modifica $X$, $T_1$ leggerà per $X$ due valori distinti senza averla modificata.

Si possono infine generale anche altre anomalie come gli inserimenti fantasma ($T_1$ legge stipendi impiegati, poi viene schedulata $T_2$ che inserisce un nuovo impiegato. $T_1$ a questo punto viene caricata di nuovo in CPU per essere completata e calcola la media degli stipendi $\Rightarrow$ non teniamo conto di inserimento fatto da $T_2$).
Il gestore delle transizioni si affida per risolvere tali problematiche a specifici *scheduler*, come quelli seriali. In questo caso le operazioni delle transizioni vengono eseguite una alla volta in maniera successiva. (Una volta terminata $T_1$ si passa poi a $T_2$) $\Rightarrow$ se $T$ presenta un elevato numero di operazioni, avremo occupazione non efficiente della CPU.
Gli scheduler, in generale, possono provocare le problematiche precedentemente citate. Una parte di essi, però, produrrà il risultato corretto, in questo caso sono detti serializzabili (ovvero producono sul DB gli stessi effetti di uno scheduler seriale). Abbiamo bisogno di un metodo per stabilire tale equivalenza. (Nella seguente trattazione supponiamo di dover gestire solo transazioni andate in commit)

## Scheduler View-Serializzabili (VSR)
Relazione “`legge da`”: dato un’ordinamento di scheduler S, si dice che una operazione di lettura $𝑟𝑖 (x)$`LEGGE_DA` un’operazione di scrittura $𝑤𝑗 (x)$ se $𝑤𝑗 (x)$ *precede* $𝑟𝑖 (x)$ in S e non sono presenti altre $𝑤𝑘 (x)$ tra le due operazioni citate.
**Scrittura finale**: $𝑤𝑖 (x)$ è scrittura finale, se è l’ultima operazione di scrittura su $x$ che appare in S. Due scheduler sono *view-equivalenti* se hanno la stessa relazione “`legge da`” e le stesse scritture finali.
Uno scheduler è **view-serializzabile** se è *view-equivalente* ad uno scheduler seriale.
***PROBLEMA***: stabilire view-serializzabilità di uno scheduler è un problema NP-completo.

## Scheduler Conflict-Serializzabili

In uno scheduler S due azioni distinte $𝑎_𝑖$ ed $𝑎_𝑗$ sono in conflitto tra loro se operano sullo stesso oggetto $x$ ed almeno una è di **write**.
Due scheduler si dicono **conflict-equivalenti** se contengono le *stesse operazioni* ed i conflitti appaiono nello stesso ordine.
Uno scheduler è **conflict-serializzabile** se è *conflict-equivalente* ad uno scheduler seriale.
Per verificare la *conflict-serializzabilità* basta utilizzare un algoritmo su grafi $(grafo \Rightarrow (nodo = transazione)$, (arco orientato da $T_i$ a $T_j$ se c’è almeno un conflitto tra una azione $𝑎_𝑖$ ed una $𝑎_𝑗$ ) ). Se il grafo ottenuto in questo modo è *aciclico*, lo scheduler è **conflict-serializzabile**. 

(Se S è conflict-serializzabile esiste uno scheduler $S’$ seriale che presenta operazioni in conflitto nello stesso ordine di S. Poiché S’ avrà un ordinemento delle transizioni del tipo $T_1, T_2, …, T_n$, il grafo associato ad S non presenterà cicli). 
Nonostante una diminuzione a livello di costi computazionali, il modello basato su **conflict-serializzabilità** funziona *solo* nel caso in cui *tutte le transazioni terminano con una commit e non risulta quindi implementabile in realtà*. Come si procede allora?

Nei DBMS moderni vengono utilizzati protocolli di **locking** sulle transazioni.
**MECCANISMO**: i lock non sono nient’altro che *variabili* associate a singoli oggetti in memoria del DB che descrivono lo stato dell’oggetto stessto rispetto alle operazioni che possono essere effettuate su di esso. 
*Una transazione richiede un lock mediante una operazione di locking, e lo rilascia mediante una unlocking.*
In questo modo implementiamo un meccanismo di mutua esclusione sulle informazioni mantenute in memoria. (Se una transizione prova a richiedere il lock di un certo oggetto, ma questo non risulta disponibile, la transizione rimarrà in attesa finchè questo non viene rilasciato $\Rightarrow$ il tutto è gestito mediante un’apposita tabella dei conflitti).

I protocolli di locking più utilizzati nei sistemi moderni sono:
- **Locking a due fasi**: una transazione non può acquisire più di una volta il lock di un dato oggetto
- Una sua variante, **locking a due fasi stretto**: i lock possono essere rilasciati da una transazione solo dopo una `commit/abort`. (Garantiamo isolamento completo delle transizioni, anche in caso di abort)

Nei sistemi basati su lock possono però verificarsi due **problematiche** fondamentali, che vanno risolte:
- *Livelock*: transazione può rimanere in attesa di un lock per un tempo indefinito. Possiamo risolvere utilizzando coda di priorità dove la priorità assegnata ad ogni transizione coincide con l’istante di richiesta del lock (in questo modo ogni transizione ad un certo avrà priorità massima per ottenere il lock)
- *Deadlock*: si ha quando due transizioni detengono ciascuna una risorsa e aspettano quella detenuta dll’altra. Si può risolvere facendo abortire le transazioni.

# Normalizzazione

Le forme normali nelle basi di dati (o normalizzazione dei database) sono una serie di linee guida progettate per organizzare i dati in una base di dati relazionale per minimizzare la ridondanza e migliorare l'integrità dei dati. La normalizzazione comporta la suddivisione delle tabelle grandi in tabelle più piccole e il collegamento tra di esse attraverso relazioni ben definite. Ecco una panoramica delle forme normali principali:

## Prima Forma Normale (1NF)

**Requisiti:**
- Ogni colonna contiene solo valori atomici (indivisibili).
- Ogni colonna contiene solo valori di un singolo tipo.
- Ogni riga è unica e identificata da una chiave primaria.
**Obiettivo:** Eliminare i gruppi ripetuti all'interno di una tabella.
**Esempio:**

| ID  | Nome | Telefono         |
| --- | ---- | ---------------- |
| 1   | Anna | 123-456, 789-012 |
| 2   | Bob  | 345-678          |

Dopo la normalizzazione in 1NF:

|ID|Nome|Telefono|
|---|---|---|
|1|Anna|123-456|
|1|Anna|789-012|
|2|Bob|345-678|

## Seconda Forma Normale (2NF)

**Requisiti:**
- Deve essere già in 1NF.
- Tutte le colonne non chiave devono dipendere interamente dalla chiave primaria.
**Obiettivo:** Eliminare la dipendenza parziale delle colonne non chiave dalla chiave primaria.
**Esempio:** Supponiamo una tabella che contiene informazioni sui corsi e sugli studenti iscritti.

|StudenteID|CorsoID|NomeStudente|NomeCorso|
|---|---|---|---|
|1|101|Anna|Matematica|
|2|102|Bob|Fisica|

Dopo la normalizzazione in 2NF:

*Tavola Studenti:*

|StudenteID|NomeStudente|
|---|---|
|1|Anna|
|2|Bob|

*Tavola Corsi:*

|CorsoID|NomeCorso|
|---|---|
|101|Matematica|
|102|Fisica|

*Tavola Iscrizioni:*

|StudenteID|CorsoID|
|---|---|
|1|101|
|2|102|

## Terza Forma Normale (3NF)

**Requisiti:**
- Deve essere già in 2NF.
- Tutte le colonne non chiave devono essere indipendenti tra loro (nessuna dipendenza transitiva).
**Obiettivo:** Eliminare la dipendenza transitiva delle colonne non chiave dalla chiave primaria.
**Esempio:** Supponiamo una tabella con informazioni sugli studenti e sulle città in cui vivono:

|StudenteID|NomeStudente|Città|Stato|
|---|---|---|---|
|1|Anna|Milano|Lombardia|
|2|Bob|Roma|Lazio|

Dopo la normalizzazione in 3NF:

*Tavola Studenti:*

|StudenteID|NomeStudente|CittàID|
|---|---|---|
|1|Anna|1|
|2|Bob|2|

*Tavola Città:*

|CittàID|Città|Stato|
|---|---|---|
|1|Milano|Lombardia|
|2|Roma|Lazio|

## Forma Normale di Boyce-Codd (BCNF)

**Requisiti:**
- Deve essere già in 3NF.
- Per ogni dipendenza funzionale non banale A→BA \rightarrow BA→B, A deve essere una superchiave.
**Obiettivo:** Gestire alcuni tipi di anomalie che non vengono risolte dalla 3NF.

# Dipendenze funzionali

Le dipendenze funzionali sono un concetto chiave nella teoria delle basi di dati relazionali, utilizzato per esprimere le relazioni tra attributi in una tabella. Comprendere le dipendenze funzionali è essenziale per la normalizzazione del database e per garantire l'integrità dei dati. Ecco una spiegazione dettagliata delle dipendenze funzionali:

### Definizione di Dipendenza Funzionale

Una dipendenza funzionale tra due insiemi di attributi di una relazione è una relazione in cui un insieme di attributi determina un altro insieme di attributi. Formalmente, si dice che un insieme di attributi XXX determina un insieme di attributi YYY (notato come X→YX \rightarrow YX→Y) se, per ogni coppia di tuple in una relazione, se le tuple concordano su tutti gli attributi di XXX, allora devono concordare anche su tutti gli attributi di YYY.

### Esempio di Dipendenza Funzionale

Consideriamo una tabella di studenti con le seguenti colonne:

|Matricola|Nome|Corso|Professore|
|---|---|---|---|
|1|Anna|Matematica|Rossi|
|2|Bob|Fisica|Bianchi|
|3|Carla|Matematica|Rossi|

In questo esempio:

- Matricola→Nome\text{Matricola} \rightarrow \text{Nome}Matricola→Nome significa che ogni matricola identifica univocamente il nome di uno studente.
- Corso→Professore\text{Corso} \rightarrow \text{Professore}Corso→Professore significa che ogni corso è tenuto da un unico professore.

### Tipi di Dipendenze Funzionali

#### Dipendenza Funzionale Completa

Una dipendenza funzionale X→YX \rightarrow YX→Y è completa se la rimozione di qualsiasi attributo da XXX fa sì che la dipendenza non sia più valida. In altre parole, tutti gli attributi di XXX sono necessari per determinare YYY.

**Esempio:**

| (Matricola, Corso) $\rightarrow$ Voto |     |
| ------------------------------------- | --- |
| 1, Matematica $\rightarrow$ 30        |     |
| 2, Fisica $\rightarrow$ 28            |     |

In questo caso, solo conoscendo sia la matricola che il corso possiamo determinare univocamente il voto di uno studente in quel corso.

#### Dipendenza Funzionale Parziale

Una dipendenza funzionale X→YX \rightarrow YX→Y è parziale se esiste un sottoinsieme proprio di XXX che determina ancora YYY.

**Esempio:**

| (Matricola, Nome) $\rightarrow$ Corso |     |
| ------------------------------------- | --- |
| 1, Anna $\rightarrow$ Matematica      |     |
| 2, Bob $\rightarrow$ Fisica           |     |

Qui, la dipendenza è parziale perché il nome da solo può determinare il corso.

#### Dipendenza Transitiva

Una dipendenza funzionale X→ZX \rightarrow ZX→Z è transitiva se esistono attributi YYY tali che X→YX \rightarrow YX→Y e Y→ZY \rightarrow ZY→Z.

**Esempio:** 

| Matricola $\rightarrow$ Corso | 

| Corso $\rightarrow$ Professore |     |
| ------------------------------ | --- |
| 1 $\rightarrow$ Matematica     |     |
| Matematica $\rightarrow$ Rossi |     |

In questo caso, Matricola→Corso→ProfessoreMatricola $\rightarrow$Corso $\rightarrow$ ProfessoreMatricola→Corso→Professore rappresenta una dipendenza transitiva.

### Importanza delle Dipendenze Funzionali

Le dipendenze funzionali sono utilizzate per:

1. **Normalizzazione:** Aiutano a identificare le anomalie di aggiornamento e a eliminare le ridondanze nei dati.
2. **Progettazione del Database:** Garantiscono che la struttura del database sia ottimale per mantenere l'integrità e l'efficienza dei dati.
3. **Integrità dei Dati:** Assicurano che le relazioni tra i dati siano mantenute correttamente, prevenendo inconsistenze.

### Verifica delle Dipendenze Funzionali

Per verificare se una dipendenza funzionale X→YX \rightarrow YX→Y è valida in una relazione, si esaminano tutte le tuple della relazione per vedere se per ogni coppia di tuple, se le tuple hanno gli stessi valori per XXX, allora devono avere gli stessi valori per YYY.

In conclusione, le dipendenze funzionali sono fondamentali per capire come gli attributi di una base di dati sono correlati tra loro e per garantire che i dati siano organizzati in modo da ridurre le ridondanze e mantenere l'integrità.