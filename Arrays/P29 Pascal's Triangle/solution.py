from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(numRows):
            temp = [1]*(i+1) # Initialize a row with 1s
            for j in range(1,i): # Start from the second element to the second last
                temp[j] = res[i-1][j-1] + res[i-1][j] # Update the inner elements based on the previous row
            res.append(temp)
        return res
    
# Example usage:
sol = Solution()
print(sol.generate(25))
