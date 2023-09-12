'''
Si scriva una funzione, denominata sort_by_freq, che prenda in input una lista a e la muti ordinando
i suoi elementi per frequenza, ovvero da quello meno frequente a quello più frequente
'''
def sort_by_freq(a):
    d = {}
    for i in range(len(a)):
        if a[i] in d:
            d[a[i]] += 1
        else:
            d[a[i]] = 1
    sorted_d = dict(sorted(d.items(),key = lambda x:x[1]))
    b = []
    for d in sorted_d:
        for i in range(sorted_d[d]):
            b.append(d)
    return b
a = ["a", "e", "b", "b", "a", "e", "e", "d", "e", "b"]
print(a)
print(sort_by_freq(a))

