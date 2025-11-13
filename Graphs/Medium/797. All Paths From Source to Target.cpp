#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(node);  // add current node to path

        if (node == graph.size() - 1) { // reached destination
            res.push_back(path);
        } else {
            for (int nei : graph[node]) {
                dfs(nei, graph, path, res);
            }
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, graph, path, res);
        return res;
    }
};
