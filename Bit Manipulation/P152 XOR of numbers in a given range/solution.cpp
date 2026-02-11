#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRangeXOR(int l, int r)
    {
        int ans = 0;
        for (int i = l; i <= r; i++)
        {
            ans ^= i;
        }
        return ans;
    }
};

class SolutionOptimized
{
    public:
    int findXOR(int n)
    {
        if (n % 4 == 0)
            return n;
        else if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else
            return 0;
    }
    
    int findRangeXOR(int l, int r)
    {
        return findXOR(r) ^ findXOR(l - 1);
    }
};

int main() {
    int l = 4, r = 7;
    SolutionOptimized sol;
    cout << sol.findRangeXOR(l, r) << endl;
    return 0;
}