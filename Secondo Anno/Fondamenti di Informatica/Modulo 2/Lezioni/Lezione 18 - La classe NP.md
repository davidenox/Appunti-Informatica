# La classe NP
>[!info]
>Allo studio della classe NP è dedicata la dispensa 9. In particolare, la dispensa si occupa di due questioni “strutturali”, come studiare la struttura dei problemi che popolano la classe NP e studiare la struttura della classe NP.

Prima di addentrarci in queste questioni strutturali, però, cerchiamo di capire: perché la classe NP è così importante?
Tanto importante che qualcuno ha pensato di mettere una taglia da un milione di dollari sulla congettura $P\not= NP$?
La classe P, è chiaro: è importante perché, se collochiamo un problema in P, quel problema sappiamo risolverlo per davvero. Ma la classe NP?
Cosa ce ne importa di sapere che un certo problema(per il quale, magari, non riusciamo a progettare un algoritmo polinomiale) è deciso da una macchina *non deterministica* in tempo polinomiale?
## L'importanza di NP
Se l’importanza di NP non va individuata nel modello di calcolo sul quale è basata, allora non può che risiedere nei problemi che la popolano!
In effetti nella classe NP si trovano tanti problemi:
1. acquistare i biglietti aerei per un giro di tutte le capitali dell’UE, spendendo in totale al massimo 10000 euro ;
2. suddividere un insieme di oggetti (ciascuno di peso diverso) sui due piatti di una bilancia in modo tale che alla fine la bilancia sia in equilibrio ; 
3. piastrellare un pavimento con mattonelle di forme e dimensioni diverse in modo tale che non rimangano spazi scoperti ;
4. scegliere al più 10 rappresentanti degli studenti ai quali comunicare una direttiva in modo tale che ogni altro studente conosca almeno uno di quelli che sono stati scelti così da poter essere informato ;
5. e tanti altri ... 
che hanno grande rilevanza pratica, e che non si riesce a risolvere mediante algoritmi (deterministici) polinomiali, ma che non si riesce nemmeno a dimostrare che non possono essere risolti in tempo deterministico polinomiale.
## La struttura dei problemi in NP
Dunque, in NP si trovano un sacco di problemi (decisionali) importanti.
E un problema è in NP quando esiste una macchina non deterministica che *accetta* le sue istanze sì in tempo polinomiale, anche se poi sappiamo che se esiste una macchina che accetta le istanze sì in tempo polinomiale, allora esiste anche una macchina che decide le sue istanze in tempo polinomiale.
Ma allora perché continuiamo a dire che in NP si trovano i linguaggi **accettati** in tempo non deterministico polinomiale ? Perché continuiamo a non usare la parola “*decisi*”?
Per comprenderlo, dobbiamo tornare ad una vecchia conoscenza: il Genio burlone e pasticcione che costituisce uno dei modelli di una computazione non deterministica. 
Quando, durante una computazione non deterministica $NT(x)$, la macchina si trova in un certo stato $q$ e legge un certo simbolo $s$, e nell’insieme delle quintuple di $NT$ esistono tante quintuple che iniziano con la coppia $(q,s)$, quale quintupla esegue $NT$?
Corre dal Genio, e lo chiede a lui.
## Multi-quintuple e Genio
Cioè, non avendo criteri per scegliere quale quintupla eseguire, ricorre al Genio sperando che riesca a scegliere la *quintupla giusta* da eseguire, ossia, la quintupla che, *nell’ipotesi che x sia una istanza sì del problema*, porti NT ad accettare. 
L’intervento del genio possiamo modellarlo inventando una istruzione apposita in **PascalMinimo**:
1. l’istruzione *scegli*
2. Vediamola in azione, scrivendo il codice corrispondente ad una Macchina di Turing non deterministica NT ad un nastro
## Multi-quintuple, genio e l'istruzione *scegli*
**Input**: parola $x_1x_2 ... x_n$ memorizzata nell’array N, con $N[i] = x_i$ per $i = 1,...,n$. 
**Costanti**: l’insieme delle quintuple $P=\{\langle q_{11},s_{11},s_{12},q_{12},m_1\rangle,...,\langle q_{k1},s_{k1},s_{k2},q_{k2},m_k\rangle\}$ che descrivono NT.
$q\leftarrow q_0; t\leftarrow 1;	primaCella\leftarrow t;ultimaCella\leftarrow n;$
![[Pasted image 20230516113305.png|center]]

