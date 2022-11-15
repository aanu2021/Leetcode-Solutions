class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        vector<bool>vis(26,false);
        for(char c:s){
            if(vis[c-'a']){
                return c;
            }
            vis[c-'a'] = true;
        }
        return 'z';
    }
};