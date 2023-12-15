class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>outdegree;
        for(int i=0;i<paths.size();i++){
            outdegree[paths[i][0]]++;
        }
        for(int i=0;i<paths.size();i++){
            if(outdegree[paths[i][1]] > 0) continue;
            return paths[i][1];
        }
        return "";
    }
};