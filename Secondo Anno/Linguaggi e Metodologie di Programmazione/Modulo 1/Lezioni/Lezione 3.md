# Concetti di OOP
Questa lezione introdurrà il concetto di oggetti, classi, ereditarietà, interfacce e pacchetti. Ogni discussione si concentra su come questi concetti si riferiscono al mondo reale, simultaneamente provvedono ad un'introduzione alla sintassi della programmazione in Java.
1. *Oggetto*:
	- Un oggetto è un pacchetto software di stato e comportamento correlati. Gli oggetti software sono spesso utilizzati come modelli per oggetti nel mondo reale. 
2. *Classe*:
	- Una classe è una planimetria o prototipo da cui gli oggetti sono creati. Questa sezione definisce una classe che modellizza lo stato e comportamento di un oggetto della vita reale. Si concentra intenzionalmente sulle basi, mostrando come una semplice classe può ordinatamente modellizzare uno stato o comportamento.
3. *Ereditarietà*:
	- L'ereditarietà fornisce un potente e naturale meccanismo per l'organizzazione e la struttura del Software. 
4. *Interfaccia*:
	- Un'interfaccia è un "contratto" tra una classe e il mondo reale. Quando una classe implementa un'interfaccia, promette di fornire il comportamento pubblicato da quell'interfaccia.
5. *Pacchetto*: 
	- Un pacchetto è uno spazio dei nomi per l'organizzazione delle classi e l'interfaccia in modo logico. Mettere il codice nei pacchetti rende più semplice la gestione dei progetti software più estesi.

## Oggetto
Gli oggetti sono chiavi per capire la tecnologia *object-oriented*. Guardandosi intorno si troveranno molti esempi reali di oggetti. Gli oggetti della vita reale condividono due caratteristiche, tutti hanno:
1. Stato;
2. Comportamento.
Identificare stati e comportamenti per oggetti dellla vita reale è un ottimo modo per iniziare a pensare in termini di programmazione object-oriented. Alcuni oggetti potranno contenere altri oggetti. Queste osservazioni della vita reale si possono tradurre nel mondo della programmazione ad oggetti.

![[Pasted image 20231009121915.png|center|500]]

Gli oggetti software sono concettualmente simili agli oggetti nel mondo reale: anche loro sono fatti di stati e comportamenti. Un oggetto immagazzina i suoi stati nei campi ( *fields* ), e manifestano i propri comportamenti attraverso i metodi ( *methods*, funzioni ). I metodi operano sullo stato interno di un oggetto e servono come meccanismo primario per comunicazioni object-to-object. Nascondere stati interni e richiedere che tutte le interazioni siano svolte attraverso metodi di oggetto è chiamato *data encapsulation* ( incapsulazioni data, un principio fondamentale della programmazione ad oggetti).
Attribuendo lo stato e fornendo metodi per modificare tale stato, l'oggetto mantiene il controllo su come il mondo esterno può utilizzarlo. 
Raggruppare il codice in singoli oggetti software offre numerosi vantaggi, tra cui:

1. *Modularity* (Modularità): il codice sorgente di un oggetto può essere scritto e mantenuto indipendentemente dal codice sorgente di altri oggetti. Una volta creato, un oggetto può essere facilmente passato all'interno del sistema.
2. *Information-hiding* (Nascondere le informazioni): interagendo solo con i metodi di un oggetto, i dettagli della sua implementazione interna rimangono nascosti al mondo esterno.
3. *Code re-use* (Riutilizzo del codice): se un oggetto esiste già (magari scritto da un altro sviluppatore di software), si può utilizzare quell'oggetto in un altro programma. Ciò consente agli specialisti di implementare/testare/debug di oggetti complessi e specifici per attività, di cui puoi quindi fidarti per l'esecuzione nel tuo codice.
4. *Pluggability and debugging ease* (Collegabilità e facilità di debug): se un particolare oggetto risulta problematico, puoi semplicemente rimuoverlo dall'applicazione e collegare un oggetto diverso in sostituzione. Questo è analogo alla risoluzione dei problemi meccanici nel mondo reale. Se si rompe un bullone, lo sostituisci, non l'intera macchina.

## Classe
Una classe è una planimetria o prototipo da cui gli oggetti sono individualmente creati.
La seguente classe *Bicycle* è una possibile implementazione di una bicicletta:
```java
class Bicycle {
	int cadence = 0;
	int speed = 0;
	int gear = 1;

	void changeCadence( int newValue) {
		cadence = newValue;
	}
}
```