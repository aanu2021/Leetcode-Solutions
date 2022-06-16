class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        
        int ans=INT_MAX;
        
        int low=0,high=n-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            ans=min(ans,nums[mid]);
            
            if(nums[mid]>=nums[low]){
                
                ans=min(ans,nums[low]);
                
                low=mid+1;
                
            }
            
            else{
                
                ans=min(ans,nums[high]);
                
                high=mid-1;
                
            }
            
        }
        
        return ans;
        
    }
};