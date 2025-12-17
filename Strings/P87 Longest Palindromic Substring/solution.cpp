#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // mid is center index, so we need to check both odd and even length palindromes
        int start = 0, maxLen = 1;
        for (int mid = 0; mid < n; ++mid) {
            // odd length
            int l = mid, r = mid; // expand around center
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                --l;
                ++r;
            }
            // even length
            l = mid, r = mid + 1; // expand around center
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                --l;
                ++r;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << "Longest Palindromic Substring of \"" << s << "\": " << sol.longestPalindrome(s) << endl;
    return 0;
}