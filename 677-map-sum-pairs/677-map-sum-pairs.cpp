
class MapSum {
public:
    
    map<string,int>mapp;
    
    MapSum() {
        mapp.clear();
    }
    
    void insert(string key, int val) {
        
        mapp[key]=val;
        
    }
    
    int sum(string prefix) {
        
        int cnt=0;
        
        for(auto itr:mapp){
            
            string str=itr.first;
            
            if(str.length()<prefix.length()){
                continue;
            }
            
            if(str.substr(0,prefix.length())==prefix){
                
                cnt+=itr.second;
                
            }
            
        }
        
        return cnt;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */