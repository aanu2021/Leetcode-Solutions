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
    
    int countPaths(int n, vector<vector<int>>& road) {
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<road.size();++i){
            
            graph[road[i][0]].push_back({road[i][1],road[i][2]});
            graph[road[i][1]].push_back({road[i][0],road[i][2]});
            
        }
        
        vector<ll>dist(n,1e15);
        
        vector<ll>roads(n,0);
        
        dist[0]=0LL;
        roads[0]=1LL;
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,comp>pq;
        
        pq.push({0LL,0LL});
        
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            ll node=curr.first;
            ll wt=curr.second;
            
            if(dist[node]<wt){
                continue;
            }
            
            for(auto nbr:graph[node]){
                
                ll v=nbr.first;
                ll weight=nbr.second;
                
                if(dist[v] > dist[node] + weight){
                    
                    dist[v] = dist[node] + weight;
                    
                    roads[v]=roads[node];
                    
                    pq.push({v,dist[v]});
                    
                }
                
                else if(dist[v]==dist[node] + weight){
                    
                    roads[v]=add(roads[v],roads[node]);
                    
                }
                
            }
            
        }
        
        return mod(roads[n-1]);
        
    }
};