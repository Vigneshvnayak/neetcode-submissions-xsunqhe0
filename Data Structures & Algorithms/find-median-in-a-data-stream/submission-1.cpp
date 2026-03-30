class MedianFinder {
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;
public:
    MedianFinder() {} 
    
    void addNum(int num) {
       first.push(num);
       if (!second.empty() && first.top() > second.top()) {
            second.push(first.top());
            first.pop();
       }
       if (first.size() > second.size() + 1) {
            second.push(first.top());
            first.pop();
       }
       if (second.size() > first.size() + 1) {
            first.push(second.top());
            second.pop();
       }
    }
    
    double findMedian() {
        if (first.size() == second.size()) {
            return ((first.top() + second.top())/2.0);
        } else if (first.size() > second.size()) {
            return first.top()/1.0;
        } else {
            return second.top()/1.0;
        }
    }
};
