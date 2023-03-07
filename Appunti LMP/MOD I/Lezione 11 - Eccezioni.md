
# Eccezioni

## Cos'è un'eccezione?

Il termine eccezione è una scorciatoia per la frase "evento eccezionale".

>[!important]- Definizione
>Un'eccezione è un evento, che si verifica durante l'esecuzione di un programma, che interrompe il normale flusso delle istruzioni del programma.

Quando si verifica un errore all'interno di un metodo, il metodo crea un oggetto e lo passa al sistema di runtime. L'oggetto, chiamato oggetto eccezione, contiene informazioni sull'errore, incluso il tipo e lo stato del programma quando si è verificato l'errore. La creazione di un oggetto eccezione e la sua consegna al sistema di runtime è chiamata generazione di un'eccezione.

Dopo che un metodo genera un'eccezione, il sistema di runtime tenta di trovare qualcosa per gestirla. L'insieme di possibili "qualcosa" per gestire l'eccezione è l'elenco ordinato di metodi che sono stati chiamati per arrivare al metodo in cui si è verificato l'errore. L'elenco dei metodi è noto come stack di chiamate (vedere la figura successiva).

![[appunti lmp/mod i/immagini/exceptions-callstack.gif|center|300]]

Il sistema di runtime cerca nello stack di chiamate un metodo che contenga un blocco di codice in grado di gestire l'eccezione. Questo blocco di codice è chiamato gestore di eccezioni. La ricerca inizia con il metodo in cui si è verificato l'errore e procede attraverso lo stack di chiamate nell'ordine inverso rispetto a quello in cui sono stati chiamati i metodi. Quando viene trovato un gestore appropriato, il sistema di runtime passa l'eccezione al gestore. Un gestore di eccezioni è considerato appropriato se il tipo dell'oggetto eccezione generato corrisponde al tipo che può essere gestito dal gestore.

Si dice che il gestore di eccezioni scelto rilevi l'eccezione. Se il sistema di runtime cerca in modo esaustivo tutti i metodi nello stack di chiamate senza trovare un gestore di eccezioni appropriato, come mostrato nella figura successiva, il sistema di runtime (e, di conseguenza, il programma) termina.
![[appunti lmp/mod i/immagini/exceptions-errorOccurs.gif|center|400]]

L'utilizzo delle eccezioni per gestire gli errori presenta alcuni vantaggi rispetto alle tradizionali tecniche di gestione degli errori

## Il Requisito Catch o Specify

Il codice del linguaggio di programmazione Java valido deve soddisfare il requisito Catch o Specify. Ciò significa che il codice che potrebbe generare determinate eccezioni deve essere racchiuso da uno dei seguenti elementi:

- Un'istruzione try che intercetta l'eccezione. Il try deve fornire un gestore per l'eccezione
- Metodo che specifica che può generare l'eccezione. Il metodo deve fornire una clausola throws che elenchi l'eccezione

Il codice che non soddisfa i requisiti Catch o Specify non verrà compilato.

Non tutte le eccezioni sono soggette al requisito di catch o specify. Per comprenderne il motivo, dobbiamo esaminare le tre categorie fondamentali di eccezioni, di cui solo una è soggetta al Requisito.

### I tre tipi di eccezioni

- Il primo tipo di eccezione è l'eccezione verificata (_checked exception_). Queste sono condizioni eccezionali che un'applicazione ben scritta dovrebbe prevedere e recuperare. Ad esempio, supponiamo che un'applicazione richieda a un utente un nome di file di input, quindi apra il file passando il nome al costruttore per java.io.FileReader. Normalmente, l'utente fornisce il nome di un file esistente e leggibile, quindi la costruzione dell'oggetto FileReader riesce e l'esecuzione dell'applicazione procede normalmente. Ma a volte l'utente fornisce il nome di un file inesistente e il costruttore genera java.io.FileNotFoundException. Un programma ben scritto rileverà questa eccezione e avviserà l'utente dell'errore, eventualmente richiedendo un nome file corretto.

Le eccezioni verificate sono soggette al requisito Catch o Specify. Tutte le eccezioni sono eccezioni controllate, tranne quelle indicate da Error, RuntimeException e le loro sottoclassi.

