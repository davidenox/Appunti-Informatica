Ritornando a [[Lezione 10 - Capitolo 6]]

# Alberi AVL (Adel’son-Vel’skii e Landis, 1962)

## Definizioni

_Def (Fattore di bilanciamento)_
**Fattore di bilanciamento $\beta(v)$** di un nodo v := altezza del sottoalbero sinistro di v - altezza del sottoalbero destro di v
_Def_
Un albero si dice **bilanciato in altezza** se ogni nodo v ha un fattore di bilanciamento in valore assoluto $\leq1$

**Alberi AVL = alberi binari di ricerca in altezza**

Generalmente $\beta(v)$ mantenuto come informazione addizionale nel record relativo a v

**Esempio**
![[appunti asd/mod i/immagini/Pasted image 20221128161923.png|center|600]]

è un albero AVL? Si, tutti i nodi hanno fattore di bilanciamento = 0

**Esempio**

![[appunti asd/mod i/immagini/Pasted image 20221128162110.png|center|500]]

è un albero AVL? No, Non vale la proprietà sui fattori di bilanciamento

>[!INFO]- Osservazione
>Per convenzione l'altezza di un albero vuoto = -1

**Esempio**

![[appunti asd/mod i/immagini/Pasted image 20221128162438.png|center|600]]

è un albero AVL? Si, proprietà sui fattori di bilanciamento rispettata

## Altezza di alberi AVL

Si può dimostrare che **un albero AVL con n nodi ha altezza $O(log(n))$**

**Idea della dimostrazione**: considerare, tra tutti gli AVL, i più sbilanciati

**Albero di Fibonacci di altezza h**: albero AVL di altezza h con il minimo numero di nodi $n_h$

Minimizzare # nodi fissata l'altezza $\equiv$ Massimizzare altezza fissato # nodi

**Intuizione**: se gli alberi di FIbonacci hanno altezza $O(log(n))$, allora tutti gli alberi AVL hanno altezza $O(log(n))$

**Esempio: come è  fatto un albero di Fibonacci di altezza 2?**

![[appunti asd/mod i/immagini/Pasted image 20221128163216.png|center|600]]

Infatti: se togliamo ancora un nodo, o diventa sbilanciato, o cambia la sua altezza
**Nota**: ogni nodo (non foglia) ha fattore di bilanciamento pari (in valore assoluto) a 1

**Alberi di Fibonacci per valori piccoli di altezza**

$T_i$: albero di Fibonacci di altezza i (albero AVL di altezza i con il minimo numero di nodi)

![[appunti asd/mod i/immagini/Pasted image 20221128163643.png|center|700]]

Si intravede lo schema per generare l'i-esimo albero di Fibonacci a partire dai precedenti?
**Lo schema**:
![[appunti asd/mod i/immagini/Pasted image 20221128164125.png|300]]

>[!important]- Lemma
>Sia $n_h$ il numero di nodi di $T_h$. 
>Risulta $n_h=F_{h+3}-1$

**Oss**: $F_i=$i-esimo numero di Fibonacci

Dimostrazione per induzione su h, si usa $n_h=1+n_{h-1}+n_{h-2}$

**Corollario**: Un albero AVL con n nodi ha altezza $h=O(log(n))$
**dim**
$n_h=F_{h+3}-1=\Theta(\phi^h)\implies h=\Theta(log(n_h))=O(log(n))$

> Ricorda che vale $F_k=\Theta(\phi^k),\phi=1.618...$ sezione aurea

corollario segue da $n_h\leq n$
$\square$ 

**Posso usare un albero AVL per implementare un dizionario?**
![[appunti asd/mod i/immagini/Pasted image 20221128165052.png|center|600]]

Come implemento Insert(14)?...e Delete(25)?
Dopo l'inserimento non è più un albero AVL

**Domanda**:
di **quanto** e **quali** fattori di bilanciamento **cambiano** a fronte di un inserimento/cancellazione?

**Se parto da un albero AVL** e inserisco/cancello un nodo
- (quali) cambiano solo i fattori di bilanciamento dei nodi lungo il cammino radice-nodo inserito/cancellato
- (quanto) i fattori di bilanciamento cambiano di +/- 1

## Implementazione delle operazioni

- L'operazione search procede come in un BST
- Ma inserimenti e cancellazioni potrebbero sbilanciare l'albero $\implies$ Manteniamo il bilanciamento tramite opportune **rotazioni**

### Rotazione di base verso destra/sinistra sul nodo v/u

![[appunti asd/mod i/immagini/Pasted image 20221128165909.png|center|700]]

Mantiene la proprietà di ricerca, richiede tempo $O(1)$

#### Ribilanciamento tramite rotazioni

- Le rotazioni sono effettuate su nodi sbilanciati
- Sia v un nodo di profondità massima (nodo **critico**) con un fattore di bilanciamento $\beta(v)\pm2$ 
- Esiste un sottoalbero T di v che lo sbilancia
- A seconda della posizione di T si hanno 4 casi:![[appunti asd/mod i/immagini/Pasted image 20221128170422.png|700]]
- I quattro casi sono simmetrici a coppie

##### Caso SS - $[\beta(v)=2,\text{altezza}\:T_1=h+1]$

- L'altezza di $T(v)=h+3$, l'altezza di $T(u)=h+2$, l'altezza di $T_3=h$ e l'altezza di $T_1=h+1\implies\beta(v)=2$ e lo sbilanciamento è provocato da $T_1$ ![[appunti asd/mod i/immagini/Pasted image 20221128170725.png|center|400]]
- Si applica una rotazione semplice verso destra su v, 2 sottocasi possibili:
	1.  **l'altezza di $T_2$ è h** $\implies$ l'altezza dell'albero coinvolto nella rotazione passa da h+3 a h+2
	2.  **l'altezza di $T_2$ è h+1** $\implies$ l'altezza dell'albero coinvolto nella rotazione rimane pari a h+3

