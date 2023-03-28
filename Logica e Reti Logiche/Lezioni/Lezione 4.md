# Il metodo dei *tableaux* per la logica proposizionale
Data una formula $\mathcal{F}$ della logica proposizionale, come possiamo verificare se $\mathcal{F}$ è una tautologia? Nell’Episodio 1 abbiamo visto che, per definizione, è sufficiente scrivere la tabella di verità e verificare che $\mathcal{F}$ risulti T in tutte le interpretazioni.
In questo episodio introduciamo il cosiddetto metodo dei tableaux, che è più “flessibile” rispetto alle tabelle di verità perché, al contrario di queste ultime, potremo poi generalizzarlo al caso della Logica del Primo Ordine.
Per seguire le argomentazioni esposte in questi appunti è necessario conoscere le tabelle di verità dei connettivi principali e il significato di termini quali *“formula ben formata”* e *“tautologia”*.
## 1 Antipasto
Sia $\mathcal{F}$ la formula seguente:$$
((p \wedge q) \Rightarrow r) \Rightarrow (\sim p \vee (q \Rightarrow r))$$
$\mathcal{F}$ è una tautologia oppure no? Dall’episodio precedente sappiamo che per
scoprirlo ci basta fare la tabella di verità. Ma, per il momento, fate la vostra scommessa, resistete un attimo alla tentazione di fare la tabella di verità e proviamo a ragionare in un altro modo.
1. Prendiamo la sua negazione $\sim\mathcal{F}$
$$∼ [((p \wedge q) \Rightarrow r) \Rightarrow (\sim p \vee (q \Rightarrow r))]
\space\space\space(1)$$
E prima di tutto osserviamo che la formula (1) qui sopra è vera in qualche interpretazione se e solo se $\mathcal{F}$ non è una tautologia. Quindi per vedere se $\mathcal{F}$ non è una tautologia possiamo dimenticarci di $\mathcal{F}$ e vedere se esiste una interpretazione che rende la (1) vera.
2. La formula (1) è del tipo $\sim [\mathcal{F} \Rightarrow \mathcal{F}_2 ]$, dove $\mathcal{F}_1$ è $(p \wedge q)\Rightarrow r$ e $\mathcal{F}_2$ è $\sim p \vee (q \Rightarrow r)$.
Quindi è vera se e soltanto se $\mathcal{F}_1$ è vera e $\mathcal{F}_2$ è falsa, ossia se e soltanto se $\mathcal{F}_1$ e $\sim\mathcal{F}_2$ sono entrambe vere. La formula (1) quindi è vera se e solo se sono vere entrambe le formule (2) e (3) qui sotto.
![[Pasted image 20230328150818.png|center]]
Quindi per vedere se un'interpretazione che rende la prima formula vera, possiamo dimenticarci della formula stessa e vedere se un'interpretazione che rende vere le formule 2,3

3.  Consideriamo la formula 2: è un'implicazione, quindi è vera solo quando è falso oppure quando è vero. In altre parole, quando almeno una è vera, fra le due formule quì sotto:
![[Pasted image 20230328150853.png|center]]

Si osservi che le ultime 2 formule non sono state posizionate una sotto l'altra come nei casi precedenti, ma si sono creati due rami. Questo perchè per vedere se una interpretazione che rende vere sia la seconda formula che la terza, possiamo dimenticarci della seconda e vedere se una interpretazione che rende vera la terza formula e almeno una fra la quarta e la quinta
4.  Si consideri la terza: è la negazine di un OR, quindi è vera e sono entrambe false, in altre parole, quando sia la sesta che la settima sono vere
![[Pasted image 20230328151028.png|center]]

Si osservi che la sesta e la settima le abbiamo messe una sotto l'altra e ripetute sotto entrambi i rami. Infatti, per vedere se una interpretazione che rende vera la terza e almeno una fra la quarta e la 5, possiamo dimenticarci della terza e vedere se una interpretazione che rende vere la quarta, la sesta e la settima, oppure la quinta, la sesta e la settima.
5.  Andiamo alla quarta: è la negazione di un AND, quindi è vera quando almeno una delle due fra p e q è falsa, ossia quando l'ottava e vera oppure la nona è vera
![[Pasted image 20230328151118.png|center]]

Per vedere se una interpretazione che rende vere la quarta, la sesta e la settima perciò possiamo dimenticarci della quarta e vedere se una interpretazione che rende vere la sesta, la settima e l'ottava, oppure la sesta, la settima e la nona. Tuttavia, una interpretazione che renda vere la sesta, la settima e l'ottava , perchè per rendere vera la sesta la variabile p dovrebbe essere T mentre per rendere vera l'ottava, dovrebbe essere F. Diciamo che quel ramo è chiuso e nello schema indicato questo fatto con una X. Per vedere se un'interpretazione che rende vere la sesta, la settima e la nona dobbiamo ancora procedere fino a scomporre la settima.
6.  Per quanto riguarda la quinta e la sesta, sono già delle varibili quindi non c'è più niente da scomporre. Ci resta da considerare la settima formula: è la negazione di un'implicazione, quindi..
![[Pasted image 20230328151150.png|center]]

Anche il secondo e il terzo ramo si chiudono : il secondo perchè una interpretazione che renda vere la nona e la decima formula, il terzo perchè una interpretazione che renda vere sia la quinta che l'undicesima formula.
Non c'è più niente da scomporre e abbiamo un albero con tutti i rami chiusi. Che cosa significa? Torniamo un attimo indietro e vediamo di ripercorrere quello che abbiamo fatto con riferimento al nostro schema di formule:
![[Pasted image 20230328151406.png|center]]

## 2 Le regole del gioco
