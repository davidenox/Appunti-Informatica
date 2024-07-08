# Concetti di programmazione orientata agli oggetti

Se non avete mai usato un linguaggio di programmazione orientato agli oggetti, dovrete imparare alcuni concetti di base prima di poter iniziare a scrivere del codice. Questa lezione introduce agli oggetti, alle classi, all'ereditarietà, alle interfacce e ai pacchetti. Ogni discussione si concentra sul modo in cui questi concetti si riferiscono al mondo reale, fornendo contemporaneamente un'introduzione alla sintassi del linguaggio di programmazione Java.

## Che cos'è un oggetto?

Un oggetto è un insieme software di stati e comportamenti correlati. Gli oggetti software sono spesso utilizzati per modellare gli oggetti del mondo reale che si trovano nella vita di tutti i giorni. 

Gli oggetti del mondo reale condividono due caratteristiche: hanno tutti uno stato e un comportamento . I cani hanno uno stato (nome, colore, razza, fame) e un comportamento (abbaiare, andare a prendere, scodinzolare). Le biciclette hanno anche uno stato (marcia attuale, cadenza di pedalata attuale, velocità attuale) e un comportamento (cambio di marcia, cambio di cadenza di pedalata, applicazione dei freni). Identificare lo stato e il comportamento degli oggetti del mondo reale è un ottimo modo per iniziare a pensare in termini di programmazione orientata agli oggetti.

Un oggetto memorizza il suo stato in campi (variabili in alcuni linguaggi di programmazione) ed espone il suo comportamento attraverso metodi (funzioni in alcuni linguaggi di programmazione). I metodi operano sullo stato interno di un oggetto e fungono da meccanismo principale per la comunicazione da oggetto a oggetto. Nascondere lo stato interno e richiedere che tutta l'interazione venga eseguita tramite i metodi di un oggetto è noto come incapsulamento dei dati , un principio fondamentale della programmazione orientata agli oggetti.


Attribuendo lo stato (velocità attuale, cadenza della pedalata attuale e marcia attuale) e fornendo metodi per modificare tale stato, l'oggetto mantiene il controllo su come il mondo esterno può utilizzarlo. Ad esempio, se la bicicletta ha solo 6 marce, un metodo per cambiare marcia potrebbe rifiutare qualsiasi valore inferiore a 1 o maggiore di 6.

Raggruppare il codice in singoli oggetti software offre numerosi vantaggi, tra cui:

1. Modularità: il codice sorgente di un oggetto può essere scritto e mantenuto indipendentemente dal codice sorgente di altri oggetti. Una volta creato, un oggetto può essere facilmente passato all'interno del sistema.
    
2. Nascondere le informazioni: interagendo solo con i metodi di un oggetto, i dettagli della sua implementazione interna rimangono nascosti al mondo esterno.
    
3. Riutilizzo del codice: se un oggetto esiste già (magari scritto da un altro sviluppatore di software), puoi utilizzare quell'oggetto nel tuo programma. Ciò consente agli specialisti di implementare/testare/debug di oggetti complessi e specifici per attività, di cui puoi quindi fidarti per l'esecuzione nel tuo codice.
    
4. Collegabilità e facilità di debug: se un particolare oggetto risulta problematico, puoi semplicemente rimuoverlo dall'applicazione e collegare un oggetto diverso in sostituzione. Questo è analogo alla risoluzione dei problemi meccanici nel mondo reale. Se si rompe un bullone, lo sostituisci , non l'intera macchina.
    
##  Che cos'è una classe?

Una classe è un progetto o un prototipo da cui vengono creati gli oggetti. Questa sezione definisce una classe che modella lo stato e il comportamento di un oggetto del mondo reale. Si concentra intenzionalmente sulle basi, mostrando come anche una classe semplice possa modellare in modo pulito lo stato e il comportamento.

```Java
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

         System.out.println("cadence:" +cadence + " speed:" + speed + " gear:" + gear);
    }
}
```

