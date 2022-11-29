class RandomizedCollection {
public:
    
    vector<int>arr;
    unordered_map<int,unordered_set<int>>index_map;
    
    RandomizedCollection() {
        arr.clear();
        index_map.clear();
    }
    
    bool insert(int val) {
        bool flag = true;
        if(index_map.find(val)!=index_map.end()) flag = false;
        index_map[val].insert(arr.size());
        arr.push_back(val);
        return flag;
    }
    
    bool remove(int val) {
        
        if(index_map.find(val)==index_map.end()) return false;
       
        int curridx = *index_map[val].begin();
        int lastidx = arr.size()-1;
        
        if(curridx==lastidx){
            
            arr.pop_back();
            index_map[val].erase(curridx);
            if(index_map[val].size()==0) index_map.erase(val);
            return true;
            
        }
        
      //  i   j
        
        else{
            
            arr[curridx] = arr[lastidx];
            index_map[val].erase(curridx);
            index_map[arr.back()].insert(curridx);
            index_map[arr.back()].erase(lastidx);
            if(index_map[val].size()==0) index_map.erase(val);
            arr.pop_back();
            return true;
            
        }
       
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */