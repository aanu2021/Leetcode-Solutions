class Solution {
public:
    
    int dp[1005][2005];
    
    int func(vector<vector<int>>&piles,int i,int n,int k){
        
        if(i>=n){
            
            if(k==0){
                return 0;
            }
            
            else{
                return -1e9;
            }
            
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        int currval=func(piles,i+1,n,k);
        
        for(int j=0;j<piles[i].size();j++){
            
            if(j+1<=k){
                currval=max(currval,piles[i][j]+func(piles,i+1,n,k-j-1));
            }else{
                break;
            }
            
        }
        
        return dp[i][k]=currval;
        
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n=piles.size();
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            
            for(int j=1;j<piles[i].size();j++){
                
                piles[i][j]+=piles[i][j-1];
                
            }
            
        }
        
        
        int ans=func(piles,0,n,k);
        
        return ans;
        
    }
};