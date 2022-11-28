class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        int k = -1;
        
        for(int i=0;i<matches.size();i++){
            k=max(k,matches[i][0]);
            k=max(k,matches[i][1]);
        }
        
        vector<int>loosing(k+1,-1); // Player Indices who are played atleast one match , and number of times they loose
        
        for(int i=0;i<matches.size();i++){
            loosing[matches[i][0]] = 0;
            loosing[matches[i][1]] = 0;
        }
        
        for(int i=0;i<matches.size();i++){
            loosing[matches[i][1]]++;
        }
        
        vector<vector<int>>ans(2);
        
        // ans[0] --> store those players who are not loosing a single match.
        
        // ans[1] --> store those platers who are loosing exactly one match.
        
        for(int i=1;i<=k;i++){
            if(loosing[i]==0){
                ans[0].push_back(i);
            }
            if(loosing[i]==1){
                ans[1].push_back(i);
            }
        }
        
        // ans[0] & ans[1] are already in sorted order.
        
        return ans;
        
    }
};