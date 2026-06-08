# Intro
**Funzioni del livello di rete**
- *Inoltro*: Spostare i pacchetti dall'ingresso del router all'uscita del router appropriata - **PIANO DATI**
- *Instradamento*: Determinare il percorso seguito dai pacchetti dalla sorgente alla destinazione - **PIANO CONTROLLO**

Due approcci alla strutturazione del piano di controllo della rete:
- Controllo per router (tradizionale)
- Controllo logicamente centralizzato (sw-defined networking).

**Piano di controllo per router**
I singoli componenti dell'algoritmo di instradamento *in ogni router* interagiscono nel piano di controllo
![[Ch. 4.2 - Rete p. Controllo-1780932535489.png]]

**Piano di controllo SDN**
Un controllore remoto calcola le tabelle di inoltro e le installa nei router
![[Ch. 4.2 - Rete p. Controllo-1780932602532.png]]

![[Ch. 4.2 - Rete p. Controllo-1780932623556.png]]

# Algoritmi di instradamento
**Obiettivo degli algoritmi di instradamento**: Determinare percorsi o cammini "buoni" tra le sorgenti ed i destinatari attraverso la rete di router.
- *Percorso*: Sequenza di router che i pacchetti attraversano dall'host di origine a quello di destinazione ( presupponendo l'attraversamento di un collegamento tra un nodo ed il successivo )
- *"Buono"*: 'costo' minimo
- Instradamento : Uno dei "primi 10" problemi nelle reti.
![[Ch. 4.2 - Rete p. Controllo-1780932761440.png|435]]

**Astrazione: Grafo**
![[Ch. 4.2 - Rete p. Controllo-1780932799910.png|250]]
$c_{a,b}$: Costo del collegamento *diretto* che connette a e b (Es. $c_{w,z}=5;c_{u,z}=\infty$)
Costo definito dall'operatore di rete: potrebbe essere sempre 1, o proporzionale alla lunghezza fisica di un collegamento (ritardo di propagazione), o inversamente correlato alla larghezza di banda, o proporzionale alla congestione.
Il *costo di un percorso* è uguale alla somma dei costi dei collegamenti attraversati.

**Classificazione degli algoritmi di instradamento**
![[Ch. 4.2 - Rete p. Controllo-1780933006571.png]]

- **Sensibili al carico**: Il costo dei collegamenti riflette il livello corrente di congestione
- **Insensibili al carico**: Il costo dei collegamenti non riflette il livello corrente/recente di congestione
A causa di difficoltà sperimentate nell'uso di algoritmi sensibili al carico, al momento si preferiscono algoritmi insensibili al carico.

## Link state - Dijkstra
- **Centralizzato**: la topologia della rete ed il costo dei collegamenti sono noti a *tutti* i  nodi.
	- Informazioni ottenute attraverso un algoritmo di "link state broadcast"
	- Tutti i nodi hanno le stesse informazioni.
- Calcola i percorsi di costo minimo da un nodo sorgente a tutti gli altri nodi
	- Dà la *tabella di inoltro* per quel nodo
- *Iterativo*: Dopo k iterazioni, conosce il cammino di costo minimo verso k destinazioni.

**Notazione**
- $C_{x,y}$: Costo del collegamento *diretto* dal nodo x al nodo y ($\infty$ se non sono vicini diretti)
- $D(v)$: Stima *corrente* del costo minimo del percorso dalla sorgente alla destinazione v
- $p(v)$: Immediato predecessore di v lungo il percorso da root a v
- $N'$: Sottoinsieme di nodi contenenti tutti e solo i nodi v per cui il percorso a costo minimo dall'origine a v è *definitivamente noto*.
![[Ch. 4.2 - Rete p. Controllo-1780933419431.png]]

### Discussione
**Complessità algoritmica**: n nodi (senza contare l'origine)
- Ciascuna delle n iterazioni deve controllare tutti i nodi w non in N' per determinare quello avente il costo minimo;
- Complessità $O(n^2)$
- Sono possibili implementazioni più efficienti ($O(n\log n)$ usando un heap)
**Complessità dei messaggi**: n nodi
- Ogni router deve *trasmettere in broadcast* le proprie informazioni sullo stato dei collegamenti agli altri n router;
- Algoritmi di broadcast efficienti: $O(n)$ attraversamenti dei collegamenti per diffondere un messaggio di broadcasting da una sorgente;
- Il messaggio di ogni router attraversa $O(n)$ collegamenti: Complessità complessiva $O(n^2)$.

**Oscillazioni**
pdf20sl31