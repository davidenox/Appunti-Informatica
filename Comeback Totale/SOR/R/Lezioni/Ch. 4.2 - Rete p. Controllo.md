# Intro
**Funzioni del livello di rete**
- *Inoltro*: Spostare i pacchetti dall'ingresso del router all'uscita del router appropriata - **PIANO DATI**
- *Instradamento*: Determinare il percorso seguito dai pacchetti dalla sorgente alla destinazione - **PIANO CONTROLLO**

Due approcci alla strutturazione del piano di controllo della rete:
- Controllo per router (tradizionale)
- Controllo logicamente centralizzato (sw-defined networking).

**Piano di controllo per router**
I singoli componenti dell'algoritmo di instradamento *in ogni router* interagiscono nel piano di controllo
![[Ch. 4.2 - Rete p. Controllo-1780932535489.png]]

**Piano di controllo SDN**
Un controllore remoto calcola le tabelle di inoltro e le installa nei router
![[Ch. 4.2 - Rete p. Controllo-1780932602532.png]]

![[Ch. 4.2 - Rete p. Controllo-1780932623556.png]]

# Algoritmi di instradamento
**Obiettivo degli algoritmi di instradamento**: Determinare percorsi o cammini "buoni" tra le sorgenti ed i destinatari attraverso la rete di router.
- *Percorso*: Sequenza di router che i pacchetti attraversano dall'host di origine a quello di destinazione ( presupponendo l'attraversamento di un collegamento tra un nodo ed il successivo )
- *"Buono"*: 'costo' minimo
- Instradamento : Uno dei "primi 10" problemi nelle reti.
![[Ch. 4.2 - Rete p. Controllo-1780932761440.png|435]]

**Astrazione: Grafo**
![[Ch. 4.2 - Rete p. Controllo-1780932799910.png|250]]
$c_{a,b}$: Costo del collegamento *diretto* che connette a e b (Es. $c_{w,z}=5;c_{u,z}=\infty$)
Costo definito dall'operatore di rete: potrebbe essere sempre 1, o proporzionale alla lunghezza fisica di un collegamento (ritardo di propagazione), o inversamente correlato alla larghezza di banda, o proporzionale alla congestione.
Il *costo di un percorso* è uguale alla somma dei costi dei collegamenti attraversati.

**Classificazione degli algoritmi di instradamento**
![[Ch. 4.2 - Rete p. Controllo-1780933006571.png]]

- **Sensibili al carico**: Il costo dei collegamenti riflette il livello corrente di congestione
- **Insensibili al carico**: Il costo dei collegamenti non riflette il livello corrente/recente di congestione
A causa di difficoltà sperimentate nell'uso di algoritmi sensibili al carico, al momento si preferiscono algoritmi insensibili al carico.

## Link state - Dijkstra
- **Centralizzato**: la topologia della rete ed il costo dei collegamenti sono noti a *tutti* i  nodi.
	- Informazioni ottenute attraverso un algoritmo di "link state broadcast"
	- Tutti i nodi hanno le stesse informazioni.
- Calcola i percorsi di costo minimo da un nodo sorgente a tutti gli altri nodi
	- Dà la *tabella di inoltro* per quel nodo
- *Iterativo*: Dopo k iterazioni, conosce il cammino di costo minimo verso k destinazioni.

**Notazione**
- $C_{x,y}$: Costo del collegamento *diretto* dal nodo x al nodo y ($\infty$ se non sono vicini diretti)
- $D(v)$: Stima *corrente* del costo minimo del percorso dalla sorgente alla destinazione v
- $p(v)$: Immediato predecessore di v lungo il percorso da root a v
- $N'$: Sottoinsieme di nodi contenenti tutti e solo i nodi v per cui il percorso a costo minimo dall'origine a v è *definitivamente noto*.
![[Ch. 4.2 - Rete p. Controllo-1780933419431.png]]

