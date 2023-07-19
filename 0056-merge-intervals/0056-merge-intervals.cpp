class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>answer;
        vector<int>interval = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= interval[1]){
                interval[1] = max(interval[1], intervals[i][1]);
            }
            else{
                answer.push_back(interval);
                interval = intervals[i];
            }
        }
        answer.push_back(interval);
        return answer;
    }
};