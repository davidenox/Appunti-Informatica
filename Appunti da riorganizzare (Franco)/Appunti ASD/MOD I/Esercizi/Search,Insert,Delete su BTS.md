L'albero è mantenuto tramite un vettore posizionale
# Search

```python
a = [15,6,20,3,8,17,27,2,4,7,13,16,19,22,30]

def search(k):
    i = 0
    v = a[i]
    pos = 0
    while v!=None:
        if k==v:
            return (v,pos)
        elif k<v:
            v = a[2*i-1]
            pos = 2*i-1
        else:
            v = a[2*i]
            pos = 2*i
        i+=1
    return None

e,pos = search(30)
print(f"Ho trovato il nodo con chiave {e} in pos {pos}")
```

# Insert
