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
work in progress