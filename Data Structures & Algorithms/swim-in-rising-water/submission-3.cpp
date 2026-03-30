class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<int> dir = {0, 1, 0, -1, 0};
       priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
       unordered_set<int> visit;
       pq.push({grid[0][0], 0, 0});
       while (!pq.empty()) {
            tuple<int, int, int> t = pq.top();
            pq.pop();
            int w = get<0>(t);
            int i = get<1>(t);
            int j = get<2>(t);
            int flat = i * n + j;
            if (visit.count(flat)) {
                continue;
            }
            visit.insert(flat);
            if (i == m - 1 && j == n - 1) {
                return w;
            }
            for (int x = 0; x < 4; x++) {
                int newi = i + dir[x];
                int newj = j + dir[x + 1];
                if (newi < 0 || newj < 0 || newi >= m || newj >= n) {
                    continue;
                }
                int newflat = newi * n + newj;
                if (visit.count(newflat)) {
                    continue;
                }
                pq.push({max(grid[newi][newj], w), newi, newj});
            }
       }
       return -1;
    }
};
