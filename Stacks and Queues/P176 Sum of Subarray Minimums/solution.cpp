#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce { // TC - O(n^2) SC - O(1)
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            int min = arr[i];
            for (int j = i ; j < n ; j++) {
                min = std::min(min, arr[j]);
                sum = (sum + min) % mod;
            }
        }
        return sum;
    }
};

// using findNSE and findPSEE
class SolutionOptimal { // TC - O(n) SC - O(n)
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0 ; i < n ; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1 ; i >= 0 ; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            sum = (sum + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        }
        return sum;
    }
};


int main() {
    SolutionBruteForce solution;
    vector<int> arr = {3, 1, 2, 4};
    cout << solution.sumSubarrayMins(arr) << endl;
    return 0;
}