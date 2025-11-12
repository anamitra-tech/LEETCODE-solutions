#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // build adjacency list: node -> list of (neighbor, weight)
        vector<vector<pair<int,int>>> adj(N + 1);
        for (auto &t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        // distances, init to +inf
        const int INF = numeric_limits<int>::max();
        vector<int> dist(N + 1, INF);
        dist[K] = 0;

        // min-heap of (distance, node)
        using pii = pair<int,int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, K});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();

            // stale entry check
            if (d > dist[node]) continue;

            for (auto &edge : adj[node]) {
                int nei = edge.first;
                int w = edge.second;
                if (dist[nei] > d + w) {
                    dist[nei] = d + w;
                    pq.push({dist[nei], nei});
                }
            }
        }

        // find the maximum distance to any reachable node (1..N)
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == INF) return -1; // unreachable node
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
