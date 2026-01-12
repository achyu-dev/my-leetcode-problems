#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode *concatenate(ListNode *less, ListNode *equal, ListNode *greater)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        // helper lambda to append nodes
        auto appendList = [&](ListNode *list)
        {
            if (!list)
                return;
            if (!head)
            {
                head = list;
                tail = list;
                while (tail->next)
                    tail = tail->next;
            }
            else
            {
                tail->next = list;
                while (tail->next)
                    tail = tail->next;
            }
        };

        appendList(less);
        appendList(equal);
        appendList(greater);

        return head;
    }

    // Time Limit Exceeded Solution
    ListNode *sortList(ListNode *head)
    {
        // quick sort
        if (!head || !head->next)
        {
            return head;
        }

        // find pivot
        ListNode *pivot = head;

        // partitioning
        ListNode *lessHead = new ListNode(0);
        ListNode *equalHead = new ListNode(0);

        ListNode *greaterHead = new ListNode(0);
        ListNode *less = lessHead;
        ListNode *equal = equalHead;
        ListNode *greater = greaterHead;
        ListNode *current = head;

        while (current)
        {
            if (current->val < pivot->val)
            {
                less->next = current;
                less = less->next;
            }
            else if (current->val == pivot->val)
            {
                equal->next = current;
                equal = equal->next;
            }
            else
            {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }

        // terminate the lists
        less->next = nullptr;
        equal->next = nullptr;
        greater->next = nullptr;

        // recursively sort less and greater lists
        ListNode *sortedLess = sortList(lessHead->next);
        ListNode *sortedGreater = sortList(greaterHead->next);
        // concatenate lists
        return concatenate(sortedLess, equalHead->next, sortedGreater);
    }
};

// Optimal Merge Sort Solution
class SolutionOptimal
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1)
        {
            tail->next = l1;
        }
        else
        {
            tail->next = l2;
        }

        return dummy.next;
    }
    
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        // find the middle point
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list into two halves
        prev->next = nullptr;

        // recursively sort both halves
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);

        // merge the sorted halves
        return merge(left, right);
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode *sortedHead = sol.sortList(head);

    // Print sorted list
    ListNode *current = sortedHead;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}