La sintassi del linguaggio di programmazione Java vi sembrerà nuova, ma la struttura di questa classe si basa sulla precedente discussione sugli oggetti bicicletta. I campi cadenza, velocità e marcia rappresentano lo stato dell'oggetto e i metodi (changeCadence, changeGear, speedUp ecc.) definiscono la sua interazione con il mondo esterno.

Si sarà notato che la classe Bicycle non contiene un metodo main. Questo perché non si tratta di un'applicazione completa, ma solo di un modello di bicicletta che potrebbe essere utilizzato in un'applicazione. La responsabilità di creare e utilizzare nuovi oggetti Bicycle spetta a qualche altra classe dell'applicazione.

Ecco una classe BicycleDemo che crea due oggetti Bicycle separati e invoca i loro metodi:

  
```Java
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
  
  

## Che cos'è l'ereditarietà?

L'ereditarietà è un meccanismo potente e naturale per organizzare e strutturare il software. Questa sezione spiega come le classi ereditano lo stato e il comportamento dalle loro superclassi e spiega come derivare una classe da un'altra utilizzando la semplice sintassi fornita dal linguaggio di programmazione Java.

Oggetti di tipo diverso hanno spesso una certa quantità di cose in comune tra loro. Le mountain bike, le biciclette da strada e i tandem, per esempio, condividono tutte le caratteristiche delle biciclette (velocità attuale, cadenza della pedalata attuale, marcia attuale). Tuttavia, ognuna di esse definisce anche caratteristiche aggiuntive che le rendono diverse: le biciclette tandem hanno due sedili e due set di manubri; le biciclette da strada hanno manubri a goccia; alcune mountain bike hanno un anello della catena aggiuntivo, che conferisce loro un rapporto di trasmissione inferiore.

La programmazione orientata agli oggetti consente alle classi di ereditare stati e comportamenti comunemente utilizzati da altre classi. In questo esempio, Bicycle diventa la superclasse di MountainBike, RoadBike e TandemBike. Nel linguaggio di programmazione Java, ogni classe può avere una sola superclasse diretta e ogni superclasse può avere un numero illimitato di sottoclassi.

La sintassi per creare una sottoclasse è semplice. All'inizio della dichiarazione della classe, si usa la parola chiave extends, seguita dal nome della classe da cui ereditare:

```Java
class MountainBike extends Bicycle {

    // new fields and methods defining 
    // a mountain bike would go here

}
```
  

In questo modo, MountainBike ha tutti gli stessi campi e metodi di Bicycle, ma il suo codice si concentra esclusivamente sulle caratteristiche che la rendono unica. Questo rende il codice delle sottoclassi di facile lettura. Tuttavia, bisogna fare attenzione a documentare correttamente lo stato e il comportamento che ogni superclasse definisce, poiché tale codice non apparirà nel file sorgente di ogni sottoclasse.

## Che cos'è un'interfaccia?

Un'interfaccia è un contratto tra una classe e il mondo esterno. Quando una classe implementa un'interfaccia, promette di fornire il comportamento pubblicato da quell'interfaccia. Questa sezione definisce una semplice interfaccia e spiega le modifiche necessarie per qualsiasi classe che la implementi.

Gli oggetti definiscono la loro interazione con il mondo esterno attraverso i metodi che espongono. I metodi costituiscono l'interfaccia dell'oggetto con il mondo esterno; i pulsanti sulla parte anteriore del televisore, ad esempio, sono l'interfaccia tra l'utente e i cavi elettrici dall'altra parte dell'involucro di plastica. Si preme il tasto "power" per accendere e spegnere il televisore.

Nella sua forma più comune, un'interfaccia è un gruppo di metodi correlati con corpi vuoti. Il comportamento di una bicicletta, se specificato come interfaccia, potrebbe apparire come segue:

```Java
interface Bicycle {
    //  wheel revolutions per minute
    void changeCadence(int newValue);
    void changeGear(int newValue);
    void speedUp(int increment);
    void applyBrakes(int decrement);
}
```

Per implementare questa interfaccia, si cambia il nome della classe (ad esempio, una particolare marca di bicicletta, come ACMEBicycle) e si usa la parola chiave implements nella dichiarazione della classe:

```Java
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

