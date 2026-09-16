Categorie di **dispositivi I/O**:
- *Dispositivi a blocchi*: Archiviazione di informazioni in blocchi di dimensioni fisse, come dischi magnetici o SSD. Ogni blocco può essere letto/scritto indipendentemente.
- *Dispositivi a caratteri*: Flusso di caratteri senza struttura a blocchi, non indirizzabili e senza opzioni di ricerca, come stampanti o interfacce di rete.
- *Altre categorie*: Modelli utili per astrarre alcuni SW di I/O nel SO.
Il FS gestisce i dispositivi a blocchi astratti mentre i SW di livello inferiore gestiscono le specificità dei dispositivi.
I dispositivi I/O sono composti da una **parte meccanica** (il dispositivo stesso) ed una parte **elettronica** (*controller*, che viene spesso integrato nella scheda madre o come scheda aggiuntiva su slot PCIe, e che può spesso gestire più dispositivi identici). Il compito del contriller è quello di *convertire il flusso seriale in blocchi di byte, correggere errori, trasferire in memoria principale*.
Senza il controller il programmatore dovrebbe gestire dettagli complessi. Il controller è inizializzato con parametri essenziali, che gli permettono di gestire autonomamente questi dettagli.

**Porte**:
- *Porta parallela*: Comunemente dotata di una connessione a 25 o 36 pin, trasmette dati multi-bit simultaneamente su più pin. Deprecata
- *Porta USB*: Universal Serial Bus, interfaccia standardizzata per connessione e comunicazione tra dispositivi e computer, utilizzata per trasferire dati e fornire alimentazione elettrica. 
	- Supporta connessioni ad alte velocità di trasferimento e viene utilizzato anche per periferiche come tastiere, mouse e dispositivi di archiviazione. Grande facilità d'utilizzo con connessione plug-and-play, retrocompatibile con versioni precedenti, assicura ampio supporto per vari dispositivi
# Comunicazione CPU-Dispositivo
**Registri dei Controller**:
- Ogni controller di dispositivo ha registri per comunicare con la CPU
- La *scrittura nei registri* avviene tramite comandi inviati ai dispositivi, mentre la *lettura nei registri* avviene tramite verifica dello stato del dispositivo e della prontezza per i nuovi comandi.
**Buffer di dati**:
- Molti dispositivi includono un buffer di dati per scrittura/lettura del SO.
Il SO è cruciale per gestire efficientemente trasferimento dati e controllo dei dispositivi, incidendo sulla progettazione e sulle prestazioni del sistema.
## Port-Mapped I/O
**Assegnazione delle porte I/O**:
- Ogni registro di controllo ha un numero di porta di I/O associato
- Formano lo spazio delle porte di I/O, accessibile solo dal SO per motivi di protezione
**Istruzioni**:
- *Lettura*: `IN REG, PORT` - La CPU legge dal registro di controlllo `PORT` e salva il risultato in `REG`
- *Scrittura*: `OUT PORT, REG` - La CPU scrive il contenuto di `REG` in un registro di controllo
**Separazione**: Spazi di indirizzi della memoria e dell'I/O sono distinti e non correlati
## Memory-Mapped I/O
**Approccio**: 
- Assegna ad ogni registro di controllo un indirizzo di memoria univoco, quindi i registri di controllo sono mappati nello spazio di memoria.
**Vantaggi**: 
- *Elimina la necessità di istruzioni speciali di I/O* come `IN` o `OUT`.
- I *registri* di controllo possono essere trattati *come variabili in C*, consentendo la scrittura del driver completamente in C
- *Protezione semplificata*: I processi utente non accedono direttamente ai registri di controllo
- *Controllo selettivo dei dispositivi*: Attraverso la gestione delle pagine di memoria, si può dare controllo selettivo su dispositivi specifici,
	- Consente *l'esecuzione di driver di dispositivi in spazi di indirizzo separati*, aumentando la sicurezza e riducendo le dimensioni del kernel
**Attenzione con la cache**:
- *Rischio di caching dei registri di controllo*: Un registro finisce in cache, la CPU controlla solo la cache e non controlla se è stato modificato dal dispositivo
- Caso limite: Se un ciclo while è in attesa che il contenuto del registro cambi: **Ciclo infinito**
- Necessità di disabilitare selettivamente la cache per alcuni indirizzi
	- Bisogna identificare con precisione quali pagine sono dedicate ai dispositivi HW
	- Gli accessi a queste aree non saranno ottimizzati dalla cache, quindi possono essere più lenti
pdf13sl23