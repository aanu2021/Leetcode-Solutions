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
        Node*prevptr = tail->prev;
        Node*nextptr = tail;
        prevptr->next = node;
        node->prev = prevptr;
        node->next = nextptr;
        nextptr->prev = node;
        size++;
    }
    
    void removeNode(Node*node){
        Node*prevptr = node->prev;
        Node*nextptr = node->next;
        prevptr->next = nextptr;
        nextptr->prev = prevptr;
        size--;
    }
    
};

class LFUCache {
public:
    
    int currSize;
    int minFreq;
    int maxCapacity;
    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqListMap;
    
    LFUCache(int capacity) {
        this->maxCapacity = capacity;
        this->currSize = 0;
        this->minFreq = 0;
        this->keyNode.clear();
        this->freqListMap.clear();
    }
    
    void updateFreqListMap(Node*node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
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
        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }
        else{
            Node*node = keyNode[key];
            int value = node->value;
            updateFreqListMap(node);
            return value;
        }
    }
    
    void put(int key, int value) {
        if(maxCapacity == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node*node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(currSize == maxCapacity){
                Node*node = freqListMap[minFreq]->head->next;
                keyNode.erase(node->key);
                freqListMap[minFreq]->removeNode(node);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            Node*node = new Node(key,value);
            List*list = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                list = freqListMap[minFreq];
            }
            list->addNode(node);
            freqListMap[minFreq] = list;
            keyNode[key] = node;
        }
    }
};

