# CORS 
Cross Origin Resource Sharing, sicurezza nei browser per richieste da domini diversi da quello della risorsa.

# Metodi HTTP:
1. GET recupera una risorsa
2. POST invia dati al server per creare una nuova risorsa
3. PUT aggiorna una risorsa esistente
4. DELETE elimina una risorsa
5. HEAD recupera le intestazioni di una risorsa
6. OPTIONS descrive le opzioni di comunicazione per la risorsa
7. PATCH applica modifiche parziali ad una risorsa

## API 
Application Programming Interface, interfacce che permettono a diverse applicazioni software di comunicare tra loro. Server: libreria `fetch` per fare richieste HTTP ai server.

### REST con principi HTTP:
Representational State Transfer, architettura per la progettazione di API basata su principi HTTP come:
1. Risorse identificate da URL
2. Uso di metodi HTTP standard
3. Operazioni stateless
4. Uso di rappresentazioni multiple (XML,JSON) per risorse.

### API REST:
1. Definire risorse e relativi endpoint.
2. Implementare metodi HTTP per ogni endpoint.
3. Gestire richieste e risposte con i codici HTTP appropriati.
4. Assicuraee la statelessness.
5. Implementare la gestione degli errori e la sicurezza.

# EVENT LOOP: 
Costrutto di programmazione che gestisce le operazioni asincrone, consentendo a JS di eseguire il codice, raccogliere ed elaborare eventi e sottoscrivere operazioni eseguite, il tutto senza bloccare il thread principale.
1. Call Stack: JS è single-threaded, ha un'unico stack di chiamate in cui vengono eseguite le funzioni. Ogni funzione invocata viene aggiunta a questo stack, e una volta terminata, viene rimossa.
2. Message Queue: Struttura dati in cui vengono messi i messaggi contenenti funzioni callbacl da eseguire. Questi messaggi sono in attesa di essere elaborati una volta che lo stack di chiamate è vuoto.
3. Event Loop: Meccanismo che controlla i due precedenti. Quando lo stack di chiamate è vuoto, l'event look prende la prima funzione della coda di messaggi e la mette nello stack di chiamate per l'esecuzione. Continua ciclicamente.

# NODE.JS: 
Runtime JS costruito sul V8 di Google Chrome, permette di eseguire JS lato server. Utilizza l'event loop per gestire le operaizoni di I/O asincrone. Invece di bloccare il thread principale durante le operazioni di I/O, come la lettura da file o l'invio di richieste di rete, node.js  delega queste operazioni ad un pool di thread worker ( `libuv` ) che gestisce le operazioni I/O in background. Quando un'operazione I/O è completata, una callback corrispondente viene messa nella coda dei messaggi, e l'event loop se ne occupa non appena lo stack di chiamate è vuoto.

>[!important]- NODEJS: Basato su un'architettura event-driven e non-bloccante. Un thread principale per l'esecuzione del codice JS, sfrutta un pool di thread del SO per operazioni di I/O asincrone.

## ARCHITETTURA DI NODE.JS:
1. Single Thread: utilizza un singolo thread per eseguire il codice JavaScript.
2. Libuv: Una libreria multi-piattaforma che gestisce il pool di thread, la gestione degli eventi e le operazioni I/O asincrone.
3. Event Loop: il cuore del modello di concorrenza di Node.js.
4. Callback: Funzioni che vengono passate come argomenti ad altre funzioni per essere eseguite dopo il completamento di operazioni asincrone (.then, .catch).
5. EventEmitter: Un modulo che facilita la gestione degli eventi e delle callback.

## VANTAGGI:
1. Alta Concorrenza: L'architettura non bloccante permette a Node.js di gestire un elevato numero di connessioni contemporanee senza bloccare il thread principale.
2. Efficienza: La delega delle operazioni I/O a thread worker permette di liberare il thread principale per altre operazioni, migliorando l'efficienza complessiva.

### MIDDLEWARE: 
Funzione che ha accesso all'oggetto request, response e alla funzione next in Express.js

# SPECIFICITÀ CSS: 
Determina quali regole CSS vanno applicate ad un elemento specifico quando ci sono regole contrastanti. basata su ID, classi e pseudo-classi.

