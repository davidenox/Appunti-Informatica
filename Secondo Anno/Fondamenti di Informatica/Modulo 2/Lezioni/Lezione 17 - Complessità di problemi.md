# Complessità di problemi
## Complessità di problemi e codifica
>[!info]
>Siamo pronti ad affrontare il paragrafo 7.5

Ci eravamo riproposti di estendere ai problemi quello che abbiamo studiato relativamente alla complessità di linguaggi, a patto, come abbiamo chiarito, di utilizzare codifiche ragionevoli per codificare le istanze dei problemi.
Resta da capire come trasformare un problema in un linguaggio!
E se questa trasformazione è indolore o se ci costringe a considerare qualche nuova questione…
## Da problema a linguaggio
Sia  $\Gamma=\langle\mathcal I_\Gamma, S,\pi_\Gamma\rangle$ un problema decisionale. 
Osserviamo che l’insieme $\mathcal I_\Gamma$ delle istanze di $\Gamma$ è partizionato in due sottoinsiemi:
1. l’insieme delle **istanze sì** – ossia le istanze che verificano $\pi_\Gamma$;
2. l’insieme delle **istanze no** - ossia le istanze che $non$ verificano $\pi_\Gamma$. 
Sia $\chi:\mathcal I_\Gamma\rightarrow\Sigma^*$ una codifica (ragionevole) per $\Gamma$. 
La codifica $\chi$ partiziona $\Sigma^*$ in *tre* sottoinsiemi di parole: 
1. l’insieme $Y_\Gamma$ delle parole che codificano istanze sì di $\Gamma$; 
2. l’insieme $N_\Gamma$ delle parole che codificano istanze no di $\Gamma$; 
3. l’insieme delle parole che *non* codificano istanze di $\Gamma$. 
Il linguaggio associato a $\Gamma$ mediante la codifica $\chi$ è il sottoinsieme $L_\Gamma(\chi)$ di $\Sigma^*$  *contenente le parole appartenenti a* $Y_\Gamma$,ossia, $$L_\Gamma(\chi)=\{x\in\Sigma^*:\exists y\in\mathcal I_\Gamma[x=\chi(y)\land\pi_\Gamma(y, S_\Gamma(y))]\}$$
Dunque, decidere se una istanza $y$ di $\Gamma$ è una istanza sì corrisponde a decidere se $x=\chi(y)$ è contenuto in $L_\Gamma(\chi)$.
E, d’altro canto, data $x\in\Sigma^*$, per decidere se $x\in L_\Gamma(\chi)$ occorre:
1. decidere se $x$ è la codifica di un’istanza $y$ di $\Gamma$; 
2. e poi, in caso affermativo, decidere se il predicato $\pi_\Gamma(y,S_\Gamma(y))$ è soddisfatto.
## Complessità di un problema
A questo punto, possiamo definire la complessità computazionale di un problema decisionale. 
>[!important]- Definizione 7.3
> Sia $\Gamma=\langle\mathcal I_\Gamma, S,\pi_\Gamma\rangle$ un problema decisionale e sia $C$ una classe di complessità.
> Data una funzione $f$ totale e calcolabile: 
> $C\in\{ DTIME[f(n)] , DSPACE[f(n)] , NTIME[f(n)] , NSPACE[f(n)] \}$

Diciamo che $\Gamma\in C$ **se esiste una codifica ragionevole** $\chi:\mathcal I_\Gamma\rightarrow\Sigma^*$ per $\Gamma$ **tale che** $L_\Gamma(\chi)\in C$. 

Vediamo ora con un esempio cosa occorre fare per decidere se $x\in L_\Gamma(\chi)$, e, quindi, da cosa è caratterizzata la complessità di un **problema** e in cosa si differenzia lo studio della complessità di problemi dallo studio della complessità di linguaggi.
## Decidere un problema
>[!info] 
>Esempio 7.6 

Ricordiamo il problema **3SAT** e la codifica $\chi_1$: 
1. se $X = \{x_1, x_2, x_3\}$ e $f=c_1\land c_2$ con $c_1=x_1\lor x_2\lor x3$ e $c_2 = x_1\lor\lnot x_2\lor\lnot  x_3$ allora $\chi_1(X,f) =$ 444 0 100 2 0 010 2 0 001 3 0 100 2 1 010 2 1 001
2. che abbiamo visto essere una codifica ragionevole
Allora, una parola $x\in\{0,1, 2, 3, 4\}^*$ è in $L_{3SAT}(\chi_1)$ se sono verificati i due fatti seguenti: 
1) $x$ deve essere la codifica secondo $\chi_1$ di qualche coppia $\langle X,f \rangle$ istanza di **3SAT**: 
		ad esempio, è facile verificare che 4021011103240111 non è la codifica di alcuna istanza
		Se $x$ non è una codifica valida, possiamo subito concludere che $x\not\in L_{3SAT} (\chi_1 )$ . 
