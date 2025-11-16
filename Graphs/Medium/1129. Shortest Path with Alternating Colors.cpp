#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        // 2 graphs: 0 = red, 1 = blue
        vector<vector<int>> graph[2];
        graph[0].resize(n);
        graph[1].resize(n);

        for (auto &e : redEdges) graph[0][e[0]].push_back(e[1]);
        for (auto &e : blueEdges) graph[1][e[0]].push_back(e[1]);

        // dist[node][color]
        vector<vector<int>> dist(n, vector<int>(2, 1e9));

        // Minheap for Dijkstra: (distance, node, lastColor)
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // Start node with both color states
        dist[0][0] = 0;
        dist[0][1] = 0;

        pq.push({0, 0, 0}); // dist, node, lastColor=red
        pq.push({0, 0, 1}); // dist, node, lastColor=blue

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int d = top[0];
            int node = top[1];
            int lastColor = top[2];

            if (d > dist[node][lastColor]) continue;

            int nextColor = 1 - lastColor;

            for (int nei : graph[nextColor][node]) {
                if (dist[node][lastColor] + 1 < dist[nei][nextColor]) {
                    dist[nei][nextColor] = dist[node][lastColor] + 1;
                    pq.push({dist[nei][nextColor], nei, nextColor});
                }
            }
        }

        // answer
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            if (best != 1e9) ans[i] = best;
        }
        return ans;
    }
};
