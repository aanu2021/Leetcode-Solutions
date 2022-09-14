class RandomizedSet {
public:
    
    vector<int>arr;
    
    unordered_map<int,int>mapp;
    
    RandomizedSet() {
        
        arr.clear();
        
    }
    
    bool insert(int val) {
        
        if(mapp.find(val)!=mapp.end()){
            
            return false;
            
        }
        
        arr.push_back(val);
        
        mapp[val]=arr.size()-1;
        
        return true;
        
    }
    
    bool remove(int val) {
        
        if(mapp.find(val)==mapp.end()){
            
            return false;
            
        }
        
        int index=mapp[val];
        
        int currvalue=arr[index];
        
        int lastval=arr.back();
        
        mapp[lastval]=index;
        
        mapp.erase(currvalue);
        
        arr[index]=lastval;
        
        arr.pop_back();
        
        return true;
        
    }
    
    int getRandom() {
        
        return arr[rand()%arr.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */