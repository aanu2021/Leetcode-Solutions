class Solution {
public:
    
    int dp[505][505];
    
    int func(vector<int>&arr,int i,int j){
        
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=0;
        
        int sum=0;
        
        for(int k=i;k<=j;k++){
            sum+=arr[k];
        }
        
        int lsum=0,rsum=0;
        
        for(int k=i;k<j;k++){
            
            lsum+=arr[k];
            rsum=(sum-lsum);
            
            if(lsum<rsum){
                
                ans=max(ans,lsum+func(arr,i,k));
                
            }
            
            else if(lsum>rsum){
                
                ans=max(ans,rsum+func(arr,k+1,j));
                
            }
            
            else{
                
                ans=max(ans,lsum+func(arr,i,k));
                
                ans=max(ans,rsum+func(arr,k+1,j));
                
            }
            
        }
        
        return dp[i][j]=ans;
        
    }
    
    int stoneGameV(vector<int>& arr) {
        
        int n=arr.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(arr,0,n-1);
        
        return ans;
        
    }
};