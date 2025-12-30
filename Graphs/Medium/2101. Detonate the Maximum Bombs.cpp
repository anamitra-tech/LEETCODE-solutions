#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int to;
    double weight;
};

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        // Adjacency list for undirected weighted graph
        // Storing {neighbor, distance}
        vector<vector<Edge>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = bombs[i][0] - bombs[j][0];
                double dy = bombs[i][1] - bombs[j][1];
                double dist = sqrt(dx * dx + dy * dy);

                // If either bomb can reach the other, we create an undirected edge
                if (dist <= (double)bombs[i][2] || dist <= (double)bombs[j][2]) {
                    adj[i].push_back({j, dist});
                    adj[j].push_back({i, dist});
                }
            }
        }

        int maxDetonated = 0;
        for (int i = 0; i < n; i++) {
            maxDetonated = max(maxDetonated, getReach(i, adj, bombs));
        }
        
        return maxDetonated;
    }

private:
    int getReach(int start, const vector<vector<Edge>>& adj, const vector<vector<int>>& bombs) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(bombs.size(), false);
        visited[start] = true;
        int count = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& edge : adj[u]) {
              
                if (!visited[edge.to] && edge.weight <= (double)bombs[u][2]) 
                {
                    count++;
                    visited[edge.to] = true;
                    q.push(edge.to);

                }
            }
        }
        return count;
    }
};
