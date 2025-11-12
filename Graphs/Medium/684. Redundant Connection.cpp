#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& graph, vector<int>& visited) {
        if (src == target) return true;
        visited[src] = 1;

        for (int nei : graph[src]) {
            if (!visited[nei]) {
                if (dfs(nei, target, graph, visited))
                    return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);  

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            vector<int> visited(n + 1, 0);

            if (dfs(u, v, graph, visited))
                return edge;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
}; 
