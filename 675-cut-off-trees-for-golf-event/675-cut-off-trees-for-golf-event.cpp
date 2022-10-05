/*

 0 --> obstacle
 1 --> empty cell
>1 --> tree's height

 North , East , South , West --> Moves Possible
 
 We can cut off all the trees , if and only if there exists a
 path from the current tree to the next greater tree value.

 We will sort the tree's according to their values and then do a
 bfs traversal b/w adjacent trees and calculate the shortest 
 distance b/w them , if there is no path possible , then return 
 -1, otherwise at the end of the program return the summation of 
 those distances.
 
 T.C : O(M*N*M*N)
 S.C : O(M*N)

*/

// Build a Tree Cell Structure for simplicity sake //

struct Tree{
  
    public:
    
    int value;
    int x;
    int y;
    
};

// Helps to sort the trees on the basis of their values //

bool static comp(const Tree&x,const Tree&y){
    
    return x.value < y.value;
    
}

// 4-directional coordinates //

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool visited[52][52];

int bfs_traversal(int src1,int src2,int dest1,int dest2,vector<vector<int>>&forest){
    
    int m = forest.size();
    int n = forest[0].size();
    
    // Reset the visited array //
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    
    // Data structure widely used for BFS Traversal //
    
    queue<pair<int,int>>q;
    
    // Single Source BFS //
    
    q.push({src1,src2});
    
    int lvl = 0;
    
    while(!q.empty()){
        
        int sz = q.size();
        
        while(sz--){
            
            auto curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            if(x==dest1 && y==dest2){
                return lvl;
            }
            
            if(visited[x][y]) continue;
            
            visited[x][y] = true;
            
            for(int dir=0;dir<4;dir++){
                
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

class Solution {
public:
    
    int cutOffTree(vector<vector<int>>& forest) {
        
        int m=forest.size();
        int n=forest[0].size();
        
        vector<Tree>vec;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1){
                    vec.push_back({forest[i][j],i,j});
                }
            }
        }
        
        // Starting Point - By default //
        
        vec.push_back({0,0,0});
        
        // Sort on the basis of the tree values //
        
        sort(vec.begin(),vec.end(),comp);
        
        int ans = 0;
        
        // BFS Traversal b/w adjacent trees //
        
        for(int i=0;i<vec.size()-1;i++){
            
            int curr = bfs_traversal(vec[i].x,vec[i].y,vec[i+1].x,vec[i+1].y,forest);
            
            // If there doesn't exist a single path b/w adjacent trees , then simple return -1 (invalid sequence) //
            
            if(curr<0){
                return -1;
            }
            
            ans += curr;
            
        }
        
        return ans;
        
    }
};