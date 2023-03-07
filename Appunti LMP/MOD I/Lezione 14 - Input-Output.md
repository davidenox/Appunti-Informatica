
# Basic I/O

## I/O Streams

Un flusso di I/O rappresenta una sorgente di input o una destinazione di output. Un flusso può rappresentare molti tipi diversi di origini e destinazioni, inclusi file su disco, dispositivi, altri programmi e array di memoria.

Gli stream supportano molti tipi diversi di dati, inclusi byte semplici, tipi di dati primitivi, caratteri localizzati e oggetti. Alcuni flussi semplicemente trasmettono dati; altri manipolano e trasformano i dati in modi utili.

Indipendentemente da come funzionino internamente, tutti i flussi presentano lo stesso semplice modello ai programmi che li utilizzano: un flusso è una sequenza di dati. Un programma utilizza un flusso di input per leggere i dati da una fonte, un elemento alla volta:

![[appunti lmp/mod i/immagini/io-ins.gif|center]]

Un programma utilizza un flusso di output per scrivere i dati in una destinazione, un elemento alla volta:

![[appunti lmp/mod i/immagini/Pasted image 20221221111833.png|center|500]]


In questa lezione vedremo flussi in grado di gestire tutti i tipi di dati, dai valori primitivi agli oggetti avanzati.

L'origine dati e la destinazione dei dati raffigurate sopra possono essere qualsiasi cosa contenga, generi o consumi dati. Ovviamente questo include i file su disco, ma una sorgente o una destinazione può anche essere un altro programma, un dispositivo periferico, un socket di rete o un array.

Nella sezione successiva, utilizzeremo il tipo più elementare di flussi, flussi di byte, per dimostrare le operazioni comuni di Stream I/O.

### Flussi di Byte

I programmi utilizzano flussi di byte per eseguire l'input e l'output di byte a 8 bit. Tutte le classi del flusso di byte discendono da InputStream e OutputStream.

Esistono molte classi di flusso di byte. Per dimostrare come funzionano i flussi di byte, ci concentreremo sui flussi di byte di file I/O, FileInputStream e FileOutputStream. Altri tipi di flussi di byte vengono utilizzati più o meno allo stesso modo; differiscono principalmente nel modo in cui sono costruiti.

#### Utilizzo di flussi di byte

Esploreremo FileInputStream e FileOutputStream esaminando un programma di esempio denominato CopyBytes, che utilizza flussi di byte per copiare xanadu.txt, un byte alla volta.

```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class CopyBytes {
    public static void main(String[] args) throws IOException {

        FileInputStream in = null;
        FileOutputStream out = null;

        try {
            in = new FileInputStream("xanadu.txt");
            out = new FileOutputStream("outagain.txt");
            int c;

            while ((c = in.read()) != -1) {
                out.write(c);
            }
        } finally {
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
        }
    }
}
```

CopyBytes passa la maggior parte del suo tempo in un ciclo semplice che legge il flusso di input e scrive il flusso di output, un byte alla volta, come mostrato nella figura seguente.

![[appunti lmp/mod i/immagini/byteStream.gif|center]]

#### Chiudi sempre i flussi

La chiusura di un flusso quando non è più necessario è molto importante, così importante che CopyBytes utilizza un blocco finally per garantire che entrambi i flussi vengano chiusi anche se si verifica un errore. Questa pratica consente di evitare gravi perdite di risorse.

Un possibile errore è che CopyBytes non è stato in grado di aprire uno o entrambi i file. Quando ciò accade, la variabile di flusso corrispondente al file non cambia mai rispetto al suo valore nullo iniziale. Ecco perché CopyBytes si assicura che ogni variabile di flusso contenga un riferimento a un oggetto prima di richiamare close

#### Quando non utilizzare i flussi di byte

CopyBytes sembra un normale programma, ma in realtà rappresenta una sorta di I/O di basso livello che dovresti evitare. Poiché xanadu.txt contiene dati di caratteri, l'approccio migliore consiste nell'utilizzare flussi di caratteri, come discusso nella sezione successiva. Esistono anche flussi per tipi di dati più complicati. I flussi di byte dovrebbero essere utilizzati solo per l'I/O più primitivo.

### Flussi di caratteri

La piattaforma Java memorizza i valori dei caratteri utilizzando le convenzioni Unicode. Il flusso di caratteri I/O traduce automaticamente questo formato interno da e verso il set di caratteri locale. Nelle versioni locali occidentali, il set di caratteri locale è solitamente un superset di ASCII a 8 bit.

