def main():
    N = int(input())
    M = int(input())
    S = [] # non conterrà ripetizioni
    S1 = []
    for _ in range(N): S.append(int(input()))
    for _ in range(M): S1.append(int(input()))

    for i in range(len(S1)):
        for j in range(i + 1, len(S1)):
            if S1[i] == S1[j]:
                print("NO", end="")
                return

    if sumFree(S1) and isSubset(S1, S):
        print("OK", end="")
    else:
        print("NO", end="")

def isSubset(sub, s):
    for i in sub:
        if i not in s:
            return False

    return True

def sumFree(l):
    for i in range(len(l)):
        for j in range(i + 1, len(l)):
            if (l[i] + l[j]) in l:
                return False

    return True

main()
