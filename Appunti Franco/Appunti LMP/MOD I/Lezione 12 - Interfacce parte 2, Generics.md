# Ritornando a [[Lezione 10 - Interfacce Parte 1#Interfacce ed ereditarietà|Lezione 10 - Interfacce]]

## Interfacce in evoluzione

Considera un'interfaccia che hai sviluppato chiamata DoIt:

```java
public interface DoIt {
   void doSomething(int i, double x);
   int doSomethingElse(String s);
}
```

Supponiamo che, in un secondo momento, vogliate aggiungere un terzo metodo a DoIt, in modo che l'interfaccia diventi ora:

```java
public interface DoIt {

   void doSomething(int i, double x);
   int doSomethingElse(String s);
   boolean didItWork(int i, double x, String s);
   
}
```

Se apporti questa modifica, tutte le classi che implementano la vecchia interfaccia DoIt si interromperanno perché non implementano più la vecchia interfaccia. I programmatori che si affidano a questa interfaccia protesteranno ad alta voce.

Prova ad anticipare tutti gli usi per la tua interfaccia e specificala completamente dall'inizio. Se vuoi aggiungere altri metodi a un'interfaccia, hai diverse opzioni. Potresti creare un'interfaccia DoItPlus che estenda DoIt:

```java
public interface DoItPlus extends DoIt {

   boolean didItWork(int i, double x, String s);
   
}
```

Ora gli utenti del tuo codice possono scegliere di continuare a utilizzare la vecchia interfaccia o eseguire l'upgrade alla nuova interfaccia.

In alternativa, puoi definire i tuoi nuovi metodi come metodi predefiniti. L'esempio seguente definisce un [[Lezione 12 - Interfacce parte 2, Generics#Metodi predefiniti|metodo predefinito]] denominato didItWork:

```java
public interface DoIt {

   void doSomething(int i, double x);
   int doSomethingElse(String s);
   **default boolean didItWork(int i, double x, String s) {
       // Method body 
   }**
   
}
```

Si noti che è necessario fornire un'implementazione per i metodi predefiniti. È inoltre possibile definire nuovi [[Lezione 12 - Interfacce parte 2, Generics#Metodi statici|metodi statici]] per le interfacce esistenti. Gli utenti che dispongono di classi che implementano interfacce migliorate con nuovi metodi predefiniti o statici non devono modificarle o ricompilarle per adattarle ai metodi aggiuntivi.

## Metodi predefiniti

La sezione Interfacce descrive un esempio che coinvolge produttori di auto controllate da computer che pubblicano interfacce standard del settore che descrivono quali metodi possono essere invocati per far funzionare le proprie auto. E se quelle case automobilistiche controllate da computer aggiungessero nuove funzionalità, come il volo, alle loro auto? Questi produttori dovrebbero specificare nuovi metodi per consentire ad altre società (come i produttori di strumenti di guida elettronica) di adattare il loro software alle auto volanti. Dove dichiarerebbero queste case automobilistiche questi nuovi metodi relativi al volo? Se li aggiungono alle loro interfacce originali, i programmatori che hanno implementato tali interfacce dovrebbero riscrivere le loro implementazioni. Se li aggiungono come metodi statici, i programmatori li considererebbero come metodi di utilità, non come metodi di base essenziali.

I metodi predefiniti consentono di aggiungere nuove funzionalità alle interfacce delle librerie e garantiscono la compatibilità binaria con il codice scritto per le versioni precedenti di tali interfacce.

Si consideri la seguente interfaccia, TimeClient:

```java
import java.time.*; 
 
public interface TimeClient {
    void setTime(int hour, int minute, int second);
    void setDate(int day, int month, int year);
    void setDateAndTime(int day, int month, int year,
                               int hour, int minute, int second);
    LocalDateTime getLocalDateTime();
}
```

La seguente classe, SimpleTimeClient, implementa TimeClient:

