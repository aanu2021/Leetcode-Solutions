class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int left=0,right=n-1;
        
        int left_max=0,right_max=0;
        
        int amount=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){
                
                left_max=max(left_max,height[left]);
                
                amount+=(left_max-height[left]);
                
                left++;
                
            }
            
            else{
                
                right_max=max(right_max,height[right]);
                
                amount+=(right_max-height[right]);
                
                right--;
                
            }
            
        }
        
        return amount;
        
    }
};


// 0 1 0 2 1 0 1 3 2 1 2  1
// 0 1 2 3 4 5 6 7 8 9 10 11    
    
// l=0  r=11

// amount_water=0
    
// left_max=0
    
// right_max=0    
    