# Introduzione alla programazione su ARM
---
## Teorema di Böhm - Jacopini
Il teorema di Böhm-Jacopini, enunciato nel 1966 da due informatici italiani dai quale prende il nome, afferma che:
>«qualunque algoritmo può essere implementato utilizzando tre sole strutture: la sequenza, la selezione e l’iterazione, che possono essere tra loro innestati fino a giungere ad un qualsivoglia livello di profondità finito (come le scatole cinesi)».

Questo serve per evitare la programmazione a spaghetti (spaghetti code) che è un termine dispregiativo per il codice sorgente di quei programmi per computer che hanno una struttura di controllo del flusso complessa e/o incomprensibile, con uso esagerato ed errato di go to, eccezioni, thread e altri costrutti di branching (diramazione del controllo) non strutturati.

## Diagrammi Nassi-Shneiderman
I Diagrammi di Nassi-Shneiderman, anche detti **DNS**, sono strumenti semplici che si usano per scrivere algoritmi intrinsecamente strutturati e complessi.
Si collegano al TH Bohm-Jacopini, associando infatti questo teorema al formalismo ideato da Isaac Nassi e Ben Shneiderman, si ottengono appunto i DNS.
I concetti di sequenza, iterazione, selezione possono essere espressi, all’interno del diagramma, in blocchi che possono essere innestati e composti a piacere fino a giungere ad un qualsiasi livello di profondità.

### Sequenza
Si esprime il concetto che ogni procedimento risolutivo si può comporre attraverso un insieme finito di passaggi, o di blocchi, che verranno eseguiti nell’ordine dall’alto verso il basso, senza la possibilità di saltare la valutazione di un passaggio intermedio.

### Selezione
È il concetto attraverso il quale il percorso del flusso di esecuzione può prendere differenti cammini a seconda della condizione espressa in testa al blocco.
Può essere:
1. Singola: se la condizione è verificata, viene eseguito un blocco, altrimenti si esce e si prosegue il flusso di esecuzione (if-then o if-else)
2. Binaria: se la condizione è verificata viene eseguito il blocco then, altrimenti il blocco else (if-then-else)
3. Multipla: controlla il valore di una variabile all’interno di un intervallo di valori predefiniti. Quando la variabile corrisponde a uno dei valori della selezione, viene eseguito il blocco ad esso associato, altrimenti viene eseguito il blocco di default (switch)

### Iterazione
Si esprime la possibilità di ripetere l’esecuzione di un blocco interno fino a quando non si verificherà la condizione di uscita, per questa ragione è di uso comune denominarlo anche “ciclo”. Esistono tre tipologie: for, while, do-while
Quando si sa a priori il numero di ripetizioni da eseguire, si usa il **for**.
Quando c’è la possibilità che il blocco non venga mai eseguito, o l’iterazione è funzione di un evento non noto, si usa il **while**.
Quando l’iterazione dipende da un evento non noto, ma il blocco deve essere eseguito almeno una volta, si usa il **do-while**.

## ARM
### Cos'è?
L'architettura ARM definisce una famiglia di microprocessori di tipo RISC (Poche e semplici istruzioni per massimizzare il throughput delle istruzioni). 
Dal punto di vista circuitale è estremamente semplice rispetto a un CPU tradizionale e quindi richiede un numero minore di transistor e di silicio, questo porta ad essere più economico sul mercato ed ha un basso consumo energetico rispetto alle sue prestazioni. (Questa architetture è diffusa su cellulari, tablet, console, portatili, elettrodomestici e televisori)
Inoltre deve eseguire l’elaborazione dei dati direttamente nel processore senza intervento della memoria e quindi accede in memoria solo per operazioni di lettura e scrittura.

### Struttura ARM
Il processore ARM utilizza un'architettura RISC a 32 bit, con spazio di indirizzamento di 32 bit e la memoria indirizzabile al singolo byte, a 16 bit (halfword) o 32 bit (word). Il processore ARM può indirizzare fino a $2^{32}$ locazioni di memoria. 

#### Organizzazione interna del processore
L'organizzazione interna di ARM prevede l'utilizzo di 3 registri:
- RD: registro destinazione dove verrà scritto il risultato
- RN: registro sorgente che contiene il primo operando (OP1) ed è utilizzato direttamente dalla ALU
- RM: resgistro sorgente che contiene il secondo operando (OP2) ed è utilizzato dalla ALU dopo il passaggio nel **barrel shift** (circuito che può shiftare una word di un numero specifico di bit in un solo ciclo di clock)

![[AE/img/img62.png|center|400]]
##### Barrel shifter
Un barrel shifter è un circuito che esegue lo shift di una parola binaria di un numero specificato di bit in un solo ciclo di clock. Questo è possibile con una sequenza di multiplexer disposti in parallelo in cui le uscite di un livello sono collegate agli ingressi dei mux adiacenti nel livello successivo. 
Nel barrel shifter si può definire la modalità di shift e il numero di bit da traslare.

###### Logical Shift Left (LSL) e *Logical Shift Right (LSR)*
L’operazione **LSL** e **LSR** si applica a un registro sorgente e richiede un valore che determina il numero di volte in cui eseguire lo scorrimento a sinistra (*destra*) dei bit del registro. Ad ogni passaggio viene inserito il valore zero nel bit meno (*più*) significativo del registro (LSB - least significant bit/ *MSB - most significative bit*). Lo shift a sinistra (*destra*) coincide col moltiplicare (*dividere*) il valore del registro per la base. Se l'operazione viene ripetuta n volte, permette di moltiplicare (*dividere*) il valore del registro per $2^n$. L’ultimo bit più (*meno*) significativo che esce dal registro sorgente, ovvero il bit in posizione 32-n (*n-1*), finisce nel flag C del registro CPSR.

![[AE/img/img63.png|center|300]]
![[AE/img/img64.png|center|300]]


![[AE/img/img65.png|center|300]]
![[AE/img/img66.png|center|300]]

##### Arithmetic Shift Right (ASR)
L’operazione ASR si applica a un registro sorgente e richiede un valore che determina il numero di volte in cui eseguire lo scorrimento a destra dei bit del registro. Ad ogni passaggio viene mantenuto il valore presente nel bit più significativo del registro (MSB most significant bit). L’operazione di shift a destra coincide col dividere per la base **preservando il segno del contenuto**. Se viene ripetuta n volte permette di dividere il valore del registro per $2^n$. L’ultimo bit meno significativo che esce dal registro sorgente ovvero il bit in posizione n-1 finisce nel flag C del registro CPSR

![[AE/img/img67.png|center|300]]
![[AE/img/img68.png|center|300]]

