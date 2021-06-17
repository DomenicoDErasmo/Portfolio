class Solution:
    def isUglyHelper(self, n: int, nums: dict) -> bool:
        two_case = three_case = five_case = True
        if n in nums:
            return nums[n]
        elif n % 2 != 0 and n % 3 != 0 and n % 5 != 0:
            nums[n] = False
            return False
        else:
            if n % 2 == 0:
                if n/2 in nums:
                    return nums[n/2]
                two_case = self.isUglyHelper(n/2, nums)
            if n % 3 == 0:
                if n/3 in nums:
                    return nums[n/3]
                three_case = self.isUglyHelper(n/3, nums)
            if n % 5 == 0:
                if n/ 5in nums:
                    return nums[n/5]
                five_case = self.isUglyHelper(n/5, nums)
            numIsUgly = two_case and three_case and five_case
            nums[n] = numIsUgly
            return numIsUgly
        
        
    def isUgly(self, n: int) -> bool:
        nums = {}
        nums[0] = False
        nums[1] = True
        nums[2] = True
        nums[3] = True
        nums[5] = True
        return self.isUglyHelper(n, nums)