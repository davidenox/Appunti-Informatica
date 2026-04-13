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

# Nucleo della rete
Per **nucleo della rete** si intende una maglia di commutatori di pacchetto e collegamenti che interconnettono i sistemi periferici di Internet.

**Packet Switching**: i sistemi periferici suddividono i messaggi di livello applicativo in *pacchetti*.
- La rete *inoltra* i pacchetti da un router al successivo attraverso collegamenti (links) lungo un *percorso* (path/route) dalla sorgente alla destinazione.
- I pacchetti sono inoltrati *indipendentemente*, senza prenotazione delle risorse.

## Inoltro ed instradamento
- **Inoltro**(*forwarding*): Azione *locale*, sposta i pacchetti in arrivo al collegamento di ingresso del router al collegamento di uscita appropriato.
- **Instradamento**(*routing*): Azione *globale*, determina i percorsi presi dai pacchetti dalla sorgente alla destinazione; opera grazie ad algoritmi di instradamento.

>Store-and-forward

![[Pasted image 20260330111940.png|center|500]]

- *delay di trasmissione*: Servono $L/R$ secondi per trasmettere pacchetti di $L$ bit attraverso un collegamento a $R$ bps.
- *store-and-forward*: Il router deve aver ricevuto l'intero pacchetto prima di poter cominciare a trasmettere sul collegamento in uscita.

Delay end-to-end per la trasmissione di un pacchetto su un percorso di $N$ collegamenti di pari velocità $R$: $$d_{end-to-end}=N\frac{L}{R}$$
Delay end-to-end per la trasmissione di P pacchetti su un percorso di N collegamenti di pari velocità R:$$d_{end-to-end}=(N+P-1)\frac{L}{R}$$
**Accodamento**(*queuing*): Si verifica quando il lavoro arriva più velocemente di quanto possa essere servito.
Se il tasso di arrivo eccede il tasso di trasmissione per un certo periodo di tempo:
- I pacchetti si accodano in attesa di essere trasmessi sul collegamento in uscita;
- I pacchetti possono essere scartati (persi) se la memoria (buffer)  si riempie.

**Commutazione di Circuito**

Le risorse richieste lungo un percorso per consentire la comunicazione tra sistemi periferici sono riservate per l'intera durata della sessione di comunicazione. La rete stabilisce una *connessione punto a punto*, detta **circuito**.
Viene utilizzato comunemente nelle reti telefoniche tradizionali:
![[Pasted image 20260403160153.png|center|500]]

### FDM e TDM

>**Multiplexing a divisione di Frequenza**(*FDM*)
>- Spettro di frequenza diviso in *bande*: bande adiacenti sono separate da piccoli intervallli di *guardia* non usati.
>- Ogni circuito ha una propria banda, può trasmettere alla velocità massima di quella banda ristretta.
>![[Pasted image 20260403160413.png|center|500]]

>**Multiplexing a divisione di Tempo**(*TDM*)
>- Tempo suddiviso in *frame* di durata fissa, ripartiti in un numero fisso di *slot*.
>- Ciascun circuito riceve slot periodici, può trasmettere alla massima velocitàdella banda di frequenza (più ampia) solo nei propri slot temporali.![[Pasted image 20260403160609.png|center|500]]

## Pacchetto vs. Circuito

![[Pasted image 20260403160811.png|center|500]]

***Domanda***: Quanti utenti possono usare questa rete sotto ciascuna commutazione?
- *Commutazione di circuito*: 10 utenti;
- *Commutazione di pacchetto*: Con 35 utenti, probabilità >10 attivi allo stesso tempo è meno di 0,0004

***Domanda***: Che succede se soltanto uno degli utenti è attivo?
- *Commutazione di circuito*: L'utente attivo può trasmettere ad una velocità media di 100Mbps, inferiore alla capacità del collegamento (1Gbps), parte della quale è stata preallocata agli altri utenti e rimarrà inutilizzata;
- *Commutazione di pacchetto*: L'unico utente attivo può trasmettere continuamente pacchetti alla massima velocità del collegamento (1Gbps).

***Domanda finale***:*La commutazione di pacchetto è una 'vincitrice assoluta'*?
- Ottima per i dati "a raffica":
	- Più semplice, non necessita l'impostazione della chiamata.
- *Eccessiva congestione*: Ritardo e perdita di pacchetti in caso di buffer overflow:
	- Sono necessari i protocolli per il trasferimento affidabile dei dati e per il controllo della congestione.
- *Ritardi end-to-end variabili ed imprevedibili*: A causa della variabilità ed imprevedibilità dei ritardi di accodamento:
	- Servizi in tempo reale (telefonia, videoconferenza,..).
