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

>[!danger]- Esercizio 3-5

>[!important]- Teorema 1.1
>Se $\mathcal F$ è dimostrabile con il metodo dei *tableaux* allora è una tautologia.

## 2 Insiemi di Hintikka e completezza del metodo
>[!important]- Definizione 2.1 (Insiemi di Hintikka)
>Un insieme di formule S per cui valgono le tre proprietà seguenti si chiama insieme di Hintikka:
>	-$H_0$ : S non contiene sia una variabile p che la sua negata $\sim p$;
>	-$H_1$ : Se S contiene una $\alpha$-formula, allora S contiene anche entrambe le sue componenti $\alpha_1$ e $\alpha_2$ ;
>	-$H_2$ : Se S contiene una $\beta$-formula allora S contiene anche almeno una delle sue componenti $\beta_1$ e $\beta_2$ .

>[!danger]- Esercizi 6-7

>[!important]- Teorema 2.2 (*Completezza*)
>
> Se $\mathcal F$ è una tautologia allora è dimostrabile col metodo dei *Tableaux*
> 
> *Dimostrazione*: Se non fosse dimostrabile allora partendo da $\sim\mathcal F$ ed espandendo tutte le formule si otterrebbe un tableau completo con almeno un ramo aperto $\theta$. L’insieme delle formule sul ramo $\theta$ quindi sarebbe un insieme di Hintikka (per l’Esercizio 7). Ma ogni insieme di Hintikka è soddisfacibile (per l’Esercizio 6). Quindi in particolare sarebbe soddisfacibile la formula $\sim\mathcal F$, che è assurdo perché per ipotesi $\mathcal F$ è una tautologia. $\square$

## 3 Conclusioni
L’insieme delle tautologie è definito in termini *semantici* (una tautologia è una formula “vera” in ogni interpretazione). In questo episodio abbiamo analizzato il metodo dei *tableaux* e abbiamo visto che, facendo soltanto operazioni sintattiche sulle formule (applicazioni delle regole $\alpha$ e $\beta$) ci consente di decidere se una data formula è una tautologia oppure no. Perchè questo è importante per noi informatici? Beh, osservate che è difficile
spiegare a un computer come distinguere ciò che è vero da ciò che è falso, ma è facile fargli eseguire delle istruzioni. . .
Il metodo dei *tableaux* è un metodo di *refutazione*: per dimostrare che $\mathcal F$ è una tautologia, partiamo da $\sim\mathcal F$ e verifichiamo che non è soddisfacibile (si noti l’analogia con le dimostrazioni per assurdo).