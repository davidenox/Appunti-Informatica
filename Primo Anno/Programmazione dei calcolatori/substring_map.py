'''
Si scriva una funzione, denominata initial_to_substring, 
che prenda in input una stringa a e restituisca un dizionario 
che mappi ogni carattere c di a nella sotto-stringa più lunga 
di a che inizi per c.
'''
def initial_to_substring(a):
    d = {}
    for i in range(len(a)):
        c = a[i]
        if c not in d.keys():
            d[c] = a[i:]
    return d


a = "franco è un negro"
d = initial_to_substring(a)
print(a)
print(d)