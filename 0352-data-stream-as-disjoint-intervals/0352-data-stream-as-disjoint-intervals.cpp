class SummaryRanges {
public:
    
    map<int,int>mp;
    
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        if(mp.size() == 0){
            mp[value] = value;
        }
        else{
            int left = value , right = value;
            auto small_entry = mp.upper_bound(value);
            if(small_entry != mp.begin()){
                auto max_entry = small_entry;
                max_entry--;
                if(max_entry->second >= value){
                    return;
                }
                if(max_entry->second == value - 1){
                    left = max_entry->first;
                }
            }
            if(small_entry != mp.end()){
                if(small_entry->first == value + 1){
                    right = small_entry->second;
                    mp.erase(small_entry);
                }
            }
            mp[left] = right;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto &itr:mp){
            ans.push_back({itr.first,itr.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */