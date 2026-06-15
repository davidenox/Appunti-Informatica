# Panoramica
## Servizi e protocolli
Il livello di rete trasporta i segmenti dall'host mittente all'host destinatario:
- *Mittente*: Incapsula i segmenti dentro ai datagrammi che passa al livello di collegamento;
- *Destinatario*: Consegna i segmenti al livello di trasporto.
I protocolli di livello di rete sono tutti implementati da *tutti i dispositivi internet* (host, router).
**Router**:
- Esamina i campi dell'intestazione di tutti i datagrammi IP che lo attraversano;
- Sposta i datagrammi dalle porte di ingresso alla porta di uscita per trasferire il datagramma lungo il percorso dall'host di origine a quello di destinazione.
![[Ch. 4.1 - Rete p. dati-1780583330633.png]]

## Due funzioni chiave
- **Inoltro**(*forwading*): Trasferisce i pacchetti da un collegamento di ingresso di un router al collegamento di uscita appropriato del router.
- **Instradamento**(*Routing*): Determina il percorso seguito dai pacchetti dall'origine alla destinazione, tramite appositi *algoritmi di instradamento*.

**Piano dei dati**:
- Funzione locale;
- Determina come i pacchetti in arrivo a una porta d'ingresso del router sono inoltrati verso una porta di uscita;
- ![[Ch. 4.1 - Rete p. dati-1780584102188.png]]
**Piano di controllo**:
- *Logica di rete*;
- Determina come i pacchetti sono instradati tra i router lungo un percorso dall'host di origine all'host di destinazione;
- Due approcci per il piano di controllo
	- *Algoritmi di instradamento tradizionali* implementati nei router;
	- *Software Defined Networking* (SDN) implementati nei server remoti.

**Piano di controllo per router**
I singoli componenti dell'algoritmo di routing in ogni singolo router;![[Ch. 4.1 - Rete p. dati-1780584254435.png]]

**Software-Defined Networking** SDN
Un controllore remoto calcola ed installa le tabelle di inoltro nei router![[Ch. 4.1 - Rete p. dati-1780584329244.png]]

## Modello di servizio del livello di rete
Domanda: Qual è il *modello di servizio* per il 'canale' che trasporta i datagrammi dal mittente al destinatario?
*Esempi di servizi per un singolo datagramma*:
- Consegna garantita;
- Consegna garantita con un ritardo inferiore a 40ms
*Esempi di servizi per un flusso di datagrammi*:
- Consegna in ordine;
- Minima ampiezza di banda;
- Restrizioni sulle modifiche della spaziatura tra i pacchetti.
![[Ch. 4.1 - Rete p. dati-1780584462587.png]]

**Modello di servizio "best effort" di internet**
*Nessuna* garanzia circa:
1. Consegna del datagramma alla destinazione con successo;
2. Tempi o ordine di consegna;
3. Larghezza di banda disponibile per il flusso da un capo all'altro.

La *semplicità del meccanismo* ha consentito l'ampia diffusione di internet. Una *dotazione sufficiente di larghezza di banda* e *protocolli in grado di adattarsi alla banda disponibile* consentono alle prestazioni delle applicazioni in tempo reale di essere "sufficientemente buone" e "per la maggior parte del tempo". *Servizi replicati e distribuiti a livello applicativo* che si collegano alle reti dei clienti consentono di fornire servizi da più luoghi, ed il controllo della congestione dei servizi "elastici" aiuta. In sintesi, *il successo del modello di servizio best-effort è difficilmente contestabile*.

# Router
## Architettura
Visione ad alto livello di una generica architettura di un router:
![[Ch. 4.1 - Rete p. dati-1780584830921.png]]

Analogia:
![[Ch. 4.1 - Rete p. dati-1780584863698.png]]

**Funzioni delle porte di ingresso**
![[Ch. 4.1 - Rete p. dati-1780584914813.png]]
![[Ch. 4.1 - Rete p. dati-1780584929737.png]]

**Destinazione basata sull'indirizzo di destinazione**:
![[Ch. 4.1 - Rete p. dati-1780584985669.png]]

**Corrispondenza a prefisso più lungo**
- Quando si cerca una voce della tabella di inoltro per un dato indirizzo di destinazione, si utilizza il prefisso di indirizzo *più lungo* che corrisponde all'indirizzo di destinazione:
![[Ch. 4.1 - Rete p. dati-1780585074135.png]]
![[Ch. 4.1 - Rete p. dati-1780585085804.png]]
![[Ch. 4.1 - Rete p. dati-1780585097816.png]]
![[Ch. 4.1 - Rete p. dati-1780585109020.png]]

