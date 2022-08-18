class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int l=0,r=n-1;
        
        int left_max=0,right_max=0;
        
        int ans=0;
        
        while(l<=r){
            
            if(height[l]<=height[r]){
                
                left_max=max(left_max,height[l]);
                
                ans+=(left_max-height[l]);
                
                l++;
                
            }else{
                
                right_max=max(right_max,height[r]);
                
                ans+=(right_max-height[r]);
                
                r--;
                
            }
            
        }
           
        
        return ans;
        
    }
};