2)  Se $x$ è la codifica secondo $\chi_1$ di una istanza $\langle X,f\rangle$ di 3SAT, affinché $x\in L_{3SAT}(\chi_1)$ occorre che $f$ sia soddisfacibile. 
Ossia, come abbiamo visto, dati un problema $\Gamma$ e una sua codifica ragionevole $\chi$, per verificare che una parola sia in $L_\Gamma(\chi)$ **occorre innanzi tutto verificare che essa sia la codifica di una istanza**.
## Il linguaggio delle istanze
Dato un problema ed una codifica ragionevole $\chi:\mathcal I_Gamma\rightarrow\Sigma^*$ per $\mathcal I_\Gamma$, 
definiamo il **linguaggio delle istanze di** $\Gamma$, ossia, il linguaggio $$\chi(\mathcal I_\Gamma)=\{x\in\Sigma^*:\exists y\in\mathcal I_\Gamma[x=\chi(y)]\}$$
>[!note]- OSSERVAZIONE 
> 1. $\chi$ è una codifica di $\mathcal I_\Gamma$ 
> 2. quindi, se $y,z\in\mathcal I_\Gamma$ sono due istanze di $\Gamma$ con $y\not=z$, allora $\chi(y)\not=\chi(z)$ 
> 3. quindi $\chi$ è una funzione **invertibile**
> Allora, possiamo definire il linguaggio $L_\Gamma(\chi)$ anche nella maniera seguente:
 $L_\Gamma(\chi)=\{x\in\Sigma^*:x\in\chi(\mathcal I_\Gamma)\land\pi_\Gamma(\chi^{-1}(x),S_\Gamma(\chi^{-1}(x)))\}$

Dunque, se, per decidere se una parola $x$ appartiene a $L_\Gamma(\chi)$ dobbiamo anche verificare se $x$ è effettivamente la codifica di un’istanza di $\Gamma$, allora per definire la complessità del problema decisionale occorre considerare anche la complessità di decidere il linguaggio $\chi(\mathcal I_\Gamma)$.
## Esempio 7.7
Consideriamo un nuovo problema decisionale PHC (Percorso in Ciclo Hamiltoniano): 
Sia dato un particolare grafo non orientato $G=(V,E)$.
>[!info]
>G è un grafo particolare: contiene un ciclo che passa una ed una sola volta per ciascuno dei suoi nodi (**ciclo hamiltoniano**).

