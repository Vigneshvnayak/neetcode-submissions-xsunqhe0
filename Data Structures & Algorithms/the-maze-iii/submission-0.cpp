class Solution {
public:
    int m, n;
    using state =  tuple<int, string, int, int>;
    vector<int> dir = {0, 1, 0, -1, 0};
    vector<string> dir_text = {"r", "d", "l", "u"};

    bool isValid(int row, int col, vector<vector<int>>& maze) {
        if (row < 0 || col < 0 || row >= m || col >= n) {
            return false;
        }
        return maze[row][col] == 0;
    }
    vector<state> getNext(int row, int col, vector<vector<int>>& maze, vector<int>& hole) {
        vector<state> neighbors;
        for(int i = 0; i < 4; i++) {
            int dx = dir[i];
            int dy = dir[i + 1];
            string direction = dir_text[i];
            int currow = row;
            int curcol = col;
            int dist = 0;
            while (isValid(currow + dx, curcol + dy, maze)) {
                currow += dx;
                curcol += dy;
                dist++;
                if (currow == hole[0] && curcol == hole[1]) {
                    break;
                }
            }
            neighbors.push_back(make_tuple(dist, direction, currow, curcol));
        }
        return neighbors;
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m = maze.size();
        n = maze[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push(make_tuple(0, "", ball[0], ball[1]));
        while (!pq.empty()) {
            state curr = pq.top();
            pq.pop();
            int curr_dist = get<0>(curr);
            string path = get<1>(curr);
            int row = get<2>(curr);
            int col = get<3>(curr);
            if (seen[row][col]) {
                continue;
            }
            if (row == hole[0] && col == hole[1]) {
                return path;
            }
            seen[row][col] = true;
            for (state next : getNext(row, col, maze, hole)) {
                int nextDist = get<0>(next);
                string nextPath = get<1>(next);
                int nextRow = get<2>(next);
                int nextCol = get<3>(next);
                pq.push(make_tuple(curr_dist + nextDist, path + nextPath, nextRow, nextCol));
            }
        }
        return "impossible";
    }
};
