#include <bits/stdc++.h>
using namespace std;

/* Definition of singly linked list */

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


class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // loop until fast and slow meet
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // loop detected
            if (slow == fast) {
                return countLoopLength(slow);
            }
        }
        return 0;
    }

    int countLoopLength(ListNode* meetingPoint) {
        ListNode* temp = meetingPoint;
        int length = 1;

        // move until meet again
        while (temp->next != meetingPoint) {
            temp = temp->next;
            length++; // increment length
        }
        return length;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Creating a loop

    Solution sol;
    int loopLength = sol.findLengthOfLoop(head);
    cout << "Length of loop: " << loopLength << endl; // Output: Length of loop: 3

    return 0;
}