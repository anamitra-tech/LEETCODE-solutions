class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // parent[i] will store the parent of node i, or -1 if none
        vector<int> parent(n, -1);

        // Assign parents and check that no node gets >1 parent
        for (int u = 0; u < n; ++u) {
            int l = leftChild[u];
            if (l != -1) {
                if (parent[l] != -1) return false; // l already has a parent -> invalid
                parent[l] = u;
            }
            int r = rightChild[u];
            if (r != -1) {
                if (parent[r] != -1) return false; // r already has a parent -> invalid
                parent[r] = u;
            }
        }

        // Find root: exactly one node should have parent == -1
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                if (root != -1) return false; // more than one root candidate -> invalid
                root = i;
            }
        }
        if (root == -1) return false; // no root -> invalid

        // Now check connectivity and cycles by DFS/BFS from root
        vector<char> visited(n, 0);
        stack<int> st;
        st.push(root);
        int count = 0;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (visited[node]) return false; // found a cycle / multiple visit
            visited[node] = 1;
            ++count;

            if (leftChild[node] != -1) st.push(leftChild[node]);
            if (rightChild[node] != -1) st.push(rightChild[node]);
        }

        // All nodes must be visited exactly once
        return count == n;
    }
};
