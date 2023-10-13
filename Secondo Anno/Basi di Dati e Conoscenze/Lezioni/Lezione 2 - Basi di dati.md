# Dati, informazioni e sistemi informativi
**Dato**: In informatica, la singola informazione codificabile o codificata. Ciò che è immediatamente presente alla conoscenza, prima di ogni elaborazione.
**Informazione**: Notizia, dato o elemento che consente di avere conoscenza più o meno esatta di fatti, situazioni, modi di essere.

*8 e Ferrari scritti su un foglio di carta sono due dati, da soli non significano nulla...*
...se il foglio di carta è relativo alle ordinazioni in un ristorante la notte di capodanno e sono note le regole che i camerieri devono seguire, allora il foglio rappresenta l'ordinazione di una bottiglia di spumante marca Ferrari da addebitare alla stanza 8.
**Con le indicazioni aggiuntive i dati diventano informazioni e arricchiscono la conoscenza**.

**L'evoluzione della tecnologia** permette oggi di raccogliere una grande quantità di dati, continuamente e in maniera pervasiva.
- *Conseguenza*: corretta e efficiente gestione dati, che è sempre stata fondamentale per la realizzazione di qualsiasi sistema informativo.
## Le risorse di una organizzazione
1. Persone
2. Denaro
3. Materiali
4. Informazioni
## Funzioni di un sistema operativo
1. Acquisizione delle informazioni
2. Conservazione delle informazioni
3. Elaborazione delle informazioni
4. Distribuzione, scambio di informazioni
# Dati, informazioni e sistemi informazioni

