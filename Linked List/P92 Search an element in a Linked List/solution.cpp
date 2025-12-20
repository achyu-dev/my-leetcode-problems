#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};


class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->val == key) { // Found the key
                return true; // Return true if key is found
            }
            current = current->next; // Move to the next node
        }
        return false;
    }
};