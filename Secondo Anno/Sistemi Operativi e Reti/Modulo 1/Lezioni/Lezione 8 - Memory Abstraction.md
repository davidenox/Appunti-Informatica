# Gestione della memoria nei SO
**Memoria Principale ( RAM )**:
- Fondamentale, cresce rapidamente, ma *i programmi crescono più velocemente*.
- *Desiderio*: Memoria privata, grande, veloce, persistente e a basso costo.
- La realtà tecnologica è diversa.
**Gerarchia della memoria**:
- Concetto sviluppato nel tempo.
- Da memoria veloce e costosa a memoria lenta, economica e di grandi dimensioni.
	- Es. Da pochi MB di memoria veloce a TB di memoria lenta e dispositivi di archiviazione come USB.
**Compito del SO**:
- Astrazione di questa gerarchia in un modello utile e gestione dell'astrazione.
**Gestione della memoria**:
- Gestisce la memoria e la sua gerarchia.
- Traccia l'uso della memoria, alloca e libera memoria per i processi.
***Focus***: **Memoria principale** ( storage di massa/dischi in lezioni successive )
## Gestione della memoria: Outline
- Memory Abstraction 
- Virtual Memory
- Algoritmi di sostituzione delle pagine
- Problemi di Progettazione per Sistemi di Paging
### Memoria senza astrazione
Modello più semplice: Uso diretto della memoria fisica!
Nei primi computer mainframe, minicomputer e PC, non esisteva astrazione della memoria ( ogni programma vedeva solo la memoria fisica ).
Ad esempio, con l'istruzione `MOV REGISTER1, 1000` la locazione fisica di memoria `1000` veniva trasferita in `REGISTER1`. Un programma poteva interferire con un altro, causando crash. ( Esempio/Rischio : Un applicativo utente può cancellare il SO! )
### Nessuna astrazione: Monoprogrammazione
Tre modelli principali di organizzazione della memoria:
a) OS in RAM : Utilizzato su mainframe e sui minicomputer ( desueto ).
b) OS in ROM : Es. Sistemi embedded.
c) OS+drivers in ROM+RAM : Primi PC ( es. MS-DOS: La ROM era chiamata Basic Input Output System - *BIOS* )
![[Pasted image 20231114160109.png|center|500]]
(Slide 7)