class MyHashMap {
public:
    
    int size;
    vector<list<pair<int,int>>>m;
    
    MyHashMap() {
        this->size = 197;
        this->m.resize(size);
    }
    
    int hash(int key){
        return (key % size);
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
        auto it = search(key);
        if(it != m[i].end()) return true;
        else return false;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            it->second = value;
        }
        else{
            m[i].push_back({key, value});
        }
    }
    
    int get(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        if(containsKey(key)){
            auto it = search(key);
            m[i].erase(it);
        }
    }
};

