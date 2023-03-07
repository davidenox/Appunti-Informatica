
# Espressioni,Blocchi e Statements
## Espressioni
_Def_
Un'espressione è un costrutto formato da variabili,operatori, invocazioni di metodi, che vengono costruiti accordandosi alla sintassi del linguaggio
**Esempio**
```java
int cadence = 0;
anArray[0] = 100;
System.out.println("Element 1 at index 0: "+anArray[0]);
in result = 1+2;
if(value1==value2)
	System.out.println("value1==value2");
```
Il tipo di dati del valore restituito da un'espressione dipende dagli elementi utilizzati nell'espressione. L'espressione cadence = 0 restituisce un int perché l'operatore di assegnazione restituisce un valore dello stesso tipo di dati dell'operando di sinistra; in questo caso, la cadenza è un int
Il linguaggio di programmazione Java consente di costruire espressioni composte da varie espressioni più piccole purché il tipo di dati richiesto da una parte dell'espressione corrisponda al tipo di dati dell'altra. Ecco un esempio di espressione composta:
```java
1*2*3
```

In questo esempio particolare, l'ordine in cui viene valutata l'espressione non è importante perché il risultato della moltiplicazione è indipendente dall'ordine; il risultato è sempre lo stesso, indipendentemente dall'ordine in cui si applicano le moltiplicazioni. Tuttavia, questo non è vero per tutte le espressioni. Ad esempio, l'espressione seguente fornisce risultati diversi, a seconda che si esegua prima l'operazione di addizione o divisione:

```java
x + y / 100 // ambiguo
```
È possibile specificare esattamente come verrà valutata un'espressione utilizzando le parentesi bilanciate: ( e ). Ad esempio, per rendere univoca l'espressione precedente, puoi scrivere quanto segue:
```java
(x + y) / 100 // non ambiguo, consigliato
```

Se non si indica esplicitamente l'ordine per le operazioni da eseguire, l'ordine è determinato dalla precedenza assegnata agli operatori in uso all'interno dell'espressione. Gli operatori che hanno una precedenza più alta vengono valutati per primi. Ad esempio, l'operatore di divisione ha una precedenza maggiore rispetto all'operatore di addizione. Pertanto, le due affermazioni seguenti sono equivalenti:
```java
x + y / 100
x + (y / 100) // non ambiguo, consigliato
```

Quando si scrivono espressioni composte, sii esplicito e indica tra parentesi quali operatori devono essere valutati per primi. Questa pratica semplifica la lettura e la manutenzione del codice.
## Statements

GLi statements sono più o meno equivalenti alle frasi nelle lingue naturali. Un'istruzione costituisce un'unità di esecuzione completa. I seguenti tipi di espressioni possono essere trasformati in un'istruzione terminando l'espressione con un punto e virgola (;).
- Espressioni di assegnazione
- Qualsiasi uso di ++ o --
- Invocazioni di metodo
- Espressioni di creazione di oggetti

Tali affermazioni sono dette espressioni di espressione
Di seguito sono riportati alcuni esempi di affermazioni di espressione.
```java
// frase di assegnazione
aValore = 8933.234;
// istruzione di incremento
aValore++;
// Istruzione di invocazione del metodo
System.out.println("Ciao mondo!");
// istruzione di creazione dell'oggetto
Bicicletta myBike = nuova Bicicletta();
```

## Blocchi
Un blocco è un gruppo di zero o più istruzioni tra parentesi graffe e può essere utilizzato ovunque sia consentita una singola istruzione. L'esempio seguente, BlockDemo, illustra l'uso dei blocchi:
```java
class BlockDemo {
     public static void main(String[] args) {
          boolean condition = true;
          if (condition) { **// begin block 1**
               System.out.println("Condition is true.");
          } **// end block one**
          else { **// begin block 2**
               System.out.println("Condition is false.");
          } **// end block 2**
     }
}
```

# Control Flow Statements

Le istruzioni all'interno dei file di origine vengono generalmente eseguite dall'alto verso il basso, nell'ordine in cui appaiono. Le istruzioni di flusso di controllo, tuttavia, interrompono il flusso di esecuzione impiegando processi decisionali, cicli e ramificazioni, consentendo al programma di eseguire condizionalmente particolari blocchi di codice. Questa sezione descrive le istruzioni decisionali (if-then, if-then-else, switch), le istruzioni di looping (for, while, do-while) e le istruzioni branching (break, continue, return) supportate da Java linguaggio di programmazione.

