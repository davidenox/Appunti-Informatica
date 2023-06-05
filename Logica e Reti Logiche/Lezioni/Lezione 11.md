# Dalla logica ai circuiti
In questo episodio introduciamo le porte logiche e vediamo come possono essere combinate per ottenere dei circuiti che calcolano funzioni Booleane.
## 1 Porte logiche
Prima di tutto specifichiamo che quando si parla di circuiti tipicamente si usa una notazione diversa per esprimere gli stessi concetti che abbiamo usato nella logica proposizionale: per esempio, indichiamo con $0$ e $1$, $False$ e $True$, rispettivamente. Nella tabella qui sotto riassumiamo brevemente le notazioni principali.
![[Pasted image 20230511164121.png|center]]

Altri simboli usati in logica non hanno un corrispondente nel “linguaggio” dei circuiti, e viceversa. Per esempio, quando parliamo di circuiti non usiamo mai il simbolo $\Rightarrow$, ma chiaramente possiamo esprimere $p\Rightarrow q$ con $\bar{p}+q$. D’altra parte, in logica generalmente non si usa un simbolo specifico per lo $XOR$, mentre quando si parla di circuiti si usa a tale scopo $p\oplus q$.

>[!danger]- Esercizio 1 
>Si osservi che scrivendo $True$ come $1$ e $False$ come $0$, l’$AND$ corrisponde a una moltiplicazione o a un minimo ($pq$ è $1$ se e solo se $p$ e $q$ sono entrambe $1$) e l’$OR$ corrisponde a un massimo ($p + q$ è $0$ se e soltanto se $p$ e $q$ sono entrambe $0$).
>

In tutta la seconda parte del corso assumeremo di avere a disposizione delle porte logiche, che implementano le operazioni logiche elementari, and, or e not, senza preoccuparci di come sono costruite a partire da componenti elettriche (transistor e diodi) e le disegneremo cosı̀

![[Pasted image 20230511164924.png|center]]

Data una qualunque formula $\mathcal F$ della logica proposizionale, possiamo sempre costruire un circuito che implementi $\mathcal F$ usando le porte logiche elementari. Per esempio, la formula $x_0\Rightarrow (x_1\land x_2 )$ è equivalente alla formula $\bar{x}_0 \lor(x_1\land x_2)$, quindi un circuito che la implementa è

![[Pasted image 20230511165231.png|center]]

>[!danger]- Esercizio 2
>Costruire un circuito che implementi la formula seguente: 
>$$(p\Rightarrow q\land r)\lor(\not q\Rightarrow \not p)$$

>[!danger]- Esercizio 3
>Costruire un circuito che implementti la seguente tabella di verità
>![[Pasted image 20230511170828.png|center]]

>[!danger]- Esercizio 4 
>Usando soltanto porte and, or e not, progettare un circuito che implementi la seguente funzione Booleana $f:\\0, 1\}^3\rightarrow\{0, 1\}
>$$f(x_1,x_2,x_3)= x_1\oplus x_2\oplus x_3$$

In aggiunta alle porte logiche elementari, spesso possiamo assumere di avere anche altre porte logiche che implementano le operazioni binarie più comuni, per esempio: 
![[Pasted image 20230511171055.png|center]]

>[!danger]- Esercizio 5 
>Costruire le porte logiche elementari and, or e not usando solo
>1. Porte nor;
>2. Porte nand.

## 2 Operazioni aritmetiche
Utilizzando opportunamente le porte logiche è facile costruire circuiti in grado di eseguire *operazioni aritmetiche*. Vediamo come.
>[!warning]- Esempio

Costruiamo un circuito con tre input $a, b$ e due output $s$ e $c_{out}$ con le seguenti tabelle di verità
![[Pasted image 20230511171448.png|center|400]]

La tabella di $s$ è uno $XOR$ mentre quella di $c$ è un $AND$, quindi possiamo disegnare il circuito cosı̀
![[Pasted image 20230511171631.png|center|400]]

Si osservi ora che in questo circuito l’output $s$ è proprio la somma dei due bit in input, mentre l’output $c$ è il riporto. Un tale circuito si chiama **Half Adder**.
Ricordiamoci come facciamo la somma di due numeri espressi in binario.
>[!danger]- Esercizi 6-11

## 3 Forme normali e circuiti
Se abbiamo una formula in *forma normale* è immediato ricavare un circuito e disegnarlo in un modo “standard”. Per esempio, data la seguente tabella di verità
![[Pasted image 20230511172129.png|center|400]]

Possiamo scrivere una formula in forma normale *somma di prodotti* $$y=x_0\bar{x}_1\bar{x}_2+x_0x_1\bar{x}_2+x_0x_1x_2\space\space\space\space(1)$$
e disegnare un circuito che la implementa così:
![[Pasted image 20230511172343.png|center|400]]

>[!danger]- Esercizi 12-13

## 4 Conclusioni
In questo episodio abbiamo introdotto le porte logiche e abbiamo visto come implementare le formule della logica proposizionale tramite circuiti. Abbiamo accennato a come è possibile costruire dei circuiti in grado di fare le operazioni aritmetiche, costruendo un circuito che calcola la “somma” di due numeri. Infine abbiamo osservato che è sempre possibile costruire un circuito con una forma “standard” partendo da una formula in forma
normale e abbiamo visto che talvolta è possibile “semplificare” le formule, preservandone la *forma normale*, in modo da ottenenere dei circuiti equivalenti costruiti con meno porte.