Siano dati, inoltre, due suoi nodi $u, v\in V$ ; 
Si chiede di decidere se esiste in G un percorso che collega $u$ a $v$.
Formalizziamo il problema precedente mediante la tripla  $\langle \mathcal I_{PHC}, S_{PHC},\pi_{PHC}\rangle$ : 
1. $\mathcal I_{PHC}=\{\langle G=(V,E),u,v\rangle$ : G è un grafo non orientato $\land$ un ciclo c in G che passa una e una sola volta attraverso ciascun nodo di G $\land$ $u,v\in V\}$; 
2. $S_{PHC}(G,u,v) = \{ p : p$ è un percorso in $G \}$; 
3. $\pi_{PHC}(G,u,v,S_{PHC}(G,u,v))=\exists p\in S_{PHC}(G,u,v)$  che connette $u$ a $v$. 
*ATTENZIONE*: Se sappiamo che un grafo contiene un ciclo che passa (una e una sola volta) attraverso tutti i nodi di G, allora, qualunque coppia di nodi $u,v$ si consideri, una porzione di quel ciclo è un percorso da $u$ a $v$. 
Questo significa che ogni istanza del problema PHC è una istanza sì. 
## Linguaggio delle istanze e complessità
Ogni istanza del problema PHC è una istanza sì. 
Quindi, indipendentemente dalla codifica utilizzata, decidere se una qualunque istanza del problema soddisfa il predicato del problema richiede costo costante. D’altra parte, data una qualunque codifica ragionevole (diciamo, binaria)  per PHC, per decidere se una parola $x\in\{0,1\}^*$  è contenuta in $L_{PHC}(\chi)$, dobbiamo verificare: 
1. sia se x è la codifica di una istanza di PHC, ossia, di un grafo che contiene un ciclo che attraversa tutti i nodi una e una sola volta e di una coppia di suoi nodi;
2. sia se detto grafo contiene un percorso che connette i due nodi. 
Come vedremo, la prima di queste due verifiche (ossia decidere $\chi(\mathcal I_{PHC})$) è un noto linguaggio NP-completo.
E, quindi, concludiamo che $L_{PHC}(\chi)$ è NP-completo. 
Allora, anche se, *una volta assodato che una parola $x\in\{0,1\}^n$  è istanza di PHC*, decidere se x soddisfa $\pi_{PHC}(G,u,v, S_{PHC}(G,u,v))$ ha costo costante.
Non possiamo affermare che decidere PHC è un problema in P.
## Da un problema al suo complemento
Sia $\Sigma$ un qualunque alfabeto finito. Una qualunque codifica $\chi$ delle istanze di un problema decisionale $\Gamma$ in parole di $\Sigma^*$ induce una tri-partizione di $\Sigma*$ - ossia, una partizione di $\Sigma*$ in tre sottoinsiemi:
1. L’insieme $Y_\Gamma$ delle parole di $\Sigma^*$ che codificano istanze sì di $\Gamma$ -  il linguaggio $L_\Gamma(\chi)$; 
2. L’insieme $N_\Gamma$ delle parole di $\Sigma^*$ che codificano istanze no di $\Gamma$ ;  
3. Parole di $\Sigma^*$ che non codificano istanze di $\Gamma$ ;  
Ora, ricordiamo, dato un qualunque linguaggio $L\subseteq\Sigma^*$, il linguaggio complemento di L è : $L^c = \Sigma^* - L$. È così che lo avevamo definito!
Perciò, secondo definizione, il linguaggio complemento di $L_\Gamma(\chi)$ è	$(L_\Gamma(\chi))^c =\Sigma^*-L_\Gamma(\chi)$ , ossia, tutte le parole di $\Sigma^*$ che codificano istanze no di $\Gamma$ e tutte le parole di $\Sigma^*$ che non codificano istanze di $\Gamma$.
Ma siamo sicuri che questo è proprio ciò che corrisponde al complemento di un problema decisionale?
In effetti, se pensiamo al complemento di un problema di decisione, quello che ci viene in mente sono *le istanze del problema che non soddisfano il predicato*.
Ad esempio, il problema $3SAT^c$ è l’insieme delle istanze $\langle X,f \rangle$ di 3SAT tali che f *non* è soddisfacibile. Formalmente, $3SAT^c=\langle\mathcal I_{3SAT}, S_{3SAT}, \lnot \pi_{3SAT}\rangle$. 
Perciò, il linguaggio che vogliamo associare al problema complemento di $\Gamma$ non è $(L_\Gamma(\chi))^c=\Sigma^*-L_\Gamma(\chi)$ , bensì l’insieme $N_\Gamma$ , $$L_\Gamma^c(\chi)=\{x\in\Sigma^*:x\in\chi(\mathcal I_\Gamma)\land\lnot\pi(\chi^{-1}(x),S_\Gamma(\chi^{-1}(x)))\}$$						
ossia, formalmente (per gli interessati), $L_\Gamma^c(\chi)=L_\Gamma^c(\chi)-\chi^c(\mathcal I_\Gamma)$.
Dunque, il linguaggio che associamo al complemento di un problema decisionale $\Gamma$ (codificato in $\Sigma^*$ secondo una codifica $\chi$ ) non è $(L_\Gamma(\chi))^c=\Sigma* - L_\Gamma(\chi)$ ma $L_\Gamma^c(\chi)$.  
Ora, dato un linguaggio L ed una classe di complessità $\mathcal C$ , noi sappiamo (per definizione) che se $L\in\mathcal C$   allora $L^c\in co\mathcal C$.
Perciò, dato un problema decisionale $\Gamma$ (codificato in $\Sigma^*$ secondo una codifica $\chi$ ), noi sappiamo che se $L_\Gamma(\chi)\in\mathcal C$  allora $(L_\Gamma(\chi))^c\in co\mathcal C$.
Ma, se sappiamo che se $L_\Gamma(\chi)\in\mathcal C$  , cosa possiamo dire del linguaggio $L_\Gamma^c(\chi)$?
Ossia: se sappiamo classificare (nell’ambito della complessità computazionale) un problema di decisione , sappiamo anche classificare il problema complemento?
Vediamo un esempio

