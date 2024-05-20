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
Slide 9