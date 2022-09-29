class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        
        int low = 0 , high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            int cnt = 0;
            
            if(mid-1>=0 && nums[mid-1]==nums[mid]) cnt++;
            if(mid+1< n && nums[mid+1]==nums[mid]) cnt++;
            
            if(cnt == 0){
                
                return nums[mid];
                
            }
            
            // Occurence at Odd Index //
            
            if(mid%2){
                
                if(mid+1<n && nums[mid+1]==nums[mid]){
                    
                    high = mid - 1;
                    
                }
                
                else{
                    
                    low = mid + 1;
                    
                }
                
            }
            
            // Occurence at Even Index //
            
            else{
                
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    
                    high = mid - 1;
                    
                }
                
                else{
                    
                    low = mid + 1;
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};