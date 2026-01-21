#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int n, string cur, vector<string>& result) {
        //base case: if length is n
        int p = cur.length();
        if (p == n) {
            result.push_back(cur);
            return;
        }

        //try adding "0"
        generate(n, cur + "0", result);

        if (cur.empty() || cur.back() != '1') {
            generate(n, cur + "1", result);
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        string current;
        generate(n, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<string> binaryStrings = sol.generateBinaryStrings(n);

    for (const string& str : binaryStrings) {
        cout << str << endl;
    }

    return 0;
}