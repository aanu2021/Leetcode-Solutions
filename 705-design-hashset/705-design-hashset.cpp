class MyHashSet {
public:
    
    vector<int>arr;
    
    int MAX = 1e6 + 5;
    
    MyHashSet() {
        
        arr.clear();
        arr.resize(MAX,0);
        
    }
    
    void add(int key) {
        
        arr[key]=1;
        
    }
    
    void remove(int key) {
        
        arr[key]=0;
        
    }
    
    bool contains(int key) {
        
        return arr[key];
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */