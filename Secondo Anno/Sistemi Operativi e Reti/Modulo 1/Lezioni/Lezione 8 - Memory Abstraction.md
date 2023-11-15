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
C'è la possibilità di eseguire più programmi contemporaneamente senza astrazione della memoria usando lo "**Swapping**": Salvataggio del contenuto *della memoria in un file su memoria non volatile* e prelievo del programma successivo.
![[Pasted image 20231115101736.png|center|500]]
*Native Approach*: Caricamento di più programmi in memoria fisica consecutivamente, senza astrazione dell'indirizzo.
*a*) Un programma di 16KB che inizia con l'istruzione `JMP 24`.
**b**) Un altro programma di 16KB che inizia con l'istruzione `JMP 28`.
***c***) Entrambi i programmi caricati consecutivamente. Quando il secondo programma viene eseguito, `JMP 28` *indirizza erroneamente all'istruzione del primo programma*, causando errori.
**Problema principale**:
- I programmi utilizzano indirizzi assoluti di memoria fisica, portando a conflitti durante l'esecuzione.
- La mancanza  di astrazione dell'indirizzo può causare il crash dei programmi.
# Astrazione della memoria
*Problema*: L'accesso diretto alla memoria fisica da parte dei programmi può causare problemi come la distruzione del SO e la difficoltà di esecuzione simultanea di più programmi.
*Soluzione*: Astrazione della memoria per separare e proteggere i programmi in esecuzione.
**Concetto di Spazio degli Indirizzi**:
- Ogni programma ha *un insieme unico di indirizzi* ( spazio degli indirizzi ) che può usare per indirizzare la memoria.
- Questo spazio è indipendente da altri processi e rappresenta una forma di memoria astratta.
## Implementazione con registri base e limite
*Vecchia soluzione*: Mappare lo spazio degli indirizzi di ogni processo in parti diverse dalla memoria fisica.
**Registri Base e Limite**: Due registri hardware speciali presenti in molte CPU.
- *Registro Base*: Contiene l'indirizzo fisico di inizio di un programma in memoria.
- *Registro Limite*: Contiene la lunghezza del programma.
Gli indirizzi generati dai programmi vengono aggiustati automaticamente aggiungendo il valore del registro base.
### Address Spaces
![[Pasted image 20231115104509.png|center|300]]

- Il registro di base mette in atto la *rilocazione dinamica*;
- Il registro limite applica la protezione.
```
Checks for MOV Reg1, Addr:
IF(Addr>LIMIT)->NOT OKAY
IF(BASE+Addr<BASE)->NOT OKAY
```

## Funzionamento e limiti dei registri
Ogni riferimento alla memoria da parte di un programma:
- *Aggiunge il valore del registro base* all'indirizzo generato.
- *Confronta con il registro limite* per assicurare che l'accesso sia entro i limiti consentiti.
**Vantaggi**: Offre a ogni processo uno *spazio degli indirizzi separato e protetto*.
**Svantaggi**: Necessità do eseguire somme e confronti ad ogni accesso alla memoria, il che può essere lento.
### Cosa accade se eccediamo di memoria?
Un computer medio al suo avvio può avere 50-100 computazioni o più ( Applicazioni come Photoshop possono richiedere fino a 1GB solo per avviarsi, perciò la memoria fisica totale necessaria è spesso superiore a quella disponibile).

>Strategie per gestire il sovraccarico di memoria:
1. **Swapping** ( scambio ) *dei processi*:
	- Sposta interi processi tra la memoria RAM e la memoria non volatile ( Disco/SSD).
	- Processi inattivi archiviati su memoria non volatile.
2. **Memoria Virtuale**:
	- Permette l'esecuzione dei programmi anche se solo parzialmente presenti nella memoria principale.
## Improvement: Dynamic Partitions and Swapping
Lo scambio può portare alla *frammentazione* della memoria, il che rende necessaria la compattazione della memoria ( <u>estremamente</u> lenta).
![[Pasted image 20231115105812.png|center|600]]
## Gestione dello spazio e crescita dei processi
*Sfida*: Gestire processi con segmenti di dati in crescita.
*Memory Compaction*: Sposta processi per liberare spazio, ma richiede tempo.
**Soluzione**: Allocare memoria extra durante lo swapping o lo spostamento dei processi.
Cosa fare in caso di Out Of Memory?
- "Uccidere" il processo.
- Trasferire il processo.
- Swapping.
![[Pasted image 20231115120702.png|center|400]]
# Gestione della memoria libera
*Obiettivo*: Tenere traccia dell'utilizzo della memoria ( ad esempio ogni blocco di 4 bytes ).

>Metodi principali:
- **Soluzione 1**: *Bitmap* tiene traccia di quali blocchi vengono allocati.
- **Soluzione 2**: Una *lista* collegata tiene traccia della memoria non allocata.

