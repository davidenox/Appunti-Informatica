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
- ![center|500](Pasted%20image%2020260417123259.png)

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

![center|500](Pasted%20image%2020260417163322.png)

### Rendere sicuro TCP

**Socket TCP e UDP**:
- Nessuna cifratura;
- Password inviate in chiaro, senza cifratura, attraverso socket attraversano internet in chiaro.
**Transport Layer Security** (*TLS*):
- Offre connessioni TCP cifrate;
- Controllo di integrità dei dati;
- Autenticazione end-to-end.
![center|500](Pasted%20image%2020260417163746.png)

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
![center|500](Pasted%20image%2020260420115556.png)
- *Host*: Hostname e numero di porta (se assente si assume 80 per http e 443 per https) del server al quale sarà inviata la richiesta. Necessario per il funzionamento delle web cache e del name-based virtual hosting.
- *User-Agent*: Identifica l'applicazione, il SO, il *vendor* e/o la versione dello user-agent che sta effettuando la richiesta.
- *Accept*: Tipi di contenuto compresi dal client.
- *Accept-Language*: Linguaggi naturali preferiti dal client.
- *Accept-Encoding*: Algoritmi di codifica compresi dal client.
- *Connection*: Controlla se la connessione rimarrà aperta al termine dello scambio richiesta/risposta. Il valore *close* indica che la connessione sarà chiusa; altrimenti, una lista non vuota di nomi di header indica che la connessione rimarrà aperta.
![center|500](Pasted%20image%2020260420120413.png)

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
![center|500](Pasted%20image%2020260420142018.png)
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
![center|500](Pasted%20image%2020260420155536.png)

**Commenti**

I cookie possono essere usati per:
- Autorizzazione;
	- ![center|500](Pasted%20image%2020260424120931.png)
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
- Usa TCP per trasferire in modo affidabile i messaggi di posta dal client al server (porta 25).
	- *Trasferimento diretto*: dal server di posta del mittente al server di posta del destinatario.
- Tre fasi di trasferimento:
	- *handshaking*;
	- *trasferimento dei messaggi*;
	- *chiusura*.

### Note finali SMTP

**Confronto con HTTP**
**HTTP**: client pull $v_s$ **SMTP**: client push.
Entrambi hanno un'interazione comando/risposta in ASCII, codici di stato.
- HTTP: Ciascun oggetto è incapsulato nel suo messaggio di risposta;
- SMTP: Più oggetti vengono trasmessi in un unico messaggio.
SMTP usa connessioni persistenti, e richiede che il messaggio sia nel formato ASCII a 7 bit.

**dot-stuffing**
Una riga contenente soltanto un punto segna la fine di un'email. *SMTP* prevede una forma di escaping, il **dot-stuffing**:
- Il client invia due punti anziché uno, quando questo si trova all'inizio di una riga;
- Il servver sostituisce ogni sequenza di due ounti all'inizio di una riga con un solo punto.
## Protocolli di accesso alla posta

![center|500](Pasted%20image%2020260507154430.png)

- **SMTP**: consegna/memorizzazione sul server del destinatario.
- Protocollo di accesso alla posta: ottenere i messaggi dal server.
	- *IMAP*: Internet Mail Access Protocol $[RFC 3501]$:  messaggi memorizzati sul server, IMAP consente di recuperare, cancellare ed archiviare i messaggi memorizzati sul server.
