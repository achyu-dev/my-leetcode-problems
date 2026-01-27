// Crazy solution with 9 loops
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        
        for (int a = 1; a <= 9; a++) {
            for (int b = a + 1; b <= 9; b++) {
                for (int c = b + 1; c <= 9; c++) {
                    for (int d = c + 1; d <= 9; d++) {
                        for (int e = d + 1; e <= 9; e++) {
                            for (int f = e + 1; f <= 9; f++) {
                                for (int g = f + 1; g <= 9; g++) {
                                    for (int h = g + 1; h <= 9; h++) {
                                        for (int i = h + 1; i <= 9; i++) {
                                            vector<int> combo;
                                            int sum = 0;
                                            
                                            if (k >= 1) { combo.push_back(a); sum += a; }
                                            if (k >= 2) { combo.push_back(b); sum += b; }
                                            if (k >= 3) { combo.push_back(c); sum += c; }
                                            if (k >= 4) { combo.push_back(d); sum += d; }
                                            if (k >= 5) { combo.push_back(e); sum += e; }
                                            if (k >= 6) { combo.push_back(f); sum += f; }
                                            if (k >= 7) { combo.push_back(g); sum += g; }
                                            if (k >= 8) { combo.push_back(h); sum += h; }
                                            if (k >= 9) { combo.push_back(i); sum += i; }
                                            int size = combo.size();
                                            if (size == k && sum == n) {
                                                result.push_back(combo);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> combinations = sol.combinationSum3(k, n);
    
    for (const auto& combo : combinations) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}