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
    
    Node*head = new Node(-1,-1);
    Node*tail = new Node(-1,-1);
    int capacity;
    unordered_map<int,Node*>keyNode;
    
    LRUCache(int capacity) {
        keyNode.clear();
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node*node){
        Node * prevNode = tail->prev;
        Node * nextNode = tail;
        node->prev = prevNode;
        prevNode->next = node;
        node->next = nextNode;
        nextNode->prev = node;
    }
    
    void removeNode(Node*node){
        Node * prevNode = node->prev;
        Node * nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }
        else{
            Node*node = keyNode[key];
            int value = node->value;
            removeNode(node);
            addNode(node);
            keyNode[key] = node;
            return value;
        }
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()){
            Node*node = keyNode[key];
            node->value = value;
            removeNode(node);
            addNode(node);
            keyNode[key] = node;
            return;
        }
        if(keyNode.size() == capacity){
            Node*node = head->next;
            int currKey = node->key;
            removeNode(node);
            keyNode.erase(currKey);
        }
        Node*node = new Node(key,value);
        addNode(node);
        keyNode[key] = node;
    }
};
