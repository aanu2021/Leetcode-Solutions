class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x+y) return false;
        vector<int>visited(x+y+1,0);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int dir[4] = {x,-x,y,-y};
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == z) return true;
            for(int d=0;d<4;d++){
                int nextNode = node + dir[d];
                if(nextNode < 0 || nextNode > x + y) continue;
                if(visited[nextNode]) continue;
                visited[nextNode] = 1;
                q.push(nextNode);
            }
        }
        return false;
    }
};