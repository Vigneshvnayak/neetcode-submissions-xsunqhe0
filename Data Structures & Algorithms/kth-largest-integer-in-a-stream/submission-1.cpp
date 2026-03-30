class KthLargest {
    int _k;
	priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
       _k = k;
		for (int &n : nums) {
			add(n);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) {
			pq.pop();
	    }
        return pq.top();
    }
};
