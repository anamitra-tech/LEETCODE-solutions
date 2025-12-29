#include <vector>
#include <utility>

using namespace std;

class Solution {
    int count = 0;

public:
    void dfs(int src, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        visited[src] = true;

        for (auto& edge : adj[src]) {
            int neighbor = edge.first;
            int isOriginal = edge.second;

            if (!visited[neighbor]) {
                if (isOriginal == 1) {
                    count++;
                }
                
                dfs(neighbor, adj, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        count = 0;
        
        // Adjacency list: {neighbor, type}
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> visited(n, false);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            // Original: u -> v (Type 1)
            adj[u].push_back({v, 1}); 
            // Reverse: v -> u (Type 0) - Needed so DFS can travel to every node
            adj[v].push_back({u, 0}); 
        }

        dfs(0, adj, visited);

        return count;
    }
};

//thw mistake was that in directed graph there no dfs of te edges that are not pointed thus make a fake undirected graph to travel in all the directions
