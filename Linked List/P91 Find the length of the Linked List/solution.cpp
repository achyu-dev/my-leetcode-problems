#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode()
    {
        delete next;
    }
};

class Solution
{
public:
    int getLength(ListNode *head)
    {

        int length = 0;
        ListNode *current = head; // Start from the head of the list
        while (current != nullptr) // Traverse until the end of the list
        {
            length++;
            current = current->next;
        }
        return length;
    }
};

int main()
{
    // Example usage:
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution solution;
    int length = solution.getLength(head);
    cout << "Length of the linked list: " << length << endl;

    delete head; // Clean up memory
    return 0;
}