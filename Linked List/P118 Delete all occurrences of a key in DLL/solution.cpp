#include <bits/stdc++.h>
using namespace std;

/*Definition of doubly linked list:*/
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

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp-> val == target) { // if current value is target
                if (temp == head) {
                    head = head->next;
                }
                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }
                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                }

                delete temp;
                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new ListNode(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->prev = head->next->next->next;
    int target = 2;
    Solution sol;
    head = sol.deleteAllOccurrences(head, target);
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}