- Il secondo tipo di eccezione è l'errore (_error_). Si tratta di condizioni eccezionali che sono esterne all'applicazione e che l'applicazione di solito non può prevedere o recuperare. Ad esempio, supponiamo che un'applicazione apra correttamente un file per l'input, ma non sia in grado di leggere il file a causa di un malfunzionamento dell'hardware o del sistema. La lettura non riuscita genererà java.io.IOError. Un'applicazione potrebbe scegliere di rilevare questa eccezione, al fine di notificare all'utente il problema, ma potrebbe anche avere senso che il programma stampi una traccia dello stack e esca.

Gli errori non sono soggetti al requisito di Catch o Specify. Gli errori sono quelle eccezioni indicate da Error e dalle sue sottoclassi.

- Il terzo tipo di eccezione è l'eccezione di runtime (_runtime exception_). Si tratta di condizioni eccezionali interne all'applicazione e che l'applicazione in genere non è in grado di prevedere o recuperare. Questi di solito indicano bug di programmazione, come errori logici o uso improprio di un'API. Ad esempio, si consideri l'applicazione descritta in precedenza che passa un nome di file al costruttore per FileReader. Se un errore logico causa il passaggio di un null al costruttore, il costruttore genererà NullPointerException. L'applicazione può intercettare questa eccezione, ma probabilmente ha più senso eliminare il bug che ha provocato l'eccezione.

Le eccezioni di runtime non sono soggette al requisito di Catch o Specify. Le eccezioni di runtime sono quelle indicate da RuntimeException e dalle sue sottoclassi.

Gli errori e le eccezioni di runtime sono noti collettivamente come eccezioni non controllate.

### Bypassare Catch o Specify

Alcuni programmatori considerano il requisito Catch o Specify un grave difetto nel meccanismo delle eccezioni e lo aggirano utilizzando eccezioni non controllate al posto di eccezioni controllate. In generale, questo non è raccomandato.

## Cattura e gestione delle eccezioni

Questa sezione descrive come utilizzare i tre componenti del gestore delle eccezioni — try, catch e infine i blocchi — per scrivere un gestore delle eccezioni. Quindi, viene spiegata l'istruzione try-with-resources, introdotta in Java SE 7. L'istruzione try-with-resources è particolarmente adatta a situazioni che utilizzano risorse Closeable, come i flussi.

L'ultima parte di questa sezione illustra un esempio e analizza ciò che accade durante vari scenari.

L'esempio seguente definisce e implementa una classe denominata ListOfNumbers. Una volta costruito, ListOfNumbers crea un ArrayList che contiene 10 elementi Integer con valori sequenziali da 0 a 9. La classe ListOfNumbers definisce anche un metodo denominato writeList, che scrive l'elenco di numeri in un file di testo denominato OutFile.txt. Questo esempio utilizza le classi di output definite in java.io

```java
// Note: This class will not compile yet.
import java.io.*;
import java.util.List;
import java.util.ArrayList;

public class ListOfNumbers {

    private List<Integer> list;
    private static final int SIZE = 10;

    public ListOfNumbers () {
        list = new ArrayList<Integer>(SIZE);
        for (int i = 0; i < SIZE; i++) {
            list.add(new Integer(i));
        }
    }

    public void writeList() {
	// The FileWriter constructor throws IOException, which must be caught.
        PrintWriter out = new PrintWriter(**new FileWriter("OutFile.txt")**);

        for (int i = 0; i < SIZE; i++) {
            // The get(int) method throws IndexOutOfBoundsException, which must be caught.
            out.println("Value at: " + i + " = " + **list.get(i)**);
        }
        out.close();
    }
}
```

La prima riga in grassetto è una chiamata a un costruttore. Il costruttore inizializza un flusso di output su un file. Se il file non può essere aperto, il costruttore lancia un'eccezione IOException. La seconda riga in grassetto è una chiamata al metodo get della classe ArrayList, che genera un'eccezione IndexOutOfBoundsException se il valore del suo argomento è troppo piccolo (minore di 0) o troppo grande (più del numero di elementi attualmente contenuti da ArrayList).

