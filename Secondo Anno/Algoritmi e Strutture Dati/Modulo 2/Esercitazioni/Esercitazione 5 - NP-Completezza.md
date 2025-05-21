# Suspicious Coalition Problem
## Traccia
Si parla di un sistema informatico che sviluppa un software di login. Il SW registra gli indirizzi IP degli utenti che accedono al sistema informatico nel tempo. In particolare, gli utenti vengono registrati in ingresso con:
- $I(u,m)=IP$, dove $u$ è l'utente registrato, $m$ è il minuto in cui si registra ed $IP$ è l'indirizzo IP associato.
Il vincolo è che lo stesso utente può fare un accesso al minuto.

Avviene un attacco informatico in un certo intervallo $u_1,..,t$. In particolare, per $t$ minuti consecutivi avviene che:
- Al minuto $1$ l'attacco ha acceduto all'IP $i_1$
- Al minuto $2$ l'attacco ha acceduto all'IP $i_2$
- Al minuto $3$ l'attacco ha acceduto all'IP $i_3$
- ...
- Al minuto $t$ l'attacco ha acceduto all'IP $i_t$
*Chi è stato?*
## Definizione del problema

>Input:
>- $i_1,..,i_t$ indirizzi IP
>- $k$ intero

$\exists$ Una coalizione (sottoinsieme di utenti) $S$ tale che $|S|\le k$ e $\forall m=1,...,t\exists u\in S:[I(u,m)=i_m]$?
## Soluzione

Si tratta di un problema di "cover". Mostriamo come SCP sia NP-Completo prima dimostrando l'appartenenza alla classe NP e poi svolgiamo una riduzione polinomiale da un problema noto.

Data una coalizione sospetta $C$, possiamo verificarne la validità in tempo polinomiale:
- Controlliamo che $|C| \leq k$
- Per ogni $I_j$​, verifichiamo che $C \cap I_j \neq \emptyset$    

Questo richiede tempo $O(mn)$ nel caso peggiore.

A questo punto, dimostriamo la completezza per NP riducendolo da Vertex Cover.
In particolare, dimostriamo che $VC\le_p SCP$:

Data un'istanza di VC:
![[Pasted image 20250521150229.png|center|300]]
Si possono vedere i nodi come gli utenti, ed ogni arco $e_j$ come un accesso sospetto di IP $e_j$ a tempo $j$. Ogni nodo $v$ è un utente $u_v$. Per ogni arco $e_j=(u_j,v_j)$ l'accesso $e_j$ a tempo $j$ l'hanno fatto i nodi $u_j$ e $v_j$.

Formalmente:
Si può mostrare una **riduzione polinomiale** da un problema noto NP-completo come **Vertex Cover**:
- Dato un grafo $G=(V,E)$, si costruisce un'istanza del SCP dove:
    - Ogni vertice $v \in V$ è un agente $a_v$;​
    - Ogni arco $(u, v) \in E$ diventa un’interazione sospetta $\{a_u, a_v\}$;
    - Il parametro $k$ resta lo stesso.       

La risposta al Vertex Cover è **sì** se e solo se la risposta all'SCP è **sì**.

Di conseguenza, si è dimostrato che SCP è un problema NP-Completo.
# Lecture Planning Problem

