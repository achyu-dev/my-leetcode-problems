class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return "01" not in s

solution = Solution()
print(solution.checkOnesSegment("1001"))