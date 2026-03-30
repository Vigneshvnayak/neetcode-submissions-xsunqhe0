class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
		vector<int> count(26, 0);
		priority_queue<int> maxheap;
		for (char t : tasks) {
			count[t - 'A']++;
		}
		for (int i=0; i<26; i++) {
			if (count[i] > 0) {
				maxheap.emplace(count[i]);
			}
		}
		int cycle = 0;
		queue<pair<int,int>> q;
		while (!maxheap.empty() || !q.empty()) {
			cycle++;
			if (maxheap.empty()) {
				cycle = q.front().second;
			} else {
				int freq = maxheap.top() - 1;
				maxheap.pop();
				if (freq > 0) q.push({freq, cycle + n});
			}
			if (!q.empty() && cycle == q.front().second) {
				maxheap.emplace(q.front().first);
				q.pop();
			}
		}
		return cycle;
 
    }
};
