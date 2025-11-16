class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1;
        for (int nei : graph[node]) {
            if (!vis[nei])
                dfs(nei, graph, vis);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);
        for (auto &e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, graph, vis);
                components++;
            }
        }

        return components - 1;
    }
};
