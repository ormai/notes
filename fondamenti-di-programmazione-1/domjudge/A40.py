def main():
    seq = []
    n = int(input())
    while n != -50:
        seq.append(n)
        n = int(input())

    if len(seq) == 0:
        print("VUOTA", end="")
        return

    media = md(seq)
    maggioriAllaMedia = []
    for i in seq:
        if i >= media:
            maggioriAllaMedia.append(i)

    print(min(maggioriAllaMedia), end="")

def md(l):
    return sum(l) // len(l)

main()
