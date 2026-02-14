#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double recursivePow(double x, long long n) {
        if (n == 0) return 1.0;
        double half = recursivePow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -(long long)n;
        }
        return recursivePow(x, n);
    }
};

int main() {
    Solution sol;
    cout << sol.myPow(2.0, 10) << endl;
    cout << sol.myPow(2.1, 3) << endl;
    cout << sol.myPow(2.0, -2) << endl;
    return 0;
}