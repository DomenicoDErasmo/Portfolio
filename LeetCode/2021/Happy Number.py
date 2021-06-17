class Solution:
    def sumOfSquaresOfDigits(self, n: int) -> bool:
        digitSum = 0
        stringNum = str(n)
        for i in range(len(stringNum)):
            digitSum = digitSum + (int(stringNum[i]) ** 2)
        return digitSum
    
    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        else:
            prevNums = {}
            while n != 1:
                if n in prevNums:
                    return False
                else:
                    newNum = self.sumOfSquaresOfDigits(n)
                    if newNum == 1:
                        return True
                    else:
                        prevNums[n] = True
                        n = newNum
