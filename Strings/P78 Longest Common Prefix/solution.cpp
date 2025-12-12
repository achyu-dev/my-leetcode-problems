#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        // compare only the first and last strings
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string prefix = "";
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] == last[i])
            {
                prefix += first[i];
            }
            else
            {
                break;
            }
        }
        return prefix;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}