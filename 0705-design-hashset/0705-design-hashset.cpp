class MyHashSet {
public:
    
    int size;
    vector<list<int>>m;
    
    MyHashSet() {
        this->size = 197;
        this->m.resize(size);
    }
    
    int hash(int key){
        return (key % size);
    }
    
    list<int>:: iterator search(int key){
        int i = hash(key);
        auto it = m[i].begin();
        while(it != m[i].end()){
            if(*it == key) return it;
            it++;
        }
        return it;
    }
    
    void add(int key) {
        int i = hash(key);
        if(contains(key)) return;
        m[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash(key);
        if(contains(key)){
            auto it = search(key);
            m[i].erase(it);
        }
    }
    
    bool contains(int key) {
        int i = hash(key);
        auto it = search(key);
        if(it != m[i].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */