class unionfind {
public:
    vector<int> parent, rank;

    unionfind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        int temp = x;
        while (temp != parent[temp]) {
            temp = parent[parent[temp]];
        }
        parent[x] = temp;
        return temp;
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        } else if (rank[px] >= rank[py]) {
            parent[py] = px;
            rank[px] += rank[py];
        } else {
            parent[px] = py;
            rank[py] += rank[px];
        }
        return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> edgelist;
        vector<vector<string>> res;
        unionfind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (edgelist.count(accounts[i][j]) > 0) {
                    uf.merge(edgelist[accounts[i][j]], i);
                } else {
                    edgelist[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int, set<string>> edgegroup; 
        for (auto [key, value] : edgelist) {
            int parent = uf.find(value);
            edgegroup[parent].insert(key);
        }
        for (auto [key, value] : edgegroup) {
            vector<string> merged;
            merged.push_back(accounts[key][0]);
            merged.insert(merged.end(), value.begin(), value.end());
            res.push_back(move(merged));
        }
        return res;
    }
};