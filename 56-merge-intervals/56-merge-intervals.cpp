class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        
        vector<vector<int>>result;
        
        vector<int>curr=intervals[0];
        
        for(int i=1;i<n;i++){
            
            if(intervals[i][0]<=curr[1]){
                curr[1]=max(curr[1],intervals[i][1]);
            }else{
                result.push_back(curr);
                curr=intervals[i];
            }
            
        }
        
        result.push_back(curr);
        
        return result;
        
    }
};