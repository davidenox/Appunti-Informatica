# Host : Invio dei pacchetti di dati

Funzione di invio dei pacchetti dell'host:

- Prende il messaggio dell'applicazione
- Lo suddivide in frammenti più piccoli, detti **pacchetti**, tutti di lunghezza $L$ bit
- Trasmette il pacchetto nella rete di accesso al **tasso di trasmissione** $R$
	- Tasso di trasmissione del collegamento, o capacità del link, o ampiezza di banda del collegamento

>ritardo di trasmissione del pacchetto = tempo necessario per trasmettere
>pacchetti di L bit nel collegamento = $\frac{L}{R}$
## Mezzi trasmissivi

I mezzi trasmissivi sono quei mezzi che trasmettono fisicamente il messaggio (*pacchetto*) da un mittente ad un destinatario

Tra i mezzi più usati troviamo :
- Cavi coassiali
- Doppino intrecciato
- Fibra ottica multimodale
- Spettro radio-terrestre
- Spettro radio-satellitare

I mezzi fisici vengono suddivisi in due categorie :
- **Mezzi vincolatri** (*guided media*) : Le onde vengono contenute in un mezzo fisico, quale cavo di fibra ottica, filo di rame etc...
- **Mezzi non vincolati** (*unguided media*) : Le onde si propagano nell'atmosfera e nello spazio esterno, come nelle LAN wireless o nei canali satellitari

### Doppino di rame intrecciato (Twisted Pair(TW))

Si compone di due fili di rame isolati, e ne esistono due catgorie :
- Categoria 5 : 100 Mbps, 1 Gbps Ethernet
- Categoria 6 : 10 Gbps Ethernet

Viene comunemente usato per l'acceesso a Internet residenziale
## Cavo Coassiale

Viene usato, nella maggior parte dei casi, nei sistemi televisivi via cavo
Può essere usato come **mezzo condiviso** vincolato.
è composto da :

- Due conduttori di rame concentrici
- è bidirezionale
- è a banda larga
### Fibra ottica

è un mezzo sottile e flessibile che conduce impulsi di luce, ciascuno dei quali rappresenta un bit.
Ha una elevata velocità di trasmissione (fino a decine di centinaia di Gbps).
Tale mezzo è immune alle interferenza elettromagnetica, presenta attenuazione di segnale molto bassa nel raggio di 100 km ed è molto difficile da intercettare.
Viene usato molto nei collegamenti intercontinentali
### Canali radio

I canali radio trasportano segnali all' interno dello spettro elettromagnetico.
Non richiede l'installazione fisica dei cavi, è in grado di attraversare le pareti, fornisce connettività agli utenti mobili e, potenzialmente, riesce a trasportare un segnale per lunghe distanze.

Possono essere classificati in vari gruppi :

- **Wireless LAN** (WiFi)
	- decine/centinaia di Mbps; decine di metri
- **Wide-Area** (es. 4G,5G)
	- Decine di Mbps (4G)
	- 4G Plus fino a 300 Mbps
- **Bluetooth** : sostituzione dei cavi
- etc...