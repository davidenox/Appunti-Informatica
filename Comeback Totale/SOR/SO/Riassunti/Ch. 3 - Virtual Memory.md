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
Per tenere traccia dell'utilizzo della memoria esistono due metodi principali:
- **Bitmap** che tiene traccia di quali blocchi vengono allocati;
- **Liste concatenate** che tengono traccia della memoria non allocata.
Vengono spesso scelte le liste concatenate, poiché trovare i blocchi non allocati richiede una scansione lenta. Nella pratica viene spesso usata *una doppia linked list*, che rendei più facile gestire lo spazio libero. 
Schemi di allocazione della memoria:
- *First Fit*: Seleziona il primo spazio disponibile (più semplice)
- *Next Fit*: Seleziona il successivo spazio disponibile (più lento)
- *Best Fit*:  Seleziona lo spazio più adeguato (porta a frammentazione)
- *Worst Fit*: Seleziona lo spazio meno adeguato (prestazioni scadenti)
- *Quick Fit*: Mantiene spazi di dimensioni diverse (scarsa performance nella coalescenza)
- *Buddy Allocation* (Linux): Migliora la coalescenza del QF. La memoria inizia come un singolo pezzo contiguo, che ad ogni richiesta viene divisa secondo una potenza di 2. Quando la memoria viene rilasciata i blocchi contigui si riuniscono. L'unico problema è che se lo spazio richiesto non è in potenza di 2 l'algoritmo porta ad una frammentazione interna.
	- **SLAB Allocator** prende blocchi tramite l'algoritmo e ritaglia unità più piccole (*slab*) per gestirle separatamente.
Nello **SLAB ALLOCATION** la memoria è divisa in blocchi chiamati *slabs* (ulteriormente suddivisi in chunk di dimensioni uniformi). Uno slab può essere in uno dei seguenti stati:
- *Pieno* (tutti i chunk utilizzati);
- *Parzialmente pieno* (alcuni chunk liberi);
- *Vuoto* (tutti i chunk liberi).
Quando un oggetto viene deallocato non viene immediatamente restituito al sistema come memoria libera, ma *mantenuto nella cache* in modo che, se viene richiesta un'altra istanza dello stesso tipo di oggetto, possa essere riallocata.

# Memoria virtuale
La memoria virtuale *estende* l'idea di registri base e limite. Ogni programma ha un proprio spazio degli indirizzi suddiviso in "*pagine*", che sono intervalli di indirizzi contigui. Non tutte le pagine devono essere contemporaneamente in memoria fisica, poiché l'HW crea una mappa di quelle direttamente in memoria, e se qualcuna manca, il SO interviene.
La maggior parte dei sistemi moderni usa il "*paging*" (paginazione), ovvero la divisione dello spazio degli indirizzi in unità di dimensione fissa.
L'alternativa è la *segmentazione* con unità di dimensione variabile, ma ormai meno comune.
L'idea è quella di creare per il processo l'illusione di uno spazio di indirizzi ampio, lo **spazio di indirizzi virtuale**. La RAM è nota come *memoria fisica*, mentre **Memory Management Unit** (*MMU*) traduce gli indirizzi virtuali in indirizzi fisici.
I sistemi moderni utilizzano la *paginazione* dividendo la memoria fisica e virtuale in pagine di dimensioni fisse, e traducendo le pagine virtuali in *pagine fisiche* (frame).
Se un programma fa riferimento ad una pagina non mappata, si verifica un **Page Fault**. Il SO allora gli assegna un frame, spostando eventuali frame raramente usati se serve, con uno specifico criterio. Quindi poi inizializza/carica la pagina richiesta nel frame libero o liberato, ed aggiorna la mappa della MMU per riflettere i cambiamenti.
La *relazione* tra gli indirizzi di memoria virtuale e fisica è data dalla **Page Table**.
Le voci di una Page Table sono composti da:
- *Bit presente/assente* - indica se la pagina virtuale è in memoria.
- *Bit protezione* - specifica i tipi di accesso consentiti (rwx).
- *Bit supervisor* - stabilisce se la pagina è accessibile solo al SO o anche ai programmi utente
- *Bit Modificato e Riferimento* - registrano l'uso della pagina.
Per velocizzare la paginazione bisogna decidere dove memorizzarla:
- Nei *Registri HW* : Un registro HW per ogni pagina virtuale, caricato all'avvio del processo. È semplice e non richiede accessi alla memoria durante la mappatura, ma risulta costoso con tabelle di pagine grandi.
- Nella *Memoria Principale*: Tabella interamente in RAM, con un registro che punta al suo inizio. Facile da cambiare ad ogni cambio di contesto, e richiede solo il caricamento di un registro, ma richiede anche accessi frequenti alla memoria rendendo la mappatura più lenta.
Si introduce il **Translation Lookaside Buffer** (*TLB*), un dispositivo HW che mappa gli indirizzi virtuali in fisici senza passare per la tabella delle pagine, riducendo gli accessi alla memoria durante la paginazione.
Il TLB è strutturato come un piccolo numero di voci, ciascuna con numero di pagina virtiaòe, bit modificato, codice di protezione e frame fisico. Alla richiesta di un indirizzo virtuale l'MMU consulta prima il TLB. Se trovato e valido (*TLB HIT*) il frame è prelevato direttamente dal TLB, altrimenti (*TLB MISS*) avviene una ricerca normale nella tabella delle pagine e la voce trovata ne rimpiazza un'altra nel TLB.
I TLB MISS sono *comuni* a causa del numero limitato di voci nel TLB, al quale però non avrebbe senzo aumentare la dimensione. 
- *Soft Miss*: La pagina è in memoria ma non nel TLB.
- *Hard Miss*: La pagina non è neanche in memoria e richiede l'accesso al disco

# Algoritmi di Sostituzione delle pagine
pdf9sl26