>[!warning]- Esempio 7.8 
>Riprendiamo dall’esempio 7.7 il problema decisionale PHC: dato un grafo non orientato $G=(V,E)$ che contiene un ciclo che passa una ed una sola volta per ciascuno dei suoi nodi, e dati due suoi nodi $u, v\in V$, si chiede di decidere se esiste in G un percorso che collega u a v.

PHC è formalizzato mediante la tripla $\langle\mathcal I_{PHC}, S_{PHC},\pi_{PHC}\rangle$ : 
1. $\mathcal I_{PHC}=\{\langle G = (V,E), u, v\rangle:G$ è un grafo non orientato $\land\exists$ un ciclo c in G che passa una e una sola volta attraverso ciascun nodo di $G\land u,v\in V$}; 
2. $S_{PHC}(G,u,v)=\{p:p$ è un percorso in G }; 
3. $\pi_{PHC}(G,u,v, S_{PHC}(G,u,v))=\exists p\in S_{PHC}(G,u,v)$ che connette u a v. 
$PHC^c$ è, allora: 
1. dato un grafo non orientato $G=(V,E)$ che contiene un ciclo che passa una ed una sola volta per ciascuno dei suoi nodi, e dati due suoi nodi $u, v\in V$ ; 
2. si chiede di decidere se *non* esiste in G alcun percorso che collega u a v.
Ed è formalizzato mediante la tripla  $\langle\mathcal I_{PHC},S_{PHC},\pi_{PHC}\rangle$ , con $\lnot\pi_{PHC}(G,u,v, S_{PHC}(G,u,v))=\not\exists p\in S_{PHC}(G,u,v)$ *che connette u a v*. 
Formalizzato il problema precedente mediante la tripla  $\langle\mathcal I_{PHC}, S_{PHC},\lnot\pi_{PHC}\rangle$  : 
1. $\mathcal I_{PHC}=\{\langle G = (V,E), u, v\rangle : G$ è un grafo non orientato $\land\exists$ un ciclo c in G che passa una e una sola volta attraverso ciascun nodo di $G\land u,v\in V\}$; 
2. $S_{PHC}(G,u,v)=\{p:p$è un percorso in $G \}$; 
3. $\pi_{PHC}(G,u,v, S_{PHC}(G,u,v)) =\not\exists p\in S_{PHC}(G,u,v)$ che connette $u$ a $v$. 
Data una qualunque codifica ragionevole $\chi$ per $PHC^c$, per decidere se una parola x è contenuta in $L_{PHC^c}(\chi)$, dobbiamo verificare : 
1. se x è la codifica di una istanza di $PHC^c$, ossia, di un grafo che contiene un ciclo che attraversa tutti i nodi una e una sola volta, e di una coppia di suoi nodi, 
2. e se detto grafo non contiene percorsi che connettono i due nodi. 
Come abbiamo visto, la verifica che x sia effettivamente la codifica di un’istanza di PHC è un problema NP-completo, e verificare se una qualunque istanza del problema soddisfa il predicato del problema richiede costo costante – perché nessuna istanza soddisfa il predicato.
E, quindi, concludiamo (ad occhio) che $PHC^c$ è NP-completo. 
Riassumiamo: il problema $PHC$ è NP-completo, e il suo complemento $PHC^c$ è anch’esso NP-completo. 																					Quindi parrebbe che *non* possiamo trasportare ai problemi decisionali la teoria della complessità che abbiamo sviluppato per i linguaggi.
E questo perché **la complessità di un problema decisionale dipende anche dalla complessità di decidere il linguaggio delle istanze**.
Ma *se la decisione del linguaggio delle istanze richiede “poche risorse”* possiamo trasferire tutto ciò che abbiamo studiato relativamente alla complessità dei linguaggi alla complessità dei problemi decisionali, come mostra il prossimo teorema.
## Il ruolo del linguaggio delle istanze
>[!important]- Teorema 7.1 
>Sia $\Gamma =\langle\mathcal I_\Gamma, S_\Gamma,\pi_\Gamma\rangle$ un problema decisionale e sia $\chi:\mathcal I_\Gamma\rightarrow\Sigma^*$ una sua codifica ragionevole. Se $\chi(\mathcal I_\Gamma)\in P$ , allora valgono le seguenti implicazioni: 
>1) se $L_\Gamma(\chi)\in NP$  allora $L^c_\Gamma(\chi)\in coNP$ ;
>2) se $L_\Gamma(\chi)\in NEXPTIME$  allora $L^c_\Gamma(\chi)\in coNEXPTIME$

**Dimostriamo il Teorema 7.1 nel caso 1)**

### Teorema 7.1 - Caso 1)

Se $\chi(\mathcal I_\Gamma)\in P$ , allora esistono una macchina deterministica T ed un intero h tali che, per ogni $x\in\Sigma^*$ , T decide se $x\in L_\Gamma(\chi)$ e $dtime(T,x)\in O(|x|^h )$. 
Se $L_\Gamma(\chi)\in NP$, allora esistono una macchina non deterministica NT ed un intero k tali che, per ogni $x\in L_\Gamma(\chi)$ , NT accetta x e $ntime(NT, x)  \in O(|x|^k)$. 
Combinando T e NT, **costruiamo una nuova macchina non deterministica $NT_0$ che accetta il linguaggio complemento di $L^c_\Gamma(\chi)$**, ossia, che **accetta** $(L^c_\Gamma(\chi))^C$.
Due domande sorgono spontanee:
1. Qual è l'importanza di accettare $(L^c_\Gamma(\chi))^C$ ?
Beh, se riusciamo a mostrare che possiamo accettare $(L^c_\Gamma(\chi))^C$ in tempo non deterministico polinomiale, allora $(L^c_\Gamma(\chi))^C$ è in NP e, dunque, $L^c_\Gamma(\chi)\in coNP$.
2. Quali parole troviamo in $(L^c_\Gamma(\chi))^C$?
Poiché in $L^c_\Gamma(\chi)$ troviamo parole che codificano istanze no di $\Gamma$, allora in $(L^c_\Gamma(\chi))^C$ troviamo:
1) parole che non codificano istanze di $\Gamma$ ;
2) parole che codificano istanze sì di $\Gamma$, ossia, parole che appartengono a $L_\Gamma(\chi)$.
$NT_0$ opera in due fasi: con input $x\in\Sigma^*$, 
**Fase1** Simula la computazione $T(x)$: se $T(x)$ termina nello stato di rigetto, allora $NT_0$ termina nello stato di accettazione, altrimenti ha inizio la Fase 2. 
**Fase 2** Simula la computazione $NT(x)$: se $NT(x)$ accetta allora $NT_0$ accetta.
$NT_0(x)$ accetta quando $x\not\in\chi(\mathcal I_\Gamma)$ oppure $x\in L_\Gamma(\chi)$, cioè
**$NT_0(x)$ accetta se e soltanto se $x$ appartiene a $(L^c_\Gamma(\chi))^C$**.
Inoltre, è semplice verificare che $ntime(NT_0,x)\in O(|x|^{max\{h,k\}} )$. Quindi: $(L^c_\Gamma(\chi))^C$ è in NP, e dunque $L^c_\Gamma(\chi)\in coNP$.

## Le assunzioni di lavoro
Non è ragionevole che sia più complesso decidere se una parola è istanza di un problema, che decidere se una istanza di quel problema è una istanza sì, come avviene negli esempi 7.7 e 7.8.
Perché la difficoltà nel risolvere un problema non dovrebbe essere nel riconoscere che i dati che ci vengono forniti siano effettivamente dati del nostro problema, ma nel trovare una soluzione (o nel verificare che una soluzione esiste) ad una data istanza del problema. 
Per questa ragione, da ora in avanti assumeremo sempre che, per ogni problema di decisione $\Gamma$ e per ogni sua codifica ragionevole $\chi$, il linguaggio delle istanze sia in P, ossia $\chi(\mathcal I_\Gamma)\in P$. 
Questo significa che, ad esempio, la formalizzazione del problema PHC sarà:
1. $\mathcal I_{PHC}=\{\langle G = (V,E), u, v\rangle : G$ è un grafo non orientato $\land u,v\in V\}$; 
2. $S_{PHC}(G,u,v) = \{ p : p$ è un percorso in $G\}$; 
3. $\pi_{PHC}(G,u,v, S_{PHC}(G,u,v)) =\exists$ un ciclo c in G che passa una e una sola volta attraverso ciascun nodo di $G\land\exists p\in S_{PHC}(G,u,v)$ che connette $u$ a $v$. 
ossia, *sposteremo nel predicato tutte le proprietà che devono essere soddisfatte dai dati che costituiscono l’istanza*. 