Spesso la corrispondenza a prefisso più lungo viene eseguita con le *ternary content addressable memories* TCAMs:
- **Content Addressable**: Un indirizzo IP a 32 bit è passato alla memoria che restituisce il contenuto della tupla nella tabella di inoltro corrispondente a quell'indirizzo in un tempo essenzialmente costante.![[Ch. 4.1 - Rete p. dati-1780586151972.png]]

### Struttura di commutazione
	Switching fabric
- Trasferisce i pacchetti dal collegamento di ingresso al collegamento di uscita appropriato;
- *Tasso di trasferimento*: tasso al quale i pacchetti vengono trasferiti dalla porta di input a quella di output:
	- Spesso misurato come multiplo del tasso di trasmissione delle linee di input/output
	- N input: si desidera avere un tasso di trasferimento della struttura di commutazione N volte il tasso delle linee di input/output.![[Ch. 4.1 - Rete p. dati-1780586281718.png]]
![[Ch. 4.1 - Rete p. dati-1780586298794.png]]

#### Commutazione in memoria
**Router di prima generazione**:
- Computer tradizionali con commutazione sotto il diretto controllo della CPU
- Pacchetti copiati nella memoria del sistema
- Velocità limitata dall'ampiezza di banda della memoria (2 attraversamenti del bus per datagramma)
![[Ch. 4.1 - Rete p. dati-1780651712720.png]]

#### Commutazione tramite bus
- Le porte di ingresso trasferiscono un pacchetto direttamente alle porte di uscita tramite un bus condiviso.
- *Bus contention*: velocità di commutazione limitata dalla velocità del bus.
- Bus a 32Gbps, Cisco 5600: velocità sufficiente per router di accesso.![[Ch. 4.1 - Rete p. dati-1780651869732.png]]

#### Commutazione attraverso rete di interconnessione
- Crossbar (matrice di commutazione), reti Clos, altre reti di interconnessione sviluppate originariamente per architetture multiprocessore;
- *Multistage Switch*: switch $n\times n$  da più stadi di switch più piccoli;
*Sfruttare il parallelismo*:
- Frammenta il datagramma in celle di lunghezza fissa all'ingresso;
- Commuta le celle attraverso la rete di commutazione e riassembla il datagramma in uscita
![[Ch. 4.1 - Rete p. dati-1780652032800.png|253]]
- Scala utilizzando molteplici piani di commutazione in parallelo:
	- speedup, scaleup attraverso il parallelismo
![[Ch. 4.1 - Rete p. dati-1780652183674.png]]

### Accodamento sulle porte di ingresso
Se la struttura di commutazione è più lenta delle porte di ingresso combinate, può verificarsi accodamento sulle porte di ingresso, e quindi ritardo di accodamento e perdite dovute all'overflow dei buffer di input
>[!important] HOL Blocking - Blocco in testa alla coda
>Il datagramma accodato all'inizio della coda impedisce agli altri in coda di avanzare.![[Ch. 4.1 - Rete p. dati-1780652333983.png]]

### Accodamento in uscita
![[Ch. 4.1 - Rete p. dati-1780652372759.png]]
- *Buffering* richiesto quando i datagrammi arrivano dalla struttura di commutazione più velocemente del tasso di trasmissione del collegamento. **Drop policy**: quale datagramma scartare se il buffer non è sufficiente?
	- I datagrammi possono essere persi a causa di congestione, mancanza di buffer.
- *Disciplina di scheduling* sceglie tra i datagrammi in coda quale trasmettere.
	- Schedulazione con priorità - chi ottiene le migliori prestazioni, neutralità della rete.
![[Ch. 4.1 - Rete p. dati-1780652512085.png]]
- Buffering quando il tasso di arrivo attraverso la struttura di commutazione supera la velocità delle linee di uscita.
- **Accodamento e perdite causati dall'overflow del buffer della porta di uscita**.
#### Quanta memoria è necessaria?
Regola RFC3439 - Buffering medio uguale al prodotto del RTT 'tipico' (diciamo 250ms) per la capacità del collegamento C.
	Raccomandazione più recente: Con N flussi, dimensione del buffer: $$\frac{RTT\cdot C}{\sqrt N}$$
