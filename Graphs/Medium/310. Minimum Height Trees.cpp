#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // single node tree

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build adjacency list and indegree count
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        // Push all leaves (nodes with indegree 1)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                q.push(i);
        }

        vector<int> ans;

        // Trim leaves level by level until <= 2 nodes remain
        while (!q.empty()) {
            int size = q.size();
            ans.clear(); // current layer of leaves

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (int nei : adj[node]) {
                    indegree[nei]--;
                    if (indegree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        return ans;
    }
};
