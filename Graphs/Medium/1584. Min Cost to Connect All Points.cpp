#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        // 1. Build the Undirected Graph (Your i, j logic)
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        // 2. Prim's Algorithm
        int total_mst_weight = 0;
        
        // d[i] stores the minimum cost to connect node i to the MST
        vector<int> d(n, INT_MAX);
        vector<bool> visited(n, false);

        // Min-heap: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start with the first node
        d[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // If node already in MST, skip
            if (visited[u]) continue;

            // Include node in MST
            visited[u] = true;
            total_mst_weight += weight;
    

            // Check all neighbors
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight_uv = edge.second;

                // PRIM'S RELAXATION:
                // Is this edge the cheapest way to connect v to the current MST?
                if (!visited[v] && weight_uv < d[v]) {
                    d[v] = weight_uv;
                    pq.push({d[v], v});
                }
            }
        }

        return total_mst_weight;
    }
};

//rememver that in these cases prims is used not dijstras as dijstaras as mainly for minimum cost like shortest path this 
//as a tree was formed for that mst algorithms must be be used

