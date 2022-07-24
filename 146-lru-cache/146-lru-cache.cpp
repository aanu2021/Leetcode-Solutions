class LRUCache {
public:
    
    list<int>keys;
    unordered_map<int,pair<int,list<int>::iterator>>mp;
    int Capacity;
    
    LRUCache(int capacity) {
        
        Capacity=capacity;
        
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            
            keys.erase(mp[key].second);
            
            keys.push_front(key);
            
            mp[key].second=keys.begin();
            
            return mp[key].first;
            
        }
        
        else{
            
            return -1;
            
        }
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
    
            keys.erase(mp[key].second);
            
            keys.push_front(key);
            
            mp[key]={value,keys.begin()};
            
            return;
            
        }
        
        else{
            
            if(Capacity==keys.size()){
                
                mp.erase(keys.back());
                
                keys.pop_back();
                
            }
            
            keys.push_front(key);
            
            mp[key]={value,keys.begin()};
            
            return;
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */