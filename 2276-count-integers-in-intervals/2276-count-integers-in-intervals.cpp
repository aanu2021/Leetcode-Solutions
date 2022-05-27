class CountIntervals {
public:
    
    int cnt=0;
    
    map<int,int>mp;
    
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        
        auto itr=mp.upper_bound(left);
        
        if(itr!=mp.begin()){
            
            auto p=prev(itr);
            
            if(p->second>=left){
                
                cnt-=(p->second-p->first+1);
                
                left=p->first;
                right=max(right,p->second);
                
                mp.erase(p);
                
            }
            
        }
        
        
        for(;itr!=mp.end() && itr->first<=right ; mp.erase(itr++)){
            
            cnt-=(itr->second-itr->first+1);
            
            right=max(right,itr->second);
            
        }
        
        mp[left]=right;
        
        cnt+=(right-left+1);
        
    }
    
    int count() {
        
        return cnt;
        
    }
};

