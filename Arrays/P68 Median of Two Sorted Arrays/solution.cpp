#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce {
public:
    void merge(vector<int>&arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        // mrege two arrays using merge function 
        res.reserve(nums1.size() + nums2.size());
        res.insert(res.end(), nums1.begin(), nums1.end());
        res.insert(res.end(), nums2.begin(), nums2.end());
        merge(res, 0, nums1.size() - 1, res.size() - 1);

        int n = res.size();
        if (n % 2 == 0) {
            return (res[n / 2 - 1] + res[n / 2]) / 2.0;
        } else {
            return res[n / 2];
        }
    }
};

class SolutionOptimal {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // find median using binary search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        int low = 0;
        int high = x;
        while (low <= high) {
            // cut the arrays
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            // Boundary conditions
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX) {
                if ((x + y) % 2 == 0) {
                    return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
                } else {
                    return (double)max(maxX, maxY);
                }
            } else if (maxX > minY) {
                // move towards left in nums1
                high = partitionX - 1;
            } else {
                // move towards right in nums1
                low = partitionX + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    SolutionOptimal solution;
    vector<int> nums1 = {1, 2, 5, 6, 7, 8, 12, 23, 3};
    vector<int> nums2 = {2, 6, 23, 12, 22, 8, 88, 54, 11, 7};
    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl; 
    return 0;
}