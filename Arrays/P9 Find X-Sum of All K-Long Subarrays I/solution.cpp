#include<bits/stdc++.h>
using namespace std;


// need to solve some day

class Solution {
public:
    using int2=pair<int, int>;
    static int x_sum( const auto& freq, int k, int x){
        auto freq2=freq;
        sort(freq2.begin(), freq2.end(), greater<int2>());
        int sum=0;
        for (int i=0; i<x; i++){
            auto [f, num]=freq2[i];
            if (f==0) break;
            sum+=num*f;
        }
        return sum;
    }
    static vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n=nums.size(), sz=n-k+1;
        vector<int> ans(sz);
        array<int2, 51> freq;
        freq.fill({0, 0});
        for(int r=0; r<k; r++){
            int z=nums[r];
            freq[z].second=z;
            freq[z].first++;
        }
        ans[0]=x_sum(freq, k, x);
        for(int l=1, r=k; l<sz; l++, r++){
            int L=nums[l-1], R=nums[r];
            freq[L].first--;
            freq[R].first++;
            freq[R].second = R;
            ans[l]=x_sum(freq, k, x);
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main() {
    vector<int> nums = {1, 2, 2, 1, 3};
    int k = 3, x = 2;
    vector<int> result = Solution::findXSum(nums, k, x);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}