# La macchina di Turing Universale
## Cos'è una macchina di Turing?
Una macchina di Turing è la descrizione di un procedimento per risolvere un problema descritto nel linguaggio delle quintuple (ossia, è un procedimento per il modello di calcolo Macchina di Turing).
Quindi, una macchina di Turing è un *algoritmo* (e, se la facciamo lavorare su qualche input, quella, in qualche modo, ci calcola la soluzione per l’istanza del problema che gli abbiamo dato in input) e il dato in input, per una macchina di Turing, è una parola, costituita da caratteri di un certo alfabeto (l’input è una **parola** – che viene scritta sul nastro della macchina).
Una macchina di Turing, però, è anche qualcos’altro.ù
## Macchine e parole
Prendiamo una macchina di Turing: cioè, un alfabeto $\Sigma$ e un insieme degli stati Q, e, soprattutto, *l’insieme delle sue quintuple* P. Si osserva che è sufficiente avere l’insieme P per sapere tutto di T: da T possiamo ricavare sia $\Sigma$ che Q.
In effetti P non dice proprio tutto tutto: per sapere tutto di T, oltre che P, dobbiamo conoscere anche quale sia lo stato iniziale e quali siano gli stati finali.
Ebbene, data una macchina T, se decidiamo di costruire una parola secondo le regole seguenti:
1. Il primo carattere della parola è ‘$q_0$’, che è seguito da un carattere non in $\Sigma$, diciamo ‘-’;
2. Che è seguito da ‘$q_A$’, poi da ‘-’, poi da ‘$q_R$’;
3. Poi, seguono, una di seguito all’altra, tutte le quintuple.
La parola che abbiamo appena costruito definisce completamente T. 
>[!danger]- Esempio:
>

