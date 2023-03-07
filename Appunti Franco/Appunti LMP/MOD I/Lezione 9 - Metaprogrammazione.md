# Annotazioni

Le annotazioni, una forma di metadati, forniscono dati su un programma che non fa parte del programma stesso. Le annotazioni non hanno alcun effetto diretto sul funzionamento del codice che annotano.

Le annotazioni hanno una serie di usi, tra cui:

- **Informazioni per il compilatore**: le annotazioni possono essere utilizzate dal compilatore per rilevare errori o sopprimere avvisi.
- **Elaborazione in fase di compilazione e distribuzione**: gli strumenti software possono elaborare le informazioni di annotazione per generare codice, file XML e così via.
- **Elaborazione in fase di esecuzione**: alcune annotazioni sono disponibili per essere esaminate in fase di esecuzione.

Questa lezione spiega dove è possibile utilizzare le annotazioni, come applicare le annotazioni, quali tipi di annotazioni predefiniti sono disponibili nella piattaforma Java, Standard Edition (API Java SE), in che modo le annotazioni di tipo possono essere utilizzate insieme a sistemi di tipi collegabili per scrivere codice con maggiore controllo del tipo e come implementare le annotazioni ripetute.

## Nozioni di base sulle annotazioni

### Formato di un annotazione
Nella sua forma più semplice, un'annotazione ha il seguente aspetto:
```java
@Entity
```

Il carattere di chiocciola (@) indica al compilatore che ciò che segue è un'annotazione. Nell'esempio seguente, il nome dell'annotazione è Override:
```java
@Override
void mySuperMetod() { ... }
```

L'annotazione può includere elementi, che possono essere nominati o senza nome, e ci sono valori per questi elementi:

```java
@Author(
   name = "Benjamin Franklin",
   date = "3/27/2003"
)
class MyClass { ... }
```

Oppure:
```java
@SuppressWarnings(value = "unchecked")
void myMethod() { ... }
```

Se c'è un solo elemento denominato valore, allora il nome può essere omesso, come in:
```java
@SuppressWarnings("unchecked")
void myMetod() { ... }
```

Se l'annotazione non ha elementi, le parentesi possono essere omesse, come mostrato nell'esempio precedente di @Override.

È anche possibile utilizzare più annotazioni sulla stessa dichiarazione:
```java
@Author(name = "Jane Doe")
@EBook
class MyClass { ... }
```

Se le annotazioni hanno lo stesso tipo, si parla di annotazione ripetuta:
```java
@Author(name = "Jane Doe")
@Author(name = "John Smith")
class MyClass { ... }
```

Il tipo di annotazione può essere uno dei tipi definiti nei pacchetti java.lang o java.lang.annotation dell'API Java SE. Negli esempi precedenti, Override e SuppressWarnings sono annotazioni Java predefinite. È anche possibile definire il proprio tipo di annotazione. Le annotazioni Autore ed Ebook nell'esempio precedente sono tipi di annotazione personalizzati.

### Dove possono essere utilizzate le annotazioni

Le annotazioni possono essere applicate alle dichiarazioni: dichiarazioni di classi, campi, metodi e altri elementi del programma. Quando viene utilizzata su una dichiarazione, ogni annotazione appare spesso, per convenzione, su una propria riga.

A partire dalla versione Java SE 8, le annotazioni possono essere applicate anche all'uso dei tipi. Ecco alcuni esempi:

- Espressione di creazione dell'istanza di classe:
```java
new @Interned MyObject();
```
- Tipo cast:
```java
myString = (@StringaNonNull) str;
```
- clausola _implements_:
```java
class UnmodifiableList<T> implements
    @Readonly List<@Readonly T> { ... }
```
- Dichiarazione di eccezione generata:
```java
void monitorTemperature() lancia
    @Critical TemperatureException { ... }
```

Questa forma di annotazione è chiamata annotazione di tipo (_type annotation_).

## Dichiarare un tipo di annotazione

Molte annotazioni sostituiscono i commenti nel codice.

Supponiamo che un gruppo di software tradizionalmente inizi il corpo di ogni classe con commenti che forniscono informazioni importanti:
```java
public class Generation3List extends Generation2List {

   // Author: John Doe
   // Date: 3/17/2002
   // Current revision: 6
   // Last modified: 4/12/2004
   // By: Jane Doe
   // Reviewers: Alice, Bill, Cindy

   // class code goes here

}
```
Per aggiungere questi stessi metadati con un'annotazione, devi prima definire il tipo di annotazione. La sintassi per farlo è:
```java
@interface ClassPreamble {
   String author();
   String date();
   int currentRevision() default 1;
   String lastModified() default "N/A";
   String lastModifiedBy() default "N/A";
   // Note use of array
   String[] reviewers();
}
```

