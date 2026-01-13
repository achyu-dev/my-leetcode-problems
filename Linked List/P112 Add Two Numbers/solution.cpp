#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        int carry = 0;
        ListNode *head = l3;
        while (l1 && l2) // traverse both lists
        {
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) // traverse remaining nodes of l1
        {
            int value = l1->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l1 = l1->next;
        }

        while (l2) // traverse remaining nodes of l2
        {
            int value = l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l2 = l2->next;
        }

        if (carry)
        {
            l3->next = new ListNode(carry);
        }
        return head->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution sol;
    ListNode *l3 = sol.addTwoNumbers(l1, l2);
    while (l3)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    return 0;
}