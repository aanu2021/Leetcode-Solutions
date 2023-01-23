class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n,0);
        vector<int>outdegree(n,0);
        for(int i=0;i<trust.size();i++){
            trust[i][0]--; trust[i][1]--;
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0) return i+1;
        }
        return -1;
    }
};