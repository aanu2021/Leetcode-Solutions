class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalTime = 0;
        for(int i=1;i<n;i++){
            int x = abs(points[i][0] - points[i-1][0]);
            int y = abs(points[i][1] - points[i-1][1]);
            int z = min(x,y);
            totalTime += z;
            x -= z;
            y -= z;
            totalTime += (x+y);
        }
        return totalTime;
    }
};

//  1 1
//  3 4
     
//  2 3   = 2 + 1
     
//  3  4
//  -1 0
     
//   4  4       