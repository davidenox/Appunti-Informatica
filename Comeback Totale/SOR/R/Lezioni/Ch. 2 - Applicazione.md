# Principi delle applicazioni di rete
## Creare un'applicazione di rete
Scrivere programmi che:
- Girano su sistemi periferici differenti;
- Comunicano attraverso la rete;
Non è necessario scrivere programmi per i dispositivi nel nucleo della rete:
- I dispositivi del nucleo della rete non eseguono applicazioni utente;
- Il confinamento delle applicazioni nei sistemi periferici ha facilitato il rapido sviluppo e la diffusione di una vasta gamma di applicazioni per internet.

**Paradigma client-server**
*Server*:
- Host sempre attivo;
- Indirizzo IP fisso;
- Spesso in datacenter (per scalabilità);
- Onere economico sui fornitori del servizio (per infrastruttura, manutenzione, traffico).
*Client*:
- Contatta, comunica col server;
- Può contattare il server in qualsiasi momento;
- Può avere IP dinamici;
- Non comunica direttamente con gli altri client;

**Architettura peer-to-peer**

- Non c'è un server sempre attivo;
- Coppie arbitrarie di host (peer) comunicano direttamente tra loro;
- I peer richiedono un servizio ad altri peer e forniscono un servizio in cambio di altri peer.
	- *scalabilità intrinseca* - nuovi peer aggiungono capacità di servizio al sistema, sebbene generino anche nuovo carico di lavoro.
- I peer non devono necessariamente essere sempre attivi e cambiano indirizzo IP;

**Processi comunicanti**

**Processo**: Programma in esecuzione su un host.
- All'interno dello stesso host, due processi comunicano usando un approccio interprocesso definito dal SO.
- Processi su host differenti comunicano attraverso lo *scambio di messaggi* usando il servizio del livello di trasporto.
*Processo client*: Dà inizio alla comunicazione, richiedendo il servizio o l'informazione.
*Processo server*: Attende di essere contattato, fornendo il servizio o l'informazione.

**Socket**

Un processo invia/riceve messaggi a/da la sua *socket*. Una socket è analoga ad una porta:
- Il processo mittente fa uscire il messaggio dalla propria socket e presuppone l'esistenza di un'infrastruttura esterna che trasporterà il messaggio, attraverso la rete, alla socket del processo di destinazione.
- ![[Pasted image 20260417123259.png|center|500]]

**Indirizzamento**

Per ricevere messaggi, un processo deve avere un *identificatore*, che coprende sia l'indizzo IP che  i numeri di porta associati al processo in esecuzione su un host. 
Un host ha un indirizzo IP univoco a 32 bit (IPv4) o 128 bit (IPv6).

Un protocollo a livello applicazione definisce:
- *Tipi di messaggi scambiati*;
- *Sintassi dei messaggi*;
- *Semantica dei messaggi*;
- *Regole*;
- *Protocolli di pubblico dominio*;
- *Protocolli proprietari*.

*Quale servizio di trasporto richiede un'applicazione?*
**Perdita di dati**:
- Alcune applicazioni (es. trasferimento file, transazioni web) richiedono un trasferimento 100% affidabile;
- Altre applicazioni (es. multimedia) possono tollerare qualche perdita.
**Sensibilità al fattore tempo**:
- Alcune applicazioni (telefonia via internet, giochi interattivi) richiedono che i ritardi siano bassi per essere "efficaci".
 **Throughput**:
- Alcune applicazioni ('sensibili alla banda') richiedono un'ampiezza di banda minima;
- Altre applicazioni ('elastiche') utilizzano l'ampiezza di banda che si rende disponibile.
**Sicurezza**:
- Riservatezza, integrità dei dati, autenticazione,...

## Servizi dei protocolli di trasporto di internet

>**TCP**
>- *Trasporto affidabile* fra i processi di invio e ricezione: dati consegnati senza errori, perdite e nell'ordine di invio;
>- *Controllo di flusso*: il mittente non vuole sovraccaricare il destinatario;
>- *Controllo della congestione*: 'strozza' il processo di invio quando la rete è sovraccarica;
>- *Orientato alla connessione*: richiesto un setup fra i processi client e server;
>- *NON OFFRE* temporizzazione, garanzie su un'ampiezza di banda minima, sicurezza.

>**UDP**
>- *Trasferimento dati inaffidabile* fra i processi d'invio e ricezione;
>- *NON OFFRE* affidabilità, controllo di flusso, controllo di congestione, temporizzazione, ampiezza di banda minima, sicurezza, né setup della connessione.
>- Offre alle applicazioni maggiore controllo sull'invio dei dati.

![[Pasted image 20260417163322.png|center|500]]

### Rendere sicuro TCP

**Socket TCP e UDP**:
- Nessuna cifratura;
- Password inviate in chiaro, senza cifratura, attraverso socket attraversano internet in chiaro.
**Transport Layer Security** (*TLS*):
- Offre connessioni TCP cifrate;
- Controllo di integrità dei dati;
- Autenticazione end-to-end.
![[Pasted image 20260417163746.png|center|500]]

# Web e HTTP
p6sl19