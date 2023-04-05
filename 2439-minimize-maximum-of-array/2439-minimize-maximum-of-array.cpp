class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(vector<int>&nums,int n,int target){
        ll have = 0LL;
        for(int i=0;i<n;i++){
            if(nums[i] <= target){
                have += (ll)(target-nums[i]);
            }
            else{
                int extra = nums[i] - target;
                if(have >= (ll)extra){
                    have -= (ll)extra;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(nums,n,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
  
    
     