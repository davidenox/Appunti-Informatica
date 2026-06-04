# Panoramica
## Servizi e protocolli
Il livello di rete trasporta i segmenti dall'host mittente all'host destinatario:
- *Mittente*: Incapsula i segmenti dentro ai datagrammi che passa al livello di collegamento;
- *Destinatario*: Consegna i segmenti al livello di trasporto.
I protocolli di livello di rete sono tutti implementati da *tutti i dispositivi internet* (host, router).
**Router**:
- Esamina i campi dell'intestazione di tutti i datagrammi IP che lo attraversano;
- Sposta i datagrammi dalle porte di ingresso alla porta di uscita per trasferire il datagramma lungo il percorso dall'host di origine a quello di destinazione.
![[Ch. 4.1 - Rete p. dati-1780583330633.png]]

## Due funzioni chiave
- **Inoltro**(*forwading*): Trasferisce i pacchetti da un collegamento di ingresso di un router al collegamento di uscita appropriato del router.
- **Instradamento**(*Routing*): Determina il percorso seguito dai pacchetti dall'origine alla destinazione, tramite appositi *algoritmi di instradamento*.

**Piano dei dati**:
- Funzione locale;
- Determina come i pacchetti in arrivo a una porta d'ingresso del router sono inoltrati verso una porta di uscita;
- ![[Ch. 4.1 - Rete p. dati-1780584102188.png]]
**Piano di controllo**:
- *Logica di rete*;
- Determina come i pacchetti sono instradati tra i router lungo un percorso dall'host di origine all'host di destinazione;
- Due approcci per il piano di controllo
	- *Algoritmi di instradamento tradizionali* implementati nei router;
	- *Software Defined Networking* (SDN) implementati nei server remoti.

**Piano di controllo per router**
I singoli componenti dell'algoritmo di routing in ogni singolo router;![[Ch. 4.1 - Rete p. dati-1780584254435.png]]

**Software-Defined Networking** SDN
Un controllore remoto calcola ed installa le tabelle di inoltro nei router![[Ch. 4.1 - Rete p. dati-1780584329244.png]]

## Modello di servizio del livello di rete
Domanda: Qual è il *modello di servizio* per il 'canale' che trasporta i datagrammi dal mittente al destinatario?
*Esempi di servizi per un singolo datagramma*:
- Consegna garantita;
- Consegna garantita con un ritardo inferiore a 40ms
*Esempi di servizi per un flusso di datagrammi*:
- Consegna in ordine;
- Minima ampiezza di banda;
- Restrizioni sulle modifiche della spaziatura tra i pacchetti.
![[Ch. 4.1 - Rete p. dati-1780584462587.png]]

**Modello di servizio "best effort" di internet**
*Nessuna* garanzia circa:
1. Consegna del datagramma alla destinazione con successo;
2. Tempi o ordine di consegna;
3. Larghezza di banda disponibile per il flusso da un capo all'altro.

La *semplicità del meccanismo* ha consentito l'ampia diffusione di internet. Una *dotazione sufficiente di larghezza di banda* e *protocolli in grado di adattarsi alla banda disponibile* consentono alle prestazioni delle applicazioni in tempo reale di essere "sufficientemente buone" e "per la maggior parte del tempo". *Servizi replicati e distribuiti a livello applicativo* che si collegano alle reti dei clienti consentono di fornire servizi da più luoghi, ed il controllo della congestione dei servizi "elastici" aiuta. In sintesi, *il successo del modello di servizio best-effort è difficilmente contestabile*.

# Router
## Architettura
Visione ad alto livello di una generica architettura di un router:
![[Ch. 4.1 - Rete p. dati-1780584830921.png]]

Analogia:
![[Ch. 4.1 - Rete p. dati-1780584863698.png]]

**Funzioni delle porte di ingresso**
![[Ch. 4.1 - Rete p. dati-1780584914813.png]]
![[Ch. 4.1 - Rete p. dati-1780584929737.png]]

**Destinazione basata sull'indirizzo di destinazione**:
![[Ch. 4.1 - Rete p. dati-1780584985669.png]]

**Corrispondenza a prefisso più lungo**
- Quando si cerca una voce della tabella di inoltro per un dato indirizzo di destinazione, si utilizza il prefisso di indirizzo *più lungo* che corrisponde all'indirizzo di destinazione:
![[Ch. 4.1 - Rete p. dati-1780585074135.png]]
![[Ch. 4.1 - Rete p. dati-1780585085804.png]]
![[Ch. 4.1 - Rete p. dati-1780585097816.png]]
![[Ch. 4.1 - Rete p. dati-1780585109020.png]]

Spesso la corrispondenza a prefisso più lungo viene eseguita con le *ternary content addressable memories* TCAMs:
- **Content Addressable**: Un indirizzo IP a 32 bit è passato alla memoria che restituisce il contenuto della tupla nella tabella di inoltro corrispondente a quell'indirizzo in un tempo essenzialmente costante.![[Ch. 4.1 - Rete p. dati-1780586151972.png]]

### Struttura di commutazione
	Switching fabric
- Trasferisce i pacchetti dal collegamento di ingresso al collegamento di uscita appropriato;
- *Tasso di trasferimento*: tasso al quale i pacchetti vengono trasferiti dalla porta di input a quella di output:
	- Spesso misurato come multiplo del tasso di trasmissione delle linee di input/output
	- N input: si desidera avere un tasso di trasferimento della struttura di commutazione N volte il tasso delle linee di input/output.![[Ch. 4.1 - Rete p. dati-1780586281718.png]]
![[Ch. 4.1 - Rete p. dati-1780586298794.png]]

pdf18sl28