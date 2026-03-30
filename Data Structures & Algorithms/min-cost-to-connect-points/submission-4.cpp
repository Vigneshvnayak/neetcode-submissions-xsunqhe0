class UnionFind {
public:
    vector<int> _par;
    vector<int> _rank;
    int _n;

    UnionFind(int n) {
        _par.resize(n);
        _rank.resize(n);
        _n = n;
        for (int i=0; i<n; i++) {
            _par[i] = i;
        }
    }

    int find(int x) {
        int p = x;
        while (p != _par[p]) {
            _par[p] = _par[_par[p]];
            p = _par[p];
        }
        return _par[x];
    }

    bool _union(int x, int y) {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary) {
            if (_rank[parx] < _rank[pary]) {
                _par[parx] = pary;
                _rank[pary] += _rank[parx];
            } else {
                _par[pary] = parx;
                _rank[parx] += _rank[pary];
            }
            _n--;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        int n = points.size();
        for (int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int edge = abs(x2 - x1) + abs(y2 - y1);
                minheap.push({edge, i, j});
            }
        }
        int res = 0;
        UnionFind uf(n);
        while (!minheap.empty()) {
            vector<int> cur = minheap.top();
            minheap.pop();
            int w = cur[0];
            int x = cur[1];
            int y = cur[2];
            if (uf._union(x,y)) {
                res += w;
            }
        }
        return res;
    }
};
