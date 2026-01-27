#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void func(int ind, int sum, vector<int> &arr, int N, vector<int> &res)
  {
    if (ind == N)
    {
      res.push_back(sum);
      return;
    }

    // pick the element
    func(ind + 1, sum + arr[ind], arr, N, res); // formula = sum + arr[ind]

    // not pick the element
    func(ind + 1, sum, arr, N, res);
  }
  vector<int> subsetSums(vector<int> &nums)
  {
    vector<int> res;
    int N = nums.size();
    func(0, 0, nums, N, res);
    sort(res.begin(), res.end());
    return res;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {9, 23, 76, 19, 1, 12, 1, 5, 11, 12, 43, 9, 34, 7, 8, 90, 21, 33, 45, 67, 12};
  vector<int> result = sol.subsetSums(nums);

  for (int sum : result)
  {
    cout << sum << " ";
  }
  cout << endl;

  return 0;
}