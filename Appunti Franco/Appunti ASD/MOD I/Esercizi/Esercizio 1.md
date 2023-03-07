# Esercizio Frittelle
## Testo
Si devono cuocere n fritelle. Si ha a disposizione una padella che riesce a contenere due fritelle alla volta. Ogni frittella va cotta su tutte e due i lati e ogni lato richiede un minuto.
Progettare un algoritmo che frigge le frittelle nel minor tempo possibile. Si argomenti, se possibile, sull'ottimità dell'algoritmo proposto

## Soluzione

### Caso base
Io ho n frittelle e una padella che può contenere al max. 2 frittelle per volta.
Nel caso base io cuocio 2 frittelle a volta, ottenendo così, in media, 1 min. di cottura per frittella
A questo punto, per cuocere n frittelle, io impiego n minuti, ottendendo così un tempo lineare in n $\implies \mathcal{O}(n)$

**Commento** se le frittelle sono dispari io ottengo un tempo di n-1 $\implies \mathcal{O}(n-1)$ che al tendere all'infinito è comunque $\mathcal{O}(n)$  

**Posso fare meglio di n?**
NO
## Dimostrazione
 
Dimostriamo per assurdo che io riesca a cuocere n frittelle in n-1 minuti, questo implica che all'interno della padella io possa mettere più di 2 frittelle (es. 3) e quindi risparmiarmi 1 minuto, ma questo è assurdo perchè nel modello di calcolo utilizzato (la padella) mi viene imposto che al max. ci possono stare 2 frittelle, e di conseguenza la mia ipotesi è falsa $\square$ 
