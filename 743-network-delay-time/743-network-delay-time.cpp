class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>dist(n+1,1e9);
        
        queue<pair<int,int>>q;
        
        q.push({k,0});
        
        dist[k]=0;
        
        vector<vector<pair<int,int>>>graph(n+1);
        
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        while(!q.empty()){
            
           auto curr=q.front();
            q.pop();
            
            int node=curr.first;
            int wt=curr.second;
            
            if(dist[node]!=wt){
                continue;
            }
            
            for(auto j:graph[node]){
                
                if(dist[j.first]>dist[node]+j.second){
                    dist[j.first]=dist[node]+j.second;
                    q.push({j.first,dist[j.first]});
                }
                
            }
            
        }
        
        int maxi=0;
        
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dist[i]);
        }
        
        if(maxi>=1e9){
            return -1;
        }else{
            return maxi;
        }
        
    }
};