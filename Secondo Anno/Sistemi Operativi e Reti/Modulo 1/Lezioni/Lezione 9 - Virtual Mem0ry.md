# Virtual memory
## Gestione della memoria : Outline
- Memory Abstractation;
- *Virtual Memory*;
- Algoritmi di sostituzione delle pagine;
- Problemi di progettazione per sistemi di paging.
## Il problema del bloatware e la crescita della memoria
Necessità di *gestire programmi che superano la capacità della memoria* disponibile.
Negli anni '60, introduzione di *tecniche per dividere programmi in parti gestibili*.
- *Overlay*: Sono piccole parti o segmenti di un programma.
- *Solo l'overlay necessario viene caricato in memoria*.
- Overlay successivi sovrascrivono o coesistono con quelli precedenti.
- Gli overlay vengono scambiati tra memoria e disco.
Originariamente, i programmatori dovevano suddividere manualmente i programmi in overlay ( soluzione tediosa e soggetta ad errori ).
## Memoria virtuale
La *memoria virtuale estende l'idea dei registri base e limite*.
- Ogni programma ha un proprio spazio degli indirizzi suddiviso in *pagine*, che sono intervalli di indirizzi contigui.
- Non tutte le pagine devono essere contemporaneamente nella memoria fisica:
	- L'hardware crea una mappa di quelle direttamente in memoria;
	- Se una pagina manca, il SO interviene.
- La maggior parte dei sistemi moderni usa il **Paging** ( paginazione ) :
	- Divisione dello spazio degli indirizzi in unità di dimensione fissa, es. 4Kb.
- *Alternativa*: **Segmentazione** con unità di dimensione variabile ( ora meno comune ).

*Problema*: 
- Finora la memoria può essere assegnata ai processi solo in blocchi contigui.
**Soluzione** ( *e vantaggio dell'uso della Memoria Virtuale* ):
- Creare per il processo l'illusione di uno spazio di indirizzi ampio ( ad esempio indicizzabile con 48 bit).
- Questo spazio è noto come spazio di indirizzi virtuale.
- La *RAM* (molto più limitata ) è nota come *memoria fisica*.
- **Memory Management Unit** ( MMU ): Traduce gli indirizzi virtuali ( come usati dal processo ) in indirizzi fisici.
![[Pasted image 20231122104849.png|center|400]]
### Memoria Virtuale e Paginazione
I sistemi moderni utilizzano la *Paginazione* ( o **Paging** ):
- Dividendo la memoria fisica e virtuale in pagine di dimensioni fisse;
- Traducendo le pagine virtuali in *pagine fisiche* ( *frame* ).
![[Pasted image 20231122105024.png|center|200]]
#### Spazio di indirizzamento virtuale vs Spazio degli indirizzi fisici, e page table
*Mappatura Memoria*:
- 16 pagine virtuali possono essere mappate in 8 frame fisici usando la MMU.
- Tuttavia, non tutte le pagine virtuali sono mappate fisicamente.
	- Quelle NON mappate sono contrassegnate con una X.
Se un programma fa riferimento a una pagina non mappata, si verifica un *Page fault*. Il SO allora:
- Sposta un frame raramente usato su disco, se serve;
- Carica la pagina richiesta nel frame libero o liberato;
- Aggiorna la mappa della MMU per riflettere i cambiamenti.
![[Pasted image 20231122112823.png|center|300]]
La *relazione* tra gli indirizzi di memoria virtuale e fisica è data dalla **Page Table**.
*Esempio*: Gestire istruzione:
- `MOV REG,32780`
Fa riferimento alla pagina virtuale 8.
- Indirizzo `12` della pagina:
- `32780-2^15 (32769) = 12`
Se non è mappata, il SO potrebbe decidere di sostituire il frame 1:
- Spostando il precedente su disco;
- Popolando il nuovo frame e puntando poi a:
	- `4108 = 4096 + 12`
Il page fault avviene nello spazio kernel durante il **trap** eseguito dal SO.
![[Pasted image 20231122113548.png|center|300]]

### Funzionamento interno della MMU
**Indirizzo virtuale**: 8196
	*Rappresentazione Binaria*: `0010 000000000100`
**Suddivisione dell'Indirizzo virtuale**:
- *Numero di pagina*: 4 bit ( permette di gestire 16 pagine ).
- *Offset*: 12 bit ( indirizza 4096 byte per pagina che compongono ogni frame ).
**Mappature tramite la Tabella delle Pagine**:
- Numero di pagina $\rightarrow$
	- Indice nella tabella delle pagine $\rightarrow$
		- Numero di frame.
![[Pasted image 20231122114045.png|center|400]]
#### Evoluzione degli indirizzi e tabella delle pagine
![[Pasted image 20231122114135.png|center|400]]
*Indirizzi nei nostri esempi*: 16 bit ( per chiarezza nelle illustrazioni ).
*Moderni PC*:
- Usano indirizzi a 32 o 64 bit.
- Con 32 bit e pagine da 4Kb:
	- 12 bit per indirizzare 4096 byte per pagina;
	- Tabella delle pagine di $2^{(32-12)}=2^{20}=1.048.576$ voci. Una taglia di 4Gb è "fattibile" anche per PC con pochi Gb di RAM.
*Indirizzi a 64 bit e pagine da 4Kb*:
- Richiede $2^{64}$ voci ($\sim 4,5\times 10^{15}$) nella tabella.
- In realtà nei sistemi a 64 bit si usano 48 bit.
	- 256 Tb bastano e avanzano, gli altri bit sono riservati per il futuro.
#### Come è composta una voce della Page Table?
Ogni voce ha informazioni cruciali come il numero del frame, come:
- *Bit Presente/Assente*: indica *se* la pagina virtuale *è in memoria*.
- *Bit Protezione*: Specifica i *tipi di accesso consentiti* (lettura, scrittura, esecuzione).
- *Bit Supervisor*: Stabilisce *se la pagina è accessibile* solo al SO o anche ai programmi utente.
- *Bit Modificato (M) e Riferimento (R)*: Registrano l'uso della pagina :
	- Il bit M si attiva quando la pagina viene scritta;
	- Il bit R viene impostato ogni volta che si accede alla pagina,
![[Pasted image 20231122120621.png|center|500]]
*Nota*: Per un processo l'indirizzo in memoria della "sua" tabella delle pagine è scritto nel registro Page Table Base Register ($\texttt{PTBR}$).
### Velocizzare la paginazione - Problemi chiave
*Mappatura Veloce*: Necessaria a ogni riferimento alla memoria. Ogni istruzione può richiedere più riferimenti alla tabella delle pagine.
- *Sfida*: Se un'istruzione impiega 1 ns, la ricerca nella tabella delle pagine deve essere inferiore a 0,2 ns per evitare colli di bottiglia.