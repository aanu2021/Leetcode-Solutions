// Time Complexity :  O(N^2) --> O(N) --> O(N) //
// Space Complexity : O(1)   --> O(N) --> O(1) //

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int low=0,high=n-1,ans=0;
        
        int left_max=0,right_max=0;
        
        while(low<=high){
            
            if(height[low]<height[high]){
                
                left_max=max(left_max,height[low]);
                
                ans+=(left_max-height[low++]);
                
            }
            
            else{
                
                right_max=max(right_max,height[high]);
                
                ans+=(right_max-height[high--]);
                
            }
            
        }
        
        return ans;
        
    }
};