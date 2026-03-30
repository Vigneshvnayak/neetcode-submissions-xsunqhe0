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
        if (parent[x] >= 0) {
            return;
        }
        parent[x] = x;
        count++;
    }

    bool is_island(int x) {
       if (parent[x] >= 0)  {
            return true;
       }
       return false;
    }

    int find(int x) {
        int temp = x;
        while (temp != parent[temp]) {
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
            rank[px] += rank[py];
        } else {
            parent[px] = py;
            rank[py] += rank[px];
        }
        count--;
        return;
    }

};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU du(m * n);
        vector<int> res;
        vector<int> dir = {0, 1, 0, -1, 0};
        for (vector<int> p : positions) {
            int flat_position = p[0] * n + p[1];
            du.add_island(flat_position);
            for (int i = 0; i < 4; i++) {
                int newx = p[0] + dir[i];
                int newy = p[1] + dir[i + 1];
                int new_flat_position = newx * n + newy;
                if (newx >= 0 && newy >= 0 && newx < m && newy < n && du.is_island(new_flat_position)) {
                    du.merge(flat_position, new_flat_position);
                }
            }
            res.push_back(du.count);
        }
        return res;
    }
};
