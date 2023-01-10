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
    
    unordered_map<int,List*>freqListMap;  // freq , [n1 , n2 , n3 , .....]
    unordered_map<int,Node*>keyNode;      // key , node address
    int capacity;                         // Maximum Capacity
    int currSize;                         // currsize of the Cache
    int minFreq;                          // minimum freq among all the currently present nodes
    
    LFUCache(int cap) {
        currSize = 0;
        minFreq = 0;
        capacity = cap;
        freqListMap.clear();
        keyNode.clear();
    }
    
    // Below function is used to update the cnt of the current node , which are used how many number of times . 
    
    void UpdateFreqListMap(Node*node){
        
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        
        node->cnt++;
        List*list = new List();
        if(freqListMap.find(node->cnt)!=freqListMap.end()){
            list = freqListMap[node->cnt];
        }
        
        list->addNode(node);
        freqListMap[node->cnt] = list;
        keyNode[node->key] = node;
        
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node*node = keyNode[key];
            int currvalue = node->val;
            UpdateFreqListMap(node);
            return currvalue;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        // Corner Case
        if(capacity == 0) return;
        
        // We already have a node with the desired key. 
        
        if(keyNode.find(key)!=keyNode.end()){
            
            Node*node = keyNode[key];
            node->val = value;
            UpdateFreqListMap(node);
            
        }
        
        // There is no node with that particular value.
        
        else{
            
            if(currSize == capacity){
                List*list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
               // freqListMap[minFreq] = list;
                currSize--;
            }
            
            currSize++;
            Node*node = new Node(key,value);
            int currFreq = 1;
            minFreq = 1;
            List*list = new List();
            if(freqListMap.find(currFreq)!=freqListMap.end()){
                list = freqListMap[currFreq];
            }
            list->addNode(node);
            freqListMap[currFreq] = list;
            keyNode[node->key] = node;
            
        }
        
    }
};

