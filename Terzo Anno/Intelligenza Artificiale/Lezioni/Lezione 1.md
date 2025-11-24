# Agenti ed ambienti

>[!important] Per **agente** si intende una qualsiasi cosa intendibile come un sistema che percepisce il suo **ambiente** attraverso dei *sensori* ed agisce su di esso mediante *attuatori*.

Per **percezione** si indicano i dati che i sensori di un agente percepiscono; la **sequenza percettiva** di un agente è la storia completa di tutto ciò che esso ha percepito nella sua esistenza.

In generale, *la scelta dell'azione di un agente in un qualsiasi istante può dipendere dalla conoscenza integrata in esso e dall'intera sequenza percettiva osservata fino a quel momento, ma non da qualcosa che l'agente non abbia percepito*.
In termini matematici, il comportamento di un agente è descritto dalla **funzione agente**, che descrive la corrispondenza tra una qualsiasi sequenza percettiva ed una specifica azione. La funzione agente è astratta, e viene implementata concretamente da un **programma agente**.

# Razionalità 

Per **agente razionale** si intende un agente che "fa la cosa giusta"; Quando un agente viene inserito in un ambiente, genera una sequenza di azioni in base alle percezioni che riceve. Questa sequenza porta l'ambiente ad attraversare una *sequenza di stati*: se tale sequenza è  desiderabile, allora l'agente ha "fatto la cosa giusta". Questa nozione di desiderabilità è catturata da una **misura di prestazione** che valuta una sequenza di stati dell'ambiente.

In generale, però, *è meglio progettare le misure di prestazione in base all'effetto che si desidera ottenere sull'ambiente, piuttosto che su come si pensa che debba comportarsi l'agente*.

In un dato momento ciò che è razionale dipende da quattro fattori:

- La **misura di prestazione**, che definisce il concetto di successo;
- La **conoscenza pregressa** dell'ambiente da parte dell'agente;
- Le **azioni** che l'agente può effettuare;
- La **sequenza percettiva** dell'agente fino all'istante corrente.

Questo porta alla seg. definizione:

>[!important] Per ogni possibile sequenza di percezioni, un agente razionale dovrebbe scegliere un'azione che massimizzi il valore atteso della sua misura di prestazione, date le informazioni fornite dalla sequenza percettiva e da ogni ulteriore conoscenza dell'agente.

Nel caso in cui la "geografia" di un ambiente fosse sconosciuta all'agente, quest'ultimo dovrebbe **esplorarlo**.

Razionalità ed *onniscenza* sono due concetti differenti: 
- Un agente onniscente conosce il risultato *effettivo* delle sue azioni e può agire di conseguenza, *ma nella realtà l'onniscenza è impossibile*.
- La razionalità non è perfezione, essa *massimizza il risultato atteso*, e non quello reale.

Intraprendere *azioni mirate a modificare le percezioni future* - **Information Gathering** - è una parte importante della razionalità, come ad esempio l'esplorazione. Un agente razionale non deve limitarsi alla sola raccolta delle informazioni, ma deve essere anche in grado di **apprendere** il più possibile dalle sue percezioni.
Quando un agente si appoggia alla conoscenza pregressa fornita dal progettista invece che dalle proprie percezioni ed ai suoi processi di apprendimento, diciamo che **manca di autonomia**.

È ragionevole fornire ad un agente AI, oltre all'abilità di apprendere, anche un po' di conoscenza iniziale. Dopo aver accumulato abbastanza esperienza in un dato ambiente, il comportamento dell'agente può diventare *indipendente* dalla conoscenza pregressa.

Bisogna anche considerare gli **ambienti operativi**, che sono essenzialmente i *problemi* a cui gli agenti razionali rappresentano le *soluzioni*. Parlando di agenti, è necessario specificarne la misura di prestazione, l'ambiente esterno, gli attuatori ed i sensori. Tutto ciò può essere racchiuso nel termine "*ambiente operativo*" oppure **PEAS** (Performance, Environment, Actuators, Sensors).

Quando si progetta un agente, il primo passo deve sempre corrispondere alla specifica dell'ambiente operativo, la più ricca possibile:
![[Pasted image 20251124123317.png|center|500]]![[Pasted image 20251124123338.png|center|500]]
## Proprietà degli ambienti lavorativi

- **Completamente/Parzialmente osservabile**:
	Se i sensori di un agente danno accesso allo stato completo dell'ambiente in ogni momento, si dice che l'ambiente lavorativo è *completamente osservabile*. Mentre, un ambiente è *parzialmente osservabile* a causa di sensori inaccurati, o per la presenza di disturbi, oppure perché una parte dei dati non viene rilevata dai sensori. Se l'agente *non dispone* di sensori, allora l'ambiente lavorativo è **inosservabile**.
