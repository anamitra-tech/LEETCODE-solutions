class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // 1️⃣ Build directed graph (b → a)
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
        }

        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        
        // 2️⃣ Run DFS for all nodes
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) return false;
            }
        }
        return true; // no cycles found
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1; // visiting

        for (int nei : adj[node]) {
            if (visited[nei] == 1) return false; // ❌ cycle found
            if (visited[nei] == 0 && !dfs(nei, adj, visited)) 
                return false;
        }

        visited[node] = 2; // ✅ done visiting
        return true;
    }
};
