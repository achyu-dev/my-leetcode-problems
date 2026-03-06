class Solution:
    def nextSmallerElements(self, arr):
        n = len(arr)
        stack = []
        res = [-1] * n

        for i in range(n):
            while stack and arr[i] < arr[stack[-1]]:
                idx = stack.pop()
                res[idx] = arr[i] # nse of popped element
            
            stack.append(i)
        
        return res
    

solution = Solution()
arr = [4, 5, 2, 10, 8]
print(solution.nextSmallerElements(arr))