Ma *troppo* buffering può aumentare i ritardi, soprattutto nei router domestici.
- RTT elevato:  prestazioni scarse delle applicazioni real-time, mittenti TCP meno reattivi alla congestione ed alla perdita dei pacchetti;
- Il controllo di congestione basato sul ritardo: 'Mantenere il collegamento collo di bottiglia sufficientemente pieno ma non troppo'.
## Gestione del buffer
![[Ch. 4.1 - Rete p. dati-1780652945802.png]]
**Politica di scarto** (drop): Quale pacchetto eliminare quando la coda è piena
- *Tail drop*: Scarta il pacchetto in arrivo;
- *Priorità*: Scarta/rimuove in base alla priorità.
**Marcatura**: Quali pacchetti marcare per segnalare la congestione (ECN, RED).![[Ch. 4.1 - Rete p. dati-1780653046904.png|471]]
### Schedulazione dei pacchetti
Decidere quale pacchetto inviare successivamente sul collegamento.

**FCFS**
Pacchetti trasmessi in ordine di arrivo alla porta di uscita.
	Conosciuto anche come FIFO

**Priority Scheduling**
Traffico in arrivo classificato ed accodato per classi.
- Qualsiasi campo di intestazione può essere utilizzato per la classificazione.
Invia il pacchetto dalla coda non vuota con priorità più alta.
- FCFS all'interno di ciascuna classe
- Possibilità di *starvation*: un pacchetto può attendere indefinitivamente se continuano ad arrivare pacchetti con priorità maggiore.
![[Ch. 4.1 - Rete p. dati-1780653267353.png|369]]

**Round-Robin Scheduling**
Traffico in arrivo classificato ed accodato per classi
- Qualsiasi campo di intestazione può essere usato per la classificazione.
Il server esegue ciclicamente e ripetutamente la scansione delle code di classe, inviando a turno un pacchetto completo di ogni classe (se disponibile).
![[Ch. 4.1 - Rete p. dati-1780653379278.png|517]]

**Weighted Fair Queuing** WFQ
Generalizza RR, ciascuna classe $i$ ha un peso $w_i$, e riceve una quantità ponderata di servizio in ogni ciclo: $\frac{w_i}{\sum_j w_j}$.
Garanzia di larghezza di banda minima (per classe di traffico).
![[Ch. 4.1 - Rete p. dati-1780653493906.png|445]]
### Barra laterale: neutralità della rete
*Tecnica*: Come un ISP dovrebbe condividere/allocare le proprie risorse.
- La schedulazione dei pacchetti e la gestione dei buffer sono i *meccanismi*.
Principi *sociali ed economici*
- Proteggere la libertà di espressione
- Incoraggiare l'innovazione e la competizione
Far rispettare *politiche e leggi*.
	Ogni paese ha il proprio approccio alla neutralità della rete.
Tre regole definite nel 2015:
- *no blocking*: ... non bloccherà i contenuti, le applicazioni, i servizi o i dispositivi non dannosi leciti, fatta salva una ragionevole gestione della rete.
- *no throttling*: ...non devono pregiudicare o degradare il traffico Internet lecito sulla base del cotenuto, dell'applicazione o del servizio Internet o dell'uso di un dispositivo non dannoso, fatta salva una ragionevole gestione della rete.
- *no paid prioritization*: ...non devono impegnarsi nella prioritizzazione a pagamento
Nel 2017 la Restoring Internet Freedom Order ha annullato questi divieti, concentrandosi invece sulla trasparenza degli ISP.

### ISP: Telecomunicazione o informazione?

Un ISP è un 'servizio di telecomunicazione' o un fornitore di 'servizi di informazione'?
La risposta è importante dal punto di vista normativo
US Telecommunication Act del 1934 e 1996: 
- *Titolo II*: impone “**common carrier duties**” ai servizi di telecomunicazione: tariffe ragionevoli, non discriminazione e richiede una regolamentazione;
- *Titolo I*: si applica ai servizi di informazione: 
	- no common carrier duties (non regolamentato)
	- ma concede alla FCC l'autorità "... necessaria per l'esecuzione delle sue funzioni "

# IP
![[Ch. 4.1 - Rete p. dati-1780655428234.png]]

## Formato dei datagrammi IP
![[Ch. 4.1 - Rete p. dati-1780655499968.png]]

