# Il problema del Dizionario

![[appunti asd/mod i/immagini/Pasted image 20221124091900.png|center|700]]

## Come implementare efficientemente un dizionario?

è possibile garantire che tutte le operazioni su un dizionario di n elementi abbiano tempo $O(log(n))$

**Due Idee**
1. Definire un albero (binario) tale che ogni operazione richiede tempo $O(\text{alteza albero})$
2. Fare in modo che l'**altezza dell'albero** sia sempre $O(log(n))$

1 - **alberi binari di ricerca**
2 - **alberi AVL**

### Alberi binari di ricerca (BST=Binary Search Tree)

_Def_
Albero binario che soddisfa le seguenti proprietà:
- ogni nodo v contiene un elemento "elem(v)" cui è associata una chiave "chiave(v)" presa da un dominio totalmente ordinato
Per ogni nodo v vale che:
- Le chiavi nel sottoalbero sx di v sono $\leq$ chiave(v)
- Le chiavi nel sottoalbero dx di v sono $\geq$ chiave(v)

**Esempio**
![[appunti asd/mod i/immagini/Pasted image 20221124092600.png|center|700]]

**...ancora un esempio...**
![[appunti asd/mod i/immagini/Pasted image 20221124092725.png|center|700]]

Cosa succede se visitiamo un BST in ordine simmetrico?

Ottengo: 2 3 4 6 7 9 13 15 17 18 20
Visito i nodi in ordine crescente di chiave!

**Verifica di correttezza**
Indichiamo con h l'altezza dell'albero
Vogliamo mostrare che la visita in ordine simmetrico restituisce la sequenza ordinata

Per induzione sull'altezza dell'ABR: h=1
![[appunti asd/mod i/immagini/Pasted image 20221124093205.png|center|600]]

h = generico(ipotizzo che la procedura sia corretta per altezza $\lt$ h)
![[appunti asd/mod i/immagini/Pasted image 20221124093307.png|center|600]]

### Implementare le op. del dizionario (search,insert,delete) su un BTS

#### Search(chiave k)->elemento

Traccia un cammino nell'albero partendo dalla radice: su ogni nodo,usa la proprietà di ricerca per decidere se proseguire nel sottoalbero sinisto o destro

**Pseudo-codice**
![[appunti asd/mod i/immagini/Pasted image 20221124093736.png|center|700]]

**Esempio**
Search(7)
![[appunti asd/mod i/immagini/Pasted image 20221124093858.png|center|600]]

Costo = $O(\text{altezza albero})$

#### Insert(elem e,chiave k)
**Idea**: aggiungere la nuova chiave come nodo foglia; per capire dove mettere la foglia simula una ricerca con la chiave da inserire

1. Crea un nuovo nodo u con elem = e e chiave=k
2. Cerca la chiave k nell'albero,identificando così il nodo v che diventerà padre di u
3. Appendi u come figlio sinistro/destro i v in modo che sia mantenuta la proprietà di ricerca

Costo = $O(\text{altezza albero})$

**Esempio**
Insert(e,8)
![[appunti asd/mod i/immagini/Pasted image 20221124095026.png|center|700]]

#### Qualche operazione ausiliaria prima dell'operazione delete

##### Ricerca del massimo
![[appunti asd/mod i/immagini/Pasted image 20221124095815.png|center|600]]

**Nota**: è possibile definire una procedura min(nodo u) in maniera del tutto analoga
>[!info]- Osservazione
>Non è sempre detto che il minimo/massimo sia una foglia nel BST

![[appunti asd/mod i/immagini/Pasted image 20221124095918.png|center|600]]

##### Predecessore e Successore

- Il **precedessore** di un nodo u in un BST è il nodo v nell'albero avente massima chiave $\leq$ chiave(u)
- Il **successore** di un nodo u in un BST è il nodo v nell'albero avente minima chiave $\geq$ chiave(u)

Come trovo il predecessore/successore di un nodo in un BST

**Ricerca del predecessore**
![[appunti asd/mod i/immagini/Pasted image 20221124100313.png|center|700]]

![[appunti asd/mod i/immagini/Pasted image 20221124100411.png|center|600]]

Nota: la ricerca del successore di un nodo è simmetrica

![[appunti asd/mod i/immagini/Pasted image 20221124101244.png|center|700]]

#### Delete(elem e)
Sia u il nodo contenente l'elemento e da cancellare:
1. u è una foglia:rimuvila
2. u ha un solo figlio: ![[appunti asd/mod i/immagini/Pasted image 20221124102324.png|center|600]]
3. u ha due figli : sostituiscilo con il predecessore (o successore) (v)  e rimuovi fisicamente il predecessore (o successore) (che ha al più un figlio)![[appunti asd/mod i/immagini/Pasted image 20221124102527.png|center|700]]
**Esempio**

![[appunti asd/mod i/immagini/Pasted image 20221124103024.png|center|700]]


#### Costo delle operazioni
- Tutte le operazioni hanno costo $O(h)$ dove h è l'altezza dell'albero
- $O(n)$ nel caso peggiore (alberi molto sbilanciati e profondi)

Con un albero binario di ricerca bilanciato: h=$O(log(n))$
![[appunti asd/mod i/immagini/Pasted image 20221124103301.png|center|700]]

Ma...
![[appunti asd/mod i/immagini/Pasted image 20221124103335.png|center|700]]

