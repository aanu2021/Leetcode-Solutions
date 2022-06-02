class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        vector<vector<int>>target={{1,2,3},{4,5,0}};
        
        int x=-1,y=-1;
        
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        
        set<vector<vector<int>>>st;
        
        queue<pair<vector<vector<int>>,pair<int,int>>>q;
        
        q.push({board,{x,y}});
        
        int moves=0;
        
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                vector<vector<int>>grid=curr.first;
                int x=curr.second.first;
                int y=curr.second.second;
                
                if(grid==target){
                    return moves;
                }
                
                if(st.find(grid)!=st.end()){
                    continue;
                }
                
                st.insert(grid);
                
                for(int i=0;i<4;i++){
                    
                    int x1=x+dx[i];
                    int y1=y+dy[i];
                    
                    if(x1<0 || y1<0 || x1>=2 || y1>=3){
                        continue;
                    }
                    
                    vector<vector<int>>temp=grid;
                    
                    swap(temp[x][y],temp[x1][y1]);
                    
                    if(st.find(temp)==st.end()){
                        q.push({temp,{x1,y1}});
                    }
                    
                }
                
            }
            
            moves++;
            
        }
        
        return -1;
        
    }
};