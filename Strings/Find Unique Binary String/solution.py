from typing import List

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        for i in range(2**n):
            candidate = bin(i)[2:].zfill(n)
            if candidate not in nums:
                return candidate
# Time complexity: O(n * 2^n) - We generate 2^n candidates and check if each candidate is in the list of nums, which takes O(n) time.
# Space complexity: O(n) - We store the candidates and the list of nums, which can take up to O(n) space.


# recursive approach
class SolutionOptimal:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        def backtrack(path):
            if len(path) == n:
                candidate = ''.join(path)
                if candidate not in nums:
                    return candidate
                return None
            for bit in ['0', '1']:
                path.append(bit)
                result = backtrack(path)
                if result:
                    return result
                path.pop()
        return backtrack([])

# Example usage:
nums = ["01", "10"]
solution = Solution()
print(solution.findDifferentBinaryString(nums))