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

**Mittente**:
- Aggiunge il numero di sequenza al pacchetto;
- Saranno sufficienti due numeri di sequenza (0,1).
- Deve controllare se gli ACK/NAK sono danneggiati;
- Il doppio di stati
	- Lo stato deve ricordarsi se il pacchetto corrente ha numero di sequenza 0 o 1.
**Ricevente**:
- Deve controllare se il pacchetto ricevuto è duplicato
	- Lo stato indica se il numero di sequenza previsto è 0 o 1;
- Il ricevente non può sapere se il suo ultimo ACK/NAK è stato ricevuto correttamente dal mittente.

### rdt2.2 - senza NAK

Stessa funzionalità do rdt2.1, utilizzando solo gli ACK. Al posto del NAK, il destinatario invia un ACK per l'ultimo pacchetto ricevuto correttamente, includendo esplicitamente il numero di sequenza del pacchetto con l'ACK. Un ACK duplicato presso il mittente determina la stessa azione del NAK, ovvero *ritrasmettere il pacchetto corrente*.
![[Ch. 3 - Trasporto-1779356023555.png]]

### rdt3.0 - canali con errori e perdite

*Nuova ipotesi*: Il canale sottostante può anche smarrire pacchetti (dati o NAK).
**Approccio**: Il mittente attende un ACK per un tempo 'ragionevole'.
- Ritrasmette se non riceve un ACK in questo periodo;
- Se il pacchetto (o l'ACK) è soltanto in ritardo (non perso):
	- La ritrasmissione sarà duplicata, ma l'uso dei numeri di sequenza già gestisce la problematica;
	- Il destinatario deve specificare il numero di sequenza del pacchetto da riscontrare.
- Utilizzare un *coutdown timer* per interrompere dopo un periodo di tempo ragionevole.

**Mittente**
![[Ch. 3 - Trasporto-1779356372678.png]]
![[Ch. 3 - Trasporto-1779356388597.png]]

**Ricevente**
Come in [[Ch. 3 - Trasporto#rdt2.1 - il mittente gestisce gli ACK/NAK alterati|rdt2.1]].

![[Ch. 3 - Trasporto-1779356469944.png]]
![[Ch. 3 - Trasporto-1779356494977.png]]

**Prestazioni**
$U_{mittente}$: *Utilizzazione* - La frazione di tempo in cui il mittente è stato effettivamente occupato nell'invio di bit sul canale.
>[!note] Esempio
>Collegamento da 1Gbps, ritardo di propagazione 15ms, pacchetti da 1000 byte (8000bit).
>Tempo per trasmettere un pacchetto sul collegamento:$$D_{trasm}=\frac{L}{R}=\frac{8000 bit}{10^9 bit/s}=8\mu s$$ 

![[Ch. 3 - Trasporto-1779357346096.png]]

$$U_{mittente}=\frac{L/R}{RTT+L/R}=\frac{.008}{30.008}=0.000267$$
Il throughput effettivo generato dal mittente: $L/(RTT+L/R)=U_{mittente}\cdot R=267kbps$.
Le prestazioni del protocollo rdt3.0 sono *pessime*, limitando le prestazioni dell'infrastruttura sottostante.

**Funzionamento con pipeline**
*Pipelining*: Il mittente ammette più pacchetti in transito, ancora da notificare.
- L'intervallo dei numeri di sequenza deve essere incrementato;
- Buffering dei pacchetti presso il mittente e, in certi casi, il ricevente.
![[Ch. 3 - Trasporto-1779358258330.png]]

### Protocolli con Pipeline: Go-Back-N 
**Mittente**: 'finestra' contenente fino ad $N$ pacchetti consecutivi trasmessi ma non riscontrati.
- Numero di sequenza a $k$ bit nell'intestazione del pacchetto.![[Ch. 3 - Trasporto-1779358372699.png]]
*Riscontro cumulativo*: $ACK(n)$: Riscontro di tutti i pacchetti con numero di sequenza minore o uguale ad $n$.
- Alla ricezione dell' ACK(n): sposta la finestra in avanti per iniziare da $n+1$.
Timer per il pacchetto più vecchio in transito, $timeout(n)$: ritrasmette il pacchetto n e tutti i pacchetti con i numeri di sequenza più grandi.

Solo ACK: Invia sempre un ACK per un pacchetto ricevuto correttamente con il numero di sequenza più alto *in sequenza*.
- Potrebbe generare ACK duplicati;
- Deve memorizzare solo `rcv_base`.
Alla ricezione di un pacchetto fuori sequenza:
- Può scartarlo (non è salvato) o inserirlo in un buffer: l'implementazione scarta i pacchetti fuori sequenza e deve solo gestire `rcv_base`.
- Rimanda un ACK per il pacchetto con il numero di sequenza più alto in sequenza.
![[Ch. 3 - Trasporto-1779444287468.png]]

*FSM esteso del mittente*:![[Ch. 3 - Trasporto-1779444320893.png]]

*FSM esteso del ricevente*:![[Ch. 3 - Trasporto-1779444351534.png]]
![[Ch. 3 - Trasporto-1779444375332.png]]

### Protocolli con pipeline: Selective Repeat
**Pipelining**: Più pacchetti in transito.
Il ricevente riscontra *individualmente* ciascuno dei pacchetti ricevuti correttamente.
- Buffer dei pacchetti, se necessario, per eventuale consegna in sequenza al livello superiore.
Mittente:
- Mantiene un timer per ogni pacchetto non riscontrato.
	- Timeout: Ritrasmette il singolo pacchetto associato al timeout.
- Mantiene una "finestra" su N numeri di sequenza consecutivi;
	- Limita i pacchetti in pipeline, in 'transito', per rientrare in questa finestra.
![[Ch. 3 - Trasporto-1779445093930.png]]

**Mittente**:
- *Dati dall'alto*: Se nella finestra è disponibile il successivo numero di sequenza, invia il pacchetto.
- *timeout(n)*: Ritrasmette il pacchetto n, riparte il timer.
- *ACK(n)* in `[sendbase, sendbase+N-1]`:
	- Marca il pacchetto n come ricevuto.
	- Se n è il numero di sequenza più piccolo, la base della finestra avanza al successivo numero di sequenza del pacchetto non riscontrato.
**Ricevente**:
*Pacchetto n* in `[rcvbase, rcvbase+N-1]`:
- Invia ACK(n);
- Fuori sequenza: Buffer.
- In sequenza: Consegna (anche i pacchetti bufferizzati in sequenza), la finestra avanza al successivo pacchetto non ancora ricevuto.
*Pacchetto n* in `[rcvbase-N, rcvbase-1]`:
- ACK(n), altrimenti ignora.
![[Ch. 3 - Trasporto-1779445508084.png]]

**Domanda**: Che accade quando arriva `ack2`?
Esempio:
- I numeri di sequenza sono usati ciclicamente.
![[Ch. 3 - Trasporto-1779445660507.png]]

Quale relazione è necessaria tra la dimensione dei numeri di sequenza e la dimensione della finestra per evitare il problema nello scenario (b)?![[Ch. 3 - Trasporto-1779445781019.png|361]]
A causa della mancata ricezione degli ACK la finestra del ricevente può andare avanti rispetto a quella del mittente: Si consideri il caso peggiore associato all'invio di un'intera finestra di pacchetti e la mancata ricezione di tutti gli ACK.
È necessario che lo spazio dei numeri di sequenza sia sufficientemente grande da contenere sia la finestra del mittente sia la finestra del destinatario senza che si sovrappomgano (considerando l'operazione di modulo).
Sia $w$ la dimensione della finestra ed $m$ la dimensione dello spazio dei numeri di sequenza:![[Ch. 3 - Trasporto-1779445950201.png]]
Se i numeri di sequenza sono espressi tramite $k$ bit, allora $m=2^k$, $w\le2^k/2$, cioè $w\le2^{k-1}$

# TCP
pdf16sl3