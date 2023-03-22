# Logica proposizionale
>[!info]
>Capitolo 5 del libro

## 1. lettere proposizionali, connettivi, tabelle di verità
Indichiamo con $p, q, r,...$ delle variabili Booleane, ossia variabili che possono assumere valore *True* (Vero, che d'ora in poi indicheremo con **T**) o *False* (che d'ora in poi indicheremo con **F**). Chiamiamo **lettere proposizionali** i simboli $p, q, r,...$ con cui indichiamo le variabili.
A partire dalle lettere proposizionali possiamo costruire delle *formule* più complesse usando i *connettivi*: data una variabile $p$, indichiamo con $\sim p$ la formula che è **T** se e solo se $p$ è **F**; indichiamo con $p\wedge q$ la formula che è **T** se e solo se almeno una fra $p$ e $q$ è **T** e con $p\vee q$ la formula che è **T** quando $p$ e $q$ sono entrambe **T**. Possiamo sintetizzare queste affermazioni nelle cosiddette *tabelle di verità*.
![[Pasted image 20230320144230.png|center|500]]
Sicuramente sono già conosciute anche $\Rightarrow$ (implicazione) e $\equiv$ (equivalenza), che hanno le seguenti tabelle di verità:
![[Pasted image 20230320144424.png|center|400]]
Quanti connettivi ci possono essere, in tutto?
![[Pasted image 20230320144516.png|center|400]]
Siccome ognuna delle x nella tabella precedente può essere **T** o **F**, in tutto ci saranno 16 tabelle distinte.
>[!danger]- Esercizio 1
>Scrivere le 16 tabelle di verità e provare a dare un 'nome' ad ognuna di esse.

## 2. Formule ben formate
Ad ogni "formula" della logica proposizionale, possiamo associare una tabella di verità.
Per esempio, la formula $p\wedge (q\vee\sim r)$ vale **T** se e soltanto se $p$ è **T** e ($q$ è **T** oppure $r$ è **F**), quindi avrà la seguente tabella di verità:
![[Pasted image 20230320145124.png|center|400]]

>[!danger]- Esercizio 2
>Scrivere le tabelle di verità delle seguenti formule:
> 1. $(p\Rightarrow q)\vee\sim p$ ;
> 2. $(p\Rightarrow(q\Rightarrow p))\Rightarrow((p\Rightarrow q)\Rightarrow(p\Rightarrow r))$ ;
> 3. $(p\Rightarrow(p\equiv q))\vee\sim (p\Rightarrow q)$ ;
> 4. $(p\wedge q)\vee (\sim p\wedge\sim q) ;$

Si osservi che non tutte le sequenze di lettere proposizionali e connettivi sono formule di cui possiamo dare una tabella di verità. Per esempio, se si prova a dare una tabella di verità per
$$p\Rightarrow\sim\vee (q\wedge r)\equiv\space\space\space\space\space\space\space\space(1)$$
Abbiamo bisogno di una denizione di **formula ben formata**.
>[!important]- Def. 2.1 (Formule ben formate)
>Le lettere proposizionali sono formule ben formate (abbreviato f.b.f., d'ora in poi). Inoltre:
>1. Se $\mathcal F$ è una f.b.f., allora anche $\sim\mathcal F$ è una f.b.f
>2. .1. Se $\mathcal F$ e $\mathcal G$ sono f.b.f. allora anche $\mathcal F \circ \mathcal G$ è una f.b.f., dove con $\circ$ abbiamo indicato uno qualunque dei connettivi $\wedge\vee\Rightarrow\equiv$.
>3. Nient'altro è una f.b.f.

>[!danger]- Esercizio 3
>Si osservi che tutte le formule dell'Esercizio 2 sono f.b.f. secondo la definizione precedente, mentre la sequenza di simboli in (1) non lo è. Ogni formula ben formata ha la sua tabella di verità. Viceversa, data una qualunque tabella di verità possiamo sempre trovare una formula (tante, in realtà) che ha quella data come tabella di verità.

>[!danger]- Esercizio 4
>Per ognuna delle seguenti tabelle di verità, trovare una formula corrispondente:
>![[Pasted image 20230320150758.png]]

>[!danger]- Esercizio 5
>Trovare un metodo per costruire una formula con una data tabella di verità. (Suggerimento: Se avete una tabella con una sola linea T e tutte le altre F, qual è una formula che fa al caso vostro? Trovata? Bene. Ora, se avete una formula con due linee T?. . . )
## 3. Tautologie, contraddizioni e contingenze
>[!abstract]- Formule di De Morgan
>![[Pasted image 20230320151226.png]]

Come sarà fatta la tabella di verità della formula (2) ?
$$\sim(p\vee q)\equiv(\sim p\wedge \sim q)\space\space\space\space\space\space(2)$$
E quella della formula (3)?
$$(\sim p\vee\sim q)\equiv\sim(p\wedge q)\space\space\space\space\space\space\space(3)$$
>[!danger]- Esercizio 6
>Vericate la vostra intuzione scrivendo esplicitamente le tabelle di verità delle formule (2) e (3).

Data una formula, chiamiamo interpretazione della formula un'assegnazione di verità alle sue variabili (osservate che, in una tabella di verità, ogni riga rappresenta una diversa
interpretazione). Data una formula F e una sua interpretazione $\tau$, la formula $\mathcal F$ è o **T** o **F** nell'interpretazione $\tau$ . Per esempio, la formula:
$$(p\vee q)\wedge\sim r$$
èF nell'interpretazione $(p, q, r) = (T, F, T)$ mentre è T nell'interpretazione $(p, q, r) = (T, F, F)$.
Si chiamano *tautologie* le formule che sono **T** in ogni interpretazione, *contraddizioni* quelle che sono **F** in ogni interpretazione e *contingenze* le altre (quelle che sono **T** in alcune interpretazioni e **F** in altre).
>[!danger]- Esercizio 7
>Per ognuna delle seguenti formule, dire se e una tautologia, una contraddizione, o una contingenza.
>1. $(p\Rightarrow q)\Rightarrow(q\Rightarrow p)$ ;
>2. $(p\Rightarrow q)\Rightarrow (\sim p\Rightarrow\sim q)$
>3. $(p\Rightarrow q)\Rightarrow(\sim q\Rightarrow\sim p)$
>4. $p\Rightarrow\sim p$
>5. $p\equiv\sim p$
>6. $(p\equiv q)\equiv(\sim p\equiv\sim q)$
>7. $\sim(p\wedge q)\equiv (\sim p\wedge \sim q)$
>8. $\sim(p\wedge q)\equiv(sim p\vee\sim q)$
>9. $(sim p\vee\sim q)\equiv\sim(p\vee q)$
>10. $\sim(p\vee q)\equiv (\sim p\wedge\sim q)$
>11. $(p\equiv(p\wedge q))\equiv (q\equiv(p\vee q))$

Si osservi che $\mathcal F$ è una tautologia se e soltanto se $\sim\mathcal F$ è una contraddizione. E viceversa. Diciamo che due formule sono equivalenti se hanno la stessa tabella di verità. Osservate che $\mathcal F$ e $\mathcal G$ sono equivalenti se e soltanto se $\mathcal F\equiv\mathcal G$ è una tautologia.
## Costanti
Abbiamo usato le lettere proposizionali $p, q, r, ...$ per indicare delle variabili Booleane. E' utile aggiungere due lettere proposizionali, $t$ e $f$, per indicare le due *costanti* Booleane **T**
e **F**. Si osserva, per esempio, che:
1. $p\wedge f$ è equivalente a $f$ mentre $p\wedge t$ è equivalente a $p$;
2. $p\vee f$ è equivalente a $p$ mentre $p\vee t$ è equivalente a $t$;
3. $f\wedge t$ è equivalente a $f$ mentre $f\vee t$ è equivalente a t.
E interessante osservare che ogni formula che contiene $t$ e/o $f$ è sempre o equivalente a una formula che non contiene né $t$ né $f$ oppure è equivalente o a $t$ o a $f$.
>[!danger]- Esercizio 8
>Ridurre le formule seguenti, che contengono le costanti $t$ e $f$, a formule equivalenti che o non contengono né $t$ né $f$, oppure sono uguali o a $t$ o a $f$:
>1. $((t\Rightarrow p)\wedge(q\vee f))\Rightarrow((q\Rightarrow f)\vee(r\Rightarrow t))$ ;
>2. $(p\vee t)\Rightarrow q$ ;
>3. $\sim(p\vee t)\equiv(f\Rightarrow q)$ ;
>4. $(\sim(p\vee f)\wedge(q\equiv t))\Rightarrow(r\wedge t)$ .

