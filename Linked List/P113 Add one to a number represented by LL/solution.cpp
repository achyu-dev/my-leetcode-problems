#include <bits/stdc++.h>
using namespace std;

/* Definition of singly linked list: */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
public:
    ListNode *addOne(ListNode *head)
    {
        // Reverse the linked list
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;

        // Add one to the reversed linked list
        ListNode *temp = head;
        int carry = 1; // Initialize carry as 1 since we are adding one
        while (temp != NULL && carry > 0)
        {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            if (temp->next == NULL && carry > 0)
            {
                temp->next = new ListNode(carry);
                carry = 0; // No more carry to propagate
            }
            temp = temp->next;
        }

        // Reverse the linked list back to original order
        prev = NULL;
        curr = head;
        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;

        return head;
    }
};

// Example usage
int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(9);

    ListNode *result = sol.addOne(head);

    // Print the result
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}