def main():
    global count
    count = 0
    print(f(3))
    print("count:", count)

def f(n):
    global count
    count += 1
    print(n)
    global cache

    if n == 0: return 0
    if n == 1: return 1

    return ((2 * f(n - 1)) - (f(n - 2) // 2))

main()

