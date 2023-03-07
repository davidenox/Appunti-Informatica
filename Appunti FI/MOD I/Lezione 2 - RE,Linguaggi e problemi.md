## Espressioni regolari

_Def_
Dato un alfabeto $\Sigma$ e dato l'insieme di simboli $(+,\star,(,),\cdot,\emptyset)$ si definisce **espressione regolare** sull'alfabeto $\Sigma$ una stringa
$$r\in(\Sigma\:\cup(+,\star,(,),\cdot,\emptyset))^+$$
tale che valga una delle seguenti condizioni:
1. $r=\emptyset$
2. $r\in\Sigma$
3. $r=(s+t)$, oppure $r=(s\cdot t)$, oppure $r=s^\star$, dove s e t sono espressioni regolari sull'alfabeto $\Sigma$

**Esempio**
$\Sigma=(a,b)$
Un'espressione regolare su $\Sigma$ appena definito può essere $r=a)+b\cdot b$ 

Le espressioni regolari consentono di rappresentare linguaggi mediante una opportuna interpretazione dei simboli che le compongono. Nella tabella seguente si mostra la corrispondenza tra un'espressione regolare $r$ e il linguaggio $\mathcal L(r)$ che essa rappresenta

![[Pasted image 20221017111656.png|center]]

**Esempio**

L'espressione regolare $r=((a+b)^\star a)$ rappresenta il linguaggio
$$L=((a+b)^\star a)\implies L((a+b)^\star)\circ L(a)=L((a+b))^\star\circ L(a)=(L(a)\cup L(b))^\star \circ \lbrace{a}\rbrace=$$
$$=(\lbrace{a}\rbrace\cup\lbrace{b}\rbrace)^\star\circ\lbrace{a}\rbrace=\lbrace{a,b}\rbrace^\star\circ\lbrace{a}\rbrace\implies \lbrace x|x\in\lbrace{a,b}\rbrace^+,\text{x termina con a}\rbrace$$

**Esercizi** 

1) determinare l'espressione regolare che, sull'alfabeto $\lbrace a,b\rbrace$, definisce l'insieme delle stringhe il cui terzultimo carattere è una b
2) determinare il linguaggio definito dall'espressione regolare $a^\star((aa)^\star b+(bb)^\star a)b^\star$ 

## Linguaggi e problemi

L'insieme dei linguaggi è in stretto rapporto con quello dei **problemi di decisione**

### Problemi di decisione
_Def (**Problema di decisione**)_
Un problema di decisione è definito su un insieme di possibili **istanze** e associa ad ognuna di esse un valore Vero/Falso

L'insieme delle istanze è partizionato in istanze **positive e negative**: il problema, per ogni istanza, è riconoscere se è un istanza positiva


**Esempi**
1) una data sequenza i interi è ordinata crescente?
2) è possibile viaggiare tra tutti i capoluoghi di provincia italiani senza passare due volte per nessuno di essi?
3) dato un programma contenente una determinata funzione e un input del programma stesso, la funzione viene eseguita?
4) dati due capoluoghi di provinvia A e B, è possibile andare da uno all'altro percorrendo meno di x km?

1. risolubile da un algoritmo che opera in tempo lineare
2. risolubile da un algoritmo in tempo esponenziale(polinomiale?)
3. non risolubile da nessun algoritmo
4. risolubile da un algoritmo che opera in tempo polinomiale


I problemi di decisione rappresentano la tipologia "più semplice" di problemi:
- problemi di ricerca: restituzione di una soluzione, **se esiste**
- problemi di enumerazione: restituzione di tutte le soluzioni, se esistono
- problemi di ottimizzazione: restituzione della "migliore" soluzione possibile

### Relazione tra linguaggi e problemi
Dato un linguaggio L e una stringa x, determinare se $x\in L$ è un problema di decisione
Istanze: tutte le possibili stringhe; L: istanze positive

Dato un problema di decisione $\mathcal P$, l'insieme delle sue istanze è codificato per mezzo di uno **schema di codifica**: ad ogni istanza corrisponde una stringa
Una stringa può corrispondere a una istanza positiva, una istanza negativa o nessuna istanza
L insieme delle stringhe corrispondenti a codifiche di istanze positive
In generale, si assume che sia possibile distinguere facilmente(efficentemente) tra le stringhe che rappresentano istanze e le altre

- Definizione data: un problema di decisione è caratterizzato dall'insieme delle istanze positive, rispetto all'insieme di tutte le istanze
- Insiemi in generale infiniti: non è una definizione praticabile
- In genere, definizione di un problema per mezzo di una sua descrizione **finita**
- Caso particolare di descrizione: un algoritmo che **decide** il problema (restituisce Vero per istanze positive e Falso per istanze negative)

Tutti i problemi possono essere descritti in modo finito?
Equivalente a dire: per tutti i problemi di decisione esistono algoritmi che li risolvono?
La risposta è **NO**
_Dim_
Consideriamo i linguaggi definiti su un alfabeto dato, ad esempio $\lbrace 0,1\rbrace$
- Un linguaggio è un insieme (infinito, in generale) di stringhe su $\lbrace 0,1\rbrace$, e quindi corrisponde ad una sequenza di 0(Falso) o 1(Vero) sulla sequenza di tutte le stringhe ordinate,ad esempio, in modo lessicografico
- Applicando la diagonalizzazione vista per i numeri reali, ne risulta che l'insieme dei linguaggi non è numerabile

Consideriamo le descrizioni utilizzando un alfabeto dato, ad esempio, ancora $\lbrace 0,1\rbrace$:
- Una descrizione/algoritmo è una stringa su $\lbrace 0,1\rbrace$
- Dato un qualunque alfabeto finito, l'insieme delle stringhe corrispondenti è numerabile

**Conseguenza**: ci sono più problemi di decisione(linguaggi) che loro descrizioni finite(algoritmi). Quindi,esistono problemi/linguaggi non descrivibili in modo finiti e non decidibili mediante algoritmi $\square$ 

Quanto detto vale nel caso di descrizioni/algoritmi più generali possibili. Che succede se consideriamo delle restizioni nelle modalità di descrizione?
Perchè dovremmo porci la questione?
Descrizioni più limitate possono corrispondere ad algoritmi di decisione più efficenti




