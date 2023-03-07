
# Ritornando alla [[Lezione 6 - Classi]]

## Classi nidificate
Il linguaggio di programmazione Java consente di definire una classe all'interno di un'altra classe. Tale classe è chiamata classe nidificata ed è illustrata qui:
```java
class OuterClass {
    ...
    class NestedClass {
        ...
    }
}
```
Una classe nidificata è un membro della sua classe che la racchiude. Le classi nidificate non statiche (classi interne) hanno accesso ad altri membri della classe che lo racchiude, anche se sono dichiarate private. Le classi nidificate statiche non hanno accesso ad altri membri della classe di inclusione. Come membro di OuterClass, una classe nidificata può essere dichiarata privata, pubblica, protetta o privata del pacchetto. (Ricorda che le classi esterne possono essere dichiarate solo pubbliche o private del pacchetto.)

### Perchè usare le classi nidificate?
I motivi convincenti per l'utilizzo di classi nidificate includono quanto segue:
- **È un modo per raggruppare logicamente le classi che vengono utilizzate solo in un posto**: se una classe è utile solo a un'altra classe, è logico incorporarla in quella classe e tenerle insieme. L'annidamento di tali "classi di supporto" rende il loro pacchetto più snello.
- **Aumenta l'incapsulamento**: considera due classi di primo livello, A e B, in cui B ha bisogno dell'accesso ai membri di A che altrimenti sarebbero dichiarati privati. Nascondendo la classe B all'interno della classe A, i membri di A possono essere dichiarati privati e B può accedervi. Inoltre, B stesso può essere nascosto dal mondo esterno.
- **Può portare a un codice più leggibile e gestibile**: l'annidamento di classi piccole all'interno di classi di livello superiore posiziona il codice più vicino a dove viene utilizzato.

### Classi interne
Come per i metodi e le variabili di istanza, una classe interna è associata a un'istanza della sua classe di inclusione e ha accesso diretto ai metodi e ai campi di quell'oggetto. Inoltre, poiché una classe interna è associata a un'istanza, non può definire alcun membro statico.

Gli oggetti che sono istanze di una classe interna esistono all'interno di un'istanza della classe esterna. Considera le seguenti classi:
```java
class OuterClass {
    ...
    class InnerClass {
        ...
    }
}
```
Un'istanza di InnerClass può esistere solo all'interno di un'istanza di OuterClass e ha accesso diretto ai metodi e ai campi della sua istanza di inclusione.

Per creare un'istanza di una classe interna, devi prima istanziare la classe esterna. Quindi, crea l'oggetto interno all'interno dell'oggetto esterno con questa sintassi:

```java
OuterClass outerObject = new OuterClass();
OuterClass.InnerClass innerObject = outerObject.new InnerClass();
```

### Classi nidificate statiche
Come per i metodi e le variabili di classe, una classe nidificata statica è associata alla sua classe esterna. E come i metodi di classe static, una classe nidificata statica non può fare riferimento direttamente a variabili di istanza o metodi definiti nella sua classe che li racchiude: può usarli solo attraverso un riferimento a un oggetto

Istanzia una classe nidificata statica allo stesso modo di una classe di primo livello:

```java
StaticNestedClass staticNestedObject = new StaticNestedClass();
```

### Esempio di classe interna e classe statica nidificata
L'esempio seguente, OuterClass, insieme a TopLevelClass, mostra a quali membri della classe di OuterClass possono accedere una classe interna (InnerClass), una classe statica nidificata (StaticNestedClass) e una classe di livello superiore (TopLevelClass):