## If-then e If-then-else
### If-then
L'istruzione if-then è la più elementare di tutte le istruzioni di flusso di controllo. Dice al tuo programma di eseguire una determinata sezione di codice solo se un particolare test restituisce true. Ad esempio, la classe Bicicletta potrebbe consentire ai freni di ridurre la velocità della bicicletta solo se la bicicletta è già in movimento. Una possibile implementazione del metodo applyBrakes potrebbe essere la seguente:
```java
void applyBrakes() {
    // the "if" clause: bicycle must be moving
    if (isMoving){ 
        // the "then" clause: decrease current speed
        currentSpeed--;
    }
}
```
Se questo test restituisce false (il che significa che la bicicletta non è in movimento), il controllo salta alla fine dell'istruzione if-then.

Inoltre, le parentesi graffe di apertura e chiusura sono facoltative, a condizione che la clausola "then" contenga una sola affermazione:
```java
void applyBrakes() {
    // same as above, but without braces 
    if (isMoving)
        currentSpeed--;
}
```
### If-then-else
L'istruzione if-then-else fornisce un percorso di esecuzione secondario quando una clausola "if" restituisce false. È possibile utilizzare un'istruzione if-then-else nel metodo applyBrakes per eseguire alcune azioni se i freni vengono applicati quando la bicicletta non è in movimento. In questo caso, l'azione è semplicemente stampare un messaggio di errore che indica che la bicicletta si è già fermata.
```java
void applyBrakes() {
    if (isMoving) {
        currentSpeed--;
    } else {
        System.err.println("The bicycle has already stopped!");
    } 
}
```
Il seguente programma, IfElseDemo, assegna un voto in base al valore di un punteggio del test: una A per un punteggio pari o superiore al 90%, una B per un punteggio pari o superiore all'80% e così via.
```java
class IfElseDemo {
    public static void main(String[] args) {

        int testscore = 76;
        char grade;

        if (testscore >= 90) {
            grade = 'A';
        } else if (testscore >= 80) {
            grade = 'B';
        } else if (testscore >= 70) {
            grade = 'C';
        } else if (testscore >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        System.out.println("Grade = " + grade);
    }
}
```

## Switch
A differenza delle istruzioni if-then e if-then-else, l'istruzione switch può avere un numero di possibili percorsi di esecuzione. Uno switch funziona con i tipi di dati primitivi byte, short, char e int.
Nell'esempio di codice seguente, SwitchDemo, viene dichiarato un int denominato month il cui valore rappresenta un mese. Il codice visualizza il nome del mese, in base al valore del mese, utilizzando l'istruzione switch.
```java
public class SwitchDemo {
    public static void main(String[] args) {

        int month = 8;
        String monthString;
        switch (month) {
            case 1:  monthString = "January";
                     break;
            case 2:  monthString = "February";
                     break;
            case 3:  monthString = "March";
                     break;
            case 4:  monthString = "April";
                     break;
            case 5:  monthString = "May";
                     break;
            case 6:  monthString = "June";
                     break;
            case 7:  monthString = "July";
                     break;
            case 8:  monthString = "August";
                     break;
            case 9:  monthString = "September";
                     break;
            case 10: monthString = "October";
                     break;
            case 11: monthString = "November";
                     break;
            case 12: monthString = "December";
                     break;
            default: monthString = "Invalid month";
                     break;
        }
        System.out.println(monthString);
    }
}
```

Un altro punto di interesse è lao statement `break`. Ogni istruzione break termina l'istruzione switch che la racchiude. Il flusso di controllo continua con la prima istruzione che segue il blocco switch. Le istruzioni break sono necessarie perché senza di esse, le istruzioni nei blocchi switch falliscono: tutte le istruzioni dopo l'etichetta case corrispondente vengono eseguite in sequenza, indipendentemente dall'espressione delle etichette case successive, fino a quando non viene incontrata un'istruzione break. Il programma SwitchDemoFallThrough mostra le istruzioni in un blocco switch che non funziona. Il programma visualizza il mese corrispondente al mese intero e i mesi che seguono nell'anno:
```java
public class SwitchDemoFallThrough {

    public static void main(String[] args) {
        java.util.ArrayList<String> futureMonths =
            new java.util.ArrayList<String>();

        int month = 8;

        switch (month) {
            case 1:  futureMonths.add("January");
            case 2:  futureMonths.add("February");
            case 3:  futureMonths.add("March");
            case 4:  futureMonths.add("April");
            case 5:  futureMonths.add("May");
            case 6:  futureMonths.add("June");
            case 7:  futureMonths.add("July");
            case 8:  futureMonths.add("August");
            case 9:  futureMonths.add("September");
            case 10: futureMonths.add("October");
            case 11: futureMonths.add("November");
            case 12: futureMonths.add("December");
                     break;
            default: break;
        }

        if (futureMonths.isEmpty()) {
            System.out.println("Invalid month number");
        } else {
            for (String monthName : futureMonths) {
               System.out.println(monthName);
            }
        }
    }
}
```

Tecnicamente, l'interruzione finale non è richiesta perché il flusso esce dall'istruzione switch. Si consiglia di utilizzare un'interruzione in modo che la modifica del codice sia più semplice e meno soggetta a errori. La sezione predefinita gestisce tutti i valori che non sono gestiti in modo esplicito da una delle sezioni del caso.

Nell'esempio di codice seguente, SwitchDemo2, viene illustrato come un'istruzione può avere più etichette maiuscole. L'esempio di codice calcola il numero di giorni in un mese particolare:
```java
class SwitchDemo2 {
    public static void main(String[] args) {

        int month = 2;
        int year = 2000;
        int numDays = 0;

        switch (month) {
            case 1: case 3: case 5:
            case 7: case 8: case 10:
            case 12:
                numDays = 31;
                break;
            case 4: case 6:
            case 9: case 11:
                numDays = 30;
                break;
            case 2:
                if (((year % 4 == 0) && 
                     !(year % 100 == 0))
                     || (year % 400 == 0))
                    numDays = 29;
                else
                    numDays = 28;
                break;
            default:
                System.out.println("Invalid month.");
                break;
        }
        System.out.println("Number of Days = "
                           + numDays);
    }
}
```
### Usare stringhe nello switch
In Java SE 7 e versioni successive, è possibile utilizzare un oggetto String nell'espressione dell'istruzione switch. Nell'esempio di codice seguente, StringSwitchDemo, viene visualizzato il numero del mese in base al valore della stringa denominata month:
```java
public class StringSwitchDemo {

    public static int getMonthNumber(String month) {

        int monthNumber = 0;

        if (month == null) {
            return monthNumber;
        }

        switch (month.toLowerCase()) {
            case "january":
                monthNumber = 1;
                break;
            case "february":
                monthNumber = 2;
                break;
            case "march":
                monthNumber = 3;
                break;
            case "april":
                monthNumber = 4;
                break;
            case "may":
                monthNumber = 5;
                break;
            case "june":
                monthNumber = 6;
                break;
            case "july":
                monthNumber = 7;
                break;
            case "august":
                monthNumber = 8;
                break;
            case "september":
                monthNumber = 9;
                break;
            case "october":
                monthNumber = 10;
                break;
            case "november":
                monthNumber = 11;
                break;
            case "december":
                monthNumber = 12;
                break;
            default: 
                monthNumber = 0;
                break;
        }

        return monthNumber;
    }

    public static void main(String[] args) {

        String month = "August";

        int returnedMonthNumber =
            StringSwitchDemo.getMonthNumber(month);

        if (returnedMonthNumber == 0) {
            System.out.println("Invalid month");
        } else {
            System.out.println(returnedMonthNumber);
        }
    }
}
```

## While e Do-While
### While
L'istruzione while esegue continuamente un blocco di istruzioni mentre una particolare condizione è vera. La sua sintassi può essere espressa come:
```java
while (expression) {
     statement(s)
}
```
L'istruzione while valuta l'espressione, che deve restituire un valore booleano. Se l'espressione restituisce true, l'istruzione while esegue le istruzioni nel blocco while. L'istruzione while continua a testare l'espressione ed eseguire il relativo blocco finché l'espressione non restituisce false. L'utilizzo dell'istruzione while per stampare i valori da 1 a 10 può essere eseguito come nel seguente programma WhileDemo:
```java
class WhileDemo {
    public static void main(String[] args){
        int count = 1;
        while (count < 11) {
            System.out.println("Count is: " + count);
            count++;
        }
    }
}
```

