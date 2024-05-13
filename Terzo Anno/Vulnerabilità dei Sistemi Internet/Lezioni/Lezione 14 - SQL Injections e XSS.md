# SQL Injection
## SQL DBMS
![[Pasted image 20240513120606.png|center|600]]
## Web Application Overview
![[Pasted image 20240513120653.png|center|600]]
## DB Basics
I server di database (ad esempio mysqld) ospitano molti database
-  ogni database ha un numero di tabelle con dati
-  I database hanno utenti
	-  alcuni sono amministratori
	-  le informazioni vengono archiviate all'interno del database
Gli utenti del database dispongono delle autorizzazioni su ciò che possono e non possono fare
-  ovvero accesso solo al database X,Y,Z ma non A,B,C
-  accesso al file system (ne parleremo più avanti)
-  Modifica/Inserisci/Aggiorna/ELIMINA/Seleziona autorizzazioni
	-  QUALSIASI database o quelli specificati
Le informazioni archiviate nei database SQL sono organizzate in tabelle
-  ogni riga memorizza un "record"
	-  ` Username, First Name, Last Name, Address, ecc..`
-  ciascuna colonna definisce il tipo di dati per ciascun dato in ciascun record.
	-  `varchar[8] Username`
	-  `varchar[80] First name`
	-  `text Address`
	-  `int UserID`
![[Pasted image 20240513121316.png|center|400]]
## SQL Basic : SELECT
Selezionerà un sottoinsieme di colonne dalla tabella.
Anche i risultati recuperati dalle query sono sotto forma di tabelle.
`SELECT Usernames, Password FROM Users;`
![[Pasted image 20240513121501.png|center|500]]
## SQL Basic : UNION
Concatena due (o più) tabelle dei risultati SELECT insieme
-  Solo risultati DISTINCT
-  "UNION ALL" per ottenere valori duplicati
-  Ciascuna istruzione SELECT deve avere lo STESSO numero di colonne
	-  Anche le colonne devono avere tipi di dati simili
	-  Di solito, anche le colonne devono essere nello stesso ordine
`SELECT species, name FROM animals UNION SELECT name, type FROM fruits`
![[Pasted image 20240513121758.png|center|500]]
## SQL Basic: Filtraggio
Filtrerà le righe in base a delle condizioni
`SELECT * FROM products WHERE cost >= 500;`
![[Pasted image 20240513121926.png|center|500]]
Supponiamo di avere una query di notizie come questa:
-  `SELECT * FROM news WHERE news_id = 121`
-  e ha 90000 risultati...
-  `*` è un carattere jolly
-  `WHERE` per cercare valore
Possiamo limitare i risultati tramite:
-  `SELECT * FROM `news` WHERE `news_id` = 121 LIMIT 9000`
-  `SELECT * FROM `news` WHERE `news_id` = 121 LIMIT X`
-  dove X è un numero intero (0, 1, 2, 3, ecc...
## SQL Basic: Accesso al filesystem
`SELECT ... LOAD_FILE`
-  Utilizzato per leggere i file
`SELECT … INTO OUTFILE/DUMPFILE`
-  Usato per scrivere file
PERICOLOSO

## Basic Queries
`SELECT <columns> FROM <tbl> WHERE <exp>`
Le colonne possono essere:
-  Elenco di nomi di colonne separati da virgole
-  `*`per tutte le colonne
tbl è un elenco di tabelle separate da virgole
exp è un'espressione SQL booleana
-  Virgolette singole per le stringhe ('')
-  I numeri interi vengono specificati nel modo normale
Convenzioni tipiche dei commenti SQL:
-  Riga singola: carattere "--" (due trattini).
-  Multilinea: `/*` e `*/` (come C)
-  Specifico del server, ad esempio, commento a riga singola "#" per mysql
### Esempio di query
![[Pasted image 20240513122447.png|center|500]]
### Esempio di join
![[Pasted image 20240513122509.png|center|500]]
#### Tautologie
![[Pasted image 20240513122555.png|center|500]]
## Classificazione SQLi
![[Pasted image 20240513122620.png|center|400]]
## Tipi di SQL Injections
SLIDE 21
