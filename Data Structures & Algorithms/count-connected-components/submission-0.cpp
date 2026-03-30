class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> rank(n, 1);
        int res = 0;
        for (int i=0; i<n; i++) {
            par[i] = i;
        }
        for (auto e : edges) {
            Union(par, rank, e[0], e[1]);
        }
        for (int i=0; i<n; i++) {
            if (i == par[i]) {
                res++;
            }
        }
        return res;
    }
private:
    int find(int n, vector<int>& par) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    void Union(vector<int> &par, vector<int> &rank, int n1, int n2) {
        int p1 = find(n1, par);
        int p2 = find(n2, par);
        if (rank[p1] >= rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
    }
};