# Struttura di internet: "rete di reti"

I sistemi periferici accedono ad Internet tramite gli Internet Service Provider (**ISP**) di *accesso*. Essi però devono essere *interconnessi* a loro volta (in modo che due host, qualsiasi ed ovunque, possano inviare i pacchetti l'uno all'altro).

**Domanda**: Dati *milioni* di ISP di accesso, come collegarli tra loro?
![[Pasted image 20260403162327.png|center|500]]

- Connettere direttamente ogni ISP di accesso all'altro risulta impossibile e non scalabile ($O(n^2)$).
**Opzione**:  Collegare ogni ISP di accesso ad un ISP globale di transito?
- ISP *cliente* e *fornitore* hanno un accordo economico:
![[Pasted image 20260403162600.png|center|500]]

Ma se un ISP globale è un'alternativa vantaggiosa, ci saranno concorrenti..

![[Pasted image 20260403162945.png|center|500]]

... e ISP regionali possono sorgere per collegare gli ISP di accesso agli ISP di primo livello:

![[Pasted image 20260403163132.png|center|600]]

... E le reti di fornitori di contenuti (Google, Microsoft,...) possono gestire la propria rete, per avvicinare servizi e contenuti agli utenti finali:
![[Pasted image 20260403163327.png|center|600]]

## Struttura finale

![[Pasted image 20260403163406.png|center]]

Al "centro": un piccolo numero di grandi reti ben connesse:
- *ISP di primo livello* (**ISP Tier 1**): Possiede una rete globale e può raggiungere ogni altra rete su Internet esclusivamente tramite accordi di peering "settlement-free".
- *Rete di fornitori di contenuti* (Google, Facebook,..): Reti private che connettono i suoi data center a Internet, spesso aggirando ISP Tier 1 e regionali..

# Prestazioni
## Perdite, ritardi, throughput

I pacchetti si *accodano* nei buffer del router, aspettando il proprio turno per la trasmissione. La lunghezza della coda cresce quando il tasso di arrivo dei pacchetti sul collegamento eccede la capacità del collegamento di evaderli.
La **perdita** dei pacchetti avviene quando la memoria che contiene la coda dei pacchetti si riempie. 
Ci sono quattro cause:
![[Pasted image 20260403171900.png|center|500]]

1. $d_{elab}$: *Elaborazione di nodo*:
	 - Controllo errori sui bit;
	 - Determinazione del collegamento di uscita;
	 - Tipicamente < microsecondi.
2. $d_{acc}$: *Ritardo di accodamento*:
	- Attesa di trasmissione;
	- Dipende dal livello di congestione del router.
3. $d_{trasm}$: *Ritardo di trasmissione*:
	- L = lunghezza del pacchetto;
	- R = tasso di trasmissione del collegamento;
	- $d_{trasm}=\frac{L}{R}$, non dipende dalla lunghezza del collegamento né dalla velocità di propagazione del segnale.
4. $d_{prop}$: *Ritardo di propagazione*:
	 - d = lunghezza del collegamento fisico;
	 - v = velocità di propagazione ($\sim 2\cdot 10^8 m/s$);
	 - $d_{prop}=\frac{d}{v}$, non dipende dalla lunghezza del pacchetto né dalla velocità di trasmissione.

**Altre cause**:
- Un host può essere costretto ad attendere prima di inviare un pacchetto su un canale condiviso, perché deve rispettare le regole del protocollo di accesso al mezzo utilizzato da tutti i dispositivi collegati;
- Ritardo di pacchettizzazione nelle applicazioni multimediali in tempo reale;
- ecc..

## Ritardo end-to-end

I ritardi totali di nodo in cui è incorso un pacchetto lungo il suo percorso dalla sorgente alla destinazione si accumulano: $$d_{end-to-end}=\sum_i (d_{elab_i}+d_{acc_i}+d_{trasm_i}+d_{prop_i}).$$
## Ritardo di accodamento dei pacchetti

- $a$ = velocità media di arrivo dei pacchetti;
- $L$ = lunghezza del pacchetto (bit);
- $R$ = velocità di trasmissione (bit).
$$\frac{L\cdot a}{R}:\frac{\text{velocità di arrivo dei bit}}{\text{velocità di servizio dei bit}}=\text{Velocità di traffico}.$$
- $L\cdot a / R\sim0$: ritardo di accodamento medio piccolo;
- $L\cdot a/R=1$: ritardo di accodamento grande;
- $L\cdot a/R>1$: più lavoro in arrivo di quanto possa essere servito.

