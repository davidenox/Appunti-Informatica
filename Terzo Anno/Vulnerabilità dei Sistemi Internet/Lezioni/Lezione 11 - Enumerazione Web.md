# Web Enumeration
	Discovering virtual-hosts, folders, files, parameters
## Enumerazione delle cartelle
- Punta ad un URL e ad una porta (tipicamente `80`  o `443`)
- Utilizzando una wordlist invia una richiesta `HTTP GET` al sito e ascolta la risposta del sito
- Se l'URL suscita una risposta positiva( 200 )
	- Sappiamo che la directory o il file esiste
- Se l'URL suscita una richiesta "proibita"
	- Possiamo probabilmente dedurre che esiste una directory o un file e che sia privato.
Ed essa potrebbe essere un file o una directory che vogliamo come target nel nostro attacco
## HTTP Status Codes
**100 - Continue**:
- La richiesta client non è stata completata per qualche motivo e il cliente dovrebbe continuare
**200 - Successful**:
- La richiesta è andata a buon fine
**300 - Multiple Choices**:
- Generalmente la richiesta non è completa
**400 - Bad request**:
- I più comuni sono 404 (Not Found) e 403 (Forbidden)
**500 - Internal Server Error**:
- Il server ha incontrato una condizione inasoerrara che impedisce il completamento della richiesta
### Enumerazione delle cartelle
- Dirbuster: Incluso in Kali
- Dirsearch
- Gobuster
```Shell
dirsearch -r -u http://www.vdsi.com -w $dirbuster_wordlist -e php, txt, ...
```
### Enumerazione dei file
- Dirbuster: Incluso in Kali
- Dirsearch
- Gobuster
```Shell
dirsearch -r -f -u http://www.vdsi.com -w $dirbuster_wordlist -e php, txt, ...
```

![[Pasted image 20240422121136.png|center|500]]
### Enumerazioni dei parametri
```Shell
wfuzz -c -z file,/usr/share/wfuzz/wordlist/general/common.txt --hh 92 "http://127.0.0.1/admin/admin.php?FUZZ='"
```
![[Pasted image 20240422121346.png|center|500]]
# Bruteforcing
## DVWA Login
```sh
hydra -l admin -P $rockyou 172.16.47.151 http-form-post "/dvwa/login.php:usernale=^USER^&password=^PASS^&Login=Login:Login failed"
```
```sh
hydra -l admin -P $rockyou 172.16.47.151 http-form-post "/dvwa/login.php:usernale=^USER^&password=^PASS^&Login=Login:S=Welcome"
```
![[Pasted image 20240422121707.png|center|500]]
