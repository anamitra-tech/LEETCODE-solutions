#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<bool> hasIncomingEdge(n, false);

        // Step 2: Loop through the edges (Your i, j logic style)
        for (auto& edge : edges) {
            int to = edge[1]; 
            hasIncomingEdge[to] = true; 
        }

        // Step 3: Any node that NO ONE points to must be a starting point
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!hasIncomingEdge[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};

//always in dag always used indegree algorithm
