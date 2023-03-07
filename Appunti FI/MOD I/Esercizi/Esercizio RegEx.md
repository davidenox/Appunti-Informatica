
Dato il linguaggio $L=\lbrace 0,1,2,3\rbrace$, trovare una regex tali che le stringhe del linguaggio sono composte in questo modo :
- cominciano e terminano per 0 o 1
- cominciano e terminano per un numero diverso
- se cominciano per 0 contengono 222
- se cominciano per 1 contengono 333

L'espressione regolare in questione è $(0\circ(0+1+2+3)^\star\circ(222)\circ(0+1+2+3)^\star\circ1)+(1\circ(0+1+2+3)^\star\circ(333)\circ(0+1+2+3)^\star\circ0)$

