class Solution {
public:
    
    int func(vector<int>&nums,int x,int y){
        
        int n=nums.size();
        
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        
        int sum=0;
        
        for(int i=0;i<x;i++){
            sum+=nums[i];
        }
        
        prefix[x-1]=sum;
        
        for(int i=x;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-x];
            prefix[i]=max(prefix[i-1],sum);
        }
        
        sum=0;
        
        for(int i=n-1;i>=n-y;i--){
            sum+=nums[i];
        }
        
        suffix[n-y]=sum;
        
        for(int i=n-y-1;i>=0;i--){
            sum+=nums[i];
            sum-=nums[i+y];
            suffix[i]=max(suffix[i+1],sum);
        }
        
        int ans=0;
        
        for(int i=x-1;i<n-y;i++){
            
            ans=max(ans,prefix[i]+suffix[i+1]);
            
        }
        
        return ans;
        
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int x, int y) {
        
        int n=nums.size();
        
        int ans=func(nums,x,y);
        
        ans=max(ans,func(nums,y,x));
        
        return ans;
        
    }
};