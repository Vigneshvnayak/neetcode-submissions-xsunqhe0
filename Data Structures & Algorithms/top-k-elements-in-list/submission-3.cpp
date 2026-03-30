class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
	vector<pair<int, int>> 	arr;
	vector<int> res;
	for (int &n : nums) {
		mp[n]++;
	}
	for (auto [key, value] : mp) {
		arr.push_back({value, key});
	}
	sort(arr.rbegin(), arr.rend());
	for (int i=0; i<k; i++) {
		res.push_back(arr[i].second);
	}
	return res;

    }
};
