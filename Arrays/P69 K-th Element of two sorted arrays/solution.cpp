#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        if (a.size() > b.size())
            return kthElement(b, a, k);

        int n = a.size();
        int m = b.size();

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = k - mid1;

            int left1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int left2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int right1 = (mid1 == n) ? INT_MAX : a[mid1];
            int right2 = (mid2 == m) ? INT_MAX : b[mid2];

            if (left1 <= right2 && left2 <= right1)
            {
                return max(left1, left2);
            }
            else if (left1 > right2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << "The " << k << "-th element is: " << sol.kthElement(a, b, k) << endl;
    return 0;
}