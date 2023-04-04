# Introduzione alla Teoria della Complessità Computazionale
## Usare "a scatola nera"
Torniamo alla dimostrazione dell’indecidibilità dell’Halting Problem, o, equivalentemente, alla non accettabilità del suo complemento.
Siamo partiti supponendo di avere una macchina T in grado di decidere $L_H$, e poi, senza sapere come era fatta T (senza “aprirla”), abbiamo costruito una serie di altre macchine $– T, T’, T’’, T* -$ che ci hanno portato dove volevamo.
La macchina T’ la abbiamo costruita senza sapere come era fatta T, e come avremmo potuto saperlo? T non esiste.
Che, poi, è quello che facciamo sempre quando utilizziamo, ad esempio una classe delle API di Java (per dire, chi di voi, prima di utilizzare il metodo show di JFrame si andrebbe a vedere come è implementato?)
Questo utilizzo “a scatola nera” di T corrisponde esattamente al concetto di “invocazione di funzione”.
Ora, quando T’ usava T, T passava (come “parametro”) a T’ il suo stesso input (i,x). In generale, possiamo utilizzare una macchina $T_0$ all’interno di un’altra macchina $T_1$ in un modo un po’ più complesso; in effetti, il linguaggio deciso/accettato da $T_0$  potrebbe anche essere molto diverso da quello deciso/accettato da $T_1$. Allora, potrebbe essere necessario “modificare” l’input di $T_1$ prima di “darlo in pasto” a $T_0$.
>[!danger]-Esempio (banale) 
>voglio costruire una macchina che decida il linguaggio $L_{P12}$ che contiene tutte (e sole) le parole palindrome di lunghezza pari costituite dai caratteri ‘1’ e ‘2’.

Assomiglia a $L_{PPAL}$ questo linguaggio $L_{P12}$.Si potrebbe provare a riutilizzare $T_{PPAL}$  – che decide $L_{PPAL}$. Peccato che $T_{PPAL}$ lavori sull’alfabeto $\{a,b\}$ invece che sull’alfabeto $\{1,2\}$. Si potrebbe provare a trasformare le parole di $L_{P12}$ in parole di $L_{PPAL}$.
Voglio costruire una macchina che decida il linguaggio $L_{P12}$ che contiene tutte (e sole) le parole palindrome di lunghezza pari costituite dai caratteri ‘1’ e ‘2’.
Facile: prendo il mio $x\in \{1,2\}^*$ e procedo così:  assumendo $x = x_1 x_2 … x_n$, per ogni $h =1, 2, ... , n$:
1. se $x_h = 1$ allora poniamo $y_h = a$;
2. se $x_h = 2$ allora poniamo $y_h = b$.
infine, poniamo $y = y_1 y_2 … y_n$ .
Quello che ho ottenuto è quindi una parola $y\in  \{a,b\}^*$ che ha le seguenti **caratteristiche**:
1. se $x\in L_{P12}$ allora $y\in  L_{PPAL}$;
2. se $x\in L_{P12}$ allora $y\in  L_{PPAL}$.
## Riduzioni (many-to-one)
Quello che abbiamo fatto, in realtà, è qualcosa di più di una semplice trasformazione di una parola in un’altra parola.
Abbiamo progettato una funzione $f : \{1,2\}^*\rightarrow  \{a,b\}^*$ tale che
1) f è **totale e calcolabile** – ossia: 
	è definita per ogni parola $x\in {1,2}^*$ e, inoltre, esiste una macchina di Turing di tipo trasduttore $T_f$ tale che, per ogni parola $x\in {1,2}^*$, la computazione $T_f (x)$ termina con la parola $f(x)\in  \{a,b\}^*$ scritta sul nastro di output.
2) per ogni $x\in  \{1,2\}^*$ vale che: $x\in  L_{P12}$  se e solo se $f(x)\in L_{PPAL}$,
ovvero: $\forall x\in\{1,2\}^*[x\in L_{P12}\iff f(x)\in L_{PPAL} ]$.
La funzione $f$ si chiama **riduzione** da $L_{P12}$  a $L_{PPAL}$, e si dice che $L_{P12}$  è **riducibile** a $L_{PPAL}$  e si scrive $L_{P12} \preceq L_{PPAL}$.
Quello che abbiamo detto sino ad ora può essere generalizzato:
Dati due linguaggi, $L_1\subseteq\Sigma_ 1^*$  e $L_2\subseteq\Sigma_2^*$,  diciamo che $L_1$  è riducibile a $L_2$  e scriviamo $L_1 \preceq L_2$  se esiste una funzione $f :\Sigma_1^*\rightarrow\Sigma_2^*$ tale che:
1) $f$ è **totale e calcolabile** – ossia, 
è definita per ogni parola $x \in\Sigma_1^*$ e, inoltre, esiste una macchina di Turing di tipo trasduttore $T_f$ tale che, per ogni parola $x \in\Sigma_1^*$, la computazione $T_f (x)$ termina con la parola $f(x)  \in\Sigma_2^*$ scritta sul nastro di output;
2) per ogni $x\in\Sigma_1^*$ vale che: $x\in  L_1$  se e solo se $f(x)\in  L_2$
- $$\forall x\in\Sigma_1^*[x\in L_1\iff f(x)\in L_2 ]$$
## Decidibilità, accettabilità e riduzioni
Il concetto di riduzione si rivela molto utile come strumento per dimostrare  che un linguaggio è decidibile/accettabile: dato un linguaggio $L_3$:
1. se dimostro che $L_3\preceq  L_4$ , per un qualche altro linguaggio $L_4$ ; 
2. se io so che $L_4$ è decidibile, allora, posso concludere che anche $L_3$ è decidibile. 
Infatti, sia $L_3\subseteq\Sigma_3^*$  e $L_4\subseteq\Sigma_4^*$ :
1. $L_4$ **è decidibile** : allora esiste una macchina $T_4$ tale che, per ogni $x\in\Sigma_4^*$, $T_4 (x)$ termina in $q_A$ se $x\in L_4$, $T_4 (x)$ termina in $q_R$ se $x\not\in L_4$;
2. $L_3\preceq L_4$ : allora esiste una un trasduttore $T_f$ tale che, per ogni $x\in\Sigma_3^*$, $T_f (x)$ termina con una parola $y\in\Sigma_4^*$ scritta sul nastro di output tale che $y \in L4$  se $x\in L_3$, e $y\not\in L_4$ se $x\not\in L_3$.
Ora, costruiamo una macchina $T_3$ , a 2 nastri, che, con input $x\in\Sigma_3^*$ :
1. prima simula $T_f (x)$ scrivendo l’output y sul secondo nastro;
2. poi simula $T_4 (y)$: se $T_4 (y)$ accetta allora anche $T_3$ accetta, se $T_4 (y)$ rigetta allora anche $T_3$ rigetta 
E a cosa serve? 
1. se $x\in L_3$ allora $y\in L_4$  e, quindi, $T_4 (y)$ accetta; quindi, $T_3$ accetta le parole in $L_3$; 
2. se , $x\not\in L_3$  allora $y\not\in L_4$  e, quindi, $T_4 (y)$ rigetta; quindi $T_3$ rigetta le parole che non sono in $L_3$. 
In conclusione, $T_3$ decide $L_3$. Ossia, $L_3$  **è decidibile**.
Con una dimostrazione simile (che vi fate per esercizio) si dimostra che dato un linguaggio $L_3$, se dimostro che $L_3\preceq L_4$ , per un qualche altro linguaggio $L_4$ , *se io so che $L_4$ è accettabile allora, posso concludere che anche $L_3$ è accettabile*.
### Riduzioni (many-to-one): esempio

https://uniroma2.sharepoint.com/:p:/r/sites/DI_IANNI-8066834-FONDAMENTI_DI_INFORMATICA_1/Materiale%20del%20corso/Lezione09-riduzioni-IntroComplessita%CC%80.pptx?d=wce90e2d940284c36a2f47eb03310b906&csf=1&web=1&e=kCCw3K

