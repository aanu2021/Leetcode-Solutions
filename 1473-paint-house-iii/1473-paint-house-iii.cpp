class Solution {
public:
    
    int dp[105][22][105];
    
    int func(vector<int>&nums,vector<vector<int>>&cost,int i,int prev,int target,int m,int n){
        
        if(i>=m){
            
            if(target==0){
                return 0;
            }else{
                return 1e9;
            }
            
        }
        
        if(dp[i][prev][target]!=-1){
            return dp[i][prev][target];
        }
        
        int ans=1e9;
        
        if(nums[i]!=0){
            
            if(nums[i]!=prev && target>0){
                
                ans=min(ans,func(nums,cost,i+1,nums[i],target-1,m,n));
                
            }
            
            else if(nums[i]==prev){
                
                ans=min(ans,func(nums,cost,i+1,nums[i],target,m,n));
                
            }
            
        }
        
        
        else{
            
            for(int j=0;j<n;++j){
                
                if((j+1)!=prev && target>0){
                    
                    ans=min(ans,cost[i][j] + func(nums,cost,i+1,j+1,target-1,m,n));
                    
                }
                
                else if(j+1==prev){
                    
                    ans=min(ans,cost[i][j] + func(nums,cost,i+1,j+1,target,m,n));
                    
                }
                
            }
            
        }
        
        return dp[i][prev][target] = ans;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n+1;j++){
                for(int k=0;k<=m;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        
        int ans=func(houses,cost,0,n+1,target,m,n);
        
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
        
    }
};