class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<ll>dist(n,1e15);
        vector<ll>path(n,0LL);
        dist[0] = 0LL;
        path[0] = 1LL;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0LL,0LL});
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            ll weight = curr.first;
            ll node = curr.second;
            if(dist[node] < weight) continue;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeWt = nbrs.second;
                if(dist[nbr] > weight + (ll)edgeWt){
                    dist[nbr] = weight + (ll)edgeWt;
                    path[nbr] = path[node];
                    pq.push({dist[nbr],nbr});
                }
                else if(dist[nbr] == weight + (ll)edgeWt){
                    path[nbr] += path[node];
                    path[nbr] %= M;
                }
            }
        }
        return path[n-1];
    }
};