def SumOfNumbersDivisibleByThreeAndFiveBelow(num: int) -> int:
    nums = [x for x in range(2, num) if x % 3 == 0 or x % 5 == 0]
    print(nums)
    return sum([x for x in range(2, num) if x % 3 == 0 or x % 5 == 0])


def main():
    print(SumOfNumbersDivisibleByThreeAndFiveBelow(1000))


if __name__ == "__main__":
    main()
