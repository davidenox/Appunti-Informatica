Prof. Alberto Caponi
# Programma approssimativo
- Introduzione
- Strumenti e pratiche raccomandate
	- Kali Linux e Metasploit
- Raccolta di informazioni
	- Ingegneria sociale
- Vulnerabilità e scansione
- Network Hacking
- Sicurezza delle password
- Sicurezza wireless
- Sfruttamento delle applicazioni web
- Escalation di privilegi
- Post-sfruttamento
Dal punto di vista difensivo (più o meno).
# Sicurezza con Alice e Bob
Come può Alice comunicare con Bob senza che Eve possa modificare o estrapolare informazioni sulla comunicazione?
> Tramite un canale di comunicazione sicuro (es. TLS/SSL)

![[Pasted image 20240312142902.png|center|400]]
## Cos'è l'heartbleed?
Esso sfrutta una vulnerabilità in OpenSSL
- Utilizzato per implementare il protocollo *TLS* (Transport Layer Security);
- Usato sul web, mobile, messaggistica istantanea, ecc..
Espone:
- Le password dell'utente
- I Cookies e altri dati sensibbili
- La *Chiave Privata* del Server
Non è un Malware!
## Come funziona?
![[Pasted image 20240312143501.png|center|700]]

# Messaggi Take-Home
L'input dell'utente potrebbe:
- Avere il valore sbagliato
- Avere la dimensione o il formato sbagliati
- Provenire da un utente autorizzato ma malintenzionato
- Provenire da un utente non autorizzato ( o essere modificato da un utente malintenzionato)
L'input dell'utente deve essere validato nella forma e nel contenuto:
- Le funzioni di sicurezza non dovrebbero mai fidarsi di input da un utente non validato
- L'input dannoso a funzioni che non sono di per sé legate alla sicurezza può comunque causare errori di sicurezza.
È difficile mantenere il software:
- Non sempre implementa ciò che ci aspettiamo
- È configurato dagli esseri umani
- È soggetto a errori
$$\text{Theory}\neq\text{Real World}$$
#  Black hat e White hat
>[!important]- White Hat Hackers
>Sono le persone *buone*.
>Sono esperti di informatica:
>- Specializzati in Penetration Testing
>- Per assicurarsi che i sistemi di informazione di un'azienda sono sicuri
>- Cercano difetti di sicurezza e vulnerabilità non per sfruttamento, ma in modo che la loro scoperta si traduca nella loro correzione, a vantaggio del bene comune

>[!danger]- Black Hat Hackers
>Questi sono i cattivi.
>- Solitamente definiti semplicemente hacker 
>- Cercano l'accesso non autorizzato ai sistemi senza acquisire legale autorizzazione. 
>La motivazione è per il vantaggio personale:
>- Creazione di ricchezza materiale tramite spambot e botnet, acquisizione informazioni lucrative, ricatto
>- Vendetta (deturpazione o vandalismo del sito web solo per divertimento)
>- Generalmente per essere pagati

## I Black Hat sono..
**Hacker sponsorizzati dallo Stato**
- I governi di tutto il mondo si rendono conto che ora si tratta solo di controllare il cyberspazio
- Dispongono di tempo e finanziamenti illimitati per colpire civili, aziende e governi
**Spia Hacker**
- Le aziende assumono hacker per infiltrarsi nella concorrenza e rubare segreti commerciali
- Potrebbero hackerare il sistema dall'esterno o trovare lavoro per agire come talpe
- Gli hacker spia possono utilizzare tattiche simili a quelle degli hacktivisti, ma il loro unico scopo è servire gli obiettivi dei loro clienti ed essere pagati.
**Terroristi informatici**
- Questi hacker, generalmente motivati ​​da convinzioni religiose o politiche, tentano di creare paura e caos distruggendo le infrastrutture critiche
- I cyberterroristi sono di gran lunga i più pericolosi, con una vasta gamma di competenze e obiettivi
- La motivazione principale dei cyberterroristi è diffondere paura, terrore e commettere omicidi
## Penetration Tester vs Hackers
Qual è la differenza tra un Pen Tester e un Hacker?
- I PenTester hanno la previa approvazione del cliente;
- Gli hacker hanno la previa approvazione da parte loro

