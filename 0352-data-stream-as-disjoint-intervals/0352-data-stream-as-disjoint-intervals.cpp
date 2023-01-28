class SummaryRanges {
public:
    
    map<int,int>intervals;
    
    SummaryRanges() {
        intervals.clear();
    }
    
    void addNum(int value) {
        int left  = value;
        int right = value;
        auto itr = intervals.upper_bound(value);
        if(itr != intervals.begin()){
            auto prev_itr = itr;
            prev_itr--;
            if(prev_itr->second >= value){
                left = prev_itr->first;
                right = max(right,prev_itr->second);
            }
            if(prev_itr->second == value - 1){
                left = prev_itr->first;
            }
        }
        if(itr != intervals.end()){
            if(itr->first == right + 1){
                right = max(right,itr->second);
                intervals.erase(itr);
            }
        }
        intervals[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto &itr : intervals){
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