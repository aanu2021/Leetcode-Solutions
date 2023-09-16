struct Pair{
    int x;
    int y;
    int wt;
};

struct comp{
    bool operator()(const Pair&x,const Pair&y){
        return x.wt > y.wt;
    }  
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        priority_queue<Pair,vector<Pair>,comp>pq;
        pq.push({0,0,0});
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int x = curr.x;
            int y = curr.y;
            int wt = curr.wt;
            if(visited[x][y]) continue;
            visited[x][y] = true;
            if(x==m-1 && y==n-1) return wt;
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(visited[nx][ny]) continue;
                    pq.push({nx,ny,max(wt,abs(heights[x][y]-heights[nx][ny]))});
                }
            }
        }
        return 0;
    }
};