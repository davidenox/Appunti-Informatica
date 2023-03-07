# Interfacce ed ereditarietà

## Interfacce
Ci sono un certo numero di situazioni nell'ingegneria del software in cui è importante che gruppi disparati di programmatori accettino un "contratto" che spieghi come interagisce il loro software. Ogni gruppo dovrebbe essere in grado di scrivere il proprio codice senza alcuna conoscenza di come viene scritto il codice dell'altro gruppo. In generale, le interfacce sono tali contratti.

Ad esempio, immagina una società futuristica in cui auto robotiche controllate da computer trasportano passeggeri per le strade della città senza un operatore umano. Le case automobilistiche scrivono software (Java, ovviamente) che aziona l'automobile: fermati, avvia, accelera, gira a sinistra e così via. Un altro gruppo industriale, produttori di strumenti di guida elettronica, realizza sistemi informatici che ricevono dati di posizione GPS (Global Positioning System) e trasmissione wireless delle condizioni del traffico e utilizzano tali informazioni per guidare l'auto.

Le case automobilistiche devono pubblicare un'interfaccia standard del settore che spieghi in dettaglio quali metodi possono essere invocati per far muovere l'auto (qualsiasi auto, di qualsiasi produttore). I produttori di guida possono quindi scrivere un software che richiami i metodi descritti nell'interfaccia per comandare l'auto. Nessuno dei due gruppi industriali deve sapere come viene implementato il software dell'altro gruppo. Ciascun gruppo, infatti, considera il proprio software altamente proprietario e si riserva il diritto di modificarlo in qualsiasi momento, purché continui ad aderire all'interfaccia pubblicata.

### Interfacce in Java
Nel linguaggio di programmazione Java, un'interfaccia è un tipo di riferimento, simile a una classe, che può contenere solo costanti, firme di metodo, metodi predefiniti, metodi statici e tipi nidificati. I corpi dei metodi esistono solo per i metodi predefiniti e per i metodi statici. Le interfacce non possono essere istanziate: possono essere implementate solo da classi o estese da altre interfacce. L'estensione è discussa più avanti in questa lezione.

La definizione di un'interfaccia è simile alla creazione di una nuova classe:
```java
public interface OperateCar {

   // constant declarations, if any

   // method signatures
   
   // An enum with values RIGHT, LEFT
   int turn(Direction direction,
            double radius,
            double startSpeed,
            double endSpeed);
   int changeLanes(Direction direction,
                   double startSpeed,
                   double endSpeed);
   int signalTurn(Direction direction,
                  boolean signalOn);
   int getRadarFront(double distanceToCar,
                     double speedOfCar);
   int getRadarRear(double distanceToCar,
                    double speedOfCar);
         ......
   // more method signatures
}
```

Si noti che le firme del metodo non hanno parentesi graffe e terminano con un punto e virgola.

Per utilizzare un'interfaccia, scrivi una classe che implementa l'interfaccia. Quando una classe istanziabile implementa un'interfaccia, fornisce un corpo del metodo per ciascuno dei metodi dichiarati nell'interfaccia. Per esempio,
```java
public class OperateBMW760i implements OperateCar {

    // the OperateCar method signatures, with implementation --
    // for example:
    public int signalTurn(Direction direction, boolean signalOn) {
       // code to turn BMW's LEFT turn indicator lights on
       // code to turn BMW's LEFT turn indicator lights off
       // code to turn BMW's RIGHT turn indicator lights on
       // code to turn BMW's RIGHT turn indicator lights off
    }

    // other members, as needed -- for example, helper classes not 
    // visible to clients of the interface
}
```
Nell'esempio dell'auto robotica sopra, sono le case automobilistiche che implementeranno l'interfaccia. L'implementazione di Chevrolet sarà sostanzialmente diversa da quella di Toyota, ovviamente, ma entrambi i produttori aderiranno alla stessa interfaccia. I produttori di guide, che sono i clienti dell'interfaccia, costruiranno sistemi che utilizzano i dati GPS sulla posizione di un'auto, mappe stradali digitali e dati sul traffico per guidare l'auto. In tal modo, i sistemi di guida invocheranno i metodi di interfaccia: svoltare, cambiare corsia, frenare, accelerare e così via.

### Interfacce come API
L'esempio dell'auto robotica mostra un'interfaccia utilizzata come API (Application Programming Interface) standard del settore. Le API sono comuni anche nei prodotti software commerciali. In genere, un'azienda vende un pacchetto software che contiene metodi complessi che un'altra azienda desidera utilizzare nel proprio prodotto software. Un esempio potrebbe essere un pacchetto di metodi di elaborazione delle immagini digitali che vengono venduti alle aziende che producono programmi di grafica per utenti finali. La società di elaborazione delle immagini scrive le sue classi per implementare un'interfaccia, che rende pubblica ai propri clienti. L'azienda grafica richiama quindi i metodi di elaborazione delle immagini utilizzando le firme ei tipi restituiti definiti nell'interfaccia. Sebbene l'API dell'azienda di elaborazione delle immagini sia resa pubblica (ai suoi clienti), la sua implementazione dell'API è tenuta segreta e gelosamente custodita, infatti potrebbe rivedere l'implementazione in un secondo momento purché continui a implementare l'interfaccia originale su cui i suoi clienti hanno fatto affidamento.

### Definire un Interfaccia
Una dichiarazione di interfaccia è composta da modificatori, la parola chiave interface, il nome dell'interfaccia, un elenco separato da virgole di interfacce padre (se presenti) e il corpo dell'interfaccia. Per esempio:
```java
public interface GroupedInterface extends Interface1, Interface2, Interface3 {

    // constant declarations
    
    // base of natural logarithms
    double E = 2.718282;
 
    // method signatures
    void doSomething (int i, double x);
    int doSomethingElse(String s);
}
```
L'identificatore di accesso pubblico indica che l'interfaccia può essere utilizzata da qualsiasi classe in qualsiasi pacchetto. Se non specifichi che l'interfaccia è pubblica, la tua interfaccia è accessibile solo alle classi definite nello stesso pacchetto dell'interfaccia.

Un'interfaccia può estendere altre interfacce, proprio come una sottoclasse di classe o estendere un'altra classe. Tuttavia, mentre una classe può estendere solo un'altra classe, un'interfaccia può estendere un numero qualsiasi di interfacce. La dichiarazione dell'interfaccia include un elenco separato da virgole di tutte le interfacce che estende.

#### Corpo dell'interfaccia
Il corpo dell'interfaccia può contenere metodi astratti, metodi predefiniti e metodi statici. Un metodo astratto all'interno di un'interfaccia è seguito da un punto e virgola, ma senza parentesi graffe (un metodo astratto non contiene un'implementazione). I metodi predefiniti sono definiti con il modificatore predefinito e i metodi statici con la parola chiave static. Tutti i metodi astratti, predefiniti e statici in un'interfaccia sono implicitamente pubblici, quindi puoi omettere il modificatore public.

Inoltre, un'interfaccia può contenere dichiarazioni di costanti. Tutti i valori costanti definiti in un'interfaccia sono implicitamente pubblici, statici e finali. Ancora una volta, puoi omettere questi modificatori.

### Implementare un interfaccia

Per dichiarare una classe che implementa un'interfaccia, includi una clausola implements nella dichiarazione di classe. La tua classe può implementare più di un'interfaccia, quindi la parola chiave implements è seguita da un elenco separato da virgole delle interfacce implementate dalla classe. Per convenzione, la clausola implements segue la clausola extends, se presente.

#### Un'interfaccia di esempio, Relatable

Si consideri un'interfaccia che definisce come confrontare le dimensioni degli oggetti.
```java
public interface Relatable {
        
    // this (object calling isLargerThan)
    // and other must be instances of 
    // the same class returns 1, 0, -1 
    // if this is greater than, 
    // equal to, or less than other
    public int isLargerThan(Relatable other);
}
```
Se vuoi essere in grado di confrontare le dimensioni di oggetti simili, indipendentemente da cosa siano, la classe che li istanzia dovrebbe implementare Relatable.

