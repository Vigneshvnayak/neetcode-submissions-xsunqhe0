class UnionFind {
    public:
    vector<int> rank, parent;

    UnionFind(int n) : rank(n, 1), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int f) {
        int x = f;
        while (x != parent[x]) {
            x = parent[parent[x]];
        }
        parent[f] = x;
        return x;
    }

    bool UnionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        if (rank[px] > rank[py]) {
            parent[py] = px;
            rank[px] += rank[py];
        } else {
            parent[px] = py;
            rank[py] += rank[px];
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgeList;
        for (int i=0; i < edges.size(); i++) {
            edgeList.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        UnionFind uf(n);
        int mst_og = 0;
        for (vector<int> &el : edgeList) {
            if (uf.UnionSet(el[0], el[1])) {
                mst_og += el[2];
            }
        }
        vector<int> critical;
        vector<int> pseudo;
        for (vector<int>& el : edgeList) {
            int weight = 0;
            UnionFind uf_without(n);
            for (vector<int> wel : edgeList) {
                if (el[3] != wel[3] && uf_without.UnionSet(wel[0], wel[1])) {
                    weight += wel[2];
                }
            }
            if (*max_element(uf_without.rank.begin(), uf_without.rank.end()) != n || weight > mst_og) {
                critical.push_back(el[3]);
                continue;
            }
            UnionFind uf_with(n);
            uf_with.UnionSet(el[0], el[1]);
            int weight_include = el[2];
            for (vector<int> iel : edgeList) {
                if (uf_with.UnionSet(iel[0], iel[1])) {
                    weight_include += iel[2];
                }
            }
            if (mst_og == weight_include) {
                pseudo.push_back(el[3]);
            }
        }
        return {critical, pseudo};
    }
};