La definizione del tipo di annotazione è simile a una definizione di interfaccia in cui la parola chiave interface è preceduta dal simbolo di chiocciola (@) (@ = AT, come nel tipo di annotazione). I tipi di annotazione sono una forma di interfaccia, che verrà trattata in una lezione successiva. Per il momento, non è necessario comprendere le interfacce.

Il corpo della precedente definizione di annotazione contiene dichiarazioni di elementi del tipo di annotazione (_annotation type element_ declarations), che assomigliano molto ai metodi. Si noti che possono definire valori predefiniti facoltativi.

Dopo aver definito il tipo di annotazione, puoi utilizzare annotazioni di quel tipo, con i valori inseriti, in questo modo:

```java
@ClassPreamble (
   author = "John Doe",
   date = "3/17/2002",
   currentRevision = 6,
   lastModified = "4/12/2004",
   lastModifiedBy = "Jane Doe",
   // Note array notation
   reviewers = {"Alice", "Bob", "Cindy"}
)
public class Generation3List extends Generation2List {

// class code goes here

}
```

**Nota**: per visualizzare le informazioni in @ClassPreamble nella documentazione generata da Javadoc, è necessario annotare la definizione @ClassPreamble con l'annotazione @Documented:
```java
// import this to use `@Documented`
import java.lang.annotation.*;

@Documented
@interface ClassPreamble {

   // Annotation element definitions
   
}
```

## Tipi di annotazioni predefinite

Un set di tipi di annotazione è predefinito nell'API Java SE. Alcuni tipi di annotazione vengono utilizzati dal compilatore Java e alcuni si applicano ad altre annotazioni.

### Tipi di annotazioni usate da Java

I tipi di annotazione predefiniti definiti in java.lang sono @Deprecated, @Override e @SuppressWarnings.

**@Deprecated**: L'annotazione @Deprecated indica che l'elemento contrassegnato è deprecato e non dovrebbe più essere utilizzato. Il compilatore genera un avviso ogni volta che un programma utilizza un metodo, una classe o un campo con l'annotazione @Deprecated. Quando un elemento è deprecato, dovrebbe anche essere documentato utilizzando il tag Javadoc @deprecated, come mostrato nell'esempio seguente. L'uso della chiocciola (@) sia nei commenti Javadoc che nelle annotazioni non è casuale: sono correlati concettualmente. Si noti inoltre che il tag Javadoc inizia con una d minuscola e l'annotazione inizia con una D maiuscola

```java
// Javadoc comment follows
    /**
     * _@deprecated_
     * _explanation of why it was deprecated_
     */
    @Deprecated
    static void deprecatedMethod() { }
}
```

**@Override**: L'annotazione @Override informa il compilatore che l'elemento ha lo scopo di sovrascrivere un elemento dichiarato in una superclasse. I metodi di override saranno discussi in Interfacce ed ereditarietà.
```java
   // _mark method as a superclass method_
   // _that has been overridden_
   @Override 
   int overriddenMethod() { }
```
Sebbene non sia necessario utilizzare questa annotazione quando si esegue l'override di un metodo, aiuta a prevenire gli errori. Se un metodo contrassegnato con @Override non riesce a sovrascrivere correttamente un metodo in una delle sue superclassi, il compilatore genera un errore

**@SuppressWarnings**: L'annotazione @SuppressWarnings indica al compilatore di sopprimere avvisi specifici che altrimenti genererebbe. Nell'esempio seguente viene utilizzato un metodo deprecato e il compilatore di solito genera un avviso. In questo caso, tuttavia, l'annotazione provoca la soppressione dell'avviso.
```java
// _use a deprecated method and tell_ 
   // _compiler not to generate a warning_
   @SuppressWarnings("deprecation")
    void useDeprecatedMethod() {
        // deprecation warning
        // - suppressed
        objectOne.deprecatedMethod();
    }
```
Ogni avviso del compilatore appartiene a una categoria. La specifica del linguaggio Java elenca due categorie: _deprecation_ e _unchecked_. L'avviso _unchecked_ può verificarsi durante l'interfacciamento con codice legacy scritto prima dell'avvento dei generici. Per sopprimere più categorie di avvisi, utilizzare la seguente sintassi:
```java
@SuppressWarnings({"unchecked", "deprecation"})
```

