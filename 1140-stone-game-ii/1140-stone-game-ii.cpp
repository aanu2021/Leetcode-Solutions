class Solution {
public:
    
    int dp[105][105];
    
    int func(vector<int>&piles,int i,int m){
        
        if(i>=piles.size()){
            return 0;
        }
        
        if(dp[i][m]!=-1){
            return dp[i][m];
        }
        
        int sum=0;
        
        int ans=INT_MIN;
        
        for(int j=0;j<2*m;j++){
            
            if(i+j>=piles.size()){
                break;
            }
            
            sum+=piles[i+j];
            
            int currval=sum-func(piles,i+j+1,max(j+1,m));
            
            ans=max(ans,currval);
            
        }
        
        return dp[i][m]=ans;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int n=piles.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(piles,0,1);
        
        int sum1=accumulate(piles.begin(),piles.end(),0);
        int sum2=ans;
        
        ans=(sum1+sum2)/2;
        
        return ans;
        
    }
};