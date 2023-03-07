- [[Lezione 4 - Vincoli d'integrità#Vincoli di integrità|Vincoli di integrità]]
- [[Lezione 4 - Vincoli d'integrità#Vincoli di ennupla|Vincoli di ennupla]]
- [[Lezione 4 - Vincoli d'integrità#Chiavi e schemi di relazione|Chiavi e schemi di relazione]]
- [[Lezione 4 - Vincoli d'integrità#Chiavi e valori nulli|Chiavi e valori nulli]]
- [[Lezione 4 - Vincoli d'integrità#Vincoli di integrità referenziale|Vincoli di integrità referenziale]]

# Vincoli di integrità
Esistono istanze di basi di dati che, pur sintatticamente corrette, non rappresentano informazioni possibili per l'applicazione di interesse.

**Esempio**
![[Pasted image 20221105112059.png|center|600]]

_Def_
Proprietà che deve essere soddisfatta dalle istanze che rappresentano informazioni corrette per l'applicazione
Un vincolo è una funzione booleana (un **predicato** basato sulla logica del prim'ordine) che associa ad ogni istanza il valore **vero** o **falso**
I vincoli di integrità consentono una descrizione più accurata della realtà e vengono usati dai DBMS nella esecuzione delle interrogazioni

## Tipi di vincoli
- vincoli **intrarelazionali**:
	- vincoli su valori (o di **dominio**)
	- vincoli su **ennupla**
- vincoli **interrelazionali**

# Vincoli di ennupla

Esprimono condizioni sui valori di ciascuna ennupla, indipendentemente dalle altre ennuple
Caso particolare:
- **vincoli di dominio**: coinvolgono un solo attributo
Una possibile sintassi:
- espressione booleana di atomi che confrontano valori di attributo o espressioni aritmetiche su di essi
![[Pasted image 20221105112635.png|center|500]]

**Esempio**
![[Pasted image 20221105112832.png|center|600]]


# Chiavi e schemi di relazione

## Identificatore delle ennuple

- Non ci sono due ennuple con lo stesso valore sull'attibuto **Matricola**
- Non ci sono due ennuple uguali su tutti e tre gli attibuti **Cognome,Nome,Data di Nascita**
![[Pasted image 20221105113142.png|center|600]]

## Chiave

Insieme di attributi che identificano univocamente le ennuple di una relazione
**Formalmente**
- un insieme K di attibuti è **superchiave** per $r$ se $r$ non contiene due ennuple distinte $t_1,t_2$ con $t_1[K]=t_2[K]$
- K è **chiave** per $r$ se è una superchiave minimale per $r$ (ossia, non contiene un'altra superchiave)

**Esempi**
- Matricola è una chiave:
	- è una **superchiave**
	- contiene un solo attributo e quindi è minimale
![[Pasted image 20221105113914.png|center|600]]

## Vincoli,schemi e istanze
- I vincoli corrispondono a proprietà del mondo reale modellato dalla base di dati
- Interessano a livello di schema (con riferimento cioè a tutte le istanze)
- Ad uno schema associamo un insieme di vincoli e consideriamo **corrette** le istanze che soddisfano tutti i vincoli
- Un'istanza può soddisfare altri vincoli ("per caso")

**Esempio**
![[Pasted image 20221105114217.png|center|600]]

- è **corretta**: soddisfa i vincoli
- Ne soddisfa anche altri ("per caso"):
	- Cognome,Corso è chiav
![[Pasted image 20221105114410.png|center|600]]

## Esistenza delle chiavi

Una relazione non può contenere **ennuple distinte** ma **uguali**
Ogni relazione ha come **superchiave** l'insieme degli attributi su cui è definita

>quindi ha (almeno) una chiave

### Importanza delle chiavi

L'esistenza delle chiavi garantisce l'accessibilità a ciascun dato nella base di dati
le chiavi permettono di correlare i dati in relazioni diverse:
- il modello relazionale è basato su valori

# Chiavi e valori nulli

In presenza di **valori nulli**, i valori della chiave non permettono:
- di identificare le ennuple
- di realizzare facilmente i riferimento da altre relazioni
![[Pasted image 20221105114743.png|center|600]]

## Chiave primaria

La **chiave primaria** è una chiave su cui non sono **ammessi nulli**
Viene prescelta fra l'insieme di chiavi secondo dei criteri di efficienza
**Notazione**: sottolineatura

# Vincoli di integrità referenziale

Informazioni in relazioni diverse sono correlate attraverso valori comuni
In particolare, valoro delle chiavi (primarie)
Le correlazioni debbono essere "coerenti"

**Esempio**
![[Pasted image 20221105115112.png|center|600]]
![[Pasted image 20221105115137.png|center|600]]

_Def_
Un vincolo di **integrità referenziale**("**foreign key**") fra gli attributi X di una relazione $R_1$ e un'altra relazione $R_2$ impone ai valori su X in $R_1$ di comparire come valori della chiave primaria di $R_2$

**Esempio**
Vincoli di integrità referenziale fra:
- L'attributo Vigile della relazione **INFRAZIONI** e la relazione **VIGILI**
- L'attributo Prov e Numero della relazione **INFRAZIONI** e la relazione **AUTO**
![[Pasted image 20221105115628.png|center|600]]

### Alcuni commenti

Giocano un ruolo fondamentale nel concetto di "**modello basato su valori**"
In presenza di valori nulli i vincoli possono essere resi meno restrittivi
Sono possibili meccanismi per il supporto alla loro gestione ("azioni" compensative a seguito di violazioni)

![[Pasted image 20221105120036.png|center|600]]

## Azioni compensative
**Esempio**:
- Viene eliminata una ennupla causando così una violazione
**Azioni**
- Rifiuto dell'operazione
- Eliminazione in cascata
- Introduzione di valori nulli

**Eliminazione in cascata**
![[Pasted image 20221105120240.png|center|600]]
**Introduzioni di valori nulli**
![[Pasted image 20221105120320.png|center|600]]






