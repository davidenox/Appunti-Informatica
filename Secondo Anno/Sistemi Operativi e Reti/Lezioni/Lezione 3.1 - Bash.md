# La shell bash
## Cos'è Linux
**Linux** è un clone Unix* nato nel 1991 e scritto da zero da Linus Torvalds con l'aiuto di un gruppo sconnesso di hacker in tutta la rete.
Il 64% dei server del mondo esegono alcune varianti di Unix o Linux ( i telefoni android e gli amazon kindle, ad esempio, eseguono Linux).

>[!note]- *"Small programs that do one thing well"*

Dall'Ambiente di Programmazione Unix (UPE), Kernighan e Pike:
- ...nel cuore c'è l'idea che il potere di un sistema viene più dalla *relazione* tra programmi piuttosto che dai programmi stessi. Molti programmi UNIX fanno cose abbastanza banali da soli, ma, combinati con altri programmi, diventano strumenti generali ed utili.
### Cos'è Linux: Utilità di elaborazione del test selezionate
| Comando | Utilizzo / Mansione                                 |
| ------- | --------------------------------------------------- |
| - awk   | Linguaggio di scamsione ed elaborazione dei modelli |
| - cat   | Mostra file                                         |
| - cut   | Estrae i campi selezionati di ogni linea di un file |
| - diff  | Confronta due file                                  |
| - grep  | Cerca testo per un modello                          |
| - head  | Mostra la prima parte di un file                    |
| - less  | Mostra i file con una base page-by-page             |
| - od    | Scarica i file in vari formati                      |
| - sed   | Editor di flussi ( ad esempio cerca e rimpiazza)    |
| - sort  | Ordina il testo dei file                            |
| - split | Divide i file                                       |
| - tail  | Mostra la parte finale di un file                   |
| - tr    | Traduce / elimina caratteri                         |
| - uniq  | Filtra linee ripetute in un file                    |
| - wc    | Conteggio di linee, parole e caratteri              |
| - tar   | Archivio file ( simile a zip )                      |
## La shell
Una *shell* è un *programma per computer che interpreta i comandi che digiti e li invia al sistema operativo*.
- Nei sistemi Linux ( e altri ), fornisce anche un set di comandi integrati e programmazione di strutture di controllo, variabili d'ambiente, ecc.
La maggior parte dei sistemi Linux, supporta almeno due shell: TCSH e BASH. ( "BASH" = Bourne-again Shell)
### Le variabili d'ambiente di bash
Le variabili sono denominate come locazioni di archiviazione. Le così dette "Variabili di ambiente" (*Environment variables*) sono utilizzate convenzionalmente dalla shell per archiviare informazioni come dove si dovrebbero cercare i comandi (PATH) . Le *Environment Variables* sono condivise ai programmi che la shell esegue.
Per vedere il valore corrente di PATH, fare :
```Bash
echo $PATH
```
Per vedere tutte le environment variables correntemente definite, fare :
```Bash
printenv
```
### Le variabili Bash
Per creare una nuova variabile, usa l'operatore di assegnazione "$=$":
```Bash
foo="questo è il valore di foo"
foo = 5
```
La variabile foo sarà ora mostrata se eseguirai il comando 'set'.
- Per far sì che foo sia visibile dai programmi eseguiti dalla shell ( farlo diventare una variabile d'ambiente ), usa 'export' :
```Bash
export foo
```
Le variabili sono usate ambiamenre negli script di Shell.
## Utilizzare la shell
Dopo esserti connesso, esegui :
```Bash
shazam              # bad command 
whoami              # my login
hostname            # name of this computer
echo "Hello, world" # print charachter to screen
echo $HOME          # print environment variable
date                # print current time/date
cal                 # print this month's calendar
```
I comandi hanno tre parti: *comando*, *opzione* e *parametri*. Esempio: 
```Bash
cal -j 3 1999
```
"cal" è il comando, "-j" è una opzione, "3" e "1999" sono i parametri
Le opzioni hanno forme lunghe e corte. Ad esempio : 
```Bash
date -u
date --universal
```
Qual è la natura della richiesta ( Prompt) ? Qual era la risposta del sistema al comando?
### Cronologia dei comandi e semplici modifiche della riga di comando
- - Prova il comando 'history' ;
- - Scegli tra la cronologia dei comandi utilizzando le frecce $\uparrow$ su e $\downarrow$ giù ;
- - Per rieseguire il tuo ultimo comando, prova !! ;
- - Per andare ancora più a fondo nella tua cronologia, prova !{numero} ;
### Aiuto con i comandi
Digita:
```Bash
date --help
man date
```
>[!important] Man
>Il comando 'man' risponde generalmente mandando in output un manuale

# Reindirizzamento I/O
# Navigazione nel file system
# Processi e controllo del lavoro
# Editors
# Hello World in C