#include <bits/stdc++.h>
using namespace std;


// recursion + backtracking
class Solution{
public:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
        for (int k = 0; k < n; k++) {
            if (k != node && graph[node][k] == 1 && color[k] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
        if (node == N) {
            return true;
        }
        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, graph, N, col)) {
                color[node] = col;
                if (solve(node + 1, color, m, N, graph)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	bool graph[101][101] = {false};
        for (auto &edge : edges) {
            graph[edge[0]][edge[1]] = true;
            graph[edge[1]][edge[0]] = true;
        }
        int color[101] = {0};
        return solve(0, color, m, n, graph);
    }
};

int main() {
    // dont take input from user
    int n = 20; // number of nodes
    int m = 30; // number of colors
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {0, 2}
    };
    Solution sol;
    if (sol.graphColoring(edges, m, n)) {
        cout << "Graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }
    return 0;
}