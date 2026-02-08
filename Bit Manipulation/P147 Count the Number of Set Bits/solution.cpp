#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 292;
    cout << "Number of set bits in " << n << " is: " << sol.countSetBits(n) << endl;
    return 0;
}