![[appunti asd/mod i/immagini/Pasted image 20221128171142.png|center|700]]
...i due sottocasi del caso SS...
![[appunti asd/mod i/immagini/Pasted image 20221128171218.png|center|700]]

###### Osservazioni sul caso SS
- Dopo la rotazione l'albero è bilanciato (tutti i fattori di bilanciamento sono in modulo $\leq1$)
- L'**inserimento** di un elemento nell'AVL (ovvero, l'aggiunta di una **foglia** a un albero bilanciato) può provocare solo il sottocaso 1 (perchè altrimenti l'AVL era già sbilanciato!)
- Invece, la **cancellazione** di un elemento dall'AVL (che necessariamente fa diminuire l'altezza di qualche sottoalbero) può provocare entrambi i casi (ad esempio, se cancello un elemento ho abbassato l'altezza di $T_3$)
- Nel caso 1, dopo la rotazione, l'albero diminuisce la sua altezza di uno

##### Caso SD - $[\beta(v)=2,altezza\:T_1=h]$
- L'altezza di $T(v)=h+3$, l'altezza di $T(z)=h+2$, l'altezza di $T_1=h$, l'altezza di $T_4=h$ e l'alteza di $T(w)=h+1\implies\beta(v)=2$ e $\beta(z)=-1$ cioè lo sbilanciamento è provocato dal sottoalbero destro di z ![[appunti asd/mod i/immagini/Pasted image 20221128171941.png|center|400]]
- Applicare due rotazioni semplici: una verso sinistra sul figlio sinistro del nodo critico (nodo z), l'altra verso destra sul nodo critico (nodo v)

![[appunti asd/mod i/immagini/Pasted image 20221128172111.png|center|700]]

- L'altezza dell'albero dopo la rotazione passa da h+3 a h+2, poichè $T_2,T_3$ sono alti al più h, e il fattore di bilanciamento di w diventa 0, mentre i fattori di bilanciamento di z e v sono 0 oppure $\pm1$
- Il caso SD può essere provocato sia da inserimenti (in $T_2$ o $T_3$), sia da cancellazioni che abbassano di 1 l'altezza di $T_4$

#### Insert(elem e, chiave k)

1. Crea un nuovo nodo u con elem=e e chiave=k
2. Inserisci u come in un BST
3. Ricalcola i fattori di bilanciamento dei nodi nel cammino della radice a u: sia v il più profondo nodo con fattore di bilanciamento pari a $\pm2$ (**nodo critico**)
4. Esegui una rotazione opportuna su v

>[!info]- Osservazioni
>Un solo ribilanciamento è sufficiente, poichè l'altezza dell'albero coinvolto diminiusce di 1 (sottocaso 1 del caso SS o DD, o casi SD o DS), e quindi torna ad essere **uguale** all'altezza che aveva **prima dell'inserimento**

Vedi esempio qua [Esempio Insert albero AVL](https://www.mat.uniroma2.it/~guala/cap6_2021.pdf#page=51)

#### Delete(elem e)

1.  Cancella il nodo come in un BST
2. Ricalcola il fattore di bilanciamento del **padre del nodo eliminato** (che potrebbe essere diverso dal nodo contenente **e**), ed esegui l'opportuna rotazione semplice o doppia ove necessario
3. Ripeti qeusto passo, sino ad arrivare eventualmente alla radice dell'AVL
	1. Se l'altezza del sottoalbero appena ribilanciato è uguale a quella che aveva prima della cancellazione, termina. Invece, se tale altezza è diminuita, risali verso l'alto (cioè vai nel padre del sottoalbero appena ribilanciato), calcola il fattore di bilanciamento, e applica l'opportuno ribilanciamento

>[!info]- Osservazione
>Potrebbero essere necessarie $O(log(n))$ rotazioni: infatti eventuali diminuzioni di altezza indotte dalle rotazioni possono propagare lo sbilanciamento verso l'alto nell'albero (l'altezza del sottoalbero in cui è avvenuta la rotazione **diminuisce di 1** rispetto a quella che aveva **prima della cancellazione**)

Vedi esempio delete qui [Esempio Delete su AVL](https://www.mat.uniroma2.it/~guala/cap6_2021.pdf#page=55)

##### Cancellazione con rotazioni a cascata

![[appunti asd/mod i/immagini/Pasted image 20221128173516.png|center]]

### Costo delle operazioni

Tutte le operazioni hanno costo $O(log(n))$ poichè l'altezza dell'albero è $O(log(n))$ e ciascuna rotazione richiede solo tempo costante

## Classe AlberoAVL

![[appunti asd/mod i/immagini/Pasted image 20221128173733.png|center|700]]

## Qualche dettaglio importante

Nell'analisi della complessità dell'operazione di insert/delete abbiamo implicitamente usato le seguenti tre proprietà:
1. dato un nodo v,è possibile conoscere $\beta(v)$ in tempo $O(1)$
2. dopo aver inserito/cancellato un nodo v nell'albero come se fosse un semplice BST, è possibile ricalcolare i fattori di bilanciamento dei nodi lungo il cammino da v alla radice in tempo complessivo $O(log(n))$
3. Nell'eseguire le rotazioni necessarie per ribilanciare l'albero, è possibile aggiornare anche i fattori di bilanciamento dei nodi coinvolti in tempo complessivo $O(log(n))$



