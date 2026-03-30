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
       return p;
    }

    bool _union(int x, int y) {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary) {
            if (_rank[parx] < _rank[pary]) {
                _par[parx] = pary;
                _rank[pary] += _rank[parx];
            }
            else {
                _par[pary] = parx;
                _rank[parx] += _rank[pary];
            }
            _n--;
            return true;
        }
        return false;
    }

    int get_num_components(void) {
        return _n;
    }
};
class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for (vector<int> &e : edges) {
            minheap.push({e[2], e[0], e[1]});
        }
        int res = 0;
        UnionFind uf(n);
        while (!minheap.empty()) {
            vector<int> cur = minheap.top();
            minheap.pop();
            int w = cur[0];
            int x = cur[1];
            int y = cur[2];
            if (uf._union(x, y)) {
                res += w;
            }
        }
        return (uf.get_num_components() != 1) ? -1 : res;
    }
};
