class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int m = firstList.size();
        int n = secondList.size();
        
        int i = 0, j = 0;
        vector<vector<int>>answer;
        
        while(i<m && j<n){
            int l = max(firstList[i][0],secondList[j][0]);
            int r = min(firstList[i][1],secondList[j][1]);
            if(l <= r){
                answer.push_back({l,r});
            }
            if(firstList[i][1] <= secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return answer;
        
    }
};