#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main() {
    Solution sol;
    int a = 5, b = 10;
    sol.swap(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;
    return 0;
}