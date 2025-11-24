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
	La