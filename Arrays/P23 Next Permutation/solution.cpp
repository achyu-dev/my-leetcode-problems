#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         vector<vector<int>> permutations;
//         sort(nums.begin(), nums.end());
//         do {
//             permutations.push_back(nums);
//         } while (next_permutation(nums.begin(), nums.end()));

//         for (int i = 0 ; i < permutations.size() ; i++) {
//             if (permutations[i] == nums) {
//                 if (i == permutations.size() - 1) {
//                     nums = permutations[0];
//                 }
//                 printf("%d ", permutations[i + 1]);

//             }
//         }

//         printf("%d ", nums);
//     }
// };

class SolutionOptimal
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int index = -1;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i; // find the first decreasing element from the right
                break;
            }
        }

        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]); // swap with the just larger element
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end()); // reverse the part after index
    }
};

int main()
{
    SolutionOptimal sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}