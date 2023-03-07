
3 lezioni e 1 esercitazione (in modo ciclico) con i 2 tutor

Libri:
- Raymond M. Smullyan. A Beginner’s Guide to Mathematical Logic. Dover Publications, 2014. 
- Sarah L. Harris and David Money Harris. Sistemi digitali e architettura dei calcolatori. Zanichelli, 2017

# Programma generale

2 parti del corso:
1. Logica
	1. Riepilogo di matematica
	2. Logica proposizionale
	3. Logica del primo ordine
2. Reti logiche
	1. Reti combinatorie
	2. Reti sequenziali
	3. Codifiche

# Cos'è la logica?

> La logica è _ragionamento_ 

In modo meno formale, la logica è una strada che porta a una risposta

**Esempio**

Tutti gli uomini sono mortali $\to$ Io sono un uomo $\to$ Io sono mortale

**Esempio**

Tutte le mosche volano $\to$ Io sono una mosca $\to$ Io volo

Questi due sillogismi sono entrambi validi, perchè se sono vere le premesse, allora è vera anche la risposta

Per la struttura del ragionamento in se, i due sillogismi sono entrambi **_validi_**

**Esempio**

- Il cibo buono non è economico
- Il cibo economico non è buono

Le due frasi sono uguali?

Da un punto di vista prettamente logico si, vediamo perchè:

A = "il cibo è buono"
B = "il cibo è economico"

Possiamo vedere che $A\implies\overline B$ e $B\implies\overline A$

Le due relazioni sono equivalenti

## Come possiamo definire il concetto di "dimostrazione"?

Prendiamo alcuni esempi provenienti dalla teoria degli insiemi

Un'insieme è una collezione di oggetti

Le operazioni che si possono fare sugli insiemi sono:

- $A\cup B$ Unione
- $A\cap B$ Intersezione
- $A\setminus B$ Differenza
- $A\times B$ Prodotto cartesiano
- $\overline A$ Complementare di A
- $A\uplus B$ Unione disgiunta
- $(A\setminus B)\cup(B\setminus A)$ Differenza Simmetrica, si indica anche con il simbolo $\triangle$ $A\triangle B$

**Esempio**

$A\cup B=A\cap B$?

In genere no, ma se A e B sono uguali, la risposta diventa **SI**

Ma la relazione non è **valida** (valida = vera sempre)

**Esercizio**

$A\cap(B\triangle C)=(A\cap B)\triangle(A\cap C)$ 

Verificare che la relazione è valida

**Fine esercizio**

Data una sequenza 
$A_1,A_2,...,A_n$

La porzione $A_i$ sarà
$$A_i=\{\underline x=(x_1,...,x_n)\in\{0,1\}^\star:x_i=1\}$$

>[!important]- Osservazione
>Argomento ancora aperto

# Cosa significa "contare"?

Prendiamo due insiemi, l'insieme A con cardinalità che conosco e l'insieme B con cardinalità che non conosco

Devo cercare una **corrispondenza biunivoca** tra i due insiemi

Una corrispondenza biunivoca è una funzione definita in questo modo:
$$\begin{align}f:&B\to A\\&x\to f(x)\end{align}$$
che è una funzione sia iniettiva che suriettiva

- Iniettiva : $\forall x,y \in B, x\neq y\implies f(x)\neq f(y)$  

- Suriettiva: $\forall y \in A,\exists x\in A : f(x)=y$

Quindi contare un insieme significa mettere in corrispondenza biunivoca l'insieme con un insieme di cui conosco la cardinalità
 
# Dimostrazione per assurdo

Prendiamo il teorema di Cantor: Non esiste una corrispondenza biunivoca $f:\mathbb N\to \mathcal P(\mathbb N)$  

Dimostriamo il teorema (per assurdo)

Supponiamo che esiste una corrispondenza biunivoca tra $\mathbb N$ e $\mathcal P(\mathbb N)$ 
Supponiamo che esista questa enumerazione dei sottoinsiemi dei Naturali :
$$\mathcal P(\mathbb N)=\{A_1\subseteq \mathbb {N},A_2,A_3,...\}$$
Prendiamo un insieme definito in questo modo:
$C=\{x\in\mathbb N:x\not\in A_x\}\subseteq\mathbb N$

Siccome $C\subseteq\mathbb N$ allora $\exists n\in\mathbb N:A_n=C$ 

Domanda: $n\in C$ o $n\not\in C$

1. se $n\in C$, allora $n\in A_n$, ma di conseguenza $n\not\in C$ (contraddizione)
2. se $n\not\in C$, allora $n\not\in A_n$, ma di conseguenza $n\in C$ (contraddizione)

E quindi **assurdo**

