#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                if (i * i != n) {
                    ans.push_back(n / i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 28;
    vector<int> result = sol.divisors(n);
    for (int divisor : result) {
        cout << divisor << " ";
    }
    cout << endl;
    return 0;
}