OuterClass.java
```java
public class OuterClass {

    String outerField = "Outer field";
    static String staticOuterField = "Static outer field";

    class InnerClass {
        void accessMembers() {
            System.out.println(outerField);
            System.out.println(staticOuterField);
        }
    }

    static class StaticNestedClass {
        void accessMembers(OuterClass outer) {
            // Compiler error: Cannot make a static reference to the non-static
            //     field outerField
            // System.out.println(outerField);
            System.out.println(outer.outerField);
            System.out.println(staticOuterField);
        }
    }

    public static void main(String[] args) {
        System.out.println("Inner class:");
        System.out.println("------------");
        OuterClass outerObject = new OuterClass();
        OuterClass.InnerClass innerObject = outerObject.new InnerClass();
        innerObject.accessMembers();

        System.out.println("\nStatic nested class:");
        System.out.println("--------------------");
        StaticNestedClass staticNestedObject = new StaticNestedClass();        
        staticNestedObject.accessMembers(outerObject);
        
        System.out.println("\nTop-level class:");
        System.out.println("--------------------");
        TopLevelClass topLevelObject = new TopLevelClass();        
        topLevelObject.accessMembers(outerObject);                
    }
}
```

TopLevelClass.java
```java
public class TopLevelClass {

    void accessMembers(OuterClass outer) {     
        // Compiler error: Cannot make a static reference to the non-static
        //     field OuterClass.outerField
        // System.out.println(OuterClass.outerField);
        System.out.println(outer.outerField);
        System.out.println(OuterClass.staticOuterField);
    }  
}
```

Si noti che una classe nidificata statica interagisce con i membri di istanza della sua classe esterna proprio come qualsiasi altra classe di primo livello. La classe nidificata statica StaticNestedClass non può accedere direttamente a outerField perché è una variabile di istanza della classe di inclusione, OuterClass. Il compilatore Java genera un errore nell'istruzione evidenziata:
```java
static class StaticNestedClass {
    void accessMembers(OuterClass outer) {
       // Compiler error: Cannot make a static reference to the non-static
       //     field outerField
       **System.out.println(outerField);**
    }
}
```
Per correggere questo errore, accedi a externalField tramite un riferimento a un oggetto:
```java
System.out.println(outer.outerField);
```
Allo stesso modo, neanche la classe di primo livello TopLevelClass può accedere direttamente a outerField.

### Shadowing
Se una dichiarazione di un tipo (come una variabile membro o un nome di parametro) in un particolare ambito (come una classe interna o una definizione di metodo) ha lo stesso nome di un'altra dichiarazione nell'ambito di inclusione, la dichiarazione oscura la dichiarazione dell'ambito di inclusione. Non puoi fare riferimento a una dichiarazione ombreggiata solo con il suo nome. L'esempio seguente, ShadowTest, lo dimostra:
```java
public class ShadowTest {

    public int x = 0;

    class FirstLevel {

        public int x = 1;

        void methodInFirstLevel(int x) {
            System.out.println("x = " + x);
            System.out.println("this.x = " + this.x);
            System.out.println("ShadowTest.this.x = " + ShadowTest.this.x);
        }
    }

    public static void main(String... args) {
        ShadowTest st = new ShadowTest();
        ShadowTest.FirstLevel fl = st.new FirstLevel();
        fl.methodInFirstLevel(23);
    }
}
```
Questo esempio definisce tre variabili denominate x: la variabile membro della classe ShadowTest, la variabile membro della classe interna FirstLevel e il parametro nel metodo methodInFirstLevel. La variabile x definita come parametro del metodo methodInFirstLevel oscura la variabile della classe interna FirstLevel. Di conseguenza, quando si utilizza la variabile x nel metodo methodInFirstLevel, fa riferimento al parametro del metodo. Per fare riferimento alla variabile membro della classe interna FirstLevel, utilizzare la parola chiave this per rappresentare l'ambito di inclusione:
```java
System.out.println("this.x = " + this.x);
```
Fare riferimento alle variabili membro che racchiudono ambiti più grandi in base al nome della classe a cui appartengono. Ad esempio, la seguente istruzione accede alla variabile membro della classe ShadowTest dal metodo methodInFirstLevel:
```java
System.out.println("ShadowTest.this.x = " + ShadowTest.this.x);
```

