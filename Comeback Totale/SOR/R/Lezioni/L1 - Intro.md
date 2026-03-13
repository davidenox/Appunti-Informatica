# Internet
Inteso come miliardi di *dispositivi* di calcolo connessi: 
- **host**: sistema periferico (end system);
- Ospitano ed eseguono le applicazioni di rete nella periferica di internet (**edge**).
*Commutatori di pacchetto* (packet switches): inoltrano i pacchetti:
- router, switch, ...
*Reti di collegamenti* (commutation link):
- Fibra ottica, rame, radio, satellite;
- Velocità di trasmissione: *ampiezza di banda* "bandwidth".
*Reti*:
- Collezione di host, commutatori di pacchetto, collegamenti: gestiti da un'organizzazione.

I *protocolli* sono ovunque, e controllano l'invio e la ricezione dei messaggi (es. HTTP, streaming video, Skype, TCP, IP, WiFo, 4/5G, Ethernet).
**Standard di internet**:
- *RCF*: Request ofr Comments;
- *IETF*: Internet Engineering Task Force.

## Servizi

Si parla di un'*infrastruttura* che fornisce servizi alle applicazioni, e che fornisce un'*interfaccia di programmazione* alle applicazioni distribuite:
- 'hook' che consentono alle applicazioni mittente/destinataria di "connettersi", usando il servizio di trasporto di internet.

## Protocolli

Un **protocollo** definisce il *formato* e l'*ordine* dei messaggi scambiati tra due o più entità in comunicazione, così come le *azioni intraprese* in fase di trasmissione e/o ricezione di un messaggio o di un altro evento.

![[Pasted image 20260313112022.png|center|500]]

# Host, reti di accesso, mezzi trasmissivi

>Ai confini della rete si trovano **host**:
- *Client* richiedono servizi;
- *Server* erogano servizi.
I server sono spesso locati nei data center.

>[!note] Cloud Computing
>Il **Cloud Computing** consiste nella distribuzione on-demand delle risorse IT tramite Internet, con una tariffazione basata sul consumo. Piuttosto che acquistare, possedere e mantenere i data center ed i server fisici, è possibile accedere a servizi tecnologici, quali *capacità di calcolo*, *archiviazione* e *database*, sulla base delle proprie necessità affidandosi ad un fornitore cloud (es. Amazon Web Services - AWS).

> Reti di accesso, mezzi trasmissivi: collegamenti **cablati** e **wireless**.

*Domanda*: Come collegare sistemi periferici ed edge router?
- Reti di accesso residenziali;
- Reti di accesso aziendali (scuole, aziende);
- Reti di accesso mobile(WiFi, 4G/5G).

È importante guardare la *velocità di trasmissione della rete di accesso* e l'*accesso dedicato e condiviso tra gli utenti*.

## DSL

![[Pasted image 20260313114835.png|center|500]]

Utilizza la linea telefonica *esistente* verso il DSLAM nella centrale locale:
- I dati sulla linea DSL vanno su internet;
- La voce sulla linea DSL va sulla rete telefonica.
*Asimmetrica*: Le velocità effettive sono inferiori per limitazioni del provider, distanza, qualità del materiale ed interferenze.
Concretizzata in diversi standard, quali ADSL e VDSL.

## Reti di accesso: FTTx
- **FTTH** - Fiber to the home;
- **FTTB** - Fiber to the basement;
- **FTTC o FTTS** - Fiber to the cabinet/street;
- **FTTN** - Fiber to the node;
- **FTTW o FTTR** Fiber to the wireless/radio.
![[Pasted image 20260313120143.png|center|500]]

>**FTTH**:
>- Fibra diretta: una singola fibra collega una centrale locale ad un'abitazione.
>- Alternativa comune: ciascuna fibra uscente dalla centrale locale viene condivisa da più utenti e solo in prossimità di questi ultimi viene divisa in più fibre, una per ogni utente.
>- Due architetture: 
>	- *Active Optical Network*(**AON**): Ethernet commutate, con commutatori in grado di ricevere/trasmettere segnali ottici.
>	- *Passive Optical Network(**PON**)*: Usano splitter ottici non alimentati che suddividono il segnale in diverse copie che raggiungono i vari utenti.

>**FWA**
>*Fixed Wireless Access, si tratta di una rete mista fibra-radio.

### Reti domestiche

![[Pasted image 20260313121853.png|center|500]]

Una rete condivisa d'accesso *wireless* collega i sistemi periferici al router, attraverso l'*Access Point*.

### Accesso aziendale

![[Pasted image 20260313122018.png|center|500]]

Misto di tecnologie di collegamento cablato e wireless, che collegano un misto di switch e router

### Data Center

Si parla di collegamenti ad alta larghezza di banda che collegano centinaia o migliaia di server tra loro e ad Internet

## Host: invio dei pacchetti di dati

- Prende il messaggio dell'applicazione;
- Lo suddivide in frammenti più piccoli, conosciuti come *pacchetti*, di lunghezza $L$ bit.
- Trasmette il pacchetto nella rete di accesso al *tasso di trasmissione* $R$. 
	- Ritardo di trasmissione del pacchetto =  tempo necessario per trasmettere pacchetti di $L$ bit nel collegamento = $\frac{L_{(bits)}}{R_{(bits/sec)}}$.

### Mezzi trasmissivi
- *Bit*: si propaga tra coppie trasmettitore/ricevitore;
- *Mezzo fisico*: cosa c'è tra trasmettitore e ricevitore;
- *Mezzo vincolato (guided media)*: I segnali si propaganto in un mezzo solido (rame, fibra, cavo coassiale,..);
- *Mezzo non vincolato (unguided media)*: I segnali si propagano liberamente.

>**Doppino di rame intrecciato** ( Twisted Pair - TP):
>- Due fili di rame isolati;
>- Intrecciati tra loro per ridurre la *diafonia* con coppie adiacenti e in parte le interferenze esterne.

>**Cavo coassiale**:
>- Due conduttori di rame concentrici;
>- Bidirezionale.

>**Cavo in fibra ottica**:
>- Sottile e flessibile che conduce impulsi di luce, ciascuno dei quali rappresenta un bit;
>- Elevata velocità trasmissiva (punto-punto ad alta velocità);
>- Basso tasso di errore.

>**Canali radio**:
>- Trasportano segnali nello spettro elettromagnetico, per cui non richiedono l'installazione fisica di cavi;
>	- WiFI, 4G/5G, Bluetooth, Microonde, Satellitari