**@SafeVarargs**: L'annotazione@SafeVarargs, quando applicata a un metodo oa un costruttore, afferma che il codice non esegue operazioni potenzialmente non sicure sul relativo parametro varargs. Quando viene utilizzato questo tipo di annotazione, gli avvisi non controllati relativi all'utilizzo di varargs vengono soppressi.

**@FunctionalInterface**: L'annotazione @FunctionalInterface, introdotta in Java SE 8, indica che la dichiarazione del tipo è intesa come interfaccia funzionale, come definito dalla specifica del linguaggio Java.

### Annotazioni che si applicano ad altre annotazioni

Le annotazioni che si applicano ad altre annotazioni sono chiamate meta-annotazioni. Esistono diversi tipi di meta-annotazione definiti in java.lang.annotation.

**@Retention**: L'annotazione @Retention specifica come viene memorizzata l'annotazione contrassegnata:

- _RetentionPolicy.SOURCE_ – L'annotazione contrassegnata viene conservata solo a livello di origine e viene ignorata dal compilatore.
- _RetentionPolicy.CLASS_: l'annotazione contrassegnata viene conservata dal compilatore in fase di compilazione, ma viene ignorata dalla Java Virtual Machine (JVM).
- _RetentionPolicy.RUNTIME_ – L'annotazione contrassegnata viene conservata dalla JVM in modo che possa essere utilizzata dall'ambiente di runtime.

