	Local file inclusion, Remote file inclusion, PHP wrappers
# PHP Basic
PHP (Hypertext Preprocessor), in cui *il codice viene eseguito in server side a runtime*. L'output è in formato HTML. Può essere configurato senza l'utilizzo degli url .php
Esempio:
```PHP
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
	"http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<title>Example</title>
	</head>
	<body>
		<?php
			$msg = “Hi, I’m a PHP script!”;
			echo $msg;
		?>
	</body>
</html>
```
## PHP Include e Eval
L'istruzione include include e valuta il file specificato. Esegue il file come codice PHP. 
È importante capirlo in seguito. 
Simile alla funzione `eval` 
`eval` — Valuta una stringa come codice PHP.
Es.
```PHP
<?php
//include html doctype,header,css,etc
	include(“../header.php”);
	echo “this text should be in the body”;
//close body tags and html, with logos
	require(“../footer.php”);
?>
```
### Parametri di Request
`$_GET` → Un array associativo di variabili passato allo script corrente tramite i parametri URL.
Le richieste effettuate in questo modo vengono generalmente registrate intatte con la query dell'URL.
`$_POST` → Un array associativo di variabili passato allo script corrente tramite il metod HTTP POST.
Le richieste effettuate in questo modo vengono registrate, ma solo se si verifica un `POST` nello script, non nei parametri inclusi. (Generalmente)
`$_REQUEST `→ Un array associativo che per impostazione predefinita contiene il contenuto di `$_GET, $_POST `e `$_COOKIE`.
Utilizzando la sintassi` $_REQUEST[“variabile”]`, l'applicazione non si preoccupa se la variabile viene riempita da GET o POST.
Utilizzando gli array `$_GET` o `$_POST` verranno riempiti solo se le variabili vengono pubblicate o recuperate rispettivamente tramite GET o POST.
Scegli attentamente in base allo scopo dell'app.
# Local File Inclusion
L'inclusione di file locali avviene quando un'app php viene scritta per includere file nel file system locale.
- (Ricordi `include()` di prima?)
- Exploit LFI
- Lo sfruttamento LFI è in genere dovuto alla scarsa sanificazione dell'input dell'utente.
```PHP
// Poorly designed LFI(1)
<?php
	include($_REQUEST[“file”]);
?>
// Poorly designed LFI(2)
<?php
	if isset($_REQUEST[“file”]) {
		$file = $_REQUEST[“file”];
		include(“$file” . “.php”);
	}
?>
// Better LFI design (3)
<?php
	if isset($_GET[“file”]) {
//remove any attempts at directory traversal
		$file = str_replace(‘../’, ‘’, $_GET[‘file’]);
		include(“$file.php”);
}
?>
```
## URL Encoding
![[Pasted image 20240513112014.png|center|500]]
## LFI Exploit - Access Log
Include il registro di accesso di Apache:
- Tramite richiesta HTTP telnet
- Tramite curl/wget
- L'utilizzo di un normale browser probabilmente non funzionerà poiché il browser effettua sostituzioni automatiche prima di effettuare effettivamente la richiesta.
- Modificando l'agente utente per contenere PHP
### Log Injection
Attacco in 3 fasi
- File di registro seed con codice PHP appropriato
- Individua il file di registro nel sistema
- Include il file di registro per eseguire il codice PHP
![[Pasted image 20240513112218.png|center|600]]

### LFI Exploit - /proc/self/environ
`include /proc/self/environ`
- Se Apache ha i diritti di visualizzazione, `include` elencherà i processi correnti, incluse cose come `HTTP_USER_AGENT`
- Se hai precedentemente modificato il tuo `useragent` per contenere codice php (ad esempio `"<?phpinfo();?>"` invece di `"Mozilla/5.0"`) verrà eseguito come codice php quando viene eseguito environ.
- Non imbatterti in questo molto spesso, la maggior parte dei sistemi non consente ad Apache di avere permessi di lettura su environ
### LFI Exploit - PHP Session
Include il tuo file di sessione php
- Determina il tuo sessionid dai cookie del browser
- Il trucco sta nell'identificare dove è archiviato il file della sessione e se l'amministratore ha configurato impostazioni univoche potrebbe rivelarsi difficile.
- Prova a includere nelle normali posizioni di archiviazione della sessione
	- `/tmp/sess_mysessionid%00`
	- `/var/lib/php5/sess_mysessionid%00`
### LFI Exploit - Lettura dei file
Legge qualsiasi file sul filesystem.
Poiché tutti i file inclusi che contengono php vengono eseguiti al momento dell'inclusione, non possiamo mai leggere nessuno dei file php, ma vengono invece eseguiti.
I filtri PHP ignoreranno questo problema.
## PHP Filters LFI Use
`index.php?page=php://filter/read=convert.base64-encode/resource=config`
Questo codice baserà64 la risorsa "config" (come se fosse `index.php?page=config`, ma con base64′d) con ciò, il tuo codice non verrà eseguito e potrai `base64_decode()` dopo prendi il file `config.php` originale. Questo metodo non avrà bisogno di virgolette magiche ma dovrai avere una versione PHP superiore o uguale a PHP5.
![[Pasted image 20240513115501.png|center|650]]
## Ricognizione LFI
Esiste una cartella?
Tenta semplicemente di attraversare la directory dentro e fuori dalla directory. Se esiste, l'inclusione funzionerà.
`index.php?page=../../../../../../var/www/doiexist/../../../../../etc/passwd%00`
## Protezione LFI
1. Attiva le virgolette magiche
2. Configura open_basedir per leggere solo nella cartella web e /tmp
3. Pulisci l'input dell'utente analizzando "/", "." e "%00" per cominciare
4. Rimuovere le autorizzazioni di lettura di Apache su access.log
5. Monitorare /tmp per eventuali aggiunte di file (/tmp viene letto/scritto da tutti)
6. Se possibile, utilizzare include statiche anziché dinamiche
	-  `if ($_GET['file'] == 'miapagina'){include('miapagina.php');};`
# Remote File Inclusion
Identico a LFi ma prende le risorse da una località remota:
![[Pasted image 20240513115837.png|center|650]]

> Da vedere DVWA