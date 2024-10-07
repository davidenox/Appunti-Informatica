>[!important]- Processo Software:
> Serie di attività necessarie alla realizzazione del prodotto SW nei tempi, con i costi e con le desiderate caratteristiche di qualità. Nel suo contesto:
> 1. Si applicano metodi, tecniche e strumenti;
> 2. Si creano prodotti ( sia intermedi che finali );
> 3. Si stabilisce il controllo gestionale del progetto;
> 4. Si garantisce la qualità;
> 5. Si governano le modifiche.

# Fasi del processo

Un processo software segue un *ciclo di vita* che si articola in tre stadi:
- *Sviluppo*;
- *Manutenzione*;
- *Dismissione*.
Nel primo stadio si possono riconoscere due tipi di fasi:
1. La fase di tipo *Definizione*, in cui ci si occupa di "cosa" il software deve fornire. Si definiscono i requisiti e si producono le specifiche.
2. La fase di tipo *Produzione*, in cui si definisce "come" realizzare quanto ottenuto con le fasi di Definizione. Si progetta il software, si codifica, si integra e si rilascia al cliente.
Lo stadio di *Manutenzione* è a supporto del software realizzato e prevede fasi di definizione e/o produzione al suo interno.

Durante ogni fase si procede ad effettuare il **testing** di quanto prodotto, mediante opportune tecniche di *verifica* e *validazione* applicate sia ai prodotti intermedi che al prodotto finale.

## Tipi di Manutenzione

-  Manutenzione *correttiva*, che ha lo scopo di eliminare i difetti (`fault`) che producono guasti (`failure`) del software;
-  Manutenzione *adattativa*, che ha lo scopo di adattare il software ad eventuali cambiamenti a cui è sottoposto l'ambiente operativo per cui è stato sviluppato;
-  Manutenzione *perfettiva*, che ha lo scopo di estendere il software per accomodare funzionalità aggiuntive;
-  Manutenzione *preventiva* (o $\texttt{software reengineering}$), che consiste nell'effettuare modifiche che rendano più semplici le correzioni, gli adattamenti e le migliorie.

# Definizione di ciclo di vita

>[!important]- Def. IEEE Std 610-12 (Terminologia ISW)
>-  Intervallo di tempo che intercorre tra l’istante in cui nasce l’esigenza di costruire un prodotto software e l’istante in cui il prodotto viene dismesso. Include le fasi di definizione dei requisiti, specifica, pianificazione, progetto preliminare, progetto dettagliato, codifica, integrazione, testing, uso, manutenzione e dismissione.
>- Nota: tali fasi possono sovrapporsi o essere eseguite in modo iterativo.

## Modelli di ciclo di vita

Il **Modello del ciclo di vita** del software specifica la serie di fasi attraverso cui il prodotto SW progredisce e l'ordine con cui le stesse vanno eseguite, dalla definizione dei requisiti alla dismissione. La scelta del modello dipende da:
1. Natura dell'applicazione;
2. Maturità dell'organizzazione
3. Metodi e tecnologie usate;
4. Eventuali vincoli dettati dal cliente.
L'assenza di un modello del ciclo di vita corrisponde ad una modalità di sviluppo detta *build & fix* ( o *fix-it-later* ), in cui il prodotto SW viene sviluppato e successivamente rilavorato al fine di soddisfare le necessità del cliente.

![[Pasted image 20241004222440.png|center|500]]

![[Pasted image 20241004222503.png|center|500]]

![[Pasted image 20241004222530.png|center|500]]

![[Pasted image 20241004222547.png|center|500]]

# Prototipazione Software
	Sviluppo rapido del software per suscitare o convalidare requisiti
## Utilizzo dei prototipi di sistema

L'utilizzo principale è di aiutare i clienti e gli sviluppatori a capire i requisiti SW.
- *Elicitazione dei requisiti*: Gli utenti possono sperimentare con un prototipo per vedere come il sistema supporta il loro lavoro;
- *Validazione dei requisiti*: Il prototipo può rivelare errori ed omissioni nei requisiti.
La prototipazione può essere vista come un'attività di riduzione di rischi che reduce i rischi di requisiti.
## Benefici della prototipazione

-  Vengono alla luce le incomprensioni tra gli utenti del software e gli sviluppatori;
-  Potrebbero essere rilevati servizi mancanti e identificati servizi confusi;
-  Un sistema funzionante è disponibile nelle prime fasi del processo;
-  Il prototipo può servire come base per derivare una specifica software;
-  Il prototipo può supportare la formazione degli utenti e il test del prodotto.

## Processo di prototipazione

![[Pasted image 20241007110148.png|center|500]]

### Prototipi come specifiche

Alcune parti dei requisiti possono essere impossibili da prototipare, quindi non appaiono nei requisiti. Un'implementazione non costituisce una legittimazione ad agire come un contratto, ed i requisiti non-funzionali non possono essere "testati" adeguatamente in un prototipo SW.

### Prototipazione usa e getta

-  Un prototipo che di solito è un'implementazione pratica del prodotto viene prodotto per aiutare a scoprire i problemi relativi ai requisiti e poi scartato. Il prodotto viene quindi sviluppato utilizzando un altro processo di sviluppo;
-  Utilizzato per ridurre il rischio legato ai requisiti;
-  Il prototipo viene sviluppato a partire da un requisito iniziale, consegnato per la sperimentazione e poi scartato;
-  Il prototipo usa e getta NON deve essere considerato un prodotto finale:
	- Alcune caratteristiche potrebbero essere state tralasciate;
	- Non esistono specifiche per la manutenzione a lungo termine;
	- Il prodotto risulterà poco strutturato e di difficile manutenzione.

![[Pasted image 20241007110955.png|center|500]]
Gli sviluppatori potrebbero essere costretti a fornire un prototipo usa e getta come prodotto finale, ma questo non è raccomandato:
-  Potrebbe essere impossibile mettere a punto il prototipo per soddisfare requisiti non funzionali;
-  Il prototipo è inevitabilmente privo di documenti;
-  La struttura verrà degradata a causa delle modifiche apportate durante lo sviluppo;
-  Potrebbero non essere stati applicati i normali standard di qualità organizzativa.

### Punti chiave

-  Un prototipo può essere utilizzato per dare agli utenti finali un'impressione concreta delle capacità del prodotto;
-  La prototipazione viene sempre più utilizzata per lo sviluppo del prodotto dove lo sviluppo rapido è essenziale;
-  La prototipazione usa e getta viene utilizzata per comprendere i requisiti del prodotto;
-  Lo sviluppo rapido dei prototipi è essenziale. Ciò potrebbe richiedere l'esclusione di funzionalità o l'allentamento dei vincoli non funzionali;
-  La programmazione visiva è parte integrante della maggior parte dei metodi di sviluppo dei prototipi.
## Programmazione visiva

Linguaggi di scripting come Visual Basic supportano la programmazione visiva in cui il prototipo viene sviluppato creando un'interfaccia utente da elementi standard e associando componenti a questi elementi. Esiste un'ampia libreria di componenti per supportare questo tipo di sviluppo, e quest'ultimi possono essere personalizzati per soddisfare i requisiti applicativi specifici.

![[Pasted image 20241007115332.png|center|500]]

### Problemi con lo sviluppo visivo
- Difficoltà di coordinazione nei team di sviluppo;
- Architettura SW non esplicita;
- Dipendenze complesse tra porzioni di programma possono causare problemi di manutenzione.

# Iterazione del processo

I requisiti si evolvono **continuamente** nel corso di un progetto, quindi l'iterazione del processo in cui le fasi precedenti vengono rielaborate fa sempre parte del processo per i prodotti di grandi dimensioni. L'iterazione può essere applicata a qualsiasi modello di processo. Esistono due approcci correlati:
- *Sviluppo incrementale*;
- *Sviluppo a spirale*.

## Sviluppo incrementale

Nello **sviluppo incrementale** il prodotto viene sviluppato e distribuito in incrementi dopo aver stabilito un'architettura complessiva. Possono essere sviluppati requisiti e specifiche per ciascun incremento.
Gli utenti possono sperimentare gli incrementi forniti mentre altri vengono sviluppati. Pertanto, questi servono come una forma di prototipo. Questo approccio è destinato a combinare alcuni dei vantaggi della prototipazione ma con un processo più gestibile e una struttura migliore.

Il prodotto SW viene sviluppato e rilasciato per incrementi (`build`) successivi:
![[Pasted image 20241007120847.png|center|500]]

Questo modello include aspetti tipici del modello basato su *rapid prototyping* (l’utente può sperimentare l’utilizzo del prodotto contenente gli incrementi consegnati, mentre i restanti sono ancora in fase di sviluppo).
Si rivela efficace quando il cliente vuole continuamente verificare i progressi nello sviluppo del prodotto e quando i requisiti subiscono modifiche.

Può essere realizzato in due versioni alternative:
- versione *con* overall architecture;
- versione *senza* overall architecture (più rischiosa).

![[Pasted image 20241007121118.png|center|500]]

![[Pasted image 20241007121140.png|center|500]]

![[Pasted image 20241007121207.png|center|500]]

## Confronto con modello a cascata
### Modello a cascata

