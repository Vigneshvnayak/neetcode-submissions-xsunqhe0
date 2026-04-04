class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<int> dist(n, INT_MAX);
       dist[src] = 0;
       for (int i = 0; i <=k; i++) {
            vector<int> tempdist = dist;
            for (vector<int> flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if (dist[s] == INT_MAX) {
                    continue;
                }
                if (dist[s] + p < tempdist[d]) {
                    tempdist[d] = dist[s] + p;
                }
            }
            dist = tempdist;
       }
       return (dist[dst] != INT_MAX) ? dist[dst] : -1;
    }
};
