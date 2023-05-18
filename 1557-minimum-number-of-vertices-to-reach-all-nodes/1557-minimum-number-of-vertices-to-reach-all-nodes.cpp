class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[v]++;
        }
        
        vector<int>answer;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                answer.push_back(i);
            }
        }
        
        return answer;
        
    }
};