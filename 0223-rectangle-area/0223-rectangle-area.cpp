class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int leftx = max(ax1,bx1);
        int lefty = max(ay1,by1);
        int rightx = min(ax2,bx2);
        int righty = min(ay2,by2);
        
        // No Intersection //
        
        if(rightx-leftx<=0 || righty-lefty<=0){
            
            return ((ay2-ay1)*(ax2-ax1)) + ((by2-by1)*(bx2-bx1));
            
        }
        
        // Have some Intersecting Region //
        
        else{
            
            return ((ay2-ay1)*(ax2-ax1)) + ((by2-by1)*(bx2-bx1)) - ((rightx-leftx)*(righty-lefty));
            
        }
        
    }
};