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