Prendiamo una macchina $T_{PAL}$ che termina in $q_A$ se la parola scritta (composta da caratteri ‘a’ e ‘b’) sul suo nastro ha lunghezza pari ed è palindroma.
Il suo stato iniziale è $q_0$, il suo stato di accettazione è $q_A$, il suo stato di rigetto è $q_R$, e le sue quintuple sono:
- -$〈 q_0 , a, \square , q_a , D〉, 〈 q_0 , b, \square, q_b , D〉$,
- -$〈 q_a , a, a, q_a , D〉,〈 q_a , b, b, q_a , D〉,〈 q_b , a, a, q_b , D〉,〈 q_b , b, b, q_b , D〉$,
- -$〈 q_a , \square, \square, q_{a1} , S〉, 〈 q_b , \square, \square, q_{b1} , S〉$,
- -$〈 q_{a1} , a, \square, q_2 , S〉,〈 q_{a1} , b, b, q_R , F〉,〈 q_{b1} , a, a, q_R , F〉,〈 q_{b1} , b, \square, q_2 , S〉$,
- -$〈 q_2 , a, a, q_2 , S〉, 〈 q_2 , b, b, q_2 , S〉, 〈 q_2 , \square, \square, q_0 , D〉$,
- -$〈 q_0 , \square, \square, q_A , F〉$.
Ebbene, è $T_{PAL}$ completamente descritta dalla parola seguente:
$\begin{align} \\ q_0 – q_A – q_R〈 q_0 , a, \square, q_a , D〉〈 q_0 , b, \square, q_b , D〉〈 q_a , a, a, q_a , D〉〈 q_a , b, b, q_a , D〉\\〈 q_b , a, a, q_b , D〉〈 q_b , b, b, q_b , D〉〈 q_a , \square, \square, q_{a1} , S〉 〈 q_b , \square, \square, q_{b1} , S〉\\〈 q_{a1} , a, \square, q_2 , S〉〈 q_{a1} , b, b, q_R , F〉〈 q_{b1} , a, a, q_R , F〉〈 q_{b1} , b, \square, q_2 , S〉\\〈 q_2 , a, a, q_2 , S〉〈 q_2 , b, b, q_2 , S〉〈 q2 , \square, \square, q_0 , D〉〈 q_0 , \square, \square, q_A , F〉\end{align}$
### Aperta parentesi
L’insieme delle quintuple di $T_{PAL}$ non è una funzione totale. Infatti, non considera in alcun modo il caso in cui la parola in input ha lunghezza dispari. In questo caso, infatti, $T_{PAL}(x)$ termina:
1. Nello stato $q_{a1}$ se x è una parola palindroma di lunghezza dispari ed ha ‘a’ al centro – per esempio, *abbabba*;
2. Nello stato $q_{b1}$ se x è una parola palindroma di lunghezza dispari ed ha ‘b’ al centro – per esempio, *abbbbba*.
Naturalmente, possiamo completare P aggiungendo le quintuple
$$〈 q_{a1} , \square, \square, q_R , F〉,〈 q_{b1} , \square, \square, q_R , F〉$$
Si osserva che, poiché vogliamo che $T_{PAL}$ termini in $q_A$ solo se la parola scritta sul suo nastro, oltre ad essere palindroma, ha lunghezza pari, allora $T_{PAL}$ rigetta le parole palindrome di lunghezza dispari.
## Tornando a Macchine e parole
In definitiva, una macchina di Turing è una parola, costituita di caratteri dell’alfabeto $Q\cup\Sigma\cup\{-\}\cup\{〈 \}\cup\{ 〉\}\cup\{\square\}$.
Ma, se è una parola, allora possiamo ben pensare di scriverla sul nastro di un’altra macchina di Turing (chiamiamola A), così che A lavori sulla macchina di Turing come input.
Si può fare, ma perché conviene?
Ad esempio, se sul nastro di A ci scriviamo, oltre alla parola che descrive la nostra macchina di Turing di partenza (chiamiamola T), anche un input x di T, allora A potrebbe simulare la computazione T(x)
Dunque, se chiamiamo $p_T$ la parola che descrive T, l’esito della computazione  $A(p_T, x)$ sarebbe uguale all’esito della computazione T(x). 
## Oltre la macchina
Pensate se, per caso, riuscissimo a progettare una macchina di Turing U che prende in input due parole:
1. Una parola $p_T$ che descrive una **qualsiasi** macchina di Turing T;
2. Una parola x, input di T.
E che riesce a simulare la computazione T(x), ***qualunque sia T***.
Ossia, U sarebbe una macchina di Turing alla quale posso comunicare un algoritmo (*qualsiasi*) e un input per quell’algoritmo, e U esegue l’algoritmo su quell’input.
*U sarebbe l’algoritmo che descrive il comportamento di un calcolatore*.
Turing ha progettato U, quella che ha preso il nome di ***macchina di Turing Universale***.
## La macchina Universale U
Intanto, progettiamo U in modo tale che sappia simulare soltanto macchine ad un nastro. Invece, dotiamo U di 4 nastri e testine indipendenti:

1. Sul primo nastro viene inizialmente scritta la parola $p_T$ che descrive la macchina T la cui computazione deve essere simulata – e il contenuto di questo nastro non sarà mai modificato durante la computazione $U(T, x)$;
2. Sul secondo nastro viene scritto l’input x della macchina T, e questo sarà il nastro sul quale avverrà la simulazione vera e propria della computazione T(x);
3. Sul terzo nastro, all’inizio della computazione, U copia lo stato iniziale di T, che, ricordiamo, è il primo simbolo di $p_T$;
4. Sul quarto nastro, all’inizio della computazione, U copia lo stato di accettazione di T, che, ricordiamo, è il simbolo di $p_T$  a destra del primo ‘-’.
Visivamente:
- -U prima che la computazione $U(p_{T_{PAL}}, ababbbabaa)$ abbia inizio:
![[Pasted image 20230321114101.png|center]]

