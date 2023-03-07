
- [[Appunti BSD/MOD I/Lezione 2#DBMS vs file system|DBMS vs file system]]
- [[Appunti BSD/MOD I/Lezione 2#Modello di rappresentazione dei dati|Modello di rappresentazione dei dati]]
- [[Appunti BSD/MOD I/Lezione 2#Schemi ed istanze|Schemi ed istanze]]
- [[Appunti BSD/MOD I/Lezione 2#Architettura di un DBMS|Architettura di un DBMS]]
- [[Appunti BSD/MOD I/Lezione 2#Indipendenza logica e fisica|Indipendenza logica e fisica]]
- [[Appunti BSD/MOD I/Lezione 2#Linguaggi per basi di dati|Linguaggi per basi di dati]]
- [[Appunti BSD/MOD I/Lezione 2#Attori del sistema|Attori del sistema]]


# DBMS vs file system
L'efficenza di un sistema si misura(come in tutti i sistemi informatici) in termini:
- di **tempo** di esecuzione e spazio
- di **memoria**
I DMBS, a causa della varietà di funzioni, non sono necessariamente più efficenti dei file system
L'efficenza è il risultato della qualitaà del DBMS e delle applicazioni che lo utilizzano
La gestione di inisiemi di dati grandi e persisteni è possibile anche attraverso sistemi più semplici - gli ordinai **file system** dei sistemi operativi
I file system prevedono forme rudimentali di consivisione: "tutto o niente". Nei DBMS, è consentita una maggiore flessibilità
I DBMS estendono le funzionalità dei file system, fornendo più servizi ed in maniera integrata
Nei programmi tradizionali che accedono a file, ogni programma contiene una descrizione della struttura del file stesso, con i conseguenti rischi di incoerenza fra le descerizioni e i file stessi
Nei DBMS, esiste una porzione della base di dati(**il catalogo o dizionario**) che contiene una descrizione centralizzata dei dati, che può essere utilizzata dai vari programmi

# Modello di rappresentazione dei dati

I DBMS non sono progettati per gestire un unico caso d'uso, al contrario sono software in grado di gestire dati eterogenei
Al fine di reare e gestire la corrispondente base di dati un schema dei dati deve essere fornito dal DBMS
Lo schema viene costruito secondo un modello di dati ben definito. Un Modello di Dati è una collezione di costrutti usati pr descrivere lo schema dei dati, le loro relazioni e i vincoli di consistenza che devono essere applicati sugli stessi
Tramite questo schema dei dati fornisce al DBMS una rappresentazione dei dati, in modo tale da permettere l'organizzazione della gestione
Le descrizioni e rappresentazioni dei dati a livelli diversi permettono l'indipendenza dei dati dalla rappresentazione fisica:
- i programmi fanno riderimento alla struttura a livello più alto, e le rappresentazioni sottostanti possono essere modificate senza necessità di modifica dei programmi
- QUesto concetto viene realizzato tramite il [[Appunti BSD/MOD I/Lezione 2#Modello dei dati|Modello dei dati]]
## Modello dei dati
Un Modello dei dati è un insieme di concetti utilizzati per organizzare i dati di interesse e descriverne la struttura in modo che essa risulti comprensibile ad un elaboratore

### Definizione di Ullman
- Un formalismo matematico composto da:
	- una notazione per descriver i dati
	- un insieme di operazioni per manipolare tali dati
Più precisamente:
**Modello di Dati**: insieme di costrutti utilizzati per organizzare i dati di interesse e descriverne la **struttura** e la **dinamica**
Un modello di dati è costituito da:
- **Costrutti sintattici** per definire i dati
- **Regole semantiche** per interpretare i dati
- **Linguaggi** per manipolare i dati

Esistono due tipi di modelli:
- **Modello logico**
- **Modello concettuale**

### Modello Logico
- Esistono diverse tipologie di modelli logici definiti nel tempo
- Descrivono l'organizzazione dei dati nei DBMS "**visibile**" all'utente
- Sono indipendenti dalle strutture fisiche
- **Gerarchico e reticolare**:
	- utilizzano riferimento espliciti (puntatori) fra record
- **Modello ad oggetti** (ODBMS,Object DBMS):
	- L'informazione è rappresentata in forma di **oggetti**
	- Utilizzate in un mercato di nicchia rispetto al modello relazione (RDBMS)
- **Relazionale**:
	- anche riferimento fra dati in strutture (relazioni) diverse sono rappresentati per mezzo dei valori stessi

### Modello Concettuale
- ha l'obiettivo di descrivere i **concetti** del mondo reale
- vengono utilizzati nelle fasi iniziali della progettazione
- **Entity-Relationship e Modello Classi Associazioni (UML)**

Esempio di modello concettuale
![[Pasted image 20221019164651.png|center|500]]

# Schemi ed istanze
In ogni base di dati esistono:
- lo **schema**,sostanzialmente inveriante nel tempo, che ne descrive la struttura (aspetto intensionale):
	- nell'esempio, le intestazioni delle tabelle
- **l'istanza**,i valori attuali, che possono cambiare anche molto rapidamente (aspetto estensionale)
	- nell'esempio, il "corpo" di ciascuna tabella

**Schema**
![[Pasted image 20221019165018.png|center|500]]
**Istanza**
![[Pasted image 20221019165123.png|center|600]]


# Architettura di un DBMS
## Architettura standard (ANSI/SPARC) a tre livelli per DBMS
![[Pasted image 20221019165546.png|center|600]]

## Schemi
- **schema logico**: descrizione della base di dati nel modello logico del DBMS
- **schema fisico**: rappresentazione dello schema logico per mezzo di strutture memorizzazione (file)
- **schema esterno**: descrizione di parte della base di dati in un modello logico ("viste" parziali,derivate,anche in modelli diversi)
**Esempio**
Un'analogia con il mondo della programamzione facenco riferimento alle matrici
- Livello concettuale:$$\text{int a[n][m];}$$
- Livello fisico:($\text{con a0=locazione iniziale}$)$$A[i][j]\text{è nella locazione }a_0+4(m(i-1)+j-1)$$
- schema fisico: il vettore è memorizzato in 4($n*m$) celle contigue a partire dalla locazione $a_0$(un intero è rappresentato con 4 Byte)
- schema concettuale: è costituito dalla dichiarazione $$\text{int a [n][m]}$$ dove, A è una matrice di interi con n righe e m colonne
- schema esterno(vista): un possibile schema è costituito dalla seguente funzione $$f(i)=\sum_{j=1}^ma[i][j]$$

# Indipendenza logica e fisica
L'indipendenza dei dati è una conseguenza della articolazione in livelli. L'accesso avviene solo tramite il livello esterno (che può coincidere con il livello logico)
Ne esistono due tipi:
- **indipendenza fisica**
- **indipendenza logica**

## Indipendenza Fisica
Si parla di **indipendenza fisica** quando il livello logico e quello esterno sono indipendenti da quello fisico
Una relazione è utilizzata nello stesso modo qualunque sia la sua realizzazione fisica
La **realizzazione fisica** può cambiare senza che debbano essere modificati i programmi

## Indipendenza Logica
Si parla di **indipendenza logica** quando il livello esterno è indipendente da quello logico
Aggiunte o modifiche alle viste non richiedono modifiche al livello logico
Modifiche allo schema logico che lasciano inalterato lo schema esterno sono trasparenti
# Linguaggi per basi di dati
- Operazioni sullo schema:
	- **DDL**:Data Definition Language
- Operazioni sui dati:
	- **DML**:Data Manipulation Language

**Esempio di op. DDL**
```sql
create table orario(
insegnamento char(20),
docente char(20),
aula char(4),
ora char(5))
```
**Esempio di op. DML**
```sql
select docente
from orario
where aula='N1'
```

I DBMS dispongono di vari linguaggi e interfacce diverse:
- **linguaggi testuali interattivi (SQL)**
- **comandi (come quelli del linguaggio interattivo)** immersi in un linguaggio **ospite**(Java,C,Spark,etc...)
- **comandi (come quelli del linguaggio interattivo)** immersi in un linguaggioad hoc, con altre funzionalità (es. grafici o stampe strutturate), anche con l'ausilio di strumen ti di sviluppo
- **con interfacce amichevoli**(senza linguaggio testuale)
## SQL,linguaggio interattivo
![[Pasted image 20221019171417.png|center|600]]
## SQL immerso in un linguaggio ad alto livello
![[Pasted image 20221019171506.png|center|500]]
## SQL immerso in un linguaggio ad hoc (Oracle PL/SQL)

![[Pasted image 20221019171621.png|center|600]]

# Attori del sistema
## Basi di dati: professionalità
- **progettisti** e realizzatori di DBMS
- **progettisti della base di dati** e amministratori della base di dati (DBA)
- **progettisti** e programmatori di applicazioni
- **utenti**:
	- utenti **finali**(terminalisti): eseguono applicazioni predefinite (transizioni)
	- utenti **casuali**: eseguono operazioni non previste a priori, usando linguaggi interattivi
### DBA
Persona o gruppo di persone responsabile del controllo centralizzato e della gestione del sistema, delle prestazioni, dell'affidabilità,delle autorizzazioni
Le funzioni del DBA includono quelle di progettazione, anche se in progetti complessi ci possono essere distinzioni
### Transizioni
Programmi che realizzano attivitò frequenti e predefinite, con poche eccezzioni, previste a priori
Esempi:
- versamento presso uno sportello bancario
- emissione di certificato anagrafico
- dichiarazione presso l'ufficio di stato civile
- prenotazione aerea
Le transizioni sono di solito realizzate con i programmi in linguaggio ospite
# Vantaggi e svantaggi dei DBMS
**Pro**:
- dati come risorsa comune, base di dati come modello di realtà
- gestione centralizzata con possibilità di standardizzazione ed "economia di scala"
- disponibilità di servizi integrati
- riduzione di ridondenza e inconsistente
- indipendenza dei dati
**Contro**
- costo dei prodotto e delle transizione verso di essi
- non scorporabilità delle funzionalità