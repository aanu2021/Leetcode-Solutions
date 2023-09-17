struct Pair{
    int node;
    int mask;
    int currLen;
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<Pair>q;
        vector<vector<bool>>visited(n,vector<bool>((1<<n),false));
        for(int i=0;i<n;i++){
            int currMask = (1<<i);
            q.push({i,currMask,1});
            visited[i][currMask] = true;
        }
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int node = curr.node;
            int mask = curr.mask;
            int currLen = curr.currLen;
            if(mask == (1<<n)-1) return currLen-1;
            for(int nbr : graph[node]){
                int newMask = mask|(1<<nbr);
                if(visited[nbr][newMask]) continue;
                visited[nbr][newMask] = true;
                q.push({nbr,newMask,currLen+1});
            }
        }
        return -1;
    }
};

/*

Alone last visited node, bitmask can't help us determining the optimal path, either we will be captured inside a loop, or we will end up with sub-optimal answer.

So, the only way is to use combination of both of them visited[last_visited][visited_mask]

Here we can use BFS algorithm, to find the shortest path considering two factoes simultaneously.

1. last_visited_node
2. visited_mask_so_far

If visited[last_visited_node][visited_mask_so_far] is already set to true, then we don't have to recalculate them again.

*/