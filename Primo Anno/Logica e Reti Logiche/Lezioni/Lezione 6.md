# Sistemi assiomatici per la logica proposizionale
## 1 Sistemi assiomatici : pronti, partenza, ...
Una sistema formale consiste in *schemi di assiomi* e *regole di inferenza*, oltre che dell’insieme dei simboli che vengono usati e delle definizioni che stabiliscono quali sequenze di simboli sono “formula”. Nel caso della logica proposizionale gli schemi di assiomi sono un insieme di formule ben formate e le regole di inferenza sono relazioni di formule di questo tipo: *“Dalle formule $X_1 , . . . , X_n$ segue la formula $Y$ ”*. Vediamo subito un esempio.
Consideriamo i due assiomi seguenti:
$$\begin{align}
&A_1:X\Rightarrow (Y\Rightarrow X) \\ \\ &A_2:(X\Rightarrow (Y\Rightarrow Z))\Rightarrow((X\Rightarrow Y)\Rightarrow(X\Rightarrow Z))
\end{align}$$
>[!danger]- Esercizio 1
>Verificare che $A_1$ e $A_2$ sono tautologie.

La regola di inferenza che usiamo si chiama *Modus Ponens*: “Dalle formule $X$ e $X\Rightarrow Y$ segue la foruma $Y$ ”. In simboli la scriviamo cosı̀
$$\begin{align}
X,X\Rightarrow Y &\\----- &\\Y\space\space\space\space\space\space\space
\end{align}$$
In questi episodio chiamerò $\mathcal S_0$ il sistema assiomatico costituito dagli assiomi in $A_1$ e $A_2$ e dalla regola di inferenza Modus Ponens.
>[!danger]- Esercizi 2- 4

## 2 Teoremi e dimostrazioni
Abbiamo iniziato questo corso ponendoci la domanda “*Cos’è una dimostrazione?*”. Nell’ambito di un sistema assiomatico, possiamo darne una definizione precisa.
>[!important]- Definizione 2.1 (Dimostrazione) 
>In un sistema assiomatico $\mathcal S$, una dimostrazione è una sequenza di formule $\mathcal F_1 , . . . ,\mathcal F_n$ tale che ogni formula $\mathcal F_i$ o è un’istanza di un assioma, oppure si ottiene dalle formule precedenti della sequenza tramite una regola di inferenza.

>[!warning]- Esempio 

Consideriamo il nostro sistema $\mathcal S_0$ . Nel seguito la indicheremo con *M.P.* la
regola di inferenza *Modus Ponens*.$$\begin{align}
\\&(1)\space p\Rightarrow(q\Rightarrow p)\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[A_1\space con\space X = p, Y = q]
\\&(2)\space(p\Rightarrow(q\Rightarrow p))\Rightarrow((p\Rightarrow q)\Rightarrow(p\Rightarrow p))\space\space[A_2\space con\space X = p, Y = q, Z = p]
\\&(3)\space(p\Rightarrow q)\Rightarrow(p\Rightarrow p)\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[(1), (2)\space e\space M.P.]
\end{align}$$
La sequenza di formule (1), (2) e (3) qui sopra è una dimostrazione secondo la Definizione 2.1. Infatti, le formule (1) e (2) sono istanze di assiomi, e la formula (3) si ottiene dalle due formule precedenti usando la regola di inferenza Modus Ponens, dove abbiamo posto $X = (p\Rightarrow(q\Rightarrow p))$ e $Y = (p\Rightarrow q)\Rightarrow(p\Rightarrow p).$
A questo punto possiamo anche dire cos’è un *teorema* in un sistema assiomatico.
>[!important]- Definizione 2.2 (Teorema)
>In un sistema assiomatico, un teorema è l’ultima formula di una dimostrazione.


>[!danger]- Esercizio 5

