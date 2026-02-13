#include <bits/stdc++.h>
using namespace std;

// Bit Manipulation
class Solution
{
public:
    vector<vector<int>> primeFactors(vector<int> &queries)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            vector<int> temp;
            int n = queries[i];
            for (int j = 2; j * j <= n; j++)
            {
                while (n % j == 0)
                {
                    temp.push_back(j);
                    n /= j;
                }
            }
            if (n > 1)
                temp.push_back(n);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> queries = {12, 15, 28};
    vector<vector<int>> result = sol.primeFactors(queries);
    for (const auto &factors : result)
    {
        for (int factor : factors)
        {
            cout << factor << " ";
        }
        cout << endl;
    }
    return 0;
}