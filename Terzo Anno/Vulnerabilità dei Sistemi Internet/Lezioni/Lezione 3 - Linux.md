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

slide 13