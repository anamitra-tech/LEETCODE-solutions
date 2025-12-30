#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    // Initialize structures from your logic
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    vector<set<int>> ancestorSets(n); // Using set to handle unique/sorted ancestors

    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    // To use your "indegree[v]--" logic effectively, we need a starting point.
    // We start with nodes that have 0 indegree (no ancestors).
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            // Your logic: If node v has remaining incoming edges
            if (indegree[v] > 0) {
                // 1. Add the immediate parent u to v's ancestors
                ancestorSets[v].insert(u);
                
                // 2. Add all of u's ancestors to v (This completes the "All Ancestors" logic)
                for (int anc : ancestorSets[u]) {
                    ancestorSets[v].insert(anc);
                }

                // 3. Decrement indegree (Your logic)
                indegree[v]--;

                // When indegree hits 0, all ancestors have been collected
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    // Convert sets back to vector<vector<int>> for the final result
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++) {
        result[i].assign(ancestorSets[i].begin(), ancestorSets[i].end());
    }
    return result;
}


//here  vector<int> indegree(n, 0); has been used and not map<int,int> as the speed complexity of 
//map is logn and that of vector is 1
//why vector<set<int>> isliye as everyone will have unique and sorted answer and all stored in n tyoe boxes
