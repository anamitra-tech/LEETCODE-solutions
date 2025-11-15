class Solution {
public:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = c;

        for (int nei : graph[node]) {

            // unvisited neighbor → give opposite color
            if (color[nei] == 0) {
                if (!dfs(nei, -c, graph, color))
                    return false;
            }

            // visited & same color → contradiction
            else if (color[nei] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        vector<int> color(N + 1, 0);

        // build adjacency list
        for (auto &d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        // DFS each unvisited node
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                if (!dfs(i, 1, graph, color))
                    return false;
            }
        }

        return true;
    }
};