```java
package defaultmethods;

import java.time.*;
import java.lang.*;
import java.util.*;

public class SimpleTimeClient implements TimeClient {
    
    private LocalDateTime dateAndTime;
    
    public SimpleTimeClient() {
        dateAndTime = LocalDateTime.now();
    }
    
    public void setTime(int hour, int minute, int second) {
        LocalDate currentDate = LocalDate.from(dateAndTime);
        LocalTime timeToSet = LocalTime.of(hour, minute, second);
        dateAndTime = LocalDateTime.of(currentDate, timeToSet);
    }
    
    public void setDate(int day, int month, int year) {
        LocalDate dateToSet = LocalDate.of(day, month, year);
        LocalTime currentTime = LocalTime.from(dateAndTime);
        dateAndTime = LocalDateTime.of(dateToSet, currentTime);
    }
    
    public void setDateAndTime(int day, int month, int year,
                               int hour, int minute, int second) {
        LocalDate dateToSet = LocalDate.of(day, month, year);
        LocalTime timeToSet = LocalTime.of(hour, minute, second); 
        dateAndTime = LocalDateTime.of(dateToSet, timeToSet);
    }
    
    public LocalDateTime getLocalDateTime() {
        return dateAndTime;
    }
    
    public String toString() {
        return dateAndTime.toString();
    }
    
    public static void main(String... args) {
        TimeClient myTimeClient = new SimpleTimeClient();
        System.out.println(myTimeClient.toString());
    }
}
```

Supponiamo di voler aggiungere nuove funzionalità all'interfaccia TimeClient, come la possibilità di specificare un fuso orario tramite un oggetto ZonedDateTime (che è simile a un oggetto LocalDateTime tranne per il fatto che memorizza le informazioni sul fuso orario):

```java
public interface TimeClient {
    void setTime(int hour, int minute, int second);
    void setDate(int day, int month, int year);
    void setDateAndTime(int day, int month, int year,
        int hour, int minute, int second);
    LocalDateTime getLocalDateTime();                           
    **ZonedDateTime getZonedDateTime(String zoneString);**
}
```

Dopo questa modifica all'interfaccia TimeClient, dovresti anche modificare la classe SimpleTimeClient e implementare il metodo getZonedDateTime. Tuttavia, invece di lasciare getZonedDateTime come astratto (come nell'esempio precedente), è invece possibile definire un'implementazione predefinita. (Ricorda che un metodo astratto è un metodo dichiarato senza un'implementazione.)

```java
package defaultmethods;
 
import java.time.*;

public interface TimeClient {
    void setTime(int hour, int minute, int second);
    void setDate(int day, int month, int year);
    void setDateAndTime(int day, int month, int year,
                               int hour, int minute, int second);
    LocalDateTime getLocalDateTime();
    
    static ZoneId getZoneId (String zoneString) {
        try {
            return ZoneId.of(zoneString);
        } catch (DateTimeException e) {
            System.err.println("Invalid time zone: " + zoneString +
                "; using default time zone instead.");
            return ZoneId.systemDefault();
        }
    }
        
    default ZonedDateTime getZonedDateTime(String zoneString) {
        return ZonedDateTime.of(getLocalDateTime(), getZoneId(zoneString));
    }
}
```

Si specifica che una definizione di metodo in un'interfaccia è un metodo predefinito con la parola chiave predefinita all'inizio della firma del metodo. Tutte le dichiarazioni di metodo in un'interfaccia, inclusi i metodi predefiniti, sono implicitamente pubbliche, pertanto è possibile omettere il modificatore public.

