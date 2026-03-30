class MedianFinder {
    priority_queue<int> first;
	priority_queue<int, vector<int>, greater<int>> second;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        first.push(num);
		if ((!first.empty() && !second.empty()) && first.top() > second.top()) {
			int small = second.top();
			second.pop();
			int large = first.top();
			first.pop();
			first.push(small);
			second.push(large);
		}
		if (first.size() - second.size() > 1) {
			int temp = first.top();
			first.pop();
			second.push(temp);
		}    
    }
    
    double findMedian() {
       double result;
		int size = first.size() + second.size();
		if (size % 2 == 0) {
			double temp1 = static_cast<double>(first.top());
			double temp2 = static_cast<double>(second.top());
			return (temp1 + temp2) / 2;
		}
		return first.top(); 
    }
};
