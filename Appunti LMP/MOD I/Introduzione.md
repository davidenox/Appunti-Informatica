# Introduzione alla programmazione ad oggetti

Esistono 3 tipi di programmazione:
- [[Introduzione#Programmazione Strutturata|Programmazione Strutturata]]
- [[Introduzione#Programmazione Procedurale|Programmazione Procedurale]]
- [[Introduzione#Programmazione Orientata agli Oggetti|Programmazione Orientata agli Oggetti]]

## Programmazione Strutturata
I seguenti requisiti devono essere rispettati da un linguaggio di programmazione strutturato:
- **Completezza**: le tre strutture della programmazione strutturata devono avere almeno una rappresentanza sintattica nel linguaggio
- **Singolo punto di Ingresso e Uscita**: in ogni struttura di controllo si devono poter identificare un singolo punto di ingresso e un singolo punto di uscita. Ciò è necessario per la successiva
- **Componibilità**: ogni struttura di controllo deve poter essere considerata come un macro-statement, di modo da poter essere usata, ricorsivamente, come istruzione in altre strutture di controllo

![[Pasted image 20221011174606.png]]

## Programmazione Procedurale
Consiste nella possibilità di agevolare la leggibilità di un programma (e la sua manutenibilità) tramite la definizione di blocchi di codice, racchiusi da delimitatori e usualmente identificati da un nome

Tali blocchi assumono il nome di:
- Subroutine
- Procedure
- Funzioni
- Metodi
## Programmazione Orientata agli Oggetti
**Principi fondamentali dell'OOP**
- **Incapsulamento** Nascondere dettagli implementativi, permettendo di raggiungere solo alcune informazioni tramite _accessors_ e _mutators_
	- per una spiegazione più dettagliata si rimanda a questo link [Incapsulamento](https://it.wikipedia.org/wiki/Incapsulamento_(informatica))
- **Astrazione**:
	- Direttamente correlata alla precedente
	- L'Astrazione ha a che fare con la definizione di modelli, viste etc... per gli oggetti che sin vogliono rappresentare
	- ...mentre l'incapsulamento garantisce che le implementazioni di tali modelli rimangano opache ai loro utilizzatori
	- Per una spiegazione più dettagliata si rimanda a questo link : [Astrazione](https://it.wikipedia.org/wiki/Astrazione_(informatica)#Astrazione_nella_programmazione_orientata_agli_oggetti_(OOP))
- **Ereditarietà**: 
	- Permette di raccogliere a fattor comune caratteristiche condivise da oggetti simili, definendo dei modelli che rappresentino tali caratteristiche, e specializzando tali modelli per insiemi di oggetti via via più ristretti, ma accomunati da una similarità maggiore
	- Esempio: la _classe_ delle autovetture accomuna tutti gli oggetti con 3 o 4 ruote dotate di un qualche sistemi di propulsione e che permettano a delle persone di spostarsi. La classe delle citycar può definita come una specializzazione della precedente perchè comprende tutte le sue caratteristiche, ed ha in più caratteristiche _aggiuntive_, o _restrizioni_ su quelle già definite
	- Per una spiegazione più dettagliata si rimanda a questo link: [Ereditarietà](https://it.wikipedia.org/wiki/Ereditariet%C3%A0_(informatica))
- **Poliformismo**:
	- _Overriding_: (run-time polymorphism)
	- _Overloading_: (compile-time polymorphism)
	- Per una spiegazione più dettagliata si rimanda a questo link: [Poliformismo](https://it.wikipedia.org/wiki/Polimorfismo_(informatica))
