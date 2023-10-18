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
Molti comandi Linux vengono stampati sullo "standard output", che per impostazione predefinita viene visualizzato sullo schermo del terminale. Il carattere '|'( *pipe* ) può essere usato per deviare o reindirizzare l'output ad un altro programma o filtro.
```Bash

w                                       #Mostra chi è loggato
w | less                                #Si reindirizza alla pagina "minore"
w | grep 'mario'                        # Si reindirizza a grep, che quindi stamperà solo le linee contenenti 'mario'
w | grep -v 'mario'                     #Stampa le sole linee che non contengono 'tuta'
w | grep 'mario' | sed s/tuta/scholar/g # Rimpiazza tutti 'mario' con 'scholar'
```
# Navigazione nel file system
- La struttura assomiglia ad un albero rovesciato. Le Directories ( cartelle ) sono collezioni di file e di altre cartelle. 
- Ogni cartella ha una radice, ad eccezione della cartella root. Molte cartelle hanno sottocartelle.
- A differenza di Windows, che può avere molteplici percorsi e molteplici file system, un sistema Unix/Linux ha un *unico* file system.
- ![[Pasted image 20231017155755.png|center]]
I principali comandi di navigazione sono:

```Bash
pwd # Stampa la directory corrente
ls  # Mostra una lista dei file
cd  # Cambia directory
```

Si utilizzano i "*pathnames*" ( nomi di percorsi ) per fare riferimento a file e cartelle nel file system Linux. Ci sono due tipi di *pathnames* :
1. *Assoluti* - Il percorso completo per una directory o file; Inizia con /
2. *Relativi* - Un percorso parziale relativo alla directory corrente; Non inizia con /
I caratteri speciali sono interpretati dalla shell come espansioni dei nomi dei file:
1. ~      La cartella home
2. .       Directory corrente
3. ..      Directory precedente
4. *      Carattere che corrisponde a tutti i filename 
5. ?      Carattere che corrisponde a tutti i caratteri
6. $\texttt{TAB}$  Prova l'autocompletamento di un filename
## Il comando ls
Utili opzioni per il comando 'ls':

```Bash
ls -a    #Lista tutti i file, inclusi i file nascosti che iniziano con "."
ls -ld * #Lista i dettagli di una directory e non il suo contenuto
ls -F    #Mette un carattere di indicatore alla fine di ogni nome
ls -l    #Semplice lista lunga
ls -lR   #Lista lunga ricorsiva
ls -lh   #Da dimensioni del file leggibili dall'uomo
ls -lS   #Ordina i file dalla dimensione
ls -lt   #Ordina i file in base alla data di modifica
```
## Alcuni comandi utili
```Bash
cp [file 1] [file 2]    # Copia file
mkdir [name]            # Crea una directory
rmdir [name]            # Rimuove una directory ( vuota )
mv [file] [destination] # Sposta/Rinomina file
rm [file]               # Rimuove (-r per la ricorsione)
file [file]             # Identifica il tipo di file
less [file]             # Sfoglia i file
head -n [file]          # Mostra le prime n linee
tail -n [file]          # Mostra le ultime n linee
ln -s [file] [new]      # Crea un link simbolico
cat [file] [file 2...]  # Mostra file
tac [file] [file 2...]  # Mostra file in ordine inverso
touch [file]            # Aggiorna l'orario di modifica / Crea file
od [file]               # Mostra i contenuti di un file
```
## Permesso di accesso ai file
I file Linux hanno un set di *permessi* associati che dirigono il *read* ( Lettura), *write* ( Scrittura) ed *execute* ( Esecuzione ) per il proprietario, i membri del gruppo del proprietario, e chiunque altro. Per vedere i permessi di un file, si usa l'appellativo `-l` da `ls` :
![[Pasted image 20231018092726.png|center]]
Si possono modificare i permessi di accesso di un file con il comando `chmod`, con gli appellativi:
- u = 'owner' 
- g = 'group'
- o = 'other'
- r = 'read'
- w = 'write'
- x = 'execute' :
![[Pasted image 20231018093528.png|center]]

Il comando `chmod` funziona anche con il seguente mappaggio, *read* = 4,*write* = 2,*execute* = 1:
![[Pasted image 20231018093827.png|center]]

Tabella : 
![[Pasted image 20231018093936.png|center]]

## File di avvio di Bash - dot files
*Inizializzazione Bash*:
- Bash legge molteplici file di avvio durante il login.
- Alcuni file sono protetti dal sistema.
- Altri risiedono nella cartella home per personalizzazione diretta.
*File nascosti*:
- Iniziano con .
- Nascosti di default
*Rivelare i file nascosti*:
- Si utilizza `ls -al` per mostrarli.
## .bash_profile, .bashrc, alias
`.bash_profile`:
- Questo file viene eseguito al login.
- PATH è posizionato qui
`.bashrc`:
- Questo file viene eseguito quando viene creata una nuova shell.
- Qui è possibile creare degli alias
# Processi e controllo del lavoro

# Editors
# Hello World in C