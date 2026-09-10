I requisiti essenziali per la memorizzazione **a lungo termine** sono:
- Capacità di *salvare grandi quantità di informazioni*;
- *Persistenza delle informazioni* oltre la vita del processo che le utilizza;
- *Accessibilità* delle info *da più processi* simultaneamente.
Il **File System** offre una soluzione di gestione delle informazioni, che vengono memorizzate tramite l'utilizzo di dischi magnetici o SSD e le operazioni su di esse. Il FS offre un'*astrazione del file*, che risolve il problema di memorizzazione consentendo la *persistenza*, l'accesso multiplo e la gestione di grandi volumi di dati.
Quindi i File System sono un metodo per *organizzare e memorizzare informazioni*. Sono organizzati in **file e directory**.
# File
I File fungono da metodo di *astrazione per salvare e leggere informazioni* su disco nascondendo i dettagli implementativi.
I file vengono identificati tramite **nomi**, che possono variare in base al SO, ed **estensioni**, che tipicamente hanno un significato specifico in base ai programmi che li utilizzano. I file possono avere due diverse strutture:
1. **Sequenza non strutturata di byte**: Il significato dei dati è determinato dai programmi a livello utente e non dal SO
2. **Sequenza di record di lunghezza fissa**: Letture e scritture avvengono a unità di record.
3. **File come albero di record**: Con lunghezze variabili e capacità di ricerche rapide basate su chiavi specifiche. Utilizzati in sistemi mainframe.
E possono dividersi in diversi tipi:
- **File e Directory Normali**:
	- *SO*: Utilizzati in UNIX e Windows;
	- *File Normali*: Contengono info utente e sono la forma più comune;
	- *Directory*: File di sistema per mantenere la struttura del FS
- **File Speciali**:
	- *File Speciali a caratteri*: Usati per modellare dispositivi I/O come terminali e stampanti;
	- *File Speciali a blocchi*: Usati per modellare dischi.

**Tipi di file normali**
- *File ASCII*: Composti da righe di testo visualizzabili e stampabili;
- *File binari*: Non leggibili come testo, hanno una struttura interna conosciuta dai programmi che li utilizzano, come file eseguibili e archivi.

**Accesso ai file**:
- *Accesso sequenziale*: All'inizio unico metodo disponibile.
- *Accesso casuale*: Permette la lettura di byte o record in posizione diverse senza seguire una sequenza.
L'accesso *Casuale* è fondamentale per applicazioni come sistemi di database. I SO inoltre associano ai file ulteriori informazioni dette *attributi* o metadati, che sono cruciali per la protezione o la gestione del file stesso.

## Operazione sui File
- `create` Crea un file senza dati
- `delete` Elimina un file per liberare spazio su disco
- `open` Apre il file per consentire al sistema di caricare in memoria attributi ed indirizzi del disco
- `close` Chiude il file al termine degli accessi per liberare spazio nelle tabelle interne
- `read` Legge i dati di un file
- `write` Scrive dati nel file
- `append` Aggiunge dati alla fine del file
- `seek` Riposiziona il puntatore del file su una posizione specifica, permettendo la lettura/scrittura da quella posizione
- `getAttributes` Legge gli attributi di un file
- `setAttributes` Modifica gli attributi di un file da parte dell'utente
- `rename` Rinomina il file.
Es. Aprire un file e scrivere:
```C
int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC);
char buf[] = "Hi there!";
write(fd, bufm strlen(buf));
close(fd);
```
Dove:
- `O_CREAT` crea il file se non esiste;
- `O_WRONLY` apre il file in modalità scrittura;
- `O_TRUNC` se il file esiste ne tronca il contenuto a dimensione 0.
Sovrascriverà quindi il contenuto di `foo.txt` con "`Hi there!`", o creerà un nuovo file con questo contenuto se `foo.txt` non esiste.

# Directory
Per **directory** si intendono file che tengono traccia degli altri file all'interno del File System. Storicamente si utilizzavano *sistemi di directory a livello singolo* (una directory 'root' che contiene tutti i file). Altrimenti, vengono implementati nei FS *sistemi di directory gerarchici*, dove:
- I file sono organizzati in gruppi correlati mediante directory ramificate
- Struttura ad albero per separare ed organizzare logicamente i file
- Ogni utente può avere una directory principale privata in ambienti condivisi
 Nasce la necessità quindi di definire i percorsi dei file, tramite i **nomi**:
 - *Nomi di percorso Assoluti*: partono dalla directory principali e conducono al file
 - *Nomi di percorso Relativi*: partono dalla directory di lavoro dell'utente

## Operazioni sulle Directory
- `create` Crea una directory vuota
- `delete` Elimina una directory, possibile solo se vuota
- `opendir` Apre una directory per leggerne il contenuto
- `closedir` Chiude la directory dopo la lettura
- `readdir` Restituisce la prossima voce in una directory aperta senza esporre la struttura interna
- `rename` Rinomina la directory

**Gestione dei link ed accessi avanzati**
- `link` crea un 'hard link' collegando un file esistente ad un nuovo percorso, condividendone l'i-node
- `unlink` rimuove una vocec di directory, cancellando il file se è l'unico link
*Link simbolici*: Variante degli 'hard link', possono puntare a file locati su dischi o computer diversi.

# Implementazione del File System
pdf12sl4