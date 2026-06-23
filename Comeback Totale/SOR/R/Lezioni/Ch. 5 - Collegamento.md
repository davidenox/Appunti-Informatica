# Intro
Terminologia:
- Host, router, switch,.. : *Nodi*
- Canali di comunicazione che collegano nodi **adiacenti** lungo il percorso di comunicazione: *Collegamenti* (*link*)
	- Cablati, wireless
	- LAN
- Pacchetto di livello di collegamento: *Frame*, incapsula datagrammi
![[Ch. 5 - Collegamento-1781793916661.png|336|279x286]]

Il **livello di collegamento** ha la responsabilità di trasferire i datagrammi da un nodo a quello **fisicamente adiacente** lungo un collegamento.








![[Ch. 5 - Collegamento-1781794050699.png]]
Il livello di rete può trasferire dati (in genere i segmenti del protocollo a livello di trasporto) da un host ad un altro, all'interno di datagrammi, che viaggiano lungo un percorso attraverso più collegamenti e router intermedi.
Questi ultimi, ricevendo un datagramma che non è loro destinato, ne effettuano l'inoltro verso il nodo successivo.

Il livello di rete si serve del livello di collegamento per trasferire i datagrammi da un nodo a quello adiacente (il successivo lungo il percorso).
![[Ch. 5 - Collegamento-1781794219441.png]]

## Contesto
Datagramma trasferito da *protocolli di collegamenti differenti* su collegamenti differenti:
- Es. WiFi sul primo, Ethernet sul successivo
Ciascun protocollo di collegamento fornisce servizi differenti:
- Es. Può o meno fornire il trasferimento di dati affidabile sul collegamento
## Servizi
![[Ch. 5 - Collegamento-1781794391250.png|399x454]]
**Framing**:
- Incapsula i datagrammi in frame, aggiungendo un'intestazione ed un trailer.
**Accesso al collegamento**:
- Un protocollo che controlla l'accesso al mezzo trasmissivo (MAC, Medium Access Control) se il mezzo trasmissivo è condiviso (e ci sono più mittenti);
- Indirizzi MAC nell'intestazione dei frame per identificare la sorgente e la destinazione (diversa dagli IP).
**Half-Duplex** e **Full-Duplex**:
- Con half-duplex i nodi ad entrambi gli estremi del collegamento possono trasmettere, ma non contemporaneamente - possibile con full duplex.
**Consegna affidabile tra nodi adiacenti**:
- Usato raramente con canali con basso tasso di errore;
- Collegamenti wireless: tassi di errore elevati
	- Correggere l'errore localmente anziché costringere il livello di trasporto o l'applicazione a ritrasmissioni dalla sorgente alla destinazione.
**Controllo di flusso**:
- Velocità tra nodi trasmittente e ricevente adiacenti.
**Rilevazione degli errori**:
- Gli errori sui bit sono causati da attenuazione del segnale e da rumore;
- Il nodo ricevente rileva gli errori.
**Correzione degli errori**: Due approcci:
- ARQ (*Automatic Repeat Request)*: Basato su ritrasmissioni;
- FEC (*Forward Error Correction*): Il ricevente identifica **e corregge** gli errori sui bit senza ritrasmissione.
## Implementazione negli host
Si trova in ogni singolo host. Si tratta del livello di collegamento implementato dall'adattatore di rete (network adapter) o scheda di rete (network interface card - NIC).
- Implementa il livello di collegamento e quello fisico
- Si collega al *bus* di sistema
È una combinazione di HW, SW e Firmware.
![[Ch. 5 - Collegamento-1781795069183.png|300]]
### Adattatore di rete negli host
![[Ch. 5 - Collegamento-1781795097910.png]]
Lato mittente, il controllore:
- Incapsula il datagramma in un frame
- Aggiunge bit di controllo degli errori, implementa il trasferimento di dati affidabile, il controllo del flusso, ecc.
Lato ricevente, il controllore:
- Verifica la presenza di errori e si occupa del trasferimento dati affidabile, del controllo di flusso ecc.
- Estrae il datagramma e lo passa al livello superiore.
La CPU esegue la parte SW del livello di collegamento, relativa a: interazione con l'adattatore di rete, assemblaggio delle informazioni di indirizzamento (lato mittente), gestione di condizioni di errore ed il passaggio del datagramma fino al livello di rete (lato ricevente).
# Rilevazione e correzione degli errori
![[Ch. 5 - Collegamento-1781796202532.png]]
## Controllo di parità
**Singolo bit di parità**
- Rileva un numero *dispari* di errori
![[Ch. 5 - Collegamento-1781796245902.png|300]]
*Il ricevente*: 
- Calcola la parità dei *d* bit ricevuti;
- Lo confronta con il bit di parità ricevuto: se differente, allora è stato rilevato un errore.

Parità bidimensionale:
- Rileva *tutte* le combinazioni di al più 3 errori (compresi errori doppi)
- Rileva un numero dispari di errori
- Rilevazione e **correzione** di errori singoli
![[Ch. 5 - Collegamento-1781796374809.png]]
![[Ch. 5 - Collegamento-1781796405125.png]]
![[Ch. 5 - Collegamento-1781796443817.png]]
![[Ch. 5 - Collegamento-1781796502014.png]]

Il controllo di parità è adatto quando entrambe le seguenti condizioni sono vere:
- La probabilità di errori nei bit è bassa
- Gli errori sono indipendenti
Sotto queste ipotesi, la probabilità di errori multipli è molto bassa: pertato è improbabile che si verifichi un numero pari di errori non rilevati dal bit di parità.

Nella realtà però gli errori tendono a verificarsi in *burst*:
- La probabilità che errori a burst non siano rilevati da un singolo bit di parità può avvicinarsi al 50%
![[Ch. 5 - Collegamento-1781796621176.png]]

## Checksum Internet
**Obiettivo**: Rilevare gli "errori" (*bit alternati*) nel segmento trasmesso.
**Mittente**:
- Tratta il contenuto del segmento come una sequenza di interi a 16 bit (inclusi i campi di intestazione UDP e gli indirizzi IP)
- `checksum`: complemento a 1 della somma (in complemento a 1) della sequenza di interi a 16 bit
- Pone il valore del checksum nel campo `checksum` del segmento UDP
**Ricevente**:
- Calcola la somma in complemento a 1 allo stesso modo del mittente, aggiungendo anche il checksum ricevuto
- Il risultato è costituito da tutti bit 1?
	- Si - nessun errore rilevato
	- No - errore rilevato
- *Oppure*: Complemento a 1 finale e si verifica che sia formata da soli 0.

## Codici di controllo a ridondanza ciclica
**Cyclic Redudancy Check - CRC**
Codifica di rilevamento degli errori più potente.
*D*: Dati da trasmettere (*d* bit);
*G*: Sequenza di $(r+1)$ bit *concordata*, detta *generatore* (standard CRC)
![[Ch. 5 - Collegamento-1781796965405.png]]
**Mittente**: Calcola $r$ bit CRC. *R*, tali che $<D,R>$ sia *divisibile esattamente* da *G*.
- Il ricevente conosce G, divide <D,R> per G. Se il resto è diverso da 0 allora è stato rilevato un errore;
- Può rilevare tutti gli errori a burst di lunghezza inferiore a r+1 bit
- La frazione dei burst più lunghi che può rilevare è approssimativamente $1-2^{-r}$
- Largamente usato in pratica

Tutti i calcoli di CRC sono eseguiti in aritmetica modulo 2 senza riporti nelle addizioni e prestiti nelle sottrazioni:
- Addizione e sottrazione sono la stessa operazione, corrispondente allo XOR bit a bit
	- ![[Ch. 5 - Collegamento-1781797203370.png]]
- La moltiplicazione e la divisione sono calcolate come al soliyo, usando queste definizioni di addizione e sottrazione:
	- ![[Ch. 5 - Collegamento-1781797244977.png|121]]
	- Questa "strana" aritmetica corrisponde al vedere le sequenze di bit come i coefficienti (modulo 2) dei polinomi.
Assumendo che il primo bit sia 1, allora il *grado* del polinomio è uguale al numero di bit -1:
![[Ch. 5 - Collegamento-1781797301807.png]]

**Esempio**
- Il mittente vuole calcolare R tale che $D\cdot 2^r\otimes R=nG$ 
- O equivalentemente $D\cdot 2^r=nG\otimes R$
- Che ci dice che:
	- Se dividiamo $D\cdot 2^r$ per G il resto è precisamente R:$$R=resto[\frac{D\cdot 2^r}{G}]\rightarrow\text{Algoritmo per calcolare } R$$
![[Ch. 5 - Collegamento-1781797526768.png|296]]
### Polinomio di errore e scelta del generatore
- Il mittente invia $T=D\cdot 2^r\otimes R$
- Il ricevente riceve $T'=T\otimes E=T+E$ (usando addizione CRC)
	- Dove E è una sequenza di bit (ovvero un polinomio) i cui bit a 1 indicano dove si è verificato un errore
- Siccome T è divisibile per G, T' sarà divisibile per G se e solo se E è divisibile per G
- Quindi G *deve essere scelto in modo tale che NON divida i polinomi di errore*.
In pratica, si cerca di definire G in modo che rilevi diversi tipi di errore.

Se G ha un numero pari di bit a 1, allora è in grado di rilevare qualsiasi numero dispari di errore. Perché?
- $E(x)$ il polinomio che rappresenta l'errore (con numero **dispari** di bit a 1)
- $G(x)$ il polinomio generatore (con numero **pari** di bit a 1)
Supponiamo per assurdo che l'errore passi inosservato, cioé che $E(x)=Q(x)\cdot G(x)$ per un qualche polinomio $Q(x)$.
Valutiamo entrambi i lati in $x=1$:
- Poiché $E(x)$ contiene un numero dispari di bit 1, si ha $E(1)=1$
- Poiché $G(x)$ contiene un numero pari di bit  a 1, si ha $G(1)=0$
Ne segue che $E(1)=Q(1)\cdot G(1)\implies 1=Q(1)\cdot0$, che è una contraddizione.
Quindi $E(x)$ **non** è divisibile per $G(x)$ e pertanto l'errore sarà sicuramente rilevato.

Se G ha almeno due bit a 1, esso è in grado di rilevare qualunque errore singolo. Perché?
Un errore singolo è espresso dal polinomio $x^k$ (cioè $1\space\underbrace{000..0}_{k}$), che è divisibile solo dai polinomi $x^i$ per $i\le k$, essendo $x^k=x^{k-i}\cdot x^i$.

# Protocolli di accesso multiplo
Due tipi di collegamento:
- *Punto a punto*: Un trasmittente ad un'estremità del collegamento ed un unico ricevente all'altra estremità
	- Collegamento punto a punto tra host e switch Ethernet
	- Protocollo PPP per accesso dial-up
- **Broadcast**: Un canale (mezzo fisico) broadcast *condiviso* tra più nodi trasmittenti e riceventi, ciascun frame viene ricevuto da tutti i nodi
	- Ethernet con cavo condiviso
	- WLAN, 4G/5G, satellite

Singolo canale broadcast condiviso, due o più trasmissioni simultanee dai nodi creano *interferenza*. **Collisione** se un nodo riceve due o più segnali nello stesso istante.
>[!important] Protocollo di accesso multiplo
>- Algoritmo distribuito che determina come i nodi condividono il canale, determina quando i nodi possono trasmettere
>- La comunicazione sulla condivisione del canale deve utilizzare il canale stesso
>	- Nessun canale fuori banda per il coordinamento

**Protocollo ideale**:
*Dato*: Un canale ad accesso multiplo (MAC) con velocità di R bps
*Desiderata*:
1. Quando un solo nodo vuole trasmettere, può inviare a velocità R
2. Quando M nodi vogliono trasmettere, ciascuna trasmissione può variare ad una velocità medi adi R/M
3. Totalmente decentralizzato:
	- Nessun nodo speciale che coordina le trasmissioni (il cui fallimento potrebbe bloccare il sistema);
	- Nessuna sincronizzazione degli orologi, slot temporali, ecc..
4. Semplice

