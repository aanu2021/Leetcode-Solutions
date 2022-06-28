class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n=nums.size();
        
        int maxi=*max_element(nums.begin(),nums.end());
        
        int mini=*min_element(nums.begin(),nums.end());
        
        int i1=-1,i2=-1;
        
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                i1=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                i2=i;
                break;
            }
        }
        
        if(i1>i2){
            swap(i1,i2);
        }
        
        int ans=(i1+1+n-i2);
        
        ans=min(ans,i2+1);
        
        ans=min(ans,n-i1);
        
        return ans;
        
    }
};