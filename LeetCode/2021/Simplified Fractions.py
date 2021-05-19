class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        # positive fractions
        # numerator less than denominator
        # denominator less than or equal to n
        # idea: generate all possible fractions that satisfy these criteria
            # next, check if fractions can be simplified
        
        all_fractions = []
        result = []
        
        # generate all possible fractions
        for numerator in range (1, n):
            for denominator in range (numerator + 1, n + 1):
                fraction_to_add = str(numerator) + "/" + str(denominator)
                all_fractions.append(fraction_to_add)
              
        # print("All fractions:", all_fractions)
        
        # check for simplifying
        for fraction in all_fractions:
            # print("fraction:", fraction)
            
            numerator, denominator = fraction.split("/")
            numerator = int(numerator)
            denominator = int(denominator)
            if math.gcd(numerator, denominator) == 1:
                result.append(fraction)
                
        return result