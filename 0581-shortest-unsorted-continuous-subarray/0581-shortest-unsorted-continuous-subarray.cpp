class Solution {
public:
    
    /*
    
    T.C : O(N)
    S.C : O(N)
    
    */
    
    int findUnsortedSubarray2(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>preMax(n);
        vector<int>sufMin(n);
        
        preMax[0] = nums[0];
        sufMin[n-1] = nums[n-1];
        
        for(int i=1;i<n;++i){
            preMax[i] = max(preMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;--i){
            sufMin[i] = min(sufMin[i+1],nums[i]);
        }
        
        int left = -1,right = -1;
        
        for(int i=0;i<n-1;i++){
            if(preMax[i] > sufMin[i+1]){
                if(left==-1) left = i;
                right = i+1;
            }
        }
        
        if(left==-1 || right==-1) return 0;
        else return right - left + 1;
        
    }
    
    /*
    
    T.C : O(N)
    S.C : O(1)
    
    */
    
    int findUnsortedSubarray(vector<int>& nums) {
        
       int n = nums.size();
        
       int mini = 1e9,maxi = -1e9;
        
       for(int i=1;i<n;i++){
           if(nums[i] < nums[i-1]){
               mini = min(mini,nums[i]);
           }
       } 
        
       for(int i=n-2;i>=0;i--){
           if(nums[i] > nums[i+1]){
               maxi = max(maxi,nums[i]);
           }
       } 
        
       int l = 0,r = n-1; 
        
       for(l=0;l<n;l++){
           if(nums[l] > mini) break;
       } 
        
       for(r=n-1;r>=0;r--){
           if(nums[r] < maxi) break;
       } 
        
       return max(r-l+1,0); 
        
    }
    
    /*
    
    Approach : Minimum and Maximum element in the unsorted subarray 
    will help us to find out the left boundary and right boundary 
    of the subarray.
    
                            /
           /\              /
      /\  /  \            /
     /  \/    \    /\    / 
    /          \  /  \  /
                \/    \/
      
      
    */
    
};