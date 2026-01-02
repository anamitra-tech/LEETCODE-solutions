#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> cnt(n, 1); // subtree sizes
        vector<int> ans(n, 0); // final answers; after dfs1, ans[0] is ready

        // Postorder DFS: compute cnt[u] and ans[u] for root=0
        function<void(int,int)> dfs1 = [&](int u, int p) {
            for (int v : adj[u]) if (v != p) {
                dfs1(v, u);
                cnt[u] += cnt[v];
                ans[u] += ans[v] + cnt[v];
            }
        };

        // Preorder DFS: reroot answers from parent u to child v
        function<void(int,int)> dfs2 = [&](int u, int p) {
            for (int v : adj[u]) if (v != p) {
                ans[v] = ans[u] - cnt[v] + (n - cnt[v]);
                dfs2(v, u);
            }
        };

        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
