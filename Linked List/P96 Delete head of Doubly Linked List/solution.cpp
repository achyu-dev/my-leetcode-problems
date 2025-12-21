#include <bits/stdc++.h>
using namespace std;


class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

class Solution {
public:
    ListNode *deleteHead(ListNode *&head) {
        // Your code goes here
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }
};

int main() {
    // Example usage:
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;

    head = sol.deleteHead(head);

    // Print the updated list
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up remaining nodes
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}