Se si tenta di compilare la classe ListOfNumbers, il compilatore stampa un messaggio di errore relativo all'eccezione generata dal costruttore FileWriter. Tuttavia, non visualizza un messaggio di errore relativo all'eccezione generata da get. Il motivo è che l'eccezione generata dal costruttore, IOException, è un'eccezione controllata e quella generata dal metodo get, IndexOutOfBoundsException, è un'eccezione non controllata.

### Il blocco Try

Il primo passaggio nella costruzione di un gestore di eccezioni consiste nel racchiudere il codice che potrebbe generare un'eccezione all'interno di un blocco try. In generale, un blocco try è simile al seguente:

```java
try {
    _code_
}
catch and finally blocks . . .
```

Il segmento nel codice etichettato di esempio contiene una o più righe di codice valide che potrebbero generare un'eccezione. (Il fermo e infine i blocchi sono spiegati nelle prossime due sottosezioni.)

Per costruire un gestore di eccezioni per il metodo writeList dalla classe ListOfNumbers, racchiudere le istruzioni che generano eccezioni del metodo writeList all'interno di un blocco try. C'è più di un modo per farlo. È possibile inserire ogni riga di codice che potrebbe generare un'eccezione all'interno del proprio blocco try e fornire gestori di eccezioni separati per ciascuno. In alternativa, puoi inserire tutto il codice writeList all'interno di un singolo blocco try e associarvi più gestori. Il listato seguente utilizza un blocco try per l'intero metodo perché il codice in questione è molto breve.

```java
private List<Integer> list;
private static final int SIZE = 10;

public void writeList() {
    PrintWriter out = null;
    try {
        System.out.println("Entered try statement");
        FileWriter f = new FileWriter("OutFile.txt");
        out = new PrintWriter(f);
        for (int i = 0; i < SIZE; i++) {
            out.println("Value at: " + i + " = " + list.get(i));
        }
    }
    catch and finally blocks  . . .
}
```

Se si verifica un'eccezione all'interno del blocco try, tale eccezione viene gestita da un gestore di eccezioni ad esso associato. Per associare un gestore di eccezioni a un blocco try, devi inserire un blocco catch dopo di esso;

### Il blocco Catch

Puoi associare i gestori di eccezioni a un blocco try fornendo uno o più blocchi catch direttamente dopo il blocco try. Nessun codice può trovarsi tra la fine del blocco try e l'inizio del primo blocco catch.

```java
try {

} catch (_ExceptionType name_) {

} catch (_ExceptionType name_) {

}
```

Ogni blocco catch è un gestore di eccezioni che gestisce il tipo di eccezione indicato dal suo argomento. Il tipo di argomento, ExceptionType, dichiara il tipo di eccezione che il gestore può gestire e deve essere il nome di una classe che eredita dalla classe Throwable. Il gestore può fare riferimento all'eccezione con il nome.

Il blocco catch contiene il codice che viene eseguito se e quando viene richiamato il gestore delle eccezioni. Il sistema di runtime richiama il gestore di eccezioni quando il gestore è il primo nello stack di chiamate il cui ExceptionType corrisponde al tipo di eccezione generata. Il sistema lo considera una corrispondenza se l'oggetto lanciato può essere legalmente assegnato all'argomento del gestore di eccezioni.

Di seguito sono riportati due gestori di eccezioni per il metodo writeList:

```java
try {

} catch (IndexOutOfBoundsException e) {
    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
} catch (IOException e) {
    System.err.println("Caught IOException: " + e.getMessage());
}
```

I gestori di eccezioni possono fare molto di più che stampare messaggi di errore o arrestare il programma. Possono eseguire il ripristino degli errori, richiedere all'utente di prendere una decisione o propagare l'errore fino a un gestore di livello superiore utilizzando eccezioni concatenate

#### Catturare più di un tipo di eccezione con un gestore di eccezioni

In Java SE 7 e versioni successive, un singolo blocco catch può gestire più di un tipo di eccezione. Questa funzione può ridurre la duplicazione del codice e ridurre la tentazione di rilevare un'eccezione eccessivamente ampia.

