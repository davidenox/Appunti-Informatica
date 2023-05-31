# Macchine a stati finiti
## Analisi di circuiti sequenziali
Consideriamo il circuito in figura

![[Pasted image 20230531145234.png|center]]

Il circuito contiene alcune porte logiche elementari e un registro formato da due flip-flop. Ognuno dei due flip-flop quindi ha uno **stato attuale** (ossia il bit che sta memorizzando), dato dalla variabile indicata con $Q$ nel disegno, e uno **stato futuro** (ossia il bit che si troverà a memorizzare nel momento in cui il clock passerà dallo stato 0 allo stato 1) dato dalla variabile indicata con $D$.

Dato lo stato attuale del circuito (la coppia di bit $Q_{1},\: Q_{2}$) e l'input che gli passiamo in questo momento (il bit $x$), risultano univocamente determinati sia l'output attuale del circuito (il bit $y$), sia lo stato futuro del circuito (la coppia di bit $D_{1},\: D_{2}$). Quindi il circuito può essere descritto da un sistema di tre equazioni in cui $Q_{1},\:Q_{2}$ e $x$ costituiscono le variabili indipendenti e $D_{1},\: D_{2}$ e $y$ quelle dipendenti.

Vediamo ora la tabella di stato del circuito mostrato sopra.

![[Pasted image 20230531145303.png|center]]

Oltre che con le equazioni di stato e la tabella di stato c'è anche un altro modo conveniente in cui possiamo rappresentare un circuito sequenziale: con un grafo diretto con gli archi etichettati. Usiamo i nodi del grafo per rappresentare gli stati del circuito, gli archi per le transizioni da uno stato all'altro e le etichette sugli archi per indicare gli input che determinano le transizioni e gli output del circuito. Il grafo che si ottiene si chiama **diagramma di stato** del circuito.
Per esempio, nel caso del nostro circuito abbiamo quattro possibili stati (i valori che la coppia di bit $(Q_{1},\: Q_{2})$ può assumere). Indichiamoli con $S_{0}=(0,0),$ $S_{1}=(0,1),$ $S_{2}=(1,0)$ e $S_{3}=(1, 1)$ e assumiamo che inizialmente il circuito si trovi nello stato $(Q_{1},Q_{2})=(0,0)$.

![[Pasted image 20230531145340.png|center]]

Cosa succede quando il clock del circuito passa per la prima volta da 0 a 1? Questo dipende dall'input del circuito: in accordo alla figura sopra, quando il circuito è nello stato $(Q_{1}, Q_{2})=(0,0)$ abbiamo che

- se l'input è $x=0$, allora l'output è $y=0$, inoltre quando il clock passa da 0 a 1, lo stato del primo flip-flop resterà 0, mentre quello del secondo passerà ad 1 $(D_{1},D_{2})=(0,0)$, quindi al ciclo di clock successivo  il circuito sarà nello stato $S_{1}$

![[Pasted image 20230531145409.png|center]]

- se invece l'input è $x=1$, l'output sarà ancora $y=0$, e quando il clock passa da 0 a 1, lo stato di entrambi i flip-flop resterà a 0 $(D_{1},D_{2})=(0,1)$, quindi al ciclo successivo di clock il circuito sarà ancora nello stato $S_{0}$

![[Pasted image 20230531145432.png|center]]

## Progetto di circuiti sequenziali 
In questa sezione vediamo come il diagramma e le equazioni risultano molto utili anche quando vogliamo progettare un circuito sequenziale che svolga una determinata operazione. 
Supponiamo di voler progettare un circuito con un input $x$ e un output $y$ che si comporti nel seguente modo:
- ad ogni ciclo di clock gli passiamo un input $x$ dal valore Booleano
- l'output $y$ del circuito deve essere 1 ogni volta che gli ultimi tre bit che abbiamo dato in input formano la sequenza 101.
Per esempio se gli input $x$ passati al circuito nei primi $t=1,\:2,\:\dots,\:10$ cicli di clock sono 

![[Pasted image 20230531145515.png|center]]

allora i valori restituiti in output dal circuito nei rispettivi cicli di clock devono essere

![[Pasted image 20230531145538.png|center]]

Infatti $y$ deve essere 1 al quarto ciclo di clock, perché nei cicli 2, 3 e 4 la sequenza di bit in input è stata 101, e deve essere 1 anche al sesto ciclo di clock perché nei cicli 4, 5 e 6 la sequenza in input è stata 101. Per tutti gli altri cicli $t$ l'output $y$ deve essere 0 perché la sequenza di bit in input nei cicli $(t-2,\:t-1,\:t)$ è diversa da 101 per ogni $t\neq 4,6$.

