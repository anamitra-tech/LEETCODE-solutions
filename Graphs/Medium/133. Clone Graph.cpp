class Solution {
public:
    unordered_map<Node*, Node*> mp; // original -> clone

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        if (mp.find(node) != mp.end())
            return mp[node]; // already cloned
        
        Node* copy = new Node(node->val);
        mp[node] = copy; // mark as cloned
        
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei)); // recursively clone neighbors
        }
        
        return copy;
    }
};
