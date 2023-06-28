class Solution {
public:
    
    struct Pair{
      
        int node;
        double weight;
        
    };
    
    struct comp{
      
        bool operator()(const Pair&x,const Pair&y){
            return x.weight > y.weight;
        }
        
    };
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        vector<double>dp(n,0.0);
        vector<bool>visited(n,false);
   
        vector<vector<Pair>>graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v,prob});
            graph[v].push_back({u,prob});
        }
        
        dp[start] = -1.0;
        pq.push({start,dp[start]});
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int node = curr.node;
            double weight = curr.weight;
            
            dp[node] = weight;
            
            if(node == end){
                return -dp[node];
            }
            
            if(visited[node]) continue;
            visited[node] = true;
            
            for(auto &nbrs : graph[node]){
                int nbr = nbrs.node;
                double edgeWt = nbrs.weight;
                if(visited[nbr]) continue;
                if(dp[nbr] > (dp[node] * edgeWt)){
                    dp[nbr] = dp[node] * edgeWt;
                    pq.push({nbr,dp[nbr]});
                }
            }
            
        }
        
        return 0.0;
        
    }
};