### Serializzazione
La serializzazione delle classi interne, comprese le classi locali e anonime, è fortemente sconsigliata. Quando il compilatore Java compila determinati costrutti, come le classi interne, crea costrutti sintetici; si tratta di classi, metodi, campi e altri costrutti che non hanno un costrutto corrispondente nel codice sorgente. I costrutti sintetici consentono ai compilatori Java di implementare nuove funzionalità del linguaggio Java senza modifiche alla JVM. Tuttavia, i costrutti sintetici possono variare tra le diverse implementazioni del compilatore Java, il che significa che anche i file .class possono variare tra le diverse implementazioni. Di conseguenza, potresti avere problemi di compatibilità se serializzi una classe interna e poi la deserializzi con un'implementazione JRE diversa. Vedere la sezione Parametri impliciti e sintetici nella sezione Ottenere nomi di parametri di metodo per ulteriori informazioni sui costrutti sintetici generati quando viene compilata una classe interna.

### Esempio di Inner Class
Per vedere una classe interna in uso, considera prima un array. Nell'esempio seguente si crea una matrice, la si riempie con valori interi e quindi si generano solo i valori di indici pari della matrice in ordine crescente.

L'esempio DataStructure.java che segue è costituito da:

- La classe esterna di DataStructure, che include un costruttore per creare un'istanza di DataStructure contenente una matrice riempita con valori interi consecutivi (0, 1, 2, 3 e così via) e un metodo che stampa gli elementi della matrice che hanno un indice pari valore.
- La classe interna EvenIterator, che implementa l'interfaccia DataStructureIterator, che estende l'interfaccia Iterator< Integer>. Gli iteratori vengono utilizzati per scorrere una struttura di dati e in genere dispongono di metodi per verificare l'ultimo elemento, recuperare l'elemento corrente e passare all'elemento successivo.
- Un metodo principale che crea un'istanza di un oggetto DataStructure (ds), quindi richiama il metodo printEven per stampare gli elementi dell'array arrayOfInts che hanno un valore di indice pari.

```java
public class DataStructure {
    
    // Create an array
    private final static int SIZE = 15;
    private int[] arrayOfInts = new int[SIZE];
    
    public DataStructure() {
        // fill the array with ascending integer values
        for (int i = 0; i < SIZE; i++) {
            arrayOfInts[i] = i;
        }
    }
    
    public void printEven() {
        
        // Print out values of even indices of the array
        DataStructureIterator iterator = this.new EvenIterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
        System.out.println();
    }
    
    interface DataStructureIterator extends java.util.Iterator<Integer> { } 

    // Inner class implements the DataStructureIterator interface,
    // which extends the Iterator<Integer> interface
    
    private class EvenIterator implements DataStructureIterator {
        
        // Start stepping through the array from the beginning
        private int nextIndex = 0;
        
        public boolean hasNext() {
            
            // Check if the current element is the last in the array
            return (nextIndex <= SIZE - 1);
        }        
        
        public Integer next() {
            
            // Record a value of an even index of the array
            Integer retValue = Integer.valueOf(arrayOfInts[nextIndex]);
            
            // Get the next even element
            nextIndex += 2;
            return retValue;
        }
    }
    
    public static void main(String s[]) {
        
        // Fill the array with integer values and print out only
        // values of even indices
        DataStructure ds = new DataStructure();
        ds.printEven();
    }
}
```
Si noti che la classe EvenIterator fa riferimento direttamente alla variabile di istanza arrayOfInts dell'oggetto DataStructure.

È possibile utilizzare le classi interne per implementare classi helper come quella mostrata in questo esempio. Per gestire gli eventi dell'interfaccia utente, è necessario sapere come utilizzare le classi interne, poiché il meccanismo di gestione degli eventi ne fa ampio uso.