### Frammentazione e riassemblaggio dei datagrammii
L'unità massima di trasmissione (MTU) è la quantità massima di dati che un frame a livello di collegamento può trasportare.
- Differenti tipi di collegamento, differenti MTU
Datagrammi IP grandi vengono frammentati in datagrammi IP più piccoli:
- Un datagramma viene frammentato;
- I frammenti saranno riassemblati solo una volta raggiunta la destinazione;
- I bit dell'intestazione IP sono usati per identificare ed ordinare i frammenti.
![[Ch. 4.1 - Rete p. dati-1780655664157.png]]

*Deprecata*:
- Ogni frammento richiede un'intestazione IP, aumentando il carico di rete (overhead) e sottraendo banda all'invio di dati utili (inefficienza)
- Perdita di un frammento -> datagramma originale perso (a dispetto della ricezione di altri frammenti)
- Impiego di risorse computazionali per il riassemblaggio dei pacchetti
- Sicurezza: 'tiny fragment attack' consiste nell'intasare i buffer di riassemblaggio inviando piccoli frammenti.
In IPv6: Frammentazione solo nella sorgente, router invia messaggio `ICMP Packet Too Big`
*Path MTU Discovery*
- Invio di pacchetti con bit (DF) `Don't fragment` impostato a 1.
- Se il router non può inoltrare il datagramma perché eccede la MTU, scarta il pacchetto ed invia al mittente un messaggio ICMP `Destination unreachable: fragmentation required` oppure `Packet too big` in IPv6

Il problema p che questi messaggi ICMP possono essere bloccati (sicurezza): in questi casi, per esempio, un mittente TCP rischia addirittura di ritrasmettere inutilmente lo stesso pacchetto più volte. Inoltre, il percorso, e quindi la MTU, possono cambiare.
Sono stato proposti approcci alternativi più robusti, tra cui la manipolazione di segmenti SYN in fase di instaurazione di una connessione TCP, cambiando l'opzione relativa al MSS.

## Indirizzamento IP
>[!important] Indirizzo IP
>Identificatore a 32 bit associato a ciascuna *interfaccia* di host e router

**Interfaccia**: Connessione tra host/router e collegamento fisico.
- I router hanno tipicamente più interfacce;
- Gli host hanno tipicamente una o due interfacce (es. Ethernet, 802.11 wireless)
![[Ch. 4.1 - Rete p. dati-1780656194264.png|325]]

Come sono effettivamente collegate le interfacce?
![[Ch. 4.1 - Rete p. dati-1780672855011.png|422]]

### Sottoreti
	Subnet
Per **sottoreti** si intendono interfacce di dispositivi che possono raggiungersi fisicamente *senza passare attraverso un router intermedio*.
Gli indirizzi IP hanno una struttura:
- *Parte della sottorete*: i dispositivi della stessa sottorete hanno in comune i bit di ordine superiore;
- *Parte dell'host*: i rimanenti bit di ordine inferiore.
![[Ch. 4.1 - Rete p. dati-1780673027342.png|317]]

**Procedura per definire le sottoreti**:
- Si sganciano le interfacce da host e router, in maniera tale da creare "isole" di reti isolate delimitate dalle interfacce
- Ognuna di queste reti isolate viene detta *sottorete* (subnet)
![[Ch. 4.1 - Rete p. dati-1780673131424.png|341]]

### CIDR
>[!important] CIDR - Classless Inter Domain Routing
>- Parte della rete dell'indirizzo di lunghezza arbitraria
>- Formato dell'indirizzo: `a.b.c.d/x`, dove `x` è il numero di bit della porzione della rete dell'indirizzo

![[Ch. 4.1 - Rete p. dati-1780673270911.png]]

**Classfull addressing**
Spazio di indirizzamento IPv4 suvviviso in blocchi con prefisso di rete di 8, 16 e 24 bit:![[Ch. 4.1 - Rete p. dati-1780673319964.png]]
Nell'indirizzamento IP la lunghezza della parte di rete era fissa e dipendeva dalla classe dell'indirizzo:
- Classe A: 1 byte dedicato alla parte di rete;
- Classe B: 2 byte dedicati alla parte di rete;
- Classe C: 3 byte dedicati alla parte di rete.
Questa rigidità comportava notevoli sprechi, e CIDR ha sostituito l'indirizzamento per classi in virtù di diversi vantaggi:
- Più efficiente allocazione di blocchi di indirizzi;
- Aggregazione di indirizzi con conseguente riduzione delle tabelle di instradamento.

