# Dalle architetture ai sistemi operativi
## Che cos'è un sistema operativo
Un *moderno calcolatore* è tipicamente formato da:
- Uno o più processori;
- Memoria centrale;
- Dischi;
- Stampanti e altre periferiche di I/O.
I dettagli di basso livello sono *molto complessi*. Gestire tutte queste componenti richiede uno strato intermedio software: il **Sistema Operativo**.

## Componenti di un computer moderno (1)
1. 1 o più processori;
2. 

## Componenti di un computer moderno (2)
Doppia modalità supportate dall'hardware:
- Modalità **Kernel** ( o *supervisor*);
- Modalità **Utente**.
-*img*

# The operating system as an extended Machine
- Idea di *astrazione* :
	- - Il sistema operativo si pone tra l'Hardware e le applicazioni; 
- Visione *top-down* :
	- - Il SO fornisce astrazioni ai programmi applicativi
- Vista *bottom-up* :
	- -Il SO gestisce parti di un sistema complesso
	- - E fornisce un'allocazione ordinata e controllata delle risorse
## Il sistema operativo come gestore di risorse
Da un moderno sistema operativo ci aspettiamo che *gestisca* :
1. *Più programmi in esecuzione*;
2. *Più utenti*.
Necessita un'allocazione ordinata e controllata di risorse, quali processore, memoria, unità di I/O ...
Non solo hardware: File, database, ...
*Multiplexing* :
- Nel *tempo* : CPU, stampante..
- Nello *spazio* : memoria centrale, disco, ...
### Storia dei sistemi operativi
Libro

## Uno sguardo all'Hardware
![[Pasted image 20231006164824.png|center]]

### Il processore
La CPU è il cervello del computer, esegue istruzioni della memoria.
- Il ciclo base della CPU: **preleva**(*fetch*), **decodifica**(*code*), **esegue**(*execute*) istruzioni.
- I programmi vengono eseguiti in questo ciclo.
![[Pasted image 20231006165017.png|center|700]]

Le CPU eseguono un set specifico di istruzioni.
- Registri interni memorizzano dati importanti e risultati.
- I set di istruzioni includono funzione per il caricamento/salvataggio dati dalla memoria.
Registri speciali come il *program counter* indicano l'istruzione successiva.
Lo *stack pointer* punta alla cima dello stack in memoria.
- Lo stack contiene frame di procedure con parametri e variabili locali.
Il *registro Program Status Word* (PSW) contiene informazioni sullo stato del programma.
- Il PSW è fondamentale per chiamate di sistema e I/O.
Il sistema operativo gestisce il *multiplexing* temporale della CPU.
- Durante il *multiplexing*, il sistema operativo salva e ripristina i registri.
- Ciò permette al sistema operativo di eseguire programmi in modo efficiente.
Programmazioni avanzate: **Pipeline** (non del tutto)