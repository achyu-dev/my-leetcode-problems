#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> backtrack(string current, int open, int close, int n,
                             vector<string>& result) {
        int currl = current.length();
        if (currl == 2 * n) {
            result.push_back(current);
            return result;
        }

        if (open < n) {
            backtrack(current + "(", open + 1, close, n, result);
        }

        if (close < open) {
            backtrack(current + ")", open, close + 1, n, result);
        }

        return result;
    }

    vector<string> generateParenthesis(int n) {
        string current = "";
        int open = 0, close = 0;
        vector<string> result;

        backtrack(current, open, close, n, result);

        return result;
    }
};


int main()
{
    Solution sol;
    int n = 1;
    vector<string> parentheses = sol.generateParenthesis(n);

    for (const string &s : parentheses)
    {
        cout << s << endl;
    }

    return 0;
}