- Gli attacchi di ingegneria sociale di PenTester sono lì per aumentare la consapevolezza
- Gli attacchi di ingegneria sociale degli hacker mirano a divulgare informazioni sensibili sul luogo in cui si trova il loro obiettivo.
Senza permesso, è *ILLEGALE*.
# Capacità degli hacker
Competenze *informatiche* di base:
- Queste competenze vanno oltre la capacità di creare un documento Word o navigare in Internet...
Competenze di *rete*:
- DHCP, NAT, subnetting, IPv4, IPv6, IP pubblico e privato, DNS, router e switch, VLAN, modello OSI, indirizzamento MAC, ARP, ecc.
- Meglio capirai come funzionano, maggiore sarà il tuo successo.
Competenze *Linux*:
- È estremamente fondamentale sviluppare competenze Linux per diventare un hacker. Quasi tutti gli strumenti che utilizziamo come hacker sono sviluppati per Linux
- Linux ci offre funzionalità che non abbiamo utilizzando Windows
Concetti e tecnologie di *sicurezza*:
- L'unico modo per superare gli ostacoli stabiliti dagli amministratori della sicurezza è conoscerli
- L'hacker deve comprendere cose come PKI (infrastruttura a chiave pubblica), SSL (secure sockets layer), IDS (sistema di rilevamento delle intrusioni), firewall, ecc.
*Scripting*:
- Per sviluppare i tuoi strumenti unici, dovrai diventare esperto almeno in uno dei linguaggi di scripting
- Dovrebbero includere uno tra Perl, Python o Ruby.
*Applicazioni Web* e *database* :
- Quanto più si comprende il funzionamento delle applicazioni Web e i database che ne stanno alla base, tanto più successo si avrà.
- Inoltre, probabilmente dovrai creare il tuo sito web per phishing e altri scopi nefasti.
*Reti* e *crittografia avanzate*:
- È necessario comprendere nei dettagli più intimi lo stack e i campi dei protocolli di rete
- Sebbene non sia necessario essere un crittografo per essere un buon hacker, più si comprendono i punti di forza e punti deboli di ciascun algoritmo crittografico, maggiori saranno le possibilità di sconfiggerlo.
*Reverse Engineering*:
- Il reverse engineering consente nell'aprire un pezzo di malware e ricostruirlo con funzionalità aggiuntive e capacità.
*Pensare in modo creativo*:
- Esiste SEMPRE un modo per hackerare un sistema e molti modi per realizzarlo. Un buon hacker può pensare in modo creativo diversi approcci allo stesso hack.
Capacità di *Problem-Solving*:
- Un hacker si trova sempre a dover affrontare problemi apparentemente irrisolvibili. Ciò richiede che l'hacker sia abituato a pensare in modo analitico e a risolvere problemi.
- Ciò spesso richiede che l'hacker diagnostichi accuratamente cosa c'è che non va e quindi risolva il problema in componenti separati. Questa è una di quelle abilità che derivano da molte ore di pratica.
*Persistenza*:
- Un hacker deve essere persistente. Se fallisci all'inizio, riprova. Se fallisce, trova un nuovo approccio e riprova.
# Cos'è il Penetration Testing
>[!quote]- Un penetration test è un metodo per valutare la sicurezza di un sistema informatico o di una rete simulando un attacco proveniente da una fonte dannosa, noto come Black Hat Hacker o Cracker. -Wikipedia

L'intenzione è quella di individuare i punti deboli della sicurezza e:
- Potenzialmente ottenere l'accesso al sistema
- Sfruttare le funzionalità del sistema
- Ottenere dati non autorizzati
I test di penetrazione possono essere **automatizzati** con applicazioni software oppure possono essere eseguiti **manualmente**.
Il processo include:
- raccolta informazioni sul bersaglio prima del test (*ricognizione*)
- identificazione dei possibili punti di ingresso (*port scanning*)
- tentativo di effrazione (*virtuale o reale*)
- *riportare i risultati*
![[Pasted image 20240312151121.png|center|400]]
# Il modello di Killchain: APT
![[Pasted image 20240312151229.png|center|400]]
**Ricognizione.** L'aggressore raccoglie informazioni sul bersaglio prima che inizi l'attacco vero e proprio. Può farlo cercando informazioni pubblicamente disponibili su Internet.
**Armamenti**. L'aggressore utilizza un exploit e crea un payload dannoso da inviare alla vittima. Questo passaggio avviene dalla parte dell'aggressore, senza contatto con la vittima.
**Consegna**. L'aggressore invia il payload dannoso alla vittima tramite e-mail o altro mezzo, che rappresenta uno di questi dei molti metodi di intrusione che l'aggressore può utilizzare.
**Sfruttamento**. L'effettiva esecuzione dell'exploit, che, ancora una volta, è rilevante solo quando l'aggressore utilizza un exploit.
**Installazione**. L'installazione di malware sul computer infetto è rilevante solo se l'aggressore ha utilizzato malware come parte dell'attacco e, anche quando è coinvolto un malware, l'installazione è un punto nel tempo all'interno di un processo di attacco molto più elaborato che richiede mesi per funzionare.
**Comando e controllo**. L'attaccante crea un canale di comando e controllo per continuare a gestire le sue risorse interne da remoto. Questo passaggio è relativamente generico e rilevante durante tutto l'attacco, non solo quando è installato malware.
**Esfiltrazione**. L’aggressore esegue i passaggi per raggiungere i suoi obiettivi reali all’interno della rete della vittima. Questo è l’elaborato processo di attacco attivo che richiede mesi e migliaia di piccoli passi per essere portato a termine.