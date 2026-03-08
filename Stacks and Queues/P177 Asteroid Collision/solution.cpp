#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        
        for (int a : asteroids) {
            bool destroyed = false;

            while (!ast.empty() && a < 0 && ast.top() > 0) {
                int diff = a + ast.top();
                
                if (diff < 0) {  // Incoming asteroid destroys the top
                    ast.pop();
                } else if (diff > 0) {  // Incoming asteroid is destroyed
                    destroyed = true;
                    break;
                } else {  // Both asteroids destroy each other
                    ast.pop();
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                ast.push(a);
            }
        }

        vector<int> result;
        while (!ast.empty()) {
            result.insert(result.begin(), ast.top());
            ast.pop();
        }

        return result;
    }
};
