from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0 
        maxc = 0 
        for i in range(len(nums)):
            if (nums[i] == 1):
                count += 1
                maxc = max(maxc, count)
            else:
                count = 0
                
        
        return maxc

if __name__ == "__main__":
    sol = Solution()
    print(sol.findMaxConsecutiveOnes([1,1,1,1,1,1,1,0,1,1,1]))
    print(sol.findMaxConsecutiveOnes([1,0,1,1,0,1]))  
