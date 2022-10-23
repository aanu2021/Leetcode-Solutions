class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        
        int repeating = -1 , missing = -1;
        
        for(int i=0;i<n;i++){
            
            if(nums[abs(nums[i])-1]>0){
                
                nums[abs(nums[i])-1]*=-1;
                
            }
            
            else{
                
                repeating = abs(nums[i]);
                
            }
            
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>0){
                
                missing = i+1;
                
            }
            
        }
        
        return {repeating,missing};
        
    }
};