- -La computazione $U( p_{T_{PAL}} , ababbbabaa)$ procede: U ha copiato lo stato iniziale di $T_{PAL}$ su $N_3$, lo stato di accettazione $T_{PAL}$ su $N_4$, e si prepara a simulare $T_{PAL}(x)$:
- ![[Pasted image 20230321114313.png|center]]
A questo punto, U ha copiato lo stato iniziale di T sul terzo nastro e lo stato di accettazione di T su quarto nastro. Per tutta la durata della simulazione che U sta per iniziare:
1. Il contenuto di $N_4$ non verrà mai modificato;
2. $N_3$ conterrà sempre lo stato in cui si troverebbe T a quel punto della simulazione.
U inizia la simulazione di T(x) vera e propria: che è una ripetizione dei passi seguenti:
1) U cerca la quintupla di T da eseguire;
2) se ha trovato la quintupla da eseguire, allora la esegue e torna al punto 1);
3) se non ha trovato la quintupla da eseguire, allora confronta il carattere letto sul terzo nastro (lo stato in cui si troverebbe T a questo punto della computazione) con il carattere letto sul quarto nastro (lo stato di accettazione di T):
	- - Se sono uguali, allora accetta;
	- -Se sono diversi, rigetta.
Vediamo i punti 1) e 2) in dettaglio.
1) U cerca la quintupla di T da eseguire: la testina su $N_1$ è posizionata sul primo carattere ’〈’ ; U esegue i passi seguenti:
	*1.1)* Muove a destra di una posizione la testina su $N_1$;
	*1.2)* Se legge lo stesso carattere su $N_1$ e su $N_3$, allora U sta scandendo una quintupla di T che inizia con lo stato in cui si troverebbe T a questo punto della computazione; in questo caso muove a destra la testina su $N_1$ per posizionarla sul carattere a destra di ‘,’ ;
		*1.2.1)* Se legge lo stesso carattere su $N_2$ e $N_1$, allora ha trovato la quintupla da eseguire e passa al punto 2) ;
		*1.2.2)* Se non legge lo stesso carattere su $N_2$ e $N_1$, allora non ha trovato la quintupla da eseguire: in questo caso, muove a destra la testina su $N_1$ alla ricerca del prossimo carattere ’〈’ : se lo trova allora torna al punto 1.1), se non lo trova allora ha scandito tutte le quintuple di T senza trovare quella da eseguire e passa al punto 3).
	*1.3)* Se non legge lo stesso carattere su $N_1$ e su $N_3$, allora sta scandendo una quintupla di T che non inizia con lo stato in cui si troverebbe T a questo punto della computazione; in questo caso muove a destra la testina su $N_1$ alla ricerca del prossimo carattere ’〈’ : se lo trova allora torna al punto 1.1), se non lo trova allora ha scandito tutte le quintuple di T senza trovare quella da eseguire e passa al punto 3).
2) Se U ha trovato la quintupla da eseguire, allora la esegue e torna al punto 1); la testina su $N_1$ è posizionata sul carattere uguale a quello letto dalla testina su $N_2$:
	*2.1)* Muove a destra di due posizioni la testina su $N_1$: ora è posizionata sul carattere che deve essere scritto;
	*2.2)* Copia su $N_2$ il carattere che legge su $N_1$ ; 
	*2.3)* Muove a destra di due posizioni la testina su $N_1$: ora è posizionata sul carattere che corrisponde allo stato in cui T deve entrare;
	*2.4)* Copia su $N_3$ il carattere che legge su $N_1$ ;
	*2.5)* Muove a destra di due posizioni la testina su $N_1$ : ora è posizionata sul carattere che descrive il movimento della testina ;
	*2.6)* Se su $N_1$ legge ‘S’ allora sposta a sinistra la testina su $N_2$, se su $N_1$ legge ‘D’ allora sposta a destra la testina su $N_2$, se su $N_1$ legge ‘F’ allora non compie alcuna azione.
Riferirsi alla figura relativa alla computazione $U( p_{T_{PAL}}, ababbbabaa)$ e provare a simulare l’intera computazione.
>[!info]
>Studiare il paragrafo 2.6) della dispensa 2.

