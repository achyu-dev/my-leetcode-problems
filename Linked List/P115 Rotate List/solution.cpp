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
    ListNode *finNthNode(ListNode *temp, int k)
    { // function to find the nth node
        int cnt = 1;
        while (temp != NULL)
        {
            if (cnt == k)
                return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || k == 0)
            return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL)
        {
            tail = tail->next; // move to next node
            len += 1;
        }

        if (k % len == 0)
            return head;

        k = k % len;

        tail->next = head;
        ListNode *newLastNode = finNthNode(head, len - k); // recursive call to find the new last node

        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    Solution sol;
    ListNode *rotatedHead = sol.rotateRight(head, k);
    ListNode *temp = rotatedHead;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}