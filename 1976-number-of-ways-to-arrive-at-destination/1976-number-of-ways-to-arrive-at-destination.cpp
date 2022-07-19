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
    
    struct comp{
      
        bool operator()(const pair<ll,ll>&x,const pair<ll,ll>&y){
            
            return x.second > y.second;
            
        }
        
    };
    
    int countPaths(int n, vector<vector<int>>&edges) {
        
        vector<vector<pair<ll,ll>>>graph(n);
        
        for(int i=0;i<edges.size();++i){
            
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,comp>pq;
        
        pq.push({0LL,0LL});
        
        vector<ll>roads(n,0LL);
        
        vector<ll>dist(n,1e15);
        
        roads[0]=1LL;
        
        dist[0]=0LL;
        
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            ll u=curr.first;
            ll wt=curr.second;
            
            if(dist[u]<wt){
                continue;
            }
            
            for(auto nbr:graph[u]){
                
                ll v=nbr.first;
                ll weight=nbr.second;
                
                if(dist[v]==dist[u]+weight){
                    
                    roads[v]=add(roads[v],roads[u]);
                    
                }
                
                else if(dist[v] > dist[u]+weight){
                    
                    dist[v]=dist[u]+weight;
                    
                    roads[v]=roads[u];
                    
                    pq.push({v,dist[v]});
                    
                }
                
            }
            
        }
        
        return mod(roads[n-1]);
        
    }
};