La simulazione di una macchina non deterministica mediante un algoritmo in PascalMinimo già l’avevamo vista.
1. fino a quando la macchina NT non entra nello stato $q_A$ o nello stato $q_R$ (e lo stato in cui si trova NT è memorizzato nella variabile $q$)
2. calcola l’insieme $\Psi$ delle quintuple che può eseguire trovandosi nello stato q e leggendo$ $N[t]$, (dove t indica la posizione della testina sul nastro di NT)
3. se $\Psi$ contiene almeno una quintupla, ne sceglie una da eseguire, e la esegue (gestendo le porzioni iniziali e finali del nastro mediante primaCella e ultimaCella)
In questo caso, invece di simulare tutte le computazioni deterministiche di $NT(x)$, l’algoritmo si affida al Genio per scegliere, di volta in volta, le quintuple da eseguire. 
Soltanto una *osservazione*: se, ad un certo istante $\Psi$ non contiene quintuple e $q$ non è $q_A$ e non è $q_R$, l’algoritmo entra in loop! Ma questo accade solo se P non è totale (ricordate?)
### Ma il genio può sbagliare
Cerchiamo, ora, di capire quali conseguenze comporta ricorrere al Genio.
Eseguiamo l’algoritmo precedente con input x - chiamiamo $\mathcal A$ l’algoritmo e $\mathcal A(x)$ la sua esecuzione sull’input x.
$\mathcal A(x)$ termina in $q_A$ o in $q_R$ (assumendo che P sia totale: e noi lo assumiamo!
Se $\mathcal A(x)$ termina in $q_A$  allora possiamo essere certi che il Genio ci ha indicato le risposte corrette
1. perché il Genio ha trovato una sequenza di quintuple da eseguire che termina nello stato $q_A$;
2. e quella sequenza costituisce una computazione accettante di $NT(x)$;
3. e, dunque, ***esiste** una computazione accettante* di $NT(x)$.
Se $\mathcal A(x)$ termina in $q_A$, allora, possiamo essere certi che possiamo accettare.

Ma se $\mathcal A(x)$ termina in in $q_R$ allora sopraggiunge qualche dubbio.
1. perché il Genio ha trovato una sequenza di quintuple da eseguire che termina nello stato $q_R$;
2. e quella sequenza costituisce una computazione di $NT(x)$ che rigetta;
3. e, dunque, ***esiste** una computazione di $NT(x)$ che rigetta*;
4. *ma questo non dimostra che **tutte** le computazioni di NT(x) rigettano*.
Ecco, allora: non fidandoci noi del Genio, possiamo solo concludere che il Genio non ha trovato la sequenza di quintuple che porta NT nello stato di accettazione.
Ma **non possiamo sapere se non l’ha trovata**, perché  una sequenza di quintuple che induce NT ad accettare non esiste, o perché il Genio non è stato sufficientemente abile da trovarla.
Ecco perché continuiamo a parlare di linguaggi **accettati**, piuttosto che decisi.
## La struttura dei problemi in NP
In effetti, questa questione del Genio “a mezzo servizio” ( il cui utilizzo è fondamentale quando lavora su una istanza sì di un problema, ma che non è di alcuna utilità quando lavora su istanze no del problema) gioca un ruolo fondamentale per comprendere la struttura dei problemi che popolano NP.
E, per comprendere questa struttura, facciamo un po’ di esempi:
1. esempi di problemi;
2. ed esempi di *algoritmi non deterministici* che li risolvono. 
E, siccome ci accingiamo a progettare algoritmi che decidono problemi anziché linguaggi, i nostri algoritmi li descriveremo “ad alto livello”, tilizzando il PascalMinimo (o sue variazioni a più alto livello) corredato dell’istruzione scegli e mettendo da parte, per il momento, le macchine di Turing.
Ma prima di farlo dobbiamo ancora chiarire una questione.
## Multi-quintuple, Genio e l'istruzione *scegli*
In effetti, è comodo poter disporre di un Genio. Rimane, però, una questione fondamentale: ma quanto è potente questo Genio?
Cioè, se dispongo di un Genio, perché non gli chiedo direttamente “l’istanza x è un’istanza sì del mio problema?” ?
Innanzi tutto, perché delle risposte del Genio non mi fido:
- se gli chiedo di indicarmi quale quintupla eseguire ad  un certo punto della computazione, poi posso verificare che mi ha indicato una quintupla che posso eseguire davvero 
- se gli chiedo di dirmi se x è una istanza sì, poi come la verifico la risposta?
Poi, soprattutto, abbiamo introdotto il genio per modellare il _**non determinismo**_
- per questo gli chiediamo di scegliere quale quintupla eseguire a ciascun passo della computazione
- e il numero di quintuple fra le quali scegliere è il grado di non determinismo della macchina, che è **COSTANTE**
Perciò, va bene trasportare il Genio nel mondo degli algoritmi ad alto livello, a patto, però, di proporgli sempre di operare le sue scelta fra un numero costante di opzioni

## Alcuni esempi

### Il problema 3SAT
Torniamo ad un Esempio che abbiamo già incontrato:
dati un insieme X di variabili booleane ed un predicato f, definito sulle variabili in X e contenente i soli operatori $\land,\lor,\neg$ , decidere se esiste una assegnazione a di valori in {vero, falso} alle variabili in X tale che $f(a(X))$=vero
Consideriamo soltanto predicati f in forma 3-congiuntiva normale (3CNF), ossia,
- f è la congiunzione di un certo numero di clausole: $f = c_1\land c_2\land \dots \land c_m$
- e ciascuna $c_j$ è la disgiunzione ($\lor$) di tre letterali (3CNF), ad esempio $x_1\lor  \neg x_2\lor x_3$
Questo problema prende il nome di 3SAT, ed è così formalizzato:
- $\mathcal I_{3SAT}= \{ \langle X, f \rangle : \text{X è un insieme di variabili booleane}\land \text{ f e un predicato su X in 3CNF}\}$
- $S_{3SAT}(X, f) = \{ a: X\to  \{vero, falso\} \} \text{(S è l’insieme delle assegnazioni di verità alle variabili in X)}$
- $\pi_{3SAT}(X, f, S_{3SAT}(X,f) )=\exists  a\in S_{3SAT}(X,f) : f(a(X)) = vero$
Descriviamo, ora, un possibile algoritmo non deterministico che accetta 3SAT    
![[Pasted image 20230529141519.png|center]]

L’algoritmo che abbiamo appena visto è logicamente suddiviso in due parti: 
la prima parte ha carattere prettamente non deterministico
- serve a scegliere una assegnazione di verità a per le variabili in f 
la seconda parte ha carattere prettamente deterministico
- serve a verificare deterministicamente che l’assegnazione scelta <u>soddisfi</u> effettivamente f 

Poiché il numero di possibilità fra le quali scegliere ad ogni passo è pari a 2, si tratta, effettivamente, di un algoritmo non deterministico

Poiché l’algoritmo accetta se **esiste** una sequenza di scelte che soddisfa f, allora è un algoritmo che accetta 3SAT

Per quanto riguarda la sua complessità, osserviamo che
- il primo ciclo while (nella parte non deterministica) richiede tempo non deterministico lineare in $n = |X|$. 
- il secondo ciclo while (nella parte deterministica) richiede tempo deterministico in 	 	$O( |X|\cdot| f |) = O( 3 n m) = O(n m).$

In conclusione, l’algoritmo accetta $\langle X,f \rangle\in\mathcal I_{3SAT}$ in tempo $O(|X|\cdot |f|)$, e questo prova che $3SAT\in  NP$. 

### Il problema CLIQUE

Siamo all’Esempio 9.2:
Il problema CLIQUE consiste nel decidere, dati un grafo non orientato $G=(V,E)$ ed un intero $k\in\mathbb N$ , se G contiene un sottografo completo di almeno k nodi. 
- un grafo si dice completo se in esso esiste un arco per ogni coppia di nodi

Formalmente, il problema è descritto dalla tripla 
- $\mathcal I_{CLIQUE}= \{ \langle G = (V,E), k \rangle : \text{G è un grafo non orientato}\land  k\in\mathbb N  \}$
- $S_{CLIQUE}(G = (V,E), k ) = \{ V'\subseteq  V \} 		\text{(S è l’insieme dei sottoinsiemi di V)}$
- $\pi_{CLIQUE}(G, k, S_{CLIQUE}(G, k) )= \exists V'\in S_{CLIQUE}(G, k) : (\forall  u, v\in  V' [ (u,v)\in  E ] )\land  |V'|\geq  k$
	- ossia, comunque si scelgano due nodi in V’, essi sono collegati da un arco

Descriviamo, ora, un possibile algoritmo non deterministico che accetta CLIQUE
![[Pasted image 20230529141634.png|center]]

L’algoritmo che abbiamo appena visto è logicamente suddiviso in due parti: 
la prima parte ha carattere prettamente non deterministico
 - serve a scegliere un sottoinsieme V’ di V  
la seconda parte ha carattere prettamente deterministico
- serve a verificare deterministicamente che il sottoinsieme scelto soddisfi <u>effettivamente</u> $\pi_{CLIQUE}(G, k, S_{CLIQUE}(G, k) )$ 

Esattamente come per l’algoritmo che accetta 3SAT!

Poiché il numero di possibilità fra le quali scegliere ad ogni passo è pari a 2, si tratta, effettivamente, di un algoritmo non deterministico

Poiché l’algoritmo accetta se esiste una sequenza di scelte che soddisfa il predicato di CLIQUE $\pi_{CLIQUE}(G, k, S_{CLIQUE}(G, k) )$, allora è un algoritmo che accetta CLIQUE

Per quanto riguarda la sua complessità, osserviamo che
- il primo ciclo while (nella parte non deterministica) richiede tempo non deterministico lineare in $n = |V |$
- il secondo ciclo while (nella parte deterministica) richiede tempo deterministico in 	 	$O( |V|^2\cdot (|V| +|E|)).$ 
In conclusione, l’algoritmo accetta $\langle G,k \rangle\in\mathcal I_{CLIQUE}$  in tempo $O(|V|^2 |E|)$, e questo prova che $CLIQUE\in  NP.$ 

### Attenzione

Siamo all’Esempio 9.3, che descrive il problema LONG PATH: dati un grafo non orientato $G=(V,E)$, due suoi nodi a e b, ed un intero $k\in\mathbb N$, vogliamo decidere se G contiene un percorso fra a e b di esattamente k archi. 

Poiché un percorso è una sequenza ordinata di nodi, possiamo pensare di rappresentare un percorso fra a e b lungo k con un array p di k-1 elementi tali che 

$$(a, p[1])\in  E, (p[1], p[2])\in  E, \dots , (p[i], p[1+1])\in  E, \dots , (p[k-2], p[k-1])\in  E, (p[k-1], b)\in  E$$

Potremmo pensare ad un algoritmo non deterministico che decide se $\langle G , a, b, k \rangle$ è una istanza sì del problema che segue lo schema degli algoritmi che abbiamo già visto: 
- Fase 1 (non deterministica): sceglie i nodi $p[1], p[2], \dots , p[k-1]$
- Fase 2: verifica se $\langle a, p[1], p[2], \dots , p[k-1], b \rangle$ è effettivamente un percorso in G

Potremmo implementare la Fase 1 mediante il seguente ciclo
![[Pasted image 20230529141804.png|center]]

Siamo proprio sicuri?.
Il numero di possibilità fra le quali scegliere ad ogni passo è pari a |V|, che non è costante!
V è parte dell’input
- <u>Non si tratta, perciò, di un algoritmo non deterministico!</u>
In effetti, la fase non deterministica che accetta LONG PATH è sensibilmente più complessa

In conclusione, quando progettate un algoritmo non deterministico, fate attenzione al fatto che il numero delle opzioni fra le quali scegliere sia _**costante**_! 

## Ma...

I tre problemi in NP che abbiamo visto, ovvero 3SAT, CLIQUE, LONG PATH hanno qualcosa in comune: la struttura del predicato $\pi$
- in tutti e tre i problemi $\pi$ ha la forma seguente: esiste un elemento di S (ossia, una soluzione possibile) che soddisfa certe proprietà – che chiamiamo $\pi$
- $\pi(x, S(x)) = \exists y\in  S(x) : \eta(x,y)$

Non solo, ma anche gli algoritmi per la loro decisione che abbiamo analizzato seguivano tutti lo stesso schema: con input x,
- Fase 1 (non deterministica): sceglie una soluzione possibile $y\in  S(x)$
- Fase 2 (deterministica): verifica se y soddisfa il predicato $\eta(x, y)$

E non basta: 
- la Fase 1, ossia, sceglie una soluzione possibile y, richiede tempo polinomiale in |x|
- la Fase 2, ossia, la verifica che x e y soddisfino il predicato , richiede tempo polinomiale in |x|

E quindi possiamo dire che ogni problema
- il cui predicato ha la forma $\pi(x, S(x)) = \exists y\in  S(x) : \eta(x,y)$
- in cui la scelta di un elemento y di S(x) richiede tempo polinomiale in |x|
- in cui la verifica che y soddisfi il predicato $\eta$, richiede tempo polinomiale in |x|
appartiene ad NP.