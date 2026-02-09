#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool sign = true; 
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);
        divisor = abs(divisor);

        long quot = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quot += 1 << cnt;
            n -= (d << cnt);
        }

        if (quot == (1 << 31) && sign) {
            return INT_MAX;
        }

        if (quot == (1 << 31) && !sign) {
            return INT_MIN;
        }

        return sign ? quot : -quot;
    }
};

int main() {
    Solution sol;
    cout << sol.divide(10, 3) << endl; // Output: 3
    cout << sol.divide(7, -3) << endl; // Output: -2
    cout << sol.divide(-2147483648, -1) << endl; // Output: 2147483647 (INT_MAX)
    return 0;
}