# Cos'è una pagina web?
Una pagina web è una risorsa (es. file)  specificata da un **URL** *(Uniform Resource Locator)*:
![[Pasted image 20240313112827.png|center|500]]
## I componenti della URL
1. **Protocollo**: Come si può accedere alla risorsa web? 
	1. Es. `http`, `https`, `ftp` ...
2. **Dominio**: Dove è localizzata la pagina?
	1. Es. `google.com`, ...
3. **SubDominio**: In quale host specifico del dominio?
	1. Es. `netgroup`, `www`, ...
4. **Percorso** della risorsa: Qual è il percorso/nome specifico della risorsa?
	1. Es. `index.html`, `home.php`, ...
# Cos'è un protocollo?
Un protocollo è un linguaggio comune tra client e server che definisce un set comune di regole e messaggi che permetto al client di essere capito dal server:
- Web $\rightarrow$ HTTP
- E-mail $\rightarrow$ SMTP
- File transfer $\rightarrow$ FTP
## Protocollo HTTP
![[Pasted image 20240313113638.png|center|500]]
## Protocollo SMTP
![[Pasted image 20240313113807.png|center|500]]
# Le applicazioni gestiscono i protocolli
![[Pasted image 20240313114124.png|center]]
![[Pasted image 20240313114141.png|center|600]]
# Il dominio è tradotto in numero
Abbiamo bisogno dell'indirizzo preciso del server della risorsa.
- Dovrebbe essere unico nel mondo.
 ![[Pasted image 20240313114744.png|center|600]]
## DNS
![[Pasted image 20240313120235.png|center|500]]
### Indirizzo IP o MAC?
Le reti fisiche non utilizzano l'indirizzo IP:
- L'indirizzo IP dipende dalla rete a cui sei connesso
- Cosa accade  se ti sposti da quella rete ad un'altra?
C'è bisogno di utilizzare l'indirizzo prestampato della tua scheda di rete: l'indirizzo MAC
![[Pasted image 20240313120436.png|center|500]]
## Address Resolution Protocol
![[Pasted image 20240313120544.png|center|500]]
![[Pasted image 20240313120647.png|center|500]]
## Client-Server Model Overview
Client chiede (*request*)$\implies$ Server fornisce (*response*)
Tipicamente: Single Server - Multiple Clients
![[Pasted image 20240313121522.png|center|500]]
Indirizza la macchina in rete dall'indirizzo IP.
Indirizza il processo dal numero della "porta".
La coppia indirizzo IP+porta costituisce un "indirizzo-socket".
![[Pasted image 20240313121855.png|center|600]]
## Client
Es. di programmi client: 
- Web Browsers
- FTP
- Telnet
- SSH
Come fa un client a trovare il server?
- L'indirizzo IP nell'indirizzo del socket del server identifica l'host fisico
- La (ben conosciuta) porta nell'indirizzo del socket del server identifica il servizio
	- Implicitamente identifica il processo del server che eroga quel servizio
Esempi di porte conosciute:
- Porta 7: server Echo
- Porta 23: server Telnet
- Porta 25: server Mail
- Porta 53: DNS
- Porta 80: server Web
### Utilizzo delle porte per l'identificazione dei servizi
![[Pasted image 20240313130132.png|center|500]]
# Kali Linux
## Avviare Kali
Kali Linux contiene oltre 300 strumenti di penetration testing. Le credenziali iniziali della VM di Kali sono:
- *Username*: kali
- *Password*: kali
Il menù di Kali presenta un grande numero di strumenti
## Find, Locate, Which
Per poter utilizzare lo strumento `locate`, è necessario eseguire `updatedb`:
- Esso crea un database locale di tutti i file nel filesystem;
- Una volta creato il db, `locate` può essere utilizzato facilmente per chiedere al database dove sono i file in locale:
![[Pasted image 20240313132215.png|center|500]]
Il comando `which` cerca tra le cartelle definite nel percorso, e se viene trovata la coincidenza, `which` rimanda il percorso completo del file cercato:
![[Pasted image 20240313132351.png|center|500]]
Il comando `find` è un comando più aggressivo di `locate` o `which`. 
- `find` è capace di cercare ricorsivamente qualsiasi percorso dato per vari file
- Ha una moltitudine di opzioni per gli attributi dei file:
![[Pasted image 20240313132600.png|center|500]]
## Bash
Immagina di essere incaricato di:
- Trovare tutti i subdomini listati nella index page di cisco.com 
- Trovare i loro corrispettivi indirizzi IP
Inizia scaricando la pagina index di cisco.com usando il comando `wget`:
![[Pasted image 20240313132837.png|center|500]]
![[Pasted image 20240313132903.png|center|500]]
## netcat
Connettersi ad una porta TCP/UDP può essere molto utile in molteplici situazioni:
- Per verificare se una porta è aperta o chiusa
- Per leggere il banner dalla porta
- Per connettersi ad un servizio di rete manualmente.
![[Pasted image 20240313133055.png|center|600]]
![[Pasted image 20240313133109.png|center|600]]
![[Pasted image 20240313133123.png|center|600]]
![[Pasted image 20240313133142.png|center|600]]

`netcat` può essere utilizzato anche per il trasferimento di file:
- *Sender side*: nc -w 3 $\text{[destination] [port] < [file]}$
- *Receiver side*: nc -l -p $\text{[port] > [file]}$
![[Pasted image 20240313133523.png|center|500]]
## Wireshark
Gli sniffer di rete come wireshark sono molto utili per:
- Capire un protocollo
- Fare il debug di un client di rete
- Analizzare il traffico nella tua rete
![[Pasted image 20240313133833.png|center|500]]

## tcpdump
Esiste la possibilità di non poter accedere alla UI di sniffer di rete come Wireshark. In questo caso, si può usare il comando da terminale `tcpdump`:
```Shell
tcpdump -r password_cracking_filtered.pcap
tcpdump -n -r password_cracking_filtered.pcap | awk -F" " '{print $3}' | sort -u | head
tcpdump -n src host 172.16.40.10 -r password_cracking_filtered.pcap
tcpdump -n dst host 172.16.40.10 -r password_cracking_filtered.pcap
tcpdump -n port 81 -r password_cracking_filtered.pcap
tcpdump -nX -r password_cracking_filtered.pcap
tcpdump -A -n 'tcp[13] = 24' -r password_cracking_filtered.pcap
tcpdump -A -n -r password_cracking_filtered.pcap | grep "HTTP/1.1 ”
```

# Introduzione ai framework di penetration test
## Metasploit
Molto conosciuto, usato per generare *payloads* che possono essere usati per sfruttare delle particolari vulnerabilità. Supporta i payloads e exploits di molti protocolli, linguaggi e framework come :
- HTTP/S
- MySQL
- SSH
Inoltre, permette la generazione di artefatti automatici come `bind`/`reverse shell` per Linux/Windows ecc...
## SQL Map
Framework utile per test e automazione di *SQL Injections*. Supporta in generale tutti i database commerciali:
- MySQL
- Oracle
- PostreSQL
- Microsoft SQL Server
- ...
È open source