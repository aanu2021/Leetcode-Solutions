class Node{
  
    public:
    
    int key;
    int value;
    int cnt;
    Node*next;
    Node*prev;
    
    Node(int key,int value){
        this->key = key;
        this->value = value;
        this->cnt = 1;
        this->next = NULL;
        this->prev = NULL;
    }
    
};

class List{
  
    public:
    
    Node*head;
    Node*tail;
    int size;
    
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNode(Node*node){
        Node*nextHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextHead;
        nextHead->prev = node;
        size++;
    }
    
    void deleteNode(Node*node){
        Node*nextNode = node->next;
        Node*prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
    
};

class LFUCache {
public:
    
    int currSize;
    int minFreq;
    int maxCapacity;
    unordered_map<int,List*>freqListMap;
    unordered_map<int,Node*>keyNode;
    
    LFUCache(int capacity) {
        currSize = 0;
        minFreq = 0;
        maxCapacity = capacity;
        freqListMap.clear();
        keyNode.clear();
    }
    
    void UpdateFreqListMap(Node*node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        node->cnt++;
        List*list = new List();
        if(freqListMap.find(node->cnt) != freqListMap.end()){
            list = freqListMap[node->cnt];
        }
        list->addNode(node);
        keyNode[node->key] = node;
        freqListMap[node->cnt] = list;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node*node = keyNode[key];
            int value = node->value;
            UpdateFreqListMap(node);
            return value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(maxCapacity == 0) return;
        
        if(keyNode.find(key) != keyNode.end()){
            Node*node = keyNode[key];
            node->value = value;
            UpdateFreqListMap(node);
            return;
        }
        else{
            if(currSize == maxCapacity){
                List*list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                freqListMap[minFreq] = list;
                currSize--;
            }
            currSize++;
            int currFreq = 1;
            minFreq = 1;
            Node*node = new Node(key,value);
            List*list = new List();
            if(freqListMap.find(currFreq) != freqListMap.end()){
                list = freqListMap[currFreq];
            }
            list->addNode(node);
            keyNode[key] = node;
            freqListMap[currFreq] = list;
        }
        
    }
};

