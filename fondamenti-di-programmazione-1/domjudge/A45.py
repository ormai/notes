def main():
    M = input() # Contiene spazi

    if corretto(M):
        print("SI", end="")
    else:
        print("NO", end="")

def corretto(s):
    if s[0].isdigit(): return False
    for i in s:
        if not i.isalnum() and i != "_":
            return False

    return True

main()
