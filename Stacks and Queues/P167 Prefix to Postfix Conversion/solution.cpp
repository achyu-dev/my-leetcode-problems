#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOperator(char y) {
        switch(y) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
        }
        return false;
    }

    string prefixToPostfix(const string& s) {
        stack<string> st;
        int n = s.size();
        for (int i = n-1; i >= 0 ; --i) {
            if (isOperator(s[i])) {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();

                string te = op1 + op2 + s[i];
                st.push(te);
            }
            else {
                st.push(string(1, s[i]));
            }
        }
        return st.top();
    }
};

// TC - O(n)
// SC - O(n) 

int main() {
    Solution sol;
    string s = "*-A/BC-/AKL";
    cout << sol.prefixToPostfix(s) << endl;
    return 0;
}