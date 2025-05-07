# Problemi di Flusso

## Problema 1

Input :
- Insieme $R$ di $n$ risorse
- Insieme $A$ di $m$ risorse
- Risorsa $i$
	- è disponibile per $b_i$ unità
	- Può essere assegnata solo al sottoinsieme $A_i\subseteq A$ delle attività
- Attività $j$ richiede almeno $r_j$ risorse in totale per essere svolta

**Goal** : Capire se si possono assegnare le risorse in modo da svolgere tutte le attività

**Soluzione**

Usiamo un grafo ausiliario $G'$, fatto in questo modo

![[Pasted image 20250507111551.png|center|500]]


**Claim** : È possibile trovare un assegnamento e svolgere tutte le attività se e soltanto se il flusso massimo in $G'$ è uguale a $\sum\limits_jr_j$

## Problema 2

Input :
- Insieme $L$ di $n$ latterie
- Insieme $G$ di $m$ gelaterie
- Insieme $C$ di $t$ clienti
- Latteria $i$ produce $l_i$ litri di latte
- Gelateria $j$
	- Si rifornisce solo nelle latterie $L_j\subseteq L$
	- Può lvaorare al più $g_j$ litri di latte
	- Ogni litro di latte è sufficiente per una vascehtta di gelato
- Cliente $k$
	- Mangia solo nelle gelaterie $G_k\subseteq G$
	- Vuole $r_k$ vascehtte di gelato

**Goal** : Capire se c'è un modo di soddisfare tutti i clienti

**Soluzione**

Anche qui andiamo ad usare un grafo ausiliario $G'$

![[Pasted image 20250507111627.png|center|500]]

**Claim** : È possibile soddisfare tutti i clienti se e soltanto se il flusso massimo in $G'$ è uguale a $\sum\limits_kr_k$

## Problema 3

Input :
- $n$ dottori
- $k$ periodi festivi (es . settimana di natale, weekend di pasqua, etc...)
- Periodo $j$ costituito da $D_j$ giorni
- Dottore $i$
	- Disponibile a lavorare nei giorni $S_i\subseteq D$, con $D=\cup_jD_j$
	- Può lavorare al più $c$ giorni festivi in totale
	- Ma mai più di un giorno per ogni periodo di festività

**Goal** : Capire se è possibile assegnare un dottore ad ogni giorno di festività (rispettando i vincoli)

**Soluzione**

Anche qui usiamo il grafo ausiliario $G'$, aggiungendo però dei "gadget" che ci serviranno per ottenere la soluzione corretta del problema

![[Pasted image 20250507111659.png|center|500]]

Come si può vedere dal grafo sopra, i gadget sono i nodi collegati all'insieme dei dottori, che stanno ad indicare che il dottore $i$ può lavorare al più un giorno per periodo festivo

Questi gadget sono poi collegati all'insieme dei giorni festivi, divisi in $D_1$ = Natale, $D_2=$ Pasqua, etc... (Esempio)

**Claim** : Esiste un assegnamento che rispetta tutti i vincoli se e soltatno se il flusso massimo in $G'$ è uguale a $\vert D\vert$