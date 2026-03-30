class CountSquares {
public:
    unordered_map<long, int> pts_count;
    vector<vector<int>> pts;
    long get_key(int x, int y) {
      return (static_cast<long>(x) << 32) | 
        static_cast<long>(y);
    }
    CountSquares() {
    }
    
    void add(vector<int> point) {
        long key = get_key(point[0], point[1]);
        pts_count[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
       int res = 0;
       int x = point[0];
       int y = point[1];
       for (const auto &p : pts) {
        int px = p[0];
        int py = p[1];
        if (abs(px - x) != abs(py - y) || x == px || y == py) {
            continue;
        }
        res += pts_count[get_key(px,y)] * pts_count[get_key(x,py)];
       }
       return res;
    }
};
