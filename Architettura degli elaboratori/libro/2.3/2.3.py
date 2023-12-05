def main():
    global cache, count
    count = 0
    cache = []

    for i in range(50):
        res = f(i)
        cache.append(res)
        print(res)

    # print("Count:", count)


def f(n):
    global cache, count
    count += 1

    if n == 0: return 0
    if n == 1: return 1

    if n < len(cache):
        return cache[n]

    return ((2 * f(n - 1)) - (f(n - 2) // 2))

main()

