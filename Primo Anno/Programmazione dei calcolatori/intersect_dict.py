def intersection(d0,d1):
  #return [key for key in d0 if key in d1]
    intersect = []
    for key in d0:
        if key in d1:
            intersect.append(key)
    return intersect
        
dict_0 = {"brand": "Ford","model": "Mustang"}
dict_1 = {"brand": "Nissan", "model":"Nismo"}

soluz = intersection(dict_0,dict_1)
print(soluz)
