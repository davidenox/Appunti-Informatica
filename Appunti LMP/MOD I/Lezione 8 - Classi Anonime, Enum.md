
# Classi Anonime

Le classi anonime ti consentono di rendere il tuo codice più conciso. Ti consentono di dichiarare e istanziare una classe allo stesso tempo. Sono come le classi locali tranne per il fatto che non hanno un nome. Usali se hai bisogno di usare una classe locale solo una volta.

## Dichiarazione di classi anonime

Mentre le classi locali sono dichiarazioni di classe, le classi anonime sono espressioni, il che significa che definisci la classe in un'altra espressione. L'esempio seguente, HelloWorldAnonymousClasses, utilizza classi anonime nelle istruzioni di inizializzazione delle variabili locali frenchGreeting e spanishGreeting, ma utilizza una classe locale per l'inizializzazione della variabile englishGreeting:
```java
public class HelloWorldAnonymousClasses {
  
    interface HelloWorld {
        public void greet();
        public void greetSomeone(String someone);
    }
  
    public void sayHello() {
        
        class EnglishGreeting implements HelloWorld {
            String name = "world";
            public void greet() {
                greetSomeone("world");
            }
            public void greetSomeone(String someone) {
                name = someone;
                System.out.println("Hello " + name);
            }
        }
      
        HelloWorld englishGreeting = new EnglishGreeting();
        
        HelloWorld frenchGreeting = new HelloWorld() {
            String name = "tout le monde";
            public void greet() {
                greetSomeone("tout le monde");
            }
            public void greetSomeone(String someone) {
                name = someone;
                System.out.println("Salut " + name);
            }
        };
        
        HelloWorld spanishGreeting = new HelloWorld() {
            String name = "mundo";
            public void greet() {
                greetSomeone("mundo");
            }
            public void greetSomeone(String someone) {
                name = someone;
                System.out.println("Hola, " + name);
            }
        };
        englishGreeting.greet();
        frenchGreeting.greetSomeone("Fred");
        spanishGreeting.greet();
    }

    public static void main(String... args) {
        HelloWorldAnonymousClasses myApp =
            new HelloWorldAnonymousClasses();
        myApp.sayHello();
    }            
}
```

## Sintassi delle classi anonime
Come accennato in precedenza, una classe anonima è un'espressione. La sintassi di un'espressione di classe anonima è come l'invocazione di un costruttore, tranne per il fatto che esiste una definizione di classe contenuta in un blocco di codice.

Considera l'istanza dell'oggetto frenchGreeting:
```java
 HelloWorld frenchGreeting = new HelloWorld() {
            String name = "tout le monde";
            public void greet() {
                greetSomeone("tout le monde");
            }
            public void greetSomeone(String someone) {
                name = someone;
                System.out.println("Salut " + name);
            }
        };
```

L'espressione di classe anonima è costituita da quanto segue:

- L'operatore new
- Il nome di un'interfaccia da implementare o di una classe da estendere. In questo esempio, la classe anonima sta implementando l'interfaccia HelloWorld.
- Parentesi che contengono gli argomenti di un costruttore, proprio come una normale espressione di creazione di un'istanza di classe. **Nota**: quando si implementa un'interfaccia, non esiste un costruttore, quindi si utilizza una coppia vuota di parentesi, come in questo esempio.
- Un corpo, che è un corpo di dichiarazione di classe. Più specificamente, nel corpo sono consentite le dichiarazioni di metodo, ma non le istruzioni.

Poiché una definizione di classe anonima è un'espressione, deve far parte di un'istruzione. In questo esempio, l'espressione di classe anonima fa parte dell'istruzione che istanzia l'oggetto frenchGreeting. (Questo spiega perché c'è un punto e virgola dopo la parentesi graffa di chiusura.)

## Accesso alle variabili locali dell'ambito di inclusione e dichiarazione e accesso ai membri della classe anonima

Come le classi locali, le classi anonime possono acquisire variabili; hanno lo stesso accesso alle variabili locali dell'ambito di inclusione:

- Una classe anonima ha accesso ai membri della sua classe di inclusione.
- Una classe anonima non può accedere alle variabili locali nel suo ambito di inclusione che non sono dichiarate finali o effettivamente finali.
- Come una classe nidificata, una dichiarazione di un tipo (come una variabile) in una classe anonima mette in ombra qualsiasi altra dichiarazione nell'ambito di inclusione che ha lo stesso nome. Vedere Ombreggiatura per ulteriori informazioni.

Le classi anonime hanno anche le stesse restrizioni delle classi locali rispetto ai loro membri:

- Non è possibile dichiarare inizializzatori statici o interfacce membro in una classe anonima.
- Una classe anonima può avere membri statici purché siano variabili costanti.

Tieni presente che puoi dichiarare quanto segue nelle classi anonime:

- Campi
- Metodi extra (anche se non implementano alcun metodo del supertipo)
- Inizializzatori di istanza
- Classi locali

Tuttavia, non è possibile dichiarare costruttori in una classe anonima.