## Tassonomia
Tre ampie classi:
- **A suddivisione del canale** (Channel Partitioning)
	- Divide il canale in "pezzi" più piccoli (slot temporali, bande di frequenza, codici)
	- Assegna un pezzo a un nodo per uso esclusivo, eliminando le collisioni
- **Ad accesso casuale** (Random Access)
	- Canale non diviso, permette le collisioni
	- Recupera dalle collisioni attraverso ritrasmissioni
- **A rotazione** ("Taking Turns")
	- I nodi si avvicendano a turno, ma i nodi con una quantità maggiore di materiale da inviare possono fare turni più lunghi

### Protocolli a suddivisione del canale: TDMA
**TDMA: Time Division Multiple Access** (accesso multiplo a divisione di tempo)
- Accesso al canale in "intervalli di tempo"
- Ciascun intervallo è ulteriormente suddiviso in N slot temporali (time slot), ciascuno assegnato ad uno degli N nodi
- La durata di uno slot temporale è in genere tale da consentire la trasmissione di un pacchetto a livello di collegamento
- Gli slot inutilizzati rimangono inutilizzati (idle)
- Es. LAN con 6 nodi, 1-3-4 hanno pacchetti da inviare, 2-5-6 sono inattivi: ![[Ch. 5 - Collegamento-1781881004288.png]]
- Nel proprio turno, un nodo trasmette a R bps, ma potendo farlo solo in 1/N della durata dell'intervallo temporale, la sua velocità media è R/N a prescindere dal fatto che ci siano altri nodi che vogliono trasmettere sul canale
- Un nodo che ha dati da trasmettere deve attendere il proprio turno

Lo spettro del canale è diviso in bande di frequenza, in cui a ciascun nodo viene assegnata una banda di frequenza fissa. Il tempo di trasmissione non utilizzato nelle bande di frequenza resta inutilizzato, Es:
LAN con 6 nodi, 1-3-4 hanno pacchetti da inviare, le bande 2-5-6 sono inutilizzate
![[Ch. 5 - Collegamento-1781881266579.png]]
- Un nodo può *trasmettere nella propria banda di frequenze* appena ha dati da inviare, senza dover attendere turni

### Protocolli ad accesso casuale
Quando un nodo ha un pacchetto da inviare, lo trasmette alla massima velocità consentita dal canale (R bps), e non c'è alcun coordinamento "a priori" tra i nodi. Ciò vuol dire che se due o più nodi stanno trasmettendo nello stesso momento accade una *collisione*.
Un **protocollo ad accesso casuale** specifica:
- Come rilevare le collisioni
- Come recuperare da esse
Es: ALOHA, slotted ALOHA, CSMA, CSMA/CD,CSMA/CA

#### Slotted ALOHA
![[Ch. 5 - Collegamento-1781881622907.png]]
*Assunzioni*:
- Tutti i frame hanno la stessa dimensione (L bit)
- Tempo suddiviso in slot temporali uguali (equivalenti al tempo per trasmettere un frame, L/R)
- I nodi cominciano la trasmissione soltanto all'inizio degli slot
- I nodi sono sincronizzati
- Se 2 o più nodi trasmettono nello stesso slot, tutti i nodi rilevano la collisione prima de termine dello slot
**Operazioni**:
Quando un nodo ha un nuovo frame da spedire, lo *trasmette per intero* all'inizio dello slot successivo.
- *Se non si verifica una collisione* il nodo puù inviare un nuovo frame nello slot successivo
- *Se si verifica una collisione* il nodo ritrasmette il frame in ciascuno slot successivo con probabilità $p$  finché non ha successo
	- $p$ - randomizzazione, perché?
![[Ch. 5 - Collegamento-1781881827022.png]]
Pro:
- Un singolo nodo attivo (con dati da trasmettere) può trasmettere continuamente alla massima velocità del canale
- Altamente decentralizzato: solo gli slot nei nodi devono essere sincronizzati
- Semplice
Contro:
- Collisioni, spreco di slot
- Slot inutilizzati per causa probabilistica
- I nodi potrebbero essere in grado di rilevare la collisione in meno del tempo necessario per trasmettere il pacchetto
- Sincronizzazione degli orologi

