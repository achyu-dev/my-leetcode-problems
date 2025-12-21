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

class Solution
{
public:
    ListNode *insertBeforeHead(ListNode *head, int X)
    {
        if (head == nullptr)
        {
            ListNode *newNode = new ListNode(X);
            return newNode;
        }
        ListNode *newNode = new ListNode(X);
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
};

int main() {
    ListNode* head = nullptr;
    Solution sol;
    head = sol.insertBeforeHead(head, 10);
    head = sol.insertBeforeHead(head, 20);
    head = sol.insertBeforeHead(head, 30);
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}