# Posizione degli elementi
![[Pasted image 20240326151122.png|center|500]]
## Cambiare il flusso
>[!important]- Position
>- `top`, `bottom`, `left`, `right`
>- `z-index`

>[!important]- Float
>- `clear`

## Proprietà position
>`position`
>Values: `static` | `relative` | `absolute` | `fixed` | `inherit`
>Default: `static`
>Applies to: All elements
>Inherits: no

- *static*: Posizione normale
- *relative*: Posizionabile rispetto al suo posto
- *absolute*: Posizionabile rispetto al suo contenitore
- *fixed*: posizionabile rispetto al viewport
### Specificare la posizione
>`top`, `right`, `bottom`, `left`
>Values: Lenght measurement | percentage | `auto` | `inherit`
>Default: `auto`
>Applies to: positioned elements ( no `auto` )
>Inherits: no

Specifica la distanza rispetto all'*elemento o blocco contenitore*.
### Modalità di posizionamento
![[Pasted image 20240326153354.png|center|500]]
### Gestire le sovrapposizioni
>`z-index`
>Values: number | `auto` | `inherit`
>Default: `auto`
>Applies to: positioned elements 
>Inherits: no

![[Pasted image 20240326153604.png|center|500]]
### Float
>`float`
>Values: `left` | `right` | `none` | `inherit`
>Default: `none`
>Applies to: All elements 
>Inherits: no

>[!info]- Muove un elemento tutto a destra o tutto a sinistra permettendo agli altri elementi di circondarlo

#### Caratteristiche
- Si staccano dal flusso  normale ma influenzano il contenuto dei blocchi intorno;
- Sono contenuti nell'area del contenuto dell'elemento che li contiene;
- I margini sono mantenuti.
