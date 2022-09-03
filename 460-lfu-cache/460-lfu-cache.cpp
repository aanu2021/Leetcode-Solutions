class Node{
    
  public:
    
    int key;
    int val;
    int cnt;
    Node*next;
    Node*prev;
    
    Node(int key,int val){
        
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
        cnt=1;
        
    }
    
};


class List{
    
  public:
    
    int size;
    Node*head;
    Node*tail;
    
    List(){
        
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        size=0;
        head->next=tail;
        tail->prev=head;
        
    }
    
    void addFront(Node*node){
        
        size++;
        
        Node*nexthead=head->next;
        
        head->next=node;
        node->prev=head;
        
        node->next=nexthead;
        nexthead->prev=node;
        
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
    
    int currSize;
    int maxSizeCache;
    int minFreq;
    unordered_map<int,List*>freqListMap;
    unordered_map<int,Node*>keyNode;
    
    LFUCache(int capacity) {
        
        minFreq=0;
        maxSizeCache=capacity;
        currSize=0;
        
    }
    
    void UpdateFreqListMap(Node*node){
        
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            
            minFreq++;
            
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
        
    }
    
    int get(int key) {
        
        if(keyNode.find(key)!=keyNode.end()){
            
            Node*node=keyNode[key];
            
            int currval=node->val;
            
            UpdateFreqListMap(node);
            
            return currval;
            
        }
        
        return -1;
        
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
                
                freqListMap[minFreq]->removeNode(list->tail->prev);
                
                currSize--;
                
            }
            
            currSize++;
            
            minFreq=1;
            
            List*newlist=new List();
            
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                
                newlist=freqListMap[minFreq];
                
            }
            
            Node*node=new Node(key,value);
            
            newlist->addFront(node);
            
            keyNode[key]=node;
            
            freqListMap[minFreq]=newlist;
            
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */