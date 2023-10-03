# Introduzione al corso
## Prerequisiti
- - Programmazione di base
- - Strutture dati elementari (array, struct, puntatori)
- - Concetto di ricorsione
- - Dimostrazione per induzione e calcolo infinitesimale
# Inizio

>[!important]- Algoritmo
>Procedimento che descrive una sequenza di passi ben definiti finalizzato a risolvere un dato problema (computazionale).

Un algoritmo può essere visto come *l'essenza computazionale* di un programma, ovvero fornisce il procedimento per giungere alla soluzione di un dato problema di calcolo.

>[!warning]- Algoritmo diverso da programma
>1. Programma è la codifica di un algoritmo
>2. Un algoritmo può essere visto come un programma distillato da dettagli riguardanti il linguaggio di programmazione, ambiente di sviluppo, sistema operativo
>3. Algoritmo è un concetto autonomo da quello di programma

L'obiettivo è analizzare e *progettare* "buoni" algoritmi;
1. **Corretti** : producono correttamente il risultato desiderato;
2. **Efficienti** : usano poche risorse di calcolo, come *tempo* e memoria.
## Concetti principali
1. Complessità temporale
2. Algoritmo
3. Problema
4. Istanza
5. Modello di calcolo
6. Efficienza
7. Dimensione dell'istanza
8. Caso peggiore
9. Correttezza
### Esempio
Si hanno *n* monete, tutte identiche d'aspetto. Una delle monete è **Falsa**, e pesa leggermente più delle altre. Si ha a disposizione solo una bilancia a due piatti.
**OBIETTIVO** : Individuare la moneta falsa (facendo poche pesate).
*Problema* : Individuare una moneta falsa tra **n** monete;
*Istanza* : **n** specifiche monete; quella falsa è una di queste;
*Dimensione dell'istanza* : Il valore **n** ;
*Modello di calcolo* : Bilancia a due piatti;
*Algoritmo* : Strategia di pesatura. La descrizione deve essere "comprensibile" e "compatta". Deve descrivere la sequenza di operazioni sul modello di calcolo eseguite per una *generica* istanza;
*Correttezza dell'algoritmo* : La strategia di pesatura deve funzionare (individuare la moneta falsa) per una *generica* istanza, ovvero indipendentemente da quante monete sono, e se la moneta falsa è la prima, la seconda, ecc.. ;
*Complessità temporale dell'algoritmo* : # di pesate che esegue prima di individuare la moneta falsa. Dipende dalla dimensione dell'istanza e dall'istanza stessa.
*Complessità temporale nel caso peggiore* : **massimo** di pesate che esegue su una istanza di una certa dimensione. È una delimitazione superiore a quanto "costa" risolvere una *generica* istanza. Espressa come funzione della dimensione dell'istanza.
*Efficienza dell'algoritmo* : L'algoritmo deve fare poche pesare, deve essere *veloce*. Ma veloce rispetto a cosa? Quando si può dire che un algoritmo è veloce?


... continua ...

### Lower bound

>[!important]- Teorema
>Un qualsiasi algoritmo che correttamente individua la moneta falsa fra *n* monete deve effettuare nel caso peggiore $\lceil\log_3 n\rceil$ pesate.

La dimostrazione usa argomentazioni matematiche per mostrare che un *generico* algoritmo se è corretto deve avere almeno una certa complessità temporale nel caso peggiore.
Dimostrazione elegante e non banale che usa la tecnica dell'*albero di decisione* di un problema

>[!info]- Alg4 è un algoritmo ottimo per il problema.

## Esercizio
Si devono cuocere *n* frittelle. Si ha a disposizione una *padella* che riesce a contenere due frittelle alla volta. Ogni frittella va cotta su tutti e due i lati e ogni lato richiede un minuto. Progettare un algoritmi che frigge le frittelle nel *minor tempo possibile*. Si argomenti, se possibile, sulla *ottimalità* dell'algoritmo proposto.