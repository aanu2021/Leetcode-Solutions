class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int idx = n;
        for(int i=0;i<n;i++){
            if(intervals[i][0] > newInterval[0]){
                idx = i;
                break;
            }
        }
        intervals.insert(intervals.begin()+idx,newInterval);
        n++;
        vector<vector<int>>ans;
        vector<int>curr = intervals[0];
        for(int i=1;i<n;i++){
            if(curr[1] >= intervals[i][0]){
                curr[1] = max(curr[1],intervals[i][1]);
            }
            else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};