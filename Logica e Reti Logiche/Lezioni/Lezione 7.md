# Introduzione alla Logica del Primo Ordine
## 1 Antipasto
Prima di addentrarci nelle descrizione precisa di sintassi (quali sono i simboli che usiamo, le formule ben formate, . . . ) e semantica (cos’è una interpretazione, quando una formula è vera o falsa, . . . ) della logica del primo ordine, vediamo qualche esempio che dovrebbe essere comprensibile attingendo a ciò che già sappiamo e usando un po’ di intuito.
Consideriamo la seguente sequenza di simboli
$$\forall x[P(x)\vee Q(x)]\space\space\space(1)$$
Ricordate che, nel caso della logica proposizionale, una *interpretazione* di una formula ben è una assegnazione di verità per le variabili. Data una interpretazione, abbiamo visto che una formula risulta $T$ oppure $F$.
Secondo voi quale può essere una “interpretazione” di una formula tipo la (1)? Vediamo. Dobbiamo specificare due cose:
1. Un *dominio* all’interno del quale si muove la variabile $x$;
2. Una *proprietà* per ognuna delle due lettere predicative $P$ e $Q$.
Una volta che specifichiamo queste due cose la formula in (1) diventa $T$ o $F$.
>[!warning]- Esempio
>Prendiamo come dominio i numeri naturali $\mathbb N$. Per quanto riguarda le due lettere predicative $P$ e $Q$, assegnamogli queste proprietà $P(x)$ è *“x è pari”* e $Q(x)$ è *“x è dispari”*. In questa **interpretazione** la Formula (1) diventa *“Per ogni numero naturale $x$, $x$ è pari oppure $x$ è dispari”* . Direi che è senz’altro vera (a meno che non mi presentate un numero naturale che non è né pari né dispari).

>[!important]- Esempio
>Dominio $\mathbb N$, $P (x) =$“x è un numero primo”, $Q(x) =$ “x è una potenza di 2”.
>In questa interpretazione la (1) è **falsa**. Infatti, per esempio, il numero naturale 6 non è né un numero primo né una potenza di 2.
>Nei due esempi qui sopra ho usato delle interpretazioni con degli “oggetti matematici”, ma una interpretazione di una formula può riferirsi essenzialmente a qualunque cosa.

>[!warning]- Esempio
>Dominio: Persone; $P (x) =$ “x è maschio”; $Q(x) =$ “x è femmina”. Direi che la (1) è vera anche in questa interpretazione.

>[!danger]- Esercizio 1
>Trovare altre due interpretazioni della (1), una in cui è vera, l’altra in cui è falsa. Nella formula (1) le lettere predicative, $P$ e $Q$, hanno un solo argomento, indicano quindi una *proprietà* degli elementi del dominio. Le lettere predicative posso avere più argomenti, nel qual caso indicano delle **relazioni** fra gli elementi del dominio.

### Esempio
Consideriamo la formula:$$\exists x\forall yP(x,y)\space\space\space (2)$$
<u>Interpretazione 1</u>: Prendiamo come dominio $\mathbb N$ e come $P (x, y)$ la relazione *“x è minore o uguale a y”*. In questa interpretazione la Formula (2) risulta **“Esiste un numero naturale x tale che per ogni numero naturale y, abbiamo che x è minore o uguale a y”**. Possiamoanche scriverla con la usuale simbologia usata in matematica $$\exists x\in\mathbb N:\forall x\in\mathbb N, x\leq y$$
Sarete d’accordo che la (2) è vera in questa interpretazione. Infatti, c’è il numero naturale 1, per cui vale che tutti i numeri naturali sono maggiori o uguali a 1. D’altra parte, è facile trovare delle interpretazioni in cui la (2) è falsa, per esempio: 
<u>Interpretazione 2</u>: Dominio $\mathbb Z$ e $P (x, y)$ come prima;  
<u>Interpretazione 3</u>: Dominio $\mathbb N$ e $P (x, y)$ con la disuguaglianza invertita ($x\geq y$).
>[!danger]- Esercizi 2-4