**@Documented**: L'annotazione @Documented indica che ogni volta che viene utilizzata l'annotazione specificata, tali elementi devono essere documentati utilizzando lo strumento Javadoc. (Per impostazione predefinita, le annotazioni non sono incluse in Javadoc.) Per ulteriori informazioni, vedere la pagina degli strumenti [Javadoc](https://docs.oracle.com/javase/8/docs/technotes/guides/javadoc/index.html)

**@Target** L'annotazione @Target contrassegna un'altra annotazione per limitare il tipo di elementi Java a cui può essere applicata l'annotazione. Un'annotazione di destinazione specifica come valore uno dei seguenti tipi di elemento:

- ElementType.ANNOTATION_TYPE può essere applicato a un tipo di annotazione.
- ElementType.CONSTRUCTOR può essere applicato a un costruttore.
- ElementType.FIELD può essere applicato a un campo oa una proprietà.
- ElementType.LOCAL_VARIABLE può essere applicato a una variabile locale.
- ElementType.METHOD può essere applicato a un'annotazione a livello di metodo.
- ElementType.PACKAGE può essere applicato a una dichiarazione di pacchetto.
- ElementType.PARAMETER può essere applicato ai parametri di un metodo.
- ElementType.TYPE può essere applicato a qualsiasi elemento di una classe.

**@Inherited**: L'annotazione @Inherited indica che il tipo di annotazione può essere ereditato dalla superclasse. (Questo non è vero per impostazione predefinita.) Quando l'utente interroga il tipo di annotazione e la classe non ha annotazioni per questo tipo, la superclasse della classe viene interrogata per il tipo di annotazione. Questa annotazione si applica solo alle dichiarazioni di classe.

**@Repeatable**: L'annotazione @Repeatable, introdotta in Java SE 8, indica che l'annotazione contrassegnata può essere applicata più di una volta alla stessa dichiarazione o utilizzo del tipo

## Tipi di annotazioni e sistemi di tipi collegabili

Prima della versione Java SE 8, le annotazioni potevano essere applicate solo alle dichiarazioni. A partire dalla versione Java SE 8, le annotazioni possono essere applicate anche a qualsiasi utilizzo di tipo. Ciò significa che le annotazioni possono essere utilizzate ovunque si utilizzi un tipo. Alcuni esempi di dove vengono utilizzati i tipi sono espressioni di creazione di istanze di classi (nuove), cast, clausole di implementazione e clausole di lancio. Questa forma di annotazione è chiamata annotazione di tipo e diversi esempi sono forniti in Nozioni di base sulle annotazioni.

Le annotazioni di tipo sono state create per supportare una migliore analisi dei programmi Java in modo da garantire un controllo del tipo più forte. La versione Java SE 8 non fornisce un framework di controllo del tipo, ma consente di scrivere (o scaricare) un framework di controllo del tipo implementato come uno o più moduli collegabili utilizzati insieme al compilatore Java.

Ad esempio, vuoi assicurarti che una particolare variabile nel tuo programma non sia mai assegnata a null; vuoi evitare di attivare una NullPointerException. Puoi scrivere un plug-in personalizzato per verificarlo. Dovresti quindi modificare il tuo codice per annotare quella particolare variabile, indicando che non è mai assegnata a null. La dichiarazione della variabile potrebbe essere simile a questa:

```java
@NonNull String str;
```

Quando si compila il codice, incluso il modulo NonNull nella riga di comando, il compilatore stampa un avviso se rileva un potenziale problema, consentendo di modificare il codice per evitare l'errore. Dopo aver corretto il codice per rimuovere tutti gli avvisi, questo particolare errore non si verificherà durante l'esecuzione del programma.

È possibile utilizzare più moduli di controllo del tipo in cui ogni modulo controlla un diverso tipo di errore. In questo modo, puoi costruire sopra il sistema di tipo Java, aggiungendo controlli specifici quando e dove vuoi.

Con l'uso giudizioso delle annotazioni di tipo e la presenza di controlli di tipo collegabili, è possibile scrivere codice più solido e meno soggetto a errori.

## Ripetere annotazioni

Esistono alcune situazioni in cui si desidera applicare la stessa annotazione a una dichiarazione oa un tipo di utilizzo. A partire dalla versione Java SE 8, la ripetizione delle annotazioni consente di eseguire questa operazione.

Ad esempio, stai scrivendo codice per utilizzare un servizio timer che ti consente di eseguire un metodo in un determinato momento o in base a una determinata pianificazione, simile al servizio UNIX cron. Ora vuoi impostare un timer per eseguire un metodo, doPeriodicCleanup, l'ultimo giorno del mese e ogni venerdì alle 23:00. Per impostare l'esecuzione del timer, creare un'annotazione @Schedule e applicarla due volte al metodo doPeriodicCleanup. Il primo utilizzo specifica l'ultimo giorno del mese e il secondo specifica venerdì alle 23:00, come mostrato nel seguente esempio di codice:

```java
@Schedule(dayOfMonth="last")
@Schedule(dayOfWeek="Fri", hour="23")
public void doPeriodicCleanup() { ... }
```

L'esempio precedente applica un'annotazione a un metodo. Puoi ripetere un'annotazione ovunque utilizzi un'annotazione standard. Ad esempio, hai una classe per la gestione delle eccezioni di accesso non autorizzato. Annoti la classe con un'annotazione @Alert per i gestori e un'altra per gli amministratori:

```java
@Alert(role="Manager")
@Alert(role="Administrator")
public class UnauthorizedAccessException extends SecurityException { ... }
```

### Step 1: dichiarare un tipo di annotazione ripetibile

Il tipo di annotazione deve essere contrassegnato con la meta-annotazione @Repeatable. L'esempio seguente definisce un tipo di annotazione ripetibile @Schedule personalizzato:

```java
import java.lang.annotation.Repeatable;

@Repeatable(Schedules.class)
public @interface Schedule {
  String dayOfMonth() default "first";
  String dayOfWeek() default "Mon";
  int hour() default 12;
}
```

Il valore della meta-annotazione @Repeatable, tra parentesi, è il tipo di annotazione del contenitore che il compilatore Java genera per memorizzare le annotazioni ripetute. In questo esempio, il tipo di annotazione contenente è Schedules, quindi le annotazioni @Schedule ripetute vengono archiviate in un'annotazione @Schedules.

L'applicazione della stessa annotazione a una dichiarazione senza prima dichiararla ripetibile genera un errore in fase di compilazione.

### Step 2: Dichiarare il tipo di annotazione contenitore

Il tipo di annotazione contenitore deve avere un elemento di valore con un tipo di matrice. Il tipo di componente del tipo di matrice deve essere il tipo di annotazione ripetibile. La dichiarazione per gli Abachi contenenti il tipo di annotazione è la seguente:

```java
public @interface Schedules {
    Schedule[] value();
}
```

### Recupero di annotazioni

Esistono diversi metodi disponibili nell'API Reflection che possono essere utilizzati per recuperare le annotazioni. Il comportamento dei metodi che restituiscono una singola annotazione, ad esempio `AnnotatedElement.getAnnotation(Class<T>)`, è invariato in quanto restituiscono una singola annotazione solo se è presente un'annotazione del tipo richiesto. Se è presente più di un'annotazione del tipo richiesto, è possibile ottenerle ottenendo prima l'annotazione del contenitore. In questo modo, il codice legacy continua a funzionare. In Java SE 8 sono stati introdotti altri metodi che analizzano l'annotazione del contenitore per restituire più annotazioni contemporaneamente, ad esempio ``AnnotatedElement.getAnnotationsByType(Class<T>)``