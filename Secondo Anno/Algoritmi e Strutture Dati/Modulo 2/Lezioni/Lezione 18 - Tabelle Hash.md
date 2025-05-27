# Implementazione randomizzata dei dizionari

**Problema del dizionario**:
Dato un universo $U$ di possibili elementi, mantenere un sottoinsieme $S\subseteq U$ soggetti alle seguenti operazioni:
- `make-dictionary()`: Inizializzare un dizionario vuoto;
- `insert(u)`: Aggiungere l'elemento $u\in U$ ad $S$;
- `delete(u)`: Elimina $u$ da $S$, se c'è;
- `look-up(u)`: Determina se $u$ è in $S$.

**Challenge**: L'universo $U$ può essere estremamente largo, quindi definire un array di grandezza $|U|$ è irrealizzabile.

*Una soluzione*: Albero bilanciato (AVL).
- Spazio $O(|S|)$;
- Tempo per operazione $O(\log{|S|})$.

*Hash Table*:
- Spazio $O(|S|)$;
- Tempo atteso per operazione $O(1)$.

**Idea**:![[Pasted image 20250527120717.png|center|500]]
`H[i]`: Lista concatenata di tutti gli elementi che $h$ mappa per immagazzinare $i$ (*Hashing con catena*).

`insert`/`delete`/`lookup` di $u$:
- Computa $h(u)$;
- `insert`/`delete`/`search` $u$ scansionando la lista $H[h(u)]$.

**Goal**: Trova una funzione $h$ che "distribuisce" gli elementi.

## Scegliere una buona Hash Function

**Oss**. Per ogni hash function *deterministica* si può trovare un insieme $S$ in cui tutti gli elementi di $S$ sono mappati nello stesso slot. $\implies\Theta(n)$ tempo per operazione.

>**Idea**: Utilizzare la *randomizzazione*.
>**Approccio ovvio**: Per ogni $u$, scegli $h(u)$ uniformemente a random.
>$look-up(u)$: dove abbiamo messo $u$?
>Dobbiamo mantenere l'insieme di coppie $\{(u,h(u)=:u\in S\}$.

## Hashing universale

>[!important] Una famiglia $\mathcal H$ di hash function è **universale** se $$\forall u,v\in U, u\not= v[Pr_{h\in\mathcal H}(h(u)=h(v))\le\frac{1}{m}].$$

>[!important] Th.
>Sia $\mathcal H$ una famiglia di hash function universali. Sia $S\subseteq U$ di $n$ elementi. 
>Sia $u\in S$. Prendi una funzione randomica $h$ da $\mathcal H$, e sia $X$ la variabile randomica contando il numero di elementi di $S$ mappati da $h(u)$. Allora, $$E[X]\le 1+\frac{n}{m}.$$
>*Pf*.
>Per ogni $s\in S$:$$X_s r.v.=\begin{cases}1&if\ h(s)=h(u)\\ 0& otherwhise\end{cases} X=\sum_{s\in S}X_s.$$
>$$E[X]=E[\sum_{s\in S}X_s]=\sum_{s\in S}E[X_s]=\sum_{s\in S}Pr(h(s)=h(u))=1+\sum_{s\in S - \{u\}}Pr(h(s)=h(u))\le 1+\frac{n}{m}   ._{\square}$$

>[!info] Nota
>$m=\Theta(n)\implies$ Tempo atteso di operazione $O(1)$.

### Progettare una famiglia universale di Hash Function