>[!info]- Sistema informativo
>Componente (**Sottosistema**) di un'organizzazione che gestisce(acquisisce, elabora, conserva, produce) le informazioni d'interesse (cioè utilizzate per il proseguimento degli scopi dell'organizzazione).

Ogni organizzazione ha un sistema informativo, eventualmente non esplicitato nella struttura.
Quasi sempre, il sistema operativo è di supporto ad altri sottosistemi, va quindi studiato nel contesto in cui è inserito.
Il sistema informativo è in genere suddiviso in sottosistemi più o meno fortemente integrati.
Il concetto di "**Sistema informativo**" è indipendente da qualsiasi automazione: esistono organizzazioni la cui ragion d'essere è la gestione d'informazioni, e che esistono da secoli.
Per la porzione automatizzata del sistema informativo, al giorno d'oggi viene usato il termine *sistema informatico*, termine usato oggi per contraddistinguere tutti i sistemi informativi.
![[Pasted image 20231005155210.png|center]]

Nelle attività standardizzate dei sistemi informativi complessi, sono state introdotte nel tempo forme di organizzazione e codifica delle informazioni.
Ad esempio, nei servizi anagrafici si è iniziato con registrazioni discorsive e poi:
1. Nome e Cognome
2. Estremi anagrafici
3. Codice Fiscale
Nelle attività umane, le informazioni vengono gestite ( registrate e scambiate ) in forme diverse:
- - Idee informali;
- - Linguaggio naturale;
- - Disegni, grafici, schemi;
- - Numeri e codici.
E su vari supporti:
- -Memoria umana;
- - Carta;
- - Dispositivi elettronici.
Nei sistemi informatici, le informazioni vengono rappresentate in modo essenziale attraverso i dati.
Approssimativamente i dati non hanno alcun significato, ma se correlati e interpretati forniscono informazioni che consentono di arricchire la nostra conoscenza del mondo.
## Informazioni e dati (1)
Nei sistemi indormatici, le informazioni vengono rappresentate in modo essenziale, attraverso i *dati*.
- **Informazione**: Notizia, dato o elemento che consente di avere conoscenza più o meno esatta di fatti, situazioni, modi di essere.
- **Dato**: Ciò che è immediatamente presente alla conoscenza, prima di ogni elaborazione; In Informatica elementi di informazione costituiti da simboli che devono essere elaborati.
# Dati, informazioni e sistemi informativi
I dati costituiscono spesso una risorsa strategica, perché più stabili nel tempo di altre componenti ( processi, tecnologie, ruoli umani).

>[!warning]-  Esempio

I dati bancari hanno una struttura invariata da decenni. Le applicazioni che operano su essi invece cambiano di frequente. La nuova procedura "eredita" i dati dalla vecchia con opportune trasformazioni. I dati vista la loro stabilità costituiscono una risorsa per l'organizzazione, un patrimonio da sfruttare e proteggere.
All'interno del sistema informativo, la collezione dei dati è chiamata *Base di dati* o **Database**.
- Compito della basi di dati è non solo di memorizzare i dati ma di rappresentare le relazioni tra di essi.
All'interno del sistema informativo il software atto specificatamente a gestire i dati è detto Sistema di Gestione della basi di dati o **Database Management System**.
Tradizionalmente adottato nei sistemi informativi di grandi dimensioni ( solitamente composti da più programmi ), oggi adottato anche da sistemi più semplici.
# Base di dati
(accezione generica, **Metodologica**)
Insieme organizzato di dati utilizzati per il supporto allo svolgimento delle attività di un ente ( azienda, ufficio, persona ).
(accezione specifiica, *metodologica* e **tecnologica**)
Insieme di dati gestito da un DBMS.
*Data independence* : La struttura di un DB deve dare garanzia che modifiche dei dati non richiedano modifiche ai programmi applicativi e/o alle tecniche di accesso ai dati stessi.

>[!important]- Basi di dati o **Database** 
>Collezione di informazioni registrate in formato leggibile dall'elaboratore elettronico e relativa ad un preciso dominio di conoscenze ( azienda, università, mente di qualcuno, ecc. ), organizzata allo scopo di poter essere consultata dai suoi utilizzatori.

## Sistema di gestione di basi di dati
**DMBS**
Sistema (**prodotto software**) in grado di gestire **collezione di dati** che siano:
	- **grandi**: di dimensioni molto maggiori della memoria centrale dei sistemi di calcolo
	- **persistenti**: con un periodo di vita indipendente dalle singole esecuzioni dei programmi
	- **condivise**: utilizzate da applicazioni e utenti diversi
	garantendo **affidabilità** (resistenza a malfunzionamenti hardware e software) e **privatezza**(con una disciplina e un controllo degli accessi). Come ogni prodotto informatico, un DBMS deve essere **efficente**(utilizzando al meglio le risorse di spazio e tempo) ed **efficace**(rendendo produttive le attività dei suoi utilizzatori).

### Archivio di file

L'approccio classico usato dai programmi che compongono il sistema informativo per la gestione delle informazioni è un archivio basato su files.
Ogni programma ha accesso al file system gestito dal sistema operativo per creare uno o più files (**archivi**)

![[Pasted image 20221013151002.png|center]]


Ogni file è un insieme di registrazioni (**record**) all'interno dei quali sono memorizzati i dati elementari (**attributi e campi**)
Condivisione di dati tra più programmi può essere fatto tramite l'uso di file condivisi

![[Pasted image 20221013151249.png|center]]

I file possono avere diversi **formati incompatibili** tra di loro, i programmi si devono adeguare a diverse convenzioni. Questo rende la **condivisione** dei dati attraverso applicazioni differenti **difficoltosa**.
I dati se non memorizzati su file condivisi sono replicati con spreco di **risorse** di memorizzazione e possibili problemi legati a inconsistenze.
L'accesso ai file in condivisione porta a dover gestire la **concorrenza con soluzioni ad-hoc**.
L'approccio basato su DBMS invece va oltre l'uso di file locali gestiti dalle singole applicazioni, tramite l'adozione di un sistema di gestione di dei dati che risulta **indipendente** dalle applicazioni e **specializzato** in tale funzione.
I dati non sono gestiti dalle singole applicazioni ma da un DBMS che offre un **interfaccia comune** a tutte le applicazioni
Si interpone fra le applicazioni e la memoria di massa

![[Pasted image 20221013152000.png|center]]

### Grandi quantità di dati
I dati gestiti da una base di dati sono:
1. Di solito più della memoria centrale: vanno gestiti in memoria secondaria;
2. L'unico limite deve essere la dimensione della memoria secondaria, e nelle basi di dati distribuite neanche questo rappresenta un problema.
### Persistenza
I dati hanno un *ciclo di vita* che dura nel tempo. Ragione in più per la gestione in memoria secondaria.

### Condivisione
Ogni organizzazione ( specie se grande) è divisa in settori o comunque svolge diverse attività.
A ciascun settore o attività corrisponde un (sotto)sistema informativo.
Possono esistere sovrapposizioni fra i dati di interesse dei vari settori.
Una base di dati è una risorsa **integrata**, condivisa fra i vari settori.

Ridurre la *rindondanza*:
	Una base di dati centralizzata permette di ridurre la replica della stessa informazione che si avrebbe se le diverse applicazioni gestissero i dati tramite file locali.
Ridurre l'*inconsistenza*: 
	L'eliminazione della presenza di varie copie dello stesso dato elimina la possibilità di inconsistenze, la gestione attraverso una componente specializzata permette di introdurre controlli sui dati per garantirne la consistenza.

DBMS sono componenti software specializzati nel gestire grandi quantità di dati e implementano procedure basate sulle best-practices ( solitamente non implementate nelle soluzioni basate su file) per la gestione di:
1. *Efficacia ed efficienza*: Le tecniche di memorizzazione adottate permettono di migliorare le prestazioni di memorizzazione e accesso alle informazioni ( che altrimenti dovrebbero essere implementate in ogni programma).
2. *Affidabilità*: Tecniche di salvaguardia e verifica dell'integrità dei dati in caso di malfunzionamenti hardware e software (crash recovery) sono solitamente implementate.
3. *Concorrenza*: I sistemi DBMS implementano delle metodologie per garantire un accesso concorrente ai dati minimizzandone l'impatto sulle prestazioni di accesso.
4. *Privatezza*: Tecniche di sicurezza per garantire accesso ristretto sono implementate in modo da garantire a ciascun utente accesso solo al sottonisieme dei dati a cui è autorizzato.
5. *Riduzione del tempo di sviluppo*: Invece di implememtare le funzionalità di gestione dei dati ogni applicazione si appoggia su quelle fornite dal BDMS.
6. *Semplificazione e standardizzazione dello sviluppo*: Il processo di realizzazione delle applicazioni viene semplificato dato che la memorizzazione e la gestione dei dati è demandato ad una componente con la quale l'applicazione interagisce tramite un'interfaccia standard.
#### DBMS, alcuni prodotti
1. DB2;
2. Oracle;
3. SQLServer;
4. Postgres;
5. MySQL;
6. SQLite.