class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>>&image,int i,int j,int prev_color,int curr_color){
     
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != prev_color) return;
        
        image[i][j] = curr_color;
        
        for(int dir = 0;dir < 4 ; dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            dfs(image,ni,nj,prev_color,curr_color);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};