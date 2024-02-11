/*
  ***Problem Desc***:
    - get -> if key exist then ret val and bring to top of cache | else ret -1
    - put -> if key exist then change val of the node, bring to top of cache | else create key, put in cache, evict from cache if need be
*/
// ***double LL for cache with a map of key to ptr[O(1) get, O(1) put | O(n) space]***:

struct doubleLL {
    int key, val; doubleLL *prev, *next;
    doubleLL(int key, int val): key(key), val(val) {}
};

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {
        pos.clear();
    }
    
    int get(int key) {
        if (pos.find(key) == pos.end()) return -1;
        doubleLL *ptr = pos[key];
        remove(ptr);
        insert(ptr);
        return pos[key]->val;
    }
    
    void put(int key, int value) {
        if (pos.find(key) == pos.end()) insert(new doubleLL(key, value));
        else {
            pos[key]->val = value;
            get(key);
        }
        
    }
private:
    int size = 0, cap;
    doubleLL *head, *tail;
    unordered_map<int, doubleLL*> pos;
    void insert(doubleLL* node) {
        if (size == cap) remove(tail);
        
        if (size == 0) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        } 
        pos.insert({node->key, node});
        size++;
    }

    void remove(doubleLL* node) {
        if (node == head && node == tail) {
            head = NULL; tail = NULL; 
        } else if (node == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else if (node == head) {
            head = node->next;
            head->prev = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        pos.erase(node->key);
        size--;
    }
};