Intanto, si osserva che le testine sui nastri 3 e 4 non si muovono *mai*. Inoltre, dopo che nella prima cella di $N_4$ è stato scritto lo stato di accettazione della macchina “scritta” su $N_1$, il contenuto di $N_4$ non verrà mai più modificato.
Poi, quale è l’alfabeto di U? Finora è stato usato l’insieme $Q\cup\Sigma\cup\{-\}\cup\{〈 \}\cup\{ 〉\}\cup\{\square\}\cup\{ , \}$ come alfabeto.
- - Ma ogni macchina T ha un suo insieme degli stati Q e un suo alfabeto $\Sigma$;
- - E noi vogliamo che U sappia simulare <u>qualunque</u> macchina di Turing T ;
- - Allora, U dovrebbe essere definita su un alfabeto infinito. Ma noi sappiamo che l’alfabeto di una macchina di Turing deve avere cardinalità costante;
- - E, allora, codifichiamo tutto in binario e utilizziamo anche la codifica usata nella dispensa.
Intanto, osserviamo che, senza perdita di generalità, possiamo assumere che sia $\Sigma =\{0,1\}$ 
Poi, a pag. 11 della dispensa 2, viene descritta una macchina di Turing T con alfabeto {0,1} e:
1. Insieme degli stati $Q_T = \{ω_0, ..., ω_{k-1}\}$ , con stato iniziale $ω_0$, stato di accettazione $ω_1$, e stato di rigetto $ω_2$ . $|Q_T|=k$ ;
2. Insieme delle quintuple $P = {p_1,..., p_h}$ , dove la sua i-esima quintupla è  $p_i = ⟨ ω_{i1} ,b_{i1} , b_{i2} , ω_{i2} , m_i ⟩$.
Mediante la seguente parola $\rho_T$  i cui caratteri appartengono all’alfabeto  $Q_T\cup\{0, 1,\oplus,\otimes, −, f , s, d \}$ :
1. $\begin{align}&\rho_T = ω_0 − ω_1 \otimes ω_{11} − b_{11} − b_{12} − ω_{12} − m_1 \oplus ω_{21} − b_{21} − b_{22} − \\& ω_{22} − m2 \oplus ... \oplus ω_{h1} −  b_{h1} − b_{h2} − ω_{h2} − m_h\oplus\end{align}$
2. Rispetto alla nostra rappresentazione, in $\rho_T$  abbiamo il carattere ’-’ al posto di ’,’, il carattere ‘$\otimes$’ per segnalare l’inizio dell’insieme delle quintuple, e il carattere ‘$\oplus$’ per separare due quintuple e per terminare la parola.
Dunque, l’alfabeto usato per rappresentare $\rho_T$ contiene QT
E, allora, codifichiamo QT in binario.
>[!info]
>A pag. 13 vene introdotta una codifica binaria  $b^Q$ dell’insieme Q degli stati di T – invece di usare quella codifica ve ne propongo qui una più semplice

