class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int>dist(n+1,0);
        
        vector<vector<int>>graph(n+1);
        
        vector<int>indegree(n+1,0);
        
        
        for(int i=0;i<relations.size();++i){
            
            graph[relations[i][0]].push_back(relations[i][1]);
            
            indegree[relations[i][1]]++;
            
        }
        
        
        queue<int>q;
        
        
        for(int i=1;i<=n;++i){
            
            if(indegree[i]==0){
                
                dist[i]=time[i-1];
                
                q.push(i);
                
            }
            
        }
        
        
        // for(int i=1;i<=n;++i){
        //     cout<<dist[i]<<" ";
        // }cout<<"\n";
        
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(int nbr:graph[node]){
                
                dist[nbr]=max(dist[nbr],time[nbr-1]+dist[node]);
                
                indegree[nbr]--;
                
                if(indegree[nbr]==0){
                    
                    q.push(nbr);
                    
                }
                
            }
            
        }
        
        int maxi=*max_element(dist.begin(),dist.end());
        
        return maxi;
        
    }
};