class CountIntervals {
public:
    
    map<int,int>mp;
    int cnt;
    
    CountIntervals() {
        mp.clear();
        cnt = 0;
    }
    
    void add(int left, int right) {
        
        auto itr = mp.upper_bound(left);
        
        if(itr != mp.begin()){
            
            auto prev_itr = itr;
            prev_itr--;
            
            if(prev_itr->second >= left){
                left = prev_itr->first;
                right = max(right,prev_itr->second);
                cnt -= (prev_itr->second - prev_itr->first + 1);
                mp.erase(prev_itr);
            }
            
        }
        
        for(;itr != mp.end() && itr->first <= right;mp.erase(itr++)){
            
            cnt -= (itr->second - itr->first + 1);
            right = max(right,itr->second);
            
        }
        
        mp[left] = right;
        cnt += (right-left+1);
        
    }
    
    int count() {
        return cnt;
    }
};
