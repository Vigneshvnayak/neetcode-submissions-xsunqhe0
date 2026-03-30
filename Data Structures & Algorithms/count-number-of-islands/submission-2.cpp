class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
	    int count = 0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    q.push({i,j});
                    count++;
                    while (!q.empty()) {
                        auto [curi, curj] = q.front();
                        q.pop();
                        if (curi < 0 || curj < 0 ||  curi >= grid.size() || 
                        curj >= grid[0].size() || grid[curi][curj] != '1') { 
                            continue;
                         }
                        grid[curi][curj] = '0';
                        q.push({curi, curj + 1});
                        q.push({curi, curj - 1});
                        q.push({curi + 1, curj});
                        q.push({curi - 1, curj});
                    }
                }
            }
        }
        return count;
    }
};
