class MyHashMap {
public:
    
    vector<list<pair<int,int>>>m;
    int size;
    
    MyHashMap() {
        size = 97;
        m.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<pair<int,int>>::iterator search(int key){
        int i = hash(key);
        auto it = m[i].begin();
        while(it!=m[i].end()){
            if(it->first==key) return it;
            it++;
        }
        return it;
    }
    
    bool containsKey(int key){
        int i = hash(key);
        if(search(key)!=m[i].end()) return true;
        else return false;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            it->second = value;
        }else{
            m[i].push_back({key,value});
        }
    }
    
    int get(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            return it->second;
        }else{
            return -1;
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            m[i].erase(it);
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