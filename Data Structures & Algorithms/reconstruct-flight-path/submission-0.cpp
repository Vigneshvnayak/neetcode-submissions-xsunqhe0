class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       unordered_map<string, vector<string>> adj;
       unordered_set<string> visit;
       vector<string> res;
       for (vector<string> t : tickets) {
        adj[t[0]].push_back(t[1]);
       }
       if (adj.count("JFK") == 0) {
        return {};
       }
       priority_queue<string, vector<string>, greater<string>> pq;
       for (string s : adj["JFK"]) {
        pq.push(s);
        visit.insert("JFK"+s);
       }
       res.push_back("JFK");
       while (!pq.empty()) {
        string c = pq.top();
        pq.pop();
        res.push_back(c);
        for (string s : adj[c]) {
            if (visit.count(c+s) == 0) {
                pq.push(s);
                visit.insert(c+s);
            }
        }
       }
      return res; 
    }
};
