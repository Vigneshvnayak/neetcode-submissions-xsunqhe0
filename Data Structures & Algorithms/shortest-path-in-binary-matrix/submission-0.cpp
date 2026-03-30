class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	queue<vector<int>> q;
	vector<vector<int>> dir = {{0,1},
	                           {0,-1},
	                           {1,0},
	                           {-1,0},
                               {1,1},
                               {1,-1},
	                           {-1,1},
	                           {-1,-1}};
	int r = grid.size();
	int c = grid[0].size();
	vector<vector<int>> visit(r, vector<int>(c,0));
	if (grid[0][0]) {
	    return -1;
	}
	q.push({0,0});
    grid[0][0] = 1;
	while (q.size()) {
	   vector<int> t = q.front();
	   q.pop();
	   int i = t[0];
	   int j = t[1];
	   if (i == r-1 && j == c-1) {
		return grid[i][j];
	   }
	   for (vector<int> d : dir) {
	 	int newi = i + d[0];
		int newj = j + d[1];
	 	if (min(newi, newj) < 0 || newi >= r ||
	 	    newj >= c || grid[newi][newj]) {
	 		continue;
	 	}
	 	grid[newi][newj] = grid[i][j] + 1;
	    q.push({newi, newj});
	   }
	}
	return -1;
    }
};