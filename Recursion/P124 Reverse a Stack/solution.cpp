#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertAtBottom(stack<int> &st, int topele) {
        if (st.empty()) {
            st.push(topele);
            return;
        }
        int ele = st.top();
        st.pop();
        insertAtBottom(st, topele);
        st.push(ele);
    }   
    
    void reverseStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }
        int topele = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topele);
    }
};