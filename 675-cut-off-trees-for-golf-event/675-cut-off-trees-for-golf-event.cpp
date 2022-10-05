class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int visited[52][52];
    
    int bfs_traversal(int x1,int y1,int x2,int y2,vector<vector<int>>&forest){
        
        int m = forest.size();
        int n = forest[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        queue<pair<int,int>>q;
        
        q.push({x1,y1});
        
        int lvl = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                if(x==x2 && y==y2) return lvl;
                
                if(visited[x][y]) continue;
                
                visited[x][y] = 1;
                
                for(int dir = 0;dir<4;dir++){
                    
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && forest[nx][ny]){
                        
                        q.push({nx,ny});
                        
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return -1;
        
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        
        int m = forest.size();
        int n = forest[0].size();
        
        vector<pair<int,pair<int,int>>>vec;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1){
                    vec.push_back({forest[i][j],{i,j}});
                }
            }
        }
        
        vec.push_back({0,{0,0}});
        
        sort(vec.begin(),vec.end());
        
        int ans = 0;
        
        for(int i=0;i<vec.size()-1;++i){
            
            int int_dist = bfs_traversal(vec[i].second.first,vec[i].second.second,vec[i+1].second.first,vec[i+1].second.second,forest);
            
            if(int_dist<0) return -1;
            
            ans += int_dist;
            
        }
        
        return ans;
        
    }
};