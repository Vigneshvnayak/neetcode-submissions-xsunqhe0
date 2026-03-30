class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int N = grid.size();
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mh;
       vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
       set<pair<int, int>> visit;

       mh.push({grid[0][0], 0, 0});
       visit.insert({0,0});
       while(!mh.empty()) {
        vector<int> temp = mh.top();
        mh.pop();
        int h = temp[0];
        int i = temp[1];
        int j = temp[2];
        if (i == N-1 && j == N-1) {
            return h;
        }
        for (vector<int> dir : d) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni < 0 || nj < 0 || ni == N || nj == N ||
            visit.count({ni, nj}) > 0) {
                continue;
            }
            mh.push({max(h, grid[ni][nj]), ni, nj});
            visit.insert({ni, nj});
        }
       }
       return N * N;
    }
};