- **Agente Singolo/Multiagente**:
	La distinzione chiave tra ambienti ad agente singolo e a multiagente è se si può descrivere il comportamento dell'agente B come il tentativo di massimizzare una misura di prestazione il cui valore dipende dal comportamento dell'agente A. Per esempio, negli scacchi l’avversario B sta cercando di massimizzare una misura di prestazione che, per le regole degli scacchi, minimizza quella dell’agente A. Gli *scacchi*, quindi, sono un *ambiente multiagente competitivo*. Nell’ambiente dei *taxi*, al contrario, evitare gli incidenti massimizza la misura di prestazioni di tutti gli agenti, per cui possiamo dire che quello è un *ambiente multiagente parzialmente cooperativo*. È *anche parzialmente competitivo* perché, tra le altre cose, una sola macchina per volta può occupare un parcheggio libero. I problemi di progettazione che sorgono negli ambienti multiagente sono spesso molto differenti da quelli ad agente singolo.
- **Determinismo/ non determinismo**: 
	Se lo stato successivo dell’ambiente è *completamente determinato* dallo stato corrente e dall’azione eseguita dall’agente (o dagli agenti), allora si può dire che l’ambiente è *deterministico*; in caso *contrario* si dice che è *non deterministico*. Se l’ambiente è solo parzialmente osservabile potrebbe sembrare non deterministico e nella pratica è così. Un’ultima nota: alcuni utilizzano il termine **stocastico** come sinonimo di “non deterministico”, ma diciamo che un modello dell’ambiente è stocastico se è esplicitamente associato a probabilità (per esempio “c’è una probabilità del 25% che domani piova”) e “non deterministico” se le varie possibilità sono elencate senza essere quantificate (per esempio “c’è la possibilità che domani piova”).
- **Episodico/sequenziale**: 
	 In un ambiente operativo episodico,*l’esperienza dell’agente è divisa in episodi atomici*. In ogni episodio l’agente riceve una percezione e poi esegue una singola azione. L’aspetto fondamentale è che un episodio non dipende dalle azioni intraprese in quelli precedenti. Negli ambienti sequenziali, al contrario, ogni decisione può influenzare tutte quelle successive. Gli ambienti episodici sono molto più semplici di quelli sequenziali, perché l’agente non deve “pensare avanti”.
- **Statico/dinamico**:
	 Se l’ambiente può *cambiare* mentre un agente sta decidendo come agire, allora diciamo che è *dinamico* per quell’agente; in caso *contrario* diciamo che è *statico*. Gli ambienti statici sono più facili da trattare perché l’agente non deve continuamente osservare il mondo mentre decide l’azione successiva e non si deve preoccupare del passaggio del tempo. Gli ambienti dinamici, invece, chiedono continuamente all’agente quello che vuole fare; se questo non risponde in tempo, è come se avesse deciso di non fare nulla. Se l’ambiente stesso non cambia al passare del tempo, ma la valutazione della prestazione dell’agente sì, allora diciamo che l’ambiente è **semidinamico**.
- **Discreto/continuo**: 
	 La distinzione tra discreto e continuo si applica allo *stato dell’ambiente*, al modo in cui è gestito il tempo, alle percezioni e azioni dell’agente. Per esempio, la scacchiera ha un numero finito di stati distinti (se si esclude il tempo). Gli scacchi hanno anche un insieme discreto di percezioni e azioni. La guida di un taxi è un problema con stato e tempo continui: la velocità e la posizione del taxi e degli altri veicoli cambiano con continuità al passare del tempo. In questo caso sono continue anche le azioni (pensiamo per esempio all’angolo di sterzo delle ruote).
- **Noto/ignoto**: 
	In termini rigorosi, *questa distinzione non si riferisce all’ambiente in sé, ma allo stato di conoscenza dell’agente (o del progettista) circa le “leggi fisiche” dell’ambiente stesso*. In un ambiente **noto**, sono *conosciuti i risultati* (o le corrispondenti probabilità, se l’ambiente è stocastico) *per tutte le azioni*. Ovviamente, se l’ambiente è ignoto, l’agente dovrà apprendere come funziona per poter prendere buone decisioni. La distinzione tra ambienti noti e ignoti non è identica a quella tra ambienti completamente osservabili e parzialmente osservabili: è infatti possibile che un ambiente noto sia parzialmente osservabile; per esempio, nei giochi a carte di solitario, il giocatore conosce le regola ma non può vedere le carte che non sono ancora state girate. Viceversa, un ambiente ignoto può essere completamente osservabile: in un nuovo videogioco, lo schermo potrebbe mostrare l’intero stato del gioco, ma il giocatore non conosce l’effetto dei pulsanti finché non li prova. In altri casi, l’agente può apprendere di più sulla misura di prestazione basandosi su ulteriori interazioni con il progettista o l’utente. Questo, a sua volta, indica che l’ambiente operativo è necessariamente visto come ambiente multiagente.

Il caso più difficile è:
- Parzialmente osservabile;
- Multiagente;
- Non deterministico;
- Sequenziale;
- Dinamico;
- Continuo;
- Ignoto.
![[Pasted image 20251124125229.png|center|500]]
