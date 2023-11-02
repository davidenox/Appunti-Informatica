# Outline
Programmazione concerrente e thread:
- Analisi del problema.
La mutua esclusione:
- I "semafori";
- Mutex e Pthreads;
- I monitor;
- Scambi di messaggi.
# Programmazione concerrente e thread: Il problema
## Sincronizzazione e comunicazione tra processi (IPC)
I processi hanno bisogno di un modo per *comunicare*: Condividere i dati durante l'esecuzione.
Nessuna condivisione esplicita tra processi: I dati devono essere scambiati normalmente tra i processi.
I processi hanno un modo per *sincronizzarsi*:
- Per tenere conto delle dipendenze;
- Per evitare che si intralcino a vicenda;
- Si applica anche all'esecuzione multithread.
## Race conditions
- Il processo *A* legge `in=7` e decide di aggiungere il suo file in quella posizione.
- *A* viene sospeso dal SO ( perché il suo slot è scaduto ).
- Anche il processo *B* legge `in=7` e inserisce il suo file in quella posizione.
- *B* imposta `in=8` e alla fine viene sospeso.
- *A* scrive il suo file nella posizione `7`.
**Problema**: La lettura/aggiornamento di un file dovrebbe essere un'azione atomica. Se non lo è, i processi possono "gareggiare" tra loro e giungere a conclusioni errate.
![[Pasted image 20231102101528.png|center|400]]
## Critical region 
Requisiti per evitare "race conditions":
1. Due processi non possono trovarsi contemporaneamente all'interno delle rispettive regioni critiche.
2. Non si possono fare ipotesi sulla velocità o sul numero di CPU.
3. Nessun processo in esecuzione al di fuori della propria regione critica può bloccare altri processi.
4. Nessun processo deve aspettare all'infinito per entrare nella propria regione critica.
*(NON)* soluzioni:
- *Disabilitare gli interrupt*: Impedisce semplicemente che la CPU possa essere riallocata. Funziona solo per sistemi a CPU singola. 
- *Bloccare le variabili*: Proteggere le regioni critiche con variabii 0/1. Le "corse" si verificano ora sulle variabili di blocco.
# La mutua esclusione
## Critical region
![[Pasted image 20231102103623.png|center|500]]
## Esclusione reciproca con *busy waiting*: Alternanza rigorosa
