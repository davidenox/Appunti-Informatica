# Gestione del box
## Il box model
Ogni elemento html è contenuto in un box rettangolare. Le proprietà `css` sono applicate al box:
- `width`
- `height`
- `padding`
- `borders`
- `margins`
Si visualizzano i box con la proprietà `border`:
`border: 1px solid black;`
## Il box degli elementi
![[Pasted image 20240319145219.png|center|500]]
![[Pasted image 20240319145246.png|center|500]]
### Dimensioni
>`width`
>*Values*: lenght measurement | percentage | `auto` | `inherit`
>*Default*: `auto`
>*Applies to*: block-level elements and replaced inline elements 
>*Inherits*: no

>`height`
>*Values*: lenght measurement | percentage | `auto` | `inherit`
>*Default*: `auto`
>*Applies to*: block-level elements and replaced inline elements 
>*Inherits*: no

### Padding
>`padding-top`, `padding-right`, `padding-bottom`, `padding-left`
>*Values*: lenght measurement | percentage | `inherit`
>*Default*: `0`
>*Applies to*: all elements except `table-row`, `table-header-group`, `table-footer-group`, `table-column` and `table-column-group`
>*Inherits*: no

>`padding`
>*Values*: lenght measurement | percentage | `inherit`
>*Default*: `0`
>*Applies to*: all elements 
>*Inherits*: no

![[Pasted image 20240319150133.png|center|500]]
### Margin
>`margin-top`, `margin-right`, `margin-bottom`, `margin-left`
>*Values*: lenght measurement | percentage |  `auto` | `inherit`
>*Default*: `auto`
>*Applies to*: all elements 
>*Inherits*: no

>`margin`
>*Values*: lenght measurement | percentage | `auto` | `inherit`
>*Default*: `auto`
>*Applies to*: all elements except elements with table display types other than `table-caption`, `table` e `inline-table` 
>*Inherits*: no

![[Pasted image 20240319150431.png|center|500]]
## Border
Del contorno di un elemento si può specificare:
- `border-style`
- `border-width`
- `border-color`
### Stili del border
>`border-top-style`, `border-right-style`, `border-bottom-style`, `border-left-style`
>*Values*: `none`  | `dotted` | `dashed` | `solid` | `double` | `groove` | `ridge` | `inset` | `outset` | `inherit`
>*Default*: `none`
>*Applies to*: all elements 
>*Inherits*: no
![[Pasted image 20240319155023.png|center|500]]
>`border-style`
>*Values*: `none` | `dotted` | `dashed` | `solid` | `double` | `groove` | `ridge` | `inset` | `outset` | `inherit` 
>*Default*: `none`
>*Applies to*: all elements
>*Inherits*: no
### Dimensione del border
10-37 tranne 34-35-36