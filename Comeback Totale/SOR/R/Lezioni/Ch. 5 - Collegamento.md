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

pdf29sl2