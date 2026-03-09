# Tipi di SO

1. **SO per Mainframe**: pc di grandi dimensioni usati in grandi aziende o istituzioni.
	- Funzioni principali:
		- *Batch Processing*: Esecuzione di job senza interazione dell'utente;
		- *Elaborazione di transazioni*: Gestione di numerose richieste simultanee;
		- *Timesharing*: Molti utenti eseguono lavori contemporaneamente.
	- Es: Z/OS, usato per applicazioni mission-critical (banche, e-commerce). 
2. **SO per Server**: Utilizzati sui server che servono più utenti attraverso la rete.
	- Servizi forniti:
		- *File Sharing*;
		- *Database*;
		- *Stampa*;
		- *Web hosting*
	- Vengono usati da provider di servizi internet ed aziende per supportare infrastrutture critiche.
	- Es: Linux, FreeBSD, Windows Server, Solaris.
3. **SO per PC**: Supportano un singolo utente con multiprogrammazione e, spesso, architetture multiprocessore. Utilizzati per compiti quotidiani.
	- Es: Windows, macOS, Linux, FreeBSD.
	- Caratteristiche: Facilità d'uso, interfaccia grafica, supporto per applicazioni di produttività
4. **SO per Smartphone e Tablet**: usati su *dispositivi mobili*.
	- Mercato dominato da *Android* (Google) e *iOS* (Apple);
	- Supportano *CPU multicore, GPS, fotocamere, app di terze parti*.
5. **SO per IoT ed Embedded**: usati in *dispositivi connessi* (frigoriferi, lavatrici, telecamere).
	- Tipicamente leggeri, con funzioni specifiche e limitate;
	- Es: Embedded Linux, QNX, TinyOS.
	- Caratteristiche: footprint ridotto.
6. **SO Real-Time**: Progettati per rispettare *scadenze rigide* nei processi industriali e militari.
	- *Hard Real Time*: Risposte immediate e precise (es. robotica industriale);
	- *Soft Real-Time*: Occasionali ritardi tollerabili (es. Streaming multimediale);
	- Es: eCos, VxWorks.
7. **SO per Smart Card**: Utilizzati in Smart Card per pagamenti, autenticazioni ed altro. Alimentate tramite contatti o induzione, con capacità limitate.
	- *Java-oriented*: alcune eseguono applet Java per multiprogrammazione;
	- Es: Sistemi proprietari, JavaCard.

Il SO offre funzionalità attraverso le *chiamate di sistema*. Gruppi di chiamate di sistema implementano *servizi*, come *File System Service* o *Process Management Service*.
I processi sono astrazioni a livello utente per eseguire un programma per suo conto. Ogni processo ha il suo *spazio di indirizzamento*, i dati coinvolti nell'operazione vengono recuperati e memorizzati in file, che persistono rispetto ai processi.

# Processo
****