## 2 Sintassi e semantica
I simboli che usiamo nella logica del primo ordine sono:
1. I *connettivi* ($\lnot,\vee,\wedge,\rightarrow, ...$ ) usati anche nella logica proposizionale;
2. Le *variabili* ($x, y, z, . . .$ oppure $x_1 , x_2 , x_3 , . . .$), che qui chiamiamo *individuali* per distinguerle dalle variabili Booleane della logica proposizionale. Le variabili individuali possono assumere valori in qualunque dominio;
3. Le *lettere predicative* ($P , Q, R, . . .$ oppure $P_1 , P_2 , P_3 , . . .$ ). A volte può essere utile indicare con un apice il numero di argomenti (per esempio, $P^{(n)}$ ).
4. I *quantificatori* ($\forall$ e $\exists$). 
In aggiunta ai simboli qui sopra, che abbiamo già utilizzato intuitivamente nellasezione precedente, useremo anche altri simboli:
1. Le *costanti* ($a, b, c, . . .$ oppure $a_1 , a_2 , a_3 , . . .$ ), che servono ad indicare specifici elementi del dominio;
2. Le *lettere funzionali* ($f , g, h, . . .$ oppure $f_1 , f_2 , f_3 , . . .$ ). Per esempio, $f(x_1,x_2)$ indicherà una funzione che mappa una coppia ordinata $(x_1,x_2)$ di elementi del dominio in un altro elementi del dominio $f(x_1,x_2)$. Come per le lettere predicative, anche nel caso delle lettere funzionali può essere utile indicare con un apice il numero di argomenti della funzione.
Dobbiamo definire cosa si intende per **formula ben formata** nella logica del primo ordine. Per farlo, abbiamo prima bisogno di definire cos’è un *termine*.
>[!important]- Definizione 2.1 (Termine)
>Le variabili e le costanti sono **termini**. Se $t_1 , . . . , t_n$ sono termini e $f^{(n)}$ è una lettera funzionale con $n$ argomenti, allora anche $f^{(n)}(t_1 , . . . , t_n )$ è un **termine**.

Ora possiamo dare una definizione precisa di *formula ben formata*.
>[!important]- Definizione 2.2 (Formule ben formate)
>Se $t_1 , . . . , t_n$ sono termini e $P (n)$ è una lettera predicativa con $n$ argomenti, allora $P^{(n)}(t_1 , . . . , t_n )$ è una **formula ben formata** *(f.b.f.)*. Queste si chiamano formule **atomiche**. Inoltre:
>1. Se $\mathcal F$ è una $f.b.f.$, allora anche $\lnot\mathcal F$ è una $f.b.f$.
>2. Se $\mathcal F$ e $\mathcal G$ sono $f.b.f.$ allora anche $\mathcal F\bullet\mathcal G$ è una $f.b.f.$, dove con $\bullet$ abbiamo indicato uno qualunque dei connettivi $\wedge,\vee,\rightarrow,\equiv$.
>3. Infine, se $\mathcal F$ è una $f.b.f.$ e $x$ è una variabile, allora anche $\forall x\mathcal F$ e $\exists x\mathcal F$ sono $f.b.f.$
>4. Nient’altro è una $f.b.f$.

>[!danger]- Esercizio 5

>[!important]- Definizione 2.3 (Interpretazione)
>Data una f.b.f. F, una sua interpretazione consiste in
>1. Un insieme non vuoto $D$ che chiamiamo *dominio*;
>2. Una proprietà o una relazione per ogni lettera predicativa $P$ in $\mathcal F$;
>3. Una funzione per ogni lettera funzionale $f$ in $\mathcal F$;
>4. Un elemento del dominio per ogni costante $a$ in $\mathcal F$.

Nel determinare la verità o meno di una formula in una data interpretazione, il significato dei connettivi che hanno nella logica proposizionale, il significato dei quantificatori è quello usuale.
### Esempio
Consideriamo la formula $$\forall x\exists yP(f(x,a),y)\space\space\space(6)$$
<u>Interpretazione 1</u>. Dominio $\mathbb N$; $P (x, y) =$*“x è uguale a y”*; $f (x, y) = x^y$ ; $a = 2$. In questa interpretazione la formula si legge **“Per ogni numero naturale $x$ esiste un numero naturale $y$ tale che $x^2 = y$”**. Direi che è $T$.
<u>Interpretazione 2</u>. Tutto come nell’Interpretazione 1, tranne che $P (x, y) =$ *“x è maggiore di y”*. In questa interpretazione la (6) si legge, **“Per ogni numero naturale $x$ esiste un numero naturale $y$ tale che $x_2$ è maggiore di $y$”**. Quindi è $F$, perché non è vera per $x = 1$.

