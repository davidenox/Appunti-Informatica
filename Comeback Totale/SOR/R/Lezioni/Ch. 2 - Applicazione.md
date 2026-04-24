# Principi delle applicazioni di rete
## Creare un'applicazione di rete
Scrivere programmi che:
- Girano su sistemi periferici differenti;
- Comunicano attraverso la rete;
Non è necessario scrivere programmi per i dispositivi nel nucleo della rete:
- I dispositivi del nucleo della rete non eseguono applicazioni utente;
- Il confinamento delle applicazioni nei sistemi periferici ha facilitato il rapido sviluppo e la diffusione di una vasta gamma di applicazioni per internet.

**Paradigma client-server**
*Server*:
- Host sempre attivo;
- Indirizzo IP fisso;
- Spesso in datacenter (per scalabilità);
- Onere economico sui fornitori del servizio (per infrastruttura, manutenzione, traffico).
*Client*:
- Contatta, comunica col server;
- Può contattare il server in qualsiasi momento;
- Può avere IP dinamici;
- Non comunica direttamente con gli altri client;

**Architettura peer-to-peer**

- Non c'è un server sempre attivo;
- Coppie arbitrarie di host (peer) comunicano direttamente tra loro;
- I peer richiedono un servizio ad altri peer e forniscono un servizio in cambio di altri peer.
	- *scalabilità intrinseca* - nuovi peer aggiungono capacità di servizio al sistema, sebbene generino anche nuovo carico di lavoro.
- I peer non devono necessariamente essere sempre attivi e cambiano indirizzo IP;

**Processi comunicanti**

**Processo**: Programma in esecuzione su un host.
- All'interno dello stesso host, due processi comunicano usando un approccio interprocesso definito dal SO.
- Processi su host differenti comunicano attraverso lo *scambio di messaggi* usando il servizio del livello di trasporto.
*Processo client*: Dà inizio alla comunicazione, richiedendo il servizio o l'informazione.
*Processo server*: Attende di essere contattato, fornendo il servizio o l'informazione.

**Socket**

Un processo invia/riceve messaggi a/da la sua *socket*. Una socket è analoga ad una porta:
- Il processo mittente fa uscire il messaggio dalla propria socket e presuppone l'esistenza di un'infrastruttura esterna che trasporterà il messaggio, attraverso la rete, alla socket del processo di destinazione.
- ![[Pasted image 20260417123259.png|center|500]]

**Indirizzamento**

Per ricevere messaggi, un processo deve avere un *identificatore*, che coprende sia l'indizzo IP che  i numeri di porta associati al processo in esecuzione su un host. 
Un host ha un indirizzo IP univoco a 32 bit (IPv4) o 128 bit (IPv6).

Un protocollo a livello applicazione definisce:
- *Tipi di messaggi scambiati*;
- *Sintassi dei messaggi*;
- *Semantica dei messaggi*;
- *Regole*;
- *Protocolli di pubblico dominio*;
- *Protocolli proprietari*.

*Quale servizio di trasporto richiede un'applicazione?*
**Perdita di dati**:
- Alcune applicazioni (es. trasferimento file, transazioni web) richiedono un trasferimento 100% affidabile;
- Altre applicazioni (es. multimedia) possono tollerare qualche perdita.
**Sensibilità al fattore tempo**:
- Alcune applicazioni (telefonia via internet, giochi interattivi) richiedono che i ritardi siano bassi per essere "efficaci".
 **Throughput**:
- Alcune applicazioni ('sensibili alla banda') richiedono un'ampiezza di banda minima;
- Altre applicazioni ('elastiche') utilizzano l'ampiezza di banda che si rende disponibile.
**Sicurezza**:
- Riservatezza, integrità dei dati, autenticazione,...

## Servizi dei protocolli di trasporto di internet

>**TCP**
>- *Trasporto affidabile* fra i processi di invio e ricezione: dati consegnati senza errori, perdite e nell'ordine di invio;
>- *Controllo di flusso*: il mittente non vuole sovraccaricare il destinatario;
>- *Controllo della congestione*: 'strozza' il processo di invio quando la rete è sovraccarica;
>- *Orientato alla connessione*: richiesto un setup fra i processi client e server;
>- *NON OFFRE* temporizzazione, garanzie su un'ampiezza di banda minima, sicurezza.

