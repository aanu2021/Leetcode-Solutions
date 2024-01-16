class RandomizedCollection {
public:
    
    vector<int>arr;
    unordered_map<int,unordered_set<int>>indexMap;
    
    RandomizedCollection() {
        arr.clear();
        indexMap.clear();
    }
    
    bool insert(int val) {
        bool flag = true;
        if(indexMap.find(val) != indexMap.end())  flag = !flag;
        indexMap[val].insert(arr.size());
        arr.push_back(val);
        return flag;
    }
    
    bool remove(int val) {
        if(indexMap.find(val) == indexMap.end()) return false;
        int currIndex = *indexMap[val].begin();
        int lastIndex = arr.size() - 1;
        if(currIndex == lastIndex){
            indexMap[val].erase(currIndex);
            arr.pop_back();
            if(indexMap[val].size() == 0) indexMap.erase(val);
        }
        else{
            indexMap[val].erase(currIndex);
            indexMap[arr[lastIndex]].erase(lastIndex);
            indexMap[arr[lastIndex]].insert(currIndex);
            swap(arr[currIndex], arr[lastIndex]);
            arr.pop_back();
            if(indexMap[val].size() == 0) indexMap.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

