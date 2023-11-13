# Lo scheduling dei Processi/Thread
In un computer multiprogrammato, molteplici processi/thread possono competere per la CPU contemporaneamente.
Lo scheduler decide quale processo/thread eseguire successivamente seguendo un algoritmo di scheduling ( molti problemi di scheduling per processi valgono anche per i thread ). Lo scheduling al livello del kernel avviene per thread, indipendentemente dal processo di appartenenza. Sfide specifiche emergono nello scheduling dei thread.
## Storia
Nei sistemi *batch storici*, lo *scheduling* era *lineare* ( si eseguiva il lavoro successivo sul nastro ). Con la *multiprogrammazione*, lo *scheduling* è diventato *complesso* a causa della concorrenza tra utenti. Gli algoritmi di scheduling erano cruciali per la prestazione e la soddisfazione dell'utente nei mainframe. Nei PC:
- Spesso un solo processo è attivo;
- La CPU raramente è una risorsa scarsa: la maggior parte dei programmi è limitata dalla velocità dell'input dell'utente.
## Quanto costa in termini di tempo?
Nei server in rete, la CPU spesso è contesa: lo scheduling torna ad essere vitale. Per i dispositivi IoT, gli smartphone e i nodi di sensori, la durata della batteria è un vincolo cruciale ( lo scheduling può cercare di ottimizzare il consumo energetico ).
Lo scambio di processi ( o "*context switch*" ) è oneroso:
- Cambio da modalità utente a modalità kernel;
- Salvataggio dello stato del processo;
- Esecuzione dell'algoritmo di scheduling;
- Cambio della mappa della memoria;
- Invalidazione potenziale della memoria cache.
Troppe commutazioni possono consumare tempo di CPU : la prudenza è essenziale.
## Introduzione al problema di scheduling dei processi
I processi alternano fasi di elaborazione CPU-intense con richieste di I/O.
a) *Compute-bound ( CPU-bound )*: Burst di CPU lunghi, attese di I/O infrequenti.
b) *I/O-bound*: Burst di CPU brevi, attese di I/O frequenti. Sono tali a causa della bassa necessità di calcoli, non della durata delle richieste di I/O.

![[Pasted image 20231107100547.png|center|600]]

Con *CPU più veloci*, i processi tendono ad essere più *I/O-bound* ( CPU e dischi magnetici non stanno avanzando rapidamente in velocità ). *SSD sostituiscono gli hard disk nei PC*, ma i data center utilizzano ancora HDD per il costo per bit.
Lo scheduling *varia in base al contesto*.
-  Ciò che funziona per un dispositivo potrebbe non essere efficace per un altro.
- Il panorama tecnologico è in continua evoluzione.
## Stati dei processi ( rivisitato )
![[Pasted image 20231107101122.png|center|500]]

