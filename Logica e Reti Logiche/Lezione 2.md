# Teorema di Cantor
>[!important]- Definizione
>$\not\exists$ funzione bionivoca tra $\mathbb{N}$ e P($\mathbb{N}$)
>

*Dim*: Supponiamo _per assurdo_ che $\exists f:\mathbb{N}\Rightarrow P(\mathbb{N})$ sia biunivoca 
($n\rightarrow A_n \subseteq \mathbb{N}$)
Definiamo $C:=\{i\in \mathbb{N}:i\not\in A_i\}\subseteq \mathbb{N}$ deve essere $C=A_k,\forall k\in\mathbb{N}$
Abbiamo due opzioni:
1. Se $k\in C\Rightarrow k\not\in C$ (Assurdo)
2. Se $k\notin C \Rightarrow k \notin A_k \Rightarrow k\in C$ (Assurdo)
**Contraddizione**:
Abbiamo trovato un'affermazione $P =k\in C$ tale che
1. Né $P$ è vera;
2. Né $\overline{P}$ è vera.
$\Longrightarrow$**Principio del terzo escluso** oppure **Principio di non contraddizione**
>[!info]- Esempio
>"Io sto mentendo" non è né falsa né vera

# Paradosso di Russell
Chiamiamo "Ordinario" un insieme $S$ tale che $S\notin S$ ;
Chiamiamo "Straordinario" un insieme $S$ tale che $S\in S$. 
Prendiamo $C:=\{insiemi\space ordinari\}$
$\Longrightarrow$ C è "Ordinario" o "Straordinario"?
1. Se $C\space Ordinario \Rightarrow C\in C\Rightarrow C\space Straordinario$ 
2. Se $C\space Straordinario \Rightarrow C\notin C\Rightarrow C\space Ordinario$ 
(**Paradosso**)
>[!info]- Hypergame

$A=\{Giochi\space a\space due\space giocatori\space finiti\}$
$\Longrightarrow$ _Finiti_=la partita finisce in un numero limitato di mosse.
Il primo giocatore sceglie il gioco finito a cui giocare. 
Il secondo fa la prima mossa del gioco e così via...
_Hypergame è finito?_
# _Assioma di astrazione_ (o Principio di astrazione)
Data una proprietà P esiste l'insieme di tutti gli elementi che hanno la proprietà P
$$S=\{x|P(x)\}$$ 
# Dimostrazioni per induzione
>[!info]- Esempio

$9^n +3$ divisibile per 4 $\forall n \geq 0$ 
| n   | $9^n+3$ |   |      |   |
|-----|-------|---|------|---|
| 0   | 4     | V | P(0) |   |
| 1   | 12    | V | P(1) |   |
| 2   | 84    | V | P(2) |   |
| ... | ...   |   | ...  |   |
| ... | ...   | V | P(n) |   |
Chiamiamo P(n) l'affermazione $P(n)='9^n+3\space divisibile\space per\space 4'$ 
## Tecniche di dimostrazione per induzione:
1. Verificare $P(0)$;
2. Dimostrare che, dato $k\in\mathbb{N}$ qualunque, se è vero $P(k)\Rightarrow$ sarà vero $P(k+1)$ 
>[!important]- Passo induttivo:

**Base**:$(n=0)\Rightarrow 9^0+3=4 \space divisibile\space per\space 4$
**Induttivo**:$$\begin{align}& (n\geq 1)\Rightarrow\exists k\in\mathbb{N},k\geq 1:\\& P(k)='9^k+3\spaceè\space divisibile\space per\space4';\space\\& P(k+1)='9^{k+1}+3\space è\space divisibile\space per\space 4'.\end{align}

$$
$$\begin{align}& 9^{k+1}+3=9\cdot 1^k+3=(8+1)9^k+3\Rightarrow\space La\space somma\space di\space due\space numeri\\&\space divisibili\space per\space 4\space è\space divisibile\space per\space 4 \space\square\end{align}$$
