class RandomizedSet {
public:
    
    vector<int>arr;
    unordered_map<int,int>index_map;
    
    RandomizedSet() {
        arr.clear();
        index_map.clear();
    }
    
    bool insert(int val) {
        if(index_map.find(val)!=index_map.end()) return false;
        index_map[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(index_map.find(val)==index_map.end()) return false;
        int curridx = index_map[val];
        int lastidx = arr.size()-1;
        if(curridx==lastidx){
            arr.pop_back();
            index_map.erase(val);
        }
        else{
            index_map.erase(val);
            index_map[arr.back()] = curridx;
            arr[curridx] = arr.back();
            arr.pop_back();
        }
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