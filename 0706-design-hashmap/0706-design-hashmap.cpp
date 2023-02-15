class MyHashMap {
public:
    
    vector<list<pair<int,int>>>m;
    int size;
    
    MyHashMap() {
        size = 97;
        m.resize(size);
    }
    
    int hash(int key){
        return (key%size);
    }
    
    list<pair<int,int>>::iterator search(int key){
        int i = hash(key);
        auto it = m[i].begin();
        while(it != m[i].end()){
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    bool containsKey(int key){
        int i = hash(key);
        if(search(key) == m[i].end()) return false;
        else return true;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        if(containsKey(key)){
            auto itr = search(key);
            itr->second = value;
        }
        else{
            m[i].push_back({key,value});
        }
    }
    
    int get(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto itr = search(key);
            return itr->second;
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto itr = search(key);
            m[i].erase(itr);
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