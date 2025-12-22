#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class SolutionBruteForce { // TC O(2N) SC O(N)
public:
    ListNode* reverseDLL(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        // traverse the DLL and push data onto stack
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;

        // pop data from stack and assign to nodes
        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

class SolutionOptimal {
public:
    ListNode* reverseDLL(ListNode* head) {
        // two pointers approach
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // traverse the DLL and swap next and prev pointers
        while (curr != nullptr) {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev; // move to next node (which is prev due to swap)
        }

        // prev helps locate the new head
        if (prev != nullptr) {
            head = prev->prev; // update head to new head
        }

        return head;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;

    SolutionOptimal solution;
    head = solution.reverseDLL(head);

    // Print reversed DLL
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // print Head
    cout << "Head: " << head->data << endl;

    return 0;
}

