class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        int idx = n;
        
        for(int i=0;i<n;i++){
            if(intervals[i][0] >= newInterval[0]){
                idx = i;
                break;
            }
        }
        
        vector<vector<int>>answer;
        
        // New Interval would be the first interval, among all the intervals.
        
        if(idx == 0){
            vector<int>curr = newInterval;
            for(int i=0;i<n;i++){
                if(intervals[i][0] <= curr[1]){
                    curr[1] = max(curr[1], intervals[i][1]);
                }
                else{
                    answer.push_back(curr);
                    curr = intervals[i];
                }
            }
            answer.push_back(curr);
            return answer;
        }
        
        // New Interval would be in between interval, among all the intervals.
        
        else{
            for(int i=0;i<idx-1;i++){
                answer.push_back(intervals[i]);
            }
            vector<int>curr = intervals[idx-1];
            if(newInterval[0] <= curr[1]){
                curr[1] = max(curr[1],newInterval[1]);
            }
            else{
                answer.push_back(curr);
                curr = newInterval;
            }
            for(int i=idx;i<n;i++){
                if(intervals[i][0] <= curr[1]){
                    curr[1] = max(curr[1], intervals[i][1]);
                }
                else{
                    answer.push_back(curr);
                    curr = intervals[i];
                }
            }
            answer.push_back(curr);
            return answer;
        }
        
    }
};