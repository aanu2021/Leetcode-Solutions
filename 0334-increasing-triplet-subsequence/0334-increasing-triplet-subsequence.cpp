  /*
  
  Key Observation :

  num > x
  num > mini  as mini <= x

  num < y
  num < maxi as maxi >= y
  
  
  Approach1 : Prefix and Suffix Min-Max
  
  
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


  /*
  
  Approach : Greedy + Observation
  
  Observation :
  
  Now we want to reduce the space complexity needed in the 
  approach 1 . For doing so we need to observe carefully , see 
  for a particular index 'k' , if we found two elements at index 
  'i' and index 'j' respectively , for which nums[k] > nums[j] >
  nums[i] && k > j > i satisfies , then we can definitely return 
  true.
  
  Algorithm :
  
  Now , we will keep track of the minimum element and second minimum element , that we visited before reaching the current index , and if the current element > second minimum element , then second minimum element definitely > minimum element till now. 
  
  You might wondering , only keeping track of min and second_min enough or not , as we need to maintain their ordering right (i.e min must come before the second min). 
  
  Now if we take some examples to prove that only keeping track of min and second min is fair enough , we don't need to bother about their ordering in the array.
  
    Check those examples out , give them a dry run acc to the mentioned code to understand why it is happening.
    
    nums : [1,2,3,4,5]
    nums : [3,4,2,1,5]
    nums : [4,3,1,2,5]
    nums : [1,1,-2, 6]
    
    
    T.C : O(N)
    S.C : O(1)
  
  */

class Solution {
public:
    bool increasingTriplet2(vector<int>& nums) {
        
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
    
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        long long int first = 1e10;
        long long int second = 1e10;
        
        for(int i=0;i<n;i++){
            
            if(nums[i] < first){
                
                first = nums[i];
                
                /* Remember we are not updating the second min 
                element , if we do so then we will lost the
                ordering.*/
                
            }
            
            if(nums[i] > first && nums[i] < second){
                
                second = nums[i];
                
            }
            
            if(nums[i] > second){
                
                /* When we visited two elements before it which
                are strictly smaller than these , so ....... we 
                are done with it.*/
                
                return true;
                
            }
            
        }
        
        return false;
        
    }
    
};