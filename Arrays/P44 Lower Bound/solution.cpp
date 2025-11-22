#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= x){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    int n, x;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> x;
    Solution sol;
    int result = sol.lowerBound(nums, x);
    cout << result << endl;
    return 0;
}