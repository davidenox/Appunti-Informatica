'''
Si scriva una funzione, denominata initials, che prenda in input una stringa 
a contenente parole separate da spazi e restituisca un dizionario che mappi 
ogni iniziale (prima lettera delle parole) alla lista di parole che hanno 
quella lettera per iniziale.
'''
def initials(a):
    d = {}
    parole = a.split()
    for parola in parole:
        iniziali=parola[0]
        if iniziali not in d:
            d[iniziali] = []
        
        d[iniziali].append(parola)
    return d
ciao = initials("ti piace bello peloso duro dura")
print(ciao)
