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

// TC - O(N^2), SC - O(1)
class Solution
{
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        vector<vector<int>> result;
        ListNode *temp1 = head;
        ListNode *temp2 = head;

        while (temp1 != NULL)
        {
            temp2 = temp1->next;
            while (temp2 != NULL && temp2->val + temp1->val <= target)
            {
                if (temp1->val + temp2->val == target)
                {
                    result.push_back({temp1->val, temp2->val});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next; // Move to the next node
        }
        return result;
    }
};


// TC - O(N), SC - O(1)
class Solution
{
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        vector<vector<int>> result;
        ListNode *left = head;
        ListNode *right = head;

        // Move right to the end of the list
        while (right->next != NULL)
        {
            right = right->next;
        }

        while (left != NULL && right != NULL && left != right && right->next != left)
        {
            int currentSum = left->val + right->val;
            if (currentSum == target)
            {
                result.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if (currentSum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return result;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new ListNode(4);
    head->next->next->next->prev = head->next->next;

    Solution sol;
    int target = 5;
    vector<vector<int>> pairs = sol.findPairsWithGivenSum(head, target);

    for (const auto &pair : pairs)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    // Clean up memory (not shown)
    return 0;
}