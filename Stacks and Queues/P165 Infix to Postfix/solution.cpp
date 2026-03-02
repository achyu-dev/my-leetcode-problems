#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prec(char c)
    {
        if (c == '^') // Exponent operator has highest precedence
            return 3;
        else if (c == '/' || c == '*') // Multiplication and division have higher precedence than addition
            return 2;
        else if (c == '+' || c == '-') // Addition and subtraction have lowest precedence
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string s)
    {
        stack<char> st;
        string res;
        for (char c : s)
        {
            if (isalnum(c))
            {
                res += c;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && prec(st.top()) >= prec(c))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = sol.infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}