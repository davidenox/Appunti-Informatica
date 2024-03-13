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
