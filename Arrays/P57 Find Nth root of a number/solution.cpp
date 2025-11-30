#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthRoot(int N, int M)
    {
        int left = 1, right = M, ans = 0;
        while (left <= right)
        { // Binary Search
            int mid = left + (right - left) / 2;
            long long sqr = 1;
            for (int i = 0; i < N; i++)
            {
                sqr *= mid;
                if (sqr > M)
                    break;
            }
            if (sqr == M)
            {
                return mid;
            }
            else if (sqr < M)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int N = 4, M = 69;
    cout << sol.NthRoot(N, M) << endl;
    return 0;
}