$b^Q:Q\rightarrow\{0,1\}^k$, ossia, la codifica $b^Q$ rappresenta uno stato di T mediante una parola di k bit.
$b^Q(ω_i)$ è la parola che ha un 1 in posizione i+1 e 0 altrove – esempio: se k=4, $b^Q(ω_0)=1000, b^Q(ω_1)=0100, b^Q(ω_2)=0010, b^Q(ω_3)=0001$ .
A questo punto, rappresentiamo T mediante la seguente parolona nell’alfabeto $\Sigma_B = \{0,1,\oplus,\otimes, −, f , s, d\}$ :
$\begin{align}\\&\beta_T = b^Q(ω_0) - b^Q( ω_1)\otimes b^Q(ω_{11}) − b_{11} − b_{12} − b^Q(ω_{12}) − m_1 \oplus \\& b^Q(ω_{21}) − b_{21} − b_{22} − b^Q(ω{22}) − m_2 \oplus ... \oplus b^Q(ω_{h1}) − b_{h1} −\\& b_{h2} − b^Q(ω_{h2}) − m_h \oplus\end{align}$
Quello che cambia, a questo punto, rispetto alla descrizione di U che abbiamo appena visto è la gestione del passo 1.2):
*1.2)* *se U legge lo stesso carattere su $N_1$ e su $N_3$*, allora sta scandendo una quintupla di T che inizia con lo stato in cui si troverebbe T a questo punto della computazione; in questo caso muove a destra la testina su $N_1$ per posizionarla sul carattere a destra di ‘,’
Adesso, su $N_3$ non è scritto un singolo carattere, ma una parola di k bit, perché, naturalmente, all’inizio della computazione, sul terzo nastro U ha copiato non “lo stato iniziale” di T ma i k bit che codificano lo stato iniziale di T – che, in questo caso, sono i primi k bit di $\beta_T$.
Perciò, **“se U legge lo stesso carattere su $N_1$ e su $N_3$”** diventa ora *“se la sequenza di k bit sul nastro $N_1$ che inizia dal punto in cui è posizionata la testina coincide con la sequenza di k bit sul nastro $N_3$”*.
Quella che prima era una quintupla, deve essere ora trasformata in un insieme di quintuple che permettono di eseguire k confronti.
La descrizione **completa** della macchina U che lavora con questa codifica binaria (che è un lavoro tecnico) la trovate nel paragrafo 2.6.
Un’ultima questione: e se la parola scritta sul primo nastro di U non corrisponde alla descrizione di una macchina di Turing?
Abbiamo due possibilità per gestire questa questione: 
1. Prima di iniziare a copiare lo stato iniziale di T sul terzo nastro e lo stato di accettazione di T sul quarto nastro, U controlla che la parola scritta sul primo nastro sia effettivamente la descrizione di una macchina di Turing (ossia, soddisfi le specifiche descritte a pag. 11 della dispensa 2): se non è così, U termina nello stato di rigetto;
2. Oppure, utilizziamo la regola che abbiamo illustrato nel paragrafo 2.3: se l’input non rispetta le specifiche, il problema è dell'utente.
Dunque, Turing ha progettato una macchina di U che prende in input:
1. Una parola $p_T$ che descrive una qualsiasi macchina di Turing T e 
2. Una parola x, input di T ;
E che riesce a simulare la computazione T(x) – **qualunque sia T** ;
Ossia, U è l’algoritmo che descrive il comportamento di un calcolatore.
Tuttavia, l’andare avanti e indietro sul nastro perché, nel modello progettato da Turing le testine, ad ogni passo, sanno muoversi di una sola posizione, è limitante.
Ma perché mai a Turing non è venuto in mente di assegnare un  indirizzo a ciascuna cella del nastro e definire le sue quintuple nella forma$〈 q_1 , s_1, s_2, q_2 , x〉$,
	che significa: se sei nello stato $q_1$ e leggi il simbolo $s_1$, allora scrivi $s_2$, entra nello stato $q_2$ e sposta la testina nella cella di indirizzo x.
Perché mai non lo ha fatto?
## La Macchina di Turing
Diciamocelo, Turing sembra averci ragionato poco sul suo modello di calcolo, per non aver pensato ad una memoria ad accesso diretto. Ma se non lo ha fatto lui, possiamo sempre farlo noi. Ossia, possiamo definire un modello di calcolo quasi identico alla Macchina di Turing, ma, nel nostro modello, ogni cella del nastro ha un indirizzo, e, siccome il nastro è infinito, ci sarà una cella 0, una cella 1, una cella 2, ... ma anche una cella -1, una cella -2, ...
![[Pasted image 20230321135007.png|center]]

e le quintuple hanno la forma $〈 q_1 , s_1, s_2, q_2 , x〉$, che significa: se sei nello stato $q_1$ e leggi il simbolo $s_1$, allora scrivi $s_2$, entra nello stato $q_2$ e sposta la testina nella cella di indirizzo x.
In fondo, dunque, non era così difficile progettare un modello di calcolo con memoria ad accesso diretto, no?
E adesso che abbiamo definito una simil-Macchina di Turing dotata di memoria ad accesso diretto, divertiamoci un po’ a vederlo all’opera.
>[!danger]- Esercizio
>Progettare una simil-macchina di Turing che esegue lo stesso compito di $T_{PAL}$.
