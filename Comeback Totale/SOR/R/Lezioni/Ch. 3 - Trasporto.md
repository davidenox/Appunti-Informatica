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
**Panoramica**
- Connessione punto a punto, singolo mittente e singolo destinatario.
- Flusso di byte affidabile e in sequenza, nessun confine ai messaggi.
- Full duplex data: i dati possono fluire in direzioni opposte allo stesso istante nella stessa connessione.
- Gli ACK sono cumulativi.
- Pipelining: il controllo di flusso e della congestione definiscono la dimensione della finestra.
- Protocollo *orientato alla connessione*:
	- L'handshaking inizializza lo stato del mittente e del destinatario prima di scambiare i dati;
	- Una connessione TCP non definisce un circuito end-to-end che caratterizza le reti a comunicazione di circuito. Le connessioni TCP sono interamente implementate nei sistemi periferici, mentre i commutatori di pacchetto vedono solo i pacchetti di rete in transito.
- Flusso controllato, il mittente non sovraccarica il destinatario.
- Controllo della congestione, il mittente riduce la velocità di invio in funzione della congestione della rete.

**Buffer di invio e ricezione TCP**
![[Ch. 3 - Trasporto-1779701206876.png]]

**MSS**
![[Ch. 3 - Trasporto-1779701264971.png|426]]
	Si vuole che $lunghezza(dati)+lunghezza(H_t)+lunghezza(H_n)\le MTU$.
Altrimenti, il pacchetto IP risultante eccederebbe la MTU del collegamento: un router dovrebbe frammentarlo (IPv4) o scartarlo (IPv6).

**MSS**: Maximum Segment Size, è la quantità massima di dati applicativi nel segmento (intestazione esclusa).
Assumendo che:
- $lunghezza(H_t)=20B$
- $lunghezza(H_n)=20B$ in IPv4 e $lunghezza(H_n)=40B$ in IPv6.
IPv4: MTU minima = $576B\rightarrow$ default MSS $536B$.
IPv6: MTU minima = $1280B\rightarrow$ default MSS $1220B$.
Minore l'MSS, maggiore l'overhead: riducendo il rapporto tra dati e intestazioni, si riduce il throughput end-to-end dal punto di vista dell'applicazione che si può raggiungere.

Un host può determinare il MSS guardando la MTU del collegamento locale, ma ciò non offre garanzie circa altri collegamenti intermedi.
	Valori tipici:
	- $lunghezza(H_t)=20B$
	- $lunghezza(H_n)=20B$ (IPv4)
	- $MTU_{Ethernet}=1500\rightarrow MSS=1460$.
Può essere negoziato durante l'instaurazione della connessione con l'opzione MSS.
- Path MTU Discovery: Scoprire il valore più piccolo della MTU lungo il percorso da mittente a destinatario.
	- L'host mittente riduce la MTU quando riceve il messaggio ICMP inviato da un router che ha scartato un pacchetto perché eccede la MTU del collegamento di uscita.
	- MTU Black Hole: Se i messaggi ICMP sono bloccati, il mittente non aggiorna la MTU e tutti i segmenti possono andare persi. L'host deve adottare tecniche per rilevare questo fatto.
	- Non permette di rilevare l'aumento della MTU.
- *MSS Clamping* nei router: Alcuni router possono aggiornare il valore dell'opzione MSS se determinano che è eccessivo per la MTU del prossimo collegamento.

## Struttura dei segmenti TCP
![[Ch. 3 - Trasporto-1779705273692.png]]

**Numeri di sequenza e ACK di TCP**
![[Ch. 3 - Trasporto-1779711234543.png|285]]
*Numeri di sequenza*:
- 'numero' del primo byte nel segmento nel flusso di byte.
*ACK*:
- Numero di sequenza del prossimo byte atteso dall'altro lato;
- ACK cumulativo;
- RCF 2018: ACK selettivo.
La specifica TCP non specifica come il destinatario i segmenti fuori sequenza, dipende dall'implementazione. Tuttavia, sono spesso inseriti in un buffer lato ricevente.
![[Ch. 3 - Trasporto-1779711567800.png]]

