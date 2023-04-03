# Correttezza e completezza del metodo dei tableaux
## 1 Insiemi soddisfacibili e correttezza del metodo
Diciamo che una formula $\mathcal F$ è soddisfacibile se esiste una interpretazione in cui è T (osservate che una formula è soddisfacibile se e solo se è o una tautologia o una contingenza).
Diciamo che un insieme S di formule è soddisfacibile, se esiste una interpretazione in cui tutte le formule di S sono T.
>[!danger]- Esercizio 1
> Dire se il seguente insieme S di formule è soddisfacibile, motivando adeguatamente la risposta
> $$S = \{p \Rightarrow q, p \Rightarrow \sim q, q \Rightarrow p\}$$

Nell’episodio precedente abbiamo visto che una formula F della logica proposizionale può essere soltanto di due tipi: una $\alpha$-formula o una $\beta$-formula (con una eccezione, l’equivalenza $\equiv$, che però abbiamo visto che può essere spezzata a sua volta in due formule, una di tipo $\beta$ e una di tipo $\alpha$).
![[Pasted image 20230403111226.png|center]]

Se F è una $\alpha$-formula (rispettivamente, $\beta$-formula) chiamiamo le formule $\alpha_1$ e $\alpha_2$ (rispettivamente, $\beta_1$ e $\beta_2$ ) le componenti della formula $\mathcal F$.
>[!danger]- Esercizio 2
> Sia S il seguente insieme di formule
> $$S = \{\sim(p \vee q), p \Rightarrow q\}$$
> 1. Verificare che S è soddisfacibile;
> 2. Osservare che la prima formula $[\sim(p\vee q)]$ è una $\alpha$-formula, mentre la seconda $[p \Rightarrow q]$ è una $\beta$-formula; 
> 3. Verificare che l’insieme S' che otteniamo da S aggiungendo entrambe le componenti della α-formula è ancora soddisfacibile $$ S' = S \cup \{\sim p, \sim q\} = \{\sim(p \vee q), p \Rightarrow q, \sim p, \sim q\}$$
> 4. Verificare che almeno uno dei due insiemi $S_1'$ e $S_2'$ che otteniamo da S aggiungendo rispettivamente la prima e la seconda componente della $\beta$-formula è soddisfacibile.$$\begin{align} \\& S_1'=S\cup\{\sim p\}=\{\sim(p\vee q),p\Rightarrow q, \sim p\} \\& S_2'=S\cup\{q\}=\{\sim(p\vee q),p\Rightarrow q, q\} \end{align}$$

>[!danger]- Esercizio 3

>[!important]- Teorema 1.1
>Se $\mathcal F$ è dimostrabile con il metodo dei *tableaux* allora è una tautologia.

