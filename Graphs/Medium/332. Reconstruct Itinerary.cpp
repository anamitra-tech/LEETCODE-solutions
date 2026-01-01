class Solution {
private:
    void dfs(
        const string& u,
        unordered_map<string,
            priority_queue<string, vector<string>, greater<string>>>& adj,
        vector<string>& result
    ) {
        auto& pq = adj[u];
        while (!pq.empty()) {
            string v = pq.top();
            pq.pop();          // use this edge ONCE and remove it
            dfs(v, adj, result);
        }
        // post-order: add airport after all outgoing edges are used
        result.push_back(u);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,
            priority_queue<string, vector<string>, greater<string>>> adj;

        // build adjacency: from -> min-heap of destinations
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        vector<string> result;
        dfs("JFK", adj, result);
        reverse(result.begin(), result.end());
        return result;
    }
};