Se ci sono più processi pronti che CPU disponibili:
- Lo scheduler decide quale processo eseguire successivamente.
- L'algoritmo utilizzato dallo scheduler è chiamato *algoritmo di scheduling*.
## Situazioni in cui è necessario lo scheduling
*Creazione Nuovo Processo*:
- Decisione tra l'esecuzione del processo genitore o figlio.
- Entrambi pronti: può essere scelto chiunque.
*Uscita di un Processo*:
- Se un processo esce, occorre sceglierne un altro dai processi pronti.
- Se nessuno è pronto, occorre eseguire un processo inattivo del sistema.
*Blocco del Processo*: 
- Se un processo si blocca ( I/O, semaforo, etc. ), occorre selezionarne un altro.
- A volte la causa del blocco può influire sulla decisione.
*Interrupt di I/O*:
- Alla conclusione di un I/O, un processo potrebbe diventare pronto.
- Decidere se eseguire il processo appena pronto, il precedente o un altro.
### Tipologie di Scheduling e Prelazione
**Non Preemptive ( Senza Prelazione)**:
- Seleziona un processo e lo *lascia eseguire fino al blocco o al rilascio volontario*.
- *Nessuna decisione* durante gli interrupt del clock.
- Ripristina il processo precedente dopo l'interrupt, a meno che non ci sia una priorità superiore.
**Preemptive ( Con Prelazione )**:
- Sceglie un processo e lo *lascia eseguire per un tempo massimo* definito.
- Se ancora in esecuzione *dopo il tempo*, è *sospeso* e viene scelto un altro.
- Richiede un interrupt del clock per restituire controllo allo scheduler.
**Importanza della Prelazione**:
- Rilevante per le applicazioni e i kernel dei SO;
- Necessaria per *prevenire* che un driver o una chiamata di sistema lenti *blocchino* la CPU;
- In un kernel con prelazione, lo scheduler può forzare un cambio di contesto.
### Diversità negli ambienti di Scheduling
**Batch**:
- Ideale per attività aziendali periodiche.
- Accetta algoritmi senza prelazione.
- Priorità a prestazioni efficienti.
**Interattivo**:
- *Prelazione fondamentale*.
- Previene la monopolizzazione della CPU.
- Adatto per server e utenti multipli.
**Sistemi Real-Time**:
- I processi spesso si bloccano velocemente sapendo di non poter eseguire a lungo.
- *Prelazione non sempre necessaria*.
- Eseguono programmi per specifiche applicazioni, a differenza dei sistemi interattivi che possono eseguire programmi arbitrari.
## Obiettivi generali degli algoritmi di Scheduling
**Sistemi Batch**:
- *Throughput*: Numero di job completati in un tempo fissato.
- *Tempo di Turnaround*: Minimizzare il tempo dallo start all'end di un job.
- *Utilizzo della CPU*: Mantenere la CPU costantemente attiva.
**Sistemi Interattivi**:
- *Tempo di Risposta*: Risposta rapida alle richieste degli utenti.
- *Adeguatezza*: Soddisfare le aspettative dell'utente in termini di tempi di risposta.
**Sistemi Real-Time**:
- *Rispetto delle Scadenze*: Assicurarsi che i dati vengono elaborati nei tempi previsti.
- *Prevedibilità*: Assicurarsi che il funzionamento sia costante, specialmente in sistemi multimediali per evitare degradi della qualità.
**Tutti i Sistemi**:
- *Equità*: Garantire un'equa condivisione della CPU a tutti i processi.
- *Imposizione della Policy*: Garantire l'attuazione delle policy dichiarate.
- *Bilanciamento*: Mantenere tutti i componenti del sistema attivi.
L'equitò è fondamentale in ogni scenario. In un sistema Batch, è ideale combinare i processi CPU-bound e I/O-bound, e nei sistemi Real-Time è cruciale rispettare le scadenze e garantire la prevedibilità.
# Scheduling nei sistemi Batch
- **First-Come First-Served**
- **Shortest Job First**
- **Shortest Remaining Time Next**
## First-Come, First-Served ( FCFS )
**Descrizione**:
- Algoritmo di scheduling *senza prelazione*.
- Processi *assegnati alla CPU nell'ordine in cui arrivano*.
- Una singola coda di processi in stato pronto. Il primo job esegue immediatamente senza interruzioni.
- Processi bloccati ritornano in fondo alla coda.
**Vantaggi**:
- Facile da capire e programmare:
	- Gestione semplice con una *linked list*.
- Equo in base all'ordine di arrivo.
**Svantaggi**:
- Prestazioni non ottimali in scenari misti ( es. processi CPU-Bound e I/O-Bound ).
- Può risultare in tempi di attesa molto lunghi per processi I/O-Bound in presenza di un processo CPU-Bound.
### Un esempio di FCFS
- Un processo CPU-Bound esegue per 1 secondo e successivamente molti processi I/O-Bound leggono dal disco.
- Usando FCFS, i processi I/O-Bound potrebbero impiegare 100 secondi per terminare, invece che 10 secondi con un algoritmo di scheduling con prelazione.
## Shortest Job First ( SJF )
**Descrizione**:
- Algoritmo batch *senza prelazione*.
- Richiede che i tempi di esecuzione siano noti in anticipo.
- Il job più breve viene eseguito per primo.
**Esempio**:
- 4 bob ( A, B, C, D) con i tempi di 8, 4, 4 e 4 minuti.
- Esecuzione in ordine:
	- 8 min. per A, 12 min. per B, 16 min. per C, 20 min. per D ( Media 14 min.)
