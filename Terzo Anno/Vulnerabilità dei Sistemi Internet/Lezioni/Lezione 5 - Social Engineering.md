# Cos'è la Social Engineering?
>[!cite]- L'arte di manipolare le persone nello svolgere azioni o divulgare informazioni personali

## Tattiche di Remote Social Engineering
Scenario:
- Telefonate in entrata ai dipendenti
- Il chiamante tenta di persuadere un utente a fornire informazioni sensibili o a visitare un sito Web falso e ad accedere alle sue credenziali per convalidare le loro password.
- L'ID del chiamante in uscita è falsificato
- Cattura nomi utente e password
*ESEMPIO*: Sito web fake
![[Pasted image 20240321142511.png|center|500]]
*La toppa* (the Patch)
Scenario:
- Telefonate in entrata ai dipendenti
- Indirizzare l'utente al sito web fake per fargli scaricare ed eseguire "the patch"
- Eseguirlo ti restituisce il suo username, indirizzo IP e hostname per internet.
*ESEMPIO*:![[Pasted image 20240321142952.png|center|500]]
>The e-mail Patch
>- Invia un'email all'utente mirato per persuaderlo a visitare un sito "Patch" per "aggiustare" una zero-day vulnerability
>- Simile allo scenario 2
>- L'eseguibile invia username, indirizzo IP e hostname per internet

>Phishing / Spear Phishing
>Il phishing è il processo criminalmente fraudolento che tenta di acquisire informazioni sensibili come nomi utente, password e dettagli della carta di credito mascherandosi da entità affidabile in un sistema elettronico di comunicazione".

### Spoofing mails
Per non essere considerato "aperto", un relè di posta elettronica deve essere sicuro e configurato per accettare e inoltrare solo i seguenti messaggi:
- Messaggi da indirizzi IP locali alle caselle di posta locali;
- Messaggi da indirizzi IP locali a caselle di posta non locali;
- Messaggi da indirizzi IP non locali a caselle di posta locali;
- Messaggi provenienti da client autenticati e autorizzati.
![[Pasted image 20240325095443.png|center|300]]

In particolare, un inoltro di posta SMTP adeguatamente protetto non dovrebbe:
- accettare e inoltrare e-mail arbitrarie da indirizzi IP non locali a caselle di posta non locali;
- da un utente non autenticato o non autorizzato.
### USB
Adescare un'unità USB denominata BonusPlan:
- L'analista lascerà dispositivi USB nelle aree in cui si riuniscono i dipendenti;
- Il test mira a determinare se i dipendenti inseriranno supporti rimovibili sconosciuti nei computer aziendali;
- Una volta inseriti, i fogli di calcolo Excel vengono visualizzati con nomi di file come "BonusPlan2016.xls";
- Excel non si apre; il programma invia silenziosamente l'indirizzo IP, il nome host e il nome utente dell'individuo a un server DDI;
# Onsite Social Engineering
La Onsite Social Engineering utilizza molteplici metodi di testing onsite, come:
- Tentare di ottenere accesso fisico ai permessi;
- Tentare di ottenere records, file o equipaggiamenti, informazioni sensibili, accessi di rete ...
- Tentare di raccogliere informazioni per permettere l'accesso a reti non autorizzate.
## Tattiche
>Scenario 1 : Nuovo dipendente
>- L'analista si finge un nuovo dipendente ed entra attraverso la porta di ingresso dei dipendenti;
>- In genere avrà già “avvolto” l'organizzazione e indosserà l'abbigliamento appropriato;
>- Avrà già un badge falso prima di venire in sede.

>Scenario 2 : Venditore verificato
>- L'analista finge di essere un impiegato di un venditore fidarto come la compagnia telefonica locale, elettricista, ...
>- In genere avrà già chiamato per vedere la firma dell'organizzazione;
>- L'abbigliamento è facile da reperire o da fabbricare.

# Ricognizione
## Come inizia un attacco informatico?
![[Pasted image 20240325100801.png|center|500]]
## Il modello Killchain
>[!important]- **Fase 1**: *Ricognizione*
>L'aggressore raccoglie informazioni sul bersaglio prima che inizi l'attacco vero e proprio. Può farlo cercando informazioni disponibili al pubblico su Internet.

