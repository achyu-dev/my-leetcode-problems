#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution
{
public:
    int helper(long long index, long long n) {
        if (index == n)
            return 1;
        
        int res = 0;

        if (index % 2 == 0) {
            for (int digit: {0, 2, 4, 6, 8}) {
                res = (res + helper(index + 1, n)) % MOD;
            }
        }
        else {  
            for (int digit : {2, 3, 5, 7}) {
                res = (res + helper(index + 1, n)) % MOD;
            }
        }
        return res;
    }

    int countGoodNumbers(long long n)
    {
       return helper(0, n);
    }
};

int main()
{
    int n = 50;
    Solution sol;
    cout << sol.countGoodNumbers(n) << endl;
    return 0;
}