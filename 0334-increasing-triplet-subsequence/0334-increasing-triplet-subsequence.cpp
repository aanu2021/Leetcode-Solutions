  /*
  
  Key Observation :

  num > x
  num > mini  as mini <= x

  num < y
  num < maxi as maxi >= y
  
  
  Approach : Prefix and Suffix Min-Max
  
  
  Algorithm : 
  
  PreMin[i] will store the minimum element till the i-th index 
  from 0-th index
  
  SuffMax[i] will store the maximum element till i-th index from
  (n-1)-th index
  
  Then we will iterate through the array from index 0 to index
  n-1 , and check whether (nums[i] > preMin[i] && 
  nums[i] < suffMax[i])  --> If the condition is valid then 
  return true .
  
  
  T.C : O(N)
  S.C : O(N)
  
  
  */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3) return false;
        
        vector<int>preMin(n);
        vector<int>suffMax(n);
            
        preMin[0] = nums[0];
        suffMax[n-1] = nums[n-1];
        
        for(int i=1;i<n;i++){
            preMin[i]=min(preMin[i-1],nums[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            suffMax[i]=max(suffMax[i+1],nums[i]);
        }
        
        for(int i=0;i<n;i++){
            
            if(preMin[i] < nums[i] && nums[i] < suffMax[i]){
                
                return true;
                
            }
            
        }
        
        return false;
        
    }
    
    bool increasingTriplet2(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3) return false;
        
        long long int first = nums[0];
        
        long long int second = 1e10;
        
         for(int i=1;i<n;i++){
            
            if(nums[i]>second){
                return true;
            }
            
            if(nums[i]<first){
                
                first = nums[i];
                
            }
            
            else if(nums[i] > first && nums[i] < second){
                
                second = nums[i];
                
            }
            
        }
        
        return false;
        
    }
    
};