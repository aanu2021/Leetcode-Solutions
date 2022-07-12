// Time Complexity :  O(N^2) --> O(N) --> O(N) //
// Space Complexity : O(1)   --> O(N) --> O(1) //

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int ans=0;
        
        int low=0,high=n-1;
        
        int leftmax=0,rightmax=0;
        
        while(low<=high){
            
            if(height[low]<height[high]){
                
                leftmax=max(leftmax,height[low]);
                
                ans+=(leftmax-height[low]);
                
                low++;
                
            }
            
            else{
                
                rightmax=max(rightmax,height[high]);
                
                ans+=(rightmax-height[high]);
                
                high--;
                
            }
            
        }
        
        return ans;
        
    }
};