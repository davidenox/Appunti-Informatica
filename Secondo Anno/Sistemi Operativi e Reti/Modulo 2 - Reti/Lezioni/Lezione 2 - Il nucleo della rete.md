# Il nucleo della rete
Il nucleo della rete è una maglia di commutatori di pacchetti e collegamenti che interconnettono i sistemi periferici di Internet.
*Commutazione di pacchetto* (packet-switching): i sistemi periferici suddividono i messaggi di livello applicativo in *pacchetti*. La rete *inoltra* (forwards) i pacchetti da un router al successivo attraverso i collegamenti (links) lungo un *percorso* (path o route) dalla sorgente alla destinazione.
## Due funzioni chiave del nucleo della rete
*Inoltro (forwarding)*:
- O *switching*;
- Azione **locale**: sposta i pacchetti in arrivo al collegamento di ingresso del router al collegamento di uscita appropriato.
*Instradamento (routing)*:
- Azione **globale**: determina i percorsi preso dai pacchetti dalla sorgente alla destinazione;
- Algoritmi di instradamemto.
![[Pasted image 20240313095806.png|center|400]]

## Commutazione di pacchetto : store-and-forward
*Ritardo(delay) di trasmissione*:
- Servono L/R secondi per trasmettere pacchetti di L bit attraverso un collegamento a R bps.
Es. $L=10kbit$, $R=100Mbps$. 
Ritardo di trasmissione "one-hop" $= 0,1\cdot 10^{-3}s=0,1ms$.
![[Pasted image 20240313095952.png|center|500]]
Ritardo da un capo all'altro (end-to-end) per la trasmissione di 1 pacchetto su un percorso di N collegamenti di pari velocità R : $d_{end-to-end}=(N+P-1)\frac{L}{R}$  trascurando il ritardo di propagazione.
## Commutazione di pacchetto: accodamento
L'accodamento (*queuing*) si verifica quando il lavoro arriva più velocemente di quanto possa essere servito.
*Accodamento dei pacchetti e perdite*: se il tasso di arrivo (arrival rate) (in bps) al collegamento eccede il tasso di trasmissione del collegamento per un certo periodo di tempo:
- I pacchetti si accodano in attesa di essere trasmessi sul collegamento in uscita;
- I pacchetti possono essere scartati ( persi ) se la memoria ( buffer ) si riempie.
## Alternativa alla commutazione di pacchetto: commutazione di circuito
>[!important]- **Le risorse richieste lungo un percorso ( buffer e velocità di trasmissione sui collegamenti) per consentire la comunicazione tra sistemi periferici sono riservate per l'intera durata della sessione dedicata**

Risorse dedicate: nessuna condivisione
- Trasferimento dati a velocità costante e garantita;
I segmenti del circuito restano inattivi se non utilizzati ( nessuna condivisione);
Usato comunemente nella rete telefonica tradizionale.
### Commutazione di circuito : FDM e TDM
**Multiplexing a Divisione di Frequenza** *(FDM)*:
- Spettro di frequenza di un collegamento suddiviso in bande (band)
- Ogni circuito ha una propria banda. può trasmettere alla velocità massima di quella ristretta.
![[Pasted image 20240313100244.png|center|400]]
**Multiplexing a divisione di tempo** *(TDM)*:
- Tempo suddivisio in frame di durata fissa, ripartiti in un numero fisso di slot
- ciascun circuito riceve slot periodici, può trasmettere alla massima velocità della banda di frequenza solo nei propri slot temporali
![[Pasted image 20240313100302.png|center|400]]
### Commutazione di pacchetto vs commutazione di circuito
![[Pasted image 20240313100345.png|center|600]]
Domanda: quaanti utenti posssono usare qusta rete sotto la commutazione di circuito e sotto la commutazione di pacchetto?
- **Commutazione di circuito**: 10 utenti.
- **Commutazione di pacchetto**: con 35 utenti, probabilità > 10 attivi allo stesso tempo è meno di 0.0004 *
La commutazione di pacchetto è una vincitrice assoluta?
- Ottimo per i "dati a raffica" 
	- Più semplice, non necesssita l'impostazione della chiamata né di mantenere le informazioni sui circuiti su tutti i router
- *Eccessiva congestione*: ritardo e perdita di pacchetti in caso di buffer overflow.
	- Sono necessari protocolli per il trasferimento affidabile dei dati e per il controllo della congestione.
- *Ritardi end-to-end variabili e imprevedibili*: a causa della variabilità e imprevedibilità dei ritardi di accodamento.
## Struttura di internet: Una "rete di reti"
I sistemi periferici accedono a Internet tramite gli Internet Service Provider (ISP) di **accesso**. Gli ISP di accesso devono essere interconnessi a loro volta, in modo che due host qualsiasi possano inviare pacchetti l'uno all'altro.
La rete di reti risultante è molto complessa.
![[Pasted image 20240313103115.png|center|500]]
## Perdite, ritardi e throughput
### Come si verificano ritardi e perdite?
I pacchetti **si accodano** nei buffer del router, aspettando il proprio turno per la trasmissione. La lunghezza della coda cresce quando il tasso di arrivo dei pacchetti sul collegamento eccede temporaneamente la capacità del collegamento di evaderli.
La **perdita** di pacchetti si verifica quando la memoria che contiene la coda dei pacchetti si riempie.![[Pasted image 20240313103829.png|center|500]]
### Commutazione di pacchetto: ritardo end-to-end
I ritardi totali di nodo in cui è incorso un pacchetto lungo il suo percorso dalla sorgente alla destinazione si accumulano, determinando un ritardo end-to-end pari a: $d_{\text{end-to-end}}=\sum_{i}{}(d_{elab_i}+d_{acc_i}+d_{trasm_i}+d_{prop_i})$ 
### Ritardo di accodamento dei pacchetti
![[Pasted image 20240313111019.png|center|500]]
### Ritardi e percorsi in Internet
Cosa significano effettivamente ritardi e perdite nella vera internet?
**Traceroute**: Programma diagnostico che fornisce una misura del ritardo dalla sorgente al router lungo i percorsi Internet punto-punto verso la destinazione.
`for all i`:
- Invia tre pacchetti che raggiungeranno il router `i` sul percorso verso la destinazione
- Il router `i` restituirà i pacchetti al mittente
- Il mittente calcola l'intervallo tra trasmissione e risposta.
![[Pasted image 20240313111552.png|center|600]]
### Perdita di pacchetti
La coda ( buffer ) che percede un collegamento ha capacità finita. Quando il pacchetto trova la coda piena, viene scartato ( perso ). Il pacchetto perso può essere ritrasmesso dal nodo precedente, dal sistema terminale che lo ha generato, o non essere ritrasmesso affatto.![[Pasted image 20240313111802.png|center|600]]
## Throughput
>[!important]- ***Throughput***: Frequenza (bit/unità di tempo) alla quale i bit sono trasferiti tra mittente e ricevente.
>- Istantaneo : In un determinato instante
>- Medio: In un percorso di tempo più lungo

![[Pasted image 20240313112107.png|center|600]]
![[Pasted image 20240313112135.png|center|600]]