>**UDP**
>- *Trasferimento dati inaffidabile* fra i processi d'invio e ricezione;
>- *NON OFFRE* affidabilità, controllo di flusso, controllo di congestione, temporizzazione, ampiezza di banda minima, sicurezza, né setup della connessione.
>- Offre alle applicazioni maggiore controllo sull'invio dei dati.

![[Pasted image 20260417163322.png|center|500]]

### Rendere sicuro TCP

**Socket TCP e UDP**:
- Nessuna cifratura;
- Password inviate in chiaro, senza cifratura, attraverso socket attraversano internet in chiaro.
**Transport Layer Security** (*TLS*):
- Offre connessioni TCP cifrate;
- Controllo di integrità dei dati;
- Autenticazione end-to-end.
![[Pasted image 20260417163746.png|center|500]]

# Web e HTTP
## Panoramica HTTP
**HTTP**(*HyperText Transfer Protocol*):
- Protocollo a livello applicazione del Web;
- Modello client/server:
	- *client*: browser che richiede, riceve e 'visualizza' gli oggetti del Web;
	- *server*: il server Web che invia oggetti in risposta alle richieste.

*HTTP usa TCP*:
- Il client inizializza la connessione TCP con il server sulla porta 80;
- Il server accetta la connessione TCP dal client;
- Messaggi HTTP scambiati tra browser e server Web;
- Connessione chiusa TCP.

HTTP è un protocollo *stateless*: il server non mantiene informazioni sulle richieste fatte dal client.
Due tipi di connessioni:
1. **Connessioni non persistenti**:
	- Connessione TCP aperta;
	- Una singola coppia richiesta/risposta HTTP per un singolo oggetto;
	- Connessione TCP chiusa.
	- Lo scaricamento di oggetti multipli richiede connessioni multiple.
2. **Connessioni persistenti**:
	- Connessione TCP al server aperta;
	- Più coppie richiesta/risposta HTTP, per trasmettere più oggetti su una singola connessione TCP tra server e client;
	- Connessione TCP chiusa.

### Tempo di risposta

**RTT**: Tempo impiegato da un piccolo pacchetto per andare dal client al server e ritornare al client (include ritardi di elaborazione, accodamento, propagazione).
**Tempo di risposta**(per oggetto): 
- Un RTT per inizializzare la connessione TCP;
- Un RTT perché ritornino la richiesta HTTP ed i primi byte della riposta HTTP;
- Tempo di trasmissione del file/oggetto
*Tempo di risposta per connessioni non persistenti*: $2RTT+$ tempo di trasmissione file.

### Connessioni persistenti
	HTTP 1.1
**Svantaggi connessioni non persistenti**:
- Richiedono 2RTT per oggetto;
- Allocazione di buffer e variabili per *ogni* connessione TCP;
- I browser spesso aprono connessioni TCP parallele per collegare gli oggetti referenziati:
	- Maggiore onere sul server web;
	- Controllo della congestione: throughput inizialmente limitato per nuove connessioni (MA connessioni multiple permettono di aggirare la suddivisione equa della banda tra le applicazioni).
**Connessioni Persistenti**:
- Il server lascia la connessione TCP aperta dopo l'invio di una risposta;
- I successivi messaggi tra gli stessi client/server vengono trasmessi sulla connessione aperta;
- Il client invia le richieste non appena incontra un oggetto referenziato;
- Un solo RTT per tutti gli oggetti referenziati.

### Messaggi HTTP

Due tipi di messaggi HTTP: *richiesta, risposta*.

**Messaggio di richiesta HTTP**:
![[Pasted image 20260420115556.png|center|500]]
- *Host*: Hostname e numero di porta (se assente si assume 80 per http e 443 per https) del server al quale sarà inviata la richiesta. Necessario per il funzionamento delle web cache e del name-based virtual hosting.
- *User-Agent*: Identifica l'applicazione, il SO, il *vendor* e/o la versione dello user-agent che sta effettuando la richiesta.
- *Accept*: Tipi di contenuto compresi dal client.
- *Accept-Language*: Linguaggi naturali preferiti dal client.
- *Accept-Encoding*: Algoritmi di codifica compresi dal client.
- *Connection*: Controlla se la connessione rimarrà aperta al termine dello scambio richiesta/risposta. Il valore *close* indica che la connessione sarà chiusa; altrimenti, una lista non vuota di nomi di header indica che la connessione rimarrà aperta.
![[Pasted image 20260420120413.png|center|500]]

