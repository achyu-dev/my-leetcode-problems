class Solution:
    def count_NGE(self, arr, indices):
        result = []
        for idx in indices:
            count = 0
            for j in range(idx+1, len(arr)):
                if arr[j] > arr[idx]:
                    count += 1
            result.append(count)

        return result

solution = Solution()
arr = [1, 2, 3, 4, 1]
indices = [0, 3]
print(solution.count_NGE(arr, indices))