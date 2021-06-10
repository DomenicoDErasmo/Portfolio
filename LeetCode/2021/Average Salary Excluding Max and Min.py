class Solution(object):
    def average(self, salary):
        """
        :type salary: List[int]
        :rtype: float
        """
        salary.sort()
        return float(sum(salary[1:len(salary)-1]))/(len(salary)-2)
