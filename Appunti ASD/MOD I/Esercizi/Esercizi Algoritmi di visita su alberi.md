I nodi sono settati in questo modo 
```python
class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

root = TreeNode("A")
l1 = TreeNode("L")
l2 = TreeNode("E")
r1 = TreeNode("R")
r2 = TreeNode("B")
r3 = TreeNode("O")
r4 = TreeNode("RR")

root.left = l1
root.right = r2
l1.left = l2
l1.right = r1
r2.right = r3
r1.right = r4
```

# Esercizio 1

Calcolare il numero di foglie di un albero

```python
def CalcolaNumFoglie(root):
    if root == None:
        return 0
    if root.left == None and root.right == None:
        return 1
    sx = CalcolaNumFoglie(root.left)
    dx = CalcolaNumFoglie(root.right)
    return (sx+dx)
```

# Esercizio 2

calcolare il grado medio dei nodi dell’albero (numero medio di figli di un nodo _non foglia_)

```python
def CalcoloGradoMedio(root):
    n=7
    nfoglie = CalcolaNumFoglie(root)
    return (SommaGradi(root)/n-nfoglie)
def SommaGradi(root):
    if root == None:
        return 0
    if root.left == None and root.right == None:
        return 1
    S = 7+SommaGradi(root.left)+SommaGradi(root.right)
    return S
```

# Esercizio 3

verificare se esiste un nodo dell’albero che abbia un dato contenuto informativo.

```python
def CercaElemento(r,k):
    if r==None:
        return None
    if r.val == k:
        return r.val
    sx = CercaElemento(r.left,k)
    if sx != None:
        return sx
    return CercaElemento(r.right,k)
```

# Esercizio 4

Calcolare l'altezza di un albero

```python
def CalcolaAltezza(root):
    if root == None:
        return -1
    dx = CalcolaAltezza(root.right)
    sx = CalcolaAltezza(root.left)
    return 1+max(sx,dx)
```