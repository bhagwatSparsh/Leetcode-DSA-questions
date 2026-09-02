class LRUCache {
public:
    class Node {
    public: 
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void add_node_after_head(Node* new_node) {
        Node* temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }

    void delete_node(Node* del_node) {
        Node* del_prev = del_node->prev;
        Node* del_next = del_node->next;
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];
        int res = node->val;

        // Move the accessed node to the front (MRU position)
        delete_node(node);
        add_node_after_head(node);

        return res;
    }
    
    void put(int key, int value) {
        // Case 1: Key already exists -> update value & move to head
        if (mpp.find(key) != mpp.end()) {
            Node* existing_node = mpp[key];
            existing_node->val = value; // update value in place
            delete_node(existing_node);
            add_node_after_head(existing_node);
            return;
        }

        // Case 2: Capacity reached -> evict LRU node (node before tail)
        if (mpp.size() == cap) {
            Node* lru_node = tail->prev;
            mpp.erase(lru_node->key);
            delete_node(lru_node);
            delete lru_node; // free memory
        }

        // Case 3: Insert new node
        Node* new_node = new Node(key, value);
        mpp[key] = new_node;
        add_node_after_head(new_node);
    }
};