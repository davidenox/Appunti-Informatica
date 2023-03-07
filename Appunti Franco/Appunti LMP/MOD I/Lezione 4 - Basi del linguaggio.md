# Basi del linguaggio

- [[Lezione 4 - Basi del linguaggio#Variabili|Variabili]]
- [[Lezione 4 - Basi del linguaggio#Operatori|Operatori]]
- [[Lezione 5 - Espressioni,Blocchi e Statement#Espressioni,Blocchi e Statements|Espressioni,Blocchi e Statements]]
- [[Lezione 5 - Espressioni,Blocchi e Statement#Control Flow Statements|Control Flow Statements]]

## Variabili
Come hai appreso nella lezione precedente, un oggetto memorizza il suo stato nei campi.
```java
int cadence = 0;
int speed = 0;
int gear = 1;
```
Nel linguaggio di programmazione Java vengono utilizzati entrambi i termini "campo" e "variabile".
Il linguaggio di programmazione Java definisce i seguenti tipi di variabili:
- **Variabili di istanza (campi non statici)** Tecnicamente, gli oggetti memorizzano i loro stati individuali in "campi non statici", ovvero campi dichiarati senza la parola chiave static. I campi non statici sono noti anche come variabili di istanza perché i loro valori sono univoci per ciascuna istanza di una classe (per ogni oggetto, in altre parole); la velocità attuale di una bicicletta è indipendente dalla velocità attuale di un'altra.
- **Variabili di classe (campi statici)** Una variabile di classe è qualsiasi campo dichiarato con il modificatore static; questo dice al compilatore che esiste esattamente una copia di questa variabile, indipendentemente da quante volte la classe è stata istanziata. Un campo che definisce il numero di marce per un particolare tipo di bicicletta potrebbe essere contrassegnato come statico poiché concettualmente lo stesso numero di marce si applicherà a tutte le istanze. Il codice `static int numGears = 6;` creerebbe un tale campo statico. Inoltre, è possibile aggiungere la parola chiave final per indicare che il numero di marce non cambierà mai
- **Variabili locali**: Analogamente al modo in cui un oggetto memorizza il proprio stato nei campi, un metodo spesso memorizza il proprio stato temporaneo in variabili locali. La sintassi per la dichiarazione di una variabile locale è simile alla dichiarazione di un campo (ad esempio, int count = 0;). Non esiste una parola chiave speciale che designa una variabile come locale; tale determinazione deriva interamente dalla posizione in cui è dichiarata la variabile, che è tra le parentesi graffe di apertura e chiusura di un metodo. In quanto tali, le variabili locali sono visibili solo ai metodi in cui sono dichiarate; non sono accessibili dal resto della classe.
- **Parametri** Hai già visto esempi di parametri, sia nella classe Bicycle che nel metodo principale di "Hello World!" applicazione. Ricordiamo che la firma per il metodo main è `public static void main(String[] args)`. Qui, la variabile args è il parametro di questo metodo. L'importante da ricordare è che i parametri sono sempre classificati come "variabili" e non come "campi". Questo vale anche per altri costrutti che accettano parametri (come costruttori e gestori di eccezioni) di cui imparerai più avanti nel tutorial.

### Denominazione delle variabili

Ogni linguaggio di programmazione ha il proprio insieme di regole e convenzioni per i tipi di nomi che puoi usare. Le regole e le convenzioni per la denominazione delle variabili possono essere riassunte come segue:
- I nomi delle variabili fanno distinzione tra maiuscole e minuscole(**Case Sensitive**). Il nome di una variabile può essere qualsiasi identificatore legale: una sequenza illimitata di lettere e cifre Unicode, che inizia con una lettera, il simbolo del dollaro $ o il carattere di sottolineatura(underscore). La convenzione, tuttavia, è di iniziare sempre i nomi delle variabili con una lettera, non con "$" o underscore. Gli spazi bianchi non sono consentiti.
- I caratteri successivi possono essere lettere, cifre, segni di dollaro o caratteri di sottolineatura. Anche a questa regola valgono le convenzioni (e il buon senso). Quando scegli un nome per le tue variabili, usa parole complete invece di abbreviazioni criptiche. In questo modo il tuo codice sarà più facile da leggere e capire. In molti casi renderà anche il tuo codice auto-documentante;Tieni inoltre presente che il nome che scegli non deve essere una parola [chiave o una parola riservata](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/_keywords.html).
- Se il nome che scegli è composto da una sola parola, scrivi quella parola in tutte le lettere minuscole. Se è composta da più di una parola, metti in maiuscolo la prima lettera di ogni parola successiva. I nomi gearRatio e currentGear sono ottimi esempi di questa convenzione. Se la tua variabile memorizza un valore costante, come `static final int NUM_GEARS = 6`, la convenzione cambia leggermente, mettendo in maiuscolo ogni lettera e separando le parole successive con il carattere di sottolineatura. Per convenzione, il carattere di sottolineatura non viene mai utilizzato altrove.

### Tipi di dato primitivi

Il tipo di dati di una variabile determina i valori che può contenere, oltre alle operazioni che possono essere eseguite su di essa. Oltre a int, il linguaggio di programmazione Java supporta altri sette tipi di dati primitivi. Un tipo primitivo è predefinito dal linguaggio ed è denominato da una parola chiave riservata. I valori primitivi non condividono lo stato con altri valori primitivi. Gli otto tipi di dati primitivi supportati dal linguaggio di programmazione Java sono:
- **byte**: il tipo di dati byte è un intero in complemento a due con segno a 8 bit. Ha un valore minimo di -128 e un valore massimo di 127 (incluso). Il tipo di dati byte può essere utile per risparmiare memoria in array di grandi dimensioni, dove il risparmio di memoria è davvero importante. Possono anche essere usati al posto di int dove i loro limiti aiutano a chiarire il tuo codice; il fatto che l'intervallo di una variabile sia limitato può servire come forma di documentazione.
- **short**: il tipo di dati short è un intero in complemento a due con segno a 16 bit. Ha un valore minimo di -32.768 e un valore massimo di 32.767 (incluso). Come per byte, si applicano le stesse linee guida: puoi usare un short per risparmiare memoria in grandi array, in situazioni in cui il risparmio di memoria è davvero importante.
- **int**: per impostazione predefinita, il tipo di dati int è un intero in complemento a due con segno a 32 bit, che ha un valore minimo di -231 e un valore massimo di 231-1. In Java SE 8 e versioni successive, è possibile utilizzare il tipo di dati int per rappresentare un intero a 32 bit senza segno, che ha un valore minimo di 0 e un valore massimo di 232-1. Utilizzare la classe Integer per utilizzare il tipo di dati int come intero senza segno.
- **long**: il tipo di dati long è un intero in complemento a due a 64 bit. Il segno lungo ha un valore minimo di -263 e un valore massimo di 263-1. In Java SE 8 e versioni successive, è possibile utilizzare il tipo di dati long per rappresentare una lunghezza a 64 bit senza segno, che ha un valore minimo di 0 e un valore massimo di 264-1. Utilizzare questo tipo di dati quando è necessario un intervallo di valori più ampio di quelli forniti da int.
- **float**: il tipo di dati float è un virgola mobile IEEE 754 a precisione singola a 32 bit. Come per i consigli per byte e short, utilizzare un float (invece di double) se è necessario risparmiare memoria in grandi matrici di numeri in virgola mobile.
- **double**: il tipo di dati double è una virgola mobile IEEE 754 a doppia precisione a 64 bit. Per i valori decimali, questo tipo di dati è generalmente la scelta predefinita.
- **boolean**: il tipo di dati booleano ha solo due valori possibili: true e false. Utilizzare questo tipo di dati per semplici flag che tengono traccia delle condizioni vero/falso. Questo tipo di dati rappresenta un bit di informazione, ma la sua "dimensione" non è qualcosa che è definito con precisione.
- **char**: il tipo di dati char è un singolo carattere Unicode a 16 bit. Ha un valore minimo di `'\u0000'` (o 0) e un valore massimo di `'\uffff'` (o 65.535 inclusi).
### Valori di default
| Data Type             | Default Value |
| --------------------- | ------------- |
| byte                  | 0             |
| short                 | 0             |
| int                   | 0             |
| long                  | 0L            |
| float                 | 0.0f          |
| double                | 0.0d          |
| char                  | `\u0000`      |
| String(or any object) | null          |
| boolean               | false         |

### Array
_Def_
Un array è un oggetto contenitore che contiene un numero fisso di valori di un singolo tipo. La lunghezza di un array viene stabilita al momento della creazione dell'array. Dopo la creazione, la sua lunghezza è fissata. Hai già visto un esempio di array, nel metodo principale di "Hello World!" applicazione.
![[objects-tenElementArray.gif|center]]

Ogni elemento in un array è chiamato elemento e ogni elemento è accessibile dal suo indice numerico.
Il programma seguente, ArrayDemo, crea una matrice di numeri interi, inserisce alcuni valori nella matrice e stampa ogni valore sull'output standard.
```java
class ArrayDemo {
    public static void main(String[] args) {
        // declares an array of integers
        int[] anArray;

        // allocates memory for 10 integers
        anArray = new int[10];
           
        // initialize first element
        anArray[0] = 100;
        // initialize second element
        anArray[1] = 200;
        // and so forth
        anArray[2] = 300;
        anArray[3] = 400;
        anArray[4] = 500;
        anArray[5] = 600;
        anArray[6] = 700;
        anArray[7] = 800;
        anArray[8] = 900;
        anArray[9] = 1000;

        System.out.println("Element at index 0: "
                           + anArray[0]);
        System.out.println("Element at index 1: "
                           + anArray[1]);
        System.out.println("Element at index 2: "
                           + anArray[2]);
        System.out.println("Element at index 3: "
                           + anArray[3]);
        System.out.println("Element at index 4: "
                           + anArray[4]);
        System.out.println("Element at index 5: "
                           + anArray[5]);
        System.out.println("Element at index 6: "
                           + anArray[6]);
        System.out.println("Element at index 7: "
                           + anArray[7]);
        System.out.println("Element at index 8: "
                           + anArray[8]);
        System.out.println("Element at index 9: "
                           + anArray[9]);
    }
}
```


Il programma precedente dichiara un array (denominato anArray) con la seguente riga di codice:
```java
// declares an array of integers
int[] anArray;
```

Come le dichiarazioni per variabili di altri tipi, una dichiarazione di array ha due componenti: il tipo dell'array e il nome dell'array. Il tipo di un array viene scritto come type[], dove type è il tipo di dati degli elementi contenuti; le parentesi sono simboli speciali che indicano che questa variabile contiene una matrice. La dimensione dell'array non fa parte del suo tipo (motivo per cui le parentesi sono vuote).
Allo stesso modo, puoi dichiarare array di altri tipi:
```java
byte[] anArrayOfBytes;
short[] anArrayOfShorts;
long[] anArrayOfLongs;
float[] anArrayOfFloats;
double[] anArrayOfDoubles;
boolean[] anArrayOfBooleans;
char[] anArrayOfChars;
String[] anArrayOfStrings;
```

>**Oss**
>La parola chiave _new_ non c'è quando si crea un array perchè in Java la new è sempre associata ad un allocazione di memoria per la creazione di un oggetto
>Infatt, la parola chiave new, si usa dopo la dichiarazione di un array per indicare la grandezza dell'array
>Es: `int[] anArray; anArray = new int[10]`

Puoi anche dichiarare un array di array (nota anche come array multidimensionale) utilizzando due o più insiemi di parentesi. Ad ogni elemento, quindi, deve accedere un numero corrispondente di valori di indice.

Nel linguaggio di programmazione Java, un array multidimensionale è un array i cui componenti sono essi stessi array. Questo è diverso dagli array in C o Fortran. Una conseguenza di ciò è che le righe possono variare in lunghezza, come mostrato nel seguente programma MultiDimArrayDemo:

```java
class MultiDimArrayDemo {
    public static void main(String[] args) {
        String[][] names = {
            {"Mr. ", "Mrs. ", "Ms. "},
            {"Smith", "Jones"}
        };
        // Mr. Smith
        System.out.println(names[0][0] + names[1][0]);
        // Ms. Jones
        System.out.println(names[0][2] + names[1][1]);
    }
}
```

## Operatori
Gli operatori nella tabella seguente sono elencati in base all'ordine di precedenza. Più un operatore appare vicino alla parte superiore della tabella, maggiore è la sua precedenza. Gli operatori con una precedenza più alta vengono valutati prima degli operatori con una precedenza relativamente più bassa. Gli operatori sulla stessa linea hanno la stessa precedenza. Quando nella stessa espressione compaiono operatori di uguale precedenza, deve governare una regola che viene valutata per prima. Tutti gli operatori binari, ad eccezione degli operatori di assegnazione, vengono valutati da sinistra a destra; gli operatori di assegnazione vengono valutati da destra a sinistra.

| Operatori            | Precendeza                            |
| -------------------- | ------------------------------------- |
| postfix              | _expr_++ _expr_--                     |
| unary                | ++_expr_ --_expr_ +_expr_ -_expr_ ~ ! |
| multiplicative       | * / %                                 |
| additive             | + -                                   |
| shift                | << >> >>>                             |
| relational           | < > <= >= instanceof                  |
| equality             | == !=                                 |
| bitwise AND          | &                                     |
| bitwise exclusive OR | ^                                     |
| bitwise inclusive OR | pipe                                |
| logical AND          | &&                                    |
| logical OR           | double Pipe                                       |
| ternary              | ? :                                   |
| assignment           | = += -= *= /= %= &= ^= |= <<= >>= >>>=                                      |

### Operatori aritmetici
Il linguaggio di programmazione Java fornisce operatori che eseguono addizioni, sottrazioni, moltiplicazioni e divisioni. Ci sono buone probabilità che li riconoscerai dalle loro controparti in matematica di base. L'unico simbolo che potrebbe sembrare nuovo per te è "%", che divide un operando per un altro e restituisce il resto come risultato.

| Operatore | Descrizione             |
| --------- | ----------------------- |
| +         | Additive operator       |
| -         | Substraction operator   |
| $\star$   | Multiplication operator |
| /         | Division operator       |
| %         | Remainder operator      |


