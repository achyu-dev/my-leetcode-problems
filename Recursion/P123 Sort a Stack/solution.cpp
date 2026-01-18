#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertInSortedOrder(stack<int> &st, int element)
    {
        // base case: if stack is empty or top element is less than or equal to the element
        if (st.empty() || st.top() <= element)
        {
            st.push(element);
            return;
        }

        // pop the top element
        int topElement = st.top();
        st.pop();

        // recursively call to insert the element
        insertInSortedOrder(st, element);

        // push the popped element back
        st.push(topElement);
    }

    void sortStack(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }

        // recursively pop the top element
        int topElement = st.top();
        st.pop();

        // recursively sort the remaining stack
        sortStack(st);

        // inser removed element back in sorted order
        insertInSortedOrder(st, topElement);
    }
};

int main()
{
    Solution solution;
    stack<int> st;

    // Example usage
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    solution.sortStack(st);

    cout << "Sorted Stack: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}