## IP:  come ottenerne uno
Due domande:
1. Come fa un host ad ottenere l'indirizzo IP all'interno della sua rete (parte host dell'indirizzo)?
2. Come fa una rete ad ottenere l'indirizzo IP (parte dell'indirizzo relativa alla rete)?

***Domanda 1:***
- Codificato dal sysadmin nel file di configurazione;
- **DHCP**: Dynamic Host Configuration Protocol, permette a un host di ottenere un indirizzo IP in modo automatico ( "plug and play" ).
### DHCP
**Obiettivo**: L'host ottiene *dinamicamente* l'indirizzo IP dal server di rete quando si 'unisce' alla rete.
- Può rinnovare la propria concessione per l'indirizzo in uso
- Permette il riutilizzo degli indirizzi ( mantiene un indirizzo solo quando è collegato/acceso )
- Supporto per gli utenti mobili che si uniscono/abbandonano la rete (ma non mantiene una connessione TCP attiva, poiché quando ci si unisce ad una nuova sottorete si ottiene un altro IP).
**Panoramica**
- L'host invia in broadcast un messaggio `DHCP Discover` (opzionale);
- Il server DHCP risponde con un messaggio `DHCP Offer` (opzionale);
- L'host richiede un indirizzo IP: messaggio `DHCP request`;
- Il server DHCP invia un indirizzo IP: messaggio `DHCP Ack`.

Scenario:
In genere il server DHCP è collocato nel router e serve tutte le sottoreti a cui il router è collegato. Il client DHCP in arrivo su questa rete ha bisogno di un indirizzo.
![[Ch. 4.1 - Rete p. dati-1780675708244.gif]]

