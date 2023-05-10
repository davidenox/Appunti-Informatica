#  Numeri e codifiche
Con questo episodio iniziamo la seconda parte del corso, in cui vedremo come la logica proposizionale può essere implementata con dei circuiti per ottenere funzioni via via più sofisticate.
Tutte le informazioni che devono passare per i circuiti di un computer devono in qualche modo essere codificate in *binario*.
## 1 Rappresentazione dei numeri naturali
>[!note]
>Ci sono soltanto 10 tipi di persone al mondo: quelli che conoscono la codifica binaria e quelli che non la conoscono.

Leggendola la prima reazione potrebbe essere: non ha senso, dove sono gli altri otto tipi? Poi un attimo di riflessione e quelli che conoscono il binario capiscono, per gli altri continua a non avere senso.
Un “numero” è un concetto astratto. I modi i cui scriviamo un numero sono molteplici.
Per esempio: sette, seven, 7 e 111 sono sequenze di simboli che esprimono tutte lo stesso concetto astratto, ognuna in una “codifica” diversa (in questo caso, italiano, inglese, decimale, binario). Al contrario delle codifiche nelle diverse lingue, le codifiche posizionali, come quella decimale e quella binaria, seguono tutte lo stesso schema: scelta una base $b\in\mathbb N$ con $b\geq 2$ e un insieme $B$ di $b$ simboli, ognuno dei quali rappresenta un numero compreso fra $0$ e $b − 1$, una sequenza di simboli $x_{k−1} x_{k−2} . . . x_1 x_0$ , dove ognuno degli $x_i$ è
un simbolo in $B$, rappresenta il numero$$x_{k−1} b^k + x_{k−2} b^{k−1} + · · · x_1 b + x_0\space\space\space(1)$$
>[!danger]- Esercizio 1 
>Verificare che se prendessimo il numero “tre” come base e i simboli $a, b, c$ per indicare rispettivamente i numeri “zero”, “uno” e “due”, allora la sequenza di simboli "bacca" rappresenterebbe il numero “centosei”.

Scriveremo (xk−1 xk−2 . . . x1 x0 )b per indicare che la sequenza di simboli xk−1 xk−2 . . . x1 x0
rappresenta il numero definito dalla (1).
I componenti elementari di un computer sono progettati per distinguere la differenza
di potenziale agli estremi di un conduttore, e il modo più affidabile per farlo è distinguere
soltanto fra due valori: alto e basso. La codifica privilegiata dai computer perciò è quella
binaria.