>[!danger]- Esercizio 6 
>Trovare altre due interpretazioni della (6), una in cui è $T$, l’altra in cui è $F$.


## 3 Variabili libere e vincolate. Formule chiuse
Per tutte le formule viste finora, una volta data una interpretazione $I$, la formula risultava $T$ o $F$ nell’interpretazione $I$. Tuttavia, questo non è vero per ogni $f.b.f.$ in accordo alla *Definizione 2.2*. Per esempio, osservate che la formula $\forall xP(x,y)$ è una $f.b.f.$ secondo la *Definizione 2.2*. Proviamo a darne una interpretazione: dominio $\mathbb N$ e $P (x, y) =$*“x è maggiore di y”*. In questa interpretazione la formula si legge **“Per ogni numero naturale $x$ si ha che $x$ è maggiore di $y$”**. Vera o falsa? Non si può dire perché non sappiamo chi è
$y$. In quella formula si dice che $x$ è una **variabile vincolata**, mentre $y$ è **libera**.
>[!important]- Definizione 3.1 (Variabili libere e vincolate)
>In una $f.b.f.$ si dice **vincolata** una variabile che sta nel campo d’azione di un quantificatore. Altrimenti la variabile si dice **libera**.

>[!danger]- Esercizio 7

>[!important]- Definizione 3.2 (Formule chiuse)
>Una f.b.f. senza variabili libere si dice chiusa.

>[!danger]- Esercizi 8-9

## Formule Valide vs Tautologie
Nella Sezione 1 abbiamo visto che ci sono delle formule che sono vere in ogni interpretazione.
>[!important]- Definizione 4.1. (Formule valide) 
>Una formula $\mathcal F$ vera in ogni interpretazione si dice **valida**.

Perchè non le chiamiamo *tautologie*, come nel caso della logica proposizionale? Perché vogliamo riservare il termine tautologie per un sottoinsieme delle formule valide. Per esempio, considerate la formula seguente:$$\forall xP(x)\vee\lnot(\forall xP(x))$$
Questa formula del tipo $\mathcal F\vee\lnot\mathcal F$, quindi chiaramente deve essere vera in ogni interpretazione. Nella logica del primo ordine si chiamano *tautologie* le formule che sono istanze di tautologie della logica proposizionale. Per esempio, la formula$$\forall xP(x)\rightarrow(\exists xQ(x)\rightarrow\forall xP(x))\space\space\space(7)$$
Si ottiene dalla formula $X \rightarrow (Y\rightarrow X)$ sostituendo $\forall xP(x)$ a $X$ e $\exists xQ(x)$. La formula (7) pertanto è una tautologia mentre, per esempio la (3), pur essendo valida, non è una tautologia.
Si noti che una tautologia è vera in ogni interpretazione *indipendentemente* dal significato che hanno i quantificatori, mentre una formula valida che non è una tautologia è vera in ogni interpretazione *per* il significato che hanno i quantificatori.
## 5 Interdipendenza dei quantificatori
I due quantificatori $\forall$ e $\exists$ non sono indipendenti, nel senso che si può “definire” uno in funzione dell’altro. Per esempio, la formula $\lnot\exists xP(x)$ è equivalente alla formula $\forall x\lnot P(x)$.
Infatti, data una qualunque interpretazione, la prima sta dicendo che “non esiste un elemento del dominio per cui vale la proprietà $P$ ”, la seconda sta dicendo che “per ogni elemento del dominio non vale la proprietà $P$ ”.
>[!danger]- Esercizio 10

## Conclusioni
In questo episodio abbiamo introdotto sintassi e semantica della logica del primo ordine, abbiamo osservato che ogni formula chiusa è $T$ o $F$ in una data interpretazione e abbiamo definito *valide* le formule che risultano $T$ in ogni interpretazione.
Se vogliamo mostrare che una certa formula non è valida, ci basta dare un *controesempio*, ossia una interpretazione in cui è falsa. E se vogliamo mostrare che è valida? Non possiamo certo elencare tutte le possibili interpretazioni (come in una tabella di verità per una formula della logica proposizionale), perché le possibili interpretazioni di una formula della logica del primo ordine sono infinite! 
Nel prossimo episodio vedremo che invece il metodo dei *tableaux*, che abbiamo introdotto per la logica proposizionale, può essere facilmente esteso anche alla logica del primo ordine per dimostrare che una data formula è valida.