class Solution {
public:
    // returns true if after skipping edge skipIdx, graph is a rooted tree:
    // i.e., no cycle and all nodes are processed by Kahn (processed == n)
    bool okAfterSkip(int n, const vector<vector<int>>& edges, int skipIdx) {
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (i == skipIdx) continue;
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0) q.push(i);

        int processed = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            processed++;
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return processed == n; // processed != n => cycle exists (Kahn criterion)
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();

        // 1) Find if any node has two parents; store the two edge indices.
        vector<int> parentEdgeIdx(n + 1, -1);
        int cand1 = -1, cand2 = -1;
        for (int i = 0; i < n; i++) {
            int v = edges[i][1];
            if (parentEdgeIdx[v] == -1) parentEdgeIdx[v] = i;
            else { cand1 = parentEdgeIdx[v]; cand2 = i; break; }
        }

        // 2) Two-parents case: try removing the later edge first.
        // If graph becomes valid, remove cand2 else remove cand1.
        if (cand1 != -1) {
            if (okAfterSkip(n, edges, cand2)) return edges[cand2];
            return edges[cand1];
        }

        // 3) No two parents: only a cycle exists.
        // Try remove edges from back to front; first that makes it valid is answer.
        for (int i = n - 1; i >= 0; i--) {
            if (okAfterSkip(n, edges, i)) return edges[i];
        }
        return {};
    }
};

