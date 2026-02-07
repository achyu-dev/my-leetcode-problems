#include <bits/stdc++.h>
using namespace std;

// do not use loops and recursion
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }

        while (n != 1) {
            if (n % 2 != 0) {
                return false;
            }
            else {
                n /= 2;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPowerOfTwo(1) << endl; 
    cout << sol.isPowerOfTwo(16) << endl; 
    cout << sol.isPowerOfTwo(3) << endl;
    return 0;
}