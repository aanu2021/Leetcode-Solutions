class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        
        int n=nums.size();
        
        int low=0,high=n-1;
        
        while(high-low>=k){
            
            if(abs(nums[low]-x) <= abs(nums[high]-x)){
                high--;
            }else{
                low++;
            }
            
        }
        
        return vector<int>(nums.begin()+low,nums.begin()+high+1);
        
    }
};