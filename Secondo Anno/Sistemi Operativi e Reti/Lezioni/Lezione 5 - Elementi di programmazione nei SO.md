# Il mondo secondo il linguaggio C
C è stato creato da Dennis Ritchie nel 1972 per sviluppare programmi UNIX. Alcune caratteristiche originali di UNIX sono ancora visibili.

>[!note]- *Everything is a file*

# UNIX: Everything is a file
- Sockets
- Devices
- Hard drives
- Stampanti
- Modem
- Pipes
- ...

| Nome Descrittivo | Short Name | File Number | Descrizione          |
| ---------------- | ---------- | ----------- | -------------------- |
| Standard In      | stdin      | 0           | Input dalla tastiera |
| Standard Out     | stdout     | 1           | Output dalla console |
| Standard Error   | stderr     | 2           | Error output dalla console                     |
Per impostazione predefinita ogni processo inizia con questi tre "file"..."aperti".
## Hello World (1)
Cosa bisognerebbe fare per stampare "Hello World" sulla console ( output standard )?
`printf(char *str,...)`
Infatti:
```C
#include <stdio.h>
int main(int argc, char **argv){
	printf("Hello World!\n");
	return 0;
}
```

> Build process
![[Pasted image 20231024160726.png|center|500]]
## Hello World (2)
```C
#include <unistd.h>
#define STDOUT 1

int main(int argc, char **argv){
	char msg[] = "Hello World!\n";
	write(STDOUT, msg, sizeof(msg));
	return 0;
}
```
## Hello World (3)
```C
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#define STDOUT 1

int main(int argc, char **argv){
	char msg[] = "Hello World!\n";
	int nr = SYS_write;
	syscall(nr, STDOUT, msg, sizeof(msg));
	return 0;
}
```

