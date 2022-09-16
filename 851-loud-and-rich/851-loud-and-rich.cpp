class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n=quiet.size();
        
        vector<int>indegree(n,0);
        
        vector<vector<int>>graph(n);
        
        vector<int>ans(n,INT_MAX);
        
        queue<int>q;
        
        for(int i=0;i<richer.size();++i){
            
            graph[richer[i][0]].push_back(richer[i][1]);
            
            indegree[richer[i][1]]++;
            
        }
        
        for(int i=0;i<n;++i){
            
            ans[i]=i;
            
            if(indegree[i]==0){
                
                q.push(i);
                
                ans[i]=i;
                
                // cout<<i<<"\n";
                
            }
            
        }
        
        /*
        
        From richer set to poorer set such that quiet (Minimum) values for each node are already calculated
        
        0 , 7
        
        ans[0]=INF
        ans[1]=INF
        ans[2]=INF
        ans[3]=INF
        ans[4]=INF
        ans[5]=INF
        ans[6]=INF
        ans[7]=INF
        
        */
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(int nbr:graph[node]){
                
                if(ans[nbr]==INT_MAX || quiet[ans[nbr]] > quiet[ans[node]]){
                    
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