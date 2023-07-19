class SummaryRanges {
public:
    
    map<int,int>mp;
    
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;
        auto itr = mp.upper_bound(value);
        if(itr != mp.begin()){
            auto prev_itr = prev(itr);
            if(prev_itr->second >= value){
                left = prev_itr->first;
                right = max(right,prev_itr->second);
            }
            else if(prev_itr->second == value-1){
                left = prev_itr->first;
            }
        }
        if(itr != mp.end()){
            if(itr->first == value + 1){
                right = max(right, itr->second);
                mp.erase(itr->first);
            }
        }
        mp[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>answer;
        for(auto &itr : mp){
            answer.push_back({itr.first,itr.second});
        }
        return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */