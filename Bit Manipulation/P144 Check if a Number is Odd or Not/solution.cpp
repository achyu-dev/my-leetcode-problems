#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {
        return n & 1;
    }
};

int main() {
    Solution sol;
    int n = 5;
    if (sol.isOdd(n)) {
        cout << n << " is odd." << endl;
    } else {
        cout << n << " is even." << endl;
    }
    return 0;
}