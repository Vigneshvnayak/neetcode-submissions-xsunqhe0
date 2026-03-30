class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        	int r = grid.size();
	        int c = grid[0].size();
	        int count = 0;
	        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	        queue<vector<int>> q;
	        for (int i=0; i<r; i++) {
		        for (int j=0; j<c; j++) {
			        if (grid[i][j] == '1') {
				        count++;
				        q.push({i,j});
				        while (!q.empty()) {
					        vector<int> t = q.front();
					        q.pop();
					        grid[t[0]][t[1]] = '0';
					        for (vector<int> &d : dir) {
						        int newi = t[0] + d[0];
						        int newj = t[1] + d[1];
						        if (min(newi, newj) < 0 || newi >= r || newj >= c ||
							        grid[newi][newj] == '0') {
							        continue;
						        }
						        q.push({newi, newj});
					        }
				        }
			        }
		        }
	        }
	        return count;
    }
};