Puoi implementare un ciclo infinito usando l'istruzione while come segue:
```java
while (true){
    // your code goes here
}
```

### Do-While
Il linguaggio di programmazione Java fornisce anche un'istruzione do-while, che può essere espressa come segue:
```java
do {
     statement(s)
} while (expression);
```
La differenza tra do-while e while è che do-while valuta la sua espressione nella parte inferiore del ciclo anziché nella parte superiore. Pertanto, le istruzioni all'interno del blocco do vengono sempre eseguite almeno una volta, come mostrato nel seguente programma DoWhileDemo:
```java
class DoWhileDemo {
    public static void main(String[] args){
        int count = 1;
        do {
            System.out.println("Count is: " + count);
            count++;
        } while (count < 11);
    }
}
```

## For
L'istruzione for fornisce un modo compatto per eseguire l'iterazione su un intervallo di valori. I programmatori spesso lo chiamano "ciclo for" a causa del modo in cui viene ripetuto ripetutamente fino a quando una particolare condizione non è soddisfatta. La forma generale dell'istruzione for può essere espressa come segue:

```java
for (_initialization_; _termination_;
     _increment_) {
    _statement(s)_
}
```
Quando si utilizza questa versione dell'istruzione for, tenere presente che:
- L'espressione di inizializzazione inizializza il ciclo; viene eseguito una volta, all'inizio del ciclo.
- Quando l'espressione di terminazione restituisce false, il ciclo termina.
- L'espressione di incremento viene richiamata dopo ogni iterazione del ciclo; è perfettamente accettabile che questa espressione incrementi o decrementi un valore.

Il seguente programma, ForDemo, utilizza la forma generale dell'istruzione for per stampare i numeri da 1 a 10 sullo standard output:
```java
class ForDemo {
    public static void main(String[] args){
         for(int i=1; i<11; i++){
              System.out.println("Count is: " + i);
         }
    }
}
```

Nota come il codice dichiara una variabile all'interno dell'espressione di inizializzazione. L'ambito di questa variabile si estende dalla sua dichiarazione alla fine del blocco governato dall'istruzione for, quindi può essere utilizzata anche nelle espressioni di terminazione e incremento. Se la variabile che controlla un'istruzione for non è necessaria al di fuori del ciclo, è meglio dichiarare la variabile nell'espressione di inizializzazione. I nomi i, j e k sono spesso usati per controllare i cicli for; dichiararli all'interno dell'espressione di inizializzazione ne limita la durata e riduce gli errori.

Le tre espressioni del ciclo for sono facoltative; un ciclo infinito può essere creato come segue:
```java
// infinite loop
for ( ; ; ) {
    
    // your code goes here
}
```

L'istruzione for ha anche un altro modulo progettato per l'iterazione attraverso raccolte e matrici. Questo modulo viene talvolta definito come l'istruzione for avanzata e può essere utilizzato per rendere i cicli più compatti e di facile lettura. Per dimostrare, considera la seguente matrice, che contiene i numeri da 1 a 10:
```java
int[] numbers = {1,2,3,4,5,6,7,8,9,10};
```

Il seguente programma, EnhancedForDemo, usa il for migliorato per scorrere l'array:
```java
class EnhancedForDemo {
    public static void main(String[] args){
         int[] numbers = 
             {1,2,3,4,5,6,7,8,9,10};
         for (int item : numbers) {
             System.out.println("Count is: " + item);
         }
    }
}
```

## Branching Statements
### Break
L'istruzione break ha due forme: etichettata e non etichettata. Hai visto il modulo senza etichetta nella discussione precedente dell'istruzione switch. Puoi anche utilizzare un'interruzione senza etichetta per terminare un ciclo for, while o do-while, come mostrato nel seguente programma BreakDemo:
```java
class BreakDemo {
    public static void main(String[] args) {

        int[] arrayOfInts = 
            { 32, 87, 3, 589,
              12, 1076, 2000,
              8, 622, 127 };
        int searchfor = 12;

        int i;
        boolean foundIt = false;

        for (i = 0; i < arrayOfInts.length; i++) {
            if (arrayOfInts[i] == searchfor) {
                foundIt = true;
                **break;**
            }
        }

        if (foundIt) {
            System.out.println("Found " + searchfor + " at index " + i);
        } else {
            System.out.println(searchfor + " not in the array");
        }
    }
}
```

