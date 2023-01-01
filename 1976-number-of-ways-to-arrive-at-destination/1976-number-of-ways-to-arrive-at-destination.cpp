class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    int countPaths(int n, vector<vector<int>>& road) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<road.size();i++){
            graph[road[i][0]].push_back({road[i][1],road[i][2]});
            graph[road[i][1]].push_back({road[i][0],road[i][2]});
        }
        
        vector<ll>dist(n,1e15);
        vector<ll>roads(n,0LL);
        
        dist[0] = 0LL;
        roads[0] = 1LL;
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        
        pq.push({0LL,0LL});
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            ll node = curr.second;
            ll wt = curr.first;
            
            if(dist[node] < wt) continue;
            
            for(auto nbrs:graph[node]){
                
                int nbr = nbrs.first;
                int edge_wt = nbrs.second;
                
                if(dist[nbr] > dist[node] + (ll)edge_wt){
                    dist[nbr] = dist[node] + (ll)edge_wt;
                    roads[nbr] = roads[node];
                    pq.push({dist[nbr],(ll)nbr});
                }
                
                else if(dist[nbr] == dist[node] + (ll)edge_wt){
                    roads[nbr] = add(roads[nbr],roads[node]);
                }
                
            }
            
        }
        
        return mod(roads[n-1]);
        
    }
};