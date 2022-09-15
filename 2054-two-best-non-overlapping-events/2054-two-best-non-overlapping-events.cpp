class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n=events.size();
        
        sort(events.begin(),events.end());
        
        int maxsum=0;
        
        vector<int>dp(n,0);
        
        dp[n-1]=events[n-1][2];
        
        maxsum=dp[n-1];
        
        for(int i=n-2;i>=0;i--){
            
            int currsum=events[i][2];
            
            int low=i+1,high=n-1;
            
            int inc=-1;
            
            while(low<=high){
                
                int mid=(low+high)/2;
                
                if(events[mid][0]>events[i][1]){
                    
                    inc=mid;
                    high=mid-1;
                    
                }
                
                else{
                    
                    low=mid+1;
                    
                }
                
            }
            
            if(inc!=-1){
                
                currsum+=dp[inc];
                
            }
            
            maxsum=max(maxsum,currsum);
            
            dp[i]=max(dp[i+1],events[i][2]);
            
        }
        
        return maxsum;
        
    }
};