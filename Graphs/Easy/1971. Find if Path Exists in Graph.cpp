class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        return dfs(source, destination, adj, visited);
    }

    bool dfs(int node, int dest, vector<vector<int>> &adj, vector<int> &visited) {
        if (node == dest) return true; 
        visited[node] = 1;

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (dfs(nei, dest, adj, visited)) 
                    return true;
            }
        }

        return false;
    }
};
