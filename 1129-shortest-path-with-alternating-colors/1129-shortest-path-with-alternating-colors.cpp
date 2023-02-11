class Solution {
public:
    
    vector<int>BFS(int n,vector<vector<int>>&redGraph,vector<vector<int>>&blueGraph,int col){
        queue<pair<int,int>>q;
        vector<int>redDist(n,1e9);
        vector<int>blueDist(n,1e9);
        vector<int>distance(n,1e9);
        if(col==0) blueDist[0] = 0;
        else       redDist[0] = 0;
        q.push({0,col});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int color = curr.second;
            if(color == 0){
                for(int nbr : redGraph[node]){
                    if(redDist[nbr] > blueDist[node] + 1){
                        redDist[nbr] = blueDist[node] + 1;
                        q.push({nbr,1-color});
                    }
                }
            }
            else{
                for(int nbr : blueGraph[node]){
                    if(blueDist[nbr] > redDist[node] + 1){
                        blueDist[nbr] = redDist[node] + 1;
                        q.push({nbr,1-color});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            distance[i] = min(blueDist[i],redDist[i]);
        }
        return distance;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>>redGraph(n);
        vector<vector<int>>blueGraph(n);
        
        for(auto &cand : redEdges){
            redGraph[cand[0]].push_back(cand[1]);
        }
        for(auto &cand : blueEdges){
            blueGraph[cand[0]].push_back(cand[1]);
        }
        
        vector<int>dist1 = BFS(n,redGraph,blueGraph,0);
        vector<int>dist2 = BFS(n,redGraph,blueGraph,1);
        
        vector<int>dist(n);
        for(int i=0;i<n;i++){
            dist[i] = min(dist1[i],dist2[i]);
            if(dist[i] >= 1e9) dist[i] = -1;
        }
        return dist;
        
    }
};