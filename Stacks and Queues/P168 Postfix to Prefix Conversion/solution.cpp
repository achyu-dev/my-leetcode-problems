#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToPre(string postfix) {
        stack<string> st;
        for (char c: postfix) {
            if (isalpha(c)) {
                st.push(string(1, c));
            } else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = c + op1 + op2;
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main() {
    string postfix = "AB+CD-*";
    Solution sol;
    cout << sol.postToPre(postfix) << endl;
    return 0;
}