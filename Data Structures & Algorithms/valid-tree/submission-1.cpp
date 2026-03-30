class UnionFind {
public:
    vector<int> par;
    vector<int> rank;

    UnionFind(int n) {
        for (int i=0; i<n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x) {
        int p = par[x];
        while (p != par[p]) {
            p = par[p];
        }
        par[x] = p;
        return par[x];
    }
    bool _union(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra != rb) {
            if (rank[a] >= rank[b]) {
                par[b] = a;
                rank[a] += rank[b];
            } else {
                par[a] = b;
                rank[b] += rank[a];
            }
        } else {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (vector<int> e : edges) {
            if (!uf._union(e[0], e[1])) {
                return false;
            }
        }
        int count = 0;
        for (int i=0; i<n; i++) {
            if (uf.par[i] == i) {
                if (++count > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
