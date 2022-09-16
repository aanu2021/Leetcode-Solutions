class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n=quiet.size();
        
        vector<int>indegree(n,0);
        
        vector<int>ans(n,INT_MAX);
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<richer.size();++i){
            
            graph[richer[i][0]].push_back(richer[i][1]);
            
            indegree[richer[i][1]]++;
            
        }
        
        queue<int>q;
        
        for(int i=0;i<n;++i){
            
            ans[i]=i;
            
            if(indegree[i]==0){
                
                q.push(i);
                
            }
            
        }
        
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(int nbr:graph[node]){
                
                if(quiet[ans[nbr]] > quiet[ans[node]]){
                    
                    ans[nbr]=ans[node];
                    
                }
                
                indegree[nbr]--;
                
                if(indegree[nbr]==0){
                    
                    q.push(nbr);
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};