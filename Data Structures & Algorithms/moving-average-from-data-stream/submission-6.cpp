class MovingAverage {
public:
    int size;
    int count;
    vector<int> window;
    MovingAverage(int size) {
       this->size = size; 
       this->count = 0;
       window.resize(size, 0);
    }
    
    double next(int val) {
       int index = count % size;
       window[index] = val;
       count++;
       int sum = accumulate(window.begin(), window.end(), 0);
       return (sum  * 1.0)/ min(count, size);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
