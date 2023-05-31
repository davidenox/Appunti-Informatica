# Blocchi funzionali combinatori
## Decoder
**Def.** (Decoder)
Un DECODER $n:2^n$ è un circuito con $n$ input, diciamo $x_{0}, x_{1},...., x_{n-1},$ e $2^n$ output, diciamo $y_{0}, y_{1},....., y_{2^{n}-1}$ , tale che per ogni $i = 0,1,.....,2^{n}-1$ 
$$y_{i}=\begin{cases} 1 \ \ se \   (i)_{10}=(x_{n-1} \ ..... \ x_{1}x_{0})_{2} \\ 0 \ \  \text{altrimenti}  & \end{cases}$$
In altre parole il circuito decodifica la sequenza di bit in input ponendo a 1 l'output $y_{i}$ il cui indice $i \in \{0,1,....., 2^{n}-1\}$   è il numero intero rappresentato in binario dagli $n$ bit in input. Per esempio, se i due bit in input di un DECODER 2:4 sono $(x_{1},x_{0}) = (1, 0)$, i quattro bit in output devono essere $(y_{3}, y_{2}, y_{1}, y_{0})= (0, 1, 0, 0)$ .
Si noti che in un decoder, qualunque sia la sequenza di bit in input, uno e uno solo degli output avrà valore 1.
Come si costruisce tale circuito?
Se $n = 1$ abbiamo un solo input $x_{0}$ e due output $y_{1},y_{0}$ ; $y_{0}$ deve essere 1 quando $x_{0}= 0$ mentre $y_{1}$ deve essere 1 quando $x_{0}=1$  

![[Pasted image 20230531112655.png|center]]

Se $n=2$ abbiamo due input $x_{0},x_{1}$ e quattro output $y_{3},y_{2},y_{1},y_{0}$ 

![[Pasted image 20230531112759.png|center]]

A questo punto dovrebbe essere chiaro come la costruzione si generalizza a un DECODER $n:2^{n}$ per qualunque $n$.
Una volta costruito il nostro blocco funzionale DECODER, possiamo immaginare di averlo a disposizione come le porte logiche AND, OR e NOT e usarlo per costruire circuiti più complessi.
A questo scopo, possiamo disegnare un DECODER 2:4 in questo modo. 
 ![[Pasted image 20230531112837.png|center]]
 
Si osservi che se abbiamo un DECODER $n:2^n$ e una porta OR possiamo implementare qualunque funzione Booleana di $n$ variabili.

**ESEMPIO**
 $$y=x_{0}x_{1}+\bar x_{0}\bar x_{1}$$
Questa formula può essere implementata con il seguente circuito 
![[Pasted image 20230531112854.png|center]]

## Multiplexer
**Def.** (Multiplexer)
Un MULTIPLEXER $2^{n}:1$ è un circuito con $2^{n}+n$ input, diciamo $x_{0},x_{1},.....,x_{2^n}-1$ e $s_{0},.....,s_{n-1}$ , e un output, y, tale che $$y=x_{(s_{n-1}...s_{1},s_{0})_{2}}$$In altre parole, fra le variabili in input $x_{0},...,x_{2^{n}-1}$ , il circuito dà in output il bit contenuto nella variabile il cui indice è codificato in binario dalle variabili di selezione $s_{0},....,s_{n-1}$. Per esempio, in un MULTIPLEXER 4:1, se gli input sono $(x_{3},x_{2},x_{1},x_{0})=(0,1,1,0)$ e $(s_{1},s_{0})= (1,0)$, il circuito darà in output $y=1$, perchè $(s_{1}s_{0})_{2}=(10)_{2}=(2)_{10}$ e $x_{2}=1$. Come costruiamo un circuito che risponda a queste specifiche?
Se $n= 1$ abbiamo soltanto due variabili in input $x_{1},x_{0}$ e una variabile di selezione $s_{0}$.
Chiaramente possiamo procedere come abbiamo fatto per il decoder e scrivere la tabella di verità con i tre input e un output e poi costruire il circuito.

Possiamo anche ragionare più ad altro livello e osservare che, quando $s_{0}=0$ dobbiamo avere $y=x_{0}$ e quando $s_{0}=1$ dobbiamo avere $y=x_1$. Quindi possiamo costruire il circuito così
![[Pasted image 20230531112916.png|center]]

Si noti che il multiplexer implementa un $if : if \ s_{0} \  then \ x_{1} \ else \ x_{0}$ 

Possiamo costruire un MULTIPLEXER 4:1 anche usando un DECODER 2:4, quattro porte AND e una porta OR, come in figura (4)

![[Pasted image 20230531112939.png|center]]
Il simbolo con cui in genere si indica un multiplexer è questo qui 

![[Pasted image 20230531113005.png|center]]

Con un MULTIPLEXER $2^{n}:1$ si può implementare una qualunque funzione con $n$ variabili, associando agli input di selezione $s_{0},....,s_{n-1}$ del multiplexer le variabili della funzione, e agli input $x_{0},....,x_{2^n-1}$ del multiplexer i valori Booleani che la funzione assume nelle righe corrispondenti della tabella di verità. Per esempio, la funzione $y=ab +\bar a\bar b$ si può implementare così
![[Pasted image 20230531113033.png|center]]
ww