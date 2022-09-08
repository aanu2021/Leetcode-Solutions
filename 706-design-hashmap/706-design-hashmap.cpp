class MyHashMap {
public:
    
    vector<list<pair<int,int>>>m;
    
    int size;
    
    MyHashMap() {
        
        size=109;
        
        m.resize(size);
        
    }
    
    int hash(int key){
        
        return key%size;
        
    }
    
    list<pair<int,int>> :: iterator search(int key){
        
        int i=hash(key);
        
        list<pair<int,int>> :: iterator it=m[i].begin();
        
        while(it!=m[i].end()){
            
            if(it->first==key){
                return it;
            }
            
            it++;
            
        }
        
        return it;
        
    }
    
    bool contains(int key){
        
        int i=hash(key);
        
        if(search(key)!=m[i].end()){
            return true;
        }else{
            return false;
        }
        
    }
    
    void put(int key, int value) {
        
        int i=hash(key);
        
        if(contains(key)){
            
            list<pair<int,int>> :: iterator it=search(key);
            
            it->second=value;
            
        }
        
        else{
            
            m[i].push_back({key,value});
            
        }
        
    }
    
    int get(int key) {
        
        int i=hash(key);
        
        if(contains(key)){
            
            list<pair<int,int>> :: iterator it=search(key);
            
            return it->second;
            
        }
        
        else{
            
            return -1;
            
        }
        
    }
    
    void remove(int key) {
        
        int i=hash(key);
        
        if(contains(key)){
            
            list<pair<int,int>> :: iterator it=search(key);
            
            m[i].erase(it);
            
        }
        
        else{
            
            return;
            
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */