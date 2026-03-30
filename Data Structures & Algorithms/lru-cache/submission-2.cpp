class LRUCache {
public:
    int n;
    queue<int> q;
    unordered_map<int, int> mp;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
       if (mp.count(key)) {
            return mp[key];
       }
    }
    
    void put(int key, int value) {
        q.push(key);
        printf("%d\n", n);
        if (q.size() > n) {
            mp[q.front()] = -1;
            q.pop();
        }
        mp[key] = value;
    }
};
