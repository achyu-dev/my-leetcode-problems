#include <bits/stdc++.h>
using namespace std;

/* Definition of doubly linked list */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *mergedHead = nullptr;
        ListNode *mergedTail = nullptr;

        if (l1->val < l2->val)
        {
            mergedHead = mergedTail = l1;
            l1 = l1->next;
        }
        else
        {
            mergedHead = mergedTail = l2;
            l2 = l2->next;
        }

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                mergedTail->next = l1;
                l1->prev = mergedTail;
                mergedTail = l1;
                l1 = l1->next;
            }
            else
            {
                mergedTail->next = l2;
                l2->prev = mergedTail;
                mergedTail = l2;
                l2 = l2->next;
            }
        }

        if (l1)
        {
            mergedTail->next = l1;
            l1->prev = mergedTail;
        }
        else if (l2)
        {
            mergedTail->next = l2;
            l2->prev = mergedTail;
        }

        return mergedHead;
    }
    ListNode *flattenLinkedList(ListNode *&head)
    {
        ListNode *curr = head;
        vector<ListNode *> lists;
        while (curr)
        {
            lists.push_back(curr);
            curr = curr->next;
        }
        ListNode *mergedList = nullptr;
        for (auto listHead : lists)
        {
            mergedList = mergeTwoLists(mergedList, listHead);
        }
        return mergedList;
    }
};

int main()
{
    // Example usage:
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->prev = head;
    head->next->next = new ListNode(7);
    head->next->next->prev = head->next;

    Solution sol;
    ListNode *flattenedList = sol.flattenLinkedList(head);

    // Print flattened list
    ListNode *curr = flattenedList;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}