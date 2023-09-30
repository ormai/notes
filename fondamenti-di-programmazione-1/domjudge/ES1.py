def main():
    N = int(input())
    M = int(input())

    if altamenteComposto(N):
        print("OK1", end="")
    else:
        print("NO1", end="")

    if sec(N, M):
        print("OK2", end="")
    else:
        print("NO2", end="")

def sec(N, M):
    ran = []
    for i in range(1, N):
        ran.append(i)

    for i in ran:
        if numeroDivisori(i) == M:
            return True

    return False

def altamenteComposto(n):
    interiPositiviMinori = []
    for i in range(n):
        interiPositiviMinori.append(i)

    divisoriDegliINteriPositiviMinori = []
    for i in range(len(interiPositiviMinori)):
        divisoriDegliINteriPositiviMinori.append(
            numeroDivisori(interiPositiviMinori[i])
        )

    if (len(divisoriDegliINteriPositiviMinori) > 0
            and numeroDivisori(n) > max(divisoriDegliINteriPositiviMinori)):
        return True
    else:
        return False

def numeroDivisori(n):
    cont = 0
    for i in range(1, n + 1):
        if n % i == 0:
            cont += 1

    return cont

main()
