class DSU {
    std::vector<int> parent, rankv;
public:
    DSU(int n): parent(n), rankv(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (rankv[pa] < rankv[pb]) parent[pa] = pb;
        else if (rankv[pb] < rankv[pa]) parent[pb] = pa;
        else { parent[pb] = pa; rankv[pa]++; }
    }
};

class Solution {
public:
    bool equationsPossible(std::vector<std::string>& equations) {
        DSU dsu(26);
        // First pass: handle all equalities
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                dsu.unite(a, b);
            }
        }
        // Second pass: check inequalities
        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                if (dsu.find(a) == dsu.find(b)) return false;
            }
        }
        return true;
    }
};  
