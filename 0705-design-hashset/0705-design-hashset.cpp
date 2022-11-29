class MyHashSet {
public:
    
    int size;
    vector<list<int>>m;
    
    MyHashSet() {
        size = 97;
        m.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<int>::iterator search(int key){
        int i = hash(key);
        auto it = m[i].begin();
        while(it!=m[i].end()){
            if(*it==key) return it;
            it++;
        }
        return it;
    }
    
    bool containsKey(int key){
        int i = hash(key);
        if(search(key)!=m[i].end()) return true;
        else return false;
    }
    
    void add(int key) {
        int i = hash(key);
        if(containsKey(key)) return;
        else m[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            m[i].erase(it);
        }
    }
    
    bool contains(int key) {
        return containsKey(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */