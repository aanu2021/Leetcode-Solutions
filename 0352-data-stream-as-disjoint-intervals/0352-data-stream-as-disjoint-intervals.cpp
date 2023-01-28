class SummaryRanges {
public:
    
    map<int,int>intervals;
    
    SummaryRanges() {
        intervals.clear();
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;
        auto itr = intervals.upper_bound(value);
        if(itr != intervals.begin()){
            auto prev_itr = itr;
            prev_itr--;
            if(prev_itr->second >= value){
                return;
            }
            if(prev_itr->second == value - 1){
                left = prev_itr->first;
            }
        }
        if(itr != intervals.end()){
            if(itr->first == value + 1){
                right = itr->second;
                intervals.erase(itr);
            }
        }
        intervals[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>allIntervals;
        for(auto &itr : intervals){
            allIntervals.push_back({itr.first,itr.second});
        }
        return allIntervals;
    }
};

