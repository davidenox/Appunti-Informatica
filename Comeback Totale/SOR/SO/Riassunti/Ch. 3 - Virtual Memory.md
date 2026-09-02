# Gestione della memoria
La **memoria principale** (*RAM*) è una componente fondamentale, che cresce rapidamente, ma non alla stessa velocità dei programmi. Il desiderio è che sia privata, veloce, persistente e a basso costo, ma nella realtà tecnologica la situazione è diversa.
Il concetto di *gerarchia della memoria* si è sviluppato nel tempo per ridurne i costi, ed il gestore della memoria gestisce anche la sua gerarchia, traccia l'uso della memoria e ne alloca o libera spazio per i processi.
Il modello più semplice è l'utilizzo diretto della memoria fisica in monoprogrammazione. Nasce poi la possiblità di eseguire più programmi contemporaneamente senza astrazione della memoria utilizzando lo **swapping** ( salvataggio del contenuto *della memoria in un file su memoria non volatile* e prelievo del programma successivo ).

## Astrazione della memoria
L'accesso diretto alla memoria fisica da parte dei programmi può causare problemi come la distruzione del SO e la difficoltà di esecuzione simultanea di più processi. La **soluzione** è l'astrazione della memoria per separare e proteggere i programmi in esecuzione. Nasce il concetto di *spazio degli indirizzi*:
- Ogni programma ha un *insieme unico di indirizzi* che può usare per indirizzare la memoria.
- Questo spazio è indipendente da altri processi e rappresenta una forma di memoria astratta.
Per la gestione del sovraccarico di memoria si utilizzano
- **Swapping dei processi**:
	- Sposta interi processi tra memoria RAM e memoria non volatile (disco/SSD);
	- Processi inattivi archiviati su memoria non volatile.
- **Memoria virtuale**:
	- Permette l'esecuzione dei programmi anche se *solo parzialmente presenti nella memoria principale*.

## Gestione della memoria libera
pdf8sl18