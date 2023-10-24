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