## 3 Derivazioni e il Teorema di Deduzione
Un concetto che estende quello di dimostrazione è quello che chiamiamo *derivazione*.
>[!important]- Definizione 3.1 (Derivazione)
>Sia $\mathcal S$ un sistema assiomatico, sia $\mathcal F$ una formula e sia $\Gamma$ un insieme di formule. Diciamo che $\mathcal F$ deriva da $\Gamma$ nel sistema $\mathcal S$ se esiste una sequenza di formule $\mathcal F_1 , . . . , \mathcal F_n$ tali che $\mathcal F_n = \mathcal F$ e ognuna delle $\mathcal F_i$ , per $i = 1, . . . n$, o è un’istanza di un assioma, o si ottiene dalle formule precedenti della sequenza tramite una regola di inferenza, oppure è una delle formule dell’insieme $\Gamma$. La sequenza $\mathcal F_1 , . . . , \mathcal F_n$ si chiama derivazione di $\mathcal F$ da $\Gamma$. Le formule in $\Gamma$ sono le ipotesi della derivazione. 
>Introduciamo anche un po’ di simboli. Quando una formula $\mathcal F$ deriva da un insieme $\Gamma$ in un sistema assiomatico $\mathcal S$ scriviamo $\Gamma\vdash_\mathcal S \mathcal F$. Quando il sistema $\mathcal S$ di cui stiamo parlando è chiaro dal contesto lo omettiamo e scriviamo semplicemente $\Gamma\vdash\mathcal F$.

>[!warning]- Esempio

Consideriamo sempre il nostro sistema $\mathcal S_0$ e facciamo vedere che la formula
$p\Rightarrow r$ deriva dalle formule $p\Rightarrow q$ e $q\Rightarrow r$. In simboli$$p\Rightarrow q, q\Rightarrow r\vdash p\Rightarrow r $$
Chiamiamo $p\Rightarrow q$ e $q\Rightarrow r$ rispettivamente *Ipotesi 1* e *Ipotesi 2*.
$$\begin{align}&
(1)\space(p\Rightarrow(q\Rightarrow r))\Rightarrow((p\Rightarrow q)\Rightarrow(p\Rightarrow r))\space\space\space\space\space\space\space\space\space\space[A_2\space con\space X = p, Y = q, Z = r] \\&
(2)\space(q\Rightarrow r)\Rightarrow(p\Rightarrow(q\Rightarrow r))\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[A_1\space con\space X = (q\Rightarrow r), Y = p]\\&
(3)\space q\Rightarrow r\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[Ipotesi\space 2]\\&
(4)\space p\Rightarrow(q\Rightarrow r)\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[(3), (2)\space e\space M.P.]\\&
(5)\space(p\Rightarrow q)\Rightarrow(p\Rightarrow r)\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[(4), (1)\space e\space M.P.]\\&
(6)\space p\Rightarrow q\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[Ipotesi\space 1]\\&
(7)\space p\Rightarrow r\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space\space[(6), (5)\space e\space M.P.]\\&
\end{align}$$
La sequenza di formule $(1), . . . , (7)$ qui sopra è una derivazione della formula $p\Rightarrow r$ dall’insieme di formule $\{p\Rightarrow q, q\Rightarrow r\}$. Le formule $(1)$ e $(2)$ sono istanze di assiomi, $(3)$ e $(6)$ sono le ipotesi, $(4)$, $(5)$ e $(7)$ seguono da formule precedenti tramite *Modus Ponens*.
>[!danger]- Esercizi 6-9

>[!important]- Teorema 3.2 (Deduzione)
>Sia $\Gamma$ un insieme di formule e siano $\mathcal F$ e $\mathcal G$ due formule. Nel sistema $\mathcal S_0$ se $\Gamma\cup\{\mathcal F\}\vdash\mathcal G$ allora $\Gamma\vdash\mathcal F\Rightarrow\mathcal G$.

## 4 Conclusioni
In questo episodio abbiamo introdotto i *sistemi assiomatici* per la logica proposizionale.
Osservate che dall’Esercizio 2 segue che in un qualunque sistema assiomatico in cui gli schemi di assiomi sono tautologie e la regola di inferenza è Modus Ponens, tutti i teoremi sono tautologie. Il nostro sistema $\mathcal S_0$ quindi è *corretto*. Sarà anche *completo*? Cosı̀ com’è adesso, no, non è completo. Ma è sufficiente aggiungere uno schema di assioma per
rendelo completo, per esempio questo:$$A_3 :(\neg X\Rightarrow \neg Y )\Rightarrow((\neg X\Rightarrow\neg Y )\Rightarrow X)$$
Se chiamiamo $\mathcal S_1$ il sistema assiomatico formato dagli assiomi $A_1$ , $A_2$ , e $A_3$ e dalla regola di inferenza Modus Ponens, si può infatti dimostrare che ogni tautologia è un teorema nel sistema $\mathcal S_1$ . 
>[!danger]- Esercizio 10