-  Requisiti “congelati” al termine della fase di specifica;
-  Feedback del cliente solo una volta terminato lo sviluppo;
-  Fasi condotte in rigida sequenza (l’output di una costituisce input per la successiva);
-  Prevede fasi di progetto dettagliato e codifica dell’intero prodotto;
-  Team di sviluppo costituito da un numero elevato di persone.

### Modello incrementale

-  Requisiti suddivisi in classi di priorità e facilmente modificabili;
-  Continuo feedback da parte del cliente durante lo sviluppo;
-  Fasi che possono essere condotte in parallelo;
-  Progetto dettagliato e codifica vengono effettuate sul singolo build;
-  Differenti team di sviluppo, ciascuno di piccole dimensioni.

## Modello a spirale

![[Pasted image 20241007121435.png|center|500]]

![[Pasted image 20241007121451.png|center|500]]

![[Pasted image 20241007121518.png|center|500]]

![[Pasted image 20241007121542.png|center|500]]

# Rischio di gestione

La gestione del rischio riguarda l'identificazione dei rischi e l'elaborazione di piani per ridurre al minimo il loro effetto su un progetto.

>[!danger]- Un rischio è la probabilità che si verifichino circostanze avverse

Categorie di rischio
- I rischi del progetto influiscono sulla pianificazione o sulle risorse;
- I rischi del prodotto influiscono sulla qualità o sulle prestazioni del software in fase di sviluppo;
- I rischi aziendali incidono sull’organizzazione che sviluppa o acquista il software.

## Categorie di rischio

![[Pasted image 20241007121844.png|center|500]]

## Il processo di gestione dei rischi
1. *Identificazione del rischio*: Identificazione del progetto, del prodotto e dei rischi d'impresa;
2. *Analisi del rischio*: Valutazione della probabilità e delle conseguenze del rischio;
3. *Pianificazione del rischio*: Ideazione di piani per eliminare o minimizzare gli effetti del rischio;
4. *Monitorazione del rischio*: Monitorazione del rischio attraverso il progetto.

![[Pasted image 20241007122327.png|center|500]]

### Identificazione dei rischi

- Rischi tecnologici;
- Rischi umani;
- Rischi organizzativi;
- Rischi strumentali;
- Rischi di requisiti;
- Rischi di stime.

![[Pasted image 20241007141200.png|center|500]]

### Analisi dei rischi

- Valutazione della **probabilità** e serietà di ogni rischio:
	- very low (<10%)
	- low (10-25%)
	- moderate (25-50%)
	- high (50-75%)
	- very high (>75%)
Gli *effetti* dei rischi possono essere *catastrofici*, *seri*, *tollerabili* o *insignificanti*.

![[Pasted image 20241007141411.png|center|500]]

### Pianificazione dei rischi

