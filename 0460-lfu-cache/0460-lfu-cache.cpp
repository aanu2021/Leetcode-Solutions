class Node{
  
    public:
    
    int key;
    int val;
    int cnt;
    Node*next;
    Node*prev;
    
    Node(int key,int val){
        this->key  = key;
        this->val  = val;
        this->cnt  = 1;
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
        Node*nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
        size++;
    }
    
    void deleteNode(Node*node){
        Node*prevNode = node->prev;
        Node*nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
    
};

class LFUCache {
public:
    
    unordered_map<int,List*>freqListMap;
    unordered_map<int,Node*>keyNode;
    int currSize;
    int minFreq;
    int capacity;
    
    LFUCache(int cap) {
        capacity = cap;
        currSize = 0;
        minFreq = 0;
        freqListMap.clear();
        keyNode.clear();
    }
    
    void UpdateFreqListMap(Node*node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
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
        if(keyNode.find(key)!=keyNode.end()){
            Node*node = keyNode[key];
            int nodeValue = node->val;
            UpdateFreqListMap(node);
            return nodeValue;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(capacity == 0) return;
        
        if(keyNode.find(key)!=keyNode.end()){
            Node*node = keyNode[key];
            node->val = value;
            UpdateFreqListMap(node);
        }
        else{
            if(currSize == capacity){
                List*list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
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

