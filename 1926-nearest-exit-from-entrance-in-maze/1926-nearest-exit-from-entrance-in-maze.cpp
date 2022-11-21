class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int lvl = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if(x==0 || x==m-1 || y==0 || y==n-1){
                    if(x==entrance[0] && y==entrance[1]){
                        
                    }else{
                        return lvl;
                    }
                }
                for(int dir=0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && maze[nx][ny]=='.'){
                        maze[nx][ny] = '+';
                        q.push({nx,ny});
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};