## RTT e Timeout
**RTT**- Tempo di andata e ritorno.
Come impostare il valore del timeout di TCP?
- Più grande di RTT, ma RTT varia!
Due scenari:
- *Troppo piccolo*: timeout prematuro, ritrasmissioni non necessarie.
- *Troppo grande*: reazione lenta alla perdita di segmenti.

*Come stimare RTT?*
- `SampleRTT`: Tempo misurato dalla trasmissione del segmento fino alla ricezione di ACK (ignorando le ritrasmissioni).
- `SampleRTT` varia, quindi occorre una stima più livellata.

`EstimatedRTT=(1-a)*EstimatedRTT+a*SampleRTT`
EWMA: MEdia mobile esponenziale pesata.
- L'influenza dei vecchi campioni decresce esponenzialmente
- I campioni più recenti riflettono meglio la congestione attuale della rete.
- ![[Ch. 3 - Trasporto-1779712477708.png|527]]
- Valore raccomandato $\alpha=0.125$.
![[Ch. 3 - Trasporto-1779712823679.png]]

Intervallo di timeout: `EstimatedRTT`+ un margine di sicurezza:
$TimeoutInterval=EstimatedRTT+4*DevRTT$, 
$DevRTT=(1-\beta)*DevRTT+\beta*|SampleRTT-EstimatedRTT|$.
Tipicamente $\beta=0.25$.

### Mittente TCP
*Evento: Ricevuti dati dall'applicazione*
- Crea un segmento con il numero di sequenza;
	- Il numero di sequenza è il numero del primo byte del segmento nel flusso di byte;
- Avvia il timer, se non già in funzione.
	- Intervallo di scadenza: `TimeoutInterval`.
*Evento: timeout*
- Ritrasmette il segmento che ha causato il timeout
- Riavvia il timer.
*Evento: ACK ricevuto*
- Se riscontra segmenti precedentemente non riscontrati
	- Aggiorna ciò che si sa essere stato riscontrato;
	- Avvia il timer se ci sono altri segmenti ancora non riscontrati.

### Ricevente TCP - Generazione degli ACK
![[Ch. 3 - Trasporto-1779714676667.png]]

**Scenari di ritrasmissione**
![[Ch. 3 - Trasporto-1779715026221.png]]
![[Ch. 3 - Trasporto-1779715042148.png]]

**Ritrasmissione rapida**
Se il mittente riceve 3 ACK addizionali per gli stessi dati, rispedisce il segmento non riscontrato con il più piccolo numero di sequenza.
- È probabile che il segmento non riscontrato sia stato perso, quindi non aspettare il timeout.
La ricezione di 3 ACK duplicati indica 3 segmenti ricevuti dopo un segmento mancante: è probabile che il segmento sia stato perso, quindi ritrasmettere.

![[Ch. 3 - Trasporto-1779716613475.png|339]]
## Controllo di flusso
Che succede se il livello di rete fornisce i dati più velocemente di quanto il livello di applicazione rimuova i dati dai buffer della socket?![[Ch. 3 - Trasporto-1779810087020.png|337]]
![[Ch. 3 - Trasporto-1779810193964.png|337]]

>[!important] Controllo di flusso
>Il destinatario controlla il mittente, in modo che il mittente non ecceda il buffer del destinatario, inviando troppo e troppo velocemente.