L'implementazione di un'interfaccia consente a una classe di rendere più formale il comportamento che promette di fornire. Le interfacce formano un contratto tra la classe e il mondo esterno, contratto che viene applicato in fase di compilazione dal compilatore. Se la classe dichiara di implementare un'interfaccia, tutti i metodi definiti da tale interfaccia devono comparire nel codice sorgente prima che la classe venga compilata correttamente.

### Cos'è un pacchetto?

Un pacchetto è uno spazio dei nomi per organizzare classi e interfacce in modo logico. La collocazione del codice in pacchetti rende più facile la gestione di progetti software di grandi dimensioni. Questa sezione spiega perché è utile e introduce l'interfaccia di programmazione delle applicazioni (API) fornita dalla piattaforma Java.

Un pacchetto è uno spazio dei nomi che organizza un insieme di classi e interfacce correlate. Concettualmente si può pensare ai pacchetti come a diverse cartelle del computer. Potreste tenere le pagine HTML in una cartella, le immagini in un'altra e gli script o le applicazioni in un'altra ancora. Poiché il software scritto nel linguaggio di programmazione Java può essere composto da centinaia o migliaia di singole classi, ha senso organizzare le cose inserendo le classi e le interfacce correlate in pacchetti.

La piattaforma Java mette a disposizione un'enorme libreria di classi (un insieme di pacchetti) da utilizzare nelle proprie applicazioni. Questa libreria è nota come "Application Programming Interface" (interfaccia di programmazione dell'applicazione) o, in breve, "API". I pacchetti rappresentano i compiti più comunemente associati alla programmazione generale. Ad esempio, un oggetto String contiene lo stato e il comportamento delle stringhe di caratteri; un oggetto File permette al programmatore di creare, cancellare, ispezionare, confrontare o modificare facilmente un file sul filesystem; un oggetto Socket consente la creazione e l'uso di socket di rete; vari oggetti GUI controllano pulsanti e caselle di controllo e qualsiasi altra cosa relativa alle interfacce grafiche. Ci sono letteralmente migliaia di classi tra cui scegliere. Questo permette al programmatore di concentrarsi sulla progettazione della propria applicazione, piuttosto che sull'infrastruttura necessaria per farla funzionare.

La Java Platform API Specification contiene l'elenco completo di tutti i pacchetti, le interfacce, le classi, i campi e i metodi forniti dalla piattaforma Java SE. Caricate la pagina nel browser e mettetela tra i preferiti. Come programmatore, diventerà la vostra documentazione di riferimento più importante.
# Polimorfismo

La definizione del dizionario di polimorfismo si riferisce a un principio in biologia in cui un organismo o una specie può avere molte forme o stadi diversi. Questo principio può essere applicato anche alla programmazione orientata agli oggetti e ai linguaggi come il linguaggio Java. Le sottoclassi di una classe possono definire i propri comportamenti unici e tuttavia condividere alcune delle stesse funzionalità della classe genitore.

Il polimorfismo può essere dimostrato con una piccola modifica alla Bicycle classe. Ad esempio, printDescription è possibile aggiungere alla classe un metodo che visualizzi tutti i dati attualmente archiviati in un'istanza.

```Java
public void printDescription(){

    System.out.println("\nBike is " + "in gear " + this.gear
        + " with a cadence of " + this.cadence +
        " and travelling at a speed of " + this.speed + ". ");

}
```

Per dimostrare le caratteristiche polimorfiche nel linguaggio Java, estendi la Bicycle classe con a MountainBike e a RoadBike class. Per MountainBike, aggiungi un campo per suspension, che è un String valore che indica se la bici ha un ammortizzatore anteriore, Front. Oppure, la bici ha un ammortizzatore anteriore e posteriore Dual.

Ecco la classe aggiornata:

