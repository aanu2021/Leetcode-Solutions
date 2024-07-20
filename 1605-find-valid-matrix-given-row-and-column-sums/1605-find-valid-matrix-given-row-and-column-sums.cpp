class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int m = rowSum.size();
        int n = colSum.size();
        
        vector<vector<int>>answer;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                int helper = min(rowSum[i], colSum[j]);
                temp.push_back(helper);
                rowSum[i] -= helper;
                colSum[j] -= helper;
            }
            answer.push_back(temp);
        }
        
        return answer;
        
    }
};
  
  
//    0 0 0
      
// 0  5 0 0
// 0  3 4 0
// 0  0 2 8    