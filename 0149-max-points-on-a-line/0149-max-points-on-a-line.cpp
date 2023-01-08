/*

Figure out how many points are making equal tangent with a fixed point on the co-ordinate plane.

*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxLen = 1;
        for(int i=0;i<n;i++){
            
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++){
                
                double curr = 0.0;
                int num = (points[j][1]-points[i][1]);
                int den = (points[j][0]-points[i][0]);
                
                if(den==0){
                    curr = 100000.0;
                }
                else{
                    curr = (num*1.0)/den;
                }
                
                if(mp.find(curr)!=mp.end()){
                    mp[curr]++;
                }
                else{
                    mp[curr] = 2;
                }
                maxLen = max(maxLen,mp[curr]);
                
            }
        }
        return maxLen;
    }
};