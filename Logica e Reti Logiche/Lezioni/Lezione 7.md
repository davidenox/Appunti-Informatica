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
>2. Se $mathcal F$ e $\mathcal G$ sono f.b.f. allora anche F ◦ G è una f.b.f., dove con ◦ abbiamo indicato uno qualunque dei connettivi ∧, ∨, →, ≡.
>3. Infine, se F è una f.b.f. e x è una variabile, allora anche ∀xF e ∃xF sono f.b.f.
>4. Nient’altro è una f.b.f.