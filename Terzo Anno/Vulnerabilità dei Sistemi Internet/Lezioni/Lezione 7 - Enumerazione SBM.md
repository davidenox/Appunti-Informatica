# Enumerazione SBM
Il **Server Message Block**:
- Fornisce accesso condiviso a file, stampanti e porte seriali;
- Viene utilizzato a partire da Windows 95, Samba permette di utilizzarlo sui sistemi Unix;
- Il servizio SBM NetBIOS ascolta sulle porte TCP *139* e *445*
`nmap -v -p 139,445 -oG smb.txt <ip range>`
`nbtscan -r <subnet or ip address>`
Nmap contiene molti script NSE che possono essere utilizzati per scoprire e numerare servizi SMB (questi script sono in `/usr/share/nmap/scripts`).
![[Pasted image 20240408121319.png|center|500]]
## Enum4linux
Enum4linux permette di estrarre diverse informazioni dall'SBM Server Target:
![[Pasted image 20240408121427.png|center|500]]
`enum4linux [options] ip`
# Nmap Scripting
	-sC  or --script
Gli script NSE definiscono un elenco di categorie:
- `auth`: Questi script gestiscono le credenziali di autenticazione (o il loro bypass) sul sistema di destinazione;
- `broadcast`: Gli script in questa categoria in genere rilevano gli host non elencati nella riga di comando trasmettendo sulla rete locale;
- `brute`: Questi script utilizzano attacchi di bruteforce per indovinare le credenziali di autenticazione di un server remoto;
- `discovery`: Questi script tentano di scoprire attivamente ulteriori informazioni sulla rete interrogando registri pubblici, dispositivi abilitati SNMP, servizi di directory, ecc.
	- Gli esempi includono html-title (ottiene il titolo del percorso root dei siti Web), smb-enum-shares (enumera le condivisioni Windows) e snmp-sysdescr (estrae i dettagli del sistema tramite SNMP).
- Gli script `dos` in questa categoria possono causare una negazione del servizio. Questi test a volte bloccano i servizi vulnerabili.
- `exploit`: Questi script mirano a sfruttare attivamente alcune vulnerabilità.
- Gli script `external` in questa categoria possono inviare dati a un database di terze parti o ad altre risorse di rete. Un esempio di ciò è whois, che stabilisce una connessione al server whois.
- `fuzzer`: Questa categoria contiene script progettati per inviare al software del server campi inaspettati o casuali in ciascun pacchetto;
- `intrusive`: Si tratta di script che non possono essere classificati nella categoria sicura perché i rischi sono troppo elevati e possono causare l'arresto anomalo del sistema di destinazione, l'utilizzo di risorse significative sull'host di destinazione (come larghezza di banda o tempo della CPU) o altrimenti essere percepiti come dannosi dagli amministratori di sistema del bersaglio;
- `malware`: Questi script verificano se la piattaforma di destinazione è infettata da malware o backdoor.
- Gli script `safe` che non sono stati progettati per bloccare i servizi, utilizzare grandi quantità di larghezza di banda di rete o altre risorse o sfruttare falle di sicurezza sono classificati come sicuri;
- `version`: Gli script in questa categoria speciale sono un'estensione della funzionalità di rilevamento della versione e non possono essere selezionati esplicitamente. Sono selezionati per essere eseguiti solo se è stato richiesto il rilevamento della versione (`-sV`).
- `vuln`; Questi script verificano la presenza di vulnerabilità note specifiche e generalmente riportano i risultati solo se vengono rilevati.
- `default`: Questi script sono il set predefinito e vengono eseguiti quando si utilizzano le opzioni `-sC` o `-A` anziché elencare gli script con `--script`. Per decidere se uno script deve essere eseguito per impostazione predefinita vengono presi in considerazione molti fattori:
	- *Velocità*: Una scansione predefinita deve terminare rapidamente
	- *Utilità*: Le scansioni predefinite devono produrre informazioni preziose e utilizzabili
	- L'output di *Verbosità* Nmap viene utilizzato per un'ampia varietà di scopi e deve essere leggibile e conciso
	- *Affidabilità*: Molti script utilizzano l'euristica e la corrispondenza fuzzy delle firme per raggiungere conclusioni sull'host o sul servizio di destinazione. Se lo script è spesso sbagliato, non appartiene alla categoria predefinita in cui potrebbe confondere o fuorviare gli utenti occasionali
	- *Invadenza*: Alcuni script sono molto invasivi perché utilizzano risorse significative sul sistema remoto, rischiano di mandare in crash il sistema o il servizio o possono essere percepiti come un attacco dagli amministratori remoti. Più uno script è invadente, meno è adatto alla categoria predefinita
	- *Privacy*: Alcuni script, in particolare quelli della categoria esterna descritta più avanti, divulgano informazioni a terzi per la loro stessa natura. Quanto più uno script è invasivo per la privacy, tanto meno è adatto per l'inclusione nella categoria predefinita
(slide 22)