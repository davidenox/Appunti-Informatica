# Servizi e protocolli di trasporto
Forniscono la *comunicazione logica* tra processi applicativi di host differenti. I protocolli di trasporto vengono eseguiti nei sistemi periferici:
- *Lato invio*: Combina il messaggio di un'applicazione con un'intestazione per creare un **segmento** e lo passa al livello di rete
- *Lato ricezione*: Estrae i dati contenuti nel segmento ricevuto dal livello di rete e li passa al livello di applicazione.
I router nel cammino da un host all'altro operano solo sull'intestazione del datagramma, ignorando il segmento incapsulato al suo interno.
Il livello di trasporto è una comunicazione logica tra *processi*, e si basa sui servizi del livello di rete e li potenzia; Il livello di rete è una comunicazione logica tra *host*.

## Protocolli
**UDP**: *User Datagram Protocol*
- Senza connessione;
- Invio di dati attraverso segmenti di lunghezza massiva prestabilita;
- Inaffidabile: perdite, duplicati e consegne senza ordine;
- Estensione di IP: solo comunicazione tra processi e controllo degli errori.
**TCP**: *Transmission Control Protocol*
- Instaurazione di una connessione tra due processi (socket);
- Invio affidabile di un flusso di byte: consegna senza errori (sui bit), senza perdite e nell'ordine originario;
- Controllo di flusso;
- Controllo della congestione.
Servizi *non* disponibili:
- Garanzie su ritardi;
- Garanzie su banda.
# Multiplexing e Demultiplexing

**Multiplexing lato mittente**: Raccogliere dati da varie socket, incapsularli con l'intestazione (utilizzata poi per il demultiplexing).
**Demultiplexing lato ricevente**: Utilizzare le informazioni nell'intestazione per consegnare i dati contenuti nei segmenti ricevuti alla socket corretta.

![[Ch. 3 - Trasporto-1779185990891.png]]

## Come funziona il demultiplexing
L'host riceve i datagrammi IP:
- Ogni datagramma ha un indirizzo IP di origine ed un indirizzo IP di destinazione;
- Ogni datagramma trasporta 1 segmento a livello di trasporto;
- Ogni segmento ha un numero di porta di origine ed un numero di porta di destinazione.
L'host usa **IP e porte** per inviare il segmento alla socket appropriata.
![[Ch. 3 - Trasporto-1779186089676.png]]

**Demultiplexing senza connessione**
1. Quando si crea una socket, si può specificare il numero di porta o, soprattutto lato client, lasciare che il SO le assegni un numero di porta *effimero*.
2. Quando si vuole spedire un messaggio attraverso la socket UDP, si devono specificare IP e porta di estinazione. Il segmento viene passato al livello di rete.
3.  Quando l'implementazione di UDP nell'host di destinazione riceve un segmento UDP:
	- Controlla il numero della porta di destinazione nel segmento;
	- Invia il segmento UDP alla socket con quel numero di porta.
Datagrammi IP/UDP con lo *stesso indirizzo IP e numero di porta di destinazione*, ma IP e/o numeri di porta di origine differenti vengono inviati alla *stessa socket* sull'host ricevente.
Indirizzo IP e numero di porta di origine servono come 'indirizzo di ritorno' per una eventuale risposta.
![[Ch. 3 - Trasporto-1779187913243.png]]

**Demultiplexing orientato alla connessione**

La socket TCP è identificata da *quattro parametri*:
- IP origine;
- Porta di origine;
- IP destinazione;
- Porta di destinazione.
Demux: Il lato ricevente utilizza i quattro valori per inviare il segmento alla socket appropriata.
Un host server crea una *socket passiva* specificando un numero di porta. La socket passiva viene usata per accettare le richieste di connessione, per ciascuna delle quali verrà creata una nuova socket *connessa*.
![[Ch. 3 - Trasporto-1779188720719.png]]

# UDP
Si tratta di un protocollo di trasporto di Internet senza connessioni. È caratterizzato da un servizio di consegna "best effort", i segmenti UDP possono essere perduti, duplicati o consegnati fuori sequenza all'applicazione.
Trattandosi di un protocollo **senza connessione**, non esiste un 'handshaking' tra mittente e destinatario UDP, ed ogni segmento è gestito indipendentemente.
UDP viene utilizzato per applicazioni multimediali (specie in tempo reale), DNS, SNTP, HTTP/3.![[Ch. 3 - Trasporto-1779198751363.png]]

