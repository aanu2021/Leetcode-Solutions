class RandomizedSet {
public:
    
    vector<int>arr;
    unordered_map<int,int>index_Map;
    
    RandomizedSet() {
        arr.clear();
        index_Map.clear();
    }
    
    bool insert(int val) {
        if(index_Map.find(val) != index_Map.end()) return false;
        index_Map[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(index_Map.find(val) == index_Map.end()) return false;
        int currIdx = index_Map[val];
        int lastIdx = arr.size() - 1;
        if(currIdx == lastIdx){
            index_Map.erase(val);
            arr.pop_back();
        }
        else{
            index_Map.erase(val);
            arr[currIdx] = arr.back();
            index_Map[arr.back()] = currIdx;
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