#include<bits/stdc++.h>
using namespace std;

// using Dutch National flag algorithm
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
         int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    }
};

int main() {
    Solution sol;
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sol.sortColors(colors);
    
    for (int color : colors) {
        cout << color << " ";
    }
    return 0;
}