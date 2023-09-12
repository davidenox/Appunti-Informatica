'''
Si scriva una funzione, denominata intersection, che prenda in input due dizionari d0e d1 e 
restituisca una lista contenente le chiavi che sono in d0 ed in d1.
NB: Sono ammesse soltanto le strutture dati trattate e lezione ovvero list, tuple,dict e str
'''
def intersection(d0,d1):
    lista = []
    for k in d0.keys():
        if k in d1.keys():
            lista.append(k)
    return lista
d0 = {i:i for i in range(10)}
d1 = {i:i for i in range(2,20)}

print(intersection(d0,d1))
'''
due liste ordinate di numeri
intersezione e unione in tempo lineare
'''