### Esempi
Fare riferimento ai file di esempio:
- 5.1_hello_world_1.c
- 5.1_hello_world_2.c
- 5.1_hello_world_3.c
Presenti nella repo
## Standard Library
Libc fornisce utili wrapper intorno alle syscall ( ad esempio `write`, `read`, `exit`). È necessario chiamare la `syscall` oppure l'istruzione `int 0x80` fatto in assembly.
# Creazione di Processi
## Process management system call
Si può creare una shell minimale che:
- Attende che l'utente digiti un comando
- Avvia un processo per eseguire il comando
- Attende che il processo sia terminato
I comandi più utilizzati saranno `fork`, `wait` e `execv`.
### Creazione del processo (1)
>`pid_t fork()`: Duplica il processo corrente
- Restituisce il pid del figlio nel chiamante ( genitore )
- Restituisce 0 nel nuovo processo ( figlio )
>`pid_t wait(int *wstatus)`:
- Attende che i processi figli cambino stato
- Scrive lo stato in `wstatus`
- Ad esempio, a causa di un exit o segnale
#### Fork, wait
```C
void main(void){
	int pid, child_status;
	if(fork()==0){
		do_something_in_child();
	} else{
		wait(&child_status); //wait for child
	}
}
```
### Creazione del processo (2)
`int execv(const char *path, char *constargv[]);`
- Carica un nuovo binario ( path ) nel processo corrente, rimuovendo tutte le altre mappature di memoria.
- `constargv` contiene gli argomenti del programma.
- L'ultimo argomento è $\texttt{NULL}$.
- Es. `constargv = {"/bin/ls", "-a", NULL}`
- Diverse varianti di exec(v)(p) ( controllare le pagine `man` ).
#### Fork, wait, execv
```C
void main(void){
	int pid, child_status;
	char *args[]={"/bin/ls", "-l", NULL};
	if(fork()==0){ //fork crea il processo figlio
		execv(args[0], args);//nel figlio: load+execure program
	}else {
		wait(&child_status); //wait for child
	}
}
```
### Una shell minimale
```C
while(1){
	char cmd[256], *args[256];
	int status;
	pid_t pid;
	read_command(cmd, args); /*legge comandi ed argomenti 
	dalla linea di comando*/
	pid = fork();

	if(pid==0){
		execv(cmd, args);
		exit(1);
	}else {
		wait(&status);
	}
}
```
## Come terminare i programmi?
`Ctrl+C`, ma come funziona?
Risposta: i *segnali*.
# Gestione dei segnali
## Chiamate di sistema per i segnali
A volte i processi devono essere interrotti durante la loro esecuzione. Viene inviato un *segnale* al processo che deve essere interrotto. Il processo interrotto può catturare il segnale installando un gestore di segnali ( *Signal Handler* ).
Cosa succede quando l'utente del terminale digita `Ctrl+C` o `Ctrl+Z`?
### Signal, Alarm, Kill
`sighandler_t signal(int signum, sighandler_t handler)`:
- Registra un gestore di segnali per il segnale `signum`.
`unsigned int alarm(unsigned int seconds)`:
- Consegna `SIGALRM` in un numero di secondi specificato.
`int kill(pid_t pid, int sig)`:
- Consegna il segnale `sig` al processo `pid` ( *non uccide* ).
#### Esempio alarm
```C
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarm_handler(int signal){
	printf("In signal handler: caught signal %d!\n",signal);
	exit(0);
}
int main(int argc, char **argv){
	signal(SIGALRM, alarm_handler);
	alarm(1); //alarm will send signal after 1sec

	while(1){
		printf("I am running!\n");	
	}
	return 0;
}
```
# Comunicazione tra processi attraverso pipe
## Esempio pipe(1)
Cosa succede se si esegue il seguente comando?
`cat names.txt | sort`
E i seguenti comandi?
`mkfifo named.pipe`
`echo "Hello World!" > named.pipe`
`cat named.pipe`
### Open, Close, Pipe, Dup
`int open(const char *pathname, int flags)`:
- Apre il file specificato dal nome del percorso ( `pathname` ).
`int close(int fd)`:
- Chiude il descrittore di file specificato `fd`.
`int pipe(int pipefd[2])`:
- Crea una `pipe` con due `fd` per le sue estremità.
`int dup(int oldfd)`:
- Crea una copia del descrittore di file `oldfd` utilizzando il descrittore di file inutilizzato con il numero più basso per la copia.
## Esempio pipe (2)
```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1

#define PIPE_RD 0
#define PIPE_WR 1

int main(int argc, char** argv ){
	pid_t cat_pid, sort_pid;
	int fd[2];

	pipe(fd);

	cat_pid = fork();
	if(cat_pid==0){
		close(fd[PIPE_RD]); //<--- chiusura
		close(STDOUT);
		dup(fd[PIPE_WR]);
		execl("/bin/cat","cat","names.txt", NULL);
	}
	sort_pid = fork();
	if(sort_pid==0){
		close(fd[PIPE_WR]); //<--- chiusura
		close(STDIN);
		dup(fd[PIPE_RD]);
		execl("/urs/bin/sort","sort", NULL);
	}

	close(fd[PIPE_RD]);
	close(fd[PIPE_WR]);

	/*wait for children to finish*/
	waitpid(cat_pid, NULL, 0);
	waitpid(sort_pid, NULL, 0);

	return 0;
}
```
### Possiamo saltare le chiusure?
1. *Evitare Blocchi*: Chiudi la fine di lettura di una pipe per impedire al processo di scrittura di rimanere bloccato.
2. *Ricezione EOF*: sort aspetta un $\texttt{EOF}$ per terminare la lettura. Chiudi la fine di scrittura per inviare un $\texttt{EOF}$ a sort
3. *Evitare Letture Accidentali*: Nel processo  cat, chiudi la fine di lettura per evitare letture inaspettate dalla pipe.
4. *Reindirizzamento di STDOUT in cat*: Dopo la duplicazione, chiudi il descriptor originale per garantire che cat scriva solo nella pipe.
5. *Reindirizzamento di STDIN in sort*: Dopo la duplicazione, chiudi il descriptor originale per assicurarti che sort legga solo dalla pipe.
6. *Descriptor nel processo padre*: Dopo la Fork, il processo padre dovrebbe chiudere entrambe le estremità della pipe.
# Esercizio
Un processo genera due processi figli P1 e P2. Il figlio P1 esegue un ciclo indeterminato durante il quale genera casualmente numeri interi compresi tra 0 e 100. P1 comunica, ad ogni interazione, il numero al padre solo se esso è dispari. P2 fa la stessa cosa  ma comunica al padre solo i numeri pari. Il padre, per ogni coppia di numeri che riceve dai figli ne fa la somma e la visualizza.
Il programma deve terminare quando la somma dei due numeri ricevuti supera il valore 190: il padre, allora, invia un segnale di terminazione a ciascuno dei figli.