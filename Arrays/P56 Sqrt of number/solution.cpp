#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    int floorSqrt(int n)  {
      int ans = 0;
      for (int i = 1; i <= n; i++) {
        if (i * i <= n) {
          ans = i;
        } else {
          break;
        }
      }
      return ans;
    }
};

class SolutionOptimal {
    public:
    int floorSqrt(int n)  {
      int left = 1, right = n, ans = 0;
      while (left <= right) { // Binary Search
        int mid = left + (right - left) / 2;
        long long sqr = (long long)mid * mid; // To avoid overflow
        if (sqr == n) {
          return mid;
        } else if (sqr < n) {
          ans = mid;
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      return ans;
    }
};

int main() {
  SolutionOptimal sol;
  int n;
  cin >> n;
  cout << sol.floorSqrt(n) << endl;
  return 0;
}