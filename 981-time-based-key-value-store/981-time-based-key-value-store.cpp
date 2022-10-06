/*

Priority --> (key , timestamp , value)

use unordered_map<string,map<int,string>> to store the 
(timestamp,value) pair corresponding to a particular key .
As we already know that timestamp values are strictly increasing 
so we will use binary search to figure out the value.

T.C : O(N.logN + NlogN)
S.C : O(N)

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
       
       if(itr==mapp[key].begin()){
           return "";
       }
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