class RandomizedCollection {
public:
    
    vector<int>arr;
    
    unordered_map<int,unordered_set<int>>mapp;
    
    
    RandomizedCollection() {
        
        arr.clear();
        mapp.clear();
        
    }
    
    bool insert(int val) {
        
        bool flag=true;
        
        if(mapp.find(val)!=mapp.end()){
            
            flag=false;
            
        }
        
        mapp[val].insert(arr.size());
        
        arr.push_back(val);
        
        return flag;
        
    }
    
    bool remove(int val) {
        
        bool flag=true;
        
        if(mapp.find(val)==mapp.end()){
            
            return false;
            
        }
        
        int curr_index=*mapp[val].begin();
        
        int last_index=arr.size()-1;
        
        int curr_value=val;
        
        int last_value=arr.back();
        
        mapp[curr_value].erase(curr_index);
        
        mapp[last_value].insert(curr_index);
        
        arr[curr_index]=last_value;
        
        mapp[last_value].erase(last_index);
        
        if(mapp[curr_value].size()==0){
            
            mapp.erase(curr_value);
            
        }
        
        arr.pop_back();
        
        return true;
        
    }
    
    int getRandom() {
        
        return arr[rand()%arr.size()];
        
    }
};


// ["RandomizedCollection",
//  "remove","remove","insert","getRandom","remove","insert"]
// [  [0],     [0],      [0],     [],        [0],     [0]]

// false , 