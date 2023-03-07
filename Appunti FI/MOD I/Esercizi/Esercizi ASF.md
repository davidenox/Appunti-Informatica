
Per ulteriori controlli sugli esercizi vedere il file -> [[Esercizi_ASF_2_nov_2022.pdf]]

# Esercizio 1

Definire un ASFD che riconosce le stringhe su $\lbrace a,b\rbrace$ caratterizzate dal fatto che il penultimo carattere è b

Soluzione:

![[Pasted image 20221102192816.png|center|500]]
Stringhe di esempio:

1. stringa aaba $$\delta(q_0,abba)=q_0\to\delta(q_0,bba)=q_1\to\delta(q_1,ba)=q_3\to\delta(q_3,a)=q_2$$
2. stringa bbb $$\delta(q_0,bbb)=q_1\to\delta(q_1,bb)=q_3\to\delta(q_3,b)=q_3$$

# Esercizio 2

Definire un ASFD su $\lbrace0,1\rbrace$ tali che: dopo ogni 0 ci sono necessariamente due 1

ASFD con stati pozzo:
![[Pasted image 20221111112744.png|center|500]]
ASFD senza stati pozzo:
![[Pasted image 20221111112828.png|center|500]]

# Esercizio 3

Definire un ASFD su $\lbrace a,b\rbrace$ tale che : le stringhe hanno come secondo carattere "b"

ASFD con stati pozzo:
![[Pasted image 20221111113854.png|center|500]]
ASFD senza stati pozzo:

Se si considera $|w|\geq2$
![[Pasted image 20221111114009.png|center|500]]
Altrimenti:
![[Pasted image 20221111114055.png|center|500]]


# Esercizio 4
