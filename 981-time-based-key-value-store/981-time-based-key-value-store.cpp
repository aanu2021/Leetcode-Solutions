/*


*/

class TimeMap {
public:
    
    unordered_map<string,map<int,string>>mapp;
    
    TimeMap() {
        
        mapp.clear();
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mapp[key][timestamp] = value;
        
    }
    
    string get(string key, int timestamp) {
        
        auto itr=mapp[key].upper_bound(timestamp);
        
        if(itr==mapp[key].begin()) return "";
        
        else{
            itr--;
            return itr->second;
        }
        
    }
};



/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */