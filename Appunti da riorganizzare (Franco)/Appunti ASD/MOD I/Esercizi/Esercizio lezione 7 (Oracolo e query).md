Dato un vettore X di n interi in $[1,k]$, costruire in tempo $O(n+k)$ una struttura dati (**oracolo**) che sappia rispondere a domande (**query**) in tempo $O(1)$ del tipo : "quanti interi in X cadono nell'intervallo $[a,b]$?", per ogni a e b

Soluzione:
Codice CreaOracolo:
Questa funzione mi crea l'**oracolo** basandosi sulla fase 1 dell'IntegerSort, in modo da avere la creazione dell'oracolo in tempo $O(n+k)$
Il mio array di appoggio Y però verrà modificato in modo da poter effettuare la differenza $Y[b]-Y[a-1]$ presente nel codice ChiamaOracolo

```pseudo
CreaOracolo(X,k)
Y array di dimensione k
for i=1 to k do Y[i]=0
for i=1 to n do incremento Y[X[i]]
for i=2 to k do Y[i]=Y[i]+Y[i-1]
return Y
```

Codice ChiamaOracolo:
Questa funzione interroga il mio oracolo, e in tempo $O(1)$ mi ritorna il numero di valori compresi fra a e b, dategli in input
Gli viene dato in input l'array Y modificato da CreaOracolo, poi i valori a e b e poi il valore k(che è il max in X, ovvero $k=max{X[i]}_{\forall x\in X}$). Dopo i controlli sui casi base, effettuo la sottrazione che mi ritorna in tempo costante il numero di elementi fra a e b

```pseudo
ChiamaOracolo(Y,a,b,k)
if b>k then b=k
if a <= 1 then return Y[b]
		  else return (Y[b]-Y[a-1])
```

**Oss** si può fare tutto anche in una sola funzione, in quel caso Y,a,b saranno globali alla funzione

**Esempio**
Array $X=[1,10,4,5,5,20,3,3];\:a=5,b=15,k=20$
Dopo aver effettuato crea oracolo avrò il mio array Y che sarà:
$Y=[1,1,3,4,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8]$
E di conseguenza la differenza $Y[b]-Y[a-1]$ sarà uguale a $Y[15]-Y[5-1]=7-4=3$
che è proprio il numero di elementi compresi fra a e b

**Esempio con codice python**

```python
x=[1,10,4,5,5,20,3,3]

def CreaOracolo(a,k):
    y=[0]*(k+1)
    n=len(a)
    for i in range(n-1):
        y[a[i]]+=1
    print(f"Array Y: {y}")
    for i in range(2,k):
        y[i]=y[i]+y[i-1]
    return y

def InterrogaOracolo(y,a,b,k):
    if b>k:
        b=k
    if a <=1:
        return y[b]
    else:
        return y[b]-y[a-1]

y=CreaOracolo(x,20)
print(f"array Y'(oracolo):{y}")
a=5
b=15
valore = InterrogaOracolo(y,a,b,20)
print(f"elementi compresi fra {a} e {b} in Y': {valore}")
```

Risultato:

![[Pasted image 20221104103945.png|center|500]]



