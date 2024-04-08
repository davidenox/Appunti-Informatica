# Enumeration
## Domain Name tradotto in numero
![[Pasted image 20240404155729.png|center|500]]
## Client-Server Model Overview
Client e Server sono processi eseguiti su macchine fisiche
![[Pasted image 20240404155911.png|center|600]]
- Indirizza la macchina sulla rete tramite l'indirizzo IP;
- Indirizza il processo tramite il numero della "porta".
La coppia di Indirizzo IP + porta crea un *socket-address*:
![[Pasted image 20240404160154.png|center|600]]
## Client
Esempi di programmi client:
- Web browsers
- `ftp`
- `telnet`
- SSH
Come fa un Client a trovare il Server?
- L'indirizzo IP nel'indirizzo del server socket identifica l'host fisico;
- La (conosciuta) porta nell'indirizzo del server socket identifica il servizio;
	- Identifica implicitamente il processo del server che eroga quel servizio.
Esempi di porte conosciute:
- *Porta 7*: Server Echo;
- *Porta 23*: Server Telnet;
- *Porta 25*: Server Mail;
- *Porta 53*: DNS;
- *Porta 80*: Web Server.
## Utilizzo delle porte per identificare i servizi
![[Pasted image 20240404160719.png|center|500]]
![[Pasted image 20240404160741.png|center|600]]

# Valutazione delle vulerabilità e PenTest
	Ricognizione attiva: PORT SCANNING
## Scansionare la rete
Nel momento in cui un hacker viene a sapere dell'esistenza di una rete, il passo successivo è quello di mappare la rete. Per avere una lista di sistemi, gli hacker scansionano utilizzando una varietà di strumenti e tecniche.
La scansione di una rete può essere eseguita dall'amministratore di rete per:
- Valorizzare la prospettiva dell'hacker sulla rete
- Esercitarsi con comuni attrezzi di scansione, col beneficio della conoscenza di essi
- Mettere sotto stress i meccanismi di monitoraggio come IDS
- Documentare la struttura della rete
- Verificare i dispositivi di controllo di accesso sulla rete, configurazioni dell'host e molto altro.
`Nmap, Zenmap, Unicorn, Netcat,Telnet, ...`
## TCP: Stretta di mano a tre
![[Pasted image 20240404161820.png|center|500]]
![[Pasted image 20240404161841.png|center|500]]
![[Pasted image 20240404161853.png|center|500]]
![[Pasted image 20240404161903.png|center|500]]
![[Pasted image 20240404161912.png|center|500]]
![[Pasted image 20240404161922.png|center|500]]
![[Pasted image 20240404161931.png|center|500]]
## TCP SYN Scan
Fa affidamento al meccanismo di stretta di mano a tre del TCP:
- Due host che stanno per comunicare possono negoziare i parametri della connessione socket TCP di rete prima di trasmettere dati.
- Tentano di completare il legame con l'host target sulla/e porta/e specifica/he.
- Se il legame è completato allora la porta è aperta.
`nc -n -vv -w 1 -z <ip address> <port range>`
![[Pasted image 20240405113343.png|center|600]]
![[Pasted image 20240405113404.png|center|600]]
## UDP Scan
Il meccanismo dietro lo scan delle porte UDP è diverso:
- UDP non utilizza la stretta di mano a tre;
- UDP è senza stati;
- Utilizza *wireshark* mentre UDP scansiona una macchina con *netcat* per capire come funziona la scansione delle porte UDP.
`nc -nv -u -z -w 1 <ip target> <port range>`
Un pacchetto UDP vuoto viene mandato ad una porta specifica:
- Se la porta UDP è aperta, non viene mandato un segnale di riposta dal target;
- Se la porta UDP è chiusa, dovrebbe essere inviato un pacchetto inarrivabile da una porta ICMP  dalla macchina target.
# Nmap
`nmap` è uno dei port scanner più popolare, versatile e robust0. È stato sviluppato attivamente per una decade ed ha una larga varietà di strumenti per il port scanning.
Una scansione `nmap` TCP scansionerà le 1000 porte più usate sulla macchina target.
`nmap <scantype> <options> <ip address>`
Abbiamo 3 stati differenti:
- Open
- Filtered
- Close
![[Pasted image 20240405114842.png|center|500]]
### Scansione di un range specifico di porte
`nmap <ip address> -p25-150`
![[Pasted image 20240405114955.png|center|500]]
### Scansione di una subnet
`nmap <network address>/24 -p80`
![[Pasted image 20240405115107.png|center|500]]
### Spoofing e scansione dell'esca
Spesso vogliamo nascondere il nostr0 IP ( o identità ):
- Ogni pacchetto deve contenere il nostro codice sorgente altrimenti la risposta dalla macchina target non saprà dove rispondere.
- Possiamo *beffare* il nostro indirizzo IP (`-S`) per qualsiasi richiesta ed ogni risposta verrà inviata ad un IP falso.
- Possiamo *offuscare* (`-D`) il nostro indirizzo IP tra altri indirizzi IP.
`nmap <ip address> -D <fake ip list>`
### Evasione Firewall
Nmap, in maniera predefinita, invia un `ping` per vedere se l'host del target è up.
- Diversi firewall e router bloccano o rigettano il ping ICMP;
- Possiamo impedire a nmap di inviare questo "ping di prova" per raggirare eventuali blocchi;
- Possiamo farlo con lo switch `P0`:
`nmap -P0 <ip address>`
![[Pasted image 20240408111029.png|center|500]]
Quando nmap esegue una scansione delle porte,
- Recupera le informazioni della porta ( aperta/chiusa/filtrata ) e restituisce con il servizio *predefinito* che viene eseguito su quella porta.
- Siccome si può eseguire un qualsiasi esercizio su una qualsiasi porta, potrebbe non essere un'informazione adeguata, poiché si vorrebbe sapere quale servizio si sta eseguendo su quella porta, e non quello di default.
- Nmap ha un'opzione che interroga il servizio che viene eseguito su ogni porta scansionata, tramite l'operatore `-V`:
`nmap -sV <ip address>`
## TCP Connect Scan
	-sT