##### Efficienza
**Efficienza**: Frazione a lungo termine di slot riusciti (molti nodi, tutti con molti frame da inviare). 
Si supponga: N nodi con molti frame da inviare, ciascuno trasmette nello slot con probabilità p (non distinguendo ritrasmissioni di frame o nuove trasmissioni): il numero di nodi che trasmettono in uno slot è una variabile aleatoria binomiale $B(N,p)$
- Prob. che un dato nodo ha successo in uno slot $=p(1-p)^{N-1}$
- Prob. che un nodo qualunque abbia successo $=Np(1-p)^{n-1}$
- Efficienza massima: Trovare $p^*$ che massimizza $Np(1-p)^{N-1}$
- Per molti nodi, calcolare il limite di $Np^*(1-p^*)^{N-1}$ per N che tende all'infinito, si ottiene: **Efficienza massima** $=1/e=.37$
- **AL MASSIMO** il canale è usato per la trasmissione utile solo per il 37% del tempo.
#### ALOHA puro
'Unslotted' ALOHA: più semplice, nessuna sincronizzazione.
- Appena arriva un nuovo frame: lo trasmette immediatamente e integralmente
- Se la trasmissione va in collisione (lo rileva per esempio a causa dell'assenza di ACK): ritrasmette il frame immediatamente (dopo averne completato la trasmissione) con probabilità p, altrimenti attende il tempo di trasmissione di un frame e ripete il processo di attesa casuale, finché non ha successo.
La probabilità di collisione aumenta in assenza di sincronizzazione:
- Il frame inviato a $t_0$ collide con altri frame inviati in $[t_0-1,t_0+1]$ ![[Ch. 5 - Collegamento-1781885388437.png]]
Efficienza massima del protocollo ALOHA puro: 18%.

#### CSMA - Accesso multiplo con rilevamento della portante
**CSMA**: Ascolta prima di ritrasmettere (rilevamento della portante, *carrier sense*):
- *Se percepisce il canale inattivo*: Trasmette l'intero frame;
- *Se percepisce il canale occupato*: Differisce la trasmissione.
	- Analogia umana: non interrompere gli altri
**CSMA/CD**: CSMA con *rilevamento della collisione* (collision detection):
- Collisioni rilevate in breve tempo;
- Le trasmissioni in collisione vengono interrotte, riducendo gli sprechi di canale;
- Rilevamento delle collisioni facile con il cavo, difficile con il wireless
	- Analogia umana: se qualcun altro parla con te, smetti di parlare

##### CSMA: Collisioni
Le collisioni possono *ancora* verificarsi con il rilevamento della portante:
- Il **ritardo di propagazione** significa che due nodi potrebbero non sentire la trasmissione appena avviata dall'altro
**Collisione**: spreco dell'intero tempo di trasmissione dei pacchetti:
- La distanza ed il ritardo di progragazione giocano un ruolo importante nel determinare la probabilità di collisione.
![[Ch. 5 - Collegamento-1782120235429.png|300]]CSMA/CD riduce la quantità di tempo sprecato nelle collisioni (trasmissione interrotta su rilevamento di collisione)![[Ch. 5 - Collegamento-1782120347053.png|300]]
##### Algoritmo CSMA/CD di Ethernet
1. Ethernet riceve un datagramma dal livello di rete, crea un frame;
2. Se Ethernet ascolta il canale:
	- *Inutilizzato* (idle): Avvia la trasmissione del frame;
	- *Occupato* (busy): Aspetta finché il canale è libero, poi trasmette.
3. Se l'intero frame viene trasmesso senza collisioni: FATTO
4. Se durante l'invio viene rilevata un'altra trasmissione: Interrompere, inviare il segnale di disturbo (*jam*) 
5. Dopo aver interrotto, entra nella *binary exponential backoff*:
	- Dopo la m-esima collisione, scegli K casualmente tra $\{0,1,2,...,2^m-1\}$. Ethernet aspetta il tempo di trasmissione di K512bit, ritorna allo step 2
	- Più collisioni: maggiore intervallo di backoff (ma $m$ viene limitato a 10).

###### Efficienza
$d_{prop}=$ massimo ritardo di propagazione tra due schede di rete
$d_{trasm}=$ tempo necessario per trasmettere un frame di dimensione massima
$$efficienza=\frac{1}{1+5d_{prop}/d_{trasm}}.$$
L'efficienza tende a 1 se:
- $d_{prop}$ tende a 0 (trasmissione interrotta subito il presenza di collisioni, evitando sprechi)
- $d_{trasm}$ tende ad infinito (un frame, appropriatosi nel canale, lo impegna a lungo)
Prestazioni migliori di ALOHA: semplice, economico, decentralizzato.
ESEMPIO
$d_{prop}=256$ bit time, $d_{trasm}=12.144$ bit time $$efficienza=\frac{1}{1+5d_{prop}/d_{trasm}}\approx90\%$$
### Protocolli a rotazione
![[Ch. 5 - Collegamento-1782121341215.png|269]]
**Polling**: Il controllore centralizzato "invita" (round-robin) gli altri nodi a trasmettere a loro volta (fino ad un massimo di frame per turno).
- Il controllore determina che il client ha finito osservando la mancanza di segnale
- Elimina collisioni e slot inutilizzati
Problemi:
- *Ritardo di polling*: Il tempo impiegato per notificare a un nodo il permesso di trasmettere $\implies$ anche in presenza di un solo nodo attivo, il controllore deve contattare periodicamente tutti gli altri nodi, determinando un throughput effettivo minore di $R$
- *Singolo punto di rottura* (master)
Il Bluetooth usa il polling

**Token passing**: Frame di controllo detto **token** passato esplicitamente da un nodo al successivo, sequenzialmente.![[Ch. 5 - Collegamento-1782121736034.png|240]]
- Trasmette mentre possiede il token (entro un massimo accordato)
Problemi:
- *Overhead associato al token*
- *Latenza*
- *Singolo punto di rottura* (token)
Usato in FDDI e token ring.


### Rete di accesso via cavo
	FDM, TDM, allocazione centralizzata e accesso casuale

![[Ch. 5 - Collegamento-1782121876371.png]]
- **Molteplici** canali FDM downstream (broadcast): fino a 1.6Gbps/canale
	- Un solo CMTS trasmette nei canali -> nessun problema di accesso multiplo
- **Molteplici** canali upstream (fino a 1Gbps/canale)
	- **Accesso multiplo**: tutti gli utenti si contendono (accesso casuale) determinati slot temporali del canale upstream; agli altri vengono assegnati TDM

![[Ch. 5 - Collegamento-1782122155107.png]]
**DOCSIS**: Specifiche di interfaccia del servizio dati via cavo
- FDM su canali di frequenze upstream e downstream
- TDM upstream: alcuni slot assegnati, alcuni sono contesi
	- Frame MAP in downstream: assegna i minislot in upstream
	- Richieste di frame in upstream (e dati) trasmessi con accesso casuale (binary backoff) in slot selezionati

# LAN
**Local Area Network**: Copre un'area limitata come un'abitazione, una scuola, un ufficio o un edificio. Due tecnologie:
- Ethernet: IEEE 802.3
- WiFi: IEEE 802.11

**Indirizzi MAC**
Indirizzi IP a 32 bit (128 in IPv6):
- Indirizzi *a livello di rete* per le interfacce
- Usati per l'inoltro a livello 3 (livello di rete)
Indirizzi MAC ( o LAN o Fisici o Ethernet):
- Funzione: *Utilizzati "localmente" per portare i frame da un'interfaccia a un'altra fisicamente connessa (stessa sottorete)*.
- Indirizzo MAC a 48 bit (per la maggior parte delle LAN) memorizzato nella ROM della NIC, a volte impostabile via software.
Ciascuna interfaccia in una LAN:
- Ha un indirizzo *MAC* univoco
- Ha un indirizzo IP univoco
![[Ch. 5 - Collegamento-1782130198337.png|center|285]]
- Allocazione degli indirizzi MAC gestita dall'IEEE
- I produttori (di schede di rete) comprano porzioni dello spazio di indirizzi MAC (per assicurare l'unicità)
Analogia:
- Indirizzi MAC: come il codice fiscale
- Indirizzo IP: come l'indirizzo postale
Indirizzo MAC (piatto): portabilità
- È possibile spostare un'interfaccia da una LAN ad un'altra
- Indirizzo IP (gerarchico) *non* portabile: dipende dalla sottorete IP alla quale il nodo è connesso.
## Protocollo per la risoluzione degli indirizzi (ARP)
	Address Resolution Protocol
*Domanda*: Come determinare l'indirizzo MAC di un'interfaccia conoscendo il suo indirizzo IP?
![[Ch. 5 - Collegamento-1782132424622.png|348]]**Tabella ARP**:
Ogni nodo IP (host, router) sulla LAN ha una tabella (una per ciascuna interfaccia)
- Corrispondenza tra gli indirizzi IP e MAC per *alcuni nodi* sulla LAN:
	- `<indirizzo IP; indirizzo MAC, TTL>`
- TTL (Time To Live): tempo dopo il quale la mappatura degli indirizzi sarà dimenticata.
![[Ch. 5 - Collegamento-1782134246931.png]]
![[Ch. 5 - Collegamento-1782134258898.png]]
![[Ch. 5 - Collegamento-1782134297687.png]]

### ARP Spoofing o ARP Poisoning
- Un attaccante invia in una LAN risposte ARP contraffatte, inducendo l'associazione di un indirizzo IP a un certo indirizzo MAC
- Il protocollo ARP è senza stato e un nodo (host o router) aggiorna la proria ARP appena viene ricevuta una risposta ARP (a prescindere che questa faccia seguito ad una effettiva richiesta).
Alcuni usi:
- `denial-of-service` (DoS): Associare diversi indirizzi IP allo stesso indirizzo MAC per sovraccaricarlo di traffico;
- `man-in-the-middle` (MITM): L'attaccante associa il proprio indirizzo MAC all'indirizzo IP di un altro nodo, in modo da intercettare (e magari modificare) il traffico destinato a quest'ultimo, per poi re-inoltrarglielo.

### Come inviare un datagramma a un nodo esterno alla sottorete
Scenario dettagliato: *invio di un datagramma da A a B passando per R*.
- Attenzione sugli indirizzi - a livello IP (datagramma) e MAC (frame)
Assunzioni:
- A conosce l'indirizzo IP di B
- A conosce l'indirizzo IP dell'interfaccia di R nella propria sottorete (DHCP)
- A conosce l'indirizzo MAC dell'interfaccia di R nella propria sottorete (ARP)
![[Ch. 5 - Collegamento-1782135501907.png]]

- A crea un datagramma IP con sorgente A e destinazione B
- A crea un frame a livello di collegamento contenente il datagramma IP da A a B
	- La destinazione del frame è l'indirizzo MAC di R
![[Ch. 5 - Collegamento-1782135978108.png]]
- Frame inviato da A a R
- Frame ricevuto da R, datagramma, passato in alto a IP
![[Ch. 5 - Collegamento-1782228750515.png]]

- R determina l'interfaccia di uscita, passa il datagramma con sorgente IP A e destinazione IP B al livello di collegamento
- R crea il frame a livello di collegamento contenente il datagramma IP da A a B. Indirizzo di destinazione del frame: indirizzo MAC di B
![[Ch. 5 - Collegamento-1782228851720.png]]

![[Ch. 5 - Collegamento-1782229213150.png]]

- B riceve il frame, il datagramma IP destinato a sé
- B passa il datagramma in alto nella pila protocollare a IP
## Ethernet
Tecnologia dominante per le LAN cablate.

**Topologia fisica**:
- *Bus*: tutti i nodi sono nello stesso dominio di collisione
- *Topologia a stella con hub*: I nodi sono interconnessi da un hub (dispositivo fisico che rigenera i segnali ricevuti su una interfaccia e li ritrasmette su tutte le altre), quindi tutti i nodi sono nello stesso dominio di collisione
- *Commutata*(Switched): Usata oggi.
	- **Switch** di livello 2 attivo al centro
	- Ogni "spoke" esegue un protocollo Ethernet separato (no collisioni).
### Struttura del frame Ethernet
L'interfaccia trasmittente incapsula il datagramma IP in *frame Ethernet*.
![[Ch. 5 - Collegamento-1782229590473.png]]
**Preambolo**:
- Usato per "risvegliare" le schede di rete dei riceventi e sincronizzare i loro clock con quello del trasmittente
- 7 byte di `10101010` seguiti da un bite di `10101011`
**Indirizzi**: Indirizzi sorgente e destinazione a 6 byte:
- Se l'adattatore riceve un frame con un indirizzo di destinazione corrispondente o con un indirizzo di broadcast (es. pacchetto ARP), passa i dati nel frame al protocollo di livello superiore
- Altrimenti, l'adattatore scarta il frame
**Tipo**: Indica un protocollo di livello superiore (2 byte)
- *Principalmente IP*, ma sono possibili anche altri protocolli a livello di rete
- Utilizzato per demultiplexare sul ricevitore
**CRC**: Controllo di ridondanza ciclica presso il ricevitore(4 byte)
- Errore rilevato: frame scartato
**Payload**: Dati passati al protocollo di livello superiore
- Minimo 46 byte: se più piccolo, deve essere aggiunto del padding; perciò è importante che il protocollo di livello superiore preveda un meccanismo per stabilire la reale dimensoine dei dati
- Massimo 1500 byte (Salvo estensioni) -> MTU
La **fine del frame** è determinata a livello fisico dall'assenza di transizioni sulla linea.
Escludendo il preambolo, la **dimensione di un frame** è compresa tra 64 e 1518 byte. In Gigabit Ethernet lo slot time è in realtà di 512 byte: frame più piccoli richiedono l'aggiunta di padding.

**Ethernet non affidabile e senza connessione**
- *Senza connessione*: Nessun handshake tra le NIC mittente e ricevente
- *Non affidabile*: La NIC ricevente non invia ACK o NAK alla NIC mittente
	- I dati nei frame scartati vengono recuperati solo se il mittente iniziale utilizza un trasferimento dati affidabile di livello superiore (es. TCP), altrimenti vanno persi
- Protocollo MAC di Ethernet: "Unslotted" *CSMA/CD con binary backoff*.

## Switch
Dispositivo **a livello di collegamento**: Ha un ruolo *attivo*:
- Memorizza e inoltra (`store-and-forward`) frame Ethernet
- Esamina l'indirizzo MAC di destinazione del frame in arrivo, inoltra *selettivamente* il frame in uno o più collegamenti di uscita quando il frame deve essere inoltrato in un segmento, usa CSMA/CD per accedere al segmento
1. *Trasparente*: Gli host sono inconsapevoli della presenza degli switch.
2. *Collegamenti eterogenei*: I collegamenti possono operare a velocità diverse ed usare mezzi trasmissivi diversi; utile per evolvere la rete in maniera incrementale.
3. *Plug-n-Play, autoapprendimento*: Non è necessario configurare gli switch.

![[Ch. 5 - Collegamento-1782231268754.png|381]]
- Gli host hanno connessioni dedicate, dirette con lo switch
- Lo switch "bufferizza" i pacchetti
- Il protocollo Ethernet è utilizzato su ciascun collegamento, così:
	- full-duplex: una singola coppia di nodi alle estremità del collegamento che possono trasmettere simultaneamente senza collisioni
	- half-duplex: Il singolo collegamento half-duplex è un dominio di collisione a sé
- **Switching**: `A-to-A'` e `B-to-B'` possono trasmettere simultaneamente senza collisioni
	- Maggiore banda aggregata rispetto ad un hub che permette una sola trasmissione per volta.
- In differenza `A-to-A'` e `C-to-A'` *non* possono accadere simultaneamente
### Tabella commutazione switch
Ciascuno switch ha una **tabella di commutazione** (*switch table*), ciascuna voce;
- `(indirizzo mac del nodo, interfaccia che conduce al nodo, timestamp)`
- Da non confondere con la tabella ARP in host e router
pdf30sl33