#### Classi locali e anonime
Ci sono due tipi aggiuntivi di classi interne. Puoi dichiarare una classe interna all'interno del corpo di un metodo. Queste classi sono conosciute come classi locali. Puoi anche dichiarare una classe interna all'interno del corpo di un metodo senza nominare la classe. Queste classi sono note come classi anonime.

#### Modificatori
Puoi usare gli stessi modificatori per le classi interne che usi per gli altri membri della classe esterna. Ad esempio, puoi utilizzare gli identificatori di accesso private, public e protected per limitare l'accesso alle classi interne, proprio come li usi per limitare l'accesso agli altri membri della classe.

#### Classi Locali
Puoi usare gli stessi modificatori per le classi interne che usi per gli altri membri della classe esterna. Ad esempio, puoi utilizzare gli identificatori di accesso private, public e protected per limitare l'accesso alle classi interne, proprio come li usi per limitare l'accesso agli altri membri della classe.

##### Dichiarare classi locali
È possibile definire una classe locale all'interno di qualsiasi blocco (consultare Espressioni, istruzioni e blocchi per ulteriori informazioni). Ad esempio, puoi definire una classe locale nel corpo di un metodo, un ciclo for o una clausola if.

L'esempio seguente, LocalClassExample, convalida due numeri di telefono. Definisce la classe locale PhoneNumber nel metodo validatePhoneNumber:
```java
public class LocalClassExample {
  
    static String regularExpression = "[^0-9]";
  
    public static void validatePhoneNumber(
        String phoneNumber1, String phoneNumber2) {
      
        final int numberLength = 10;
        
        // Valid in JDK 8 and later:
       
        // int numberLength = 10;
       
        class PhoneNumber {
            
            String formattedPhoneNumber = null;

            PhoneNumber(String phoneNumber){
                // numberLength = 7;
                String currentNumber = phoneNumber.replaceAll(
                  regularExpression, "");
                if (currentNumber.length() == numberLength)
                    formattedPhoneNumber = currentNumber;
                else
                    formattedPhoneNumber = null;
            }

            public String getNumber() {
                return formattedPhoneNumber;
            }
            
            // Valid in JDK 8 and later:

//            public void printOriginalNumbers() {
//                System.out.println("Original numbers are " + phoneNumber1 +
//                    " and " + phoneNumber2);
//            }
        }

        PhoneNumber myNumber1 = new PhoneNumber(phoneNumber1);
        PhoneNumber myNumber2 = new PhoneNumber(phoneNumber2);
        
        // Valid in JDK 8 and later:

//        myNumber1.printOriginalNumbers();

        if (myNumber1.getNumber() == null) 
            System.out.println("First number is invalid");
        else
            System.out.println("First number is " + myNumber1.getNumber());
        if (myNumber2.getNumber() == null)
            System.out.println("Second number is invalid");
        else
            System.out.println("Second number is " + myNumber2.getNumber());

    }

    public static void main(String... args) {
        validatePhoneNumber("123-456-7890", "456-7890");
    }
}
```

##### Accesso ai membri di una classe di inclusione
Una classe locale ha accesso ai membri della sua classe di inclusione. Nell'esempio precedente, il costruttore PhoneNumber accede al membro LocalClassExample.regularExpression.

Inoltre, una classe locale ha accesso alle variabili locali. Tuttavia, una classe locale può accedere solo a variabili locali dichiarate final. Quando una classe locale accede a una variabile locale oa un parametro del blocco che lo contiene, acquisisce tale variabile o parametro. Ad esempio, il costruttore PhoneNumber può accedere alla variabile locale numberLength perché è dichiarata final; numberLength è una variabile acquisita.

