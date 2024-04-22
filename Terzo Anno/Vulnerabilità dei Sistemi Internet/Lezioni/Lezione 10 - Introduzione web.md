# Web Applications
Le applicazioni web sono:
- Spesso molto più utili dei software desktop, e di conseguenza più popolari
- Spesso disponibili pubblicamente
- Un bersagli facile per chi attacca
- Facili da sviluppare ( tralasciando la sicurezza )
## Minacce
>Deturpazione web
>- Perdita di reputazione ( clientela, accordi )
>- Paura, incertezza e dubbio

>Divulgazioni di informazioni confidenziali
>- Segreti finanziari, database della clientela, cartelle cliniche, documenti governativi

>Perdita di dati

>Accessi non autorizzati
>- Abuso delle funzionalità dell'applicazione

>Negazione di servizi
>- Perdita di disponibilità o di funzionalità

## Top 10 OWASP
	OWASP (Open Web Application Security Project)
- A1: Injection
- A2: Broken Auth and Session Management
- A3: Cross-Site Scripting (XSS)
- A4: Insecure Direct Object References
- A5: Security Misconfiguration
- A6: Sensitive Data Exposure
- A7: Missing Function Level Access Controll
- A8: Cross-Site Request Forgery (CSRF)
- A9: Using Components with Known Vulnerabilities
- A10: Unvalidated Redircts and Forwards
## Client-Server - No Trust
> ***La sicurezza nel lato client non funziona* ( e non può funzionare)**
>- Non fare affidamento al client per eseguire controlli di sicurezza
>- `<input type="text" maxlength"20">` non è abbastanza
>- L'autenticazione deve essere fatta lato server

>***Non fare affidamento al tuo client***
>- HTTP Response Header Fields come cookies ecc...
>- HTTP query string values 
>- `<input type="hidden" name="price" value="299">` in uno shop online potrà essere abusato (e lo sarà)

>***Esegui tutti i controlli di sicurezza sul lato server***
>- Non aspettarti che i tuoi client ti mandino query SQL, comandi shell (ecc...) da eseguire.
>- Inserisci limiti sul numero di connessioni e imposta dei timeout

### Consigli
> ***Proteggi dati e codici***
> Fai in modo che non possano essere facilmente scaricati o che siano di accesso pubblico:
> - File di password
> - File `.htaccess`
> - File `.bak`, `.old`, `.php` ecc... con codici sorgente

>***Vieta l'indicizzazione delle directory***
>- Su apache utilizza `Options -Indexes`

## Indurimento del Web server
- *Spoglia* le configurazioni di sistema
	- Tieni solo pacchetti necessari, account, processi e  servizi
- *Rattoppa* OS, Web Server e Web Applications
	- Utilizza patch automatiche se possibile
- Utilizza un *firewall locale*
	- In modo da permettere solo ciò che ci si aspetta
- *Indurisci* le configurazioni del Web server
	- Incluse piattaforme di programmazione
- Esegui Web server come *utente regolare* (**non privilegiato**)
- Utilizza i *log*
## Programmazione di PHP
- Disabilita `allow_url_fopen` e `allow_url_include`
- Disabilita `register_globals`
- Usa `E_STRICT` per trovare variabili non inizializzate
- Disabilita `display_errors`
- Non lasciare i file `phpinfo()` nella versione di produzione
# Architettura Web
I Web Server sono costantemente e direttamente attaccati da hacker. Il loro obiettivo *di solito* varia tra nascondere furtivamente dei malware nel sito per bersagliare i loro utenti, al furto di informazioni degli utenti dai database
![[Pasted image 20240422112555.png|center|500]]
## Attacco del Server
![[Pasted image 20240422112617.png|center|500]]
## Attacco lato client
Gli utenti sono spesso attaccati da contenuti sospetti che eseguono codici sulle loro macchine. Tipicamente viene sfruttato lo scripting lato client (js, actionscript, vbscript, html5,...)
![[Pasted image 20240422113404.png|center|500]]
![[Pasted image 20240422113426.png|center|500]]
### Web Privilege Escalation
![[Pasted image 20240422113506.png|center|500]]
# DVWA
	Damn Vulnerable Web Application
Si tratta di una web application PHP/MySQL che contiene la maggior parte delle vulnerabilità della Top Ten di OWASP. Viene usata per verificare le proprie conoscenze e l'effettiva funzione dei framework di sicurezza.
## Installazione
`sudo docker run --rm -it -p 80:80 vulnerables/web-dvwa`
Apri il browser e connettiti ad http://127.0.0.1
Credenziali:
- Username: admin
- Password: password