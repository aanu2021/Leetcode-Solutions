class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y < z) return false;
        if(x+y == z) return true;
        set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        int direction[4] = {x,-x,y,-y};
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
    
    int gcd(int x,int y){
        if(x==0) return y;
        if(y==0) return x;
        if(x>y) return gcd(x%y,y);
        else return gcd(x,y%x);
    }
    
    bool canMeasureWater2(int x, int y, int z) {
        if(x+y < z) return false;
        if(x+y == z || x==z || y==z) return true;
        int g = gcd(x,y);
        return (z%g==0);
    }
};