#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights)
            graph[f[0]].push_back({f[1], f[2]});

        using T = tuple<int, int, int>; // (cost, node, stops)
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, src, 0});

        // Track minimum cost to reach [node] with [stops] used
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto [nei, price] : graph[node]) {
                int newCost = cost + price;
                if (newCost < dist[nei][stops + 1]) {
                    dist[nei][stops + 1] = newCost;
                    pq.push({newCost, nei, stops + 1});
                }
            }
        }

        return -1;
    }
};

