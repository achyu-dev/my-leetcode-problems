#include <bits/stdc++.h>
using namespace std;

int setRightmostUnsetBit(int n) {
    // Use bitwise OR with n+1 to set rightmost 0
    return n | (n + 1);
}

int main() {
    int n = 10; 
    int result = setRightmostUnsetBit(n);
    cout << "The number after setting the rightmost unset bit of " << n << "is: " << result << endl;
    return 0;
}