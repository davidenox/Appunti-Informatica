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
>In banda (noto anche come "SQLi basato su errori")
>- Le SQL injection che utilizzano lo stesso canale di comunicazione come input per eseguire il dump delle informazioni sono chiamate SQL injection in banda o inline. Ad esempio, un parametro di query, se iniettabile, porta al dumping di informazioni sulla pagina web.

>Fuori banda (noto anche come "SQLi basato sull'Unione")
>- Le iniezioni che utilizzano un canale di comunicazione secondario o diverso per eseguire il dump dell'output delle query eseguite tramite il canale di input vengono definite iniezioni SQL fuori banda. Ad esempio, l'iniezione viene effettuata su un'applicazione Web e un canale secondario come l'e-mail invia i dati all'aggressore.

>Inferenziale (noto anche come "Blind SQLi") 
>- Non avviene alcun trasferimento dati effettivo. L'aggressore è in grado di ricostruire le informazioni inviando particolari richieste e osservando il conseguente comportamento del sito web/DB.

![[Pasted image 20240513145357.png|center|500]]
![[Pasted image 20240513145414.png|center|500]]
## SQL Injection Workflow
![[Pasted image 20240513145717.png|center|500]]
![[Pasted image 20240513145805.png|center|500]]
![[Pasted image 20240513145823.png|center|500]]
![[Pasted image 20240513145834.png|center|500]]
![[Pasted image 20240513145846.png|center|500]]
![[Pasted image 20240513145943.png|center|500]]
![[Pasted image 20240513145953.png|center|500]]
![[Pasted image 20240513150008.png|center|500]]
## Blind SQL Injections
![[Pasted image 20240513150121.png|center|500]]

**Def**: Un attacco Blind SQL injection è un attacco contro un server che risponde con una pagina di errore generica o addirittura senza nulla.
**Approccio**: porre una serie di domande vero/falso, sfruttare i canali laterali.
![[Pasted image 20240513150243.png|center|500]]
![[Pasted image 20240513150253.png|center|500]]
# SQL Injections
Il codice php di accesso dell'amministratore SU SITI WEB FATTI MALE sarà solitamente simile a questo, ad un certo punto:
```PHP
//connect to db
$conn = mysql_connect("localhost","username","password");
//build SQL statement
$query = "SELECT id, name FROM users
WHERE name = '$_POST["username"]’ AND password = '$_POST["password"]' ";
…
//run query
$result = mysql_query ($query);
//ensure a user was returned
$numrows = mysql_num_rows($result);
if($numrows > 0) {
	header("Location:admin.php");
} else {
	die('Invalid username or password.');
}
```
![[Pasted image 20240513150453.png|center|250]]

```PHP
//connect to db
$conn = mysql_connect("localhost","username","password");
//build SQL statement
$query = "SELECT id, name FROM users WHERE name = ’alberto’ AND password = ’secret' ";
…
//run query
$result = mysql_query ($query);
//ensure a user was returned
$numrows = mysql_num_rows($result);
if($numrows > 0) {
	header("Location:admin.php");
} else {
	die('Invalid username or password.');
}
```
![[Pasted image 20240513150543.png|center|250]]

```PHP
//connect to db
$conn = mysql_connect("localhost","username","password");
//build SQL statement
$query = "SELECT id, name FROM users WHERE name = ’admin’ AND password = ’xx’ OR ‘1’=‘1' ";
…
//run query
$result = mysql_query ($query);
//ensure a user was returned
$numrows = mysql_num_rows($result);
if($numrows > 0) {
	header("Location:admin.php");
} else {
	die('Invalid username or password.');
}
```
![[Pasted image 20240513150629.png|center|250]]
## Detecting SQL Injections
	`http://10.0.0.X/cat.php?id=1'`
	
