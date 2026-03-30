class Solution {
public:
    string multiply(string num1, string num2) {
       if (num1 == "0" || num2 == "0") {
		return "0";
	}
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	vector<int> nums(num1.length() + num2.length(), 0);
	for (int i=0; i < num1.length(); i++) {
		for (int j=0; j < num2.length(); j++) {
			nums[i+j] += (num1[i] - '0') * (num2[j] - '0');
			nums[i+j+1] += nums[i+j] / 10;
			nums[i+j] = nums[i+j] % 10;
		}
	}
	stringstream ss;
	int k = nums.size() - 1;
	while (k >= 0 && nums[k] == 0) {
		k--;
	}
	while (k >= 0) {
		ss << nums[k--];
	}
	return ss.str();
    }
};