Per la maggior parte delle applicazioni, l'I/O con flussi di caratteri non è più complicato dell'I/O con flussi di byte. L'input e l'output eseguiti con le classi di flusso si traducono automaticamente da e verso il set di caratteri locale. Un programma che utilizza flussi di caratteri al posto dei flussi di byte si adatta automaticamente al set di caratteri locale ed è pronto per l'internazionalizzazione, il tutto senza ulteriori sforzi da parte del programmatore.

Se l'internazionalizzazione non è una priorità, puoi semplicemente utilizzare le classi del flusso di caratteri senza prestare molta attenzione ai problemi del set di caratteri. Successivamente, se l'internazionalizzazione diventa una priorità, il tuo programma può essere adattato senza un'estesa ricodifica.

#### Utilizzo di flussi di caratteri

Tutte le classi del flusso di caratteri discendono da Reader e Writer. Come per i flussi di byte, esistono classi di flussi di caratteri specializzate nell'I/O di file: FileReader e FileWriter. L'esempio CopyCharacters illustra queste classi.

```java
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CopyCharacters {
    public static void main(String[] args) throws IOException {

        FileReader inputStream = null;
        FileWriter outputStream = null;

        try {
            inputStream = new FileReader("xanadu.txt");
            outputStream = new FileWriter("characteroutput.txt");

            int c;
            while ((c = inputStream.read()) != -1) {
                outputStream.write(c);
            }
        } finally {
            if (inputStream != null) {
                inputStream.close();
            }
            if (outputStream != null) {
                outputStream.close();
            }
        }
    }
}
```

CopyCharacters è molto simile a CopyBytes. La differenza più importante è che CopyCharacters utilizza FileReader e FileWriter per l'input e l'output al posto di FileInputStream e FileOutputStream. Si noti che sia CopyBytes che CopyCharacters usano una variabile int per leggere e scrivere. Tuttavia, in CopyCharacters, la variabile int contiene un valore di carattere nei suoi ultimi 16 bit; in CopyBytes, la variabile int contiene un valore di byte nei suoi ultimi 8 bit.

#### Flussi di caratteri che utilizzano flussi di byte

I flussi di caratteri sono spesso "wrapper" per i flussi di byte. Il flusso di caratteri utilizza il flusso di byte per eseguire l'I/O fisico, mentre il flusso di caratteri gestisce la traduzione tra caratteri e byte. FileReader, ad esempio, utilizza FileInputStream, mentre FileWriter utilizza FileOutputStream.

Esistono due flussi "ponte" da byte a carattere generici: InputStreamReader e OutputStreamWriter. Usali per creare stream di caratteri quando non ci sono classi di stream di caratteri preconfezionate che soddisfino le tue esigenze.

#### I/O orientato alla linea

L'I/O dei caratteri di solito si verifica in unità più grandi rispetto ai singoli caratteri. Un'unità comune è la riga: una stringa di caratteri con un terminatore di riga alla fine. Un terminatore di riga può essere una sequenza di ritorno a capo/avanzamento riga ("\r\n"), un singolo ritorno a capo ("\r") o un singolo avanzamento riga ("\n"). Il supporto di tutti i possibili terminatori di riga consente ai programmi di leggere file di testo creati su qualsiasi sistema operativo ampiamente utilizzato.

Modifichiamo l'esempio CopyCharacters per utilizzare l'I/O orientato alla riga. Per fare questo, dobbiamo usare due classi che non abbiamo mai visto prima, BufferedReader e PrintWriter

L'esempio CopyLines richiama BufferedReader.readLine e PrintWriter.println per eseguire input e output una riga alla volta.

```java
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;

public class CopyLines {
    public static void main(String[] args) throws IOException {

        BufferedReader inputStream = null;
        PrintWriter outputStream = null;

        try {
            inputStream = new BufferedReader(new FileReader("xanadu.txt"));
            outputStream = new PrintWriter(new FileWriter("characteroutput.txt"));

            String l;
            while ((l = inputStream.readLine()) != null) {
                outputStream.println(l);
            }
        } finally {
            if (inputStream != null) {
                inputStream.close();
            }
            if (outputStream != null) {
                outputStream.close();
            }
        }
    }
}
```

Invocando readLine restituisce una riga di testo con la riga. CopyLines emette ogni riga utilizzando println, che aggiunge il terminatore di riga per il sistema operativo corrente. Questo potrebbe non essere lo stesso terminatore di riga utilizzato nel file di input.

Esistono molti modi per strutturare l'input e l'output del testo oltre i caratteri e le righe

### Flussi bufferizzati (Buffered Streams)

La maggior parte degli esempi visti finora utilizza I/O senza buffer. Ciò significa che ogni richiesta di lettura o scrittura viene gestita direttamente dal sistema operativo sottostante. Ciò può rendere un programma molto meno efficiente, poiché ciascuna di queste richieste spesso attiva l'accesso al disco, l'attività di rete o qualche altra operazione relativamente costosa.

Per ridurre questo tipo di sovraccarico, la piattaforma Java implementa flussi di I/O bufferizzati. I flussi di input bufferizzati leggono i dati da un'area di memoria nota come buffer; l'API di input nativa viene chiamata solo quando il buffer è vuoto. Allo stesso modo, i flussi di output bufferizzati scrivono i dati in un buffer e l'API di output nativa viene chiamata solo quando il buffer è pieno.

Un programma può convertire un flusso non bufferizzato in un flusso bufferizzato utilizzando l'idioma di wrapping che abbiamo utilizzato diverse volte, in cui l'oggetto flusso non bufferizzato viene passato al costruttore per una classe di flusso bufferizzato. Ecco come modificare le invocazioni del costruttore nell'esempio CopyCharacters per utilizzare l'I/O bufferizzato:

```java
inputStream = new BufferedReader(new FileReader("xanadu.txt"));
outputStream = new BufferedWriter(new FileWriter("characteroutput.txt"));
```

Esistono quattro classi di flussi bufferizzati utilizzati per eseguire il wrapping di flussi non bufferizzati: BufferedInputStream e BufferedOutputStream creano flussi di byte bufferizzati, mentre BufferedReader e BufferedWriter creano flussi di caratteri bufferizzati.

#### Svuotamento dei flussi bufferizzati (Flushing)

Spesso ha senso scrivere un buffer nei punti critici, senza attendere che si riempia. Questo è noto come svuotamento del buffer.

Alcune classi di output bufferizzate supportano lo scaricamento automatico, specificato da un argomento costruttore facoltativo. Quando lo svuotamento automatico è abilitato, alcuni eventi chiave provocano lo svuotamento del buffer. Ad esempio, un oggetto PrintWriter autoflush scarica il buffer a ogni chiamata di println o format

Per svuotare manualmente uno stream, richiamare il relativo metodo flush. Il metodo flush è valido su qualsiasi flusso di output, ma non ha alcun effetto a meno che il flusso non sia memorizzato nel buffer.

### Scanning e Formattazione

La programmazione di I/O spesso implica la traduzione da e verso i dati ordinatamente formattati con cui gli umani amano lavorare. Per assisterti in queste faccende, la piattaforma Java fornisce due API. L'API dello scanner suddivide l'input in singoli token associati a bit di dati. L'API di formattazione assembla i dati in una forma ben formattata e leggibile dall'uomo.

#### Scanning

Gli oggetti di tipo Scanner sono utili per suddividere l'input formattato in token e tradurre i singoli token in base al loro tipo di dati.

##### Rompere l'input in token

Per impostazione predefinita, uno scanner utilizza lo spazio bianco per separare i token. (I caratteri di spazio bianco includono spazi vuoti, tabulazioni e terminazioni di riga. Per l'elenco completo, fare riferimento alla documentazione di Character.isWhitespace.) Per vedere come funziona la scansione, diamo un'occhiata a ScanXan, un programma che legge le singole parole in xanadu.txt e li stampa, uno per riga.

```java
import java.io.*;
import java.util.Scanner;

public class ScanXan {
    public static void main(String[] args) throws IOException {

        Scanner s = null;

        try {
            s = new Scanner(new BufferedReader(new FileReader("xanadu.txt")));

            while (s.hasNext()) {
                System.out.println(s.next());
            }
        } finally {
            if (s != null) {
                s.close();
            }
        }
    }
}
```

Si noti che ScanXan richiama il metodo close di Scanner quando ha terminato con l'oggetto scanner. Anche se uno scanner non è un flusso, devi chiuderlo per indicare che hai finito con il suo flusso sottostante.

Per utilizzare un diverso separatore di token, richiamare useDelimiter(), specificando un'espressione regolare. Ad esempio, supponi di volere che il separatore di token sia una virgola, facoltativamente seguita da uno spazio bianco. invocheresti:

```java
s.useDelimiter(",\\s*");
```

##### Traduzione di token individuali

L'esempio ScanXan tratta tutti i token di input come semplici valori stringa. Scanner supporta anche i token per tutti i tipi primitivi del linguaggio Java (ad eccezione di char), oltre a BigInteger e BigDecimal. Inoltre, i valori numerici possono utilizzare i separatori delle migliaia. Pertanto, in una versione locale degli Stati Uniti, Scanner legge correttamente la stringa "32.767" come rappresentante di un valore intero.

Dobbiamo menzionare il locale, perché i separatori delle migliaia ei simboli decimali sono specifici del locale. Pertanto, l'esempio seguente non funzionerebbe correttamente in tutte le versioni locali se non si specifica che lo scanner deve utilizzare la versione locale degli Stati Uniti. Di solito non è qualcosa di cui ti devi preoccupare, perché i tuoi dati di input provengono solitamente da fonti che utilizzano le tue stesse impostazioni locali. Ma questo esempio fa parte del Java Tutorial e viene distribuito in tutto il mondo.

L'esempio ScanSum legge un elenco di valori double e li somma. Ecco la fonte:

```java
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

public class ScanSum {
    public static void main(String[] args) throws IOException {

        Scanner s = null;
        double sum = 0;

        try {
            s = new Scanner(new BufferedReader(new FileReader("usnumbers.txt")));
            s.useLocale(Locale.US);

            while (s.hasNext()) {
                if (s.hasNextDouble()) {
                    sum += s.nextDouble();
                } else {
                    s.next();
                }   
            }
        } finally {
            s.close();
        }

        System.out.println(sum);
    }
}
```

#### Formattazione

Gli oggetti stream che implementano la formattazione sono istanze di PrintWriter, una classe di flusso di caratteri o PrintStream, una classe di flusso di byte.

>[!warning]- Nota
>Gli unici oggetti PrintStream di cui potresti aver bisogno sono System.out e System.err. Quando devi creare un flusso di output formattato, istanzia PrintWriter, non PrintStream.

Come tutti gli oggetti flusso di byte e caratteri, le istanze di PrintStream e PrintWriter implementano un set standard di metodi di scrittura per l'output di byte e caratteri semplici. Inoltre, sia PrintStream che PrintWriter implementano lo stesso set di metodi per convertire i dati interni in output formattato. Sono disponibili due livelli di formattazione:

- `print` e `println` formattano i singoli valori in modo standard.
- `format` formatta quasi qualsiasi numero di valori in base a una stringa di formato, con molte opzioni per una formattazione precisa.

##### I metodi print e println

Richiamare print o println restituisce un singolo valore dopo averlo convertito utilizzando il metodo toString appropriato. Possiamo vedere questo nell'esempio Root:

```java
public class Root {
    public static void main(String[] args) {
        int i = 2;
        double r = Math.sqrt(i);
        
        System.out.print("The square root of ");
        System.out.print(i);
        System.out.print(" is ");
        System.out.print(r);
        System.out.println(".");

        i = 5;
        r = Math.sqrt(i);
        System.out.println("The square root of " + i + " is " + r + ".");
    }
}
```

Le variabili i e r sono formattate due volte: la prima volta utilizzando il codice in un overload di print, la seconda volta tramite il codice di conversione generato automaticamente dal compilatore Java, che utilizza anche toString. Puoi formattare qualsiasi valore in questo modo, ma non hai molto controllo sui risultati.

##### Il formato Metodo

Il metodo format formatta più argomenti in base a una stringa di formato. La stringa di formato è costituita da testo statico incorporato con identificatori di formato; ad eccezione degli identificatori di formato, la stringa di formato viene emessa invariata.

Le stringhe di formato supportano molte funzionalità. In questo tutorial, tratteremo solo alcune nozioni di base.

L'esempio Root2 formatta due valori con una singola chiamata di formato:

```java
public class Root2 {
    public static void main(String[] args) {
        int i = 2;
        double r = Math.sqrt(i);
        
        System.out.format("The square root of %d is %f.%n", i, r);
    }
}
```

Come i tre utilizzati in questo esempio, tutti gli identificatori di formato iniziano con % e terminano con una conversione di 1 o 2 caratteri che specifica il tipo di output formattato generato. Le tre conversioni utilizzate qui sono:

- `d` formatta un valore intero come valore decimale.
- `f` formatta un valore in virgola mobile come valore decimale.
- `n` emette un terminatore di riga specifico della piattaforma.

Ecco alcune altre conversioni:

- `x` formatta un numero intero come valore esadecimale.
- `s` formatta qualsiasi valore come stringa.
- `tB` formatta un numero intero come nome del mese specifico della locale.

Ci sono molte altre conversioni.

>[!info]- Nota
>Ad eccezione di `%%` e `%n`, tutti gli identificatori di formato devono corrispondere a un argomento. In caso contrario, viene generata un'eccezione.
>Nel linguaggio di programmazione Java, l'escape \n genera sempre il carattere di avanzamento riga (\u000A). Non usare \n a meno che tu non voglia specificamente un carattere di avanzamento riga. Per ottenere il separatore di riga corretto per la piattaforma locale, utilizzare %n.

Oltre alla conversione, un identificatore di formato può contenere diversi elementi aggiuntivi che personalizzano ulteriormente l'output formattato. Ecco un esempio, Format, che utilizza ogni possibile tipo di elemento.

```java
public class Format {
    public static void main(String[] args) {
        System.out.format("%f, %1$+020.10f %n", Math.PI);
    }
}
```

Gli elementi aggiuntivi sono tutti facoltativi. La figura seguente mostra come l'identificatore più lungo si suddivide in elementi

![[appunti lmp/mod i/immagini/io-spec.gif|center]]

Gli elementi devono apparire nell'ordine indicato. Partendo da destra, gli elementi facoltativi sono:

- **Precisione**. Per i valori in virgola mobile, questa è la precisione matematica del valore formattato. Per se altre conversioni generali, questa è la larghezza massima del valore formattato; il valore viene troncato a destra se necessario.
- **Larghezza**. La larghezza minima del valore formattato; il valore viene riempito se necessario. Per impostazione predefinita, il valore viene riempito a sinistra con spazi vuoti.
- **I contrassegni (flags)** specificano opzioni di formattazione aggiuntive. Nell'esempio Format, il flag + specifica che il numero deve essere sempre formattato con un segno e il flag 0 specifica che 0 è il carattere di riempimento. Altri flag includono - (pad a destra) e , (numero di formato con separatori delle migliaia specifici della locale). Si noti che alcuni flag non possono essere utilizzati con determinati altri flag o con determinate conversioni.
- **L'indice degli argomenti (argument index)** consente di abbinare in modo esplicito un argomento designato. È inoltre possibile specificare < per trovare la corrispondenza con lo stesso argomento dell'identificatore precedente. Quindi l'esempio avrebbe potuto dire: 
```java 
System.out.format("%f, %<+020.10f %n", Math.PI);
```

### I/O dalla riga di comando

Un programma viene spesso eseguito dalla riga di comando e interagisce con l'utente nell'ambiente della riga di comando. La piattaforma Java supporta questo tipo di interazione in due modi: attraverso gli Standard Stream e attraverso la Console.

#### Standard Streams

I flussi standard sono una funzionalità di molti sistemi operativi. Per impostazione predefinita, leggono l'input dalla tastiera e scrivono l'output sul display. Supportano anche l'I/O su file e tra programmi, ma tale funzionalità è controllata dall'interprete della riga di comando, non dal programma.

La piattaforma Java supporta tre flussi standard: input standard, accessibile tramite System.in; Standard Output, accessibile tramite System.out; e Standard Error, accessibile tramite System.err. Questi oggetti vengono definiti automaticamente e non è necessario aprirli. Standard Output e Standard Error sono entrambi per l'output; avere l'output degli errori separatamente consente all'utente di deviare l'output regolare su un file ed essere ancora in grado di leggere i messaggi di errore. Per ulteriori informazioni, fare riferimento alla documentazione dell'interprete della riga di comando.

Potresti aspettarti che i flussi standard siano flussi di caratteri, ma, per ragioni storiche, sono flussi di byte. System.out e System.err sono definiti come oggetti PrintStream. Sebbene sia tecnicamente un flusso di byte, PrintStream utilizza un oggetto flusso di caratteri interno per emulare molte delle caratteristiche dei flussi di caratteri.

Al contrario, System.in è un flusso di byte senza funzionalità di flusso di caratteri. Per utilizzare l'input standard come flusso di caratteri, eseguire il wrapping di System.in in InputStreamReader.

```java
InputStreamReader cin = new InputStreamReader(System.in);
```

#### Console

I flussi standard sono una funzionalità di molti sistemi operativi. Per impostazione predefinita, leggono l'input dalla tastiera e scrivono l'output sul display. Supportano anche l'I/O su file e tra programmi, ma tale funzionalità è controllata dall'interprete della riga di comando, non dal programma.

La piattaforma Java supporta tre flussi standard: input standard, accessibile tramite System.in; Standard Output, accessibile tramite System.out; e Standard Error, accessibile tramite System.err. Questi oggetti vengono definiti automaticamente e non è necessario aprirli. Standard Output e Standard Error sono entrambi per l'output; avere l'output degli errori separatamente consente all'utente di deviare l'output regolare su un file ed essere ancora in grado di leggere i messaggi di errore. Per ulteriori informazioni, fare riferimento alla documentazione dell'interprete della riga di comando.

Potresti aspettarti che i flussi standard siano flussi di caratteri, ma, per ragioni storiche, sono flussi di byte. System.out e System.err sono definiti come oggetti PrintStream. Sebbene sia tecnicamente un flusso di byte, PrintStream utilizza un oggetto flusso di caratteri interno per emulare molte delle caratteristiche dei flussi di caratteri.

Al contrario, System.in è un flusso di byte senza funzionalità di flusso di caratteri. Per utilizzare l'input standard come flusso di caratteri, eseguire il wrapping di System.in in InputStreamReader.

```java
import java.io.Console;
import java.util.Arrays;
import java.io.IOException;

public class Password {
    
    public static void main (String args[]) throws IOException {

        Console c = System.console();
        if (c == null) {
            System.err.println("No console.");
            System.exit(1);
        }

        String login = c.readLine("Enter your login: ");
        char [] oldPassword = c.readPassword("Enter your old password: ");

        if (verify(login, oldPassword)) {
            boolean noMatch;
            do {
                char [] newPassword1 = c.readPassword("Enter your new password: ");
                char [] newPassword2 = c.readPassword("Enter new password again: ");
                noMatch = ! Arrays.equals(newPassword1, newPassword2);
                if (noMatch) {
                    c.format("Passwords don't match. Try again.%n");
                } else {
                    change(login, newPassword1);
                    c.format("Password for %s changed.%n", login);
                }
                Arrays.fill(newPassword1, ' ');
                Arrays.fill(newPassword2, ' ');
            } while (noMatch);
        }

        Arrays.fill(oldPassword, ' ');
    }
    
    // Dummy change method.
    static boolean verify(String login, char[] password) {
        // This method always returns
        // true in this example.
        // Modify this method to verify
        // password according to your rules.
        return true;
    }

    // Dummy change method.
    static void change(String login, char[] password) {
        // Modify this method to change
        // password according to your rules.
    }
}
```

La classe Password segue questi passaggi:

- Tentativo di recuperare l'oggetto Console. Se l'oggetto non è disponibile, interrompere.
- Richiamare Console.readLine per richiedere e leggere il nome di accesso dell'utente.
- Richiamare Console.readPassword per richiedere e leggere la password esistente dell'utente.
- Richiamare la verifica per confermare che l'utente è autorizzato a modificare la password. (In questo esempio, la verifica è un metodo fittizio che restituisce sempre true.)
- Ripetere i seguenti passaggi finché l'utente non inserisce due volte la stessa password:
- Richiamare Console.readPassword due volte per richiedere e leggere una nuova password.
- Se l'utente ha immesso la stessa password entrambe le volte, richiamare change per modificarla. (Ancora una volta, il cambiamento è un metodo fittizio.)
- Sovrascrivi entrambe le password con spazi vuoti.
- Sovrascrivi la vecchia password con spazi vuoti.

## File I/O (Featuring NIO.2)

Il pacchetto java.nio.file e il pacchetto correlato, java.nio.file.attribute, forniscono un supporto completo per l'I/O di file e per l'accesso al file system predefinito. Sebbene l'API abbia molte classi, devi concentrarti solo su pochi punti di ingresso. Vedrai che questa API è molto intuitiva e facile da usare.

Il tutorial inizia chiedendo cos'è un percorso? Viene quindi introdotta la classe Path, il punto di ingresso principale per il pacchetto. Vengono spiegati i metodi della classe Path relativi alle operazioni sintattiche. L'esercitazione passa quindi all'altra classe primaria nel pacchetto, la classe Files, che contiene i metodi che gestiscono le operazioni sui file. Per prima cosa vengono introdotti alcuni concetti comuni a molte operazioni sui file. Il tutorial copre quindi i metodi per il controllo, l'eliminazione, la copia e lo spostamento dei file.

Il tutorial mostra come vengono gestiti i metadati, prima di passare all'I/O di file e all'I/O di directory. Vengono spiegati i file ad accesso casuale e vengono esaminati i problemi specifici dei collegamenti simbolici e fisici.

Successivamente, vengono trattati alcuni degli argomenti molto potenti, ma più avanzati. Innanzitutto, viene dimostrata la capacità di percorrere in modo ricorsivo l'albero dei file, seguita da informazioni su come cercare i file utilizzando i caratteri jolly. Successivamente, viene spiegato e dimostrato come controllare una directory per le modifiche. Quindi, i metodi che non si adattano altrove ricevono una certa attenzione.

Infine, se disponi di codice I/O di file scritto prima della versione Java SE 7, è disponibile una mappa dalla vecchia API alla nuova API, nonché informazioni importanti sul metodo File.toPath per gli sviluppatori che desiderano sfruttare la nuova API senza riscrivere il codice esistente.

### Cos'è un path? (E altri fatti sul file system)

Un file system memorizza e organizza i file su una qualche forma di supporto, generalmente uno o più dischi rigidi, in modo tale che possano essere facilmente recuperati. La maggior parte dei file system in uso oggi memorizza i file in una struttura ad albero (o gerarchica). Nella parte superiore dell'albero c'è uno (o più) nodi radice. Sotto il nodo principale ci sono file e directory (cartelle in Microsoft Windows). Ogni directory può contenere file e sottodirectory, che a loro volta possono contenere file e sottodirectory e così via, potenzialmente fino a una profondità quasi illimitata.

#### Cos'è un path?

La figura seguente mostra un albero di directory di esempio contenente un singolo nodo radice. Microsoft Windows supporta più nodi radice. Ciascun nodo radice esegue il mapping a un volume, ad esempio C:\ o D:\. Il sistema operativo Solaris supporta un singolo nodo radice, indicato dal carattere barra /.

![[appunti lmp/mod i/immagini/io-dirStructure.gif|center|300]]

Un file è identificato dal suo percorso attraverso il file system, a partire dal nodo radice. Ad esempio, il file statusReport nella figura precedente è descritto dalla seguente notazione nel sistema operativo Solaris:
`/home/sally/statusReport`

In Microsoft Windows, statusReport è descritto dalla seguente notazione:
`C:\home\sally\statusReport`

Il carattere utilizzato per separare i nomi delle directory (chiamato anche delimitatore) è specifico del file system: il sistema operativo Solaris utilizza la barra `(/)` e Microsoft Windows utilizza la barra rovesciata `(\)`.

#### Relativo o Assoluto?

Un percorso è relativo o assoluto. Un percorso assoluto contiene sempre l'elemento radice e l'elenco completo delle directory necessarie per individuare il file. Ad esempio, `/home/sally/statusReport` è un percorso assoluto. Tutte le informazioni necessarie per individuare il file sono contenute nella stringa del percorso.

Un percorso relativo deve essere combinato con un altro percorso per accedere a un file. Ad esempio, `joe/foo` è un percorso relativo. Senza ulteriori informazioni, un programma non può individuare in modo affidabile la directory `joe/foo` nel file system.

#### Collegamenti simbolici

Gli oggetti del file system sono generalmente directory o file. Tutti conoscono questi oggetti. Ma alcuni file system supportano anche la nozione di collegamenti simbolici. Un collegamento simbolico viene anche definito collegamento simbolico o collegamento software.

Un collegamento simbolico è un file speciale che funge da riferimento a un altro file. Per la maggior parte, i collegamenti simbolici sono trasparenti per le applicazioni e le operazioni sui collegamenti simbolici vengono reindirizzate automaticamente alla destinazione del collegamento. (Il file o la directory a cui si fa riferimento è chiamato la destinazione del collegamento.) Le eccezioni si verificano quando un collegamento simbolico viene eliminato o rinominato, nel qual caso il collegamento stesso viene eliminato o rinominato e non la destinazione del collegamento.

Nella figura seguente, logFile sembra essere un normale file per l'utente, ma in realtà è un collegamento simbolico a `dir/logs/HomeLogFile`. HomeLogFile è la destinazione del collegamento.

![[appunti lmp/mod i/immagini/io-symlink.gif|center|400]]

Un collegamento simbolico è solitamente trasparente per l'utente. Leggere o scrivere su un collegamento simbolico equivale a leggere o scrivere su qualsiasi altro file o directory.

La frase risolvere un collegamento significa sostituire la posizione effettiva nel file system per il collegamento simbolico. Nell'esempio, la risoluzione di logFile restituisce `dir/logs/HomeLogFile`.

Negli scenari del mondo reale, la maggior parte dei file system fa un uso liberale dei collegamenti simbolici. Occasionalmente, un collegamento simbolico creato con noncuranza può causare un riferimento circolare. Un riferimento circolare si verifica quando la destinazione di un collegamento rimanda al collegamento originale. Il riferimento circolare potrebbe essere indiretto: la directory a punta alla directory b, che punta alla directory c, che contiene una sottodirectory che punta alla directory a. I riferimenti circolari possono causare problemi quando un programma percorre ricorsivamente una struttura di directory. Tuttavia, questo scenario è stato tenuto in considerazione e non causerà il ciclo infinito del programma.

### La classe Path

La classe Path, introdotta nella versione Java SE 7, è uno dei principali punti di ingresso del pacchetto java.nio.file. Se la tua applicazione utilizza file I/O, vorrai conoscere le potenti funzionalità di questa classe.

Come suggerisce il nome, la classe Path è una rappresentazione programmatica di un percorso nel file system. Un oggetto Path contiene il nome del file e l'elenco di directory utilizzati per costruire il percorso e viene utilizzato per esaminare, individuare e manipolare i file.

Un'istanza Path riflette la piattaforma sottostante. Nel sistema operativo Solaris, un percorso utilizza la sintassi di Solaris (/home/joe/foo) e in Microsoft Windows, un percorso utilizza la sintassi di Windows (C:\home\joe\foo). Un percorso non è indipendente dal sistema. Non è possibile confrontare un percorso da un file system Solaris e aspettarsi che corrisponda a un percorso da un file system Windows, anche se la struttura della directory è identica ed entrambe le istanze individuano lo stesso file relativo.

Il file o la directory corrispondente al percorso potrebbe non esistere. Puoi creare un'istanza di Path e manipolarla in vari modi: puoi accodarla, estrarne pezzi, confrontarla con un altro percorso. Al momento opportuno, è possibile utilizzare i metodi della classe Files per verificare l'esistenza del file corrispondente al Path, creare il file, aprirlo, eliminarlo, modificarne i permessi e così via.

#### Operazioni su Path

La classe Path include vari metodi che possono essere utilizzati per ottenere informazioni sul percorso, accedere agli elementi del percorso, convertire il percorso in altre forme o estrarre parti di un percorso. Esistono anche metodi per abbinare la stringa del percorso e metodi per rimuovere le ridondanze in un percorso. Questa lezione affronta questi metodi Path, a volte chiamati operazioni sintattiche, perché operano sul percorso stesso e non accedono al file system

##### Creazione di un percorso

Un'istanza Path contiene le informazioni utilizzate per specificare la posizione di un file o di una directory. Nel momento in cui viene definito, un Sentiero viene fornito con una serie di uno o più nomi. Potrebbero essere inclusi un elemento radice o un nome file, ma nessuno dei due è obbligatorio. Un percorso potrebbe consistere in una singola directory o nome di file.

È possibile creare facilmente un oggetto Path utilizzando uno dei seguenti metodi get dalla classe helper Paths (notare il plurale):

```java
Path p1 = Paths.get("/tmp/foo");
Path p2 = Paths.get(args[0]);
Path p3 = Paths.get(URI.create("file:///Users/joe/FileTest.java"));
```

##### Recupero di informazioni su un percorso

Puoi pensare al percorso come alla memorizzazione di questi elementi del nome come una sequenza. L'elemento più alto nella struttura della directory si trova all'indice 0. L'elemento più basso nella struttura della directory si trova all'indice $[n-1]$, dove n è il numero di elementi del nome nel percorso. Sono disponibili metodi per recuperare singoli elementi o una sottosequenza del percorso utilizzando questi indici.

Gli esempi in questa lezione utilizzano la seguente struttura di directory.

![[appunti lmp/mod i/immagini/io-dirStructure 1.gif|center]]

Il seguente frammento di codice definisce un'istanza Path e quindi richiama diversi metodi per ottenere informazioni sul percorso:

```java
// None of these methods requires that the file corresponding
// to the Path exists.
// Microsoft Windows syntax
Path path = Paths.get("C:\\home\\joe\\foo");

// Solaris syntax
Path path = Paths.get("/home/joe/foo");

System.out.format("toString: %s%n", path.toString());
System.out.format("getFileName: %s%n", path.getFileName());
System.out.format("getName(0): %s%n", path.getName(0));
System.out.format("getNameCount: %d%n", path.getNameCount());
System.out.format("subpath(0,2): %s%n", path.subpath(0,2));
System.out.format("getParent: %s%n", path.getParent());
System.out.format("getRoot: %s%n", path.getRoot());
```