- Fase 2: *Armamento*. L'aggressore utilizza un exploit e crea un payload dannoso da inviare alla vittima. Questo passaggio avviene dalla parte dell'aggressore, senza contatto con la vittima.
- Fase 3: *Consegna*. L'aggressore invia il payload dannoso alla vittima tramite e-mail o altri mezzi, che rappresenta uno dei tanti metodi di intrusione che l'aggressore può utilizzare.
- Fase 4: *Sfruttamento*. L'effettiva esecuzione dell'exploit, che, ancora una volta, è rilevante solo quando l'aggressore utilizza un exploit.
- Fase 5: *Installazione*. L'installazione di malware sul computer infetto è rilevante solo se l'aggressore ha utilizzato malware come parte dell'attacco e, anche quando è coinvolto del malware, l'installazione è un punto temporale all'interno di un processo di attacco molto più elaborato che richiede mesi per funzionare.
- Fase 6: *Comando e controllo*. L'aggressore crea un canale di comando e controllo per continuare a gestire le sue risorse interne da remoto. Questo passaggio è relativamente generico e rilevante durante tutto l'attacco, non solo quando viene installato il malware.
- Fase 7: *Esfiltrazione*. L’aggressore esegue i passaggi per raggiungere i suoi obiettivi reali all’interno della rete della vittima. Questo è l’elaborato processo di attacco attivo che richiede mesi e migliaia di piccoli passi per essere portato a termine.

>[!important]- Passive Information Gathering / Open Source Intelligence (OSINT)
>- Ricerca, selezione e acquisizione di informazioni da fonti disponibili al pubblico:
>- Non inviare mai traffico all'organizzazione di destinazione né da uno dei nostri host né da host o servizi "anonimi" su Internet;
>- Può utilizzare e raccogliere solo informazioni immagazzinate o archiviate;
>- Può essere obsoleto o errato poiché siamo limitati ai risultati raccolti da terze parti.

## Google Dorking
`filetype: pdf|txt|sql|...`
> `allintext:"define('DB_PASSWORD',"`
> - Cerca più parole nel corpo del testo delle pagine indicizzate. Viene utilizzato in modo simile a allinurl:
> `allintitle`:
> - Funziona come intitle: ma cerca più parole nel titolo. Ad esempio, utilizza allintitle: canale conflitto online vendita al dettaglio per cercare documenti che contengano tutte e quattro le parole nel titolo. Tieni presente che quando usi questo operatore c'è uno spazio dopo i due punti.
> `inanchor`:
> - L'operatore limiterà la tua ricerca alle pagine in cui il testo sottolineato dei collegamenti in entrata corrisponde alla parola cercata. Ad esempio, se volessi cercare mappe del sito HTML ma limitare la ricerca a quelle pagine con collegamenti che dicono "site map", inanchor:"site map" andrebbe bene, poiché la maggior parte dei siti si collega alle proprie site map utilizzando l'opzione testo del collegamento di "site map".
> `inurl:"admin.php"`:
> - Operatore per limitare i risultati della ricerca alle pagine che contengono una parola particolare nell'URL. Ciò può essere particolarmente utile se desideri che Google visualizzi tutte le pagine trovate con un particolare nome di script, come inurl:ToolPage site:www.vfinance.com. Ancora una volta, quando si utilizza questo operatore non c'è spazio dopo i due punti.
> `allinurl`:
> - Questo operatore è simile nella funzione all'operatore `inurl`: ma viene utilizzato per trovare più parole nell'URL. Elimina la necessità di continuare a ripetere `inurl`: davanti a ogni parola che desideri cercare nell'URL. Ad esempio, `allinurl:china exporting` è una forma equivalente e più concisa della `queryinurl:china` `inurl:exporting` per trovare pagine Web che contengono le parole china e exporting in qualsiasi punto dell'URL, incluso il nome file, i nomi delle directory, l'estensione o il dominio. C'è uno spazio dopo i due punti quando si utilizza l'operatore allinurl:.
> `intext`:
> - Cerca una parola nel body text principale. È simile alla funzione `inurl:`.
> `cache`:
> - Fornisce una visualizzazione istantanea di una pagina Web come appariva l'ultima volta che Googlebot ha visitato la pagina. Segue questo operatore con un indirizzo Web, ad esempio cache:www.covario.com per visualizzare la pagina che Google ha memorizzato nella cache. Tieni presente che Googlebot deve aver scaricato la pagina affinché funzioni.
> `site`:
> - Puoi effettuare ricerche all'interno di un sito o di un dominio aggiungendo alla query l'operatore `site:` seguito dal nome di dominio del sito. Ad esempio, potresti cercarmi ma limitare la ricerca solo alle pagine all'interno del sito con una query del tuo nome sito:www.tuositocom. Puoi anche aggiungere una sottodirectory alla fine del dominio in un `site: query`. Ad esempio il sito SEO:www.tuonome/cosa-facciamo/. Puoi limitare la ricerca ai siti .com con `site:com`, ai siti .gov con `site:gov` o a .co.uk con `site:co.uk`. Combinando la logica booleana con l'operatore `site:` ti consentirà di effettuare ricerche all'interno di più siti contemporaneamente. Ad esempio, il search marketing (site:marketingprofs.com | site:marketingsherpa.com | site:marketingpower.com) effettua la ricerca nei tre siti contemporaneamente. Utilizza l'operatore `site:` da solo senza altre parole di ricerca per ottenere un elenco di tutte le pagine indicizzate, ad esempio `site:actionableinsights.covario.com`. Ancora una volta, tieni presente che non c'è spazio dopo i due punti quando usi questo operatore.

