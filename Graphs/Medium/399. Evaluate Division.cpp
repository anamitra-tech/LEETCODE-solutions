class Solution {
public:
    double dfs(string start, string end,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited) {

        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;
        if (start == end)
            return 1.0;

        visited.insert(start);

        for (auto& [neighbor, value] : graph[start]) {
            if (visited.count(neighbor)) continue;

            double ans = dfs(neighbor, end, graph, visited);
            if (ans != -1.0)
                return ans * value;  // multiply along path
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> result;
        for (auto& q : queries) {
            unordered_set<string> visited;
            result.push_back(dfs(q[0], q[1], graph, visited));
        }

        return result;
    }
};
v
