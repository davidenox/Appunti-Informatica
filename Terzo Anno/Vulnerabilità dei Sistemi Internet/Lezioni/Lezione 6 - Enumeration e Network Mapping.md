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
work in progress