- **Post**:
	- La pagina web spesso include un form per l'input dell'utente;
	- L'input dell'utente viene inviato dal client al server nel corpo dell'entità di un messaggio di richiesta HTTP POST.
- **Head**:
	- Richiede le intestazioni che verrebbero restituite se l'URL specificato fosse richiesto con il metodo HTTP GET.
- **Get** (per inviare dati al server):
	- L'input arriva al server nel campo URL della riga di richiesta (dopo un '?').
- **Put**: 
	- Carica un nuovo file sul server;
	- Sostituisce completamente il file esistente all'URL specificato con il contenuto del corpo dell'entità del messaggio di richiesta HTTP PUT.

**Idempotenza**:
Un'operazione si dice *idempotente* se l'effetto intero sul server di una singola richiesta è lo stesso di quello di più richieste identiche.
- GET, PUT, HEAD sono idempotenti;
- POST no.
Un form può essere implementato usando:
- GET se l'operazione associata al form è idempotente;
- POST se l'operazione associata al form NON è idempotente.
Il concetto di idempotenza è utile per stabilire se un client può *ritentare* in automatico una richiesta in caso di problemi di rete.

**Messaggio di risposta HTTP**:
![[Pasted image 20260420142018.png|center|500]]
- *Date*: Data e ora in cui il messaggio è stato originato;
- *Server*: Descrive il sw usato dal server di origine per gestire la richiesta;
- *Last-Modified*: La data e l'ora in cui il server di origine crede che l'oggetto sia stato modificato l'ultima volta;
- *Accept-Ranges*: Indica il supporto del server ai download parziali: Il valore, se diverso da NONE, indica l'unità che si può usare per esprimere l'intervallo richiesto;
- *Content-Lenght*: Lunghezza in byte del corpo dell'entità inviato al ricevente;
- *Content-Type*: Formato del corpo dell'entità inviato al ricevente.
#### Codici di stato della risposta HTTP
Raggruppati in cinque categorie, differenziate dalla prima cifra:
- 1xx **Informal**:
	- Risposta intermedia per comunicare lo stato di connessione o l'avanzamento della richiesta prima di completare l'azione richiesta ed inviare una risposta finale.
- 2xx **Successful**:
	- La richiesta è stata ricevuta con successo, compresa ed accettata.
- 3xx **Redirect**:
	- Il client deve eseguire ulteriori azioni per soddisfare la richiesta.
- 4xx **Client Error**:
	- La richiesta è sintatticamente scorretta o non può essere soddisfatta.
- 5xx **Server Error**:
	- Il server ha fallito nel soddisfare una richiesta apparentemente valida
### Mantenere stato utente/server: Cookie
L'interazione HTTP GET/risposta è *stateless*: Nessuna nozione di scambio di messaggi HTTP in più fasi per completare una 'transazione' Web. 
- Non è necessario che il client o il server tengano traccia dello "stato" dello scambio in più fasi. 
- Tutte le richieste HTTP sono indipendenti l'una dall'altra.
- Non è necessario che il client né il server siano in grado di 'recuperare' da una transazione quasi completa ma mai completata.
I siti web ed il browser client usano i *cookie* per mantenere lo stato tra le transazioni. Quattro componenti:
1. Una riga di intestazione nel messaggio di risposta HTTP;
2. Una riga di intestazione nel messaggio di richiesta HTTP;
3. Un file cookie mantenuto sul sistema terminale dell'utente e gestito dal browser dell'utente;
4. Un db sul sito.
![[Pasted image 20260420155536.png|center|500]]

**Commenti**

I cookie possono essere usati per:
- Autorizzazione;
	- ![[Pasted image 20260424120931.png|center|500]]
