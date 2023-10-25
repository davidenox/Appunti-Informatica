/*
Un processo genera due processi figli P1 e P2. Il figlio P1 esegue un ciclo 
indeterminato durante il quale genera casualmente numeri interi compresi tra 
0 e 100. P1 comunica, ad ogni interazione, il numero al padre solo se esso è 
dispari. P2 fa la stessa cosa ma comunica al padre solo i numeri pari. Il padre, 
per ogni coppia di numeri che riceve dai figli ne fa la somma e la visualizza. 
Il programma deve terminare quando la somma dei due numeri ricevuti supera il 
valore 190: il padre, allora, invia un segnale di terminazione a ciascuno dei 
figli.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1
#define PIPE_WR 0
#define PIPE_RD 1
#define MAX 190

int main(int argc, char** argv){

    pid_t p1, p2;   // processi figli
    int fd1[2],fd2[2];// file descriptor dei due figli

    if (pipe(fd1) == -1 || pipe(fd2) == -1){
	    perror("Errore"); // gestione dell'errore
	    exit(1);
    }

    p1 = fork(); //genera processo figlio
    if(p1 == 0){ //se esiste e funziona
        close(fd1[0]); //chiude stream di lettura
        srand(getpid()); 
        while(1){
            int n = rand() % 101; // genera numero random da 0 a 100
            if(n % 2 == 1){ // se è dispari
                write(fd1[1],&n, sizeof(int)); //scrivilo
            }
        }
        close(fd1[1]); //chiudi la stream di scrittura
    }else{
        p2 = fork(); //genera processo figlio
        if(p2 == 0){ //se esiste e funziona
            close(fd2[0]); //chiudi la stream di lettura
            srand(getpid());
            while(1){
                int n = rand() % 101;
                if (n % 2 == 0){ //se è pari
                    write(fd2[1], &n, sizeof(int)); //scrivilo
                }
            }
            close(fd2[1]); //scrivi la stream di scrittura
        }else{
            close(fd1[1]); //chiudi le due stream di scrittura
            close(fd2[1]);
            int somma = 0; //inizializza la somma
            while(1){
                int n1, n2;
                read(fd1[0], &n1, sizeof(int)); //il processo padre legge il figlio p1
                read(fd2[0], &n2, sizeof(int)); //il processo padre legge il figlio p2
                somma = n1+n2;//somma
                printf("%d + %d = %d\n", n1, n2, somma); //printa la somma
                if(somma > MAX){ //controlla se la somma è più grande della soglia
                    kill(p1, SIGTERM); //termina i processi figli se si
                    kill(p2, SIGTERM);
                    printf("Processi terminati, p1 = %d, p2 = %d, somma = %d\n", n1, n2, somma);
                    break;//stampa l'ultima somma e si ferma
                }
            }// chiude le stream di scrittura dei figli e aspetta che terminano
            close(fd1[0]);
            close(fd2[0]);
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}