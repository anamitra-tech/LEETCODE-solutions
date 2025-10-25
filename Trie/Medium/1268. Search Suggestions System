
    struct TrieNode {
        TrieNode* children[26];
        vector<string> suggestions; // store up to 3 smallest words
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    // Insert word into Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];

            // store up to 3 lexicographically smallest words
            if (node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // ensures lexicographic order

        TrieNode* root = new TrieNode();
        for (auto& word : products)
            insert(root, word);

        vector<vector<string>> result;
        TrieNode* node = root;

        for (char c : searchWord) {
            if (node) node = node->children[c - 'a'];
            if (node) result.push_back(node->suggestions);
            else result.push_back({});
        }

        return result;
    }
