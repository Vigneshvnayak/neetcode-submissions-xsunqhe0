class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }
        
        queue<pair<int, int>> q;
        q.push({source, 0});
        unordered_set<int> visitedStops;
        vector<bool> visitedBuses(routes.size(), false);
        visitedStops.insert(source);

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int stop = cur.first;
            int dist = cur.second;

            if (stop == target) return dist;

            for (int busIdx : stopToBuses[stop]) {
                if (visitedBuses[busIdx]) continue;
                visitedBuses[busIdx] = true;
                for (int nextStop : routes[busIdx]) {
                    if (!visitedStops.count(nextStop)) {
                        visitedStops.insert(nextStop);
                        q.push({nextStop, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};