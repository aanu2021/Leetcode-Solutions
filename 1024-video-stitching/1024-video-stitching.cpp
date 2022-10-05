class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        vector<int>dp(time+1,-1);
        
        for(int i=0;i<clips.size();i++){
            
            int left = min(clips[i][0],time);
            int right = min(clips[i][1],time);
            
            dp[left] = max(dp[left] , right);
            
        }
        
        int currmax = dp[0];
        
        int nextmax = -1;
        
        int jumps = 1;
        
        if(dp[0]==time) return 1;
        
        for(int i=0;i<=time;i++){
            
            nextmax = max(nextmax,dp[i]);
            
            if(currmax==i){
                
                currmax = nextmax;
                jumps++;
                
            }
            
            if(currmax == time){
                
                return jumps;
                
            }
            
        }
        
        return -1;
        
    }
};