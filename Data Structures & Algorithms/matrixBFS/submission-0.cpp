class Solution {
public:
    int mr;
    int mc;
    int shortestPath(vector<vector<int>>& grid) {
        mr = grid.size();
        mc = grid[0].size();
        queue<pair<int,int>> q;
        int length = 0;
        vector<vector<int>> visit(mr, vector<int>(mc, 0));
        visit[0][0] = 1;
        q.push(pair<int, int>(0,0));

        while (q.size()) {
            int size = q.size();
            for (int k =0; k<size; k++) {
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if (r == mr-1 && c == mc-1) {
                    return length;
                }
                vector<vector<int>> dir = {{r, c+1}, {r, c-1}, {r+1, c}, {r-1, c}};
                for (int i =0; i<4; i++) {
                    int newr = dir[i][0];
                    int newc = dir[i][1];
                    if (min(newr, newc) < 0 || newr == mr || newc == mc ||
                    grid[newr][newc] || visit[newr][newc]) {
                        continue;
                    }
                    visit[newr][newc] = 1;
                    q.push(pair<int,int>(newr, newc));
                }
            } 
            length++;
        }
        return -1;
    }
};
