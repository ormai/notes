# This program computes the sum of the digit of an integer with a recursive
# function

def main():
    n = int(input())

    print(digitSum(n))

def digitSum(i):
    if i == 0 : return 0

    return digitSum(i // 10) + i % 10

main()

# example with n = 964
# digitSum(964 // 10) + 964 % 10 ==> digiSum(96) + 4
# digitSum(96 // 10) + 96 % 10 ==> digitSum(9) + 6
# digitSum(9 // 10) + 9 % 10 ==> digitsum(0) + 9
# return 0 + 9 + 6 + 4 ==> 19