Un'entità TCP comunica lo spazio disponibile nel campo `rwnd` (receive window) nell'intestazione TCP.
- `RcvBuffer` dimensione impostata attraverso opzioni della socket (base 4096 byte).
- Molti SO regolano automaticamente `RcvBuffer`.
Il mittente mantiene la variabile `rwnd` che viene usata per limitare i dati non riscontrati.
- Garantisce che il buffer di ricezione non vada in overflow.
Se `rwnd=0` il mittente invia i segmenti di 1B per sondare se il buffer si è svuotato.![[Ch. 3 - Trasporto-1779810487466.png|354]]
## Gestione della connessione TCP
Prima di scambiare i dati, il mittente ed il destinatario si 'stringono la mano', *handshake:
- Accettano di stabilire una connessione;
- Concordano i parametri di connessione;
- Inizializzano variabili e buffer:
![[Ch. 3 - Trasporto-1779810656246.png]]

**Handshake a due vie**
	NON USATO IN TCP
![[Ch. 3 - Trasporto-1779810716578.png|310]]
Funzionerebbe sempre?
- Ritardi variabili;
- Messaggi ritrasmessi a causa della perdita di messaggi;
- Riordino dei messaggi;
- Impossibilità di 'vedere' l'altro lato.
![[Ch. 3 - Trasporto-1779810800916.png|240]]
![[Ch. 3 - Trasporto-1779810831871.png|493]]
![[Ch. 3 - Trasporto-1779810857942.png|251]]

### 3-way handshake

![[Ch. 3 - Trasporto-1779810928976.png]]

Se un host riceve una richiesta di connessione per una porta su cui nessuna socket è in ascolto, l'host invia al mittente un segmento con bit RST uguale ad 1.
La ricezione di un segmento TCP RST informa un potenziale aggressore che la porta incriminata non è usata da alcun processo e che il segmento destinato a quella porta non è stato bloccato da un firewall lungo il percorso.
#### Attacco SYN FLOOD
- L'aggressore invia un segmento TCP SYN ad un server con un IP fasullo;
- Il server alloca ed inizializza le variabili ed i buffer della connessione e risponde inviando un segmento TCP SYNACK alla porta e all'indirizzo IP (fasullo) di origine e transita nello stato SYN_RCVD;
- La rete tenta di consegnare il segmento TCP SYNACK all'IP fasullo, possibilmente raggiungendo un altro host che non c'entra nulla e che non risponderà;
- Il server, nello stato SYN_RCVD, non ricevendo un ACK, eventualmente rilascerà tutte le risorse associate a quella connessione mezza aperta;
- Nel frattempo però l'aggressore è riuscito a consumare delle risorse del server. Inviando numerosi segmenti SYN ad un server target, un aggressore può montare un attacco DoS

**Contromisure 'SYN cookie'**
Alla ricezione del segmento SYN iniziale, il server:
- Calcola l'hash degli indirizzi IP e numeri di porta di origine e di destinazione e di una chiave  segreta, producendo un cookie
	- `cookie= hash(IP sorgente, IP destinazione, porta sorgente, porta destinazione, chiave segreta)`
- usa il cookie con numero di sequenza iniziale da inserire dentro al segmento SYNACK
- non alloca alcuna risorsa né memorizza il cookie
Se il segmento SYN ricevuto in precedenza era legittimo, il client alla ricezione del segmento SYNACK risponde con un segmento ACK, che usa come numero di `Acknowledgment cookie + 1`
Alla ricezione di un segmento ACK, il server può capire che è legato al SYN precedente perché gli basta calcolare `Acknowledgment – 1` per ottenere il cookie. Quindi, riesegue il calcolo del cookie per vedere se ottiene lo stesso valore. Si noti che l'inclusione di una chiave segreta impedisce a un aggressore di creare un cookie valido.

Per evitare attacchi replay, la funzione l'input hash dovrebbe includere una marca temporale, oppure la chiave segreta deve cambiare periodicamente. 
### Chiusura di una connessione TCP
Client e server chiudono ciascuno il proprio lato della connessione inviando il segmento TCP con il bit `FIN=1`, per poi rispondere al FIN ricevuto con un ACK.![[Ch. 3 - Trasporto-1779812200647.png]]

# Principi del controllo della congestione
pdf17sl3