def GetFibonacci(limit: int) -> list:
    nums = [1, 1]
    while nums[-1] < limit:
        nums.append(nums[-1] + nums[-2])
    return nums


def SumOfEvens(fibonacci_nums: list) -> int:
    sum = 0
    for num in fibonacci_nums:
        if num % 2 == 0:
            sum += num
    return sum


def main():
    fibonacci_nums = GetFibonacci(4000000)
    print("Sum: " + str(SumOfEvens(fibonacci_nums)))


if __name__ == "__main__":
    main()
