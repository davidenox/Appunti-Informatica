# Domande che possono capitare all'esame
## Quanti tipi di variabili si possono usare?
- Globali
- Locali
- Parametri
- Campi
## A cosa serve l'interfaccia in Java?
Forniscono un vocabolario unificante per interagire con oggetti aventi implementazioni differenti (cioè basati su classi diverse)

## Quanti tipi si conoscono in Java?
- Primitivi:
	- int
	- string
	- float
	- double
	- boolean
- Oggetti:
	- classi
	- interfacce

# Concetti della programmazione Object-Oriented
- **Cos'è un oggetto?** : Un oggetto è un pacchetto software di stati e comportamenti correlati.Gli oggetti software sono spesso utilizzati per modellare gli oggetti della vita reale che puoi trovare ogni giorno
- **Cos'è una classe?**: Una classe è lo schema o prototipo da cui sono creati gli oggetti
- **Cos'è l'ereditarietà?**: L'ereditarietà fornisce un meccanismo potente e naturale per organizzare e strutturare software
- **Cos'è un interfaccia?**: L'interfaccia è un "contratto" tra una classe e il mondo esterno. Quando una classe implementa un'interfaccia, promette di fornire il comportamento pubblicato da quell'interfaccia.
- **Cos'è un pacchetto?**: Un pacchetto è uno spazio dei nomi che serve ad organizzare classi e interfaccie in maniera logica. Inserire il codice nei pacchetti semplifica la gestione di progetti software di grandi dimensioni

## Oggetto
Gli oggetti sono la chiave per capire la tecnologia object-oriented. Ci sono vari esempi di oggetti nella vita reale: un cane, la scrivania, etc...
Gli oggetti condividono due caratteristiche:
- stati(state)
- comportamenti(behavior)
Identificare lo stato e il comportamento di un oggetto nella vita reale è una grande idea per iniziare a pensare in termini di OOP

![[Pasted image 20221016174127.png|center|450]]

Gli oggetti software sono concettualmente simili agli oggetti nella vita reale: anche loro sono cpomposti da stati e comportamenti. Un oggetto software salva i suoi stati nei _fields_(campi)(variabili in qualche linguaggio di programmazione) ed espone i suoi comportamenti tramite i _methods_(metodi)(funzioni in qualche linguaggio di programmazione). I metodi operano sullo stato interno di un oggetto e servono come il meccanismo primario per la comunicazione object-to-object.
Nascondere lo stato interno e richiedere che tutte le interazioni vengano eseguite attraverso i metodi di un oggetto è noto come incapsulamento dei dati(**data encapsulation**), un principio fondamentale della programmazione orientata agli oggetti

Raggruppare il codice in oggetti software individuali fornisce un numero di benefits, inclusi:
- **Modularità**: il codice sorgente per un oggeto può essere scritto e mantenuto indipendentemente dal codice sorgente di altri oggetti
- **Informatio-hiding**: interaggendo solo con i metodi dell'oggetto, i dettagli delle implementazioni interne rimane nascosto al mondo esterno
- **Riutilizzo del codice**: se un oggetto già esiste, puoi usare quell'oggetto nel tuo programma
- **Collegabilità e debugging facili**: Se un particolare oggetto risulta essere problematico, puoi semplicemente rimuoverlo dall'applicazione e collegare un oggetto diverso come sostituto.

## Classe

Una classe è lo schema da cui ogni oggetto viene creato.
Esempio della classe bicicletta
```java
class Bicycle {

    int cadence = 0;
    int speed = 0;
    int gear = 1;

    void changeCadence(int newValue) {
         cadence = newValue;
    }

    void changeGear(int newValue) {
         gear = newValue;
    }

    void speedUp(int increment) {
         speed = speed + increment;   
    }

    void applyBrakes(int decrement) {
         speed = speed - decrement;
    }

    void printStates() {
         System.out.println("cadence:" +
             cadence + " speed:" + 
             speed + " gear:" + gear);
    }
}
```
I campi cadence, speed e gear rappresentano lo stato dell'oggetto e i metodi (changeCadence, changeGear, speedUp ecc.) ne definiscono l'interazione con il mondo esterno.

Potresti aver notato che la classe Bicycle non contiene un metodo principale. Questo perché non è un'applicazione completa; è solo il progetto per le biciclette che potrebbe essere utilizzato in un'applicazione. La responsabilità di creare e utilizzare nuovi oggetti Bicycle appartiene a un'altra classe nell'applicazione.

Ecco una classe BicycleDemo che crea due oggetti Bicycle separati e ne invoca i metodi:

```java
class BicycleDemo {
    public static void main(String[] args) {

        // Create two different 
        // Bicycle objects
        Bicycle bike1 = new Bicycle();
        Bicycle bike2 = new Bicycle();

        // Invoke methods on 
        // those objects
        bike1.changeCadence(50);
        bike1.speedUp(10);
        bike1.changeGear(2);
        bike1.printStates();

        bike2.changeCadence(50);
        bike2.speedUp(10);
        bike2.changeGear(2);
        bike2.changeCadence(40);
        bike2.speedUp(10);
        bike2.changeGear(3);
        bike2.printStates();
    }
}
```