Un'istruzione break senza etichetta termina l'istruzione switch più interna, for, while o do-while, ma un'interruzione con etichetta termina un'istruzione esterna. Il programma seguente, BreakWithLabelDemo, è simile al programma precedente, ma usa i cicli for nidificati per cercare un valore in una matrice bidimensionale. Quando il valore viene trovato, un'interruzione etichettata termina il ciclo for esterno (etichettato "ricerca"):

```java
class BreakWithLabelDemo {
    public static void main(String[] args) {

        int[][] arrayOfInts = { 
            { 32, 87, 3, 589 },
            { 12, 1076, 2000, 8 },
            { 622, 127, 77, 955 }
        };
        int searchfor = 12;

        int i;
        int j = 0;
        boolean foundIt = false;

    search:
        for (i = 0; i < arrayOfInts.length; i++) {
            for (j = 0; j < arrayOfInts[i].length;
                 j++) {
                if (arrayOfInts[i][j] == searchfor) {
                    foundIt = true;
                    break search;
                }
            }
        }

        if (foundIt) {
            System.out.println("Found " + searchfor + " at " + i + ", " + j);
        } else {
            System.out.println(searchfor + " not in the array");
        }
    }
}
```

L'istruzione break termina l'istruzione etichettata; non trasferisce il flusso di controllo all'etichetta. Il flusso di controllo viene trasferito all'istruzione immediatamente dopo l'istruzione etichettata (terminata).

### Continue
L'istruzione continue salta l'iterazione corrente di un ciclo for, while o do-while. Il modulo senza etichetta salta alla fine del corpo del ciclo più interno e valuta l'espressione booleana che controlla il ciclo. Il seguente programma, ContinueDemo , scorre una stringa, contando le occorrenze della lettera "p". Se il carattere corrente non è una p, l'istruzione continue salta il resto del ciclo e passa al carattere successivo. Se è una "p", il programma incrementa il conteggio delle lettere.
```java
class ContinueDemo {
    public static void main(String[] args) {

        String searchMe = "peter piper picked a " + "peck of pickled peppers";
        int max = searchMe.length();
        int numPs = 0;

        for (int i = 0; i < max; i++) {
            // interested only in p's
            if (searchMe.charAt(i) != 'p')
                continue;

            // process p's
            numPs++;
        }
        System.out.println("Found " + numPs + " p's in the string.");
    }
}
```

Un'istruzione continue con etichetta salta l'iterazione corrente di un ciclo esterno contrassegnato con l'etichetta data. Il seguente programma di esempio, ContinueWithLabelDemo, utilizza cicli nidificati per cercare una sottostringa all'interno di un'altra stringa. Sono necessari due cicli nidificati: uno per scorrere la sottostringa e uno per scorrere la stringa cercata. Il programma seguente, ContinueWithLabelDemo, usa la forma etichettata di continue per saltare un'iterazione nel ciclo esterno.
```java
class ContinueWithLabelDemo {
    public static void main(String[] args) {

        String searchMe = "Look for a substring in me";
        String substring = "sub";
        boolean foundIt = false;

        int max = searchMe.length() - 
                  substring.length();

    test:
        for (int i = 0; i <= max; i++) {
            int n = substring.length();
            int j = i;
            int k = 0;
            while (n-- != 0) {
                if (searchMe.charAt(j++) != substring.charAt(k++)) {
                    continue test;
                }
            }
            foundIt = true;
                break test;
        }
        System.out.println(foundIt ? "Found it" : "Didn't find it");
    }
}
```

### Return
L'ultima delle istruzioni di ramificazione è la dichiarazione di ritorno(**return**). L'istruzione return esce dal metodo corrente e il flusso di controllo torna al punto in cui è stato richiamato il metodo. L'istruzione return ha due forme: una che restituisce un valore e una che non lo fa. Per restituire un valore, metti semplicemente il valore (o un'espressione che calcola il valore) dopo la parola chiave return.
```java
return ++count;
```

Il tipo di dati del valore restituito deve corrispondere al tipo del valore restituito dichiarato del metodo. Quando un metodo viene dichiarato void, utilizzare il modulo di ritorno che non restituisce un valore.
```java
return;
```
