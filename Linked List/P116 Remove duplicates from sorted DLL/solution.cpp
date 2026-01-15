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



// TC - O(N), SC - O(1)
class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            ListNode* nextNode = temp->next;
            while (nextNode != NULL && nextNode->val == temp->val) {
                ListNode* nodeToDelete = nextNode;
                nextNode = nextNode->next;
                delete nodeToDelete;
            }
            temp->next = nextNode;
            if (nextNode != NULL) {
                nextNode->prev = temp;
            }

            temp = nextNode;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->prev = head;
    head->next->next = new ListNode(2);
    head->next->next->prev = head->next;
    Solution sol;
    ListNode* newHead = sol.removeDuplicates(head);
    ListNode* curr = newHead;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}