-  Esecuzione con SJF:
	- 4 min. , 8 min. , 12 min. e 20 min. ( Media 11 min. )

![[Pasted image 20231113114728.png|center|600]]

### Ottimalità di SJF e considerazioni
**Ottimalità**:
SJB è *ottimale nel minimizzare il tempo di turnaround medio* ( il tempo dallo start all'end di un job ) quando tutti i job sono disponibili contemporanemante.

**Limitazione**:
Se i job arrivano in momenti diversi, SJF potrebbe non essere ottimale ( Es. Job A-E con tempi 2-4-1-1-1 e arrivi a 0-0-3-3-3. Due sequenze diverse producono medie di 4,6 e 4,4 min. )
## Shortest Remaining Time Next ( SRTN )
**Descrizione**:
- Versione *con prelazione* di SJF.
- Seleziona sempre il processo con il tempo rimanente più breve per completare.
- Il tempo di esecuzione deve essere noto in anticipo.
**Funzionamento**:
- Confronta il tempo totale del nuovo job con il tempo rimanente dei processi in esecuzione.
- Se il nuovo job è più breve del processo corrente, sospende il processo corrente ed esegue il nuovo job.
- Assicura che i nuovi job brevi ricevano un servizio rapido.
# Scheduling in Sistemi Interattivi
*Il tempo di risposta è fondamentale* rispondendo rapidamente alle richieste.
*Proporzionalità*: Occorre soddisfare le aspettative degli utenti.
*Metodi*:
- Round-Robin Scheduling
- Priority Scheduling
- Shortest Process Next
- Guaranteed Scheduling
- Lottery Scheduling
- Fair-Share Scheduling
## Round-Robin Scheduling
**Concetto**:
- Uno degli algoritmi di scheduling più *vecchi*, *semplici*, *equi e ampiamente utilizzati*.
- *Ogni processo riceve* un intervallo di tempo o "*quanto*" per l'esecuzione.
- Se il processo *non ha terminato* al termine del quanto, *la CPu è oggetto di prelazione* per un altro processo.
- Se un processo termina o si blocca prima del quanto, il passaggio avviene automaticamente.
**Implementazione**:
- Mantenere una lista dei processi eseguibili.
- Una volta esaurito il quanto, il processo viene spostato alla fine della lista.
![[Pasted image 20231113121339.png|center|600]]
### Sfide del Round-Robin e durata del quanto
**Durata del Quanto**:
- La scelta del quanto influisce sull'efficienza.
- Supponendo 1 ms per il cambio di contesto e 4 ms per il quanto: 20% del tempo CPU sprecato in overhead.
**Trade-off**:
- *Quanto lungo*: riduce l'overhead, ma peggiora la reattività ( es. 5 secondi di attesa per un breve comando in un server affollato ).
- *Quanto breve*: maggiore overhead e riduzione dell'efficienza della CPU.
**Ottimizzazione**:
- Se il quanto è maggiore del tempo medio di burst di CPU, la prelazione potrebbe non avvenire spesso. Molti processi potrebbero bloccarsi prima.
- *Compromesso*: Un quanto tra 20 e 50 ms è spesso ragionevole per bilanciare efficienta e reattività.
## Introduzione al Priority Scheduling
*Premessa*: 
- Round-Robin considera tutti i processi ugualmente importanti.
- Alcuni contesti richiedono una gerarchia ( es. Università con differenti ruoli ).
![[Pasted image 20231113122713.png|center|600]]

**Scheduling a priorità**:
- Ogni processo ha una priorità assegnata.
- La CPU esegue il processo con la priorità più alta tra quelli pronti.
- Applicabile anche su semplici PC ( es. `daemon` ).
### Funzionamento
**Gestione delle Priorità**:
- *Priorità* del processo attualmente in esecuzione *può diminuire col tempo*.
- *Se scende* sotto quella del processo successivo, *avviene uno scambio*.
- Possibilità di assegnare un quanto di tempo: al suo esaurirsi, si passa al processo con priorità appena inferiore.
- Evitare che i processi rimangano inibiti indefinitamente, altrimenti potrebbero finire a priorità 0.
**Priorità Statica vs Dinamica**
- *Statica*: es. gerarchie militari o basate sui costi nel data center.
- *Dinamica*: es. basata sull'utilizzo della CPU o sul comportamento I/O-Bound.
### Strategie combinate e Classi di priorità
**Raggruppamento in classi**: 
- Processi divisi in classi di priorità.
- Scheduling a priorità tra le classi, ma round-robin all'interno della stessa classe.
**Esempio**:
- Sistema con 4 classi di priorità.
- Fintanto che ci sono processi in priorità 4, si usano in round-robin. Se vuota, si passa alla 3, poi alla 2, e così via.
- Importante rivedere periodicamente le priorità per evitare che processi a bassa priorità non vengano mai eseguiti ( "morire di inedia" ).
![[Pasted image 20231113134639.png|center|600]]
## Shortest Process Next con Aging
SJB ottimizza il tempo medio di risposta nei sistemi batch. L'obiettivo è applicarlo ai sistemi interattivi.
*Sfida*: Identificare quale tra i processi eseguibili sia effettivamente il più breve.
**Soluzione - Aging**:
- Fare stime basate sul comportamento passato.
- Stima del tempo di un comando: $T0$.
- Stima aggiornata dopo nuova esecuzione $T1$ diventa $aT0+(1-a)T1$.
- Scelta di '$a$' determina il peso delle esecuzioni precedenti nella nuova stima.
- Esempio con $a=1/2$:
	- $T0,T0/2+T1/2,T0/4+T1/4+T2/2,...$
- Dopo 3 esecuzioni, il peso di $T0$ nella stima è $1/8$.
**Utilizzo dell'Aging**: Prevista in molte situazioni dove si basa la previsione su valori passati.
## Guaranteed Scheduling
*Concetto principale*: Fare promesse concrete sugli standard di prestazione e rispettarle.
*Promessa Base*: Se ci sono $n$ utenti o processi, ciascuno ottiene $\sim 1/n$ della potenza della CPU.
*Come funziona*:
- Il sistema tiene traccia di quanta CPU ha ricevuto ogni processo dal momento della sua creazione ( es. 100 secondi ).
- Calcola quanto tempo CPU ogni processo dovrebbe avere:
	- Tempo da creazione $\div n$ (ad esempio 100 sec. 10 processi, ogni processo dovrebbe avere 10 secondi).
- Valuta il rapporto tra il tempo di CPU consumato e quello dovuto.
	- Rapporto di 0,5: ha avuto metà di quanto dovuto.
	- Rapporto di 2,0: ha avuto il doppio di quanto dovuto.
- Esegue il processo con il rapporto più basso finché non supera il suo concorrente più vicino.
## Lottery Scheduling
**Concetti di base**:
- Assegnazione di biglietti della lotteria ai processi per le risorse del sistema, come il tempo della CPU.
- Estrazione casuale di un biglietto per decidere quale processo ottiene la risorsa.
- Esempio: Estrazione 50 volte al secondo $\implies$ vincitore riceve 20 ms di tempo della CPU.
**Distribuzione delle probabilità**:
- Biglietti extra per processi più importanti $\implies$ maggiori probabilità di vincere.
- Esempio: Se un processo ha il 20% dei biglietti, guadagnerà a lungo termine il 20% della CPU.
### Proprietà e applicazioni dello scheduling a lotteria
**Reattività**: Risponde velocemente ai nuovi processi grazie alla distribuzione dei biglietti.
**Cooperazione tra processi**:
- Possibilità di scambiarsi biglietti tra processi cooperanti.
- Esempio: Un processo client dona i suoi biglietti a un processo server per farlo eseguire più rapidamente.
**Soluzione a problemi complessi**:
- Adatto a situazioni dove altri metodi falliscono.
- Esempio: Server video con diverse necessità di frequenze di fotogrammi.
	- Assegnazione di biglietti in base alla velocità necessaria $\implies$ divisione automatica della CPU nelle proporzioni corrette.
## Scheduling Fair-Share
**Premessa**: 
- Tradizionalmente, ogni processo è oggetto di scheduling individualmente.
- Es. Se l'utente 1 ha 9 processi e l'utente 2 ne ha 1, con round-robin o priorità uguali, l'utente 1 avrà il 90% della CPU, l'utente 2 solo il 10%.
**Approccio Fair-Share**:
- Considera la proprietà di ogni processo prima di considerarlo.
- Ogni utente riceve una frazione predefinita di CPU.
- Lo scheduler si assicura che ogni utente riceva la sua frazione, indipendentemente dal numero di processi posseduti.
*Esempio*:
- Due utenti, ciascuno con il 50% della CPU.
	- Utente 1 ha processi *A, B, C, D*;
	- Utente 2 ha processo **E**.
- Sequenza con round-robin:
	- *A B* **E** *C D* **E** *A B* **E**
**Versatilità**: Molti modi di implementare, basati sulla definizione di "equità".
# Scheduling in Sistemi RealTime
Usato nei sistemi operativi in applicazioni in cui il tempo di risposta è fondamentale ( Lettori in CD, Monitoraggio in terapia intensiva, Piloti automatici, Controllo robotico in fabbriche).
Ritardi o mancati tempi di risposta possono avere gravi implicazioni.
## Tipi di sistemi e caratteristiche Real-Time
**Categorie**:
- *Hard Real-Time* : Scadenze assolute da rispettare.
- *Soft Real-Time* : Qualche scadenza mancata è tollerabile.
**Comportamento** : Processi prevedibili, brevi e noti in anticipo.
**Tipi di eventi**:
- *Periodici* : Avvengono a intervalli regolari.
- *Non Periodici* : Avvengono in modo imprevedibile.
**Condizioni di << Schedulabilità >>** : La CPU deve essere in grado di gestire la somma totale del tempo richiesto dai processi.
Per esempio, se ci sono $m$ eventi periodici, l'evento $i$ avviene con un periodo $P_i$ e richiede $C_i$ secondi di tempo della CPU per gestire ogni evento, allora il carico può essere gestito solo se $$\sum_{i=1}^{m}{\frac{C_i}{P_i}}\le 1$$
### Esempi e tipologie di algoritmi Real-Time
**Esempio**:
- Eventi periodici : 100ms, 200ms, 500ms.
- Tempi richiesti: 50ms, 30ms, 100ms.
- Condizione: 0,5+0,15+0,2 < 1.

| Eventi | Periodo | Tempi Richiesti |
| ------ | ------- | --------------- |
| P1     | 100ms   | 50ms            |
| P2     | 200ms   | 30ms            |
| P3     | 500ms   | 100ms                |

**Algoritmi di Scheduling**: 
- *Statici* : Decisioni prese prima dell'esecuzione.
- *Dinamici* : Decisioni prese durante l'esecuzione.
**Limitazioni**: Lo scheduling statico richiede una perfetta conoscenza delle esigenze e delle scadenze.
# Processi e Scheduling
**Premessa**: Abbiamo sempre considerato i processi come appartenenti a utenti differenti in competizione per la CPU.
**Scenario reale**: 
- Un processo può avere molti processi figli sotto il suo controllo.
- Esempio: Un sistema di gestione di una base di dati con molti figli, ognuno con funzioni specifiche.
**Problematica**: Gli scheduler tradizionali non accettano input dai processi utente, spesso portando a decisioni sub-ottimali.
## Separazione tra Meccanismo e Politica di Scheduling
**Principio**: Separare il meccanismo di scheduling dalla politica di scheduling.
**Vantaggio**: L'algoritmo di scheduling può essere parametrizzato, ma i parametri sono forniti dai processi utente.
**Esempio pratico**:
- Kernel con algoritmo di scheduling a priorità.
- Chiamata di sistema permette a un processo di impostare le priorità dei suoi figli.
- Il genitore può influenzare lo scheduling dei suoi figli senza controllarlo direttamente.
**Conclusione**:







## Sincronizzazione, stati e scheduling
