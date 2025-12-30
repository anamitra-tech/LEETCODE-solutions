#include <vector>

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        long long totalPairs = 0;
        long long nodesSeenSoFar = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long currentComponentSize = 0;
                dfs(i, adj, visited, currentComponentSize);
                
                // Mathematical logic: Each node in the new component 
                // is unreachable from every node we've seen in previous components.
                totalPairs += (nodesSeenSoFar * currentComponentSize);
                nodesSeenSoFar += currentComponentSize;
            }
        }
        return totalPairs;
    }

private:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, long long& count) {
        visited[u] = true;
        count++;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, count);
            }
        }
    }
};