Nella clausola catch, specifica i tipi di eccezioni che il blocco può gestire e separa ciascun tipo di eccezione con una barra verticale (|):

```java
catch (IOException|SQLException ex) {
    logger.log(ex);
    throw ex;
}
```

**Oss**: Se un blocco catch gestisce più di un tipo di eccezione, allora il parametro catch è implicitamente _final_. In questo esempio, il parametro catch ex è final e pertanto non è possibile assegnargli alcun valore all'interno del blocco catch

### Il blocco finally

Il blocco finally viene sempre eseguito quando il blocco try termina. Ciò garantisce che il blocco finally venga eseguito anche se si verifica un'eccezione imprevista. Ma infine è utile per qualcosa di più della semplice gestione delle eccezioni: consente al programmatore di evitare che il codice di pulizia venga accidentalmente aggirato da un return, continue o break. Mettere il codice di pulizia in un blocco finally è sempre una buona pratica, anche quando non sono previste eccezioni.

**Oss**: Il blocco finally potrebbe non essere eseguito se la JVM esce durante l'esecuzione del codice try o catch.

Il blocco try del metodo writeList con cui hai lavorato qui apre un PrintWriter. Il programma dovrebbe chiudere quel flusso prima di uscire dal metodo writeList. Ciò pone un problema alquanto complicato perché il blocco try di writeList può terminare in tre modi.

- L'istruzione new FileWriter ha esito negativo e genera un'eccezione IOException.
- L'istruzione list.get(i) ha esito negativo e genera un'eccezione IndexOutOfBoundsException.
- Tutto riesce e il blocco try esce normalmente.

Il sistema di runtime esegue sempre le istruzioni all'interno del blocco finally indipendentemente da ciò che accade all'interno del blocco try. Quindi è il posto perfetto per eseguire la pulizia.

Il seguente blocco finally per il metodo writeList pulisce e quindi chiude PrintWriter e FileWriter.

```java
finally {
    if (out != null) { 
        System.out.println("Closing PrintWriter");
        out.close(); 
    } else { 
        System.out.println("PrintWriter not open");
    } 
    if (f != null) {
	    System.out.println("Closing FileWriter");
	    f.close();
	}	
}
```

**Importante**
Utilizzare un'istruzione try-with-resources invece di un blocco finally quando si chiude un file o si recuperano risorse in altro modo. L'esempio seguente utilizza un'istruzione try-with-resources per ripulire e chiudere PrintWriter e FileWriter per il metodo writeList:
```java
public void writeList() throws IOException {
    try (FileWriter f = new FileWriter("OutFile.txt");
         PrintWriter out = new PrintWriter(f)) {
        for (int i = 0; i < SIZE; i++) {
            out.println("Value at: " + i + " = " + list.get(i));
        }
    }
}
```

L'istruzione try-with-resources rilascia automaticamente le risorse di sistema quando non sono più necessarie

### L'istruzione try-with-resources

L'istruzione try-with-resources è un'istruzione try che dichiara una o più risorse. Una risorsa è un oggetto che deve essere chiuso al termine del programma. L'istruzione try-with-resources assicura che ogni risorsa sia chiusa alla fine dell'istruzione. Qualsiasi oggetto che implementa java.lang.AutoCloseable, che include tutti gli oggetti che implementano java.io.Closeable, può essere utilizzato come risorsa.

L'esempio seguente legge la prima riga da un file. Utilizza un'istanza di FileReader e BufferedReader per leggere i dati dal file. FileReader e BufferedReader sono risorse che devono essere chiuse al termine del programma:

```java
static String readFirstLineFromFile(String path) throws IOException {
	    **try (FileReader fr = new FileReader(path);
	         BufferedReader br = new BufferedReader(fr))** {
	        return br.readLine();
	    }
	}
```

