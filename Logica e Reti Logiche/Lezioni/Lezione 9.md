# Correttezza e completezza del metodo dei *tableaux* per la Logica del Primo Ordine
## 1 Formule soddisfacibili e correttezza del metodo
Per dimostrare la correttezza del metodo dei tableaux è utile dare un nome alle formule che hanno almeno una interpretazione in cui sono T.
>[!important]- Definizione 1.1 (Formule e insiemi di formule soddisfacibili).
>Una formula F è soddisfacibile se esiste una interpretazione in cui F è T. Un insieme S di formule è soddisfacibile se esiste una interpretazione in cui tutte le formule di S sono T.

>[!danger]- Esercizio 1 
>Osservare che una formula $F$ è soddisfacibile se e solo se $\lnot F$ non è valida.

>[!danger]- Esercizio 2 
>Fare un esempio di formula soddisfacibile e un esempio di formula non soddisfacibile. Per la formula soddisfacibile, esibire una interpretazione in cui è T, per quella non soddisfacibile dare una spiegazione intuitiva del perché non può esistere una interpretazione in cui è T. Se I è una interpretazione in cui la formula F è T diremo anche che I soddisfa F. Diremo che I soddisfa l’insieme S se I soddisfa tutte le formule in S.

>[!danger]- Esercizio 3
>Mostrare che l’insieme $$S = \{\exists x[P(x)\wedge Q(x)],\forall x[P(x)\vee Q(x)],\lnot\forall xP(x), \lnot\forall xQ(x)\}$$
>è soddisfacibile esibendo una interpretazione che soddisfa S. Si ricordi che una formula $F$ si dice dimostrabile col metodo dei tableaux se esiste un tableau chiuso che parte da $\lnot F$.

>[!important]- Teorema 1.2 (Correttezza) 
>Se una formula F è dimostrabile col metodo dei tableaux allora è valida.

- Idea della dimostrazione. 
Per dimostrare che se F è dimostrabile col metodo dei tableaux allora F è valida, dimostreremo che se F non è valida allora F non è dimostrabile col
metodo dei tableaux. Possiamo schematizzare la dimostrazione in questi tre passaggi:
1. Se F non è valida, allora ¬F deve essere soddisfacibile. (Segue direttamente dalle definizioni di formula valida e formula soddisfacibile) .
2. Se ¬F è soddisfacibile, allora non è possibile ottenere un tableau chiuso a partire da ¬F. (Questo è il passaggio cruciale. Spezziamolo in due passaggi.)
	1. Se ϑ è un ramo chiuso di un tableau, allora l’insieme Sϑ , formato da tutte le formule sul ramo ϑ, non è soddisfacibile;(Se ϑ è chiuso allora in Sϑ deve esserci sia una formula che la sua negata.)
	2. Se ¬F è soddisfacibile e uso le regole α, β, γ e δ per costruire un tableau a partire da ¬F, allora nel tableau che costruisco ci sarà sempre un ramo ϑ tale che l’insieme Sϑ , formato da tutte le formule sul ramo ϑ, è soddisfacibile. (Questo viene dal significato semantico delle regole di estensione del tableaux:lo dimostriamo nel successivo Lemma 1.3)
3. Quindi se ottengo un tableau chiuso a partire da ¬F allora F deve essere valida.
Segue direttamente dai punti 1 e 2.)
Ci manca un solo pezzo per completare il puzzle: dobbiamo dimostrare il punto (2.2).
>[!important]- Lemma 1.3 
>Sia S un insieme di formule soddisfacibile e sia F una formula in S. Se F è una 
>(a) α-formula, allora anche l’insieme S ∪ {α1 , α2 } è soddisfacibile;
>(b) β-formula, allora almeno uno dei due insiemi S ∪ {β1 } e S ∪ {β2 } è soddisfacibile;
>(c) γ-formula, allora anche l’insieme S ∪ {γ(a)} è soddisfacibile, quaunque sia il parametro a;
>(d) δ-formula, allora anche l’insieme S ∪ {δ(a)} è s

>[!danger]-  Esercizi 4-7