## Interdipendenza dei connettivi
Finora nelle formule sono stati usati i connettivi $\sim,\wedge,\vee,\Rightarrow$, e $\equiv$. Osservate che questi non sono tutti "necessari", perché per esempio, 
1. $p\Rightarrow q$ è equivalente a $\sim p\vee q$, diciamo in questo caso che il connettivo $\Rightarrow$ può essere definito in termini dei connettivi $\sim$
e $\vee$ ;
2. $p\equiv q$ è equivalente a $\sim(\sim p\vee\sim q)$, quindi anche $\vee$ può essere definito in termini di $\sim$ e$\vee$ ;
3. $p\equiv q$ è equivalente a $(p\Rightarrow q)\wedge(q\Rightarrow p)$ o anche a $(p\wedge q)\vee(\sim p\wedge\sim q)$, e siccome $\Rightarrow$ e $\wedge$ possono essere definiti in termini di $\sim$ e $\vee$ anche $\equiv$ può essere definito in termini di $\sim$ e $\vee$ .
Quindi potremmo riscrivere tutte le formule viste finora usando soltanto i due connettivi $\sim$ e $\vee$ . In modo analogo, potremmo farlo usando soltanto i due connettivi $\sim$ e $\wedge$ .
>[!danger]- Esercizio 9
>Definire ognuno dei connettivi $\vee,\Rightarrow,\equiv,$ in termini dei connettivi $\sim$ e $\vee$ .

Non c'è niente di speciale nelle coppie di connettivi scelte qui sopra. Potremmo usare altre combinazioni.
>[!danger]- Esercizio 10
>1. Definire il connettivo $\wedge$ in termini dei connettivi $\sim$ e $Rightarrow$ ;
>2. Definire il connettivo $\equiv$ in termini dei connettivi $\wedge$ e $Rightarrow$ ;
>3. Definire il connettivo $\vee$ in termini del connettivo $\Rightarrow$ ;
>4. Definire il connettivo $\sim$ in termini del connettivo $\Rightarrow$ e di f.

Si considera il connettivo seguente, che chiamiamo *joint denial* (lo chiameremo nor, quando parleremo di circuiti): 
![[Pasted image 20230320171405.png|center|400]]

Si osserva che:
1. $p\downarrow p$ è **F** quando $p$ è **T** ed è **T** quando $p$ è **F**. In altri termini, $p\downarrow p$ è equivalente a $\sim p$;
2. La tabella di verità di $\downarrow$ è la negazione di quella di $\vee$, ossia $p\downarrow q$ è equivalente a $\sim(p\vee q)$. Ma allora $p\vee q$ deve essere equivalente a $\sim(p\downarrow q)$, che a sua volta, per il punto precedente, deve essere equivalente a $(p\downarrow q)\downarrow(p\downarrow q)$.
>[!danger]- Esercizio 11 
>Verificare che $(p\downarrow q)\downarrow (p\downarrow q)$ ha la stessa tabella di verità di $p\vee q$. 

Siccome possiamo definire i connettivi $\sim$ e $\vee$ in termini del connettivo $\downarrow$ per quanto visto all'inizio di questa sezione, possiamo definire anche tutti gli altri connettivi in termini del
connettivo $\downarrow$.
Oltre a $\downarrow$, c'è un altro connettivo che, da solo, può essere usato per definire tutti gli altri: lo indichiamo con $|$ e lo chiamiamo *alternative denial* (oppure **NAND**).
![[Pasted image 20230320172146.png|center|400]]

>[!danger]- Esercizio 12
>Definire i connettivi $\wedge$ e $\sim$ in termini del connettivo $|$.

# Riepilogo
In questo episodio abbiamo iniziato a studiare la logica proposizionale, introducendone la *sintassi* (ossia, qual è la "forma" degli oggetti che studiamo: lettere proposizionali,
connettivi, formule ben formate) e la *semantica* (ossia, qual è il loro "signicato": tabelle di verità, interpretazioni). Abbiamo classificato le formule della logica proposizionale in **tautologie**, **contingenze** e **contraddizioni**. Abbiamo osservato che i connettivi non sono indipendenti fra loro e ne abbiamo individuato due "speciali". Inne abbiamo accennato
alle formule in notazione polacca e ne abbiamo visto qualche proprietà.


 