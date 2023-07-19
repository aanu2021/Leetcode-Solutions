class RangeModule {
public:
    
    map<int,int>mp;
    
    RangeModule() {
        mp.clear();
    }
    
    void addRange(int left, int right) {
        right--;
        auto itr = mp.upper_bound(left);
        if(itr != mp.begin()){
            auto prev_itr = prev(itr);
            if(prev_itr->second >= left){
                left = prev_itr->first;
                right = max(right,prev_itr->second);
            }
            else if(prev_itr->second == left - 1){
                left = prev_itr->first;
            }
        }
        if(itr != mp.end()){
            for(;itr!=mp.end();){
                int l = itr->first;
                int r = itr->second;
                if(right >= itr->first - 1){
                    right = max(right,itr->second);
                    mp.erase(itr++);
                }
                else{
                    break;
                }
            }
        }
        mp[left] = right;
    }
    
    bool queryRange(int left, int right) {
        right--;
        auto itr = mp.upper_bound(left);
        if(itr != mp.begin()){
            auto prev_itr = prev(itr);
            if(prev_itr->second >= left){
                int l = prev_itr->first;
                int r = prev_itr->second;
                if(left >= l && right <= r){
                    return true;
                }
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        right--;
        auto itr = mp.upper_bound(left);
        if(itr != mp.begin()){
            auto prev_itr = prev(itr);
            if(prev_itr->second >= left){
                int l = prev_itr->first;
                int r = prev_itr->second;
                int l1 = l;
                int r1 = left - 1;
                int l2 = right + 1;
                int r2 = r;
                mp.erase(l);
                if(l1 <= r1){
                    mp[l1] = r1;
                }
                if(l2 <= r2){
                    mp[l2] = r2;
                }
            }
        }
        if(itr != mp.end()){
            while(itr != mp.end()){
                int l = itr->first;
                int r = itr->second;
                if(l > right){
                    break;
                }
                if(l >= left && r <= right){
                    mp.erase(l);
                }
                else{
                    if(right + 1 <= r){
                        mp[right + 1] = r;
                    }
                    mp.erase(l);
                    break;
                }
                itr = mp.upper_bound(left);
            }
        }
    }
};

