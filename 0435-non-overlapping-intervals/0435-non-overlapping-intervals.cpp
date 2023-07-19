class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[1] < y[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        
        int ans = 1;
        int curr = intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= curr){
                ans++;
                curr = intervals[i][1];
            }
            else{
                continue;
            }
        }
        
        return n-ans;
    }
};