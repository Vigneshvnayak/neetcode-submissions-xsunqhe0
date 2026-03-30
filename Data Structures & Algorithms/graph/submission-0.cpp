class Graph {
unordered_map<int, unordered_set<int>> al;
public:
    Graph() {}
    void addEdge(int src, int dst) {
            al[src].insert(dst);
        }

    bool removeEdge(int src, int dst) {
        if (al.count(src)) {
            if (al[src].find(dst) != al[src].end()) {
                al[src].erase(dst);
                return true;
            } else {
                return false;
            }
         }
         return false;
    }

    bool hasPath(int src, int dst) {
        queue<int> q;
        unordered_set<int> visit;
        if (al.count(src)) {
            visit.insert(src);
            q.push(src);
        }
        while (q.size()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int temp = q.front();
                q.pop();
                if (temp == dst) {
                    return true;
                }
                for (int adj : al[temp]) {
                    if (visit.find(adj) == visit.end()) {
                        q.push(adj);
                        visit.insert(adj);
                    }
                }
            }
        }
        return false;
    }
};
