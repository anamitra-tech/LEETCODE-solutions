#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        
        // Adjacency list: {neighbor, time}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // dist[i] is the minimum time to reach node i
        // ways[i] is the number of ways to reach node i in dist[i] time
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        // Min-priority queue: {time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization: skip if we've already found a better path
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int time = edge.second;

                // Case 1: Found a shorter path to v
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } 
                // Case 2: Found another path to v with the same minimum time
                else if (dist[u] + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