Tuttavia, a partire da Java SE 8, una classe locale può accedere a variabili e parametri locali del blocco che lo racchiude che sono final o effettivamente final. Una variabile o un parametro il cui valore non viene mai modificato dopo l'inizializzazione è effettivamente definitivo. Ad esempio, supponiamo che la variabile numberLength non sia dichiarata final e aggiungi l'istruzione di assegnazione evidenziata nel costruttore PhoneNumber per modificare la lunghezza di un numero di telefono valido a 7 cifre:
```java
PhoneNumber(String phoneNumber) {
    **numberLength = 7;**
    String currentNumber = phoneNumber.replaceAll(
        regularExpression, "");
    if (currentNumber.length() == numberLength)
        formattedPhoneNumber = currentNumber;
    else
        formattedPhoneNumber = null;
}
```
A causa di questa istruzione di assegnazione, la variabile numberLength non è più definitiva. Di conseguenza, il compilatore Java genera un messaggio di errore simile a "le variabili locali a cui fa riferimento una classe interna devono essere definitive o effettivamente finali" in cui la classe interna PhoneNumber tenta di accedere alla variabile numberLength:
```java
if (currentNumber.length() == numberLength)
```
A partire da Java SE 8, se dichiari la classe locale in un metodo, può accedere ai parametri del metodo. Ad esempio, puoi definire il seguente metodo nella classe locale PhoneNumber:
```java
public void printOriginalNumbers() {
    System.out.println("Original numbers are " + phoneNumber1 +
        " and " + phoneNumber2);
}
```

#### Le classi locali sono simili alle classi interne
Le classi locali sono simili alle classi interne perché non possono definire o dichiarare alcun membro statico. Le classi locali nei metodi statici, come la classe PhoneNumber, che è definita nel metodo statico validatePhoneNumber, possono fare riferimento solo ai membri statici della classe di inclusione. Ad esempio, se non si definisce la variabile membro regularExpression come statica, il compilatore Java genera un errore simile a "impossibile fare riferimento alla variabile non statica regularExpression da un contesto statico".

Le classi locali non sono statiche perché hanno accesso ai membri dell'istanza del blocco contenitore. Di conseguenza, non possono contenere la maggior parte dei tipi di dichiarazioni statiche.

Non puoi dichiarare un'interfaccia all'interno di un blocco; le interfacce sono intrinsecamente statiche. Ad esempio, il seguente estratto di codice non viene compilato perché l'interfaccia HelloThere è definita all'interno del corpo del metodo greetInEnglish:
```java
public void greetInEnglish() {
        interface HelloThere {
           public void greet();
        }
        class EnglishHelloThere implements HelloThere {
            public void greet() {
                System.out.println("Hello " + name);
            }
        }
        HelloThere myGreeting = new EnglishHelloThere();
        myGreeting.greet();
    }
```
Non è possibile dichiarare inizializzatori statici o interfacce membro in una classe locale. Il seguente estratto di codice non viene compilato perché il metodo EnglishGoodbye.sayGoodbye è dichiarato statico. Il compilatore genera un errore simile a "il modificatore 'static' è consentito solo nella dichiarazione di variabile costante" quando incontra questa definizione di metodo:
```java
public void sayGoodbyeInEnglish() {
        class EnglishGoodbye {
            public static void sayGoodbye() {
                System.out.println("Bye bye");
            }
        }
        EnglishGoodbye.sayGoodbye();
    }
```
Una classe locale può avere membri statici purché siano variabili costanti. (Una variabile costante è una variabile di tipo primitivo o di tipo String dichiarata final e inizializzata con un'espressione costante in fase di compilazione. Un'espressione costante in fase di compilazione è in genere una stringa o un'espressione aritmetica che può essere valutata in fase di compilazione. Vedere Comprensione dei membri della classe per ulteriori informazioni.) Il seguente estratto di codice viene compilato perché il membro statico EnglishGoodbye.farewell è una variabile costante:
```java
public void sayGoodbyeInEnglish() {
        class EnglishGoodbye {
            public static final String farewell = "Bye bye";
            public void sayGoodbye() {
                System.out.println(farewell);
            }
        }
        EnglishGoodbye myEnglishGoodbye = new EnglishGoodbye();
        myEnglishGoodbye.sayGoodbye();
    }
```

