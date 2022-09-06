class Node{
    
  public:
    
    int cnt;
    int key;
    int val;
    Node*next;
    Node*prev;
    
    Node(int key,int val){
        
        this->key=key;
        this->val=val;
        this->cnt=1;
        this->next=NULL;
        this->prev=NULL;
        
    }
    
};

class List{
    
  public:
    
    int size;
    Node*head;
    Node*tail;
    
    List(){
        
        size=0;
        
        head=new Node(0,0);
        tail=new Node(0,0);
        
        head->next=tail;
        tail->prev=head;
        
    }
    
    void addFront(Node*node){
        
        Node*nexthead=head->next;
        
        head->next=node;
        node->prev=head;
        
        node->next=nexthead;
        nexthead->prev=node;
        
        size++;
        
    }
    
    void removeNode(Node*node){
        
        Node*prevnode=node->prev;
        Node*nextnode=node->next;
        
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        
        size--;
        
    }
    
};

class LFUCache {
public:
    
    int maxSizeCache;
    int currSize;
    int minFreq;
    
    unordered_map<int,List*>freqListMap;
    unordered_map<int,Node*>keyNode;
    
    LFUCache(int capacity) {
        
        maxSizeCache=capacity;
        currSize=0;
        minFreq=0;
        
    }
    
    void UpdateFreqListMap(Node*node){
        
        keyNode.erase(node->key);
        
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            
            minFreq++;
            
        }
        
        node->cnt++;
        
        List*list=new List();
        
        if(freqListMap.find(node->cnt)!=freqListMap.end()){
            
            list=freqListMap[node->cnt];
            
        }
        
        list->addFront(node);
        
        freqListMap[node->cnt]=list;
        
        keyNode[node->key]=node;
        
    }
    
    int get(int key) {
        
        if(keyNode.find(key)!=keyNode.end()){
            
            Node*node=keyNode[key];
            
            int currval=node->val;
            
            UpdateFreqListMap(node);
            
            return currval;
            
        }
        
        else{
            
            return -1;
            
        }
        
    }
    
    void put(int key, int value) {
        
        if(maxSizeCache==0){
            return;
        }
        
        if(keyNode.find(key)!=keyNode.end()){
            
            Node*node=keyNode[key];
            
            node->val=value;
            
            UpdateFreqListMap(node);
            
        }
        
        else{
            
            if(currSize==maxSizeCache){
                
                List*list=freqListMap[minFreq];
                
                keyNode.erase(list->tail->prev->key);
                
                list->removeNode(list->tail->prev);
                
                currSize--;
                
            }
            
            currSize++;
            
            minFreq=1;
            
            Node*node=new Node(key,value);
            
            List*list=new List();
            
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                
                list=freqListMap[minFreq];
                
            }
            
            list->addFront(node);
            
            freqListMap[minFreq]=list;
            
            keyNode[key]=node;
            
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */