class Solution {
public:
    
    /*
    
    Try to visualize the problem , as a traditional Knapsack problem. Now in case of K.S Problems , our goal is to maximize the profit , within the given capacity.
    
    In these problem , our goal is to Minimize the number of stations picked in our journey to reach the destination from '0'.
    
    So our recursion state would look like something these, dp[i] --> denotes the Minimum number of stations we need to stop at to reach target.
    
    Now , our 'i' value ranges from '0' to 'target'
    
    But wait!!! , let's have a look at the constraints ,
    target <= 10^9 , we can't consider the 'station_dist' as our recursion state , as it will eventually give us MLE,
    
    
    So , what ......
    
    Let's use the same approach , but now from a different perspective. Instead of finding the minimum number of refueling stations to reach i-th station ('target') , we just need to find out the maximum amount of fuel we can get by refuelling at 'i' number of stations.
    
    
    Now , dp[i] --> Maximum amount of fuel , we can achieve by refueling our car exactly at 'i' number of stations. 
    
    */
    
     typedef long long ll;
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n=stations.size();
        
        vector<ll>dp(n+1,0);
        
        // Base Case //
        
        dp[0]=(ll)startFuel; // Head-start from the source.
        
        for(int i=0;i<n;++i){
            
            for(int j=i;j>=0;j--){
                
                if(dp[j]>=(ll)stations[i][0]){
                    
                    dp[j+1]=max(dp[j+1],dp[j]+(ll)stations[i][1]);
                    
                }
                
            }
            
        }
        
        if(dp[n]<target){
            
            return -1;
            
        }
        
        for(int i=0;i<=n;++i){
            
            if(dp[i]>=target){
                return i;
            }
            
        }
        
        return -1;
        
    }
};