- Carrello degli acquisti;
- Raccomandazioni;
- Stato della sessione dell'utente.
È possibile mantenere lo stato della sessione tramite gli endpoint del protocollo, utilizzando multiple transazioni.

I cookie possono essere usati per:
- Tracciare il comportamento degli utenti su un dato sito (*cookie di prima parte*);
- Tracciare il comportamento degli utenti su più siti (*cookie di terze parti*) senza che l'utente abbia mai scelto di visitare il sito del tracker (!).
- Il tracciamento può essere *invisibile* all'utente

### Web Cache

**Obiettivo**: Soddisfare la richiesta del client senza coinvolgere il server di origine.
- L'utente configura il browser per usare una *web cache* locale.
- Il browser trasmette tutte le richieste HTTP alla cache:
	- *Se* l'oggetto è nella cache: la cache fornisce l'oggetto al client;
	- *Altrimenti*: la cache richiede l'oggetto al server di origine, memorizza l'oggetto ricevuto e lo restituisce infine al client.
In altre parole la cache opera come client per il server di origine e come server per il client originale.

#### GET condizionale

**Obiettivo**: non inviare un oggetto se la cache ha una copia aggiornata dell'oggetto.
- *Client*: specifica la data della copia dell'oggetto nella richiesta HTTP;
- *Server*: la risposta non contiene l'oggetto se la copia nella cache è aggiornata.

Il web caching riduce i tempi di risposta alle richieste dei client, riduce il traffico sul collegamento di accesso a Internet istituzionale, ed in generale riduce il traffico globale su Internet.

#### Note

Il caching può essere effettuato da:
- Una web cache, ossia uno speciale tipo di proxy, cui il browser invia le richieste invece che indirizzarle al server d'origine;
- Oppure, dal browser stesso, che conserva una copia degli oggetti richiesti in precedenza.
In entrambi i casi occorre prestare attenzione al problema dell'aggiornamento degli oggetti.

## HTTP 2

**Obiettivo principale**: Diminuzione del ritardo nelle richieste HTTP a più oggetti.

>**HTTP 1.1** ha introdotto *GET multiple in più pipeline* su una singola connessione TCP:
>- Il server risponde *in ordine* (FCFS) alle richieste GET;
>- Con FCFS oggetti piccoli possono dover aspettare per la trasmissione (*head-of -line* **HOL***blocking*) dietro a uno o più oggetti grandi
>- Il recupero delle perdite (ritrasmissione dei segmenti TCP persi) blocca la trasmissione degli oggetti

>**HTTP 2** maggiore flessibilità del server nell'invio di oggetti al client:
>- metodi, codice di stato, maggior parte dei campi di intestazione inalterati rispetto a HTTP 1.1
>- Introduce una codifica binaria dei messaggi, con supporto alla compressione degli header
>- Ordine di trasmissione degli oggetti richiesti basata su una priorità degli oggetti specificata dal client (non necessariamente FCFS)
>- Invio *push* al client di oggetti aggiuntivi, senza che il client li abbia richiesti
>- Dividere gli oggetti (messaggi) in frame, alternare i frame relativi ad oggetti (messaggi) diversi per mitigare il blocco HOL.

Affrontando l'HOL, HTTP2 vuole permettere di scaricare una pagina conpiù oggetti attraverso una singola connessione TCP:
- Minor overhead sul server;
- Miglior funzionamento del controllo della congestione TCP.

**HTTP 3** aggiunge sicurezza, controllo di errore (per oggetto)  e congestione (più pipelining) su UDP.

# Email, SMTP, IMAP

## Email
Tre componenti principali:
- User Agent;
- Mail Server;
- Simple Mail Transfer Protocol - **SMTP**.

*User-Agent*:
- Detto anche 'mail reader';
- Composizione, editing, lettura dei messaggi;
- I messaggi in uscita/arrivo sono memorizzati sul server;
- es. Outlook

*Mail Servers*:
- `mailbox` (casella di posta) contiene i messaggi in arrivo per l'utente;
- coda di messaggi da trasmettere.
**Protocollo SMTP** tra mail server per inviare messaggi email:
- *client* - mail server trasmittente;
- *server* - mail server ricevente.

**SMTP RFC**

p7sl5