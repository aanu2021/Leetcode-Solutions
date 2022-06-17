class Solution {
public:
    
    bool isPossible(vector<int>&nums,int Len,int target){
        
        int sum=0;
        
        int n=nums.size();
        
        for(int i=0;i<Len;i++){
            sum+=nums[i];
            if(sum>=target){
                return true;
            }
        }
        
        for(int i=Len;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-Len];
            if(sum>=target){
                return true;
            }
        }
        
        return false;
        
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        
        int low=1,high=n;
        
        int ans=0;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(isPossible(nums,mid,target)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        
        return ans;
        
    }
};