- **HTTP**: gmail, Hotmail, Yahoo!Mail,... consente interfaccia web sopra a SMTP (per l'invio) e IMAP per il recupero delle mail.

# DNS - servizio di directory di Internet

Nasce la necessità di dover mappare indirizzi ip (host e router) con nomi (persone) e viceversa. 

**File *hosts*** - Associa un indirizzo IP a uno o più hostname:
![center|500](Pasted%20image%2020260507155420.png)

*Anni '70*: `HOSTS.TXT`
- Mantenuto dal Network Information Center (NIC) presso lo SRI;
- Reso disponibile su un host designato (attraverso FTP);
- Installatp dagli amministratori di sistema sui singoli nodi
PROBLEMI:
- Crescita del file;
- Traffico generato sull'host dove era pubblicato.

**Domain Name System** - *DNS*
- Database distribuito implementato in una gerarchia di nameserver;
- Protocollo a livello di applicazione che consente agli host ed ai server DNS di comunicare per *risolvere* i nomi (traduzione nome/indirizzo).
	- si noti: funzioni critiche di Internet, implementate come protocollo a livello di applicazione;
	- Complessità nelle parti periferiche della rete.

**Servizi DNS**
-  Traduzione degli Hostname in indirizzi IP;
- Host aliasing
	- nome canonico e alias;
- Mail server aliasing;
- Load distribution
	- Server web replicati: più indirizzi IP corrispondono ad un solo nome.

È opportuno pensare al DNS come ad un *enorme db distribuito*, con miliardi di record, ciascuno semplice. Gestisce molte interrogazioni al giorno:
- Molte più letture che scritture;
- Quasi tutte le transazioni Internet interagiscono col DNS.
È organizzativamente e fisicamente decentralizzato, affidabile e sicuro.
![center|500](Pasted%20image%2020260507163229.png)

**Root name server**:
- Ufficiale, contratto di ultima istanza da parte dei name server che non sono in grado di risolvere il nome - *Fornisce gli indirizzi IP dei TLD server*
**Top-Level Domain server**:
- Si occupano di domini come .com, .org, .net ... e di tutti i domini locali di alto livello come .it, .de, .uk,...
- *Network Solutions*: Gestisce i server TLD per i domini .com e .net
**DNS Server autoritativo**:
- Server DNS propri di ciascuna organizzazione, forniscono i mapping ufficiali da hostname a IP per gli host dell'organizzazione;
- Possono essere mantenuti dall'organizzazione o dal service provider.

Quando l'host effettua una richiesta DNS, la query viene inviata al suo server DNS *locale*:
- Il server DNS locale restituisce una risposta, rispondendo  dalla sua cache locale di coppie $(nome\rightarrow indirizzo)$ inoltrando la richiesta alla gerarchia DNS per la risoluzione.
- Ciascun ISP ha un proprio server DNS locale;
- Il server DNS locale non appartiene strettamente alla gerarchia dei server.

**Interrogazione iterativa**:
- Il server contattato risponde con il nome del server da contattare
	- 'Non conosco questo nome, ma puoi chiederlo a questo server'.
**Interrogazione ricorsiva**:
- Affida il compito di tradurre il nome al server contattato
**Caching ed aggiornamento dei record**:
Una volta che un qualsiasi nameserver impara la mappatura, la mette nella *cache* e restituisce *immediatamente* il mapping nella cache in risposta ad una query.
- Il caching migliora i tempi di risposta;
- Le voci della cache vanno in timeout dopo un certo tempo;
- I server TLD sono in genere memorizzati nella cache sei server dei nomi locali.
Le voci nella cache potrebbero essere *obsolete*:
- Se l'host con nome cambia il suo indirizzo IP, potrebbe non essere conosciuto su Internet fino alla scadenza di tutti i TTL.
	- *traduzione  nome -> indirizzo best-effort*.

## Record DNS
**DNS**: db distribuito che memorizza record di risorsa (RR). 
- Formato RR: `(name, value, type, ttl)`.
	- `type=A`:
		- `name` è l'hostname;
		- `value` è l'IP.
	- `type=NS`:
		- `name` è il dominio (foo.com);
		- `value` è l'hostname dell'authoritative name server per questo dominio.
	- `type=CNAME`:
		- `name` è l'alias di qualche nome canonico;
		- `value` è il nome canonico.
	- `type=MX`:
		- `value` è il nome del server di posta associato a `name`.

Nel DNS non esiste alcuna limitazione che impedisca di associare allo stesso `name` più record di tipi diversi. La principale eccezione è rappresentata dal fatto che non può esserci un record CNAME e nessun altro tipo di record per lo stesso `name`.
**Ogni tipo di record risponde ad una domanda diversa**, posta da client diversi in momenti diversi.

## Messaggi DNS
*Domande* (query) e messaggi di *risposta* (reply), entrambi con lo stesso formato:
Intestazione del messaggio:
- *Identificazione*: numero di 16 bit per la domanda; la risposta alla domanda usa lo stesso numero.
- *Flag*:
	- Domanda o risposta;
	- Richiesta di ricorsione;
	- Ricorsione disponibile;
	- DNS server autoritativo.
![center|500](Pasted%20image%2020260511121315.png)

### Inserire record nel db DNS
Es. Nuova società `nomesocietà`.
- Si registra il nome `nomesocietà.com` presso il *DNS Registrar*, fornendogli il nome e gli indirizzi IP degli authoritative name server.
- Il registrar inserisce due RR nel TLD server .com:
	- `(nomesocietà.com, nds1.nomesocietà.com, NS)`
	- `(dns1.nomesocietà.com, 212.212.212.1, A)`
- Si inserisce localmente nell'authoritative server:
	- Un record A per `www.nomesocietà.com`;
	- Un record MX per `nomesocietà.com`.

### Sicurezza DNS

*Attacchi DDoS*:
- Bombardare di traffico di root server:
	- Finora senza successo;
	- Filtraggio del traffico;
	- I server DNS locali mantengono in cache gli indirizzi IP dei server TLD, consentendo di aggirare i root server;
- Bombardare il server TLD:
	- Potenzialmente più pericoloso.
*Attacco di spoofing*:
- Intercettare le query DNS, restituendo risposte fasulle:
	- DNS cache poisoning;
	- RFC 4033:DNSSEC - servizi di autenticazione.

# Applicazioni P2P

**Architettura Peer-to-Peer**:
- *Nessun* server sempre attivo
- Sistemi periferici arbitrari comunicano direttamente
- I peer richiedono un servizio ad altri peer e forniscono un servizio in cambio ad altri peer
	- *Scalabilità intrinseca - nuovi peer portano nuova capacità di servizio e nuove richieste di servizio*
- I peer sono connessi ad intermittenza e cambiano indirizzo IP
	- Gestione complessa.
![center|493](Pasted%20image%2020260511133503.png)

**File distribution time: Client-Server**

*Trasmissione via server*: deve inviare in sequenza $N$ copie di file:
- Tempo per inviare una copia: $F/u_s$.
- Tempo per inviare $N$ copie: $NF/u_s$.
*Client*: Ogni client deve scaricare una copia del file:
- $d_{min}$= banda di download più bassa.
- tempo di download per il client con banda minima è almento $F/d_{min}$.


Tempo per distribuire F ad N client usando l'approccio client-server: $$D_{C-S}\ge\max\{NF/u_s,F/d_{min}\}$$ - Aumenta linearmente in $N$.

Tempo per distribuire $F$ ad $N$ client usando l'approccio P2P:$$D_{P2P}\ge\max\{F/u_s,F/d_{min}, NF/(u_s+\sum u_i)\}$$
**BitTorrent**
- File diviso in chunk, in genere di 256kB
- I peer nel torrent inviano/ricevono chunk del file.
![[Ch. 2 - Applicazione-1778504968255.png]]

Un peer che entra a far parte del torrent:
- Non ha chunk del file, ma li accumulerà nel tempo da altri peer;
- Si registra con un tracker, ottenendo la lista  di un sottoinsieme dei peer nel torrent, stabilisce una connessione con un sottoinsieme di questi, che sono detti peer "vicini".
- Informa periodicamente il tracker che è ancora nel torrent.
Mentre scarica chunk, un peer invia i chunk già in suo possesso agli altri peer. Un peer può cambiare i peer con cui scambia i chunk, ed una volta che un peer ha acquisito l'intero file, può lasciare il torrent o rimanerci come *seeder*.

**Richiesta di chunk**
- In ogni momento peer diversi hanno sottoinsiemi diversi di chunk
- Periodicamente un peer chiede ai peer vicini l'elenco dei chunk in loro possesso
- Il peer richiede ai peer i chunk mancanti, adottando la strategia del "*rarest first*", uniformando la distribuzione dei chunk, migliora la disponibilità globale e aumenta le possibilità di scambio (maggiore throughput).
- Un peer appen entrato può chiedere un blocco in modo casuale, mentre quando sta per completare il file può adottare la strategia end game e richiedere lo stesso blocco a più peer simultaneamente.

**Invio di chunk**
- Un peer invia i chunk ai quattro peer vicini che attualmente gli inviano i chunk alla *velocità più alta*.
	- Altri peer sono detti 'choked'
	- Rivaluta i primi quattro posti ogni 10 secondi
- Ogni 30 secondi: seleziona in modo causale un vicino ed inizia ad inviare chunk
	- Questo peer è detto "optimistically unchocked"
	- Il nuovo peer scelto può entrare nella top 4.

# Streaming video e reti di distibuzione di contenuti
Il traffico video in streaming è un grande consumatore di larghezza di banda di Internet.
Le sfide sono la scala (raggiungere tanti utenti) e l'eterogeneità ( utenti diversi hanno capacità diverse ). La *soluzione* è un'infrastruttura distribuita a livello di applicazione.

## Video
Per video si intende una sequenza di immagini visualizzate a tasso costante (*frame rate*).
- Immagine digitale: Un array di pixel, in cui ogni pixel è rappresentato da bit.
- Codifica: Utilizzare la ridondanza *all'interno* e *tra* le immagini per ridurre il numero di bit utilizzati per la codifica dell'immagine
	- Spaziale (all'interno di una data immagine);
	- Temporale (da un'immagine all'altra).
