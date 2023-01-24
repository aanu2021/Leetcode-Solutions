class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        queue<int>q;
        q.push(1);
        
        vector<int>vis(n*n + 1 , 0);
        vector<int>jump(n*n + 1 , -1);
        
        int currCell = 1;
        reverse(board.begin(),board.end());
        for(int i=1;i<n;i+=2){
            reverse(board[i].begin(),board[i].end());
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                jump[currCell++] = board[i][j];
            }
        }
        
        // for(int i=1;i<=n*n;i++){
        //     cout<<jump[i]<<" ";
        // }cout<<"\n";
        
        int steps = 0;
        int target = n*n;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
               // cout<<node<<"\n";
                if(vis[node]) continue;
                vis[node] = 1;
                if(node == target) return steps;
                   
                         for(int currJump = 1;currJump <= 6;currJump++){
                        int nextNode = node + currJump;
                        if(nextNode < 0 || nextNode > target) continue;
                        if(jump[nextNode] != -1) q.push(jump[nextNode]);
                             else q.push(nextNode);
                    }
            }
            // cout<<"------------------\n";
            steps++;
        }
        return -1;
    }
};