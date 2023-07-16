class Node{
  
    public:
    int key;
    int value;
    Node*next;
    Node*prev;
    
    Node(int key,int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
    
};

class LRUCache {
public:
    
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    int capacity;
    unordered_map<int,Node*>keyMap;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node*node){
        Node * prevptr = tail->prev;
        Node * nextptr = tail;
        prevptr->next = node;
        node->prev = prevptr;
        node->next = nextptr;
        nextptr->prev = node;
    }
    
    void removeNode(Node*node){
        Node*prevptr = node->prev;
        Node*nextptr = node->next;
        prevptr->next = nextptr;
        nextptr->prev = prevptr;
    }
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end()){
            return -1;
        }
        else{
            Node*node = keyMap[key];
            removeNode(node);
            addNode(node);
            keyMap[key] = node;
            return node->value;
        }
    }
    
    void put(int key, int value) {
        if(keyMap.find(key) != keyMap.end()){
            Node*node = keyMap[key];
            node->value = value;
            removeNode(node);
            addNode(node);
            keyMap[key] = node;
        } 
        else{
            if(keyMap.size() == capacity){
                Node*node = head->next;
                keyMap.erase(node->key);
                removeNode(node);
            }
            Node*node = new Node(key,value);
            addNode(node);
            keyMap[key] = node;
        }
    }
};

