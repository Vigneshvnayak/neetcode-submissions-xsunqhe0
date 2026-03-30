class Solution {
public:
    int mr;
    int mc;
    int orangesRotting(vector<vector<int>>& grid) {
       int res = INT_MAX;
       int fresh = 0;
       queue<pair<int,int>> mq;
       mr = grid.size();
       mc = grid[0].size();
       for (int i=0; i<mr; i++) {
        for (int j=0; j<mc; j++) {
            if (grid[i][j] == 2) {
                mq.push(pair<int,int>(i, j));
            } else if(grid[i][j] == 1) {
                fresh++;
            }
        }
       }
       int msize = mq.size();
       while(mq.size()) {
        pair<int, int> mp = mq.front();
        mq.pop();
        vector<vector<int>> visit(mr, vector<int>(mc, 0));
        queue<pair<int,int>> q;
        int time = -1;
        q.push(pair<int,int>(mp.first, mp.second));
        visit[mp.first][mp.second] = 1;
        while (q.size()) {
            int size = q.size();
            for (int i =0; i<size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                vector<vector<int>> dir = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};
                for(int j=0; j<4; j++) {
                    int newr = dir[j][0];
                    int newc = dir[j][1];
                    if (min(newr, newc) < 0 || newr == mr || newc == mc || !grid[newr][newc] ||
                    visit[newr][newc]) {
                        continue;
                    }
                    fresh--;
                    q.push(pair<int, int>(newr, newc));
                    visit[newr][newc] = 1;
                    }
                }
                time +=1;
            }
            res = min(time, res);
       }
       if (fresh != 0) {
        return -1;
       }
       return res;
   }
};