Ciò sfuggirà all'istruzione SQL preparata
-  interrompe la sintassi e provoca un errore SQL
Questo ci dice che sta eseguendo SQL
-  …e presenta una vulnerabilità SQLi
>[!quote]- <<Hai un errore nella sintassi SQL, controlla nel manuale che corrisponde alla versione del tuo server MySQL la sintassi corretta da utilizzare vicino a ''' alla riga 1>>

Quindi, è SQLi vulnerabile
-  ma non sappiamo come sia la query SQL dietro nel codice c`at.php`
-  scopriamo quante colonne richiede
## Exploit SQL Injection
**FUN FACT:**
Tutte le query in un'istruzione SQL contenente l'operatore `UNION` devono avere un numero uguale di espressioni negli elenchi di destinazione,
cioè `UN'UNIONE B`.
- deve avere lo stesso numero di colonne
Possiamo usarlo per enumerare le colonne di una dichiarazione?
`http://10.0.0.X/cat.php?id=1 UNION SELECT ALL 1--`
The used SELECT statements have a different number of columns
`http:// 10.0.0.X /cat.php?id=1 UNION SELECT ALL 1,2--`
The used SELECT statements have a different number of columns
`http:// 10.0.0.X /cat.php?id=1 UNION SELECT ALL 1,2,3--`
The used SELECT statements have a different number of columns
"The UNION SELECT ALL ...." part is a common SQLi trick

`http://10.0.0.X/cat.php?id=1 UNION SELECT ALL 1,2,3,4--`
Successo! otteniamo una pagina Web valida e popolata Quindi questa dichiarazione preparata ha 4 colonne...! 
- Questa tecnica funziona quando i messaggi di errore SQL sono disabilitati (e SQLi basato sugli errori non funziona) 
- Giocare con questi parametri rivelerà cosa fa cosa.
![[Pasted image 20240513154131.png|center|400]]
La maggior parte dei database SQL ha una tabella in ciascun database chiamata "`information_schema`", che è sempre interessante. Possiamo prendere tutti i nomi delle tabelle e dei nomi delle colonne da esso. Una volta che conosci il tipo e la versione del DB, queste informazioni sono facili da determinare.
Possiamo utilizzare il seguente SQLi per estrarre queste informazioni:
![[Pasted image 20240513154243.png|center|500]]
### Esempio
`UNION SELECT 1, login, 3, 4 FROM users`
Rivela un login di "admin"
`UNION SELECT 1, password, 3, 4 FROM users`
Rivela una password in hash, che convertita rivela la vera password.
## Capire il problema
La causa principale di molti problemi con l'input è che un server web:
- innanzitutto sostituisce alcuni input dell'utente in una stringa
- quindi analizza la stringa per interpretarne il significato
Analizzando prima e poi sostituendo, possiamo evitare alcuni problemi.
Perché?
I caratteri di controllo nell'input dell'utente non possono più influenzare globalmente l'analisi
## Evitare le SQL Injection
>Convalida dell'input
>- È possibile impedire l'iniezione SQL se si adotta una tecnica di convalida dell'input in cui l'input dell'utente viene autenticato rispetto a un insieme di regole definite per lunghezza, tipo e sintassi e anche rispetto alle regole aziendali

>Evitare SQL dinamico
>- Utilizza API di query con parametri fortemente tipizzate con indicatori di sostituzione dei segnaposto, anche quando si chiamano procedure memorizzate.
>- Prestare attenzione quando si utilizzano le procedure memorizzate poiché generalmente sono sicure dall'iniezione. Tuttavia, fai attenzione poiché possono essere iniettabili (ad esempio tramite l'uso di exec() o concatenando argomenti all'interno della procedura memorizzata).

**Vulnerabile**:
```
String updateString = "SELECT * FROM Account WHERE
Username" + username + " AND Password = " + password;
stmt.executeUpdate(updateString);
```

*Sicuro*:
```
PreparedStatement login = con.preparedStatement("SELECT * FROM Account WHERE Username = ? AND
Password = ?" );
login.setString(1, username);
login.setString(2, password);
login.executeUpdate();
```

## Blind SQL Injections
