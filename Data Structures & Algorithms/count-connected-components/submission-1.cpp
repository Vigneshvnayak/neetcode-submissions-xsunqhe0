class unionfind {
public:
    vector<int> parent;
    vector<int> rank;
    
    unionfind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    int find(int x) {
        int temp = x;
        while (temp != parent[temp]) {
            temp = parent[parent[temp]];
        }
        parent[x] = temp; 
        return temp;
    }

    bool merge (int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
           if (rank[px] >= rank[py]) {
                parent[py] = px;
                rank[px] += rank[py];
           } else {
                parent[px] = py;
                rank[py] += rank[px];
           }
           return true;
        }
        return false;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
       unionfind uf(n);
       int res = n;
       for (vector<int> e : edges) {
            if (uf.merge(e[0], e[1])) {
                res--;
            }
       }
       return res;
    }
};
