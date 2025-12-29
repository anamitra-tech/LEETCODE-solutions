#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // 1. Build Adjacency List: {neighbor, probability}
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // 2. Max-Heap to store {probability, node}
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        // 3. Keep track of the best probability found for each node
        vector<double> max_prob(n, 0.0);
        max_prob[start_node] = 1.0;

        while (!pq.empty()) {
            double curr_p = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // If we reached the end, this is the maximum probability path
            if (u == end_node) return curr_p;

            // If we already found a better path to u, skip this
            if (curr_p < max_prob[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                double path_prob = edge.second;

                // YOUR LOGIC: product = current * edge_probability
                if (max_prob[u] * path_prob > max_prob[v]) {
                    max_prob[v] = max_prob[u] * path_prob;
                    pq.push({max_prob[v], v});
                }
            }
        }

        return 0.0; // If end_node is unreachable
    }
};

//here this initially dfs had been used the major mistake was that since it was dfs so ans=min() walla should be 
//when src==destination and prob=1 main mat reset karo instead do visited=false to all so that it can be backtracked or traversed