Qualsiasi classe può implementare Relatable se esiste un modo per confrontare la "dimensione" relativa degli oggetti istanziati dalla classe. Per le stringhe, potrebbe essere il numero di caratteri; per i libri, potrebbe essere il numero di pagine; per gli studenti, potrebbe essere peso; e così via. Per gli oggetti geometrici planari, l'area sarebbe una buona scelta (vedi la classe RectanglePlus che segue), mentre il volume funzionerebbe per gli oggetti geometrici tridimensionali. Tutte queste classi possono implementare il metodo isLargerThan().

Se sai che una classe implementa Relatable, allora sai che puoi confrontare la dimensione degli oggetti istanziati da quella classe.

#### Implementazione dell'interfaccia Relatable
Ecco la classe Rectangle che è stata presentata nella sezione [[Lezione 6 - Classi#Creare oggetti|Lezione 6 - Creare oggetti]], riscritta per implementare Relatable.
```java
public class RectanglePlus 
    implements Relatable {
    public int width = 0;
    public int height = 0;
    public Point origin;

    // four constructors
    public RectanglePlus() {
        origin = new Point(0, 0);
    }
    public RectanglePlus(Point p) {
        origin = p;
    }
    public RectanglePlus(int w, int h) {
        origin = new Point(0, 0);
        width = w;
        height = h;
    }
    public RectanglePlus(Point p, int w, int h) {
        origin = p;
        width = w;
        height = h;
    }

    // a method for moving the rectangle
    public void move(int x, int y) {
        origin.x = x;
        origin.y = y;
    }

    // a method for computing
    // the area of the rectangle
    public int getArea() {
        return width * height;
    }
    
    // a method required to implement
    // the Relatable interface
    public int isLargerThan(Relatable other) {
        **RectanglePlus otherRect 
            = (RectanglePlus)other;**
        if (this.getArea() < otherRect.getArea())
            return -1;
        else if (this.getArea() > otherRect.getArea())
            return 1;
        else
            return 0;               
    }
}
```

#### Utilizzo di un'interfaccia come tipo

Quando si definisce una nuova interfaccia, si definisce un nuovo tipo di dati di riferimento. È possibile utilizzare i nomi di interfaccia ovunque sia possibile utilizzare qualsiasi altro nome di tipo di dati. Se definisci una variabile di riferimento il cui tipo è un'interfaccia, qualsiasi oggetto che le assegni deve essere un'istanza di una classe che implementa l'interfaccia.

Ad esempio, ecco un metodo per trovare l'oggetto più grande in una coppia di oggetti, per qualsiasi oggetto istanziato da una classe che implementa Relatable:

```java
public Object findLargest(Object object1, Object object2) {
   Relatable obj1 = (Relatable)object1;
   Relatable obj2 = (Relatable)object2;
   if ((obj1).isLargerThan(obj2) > 0)
      return object1;
   else 
      return object2;
}
```

Eseguendo il cast di object1 su un tipo Relatable, può richiamare il metodo isLargerThan.

Se ti impegni a implementare Relatable in un'ampia varietà di classi, gli oggetti istanziati da una qualsiasi di queste classi possono essere confrontati con il metodo findLargest(), a condizione che entrambi gli oggetti siano della stessa classe. Allo stesso modo, possono essere tutti confrontati con i seguenti metodi:

```java
public Object findSmallest(Object object1, Object object2) {
   Relatable obj1 = (Relatable)object1;
   Relatable obj2 = (Relatable)object2;
   if ((obj1).isLargerThan(obj2) < 0)
      return object1;
   else 
      return object2;
}

public boolean isEqual(Object object1, Object object2) {
   Relatable obj1 = (Relatable)object1;
   Relatable obj2 = (Relatable)object2;
   if ( (obj1).isLargerThan(obj2) == 0)
      return true;
   else 
      return false;
}
```

Questi metodi funzionano per qualsiasi oggetto "riconoscibile", indipendentemente dalla loro ereditarietà di classe. Quando implementano Relatable, possono essere sia del proprio tipo di classe (o superclasse) che di tipo Relatable. Ciò offre loro alcuni dei vantaggi dell'ereditarietà multipla, in cui possono avere un comportamento sia da una superclasse che da un'interfaccia.