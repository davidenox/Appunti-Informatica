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