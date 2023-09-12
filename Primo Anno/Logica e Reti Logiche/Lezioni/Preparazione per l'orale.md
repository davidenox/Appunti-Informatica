# Correttezza e completezza del metodo dei Tableaux
>[!important]-  Correttezza
>Se $\mathcal F$ è dimostrabile con il metodo dei tableaux allora è una tautologia.

>[!info]- Dimostrazione
>Se $F$ non fosse una tautologia, allora $¬F$ sarebbe soddisfacibile. Quindi ogni tableau che si ottiene da $¬F$ dovrebbe essere soddisfacibile . Ma questo è assurdo perché per ipotesi $F$ è dimostrabile col metodo dei tableaux, quindi c’è un tableau chiuso per $¬F$.

>[!important]- Completezza 
>Se F è una tautologia allora è dimostrabile con il metodo dei tableaux.

>[!info]- Dimostrazione 
>Se non fosse dimostrabile allora partendo da $¬F$ ed espandendo tutte le formule si otterrebbe un tableau completo con almeno un ramo aperto $θ$. L’insieme delle formule sul ramo $θ$ quindi sarebbe un insieme di Hintikka. Ma ogni insieme di Hintikka è soddisfacibile . Quindi in particolare sarebbe soddisfacibile la formula $¬F$, che è assurdo perché per ipotesi $F$ è una tautologia.

>[!important]- Insiemi di Hintikka
>Un insieme di formule S per cui valgono le tre proprietà seguenti si chiama *insieme di Hintikka*
>1. $H_0$ : S non contiene sia una variabile p che la sua negata ¬p;
>2. $H_1$ : Se S contiene una α-formula, allora S contiene anche entrambe le sue componenti $α_1$ e $α_2$;
>3. $H_2$ : Se S contiene una β-formula allora S contiene anche almeno una delle sue componenti $β_1$ e $β_2$.

