class Solution {
public:
    
   // double dp[105][105];
    
    map<int,map<int,double>>dp;
    
    double func(vector<int>&nums,int i,int n,int k){
        
        if(i>=n){
            
            if(k>=0){
                return 0.0;
            }
            
            else{
                return -100000000;
            }
            
        }
        
        if(k<0){
            
            return -10000000;
            
        }
        
        if(dp[i].find(k)!=dp[i].end()){
            
            return dp[i][k];
            
        }
        
//         if(dp[i][k]!=-1){
            
//             return dp[i][k];
            
//         }
        
        int sum=0;
        
        double curr=0.0;
        
        double ans=-10000000;
        
        for(int j=i;j<n;j++){
            
            sum+=nums[j];
            
            curr=(sum*1.0)/(j-i+1);
            
            ans=max(ans,curr+func(nums,j+1,n,k-1));
            
        }
        
        return dp[i][k] = ans;
        
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        
       // memset(dp,-1,sizeof(dp));
        
        double ans=func(nums,0,n,k);
       
        return ans;
        
    }
};