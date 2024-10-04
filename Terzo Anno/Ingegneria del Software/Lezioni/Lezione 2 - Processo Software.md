>[!important]- Processo Software:
> Serie di attività necessarie alla realizzazione del prodotto SW nei tempi, con i costi e con le desiderate caratteristiche di qualità. Nel suo contesto:
> 1. Si applicano metodi, tecniche e strumenti;
> 2. Si creano prodotti ( sia intermedi che finali );
> 3. Si stabilisce il controllo gestionale del progetto;
> 4. Si garantisce la qualità;
> 5. Si governano le modifiche.

# Fasi del processo

Un processo software segue un *ciclo di vita* che si articola in tre stadi:
- *Sviluppo*;
- *Manutenzione*;
- *Dismissione*.
Nel primo stadio si possono riconoscere due tipi di fasi:
1. La fase di tipo *Definizione*, in cui ci si occupa di "cosa" il software deve fornire. Si definiscono i requisiti e si producono le specifiche.
2. La fase di tipo *Produzione*, in cui si definisce "come" realizzare quanto ottenuto con le fasi di Definizione. Si progetta il software, si codifica, si integra e si rilascia al cliente.
Lo stadio di *Manutenzione* è a supporto del software realizzato e prevede fasi di definizione e/o produzione al suo interno.

Durante ogni fase si procede ad effettuare il **testing** di quanto prodotto, mediante opportune tecniche di *verifica* e *validazione* applicate sia ai prodotti intermedi che al prodotto finale.

## Tipi di Manutenzione

-  Manutenzione *correttiva*, che ha lo scopo di eliminare i difetti (`fault`) che producono guasti (`failure`) del software;
-  Manutenzione *adattativa*, che ha lo scopo di adattare il software ad eventuali cambiamenti a cui è sottoposto l'ambiente operativo per cui è stato sviluppato;
-  Manutenzione *perfettiva*, che ha lo scopo di estendere il software per accomodare funzionalità aggiuntive;
-  Manutenzione *preventiva* (o $\texttt{software reengineering}$), che consiste nell'effettuare modifiche che rendano più semplici le correzioni, gli adattamenti e le migliorie.

# Definizione di ciclo di vita

>[!important]- Def. IEEE Std 610-12 (Terminologia ISW)
>-  Intervallo di tempo che intercorre tra l’istante in cui nasce l’esigenza di costruire un prodotto software e l’istante in cui il prodotto viene dismesso. Include le fasi di definizione dei requisiti, specifica, pianificazione, progetto preliminare, progetto dettagliato, codifica, integrazione, testing, uso, manutenzione e dismissione.
>- Nota: tali fasi possono sovrapporsi o essere eseguite in modo iterativo.

## Modelli di ciclo di vita

Il **Modello del ciclo di vita** del software specifica la serie di fasi attraverso cui il prodotto SW progredisce e l'ordine con cui le stesse vanno eseguite, dalla definizione dei requisiti alla dismissione. La scelta del modello dipende da:
1. Natura dell'applicazione;
2. Maturità dell'organizzazione
3. Metodi e tecnologie usate;
4. Eventuali vincoli dettati dal cliente.
L'assenza di un modello del ciclo di vita corrisponde ad una modalità di sviluppo detta *build & fix* ( o *fix-it-later* ), in cui il prodotto SW viene sviluppato e successivamente rilavorato al fine di soddisfare le necessità del cliente.

![[Pasted image 20241004222440.png|center|500]]

![[Pasted image 20241004222503.png|center|500]]

![[Pasted image 20241004222530.png|center|500]]

![[Pasted image 20241004222547.png|center|500]]

# Prototipazione Software
	Sviluppo rapido del software per suscitare o convalidare requisiti
## Utilizzo dei prototipi di sistema
(slide 11)