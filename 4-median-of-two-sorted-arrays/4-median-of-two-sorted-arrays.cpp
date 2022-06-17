class Solution {
public:
    
    double avg(int a,int b){
        
        return (a+b)/2.0;
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int x=nums1.size();
        int y=nums2.size();
        
        if(x>y){
            
            return findMedianSortedArrays(nums2,nums1);
            
        }
        
        int low=0,high=x;
        
        while(low<=high){
            
            int partX=(low+high)/2;
            int partY=(x+y+1)/2;
            partY-=partX;
            
            int maxLeftX=INT_MIN;
            int maxLeftY=INT_MIN;
            int minRightX=INT_MAX;
            int minRightY=INT_MAX;
            
            if(partX!=0){
                maxLeftX=nums1[partX-1];
            }
            
            if(partY!=0){
                maxLeftY=nums2[partY-1];
            }
            
            if(partX!=x){
                minRightX=nums1[partX];
            }
            
            if(partY!=y){
                minRightY=nums2[partY];
            }
            
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                
                if((x+y)%2!=0){
                    
                    return max(maxLeftX,maxLeftY);
                    
                }
                
                else{
                    
                    return avg(max(maxLeftX,maxLeftY),min(minRightX,minRightY));
                    
                }
                
            }
            
            if(maxLeftY>minRightX){
                
                low=partX+1;
                
            }
            
            else{
                
                high=partX-1;
                
            }
            
        }
        
        return -1.0;
        
    }
};