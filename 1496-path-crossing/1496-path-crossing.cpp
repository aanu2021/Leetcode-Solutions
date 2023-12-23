class Solution {
public:
    
    string getHash(int x,int y){
        return to_string(x) + "," + to_string(y);
    }
    
    bool isPathCrossing(string s) {
        
        unordered_map<char,int>index;
        int n = s.length();
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        index['N'] = 0;
        index['S'] = 1;
        index['E'] = 2;
        index['W'] = 3;
        
        unordered_set<string>visited;
        int x = 0, y = 0;
        visited.insert(getHash(x,y));
        
        for(int i=0;i<n;i++){
            char dir = s[i];
            x += dx[index[dir]];
            y += dy[index[dir]];
            if(visited.find(getHash(x,y)) != visited.end()) return true;
            visited.insert(getHash(x,y));
        }
        return false;
    }
};