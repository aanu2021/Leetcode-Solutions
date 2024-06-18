class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        s = "#" + s;
        p = "#" + p;
        
        vector<bool>prev(n+1, false);
        vector<bool>curr(n+1, false);
        prev[0] = true;
        
        for(int i=1;i<=n;i++){
            if(p[i] == '*'){
                prev[i] = prev[i-2];
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i] == p[j] || p[j] == '.'){
                    curr[j] = prev[j-1];
                }
                else if(p[j] == '*'){
                    curr[j] = curr[j-2];
                    if(p[j-1] == '.' || s[i] == p[j-1]){
                        curr[j] = curr[j] || prev[j];
                    }
                }
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
                curr[j] = false;
            }
        }
        
        return prev[n];
    }
};