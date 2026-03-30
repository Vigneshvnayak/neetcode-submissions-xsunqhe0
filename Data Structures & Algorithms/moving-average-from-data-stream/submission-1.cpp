class MovingAverage {
private:
    int left;
    int sz; 
    vector<int> q;
public:
    MovingAverage(int size) {
        left = 0;
        sz = size;
    }
    
    double next(int val) {
        double res = 0;
        q.push_back(val);
        if (q.size() - left > sz) {
            left++;
        }
        for (int i = left; i < q.size(); i++) {
            res += q[i];
        }
        return (res / static_cast<double>(q.size() - left));

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
