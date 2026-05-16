class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
public:
    Node* left;
    Node* right;
    unordered_map<int, Node*> map;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->left = new Node(-1,-1);
        this->right = new Node(-1, -1);
        this->left->next = right;
        this->right->prev = left;
    }

    void remove(Node* n) {
        Node* l = n->prev;
        Node* r = n->next;
        l->next = r;
        r->prev = l;
        return;
    }

    void update(Node* new_first) {
        Node* old_first = right->prev;
        old_first->next = new_first;
        new_first->prev = old_first;
        new_first->next = right;
        right->prev = new_first;
        return;
    }
    int get(int key) {
        if (!map.count(key)) return -1;
        Node* n = map[key];
        remove(n);
        update(n);
        return n->value;
    }
    
    void put(int key, int value) {
       if (map.count(key)) {
            Node* n = map[key];
            n->value = value;
            remove(n);
            update(n);
            return;
       } else {
            map[key] = new Node(key, value);
            update(map[key]);
        }
        if ((int)map.size() > capacity) {
            Node* lru = left->next;
            remove(lru);
            map.erase(lru->key);
            delete(lru);
        }
        return;
    }
};
