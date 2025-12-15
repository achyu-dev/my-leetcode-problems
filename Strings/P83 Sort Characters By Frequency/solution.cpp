#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        if (p1.first > p2.first) return true;
        if (p1.first < p2.first) return false;
        return p1.second < p2.second;
    }

    string frequencySort(string s)
    {
        unordered_map<char, int> freq;

        for (char c : s)
        {
            freq[c]++;
        }

        vector<pair<int, char>> freqVec;
        for (auto& p : freq) {
            freqVec.push_back({p.second, p.first});
        }

        sort(freqVec.begin(), freqVec.end(), comparator);

        string ans = "";

        for (auto& p : freqVec) {
            for (int j = 0; j < p.first; j++) {
                ans += p.second;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;
    return 0;
}