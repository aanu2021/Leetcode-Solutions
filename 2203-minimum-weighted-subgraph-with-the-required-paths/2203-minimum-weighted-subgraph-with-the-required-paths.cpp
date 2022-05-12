class Solution {
public:
    
    typedef long long ll;
    
    void func(ll src,ll n,vector<vector<pair<ll,ll>>>&graph,vector<ll>&dist){
        
        dist[src]=0LL;
        
        queue<pair<ll,ll>>q;
        
        q.push({src,0LL});
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            ll node=curr.first;
            ll wt=curr.second;
            
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
        
    }
    
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<pair<ll,ll>>>al(n);
        vector<vector<pair<ll,ll>>>ral(n);
        
        for(ll i=0;i<edges.size();i++){
            
            al[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            ral[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        
        vector<ll>dist1(n,1e18);
        vector<ll>dist2(n,1e18);
        vector<ll>dist3(n,1e18);
        
        dist1[src1]=0LL;
        dist2[src2]=0LL;
        dist3[dest]=0LL;
        
        func(src1,n,al,dist1);
        func(src2,n,al,dist2);
        func(dest,n,ral,dist3);
        
        ll ans=1e18;
        
        for(ll i=0;i<n;i++){
            
            if(dist1[i]>=1e18 || dist2[i]>=1e18 || dist3[i]>=1e18){
                continue;
            }
            
            ans=min(ans,dist1[i]+dist2[i]+dist3[i]);
            
        }
        
        return ans>=1e18 ? -1 : ans;
        
    }
};