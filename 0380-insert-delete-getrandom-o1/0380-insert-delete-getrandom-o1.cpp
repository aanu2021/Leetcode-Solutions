class RandomizedSet {
public:
    
    vector<int>arr;
    unordered_map<int,int>indexMap;
    
    RandomizedSet() {
        arr.clear();
        indexMap.clear();
    }
    
    bool insert(int val) {
        if(indexMap.find(val) != indexMap.end()) return false;
        indexMap[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(indexMap.find(val) == indexMap.end()) return false;
        int currIndex = indexMap[val];
        if(currIndex == arr.size() - 1){
            indexMap.erase(val);
            arr.pop_back();
        }
        else{
            int lastIndex = arr.size() - 1;
            indexMap[arr[lastIndex]] = currIndex;
            indexMap.erase(val);
            swap(arr[currIndex], arr[lastIndex]);
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