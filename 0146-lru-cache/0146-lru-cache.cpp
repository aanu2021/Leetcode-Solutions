class Node{
  
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    
    Node(int key,int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
    
};

class LRUCache {
public:
    
    Node*head = new Node(-1,-1);
    Node*tail = new Node(-1,-1);
    int capacity;
    unordered_map<int,Node*>mp;
    
    LRUCache(int cap) {
        head->next = tail;
        tail->next = head;
        capacity = cap;
        mp.clear();
    }
    
    void addNode(Node*node){
        Node*nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }
    
    void deleteNode(Node*node){
        Node*prevNode = node->prev;
        Node*nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node*node = mp[key];
            int nodeValue = node->val;
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return nodeValue;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*node = mp[key];
            deleteNode(node);
            node->val = value;
            addNode(node);
            mp[key] = head->next;
        }
        else{
            if(mp.size() == capacity){
                Node*node = tail->prev;
                int nodeKey = node->key;
                deleteNode(node);
                mp.erase(nodeKey);
            }
            Node*node = new Node(key,value);
            addNode(node);
            mp[key] = head->next;
        }
    }
};

