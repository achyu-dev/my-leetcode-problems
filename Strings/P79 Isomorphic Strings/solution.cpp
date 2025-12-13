#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> s_to_t, t_to_s; // mappings in both directions
        for (int i = 0; i < n; ++i) {
            char c1 = s[i], c2 = t[i];
            if ((s_to_t.count(c1) && s_to_t[c1] != c2) || // check mapping from s to t
                (t_to_s.count(c2) && t_to_s[c2] != c1)) { // check mapping from t to s
                return false;
            }
            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "egg", t = "add";
    cout << (sol.isIsomorphic(s, t) ? "True" : "False") << endl;
    return 0;
}