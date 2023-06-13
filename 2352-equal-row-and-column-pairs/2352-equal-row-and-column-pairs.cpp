class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        unordered_map<string,int>freq;
        
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++){
                str += to_string(grid[j][i]);
                str += "#";
            }
            freq[str]++;
        }
        
        int cntPairs = 0;
        
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++){
                str += to_string(grid[i][j]);
                str += "#";
            }
            cntPairs += freq[str];
        }
        
        return cntPairs;
        
    }
};