class Solution {
public:
    int maxArea(vector<int>& height) {
        
         int n=height.size();
        
         int max_area=0;
        
         int l=0,r=n-1;
        
        while(l<r){
            
            max_area=max(max_area,(r-l)*min(height[l],height[r]));
            
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
            
        }
        
        return max_area;
        
    }
};