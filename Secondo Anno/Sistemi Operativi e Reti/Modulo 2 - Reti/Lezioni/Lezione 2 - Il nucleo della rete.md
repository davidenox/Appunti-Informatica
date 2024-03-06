# Il nucleo della rete
Il nucleo della rete è una maglia di commutatori di pacchetti e collegamenti che interconnettono i sistemi periferici di Internet.
*Commutazione di pacchetto* (packet-switching): i sistemi periferici suddividono i messaggi di livello applicativo in *pacchetti*. La rete *inoltra* (forwards) i pacchetti da un rputer al successivo attraverso i collegamenti (links) lungo un *percorso* (path o route) dalla sorgente alla destinazione.
## Due funzioni chiave del nucleo della rete
*Inoltro (forwarding)*:
- O *switching*;
- Azione **locale**: sposta i pacchetti in arrivo al collegamento di ingresso del router al collegamento di uscita appropriato.
*Instradamento (routing)*:
- Azione **globale**: determina i percorsi preso dai pacchetti dalla sorgente alla destinazione;
- Algoritmi di instradamemto.
## Commutazione di pacchetto : store-and-forward
*Ritardo(delay) di trasmissione*:
- Servono L/R secondi per trasmettere pacchetti di L bit attraverso un collegamento a R bps.
Es. $L=10kbit$, $R=100Mbps$. 
Ritardo di trasmissione "one-hop" $= 0,1\cdot 10^{-3}s=0,1ms$.

-immagine

Ritardo da un capo all'altro (end-to-end) per la trasmissione di 1 pacchetto su un percorso di N collegamenti di pari velocità R : $d_{end-to-end}=(N+P-1)\frac{L}{R}$  trascurando il ritardo di propagazione.
## Commutazione di pacchetto: accodamento
L'accodamento (*queuing*) si verifica quando il lavoro arriva più velocemente di quanto possa essere servito.
*Accodamento dei pacchetti e perdite*: se il tasso di arrivo (arrival rate) (in bps) al collegamento eccede il tasso di trasmissione del collegamento per un certo periodo di tempo:
- 
- 
## Alternativa alla commutazione di pacchetto: commutazione di circuito
>[!important]- **Le risorse richieste lungo un percorso ( buffer e velocità di trasmissione sui collegamenti) per consentire la comunicazione tra sistemi periferici sono riservate per l'intera durata della sessione dedicata**

Risorse dedicate: nessuna condivisione
- Trasferimento dati a velocità costante e garantita;
I segmenti del circuito restano inattivi se non utilizzati ( nessuna condivisione);
Usato comunemente nella rete telefonica...
### Commutazione di circuito : FDM e TDM
**Multiplexing a Divisione di Frequenza** *(FDM)*:
- Spettro di frequenza di un collegamento suddiviso in bande (band)
- Ogni circuito ha una propria banda. può trasmettere alla velocità massima di quella ristretta.
**Multiplexing a divisione di tempo** *(TDM)*:
- Tempo suddivisio in frame di durata fissa, ripartiti in un numero fisso di slot
- ciascun circuito riceve slot periodici, può trasmettere alla massima velocità della banda di frequenza solo nei propri slot temporali
### Commutazione di pacchetto vs commutazione di circuito
Esempio da vedere
Domanda: quaanti utenti posssono usare qusta rete sotto la commutazione di circuito e sotto la commutazione di pacchetto?
- **Commutazione di circuito**: 10 utenti.
- **Commutazione di pacchetto**: con 35 utenti, probabilità > 10 attivi allo stesso tempo è meno di 0.0004 *
DA FINIRE
## Struttura di internet: Una "rete di reti"
