#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string prefixToInfix(string s)
    {
        stack<string> st;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
                continue;
            if (isalpha(s[i]))
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string temp = "(" + op1 + s[i] + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main()
{
    Solution sol;
    string s = "* + A B - C D";
    cout << sol.prefixToInfix(s) << endl;
    return 0;
}
