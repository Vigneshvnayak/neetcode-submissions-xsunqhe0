class Solution {
public:
    int get_islands(int m, int n, vector<vector<int>> temp_grid) {
        int islands = 0;
        queue<pair<int,int>> q;
        //vector<vector<int>> temp_grid = grid;
        vector<int> dir = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp_grid[i][j] == 1) {
                    islands++;
                    q.push({i,j});
                    temp_grid[i][j] = 0;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        temp_grid[cur.first][cur.second] = 0;
                        for (int k = 0; k < 4; k++) {
                            int newi = cur.first + dir[k];
                            int newj = cur.second + dir[k + 1];
                            if (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                                temp_grid[newi][newj]) {
                                q.push({newi, newj});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        cout<<m<<n<<endl;
        for(vector<int>& p : positions) {
            grid[p[0]][p[1]] = 1;
            res.push_back(get_islands(m, n, grid));
        }
        return res;
    }
};