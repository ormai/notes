def main():
    stringa = input()

    if thueMorse(stringa):
        print("SI", end="")
    else:
        print("NO", end="")

def thueMorse(seq):
    SN = "0"
    while len(seq) > len(SN):
        curr = ""
        for i in SN:
            if i == "0":
                curr += "1"
            elif i == "1":
                curr += "0"
            else:
                return False
        SN += curr

    if SN.startswith(seq): return True
    return False

main()
