#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int ans = 0;

        for (char a: s) {
            if (a == '(') p++;
            else if (a == ')') p--;
            ans = max(ans, p);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << sol.maxDepth(s) << endl;
    return 0;
}