Progettare il circuito pensando direttamente alle porte logiche che serviranno e come connetterle sembra molto difficile, ma se partiamo dall'astrazione che ci fornisce il diagramma di stato, il progetto del circuito diventa molto più facile.
Il nostro circuito dovrà partire da uno stato iniziale $S_{0}$. 

![[Pasted image 20230531145611.png|center|500]]

Il primo input $x$ sarà 0 o 1. Cosa deve fare il circuito nei due casi? Sicuramente in entrambi i casi deve restituire 0 in output, ma se l'input è $x=0$ allora è come se fossimo ancora nello stato iniziale, mentre se $x=1$, quello potrebbe essere il primo bit della sequenza 101 che il circuito deve "riconoscere", quindi mandiamo il circuito in un nuovo stato $S_{1}$. Potete pensare allo stato $S_{1}$ informalmente come quello che si "ricorda" che l'ultimo bit letto è 1. 

![[Pasted image 20230531145655.png|center|500]]

Cosa deve fare il circuito quando si trova nello stato $S_1$? Se l'input è x=0 allora quello potrebbe essere il secondo bit della nostra sequenza 101, quindi mandiamo il circuito in un nuovo stato $S_{2}$, che deve "ricordarsi" che gli ultimi due bit letti sono 10. Se invece $x=1$ allora vuol dire che gli ultimi due bit letti sono 11, ma quindi ai fini di riconoscre la sequenza 101, il circuito deve solo ricordarsi che l'ultimo bit letto è 1. Abbiamo già uno stato che si ricorda che l'ultimo bit letto è 1, ovvero $S_{1}$.

![[Pasted image 20230531145724.png|center]]

Se siamo nello stato $S_2$, gli ultimi due bit letti sono 10. Quindi se ora leggiamo $x=0$ vuol dire che gli ultimi tre bit letti saranno 100: resituiamo in output 0 e mandiamo il nostro circuito allo stato iniziale $S_0$. Se invece $x=1$ abbiamo completato la nostra sequenza 101 e quindi restituiamo in input $y=1$. In quale stato mandiamo il circuito? L'ultimo 1 letto potrebbe essere il primo bit di una nuova sequenza 101, quindi mandiamo il circuito nello stato $S_{1}$ che si ricorda che l'ultimo bit letto è 1.![[Pasted image 20230531145755.png|center]]
A questo punto il lavoro concettuale di progettazione è finito. Ora dobbiamo tradurre il diagramma di stato in un circuito, ripercorrendo a ritroso i passaggi che abbiamo svolto nella [[#Analisi di circuiti sequenziali|prima sezione]].
Siccome il nostro diagramma ha tre stati $S_{0}, S_{1}$ e $S_{2}$, avremo bisogno di almeno due flip-flop. Se codifichiamo i tre stati del nostro diagramma con le coppie di bit $S_{0}=(0,0)$, $S_{1}=(0,1)$ e $S_2=(1,0)$ e indichiamo come al solito con $Q_1$ e $Q_2$ gli stati attuali dei flip-flop e con $D_{1}$ e $D_{2}$ gli stati futuri, dal diagramma di stato otteniamo la seguente tabella di stato

![[Pasted image 20230531145829.png|center]]

Nella tabella ci sono delle **X** sulle righe sulle righe corrispondenti allo stato $(Q_{1},Q_{2})=(1,1)$, perché se il nostro circuito partisse dallo stato $(Q_{1},Q_{2})=(0,0)$ non andrà **mai** nello stato $(1,1)$, quindi non importa quali valori assegnamo a $D_1,D_2$ e $y$ in corrispondenza di quelle righe.

Sappiamo già come possiamo ricavare una formula da una tabella di verità: per esempio, la mappa di Karnaugh per la colonna $D_{1}$ è

![[Pasted image 20230531151103.png|center]]

quindi una formula per $D_1$ è $Q_{2}\bar x$.

![[Pasted image 20230531151144.png|center]]

La foto sopra indica un circuito che implementa il diagramma di stato in [[LRL/img/img86.png|figura]].

## Macchine a stati finiti
I circuiti visti in questa lezione si chiamano **macchine** (o **automi**) a stati finiti e possiamo schematizzarli come nella figura sottostante

![[Pasted image 20230531151240.png|center]]

Ogni blocco del circuito o è un circuito combinatorio o un registro; tutti i registri sono sincronizzati allo stesso clock e in ogni ciclo contenuto nel circuito c'è almeno un registro. 
Questi circuiti si distinguono in macchine alla *Mealy* (quelle in cui gli output dipendono anche dagi input **attuali**) e le macchine alla *Moore* (quelle in cui gli output dipendono solo dallo stato del circuito). Gli esempi visti in questa lezione sono macchine alla Mealy.