#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count = 0;
        for (char curr : s) {
            if (curr == '(') {
                if (count > 0) res += '(';
                count++;
            } else if (curr == ')') {
                count--;
                if (count > 0) res += ')';
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "(()())(())";
    cout << sol.removeOuterParentheses(s) << endl; 
    return 0;
}