In questo esempio, le risorse dichiarate nell'istruzione try-with-resources sono un FileReader e un BufferedReader. Le istruzioni di dichiarazione di queste risorse vengono visualizzate tra parentesi subito dopo la parola chiave try. Le classi FileReader e BufferedReader, in Java SE 7 e versioni successive, implementano l'interfaccia java.lang.AutoCloseable. Poiché le istanze FileReader e BufferedReader sono dichiarate in un'istruzione try-with-resource, verranno chiuse indipendentemente dal fatto che l'istruzione try venga completata normalmente o bruscamente (come risultato del metodo BufferedReader.readLine che genera un'eccezione IOException).

Prima di Java SE 7, puoi utilizzare un blocco finally per assicurarti che una risorsa venga chiusa indipendentemente dal fatto che l'istruzione try venga completata normalmente o bruscamente. L'esempio seguente utilizza un blocco finally invece di un'istruzione try-with-resources:

```java
static String readFirstLineFromFileWithFinallyBlock(String path) throws IOException {
   
    FileReader fr = new FileReader(path);
    BufferedReader br = new BufferedReader(fr);
    try {
        return br.readLine();
    } finally {
        br.close();
        fr.close();
    }
}
```

Tuttavia, questo esempio potrebbe avere una perdita di risorse. Un programma deve fare di più che affidarsi al Garbage Collector (GC) per recuperare la memoria di una risorsa quando ha finito con essa. Il programma deve inoltre rilasciare nuovamente la risorsa al sistema operativo, in genere chiamando il metodo close della risorsa. Tuttavia, se un programma non riesce a eseguire questa operazione prima che il GC rivendichi la risorsa, le informazioni necessarie per rilasciare la risorsa vengono perse. La risorsa, che è ancora considerata in uso dal sistema operativo, è trapelata.

In questo esempio, se il metodo readLine genera un'eccezione e l'istruzione br.close() nel blocco finally genera un'eccezione, allora il FileReader è trapelato. Pertanto, usa un'istruzione try-with-resources invece di un blocco finally per chiudere le risorse del tuo programma.

Se i metodi readLine e close generano entrambi eccezioni, il metodo readFirstLineFromFileWithFinallyBlock genera l'eccezione generata dal blocco finally; l'eccezione generata dal blocco try viene soppressa. Al contrario, nell'esempio readFirstLineFromFile, se le eccezioni vengono generate sia dal blocco try che dall'istruzione try-with-resources, il metodo readFirstLineFromFile genera l'eccezione generata dal blocco try; l'eccezione generata dal blocco try-with-resources viene soppressa. In Java SE 7 e versioni successive, puoi recuperare le eccezioni soppresse; vedere la sezione Eccezioni soppresse per ulteriori informazioni.

L'esempio seguente recupera i nomi dei file compressi nel file zip zipFileName e crea un file di testo che contiene i nomi di questi file:

```java
public static void writeToFileZipFileContents(String zipFileName,
                                           String outputFileName)
                                           throws java.io.IOException {

    java.nio.charset.Charset charset =
         java.nio.charset.StandardCharsets.US_ASCII;
    java.nio.file.Path outputFilePath =
         java.nio.file.Paths.get(outputFileName);

    // Open zip file and create output file with 
    // try-with-resources statement

    **try (
        java.util.zip.ZipFile zf =
             new java.util.zip.ZipFile(zipFileName);
        java.io.BufferedWriter writer = 
            java.nio.file.Files.newBufferedWriter(outputFilePath, charset)
    )** {
        // Enumerate each entry
        for (java.util.Enumeration entries =
                                zf.entries(); entries.hasMoreElements();) {
            // Get the entry name and write it to the output file
            String newLine = System.getProperty("line.separator");
            String zipEntryName =
                 ((java.util.zip.ZipEntry)entries.nextElement()).getName() +
                 newLine;
            writer.write(zipEntryName, 0, zipEntryName.length());
        }
    }
}
```

In questo esempio, l'istruzione try-with-resources contiene due dichiarazioni separate da un punto e virgola: ZipFile e BufferedWriter. Quando il blocco di codice che lo segue direttamente termina, normalmente oa causa di un'eccezione, i metodi close degli oggetti BufferedWriter e ZipFile vengono chiamati automaticamente in questo ordine. Si noti che i metodi di chiusura delle risorse vengono chiamati nell'ordine opposto rispetto alla loro creazione.

L'esempio seguente utilizza un'istruzione try-with-resources per chiudere automaticamente un oggetto java.sql.Statement:

```java
public static void viewTable(Connection con) throws SQLException {

    String query = "select COF_NAME, SUP_ID, PRICE, SALES, TOTAL from COFFEES";

    **try (Statement stmt = con.createStatement())** {
        ResultSet rs = stmt.executeQuery(query);

        while (rs.next()) {
            String coffeeName = rs.getString("COF_NAME");
            int supplierID = rs.getInt("SUP_ID");
            float price = rs.getFloat("PRICE");
            int sales = rs.getInt("SALES");
            int total = rs.getInt("TOTAL");

            System.out.println(coffeeName + ", " + supplierID + ", " + 
                               price + ", " + sales + ", " + total);
        }
    } catch (SQLException e) {
        JDBCTutorialUtilities.printSQLException(e);
    }
}
```

### Mettiamo tutto insieme

Quando tutti i componenti vengono messi insieme, il metodo writeList ha il seguente aspetto.

```java
public void writeList() {
    PrintWriter out = null;

    try {
        System.out.println("Entering" + " try statement");

        out = new PrintWriter(new FileWriter("OutFile.txt"));
        for (int i = 0; i < SIZE; i++) {
            out.println("Value at: " + i + " = " + list.get(i));
        }
    } catch (IndexOutOfBoundsException e) {
        System.err.println("Caught IndexOutOfBoundsException: "
                           +  e.getMessage());
                                 
    } catch (IOException e) {
        System.err.println("Caught IOException: " +  e.getMessage());
                                 
    } finally {
        if (out != null) {
            System.out.println("Closing PrintWriter");
            out.close();
        } 
        else {
            System.out.println("PrintWriter not open");
        }
    }
}
```

Come accennato in precedenza, il blocco try di questo metodo ha tre diverse possibilità di uscita; qui ce ne sono due.

- Il codice nell'istruzione try ha esito negativo e genera un'eccezione. Potrebbe trattarsi di una IOException causata dalla nuova istruzione FileWriter o di un'eccezione IndexOutOfBoundsException causata da un valore di indice errato nel ciclo for.
- Tutto riesce e l'istruzione try termina normalmente.

Diamo un'occhiata a cosa succede nel metodo writeList durante queste due possibilità di uscita.

#### Scenario 1: si verifica un'eccezione

L'istruzione che crea un FileWriter può fallire per diversi motivi. Ad esempio, il costruttore per FileWriter lancia una IOException se il programma non può creare o scrivere nel file indicato.

Quando FileWriter lancia una IOException, il sistema di runtime interrompe immediatamente l'esecuzione del blocco try; le chiamate al metodo in esecuzione non vengono completate. Il sistema di runtime avvia quindi la ricerca nella parte superiore dello stack di chiamate del metodo per un gestore di eccezioni appropriato. In questo esempio, quando si verifica IOException, il costruttore FileWriter si trova in cima allo stack di chiamate. Tuttavia, il costruttore FileWriter non dispone di un gestore di eccezioni appropriato, quindi il sistema di runtime controlla il metodo successivo, il metodo writeList, nello stack di chiamate al metodo. Il metodo writeList ha due gestori di eccezioni: uno per IOException e uno per IndexOutOfBoundsException.

Il sistema di runtime controlla i gestori di writeList nell'ordine in cui appaiono dopo l'istruzione try. L'argomento del primo gestore di eccezioni è IndexOutOfBoundsException. Questo non corrisponde al tipo di eccezione generata, quindi il sistema di runtime controlla il successivo gestore di eccezioni: IOException. Questo corrisponde al tipo di eccezione generata, quindi il sistema di runtime termina la ricerca di un gestore di eccezioni appropriato. Ora che il runtime ha trovato un gestore appropriato, viene eseguito il codice in quel blocco catch.

Dopo l'esecuzione del gestore delle eccezioni, il sistema di runtime passa il controllo al blocco finally. Il codice nel blocco finally viene eseguito indipendentemente dall'eccezione rilevata al di sopra di esso. In questo scenario, FileWriter non è mai stato aperto e non è necessario chiuderlo. Al termine dell'esecuzione del blocco finally, il programma continua con la prima istruzione dopo il blocco finally.

Ecco l'output completo del programma ListOfNumbers che appare quando viene generata un'eccezione IOException.

```java
Entering try statement
Caught IOException: OutFile.txt
PrintWriter not open
```

Il codice in grassetto nel seguente elenco mostra le istruzioni che vengono eseguite durante questo scenario:

```java
public void writeList() {
   **PrintWriter out = null;

    try {
        System.out.println("Entering try statement");
        out = new PrintWriter(new FileWriter("OutFile.txt"));**
        for (int i = 0; i < SIZE; i++)
            out.println("Value at: " + i + " = " + list.get(i));
                               
    } catch (IndexOutOfBoundsException e) {
        System.err.println("Caught IndexOutOfBoundsException: "
                           + e.getMessage());
                                 
    } **catch (IOException e) {
        System.err.println("Caught IOException: " + e.getMessage());
    } finally {
        if (out != null) {**
            System.out.println("Closing PrintWriter");
            out.close();
        } 
        **else {
            System.out.println("PrintWriter not open");
        }**
    }
}
```

#### Scenario 2: Il blocco try si chiude normalmente

In questo scenario, tutte le istruzioni all'interno dell'ambito del blocco try vengono eseguite correttamente e non generano eccezioni. L'esecuzione cade alla fine del blocco try e il sistema di runtime passa il controllo al blocco finally. Poiché tutto è andato a buon fine, PrintWriter è aperto quando il controllo raggiunge il blocco finally, che chiude PrintWriter. Di nuovo, dopo che il blocco finally ha terminato l'esecuzione, il programma continua con la prima istruzione dopo il blocco finally.

Ecco l'output del programma ListOfNumbers quando non vengono lanciate eccezioni.

```java
Entering try statement
Closing PrintWriter
```

Il codice in grassetto nell'esempio seguente mostra le istruzioni che vengono eseguite durante questo scenario.

```java
public void writeList() {
    **PrintWriter out = null;
    try {
        System.out.println("Entering try statement");
        out = new PrintWriter(new FileWriter("OutFile.txt"));
        for (int i = 0; i < SIZE; i++)
            out.println("Value at: " + i + " = " + list.get(i));
                  
    }** catch (IndexOutOfBoundsException e) {
        System.err.println("Caught IndexOutOfBoundsException: "
                           + e.getMessage());

    } catch (IOException e) {
        System.err.println("Caught IOException: " + e.getMessage());
                                 
    } **finally {
        if (out != null) {
            System.out.println("Closing PrintWriter");
            out.close();
        }** 
        else {
            System.out.println("PrintWriter not open");
        }
    }
}
```

## Specifica delle eccezioni generate da un metodo

La sezione precedente ha mostrato come scrivere un gestore di eccezioni per il metodo writeList nella classe ListOfNumbers. A volte, è opportuno che il codice rilevi le eccezioni che possono verificarsi al suo interno. In altri casi, tuttavia, è meglio lasciare che un metodo più in alto nello stack di chiamate gestisca l'eccezione. Ad esempio, se fornisci la classe ListOfNumbers come parte di un pacchetto di classi, probabilmente non potresti anticipare le esigenze di tutti gli utenti del tuo pacchetto. In questo caso, è meglio non rilevare l'eccezione e consentire a un metodo più in alto nello stack di chiamate di gestirla.

Se il metodo writeList non rileva le eccezioni verificate che possono verificarsi al suo interno, il metodo writeList deve specificare che può generare tali eccezioni. Modifichiamo il metodo writeList originale per specificare le eccezioni che può lanciare invece di catturarle. Per ricordartelo, ecco la versione originale del metodo writeList che non verrà compilata.

```java
public void writeList() {
    PrintWriter out = new PrintWriter(new FileWriter("OutFile.txt"));
    for (int i = 0; i < SIZE; i++) {
        out.println("Value at: " + i + " = " + list.get(i));
    }
    out.close();
}
```

per specificare che writeList può generare due eccezioni, aggiungere una clausola throws alla dichiarazione del metodo per il metodo writeList. La clausola throws comprende la parola chiave throws seguita da un elenco separato da virgole di tutte le eccezioni generate da tale metodo. La clausola va dopo il nome del metodo e l'elenco degli argomenti e prima della parentesi graffa che definisce l'ambito del metodo; ecco un esempio.

```java
public void writeList() **throws IOException, IndexOutOfBoundsException** {
```

## Come generare eccezioni

Prima che tu possa rilevare un'eccezione, un codice da qualche parte deve lanciarne una. Qualsiasi codice può generare un'eccezione: il tuo codice, il codice di un pacchetto scritto da qualcun altro, ad esempio i pacchetti forniti con la piattaforma Java o l'ambiente di runtime Java. Indipendentemente da ciò che genera l'eccezione, viene sempre generata con l'istruzione throw.

Come probabilmente avrai notato, la piattaforma Java fornisce numerose classi di eccezione. Tutte le classi sono discendenti della classe Throwable e tutte consentono ai programmi di differenziare tra i vari tipi di eccezioni che possono verificarsi durante l'esecuzione di un programma.

Puoi anche creare le tue classi di eccezione per rappresentare i problemi che possono verificarsi all'interno delle classi che scrivi. Infatti, se sei uno sviluppatore di pacchetti, potresti dover creare il tuo insieme di classi di eccezione per consentire agli utenti di differenziare un errore che può verificarsi nel tuo pacchetto dagli errori che si verificano nella piattaforma Java o in altri pacchetti.

Puoi anche creare eccezioni concatenate

### L'istruzione throw

Tutti i metodi utilizzano l'istruzione throw per generare un'eccezione. L'istruzione throw richiede un singolo argomento: un oggetto gettabile. Gli oggetti Throwable sono istanze di qualsiasi sottoclasse della classe Throwable. Ecco un esempio di istruzione throw.

```java
throw _someThrowableObject_;
```

Diamo un'occhiata all'istruzione throw nel contesto. Il seguente metodo pop è tratto da una classe che implementa un oggetto stack comune. Il metodo rimuove l'elemento superiore dallo stack e restituisce l'oggetto.

```java
public Object pop() {
    Object obj;

    if (size == 0) {
        **throw new EmptyStackException();**
    }

    obj = objectAt(size - 1);
    setObjectAt(size - 1, null);
    size--;
    return obj;
}
```

### Classe Throwable e sue sottoclassi

Gli oggetti che ereditano dalla classe Throwable includono discendenti diretti (oggetti che ereditano direttamente dalla classe Throwable) e discendenti indiretti (oggetti che ereditano da figli o nipoti della classe Throwable). La figura seguente illustra la gerarchia di classi della classe Throwable e delle sue sottoclassi più significative. Come puoi vedere, Throwable ha due discendenti diretti: Error ed Exception.

![[appunti lmp/mod i/immagini/exceptions-throwable.gif|center|400]]

#### Classe Error

Quando si verifica un errore di collegamento dinamico o un altro errore hardware nella macchina virtuale Java, la macchina virtuale genera un errore. I programmi semplici in genere non rilevano né generano errori.

#### Classe Exception

La maggior parte dei programmi lancia e cattura oggetti che derivano dalla classe Exception. Un'eccezione indica che si è verificato un problema, ma non si tratta di un grave problema di sistema. La maggior parte dei programmi che scrivi genererà e rileverà eccezioni anziché errori.

La piattaforma Java definisce i numerosi discendenti della classe Exception. Questi discendenti indicano vari tipi di eccezioni che possono verificarsi. Ad esempio, IllegalAccessException segnala che non è stato possibile trovare un metodo particolare e NegativeArraySizeException indica che un programma ha tentato di creare un array con una dimensione negativa.

Una sottoclasse Exception, RuntimeException, è riservata alle eccezioni che indicano un uso non corretto di un'API. Un esempio di eccezione di runtime è NullPointerException, che si verifica quando un metodo tenta di accedere a un membro di un oggetto tramite un riferimento null