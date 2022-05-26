class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int>dp(n+1,INT_MIN);
        
        dp[n-1]=arr[n-1];
        dp[n]=0;
        
        for(int i=n-2;i>=0;i--){
            
            int currsum=0;
            
            int maxsum=INT_MIN;
            
            for(int j=i;j<=min(i+2,n-1);j++){
                
                currsum+=arr[j];
                
                maxsum=max(maxsum,currsum-dp[j+1]);
                
            }
            
            dp[i]=maxsum;
            
        }
        
        if(dp[0]>0){
            return "Alice";
        }
        
        else if(dp[0]<0){
            return "Bob";
        }
        
        else{
            return "Tie";
        }
        
    }
};