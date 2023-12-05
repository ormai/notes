pagaNormale = float(input("Inserire la paga oraria normale: "))
oreRegolari = float(input("Inserire le ore normali lavorate: "))
oreStraordinarie = float(input("Inserire le ore straordinarie lavorate: "))

print("Paga settimanale totale:", oreRegolari * pagaNormale + oreStraordinarie * pagaNormale*1.5)
