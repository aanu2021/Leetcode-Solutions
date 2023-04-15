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
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        priority_queue<Node,vector<Node>,comp>pq;
        pq.push({0,0,passingFees[0]});
        minTime[0] = 0;
        
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int node = curr.node;
            int timer = curr.timer;
            int cost = curr.cost;
            if(node==n-1) return cost;
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.first;
                int edgeTime = nbrs.second;
                int nextTime = edgeTime + timer;
                int nextCost = cost + passingFees[nbr];
                if(nextTime < minTime[nbr]){
                    minTime[nbr] = nextTime;
                    pq.push({nbr,minTime[nbr],nextCost});
                }
            }
        }
        
        return -1;
        
    }
};