# Tipi di enumerazione (Enum Types)
Un tipo enum è un tipo di dati speciale che consente a una variabile di essere un insieme di costanti predefinite. La variabile deve essere uguale a uno dei valori predefiniti per essa. Esempi comuni includono le direzioni della bussola (valori di NORD, SUD, EST e OVEST) ei giorni della settimana.

Poiché sono costanti, i nomi dei campi di un tipo enum sono in lettere maiuscole.

Nel linguaggio di programmazione Java, si definisce un tipo enum utilizzando la parola chiave enum. Ad esempio, specificare un tipo di enumerazione dei giorni della settimana come:
```java
public enum Day {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY,
    THURSDAY, FRIDAY, SATURDAY 
}
```
È necessario utilizzare i tipi enum ogni volta che è necessario rappresentare un insieme fisso di costanti. Ciò include tipi di enum naturali come i pianeti nel nostro sistema solare e set di dati in cui conosci tutti i possibili valori in fase di compilazione, ad esempio le scelte in un menu, i flag della riga di comando e così via.

Ecco un codice che mostra come utilizzare l'enumerazione Day definita sopra:
```java
public class EnumTest {
    Day day;
    
    public EnumTest(Day day) {
        this.day = day;
    }
    
    public void tellItLikeItIs() {
        switch (day) {
            case MONDAY:
                System.out.println("Mondays are bad.");
                break;
                    
            case FRIDAY:
                System.out.println("Fridays are better.");
                break;
                         
            case SATURDAY: case SUNDAY:
                System.out.println("Weekends are best.");
                break;
                        
            default:
                System.out.println("Midweek days are so-so.");
                break;
        }
    }
    
    public static void main(String[] args) {
        EnumTest firstDay = new EnumTest(Day.MONDAY);
        firstDay.tellItLikeItIs();
        EnumTest thirdDay = new EnumTest(Day.WEDNESDAY);
        thirdDay.tellItLikeItIs();
        EnumTest fifthDay = new EnumTest(Day.FRIDAY);
        fifthDay.tellItLikeItIs();
        EnumTest sixthDay = new EnumTest(Day.SATURDAY);
        sixthDay.tellItLikeItIs();
        EnumTest seventhDay = new EnumTest(Day.SUNDAY);
        seventhDay.tellItLikeItIs();
    }
}
```

I tipi enum del linguaggio di programmazione Java sono molto più potenti delle loro controparti in altri linguaggi. La dichiarazione enum definisce una classe (chiamata tipo enum). Il corpo della classe enum può includere metodi e altri campi. Il compilatore aggiunge automaticamente alcuni metodi speciali quando crea un enum. Ad esempio, hanno un metodo di valori statici che restituisce un array contenente tutti i valori dell'enumerazione nell'ordine in cui sono dichiarati. Questo metodo viene comunemente utilizzato in combinazione con il costrutto for-each per scorrere i valori di un tipo enum. Ad esempio, questo codice dell'esempio di classe Planet riportato di seguito esegue l'iterazione su tutti i pianeti del sistema solare.
```java
for (Planet p : Planet.values()) {
    System.out.printf("Your weight on %s is %f%n",
                      p, p.surfaceWeight(mass));
}
```

>[!Info]- Osservazione
>Il costruttore per un tipo enum deve essere package-private o private access. Crea automaticamente le costanti definite all'inizio del corpo dell'enumerazione. Non puoi invocare tu stesso un costruttore enum.

Oltre alle proprietà e al costruttore, Planet dispone di metodi che consentono di recuperare la gravità superficiale e il peso di un oggetto su ciascun pianeta. Ecco un programma di esempio che prende il tuo peso sulla terra (in qualsiasi unità) e calcola e stampa il tuo peso su tutti i pianeti (nella stessa unità):
```java
public enum Planet {
    MERCURY (3.303e+23, 2.4397e6),
    VENUS   (4.869e+24, 6.0518e6),
    EARTH   (5.976e+24, 6.37814e6),
    MARS    (6.421e+23, 3.3972e6),
    JUPITER (1.9e+27,   7.1492e7),
    SATURN  (5.688e+26, 6.0268e7),
    URANUS  (8.686e+25, 2.5559e7),
    NEPTUNE (1.024e+26, 2.4746e7);

    private final double mass;   // in kilograms
    private final double radius; // in meters
    Planet(double mass, double radius) {
        this.mass = mass;
        this.radius = radius;
    }
    private double mass() { return mass; }
    private double radius() { return radius; }

    // universal gravitational constant  (m3 kg-1 s-2)
    public static final double G = 6.67300E-11;

    double surfaceGravity() {
        return G * mass / (radius * radius);
    }
    double surfaceWeight(double otherMass) {
        return otherMass * surfaceGravity();
    }
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java Planet <earth_weight>");
            System.exit(-1);
        }
        double earthWeight = Double.parseDouble(args[0]);
        double mass = earthWeight/EARTH.surfaceGravity();
        for (Planet p : Planet.values())
           System.out.printf("Your weight on %s is %f%n",
                             p, p.surfaceWeight(mass));
    }
}
```
