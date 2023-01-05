class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[1] < y[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int arrows = 1;
        int inter_point = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= inter_point){
                continue;
            }
            else{
                arrows++;
                inter_point = points[i][1];
            }
        }
        return arrows;
    }
};

/*

[ Xl , Xr ]
    
                   ....................
             ............. 
   ............. 
 ........... 
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
   

 6  -> +2
 12 -> +2
 
 [1,6] [2,8] | [7,12] [10,16] |
 
 1 + 1 = 2
 
 Algo : Sort the points on the ascending order of their Xend
    
        Take the ending point of a balloon , and consider it as the 
        maximum possible balloons' intersection.
        
        When we are left with no balloons with that particular 
        intersection point inside them , then we need to start with 
        another arrow.
        
        [1,8] [2,7]
        [2,7] [1,8] [0,10]
        
 T.C : O(N*logN)
 S.C : O(1)

*/