# Complessità
## La Torre di Hanoi
Consideriamo una torre di 3 soli dischi impilata, diciamo, sull’asta a sinistra: l’obiettivo è spostarla sull’asta a destra. L’asta centrale avrà la funzione di “asta d’appoggio”. 
![[Pasted image 20230404145148.png|center]]
Portiamo a termine il compito eseguendo le seguenti mosse : 
1) poiché possiamo spostare un solo disco alla volta, spostiamo il disco più  piccolo sull’asta a destra; 
2) ora possiamo spostare il disco di grandezza intermedia e, poiché non possiamo appoggiarlo sul disco più piccolo, lo impiliamo nell’asta al centro;
3) a questo punto, spostiamo il disco più piccolo sull’asta al centro, appoggiandolo sul disco di grandezza intermedia;
4) spostiamo il disco più grande sull’asta a destra; 
5) spostiamo il disco più piccolo dall’asta centrale sull’asta a sinistra ; 
6) spostiamo il disco di grandezza intermedia sull’asta a destra, appoggiandolo sul disco più grande
7) Infine, spostiamo il disco più piccolo sull’asta a destra, appoggiandolo sul disco di grandezza intermedia: fatto! 
Dunque, abbiamo spostato una torre di 3 dischi utilizzando 7 spostamenti di dischi singoli, e non è possibile realizzare il nostro compito utilizzando un numero inferiore di spostamenti di dischi singoli. 
Per spostare una torre di 4 dischi è necessario:
spostare la sotto-torre costituita dai 3 dischi più piccoli dall’asta di sinistra a quella centrale, poi spostare il disco più grande sull’asta di destra ,
e, infine, spostare la sotto-torre costituita dai 3 dischi più piccoli dall’asta centrale a quella di destra. E *non* possiamo far di meglio.
Questo procedimento è generalizzabile. Per spostare una torre di n dischi è necessario:
1. spostare la sotto-torre costituita dagli n-1 dischi più piccoli dall’asta di sinistra a quella centrale (configurazione 4) nella figura); 
2. poi spostare il disco più grande sull’asta di destra (configurazione 5) nella figura);
3. infine, spostare la sotto-torre costituita dagli n-1 dischi più piccoli dall’asta centrale a quella di destra (configurazione 7) nella figura).
E non possiamo far di meglio.
Quindi, se indichiamo con $M(n)$ il numero di spostamenti di dischi singoli necessario a spostare una torre di n dischi, vale la seguente relazione di ricorrenza: $$M(n) = 2 M(n-1) +1$$
Che ha come soluzione $M(n) = 2^n-1$
E non possiamo far di meglio.
Quindi, se indichiamo con $M(n)$ il numero di spostamenti di dischi singoli necessario a spostare una torre di n dischi, abbiamo che	$M(n) = 2^n-1$
E non possiamo far di meglio. Ma che significa?
Che per spostare la Torre di Hanoi occorrono (sono necessari) $2^{64} - 1 = 18.446.744.073.709.551.615$ spostamenti di dischi e che, anche se i monaci riuscissero a spostare un disco in 1 secondo, occorrerebbero  almeno 18.446.744.073.709.551.615  secondi per spostare la torre, che corrispondono a circa 5.845.580.504 secoli. Un tempo così lungo che quando il sole diverrà una gigante rossa e brucerà la Terra, il gioco non sarà ancora stato completato. 
lo sappiamo risolvere o no il problema della torre di Hanoi? Certo, che lo sappiamo risolvere!
Vi ho mostrato il procedimento che sposta una torre di n dischi da un’asta all’altra. Tuttavia, anche se sappiamo come fare a spostare una torre grande quanto ci pare, se la torre è abbastanza grande l’intera nostra vita non sarà sufficiente a vedere la torre spostata.
Se il tempo necessario a calcolare la soluzione di  (un’istanza di) un problema è troppo elevato, saper calcolare quella soluzione è equivalente a non saperla calcolare.
## La teoria della complessità computazionale
Studia la “quantità di risorse” **necessarie** a risolvere un problema, o meglio: a decidere un linguaggio, e suddivide i problemi in *“trattabili”* e *“intrattabili”* dipendentemente dal fatto che la “quantità di risorse” necessarie cresca come un polinomio o più di un polinomio.
Ma perché la crescita polinomiale è discriminante fra trattabilità e intrattabilità?
Beh, lo avete visto quanto è grande $2^{64}$: un numero di 20 (venti!) cifre. Invece, $64^2$ è il minuscolo 4096. Piccolo.
Chiara l’idea?
Una funzione più che polinomiale cresce infinitamente più velocemente di una funzione polinomiale, e, se quella funzione rappresenta la “quantità di risorse” necessaria a risolvere un problema..
Sì, ma qui stiamo parlando di funzioni che rappresentano la “quantità di risorse” necessaria a risolvere un problema. Ma qual è l’argomento di queste funzioni?
Cioè: in funzione di cosa esprimiamo la complessità di un problema?
E, poi, quali sono le “risorse” che prendiamo in considerazione?
