# Il metodo dei *tableaux* per la Logica del Primo Ordine
## 1 Le regole per i quantificatori
Abbiamo visto che possiamo classificare essenzialmente tutte le formule della logica proposizionale in due tipi: $\alpha$-formule (quelle di tipo $AND$) e $\beta$-formule (quelle di tipo $OR$):
![[Pasted image 20230426101527.png|center]]

Ad ogni formula corrisponde una regola di estensione nei *tableaux*:
![[Pasted image 20230426101616.png|center|400]]

Nella logica del primo ordine, in aggiunta alle $\alpha$-formule e $\beta$-formule, abbiamo anche le formule che coinvolgono i quantificatori: per esempio, $\forall xP(x)$ e $\exists xP(x)$. Quali saranno le regole di estensione dei tableaux per questi tipi di formule? Vediamo.
![[Pasted image 20230426101756.png|center]]

La **prima** traduce il ragionamento seguente: se è vero che la proprietà $P$ vale per ogni elemento del dominio (ossia, $\forall xP (x)$) allora prendiamo un elemento a per cui la proprietà $P$ vale (ossia, $P(a)$). 
La **seconda**, questo: se è vero che deve esistere un elemento del dominio per cui vale la proprietà $P$ (ossia, $\exists xP(x)$), allora prendiamo un elemento a per cui la proprietà $P$ vale (ossia, $P(a)$). Entrambi i ragionamenti sembrano corretti. Allora, cos’è che manca?
Quando incontriamo per la prima volta una formula del tipo $\exists xP(x)$ e aggiungiamo $P(a)$ al nostro *tableau*, questo è perfettamente legittimo, per il ragionamento che abbiamo fatto sopra. 
Ma immaginate che poi nel nostro percorso di scomposizione troviamo un’altra formula del tipo $\exists xQ(x)$. È legittimo aggiungere al nostro tableau $Q(a)$? Beh, riflettete un attimo sul fatto che la risposta è no, non è legittimo: perché anche se esiste un elemento del dominio per cui vale la proprietà $Q$, questo elemento non è necessariamente lo stesso per cui vale la proprietà $P$. Quindi in questo caso dobbiamo *istanziare* la proprietà $Q$ su un altro elemento, diciamo $b$.
E se dopo aver esteso $\exists xP(x)$ con $P(a)$ incontriamo una formula del tipo $\forall xQ(x)$? Abbiamo lo stesso problema? Beh, no, perché siccome $Q$ vale per tutti gli elementi del dominio, varrà anche per l’elemento a per cui vale la proprietà $P$.
Quindi, possiamo completare le nostre regole in questo modo:
![[Pasted image 20230426102421.png|center]]

Oltre a quelle qui sopra, dobbiamo stabilire altre due regole: una per $\lnot\exists xP (x)$ l’altra per $\lnot\forall xP(x)$.
>[!danger]- Esercizio 1 
>Prima di procedere è utile fermarsi un attimo e ragionare intuitivamente su quali dovrebbero essere le regole per $\lnot\exists xP (x)$ e $\lnot\forall xP (x)$.

Osservate che le formule $\forall xP(x)$ e $\lnot\exists xP$ (x) sono di tipo **universale**, cioè si riferiscono a tutti gli elementi del dominio. Invece le formule $\exists xP(x)$ e $\lnot\forall xP(x)$ sono di tipo **esistenziale**, cioè si riferiscono ad almeno uno degli elementi del dominio.
In analogia con quanto fatto per le formule della logica proposizionale, possiamo quindi classificare le formule della logica del primo ordine che coinvolgono i quantificatori in due categorie: 
1. Le $\gamma$-formule (quelle di tipo *universale*);
2. Le $\delta$-formule (quelle di tipo *esistenziale*); 
Con le relative regole di estensione dei *tableaux*.
![[Pasted image 20230426105150.png|center]]

Come nel caso della logica proposizionale, diciamo che *un ramo di un tableau è **chiuso** se sul ramo c’è sia una formula che la sua negata*. Diciamo che *un tableau è **chiuso** se tutti i suoi rami sono chiusi* e diciamo che *una formula $F$ è **dimostrabile col metodo dei tableaux** se partendo da $\lnot F$ e applicando le regole per le $\alpha$, $\beta$, $\gamma$ e $\delta$ formule riusciamo a ottenere un tableau chiuso*.
## 2 Esempi
>[!warning]- Esempio 1

Consideriamo la formula $$\forall xP(x)\rightarrow\exists xP(x)$$
Nell’episodio precedente, ragionando intuitivamente abbiamo osservato che è impossibile trovare una interpretazione che la rende falsa, quindi la formula è valida. Facciamo vedere che è dimostrabile col metodo dei tableaux:
![[Pasted image 20230426105654.png|center]]

Le formule (2) e (3) vengono dalla (1) applicando la regola $\alpha$, la (4) viene dalla (2) tramite la regola $\gamma$ e la (5) dalla (3) sempre tramite la regola $\gamma$. La (4) e la (5) sono in coddraddizione quindi il tableau, che ha un unico ramo, è **chiuso**.
>[!warning]- Esempio 2

Consideriamo un’altra formula che abbiamo già incontrato $$\exists x(P(x)\wedge Q(x))\rightarrow\exists xP(x)\wedge\exists xQ(x)$$
Se avete svolto l’Esercizio 4 dell’episodio precedente, dovreste già avere un’idea intuitiva del perché questa formula deve essere valida. Qui vediamo che è dimostrabile col metodo dei *tableaux*.
![[Pasted image 20230426110110.png|center]]

Le formule (2) e (3) vengono da (1) (regola $\alpha$), la (4) dalla (2) (regola $\delta$), (5) e (6) da (4) (regola $\alpha$), (7) e (8) da (3) (regola $\beta$), infine (9) e (10) da (7) e (8) rispettivamente (entrambe regole $\gamma$). Le formule (9) e (5) sono in contraddizione, cosı̀ come le formule (10) e (6). Quindi entrambi i rami sono chiusi. La formula è dimostrata.
>[!warning]- Esempio 3

Consideriamo la formula $$\exists y[P(y)\rightarrow\forall xP(x)]$$
Pensate che sia valida oppure no? Intanto vediamo che è dimostrabile:
![[Pasted image 20230426111531.png|center]]

La (2) viene dalla (1) (regola $\gamma$), (3) e (4) vengono dalla (2) (regola $\alpha$). La (5) viene dalla (4) (regola $\delta$), ma osservate che non ho potuto mettere $\lnot P(a)$ e trovare una contraddizione con la (3), perché la (4) è di tipo $ESISTENZIALE$, quindi devo usare un parametro che non ho già usato prima. Quindi? Il tableau non si chiude e la formula non è dimostrabile?
La formula (1) è di tipo $UNIVERSALE$, quindi posso *riusarla* con un altro parametro
![[Pasted image 20230426111531.png|center]]
![[Pasted image 20230426111908.png|center]]

La (6) viene dalla (1), la (7) e la (8) vengono dalla (6) e non c’è bisogno di proseguire sviluppando la (8) perché la (7) e la (5) sono in contraddizione e il tableau è *chiuso*.
>[!danger]-  Esercizi 2-6

## Conclusioni
In questo episodio abbiamo visto come si estende il metodo dei *tableaux* alla logica del primo ordine. Dobbiamo dimostrare che il metodo è **corretto** (ogni formula dimostrabile col metodo dei *tableaux* è $valida$) e **completo** (ogni formula valida è $dimostrabile$ col metodo dei *tableaux*).
