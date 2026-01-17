#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // Trim leading whitespace
        int i = 0, n = s.size();
        while (i < n && isspace(s[i]))
            i++;
        // Handle sign if + or -, if none assume +
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // Convert digits to integer
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // Check for overflow
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;
            i++;
        }

        return static_cast<int>(sign * result);
    }
};