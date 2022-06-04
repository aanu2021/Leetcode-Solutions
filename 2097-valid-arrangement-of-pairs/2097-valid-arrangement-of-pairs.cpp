class Solution {
public:
    
    unordered_map<int,stack<int>>graph;
    unordered_map<int,int>indegree;
    unordered_map<int,int>outdegree;
    
    vector<vector<int>>ans;
    
    void dfs(int u){
        
        auto&curr=graph[u];
        
        while(!curr.empty()){
            
            int v=curr.top();
            curr.pop();
            
            dfs(v);
            
            ans.push_back({u,v});
            
        }
        
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        int m=pairs.size();
        
        graph.reserve(m);
        indegree.reserve(m);
        outdegree.reserve(m);
        
        int start=-1;
        
        for(int i=0;i<m;i++){
            
            int u=pairs[i][0];
            int v=pairs[i][1];
            
            graph[u].push(v);
            indegree[v]++;
            outdegree[u]++;
            
        }
        
        
        for(auto itr:indegree){
            if(outdegree[itr.first]==indegree[itr.first]+1){
                start=itr.first;
                break;
            }
        }
        
        
        for(auto itr:outdegree){
            if(outdegree[itr.first]==indegree[itr.first]+1){
                start=itr.first;
                break;
            }
        }
        
        if(start==-1){
            start=graph.begin()->first;
        }
        
        dfs(start);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};