![[Pasted image 20240408111954.png|center|500]]
### Svantaggi
Lo svantaggio di questa scansione è quello di essere una scansione molto "rumorosa":
- Controlla il log di connessione dell'applicazione;
- Finchè la scansione TCP sta per completare una connessione TCP, i processi di normale applicazione seguono immediatamente;
- Queste applicazioni incontrano immediatamente un pacchetto RST
È consigliabile utilizzare lo scan TCP come ultima spiaggia
## TCP SYN Scan 
	-sS

La scansione TCP SYN utilizza metodi comuni per l'identificazione delle porte, che da la possibilità ad nmap di ricavare informazioni sulle porte aperte prima che si completi il collegamento TCP. Quando viene identificata una porta aperta:
- Il collegamento TCP viene resettato prima di essere completato;
- Questa tecnica è spesso chiamata "scansione *mezza aperta*".
![[Pasted image 20240408112724.png|center|500]]
### Vantaggi
La scansione TCP SYN non crea mai in realtà una sessione TCP, ed è una scansione molto più *silenziosa* del TCP Connect, con meno visibilità per il sistema di destinazione. Siccome la sessione TCP non viene mai iniziata, SYN è anche molto meno stressante per i servizi delle applicazioni.
## Scansioni Stealth
- FIN Scan (`-sF`);
- Xmas Scan (`-sX`);
- NULL Scan (`-sN`);

Vengono chiamate scansioni "Stealth" perché inviano un singolo frame ad una porta TCP senza nessuna connessione TCP o pacchetti trasferiti in eccesso. Queste scansioni operano tramite la manipolazione dei bit del TCP Header per introdurre una risposta dalla stazione remota. 
Ad eccezione della scansione SYN, `nmap` crea TCP Headers che combinano le opzioni di bit che non dovrebbero mai accadere nel mondo reale.
Il protocollo TCP stabilisce che le stazioni riceventi informazioni (su una porta TCP chiusa dovrebbe inviare un frame RST) e una porta TCP disponibile non dovrebbe rispondere affatto. Durante una qualsiasi di queste scansioni invisibili, nmap classifica le risposte come chiuse o aperte|filtrate .
È impossibile determinare se la risposta mancante è dovuta a una porta aperta o a una connessione di rete filtrata
- non c'è modo di distinguere tra una porta aperta e un frame eliminato a livello amministrativo.
A causa di questi pacchetti "*personalizzati*".
- nmap richiede un accesso privilegiato per eseguire scansioni invisibili
### FIN Scan
![[Pasted image 20240408114035.png|center|500]]
### Xmas Scan
![[Pasted image 20240408114057.png|center|500]]
### NULL Scan
![[Pasted image 20240408114120.png|center|500]]
## Version Detection
	nmap -sV <ip address>

![[Pasted image 20240408120231.png|center|500]]
## Scan Timing
![[Pasted image 20240408120335.png|center|500]]
### Temporizzare la scansione
![[Pasted image 20240408120407.png|center|500]]
