class Node{
    
   public:
    
    int key;
    int value;
    int cnt;
    Node * prev;
    Node * next;
    
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->cnt = 1;
        this->prev = NULL;
        this->next = NULL;
    }
};

class List{
  public:
    
    Node * head;
    Node * tail;
    int size;
    
    List(){
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->size = 0;
    }
    
    void addNode(Node * node){
        Node * prevNode = tail->prev;
        Node * nextNode = tail;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = nextNode;
        nextNode->prev = node;
        size++;
    }
    
    void removeNode(Node * node){
        Node * prevNode = node->prev;
        Node * nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
    
};

class LFUCache {
public:
    
    int currSize;
    int capacity;
    int minFreq;
    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqListMap;
    
    LFUCache(int capacity) {
        this->currSize = 0;
        this->capacity = capacity;
        this->minFreq = 1;
        this->keyNode.clear();
        this->freqListMap.clear();
    }
    
    void updateFreqListMap(Node * node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        node->cnt++;
        List * list = new List();
        if(freqListMap.find(node->cnt) != freqListMap.end()){
            list = freqListMap[node->cnt];
        }
        list->addNode(node);
        freqListMap[node->cnt] = list;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        Node * node = keyNode[key];
        int value = node->value;
        updateFreqListMap(node);
        return value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node * node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
            return;
        }
        if(currSize == capacity){
            Node * node = freqListMap[minFreq]->head->next;
            keyNode.erase(node->key);
            freqListMap[node->cnt]->removeNode(node);
            currSize--;
        }
        currSize++;
        minFreq = 1;
        Node * node = new Node(key, value);
        List * list = new List();
        if(freqListMap.find(minFreq) != freqListMap.end()){
            list = freqListMap[minFreq];
        }
        list->addNode(node);
        keyNode[node->key] = node;
        freqListMap[node->cnt] = list;
    }
};

