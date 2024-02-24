class Solution {
public:
    
    const int MAX = INT_MAX;
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int person) {
        vector<int>answer;
       
 vector<vector<pair<int,int>>>graph(n);
        for(auto &m : meetings){
            graph[m[0]].push_back({m[1],m[2]});
            graph[m[1]].push_back({m[0],m[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<bool>visited(n, false);
        vector<int>dist(n, MAX);
        dist[0] = 0;
        dist[person] = 0;
        
        pq.push({0,0});
        pq.push({0,person});
        
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int timer = curr.first;
            int node = curr.second;
            if(visited[node]) continue;
            visited[node] = true;
            // cout<<node<<" "<<timer<<"\n";
            if(dist[node] != timer) continue;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeTime = nbrs.second;
                if(visited[nbr]) continue;
                if(dist[node] <= edgeTime){
                    if(dist[nbr] > edgeTime){
                        dist[nbr] = edgeTime;
                        // cout<<nbr<<" "<<dist[nbr]<<"\n";
                        pq.push({dist[nbr], nbr});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i] != MAX) answer.push_back(i);
        }
        return answer;
    }
};



