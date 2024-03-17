class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>answer;
        vector<int>v = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= v[1]){
                v[1] = max(v[1], intervals[i][1]);
            }
            else{
                answer.push_back(v);
                v = intervals[i];
            }
        }
        answer.push_back(v);
        return answer;
    }
};