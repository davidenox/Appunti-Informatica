
# Esercizio 2

```
# inizio prima parte
T=[2n]
for each buffet b:
	inserisco in T le due tuple
		<name(b),start(b),value(b),True>
		<name(b),start(b),value(b),False>
Ordino T in base al valore start()
# fine prima parte
# inizio seconda parte
Istanzio un AVL:
	S<-AVL
	b_s<-null
	v_s<-=0
for i=1 to 2n:
	if T(i).open=True:
		S.insert(<T(i).v,T(i).b>)
		if T(i).v > v_s:
			v_s = T(i).v
			b_s = T(i).b
			return <b_s,v_s,T(i).h>
	else:
		S.remove(T(i).b)
		if T(i).b = b_s:
			v_max = S.max()
			b_max = S.search(v_max)
			v_s = v_max
			b_s = b_max
			return v_s,b_s 
# fin seconda parte
```

**Costo**: 
- prima parte: $O(n)$
- ordinamento di T: $\Theta(nlog(n))$
- seconda parte: $O(1)+O(n(2log(n)))+O(nlog(n))\implies O(nlog(n))$

Tot: $O(nlog(n))$

Spazio: $O(n)$

# Esercizio 3

