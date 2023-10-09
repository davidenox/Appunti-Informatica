# Modelli dei dati
## DBMS vs File System
L'efficienza di un sistema si misura ( come in tutti i sistemi informatici ) in termini:
- - Di *tempo* di esecuzione ( tempo di risposta ) e spazio;
- -Di *memoria* ( principale e secondaria ).
I DBMS, a causa della varietà di funzioni, non sono necessariamente più efficienti dei file system. L'efficienza è il risultato della qualità del DBMS e delle applicazioni che lo utilizzano.
La gestione di insiemi di dati grandi e persistenti è possibile anche attraverso problemi più semplici ( gli ordinari *file system* dei sistemi operativi ). I file system prevedono forme rudimentali di condivisione: " tutto o niente ". Nei DBMS, è consentita una maggiore flessibilità. I DBMS estendono le funzionalità dei file system, fornendo più servizi ed in maniera integrata ( efficacia ).
Nei programmi tradizionali che accedono a file, ogni programma contiene una descrizione della struttura del file stesso, con i conseguenti rischi di incoerenza fra le descrizioni ( ripetute in ciascun programma ) e i file stessi. Nei DBMS, esiste una porzione della base di dati ( il *catalogo* o *dizionario* ) che contiene una descrizione centralizzata dei dati, che può essere utilizzata da vari programmi.
## Modello di rappresentazione dei dati
I DBMS non sono progettati per gestire un unico caso d'uso, al contrario sono software in grado di gestire dati eterogenei. Al fine di creare e gestire la corrispondente base di dati uno schema dei dati deve essere fornito al DBMS. Lo schema viene costruito secondo un modello di dati ben definito. Un Modello di Dati è una collezione di costrutti usato per descrivere lo schema dei dati, le loso relazioni e i vincoli di consistenza che devono essere applicati sugli stessi. Tramite questo schema di dati si fornisce al DBMS una rappresentazione dei dati, in modo tale da permettere l'organizzazione della gestione.
Le descrizioni e rappresentazioni dei dati a livelli diversi permettono l'indipendenza dei dati dalla rappresentazione fisica: i programmi fanno riferimento alla struttura a livello più alto, e le rappresentazioni sottostanti possono esserte modificate senza necessità di modificare dei programmi. Questo concetto viene realizzato tramite il  **modello dei dati**.
*Modello dei dati*: Un Modello dei dati è un insieme di concetti per organizzare i dati di interesse e descriverne la struttura in modo che essa risulti comprensibile ad un elaboratore( e non solo... ).
*Definizione di Ullman*: Un formalismo matematico composto da :
- - Una notazione per scrivere i dati;
- - Un insieme di operazioni per manipolate tali dati.
Più precisamente,
**Modello dei dati**: Insieme di costrutti utilizzati per organizzare i dati di interesse e descriverne la *struttura* e la *dimanica*.
Un *modello* di dati è costituito da:
1. *Costrutti sintattici* per definire i dati;
2. *Regole semantiche* per interpretare i dati;
3. *Linguaggi* per manipolare i dati.
![[Pasted image 20231009162330.png|center]]
### Modelli per la rappresentazione dei dati nei DBMS
Insieme di costrutti utilizzati per organizzare i dati di interesse e descrivere le operazioni su di essi. Due tipi di modelli:
- - *Modello logico*;
- -*Modello concettuale*;
#### Modello logico
Esistono diverse tipologie di modelli logici definiti nel tempo. Descrivono l'organizzazione dei dati nei DBMS "*visibile*" all'utente. Sono indipendenti dalle strutture fisiche:
- *Gerarchico* e *reticolare*:
- - Utilizzano riferimenti espliciti ( puntatori ) fra record.
- *Modello ad oggetti*: (ODBMS, Object Database Management System)
- - L'informazione è rappresentata in forma di *oggetti*;
- - Utilizzate in un mercato di nicchia rispetto al modello relazionale (RDBMS). ( applicazioni real time)
- *Relazionale*: è basato sui valori (RDBMS):
- - Anche i riferimenti fra dati in strutture ( relazioni ) diverse sono rappresentati per mezzo dei valori stessi.
#### Modello concettuale
Hanno l'obiettivo di descrivere i *concetti* del mondo reale, utilizzati nelle fasi iniziali della progettazione. ( *Entity-Relationship* e *Modello Classi Associazioni* (UML) ).
![[Pasted image 20231009163218.png|center]]