## Ereditarietà

Diversi tipi di oggetti hanno spesso una certa quantità in comune tra loro. Mountain bike, bici da strada e bici tandem, ad esempio, condividono tutte le caratteristiche delle biciclette (velocità attuale, cadenza del pedale attuale, marcia attuale). Eppure ognuno definisce anche caratteristiche aggiuntive che li rendono diversi: le biciclette tandem hanno due sedili e due set di manubri; le bici da strada hanno il manubrio drop; alcune mountain bike hanno una corona aggiuntiva, che conferisce loro un rapporto di trasmissione inferiore.

La programmazione orientata agli oggetti consente alle classi di ereditare lo stato e il comportamento comunemente usati da altre classi. In questo esempio, la bicicletta diventa ora la superclasse di MountainBike, RoadBike e TandemBike. Nel linguaggio di programmazione Java, ogni classe può avere una superclasse diretta e ogni superclasse ha il potenziale per un numero illimitato di sottoclassi:
![[concepts-bikeHierarchy.gif|center]]

La sintassi per creare una sottoclasse è semplice. All'inizio della tua dichiarazione di classe, usa la parola chiave extends, seguita dal nome della classe da cui ereditare:
```java
class MountainBike extends Bicycle {

    // new fields and methods defining 
    // a mountain bike would go here

}
```

Ciò offre a MountainBike tutti gli stessi campi e metodi di Bicycle, ma consente al suo codice di concentrarsi esclusivamente sulle caratteristiche che lo rendono unico. Questo rende il codice per le tue sottoclassi facile da leggere. Tuttavia, devi fare attenzione a documentare correttamente lo stato e il comportamento definiti da ciascuna superclasse, poiché quel codice non apparirà nel file sorgente di ciascuna sottoclasse.

## Interfaccia

nella sua forma più comune, un'interfaccia è un gruppo di metodi correlati con corpi vuoti. Il comportamento di una bicicletta, se specificato come interfaccia, potrebbe apparire come segue:

```java
interface Bicycle {

    //  wheel revolutions per minute
    void changeCadence(int newValue);

    void changeGear(int newValue);

    void speedUp(int increment);

    void applyBrakes(int decrement);
}
```

Per implementare questa interfaccia, il nome della tua classe cambierebbe (in una particolare marca di bicicletta, ad esempio, come ACMEBicycle) e useresti la parola chiave implements nella dichiarazione della classe:
```java
class ACMEBicycle implements Bicycle {

    int cadence = 0;
    int speed = 0;
    int gear = 1;

   // The compiler will now require that methods
   // changeCadence, changeGear, speedUp, and applyBrakes
   // all be implemented. Compilation will fail if those
   // methods are missing from this class.

    void changeCadence(int newValue) {
         cadence = newValue;
    }

    void changeGear(int newValue) {
         gear = newValue;
    }

    void speedUp(int increment) {
         speed = speed + increment;   
    }

    void applyBrakes(int decrement) {
         speed = speed - decrement;
    }

    void printStates() {
         System.out.println("cadence:" +
             cadence + " speed:" + 
             speed + " gear:" + gear);
    }
}
```

L'implementazione di un'interfaccia consente a una classe di diventare più formale sul comportamento che promette di fornire. Le interfacce formano un contratto tra la classe e il mondo esterno e questo contratto viene applicato in fase di compilazione dal compilatore. Se la tua classe afferma di implementare un'interfaccia, tutti i metodi definiti da tale interfaccia devono apparire nel codice sorgente prima che la classe venga compilata correttamente.

## Pacchetto

Un pacchetto è uno spazio dei nomi che organizza un insieme di classi e interfacce correlate. Concettualmente puoi pensare ai pacchetti come simili a diverse cartelle sul tuo computer. È possibile mantenere le pagine HTML in una cartella, le immagini in un'altra e gli script o le applicazioni in un'altra ancora. Poiché il software scritto nel linguaggio di programmazione Java può essere composto da centinaia o migliaia di classi singole, ha senso mantenere le cose organizzate inserendo classi e interfacce correlate in pacchetti.

La piattaforma Java fornisce un'enorme libreria di classi (un insieme di pacchetti) adatta per l'uso nelle proprie applicazioni. Questa libreria è nota come "Application Programming Interface" o "API" in breve. I suoi pacchetti rappresentano le attività più comunemente associate alla programmazione generica. Ad esempio, un oggetto String contiene stato e comportamento per le stringhe di caratteri; un oggetto File consente a un programmatore di creare, eliminare, ispezionare, confrontare o modificare facilmente un file sul filesystem; un oggetto Socket consente la creazione e l'utilizzo di socket di rete; vari oggetti della GUI controllano pulsanti e caselle di controllo e qualsiasi altra cosa relativa alle interfacce utente grafiche. Ci sono letteralmente migliaia di classi tra cui scegliere. Ciò consente a te, programmatore, di concentrarti sulla progettazione della tua particolare applicazione, piuttosto che sull'infrastruttura necessaria per farla funzionare.

