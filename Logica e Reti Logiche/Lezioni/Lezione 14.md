# Introduzione ai circuiti sequenziali
Tutti i circuiti visti nelle lezioni precedenti sono aciclici, ovvero non c'è mai un percorso che dall'output di una porta logica P torna in input alla stessa porta. Questi circuiti si chiamano **circuiti combinatori**. In questa lezione vedremo che si possono costruire dei circuiti contenenti dei cicli.
## Antipasto
Cosa succede se costruissimo un circuito in questo modo?

![[Pasted image 20230531143414.png|center|400]]

Sembra un "paradosso logico", infatti se l'input della porta NOT è 1 deve anche essere 0 e viceversa. E se provassimo a costruirlo in questo modo?

![[Pasted image 20230531143450.png|center|500]]

Non appena diamo corrente all'input $x$, qualcosa di brutto accadrà alla porta NOT. Tuttavia, costruire un circuito che contiene un ciclo non sempre genera un cortocircuito, come nell'esempio qui sotto: 

![[Pasted image 20230531143531.png|center]]

Anche se contiene un ciclo, le due porte NOT non hanno problemi. Ovviamente il circuito fa ben poco, perché l'output $y$ sarà uguale all'input $x$. Chiamiamolo elemento **bistabile** e osserviamo che possiamo disegnarlo in modo differente e descrivere l'output in funzione dell'input con una tabella di verità.

![[Pasted image 20230531143552.png|center]]

Cosa succede se proviamo ad utilizzare lo stesso schema utilizzando porte a due ingressi, come ad esempio delle porte OR in cui l'output di una delle due porte entra in input nell'altra porta

![[Pasted image 20230531143626.png|center|500]]

Siccome l'output di una porta OR è 1 quando almeno uno dei due ingressi è 1, non c'è nessun dubbio su quali siano i valori degli output $y_0$ e $y_1$ quando almeno uno dei due ingressi è 1: per esempio se $x_{0}=1$ allora $y_{0}=1$ e quindi anche $y_{1}$ sarà 1. Ma cosa possiamo dire sui bit in output $(y_{0},y_{1})$, quando i bit in input sono entrambi zero, $(x_{0},x_{1})=(0,\: 0)$.

![[Pasted image 20230531143656.png|center|400]]

Se immaginiamo che il circuito parta da una configurazione iniziale in cui sia gli input che gli output sono 0, allora non appena poniamo a 1 uno dei due bit in input entrambi gli output andranno ad 1 e da lì in poi rimarranno sempre $(y_{0}, y_{1})=(1,\:1)$.
Come per l'elemento bistabile quindi anche in questo circuito, nonostante ci siano dei cicli, non creiamo nessun "paradosso logico" assegnando dei valori in input. Anche questo circuito però non fa nulla di interessante: manovrando gli input possiamo soltanto spostare una volta i valori di output da 0 a 1, che poi rimarranno fissi a 1 indipendentemente da come riassegnamo gli input.

## SR-Latch e D-Latch
Se costruiamo un circuito come abbiamo fatto prima, ma utilizzando porte NOR (o NAND), non otteniamo paradossi logici e succede anche qualcosa di interessante.
Consideriamo questo circuito con la tabella di verità della porta NOR:
![[Pasted image 20230531143729.png|center]]
![[Pasted image 20230531143807.png|center|300]]


Come sarà la tabella di verità del circuito?

![[Pasted image 20230531143828.png|center|400]]

Con questo circuito quindi possiamo, per esempio, impostare per un attimo gli input a $(x_{0}, x_{1})=(1,\:0)$ e così settare il bit in output $y_{1}=1$ e il bit $y_{0}= 0$, riportare gli input a $(x_{0},x_{1})= (0,0)$ e $y_{1}$, rimarrà a 1.
Inoltre, impostando per un attimo gli input a $(x_{0}, x_{1})=(0,1)$ possiamo resettare il bit $y_{1} = 0$.
Osservate che abbiamo  appena costruito una memoria: un circuito in grado di fissare un bit in output $yi$ a 0 o 1, a seconda dei valori assegnati agli input $(x_{0}, x_{1})$, e ricordare il bit assegnato a $y_{1}$ quando entrambi gli input tornano ad avere valore .
Il circuito costruito si chiama SR - Latch: gli input si chiamano S e R (Set e Reset) e gli output $Q \ e \ \bar Q$, e il simbolo con cui si indica il circuito è quello in Figura (1).

Osservate che chiamare gli output di un SR - Latch $Q  \ e \ \bar Q$ non è propriamente corretto, perchè se gli input R e S sono entrambi 1 e gli output sono entrambi zero. Inoltre impostare entrambi gli input a 1 crea anche un altro problema.
![[Pasted image 20230531143957.png|center]]

Si deve assolutamente eliminare la possibilità che gli input siano entrambi 1

![[Pasted image 20230531144028.png|center]]

Il circuito costruito qui sopra, oltre che a garantire che i due output $Q$ e $\bar Q$ saranno sempre uno il negato dell'altro, consente si separare quale bit viene assegnato all'output $Q$ da quando viene assegnato.
Il circuito così costruito si chiama D-Latch e il simbolo usato è quello in Figura (2).
Quando CLK = 1 si dice che il latch è trasparente, quando invece CLK = 0 si dice che il latch è opaco.

## Flip-flop e registri
Un D-Latch ci consente di settare il valore di $Q$ quando CLK = 1 e tenerlo in memoria per tutto il tempo in cui CLK = 0. Tuttavia il fatto che il latch è "trasparente" quando CLK = 1 può essere uno svantaggio in alcuni casi. Consideriamo un circuito fatto così

![[Pasted image 20230531144057.png|center]]

Quando CLK = 0 non c'è nessun problema: il valore in input D sarà uguale al negato dell'output $Q$, ma il valore di $Q$ non cambia perchè il latch è opaco. Nel momento in cui poniamo CLK = 1 però creiamo un "paradosso logico".

Questo problema può essere risolto mettendo in sequenza due D-Latch collegati ad un unica variabile CLK che entra negata nel primo latch e asserita nel secondo. Il circuito che otteniamo si chiama flip-flop: lo schema e il simbolo sono in Figura(3)

![[Pasted image 20230531144115.png|center]]

In un D-flip-flop:
- Quando CLK = 0 il latch master è trasparente ma il latch slave è opaco
- Quando CLK = 1 il latch slave è trasparente ma il latch master è opaco

In altre parole, il flip-flop fa passare il valore dell'input D all'output $Q$ solo "nel momento" in cui il valore di CLK passa da 0 a 1.
Se si pensa all'input CLK come a una variabile che periodicamente cambia valore da 0 a 1 e viceversa, l'output $Q$ rappresenta lo stato lo stato attuale del flip-flop e l'input D il suo stato futuro

Una serie di flip-flop con i clock sincronizzati costituiscono collegati un registro

![[Pasted image 20230531144139.png|center]]

Possiamo disegnare un registro a 4 bit anche in questo modo

![[Pasted image 20230531144222.png|center]]

I flip-flop, come gli altri blocchi funzionali, possono avere ulteriori input. Per esempio per abilitarli o per resettarli.