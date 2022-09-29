class Solution {
public:
    
    // Time Complexity : O(logN) + O(K)
    
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        
        int high = lower_bound(nums.begin(),nums.end(),x)-nums.begin();
        
        int low = high - 1;
        
        while(k--){
            
            if(high>=n || (low>=0 && abs(nums[low]-x) <= abs(nums[high]-x))){
                
                low--;
                
            }
            
            else{
                
                high++;
                
            }
            
        }
        
        return vector<int>(nums.begin()+low+1,nums.begin()+high);
        
    }
};