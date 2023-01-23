class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y < z) return false;
        if(x+y == z) return true;
        set<int>visited;
        queue<int>q;
        int direction[4] = {x,-x,y,-y};
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == z) return true;
            for(int dir=0;dir<4;dir++){
                int nextNode = node + direction[dir];
                if(nextNode < 0 || nextNode > x+y) continue;
                if(visited.find(nextNode) != visited.end()) continue;
                visited.insert(nextNode);
                q.push(nextNode);
            }
        }
        return false;
    }
};