	CGI, Vulnerable Functions, Concatenate shell commands
# Le web app ottengono dati o codici?
>[!cite]- Qualsiasi ambiente di applicazione Web permette l'esecuzione di comandi esterni come le chiamate di sistema, i comandi di shell e le richieste SQL. La suscettibilità di una chiamata esterna per il controllo di injection dopende da come la chiamata viene fatta ed il componente specifico che viene chiamato, ma quasi tutte le chiamate esterne possono essere attaccate se l'applicazione web non è stata sviluppata correttamente. --OWASP

## Common Gateway Interface ( CGI )
Si tratta di una nuova ma ormai un metodo "vecchio stile" per i server web per interagire con gli eseguibili del terminale.
```Web
http://bla.com/cgi-bin/my_script.cgi?yr=2015&str=a%20name
```
Il server web lo esegue:
- Passando parametri allo standard input
- Restituento l'output ( tipicamente HTML ) al client
### CGI bash script
```Bash
#!/bin/bash
echo 'Content-type: text/html'
echo ''
echo '<html>'
echo '<head>'
echo '<title>My first CGI bash script</title>'
echo '</head>'
echo '<body>'
echo 'Hello World'
cat some_html_content.html
echo '</body>'
echo '</html>'
```
### CGI perl script
```perl
#!/usr/bin/perl
print "Content-type: text/html\n\n";
print << HTML;
<html>
<head> <title>My first perl CGI script </title>
</head>
<body> <p>Hello World</p>
</body>
HTML
exit;
```
### CGI: Pro e contro
>[!important]- Pro
>- Concetti e interfacce estremamente semplici
>- Programmabile in qualsiasi linguaggio

>[!danger]- Contro
>- Puoi usare qualunque linguaggio di programmazione
>- Non c'è supporto per ogni feature
>- Analisi dello standard input per ricevere i parametri GET e POST

## Command Injection
Uno script bash CGI contiene:
- `cat thefile`
- `mail clientaddress`
Per inviare un file sulla mail di un utente.
***Problemi di sicurezza?***
Un malintenzionato potrebbe entrare nell'indirizzo della mail:
`tumadre.pelata@maildeldiavolo.it ; rm -rf /`
Cosa succederebbe?
`cat thefile | mail tumadre.pelata@maildeldiavolo.it ; rm -rf / `
### Concatenazione di comandi ed esecuzione
#### Bash ( Linux )
- `; → uname –a; id`
- `&, && → xxx & id vs. xxx && id`
- `|, || → xxx | id vs. xxx || id`
Can exploit also with:
-  `$(…), ${…}` 
-  `…`
-  `' → echo 'h''e''l''l''o’`
-  `?, * → /u?r/b*n/w*oa?i`
#### Windows
- `&, &&`
( SLIDE 12 )
## Command Injection
Qualsiasi codice eseguibile in lato server che utilizza l'input del client per interagire con l'OS può essere utilizzato per l'inject di comandi al SO.
![[Pasted image 20240429121824.png|center|500]]
![[Pasted image 20240429121842.png|center|500]]
![[Pasted image 20240429121906.png|center|600]]
![[Pasted image 20240429121929.png|center|600]]
## Reverse shell
![[Pasted image 20240429122010.png|center|500]]
![[Pasted image 20240429122031.png|center|500]]
## Mitigazione di Command Injections
Validazione dell'input: Esegue la validazione di tutti gli input degli utenti per evitare caratteri pericolosi (ad esempio `; | >`...). È sempre meglio il white-listing del black-listing, dato che è preferibile dire quali caratteri sono concessi piuttosto che dire quali non sono ammessi.
Ancora meglio: analizzare (*parse*) l'input completo prima di farci qualsiasi cosa, usando un parser standard, quindi usare gli alberi di analisi invece delle stringhe.
La convalida dell'input tenta di prevenire gli attacchi.

Dovremmo anche cercare di mitigare il possibile impatto:
- eseguendo l'applicazione web con privilegi minimi
- (ovvero applicando il principio del privilegio minimo)