### Online Platforms
![[Pasted image 20240325110618.png|center|500]]
#### ShodanHQ
*SHODAN* è uno strumento di ricerca che permette di trovvare specifici computer (router, server, ecc.. ) utilizzando una varietà di filtri. Alcuni lo hanno anche descritto come una directory pubblica di scansione delle porte o un motore di ricerca di banner.
- Se sei interessato a trovare computer che eseguono un determinato software (come Apache)
- Se vuoi sapere quale versione di Microsoft IIS è la più popolare
- Vuoi vedere quanti server FTP anonimi ci sono
- È apparsa una nuova vulnerabilità e vuoi vedere quanti host potrebbe infettare
	- Cerca una marca specifica di hardware (ad esempio CISCO, TP-LINK, ecc.)...
	- Modello specifico...
	- In un paese specifico (ad esempio IT, Stati Uniti, Regno Unito, ecc.)...
	- Ecc...
### Siti web memorizzati nella cache
Ci sono momenti in cui non saremo in grado di accedere alle informazioni del sito web perché il contenuto potrebbe non essere più disponibile dalla fonte originale.
- La possibilità di accedere alle copie archiviate di queste informazioni consente l'accesso alle informazioni passate.
Esegui ricerche su Google utilizzando stringhe di ricerca appositamente mirate:
	`cache:<sito.com>`
Utilizza le informazioni archiviate dalla Wayback Machine
	`http://www.archive.org`
## Whois
![[Pasted image 20240325114849.png|center|700]]
## TheHarvester
Email Harvesting è utile per trovare email, ed eventualmente nomi utente, appartenenti ad un'organizzazione. Queste e-mail sono utili in molti modi:
- fornendoci un potenziale elenco di attacchi lato client
- rivelare la convenzione di denominazione utilizzata nell'organizzazione
- mappatura degli utenti nell'organizzazione.
Uno degli strumenti di Kali Linux in grado di svolgere questo compito è theharvester
- Può cercare indirizzi email su Google, Bing e altri siti

```Shell
- theharvester -d <dominio> -b google
- theharvester -d <dominio> -b bing
- theharvester -d <dominio> -b all -h
```

## Recon NG
Recon NG è un framework di ricognizione web completo
- Completo di moduli indipendenti
- Interazione con il database
- Funzioni utili integrate
- Aspetto simile al Metasploit Framework

 Mostra moduli
- utilizzare `recon/domains-contacts/whois_pocs`
- utilizzare `recon/domains-hosts/hackertarget`
- utilizza `recon/domains-hosts/google_site_web`
# Host discovery
