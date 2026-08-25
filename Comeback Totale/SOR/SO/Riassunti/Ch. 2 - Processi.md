# Processo
**Un processo è un programma in esecuzione**.
Esso fornisce un'*astrazione* fondamentale del SO, consentendogli di semplificare l'allocazione delle risorse. Ogni processo ha un *proprio flusso di controllo*, e tutti i processi progrediscono ma solo uno è attivo in un dato momento.
## Gerarchie di processi
Il SO crea solo un processo di `init`, mentre i sottoprocessi sono creati in modo **indipendente**.
## Creazione e terminazione di un processo
Un processo viene creato a seguito di uno di questi quattro eventi principali:
1. *Inizializzazione* del sistema;
2. Esecuzione di una *chiamata di sistema per la creazione* di un processo da parte di un processo in esecuzione ( `fork()` );
3. *Richiesta dell'utente* di creare un nuovo processo (es. tramite `bash`);
4. *Avvio di un lavoro* in modalità batch.

Invece, un processo viene terminato a seguito di quattro condizioni tipiche:
1. Uscita normale (volontaria);
2. Uscita a causa di un errore (volontaria);
3. Errore 'fatale' (involontario);
4. Ucciso da un altro processo (involontario).

- `fork`: Crea un *nuovo* processo
	- Il figlio è un 'clone' del genitore, con cui condivide alcune risorse (es. file aperti, segmento di codice, variabili d'ambiente e directory corrente ereditate)
- `exec`: Esegue un nuovo processo (utilizzato in combinazione con fork)
- `exit`: Termina il processo volontariamente ('stato di uscita' comunicato al processo genitore)
- `kill`: Segnale ad un processo (o gruppo di processi) che può causare la terminazione involontaria di un processo.

Un processo può trovarsi in uno di questi tre stati:
1. **Running** - In esecuzione (utilizzando la CPU);
2. **Ready** - Pronto (eseguibile, temporaneamente fermo per consentire l'esecuzione di un altro processo);
3. **Blocked** - Bloccato (finché non si verifica un evento esterno).

Nella tabella dei processi del SO sono memorizzate, per ogni processo, le informazioni:
- ID (PID), Utente (UID), Gruppo (GUID);
- Spazio degli indirizzi di memoria
- Registri HW (Es. Program Counter);
- File aperti;
- Segnali;
- Interrupt;
### Interrupt e Signal
Meccanismi utilizzati nei SO e nelle applicazioni per gestire eventi asincroni
**Interrupt**:
	Evento di origine HW, gestito tramite la *Interrupt Service Routine*, viene utilizzato per la comunicazione tra HW e SW, con una risposta pronta agli eventi HW. Si verifica in modo asincrono ma gestito immediatamente.
**Signal**:
	Evento di origine HW, generati da un processo o dal SO, come gestore di segnali personalizzati o comportamenti predefiniti. Viene utilizzato per la gestione di condizioni eccezionali nelle applicazioni, e viene inviato asincronicamente ma può essere gestito in modo sincrono.

Per deallocare la CPU a fagore dello scheduler ci si affida alla ISR, che *permette allo scheduler di ottenere periodicamente il controllo*. Si utilizza un *interrupt vector* associato a ciascun dispositivo I/O e linea di interrupt e contenente l'indirizzo iniziale di una procedura interna fornita dal SO.

Al verificarsi di un interrupt:
1. L'HW impila il Program Counter e le altre info del processo;
2. L'HW carica il nuovo PC dal vettore degli interrupt;
3. La procedura in linguaggio Assembly salva i registri ed imposta un nuovo stack;
4. Il servizio di interrupt C viene eseguito;
5. Lo scheduler decide quale processo deve essere eseguito successivamente;
6. La procedura C ritorna al codice Assembly
7. La procedura Assembly avvia il nuovo processo
**Ogni volta che si verifica un interrupt lo scheduler ottiene il controllo ed agisce come mediatore** ( Un processo non può cedere CPU ad un altro processo senza passare attraverso lo scheduler).

Tipi di segnali:
- HW-indotti (es. `SIGKILL`);
- SW-indotti (es. `SIGQUIT` o `SIGPIPE`).
Azioni possibili:
- `Term, Ign, Core, Stop, Cont`;
- Azione predefinita per ogni segnale, tipicamente sovrascrivibile;
- I segnali possono essere tipicamente bloccati e le azioni ritardate.
Gestione dei segnali:
- Il processo registra il gestore del segnale;
- Il SO invia il segnale e consente al processo di eseguire l'handler;
- Il contesto di esecuzione corrente deve essere salvato/ripristinato.

## Thread 
Per thread si intende mini processi leggeri associati a dei processi che permettono la multiesecuzione in parallelo efficienti in termine di spazio e tempo, e con una comunicazione ed una sincronizzazione *semplici*.
I thread **risiedono nello stesso spazio degli indirizzi di un singolo processo**, e tutti gli scambi di informazioni avvengono tramite dati condivisi tra i thread. Ogni thread ha il proprio *stack*, i propri *registri HW* ed il proprio *stato*. Ciascun thread può chiamare *qualsiasi* chiamata di sistema supportata dal SO *per conto del processo* a cui appartiene

| **Thread call**        | **Description**                                                |
| ---------------------- | -------------------------------------------------------------- |
| `pthread_cteate`       | Crea un nuovo thread                                           |
| `pthread_exit`         | Termina il thread chiamante                                    |
| `pthread_join`         | Attende "l'uscita" di uno specifico thread                     |
| `pthread_yield`        | Rilascia la CPU per consentire l'esecuzione di un altro thread |
| `pthread_attr_init`    | Crea ed inizializza la struttura di attributi di un thread     |
| `pthread_attr_destroy` | Rimuove la struttura di attributi di un thread                 |


