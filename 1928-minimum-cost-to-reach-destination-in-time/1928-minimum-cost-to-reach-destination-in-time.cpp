class Solution {
public:
    
    struct Node{
      int node;
      int timer;
      int cost;  
    };
    
    struct comp{
       bool operator()(const Node&x,const Node&y){
           return x.cost > y.cost;
       }        
    };
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();
        vector<int>minTime(n,maxTime+1);
        
        priority_queue<Node,vector<Node>,comp>pq;
        pq.push({0,0,passingFees[0]});
        minTime[0] = 0;
        
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int node = curr.node;
            int timer = curr.timer;
            int cost = curr.cost;
            if(node==n-1) return cost;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int etime = nbrs.second;
                int nt = timer + etime;
                int nc = cost + passingFees[nbr];
                if(minTime[nbr] > nt){
                    minTime[nbr] = nt;
                    pq.push({nbr,nt,nc});
                }
            }
        }
        
        return -1;
        
    }
};