```Java
public class MountainBike extends Bicycle {

    private String suspension;

	public MountainBike(
               int startCadence,
               int startSpeed,
               int startGear,
               String suspensionType){
        super(startCadence,
              startSpeed,
              startGear);
        this.setSuspension(suspensionType);
    }

    public String getSuspension(){
      return this.suspension;
    }
    
    public void setSuspension(String suspensionType) {
        this.suspension = suspensionType;
    }

    public void printDescription() {
        super.printDescription();
        System.out.println("The " + "MountainBike has a" +
            getSuspension() + " suspension.");
    }
}
```
  
Nota il printDescription metodo sovrascritto. Oltre alle informazioni fornite in precedenza, nell'output vengono inclusi dati aggiuntivi sulla sospensione.

Successivamente, crea la RoadBike classe. Poiché le bici da strada o da corsa hanno pneumatici stretti, aggiungi un attributo per tenere traccia della larghezza del pneumatico. Ecco la RoadBike classe:

```Java
public class RoadBike extends Bicycle{

    // In millimeters (mm)

    private int tireWidth;

  

    public RoadBike(int startCadence,

                    int startSpeed,

                    int startGear,

                    int newTireWidth){

        super(startCadence,

              startSpeed,

              startGear);

        this.setTireWidth(newTireWidth);

    }

  

    public int getTireWidth(){

      return this.tireWidth;

    }

  

    public void setTireWidth(int newTireWidth){

        this.tireWidth = newTireWidth;

    }

  

    public void printDescription(){

        super.printDescription();

        System.out.println("The RoadBike" + " has " + getTireWidth() +

            " MM tires.");

    }

}
```

Tieni presente che ancora una volta il printDescription metodo è stato sovrascritto. Questa volta vengono visualizzate le informazioni sulla larghezza del pneumatico.

Per riassumere, ci sono tre classi: Bicycle, MountainBike, e RoadBike. Le due sottoclassi sovrascrivono il printDescription metodo e stampano informazioni univoche.

Ecco un programma di test che crea tre Bicycle variabili. Ciascuna variabile è assegnata a una delle tre classi di biciclette. Ogni variabile viene quindi stampata.


``` Java
public class TestBikes {

  public static void main(String[] args){

    Bicycle bike01, bike02, bike03;

  

    bike01 = new Bicycle(20, 10, 1);

    bike02 = new MountainBike(20, 10, 5, "Dual");

    bike03 = new RoadBike(40, 20, 8, 23);

  

    bike01.printDescription();

    bike02.printDescription();

    bike03.printDescription();

  }

}
```
  
Quello che segue è l'output del programma di test:

```Java
Bike is in gear 1 with a cadence of 20 and travelling at a speed of 10. 

Bike is in gear 5 with a cadence of 20 and travelling at a speed of 10. 

The MountainBike has a Dual suspension.

Bike is in gear 8 with a cadence of 40 and travelling at a speed of 20. 

The RoadBike has 23 MM tires.
```

La Java virtual machine (JVM) richiama il metodo appropriato per l'oggetto a cui si fa riferimento in ciascuna variabile. Non chiama il metodo definito dal tipo della variabile. Questo comportamento viene definito invocazione del metodo virtuale e dimostra un aspetto delle importanti funzionalità del polimorfismo nel linguaggio Java.

## Metodi e classi astratti

Una classe astratta è una classe dichiarata astratta e può includere o meno metodi astratti. Le classi astratte non possono essere istanziate, ma possono essere subclassate.

Un metodo astratto è un metodo dichiarato senza un'implementazione (senza parentesi e seguito da un punto e virgola), come questo:

```Java
abstract void moveTo(double deltaX, double deltaY);
```

Se una classe include metodi astratti, la classe stessa deve essere dichiarata astratta, come in:

```Java
public abstract class GraphicObject {

   // declare fields

   // declare nonabstract methods

   abstract void draw();

}
```

Quando una classe astratta viene subclassata, la sottoclasse di solito fornisce le implementazioni per tutti i metodi astratti della classe madre. Tuttavia, se non lo fa, anche la sottoclasse deve essere dichiarata astratta.

## CHATGPT:

La Programmazione Orientata agli Oggetti (OOP) è un paradigma di programmazione che utilizza oggetti e classi per organizzare il codice e modellare i dati del mondo reale. Ecco i concetti fondamentali dell'OOP:

