struct Node{
    
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
    
    int cap;
    unordered_map<int,Node*>mp;
    
    LRUCache(int capacity) {
        
        mp.clear();
        cap=capacity;
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
        
        Node*prev_node=node->prev;
        Node*next_node=node->next;
        
        prev_node->next=next_node;
        next_node->prev=prev_node;
        
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
        
        if(mp.size()==cap){
            
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