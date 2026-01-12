#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *&head)
    {
        // your code goes here
        int count0 = 0, count1 = 0, count2 = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
                count0++;
            else if (temp->data == 1)
                count1++;
            else
                count2++;
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            if (count0 != 0)
            {
                temp->data = 0;
                count0--;
            }
            else if (count1 != 0)
            {
                temp->data = 1;
                count1--;
            }
            else
            {
                temp->data = 2;
                count2--;
            }
            temp = temp->next;
        }

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);

    Solution sol;
    head = sol.sortList(head);
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}