### 1. Classe

Una classe è un modello o una struttura che definisce le proprietà (attributi) e i comportamenti (metodi) che gli oggetti creati da essa possederanno. È una sorta di blueprint che descrive come gli oggetti dovrebbero essere.

- Attributi: Variabili che memorizzano lo stato di un oggetto. Ad esempio, una classe Persona può avere attributi come nome e età.
    
- Metodi: Funzioni definite all'interno di una classe che descrivono i comportamenti degli oggetti. Ad esempio, una classe Persona può avere un metodo parla().
    

```Java
public class Persona {

    String nome;
    int eta;

    void parla() {
        System.out.println("Ciao, mi chiamo " + nome);
    }
}
```

### 2. Oggetto

Un oggetto è un'istanza di una classe. Quando una classe viene instanziata, si crea un oggetto che può utilizzare i metodi e accedere agli attributi definiti nella classe.

```Java
Persona persona1 = new Persona();
persona1.nome = "Mario";
persona1.eta = 30;
persona1.parla(); // Output: Ciao, mi chiamo Mario
```

### 3. Incapsulamento

L'incapsulamento è il concetto di nascondere i dettagli interni di un oggetto e consentire l'accesso solo attraverso metodi pubblici definiti. Questo migliora la modularità e la sicurezza del codice.  

- Accesso controllato: Gli attributi di una classe sono tipicamente dichiarati come private e accessibili solo tramite metodi public detti getter e setter.
    

```Java
public class Persona {
    private String nome;
    private int eta;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getEta() {
        return eta;
    }

    public void setEta(int eta) {
        if (eta > 0) {
            this.eta = eta;
        }
    }
}
```

### 4. Ereditarietà

L'ereditarietà permette di creare una nuova classe che eredita gli attributi e i metodi di un'altra classe. La classe che eredita è detta sottoclasse, mentre la classe da cui eredita è detta superclasse.

```Java
public class Studente extends Persona {
    private String corsoDiStudi;

    public String getCorsoDiStudi() {
        return corsoDiStudi;
    }

    public void setCorsoDiStudi(String corsoDiStudi) {
        this.corsoDiStudi = corsoDiStudi;
    }
}
```

### 5. Polimorfismo

Il polimorfismo permette agli oggetti di essere trattati come istanze della loro superclasse piuttosto che della loro classe concreta. Esistono due tipi principali di polimorfismo:

- Polimorfismo a compilazione (sovraccarico dei metodi): Più metodi con lo stesso nome ma con parametri diversi.
    
- Polimorfismo a esecuzione (sovrascrittura dei metodi): Un metodo definito in una superclasse viene riscritto in una sottoclasse.
    

```Java
public class Animale {
    public void faiVerso() {
        System.out.println("L'animale fa un verso");
    }
}

public class Cane extends Animale {

    @Override
    public void faiVerso() {
        System.out.println("Il cane abbaia");
    }
}

public class Main {
    public static void main(String[] args) {
        Animale mioAnimale = new Cane();
        mioAnimale.faiVerso(); // Output: Il cane abbaia
    }
}
```

### 6. Astrazione

L'astrazione è il concetto di nascondere i dettagli di implementazione e mostrare solo la funzionalità essenziale di un oggetto. Questo può essere ottenuto attraverso classi astratte e interfacce.

- Classe astratta: Una classe che non può essere istanziata direttamente e può contenere metodi astratti (senza implementazione).
    

```Java
public abstract class Forma {
    abstract void disegna();
}

public class Cerchio extends Forma {
    @Override
    void disegna() {
        System.out.println("Disegna un cerchio");
    }
}
```

- Interfaccia: Una collezione di metodi astratti che una classe deve implementare.

```Java
public interface Volante {
    void vola();
}
public class Uccello implements Volante {
    @Override
    public void vola() {
        System.out.println("L'uccello vola");
    }
}
```
  
Questi concetti combinati permettono di scrivere codice più modulare, riutilizzabile e manutenibile, facilitando la modellazione di sistemi complessi in modo intuitivo e organizzato.