La coda (buffer) che precede un collegamento ha capacità finita : quando un pacchetto trova la coda piena viene scartato (quindi perso). Il pacchetto perso può essere ritrasmesso dal nodo precedente, dal sistema terminale che lo ha generato o non essere più ritrasmesso.
![[Pasted image 20260413112329.png|center|500]]

## Throughput

>[!important] **Throughput** - frequenza (bits/s) alla quale i bit sono trasferiti tra mittente e ricevente. Istantaneo o medio

![[Pasted image 20260413112546.png|center|500]]

Il throughput end-to-end non può superare la velocità di trasmissione dei collegamenti attraversati dal flusso di dati:
- Se il percorso non è interessato da altro traffico $throughput\sim\min\{R_i\}$ con $R_i$ velocità di trasmissione dell'i-esimo collegamento;
- Altrimenti, occorre considerare la frazione disponibile della capacità del collegamento.
Quindi, il throughput effettivo può essere inferiore a causa di altri fattori.

# Sicurezza di rete

## Intercettazione dei pacchetti

**Packet Sniffing**:
- Media broadcast (ethernet condivisa, wireless);
- Interfaccia di rete promiscua legge/registra tutti i pacchetti che l'attraversa.
![[Pasted image 20260413113513.png|center|500]]

**IP Spoofing** - iniezione di pacchetti con indirizzo sorgente falso:![[Pasted image 20260413113603.png|center|500]]
Usi:
- Ostacolare identificazione/blocco di una sorgente di attacco;
- Sfruttare relazioni di fiducia tra host;
- Indirizzare messaggi di risposta verso B, montando un attacco di negazione di servizio contro B, basato sull'ampliamento di traffico generato da C.

**DoS** - Negazione di servizio:
Gli aggressori rendono una rete, un host o un altro elemento infrastrutturale non disponibile per gli utenti legittimi. Tre categorie:
- *Attacchi alla vulnerabilità di sistemi*: Invio di pochi pacchetti costruiti ad hoc per causare il blocco di un servizio o lo spegnimento di un host, sfruttando vulnerabilità delle applicazioni o dei SO.
- *Bandwidth flooding*: Invio massivo di pacchetti all'host obiettivo impedendo al traffico legittimo di raggiungerlo.
- *Connection flooding*: Stabilire un gran numero di connessioni TCP con l'host obiettivo, impedendogli di accettare connessioni legittime.

## Linee di difesa

- **Autenticazione**: dimostrare la propria identità
- **Riservatezza**: cifratura di dati sensibili;
- **Integrità**: tramite firme digitali che prevengono/rilevano manomissioni;
- **Restrizioni di accesso**: VPN protette da password;
- **Firewalls**: "middlebox" specializzate nelle reti di accesso e di base
- ...

# Livelli di protocollo e modelli di servizio

Complessità delle reti: 
- Host
- Router
- Mezzi trasmissivi
- Applicazioni
- Protocolli
- HW/SW
È possibile organizzare l'architettura delle reti?

*Layer* - ogni livello implementa un servizio effettuando determinate azioni all'interno del livello ed utilizzando i servizi del livello immediatamente inferiore.
- Una struttura esplicita consente l'identificazione dei vari componenti di un sistema complesso e delle loro inter-relazioni - *analisi del modello di riferimento a strati*.
- La modularizzazione facilita la manutenzione e l'aggiornamento di un sistema.
Tuttavia, un livello può duplicare funzionalità del livello inferiore. Esiste la necessità di violare la separazione tra livelli, perché un livello ha bisogno di un'informazione disponibile solo all'interno del livello inferiore.

## Pila protocollare

- **Applicazione** - supporto alle applicazioni di rete (HTTP,IMAP,SMTP,DNS);
- **Trasporto** - trasferimento di dati tra processi in esecuzione su host differenti (TCP,UDP);
- **Rete** - trasferimento di pacchetti di rete (datagrammi) da un host all'altro (IP, protocolli di instradamento);
- **Collegamento** - trasferimento dati tra elementi di rete vicini (Ethernet, WiFi, PPP);
- **Fisico** - bit "sul filo".

**Service Model**:
- Insieme dei servizi offerti da un livello a quello superiore;
- I diversi servizi possono essere implementati da protocolli diversi;
- Il livello di collegamento può offrire servizi diversi in base a protocollo impiegato sul link;
- Un protocollo a livello di collegamento può prevedere diversi protocolli a livello fisico dipendentemente dalla tecnologia di trasmissione e dal mezzo trasmissivo del link. 

**Incapsulamento**
l4p24