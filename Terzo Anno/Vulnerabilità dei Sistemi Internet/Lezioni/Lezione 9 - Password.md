# Password
>[!important]- Definizione
>Informazione segreta condivisa tra utente e servizio:
>- L'utente rivela la password per autenticarsi;
>- La password verifica l'identità dell'utente.
Il servizio admin necessita di immagazzinare le password degli utenti, ma come? dove?
## Autenticazione
1. L'utente invia id e password;
2. Il servizio verifica se l'utente esiste nel database;
3. Il servizio verifica se la password e il nome dell'utente coincidono con quello che è stato memorizzato in precedenza:
![[Pasted image 20240418155040.png|center|600]]
### Furto di identità
Se qualcuno conosce una password di un'altra persona, può autenticarsi come la stessa.
>[!note]
>Le password nel database devono essere protette $\implies$ Servizio
>Le password devono essere complesse $\implies$ Utente

![[Pasted image 20240418155237.png|center|600]]
![[Pasted image 20240418155313.png|center|600]]
## Bassa entropia
![[Pasted image 20240418155344.png|center|500]]
![[Pasted image 20240418155400.png|center|500]]
![[Pasted image 20240418155451.png|center|500]]

Le probabilità di indovinare una password sono di $(\frac{1}{2})^n$ dove $n$ è la lunghezza della password, ma in realtà è molto più semplice.
## Problemi delle password
Le persone utilizzano spesso la stessa password o password molto simili fra loro su portali differenti, portando ad un *password overload*. Questo permette di trovare la password di un utente su un sito "di minor importanza" (iscrizione ai giornali, palestre ecc... ) per poter poi accedere o comunque avere una base di partenza per ottenere le password "di maggior importanza" ( banche, progetti ecc... ).
Inoltre, le persone utilizzano i soli caratteri all'interno della propria tastiera, e non ne utilizzano neanche tutti i possibili, spesso solo lettere e numeri.
Le persone sono anche molto ingenue nella scelta dei numeri e dei caratteri da utilizzare nelle password ( i numeri più usati sono da 1 a 31, mentre i caratteri speciali più utilizzati sono + @ # ), ciò li rende più prevedibili e quindi più vulnerabili.
## Modalità di attacco

>[!important]- Online
>Strumento: Hydra
>- Non utilizzato spesso, per via di lentezza e mancanza di "profilo basso"

>[!important]- Offline
>- Accesso ai dati dei db
>Strumenti per automatizzare: **John The Ripper**, **Hashcat**.
>- Molto veloci ( la velocità dipende dal processore )
>- Quasi invisibili

## Come nascondere le password - Server Side