- Considerazione di ogni rischio e sviluppo di una strategia per gestire tali rischi;
- Strategie di evitamento ( probabilità che il rischio si presenti è ridotta);
- Minimizzazione delle strategie ( l'impatto del rischio sul progetto o prodotto viene ridotto);
- Piani di emergenza ( se il rischio si presenta, i piani di emergenza sono strategie per contrastare quel rischio).

![[Pasted image 20241007141718.png|center|500]]

### Monitorazione dei rischi

- Valutazione di ogni rischio identificato regolarmente per decidere quando diventa più o meno probabile;
- Per attuare la valutazione si valutano i *fattori di rischio*;
- Valutazione aggiuntiva che gli effetti del rischio siano cambiati;
- Qualsiasi rischio chiave dovrebbe essere discusso negli incontri di sviluppo.

![[Pasted image 20241007142129.png|center|500]]

# Altri modelli

- Modello *object-oriented*:
![[Pasted image 20241007142156.png|center|500]]

1. Modello di **ingegneria simultanea** (o *concorrente*):
	- ha come obiettivo la riduzione di tempi e costi di sviluppo, mediante un approccio sistematico al progetto integrato e concorrente di un prodotto software e del processo ad esso associato. 
	- Le fasi di sviluppo coesistono invece di essere eseguite in sequenza. 
2. Modello basato su **metodi formali**:
	- comprende una serie di attività che conducono alla specifica formale matematica del software, al fine di eliminare ambiguità, incompletezze ed inconsistenze e facilitare la verifica dei programmi mediante l'applicazione di tecniche matematiche. 
	- La *Cleanroom Software Engineering* (1987) ne rappresenta un esempio di realizzazione, in cui viene enfatizzata la possibilità di rilevare i difetti del software in modo più tempestivo rispetto ai modelli tradizionali.

# Il modello Microsoft
La Microsoft, come altre organizzazioni che sviluppano software commerciale, ha dovuto
affrontare, fin dalla metà degli anni 80, problemi di:
- *incremento della qualità* dei prodotti software
- *riduzione di tempi e costi* di sviluppo
Per cercare di risolvere tali problemi si è adottato un processo che è al tempo stesso *iterativo*, *incrementale* e *concorrente* e che permette di esaltare le doti di creatività delle persone coinvolte nello sviluppo di prodotti software.

## Approccio `synch-and-stabilize`

Tale approccio è basato su:
- **Sincronizzazione** quotidiana delle attività svolte dalle persone sia individualmente che in team, mediante assemblaggio dei componenti software sviluppati ( anche parzialmente ) in un prodotto (*daily build*) che viene testato e corretto;
- **Stabilizzazione** periodica del prodotto in incrementi (*milestone*) successivi durante l'avanzamento del progetto, piuttosto che un'unica volta alla fine.

## Ciclo di sviluppo a 3 fasi

1. *Pianificazione*: Definizione della visione del prodotto, specifiche e programmi;
2. *Sviluppo*: Sviluppo delle funzionalità in sottoprogetti, ognuno di essi sotto forma di incrementi rilasciati;
3. *Stabilizzazione*: Comprensione dei test interni ed esterni, prodotto finale, stabilizzazione e distribuzione.

### Pianificazione

![[Pasted image 20241007145222.png|center|500]]

### Sviluppo

![[Pasted image 20241007145245.png|center|500]]

### Stabilizzazione

![[Pasted image 20241007145331.png|center|500]]

## Strategie e principi

1. **Strategie per definire prodotto e processo**: "*considerare la creatività come elemento essenziale*". **Principi di realizzazione**:
	1. Dividere il processo in milestone;
	2. Definire una "product vision" e produrre una specifica funzionale che si evolverà durante il progetto;
	3. Selezionare le funzionalità e le relative priorità in base alle necessità utente;
	4. Definire un'architettura modulare per replicare nel progetto la struttura del prodotto;
	5. Assegnare task elementari e limitare le risorse.
2. **Strategia per lo sviluppo e la consegna dei prodotti**:"*lavorare in parallelo con frequenti sincronizzazioni*". **Principi di realizzazione**:
	1. Definire team paralleli ed utilizzare `daily build` per la sincronizzazione;
	2. Avere sempre un prodotto da consegnare, con versioni per ogni piattaforma e mercato;
	3. Usare lo stesso linguaggio di programmazione all'interno dello stesso sito di sviluppo;
	4. Testare continuamente il prodotto durante il suo sviluppo;
	5. Usare metriche per il supporto alle decisioni;

![[Pasted image 20241007152348.png|center|500]]

![[Pasted image 20241007152408.png|center|500]]

![[Pasted image 20241007152418.png|center|500]]

![[Pasted image 20241007152441.png|center|500]]

## Il modello Netscape

Anche alla Netscape si è adottato un modello di tipo `synchronize-and-stabilize`, con opportuni adattamenti allo sviluppo di applicazioni Internet (browser e prodotti server):
- **dimensione dello staff**:
	- In media 1 tester ogni 3 sviluppatori (ma stessa produttività di Microsoft nello sviluppo di prodotti comparabili, ad es. IE vs. Communicator)
- **processo**:
	- scarso effort di pianificazione (tranne che su prodotti server)
	- documentazione incompleta
	- scarso controllo sullo stato di avanzamento del progetto (lasciato all’esperienza e all’influenza dei project manager)
	- scarso controllo su attività di ispezione del codice (code review)
	- pochi dati storici per il supporto alle decisioni

## Processo di sviluppo Netscape

**Step 1**: *Requisiti del prodotto e proposta di progetto*
- *Advance Planning Meeting* (APM) ( riunione di pianificazione anticipata ) tenuta per scambiare idee (marketing, sviluppi, dirigenti).
- Visione del prodotto generata, inizialmente da ingegneri senior, ora principalmente da product manager.
- Alcuni progetti e codifica da parte di ingegneri per esplorare tecnologie alternative o idee di funzionalità.
- Documento sui requisiti del prodotto compilato dai product manager, con l'aiuto degli sviluppatori. 
- Revisione informale di questa specifica preliminare da parte degli ingegneri. 
- Specifiche funzionali avviate dagli ingegneri, talvolta con l'aiuto dei product manager.
- Pianificazione e piano di budget compilati dal marketing e dall'ingegneria e discussi in modo informale con i dirigenti
**Step 2**: *Prima rivisita esecutiva*
- I dirigenti esaminano il documento sui requisiti del prodotto, la pianificazione e la proposta di budget.
- Piano modificato secondo necessità;
**Step 3**: *Inizio della fase di sviluppo*

2.3S16