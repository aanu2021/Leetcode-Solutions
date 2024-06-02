class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>intervals;
        vector<int>interval = meetings[0];
        for(int i=1;i<n;i++){
            if(meetings[i][0] > interval[1]){
                intervals.push_back(interval);
                interval = meetings[i];
            }
            else{
                interval[1] = max(interval[1], meetings[i][1]);
            }
        }
        intervals.push_back(interval);
        // for(int i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
        // }
        int total = 0;
        n = intervals.size();
        for(int i=1;i<n;i++){
            total += max(0, intervals[i][0] - intervals[i-1][1] - 1);
        }
        total += max(0, intervals[0][0] - 1);
        total += max(0, days - intervals[n-1][1]);
        return total;
    }
};