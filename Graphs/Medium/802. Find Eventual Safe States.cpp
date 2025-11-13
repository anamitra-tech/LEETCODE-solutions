#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdeg(n, 0);
        vector<vector<int>> rev(n);
        
        // build reverse graph and record outdegrees
        for (int u = 0; u < n; ++u) {
            outdeg[u] = graph[u].size();
            for (int v : graph[u]) {
                rev[v].push_back(u); // reverse edge
            }
        }
        
        queue<int> q;
        // start with terminal nodes (outdeg == 0)
        for (int i = 0; i < n; ++i)
            if (outdeg[i] == 0) q.push(i);
        
        vector<int> safe;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            safe.push_back(u);
            for (int pred : rev[u]) {
                outdeg[pred]--;
                if (outdeg[pred] == 0) q.push(pred);
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};
