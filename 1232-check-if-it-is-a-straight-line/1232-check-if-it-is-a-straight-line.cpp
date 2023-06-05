class Solution {
public:
    
    double getSlope(int x1,int y1,int x2,int y2){
        double slope = 1e9;
        if(x2-x1 != 0){
            slope = (double)(y2-y1)/(double)(x2-x1);
        }
        return slope;
    }
    
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        double slope = getSlope(c[0][0],c[0][1],c[1][0],c[1][1]);
        for(int i=2;i<n;i++){
            double currSlope = getSlope(c[0][0],c[0][1],c[i][0],c[i][1]);
            // cout<<currSlope<<"\n";
            if(currSlope != slope){
                return false;
            }
        }
        
        return true;
        
    }
};