Lato *mittente*:
- Gli viene passato un messaggio applicativo;
- Determina i valori dei campi di intestazione del segmento UDP;
- Crea il segmento e lo passa a IP.
Lato *ricevente*:
- Riceve il segmento da IP;
- Controlla il valore del campo di intestazione UDP `checksum`;
- Estrae il messaggio applicativo;
- Consegna il messaggio alla socket appropriata.

![[Ch. 3 - Trasporto-1779198882252.png]]

**Checksum UDP** - L'obiettivo è *rilevare* gli errori nel segmento trasmesso:
![[Ch. 3 - Trasporto-1779199605940.png]]

**Mittente**:
- Tratta il contenuto del segmento come una sequenza di interi dai 16 bit
- *Checksum*: Complemento a 1 della somma della sequenza di interi a 16 bit;
- Pone il valore della checksum nel campo `checksum` del segmento UDP.
**Ricevente**:
- Calcola la checksum allo stesso modo del mittente;
- Il risultato è costituito da tutti bit 1. Si - nessun errore rilevato; No - errore rilevato.
- Altre implementazion verificano la checksum calcolandola e confrontandola col valore ricevuto.

# Principi trasferimento dati affidabile
![[Ch. 3 - Trasporto-1779200038469.png]]

Per il momento verrà mostrato un canale unidirezionale, per l'invio affidabile di dati da un mittente ad un destinatario. Nonostante questo, però, le due parti devono comunicare in entrambi i versi usando il canale inaffidabile fornito dal livello di rete:![[Ch. 3 - Trasporto-1779200205970.png]]
La complessità del protocollo di trasferimento dati affidabile dipende fortemente dalle caratteristiche del canale inaffidabile.
Il mittente ed il ricevente non conoscono ciascuno lo stato dell'altro.![[Ch. 3 - Trasporto-1779200300100.png]]
## Come iniziare
Verrano sviluppati progressivamente i lati d'invio e ricezione di un protocollo di trasferimento affidabile (Reliable Data Transfer protocol - `rdt`). Verranno poi considerati solo i trasferimenti dati unidirezionali (anche se le info di controllo fluiranno in entrambe le direzioni) e verranno utilizzate macchine a stati finiti per specificare mittente e ricevente.
![[Ch. 3 - Trasporto-1779200513059.png]]

### rdt1.0 - trasferimento affidabile su canale affidabile
Canale sottostante perfettamente affidabile:
- Nessun errore nei bit;
- Nessuna perdita di pacchetti.
FSM *distinto* per mittente e ricevente:
- Il mittente invia i dati nel canale sottostante;
- Il ricevente legge i dati dal canale sottostante.
Si suppone che il ricevente possa gestire i pacchetti secondo il tasso di invio del mittente (problema del *controllo del flusso*).

### rdt2.0 - canale con errori nei bit
Il canale sottostante può invertire (flip) i bit nel pacchetto. Si utilizza `checksum`  per rilevare gli errori nei bit. Come recuperare dagli errori?
- Notifica positiva, `acknowledgements` (*ACKs*): Il ricevente comunica espressamente al mittente che il pacchetto ricevuto è corretto.
- Notifica negativa, `negative acknowledgements`(*NAKs*): Il ricevente comunica espressamente al mittente che il pacchetto contiene errori.
	- Il mittente *ritrasmette* il pacchetto se riceve un NAK.
>[!note] Stop and Wait
>Il mittente attende la notifica di ricezione del pacchetto in corso prima di procedere con l'invio di nuovi dati.

**Specifica delle FSM**
![[Ch. 3 - Trasporto-1779201758020.png]]

Lo 'stato' del destinatario non è noto al mittente a meno che non venga comunicato in qualche modo dal destinatario al mittente - ecco la funzione di un protocollo!

**Difetto**
*Cosa accade se i pacchetti ACK/NAK sono danneggiati?*
- Il mittente non sa cosa sia accaduto;
- Non basta ritrasmettere - possibili duplicati.
*Gestione dei duplicati*:
- Il mittente ritrasmette il pacchetto corrente se ACK/NAK è alterato;
- Il mittente aggiunge un *numero di sequenza* ad ogni pacchetto;
- Il ricevitore scarta il pacchetto duplicato.

### rdt2.1 - il mittente gestisce gli ACK/NAK alterati
![[Ch. 3 - Trasporto-1779202851293.png]]
![[Ch. 3 - Trasporto-1779202878293.png]]

pdf15sl19