##### Rotate Right (ROR)
L’operazione ROR si applica a un registro sorgente e richiede un valore che determina il numero di volte in cui eseguire lo scorrimento a destra dei bit del registro. Ad ogni passaggio il LSB finisce in posizione MSB senza che nessun bit si perda. L’ultimo bit meno significativo che esce dal registro sorgente per girare ovvero il bit in posizione n-1 finisce nel flag C del registro CPSR.

![[AE/img/img69.png|center|300]]
![[AE/img/img70.png|center|300]]

###### Rotate Right con estensione (RRX)
L’operazione RRX funziona esattamente come la ROR ad eccezione del fatto che considera il flag C come estensione del registro sorgente. Ad ogni passaggio il LSB finisce nel flag C, il vecchio valore del flag C in posizione MSB e tutti gli altri si spostano verso destra senza che nessun bit venga perso.

![[AE/img/img72.png|center|300]]

###### Rotate Left con estensone
Nel barrel shifter non esiste una operazione analoga alla RRX che sia in grado di eseguire la rotazione di bit verso sinistra (rotate left with extend).
si può utilizzare l’istruzione ADCS che produce lo stesso effetto
ADCS R0, R0, R0 ; RLX R0

#### I registri ARM
L'architettura ARM prevede la seguente organizzazione:
- 16 registri denominati R0 - R15:
	- R0 - R12 registri di uso generale utilizzabili dal programmatore per realizzare applicazioni
	- R13 è lo [[Architettura degli elaboratori#Lo stack|stack pointer]] (SP)
	- R14  è il subroutine link register (LR), registro utilizzato per ripristinare il PC alla istruzione successiva alla chamata ad una subroutine, quando quest'ultima ha terminato la sua esecuzione
	- R15 è il Program Counter (PC) e conserva l'indirizzo di memoria della successiva istruzione da eseguire
- Un registro di stato denominato Current Program Status Register (CPSR) 
- 20 registri non accessibili nel modo utente/sistema e organizzati come segue:  
	- 5 registri da R8_FIQ a R12_FIQ attivi solo nella modalità di risposta ad una eccezione causata da un interrupt ad alta priorità
	- 10 registri (SP_FIQ, LR_FIQ, SP_IRQ, LR_IRQ, SP_SVC, LR_SVC, SP_ABT, LR_ABT, SP_UND e LR_UND) attivi soltanto due per volta (stack pointer e linker registri) nella modalità di risposta ad un eccezione
	- 5 registri (SPSR_FIQ, SPSR_SVC, SPSR_ABT, SPSR_IRQ, SPSR_UND) attivo uno per volta nella modalità di risposta ad un eccezione e che permette di salvare il contenuto del registro di stato corrente CPSR nel corrispondente registro sved program status register (SPSR)

##### Current Program Status Register (CPSR)
Questo registro tiene traccia dello stato del programma. Molto utili sono i 5 bit principali di stato (flag di stato) che esprimono le seguenti condizioni aritmetiche:
- Bit N (Bit 31): risultato negativo
- Bit Z (Bit 30): risultato zero dalla ALU
- Bit C (Bit 29): flag di riporto
	- Durante un addizione,  C = 1 se c'è un riporto
	- Durante una sottrazione, C = 0 se è richiesta una cifra in prestito
	- Operazioni di shift o rotazione, viene impostato con l'ultimo bit che esce a causa dello scorrimento
- Bit V (Bit 28): V = 1 se si è verifcata una condizione di overflow. Questa circostanza accade quando si sommano o sottraggono valori con segno rappresentati in completamento alla base
- Bit Q (Bit 27): saturazione - impostato a 1 quando nel risultato è stato inserito un valore limite (estremo superiore o inferiore)
- Sono presenti inoltre altri flag di stato cioè:
	- Bit E Endian - se E=0 little-endian altrimenti se E=1 big-endian (modo di indirizzamento dei byte).
	- Bit Do Not Modify, per futuri utilizzi.
	- Bit Greater Than or Equal, vengono usati come flag di maggiore di o uguale (GE).
	- Bit Imprecise Data Abort enable/disable, abilita/disabilita ogni richiesta di abort dati imprecisi.
	- Bit Interrupt enable/disable, abilita/disabilita ogni richiesta di interrupt a bassa priorità IRQ.
	- Bit Fast Interrupt enable/disable, abilita/disabilita ogni richiesta di interrupt ad alta priorità FIQ.
	- Bit di stato Thumb, il processore entra nello stato thumb e le istruzioni vengono allineate a 16 bit e il valore del PC è memorizzato nei 31 bit più significativi.
	- Bit di stato Jazelle, il processore entra nello stato jazelle e permette il riconoscimento del byte code (Java) utilizzando un set di istruzioni a 8 bit, mantiene la modalità di accesso alla memoria a 32 bit quindi è in grado di leggere 4 istruzioni alla volta.
	- Bit M0-M4 definiscono la mod di funzionamento del processore ARM:
		- Utente - mod standard
		- Supervisor - si attiva al reset o quando il processore riceve un’istruzione di interrupt software (SWI)
		- Fast Interrupt Request - si attiva quando il bit FIQ viene asserito
		- Interrupt Request si attiva quando il bit IRQ viene asserito
		- Abort - si attiva in risposta ad una eccezione di abort
		- Undefined - si attiva quando si verifica un'eccezione dopo l’esecuzione di un'istruzione non supportata
		- System - Mod privilegiata

![[AE/img/img57.png|center|500]]

#### Tabella delle condizioni aritmetico logiche

![[AE/img/img58.png|center|600]]

#### Esempio registro di stato 

![[AE/img/img59.png|center|550]]

L’istruzione **ADD** verrà eseguita solo se la condizione **GT** (maggiore stretto) sarà verificata. La condizione GT è identificata dal codice 1100 nella sezione del registro chiamata condition code.

---

![[AE/img/img60.png|center|550]]

In questo esempio la condizione **LE** (minore uguale) è verificata, in quanto nel registro di stato CPSR i flags N Z C V rispettano almeno una delle condizioni in tabella (Z = 1 OR N != V).

#### Grado di parità di gestione delle eccezioni

![[AE/img/img61.png|center|500]]


### Particolarità ARM
- Non esistono istruzioni di shift o rotazione di bit se non innestate all’interno di altre istruzioni di elaborazione (aritmetica, logica…) e possono essere applicate ad un solo operando   
- Riesce ad applicare una operazione aritmetica o logica e lo shift o di rotazione in una sola istruzione
- Non esiste una istruzione per eseguire l’operazione di divisione questo viene delegato a un coprocessore che, avendo un ambito di applicazione più specifico, può risolvere meglio il compito
- Le istruzioni normalmente non scrivono il registro CPSR ma è possibile farlo tramite un suffisso **S** (forza la scrittura nel registro CPSR) aggiungendolo al codice mnemonico dell’ istruzione.

### Big endian e Little endian
Sono 2 tipi di ordinamento dei bit e dei byte.
1.  Big Endian imposta i bit della word partendo da quello più significativo a quello meno significativo
2.  Little Endian imposta i bit della word partendo da quello meno significativo a quello più significativo

### Modalità di indirizzamento 
Sono le tecniche attraverso le quali il processore ARM individua gli operandi presenti nell'istruzione per poi operare su di essi. Le modalità più semplici sono:
- Indirizzamento immediato: l'operando è contenuto nella codifica dell'istruzione
- Indirizzamento a registro:  l’operando è contenuto nel registro
- Indirizzamento a registro con shift: l'operando è contenuto in un registro ma subirà un operazione di shift o rotazione prima di essere utilizzato

#### Indirizzamento per le operazioni di load/store
Le istruzioni di load/store utilizzano un registro base e un offset che, sommato o sottratto al registro base, restituisce l'indirizzo di memoria ove effettuare l'operazione.
Per le operazioni di load/store sono possibili le seguenti modalità di indirizzamento:
- **con offset immediato**: l'offset è un valore senza segno specificato nell'istruzione
- **con offset a registro**: l’offset è un valore contenuto in un registro generico (con esclusione del PC o R15)
- **con offset a registro scalato**: l’offset è un valore calcolato per traslazione o rotazione del contenuto in un registro generico (con esclusione del PC)
- **assoluto**: è l’unico metodo che ha una sintassi unica
Per favorire l'accesso a blocchi di memoria o a strutture complesse, sono state aggiunte le modalità indicizzate, che permettono di aggiornare il registro base con l'indirizzo calcolato. Esistono due diverse modalità di aggiornamento:
- **pre-indicizzata**: prima si calcola l'indirizzo è successivamente si scrive il registro base
- **post-indicizzata**: prima si utilizza il registro base come riferimento di memoria e dopo si aggiorna con il nuovo valore.

### Il set delle istruzioni
Le istruzioni ARM possono essere classificate in base alla tipologia e alla sintassi che le accomuna in diverse classi di istruzioni.

#### Istruzioni di elaborazione e trasferimento dati
Le istruzioni di elaborazione servono al processore per svolgere calcoli come operazioni aritmetiche o logiche, mentre le istruzioni di trasferimento dati consentono di caricare i vari registri.

##### Istruzioni aritmetiche e logiche
Implementano le operazioni matematiche. Queste possono essere di tipo **aritmetiche** (somma, differenza, prodotto), **logiche** (operazioni booleane) o **relazionali** (comparazione di valori)
Le istruzioni aritmetiche e logiche operano al massimo su due operandi e possono aggiornare i flag del registro di stato.
L'istruzione aritmetica o logica presenta la seguente sintassi:
$$
\text{< MNEM >\{< PreCond >\}\{< S >\} <Rd>, < Rn >, OP}_2
$$
- $\text{< MNEM >}$ è il codice mnemonico dell'operazione (ADD, SUB)
- $\text{< PreCond >}$ è la pre-condizione (opzionale) che consente l'esecuzione dell'istruzione quando risulta verificata, altrimenti, se falsa, l'istruzione verrà ignorata
- $\text{< S >}$ (opzionale) forza la scrittura nel registro di stato CPSR
- $\text{< Rd >}$ è il registro destinazione nel quale verrà salvato il risultato dell'operazione
- $\text{< Rn >}$ è il registro sorgente nel quale è presente il valore del primo operando
- $\text{OP}_2$ è il secondo operando, che può essere un valore immediato, un altro registro oppure il risultato di un operazione di shift su un valore o registro

![[AE/img/img72.png|center|500]]

###### Esempi di istruzioni artimetiche e logiche
- **ADD R0, R1, R2**: carico in R0 la somma tra il contenuto del registro R1 ed R2 (indirizzamento a registro)
- **ADD R0, R1, #16**: carico in R0 la somma tra il contenuto del registro R1 ed il numero decimale 16 (indirizzamento immediato)
- **ADD R0, R1, # 0xF**: carico in R0 la somma tra il contenuto del registro R1 ed il numero esadecimale F (indirizzamento immediato)
- **ADDLT R0, R1, R2**: carico in R0 la somma tra il contenuto del registro R1 e del registro R2, inoltre carico lo stato del risultato nei flags NZCV del registro di stato CPSR. Per esempio, se il risultato della somma va in overflow i flag C (carry) e V (overflow) verranno settati a 1

###### Indirizzamento immediato
Si hanno a disposizione solo 12 bit su 32 che costituiscono la word dell’istruzione, quindi si potrebbero rappresentare soltanto i numeri che vanno da 0…+4095 oppure da -2048…+2047. Questo limite non è accettabile perchè il processore ARM gestisce valori che hanno un campo di variazione da 0x00000000 a 0xFFFFFFFF
Vengono memorizzati nei 12 bit due campi: posizione (4 bit) e valore (8 bit)

Il numero descritto è ottenuto per traslazione, verso destra, dei bit del campo valore per un numero di posizioni pari al doppio del campo posizione

Questo implica che si possono esprimere tutti i valori che hanno in binario bit 1 a distanza massima minore, o al più uguale, ad 8 che possano essere ottenuti per traslazione in pos pari.

in generale:
1.  convertire il valore in binario e verificare che il bit 1 più significativo e ultimo bit 1 meno significativo siano a distanza massimo di 8 (compressi il primo bit 1 più significativo e ultimo bit 1 meno significativo) 
2.   verificare che il numero di zeri sia pari
	- il codice binario anche se in riga vanno immaginati come scritti su un cerchio perciò anche se 0xA000000A sembra non indirizzabile perchè in binario è 10100000000000000000000000001010 e sembra non rispettare nessuno dei due punti in realtà **1010**000000000000000000000000**1010** le parti evidenziate sono come nelle mappe K vicine tra di loro

###### Indirizzamento con shift immediato e con shift a registro
Se il bit 25 vale 0, nei bit 5 e 6 il tipo di shift da applicare tra quelli disponibili nel [[#Barrel shifter|barrel shifter]] (LSL, LSR, ASR, ROR, RRX) mentre il bit 4 specifica il tipo di indirizzamento.
Esempi:
**(INDIRIZ. CON SHIFT IMMEDIATO)**:
- ADD R3, R3, R3, LSL #2 —> R3 = R3 + R3 * 4
- RSB R2, R2, R2, LSL #4—> R2 = R2 * 16 - R2
- AND R0, R1, R2, RRX —> R0 = R1 AND RRX (R2)

**(INDIRIZZ. CON SHIFT A REGISTRO)**:
ADD R0, R1, R2, LSL R3 —> R0 = R1+R2*(2^R3)
ORR R0, R0, R2, LSL R3 —> R0 = R0 0R R2 * (2^R3)
AND R0, R0, R2, LSR R3 —>R0 = R0 AND R2 / (2^R3)

###### Indirizzamento a registro
Il secondo operando è il registro Rm, senza che quest’ultimo subisca operazioni di shift
Questa istruzione è un caso particolare dell'istruzione LSL con indirizzamento immediato in cui i bit non sono traslati

##### Istruzioni aritmetiche con saturazione
Se si utilizzano 32 bit per codificare i numeri interi con segno, l’intervallo di rappresentazione si divide in due sottoinsiemi:
-   valori positivi da 1 a $2^{32}-1$
-   valori negativi da -1 a $-2^{32}-1$

Se durante un'operazione aritmetica si ottiene un numero che eccede uno dei due limiti, il risultato potrebbe essere interpretato per sbaglio nel limite opposto.
Per questo ARM usa la tecnica di aritmetica con saturazione, in cui tutte le operazioni finiscono in un dominio intero e finito di valori compresi tra un minimo e un massimo.
Quando un valore supera un estremo, il flag Q del CPSR viene attivato.
Le istruzioni che supportano le operazioni aritmetiche con saturazione sono QADD e QSUB
I bit non utilizzati nella codifica dell’istruzione sono segnati con SBZ (Should Be Zero)

La sintassi delle istruzioni aritmetiche con interi saturi è:
$$
\text{< MNEM >\{< PreCond >\} <Rd>, < Rm >, < Rn >}
$$
La codifica delle istruzioni aritmetiche con interi saturi è:

| 31.. 28 | 27 26 25 | 24.. 21 | 20 | 19.. 16 | 15.. 12 | 11.. 8 | 7 6 5 4 | 3.. 0 |
|:-------:|:--------:|:-------:|:--:|:-------:|:-------:|:------:|:-------:|:-----:|
| PreCond |   0 0 0  |  OPCODE |  0 |    Rn   |    Rd   |   SBZ  | 0 1 0 1 |   Rm  |

|  CODE |  MNEM |             Descrizione            |           Semantica          |
|:-----:|:-----:|:----------------------------------:|:----------------------------:|
| 10000 |  QADD |      Addizione con saturazione     |       Rd <-- sat(Rm+Rn)      |
| 10100 | QDADD | Addizione con doppia saturazione   | Rd <-- sat(Rm + sat(2 * Rn)) |
| 10010 | QSUB  | Sottrazione con saturazione        | Rd <-- sat(Rm - Rn)          |
| 10110 | QDSUB | Sottrazione con doppia saturazione | Rd <-- sat(Rm - sat(2 * Rn)) |

##### Istruzioni di confronto
Utilizzano in ingresso due operandi, ma non hanno un registro destinazione poiché il loro effetto è nella scrittura del registro di stato in base al valore risultato. La loro sintassi è la seguente:

$$
\text{< MNEM >\{< PreCond >\} < Rn >, OP}_2
$$

| OPCODE |  MNEM |             Descrizione            |           Semantica          |
|:-----:|:-----:|:----------------------------------:|:----------------------------:|
| 1000 |  TST |      Test bit     |       CPSR <-- < Rn >$\cdot \:OP_2$      |
| 1001 | TEQ | Test uguaglianza bit-a-bit   | CPSR <-- < Rn >$\oplus \:OP_2$ |
| 1010 | CMP  | Comparazione        | CPSR <-- < Rn >$- \:OP_2$|
| 1011 | CMN | comparazione negativa | CPSR <-- < Rn >$+ \:OP_2$ |

Sono 4 ed hanno il seguente comportamento:
1.  TST - Test Bit
2.  TEQ - Test uguaglianza bit-a-bit
3.  CMP - Comparazione
4.  CMN - Comparazione negativa

Utilizzano lo stesso formato delle istruzioni aritmetico/logiche e quindi valgono le stesse regole per quanto riguarda le modalità di indirizzamento.
CMP si comporta come ADD, CMN come SUB, TST come AND, TEQ come EOR (Exor)

##### Istruzione di moltiplicazione
Tutte le istruzioni di moltiplicazione accettano due o tre registri come operandi sorgente e scrivono il risultato in un registro destinazione. Hanno un funzionamento molto variegato perché consentono di eseguire operazioni di moltiplicazione e somma su word e halfword con o senza segno e di scrivere il risultato in word o double word

###### Moltiplicazione a due operandi
La sintassi delle istruzioni di moltiplicazione che utilizzano due operandi e forniscono un risultato in word (32-bit) è:
$$
\text{< MNEM >\{< PreCond >\}\{< S >\} <Rd>, < Rn >, < Rm > }
$$
< Rm >, < Rs > come registri sorgente, mentre < Rd > è il registro di destinazione.

L'indicazione del suffisso S forza la la scrittura nel CPSR ed è utilizzabile solo nell'istruzione MUL, in tutte le altre istruzioni di moltiplicazione a due operandi non è possibile forzare la scrittura sul registro dei flag.

|  MNEM  |        Descrizione        |  Molt.  |                    Semantica                   |    Tronc.    |
|:------:|:-------------------------:|:-------:|:----------------------------------------------:|:------------:|
|   MUL  |          Multiply         | 32 x 32 |                Rd <-- $Rm\cdot Rn$               |  31 $\div$ 0 |
| SMULxy |      Sign. Mult. Long     | 16 x 16 |            Rd <-- $Rm[x]\cdot Rs[y]$           |              |
| SMULWy |      Sign. Mult. Word     | 32 x 16 |             Rd <-- $Rm \cdot Rs[y]$            |  31 $\div$ 0 |
|  SMUAD |   Sign. Mult., Add Dual   | 16 x 16 | Rd <-- $Rm[B] \cdot Rs[B] + Rm[T] \cdot Rm[T]$ |              |
| SMUADX | Sign Mult, Add Dual, eXch | 16 x 16 | Rd <-- $Rm[B] \cdot Rs[T] + Rm[T] \cdot Rm[B]$ |              |
|  SMUSD |     Sign Mult Sub Dual    | 16 x 16 | Rd <-- $Rm[B] \cdot Rs[B] - Rm[T] \cdot Rm[T]$ |              |
| SMUSDX |  Sign Mult Sub Dual, eXch | 16 x 16 | Rd <-- $Rm[B] \cdot Rs[T] - Rm[T] \cdot Rm[B]$ |              |
|  SMMUL |   Sign MSW Mult Truncate  | 32 x 32 |              Rd <-- $Rm \cdot Rs$              | 63 $\div$ 32 |
| SMMULR |    Sign MSW Mult Round    | 32 x 32 |              Rd <-- $Rm \cdot Rs$              | 63 $\div$ 32 |

###### Moltiplicazioni a tre operandi
La sintassi delle moltiplicazioni che utilizzano 3 operandi e restituiscono un risultato in word (32 bit) è:
$$
\text{< MNEM >\{< PreCond >\}\{< S >\} <Rd>, < Rm >, < Rs >, < Rn > }
$$

< Rd > è il registro di destinazione , < Rm >, < Rs > e < Rn > sono i registri sorgente cioè gli operandi.
Il suffisso S che consente la scrittura dei flag del registro di stato (CPSR) è ammesso solo per l’istruzione MLA

|  MNEM  |          Descrizione          |  Molt.  |                      Semantica                      |    Tronc.    |
|:------:|:-----------------------------:|:-------:|:---------------------------------------------------:|:------------:|
|   MLA  |           Mult. Acc           | 32 x 32 |              Rd <-- $Rn + Rm \cdot Rs$              |  31 $\div$ 0 |
| SMLAxy |      Sign. Mult. Long Acc     | 16 x 16 |            Rd <-- $Rn + Rm[x]\cdot Rs[y]$           |              |
| SMLAWy |      Sign. Mult. Word Acc     | 32 x 16 |             Rd <-- $Rn + Rm \cdot Rs[y]$            |  31 $\div$ 0 |
|  SMLAD |   Sign. Mult., Add acc Dual   | 16 x 16 | Rd <-- $Rn + Rm[B] \cdot Rs[B] + Rm[T] \cdot Rs[T]$ |              |
| SMUADX | Sign Mult, Add acc Dual, eXch | 16 x 16 | Rd <-- $Rn + Rm[B] \cdot Rs[T] + Rm[T] \cdot Rs[B]$ |              |
|  SMLSD |     Sign Mult Sub acc Dual    | 16 x 16 |    Rd <-- $Rm[B] \cdot Rs[B] - Rm[T] \cdot Rs[T]$   |              |
| SMLSDX |  Sign Mult Sub acc Dual, eXch | 16 x 16 | Rd <-- $Rn + Rm[B] \cdot Rs[T] - Rm[T] \cdot Rs[B]$ |              |
|  SMMLA |   Sign MSW Mult acc Truncate  | 32 x 32 |              Rd <-- $Rn + Rm \cdot Rs$              | 63 $\div$ 32 |
| SMMLAR |    Sign MSW Mult acc Round    | 32 x 32 |              Rd <-- $Rn + Rm \cdot Rs$              | 63 $\div$ 32 |
|  SMMLS |   Sign MSW mult sub, trunc.   | 32 x 32 |              Rd <-- $Rn - Rm \cdot Rs$              | 63 $\div$ 32 |
| SMMLSR |    Sign MSW mult sub, trunc   | 32 x 32 |              Rd <-- $Rn - Rm \cdot Rs$              | 63 $\div$ 32 |

###### Moltiplicazioni con risultati a dobuleword
La sintassi delle moltiplicazioni che utilizzano due operandi e forniscono un risultato in doubleword (64-bit) è:
$$
\text{< MNEM >\{< PreCond >\}\{< S >\} < RdL >, < RdH >, < Rm >, < Rs > }
$$
Il suffisso S per la scrittura dei flag nel registro di stato è possibie per le istruzioni UMULL, UMLAL, SMULL, SMLAL.
![[AE/img/img73.png|center|500]]

##### Istruzioni di trasferimento dati
SI occupano di trasferire i valori tra i registri o nei registri
La codifica delle istruzioni di trasferimento ha la medesima forma di quelle di elaborazione dati, ovvero:
$$
\text{< MNEM >\{< PreCond >\}\{< S >\} <Rd>, < Rn >, OP}_2
$$
![[AE/img/img74.png|center|500]]

##### Istruzioni Single Istruction Multiple Data (SIMD)
ARM ha introdotto delle istruzioni aritmetiche che agiscono sui registri considerandoli come dei contenitori di array definiti su word (32 bit) e halfword (16 bit). Una singola istruzione è in grado di operare contemporaneamente su più dati e quindi di eseguire, per esempio, la somma degli elementi di due array di 2 o 4 elementi.

![[AE/img/img75.png|center|500]]

La sintassi generica di una istruzione aritmetica SIMD è la seguente:
$$
\text{< MNEM >\{< PreCond >\} <Rd>, < Rn >, < Rm >}
$$
Il codice mnemonico $\text{< MNEM >}$ si ottiene unendo due elementi:
- Il prefisso, che definisce due modalità di esecuzione dell'operazione (U = Unsigned, Q = con saturazione, H = risultati dimezzati per prevenire overflow)
- Il tipo di istruzione combinata con la dimensione del singolo elemento dell'array (ADD8, SUB8, ADD16, SUB16, ADDSUBX, SUBADDX).

La possibili conbinazioni di prefissi applicabili alle istruzioni SIMD sono:

![[AE/img/img76.png|center|500]]

Le istruzioni SIMD utilizzano i bit GE del CPSR come flag per i byte o le halfword dei risultati. Questo permette di utilizzarli per controllare l’esecuzione di una successiva istruzione. Per le istruzioni che operano su due halfword:
-   I bit GE$[2 \div 3]$ sono impostati in base al risultato dell’halfword in posizione 1 (Most Significant Halfword).
-   I bit GE$[0 \div 1]$ sono impostati in base al risultato dell’halfword in posizione 0 (Least Significant Halfword)

Per le istruzioni che operano su 4 byte, i bit GE$[\: i \:]$ sono impostati in base al risultato del byte in posizione $i$ con $i = [0,\: 1,\: 2,\: 3]$. Questi bit sono aggiornati se durante una operazione di addizione di numeri senza segno si raggiunge, o si supera, il massimo valore rappresentabile. La stessa cosa accade se durante un'operazione di sottrazione di numeri con segno il risultato è maggiore o uguale a 0.
Le possibili tipologie di istruzioni SIMD sono:

![[AE/img/img77.png|center|500]]

Le istruzioni SIMD dell'architettura ARM che operano su array di 4 byte sono:

![[AE/img/img78.png|center|500]]

Interessante è l’istruzione USAD8 che esegue la somma dei valori assoluti delle differenze dei byte di due array, che presenta la stessa sintassi delle altre istruzioni SIMD. Esiste anche la variante del registro destinazione che permette di accumulare i risultati parziali (USADA8) in questo caso nella sintassi occorre aggiungere < Rn >.

![[AE/img/img79.png|center|500]]

Le istruzioni SIMD che operano su array di due halfword sono:

![[AE/img/img80.png|center|500]]
##### Istruzioni di accesso ai registri di stato

Le istruzioni per l’accesso ai registri di stato sono:
1.  MRS (Move to Register from Status register) copia il valore del CPSR o del SPSR nell'attuale modo di funzionamento del processore, all’interno dei registri di uso generale; la sintassi è :
$$MRS \{<PreCond>\} <Rd>, \{CPSR|SPSR\}$$
2.  MSR (Move to Status register from Register) copia il contenuto di un registro o una costante in una o più ambiti del registro CPSR o del SPSR nell'attuale modo di funzionamento del processore, le sintassi:
$$MSR\{<PreCond>\} \{CPSR|SPSR\}\{\_<ambiti>\}, <Rm>$$
$$MSR\{<PreCond>\}\{CPSR|SPSR\}\{\_<ambiti>\}, \#<valore>$$
Il campo $< ambiti >$ permette di specificare, attraverso una lista di caratteri in sequenza (c = controllo, x = estensione, s = stato, f = flag), quali sezioni del registro di stato devono essere sovrascritte con il contenuto del secondo operando.

![[AE/img/img86.png|center|500]]


Il bit 25 rappresenta il tipo di operando(0 = registro, 1 = valore immediato), il bit 22 specifica il tipo di registro di stato(0 = CPSR o 1 = SPSR), il campo field_mask, è costituito da 4 bit, responsabile del mascheramento dei diversi ambiti dei registri di stato.

La sintassi dell’istruzione MSR permette di inserire nel campo ambito una sequenza di letterali, che corrisponde ai diversi ambiti da mascherare:

![[AE/img/img87.png|center|500]]

Per esempio è divenuta obsoleta la lettura del bit E con un'istruzione MRS.
I bit di stato di esecuzione nel CPSR, diversi dal bit E, possono essere letti soltanto quando il processore è nello stato di debug. è stato anche introdotto un registro chiamato APSR (Application Program Status Register) che contiene i flag di stato dell’ALU e che andrebbe utilizzato per accedere modalità Utente ai flag delle condizioni.

![[AE/img/img88.png|center|500]]


#### Istruzioni di branch
Le istruzioni di branch (o jump) sono utili per il controllo del flusso di esecuzione delle istruzioni.
La sintassi di queste istruzioni è:
$$
\text{< MNEM >\{< PreCond >\}< Operando >}
$$
- $\text{< MNEM >}$ è il codice mnemonico dell'operazione (B = Branch e BL = branch with link)
- $\text{<PreCond>}$ (Opzionale) definisce vincolo di precondizione per l'esecuzione costitutita da due lettere (EQ = uguaglianza, GE = maggiore o uguale, ...) 
- $\text{< Operando >}$ rappresenta il riferimento all'istruzione da raggiungere con il salto e può essere specificato in modo immediato o indiretto all'interno di un registro sorgente ($\text{< Rn >}$) 

L’istruzione B carica nel PC l’indirizzo della prima istruzione della procedura che si desidera eseguire, causando così un salto nel flusso di esecuzione delle istruzioni. Per comodità le procedure vengono identificate univocamente con dei nomi detti label (o etichetta). 
L’istruzione BL è simile all’istruzione B, però carica nel registro LR (R14) l’indirizzo di ritorno della procedura, ovvero il valore del PC nel momento in cui viene eseguita l’istruzione BL.
Le istruzioni di branch sono necessarie per l’implementazione di istruzioni di condizione (if-thenelse), cicli e chiamate di funzioni.    
Per calcolare l’indirizzo di arrivo, ARM esegue i seguenti passaggi:
-   estende il segno a 30 bit il valore presente nei 24-bit di offset
-   esegue uno shift di 2 bit per arrivare a coprire i 32 richiesti
-   aggiunge il valore del PC

#### Istruzioni di load/store
Muovono dati da (load) e verso (store) la memoria principale e viceversa.
L’istruzione LDR (Load Register) carica in un registro destinatario un byte, una half word o una full world contenuta in una data locazione della memoria principale. La sintassi è:

$$\text{ LDR \{type\}\{condition\} dest, [ pointer ] }$$
$$\text{LDR \{type\}\{condition\} dest, [pointer, offset]}$$
Il campo **dest** è il registro destinatario nel quale caricare il contenuto prelevato dalla memoria.
Il campo $\text{[ pointer ]}$ indica un registro puntatore il quale definisce un contenuto che punta all’indirizzo in memoria della cella che si desidera referenziare. È possibile inoltre definire un offset il quale verrà sommato al puntatore.

L’istruzione STR (Store Register) esegue esattamente l’operazione inversa di LDR; carica in memoria il contenuto di un registro sorgente all’indirizzo definito dal puntatore.

##### Esempio di istruzioni load/store
- LDR R0, $[$ R1, #2 $]$ Carico in R0 la parola in memoria puntata dal registro R1

![[AE/img/img81.png|center|500]]

- LDRH R0, $[$ R1, #2 $]$ Carico in R0 la HalfWord (H) 2 byte a partire dalla cella puntata dal registro R1

![[AE/img/img82.png|center|500]]

-  STR R0, $[$ R1 $]$ Carico all’indirizzo puntato da R1 la parola contenuta nel registro R0

![[AE/img/img83.png|center|500]]


##### Istruzione di load e store su byte, word o doubleword
Le operazioni di load/store che agiscono su byte con segno, halfword (con o senza segno) e word (con e senza segno). La sintassi è:
$$
\text{LDR\{< PreCond >\}\{SB | H | SH\}< Rd >, < indirizzamento >}
$$
$$
\text{STR\{< PreCond >\}\{H\}< Rd >, < indirizzamento >}
$$
I suffissi SB, H e SH specificano il dominio dei dati su cui deve operare l'istruzione

![[AE/img/img84.png|center|500]]

##### Istruzione di load e store su registro multipli
Le istruzioni di load/store multipli (LDM e STM) eseguono un trasferimento di un qualsiasi numero di registri da o verso la memoria. Queste istruzioni sono pensate per far corrispondere al registro con indice più piccolo l’indirizzo di memoria più basso e, viceversa, a quello con indice più grande l’indirizzo più alto. 
La sintassi delle istruzioni LDM e  STM è la seguente:
$$
\text{< MNEM >\{< PreCond >\}{< Modo agg >} <Rn>\{!\}, < Registri >\{} \: \wedge\: \} 
$$
Il campo $\text{< Modo agg >}$ può assumere i formati indicati nella colonna sintassi della tabella:

![[AE/img/img85.png|center|500]]

###### Esempio
LDR R7, {R1, R4, R5}
STMDB R3!,  {R4-R6, R11-R12}
STMFD R13!, {R0-R10, LR}
LDMFD R13!, {R1-R5, PC}

##### Istruzioni di accesso esclusivo alla memoria
Queste istruzioni nascono per la sincronizzazione dei processi in ambiente multiprocessore basato su memoria condivisa. Sono istruzioni progettate per avere il comportamento atomico richiesto nei semafori senza bloccare tutte le risorse di sistema durante le fasi di accesso alla memoria condivisa.
L’ istruzione LDREX carica in modo condizionale nel registro Rd la word presente nell’indirizzo indicato da Rn (Rd←memoria $[$ Rd $]$). La sintassi è:
$$
<LDREX>\{<Precond>\} <Rd>, [<Rn>]
$$
L’istruzione STREX esegue una scrittura in modo condizionale nel registro Rm in memoria (memoria[Rn]←Rm) la sintassi è:
$$<STREX>\{<Precond>\} <Rd>, <Rm>, \{<Rn>\}$$

#### Istruzioni verso i coprocessori
Il processore ARM può richiedere ai vari coprocessori operazioni di calcolo numerico (istruzioni di elaborazione dati) mentre continua a svolgere altri compiti
ARM può arrivare ad avere fino a 16 coprocessori che sono identificati nelle istruzioni con gli alias P0-P15
Le istruzioni fanno parte del modo 5 di indirizzamento

##### Istruzioni di elaborazioe dati
L’istruzione CDP(Coprocessor Data Processing) consente di richiedere ad un coprocessore disponibile (tra P0…P15) di eseguire una istruzione tra quelle disponibili nel suo Instruction Set

##### Istruzioni di trasferimento dati in memoria
Le istruzioni di trasferimento in memoria sono:
1.  LDC(Load to Coprocessor): carica i registri del coprocessore con i dati contenuti in una sequenza contigua di locazioni in memoria.
2.  STC(Store from Coprocessor): memorizza in una sequenza di indirizzi di memoria contigui i dati contenuti nei registri del coprocessore

![[AE/img/img89.png|center|500]]

Il campo CP_Num indica con un numero intero quale coprocessore dovrà rispondere alla chiamata
il bit L, come per le istruzioni Load/Store, indica se l’istruzione è LDC(L=1) o STC(L=0)
il bit U determina se l’offset va sommato o sottratto
i bit P e W determinano il tipo di indirizzamento

##### Istruzioni di trasferimento dati tra registri
Le istruzioni di trasferimento dati tra registri sono:
1.  MCR(Move to Coprocessor from ARM register):  trasferisce il contenuto del registro RD del processore nel registro del coprocessore
2.  MCRR(Move to Coprocessor from two ARM register)
3.  MRC(Move to ARM register from Coprocessor) trasferisce il contenuto dei registri del coprocessore nel registro RD del processore o nei flag del registro di stato
4.  MRRC(Move to two ARM register from Coprocessor)

![[AE/img/img90.png|center|500]]

Nel caso di MRC, se viene indicato R15, l’effetto ottenuto è l’aggiornamento dell’ambito dei flag nel registro CPSR
Il bit r/$\bar c$ individua il tipo di istruzione: se 1 si tratta di MRC altrimento di MCR
per MCRR e MRRC: se il bit r/c(negato) vale 1 si tratta di MRRC altrimenti di MCRR

![[AE/img/img91.png|center|500]]

#### Istruzioni per generare eccezioni
Le eccezioni possono essere generato in modo volontario attraverso istruzioni software o un errore imprevisto. Le eccezioni volontarie sono attivate da istruzioni che mandano il processore in modalità di funzionamento privilegiata. 

##### Interruzione software
L'istruzione SWI genera un eccezione SWI che porta il processore nello stato ARM e la modalità cambia in **supervisor**, quindi il registro CPSR viene salvato nel registro SPSR_SVC. Questa è la modalità attraverso la quale un processo utente invoca una system call del sistema operativo. La sintassi risulta:
$$
SWI \{< Precond >\} < costante_{24} >
$$
L'indirizzamento è immediato.

##### Breakpoint software
Istruzione BKPT (breakpoint) è utilizzata per introdurre punti di interruzione nel codice e causare una eccezione di **prefetch abort**. Il debugger permette di  sospendere l'esecuzione al punto di interruzione, ipezionare il contenuto delle variabili e il percorso eseuito durante l'esecuzione. La sintassi risulta:
$$
BKPT<costante_{16}>
$$
L’indirizzamento è immediato

#### Istruzioni per il packaging e unpackaging dei dati
##### Packaging
Le istruzioni per il packing dei dati sono due:
1. PKHBT (pack halfword bottom top) unisce le cifre meno significative del primo operando con quelle più significative del secondo
	Esempio:
	LDR R1, =0x11112222
	LDR R2, =0x33334444
	PKHBT R3, R1, R2 //R3=0x33332222
2. PKHTB (pack halfword top bottm) unisce le cifre più significative del primo operando con quella meno significative del secondo
	Esempio:
	LDR R1, =0x11112222
	LDR R2, =0x33334444
	PKHBT R3, R1, R2 //R3=0x11114444

##### Unpacking
Sono istruzioni che permettono di ruotare di 0, 8, 16 o 24 bit il contenuto di un registro, inoltre possono accumulare il valore ottenuto, nei vari incrementi, in un registro destinazione.

#### Istruzioni di saturazione
Controllano se un valore è al di fuori di un intervallo prestabilito e in questo caso di assegnare l’estremo più vicino dell’intervallo stesso.
Ci sono 4 versioni di queste istruzioni, a seconda che si considerino valori con segno o meno e se agiscano su intere word o halfword:
1.  SSAT(Signed Saturate)
2.  USAT(Unsigned Saturate)
3.  SSAT16(Signed Saturate two 16-bit values)
4.  USAT16(Unsigned Saturate two 16-bit values)

#### Istruzioni di conteggio degli zeri finali
Istruzione CLZ (count leading zero) rientra nella categoria dell’elaborazione dati e fornisce quanti bit sono zero a partire dal bit più significativo, spostandosi  verso la cifra meno significativa 
La sintassi è:
$$
CLZ\{<Precond>\} <Rd>, <Rm>
$$
Esempi:
LDR R1, = 0x0000FFFF
MOV R3, # 0x10000000
CLZ R2, R1 // R2 = 0x0000010
CLZ R4, R3 // R4 = 0x0000003

#### Istruzioni di inversione di byte
Queste istruzioni converte i dati dal formato little-endian a quello big-endian e viceversa
La sintassi è:
$$
<MNEM>\{<Precod>\} <Rd>, <Rm>
$$
![[AE/img/img92.png|center|500]]

Esempio:
LDR R1, =0x0FE10547
REV R2, R1 // R2=0x4705E10F     NB: vengono girati a coppie es 47, 05, E1 ecc
REV16 R3, R1 // R3=0xE10F4705
REVSH R4, R1 // R4=0x00004705                            Halfword

#### Pseudo-istruzioni
##### No operation
La pseudo-istruzione NOP è una operazione che non esegue alcun compito: 
-   può essere utilizzata come segnaposto nel corpo del programma da sostituire in seguito con istruzioni attive
-   può invalidare un istruzione esistente (es: un branch) per scopi di debug
-   può richiedere un ciclo di clock 
-   in alcune circostanze il processore potrebbe rimuoverla dalla pipeline prima che raggiunga la fase di esecuzione
-   ARM potrebbe tradurre NOP con:

MOV R0, R0 //nella modalità arm

oppure

MOV R8, R8 //nella modalità Thumb

##### Shifting e rotazione
ARM non dispone di istruzioni di shifting e rotazione dirette se non attraverso l’innesto all’interno di istruzioni di elaborazione dati. L’assembler (ARM) riconosce 5 pseudo-istruzioni (LSL, LSR,  ASR, ROR e RRX) che sono poi tradotte utilizzando l’istruzione MOV.
RRX utilizza un solo operando ed è differente dalle altre istruzioni di shift o rotate con la sintassi:
$$
RRX {<Precond>}{<S>} <Rd>, <Rn>
$$
Mentre  per le istruzioni LSL, LSR, ASR, ROR le sintassi possibili sono:
$$
<MNEM>\{<Precond>\}\{<S>\} <Rd>, <Rn>, Rs
$$
$$
<MNEM>\{<Precond>\}\{<S>\} <Rd>, <Rn>, \#valore
$$
Il registro Rs indica nel suo Byte meno significativo il numero di cifre da scorrere.
il campo # valore è un numero intero compreso tra 1 e 31.

![[AE/img/img93.png|center|500]]

##### Copia registro
L'Istruzione CPY è una pseudo-istruzione sinonima della MOV offset a registro ma, differentemente da quest’ultimo, non ha la possibilità di impostare i flag del registro di stato (S) e neanche di eseguire lo shift sul secondo operando la sua sintassi risulta:
$$
CPY\{<Precond>\} <Rd>, <Rm>
$$
#### Change Processor State
CPS (Change Processor State) è una istruzione molto duttile che può essere utilizzata per abilitare o disabilitare le eccezioni (FIQ, IRQ e data Abort mask) e allo stesso tempo modificare il modo di funzionamento del processore (Utente, FIQ, IRQ, Supervisor, Abort, Undefined e System) nel registro CPSR. La stessa istruzione si può utilizzare esclusivamente per alterare la modalità di funzionamento, senza alterare le abilitazioni sul trattamento delle eccezioni.
La sintassi dell'istruzione CPS risulta quindi:
$$
CPS\{IE|ID\} <int\_flag> \{,\#<modo>\}
$$
Il campo int_flag indica quali bit nel registro di stato verranno abilitati o disabilitati.

![[AE/img/img94.png|center|500]]

![[AE/img/img95.png|center|500]]

Il campo IE_ID permette di specificare se si tratta di un Interrupt Enable (IE_ID=10) oppure un Interrupt Disable (IE ID=11). Se il bit M è asserito allora significa che l'istruzione contiene un cambio di modalità di funzionamento e pertanto negli ultimi 5 bit sarà indicato il relativo codice.

![[AE/img/img96.png|center|500]]

#### Store return state onto a stack
L'istruzione SRS (Store Return State onto a stack), memorizza rispettivamente il LR e SPR dell'attuale modalità di funzionamento, nelle due word successive a partire da (SP) della modalità indicata all'interno dell'istruzione. Grazie a questa istruzione è possibile predisporre lo stato di ritorno da un exception handler su uno stack diverso da quel-
lo utilizzato automaticamente dal processore. Le due sintassi equivalenti dell'istruzione risultano:
$$
SRS\{<Modo Agg>\}\{<PreCond>\} SP\{!\}, \# <Modo>
$$
$$
SRS\{<Modo Agg›\}\{<PreCond>\} \#‹Modo>\{!\}
$$
  

L'istruzione SRS si comporta come una STM che però opera sulla coppia di registri: R14 e SPSR del corrente modo di funzionamento. Utilizza la medesima modalità di aggiornamento (IA, IB, DA e DB) e utilizza come registro base il registro R13 relativo alla modalità di funzionamento indicata nel campo numerico $<Modo>$. Il punto esclamativo permette di aggiornare il registro base con la nuova posizione di memoria ed agisce sul bit di writeback (W). La codifica dell'istruzione SRS risulta:

![[AE/img/img99.png|center|500]]



#### Return from exception
L'istruzione RFE (Return From Exception) permette di ripristinare lo stato del processore salvato da una istruzione di SRS al termine dell'esecuzione di una routine di servizio di una eccezione.
La RFE permette di caricare la coppia di registri PC e CPSR a partire dall'indirizzo contenuto in $< Rn >$ e nella successiva word. La sintassi dell'istruzione risulta:  
$$
RFE<Modo Agg> <Rn>\{!\}
$$
L'istruzione RFE si comporta come una LDM che opera sulla coppia di registri: PC e CPSR. Utilizza la stessa modalità di aggiornamento (IA, IB, DA e DB). Come per la SRS, il punto esclamativo permette di aggiornare il registro base con la nuova posizione di memoria ed agisce sul bit di writeback (W). L'istruzione è codificata nel seguente modo:

![[AE/img/img97.png|center|500]]

#### Set eandniess
Questa istruzione permette di modificare l'ordinamento dei byte (big-endian o little-endian) durante le operazioni di accesso in memoria. L'istruzione SETEND è stata introdotta per aumentare l'efficienza delle applicazioni rendendo possibile un accesso ottimizzato in funzione del formato di memorizzazione. Differentemente dalle altre istruzioni, la SETEND non può essere eseguita in modo condizionato e agisce direttamente sul bit E
del flag di stato CPSR senza alterarne gli altri bit. Sono possibili due sintassi, la prima per abilitare l'ordinamento big-endian (E=1) e la seconda per il little-endian (E=0):  
$$
SETEND \{BE|LE\}
$$
L’istruzione è codificata nel seguente modo:

![[AE/img/img98.png]]

