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
                if(right >= itr->first-1){
                    right = max(right,itr->second);
                    mp.erase(itr++);
                }
                else{
                    break;
                }
            }
            // if(right >= itr->first - 1){
            //     right = max(right,itr->second);
            //     mp.erase(itr->first);
            // }
        }
        mp[left] = right;
        // cout<<"Add Range\n";
        // for(auto &itr : mp){
        //     cout<<itr.first<<" "<<itr.second<<"\n";
        // }
    }
    
    bool queryRange(int left, int right) {
        right--;
        // cout<<"Query Range\n";
        // for(auto &itr : mp){
        //     cout<<itr.first<<" "<<itr.second<<"\n";
        // }
        auto itr = mp.upper_bound(left);
        if(itr != mp.begin()){
            auto prev_itr = prev(itr);
            int l = prev_itr->first;
            int r = prev_itr->second;
            if(left >= l && right <= r){
                return true;
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
                int cl = prev_itr->first;
                int l1 = prev_itr->first;
                int r1 = left - 1;
                int l2 = right + 1;
                int r2 = prev_itr->second;
                mp.erase(cl);
                // cout<<"Remove Range\n";
                // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
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
                int cl = itr->first;
                int cr = itr->second;
                if(cl > right){
                    break;
                }
                if(cl >= left && cr <= right){
                    mp.erase(cl);
                }
                else{
                    if(right + 1 <= cr){
                        mp[right + 1] = cr;
                    }
                    mp.erase(cl);
                    break;
                }
                itr = mp.upper_bound(left);
            }
            // for(;itr!=mp.end();){
            //     itr = upper_b
            //     int cl = itr->first;
            //     int cr = itr->second;
            //     if(cl >= left && cr <= right){
            //         mp.erase(itr++);
            //     }
            //     else{
            //         if(right + 1 <= cr){
            //             mp[right + 1] = cr;
            //         }
            //         mp.erase(itr++);
            //         break;
            //         // mp.erase(cl);
            //         // mp[right+1] = cr;
            //         // break;
            //     }
            // }
        }
        // cout<<"Remove Range\n";
        // for(auto &itr : mp){
        //     cout<<itr.first<<" "<<itr.second<<"\n";
        // }
    }
};


// [1,5] [20,25]
// [1,3] [9,10]

// [4,22]

// [10,19]

// [14,15]




/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */