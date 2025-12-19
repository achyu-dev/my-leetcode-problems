#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};


class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            // insert X at the head of the linked list
            ListNode* newNode = new ListNode(X);
            newNode->next = head;
            head = newNode;
            return head;
        }
};

int main() {
    // Example usage:
    ListNode* head = nullptr;
    Solution sol;
    head = sol.insertAtHead(head, 1);
    head = sol.insertAtHead(head, 2);
    head = sol.insertAtHead(head, 3);

    // Print the linked list
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}