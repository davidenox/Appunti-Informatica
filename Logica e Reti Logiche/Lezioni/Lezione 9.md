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

