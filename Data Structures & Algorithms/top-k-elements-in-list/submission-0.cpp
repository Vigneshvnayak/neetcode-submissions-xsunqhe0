class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
	vector<int> res;
	for (int &n : nums) {
		mp[n]++;
	}
	for (auto [key,value] : mp) {
		if (value >= k) {
			res.push_back(key);
		}
	}
	return res;
 
    }
};
