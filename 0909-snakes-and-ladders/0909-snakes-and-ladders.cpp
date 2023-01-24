class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        int target = (n*n);
        
        vector<int>Jump(n*n+1 , -1);
        vector<int>Vis(n*n+1 , 0);
        
        int currCell = 1;
        reverse(board.begin(),board.end());
        for(int i=1;i<n;i+=2){
            reverse(board[i].begin(),board[i].end());
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Jump[currCell++] = board[i][j];
            }
        }
        
        queue<int>q;
        q.push(1);
        Vis[1] = 1;
        int steps = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                
                int node = q.front();
                q.pop();
                if(node == target) return steps;
                for(int currJump = 1; currJump <= 6 ; currJump++){
                    int nextNode = node + currJump;
                    if(nextNode < 0 || nextNode > target) continue;
                    if(Jump[nextNode]!=-1){
                        if(Vis[Jump[nextNode]]==0){
                            Vis[Jump[nextNode]] = 1;
                            q.push(Jump[nextNode]);
                        }
                    }
                    else{
                        if(Vis[nextNode]==0){
                            Vis[nextNode] = 1;
                            q.push(nextNode);
                        }
                    }
                }
            }
            steps++;
            
        }
        return -1;
    }
};