
# Esercizio 2
determinare il linguaggio definito dall'espressione regolare $a^\star((aa)^\star b+(bb)^\star a)b^\star$ 


$$L=a^\star((aa)^\star b+(bb)^\star a)b^\star\implies L(a)^\star\circ [[(L(a)\circ L(a))^\star\circ L(b)] + [(L(b)\circ L(b))^\star\circ L(a)]]\circ L(b)^\star\implies$$
$$\underbrace{(\lbrace a\rbrace^\star\circ\lbrace aa\rbrace^\star\circ\lbrace b\rbrace\circ\lbrace b\rbrace^\star)}_{L_1}+\underbrace{(\lbrace a\rbrace^\star\circ\lbrace bb\rbrace^\star\circ\lbrace a\rbrace\circ\lbrace b\rbrace^\star)}_{L_2}$$
$\lbrace x\in\lbrace a,b\rbrace^\star|\text{la stringa inizia con una sequenza (pot. inf.) di a}$,$\text{seguita da una b e termina con una sequenza (pot. inf.) di b}$,OPPURE,$\text{inizia con una sequenza di a, seguita da una sequenza di b, seguita da a e termina con una sequenza di b}\rbrace$
Il linguaggio definito da questa espressione regolare sarà dato dall'unione di $L_1$ con $L_2$ ovvero $L_{tot}=L_1\cup L_2$

**OSS** $\lbrace aa\rbrace^\star\subseteq\lbrace a\rbrace^\star$
$\text{perchè (aa) dice che la sequenza è composta da coppie di a pari,}$
$\text{mentre (a) dice che la sequenza è di tutte a, sia pari che dispari}$ 

# Esercizio 1
determinare l'espressione regolare che, sull'alfabeto $\lbrace a,b\rbrace$, definisce l'insieme delle stringhe il cui terzultimo carattere è una b

$$r=(\underbrace{\lbrace ab\rbrace^\star}_{s_1}\circ\underbrace{\lbrace b\rbrace}_{s_2}\circ\underbrace{[(a+b)\circ(a+b)]}_{s_3})$$
$s_1=\text{Una sequenza(potenzialmente infinita) della coppia ab}$
$s_2=\text{il carattere b}$
$s_3=\text{la stringa finisce o con 2 "a" o con 2 "b" o con la coppia ab}$




