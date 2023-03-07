# Introduzione

## Dati, informazioni e sistemi informativi
- **Dati**: In informatica. la singola informazio ecodificabile o codificata. Ciò che è immediatamente presente alla conoscenza, prima di ogni elaborazione
- **Informazione**: notizia, dato o elemento che consente di avere conoscenza più o meno esatta di fatti, situazioni, modi di essere
- [[#Sistema informativo]] 


**Esempio**
8 e Ferrari scritti su un foglio di carta sono due dati, da soli non segnificano nulla...

...se il folgio di carta è relativpo alle ordinazioni in un ristorante e sono note le regole che i camerieri devono eseguire allora il foglio rappresenta l'ordinazione di una bottiglia di spumante marca Ferrari da addebbitare alla stanza 8

**Con le indicazioni aggiuntive i dati diventano informazioni e arricchiscono la conoscenza**

- **L'evoluzione della tecnologia** permette oggi di raccogliere una grande quantità di dati, continuamente e in maniera pervasiva
**Conseguenza**: corretta e efficente gestione dati, che è sempre stata fondamentale per la buona realizzazione di qualsiasi sistema informativo

### Risorse di una organizzazione
- persone
- denaro
- materiali
- informazioni
### Funzioni di un sistema informativo
- acquisizione delle informazioni
- conservazione delle informazioni
- elaborazioni delle informazioni
- distribuzione, scambio di informazioni

### Sistema informativo
_Def_:
è la componente (**sottosistema**) di un'organizzazione che gestisce (acquisisce, elabora, conserva, produce) le informazioni d'interesse:
- Ogni organizzazione ha un sistema informativo, eventualemente non esplicitato nella struttura.
- Quasi sempre,il sistema informativo è di supporto ad altri sottosistemi, va quindi studiato nel contesto in cui è inserito
- Il sistema informativo è in genere suddiviso in sottosistemi più o meno fortemente integrati

Il concetto di "**sistema informativo**" è indipendente da qualsiasi automazione:
- Esistono organizzazioni la cui ragion d'essere è la gestione d'informazioni
Per la porzione automatizzata del sistema informativo, al giorno d'oggi viene usato il termine **sistema informatico**, termine usato oggi per distinguere tutti i sistemi informativi

>Sistema Azienda
>>SIistema Informativo
>>>Sistema Informatico

Nelle attività standadrizzate dei sistemi informativi complessi, sono state introdotte nel tempo forme di organizzazione e codifica delle informazioni
Nei sistemi informatici, le informazioni vengono rappresentate in modo essenziale attraverso i dati

## Informazioni e dati
Nei sistemi informatici, le informazioni vengono rappresentate in modo essenziale, attraverso i **dati**
Dal Vocabolario della lingua italiana:
- **Informazione**: notizia, dato o elemento che consente di avere conoscenza più o meno esatta di fatti, situazioni, etc...
- **Dato**: ciò che è immediatamente presente alla conoscenza, prima di ogni elaborazione;

I dati costituiscono spesso una risorsa strategica, perchè più stabili nel tempo di altre componenti
**Esempio**
- I dati bancari hanno una struttura invariata da decenni. Le applicazioni che operano su essi invece cambiano di frequente. La nuova procedure "eredità" i dati dalla vecchia con opportune trasformazioni
- I dati vista la loro stabilità costituiscono una risorsa per l'organizzazione, un patrimonio da sfruttare e proteggere

All'interno del sistema informativo, la collezione di dati è chiamata **Basi di dati** o **Database**
- Compito della base di dati è non solo di memorizzare ma di rappresentare le relazioni tra essi
All'interno del sistema informativo il software atto specificatamente a gestire i dati è detto Sistema di Gestione della base di dati o **Database Management System**

## Basi di dati

_Def metodologica:_ Insieme organizzato di dati utilizzati per il supporto allo svolgimento delle attività
_Def metodologica e tecnologica:_ insieme di dati gestito dal DBMS

**Data Independence:** La struttura di un DB deve dare garanzia che modifiche dei dati non richiedano modifiche ai programmi applicativi e/o alle tecniche di accesso ai dati stessi

- **Basi di dati o Database**
Collezione di informazioni registrate in formato leggibile dell'elaboratore elettronico e relativa ad un preciso dominio di conoscenze, organizzata allo scopo di poter essere consultata dai suoi utilizzatori

- **DMBS**
	Sistema (**prodotto software**) in grado di gestire **collezione di dati** che siano:
		- **grandi**: di dimensioni molto maggiori della memoria centrale dei sistemi di calcolo
		- **persistenti**: con un periodo di vita indipendente dalle singole esecuzioni dei programmi
		- **condivise**: utilizzate da applicazioni e utenti diversi
	garantendo **affidabilità** (resistenza a malfunzionamenti hardware e software) e **privatezza**(con una disciplina e un controllo degli accessi). Come ogni prodotto informatico, un DBMS deve essere **efficente**(utilizzando al meglio le risorse di spazio e tempo) ed **efficace**(rendendo produttive le attività dei suoi utilizzatori)

- **Archivio di file**
L'approccio classico usato dai programmi che compongono il sistema informativo per la gestione delle informazioni è un archivio basato su files
Ogni programma ha accesso al file system gestito dal sistema operativo per creare uno o più files (**archivi**)

![[Pasted image 20221013151002.png|center]]


Ogni file è un insieme di registrazioni (**record**) allìinterno dei quali sono memorizzati i dati elementari (**attributi e campi**)
Condivisione di dati tra più programmi può essere fatto tramite l'uso di file condivisi

![[Pasted image 20221013151249.png|center]]
I file possono avere diversi **formati incompatibili** tra di loro, i programmi si devono adeguare a diverse convenzioni. Questo rende la **condivisione** dei dati attraverso applicazioni differenti **difficoltosa**
I dati se non memorizzati su file condivisi sono replicati con spreco di **risorse** di memorizzazione e possibili problemi legati a inconsistenze
L'accesso ai file in condivisione porta a dover gestire la **concorrenza con soluzioni ad-hoc**
L'approccio basato su DBMS invece va oltre l'uso di file locali gestiti dalle singole applicazioni tramite l'adozione di un sistema di gestione di dei dati che risulta **indipendente** dalle applicazioni e **specializzato** in tale funzione.
I dati non sono gestiti dalle singole applicazioni ma da un DBMS che offre un **interfaccia comune** a tutte le applicazioni
Si interpone fra le applicazioni e la memoria di massa

![[Pasted image 20221013152000.png|center]]

### ...Ritornando al DBMS

- **Grandi quantità di dati**: I dati gestiti da una base di dati sono:
	- DI solito più della memoria centrale:vanno gestiti in memoria secondaria
	- L'unico limite deve essere la dimensione della memoria secondaria, e nelle basi di dati distribuite nenche questo rappresenta un problema
- **Persistenza**: i dati hanno un **ciclo di vita** che dura nel tempo, un'altra ragione per la gestione in memoria secondaria
- **Condivisione**: 
	- Ogni organizzazione è divisa in settori o comunque svolge attività diverse
	- A ciascun settore o attività corrisponde un sistema informativo
	- Possono esistere sovrapposizioni fra i dati di interesse dei vari settori
	- Una base di dati è una risorsa **integrata**, condivisa fra i vari settori
	- Ridurre la **ridondanza**: una base di dati centralizzata permette di ridurre la replica della stessa informazione che si avrebbe se le diverse applicazioni gestissero i dati tramite file locali
	- Ridurre **l'inconsistenza**: l'eliminazione della presenza di varie copie dello stesso dato elimina la possibilità di inconsistenze, la gestione attraverso una componente specializzata permette di introdurre controlli sui dati per garantirne la consistenza

I DMBS sono componenti software specializzati nel gesire grandi quantità di dati e implementano procedure basate sulle best-practices per la gestione di:
- **Efficacia e efficienza**: le tecniche di memorizzazione adottate permettono di migliorare le prestazioni di memorizzazione e accesso alle informazioni
- **Affidabilità**: tecniche di salvaguardia e verifica dell'integrità dei dati in caso di malfunzionamento hardware e software (crash recovery) sono solitamente implementate
- **Concorrenza**: i sistemi DBMS implementano delle metodologie per garantire un accesso concorrente ai dati minimizzandone l'impatto sulle prestazioni di accesso
- **Privatezza**: tecniche di sicurezza per garantire accesso ristretto sono implementate in modo da garantire a ciascun utente accesso solo al sottoinsieme dei dati a cue è autorizzato
- **Riduzione del tempo di sviluppo**: invece di implementare le funzionalità di gestione dei dati ogni applicazione si appoggia su quelle fornite dal DBMS
- **Semplificazione e standardizzazione dello sviluppo**: il processo di realizzazione delle applicazioni viene semplificato dato che la memorizzazione e la gestione dei dati è demandato ad una componente con la quale l'applicazione interagisce tramite un'interfaccia standard

