class RandomizedSet {
public:
    
    vector<int>arr;
    
    unordered_map<int,int>mapp;
    
    RandomizedSet() {
        
        arr.clear();
        mapp.clear();
        
    }
    
    bool insert(int val) {
        
        if(mapp.find(val)!=mapp.end()){
            
            return false;
            
        }
        
        else{
            
            mapp[val]=arr.size();
            
            arr.push_back(val);
            
            return true;
            
        }
        
    }
    
    bool remove(int val) {
        
        if(mapp.find(val)==mapp.end()){
            
            return false;
            
        }
        
        else{
            
            int curr_index=mapp[val];
            
            int last_value=arr.back();
            
            int last_index=arr.size()-1;
            
            arr[curr_index]=last_value;
            
            mapp[last_value]=curr_index;
            
            mapp.erase(val);
            
            arr.pop_back();
            
            return true;
            
        }
        
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