Indice:
- [[Lezione 2 - Il linguaggio Java#Il linguaggio Java |Il linguaggio java]]
- [[Lezione 2 - Il linguaggio Java#La piattaforma Java|La piattaforma Java]]
- [[Lezione 2 - Il linguaggio Java#Cosa posso fare con la tecnologia Java|Cosa posso fare con la tecnologia Java?]]


# Il linguaggio Java

_Def:_
Java è un linguaggio ad alto livello che è caratterizzato dalle seguenti caratteristiche:
- Semplice
- Object Oriented
- Distribuito
- Multithread
- Dinamico
- Architettura Neutrale(Virtualizzata)
- Portatile
- Alte performance
- Robusto
- Sicuro (perchè sta su VM!)

Java è un linguaggio complesso
Nel linguaggio java tutto il codice sorgente viene scritto in file di testo con estensione .java
Questi file sorgente vengono poi compilati in file .class dal compiler java chiamat <b>JAVAC</b>
Un file .class <u>non</u> contiene codice nativo del processore; al contrario contiene <b>Bytecodes</b> (Il linguaggio macchina della Java Virtual Machine)

![[getStarted-compiler.gif]]

Dato che la Java VM è disponibile su vari Sistemi Operativi, lo stesso file .class può essere lanciato su windows, linux, solaris so,macos
# La piattaforma Java

Una <u>piattaforma</u> è l'ambiente hardware o software in cui un programma viene eseguito.
Molte piattaforme possono essere descritte come una combinazione di sistema operativo e hardware prioritario.
La piattaforma Java differisce dalle altre piattaforme in quanto è una piattaforma solo software che funziona su piattaforme basate su hardware.
La piattaforma Java ha 2 componenti:
- La Java VIrtual Machine
- La Java Application Programming Interface (API)

_Def:_
L'API è una vasta collezione di componenti software già pronti che forniscono molte funzionalità.
è raggruppato in librerie di classi e interfacce correlate. Queste librerie sono conosciute come pacchetti(package)


![[helloWorld.gif]]

# Cosa posso fare con la tecnologia Java?

Ogni implementazione della piattaforma Java ti da le seguenti features:
- <u>Development Tools</u>: Gli strumenti di sviluppo ti danno tutto quello di cui hai bisogno per compilare,runnare,debuggare e documentare la tua applicazione
- <u>Application Programming Interface</u>: L'API fornisce il nucleo delle funzionalità del linguaggio Java: Offre un enorme array di classi molot utili già pronte per essere utilizzate nella tua applicazione. Comprende tutto partendo dagli oggetti di base, fino ad arrivare al networking, e sicurezza,fino alla generazione di XML e accessi al database, ecc.... Il nucleo API è molto grande
- <u>Deployment Technologies</u>: Il software JDK fornisce dei meccanismi standard come il software Java Web Star e il software Java Plug-In per distribuire la tua applicazione agli utenti finali
- <u>User Interface Toolkits</u>: I toolkit JavaFX,Swing e Java2D rendono possibile la creazione di sofisticate interfacce utente - Graphical User Interfaces (GUIs)
- <u>Integration Libraries</u>: Le librerie di integrazione come la Java IDL API, JDBC API, Java Naming and Directory Interface (JNDI) API, Java RMI e Java Remote Method Invocation over Inter-ORB Protocol Technology (Java RMI-IIOP Technology) abilitano l'accesso al database e la manipulazione di oggetti remoti

Per il tutorial al primo programma in Java si rimanda a questo link: [HelloWorldApp](https://docs.oracle.com/javase/tutorial/getStarted/cupojava/index.html)

