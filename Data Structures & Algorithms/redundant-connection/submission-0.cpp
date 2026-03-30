class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
       vector<int> par(n+1);
       vector<int> rank(n+1, 1);
       for (int i=0; i<=n; i++) {
        par[i] = i;
       }
       
       for (const auto& e : edges) {
            if(!Union(par, rank, e[0], e[1])) {
                return vector<int>{e[0], e[1]};
            }
       }
       return {};
    }
private: 
    int find(vector<int> &par, int n) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = find(par, n1);
        int p2 = find(par, n2);
        if (p1 == p2) {
            return false;
        }
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

};
