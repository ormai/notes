# Verificare che in "exp" ci sia lo stesso numero di parentesi aperte
# e parentesi chiuse e che non ci sia mai una parentesi aperta e una chiusa
# consecutive.

exp = input()
numParentesiAperte = exp.count("(")
numParentesiChiuse = exp.count(")")

parentesiSuperflue = False
for i in range(len(exp)):
    if i + 1 < len(exp):
        if exp[i] == "(" and exp[i + 1] == ")":
            parentesiSuperflue = True

if numParentesiAperte != numParentesiChiuse:
    print("no1")
else:
    print("ok1")

if parentesiSuperflue:
    print("no2")
else:
    print("ok2")
