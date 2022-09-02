class Node{
    
  public:  
    
  int key; 
  int val;
  Node*next;
  Node*prev;
    
  Node(int key,int val){
      
      this->key=key;
      this->val=val;
      next=NULL;
      prev=NULL;
      
  }  
    
};

class LRUCache {
public:
    
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    
    int capacity;
    
    map<int,Node*>mp;
    
    
    LRUCache(int cap) {
        
        capacity=cap;
        
        head->next=tail;
        tail->prev=head;
        
    }
    
    void addNode(Node*node){
        
        Node*nexthead=head->next;
        
        head->next=node;
        node->prev=head;
        
        node->next=nexthead;
        nexthead->prev=node;
        
    }
    
    void deleteNode(Node*node){
        
        Node*nextnode=node->next;
        
        Node*prevnode=node->prev;
        
        prevnode->next=nextnode;
        
        nextnode->prev=prevnode;
        
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            
            Node*node=mp[key];
            
            int currval=node->val;
            
            mp.erase(key);
            
            deleteNode(node);
            
            addNode(node);
            
            mp[key]=head->next;
            
            return currval;
            
        }
        
        else{
            
            return -1;
            
        }
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            
            Node*node=mp[key];
            
            mp.erase(key);
            
            deleteNode(node);
            
        }
        
            
            if(mp.size()==capacity){
                
                mp.erase(tail->prev->key);
                
                deleteNode(tail->prev);
                
            }
            
        
        addNode(new Node(key,value));
            
        mp[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */