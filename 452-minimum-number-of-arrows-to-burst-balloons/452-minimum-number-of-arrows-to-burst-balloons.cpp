class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] < y[1];
        
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),comp);
        
        int balloons=1;
        
        int curr=points[0][1];
        
        for(int i=1;i<points.size();++i){
            
            if(points[i][0]<=curr){
                
                continue;
                
            }
            
            else{
                
                balloons++;
                
                curr=points[i][1];
                
            }
            
        }
        
        return balloons;
        
    }
};