Il DHCP può restituire più di un indirizzo IP:
- Indirizzo del router first-hoè o router (o gateway) predefinito (per comunicare al di là della sottorete);
- Nome e indirizzo IP del server DNS;
- Maschera di sottorete ( che indica la porzione di sottorete rispetto a quella di host dell'indirizzo ).
Esempio:
![[Ch. 4.1 - Rete p. dati-1780675829245.png|400]]
Il portatile che si collega utilizzerà il DHCP per ottenere l'indirizzo IP, l'indirizzo del router first-hop e l'indirizzo del server DNS.
- Messaggio di richiesta DHCP incapsulato in UDP, incapsulato in IP, incapsulato in Ethernet.
- Trasmissione di frame Ethernet (destinazione `FFFFFFFFFF`) sulla LAN, ricevuto dal router che esegue il server DHCP.
- Ethernet demultiplato in IP, IP demultiplato in UDP, UDP demultiplato in DHCP.
![[Ch. 4.1 - Rete p. dati-1780675989276.png]]

Il server DHCP formula un DHCP ACK contenente l'indirizzo IP del client, l'indirizzo IP del router first-hop per il client, il nome e l'indirizzo IP del server DNS.
- Risposta del server DHCP incapsulata ed inoltrata al client, de-mux fino a DHCP sul client;
- Il client conosce ora il proprio IP, il nome e l'IP del server DNS, e l'IP del router first-hop.

***Domanda 2***
- La tete ottiene l'assegnazione di una porzione dello spazio di indirizzi del suo provider ISP. 
![[Ch. 4.1 - Rete p. dati-1780911454043.png]]

### Indirizzamento Gerarchico
**Aggregazione di indirizzi** (Route Aggregation)
- L'indirizzamento gerarchico consente di pubblicizzare in modo efficiente le informazioni di routing:
![[Ch. 4.1 - Rete p. dati-1780911725621.png]]

**Percorsi più specifici**:
- L'organizzazione 1 si sposta da Fly-By-Night-ISP a ISP-R-Us;
- ISP-R-Us ora pubblicizza un percorso più specifico verso l'organizzazione 1:
![[Ch. 4.1 - Rete p. dati-1780911900451.png]]

**Ultime domande**
1. Come fa un ISP ad ottenere un blocco di indirizzi?
	- *ICANN*: International Corporations for Assigned Names and Numbers
		- Assegnazione degli indirizzi IP, attraverso *5 registri regionali (RR)*
		- Gestisce la zona radice del DNS, compresa la delega della gestione dei singoli TLD.
2. Ci sono abbastanza indirizzi IP a 32 bit?
	- ICANN ha assegnato l'ultima porzione di indirizzi IPv4 ai RR nel 2011.
	- NAT(successivo) aiuta con l'esaurimento dello spazio degli indirizzi IPv4
	- IPv6 ha uno spazio di indirizzi a 128 bit

## Traduzione degli indirizzi di rete: NAT
**NAT**(*Network Address Translation*): Tutti i dispositivi ella rete locale condividono *un solo* indirizzo IPv4 per il mondo esterno.![[Ch. 4.1 - Rete p. dati-1780913047858.png]]
Tutti i dispositivi della rete locale hanno indirizzi a 32 bit in uno spazio di indirizzi IP "privato" (prefissi 10/8, 172.16/12, 192.168/16) che possono essere usati solo nella rete locale.
Vantaggi:
- È necessario *un solo* indirizzo IP dal provider ISP per **tutti** i dispositivi;
- Può cambiare gli indirizzi degli host nella rete locale senza notificare il mondo esterno;
- Può cambiare ISP senza modificare gli indirizzi dei dispositivi nella rete locale;
- Sicurezza: Dispositivi all'interno della rete locale non direttamente indirizzabili o visibili dall'esterno.

**Implementazione**: I router NAT devono (in maniera trasparente):
- *Datagrammi in uscita: Sostituire* (IP sorgente, Porta sorgente) di ogni datagramma in uscita con (IP NAT, nuovo num. porta)
	- I client/server rempoti risponderanno con (IP NAT, nuovo num. porta) come indirizzo di destinazione;
- *Ricordare*(nella "tabella di traduzione NAT") ogni coppia di traduzione da origine a nuovo.
- *Datagrammi in ingresso: Sostituire* (IP NAT, nuovo num. porta) nei campi di intestazione di ogni datagramma in ingresso con il corrispondente (IP NAT, nuovo n. porta) memorizzato nella tabella NAT.
![[Ch. 4.1 - Rete p. dati-1780913457690.png]]

Il NAT è spesso oggetto di controversie:
- I router "dovrebbero" elaborare i pacchetti solo fino al livello 3;
- La "scarsità" di indirizzi dovrebbe essere risolta da IPv6;
- Viola il cosiddetto argomento punto-punto (num. di porta manipolato da un dispositivo a livello di rete);
- Attraversamento NAT (NAT traversal): Cosa succede se un client vuole connettersi ad un server dietro NAT?
Ma allo stesso tempo è qui per restare, siccome è ampiamente utilizzato nelle reti domestiche ed istituzionali, e nelle reti 4G/5G.

## IPv6
**Motivazione iniziale**: Lo spazio degli indirizzi IPv4 a 32 bit sarebbe stato completamente allocato;
*Motivazioni aggiuntive*:
- Velocità di elaborazione/inoltro: intestazione con una larghezza fissa di 40 byte
- Consentire un diverso trattamento dei "flussi" a livello di rete

**Formato del datagramma IPv6**
- *Classe di traffico*: Attribuisce priorità a datagrammi all'interno di un flusso o proveniente da specifiche applicazioni.
- *Etichetta di flusso*: Identifica i datagrammi appartenenti allo stesso flusso (concetto di "flusso" non ben definito).
- *128-bit*.
![[Ch. 4.1 - Rete p. dati-1780915334058.png|440]]
Cosa manca (rispetto a IPv4):
- No `checksum` (velocitta l'elaborazione presso i router)
- No frammentazione/riassemblaggio
- No opzioni

**Etichettatura dei Flussi IPv6**
L'etichettatura dei pacchetti che appartengono a flussi particolari per i quali il mittente richiede una gestione speciale, come una qualità di servizio diversa da quella di default o un servizio in tempo reale.

**Notazione**
Gli indirizzi IPv6 128 bit sono scritti nella forma `x:x:x:x:x:x:x:x` dove le `x` rappresentano da 1 a 4 cifre esadecimali. Es:
`2001:0db8:0000:0000:0000:8a2e:0370:7344`
Abbreviazioni:
1. `2001:0db8:0:0:0:8a2e:0370:7344`
2. `2001:0db8::8a2e:0370:7344`

### Da IPv4 a IPv6
Non tutti i router possono essere aggiornati contemporaneamente:
- no 'flag day';
- come funzionerà la rete con un misto di router IPv4 e IPv6?
**Tunneling**: Datagramma IPv6 trasportato come *payload* in un datagramma IPv4 tra i router IPv4 (pacchetto nel pacchetto). Viene ampiamente utilizzato in contesti come 4G/5G.![[Ch. 4.1 - Rete p. dati-1780927779692.png]]
![[Ch. 4.1 - Rete p. dati-1780927808664.png]]![[Ch. 4.1 - Rete p. dati-1780927827901.png]]
![[Ch. 4.1 - Rete p. dati-1780927847073.png]]

## Inoltro generalizzato, SDN

**Match+Action**
![[Ch. 4.1 - Rete p. dati-1780928113749.png]]
Ciascun royter ha una *tabella di inoltro*( o dei flussi).
Astrazione "**match plus action**": Cerca corrispondenze nei bit dei pacchetti in arrivo, agisce:
- *Inoltro basato sulla destinazione*: Inoltra in base all'IP del destinatario
- *Inoltro generalizzato*:
	- Più campi di intestazione possono determinare l'azione;
	- Più azioni possibili (scarta/copia/modifica/logga il pacchetto)
![[Ch. 4.1 - Rete p. dati-1780928247851.png]]

**Tabella dei flussi**
*Flusso*: Definito dai valori campi di intestazione (a livello di collegamento, rete o trasporto).
*Inoltro generalizzato*: Semplici regole per la gestione dei pacchetti:
- *Match*: pattern sui valori dei campi di intestazione;
- *Actions*: per il pacchetto in cui viene trovata una corrispondenza: scartare(drop), inoltrare (forward), modificare l'intestazione (modify), o inviare al controllore;
- *Priorità*: Disambigua pattern sovrapposti;
- *Contatori*: numero di byte e numero di pacchetti, marca temporale ultimo aggiornamento.
![[Ch. 4.1 - Rete p. dati-1780928498738.png]]
![[Ch. 4.1 - Rete p. dati-1780928519581.png]]

**OpenFlow**
![[Ch. 4.1 - Rete p. dati-1780928654173.png]]
Esempi:
![[Ch. 4.1 - Rete p. dati-1780928675942.png]]

**Astrazione in OverFlow**
*Match+Action* astrae dispositivi differenti:
**Router**:
- *match*: prefisso IP di destinazione più lungo
- *action*: inoltro attraverso un collegamento
**Firewall**:
- *match*: indirizzi IP e  numeri di porta TCP/UDP
- *action*: consentire o negare (permit/deny)
**Switch**:
- *match*: indirizzo MAC di destinazione
- *action*: inoltra o inonda
**NAT**:
- *match*: indirizzo IP e porta
- *action*: riscrive indirizzo e porta

## Middlebox

>[!cite] "Qualsiasi box intermedio che svolge *funzioni diverse da quelle normali e standard di un router IP * **sul percorso dei dati tra un host di origine e un host di destinazione"**
![[Ch. 4.1 - Rete p. dati-1780929048931.png]]

Inizialmente le middlebox erano soluzioni hardware proprietarie (chiuse). Si è passati ad hardware "whitebox" che implementano API aperte, per:
- abbandonare le soluzioni hardware proprietari;
- effettuare *azioni locali probammabili* attraverso 'match+action'
- orientarsi verso innovazione/differenziazione nel software.
*SDN*: Disaccoppia piano di controllo (centralizzato) dal piano dei dati (distribuito)
**Network Funcions Virtualization** (VFN): Astrae le funzioni di rete dall'hardware: le funzioni di rete (Es. router, switch, firewall) sono programmate in software ed eseguite su hardware COTS (Commodity Off-The-Shelf) tramite VM o container, sfruttando risorse di calcolo, storage e rete. Sono usate svariate tecniche e tecnologie per migliorare le prestazioni. Possono essere quindi anche eseguite in Cloud.

**Clessidra IP**
![[Ch. 4.1 - Rete p. dati-1780929333549.png]]
![[Ch. 4.1 - Rete p. dati-1780929351206.png]]

**Principi architetturali di internet**
Tre convinzioni fondamentali:
- Connettività semplice;
- Protocollo IP
- Intelligenza, complessità alla periferia della rete.

**Principio end-to-end**
Alcune funzionalità possono essere implementate nel *nucleo della rete* o nella *periferia della rete*:![[Ch. 4.1 - Rete p. dati-1780929466461.png]]
