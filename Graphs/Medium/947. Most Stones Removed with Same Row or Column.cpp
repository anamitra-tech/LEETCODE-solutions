class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (rankv[pa] < rankv[pb]) parent[pa] = pb;
        else if (rankv[pb] < rankv[pa]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rankv[pa]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Compare every stone with every other stone
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }

        int comps = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) comps++;
        }

        return n - comps;
    }
};
