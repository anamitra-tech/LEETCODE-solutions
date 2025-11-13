class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1;
        for (int nei : graph[node]) {
            if (!visited[nei])
                dfs(nei, graph, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // treating "rooms" as a directed graph already
        int n = rooms.size();
        vector<int> visited(n, 0);

        dfs(0, rooms, visited);  // start from room 0

        for (int v : visited)
            if (!v) return false;  // if any room remains unvisited
        return true;
    }
};
