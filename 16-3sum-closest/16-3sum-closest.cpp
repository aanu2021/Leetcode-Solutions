class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int minSum = INT_MAX;
        
        int ans = INT_MAX;
        
        for(int i=0;i<n-2;i++){
            
            int j=i+1;
            int k=n-1;
            
            while(j<k){
                
                int currsum = nums[i] + nums[j] + nums[k];
                
                if(abs(currsum-target)<minSum){
                    
                    minSum = abs(currsum-target);
                    ans = currsum;
                    
                }
                
                if(currsum > target){
                    
                    k--;
                    
                }
                
                else{
                    
                    j++;
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};