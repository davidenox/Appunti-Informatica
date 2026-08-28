| Nome           | Abbreviazione | File Number | Descrizione                  |
| -------------- | ------------- | ----------- | ---------------------------- |
| Standard In    | `stdin`       | 0           | Input da tastiera            |
| Standard Out   | `stdout`      | 1           | Output da terminale          |
| Standard Error | `stderr`      | 2           | Output d'errore da terminale |
Per stampare "Hello World" su console in standard output?
```C
#include <unistd.h>
#define STDOUT 1

int main(int argc, char **argv){
	char msg[] = "Hello World!\n";
	write(STDOUT, msg, sizeof(msg));
	return 0;
}
```

# Creazione di processi
Si crea una shell minimale che attende che l'utente digiti un comando, avvia un processo per eseguire il comando e che infine attende che il processo sia terminato 
`(fork, wait, execv)`

`pid_t fork()`  Duplica il processo corrente.
- Restituisce il pid del figlio nel chiamante (padre)
- Restituisce 0 nel nuovo processo (figlio)
`pid_t wait(int *wstatus)` Attende che i processi figli cambino stato.
- Scrive lo stato in `wstatus`
- Es. a causa di exit o segnale

```C
void main(void){
	int pid, child_status;
	if(fork()==0){
		do_something_in_child();
	} else{
		wait(&child_status);
	}
}
```
# Gestione dei segnali
A volte i programmi devono essere interrotti durante la loro esecuzione, inviandogli un **segnale**. Il processo interrotto può catturare il segnale installando un *gestore di segnali* (**signal handler**).
`(signal, alarm, kill)`

- `sighandler_t signal(int signum, sighandler_t handler)` Registra un gestore di segnali per il segnale `signum`.
- `unsigned int alarm (unsigned int seconds)` Consegna `SIGALARM` in un numero di secondi specificato
- `int kill(pid_t pid, int sig)` Consegna il segnale `sig` al processo `pid` (non uccide!)

# Comunicazione tra processi tramite pipe
	(open, close, pipe, dup)

- `int open(const char *pathname, int flags)` Apre il file specificato dal nome del percorso;
- `int close(int fd)` Chiude il descrittore di file specificato `fd`;
- `int pipe(int pipefd[2])` Crea una *pipe* con due `fd` per le sue estremità;
- `int dup(int oldfd)` Crea una copia del file descriptor `oldfr` utilizzando il file descriptor inutilizzato con il numero più basso per la copia.