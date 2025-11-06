#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int p = 0;
        for (int num : nums) {
            p ^= num;
        }
        return p;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,1,2,1,2};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}