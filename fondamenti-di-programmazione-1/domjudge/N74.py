def main():
    n = int(input())
    print(nRomboidaleIterative(n), end="")

def nRomboidaleIterative(n):
    row = 1
    result = row
    # print('*')
    for _ in range(n - 1):
        row += 2
        result += row
        # print('*' * row)

    for _ in range(n - 1):
        row -= 2
        result += row
        # print('*' * row)

    return result

main()
