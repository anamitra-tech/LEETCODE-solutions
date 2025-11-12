#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = c;

        for (int nei : graph[node]) {
            if (color[nei] == 0) {
                if (!dfs(nei, -c, graph, color))
                    return false;
            } 
            else if (color[nei] == color[node]) {
                return false; // same color on both sides
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                if (!dfs(i, 1, graph, color))
                    return false;
            }
        }
        return true;
    }
};