*Importanza*: Questo tracciamento non riguarda solo la memoria, ma anche risorse come i file system.
## Memory Management: Bitmaps vs Linked Lists
*Bitmap*: Trovare i fori richiede una scansione ( lenta ).
*Lista*: Liste di processi/"buchi":
- Allocazione lenta contro deallocazione lenta.
- Buchi ordinati per indirizzo per una rapida coalescenza ( come fusione tra gocce ).
 ![[Pasted image 20231115122458.png|center]]
### Memory Management e Linked List
Nella pratica *viene spesso usata una doppia linked list*:
- Rende *più facile gestire lo spazio libero*:
	- Può controllare facilmente se il precedente spazio è libero.
	- Può regolare facilmente i puntatori.
![[Pasted image 20231115122903.png|center|500]]
## Schemi di allocazione della memoria
- *First Fit*: Seleziona il primo spazio disponibile.
	- Opzione più semplice (MINIX3);
- *Next Fit*: Seleziona il successivo spazio disponibile.
	- Più lento del First Fit in pratica;
- *Best Fit*: Sceglie lo spazio più adeguato.
	- Tende alla frammentazione;
- *Worst Fit*: Sceglie lo spazio meno adeguato.
	- Prestazioni scadenti in pratica;
- *Quick Fit*: Mantiene spazi di dimensioni diverse ( le più richieste ).
	- Scarsa performance nella coalescenza.
- *Buddy Allocation* ( Linux ): Migliora la performance di coalescenza del Quick Fit.
![[Pasted image 20231115124704.png|center|150]]
### Allocazione della memoria in Linux
Linux utilizza vari meccanismi per l'allocazione della memoria.
Il principale è una allocazione delle pagine basata sull'algoritmo di *Buddy Memory Allocation*.
**Funzionamento**:
- La memoria inizia come un singolo pezzo contiguo.
- Ad ogni richiesta, la memoria viene divisa secondo una potenza di 2.
- Blocchi di memoria contigui vengono uniti quando rilasciati.
#### BMA: Un esempio
![[Pasted image 20231115140405.png|center|400]]
1. Inizialmente la memoria consiste di un singolo pezzo contiguo ( 64 pagine nel semplice esempio (a));
2. Arriva una richiesta da 8 pagine ( arrotondata a potenza di 2);
3. L'intero pezzo di memoria viene quindi diviso a metà (b);
4. Poiché ciascuno dei due pezzi è ancora troppo grande, il pezzo più in basso viene diviso ancora a metà (c) e poi ancora (d);
5. Ora abbiamo un pezzo della dimensione corretta, che viene così allocata al chiamante, grigio in (d).
![[Pasted image 20231115140747.png|center|400]]
6. Arriva una seconda richiesta di 8 pagine; questa può essere soddisfatta immediatamente (e);
7. Arriva una terza richiesta di 4 pagine;
8. Il pezzo disponibile più piccolo viene diviso (f) e ne viene assegnata la metà (g);
9. Successivamente il secondo pezzo di 8 pagine viene rilasciato(h);
10. Infine, anche l'altro pezzo di 8 pagine viene rilasciato. Poiché i due pezzi di 8 pagine adiacenti appena liberati provengono dallo stesso pezzo di 16 pagine, *vengono uniti* per riottenere il pezzo di 16 pagine (i).
### Frammentazione e Slab Allocator
Il *Buddy Algorithm puù causare frammentazione* interna: Una richiesta di 65 pagine richiede l'allocazione di 128 pagine.
Lo *SLAB Allocator* in Linux risolve questo problema: 
- Prendendo blocchi tramite l'algoritmo buddy e;
- Ritagliando unità più piccole ( *slab* ) per gestirle separatamente
![[Pasted image 20231115141323.png|center|400]]
#### SLAB Allocator
**Principio di Base**:
- Il kernel spesso ha bisogno di creare e distruggere piccoli oggetti di dimensioni e tipi specifici.
- Senza ottimizzazione, questa operazione potrebbe portare a una significativa frammentazione della memoria.
**Come Funziona**:
- Nello slab allocation, la *memoria è divisa in blocchi chiamati "**slabs**"*.
	- Ulteriormente suddivisi in chunk di dimensioni uniformi,
	- adeguati per ospitare un oggetto di un certo tipo.
- Un "slab" può essere in uno dei seguenti stati:
	- Pieno ( tutti i chunk sono utilizzati );
	- Parzialmente pieno ( alcuni chunk sono liberi);
	- Vuoto ( tutti i chunk sono liberi ).
![[Pasted image 20231115141820.png|center|400]]
#### Slab e Caching
Quando un oggetto viene deallocato, non viene immediatamente restituito al sistema come memoria libera. 
- Viene mantenuto nella cache in modo che, se viene richiesta un'altra istanza dello stesso tipo di oggetto, possa essere rapidamente riallocata senza l'overhead di inizializzazione.
![[Pasted image 20231115142104.png|center|500]]

In questo esempio, uno Slab contiene:
- Puntatori all'inizio della memoria con gli slot degli oggetti;
- Indice del prossimo slot libero;
- `bufctl` : Array di indici dei prossimi oggetti liberi;
- Slot per gli oggetti.