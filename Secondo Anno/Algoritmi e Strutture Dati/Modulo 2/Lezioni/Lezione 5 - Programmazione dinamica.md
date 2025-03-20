# Insieme indipendente di peso massimo
	Su grafi a cammino
>**Input**: Un cammino $G$ di $n$ nodi. Ogni nodo $v_i$ ha un *peso* $w_i$.

>**Goal**: Trovare un insieme indipendente di *peso massimo*, ovvero un insieme $S$ di nodi tale che:
>1. $S$ è un II
>2. $w(s)=\sum_{v_i\in S} w_i$ è più grande possibile.

![[Pasted image 20250320114429.png|center|500]]
Un *Insieme Indipendente* di $G$ è un sottoinsieme di nodi che non contiene due nodi adiacenti, ovvero per ogni coppia di nodi dell'insieme i due nodi non sono collegati da un arco.