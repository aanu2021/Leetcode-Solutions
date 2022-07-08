class Solution {
public:
    
int func(vector<int>&v,int i,int target,vector<vector<int>>&dp){
        
        // Base Case 1
    
        if(i>=v.size()){
        
            if(target==0){
                return 0;
            }else{
                return 1e9;
            }
            
        }
     
        // Base Case 2
    
        if(target==0){
            
           return 0;
            
        }
    
        
        // Memoization
    
        if(dp[i][target]!=-1){
            
            return dp[i][target];
            
        }
    
        
        int ans=1e9;
    
         // Skip the value
    
        ans=min(ans,func(v,i+1,target,dp)); 
    
    
        if(target>=v[i]){
            
              // Pick the value 
            
             ans=min(ans,1 + func(v,i,target-v[i],dp)); 
            
        }
    
      
       return dp[i][target] = ans;
        
    }
    
    int numSquares(int n) {
        
        vector<int>v;
        
        int i=1;
        
        while(i*i<=n){
            v.push_back(i*i);
            i++;
        }
        
        int sz=v.size();
        
        reverse(v.begin(),v.end());
        
        vector<vector<int>>dp(sz,vector<int>(n+1,-1));
        
//         for(int i=0;i<sz;++i){
//             cout<<v[i]<<" ";
//         }cout<<"\n";
        
        int ans=func(v,0,n,dp);
        
        // for(int i=0;i<sz;++i){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        
        return ans;
        
    }
};