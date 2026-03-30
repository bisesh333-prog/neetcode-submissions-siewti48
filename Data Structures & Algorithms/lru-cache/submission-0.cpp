class Node{
public:
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int v, int k) : val(v), key(k), prev(nullptr), next(nullptr){}

};

class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next=next;
        next->prev=prev;
    }

    void add(Node* node){
        Node*prev=right->prev;
        prev->next=node;
        node->prev=prev;
        node->next=right;
        right->prev=node;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        left = new Node(0,0), right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.count(key)){
            Node* node = cache[key];
            remove(node);
            add(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            node->val=value;
            remove(cache[key]);
            add(cache[key]);
        }
        else{
            Node* node =new Node(value,key);
            add(node);
            cache[key]=node;
            if(cache.size()>cap){
                Node* lru = left->next;
                cache.erase(lru->key);
                remove(lru);
                delete lru;
            }
        }
        
    }
};