## Schemi e istanze
In ogni base di dati esistono:
1. Lo *schema*, sostanzialmente invariante nel tempo, che ne descrive la struttura ( aspetto intensionale ).
	- Nell'esempio, le intestazioni delle tabelle.
2. L'*Istanza*, i valori attuali, che possono cambiare anche molto rapidamente ( aspetto estensionale ).
	- Nell'esempio, il "corpo" di ciascuna tabella.
#### Schema
*Struttura della base di dati*
![[Pasted image 20231009163742.png|center]]

#### Istanza
*Contenuto della base dati*
![[Pasted image 20231009163819.png|center]]

## Architettura standard (ANSI/SPARC) a tre livelli per DBMS
![[Pasted image 20231009163909.png|center]]

### Architettura di un DBMS : schemi
*Schema logico*: Descrizione della base di dati nel modello logico del DBMS;
*Schema fisico*: Rappresentazione dello schema logico per mezzo di strutture memorizzazione (file).
*Schema esterno*: Descrizione di parte della base di dati in un modello logico ( "viste" parziali, derivate, anche in modelli diversi )
#### Viste
![[Pasted image 20231009164322.png|center]]
#### Schemi dei dati: Esempio
Un'analogia con il mondo della programmazione facendo rifermento alle matrici.
*Livello concettuale*:
```Java
int a[n][m];
```
*Livello fisico*: (con $a_0$= locazione iniziale)
```Java
A[i][j] è nella locazione a0+4(m(i-1)+j-1) 
```
*Schema fisico*: Il vettore è memorizzato in $4(n*m)$ celle contigue a partire dalla locazione $a_0$ (un intero è rappresentato con 4 byte).
*Schema concettuale*: è cosituito dalla dichiarazione 
```Java
int a[n][m];
```
Dove, A è una matrice di interi con n righe e m colonne.
*Schema esterno(vista)*: Un possibile schema è costituito dalla seguente funzione.
$$f(i)=\sum_{j = 1}^m a[i][j]$$
## Indipendenza dei dati
L'indipendenza dei darti è una conseguenza della articolazione in livelli. L'accesso avviene solo tramite il livello esterno ( che può coincidere con il livello logico ).
Due forme:
1. *Indipendenza fisica*;
2. *Indipendenza logica*.
### Indipendenza fisica
Si parla di *indipendenza fisica* quando il livello logico e quello esterno sono indipendenti da quello fisico. Una relazione è utilizzata nello stesso modo qualunque sia la sua realizzazione fisica. La *realizzazione fisica* può cambiare senza che debbano essere modificati i programmi.
### Indipendenza logica
Si parla di *indipendenza logica* quando il livello esterno è indipendente da quello logico. Aggiunte o modifiche alle viste non richiedono modifiche al livello logico. Modifiche allo schema logico che lasciano inalterato lo schema esterno sono trasparenti.
## Linguaggi per basi di dati
1. Operazioni sullo schema:
	- ***DDL**: Data Definition Language*.
2. Operazioni sui dati:
	- ***DML**: Data Manipulation Language*.
### Un'operazione DDL
(Sullo schema)
```SQL
create table orario (
insegnamento char(20),
docente      char(20),
aula         char(4) ,
ora          char(5) )
```
#### Un'operazione DML
(Sullo schema)
```SQL
select docente
from orario
where aula = 'N1'
```
## Linguaggi per basi di dati
I DBMS dispongono di vari linguaggi e interfacce diverse
(slide 34)