## WEB FONT: 
Font caricati e utilizzati nelle pagine web tramite CSS.

## FONT-FAMILY: 
Specifica una lista di famiglie di caratteri per un elemento.

## FONT STACK: 
Lista di famiglie di caratteri specificata nella proprietà font-family. Permette al browser di usare il primo font disponibile nell'elenco. Se non è possibile, va a cascata.

### DESKTOP-FIRST e MOBILE-FIRST: 
Due approcci alla progettazione responsive.
DF- max-width con media query
MF- min-width

### SERIF, SANS-SERIF:
Con grazie e senza grazie, presenza o meno di piccoli abbellimenti.

### MARGIN e PADDING: 
Margin esterno Padding interno

### BORDER-BOX: 
box-sizing: border-box modifica il comportamento del modello di box. QUando è impostata

## CSS position:
- static : valore predefinito secondo il normale flusso del documento.
- fixed : posizionato rispetto alla finestra del browser, non si muove quando la pagina viene scrollata.
- relative : posizionato rispetto alla sua posizione originale 
- absolute : posizionato rispetto all'elemento contenitore più vicino che ha una posizione diversa da static.

## MEDIA QUERY: 
applicare stili differenti a seconda delle caratteristiche del dispositivo, come la larghezza della finestra o la risoluzione dello schermo. Usate soprattutto per il design desktop-tablet-mobile.

RESPONSIVE:
1. Uso di layout fluidi a percentuali ( non pixel ).
2. Media queries
3. Margini responsive
4. Griglie flessibili e framework come Bootstrap o Foundation.

# JAVASCRIPT: 
Linguaggio di programmazione dinamico e interpretato, basato sugli eventi e orientato agli oggetti. Supporta funzioni di prima classe ed ha un'ampia compatibilità coi browser. Usa la gestione asincrona tramite callback, promises e async/await, ma soprattutto permette la manipolazione del DOM.

## FORM: 
contenitore per elementi di input che permette di inviare dati ad un server. Include campi di testo, caselle di controllo, pulsanti radio, menu a discesa e pulsanti di invio.

## THIS LATO FUNCTION: 
Due casi:
1. Funzione come metodo di un oggetto: this si riferisce all'oggetto stesso
2. Funzione standal-one: this si riferisce all'oggetto globale.

## PROMISE: 
rappresenta l'eventuale completamento o fallimento di un'operazione asincrona. Tre stati: pending ( in attesa ), fulfilled ( completata con successo ) e rejected ( fallita ). Il costruttore `promise` prende una funzione executor con i parametri resolve e reject.  

## CODA DI MICROTASK: 
coda di operazioni che devono essere eseguite dopo il completamento della task attuale. Esempio: promise.

## GARBAGE COLLECTOR: 
sistema di gestione della memoria che recupera la memoria inutilizzata liberando oggetti non più raggiungibili o utilizzati.

## SCOPE: 
visibilità e durata delle variabili e delle funzioni: Scope locale/globale.

## COSTRUTTORE: 
funzione/oggetto chiamato per inizializzare l'oggetto appena creato. `new`:
1. Creato oggetto vuoto e assegnato a this
2. Eseguita la funzione
3. Ritornato this
Lo scope di `var` è il functional block più vicino.
Lo scope di `let` è l'enclosing block più vicino.

# DOM: 
Document Oject Model. Rappresentazione strutturata di un documento HTML sotto forma di albero. Permette a JS di manipolare il contenuto, la struttura e lo stile.

## CODICE SINCRONO/ASINCRONO:
1. Sincrono: eseguito in sequenza, ogni istruzione attende la fine della precedente.
2. Asincrono: permette l'esecuzione di operazioni senza bloccare il flusso principale del programma (callback, promises o async/await).

## ROUTING: 
Determinazione di quale azione intraprendere in risposta ad una richiesta di un URL specifico.
### LATO SERVER: 
associa gli URL alle funzioni del serve ai controller che gestiscono le richieste. Quando un server web riceve una richiesta, il router analizza l'URL e decide quale codice eseguire per rispondere alla richiesta.