#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        // bit masking technique
        return (n & (1 << i)) != 0; 
    }
};

int main() {
    int n = 5, i = 1;
    Solution sol;
    if (sol.checkIthBit(n, i)) {
        cout << "The " << i << "-th bit is set." << endl;
    } else {
        cout << "The " << i << "-th bit is not set." << endl;
    }
}