### Discussione
**Complessità algoritmica**: n nodi (senza contare l'origine)
- Ciascuna delle n iterazioni deve controllare tutti i nodi w non in N' per determinare quello avente il costo minimo;
- Complessità $O(n^2)$
- Sono possibili implementazioni più efficienti ($O(n\log n)$ usando un heap)
**Complessità dei messaggi**: n nodi
- Ogni router deve *trasmettere in broadcast* le proprie informazioni sullo stato dei collegamenti agli altri n router;
- Algoritmi di broadcast efficienti: $O(n)$ attraversamenti dei collegamenti per diffondere un messaggio di broadcasting da una sorgente;
- Il messaggio di ogni router attraversa $O(n)$ collegamenti: Complessità complessiva $O(n^2)$.

**Oscillazioni**
Quando i costi dei collegamenti dipendono dal volume di traffico sono possibili *oscillazioni dei percorsi*. 
Esempi: 
- Instradamento verso a: i nodi b, d e c trasmettono rispettivamente con tasso 1,1 e <1
- Il costo dei collegamenti è direzionale dipendente dal traffico.
![[Ch. 4.2 - Rete p. Controllo-1781096661227.png]]

## Distance Vector
Basato sull'equazione di *Bellman-Ford*:$$\begin{align}\\&
\text{Sia }D_x(y)\text{ il costo del percorso di costo minimo da }x\text{ a }y.\\& 
\text{Allora:}\\&
D_x(y)=\min_v\{c_{x,v}+d_v(y)\}
\end{align}$$
Dove:
- $d_v(y)$ è il costo del cammino minimo da v a y
- $c_{x,v}$ è il costo diretto del cammino da x e v
- $\min [..]$ è il minimo calcolato su tutti i vicini v di x
**Intuizione**
Il secondo nodo lungo qualsiasi cammino da x a y è necessariamente un vicino $v_i$ di x.
Il costo del primo arco è $c_{x,v_i}$ mentre la parte restante del cammino non può costare meno di $d_{v_i}(y)$ cioè il costo del cammino minimo da $v_i$ ad y, per un totale di $c_{x,v_i}+d_{v_i}(y)$.
Per trovare il cammino di costo minimo da x ad y è quindi sufficiente trovare il vicino di x che minimizza questa quantità:![[Ch. 4.2 - Rete p. Controllo-1781097164494.png]]
**Idea chiave**
- Di tanto in tanto, ogni nodo invia ai vicini il proprio vettore delle distanze (stimate) (*distance vector*);
- Quando x riceve un DV da un qualsiasi altro vicino, aggiorna la propria DV utilizzando l'equazione BF:$$D_x(y)\leftarrow\min_v\{c_{x,v},D_v(y)\}\forall y\in N$$
- Sotto certe condizioni minori e naturali, la stima $D_x(y)$ *converge* verso l'effettivo costo minimo $d_x(y)$.
![[Ch. 4.2 - Rete p. Controllo-1781097444351.png|271]]
- **Iterativo, asincrono**: Ciascuna iterazione locale causata:
	- Cambiamento del costo del collegamento locale;
	- Messaggio di aggiornamento del DV da un vicino.
- **Distribuito, auto-terminante**: Ciascun nodo notifica i vicini *solo* quando la sua DV cambia
	- I vicini notificano i loro vicini *solo se necessario*;
	- Nessuna notifica ricevuta implica nessuna azione intrapresa.

![[Ch. 4.2 - Rete p. Controllo-1781097964288.gif]]
E così via
Vediamo ora le *computazioni* iterative ai nodi
![[Ch. 4.2 - Rete p. Controllo-1781098191171.gif]]

**Diffusione di informazioni sullo stato**
La comunicazione iterativa, le fasi di calcolo diffondono le informazioni attraverso la rete:![[Ch. 4.2 - Rete p. Controllo-1781098255979.png]]
**Cambiamento del costo dei collegamenti**
- Un nodo rileva la modifica del costo del collegamento locale
- Aggiorna le informazioni di instradamento, ricalcola il DV locale
- Se il DV cambia, avvisa i vicini
## Confronto
![[Ch. 4.2 - Rete p. Controllo-1781098367812.png]]

# Instradamento interno al sistema autonomo : OSPF
**Rendere l'instradamento scalabile**
Fino ad ora è stato idealizzato il router come:
- Tutti i router sono identici
- La rete è "piatta"
Nella praticità è diverso.
*Scalabilità*: Miliardi di destinazioni:
- Non può memorizzare tutte le destinazioni nelle tabelle di instradamento;
- L'invio in broadcast degli aggiornamenti sullo stato dei link otturerebbe i collegamenti;
- Gli algoritmi DV impiegherebbero tempo enorme per convergere.
*Autonomia amministrativa*:
- Internet come una rete di reti;
- Ogni amministratore di rete può voler controllare l'instradamento nella propria rete o nascondere dettagli della sua struttura interna.

## Approccio di Internet al routing scalabile
L'idea è di aggregare i router in regioni note come *sistemi autonomi* ( SA, anche detti **domini**), formati di solito da router sottoposti alla stessa amministrazione.
Un ISP può costituire un unico AS oppure essere partizionato in più AS.
AS identificati da un Autonomous System Number (ASN).
**intra-AS** (o *intra-domain*): instradamento interno al sistema autonomo ("rete"):
- Tutti i router nell'AS devono eseguire lo stesso protocollo di instradamento interno al sistema autonomo;
- AS differenti possono eseguire differenti protocolli di instradamento interno al sistema autonomo
- *Router Gateway*: sul "bordo" (*edge*) del proprio AS, connesso a uno o più router in altri AS.
**inter-AS** (o *inter-domain*): instradamento *tra* sistemi autonomi:
- I gateway effettuano l'instradamento inter-AS.

![[Ch. 4.2 - Rete p. Controllo-1781100712486.png]]
![[Ch. 4.2 - Rete p. Controllo-1781100718824.png]]
![[Ch. 4.2 - Rete p. Controllo-1781100736732.png]]

### Instradamento inter-AS
Si supponga che un router dentro AS1 riceva un datagramma destinato al di fuori di AS1:
- Il royter dovrebbe inoltrare il pacchetto ad un router gateway in AS1, ma quale?
**L'instradamento inter-AS in AS1 deve**:
1. Imparare quali destinazioni sono raggiungibili attraverso AS2 e quali atttraverso AS3
2. Propagare queste informazioni di raggiungibilità a tutti i router in AS1:
![[Ch. 4.2 - Rete p. Controllo-1781100894947.png]]
### Instradamento intra-AS
Protocolli di instradamento intra-AS più comuni:
- **RIP: Routing Information Protocol**
	- DV classico: DV scambiati ogni 30sec
	- Non più largamente usato
- **EIGRP: Enhanced Interior Gateway Routing Protocol**
	- Basato su DV
	- Precedentemente di proprietà di CISCO per decenni
- **OSPF: Open Shortest Path First**
	- Instradamento link-state
	- Protocollo IS-IS(ISO standard, non standard RFC) essenzialmente identico a OSPF.

## OSPF
Disponibile pubblicamente, classico link-state:
- Ciascun router utilizza il *flooding* per inviare in broadcast (periodicamente, ogni 30min) le informazioni circa lo stato dei collegamenti (direttamente dentro datagrammi IP senza usare TCP/UDP) a tutti gli altri router nell'intero AS;
- Costo dei collegamenti: inversamente proporzionale alla larghezza di banda;
- Ogni router dispone di una topologia completa, utilizza l'algoritmo di Dijkstra per calcolare la tabella di inoltro.
**Sicurezza**: Tutti i messaggi OSPF sono autenticati per prevenire intrusioni dannose.

### ECMP Routing
	Equal-Cost Multi-Path routing
L'**instradamento ECMP** consente di instradare i pacchetti verson una stessa destinazione usando molteplici percorsi di uguale costo (verso un certo prefisso) *aumentando la larghezza di banda*.
Un router che deve inoltrare un pacchetto fa *load balancing* tra i possibili *next hop*:
- **Per flusso**: Ne segue che tutti i pacchetti che appartengono al medesimo flusso attraversano lo stesso percorso
- **Per destinazione**: Ne segue che i pacchetti che hanno lo stesso IP di destinazione attraversano lo stesso percorso
- **Per pacchetto**: Ne segue che ogni pacchetto per una stessa destinazione può seguire un percorso differente. Può creare problemi a TCP a causa di:
	- Consegna fuori ordine
	- Variabilità del ritardo
	- Variabilità della MTU minima
### OSPF Gerarchico
**Gerarchia a due livelli**: Area locale, dorsale (backbone)
- Annunci link-sttae inondati solo in area locale o dorsale
- Ogni nodo ha una topologia dettagliata dell'area; conosce solo la direzione per raggiugere altre destinazioni.
![[Ch. 4.2 - Rete p. Controllo-1781532933711.png]]
# Instradamento tra sistemi autonomi: BGP
## Instradamento Internet inter-AS: BGP
**BGP**(*Border Gateway Protocol*): Il protocollo di fatto per l'instradamento inter-domain.
Permette alla sottorete di pubblicizzare la sua esistenza e le destinazioni che può rggiungere al resto di internet. BGP fornisce a ciascun AS un mezzo per:
- Ottenere informazioni sulla raggiungibilità dei prefissi di sottorete da parte dei sistemi confinanti (*eBGP*)
- Determinare le rotte verso altre reti sulla base delle informazioni di raggiungiblità e di politiche
- Propagare le informazioni di raggiungiblità a tutti i router interni all'AS (*iBGP*)
- *Annunciare* alle reti confinanti le informazioni sulla raggiungibilità delle destinazioni.
![[Ch. 4.2 - Rete p. Controllo-1781533228861.png]]

## Nozioni base su BGP
**Sessione BGP**: Due router BGP (peers) si scambiano messaggi BGP attraverso una connessione TCP semi-permanente:
- Annunciare *percorsi* verso diversi prefissi di rete
Quando il gateway 3a di AS3 annuncia il *percorso AS3,X* al gateway di 2c di AS2:
- AS3 *promette* a AS2 che inoltrerà i datagrammi verso X
![[Ch. 4.2 - Rete p. Controllo-1781533357421.png]]

### Messaggi BGP
I messaggi BGP sono scambiati tra peer su connessioni TCP:
- `OPEN`: Apre la connessione TCP al peer BGP remoto ed autentica il peer BGP mittente
- `UPDATE`: Annuncia un nuovo percorso (o ritira il vecchio)
- `KEEPALIVE`: Mantiene attiva la connessione in assenza di `UPDATE`; Inoltre ACK della richiesta `OPEN`
- `NOTIFICATION`: Segnala gli errori nel messaggio precedente; viene usato anche per chiudere la connessione.
### Attributi e Rotte
**Rotta** (route) annunciata da BGP: prefisso + attributi
- Prefisso: la destinazione che viene annunciata;
- Due attributi importanti:
	- `AS-PATH`: Elenco degli AS attraverso i quali è passato l'annuncio del prefisso
	- `NEXT-HOP`: Indirizzo IP dell'interfaccia del router che inizia l'`AS-PATH`
**Instradamento basato su politiche**
Un gatewy che riceve un annuncio di percorso usa una *import policy* per accettare/declinare il percorso. Le politiche dell'AS determinano anche se *annunciare* un percorso ad altri AS vicini.

![[Ch. 4.2 - Rete p. Controllo-1781533713917.png]]

**PERCORSI MULTIPLI**:![[Ch. 4.2 - Rete p. Controllo-1781533766596.png]]
Un **router gateway** potrebbe venire a conoscenza di percorsi *multipli* verso una certa destinazione.

**Popolare le tabelle di inoltro**
![[Ch. 4.2 - Rete p. Controllo-1781533826748.png]]

**Instradamento a patata bollente**
![[Ch. 4.2 - Rete p. Controllo-1781533863948.png]]

#### Selezione delle rotte BGP
Un **router** può conoscere più di un percorso verso l'AS di destinazoine, seleziona il percoros in base a:
- Valore dell'attributo di *preferenza locale*: decisione politica
- `AS-PATH` più breve
- Router `NEXT-HOP` più vicino: instradamento a patata bollente
- Identificatori BGP
## Implementare le politiche attraverso gli annunci
![[Ch. 4.2 - Rete p. Controllo-1781535333734.png]]
L'ISP vuole instradare il traffico solo verso/da le reti dei propri clienti:
- A annuncia il percorso Aw a B e a C
- B *sceglie di non annunciare* BAw a C
	- B non riceve alcuna "entrata" per l'instradamento CBAw, visto che né C, A,w sono clienti di B
	- C *non* viene a conoscenza del percorso CBAw
- C instraderà CAw (non usando B) per raggiungere w

### Diversi tipi di instradamento
Perché esistono diversi instradamenti Intra-AS e Inter-AS?
1. Politiche
	- inter-AS: L'amministratore vuole avere il controllo sul modo in cui viene instradato il suo traffico **e** su chi passa attraverso la sua rete
	- intra-AS: Singolo amministratore, quindi le politiche sono meno rilevanti
2. Scalabilità
	- Routing gerarchico: Limita l'ambito delle informazioni topologiche dettagliate al singolo AS
	- Instradamento BGP verso prefissi per supportare un gran numero di destinazioni
3. Prestazioni
	- intra-AS: Può concentrarsi sulle prestazioni
	- inter-AS: le politiche sono dominanti rispetto alle prestazioni

# Piano di controllo SDN
**Software Defined Networking**
Livello di rete di internet: storicamente implementato tramite un approccio di controllo distribuito e per router:
- Un *router monolitico* contiene l'hardware di commutazione (switching), esegue un'implementazione proprietaria dei protocolli standard di internet in un SO proprietario specializzato per dispositivi di rete
- "middlebox" differenti per differenti funzioni del livello di rete: firewalls, load balancers, NAT,...

**Piano di controllo per router**
I singoli componenti dell'algoritmo di instradamento *in ogni router* interagiscono nel piano di controllo.![[Ch. 4.2 - Rete p. Controllo-1781535927867.png]]

**Piano di controllo SDN**
Il controller remoto calcola ed installa le tabelle di inoltro nei router
![[Ch. 4.2 - Rete p. Controllo-1781535972041.png]]

*Perché* un piano di controllo *logicamente centralizzato*?
- Gestione più semplice della rete: evitare errori di configurazione dei router, maggiore flessibilità dei flussi di traffico
- Inoltro basato sulle tabelle dei flussi, permette la "programmazione" dei router
	- La programmazione centralizzata è più semplice: calcola le tabelle centralmente e poi le distribuisce
	- La programmazione distribuita è più difficile: calcolo delle tabelle come risultato di un algoritmo (protocollo) distribuito implementato in ogni singolo router
- Implementazione aperta (non proprietaria) del piano di controllo
	- Promuove l'innovazione

## Ingegneria del traffico
L'**Ingegneria del traffico** (TE) si occupa dell'ottimizzazione delle prestazioni delle reti in esercizio. In generale, comprende l'applicazoine della tecnologia e dei principi scientifici alla misurazione, alla modellazione, alla *caratterizzazione* **e** al *controllo del traffico* Internet, e l'applicazione di tali conoscenze e tecniche per *raggiungere specifici obiettivi di prestazione*.

**Difficile con il routing tradizionale**
![[Ch. 4.2 - Rete p. Controllo-1781536328704.png]]
![[Ch. 4.2 - Rete p. Controllo-1781536347694.png]]

### Estensioni in OSPF
OSPF è stato esteso con la possibilità di annunciare informazioni utili al Traffic Engineering, quali banda disponibile, ritardo, jitter, perdita ecc..
OSPF però non sfrutta questi dati per ricalcolare i propri percorsi.
In particolare, tecnologie come MPLS (MultiProtocol Label Switching) possono usare queste informazioni. Anziché limitarsi all'inoltro tradizionale basato solo sui percorsi di destinazione, MPLS-TE permette di instradare i flussi su cammini alternativi. In questo modo si tiene conto della congestione di rete e si massimizzano le prestazioni.
![[Ch. 4.2 - Rete p. Controllo-1781536550988.png]]

**Switch del piano dei dati**![[Ch. 4.2 - Rete p. Controllo-1781536683940.png|200]]

- Switch veloci e semplici che implementano l'inoltro generalizzato del piano dei dati in hardware
- Tabella dei flussi (inoltro) calcolata, installata sotto la supervisione del controllore
- API per il controllo degli switch basato su tabelle
	- Definisce ciò che è controllabile e ciò che non lo è
- Protocollo di comunicazione con il controllore


**SDN Controller**![[Ch. 4.2 - Rete p. Controllo-1781536859529.png|200]]

- Mantiene le informazioni sullo stato della rete
- Interagisce con le applicazioni di controllo della rete "in alto" tramite API "northbound"
- Interagisce con gli switch di rete "in basso" tramite API "southbound"
- Implementato come sistema distribuito per garantire prestazioni, scalabilità, tolleranza ai guasti, robustezza e sicurezza

**Applicazioni di controllo di rete**![[Ch. 4.2 - Rete p. Controllo-1781536989848.png|200]]

- "Cervelli" di controllo: Implementano le funzioni di controllo utilizzando servizi di livello inferiore attraverso API fornite dal controller SDN
- *scorporate*: Può essere fornito da terzi (distinto dal dornitore di routing o dal controller SDN)



**Componenti di un Controller SDN**
pdf21sl46