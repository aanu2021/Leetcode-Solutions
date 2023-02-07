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
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<ll>dist(n+1,1e15);
        vector<ll>ways(n+1,0LL);
        dist[0] = 0LL;
        ways[0] = 1LL;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0LL,0LL});
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ll node = curr.second;
            ll weight = curr.first;
            if(dist[node] < weight) continue;
            for(auto &nbrs : graph[node]){
                ll nbr = nbrs.first;
                ll edgeWt = nbrs.second;
                if(dist[nbr] > dist[node] + edgeWt){
                    dist[nbr] = dist[node] + edgeWt;
                    ways[nbr] = ways[node];
                    pq.push({dist[nbr],nbr});
                }
                else if(dist[nbr] == dist[node] + edgeWt){
                    ways[nbr] = add(ways[nbr],ways[node]);
                }
            }
        }
        return ways[n-1];
    }
};