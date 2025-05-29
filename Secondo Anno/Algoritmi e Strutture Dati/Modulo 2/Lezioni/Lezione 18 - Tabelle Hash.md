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

*Grandezza della tavola*: Sceglie $m$ come un numero primo tale che $n\le m\le 2n$. (esiste sempre - `[Chebyshev 1850]`)
*Integer Encoding*: Identifica ogni elemento $x\in U$ con un intero di base $m$ di $r$ cifre: $x=(x_1,x_2,...,x_r), x_i\in\{0,1,...,m-1\}$
*Hash Function*: Dato $a\in U, a=(a_1,...,a_r).$
$$h_a(x)=[\sum_{i=1}^r a_i x_i] mod\ m.$$
![[Pasted image 20250527152319.png|center|300]]

*Famiglia delle hash function*: $\mathcal H=\{h_a:a\in U\}$

*Word RAM Model*:
- Manipolazione di $O(1)$ parole di macchine richiede tempo $O(1)$;
- Ogni oggetto di interesse si adatta ad una parola macchina.
$\implies$
- Immagazzinare $h_a$ richiede solo l'immagazzinamento di un valore singolo, $a$ (1 parola macchina);
- Computare $h_a(x)$ richiede tempo $O(1)$.

>[!important] Th.
>$\mathcal H=\{h_a:a\in U\}$ è universale.
>*Pf*.
>Siano $x=(x_1,x_2,...,x_r)$ e $y=(y_1,y_2,...,y_r)$ due elementi distinti di $U$. Dobbiamo mostrare che $Pr[h_a(x)=h_a(y)]\le\frac{1}{m}$.
>Dato che $x\not=y$, allora esiste un intero $j$ tale che $x_j\not=y_j$. 
>Abbiamo $h_a(x)=h_a(y)$ se e solo se $$a_j\underbrace{(y_j-x_j)}_{z}=\underbrace{\sum_{i\not=y}a_i(x_i-y_i)}_{\alpha}mod\ m.$$
>Possiamo assumere che $a$ sia scelto uniformemente a random prima selezionando tutte le coordinate $a_i$ dove $i\not=j$, poi selezionando $a_j$ a random. Quindi, possiamo assumere che $a_i$ sia fissata per tutte le coordinate $i\not=j$.
>Siccome $m$ è primo e $z\not=0$, $z$ ha un'inversa moltiplicativa $z^{-1}$; es. $z\cdot z^{-1}=1 mod\ m$.
>Questo implica che $Pr[h_a(x)=h_a(y)]\le\frac{1}{m}._\square$

#### Un'altra famiglia di hash universale

Scegli un primo $p\ge|U|$ (una volta sola).
**Famiglia hash**:
Dati $a,b\in U,$ $$h_{ab}(x)=[(ax+b)mod\ p]mod\ m$$
**Famiglia di hash function**: $\mathcal H=\{h_{ab}:a,b\in U\}.$

### Come scegliere (dinamicamente) la grandezza della tavola

>[!note] Nota: $S$ si carica nel tempo e noi vogliamo usare spazio $O(|S|)$.

**Parametri**:
- $n$: numero di elementi correntemente in tavola;
- $N$: grandezza virtuale della tavola;
- $m$: grandezza effettiva della tavola (un numero primo tra $N$ e $2N$).

**Tecnica di raddoppio/dimezzamento**:

```
- init n=N=1
- quando n>N:
	- N := 2N
	- scegli un nuovo m
	- re-hash tutti gli elementi (in O(n) tempo) -->O(1) ammortizzato per insert/delete
- quando n<N/4:
	- n := N/2
	- scegli un nuovo m
	- re-hash tutti gli elementi (in O(n) tempo)
```