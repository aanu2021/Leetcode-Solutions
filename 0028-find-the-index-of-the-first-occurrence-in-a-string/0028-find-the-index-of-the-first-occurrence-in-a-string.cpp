class Solution {
public:
    
    // current prefix na hole ager prefix ta dekh lo vmro ...
    
    int strStr(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(n < m) return -1;
        vector<int>lps(m,0);
        for(int i=1;i<m;i++){
            int len = lps[i-1];
            while(len > 0 && p[i] != p[len]) len = lps[len-1];
            if(p[i] == p[len]) len++;
            lps[i] = len;
        }
        int j = 0;
        for(int i=0;i<n;i++){
            if(s[i] == p[j]){
                j++;
                if(j == m){
                    return i-m+1;
                    j = lps[j-1];
                }
            }
            else{
                while(j > 0 && s[i] != p[j]){
                    j = lps[j-1];
                }
                if(s[i] == p[j]) j++;
            }
        }
        return -1;
    }
};