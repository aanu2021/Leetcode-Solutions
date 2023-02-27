class Solution {
public:
    
    // GGLLGG
    
    bool isRobotBounded(string s) {
        int n = s.length();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int id = 0;
        int x = 0, y = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'R'){
                id = (id + 1) % 4;
            }
            else if(s[i] == 'L'){
                id = (id - 1 + 4) % 4;
            }
            else{
                x += dx[id];
                y += dy[id];
            }
        }
        return ((x==0 && y==0) || (id != 0));
    }
};