# Semplificazioni di formule in forma normale 
Data una formula in forma normale, come
$$y = x_{0} \bar x_{1} \bar x_{2}+  x_{0} x_{1}\bar x_{2} + x_{0}x_{1}x_{2}$$
possiamo immediatamente costruire un circuto che la implementi, ma semplificandola possiamo risparmiare qualche porta sul circuito finale.
La formula semplificata risulta quindi
$$y = x_{0} \bar x_{1} \bar x_{2}+  x_{0} x_{1}\bar x_{2} + x_{0}x_{1}x_{2}=$$$$= x_{0} \bar x_{1} \bar x_{2}+ x_{0}x_{1}(\bar x_{2}+ x_{2})
$$$$= x_{0} \bar x_{1} \bar x_{2}+ x_{0} x_{1}$$
In foto notiamo la differenza tra i due circuiti:
**circuito iniziale**
![[Pasted image 20230531110059.png|center]]

**circuito ridotto**
![[Pasted image 20230531110123.png|center]]

## Codici Gray e Mappe di Karnaugh

Confrontando la semplificazione che abbiamo svolto nel paragrafo precedente:
$$x_{0}  x_{1} \bar x_{2}+x_{0}  x_{1} \bar x_{2}= x_{0}x_{1}(\bar x_{2}+ x_{2})=x_{0}x_1 $$
Con la seguente tabella di verità:
![[Pasted image 20230531110206.png|center]]

Si noti che abbiamo raccolto i due **mintermini** relativi agli 1 cerchiati in blu in un unico implicante, $x_{0}x_{1}$ dove la variabile $x_{2}$ è stata eliminata perchè assume valori di verità diversi nelle due righe cerchiate in verde della tabella di verità, mentre $x_{0}$ e $x_1$ compaiono asseriti, perchè il loro valore di verità è 1 in entrambe le righe. Si noti che allo stesso modo avremmo potuto semplificare:
$$x_{0}  x_{1} \bar x_{2}+x_{0}  \bar x_{1} \bar x_{2} = x_{0}\bar x_{2}$$

dove a essere eliminata è la variabile $x_1$, mentre $x_0$ compare asserita e $x_2$ compare negata.
![[Pasted image 20230531110230.png|center]]

Per evidenziare direttamente dalla tabella quali semplificazioni si possono fare, sarebbe utile scrivere le righe con un ordinamento in cui ogni riga differisca dalla precedente e dalla successiva per un unico bit. È possibile farlo?
L'ordinamento usuale con cui scriviamo le $2^n$ righe di una tabella con $n$ variabili si può generare ricorsivamente in questo modo: 
Per costruire le righe della tabella con $n+1$ varibili, partiamo dalla riga della tabella con $n$ varibili, la "duplichiamo" e aggiungiamo 0 davanti a tutte le righe dell' "originale" e 1 davanti a tutte le righe della "copia"
![[Pasted image 20230531110259.png|center]]

Se nella costruzione precedente, quando "duplichiamo" la sequenza, la "ribaltiamo" anche, otteniamo un ordinamento chiamato codice di $Gray$ 
![[Pasted image 20230531110329.png|center]]
Quindi se scriviamo una tabella di verità con le righe ordinate secondo il codice di $Gray$ alcune semplificazioni appariranno immediatamente evidenti. Per esempio, la tabella nella (3) verrebbe scritta così: 
![[Pasted image 20230531110357.png|center]]

Dove i due 1 adiacenti cerchiati in blu evidenziano la semplificazione ($x_{0}  x_{1} \bar x_{2}+x_{0}  x_{1} x_{2} = x_{0}x_{1}$). Si osservi però che mentre alcune semplificazioni si evidenziano, altre rimangono "nascoste", come per esempio la semplificazione che si può ottenere dalla quinta e ultima riga della tabella precedente ($x_{0}  x_{1} \bar x_{2}+x_{0} \bar x_{1} \bar x_{2} = x_{0}\bar x_{2}$).
Per ottenere il massimo possibile da questa schematizzazione non è sufficiente ordinare le righe di una tabella secondo il codice di $Gray$, ma dobbiamo scrivere la tabella di verità in modo $bidimensionale$.

## Mappe di Karnaugh
Possiamo scrivere la tabella di verità in (4) anche in questo modo:
![[Pasted image 20230531110433.png|center]]

dove, per esempio, il numero cerchiato in verde rappresenta il valore che assume l'output $y$ quando la terna in input è ($x_{0}x_{1}x_{2}$) = (0,0,1). Una tabella scritta in questo modo si chiama $Mappa \ di \  Karnaugh$. Si noti che in una mappa di Karnaugh l'ordine con cui sono indicizzate righe e colonne è quello dato dal codice di $Gray$.
In una mappa di Karnaugh tutti i mintermini che si possono semplificare sono adiacenti
![[Pasted image 20230531110510.png|center]]

Si noti inoltre che, siccome le colonne della mappa di Karnaugh sono indicizzate con il codice di $Gray$, l'ultima colonna è adicente alla prima.
Si noti inoltre anche che l'1 in posizione $(x_{0},x_{1},x_{2})=(1,1,0)$ nella mappa in (5) è stato considerato due volte. Complessivamente quindi la forma semplificata che otteniamo dalla (5) è $$y = x_{0}x_{1}+ x_{0}\bar x_{2}$$
dove l'implicamente $x_{0}x_{1}$ corrisponde al rettangolo blu in (5) mentre l'implicante $x_{0}\bar x_{2}$ corrisponde a quello rosso.
SI noti che l'1 in poszione $(x_{0},x_{1},x_{2})= (1,1,0)$ nella mappa in (5) è stato considerato due volte. Complessivmente quindi la formula semplificata che otteniamo dalla (5) è $$y=x_{0}x_{1}+ x_{0}\bar x_{2}$$
dove l'implicante $x_{0}x_{1}$ corrisponde al rettangolo blu in (5) mentre l'implicante $x_{0}\bar x_{2}$ corrisponde a quello rosso.

Si osservi che nonostante gli 1 siano tutti adiacenti nella (5) non possiamo raggrupparli tutti e tre insieme in un unico implicante, mentre avremmo potuto farlo se fossero stati "quattro" adiacenti.

**Esempio**
In questo esempio si possono raggruppare gli 1 in questo modo
![[Pasted image 20230531110530.png|center]]

Ottendeno la formula $x_{0}+\bar x_{1}x_{2}$ , dove l'implicante $x_{0}$ viene dal rettangolo blu e l'implicante $\bar x_{1}x_{2}$ viene dal rettangolo rosso.

Se ci limitiamo a formule con al più quattro variabili, le mappe di Karnaugh ci consentono si semplificare una formula in forma normale disgiuntiva fino a ottenere il minor numero possibile di implicanti e con il minor numero di variabili per implicante. Per esempio, dalla seguente mappa di Karnaugh
![[Pasted image 20230531110548.png|center]]

Corrisponde la seguente formula $$\bar x_{0}\bar x_{3}+ \bar x_{0}x_{1}+ x_{0}\bar x_{1} x_{3}$$ Dove il primo implicante $\bar x_{0}\bar x_{3}$, viene dal quadrato blu, il secondo implicante $\bar x_{0} x_{1}$ viene dal rettangolo verde e il terzo implicante, $x_{0}\bar x_{1}x_{3}$, viene dal rettangolo rosso.
Osservate che se nella mappa (8) avessimo considerato dei rettangoli diversi, avremmo ottennuto una formula equivalente ma non minimizzata.