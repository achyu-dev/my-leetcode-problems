from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        nextgreater = {}
        for num in nums2:
            while stack and num > stack[-1]:
                nextgreater[stack.pop()] = num
            stack.append(num)
        return [nextgreater.get(num, -1) for num in nums1]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [4, 1, 2]
    nums2 = [1, 3, 4, 2]
    print(solution.nextGreaterElement(nums1, nums2))