Con questa interfaccia, non è necessario modificare la classe SimpleTimeClient, e questa classe (e qualsiasi classe che implementa l'interfaccia TimeClient), avrà il metodo getZonedDateTime già definito. L'esempio seguente, TestSimpleTimeClient, richiama il metodo getZonedDateTime da un'istanza di SimpleTimeClient

```java
package defaultmethods;
 
import java.time.*;
import java.lang.*;
import java.util.*;

public class TestSimpleTimeClient {
    public static void main(String... args) {
        TimeClient myTimeClient = new SimpleTimeClient();
        System.out.println("Current time: " + myTimeClient.toString());
        System.out.println("Time in California: " +
            myTimeClient.getZonedDateTime("Blah blah").toString());
    }
}
```

### Estensione di interfacce che contengono metodi predefiniti

Quando estendi un'interfaccia che contiene un metodo predefinito, puoi eseguire le seguenti operazioni:

- Non menzionare affatto il metodo predefinito, che consente alla tua interfaccia estesa di ereditare il metodo predefinito.
- Ridichiarare il metodo predefinito, che lo rende astratto.
- Ridefinire il metodo predefinito, che lo sovrascrive.

Supponiamo di estendere l'interfaccia TimeClient come segue:

```java
public interface AnotherTimeClient extends TimeClient { }
```

Qualsiasi classe che implementa l'interfaccia AnotherTimeClient avrà l'implementazione specificata dal metodo predefinito TimeClient.getZonedDateTime.

Supponiamo di estendere l'interfaccia TimeClient come segue:

```java
public interface AbstractZoneTimeClient extends TimeClient {
    public ZonedDateTime getZonedDateTime(String zoneString);
}
```

Qualsiasi classe che implementa l'interfaccia AbstractZoneTimeClient dovrà implementare il metodo getZonedDateTime; questo metodo è un metodo astratto come tutti gli altri metodi non predefiniti (e non statici) in un'interfaccia.

Supponiamo di estendere l'interfaccia TimeClient come segue:

```java
public interface HandleInvalidTimeZoneClient extends TimeClient {
    default public ZonedDateTime getZonedDateTime(String zoneString) {
        try {
            return ZonedDateTime.of(getLocalDateTime(),ZoneId.of(zoneString)); 
        } catch (DateTimeException e) {
            System.err.println("Invalid zone ID: " + zoneString +
                "; using the default time zone instead.");
            return ZonedDateTime.of(getLocalDateTime(),ZoneId.systemDefault());
        }
    }
}
```

Qualsiasi classe che implementa l'interfaccia HandleInvalidTimeZoneClient utilizzerà l'implementazione di getZonedDateTime specificata da questa interfaccia invece di quella specificata dall'interfaccia TimeClient.

### Metodi statici

Oltre ai metodi predefiniti, è possibile definire [[Lezione 6 - Classi#Metodi della classe|metodi statici]] nelle interfacce. (Un metodo statico è un metodo associato alla classe in cui è definito piuttosto che a qualsiasi oggetto. Ogni istanza della classe condivide i suoi metodi statici.) Ciò semplifica l'organizzazione dei metodi di supporto nelle librerie; puoi mantenere metodi statici specifici per un'interfaccia nella stessa interfaccia piuttosto che in una classe separata. L'esempio seguente definisce un metodo statico che recupera un oggetto ZoneId corrispondente a un identificatore di fuso orario; utilizza il fuso orario predefinito del sistema se non esiste alcun oggetto ZoneId corrispondente all'identificatore specificato. (Di conseguenza, puoi semplificare il metodo getZonedDateTime):

```java
public interface TimeClient {
    // ...
    static public ZoneId getZoneId (String zoneString) {
        try {
            return ZoneId.of(zoneString);
        } catch (DateTimeException e) {
            System.err.println("Invalid time zone: " + zoneString +
                "; using default time zone instead.");
            return ZoneId.systemDefault();
        }
    }

    default public ZonedDateTime getZonedDateTime(String zoneString) {
        return ZonedDateTime.of(getLocalDateTime(), getZoneId(zoneString));
    }    
}
```

Analogamente ai metodi statici nelle classi, si specifica che una definizione di metodo in un'interfaccia è un metodo statico con la parola chiave static all'inizio della firma del metodo. Tutte le dichiarazioni di metodo in un'interfaccia, inclusi i metodi statici, sono implicitamente pubbliche, pertanto è possibile omettere il modificatore public.

# Ereditarietà

>[!important]- Definizione
>Una classe derivata da un'altra classe è chiamata sottoclasse (anche classe derivata, classe estesa o classe figlia). La classe da cui deriva la sottoclasse è chiamata superclasse (anche classe base o classe genitore).
>Ad eccezione di Object, che non ha superclasse, ogni classe ha una e una sola superclasse diretta (eredità singola). In assenza di qualsiasi altra superclasse esplicita, ogni classe è implicitamente una sottoclasse di Object.
>Le classi possono essere derivate da classi derivate da classi derivate da classi e così via, e infine derivate dalla classe più in alto, Object. Si dice che una tale classe discenda da tutte le classi nella catena di ereditarietà che risale a Object.

L'idea dell'ereditarietà è semplice ma potente: quando vuoi creare una nuova classe ed esiste già una classe che include parte del codice che desideri, puoi derivare la tua nuova classe dalla classe esistente. In questo modo, puoi riutilizzare i campi ei metodi della classe esistente senza doverli scrivere (ed eseguire il debug!) da soli.

Una sottoclasse eredita tutti i membri (campi, metodi e classi nidificate) dalla sua superclasse. I costruttori non sono membri, quindi non vengono ereditati dalle sottoclassi, ma il costruttore della superclasse può essere richiamato dalla sottoclasse.

## Ereditarietà multipla di stato, implementazione e tipo

Una differenza significativa tra classi e interfacce è che le classi possono avere campi mentre le interfacce no. Inoltre, puoi istanziare una classe per creare un oggetto, cosa che non puoi fare con le interfacce. Come spiegato nella sezione Cos'è un oggetto?, un oggetto memorizza il suo stato in campi, che sono definiti in classi. Uno dei motivi per cui il linguaggio di programmazione Java non consente di estendere più di una classe è evitare i problemi di ereditarietà multipla dello stato, ovvero la possibilità di ereditare campi da più classi. Si supponga, ad esempio, di poter definire una nuova classe che estenda più classi. Quando crei un oggetto istanziando quella classe, quell'oggetto erediterà i campi da tutte le superclassi della classe. Cosa succede se metodi o costruttori di diverse superclassi istanziano lo stesso campo? Quale metodo o costruttore avrà la precedenza? Poiché le interfacce non contengono campi, non è necessario preoccuparsi dei problemi derivanti dall'ereditarietà multipla dello stato.

L'ereditarietà multipla dell'implementazione è la capacità di ereditare le definizioni dei metodi da più classi. I problemi sorgono con questo tipo di ereditarietà multipla, come i conflitti di nome e l'ambiguità. Quando i compilatori di linguaggi di programmazione che supportano questo tipo di ereditarietà multipla incontrano superclassi che contengono metodi con lo stesso nome, a volte non sono in grado di determinare a quale membro o metodo accedere o richiamare. Inoltre, un programmatore può involontariamente introdurre un conflitto di nomi aggiungendo un nuovo metodo a una superclasse. I metodi predefiniti introducono una forma di ereditarietà multipla dell'implementazione. Una classe può implementare più di un'interfaccia, che può contenere metodi predefiniti con lo stesso nome. Il compilatore Java fornisce alcune regole per determinare quale metodo predefinito utilizza una particolare classe.

Il linguaggio di programmazione Java supporta l'ereditarietà multipla del tipo, ovvero la capacità di una classe di implementare più di un'interfaccia. Un oggetto può avere più tipi: il tipo della propria classe ei tipi di tutte le interfacce implementate dalla classe. Ciò significa che se una variabile viene dichiarata essere il tipo di un'interfaccia, il suo valore può fare riferimento a qualsiasi oggetto istanziato da qualsiasi classe che implementa l'interfaccia. Questo è discusso nella sezione Utilizzo di un'interfaccia come tipo.

Come per l'ereditarietà multipla dell'implementazione, una classe può ereditare diverse implementazioni di un metodo definito (come predefinito o statico) nelle interfacce che estende. In questo caso, il compilatore o l'utente deve decidere quale utilizzare.

## Scrivere classi e metodi finali

Puoi dichiarare alcuni o tutti i metodi di una classe final. Si utilizza la parola chiave final in una dichiarazione di metodo per indicare che il metodo non può essere sovrascritto dalle sottoclassi. La classe Object fa questo: molti dei suoi metodi sono definitivi.

Potresti voler rendere definitivo un metodo se ha un'implementazione che non deve essere modificata ed è fondamentale per lo stato coerente dell'oggetto. Ad esempio, potresti voler rendere finale il metodo getFirstPlayer in questa classe ChessAlgorithm:

```java
class ChessAlgorithm {
    enum ChessPlayer { WHITE, BLACK }
    ...
    **final** ChessPlayer getFirstPlayer() {
        return ChessPlayer.WHITE;
    }
    ...
}
```

I metodi chiamati dai costruttori dovrebbero generalmente essere dichiarati final. Se un costruttore chiama un metodo non finale, una sottoclasse può ridefinire quel metodo con risultati sorprendenti o indesiderati.

Nota che puoi anche dichiarare finale un'intera classe. Una classe dichiarata final non può essere sottoclasse. Ciò è particolarmente utile, ad esempio, quando si crea una classe immutabile come la classe String.

# Generics

>[!cite]- Osservazione
>sono un modo per parametrizzare l'interzione con altre classi

In qualsiasi progetto software non banale, i bug sono semplicemente un dato di fatto. Un'attenta pianificazione, programmazione e test possono aiutare a ridurre la loro pervasività, ma in qualche modo, da qualche parte, troveranno sempre un modo per insinuarsi nel tuo codice. Ciò diventa particolarmente evidente quando vengono introdotte nuove funzionalità e la tua base di codice cresce in dimensioni e complessità.

Fortunatamente, alcuni bug sono più facili da rilevare rispetto ad altri. I bug in fase di compilazione, ad esempio, possono essere rilevati in anticipo; puoi usare i messaggi di errore del compilatore per capire qual è il problema e risolverlo, subito e lì. I bug di runtime, tuttavia, possono essere molto più problematici; non sempre emergono immediatamente e, quando lo fanno, potrebbe essere in un punto del programma molto lontano dalla vera causa del problema.

I generics aggiungono stabilità al tuo codice rendendo più rilevabili i tuoi bug in fase di compilazione

## Perchè usare i generics?

In poche parole, i generici consentono ai tipi (classi e interfacce) di essere parametri durante la definizione di classi, interfacce e metodi. Proprio come i parametri formali più familiari utilizzati nelle dichiarazioni di metodo, i parametri di tipo forniscono un modo per riutilizzare lo stesso codice con input diversi. La differenza è che gli input ai parametri formali sono valori, mentre gli input ai parametri di tipo sono tipi.

Il codice che utilizza i generici ha molti vantaggi rispetto al codice non generico:

- Controlli di tipo più forti in fase di compilazione.Un compilatore Java applica un forte controllo del tipo al codice generico e genera errori se il codice viola l'indipendenza dai tipi. Correggere gli errori in fase di compilazione è più semplice che correggere gli errori di runtime, che possono essere difficili da trovare.

- Eliminazione dei cast. Il seguente frammento di codice senza generici richiede il casting
```java
List list = new ArrayList();
list.add("hello");
String s = **(String)** list.get(0);
```
Quando viene riscritto per utilizzare i generici, il codice non richiede il casting:
```java
List<String> list = new ArrayList<String>();
list.add("hello");
String s = list.get(0);   // no cast
```
- Consentire ai programmatori di implementare algoritmi generici. Utilizzando i generici, i programmatori possono implementare algoritmi generici che funzionano su raccolte di tipi diversi, possono essere personalizzati e sono indipendenti dai tipi e più facili da leggere.

## Tipi generici

Un tipo generico è una classe o un'interfaccia generica parametrizzata sui tipi. La seguente classe Box verrà modificata per illustrare il concetto.

### Una semplice classe Box

Inizia esaminando una classe Box non generica che opera su oggetti di qualsiasi tipo. Deve solo fornire due metodi: set, che aggiunge un oggetto alla scatola, e get, che lo recupera:

```java
public class Box {
    private Object object;

    public void set(Object object) { this.object = object; }
    public Object get() { return object; }
}
```

Poiché i suoi metodi accettano o restituiscono un oggetto, sei libero di passare quello che vuoi, a condizione che non sia uno dei tipi primitivi. Non c'è modo di verificare, in fase di compilazione, come viene utilizzata la classe. Una parte del codice potrebbe inserire un numero intero nella casella e aspettarsi di estrarre numeri interi da esso, mentre un'altra parte del codice potrebbe passare erroneamente una stringa, provocando un errore di runtime.

### Una versione generica della classe Box

Una **classe generica** è definita con il seguente formato:
```java
class name<T1, T2, ..., Tn> { /* ... */ }
```

La sezione del parametro di tipo, delimitata da parentesi angolari (<>), segue il nome della classe. Specifica i parametri di tipo (chiamati anche variabili di tipo) T1, T2, ... e Tn.

Per aggiornare la classe Box in modo che utilizzi generici, creare una dichiarazione di tipo generico modificando il codice ``"public class Box"`` in ``"public class Box<T>"``. Questo introduce la variabile di tipo, T, che può essere utilizzata ovunque all'interno della classe.

Con questa modifica la classe Box diventa:
```java
/**
 * Generic version of the Box class.
 * @param <T> the type of the value being boxed
 */
public class Box<T> {
    // T stands for "Type"
    private T t;

    public void set(T t) { this.t = t; }
    public T get() { return t; }
}
```

Come puoi vedere, tutte le occorrenze di Object vengono sostituite da T. Una variabile di tipo può essere qualsiasi tipo non primitivo specificato: qualsiasi tipo di classe, qualsiasi tipo di interfaccia, qualsiasi tipo di array o anche un'altra variabile di tipo.

Questa stessa tecnica può essere applicata per creare interfacce generiche.

### Convenzioni per il nominativo dei tipi

Per convenzione, i nomi dei parametri di tipo sono lettere maiuscole singole. Ciò è in netto contrasto con le convenzioni di denominazione delle variabili che già conosci, e con buone ragioni: senza questa convenzione, sarebbe difficile distinguere tra una variabile di tipo e un normale nome di classe o interfaccia.

I nomi dei parametri di tipo più comunemente utilizzati sono:

- E - Element (utilizzato ampiamente da Java Collections Framework)
- K - Chiave
- N - Numero
- T - Tipo
- V - Valore
- S,U,V ecc. - 2°, 3°, 4° tipo

### Invocazione e istanziazione di un tipo generico

Per fare riferimento alla classe Box generica dall'interno del codice, è necessario eseguire un'invocazione di tipo generico, che sostituisce T con un valore concreto, ad esempio Integer:

```java
Box<Integer> integerBox;
```

Puoi pensare a un'invocazione di tipo generico come simile a un'invocazione di metodo ordinaria, ma invece di passare un argomento a un metodo, stai passando un argomento di tipo, Integer in questo caso, alla stessa classe Box.

Come qualsiasi altra dichiarazione di variabile, questo codice in realtà non crea un nuovo oggetto Box. Dichiara semplicemente che integerBox manterrà un riferimento a un "Box of Integer", che è il modo in cui ``Box<Integer>`` viene letto.

Una chiamata di un tipo generico è generalmente nota come tipo con parametri.

Per istanziare questa classe, usa la parola chiave new, come al solito, ma inserisci ``<Integer>`` tra il nome della classe e la parentesi:

```java
Box<Integer> integerBox = new Box<Integer>();
```

### Il Diamante

In Java SE 7 e versioni successive, è possibile sostituire gli argomenti di tipo richiesti per richiamare il costruttore di una classe generica con un set vuoto di argomenti di tipo (<>) purché il compilatore possa determinare o dedurre gli argomenti di tipo dal contesto . Questa coppia di parentesi angolari, <>, è chiamata informalmente il **diamante**. Ad esempio, puoi creare un'istanza di ``Box<Integer>`` con la seguente istruzione:

```java
Box<Integer> integerBox = new Box<>();
```

### Parametri di tipo multiplo

Come accennato in precedenza, una classe generica può avere più parametri di tipo. Ad esempio, la classe generica OrderedPair, che implementa l'interfaccia generica Pair:

```java
public interface Pair<K, V> {
    public K getKey();
    public V getValue();
}

public class OrderedPair<K, V> implements Pair<K, V> {

    private K key;
    private V value;

    public OrderedPair(K key, V value) {
	this.key = key;
	this.value = value;
    }

    public K getKey()	{ return key; }
    public V getValue() { return value; }
}
```

Le seguenti istruzioni creano due istanze della classe OrderedPair:

```java
Pair<String, Integer> p1 = new OrderedPair<String, Integer>("Even", 8);
Pair<String, String>  p2 = new OrderedPair<String, String>("hello", "world");
```

Il codice, new OrderedPair<String, Integer>, istanzia K come String e V come Integer. Pertanto, i tipi di parametro del costruttore di OrderedPair sono rispettivamente String e Integer. A causa dell'autoboxing, è valido passare una stringa e un int alla classe.

Come accennato in The Diamond, poiché un compilatore Java può dedurre i tipi K e V dalla dichiarazione OrderedPair<String, Integer>, queste istruzioni possono essere abbreviate utilizzando la notazione a diamante:

```java
OrderedPair<String, Integer> p1 = new OrderedPair**<>**("Even", 8);
OrderedPair<String, String>  p2 = new OrderedPair**<>**("hello", "world");
```

### Tipi parametrizzati

È inoltre possibile sostituire un parametro di tipo (ovvero K o V) con un tipo con parametri (ovvero ``List<String>``). Ad esempio, utilizzando l'esempio OrderedPair<K, V>:

```java
OrderedPair<String, **Box<Integer>**> p = new OrderedPair<>("primes", new Box<Integer>(...));
```

## Tipi Raw

Un tipo non elaborato (Raw) è il nome di una classe o interfaccia generica senza argomenti di tipo. Ad esempio, data la generica classe Box:

```java
public class Box<T> {
    public void set(T t) { /* ... */ }
    // ...
}
```

Per creare un tipo parametrico di ``Box<T>``, fornire un argomento di tipo effettivo per il parametro di tipo formale T:
```java
Box<Integer> intBox = new Box<>();
```

Se l'argomento del tipo effettivo viene omesso, crei un tipo non elaborato di ``Box<T>``:
```java
Box rawBox = new Box();
```

Pertanto, Box è il tipo non elaborato del tipo generico ``Box<T>``. Tuttavia, una classe non generica o un tipo di interfaccia non è un tipo non elaborato.

I tipi non elaborati vengono visualizzati nel codice legacy perché molte classi API (come le classi Collections) non erano generiche prima di JDK 5.0. Quando usi i tipi non elaborati, ottieni essenzialmente un comportamento pre-generico: una scatola ti dà oggetti. Per compatibilità con le versioni precedenti, è consentito assegnare un tipo con parametri al relativo tipo non elaborato:

```java
Box<String> stringBox = new Box<>();
Box rawBox = stringBox;               // OK
```

Ma se assegni un tipo non elaborato a un tipo parametrizzato, ricevi un avviso:

```java
Box rawBox = new Box(); // rawBox è un tipo non elaborato di Box<T>
Box<Integer> intBox = rawBox; // avviso: conversione non verificata
```

Ricevi anche un avviso se usi un tipo non elaborato per richiamare metodi generici definiti nel tipo generico corrispondente:

```java
Box<String> stringBox = new Box<>();
Box rawBox = stringBox;
rawBox.set(8);  // warning: unchecked invocation to set(T)
```

## Metodi generici

I metodi generici sono metodi che introducono i propri parametri di tipo. È simile alla dichiarazione di un tipo generico, ma l'ambito del parametro di tipo è limitato al metodo in cui è dichiarato. Sono consentiti metodi generici statici e non statici, nonché costruttori di classi generiche.

La sintassi per un metodo generico include un elenco di parametri di tipo, all'interno di parentesi angolari, che viene visualizzato prima del tipo restituito del metodo. Per i metodi generici statici, la sezione del parametro di tipo deve essere visualizzata prima del tipo restituito del metodo.

La classe Util include un metodo generico, compare, che confronta due oggetti Pair:

```java
public class Util {
    **public static <K, V> boolean compare(Pair<K, V> p1, Pair<K, V> p2)** {
        return p1.getKey().equals(p2.getKey()) &&
               p1.getValue().equals(p2.getValue());
    }
}

public class Pair<K, V> {

    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public void setKey(K key) { this.key = key; }
    public void setValue(V value) { this.value = value; }
    public K getKey()   { return key; }
    public V getValue() { return value; }
}
```

La sintassi completa per invocare questo metodo sarebbe:

```java
Pair<Integer, String> p1 = new Pair<>(1, "apple");
Pair<Integer, String> p2 = new Pair<>(2, "pear");
boolean same = Util.**<Integer, String>**compare(p1, p2);
```

Il tipo è stato fornito in modo esplicito, come mostrato in grassetto. In genere, questo può essere omesso e il compilatore dedurrà il tipo necessario:

```java
Pair<Integer, String> p1 = new Pair<>(1, "apple");
Pair<Integer, String> p2 = new Pair<>(2, "pear");
boolean same = Util.compare(p1, p2);
```

Questa funzionalità, nota come inferenza del tipo, consente di invocare un metodo generico come metodo ordinario, senza specificare un tipo tra parentesi angolari