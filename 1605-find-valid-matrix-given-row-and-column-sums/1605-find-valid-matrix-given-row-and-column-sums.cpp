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
  
  
//   8 6 8
      
// 5  5 0 0
// 7  7 1 0
// 10     