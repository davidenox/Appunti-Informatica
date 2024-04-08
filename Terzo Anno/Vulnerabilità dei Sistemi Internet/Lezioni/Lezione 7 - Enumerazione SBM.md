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
slide 15