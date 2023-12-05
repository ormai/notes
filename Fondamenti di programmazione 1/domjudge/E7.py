def main():
    n = input()
    print(roman(n), end="")

def roman(s): # s per stringa
    r = [] # risultato
    primo = int(s[len(s) - 1])

    if primo < 4:
        r.insert(0, ("I" * primo))
    elif primo == 4:
        r.insert(0, "IV")
    elif primo == 5:
        r.insert(0, "V")
    elif primo > 5 and primo < 9:
        r.insert(0, ("V" + ("I" * (primo - 5))))
    elif primo == 9:
        r.insert(0, "IX")

    if len(s) >= 2:
        secondo = int(s[len(s) - 2])
        if secondo < 4:
            r.insert(0, ("X" * secondo))
        elif secondo == 4:
            r.insert(0, "XL")
        elif secondo == 5:
            r.insert(0, "L")
        elif secondo > 5 and secondo < 9:
            r.insert(0, ("L" + ("X" * (secondo - 5))))
        elif secondo == 9:
            r.insert(0, "XC")

    if len(s) >= 3:
        terzo = int(s[len(s) - 3])
        if terzo < 4:
            r.insert(0, ("C" * terzo))
        elif terzo == 4:
            r.insert(0, "CD")
        elif terzo == 5:
            r.insert(0, "D")
        elif terzo > 5 and terzo < 9:
            r.insert(0, ("D" + ("C" * (terzo - 5))))
        elif terzo == 9:
            r.insert(0, "CM")

    if len(s) == 4 and int(s[0]) == 1:
        r.insert(0, "M")

    return "".join(r)

main()
