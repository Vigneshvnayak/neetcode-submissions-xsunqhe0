class DSU {
public:
    vector<int> parent, rank;
    int count;

    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 0);
        count = 0;
    }

   void add_island(int x) {
        if (parent[x] < 0) {
           parent[x] = x;
           count++;
        }
        return;
   }

   bool is_island(int x) {
        if (parent[x] >= 0) {
            return true;
        }
        return false;
   }

   int find(int x) {
        int temp = x;
        while(temp != parent[temp]) {
            temp = parent[parent[temp]];
        }
        parent[x] = temp;
        return temp;
   }

   void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) {
            return;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        count--;
   }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU du(m * n);
        vector<int> dir = {0, 1, 0, -1, 0};
        vector<int> res;

        for (vector<int> p : positions) {
            int land_pos = p[0] * n + p[1];
            du.add_island(land_pos);
            for (int i = 0; i < 4; i++) {
                int nei_x = p[0] + dir[i];
                int nei_y = p[1] + dir[i + 1];
                int nlp = nei_x * n + nei_y;
                if (nei_x >= 0 && nei_y >= 0 && nei_x < m && nei_y < n &&
                    du.is_island(nlp)) {
                        du.merge(land_pos, nlp);
                    }
            }
            res.push_back(du.count);
        }
        return res;
    }
};
